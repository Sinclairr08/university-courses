/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Implementation of Concurrent File Copy
*
* Project name : HW2
* File names : HW2.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.09.23
* Lastest revised date : 2018.09.29
*
* Operation System : Ubuntu 1804
*
* Modification histroy :
*
* ==================================================================================*/

#define MAX_WORD_SIZE 100
#define MAX_FILE_SIZE 100
#define BUFFER_SIZE 1024
#define HAVE_STRUCT_TIMESPEC

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* In oreder to pass the parameter to the thread function, use a new structure */
typedef struct
{
	char input_name[MAX_WORD_SIZE];
	char output_name[MAX_WORD_SIZE];
	FILE* src;
	FILE* des;
}FILE_ptrs;

/* To do the concurrent file copy, use thread function */
void *thread_copy(void* file_ptr)
{
	/* To record the time */
	static clock_t program_start;

	/* The first function call is with the NULL pointer, and it gives an initializaion */
	if(file_ptr == NULL)
	{
		/* Record the time and remove the preexisting log file */
		program_start = clock();
		FILE* log = fopen("log.txt","w");
		fclose(log);
		return NULL;
	}

	/* Use the given parameters */
	FILE_ptrs* file_p = (FILE_ptrs*)file_ptr;
	int fcnt;
	char buffer[BUFFER_SIZE];						// Literally, it roles the buffer

	/* Record the starting progress to the log file */
	FILE* log = fopen("log.txt", "a+");
	clock_t copy_start = clock();

	fprintf(log, "%f\t", (float)(copy_start - program_start) / CLOCKS_PER_SEC);
	fprintf(log, "Start copying %s to %s\n", file_p->input_name, file_p->output_name);

	fclose(log);
	
	/* Read the datas in the source until there are no datas to read */
	while (fcnt = fread((void*)buffer, 1, sizeof(buffer), file_p->src))
	{
		/* If the read data is smaller than the size of the buffer */
		if (fcnt < sizeof(buffer))
		{
			/* If the source file reaches at the end of file */
			if (feof(file_p->src) != 0)
			{
				fwrite((void*)buffer, 1, fcnt, file_p->des);
				break;
			}

			/* If the source file does not reach at the end of file */
			else
			{
				printf("File copy is failed");
				exit(1);
			}
		}

		else
			fwrite((void*)buffer, 1, sizeof(buffer), file_p->des);
	}

	/* Record the ending progress to the log file */
	log = fopen("log.txt", "a+");
	clock_t copy_end = clock();
	fprintf(log, "%f\t", (float)(copy_end - program_start) / CLOCKS_PER_SEC);
	fprintf(log, "%s is copied completely\n", file_p->output_name);
	
	fclose(log);

	fclose(file_p->des);
	fclose(file_p->src);
	pthread_exit(NULL);

}

int main()
{
	FILE_ptrs file_p[MAX_FILE_SIZE];
	pthread_t p_thread[MAX_FILE_SIZE];
	int i = 0;

	/* Give the parameter as a NULL, and it means initialization */
	thread_copy(NULL);

	while (1){
		/* Get an existing file name */
		printf("Input the file name : ");
		scanf("%s", file_p[i].input_name);

		file_p[i].src = fopen(file_p[i].input_name, "rb");

		/* If there is no file, exit the program */
	        if (!file_p[i].src)
		{
			printf("File open is failed\n");
			return -1;
		}

		/* Get an file name which will be copied */
		printf("Input the new name : ");
		scanf("%s", file_p[i].output_name);

		file_p[i].des = fopen(file_p[i].output_name, "wb");

		/* If file open is failed, exit the program */
		if (!file_p[i].des)
		{
			printf("File open is failed\n");
			return -1;
		}

		/* Using multithread, run the copy function in background */
		pthread_create(&p_thread[i], NULL, thread_copy, &file_p[i]);
		i++;
	}
	
	return 0;
}
