#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <sys/time.h>
#include <sys/resource.h>

#ifndef BENCH_H
#define BENCH_H

typedef struct {
    struct timeval stime, etime;
    struct rusage r1, r2;
} UsageArg;

void set_time_mark();
void unset_time_mark();
#endif /* BENCH_H */

