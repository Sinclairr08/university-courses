/*==================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 3 of C Programming : Flow of control
 *
 * Summary of this lab : 조건문, 반복문등을 이용한
 *                       평점 평균을 구하는 프로그램 작성
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 * 
 * File name : 2014310407.이준혁.HW3.c
 * Written on October 8, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on October 9, 2014
 *	     (a) comment 수정
 *    2. by Jun Hyuk Lee on October 9, 2014
 *	     (a) main 함수, 헤더파일 등에 대한 코멘트 추가
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition 
 *================================================================*/

/*printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입*/
#include <stdio.h>

int main(void) {
    /* 메인 함수의 시작
     * Input : none
     * Output : 0 */
    char Math_credit, Eng_credit; /*수학, 영어 학점을 입력받기 위한 학점 변수*/
    float Math_grade, Eng_grade;  /*각각의 평점을 계산, 출력하기 위한 평점 변수*/

    do {
       /* 사용자에게 학점 입력 요구
        * 소문자와 대문자가 다르므로 대문자로 작성할 것을 요구 */
        printf("영어와 수학의 학점을 순서대로 대문자로 입력하십시오\n");

        /* 변수를 입력받는 과정에서 <Enter>키가 항상 들어가는데
         * while문이 반복되면서 이 <Enter>키를 하나의 문자로 인식해
         * 변수값에 <Enter>, 즉 \n이 들어가는 것을 방지하기 위해
         * 첫 %c 앞에 공백을 두었다. */
        scanf(" %c%c", &Eng_credit, &Math_credit);

        /* 수학, 영어 학점 중 하나라도 E가 있으면 do - while 문을 빠져나감*/
        if ((Math_credit == 'E') || (Eng_credit == 'E'))
            break;

        /* 주어진 영어 학점에 따라 영어 평점이
         * 다르게 저장되도록 if-else 문을 이용해 표현*/
        if (Eng_credit == 'A')
            Eng_grade = 4.0;
        else if (Eng_credit == 'B')
            Eng_grade = 3.0;
        else if (Eng_credit == 'C')
            Eng_grade = 2.0;
        else if (Eng_credit == 'D')
            Eng_grade = 1.0;
        else if (Eng_credit == 'F')
            Eng_grade = 0.0;
        else
            printf("영어 학점의 오류입니다.\n"), Eng_grade = -1.0;
        /* A,B,C,D,F가 아닌 경우에는 오류 메시지 출력
         * 이 때는 평균을 계산하지 않으므로 평점 변수를 일단 음수값으로 두고
         * 나중에 평점 변수가 양수인 경우만 출력하기로 함 */

        /* 주어진 수학 학점에 따라 수학 평점이 다르게 저장되도록
         * switch 문을 이용해 표현 */
        switch (Math_credit) {
            case 'A' : Math_grade = 4.0; break; /* 문자형 상수 이므로 */
            case 'B' : Math_grade = 3.0; break; /* 작은 따옴표 사용 */
            case 'C' : Math_grade = 2.0; break;
            case 'D' : Math_grade = 1.0; break;
            case 'F' : Math_grade = 0.0; break;
            default : printf("수학 학점의 오류입니다.\n"),
                      Math_grade = -1.0; break;
            /* 마찬가지로 A,B,C,D,F가 아닌 경우에는
             * 오류 메시지 출력 후 평점 변수를 음수값으로 둠 */
        }

        if ((Math_grade >= 0.0) && (Eng_grade >= 0.0))
            printf("%.2f\n", (Math_grade + Eng_grade)/2);
        /* 평점 변수가 하나라도 음수이면 제대로 된 입력이 아닌 경우 이므로
         * 두 변수 모두 양수인 경우만 출력 */
    }while(1);
     /* E가 입력되기 전까지는 계속 반복되어야 하므로
      * while문을 검사하는 곳에 1을 두어 항상 참이 되게 함 */

    return 0;/* 0으로 반환, 메인 함수의 끝 */
}
