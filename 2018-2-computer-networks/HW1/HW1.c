/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementation of Binary File Copy
*
* Project name : Project 1
* File names : HW1.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.09.11
* Lastest revised date : 2018.09.11
*
* Operation System : Windows 10
*
* Modification histroy :
*
* ==================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD_SIZE 100
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char input[MAX_WORD_SIZE];
	char output[MAX_WORD_SIZE];

	int fcnt;

	printf("Input the file name : ");
	scanf("%s", input);

	FILE* src = fopen(input, "rb");

	printf("Input the new name : ");
	scanf("%s", output);

	FILE* des = fopen(output, "wb");

	if (!src || !des)
	{
		printf("File open is failed");
		return -1;
	}

	char buffer[BUFFER_SIZE];

	/* Read the datas in the source until there are no datas to read */
	while (fcnt = fread((void*)buffer, 1, sizeof(buffer), src))
	{
		/* If the read data is smaller than the size of the buffer */
		if (fcnt < sizeof(buffer))
		{
			/* If the source file reaches at the end of file */
			if (feof(src) != 0)
			{
				fwrite((void*)buffer, 1, fcnt, des);
				break;
			}

			/* If the source file does not reach at the end of file */
			else
			{
				printf("File copy is failed");
				return -1;
			}
		}

		else
			fwrite((void*)buffer, 1, sizeof(buffer), des);
	}

		
	FILE* log = fopen("log.txt", "w");
	fprintf(log, "file copy is done");
	
	fclose(src);
	fclose(des);
	fclose(log);

	return 0;
}