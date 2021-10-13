#include <CString.h>
#include <stdio.h>

#include <print.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/home/hotnuma/.mpvsocket"
#define BUFFER_SIZE 12

int
main(int argc, char **argv)
{
   int ret;
   int data_socket;
   char buffer[BUFFER_SIZE];

   /* Create local socket. */

   data_socket = socket(AF_UNIX, SOCK_STREAM, 0);

   if (data_socket == -1)
   {
       perror("socket");
       exit(EXIT_FAILURE);
   }

   /*
    * For portability clear the whole structure, since some
    * implementations have additional (nonstandard) fields in
    * the structure.
    */

   struct sockaddr_un addr;
   memset(&addr, 0, sizeof(addr));

   /* Connect socket to socket address. */

   addr.sun_family = AF_UNIX;
   strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

   ret = connect(data_socket, (const struct sockaddr *) &addr,
                  sizeof(addr));

   if (ret == -1)
   {
       fprintf(stderr, "The server is down.\n");
       exit(EXIT_FAILURE);
   }

   /* Send arguments. */


   CString inpath = "/home/hotnuma/Downloads/emile.avi";
   CString message = strFmt("loadfile \"%s\" replace panscan=0.0\n",
                            inpath.c_str());

   ret = write(data_socket, message.c_str(), message.size() + 1);

   if (ret == -1)
   {
       perror("write");
   }

   /* Request result. */

   strcpy(buffer, "END");
   ret = write(data_socket, buffer, strlen(buffer) + 1);
   if (ret == -1)
   {
       perror("write");
       exit(EXIT_FAILURE);
   }

   /* Receive result. */

   ret = read(data_socket, buffer, sizeof(buffer));
   if (ret == -1)
   {
       perror("read");
       exit(EXIT_FAILURE);
   }

   /* Ensure buffer is 0-terminated. */

   buffer[sizeof(buffer) - 1] = 0;

   printf("Result = %s\n", buffer);

   /* Close socket. */

   close(data_socket);

   exit(EXIT_SUCCESS);
}


