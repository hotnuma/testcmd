#include <gio/gio.h>
#include <stdio.h>

int main()
{
    GFile *gfile = g_file_new_for_path("/home/hotnuma/Downloads/test");
    gchar *basename = g_file_get_basename(gfile);

    printf("%s\n", basename);

    g_free(basename);
    g_object_unref(gfile);

    return 0;
}


