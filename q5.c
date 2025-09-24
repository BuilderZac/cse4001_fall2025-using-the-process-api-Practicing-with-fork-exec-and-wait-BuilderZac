#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int rc = fork();
    if (rc == 0) {
        int st;
	int w = wait(&st);
        printf("Child final words %d\n", w);
        _exit(25);
    } else {
        int st;
	int w = wait(&st);
        printf("Parent found body %d with code %d\n", w, WEXITSTATUS(st));
    }
    return 0;
}
