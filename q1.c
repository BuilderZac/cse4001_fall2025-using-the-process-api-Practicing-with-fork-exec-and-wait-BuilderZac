#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;
    printf("hello world (pid:%d) & x is %d\n", (int) getpid(), x);
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d) & x is %d \n", (int) getpid(), x);
	x += 100;
	printf("As kid I rebelled & made x %d\n", x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
	x += 25;
	printf("As parent I added a bit & made x %d\n", x);
    }
    return 0;
}
