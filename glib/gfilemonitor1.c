#include <gio/gio.h>
#include <stdbool.h>
#include <stdio.h>

static void debug_event(GFileMonitor *monitor,
                        GFile *event_file, GFile *other_file,
                        GFileMonitorEvent event_type,
                        gpointer user_data)
{
    (void) monitor;
    (void) user_data;

    switch (event_type)
    {
    case G_FILE_MONITOR_EVENT_CHANGED:
        printf("G_FILE_MONITOR_EVENT_CHANGED\n");
        break;
    case G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT:
        printf("G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT\n");
        break;
    case G_FILE_MONITOR_EVENT_DELETED:
        printf("G_FILE_MONITOR_EVENT_DELETED\n");
        break;
    case G_FILE_MONITOR_EVENT_CREATED:
        printf("G_FILE_MONITOR_EVENT_CREATED\n");
        break;
    case G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED:
        printf("G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED\n");
        break;
    case G_FILE_MONITOR_EVENT_PRE_UNMOUNT:
        printf("G_FILE_MONITOR_EVENT_PRE_UNMOUNT\n");
        break;
    case G_FILE_MONITOR_EVENT_UNMOUNTED:
        printf("G_FILE_MONITOR_EVENT_UNMOUNTED\n");
        break;
    case G_FILE_MONITOR_EVENT_MOVED:
        printf("G_FILE_MONITOR_EVENT_MOVED\n");
        break;
    case G_FILE_MONITOR_EVENT_RENAMED:
        printf("G_FILE_MONITOR_EVENT_RENAMED\n");
        break;
    case G_FILE_MONITOR_EVENT_MOVED_IN:
        printf("G_FILE_MONITOR_EVENT_MOVED_IN\n");
        break;
    case G_FILE_MONITOR_EVENT_MOVED_OUT:
        printf("G_FILE_MONITOR_EVENT_MOVED_OUT\n");
        break;
    default:
        printf("INVALID\n");
        break;
    }

    if (event_file)
    {
        gchar *file_path = g_file_get_path(event_file);
        printf("event_file : %s\n", file_path);
        g_free(file_path);
    }

    if (other_file)
    {
        gchar *file_path = g_file_get_path(other_file);
        printf("other_file : %s\n", file_path);
        g_free(file_path);
    }

    //if (g_file_equal(gfile, event_file))
    //{
    //    printf("g_file_equal\n");
    //}

    if (g_file_monitor_is_cancelled(monitor))
    {
        printf("monitor_is_cancelled\n");
    }

}

int main(int argc, const char **argv)
{
    setbuf(stdout, NULL);

    if (argc != 2)
        return EXIT_FAILURE;

    bool dirmonitor = false;

    GFile *gfile = NULL;

    gfile = g_file_new_for_path(argv[1]);

    GFileMonitor *monitor = NULL;

    if (dirmonitor)
    {
        monitor = g_file_monitor_directory(gfile,
                                           G_FILE_MONITOR_WATCH_MOVES,
                                           NULL, NULL);
    }
    else
    {
        monitor = g_file_monitor(gfile,
                                 G_FILE_MONITOR_WATCH_MOUNTS
                                 | G_FILE_MONITOR_WATCH_MOVES,
                                 NULL, NULL);
    }

    if (monitor == NULL)
        return EXIT_FAILURE;

    g_signal_connect(monitor, "changed",
                     G_CALLBACK(debug_event), NULL);

    if (!monitor)
        return EXIT_FAILURE;

    g_object_unref(gfile);

    GMainLoop *mainloop = g_main_loop_new(NULL, FALSE);

    g_main_loop_run(mainloop);

    g_main_loop_unref(mainloop);
    g_object_unref(monitor);

    return 0;
}


