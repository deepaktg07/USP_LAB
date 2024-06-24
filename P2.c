#include <stdio.h>
#include <unistd.h>
int main() {
 // Check and display _POSIX_VERSION constant
 printf("_POSIX_VERSION constant: %ld\n", _POSIX_VERSION);
 
#ifdef _POSIX_ASYNCHRONOUS_IO
 printf("POSIX Asynchronous I/O supported\n");
#endif

#ifdef _POSIX_BARRIERS
 printf("POSIX Barriers supported\n");
#endif

#ifdef _POSIX_CPUTIME
 printf("POSIX CPU Time supported\n");
#endif

#ifdef _POSIX_FSYNC
 printf("POSIX Fsync supported\n");
#endif

#ifdef _POSIX_IPV6
 printf("POSIX IPv6 supported\n");
#endif

#ifdef _POSIX_SEMAPHORES
 printf("POSIX Semaphores supported\n");
#endif

#ifdef _POSIX_SHELL
 printf("POSIX Shell supported\n");
#endif

#ifdef _POSIX_THREADS
 printf("POSIX Threads supported\n");
#endif

#ifdef _POSIX_TIMEOUTS
 printf("POSIX Timeouts supported\n");
#endif

#ifdef _POSIX_TIMERS
 printf("POSIX Timers supported\n");
#endif

#ifdef _POSIX_TRACE
 printf("POSIX Trace supported\n");
#endif

return 0;
}
