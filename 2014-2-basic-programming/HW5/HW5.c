/*==================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 5 of C Programming : Enumeration Type
 *
 * Summary of this lab : Enumeration type을 이용한 컴퓨터와
 *                       가위바위보 하는 게임 작성
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 * 
 * File name : 2014310407.이준혁.HW5.c
 * Written on October 29, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on October 31
 *       (a) comment 수정 및 추가
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================*/

/* printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* random 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdlib.h>

/* 가위, 바위, 보, 탈출을 하기 위한 상수들이 있는
 * enumeration type을 RSP로 선언 */
typedef enum {ROCK, SCISSORS, PAPER, QUIT} RSP;

/* 누가 이겼는지, 비겼는지를 판단하기 위한
 * enumeration type을 WHO_WIN으로 선언 */
typedef enum {COMPUTER_WIN, USER_WIN, TIE} WHO_WIN;

/* 프로그램 진행에 필요한 function prototype들을 선언 */
RSP USER_RSP(void);

RSP COMPUTER_RSP(void);

WHO_WIN decideWhoWins(RSP USER_VALUE, RSP COMPUTER_VALUE);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    /* 가위 바위 보 프로그램을 실행하기 위해 필요한 변수 선언 */

    WHO_WIN result;    /* 누가 이겼는지를 나타내는 변수 */
    RSP USER_VALUE;    /* 사용자의 가위, 바위, 보 값 혹은 quit값을 나타내는 변수 */
    RSP COMPUTER_VALUE;/* 컴퓨터의 가위, 바위, 보 값을 나타내는 변수 */

    /* while 문을 이용해 사용자가 q를 주기 전까지는 계속 입력을
     * 받아 가위바위보 결과를 출력하는 프로그램이 반복되도록 작성 */
    while (1) {
        /* 사용자의 가위, 바위, 보 값을 USER_RSP라는
         * function의 반환값을 통해 결정 */
        USER_VALUE = USER_RSP();

        /* USER_VALUE가 QUIT일 때 탈출, 나머지 경우는
         * "you choose ...."에서 ....부분을 사용자가 준
         * 값과 같게 출력하도록 하기 위해 if-else문 이용 */

        if (USER_VALUE == QUIT)
            break;
        else if (USER_VALUE == ROCK)
            printf("you choose rock ");
        else if (USER_VALUE == SCISSORS)
            printf("you choose scissors ");
        else if (USER_VALUE == PAPER)
            printf("you choose paper ");

        /* 컴퓨터의 가위, 바위, 보 값을 COMPUTER_RSP라는
         * function의 반환값을 통해 결정 */
        COMPUTER_VALUE = COMPUTER_RSP();

        /* "and I choose ...."에서 ....부분을 컴퓨터가 내놓은 값과
         * 같게 출력하도록 하기 위해 if-else문 이용 */
        if (COMPUTER_VALUE == ROCK)
            printf("and I choose rock. ");
        else if (COMPUTER_VALUE == SCISSORS)
            printf("and I choose scissors. ");
        else if (COMPUTER_VALUE == PAPER)
            printf("and I choose paper. ");

        /* 누가 이겼는지를 결정하기 위해 사용자가 준 값과 컴퓨터가 내놓은
         * 값을 decideWhoWins라는 function에 넣어서 반환된 값을 result라는
         * 변수에 저장 */
        result = decideWhoWins(USER_VALUE, COMPUTER_VALUE);

        /* result는 누가 이겼는지 그 결과를 나타내는 변수이므로
         * result의 값에 따라 누가 이겼는지를 출력 */
        if (result == TIE)
            printf("A TIE.\n");
        else if (result == USER_WIN)
            printf("You win.\n");
        else if (result == COMPUTER_WIN)
            printf("You lose.\n");
    }
    return 0;/* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 사용자에게 p, r, s, q를 입력하도록 요구해서
 * 사용자에게 입력 받은 값을 그에 대응되는 RSP type의 ROCK,
 * SCISSORS, PAPER, QUIT로 반환하는 함수이다.
 *
 * 이 때 사용자가 p, r, s, q 이외의 값을 입력한다면, 제대로 된
 * 입력을 할 때 까지 잘못 입력했다는 메시지를 출력하고,
 * 재입력을 요구한다.
 *
 * 함수의 입력은 없고, p,q,r,s의 입력은 함수 내에서 scanf 함수를
 * 통해 받는다.
 *
 * Input : None
 *
 * Output : 사용자가 입력한 값에 따라, ROCK,
 *          SCISSORS, PAPER, QUIT 중 하나
 */

