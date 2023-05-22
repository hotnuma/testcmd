#include <gio/gio.h>
#include <stdio.h>

int main()
{
    GFile *gfile = g_file_new_for_path("/home/hotnuma/DevFiles/testcmd/main.c");

    // async load the content-type
    GFileInfo *fileinfo = g_file_query_info(
                                gfile,
                                G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE ","
                                G_FILE_ATTRIBUTE_STANDARD_FAST_CONTENT_TYPE,
                                G_FILE_QUERY_INFO_NONE,
                                NULL, NULL);

    if (fileinfo)
    {
        // store the new content type
        const gchar *content_type = g_file_info_get_content_type(fileinfo);

        if (content_type)
        {
            content_type = g_file_info_get_attribute_string(
                                fileinfo,
                                G_FILE_ATTRIBUTE_STANDARD_FAST_CONTENT_TYPE);
            printf("%s\n", content_type);
        }

        if (content_type)
            printf("%s\n", content_type);

        g_object_unref(G_OBJECT(fileinfo));
    }

    g_object_unref(gfile);

    return 0;
}


