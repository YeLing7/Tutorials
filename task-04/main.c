#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "thread.h"
#include "xtimer.h"

char stack[THREAD_STACKSIZE_MAIN];

void *thread_handler(void *arg)
{
    (void) arg;
    while (1)
    {
       printf("%" PRIu32 "\n",xtimer_now());
       xtimer_usleep(2000000); 
    }
    
    return NULL;
}

int main(void)
{
    puts("This is Task-04");

    thread_create(stack, sizeof(stack),
                                     THREAD_PRIORITY_MAIN - 1,
                                     THREAD_CREATE_STACKTEST,
                                     thread_handler, NULL,
                                     "thread");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
