#include <stdio.h>
#include <string.h>

#include "shell.h"

int echo(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    	printf("%s\n",argv[i]);
    return 0;
}

static const shell_command_t commands[] = {
	{"echo","print out words",echo},
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("This is Task-02");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    //program never reaches here

    return 0;
}
