#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <stdbool.h>


/*define*/
#define USER "trungpc_command: "
#define WAIT_FOR_COMMAND(x) printf("%s", x)
#define IN_SESSION true
#define STOP_SESSION false
#define MAX 1024
#define MAX_COMMAND 256
#define MAX_ARGC 16
/*********************************************/


/*global*/
bool stt = IN_SESSION;
/********************************************/

int main()
{
	WAIT_FOR_COMMAND(USER);
	char full_command_string[MAX_COMMAND];
	get_command(full_command_string);
	/*
	printf("%s\n", full_command_string);
	*/
}

typedef struct 
full_command
{
	int arg_c;
	char arg_v[MAX_ARGC];
} command;

void 
get_command(char* full_command_string)
{
	/*this function is safe, but there is a "\n" at the end of command*/
	/*
	fgets(full_command, strlen(full_command), stdin);
	*/


	gets(full_command_string);
	return;
}

void
parse_command(char* full_command_string, command last_command)
{
	int i, cur_arg = 0;
	for(i = 0; i < strlen(full_command_string); i++)
	{
		if(full_command_string[i] == ' ')
		{
			strcpy();
		}
	}
}

void
ssh()
{
}

void
ftp()
{
}
