#include "bench.h"

UsageArg __usage;

void
static __print_usage_measure()
{
    printf("Elapsed time:%f sec\nUser time:%f sec\nSystem time:%f sec\n\n",
      (__usage.etime.tv_sec + __usage.etime.tv_usec/1000000.) -
      (__usage.stime.tv_sec + __usage.stime.tv_usec/1000000.),
      (__usage.r2.ru_utime.tv_sec + __usage.r2.ru_utime.tv_usec/1000000.) -
      (__usage.r1.ru_utime.tv_sec + __usage.r1.ru_utime.tv_usec/1000000.),
      (__usage.r2.ru_stime.tv_sec + __usage.r2.ru_stime.tv_usec/1000000.) -
      (__usage.r1.ru_stime.tv_sec + __usage.r1.ru_stime.tv_usec/1000000.));
}

void
set_time_mark()
{
    getrusage(RUSAGE_SELF, &(__usage.r1));
    gettimeofday(&(__usage.stime), NULL);
}

void
unset_time_mark()
{
    getrusage(RUSAGE_SELF, &(__usage.r2));
    gettimeofday(&(__usage.etime), NULL);
    __print_usage_measure();
}
