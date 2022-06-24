
/* 
 * Copyright (C) 2011-2012 by Hyoung Bok Min, All rights reserved.
 *
 * Lab 1 of C Programming : Operators
 *
 * Summary of this lab :
 *    1. a+++b의 해석
 *    2. increment/decrement가 들어간 식의 계산
 *    3. 괄호 유무에 따른 assignment operator의 작동 여부
 *
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 * 
 * File name : 2014310407.이준혁.HW1.c
 * Written on September 24, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on September 27, 2014
 *	    (a) 불필요한 내용 제거
 *	    (b) 과도한 설명은 주석처리 및 보고서로 옮김
 *	    (c) 설명이 부족했던 부분은 설명 추가
 *	    (d) style 개선
 *        
 *  Compiler Used : Microsoft Visual C++ 2010 Express Edition 
 */


#include <stdio.h> /* printf 함수를 이용하기 위한 헤더 파일 stdio.h 선언 */


int main(void) { /* main 함수의 시작 */
      int a = 1, b = 1, sum;
     /*
      * 문제 1을 위한 변수 선언
      * a,b는 자료에 주어진 문자를 그대로 사용.
      * 변화를 관찰하기 위한 수들 이므로 계산이 용이한 1을 대입.
      * sum은 a+++b의 값을 저장하는 변수로 이용.
      */
      int A, B = 0, C = 0;
     /*
      * 문제 2를 위한 변수 선언
      * A,B,C는 자료에 주어진 문자와 초기값을 그대로 사용.
      */
      int x, y, z;
     /*
      * 문제 3을 위한 변수 선언
      * x,y,z는 자료에 주어진 문자를 그대로 사용.
      * 초기값은 필요 없으니 정의하지 않음
      */

     /* PROBLEM # 1 */
      printf("문제 1\n");

      sum = a+++b;

     /* a+++b는 다음 세 가지 중 하나로 추측 할 수 있다.
      * 1) a++ + b : 이 때 a = 2, b = 1, sum = 2 이다.
      * 2) a + ++b : 이 때 a = 1, b = 2, sum = 3 이다.
      * 3) a + + + b : : 이 때 a = 1, b = 1, sum = 2 이다.
      * 이 부분은 보고서에 자세히 명시하였다.
      */

      printf("a+++b가 어떻게 해석되는지 알아보기 위해 a=1, b=1\n"
             "sum = a+++b로 정의한 후에 예측한 값과 a,b,sum값을 비교해 보자.\n");

      printf("a=%d, b=%d, sum=%d 이다.\n", a, b, sum);

      printf("a+++b는 결국 a++ + b로 해석된다.\n\n");
     /*sum = a+++b의 결과가 sum = a++ + b의 결과와 일치하므로*/

     /* PROBLEM # 2 */
      printf("문제 2\n");

      printf("초기값이 0인 B,C를 다음 연산들을 했을 때 "
             "A,B,C값이 어떻게 변하는지 살펴보자.\n");

      A = ++B + ++C;
      printf("A = ++B + ++C일 때 A=%d B=%d C=%d\n", A, B, C);
      /*
       * ++가 prefix이므로 B = B + 1, C = C + 1, A = B + C이다.
       * 즉, A = 2, B = 1, C = 1 이다.
       */

      A = B++ + C++;
      printf("A = B++ + C++일 때 A=%d B=%d C=%d\n", A, B, C);
     /* 
      * ++가 postix이므로 A = B + C, B = B + 1, C = C + 1이다.
      * 즉, A = 2, B = 2, C = 2 이다.
      */

      A = ++B + C++;
      printf("A = ++B + C++일 때 A=%d B=%d C=%d\n", A, B, C);
     /*
      * B의 ++는 prefix이고, C의 ++는 postfix이므로
      * B = B + 1, A = B + C, C = C + 1 이다.
      * 즉, A = 5, B = 3, C = 3 이다
      */

      A = B-- + --C;
      printf("A = B-- + --C일 때 A=%d B=%d C=%d\n\n", A, B, C);
     /*
      *C의 --는 prefix이고, B의 --는 postfix이므로
      *C = C - 1, A = B + C, B = B - 1이다.
      *즉, A = 5, B = 2, C = 2 이다
      */

     /* PROBLEM # 3 */
      printf("문제 3\n");

      printf("x = (y = 2) + (z = 3) 라는 식에서 괄호가 없는 경우\n"
             "첫번째 것만 없는 경우, 두번째 것만 없는 경우, 다 있는 경우 "
             "이 네가지를 살펴보자.\n\n");

     /*
      * x = y = 2 + z = 3;
      * printf("괄호가 둘 다 없을 경우 x=%d, y= %d, z=%d\n", x, y, z);
      */
     /* 2+z = 3 이므로 왼쪽에 하나의 변수가 오지 않으므로 오류 */
      printf("괄호가 둘 다 없을 경우 오류 발생\n\n");

      x = y = 2 + (z = 3);
      printf("첫번째 괄호가 없을 경우 x=%d, y= %d, z=%d\n\n", x, y, z);
     /* z에 3 assign. y = 2 + z이므로 y에 5 assign. x = y 이므로 x에 5 assign*/

     /* x = (y = 2) + z = 3;
      * printf("괄호가 둘 다 없을 경우 x=%d, y= %d, z=%d\n", x, y, z);
      */
     /* (y=2)+z = 3 이므로 왼쪽에 하나의 변수가 오지 않으므로 오류 */
      printf("두번째 괄호가 없을 경우 오류 발생\n\n");

      x = (y = 2) + (z = 3);
      printf("괄호가 둘 다 있는 경우 x=%d, y= %d, z=%d\n", x, y, z);
     /*z에 3 assign. y에 2 assign. x = y + z 이므로 x에 5 assign*/

      return 0;
}    /* main 함수의 끝 */