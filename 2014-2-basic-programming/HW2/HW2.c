/* 
 * Copyright (C) 2011-2012 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 1 of C Programming : if statement
 *
 * Summary of this lab : if문을 활용한 학점변환기 만들기
 *
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 * 
 * File name : 2014310407.이준혁.HW2.c
 * Written on October 1, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on October 3, 2014
 *	     (a) comment 수정
 *       (b) if문이 과도하게 복잡했던 것을 수정
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition 
 */

/* scanf, printf등의 함수를 이용하기 위한 헤더파일 stdio.h를 include */
#include <stdio.h>

int main(void) {  /* main 함수의 시작 */
    int grade;    /* 점수를 입력받기 위한 변수 */
    char credit;  /* 점수에 상응하는 학점을 출력하기 위한 변수 */

    /* 학점 출력을 위한 점수 입력 요구 */
    printf("중간고사 점수를 양의 정수로 입력하시오\n");

    /* 입력받은 정수값을 grade에 저장 */
    scanf("%d", &grade);

    /* 이 때 입력받은 정수가 0  이하면 재입력을 요구해야하므로 while문 사용 */
    while (grade < 0) {
        printf("ERROR : Grade must be a positive integer.\n"
               "중간고사 점수를 양의 정수로 다시 입력하십시오\n");/* 재입력 요구 */
        scanf("%d", &grade);
    }
    /*grade가 0 미만이면 while문이 반복되므로,
      while문을 나올 때 grade는 0 이상 */

    if (grade >= 85)
        credit = 'A';

    else if (grade >= 75)
        credit = 'B';

    else if (grade >= 65)
        credit = 'C';

    else if (grade >= 50)
        credit = 'D';

    else
        credit = 'F'; /* 점수에 따라 학점을 credit이라는 변수에 저장 */
                      /* 매 if문 마다 printf 함수를 쓰는 것보다
                         효율적이라 사료되었음 */

    /* 결과 메시지 출력 */
    printf("Your grade point is %d, and it is %c\n", grade, credit);

    return 0;
} /* main 함수의 끝 */