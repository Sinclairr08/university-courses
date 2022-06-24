#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;

	for(int i = 0; i < 4 ; i++)
		fork();

	sleep(10);

	return 0;
}
