/*==================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 4 of C Programming : Functions
 *
 * Summary of this lab : Function을 이용한 factorial과
  *                      exponent를 계산하는 프로그램 작성
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 * 
 * File name : 2014310407.이준혁.HW4.c
 * Written on October 15, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on October 15, 2014
 *	     (a) logic 수정
 *    2. by Jun Hyuk Lee on October 17, 2014
 *       (a) comment 추가
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================*/

/*printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입*/
#include <stdio.h>

/* function prototype
 * factorial 함수와 exponent 함수 선언 */
int factorial(int factorial_num);
int exponent(int base_num, int exponent_num);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    /* factorial과 exponent를 계산하기 위해 입력받는 변수들과
     * 결과 값들을 나타내는 변수들의 선언 */
    int factorial_num;          /* factorial 입력값 */
    int base_num, exponent_num; /* exponent  입력값 */
    int factorial_result;       /* factorial 출력값 */
    int exponent_result;        /* exponent  출력값 */

    /* factorial 을 구하는 과정
     * n!을 구하기 위해 사용자에게 n 입력을 요구 */
    printf("구하고 싶은 factorial 값을 입력하십시오\n");
    scanf("%d", &factorial_num);

    /* n < 0인 경우는 고려할 수 없으므로
     * while문을 이용해 재입력을 요구 */
    while (factorial_num < 0) {
        printf("0 미만의 factorial값은 계산할 수 없습니다.\n"
               "0 이상의 정수값으로 다시 입력하십시오\n");
        scanf("%d", &factorial_num);
    }

    /* function call 을 이용해 factorial 값 계산 */
    factorial_result = factorial(factorial_num);

    /* exponent 를 구하는 과정
     * a^b를 구하기 위해 사용자에게 a,b 입력을 요구 */
    printf("구하고 싶은 exponent의 밑과 지수를 입력하십시오\n");
    scanf("%d %d", &base_num, &exponent_num);

    /* b < 0인 경우와 a와b가 동시에 0인 경우는 고려할 수 없으므로
     * while문과 if문을 이용해 재입력을 요구
     * 위 두가지가 아닌 경우만 while문 탈출 */
    while (1) {
        if (exponent_num < 0) {
         printf("0 미만의 지수승은 계산할 수 없습니다.\n"
                "지수를 0 이상의 정수값으로 밑과 함께 다시 입력하십시오\n");
         scanf("%d %d", &base_num, &exponent_num);
        } else if ((exponent_num == 0) && (base_num == 0)) {
            printf("0의 0승은 정의되지 않습니다.\n"
                   "0의 0승이 아닌 값으로 지수와 밑을 다시 입력하십시오\n");
            scanf("%d %d", &base_num, &exponent_num);
        } else {
            break;
        }
    }

    /* function call 을 이용해 exponent 값 계산 */
    exponent_result = exponent(base_num, exponent_num);

    /* 계산된 factorial값과 exponent값을 출력 */
    printf("%d! = %d\n", factorial_num, factorial_result);
    printf("%d^%d = %d\n", base_num, exponent_num, exponent_result);

    return 0;/* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/* function definition
 * 이 함수는 주어진 정수 값의 factorial 값을 출력하는 함수이다.
 * 즉, 주어진 정수값에 대해 그 값보다 작거나 같은 모든 양의 정수값을 곱해서
 * 나온 값을 출력하는 함수이다. for문을 이용한다.
 * 다만 음수에서는 정의되지 않으며, 0!은 1로 둔다.
 * 
 * Input : int facotorial_num : 사용자가 입력하는 값이다.
 * 
 * Output : int factorial_ result
 *          이 값은 (factorial_num)! 과 같다.
 */

int factorial(int factorial_num) {
    int number, factorial_result = 1;
    for (number = 1; number <= factorial_num; number++)
        factorial_result *= number;
    /* 1보다 같거나 크고 factorial_num보다 작거나 같은 number들을 모두 곱한다.
     * 단,  factorial_num이 0이면 factorial_result의 초기값인 1을 출력한다.*/
    return factorial_result;
}

/* function definition
 * 이 함수는 주어진 정수로 된 밑과 지수의 exponent 값을 출력하는 함수이다.
 * 즉, 주어진 밑 값을 지수 번 곱해서 나온 값을 출력하는 함수이다.
 * while 문을 이용한다. 다만 지수가 음수일 때는 정의되지 않으며,
 * a^0은 1로 둔다. 단, 0^0일 때는 정의하지 않는다.
 *
 * Input : int base_num, int exponent num : 사용자가 입력하는 값이다.
 *
 * Output : int exponent_ result
 *          이 값은 (base_num)^(exponent_num)과 같다.
 */

int exponent(int base_num, int exponent_num) {
    int exponent_result = 1, cnt = 0;
    while (++cnt <= exponent_num)
        exponent_result *= base_num;
    /* cnt가 1에서 exponent_num일 때 까지 동작힌다.
     * 따라서 1에 base_num을 exponent_num번 곱하는 것이다.
     * 단, exponent_num이 0이면 exponent_result인 1값을 바로 출력한다.*/
    return exponent_result;
}
