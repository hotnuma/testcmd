#include <cfile.h>
#include <cstringlist.h>
#include <libapp.h>
#include <ctype.h>
#include <print.h>

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

int main(int argc, char **argv)
{
    const char *filepath = NULL;

    int n = 1;

    while (n < argc)
    {
        const char *part = argv[n];

        // Input file.
        if (strcmp(part, "-i") == 0)
        {
            if (++n >= argc)
                return 1;

            filepath = argv[n];
        }

        n++;
    }

    if (!file_exists(filepath))
        return 1;

    CFileAuto *file = cfile_new();
    if (!cfile_read(file, filepath))
        return 1;

    CStringAuto *line = cstr_new_size(32);
    CStringAuto *word = cstr_new_size(32);
    CStringListAuto *list = cstrlist_new_size(128);

    while (cfile_getline(file, line))
    {
        char *curr = cstr_data(line);

        while (get_word(&curr, word))
        {
            if (cstr_startswith(word, "xfce_", false)
                || cstr_startswith(word, "exo_", false))
            {
                if (cstrlist_find(list, c_str(word), true) == -1)
                {
                    cstrlist_append(list, c_str(word));
                }
            }
        }
    }

    cstrlist_sort(list, false);

    int size = cstrlist_size(list);
    for (int i = 0; i < size; ++i)
    {
        CString *item = cstrlist_at(list, i);
        print(c_str(item));
    }

    return 0;
}


