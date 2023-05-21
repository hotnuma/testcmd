#include <libnotify/notify.h>

int main()
{
    char title[200] = "Title";
    char message[500] = "<b>Artist:</b> Unknown";

    notify_init("notify-test");

    NotifyNotification *notif;
    notif = notify_notification_new(title, message, NULL);
    notify_notification_show(notif, NULL);

    notify_uninit();

    return 0;
}


