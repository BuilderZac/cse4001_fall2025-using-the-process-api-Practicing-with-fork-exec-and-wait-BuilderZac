#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    if (fork() == 0) {
        close(1);
        printf("test \n");
        open("q7.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        printf("testING\n");
        _exit(0);
    }
    return 0;
}
