#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int x = 100;
    printf("x = %d, (pid:%d)\n", x, (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("x = %d in child, (pid:%d)\n", x, (int) getpid());
        x = 1;
        printf("changed x = %d  in child, (pid:%d)\n", x, (int) getpid());
    } else {
        // parent goes down this path (original process)
        printf("x = %d in parent, (pid:%d)\n", x, (int) getpid());
        x = 2;
        printf("changed x = %d  in parent, (pid:%d)\n", x, (int) getpid());
    }
    return 0;
}
