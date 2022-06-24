/*================================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min and Jun Hyuk Lee, All rights reserved.
 *
 * Lab 9 of C Programming : Structures
 *
 * Summary of this lab : Structure를 이용해 코일의 길이와
 *                       인덕턴스를 구하는 프로그램 구현
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 *
 * File name : 2014310407.이준혁.HW9.c
 * Written on December 3, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on December 6
 *       (a) comment 추가
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================================*/

/* printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* malloc과 free함수를 사용하기 위한 헤더 파일 삽입 */
#include <stdlib.h>

/* inductance 계산 도중 나오는 제곱을 계산하기 위한 헤더 파일 삽입 */
#include <math.h>

/* COIL이라는 이름을 가진 type 선언
 * COIL의 변수는 각 그 반지름, 회전수, 인덕턴스 값을 갖도록 선언됨.
 * function prototype에서 사용되므로 그것 이전에 선언 */
typedef struct _coil {
    double radius;         /* 각 코일의 반지름 */
    int    number_of_turns;/* 회전 수 */
    double inductance;     /* 인덕턴스*/
} COIL;

/* 함수 진행에 필요한 Function prototypes 선언 */
void build_a_coil(COIL *coil, double radius, int turns, double inductance);

void print_coil_info(COIL coil);

double length_of_wire(COIL *coil, int number);

double inductance_in_series(COIL *coil, int number);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    COIL  *coils; /* COIL type의 array를 이용하기 위해 위해 pointer 선언 */
    double  total_length;
    double  total_inductance;

    /* pointer로 선언된 coils가 array의 역할을 수행하도록 동적 메모리 할당 */
    coils = (COIL *)malloc(4*sizeof(COIL));

    /* coils라는 array의 각 원소의 radius, number of turns, 
     * inductance를 초기화 후 출력*/
    build_a_coil(&coils[0], 1.2, 120, 0.5); /* 값을 변경시키므로 주소를 줌 */
    print_coil_info(coils[0]);              /* 값의 변경이 없으므로 값을 줌*/

    build_a_coil(&coils[1], 2.0, 400, 0.8);
    print_coil_info(coils[1]);

    build_a_coil(&coils[2], 0.8, 500, 3.2);
    print_coil_info(coils[2]);

    build_a_coil(&coils[3], 3.5, 50, 1.2);
    print_coil_info(coils[3]);

    /*각 coil의 길이를 계산 후 총 길이를 반환하는 함수를 이용해 총 길이 출력 */
    total_length = length_of_wire(coils, 4);
    printf("Total length of 4 Coils : %.2lf\n", total_length);

    /* coil의 총 인덕턴스를 반환하는 함수를 이용해 총 인덕턴스 출력 */
    total_inductance = inductance_in_series(coils, 4);
    printf("Total inductance of 4 Coils : %.2lf\n", total_inductance);

    /* coils가 할당받은 메모리 deallocate */
    free(coils);

    return 0; /* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 COIL의 변수 하나의 주솟값과 그 coil의 member 값에 
 * 할당될 값을 입력으로 받아서, 그 값들을 COIL 변수의 member에 
 * 할당하는 함수이다.
 *
 * 이 때 포인터를 이용하므로 operator ->을 사용해 값을 assign 한다.
 *
 * 단순히 값의 할당만이 목적이므로, 포인터를 이용해 값을 변경하는 것 
 * 이외에는 출력이 없다.
 *
 * Input  : 값을 할당하고자 하는 한 coil의 주소와 그 coil에 할당될 값들을 
 *          입력받는다.
 *
 * Output : pointer로 주소를 준 main에 있는 COIL type의 변수의 값을
 *          바꾸는 것 이외에 return을 통한 반환은 없다.
 */

void build_a_coil(COIL *coil, double radius, int turns, double inductance) {
    /* coil이 가리키는 변수의 각 member에 값 assign */
    coil -> radius = radius;
    coil -> number_of_turns = turns;
    coil -> inductance = inductance;
}

