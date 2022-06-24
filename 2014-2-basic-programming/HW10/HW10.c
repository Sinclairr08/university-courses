/*================================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min and Jun Hyuk Lee, All rights reserved.
 *
 * Lab 10 of C Programming : I/O and Files
 *
 * Summary of this lab : 주어진 file을 입력으로 받아서 GPA를 계산한 후
 *                       다른 file로 출력하는 프로그램 작성
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 *
 * File name : 2014310407.이준혁.HW10.c
 * Written on December 10, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on December 13
 *       (a) comment 추가
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================================*/

/* fscanf, fopen, 등의 file관련 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* dynamic memory allocation을 사용하기 위한 헤더 파일 삽입 */
#include <stdlib.h>

/* STUDENT라는 structure를 선언. STUDENT type으로 선언된 변수는
 * 이름, 나이, 성적을 담을수 있도록 선언됨
 * function prototype에서 사용되므로 그 이전에 선언*/
typedef struct _student {
    char  name[10];
    int   age;
    char  grades[5]; /* 성적이 5개 이므로 */
} STUDENT;


/* sizeof(STUDENT)?
 * 문자형 변수와 정수형 변수가 뒤섞여 있을 때 계산속도 때문에 문자형 변수가 정수형
 * 변수의 크기만큼 (내 컴퓨터에서는 4byte) 메모리의 크기를 잡는 다는 사실은 알고
 * 있었다. 그러나 문자형 array와 정수형 변수가 섞여 있을 때 크기를 어떻게 할당받는 지
 * 알지 못해서 몇 번 예측해 봤는데, 다 틀렸다. 결과로 24가 나왔다. 왜 24가 나왔는지
 * 곰곰이 생각해 보니 처음 name이라는 10개의 문자형 array의 메모리를 우선 할당받는다.
 * 이 때 10개의 1byte짜리 메모리를 연속적으로 잡게 된다. 그 다음에 정수형 변수가 오기
 * 때문에, 문자형 변수가 4byte씩 단위 지어서 나뉠 것이라 보았다.(정수형 변수의 크기가
 * 4byte이므로). 그런데 4+4+2개, 총 10개의 array가 있으므로, 4byte짜리 메모리를 세 개
 * 잡게 된다. 그리고 마지막 4byte짜리 메모리에는 2byte만 채워지게 될 것이라 생각했다.
 * 그 다음에 바로 붙어서 정수가 올 수 없으므로, 정수형 변수는 2byte를 건너뛰고 다음
 * 지역에 4byte짜리 메모리를 잡게 될 것이라 보았다. 그 다음에는 또 grades라는 5개의
 * 문자형 array가 있으므로, 그것이 메모리를 잡는데 역시 4byte 단위로 자리를 잡을
 * 것이었다. 4+1이므로, 4byte짜리 메모리를 2개 잡은 후 두 번째 메모리에 1byte만
 * 메모리를 채우고 나머지 3byte를 비워둘 것이다. 이렇게 되면 빈 메모리를 포함해 총
 * 4byte짜리 메모리를 총 6개 잡게 되므로, 24byte가 나온다고 예측할 수 있었다.
 * 그리고 실제로 24byte가 나오게 되었다.
 *
 * 그러나 이 것은 windows가 meomory를 잡을 때 이렇게 빈 공간을 만들어서 잡고,
 * 또 내 컴퓨터에서 정수형 변수(정확히는 int type)의 크기가 4byte여서 이렇게
 * 예측 가능했다. 만약 메모리 잡는 법이나 정수형 변수의 크기가 달라진다면
 * sizeof(STUDENT)는 분명히 다른 값을 가지게 될 것이다.
 */


/* 함수 진행에 필요한 Function prototypes 선언 */
void Fill_struct(FILE *ifp, STUDENT *students, int num_students);

void Get_average(STUDENT *students, int num_students, FILE *ofp);

