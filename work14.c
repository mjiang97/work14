#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

static void sighandler (int signo) {
    if (signo == SIGINT) {
        int file = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (file == -1) {
            printf("Error: %s\n", strerror(errno));
        }
        char b[] = "Program exited due to SIGINT.\n";
        int wr = write(file, b, sizeof(b));
        if (wr == -1) {
            printf("Error: %s\n", strerror(errno));
            return;
        }
        exit(0);
    }
    if (signo == SIGINT) {
        printf("PPID: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while(1) {
        printf("PID: %d\n", getpid());
        sleep(1);
    }
    return 0;
}