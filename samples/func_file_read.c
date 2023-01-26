#include <cfile.h>
#include <print.h>

int main()
{
    CStringAuto *buffer = cstr_new_size(512);

    file_read(buffer, "/proc/meminfo");

    print(c_str(buffer));

    print("size = %d", cstr_size(buffer));
    print("capacity = %d", cstr_capacity(buffer));

    return 0;
}


