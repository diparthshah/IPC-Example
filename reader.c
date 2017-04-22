#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buffer[80];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buffer,sizeof(buffer));
    printf("Received String : %s\n", buffer);
    close(fd);

    return 0;
}