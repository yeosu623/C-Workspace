#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t p;
	int i = 0;
	
	for(i = 0; i < 3; i++)
	{
		p = fork();
	}
	
	if(p == -1)
	{
		puts("error");
	}
	else if(p == 0)
	{
		char* args[] = {"echo", "child", NULL};
		
		execvp("echo", args);
	}
	else 
	{
		char* args[] = {"echo", "parent", NULL};
		
		execvp("echo", args);
	}
	
	return 0;
}
