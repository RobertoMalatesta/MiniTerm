#include <stdio.h>

void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

int takeInput(char* str)
{
	char* buf;
	
	buf = readline("\n>>> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		strcpy(str, buf);
		return 0;
	} 
	else 
	{
		return 1;
	}
}



int main()
{
	char inputString[1024], *parsedArgs[100];
	char* parsedArgsPiped[100];
	int execFlag = 0;
	//init_shell();

	while (1) 
	{
		printDir();
		if(takeInput(inputString))
			continue;
		//else
		//	printf("Command: %s\n", inputString);
		/*
		execFlag = processString(inputString, parsedArgs, parsedArgsPiped);

		if(execFlag == 1)
			execArgs(parsedArgs);
		if(execFlag == 2)
			execArgsPiped(parsedArgs, parsedArgsPiped);
		*/
	}
	return 0;
}
