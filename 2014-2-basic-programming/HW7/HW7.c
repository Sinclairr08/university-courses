/*==================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 7 of C Programming : Array & Pointers
 *
 * Summary of this lab : Array와 pointer를 이용한 최댓값, 최솟값, 평균,
 *                       그리고 표준편차를 계산하는 프로그램 작성
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 *
 * File name : 2014310407.이준혁.HW7.c
 * Written on November 19, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on November 21
 *       (a) comment 추가
 *       (b) style 개선
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================*/

/* printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* malloc, free, rand, srand 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdlib.h>

/* sqrt, pow등 수학 계산을 편리하게 하기 위한 헤더 파일 삽입 */
#include <math.h>

/* random number generator의 무작위성을 증가시키기 위한 헤더 파일 삽입 */
#include <time.h>

/* 프로그램 진행에 필요한 function prototype 선언 */

void assign_array(int *random_array, int size);

void print_array(int *random_array, int size);

void compute_using_array(int *random_array, int *min, int *max,
                                         double *ave, double *dev, int size);

void compute_using_pointer(int *random_array, int *min, int *max,
                                           double *ave, double *dev, int size);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    /* 변수 선언 */
    int  size;           /* array의 크기 */
    int  *random_array;  /* array처럼 이용할 pointer */
    int  min, max;       /* 최대, 최솟값 */
    double ave, dev;     /* 평균, 표준편차 */

    /* array의 크기를 입력받음 */
    printf("Input a size of array\n");
    scanf("%d", &size);

    /* array의 크기가 0 미만일시 재입력 요구 */
    while (size <= 0) {
        printf("Unvaild value! size of array must be a positive integer\n");
        printf("Input a size of array\n");
        scanf("%d", &size);
    }

    /* array의 크기와 int의 크기를 곱한 것 만큼의 메모리를 random_array에 할당 
     * pointer를 초기화 시킴으로 인해 array처럼 data를 저장할 수 있는 
     * 공간을 만들어 줌*/
    random_array = (int *)malloc(size*sizeof(int));

    /* array에 값을 할당하는 function call */
    assign_array(random_array, size);

    /* array에 할당된 값을 출력하는 function call */
    print_array(random_array, size);

    /* array를 이용해 최댓값, 최솟값, 평균, 표준편차 구하기 */
    printf("compute using array\n\n");

    /* 최댓값, 최솟값, 평균, 표준편차의 값을 계산하는 함수 call
     * 이 함수는 함수 내에서 main함수 안의 최댓값, 최솟값, 평균, 표준편차를
     * 나타내는 변수들의 값에 직접 접근해 변경시키고,
     * 특별한 값을 return하지 않으므로 function call만 함. array 이용 */
    compute_using_array(random_array, &min, &max, &ave, &dev, size);

    printf("minimum = %d\n", min);
    printf("maxiximum = %d\n", max);
    printf("average = %.2lf\n", ave);
    printf("standard deviation = %.2lf\n\n", dev);

    /* pointer표현을 이용해 최댓값, 최솟값, 평균, 표준편차 구하기 */
    printf("compute using pointer\n\n");

    /* 이 함수 역시 함수 내에서 main함수의 값만 변경시키고 return하지
     * 않으므로 function call만 함. pointer표현 이용 */
    compute_using_pointer(random_array, &min, &max, &ave, &dev, size);

    printf("minimum = %d\n", min);
    printf("maxiximum = %d\n", max);
    printf("average = %.2lf\n", ave);
    printf("standard deviation = %.2lf\n", dev);

    /* 할당받은 메모리 주소를 반환 */
    free(random_array);

    return 0; /* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 주어진 크기 만큼의 array에 -3000 ~ 4000 사이의 값을
 * 무작위하게 할당하는 함수이다.
 *
 * 난수추출을 무작위하게 하기 위해 srand(time(NULL)) 를 이용한다.
 * 
 * array하나와 그 array의 크기를 입력 받아서, for문을 이용해
 * 모든 array에 -3000 ~ 4000 사이의 값을 할당한다. return되는 값은 없다.
 *
 * Input : main함수에 정의된, 값을 변경시키고자 하는 array(이자 pointer)를
 *         입력받는다. 다시말해, array가 가지고 있는 주소를 입력받는다.
 *         또, 그 array의 크기에 해당하는 정수 하나를 입력받는다. 이 정수는
 *         사용자가 main에서 키보드를 통해 입력한 값이다.
 *
 * Output : return을 통한 output은 없다. 하지만 main함수에 있는 
 *          array의 값을 변경시킨다.
 */
void assign_array(int *random_array, int size) {
    int cnt;

    srand(time(NULL));  /* 무작위성 증가 */

    /* random_array[0] ~ [size-1]에 -3000 ~ 4000 사이의 임의의 값 할당 */
    for (cnt = 0; cnt < size; cnt++)
        random_array[cnt] = (rand())%7001 - 3000;
}

/*
 * 이 함수는 array를 출력하기 위한 함수이다.
 *
 * 단순히 array를 출력하는 위한 기능밖에 없으며,
 * 5번 출력할 때마다 줄을 바꾼다.(\n을 출력한다.)
 *
 * array하나와 그 array의 크기를 입력으로 받아들인다. printf함수를
 * 이용한 출력이 목적이므로, return하는 값은 없다.
 *
 * Input : 출력하고자 하는 array와 그 array의 크기에 해당하는
 *         정수 하나를 입력받는다.
 *
 * Output : None
 */