RSP USER_RSP(void) {
    /* 사용자가 입력할 p, q, r, s를 받기 위한 변수와 그 변수를
     * RSP type으로 반환하기 위한 변수 선언 */
    char usergive;
    RSP USER_VALUE;

    /* 사용자에게 p, q, r, s를 입력하도록 요구하고, 입력받은 후에 그 값이
     * p, q, r, s가 아니면 재입력 요구 */
    printf("Input p(paper), r(rock), s(scissors) or q(quit) : ");
    scanf(" %c", &usergive);

    while ((usergive != 'p') && (usergive != 'r') &&
           (usergive != 's') && (usergive != 'q')) {
        printf("You put a wrong word.\nInput p(paper), r(rock), "
               "s(scissors) or q(quit) : ");
        scanf(" %c", &usergive);
    }

    /* 사용자가 준 값에 따라 switch문을 이용해
     * USER_VALUE에 적절한 값을 할당 후 그 값을 반환*/
    switch (usergive) {
        case 'p': USER_VALUE = PAPER; break;
        case 'r': USER_VALUE = ROCK; break;
        case 's': USER_VALUE = SCISSORS; break;
        case 'q': USER_VALUE = QUIT; break;
    }
    return USER_VALUE;
}

/*
 * 이 함수는 COMPUTER_VALUE에 ROCK, SCISSOR, PAPER중의 하나를
 * 임의로 배정하는 함수이다.
 *
 * 이 때 random함수를 이용해 0, 1, 2 중 하나의 값을 임의로 얻고,
 * 그 값을 type casting을 이용해 ROCK, SCISSORS, PAPER으로
 * 변환하는 방법을 통해서 COMPUTER_VALUE에 임의의 값이
 * 들어갈 수 있도록 한다.
 *
 * random 함수를 통해 값이 만들어지므로, 입력은 없다.
 *
 * Input : None
 *
 * Output : ROCK, SCISSORS, PAPER중 하나. 임의로 배정된 값
 */
RSP COMPUTER_RSP(void) {
    /* 0, 1, 2 중 임의의 정수를 담기 위한 변수와 그 변수를
     * RSP type으로 반환하기 위한 변수 선언 */
    int random;
    RSP COMPUTER_VALUE;

    /* 수를 0, 1, 2중 하나로 제한함 */
    random = (rand()) % 3;

    /* type casting을 통해 random의 값을 COMPUTER_VALUE에 할당 */
    COMPUTER_VALUE = (RSP)random;

    return COMPUTER_VALUE;
}

/*
 * 이 함수는 사용자가 준 가위, 바위, 보 값과 컴퓨터가 내놓은 가위, 바위, 보
 * 값을 비교해, 누가 이겼는지를 그 결과를 WHO_WIN type의 TIE, COMPUTER_WIN,
 * USER_WIN 중의 하나로 반환 하는 함수이다.
 *
 * 이 때 사용자가 quit을 준 경우에는 break문을 통해 반복문을 빠져나가므로,
 * 이 함수가 function call될 일이 없으므로, 고려하지 않아도 된다.
 *
 * 사용자가 준 가위 바위 보 값과 컴퓨터가 내놓은 가위, 바위, 보 값을
 * 정수로 type casting 해서 그것을 뺀 결과가 어떤 값을 
 * 내놓느냐에 따라 누가 이겼는지를 결정한다.
 *
 * Input : USER_VALUE : 사용자가 준 값으로, USER_RSP가 return한 값이다.
 *                      ROCK, SCISSORS, PAPER중 하나이다.
 *         COMPUTER_VALUE : 컴퓨터가 내놓은 값으로, COMPUTER_RSP가 return한
 *                          값이다. ROCK, SCISSORS, PAPER중 하나이다.
 *
 * Output : USER_VALUE와 COMPUTER_VALUE를 비교해 TIE, COMPUTER_WIN,
 *          USER_WIN 중의 하나로 반환한다.
 */
WHO_WIN decideWhoWins(RSP USER_VALUE, RSP COMPUTER_VALUE) {
    int decision_number; /*누가 이겼는지를 판단하기 위한 변수 정의*/

    decision_number = ((int)USER_VALUE - (int)COMPUTER_VALUE);

    /* 이 과정을 통해 만들어진 decision number가 0이면 비긴것,
     * -1 혹은 2이면 사용자의 승리, 1 혹은 -2이면 컴퓨터의 승리이므로,
     * 다음과 같이 if-else 문을 이용해 서로 다른 값을 return하기로 했다. */

    if (decision_number == 0)
        return TIE;
    else if ((decision_number == -1) || (decision_number == 2))
        return USER_WIN;
    else if ((decision_number == 1) || (decision_number == -2))
        return COMPUTER_WIN;
}
