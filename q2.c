#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("q2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    int rc = fork();
    if (rc == 0) {
        for (int i = 0; i < 5; i++) dprintf(fd, "Child Test %d\n", i);
        _exit(0);
    } else {
        for (int i = 0; i < 5; i++) dprintf(fd, "Parent Test %d\n", i);
    }
    return 0;
}
