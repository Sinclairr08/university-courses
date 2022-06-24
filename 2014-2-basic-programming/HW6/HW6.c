/*==================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 6 of C Programming : Pointers
 *
 * Summary of this lab : 포인터를 이용한 간단한 프로그램 작성
 *
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 *
 * File name : 2014310407.이준혁.HW6.c
 * Written on November 12, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on November 14
 *       (a) style 개선
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================*/

/* printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* 프로그램 진행에 필요한 function prototype들을 선언 */

void swap(int num1, int num2);

void swap_by_pointer(int *num1, int *num2);

int compute_minmax(int num1, int num2, int num3, int *minimum);

int maximum_by_static(int number);


/* main 함수의 시작
 * Input : None
 * Output : int 0 */

int main(void) {
    /* 변수 선언 */
    int  num1 = 10, num2 = 20, num3 = 30;
    int  *pnum1,    *pnum2,    *pnum3;
    int  minimum, maximum;

/*
 *  문제 1 : Basic pointer operations
 */
    printf("Q1\n");

    /* pointer variable들에 각각의 주소 할당 */

    pnum1 = &num1;
    pnum2 = &num2;
    pnum3 = &num3;

    /* num1, num2, num3을 출력하기 위해 그것들을
     * 가리키고 있는 포인터들 pnum1, pnum2, pnum3 앞에 *을 붙여 출력 */

    printf("num1 = %d, num2 = %d, num 3 = %d\n", *pnum1, *pnum2, *pnum3);
    printf("\n");

/*
 *  문제 2 : Function swap
 */
    printf("Q2\n");

    /* 우선 두 수가 무엇인지 변경 전에 확인 */
    printf("before swap : num1 = %d, num2 = %d\n", num1, num2);

    /* swap이라는 함수를 function call함 */
    swap(num1, num2);    /* 주소를 주는 것이 아니니 이 함수는 포인터를 이용하지 않음 */

    printf("after  swap : num1 = %d, num2 = %d\n", num1, num2);

    /* swap_by_pointer라는 함수를 function call함 */
    swap_by_pointer(&num1, &num2);  /* 주소를 주었으니 이 함수는 포인터를 이용함 */

    printf("after pointer swap : num1 = %d, num2 = %d\n", num1, num2);
    printf("\n");


/*
 *  문제 3 : Function with 2 or more output values
 */
    printf("Q3\n");

    /* 최댓값과 최솟값을 계산하고자 하는 값들 확인 */
    printf("Computing minimum and maxinum of %d, %d, and %d.\n",
                                                   num1, num2, num3);

    /* 주어진 수들의 최댓값과 최솟값 계산후 출력 */
    maximum = compute_minmax(num1, num2, num3, &minimum);
    printf("minimum = %d, maximum = %d\n", minimum, maximum);
    printf("\n");

/*
 *  문제 4: Function with static variable
 */
    printf("Q4\n");

    /* 최댓값을 계산하고자 하는 값들 확인 */
    printf("Computing maxinum of %d, %d, and %d.\n", num1, num2, num3);

    /* num1을 maximum에 저장후 출력 */
    maximum = maximum_by_static(num1);
    printf("static : maximum = %d\n", maximum);

    /* num1, num2중 큰 수를 maximum에 저장후 출력 */
    maximum = maximum_by_static(num2);
    printf("static : maximum = %d\n", maximum);

    /* num1, num2중 큰 수와 num3를 비교해 큰 수를 maximum에 저장후 출력 */
    maximum = maximum_by_static(num3);
    printf("static : maximum = %d\n", maximum);

    return 0; /* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 포인터를 이용하지 않는 swap함수로, 입력 받은 두 개의 수를 바꾸고자 하는 함수이다.
 *
 * 이 때 이 함수는 function 내부에서 값을 변화시키려 하므로, 입력만 있고 출력은 없다.
 *
 * 그러나, 사실 이 함수는 두 개의 함수의 값을 변경시키지 못하는데, 그 이유는 이 함수 안의
 * 변수만 변경될 뿐 main함수 안의 두 값을 바꿀 수 없기 때문이다.
 *
 * Input : 사용자가 바꾸고자 하는 두 개의 값으로, 정수형 변수이다.
 *         main함수에서 이미 정의된 변수이다.
 *
 * Output : return을 통한 output은 없다. 그러나 함수 내에서 값을 변경 시키고자 한다.
 */

void swap(int number1, int number2) {
    int temp;   /* swap을 위해 필요한 매개변수 선언 */

    temp = number1;
    number1 = number2;
    number2 = temp;
}

/*
 * 이 함수는 포인터를 이용하는 swap함수로, 입력 받은 두 개의 수를 바꾸는 함수이다.
 *
 * 이 때 이 함수는 function 내부에서 값을 변화시키려 하므로, 입력만 있고 출력은 없다.
 *
 * 이 함수는 포인터를 이용해 main함수의 변수들이 나타내는 주소를 받고, 그 주소를
 * 통해서 두 변수의 값을 변경한다. 따라서, main함수 내의 두 개의 값이 변경된다.
 *
 * Input : 사용자가 바꾸고자 하는 두 개의 값의 주소이다. 정수형 포인터 변수이다.
 *         main함수에서 이미 정의된 변수의 주소이다.
 *
 * Output : return을 통한 output은 없다. 그러나 함수 내에서 값을 변경 시킨다.
 */

void swap_by_pointer(int *number1, int *number2) {
    int temp;    /* swap을 위해 필요한 매개변수 선언 */

    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

/* 
 * 이 함수는 세 개의 수 중 가장 큰 수와 작은 수를 구별하기 위한 함수이다.
 *
 * 이 때 이 함수는 세개의 값을 입력받아, 그 세개의 수 중에서 가장 큰 값과
 * 가장 작은 값을 계산한다.
 *
 * 그러나 함수의 출력은 하나만 있을 수 있으므로, 최댓값만 반환하고, 최솟값은
 * 포인터를 이용해 값을 변화시킨다. 즉, 함수의 출력을 포인터를 이용해 하는 것이다.
 *
 * 즉, 포인터를 이용하기 위해 최솟값 변수의 주소도 입력받아야 한다.
 *
 * Input : 사용자가 최댓값과 최솟값을 구하고자 하는 세 개의 수를 입력으로 받아들인다.
 *         또, 최솟값 변수의 값을 변경하기 위해, 최솟값 변수의 주소도 입력으로 받아들인다.
 *         모든 변수들은 main에 선언되어 있다.
 *
 * Output : return을 통한 output은 최댓값이고, 포인터를 이용한 출력은 최솟값이다.
 */

int compute_minmax(int number1, int number2, int number3, int *minimum) {
    int maximum;        /* 최댓값을 반환할 변수 */

    *minimum = number1; /* 최솟값은 포인터를 이용해 값을 변경 */

    if (*minimum > number2)
        *minimum = number2;

    if (*minimum > number3)
        *minimum = number3;

    maximum = number1;

    if (maximum < number2)
        maximum = number2;

    if (maximum < number3)
        maximum = number3;

    return maximum;
}

/*
 * 이 함수는 static variable을 이용해 최댓값을 가려내는 함수이다.
 *
 * 이 함수는 하나의 값을 입력받아, 그것이 이미 저장되어 있는 값과 비교하여
 * 더 큰지 작은지를 비교해서 더 큰 값을 저장하고, 반환한다.
 *
 * 이 때 여러 수의 최댓값과 최솟값을 반환하기 위해 function call을
 * 여러 번 해야 하는데, 그 때마다 초기화되지 않게 하기 위해
 * static variable을 이용한다.
 *
 * Input : 저장되어 있는 값과 비교하기 위한 정수형 변수이다.
 *         main함수에 이미 정의되어 있는 변수이다.
 *
 * Output : 입력받은 값과 저장된 값 중 큰 값을 저장하고 반환한다.
 */

int maximum_by_static(int number) {
    /* function이 끝나도 값을 유지시키기 위해 static으로 변수 선언 */
    static int stored_maximum = -1;

    if (number > stored_maximum)
        stored_maximum = number;

    return stored_maximum;
}
