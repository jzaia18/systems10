#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGINT) {
    int fd = open("logfile.txt", O_APPEND | O_RDWR);
    write(fd, "SIGINT\n", 8);
    close(fd);
    printf("\nGoodbye!\n\n");
    exit(1);
  } else if (signo == SIGUSR1)
    printf("\n%d stopped!\n", signo);
}

int main(){
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while (1) {
    printf("Greetings from process %d!\n", getpid());
    sleep(1);
  }
}
