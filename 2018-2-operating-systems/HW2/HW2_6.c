#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		fprintf(stderr, "Fokr Failed");
		return 1;
	}

	else if(pid == 0)
	{
		exit(0);
	}

	else
	{
		sleep(90);
	}

	return 0;
}
