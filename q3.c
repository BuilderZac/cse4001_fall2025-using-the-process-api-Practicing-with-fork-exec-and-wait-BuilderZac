#include <stdio.h>
#include <unistd.h>

int main() {
    int p[2];
    pipe(p);
    int rc = fork();
    if (rc == 0) {
        close(p[0]);
        printf("hello\n");
        write(p[1], "x", 1);
        _exit(0);
    } else {
        close(p[1]);
        char c;
        read(p[0], &c, 1);
        printf("goodbye\n");
    }
    return 0;
}
