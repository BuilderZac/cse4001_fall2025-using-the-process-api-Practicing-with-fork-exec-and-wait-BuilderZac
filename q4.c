#include <unistd.h>
int main() {
    if (fork() == 0) execl("/bin/ls", "ls", "-l", (char*)0); 
    return 0; 
}