void Compute_GPA(STUDENT *students, int num_students, FILE *ofp);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    /* 변수 선언 */
    STUDENT *students;     /* 학생들을 담을 array를 포인터로 선언 */
    int  num_students = 7; /* 학생 수가 7명이므로 */
    FILE *ifp, *ofp;       /* 입/출력을 담당할 FILE type의 포인터 */

    /* students라는 pointer에 동적 메모리 할당을 통해 array처럼 data를
     * 담을 공간을 만들어 줌. 만약 메모리 할당 실패시 오류 메시지 출력 */
    students = (STUDENT *)malloc(num_students*sizeof(STUDENT));
    if (!students) { /* 반환된 값이 NULL일 때 */
        fprintf(stderr, "Out of memory.\n");
        return -1;   /* main함수의 비정상적인 종료 */
    }

    /* student.txt라는 읽을 파일과 result.txt라는 쓸 파일을
     * 각각 염. (이 파일과 같은 위치에 student.txt가 있다고 전제) */
    ifp = fopen("students.txt", "r");
    ofp = fopen("result.txt", "w");

    /* fopen 함수가 반환한 값이 NULL인지 검사 후 NULL이면 오류 메시지 출력 */
    if (ifp == NULL || ofp == NULL) {
        fprintf(stderr, "Can't open file.\n");
        return -1;
    }

    /* structure를 파일로 부터 읽어들인 값으로 채우는 함수를 이용해
     * 값 할당 */
    Fill_struct(ifp, students , num_students);

    /* 읽기가 목적인 file(student.txt)을 다 읽었으므로 file 닫음 */
    fclose(ifp);

    /* 학생들의 나이 평균을 구하는 함수를 이용해 학생들의 나이 평균을 구함 */
    Get_average(students, num_students, ofp);

    /* GPA를 구하는 함수를 이용해 학생들의 GPA를 구함 */
    Compute_GPA(students, num_students, ofp);

    /* 출력이 끝났으니 출력이 목적이었던 file(result.txt)을 닫음.
     * 또 동적 메모리 할당을 한 students의 메모리를 반환 */
    fclose(ofp);
    free(students);

    return 0;  /* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 STUDENT type의 array(pointer)를 file에서 읽은 내용으로
 * 채우는 역할을 한다.이 때 array의 한 원소는 한 학생을 나타내므로,
 * 각 학생들의 이름, 나이 , 성적을 채운다고 볼 수 있다.
 *
 * 이 때 fscanf함수를 이용해 입력을 받으며, 이로 인해서 string을 
 * white space character를 기준으로 입력받게 된다. 그러나 문자를 입력받을 때는
 * white space character를 입력받을 수 있으므로 이를 방지하기 위해 " %c"를 이용한다.
 *
 * 또, array의 크기(학생의 수)를 입력으로 받는데 이는 몇 번째 array까지 입력을
 * 받아야 하는 지 알기 위함이다.
 *
 * Input  : main에서 읽기를 목적으로 연 file의 pointer와, array의 역할을 하는
 *          STUDENT type의 pointer, 그리고 그 array의 크기를 받아들인다.
 *          이 때 array 내부의 한 원소는 한 학생을 나타내고, array의 크기는
 *          학생의 수를 나타낸다.
 *
 * Output : return을 통한 반환은 없으나, fscanf 함수를 이용해 main에 선언된
 *          STUDENT type의 array에 함수에서 읽은 값들을 채워넣는다.
 */
void Fill_struct(FILE *ifp, STUDENT *students, int num_students) {
    /* 학생을 세기 위한 변수와 성적을 세기 위한 변수 선언 */
    int count1, count2;

    /* 각 학생의 이름, 나이, 성적값을 file로 부터 읽어들인 값으로 할당
     * 하는 for문 이용*/
    for (count1 = 0; count1 < num_students; ++count1) {
        fscanf(ifp, "%s %d", students[count1].name, &students[count1].age);

        /* 성적을 읽을 때 한 문자씩 읽어서 할당 */
        for (count2 = 0; count2 < 5; ++count2)   /* 5개의 성적이 있으므로 */
            fscanf(ifp, " %c", &students[count1].grades[count2]);
    }
}

