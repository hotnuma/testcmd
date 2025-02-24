/*
 * Demo for g_file_monitor().
 *
 * gcc -o filemonitor g_file_monitor.c $(pkg-config --cflags --libs gio-2.0)
 *
 * It is possible to pass either a directory or a file path as argument.
 * 
 * https://gist.github.com/simu/0ed1e9b12871e20cec48efe73eeeb8e1
 * 
 */
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <glib.h>
#include <gio/gio.h>

void file_changed_cb(GFileMonitor *monitor, GFile *file, GFile *other, GFileMonitorEvent evtype, gpointer user_data)
{
    char *fpath = g_file_get_path(file);
    char *opath = NULL;
    if (other) {
        opath = g_file_get_path(other);
    }
    switch(evtype) {
        case G_FILE_MONITOR_EVENT_CHANGED:
            g_print("%s contents changed\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT:
            g_print("%s set of changes done\n\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_DELETED:
            g_print("%s deleted\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_CREATED:
            g_print("%s created\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED:
            g_print("%s attributes changed\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_RENAMED:
            g_print("%s renamed to %s\n", fpath, opath);
            break;
        case G_FILE_MONITOR_EVENT_MOVED_IN:
            g_print("%s moved to directory\n", fpath);
            break;
        case G_FILE_MONITOR_EVENT_MOVED_OUT:
            g_print("%s moved from directory\n", fpath);
            break;
        default:
            g_print("%s event %x\n", fpath, evtype);
            break;
    }
    if (opath) {
        g_free(opath);
    }
    g_free(fpath);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        g_print("usage: %s /path/to/file/to/monitor\n", argv[0]);
        return 1;
    }

    GMainLoop *ws = g_main_loop_new(NULL, FALSE);
    assert(ws);

    GFile *f = g_file_new_for_commandline_arg(argv[1]);
    assert(f);

    GError *err = NULL;
    // We use G_FILE_MONITOR_WATCH_MOVES here to get EVENT_RENAMED,
    // EVENT_MOVED_IN, and EVENT_MOVED_OUT when appropriate.
    GFileMonitor *fm = g_file_monitor(f, G_FILE_MONITOR_WATCH_MOVES, NULL, &err);
    if (err) {
        fprintf(stderr, "unable to monitor %s: %s\n", argv[1], err->message);
        g_error_free(err);
        return 1;
    }

    g_signal_connect(G_OBJECT(fm), "changed", G_CALLBACK(file_changed_cb), NULL);

    char *fpath = g_file_get_path(f);
    g_print("monitoring %s\n", fpath);
    g_free(fpath);

    g_main_loop_run(ws);

    return 0;
}
