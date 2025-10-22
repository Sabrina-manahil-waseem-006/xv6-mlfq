#include "types.h"
#include "stat.h"
#include "user.h"
#include "procinfo.h"  // has your struct procinfo

// Process state strings
static char *states[] = {
  [0] "UNUSED",
  [1] "EMBRYO",
  [2] "SLEEPING",
  [3] "RUNNABLE",
  [4] "RUNNING",
  [5] "ZOMBIE"
};

int
main(void)
{
  struct procinfo info;
  int pid;

  printf(1, "\n--- Process Table (Including ZOMBIES) ---\n");

  for (pid = 1; pid < 64; pid++) {
    if (getprocinfo(pid, &info) == 0) {
      if (info.state != 0) {
        printf(1,
          "PID: %d | State: %s | Level: %d | Priority: %d | "
          "Ticks Run: %d | Scheduled: %d | Name: %s\n",
          info.pid,
          states[info.state],
          info.level,
          info.priority_level,
          info.ticks_run,
          info.sched_count,
          info.name);
      }
    }
  }

  exit();
}
