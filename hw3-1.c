#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    /*
    int fd[2];
    char buf[20]={"goodbye"};
    char buf1[20]={};
    if(pipe(fd) < 0) {
        //pipe failed; exit
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    */
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        //close(fd[0]);
        printf("hello\n");
        //write(fd[1], buf, sizeof(buf));
        //close(fd[1]);
    } else {
        // parent goes down this path (original process)
        //close(fd[1]);
        /*if(read(fd[0], buf1, sizeof(buf1)) == 0) {
            printf("not get\n");
        }
        else printf("%s\n",buf1);*/
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}