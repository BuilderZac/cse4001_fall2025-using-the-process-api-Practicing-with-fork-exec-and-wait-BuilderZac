#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t c = fork();
    if (c == 0) {
        int st; 
	int w = wait(&st);
        printf("Child final words %d\n", w);
        _exit(25);
    } else {
        int st; 
	int w = waitpid(c, &st, 0);
        printf("Parent found body %d with code %d\n", w, WEXITSTATUS(st));
    }
    return 0;
}
