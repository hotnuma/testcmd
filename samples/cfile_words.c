#include <cfile.h>
#include <cstringlist.h>
#include <libapp.h>
#include <libstr.h>
#include <ctype.h>
#include <print.h>

typedef bool (*WordParseFunc) (const char*);

typedef struct
{
    CStringList *list;
    WordParseFunc func;

} WordParser;

WordParser* wp_new(WordParseFunc func);
void wp_free(WordParser *parser);

#define WordParserAuto GC_CLEANUP(_freeWordParser) WordParser
GC_UNUSED static inline void _freeWordParser(WordParser **parser)
{
    wp_free(*parser);
}

bool wp_readfile(WordParser *parser, const char *filepath);
bool get_word(char **start, CString *result);

WordParser* wp_new(WordParseFunc func)
{
    WordParser *parser = (WordParser*) malloc(sizeof(WordParser));
    parser->list = cstrlist_new_size(128);
    parser->func = func;


    return parser;
}

void wp_free(WordParser *parser)
{
    if (parser->list)
        cstrlist_free(parser->list);

    free(parser);
}

bool wp_readfile(WordParser *parser, const char *filepath)
{
    if (!parser->func || !file_exists(filepath))
        return false;

    CFileAuto *file = cfile_new();
    if (!cfile_read(file, filepath))
        return false;

    CStringAuto *line = cstr_new_size(32);
    CStringAuto *word = cstr_new_size(32);

    while (cfile_getline(file, line))
    {
        char *curr = cstr_data(line);

        while (get_word(&curr, word))
        {
            if (parser->func(c_str(word)))
            {
                if (cstrlist_find(parser->list, c_str(word), true) == -1)
                {
                    cstrlist_append(parser->list, c_str(word));
                }
            }
        }
    }

    cstrlist_sort(parser->list, false);

    return true;
}

bool get_word(char **start, CString *result)
{
    // end of buffer ?
    if (**start == '\0')
        return false;

    // start of line.
    char *first = *start;
    char *p = first;

    while (1)
    {
        if (isalpha(*p) || *p =='_')
        {
            char *word = p;
            while (isalnum(*p) || *p =='_')
                ++p;

            cstr_clear(result);
            cstr_append_len(result, word, p - word);

            // move to next word.
            *start = p;

            return true;
        }
        else if (*p == '\0')
        {
            return false;
        }

        ++p;
    }
}

bool test_word(const char *word)
{
    return (str_startswith(word, "HAVE_", true));
}

int main(int argc, char **argv)
{
    const char *filepath = "/home/hotnuma/DevSrc/gpicview/src/main-win.c";

    int n = 1;

    while (n < argc)
    {
        const char *part = argv[n];

        // Input file.
        if (strcmp(part, "-i") == 0)
        {
            if (++n >= argc)
                return EXIT_FAILURE;

            filepath = argv[n];
        }

        n++;
    }

    WordParserAuto *parser = wp_new(test_word);
    if (!wp_readfile(parser, filepath))
        return EXIT_FAILURE;

    int size = cstrlist_size(parser->list);
    for (int i = 0; i < size; ++i)
    {
        CString *item = cstrlist_at(parser->list, i);
        print(c_str(item));
    }

    return EXIT_SUCCESS;
}