void print_array(int *random_array, int size) {
    int cnt;

    for (cnt = 0; cnt < size; cnt++) {
        if (cnt % 5 == 0)
            printf("\n");     /* 5의 배수 번째 마다 줄 바꿈 */
        printf("%6d", random_array[cnt]);
    }
    printf("\n\n");
}

/*
 * 이 함수는 array 표현을 이용해 주어진 값들의 최댓값, 최솟값,
 * 평균, 표준편차를 계산하기 위한 함수이다.
 *
 * 우선, main에 정의된 array 하나와 최댓값, 최솟값, 평균, 표준편차를
 * 의미하는 변수들의 주솟값을 입력받는다. array의 크기 역시 입력받는다.
 *
 * 그 다음에 array표현을 이용해서, array 안에 있는 수들의 최댓값, 최솟값,
 * 평균, 표준편차를 계산한다. 이 때, dereference operator를 이용해
 * main에 있는 변수들에 직접 작용해 값을 변경한다.
 *
 * 이 과정에서 for문을 이용하고, 또 계산의 편리성을 <math.h>에 정의된
 * 위해 지수함수와 제곱근 함수를 이용한다.
 *
 * 또, 위와 같은 이유 때문에 return을 통한 출력은 없다.
 *
 * Input : main에 있는 array(정확히는 거기에 담겨있는 주소)와
 *         그 크기를 입력받는다. 또, main에서 최댓값, 최솟값,
 *         평균, 표준편차를 의미하는 변수들의 주솟값을 입력받는다.
 *
 * Output : return을 통한 출력은 없다. 그러나 main의 최댓값, 최솟값,
 *          평균, 표준편차를 직접 변화시킨다.
 */
void compute_using_array(int *random_array, int *min, int *max,
                                         double *ave, double *dev, int size) {
    int cnt;

    /* random_array[0]으로 초기화 후 값을 비교하면서 최댓값 계산*/
    *max = random_array[0];

    for (cnt = 1; cnt < size; cnt++)
        if (*max < random_array[cnt])
            *max = random_array[cnt];

    /* 최댓값과 같은 논리로 최솟값 계산*/
    *min = random_array[0];

    for (cnt = 1; cnt < size; cnt++)
        if (*min > random_array[cnt])
            *min = random_array[cnt];

    /* 모든 array 값 더한 후 size로 나눠서 평균 계산 */
    *ave = 0;

    for (cnt = 0; cnt < size; cnt++)
        *ave += random_array[cnt];

    *ave /= size;

    /* 표준편차 계산 */
    *dev = 0;

    /* 평균으로 뺀 array 값들의 제곱을 다 더함 */
    for (cnt = 0; cnt < size; cnt++)
        *dev += pow(random_array[cnt] - *ave, 2.0);

    /* 그리고 size로 나누고, 제곱근을 취해 표준편차 계산 */
    *dev /= size;
    *dev = sqrt(*dev);
}

/*
 * 이 함수는 pointer표현을 이용해 주어진 값들의 최댓값, 최솟값,
 * 평균, 표준편차를 계산하기 위한 함수이다.
 *
 * 우선, main에 정의된 array 하나와 최댓값, 최솟값, 평균, 표준편차를
 * 의미하는 변수들의 주솟값을 입력받는다. array의 크기 역시 입력받는다.
 *
 * 그 다음에 pointer표현을 이용해서, array 안에 있는 수들의 최댓값, 최솟값,
 * 평균, 표준편차를 계산한다. 이 때, dereference operator를 이용해
 * main에 있는 값들에 직접 작용해 값을 변경한다.
 *
 * 기본적인 논리는 array표현을 사용하는 것과 동일하나, pointer 연산을 통해
 * pointer에 접근하고, 값을 변경시킨다.
 *
 * 또, 위와 같은 이유 때문에 return을 통한 출력은 없다.
 *
 * Input : main에 있는 array와 그 크기를 입력받는다.
 *         또, main에서 최댓값, 최솟값, 평균, 표준편차를
 *         의미하는 변수들의 주솟값을 입력받는다.
 *
 * Output : return을 통한 출력은 없다. 그러나 main의 최댓값, 최솟값, 평균,
 *          표준편차를 직접 변화시킨다.
 */
void compute_using_pointer(int *random_array, int *min, int *max,
                                           double *ave, double *dev, int size) {
    int cnt;
    int *ptr = random_array; /* 가독성을 높이기 위해 ptr이라는 pointer 변수 선언 */

    /* 첫 번째 array, 즉 random_array[0]의 값을 할당한 것과 같음
     * 위 함수와 같은 논리로 최댓값 계산 */
    *max = *random_array;

    for (cnt = 1; cnt < size; cnt++)
        if (*max < *(ptr + cnt))
            *max = *(ptr + cnt);

    /* 최솟값 계산 */
    *min = *random_array;

    for (cnt = 1; cnt < size; cnt++)
        if (*min > *(ptr + cnt))
            *min = *(ptr + cnt);

    /* 평균 계산 */
    *ave = 0;

    for (cnt = 0; cnt < size; cnt++)
        *ave += *(ptr + cnt);

    *ave /= size;

    /* 표준편차 계산 */
    *dev = 0;
    for (cnt = 0; cnt < size; cnt++)
        /* ++가 postfix라 *보다 나중에 적용되기 때문에 아래와 같이 쓸 수 있음*/
        *dev += pow(*ptr++ - *ave, 2.0);

    *dev /= size;
    *dev = sqrt(*dev);
}
