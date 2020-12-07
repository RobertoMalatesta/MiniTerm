#include <stdio.h>
#include <string.h>

#define IFS " "

int main()
{
	char str[1024];
	char example[1024][1024] = {"Nguyen", "Chi Trung", "Hello"};
	char *flags[1024];
	//printf("Example0: %s\n", example[0]);
	//printf("Example1: %s\n", &example[1]);

	//gets(str);
	//fgets(str, sizeof(str), stdin);
	
	/*
	get_command(str);
	printf("Enter: %s, size: %d\n", str, strlen(str));
	*/
	
	//parse_command(str, flags);
	
	//int i = 0;
	//char ** p = flags;
	//printf("=======%s+++++++\n", *p);
	/*
	for(i =0; i < strlen(str); i++)
	{
		if(str[i] != ' ')
		{
			printf("%c", str[i]);
			//flags[];
		}
		else 
		{
			printf("\n");
		}
	}	
	*/
	

	/*
	char *p = &example;
	printf("Check %s \n", &p[0]);
	gets(str);
	strcpy(p, str);
	printf("Check %s \n", &p[0]);
	printf("Example[0]: %s\n", example[0]);
	
	p = example[1];
	printf("Example1: %s\n", &example[1]);
	printf("Check: %s \n", &p[0]);
	*/
	
	/*
	char* p = &flags;
	int i;
	strcpy(&flags[0], &example[0][1]);
	strcpy(&flags[1], example[1]);
	printf("flags[0]: %s\n", &flags[0]);
	printf("flags[1]: %s\n", flags[1]);
	if(strcmp(flags[2], "") == 0)
	{
		printf("flags[2]: NULL\n");
	}
	else
	{
		printf("flags[2]: %s\n", &flags[2]);
	}
	*/


	
	printf("Command: ");
	gets(str);
	parse_command(str, flags);
	
	printf("In main flags[0]: %s\n", &flags[0]);
	printf("In main flags[1]: %s\n", &flags[1]);
	printf("In main flags[2]: %s\n", &flags[2]);
	/*
	printf("In main Flags[0] with &: %s\n", &flags[1024]);
	printf("In main flags[0] with & address: %p\n", &flags[1024]);
	printf("In main Flags[0] without &: %s\n", flags[1024]);
	printf("In main flags[0] without & address: %p\n", flags[1024]);
	printf("\n");
	*/


	//printf("Flags[2]: %s\n", flags[2]);
	/*	
	int i;
	for(i = 0; i < 3; i++)
	{
		printf("Flags[%d]: %s\n",i, flags[i]);
	}
	*/

	return 0;

}

void get_command(char* command)
{
	//fgets(command, 1024, stdin);
	gets(command);
}

void parse_command(char* command, char ** flags)
{	
	//strcpy(&flags[0], command);
	
	
	int i=0;
	char * pointer = strtok(command, IFS);
	printf("First command: %s\n", pointer);
	while(pointer != NULL)
	{
		strcpy(&flags[i++], pointer);
		pointer = strtok(NULL, IFS);
	}
	

	printf("Flags[0] with &: %s\n", &flags[0]); //must have "&" before flags[0]
	printf("----------\n");
	for(i = 0; i < 3; i++)
	{
		printf("Flag%d: %s\n",i, &flags[i]); 
	}
	
	printf("-----------\n");
	
}

void separate_command()
{

}

void
ssh()
{
}
