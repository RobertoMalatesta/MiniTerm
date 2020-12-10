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
#define IFS " "
/*********************************************/


/*global*/
bool stt = IN_SESSION;
/********************************************/

typedef struct
full_command
{
	int arg_c;
	char *arg_v[MAX_COMMAND];
} command;

int main()
{
	WAIT_FOR_COMMAND(USER);
	char full_command_string[MAX_COMMAND];
	command last_command;
	get_command(full_command_string);
	parse_command(full_command_string, &last_command);
	
	int i;
	
	//printf("In main flags[0]: %s\n", &last_command.arg_v[0]);

	printf("Number of command: %d\n", last_command.arg_c);	
	for(i = 0; i < last_command.arg_c; i++)
	{
		printf("%s\n", &last_command.arg_v[i]);
		
	}
	
}

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
parse_command(char* full_command_string, command* last_command_ptr)
{
	int i=0;
	char * ptr = strtok(full_command_string, IFS);
	last_command_ptr->arg_c = 0;
	while(ptr != NULL)
	{
		strcpy(&last_command_ptr->arg_v[i++], ptr);
		ptr = strtok(NULL, IFS);
		last_command_ptr->arg_c += 1;
	}
	
}

void
list()
{
	printf("LIST\n");
	pritnf("TEST");
}
void
ssh()
{
	printf("SSH\n");
}

void
ftp()
{
}
