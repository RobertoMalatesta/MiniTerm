#include <stdio.h>
#include <string.h>

#define IFS " "

int main()
{
	char str[1024];
	char example[1024][1024] = {"Nguyen", "Chi Trung", "Hello"};
	char flags[1024][1024];
	printf("Example0: %s\n", example[0]);

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

	char *p = &example;
	printf("Check %s \n", &p[0]);
	gets(str);
	strcpy(p, str);
	printf("Check %s \n", &p[0]);
	printf("Example[0]: %s\n", example[0]);
	
	p = example[1];
	printf("Example1: %s\n", &example[1]);
	printf("Check: %s \n", &p[0]);
	return 0;

}

void get_command(char* command)
{
	//fgets(command, 1024, stdin);
	gets(command);
}

void parse_command(char* command, char ** flags)
{
	int i;
	char * pointer;
	for(i = 0; i < strlen(command); i++)
	{
		if(command[i] != ' ')
		{
			*pointer = command[i];
		       pointer += 1;	
		}
		else 
		{
			pointer += 1024;
		}
	}


	printf("Flag1: %s", flags[1]); 
}
