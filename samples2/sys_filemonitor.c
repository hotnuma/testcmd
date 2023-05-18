#include <gio/gio.h>
#include <stdbool.h>
#include <stdio.h>

//typedef enum {
//  G_FILE_MONITOR_EVENT_CHANGED,
//  G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT,
//  G_FILE_MONITOR_EVENT_DELETED,
//  G_FILE_MONITOR_EVENT_CREATED,
//  G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED,
//  G_FILE_MONITOR_EVENT_PRE_UNMOUNT,
//  G_FILE_MONITOR_EVENT_UNMOUNTED,
//  G_FILE_MONITOR_EVENT_MOVED,
//  G_FILE_MONITOR_EVENT_RENAMED,
//  G_FILE_MONITOR_EVENT_MOVED_IN,
//  G_FILE_MONITOR_EVENT_MOVED_OUT
//} GFileMonitorEvent;

static void _on_monitor_changed(GFileMonitor *monitor,
                                GFile *event_file, GFile *other_file,
                                GFileMonitorEvent event_type,
                                gpointer user_data)
{
    (void) monitor;
    (void) event_file;
    (void) other_file;
    (void) event_type;
    (void) user_data;

    switch(event_type)
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

}

static GFileMonitor* monitor_create(const gchar *path, gboolean is_dir)
{
    GFileMonitor *monitor;
    GError *error = NULL;

    GFile *file = g_file_new_for_path(path);

    if (is_dir)
        monitor = g_file_monitor_directory(file,
                                           G_FILE_MONITOR_WATCH_MOVES,
                                           NULL, &error);
    else
        monitor = g_file_monitor_file(file,
                                      G_FILE_MONITOR_NONE,
                                      NULL, &error);

    g_object_unref(file);

    if (monitor == NULL)
    {
        g_warning("Error monitoring %s at %s: %s (%s, %d)",
                  is_dir ? "directory" : "file",
                  path,
                  error->message,
                  g_quark_to_string(error->domain),
                  error->code);
                  g_error_free(error);
    }

    return monitor;
}


int main()
{
    setbuf(stdout, NULL);

    GFileMonitor *monitor = monitor_create("/home/hotnuma/Downloads/test", true);

    if (!monitor)
        return EXIT_FAILURE;

    g_signal_connect(monitor, "changed",
                     G_CALLBACK(_on_monitor_changed), NULL);


    GMainLoop *mainloop = g_main_loop_new(NULL, FALSE);


    g_main_loop_run(mainloop);

    g_main_loop_unref(mainloop);
    g_object_unref(monitor);

    return 0;
}


