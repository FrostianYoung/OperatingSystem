#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    int fd = open("./hw2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    if (rc < 0) {
        // fork failed; exit
        close(fd);
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *s = "child\n";
        write(fd, s, strlen(s));
    } else {
        char *s = "parent\n";
        write(fd, s, strlen(s));
        wait(NULL);
        close(fd);
    }
    return 0;
}
