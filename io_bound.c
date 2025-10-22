#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  int i;
  int pid;

  printf(1, "Starting I/O-bound process :)\n");

  // Fork a child process to run ps
  pid = fork();
  if (pid == 0) {
    // child: show process table while parent is doing I/O
    sleep(20); // thoda delay taaki parent kuch iterations run kar le
    printf(1, "\n *** Child running ps ***\n");
    char *argv[] = { "ps", 0 };
    exec("ps", argv);
    printf(1, "exec failed in child\n");
    exit();
  }

  // parent: simulate I/O work (sleep heavy)
  for (i = 0; i < 50; i++) {
    printf(1, "I/O operation %d\n", i);
    sleep(10); // simulates waiting for I/O
  }

  printf(1, "I/O-bound process finished! Waiting for child :) \n");

  // wait for child to finish (avoid zombie)
  wait();

  printf(1, "Child finished. No zombie!\n");
  exit();
}