/*
 * 이 함수는 입력으로 받아들인 COIL type의 변수가 어떤 값을 가지고 있나
 * 출력하는 함수이다.
 *
 * 입력으로 받아들이는 변수는 main에 정의되어 있으며, 출력(printf)만이 목적이므로
 * return을 통한 반환은 없다.
 *
 * 출력한 것의 가독성을 높이기 위해 \t를 이용한다.
 *
 * Input  : main에 정의된, 정보를 출력(printf)할 COIL type의 변수 하나를 
 *          입력으로 받아들인다. 값의 변경이 이루어지지 않기 때문에 그냥
 *          값 자체를 받아들인다.
 *
 * Output : None
 */

void print_coil_info(COIL coil) {
    /* 입력받은 coil의 radius, number of turns, inductance 정보 출력 */
    printf("%s\t\t%s \t%s\n", "Radius", "Number of Turns", "Inductance");
    printf("%.1lf\t\t%d\t\t\t%.1lf\n", coil.radius, coil.number_of_turns,
                                       coil.inductance);
}

/*
 * 이 함수는 main에 정의된 COIL type의 array(pointer)를 받아들여 array의
 * 각 원소의 길이를 구한 후, 총 길이를 반환하는 함수이다.
 *
 * 이 때 길이를 구하는 것은 민형복 교수님의 practice9.pdf의
 * 7페이지를 참고한다.
 *
 * 또한, 몇 개를 더하는 지 알아야 하기 때문에 array의 갯수도
 * 입력으로 받아들인다.
 *
 * Input  : coil들이 담겨있는 array(pointer)를 입력으로 받아들인다.
 *          이 array는 main에 정의되어 있다. 또, 몇 개의 길이를
 *          더해야 하는지 알기 위해 array의 갯수도 입력으로 받는다.
 *          
 * Output : array의 각각의 원소의 길이를 계산한 후에, 각 원소의 길이를
 *          다 더한 값을 반환한다. 이는 main에 있는 total_length라는
 *          변수에 저장되게 된다.
 */

double length_of_wire(COIL *coil, int number) {
    int cnt = 0;
    /* 각 coil의 길이를 출력하기 위한 변수 pritn_length와 
     * 총 길이를 출력하기 위한 total_length를 0으로 초기화 */
    double print_length, total_length = 0;

    /* while문을 이용해 numebr번 각 coil의 길이를 구하고
     * 출력한 후 그 길이를 총 길이에 더하는 과정 반복 */
    while (cnt < number) {
        print_length = coil[cnt].radius*(pow(coil[cnt].number_of_turns, 2.0)*
                       coil[cnt].radius - 9*coil[cnt].inductance) /
                       (10*coil[cnt].inductance);

        printf("Coils[%d] length : %.2lf\n", cnt, print_length);

        cnt++;
        total_length += print_length; /* 총 길이에 각각의 길이를 더함 */
    }
    /* 총 길이 반환 */
    return total_length;
}

/*
 * 이 함수는 main에 정의된 COIL type의 array(pointer)를 받아들여 각 array의
 * 각 인덕턴스를 다 합해 총 인덕턴스를 반환하는 함수이다.
 *
 * 이 때 몇 개를 더하는 지 알아야 하기 때문에 array의 갯수도
 * 입력으로 받아들인다.
 *
 * Input  : coil들이 담겨있는 array(pointer)를 입력으로 받아들인다.
 *          이 array는 main에 정의되어 있다. 또, 몇 개의 인덕턴스를
 *          더해야 하는지 알기 위해 array의 갯수도 입력으로 받는다.
 *          
 * Output : array의 각 원소의 인덕턴스를 더한 값을 반환한다. 이는 main
 *          에 있는 total_inductance라는 변수에 저장되게 된다.
 */

double inductance_in_series(COIL *coil, int number) {
    int cnt = 0;
    /* 총 inductance를 0으로 초기화 */
    double total_inductance = 0;

    /* while문을 이용해 number번 각 array의 inductance를 더함 */
    while (cnt < number) {
        total_inductance += coil[cnt].inductance;
        cnt++;
    }
    /* 총 inductance를 반환 */
    return total_inductance;
}
