#include <cfile.h>
#include <stdlib.h>
#include <stdio.h>

#include <gumbo.h>

static void search_for_links(GumboNode* node)
{
    if (node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    GumboAttribute *href = gumbo_get_attribute(&node->v.element.attributes, "href");
    if (node->v.element.tag == GUMBO_TAG_A && href)
    {
        printf("%s\n", href->value);
    }

    GumboVector *children = &node->v.element.children;

    for (unsigned int i = 0; i < children->length; ++i)
    {
        search_for_links((GumboNode*) children->data[i]);
    }
}

int main(/*int argc, char** argv*/)
{
    //if (argc != 2)
    //{
    //    printf("Usage: find_links <html filename>.\n");
    //    exit(EXIT_FAILURE);
    //}

    //const char *filename = argv[1];

    const char *filepath = "/home/hotnuma/Bureau/bookmarks.html";

    CFileAuto *file = cfile_new();
    if (!cfile_read(file, filepath))
        return EXIT_FAILURE;

    GumboOutput *output = gumbo_parse(cfile_data(file));

    search_for_links(output->root);

    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return EXIT_SUCCESS;
}


