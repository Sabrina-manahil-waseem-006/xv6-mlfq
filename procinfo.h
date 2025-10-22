// procinfo.h — shared between kernel & user

#ifndef PROCINFO_H
#define PROCINFO_H

struct procinfo {
  int pid;
  int priority_level;
  int ticks_run;
  int state;
  int level;
  int ticks;
  int sched_count;
  char name[16];  
};


#endif