/*
 * 이 함수는 STUDENT type의 array에 저장되어 있는 원소(학생)들의 age(나이)라는
 * member의 평균을 내는 함수이다. 다시말해, 학생들의 평균 나이를 구하는 함수이다.
 *
 * 이 때 평균 나이를 구한 후에, 그것을 콘솔 창에 띄울 뿐만 아니라 result.txt
 * 라는 file에 그 내용을 쓴다 (출력한다).
 *
 * 그 외에 return을 통한 출력이 필요한 것은 아니므로, 함수의 반환 type은 void이다.
 *
 * Input  : 평균 나이을 구할 학생들이 저장되어 있는 array와 그 array의 크기,
 *          그리고 그 내용이 쓰여질 main에서 연 파일의 포인터를 입력으로 받는다.
 *
 * Output : return을 통한 output은 없으나, 콘솔 창과 result.txt 파일에 평균
 *          나이를 구한 내용이 출력된다. (file에 쓰여진다.)
 */
void Get_average(STUDENT *students, int num_students, FILE *ofp) {
    /* 평균 나이와 셈을 계산하기 위한 변수 선언 */
    double average_age = 0;
    int cnt = 0;

    /* 각 학생들의 나이를 다 더한 후 학생 수로 나누어 평균 나이를 구함 */
    while (cnt < num_students) {
        average_age += students[cnt].age;
        cnt++;
    }
    average_age /= num_students;

    /* 평균 나이를 콘솔 창과 file에 각각 출력 */
    printf("Average age : %.2lf", average_age);
    fprintf(ofp, "%s%.2lf", "Average age : ", average_age);

    putchar('\n');
    putchar('\n');
    putc('\n', ofp);
    putc('\n', ofp);
}

/*
 * 이 함수는 STUDENT type의 array에 저장되어 있는 원소들의 grade라는 변수의 
 * GPA를 구하는 함수이다. 다시 말해, 각 학생들의 성적 GPA를 계산하고 출력하는
 * 함수이다.
 *
 * 각 학생의 grade를 A는 4.0, B는 3.0, C는 2.0, D는 1.0의 평점으로 변환해,
 * 그 평균을 낸다. 그 후 출력 file(result.txt)와 콘솔 창에 각각 출력한다.
 * 이 과정을 모든 학생에 대해 시행한다.
 *
 * 이 함수 역시 return을 통한 출력이 필요 한 것이 아니므로, 함수의 반환 type은
 * void이다.
 *
 * Input  : 각 GPA를 구할 학생들이 저장되어 있는 array와 그 array의 크기,
 *          그리고 그 내용이 쓰여질 main에서 연 파일의 포인터를 입력으로 받는다.
 *
 * Output : return을 통한 output은 없으나, 콘솔 창과 result.txt 파일에 각 학생의
 *          GPA를 구한 내용이 출력된다. (file에 쓰여진다.)
 */
void Compute_GPA(STUDENT *students, int num_students, FILE *ofp) {
    /* 몇 번째 학생인지 세기 위한 변수와 몇 번째 성적인지 세기 위한 변수
     * 선언. 또, 각 학생의 GPA를 계산하기 위한 실수형 변수 선언 */
    int count1, count2;
    double GPA = 0;

    /* 이름과 GPA라는 항목이라는 것을 보여줌 */
    printf("%s \t%s\n", "Name", "GPA");
    fprintf(ofp, "%s \t%s\n", "Name", "GPA");

    /* 모든 학생에 대해서 GPA를 구하는 for문 실행 */
    for (count1 = 0; count1 < num_students; ++count1) {
        /* 학생의 grade가 무엇인지에 따라 GPA값에 적절한 값을 대입하는 
         * for 문. 성적이 총 5개이므로 5번 반복 수행 */
        for (count2 = 0; count2 < 5; ++count2)
            switch (students[count1].grades[count2]) {
            case 'A' : GPA += 4.0; break;
            case 'B' : GPA += 3.0; break;
            case 'C' : GPA += 2.0; break;
            case 'D' : GPA += 1.0; break;
            /* A, B, C, D가 아닐 때 오류임을 밝히고 프로그램 종료 */
            default : printf("Error! grade must be A, B, C or D!\n");
                      exit(1);
        }
        GPA /= 5; /* GPA를 과목 수(성적의 수)로 나눔 */

        /* 구해진 GPA 값과 이름을 콘솔창에 출력하고 file에도 씀 */
        printf("%s  %.2lf\n", students[count1].name, GPA);
        fprintf(ofp, "%s  %.2lf\n", students[count1].name, GPA);
        GPA = 0; /* 다음 학생의 GPA를 구하기 위해 0으로 초기화 */
    }
}
