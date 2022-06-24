#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();

	/* error */
	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}

	/* Child  */
	else if(pid == 0)
	{
		sleep(10);
		execlp("/bin/ls", "ls", NULL);
		printf("LINE J");
	}

	/* Parent  */
	else
	{
		wait(NULL);
		printf("Child Complete");
	}

	return 0;
}
