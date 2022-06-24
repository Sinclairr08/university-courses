/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Dynamic programming EX
*
* Project name : HW3
* File names : 2014310407_HW3C.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.05.09
* Lastest revised date : 2018.05.09
*
* Operation System : Windows 10
*
* Modification histroy :
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_INPUT_SIZE 51

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The function which fills dp, for the minimum number of changes */
void Sleep_Raccoons(char* input, int size, int i, long long** dp);

/* Calculate 2^num by using recursion */
long long Exp_2(int num);

int main()
{
	int size;
	char* input = (char*)malloc(sizeof(char) * MAX_INPUT_SIZE);

	scanf("%s", input);
	size = strlen(input);

	/* Make N * 2 size storage */
	long long** dp = (long long**)malloc(sizeof(long long*) * size);

	for(int i = 0; i < size; i ++)
		dp[i] = (long long*)malloc(sizeof(long long) * 2);
	
	/* Fill dp. dp[0][0] is the minimum number of changes to sleep all raccoons */
	Sleep_Raccoons(input, size, size - 1, dp);
	printf("%lld\n", dp[0][0]);
	
	free(input);
	for (int i = 0; i < size; i++)
		free(dp[i]);

	free(dp);

	return 0;
}

/* The function which fills dp, for the minimum number of changes */
void Sleep_Raccoons(char* input, int size, int i, long long** dp)
{
	/* Base case */
	if (i == size - 1)
	{
		if (input[i] == '0')
		{
			dp[i][0] = 0;
			dp[i][1] = 1;
		}

		if (input[i] == '1')
		{
			dp[i][0] = 1;
			dp[i][1] = 0;
		}
		
		
	}

	else
	{
		/* if ith raccoon is 0 */
		if (input[i] == '0')
		{
			/* The number of change is same with i + 1 */
			dp[i][0] = dp[i + 1][0];

			/* Awake i + 1th raccoon, Awake ith raccoon, Sleep i + 1th raccoon */
			dp[i][1] = dp[i + 1][1] + Exp_2(size - i - 1);
		}

		/* if ith raccoon is 1 */
		else
		{
			/* Awake i + 1th raccoon, Sleep i + 1th raccoon, Sleep ith raccoon */
			dp[i][0] = dp[i + 1][1] + Exp_2(size - i - 1);

			/* The number of change is same with i + 1 */
			dp[i][1] = dp[i + 1][0];
		}

	}

	/* If raccoons are remained, recursively fill dp by reducing i */
	if (i != 0)
		return Sleep_Raccoons(input, size, i - 1, dp);

	/* If there are no raccoons are left */
	else return;

}

/* Calculate 2^num by using recursion */
long long Exp_2(int num)
{
	if (num == 0)
		return 1;

	if (num % 2 == 0)
	{
		long long temp = Exp_2(num / 2);
		return temp * temp;
	}

	else
		return 2 * Exp_2(num - 1);
}