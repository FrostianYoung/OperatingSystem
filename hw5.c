#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    //int wc;
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //wc = wait(NULL);
        printf("child thread pid:%d wc:%d rc:%d\n", (int)getpid(), wait(NULL), rc);
    } else {
        printf("parent thread pid:%d wc:%d rc:%d\n", (int)getpid(), wait(NULL), rc);
    }
    return 0;
}
