#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo){
  printf("\n%d?\nGoodbye!\n\n", signo);
  exit(1);
}

int main(){
  while (1) {
    signal(SIGTERM, sighandler);
    signal(SIGINT, sighandler);

    printf("Greetings from process %d!\n", getpid());
    sleep(1);
  }
}
