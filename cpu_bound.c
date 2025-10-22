#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  int i;
  int pid;

  printf(1, "Starting CPU-bound process :) \n");

  pid = fork();
  if (pid == 0) {
    // Child: run ps
    sleep(10);
    printf(1, "\n *** Child running ps *** :)\n");
    char *argv[] = { "ps", 0 };
    exec("ps", argv);
    printf(1, "exec failed in child\n");
    exit();
  }

  // Parent: CPU intensive loop
  for (i = 0; i < 100000000; i++) {
    asm("nop");
  }

  printf(1, "\nCPU-bound process finished! Waiting for child\n");
  wait();
  printf(1, "Child finished. No zombie!\n");

  exit();
}

