#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/19227781/

int main (void)
{
    struct if_nameindex *if_nidxs = if_nameindex();
    if (!if_nidxs)
        return EXIT_FAILURE;

    struct if_nameindex *intf;

    for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != NULL; ++intf)
    {
        printf("%s\n", intf->if_name);
    }

    if_freenameindex(if_nidxs);

    return 0;
}


