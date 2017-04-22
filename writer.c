#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";
    char str[10];

    printf("Enter String :  ");
    scanf("%s",str);
   
    /* create the FIFO */
    mkfifo(myfifo, 0666);
   
    /* write string to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd,str, (strlen(str)+1));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);
    return 0;
}
