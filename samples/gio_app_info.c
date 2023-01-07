#include <gio/gio.h>

static gint _sort_app_infos(gconstpointer a, gconstpointer b)
{
    return g_utf8_collate(g_app_info_get_name(G_APP_INFO(a)),
                          g_app_info_get_name(G_APP_INFO(b)));
}

int main()
{
    GList *all = g_app_info_get_all();
    all = g_list_sort(all, _sort_app_infos);

    for (GList *lp = all; lp; lp = lp->next)
    {
        GAppInfo *info = (GAppInfo*) lp->data;

        g_print("------------------------------------------------------------\n");

        const gchar *str = NULL;

        str = g_app_info_get_id(info);
        if (str)
            g_print("Id : %s\n", str);

        str = g_app_info_get_name(info);
        if (str)
            g_print("Name : %s\n", str);

        str = g_app_info_get_description(info);
        if (str)
            g_print("Desc : %s\n", str);

        str = g_app_info_get_executable(info);
        if (str)
            g_print("Exec : %s\n", str);
    }

    g_list_free_full(all, g_object_unref);

    return 0;
}


