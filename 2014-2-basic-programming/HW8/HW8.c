/*================================================================================
 * Copyright (C) 2011-2014 by Hyoung Bok Min and Jun Hyuk Lee, All rights reserved.
 *
 * Lab 8 of C Programming : Strings & Pointers
 *
 * Summary of this lab : string과 pointer를 이용해 swap 함수와
 *                       strtok 함수를 구현
 * 
 * Written by Jun Hyuk Lee,
 *            School of Natural Science
 *            Sungkyunkwan University.
 *
 * File name : 2014310407.이준혁.HW8.c
 * Written on November 26, 2014
 * Modification History :
 *    1. by Jun Hyuk Lee on November 28
 *       (a) 프로그램 오류 수정
 *       (b) comment 수정
 *       (c) style 개선
 *
 * Compiler Used : Microsoft Visual C++ 2010 Express Edition
 *================================================================================*/

/* printf, scanf등의 함수를 이용하기 위한 헤더 파일 삽입 */
#include <stdio.h>

/* string 처리에 필요한 함수를 사용하기 위한 헤더 파일 삽입 */
#include <string.h>

/* 함수 진행에 필요한 Function prototypes 선언 */
void swap(char **, char **);

char *user_strtok(char *str, char *token);

void getSentence(char *, char *);

/* main 함수의 시작
 * Input : None
 * Output : int 0 */
int main(void) {
    /* 두 개의 string을 바꾸기 위해 변수 선언 */
    char  *str1 = "I am a boy";
    char  *str2 = "You are a girl";

    /* strtok함수를 이용하기 위해 기본 string값과 token 선언 */
    char  *default_str = "I /am ;a ,computer programmer.";
    char  s2[] = "/;, ";
    char  s1[256]; /* 사용자에게 입력받은 string을 저장하는 변수*/
    char  *token;  /* 쪼개진 string을 출력할 변수 */

    /* 두 string을 바꾸는 문제를 위해 swap 이전의 string 출력 */
    printf("before swap : string1 = %s\n", str1);
    printf("before swap : string2 = %s\n", str2);

    /* '주소'를 줘서 함수 내에서 직접 main에
     * 있는 변수들의 값(string)을 바꿈 */
    swap(&str1, &str2);

    /* 변경 후의 string 출력 */
    printf(" after swap : string1 = %s\n", str1);
    printf(" after swap : string2 = %s\n", str2);
    putchar('\n');

    /* strtok함수를 구현하기 위해 우선 사용자에게 string을 입력받음 */
    getSentence(s1, default_str);

    /* string과 separator가 무엇인지 출력 */
    printf("String => %s\n", s1);
    printf("Token Separators => \"%s\"\n\n", s2);

    /* user_strok로 인해 분리된 첫 번째 token 출력 */
    printf("Token => ");
    printf("\"%s\"", user_strtok(s1, s2));


    /* 더 이상 분리될 token이 없어서 NULL을 반환하기 전까지
     * 계속 다음 token들을 출력 */
    while ((token = user_strtok(NULL, s2)) != NULL)
        printf(" \"%s\"", token);

    putchar('\n');
    putchar('\n');
    return 0; /* main 함수의 출력을 0으로 반환, main 함수의 끝 */
}

/*
 * 이 함수는 두 string을 함수 내에서 바꿔주는(swap 해주는) 함수이다.
 * 그렇기 때문에 두 string의 주소를 입력받는데, string은 문자형 포인터
 * type이므로, char ** type의 두 값을 입력받는다.
 *
 * swap하는 방식은 정수를 대상으로 하는 swap 함수와 같다.
 *
 *  Input  : 두 string의 주소로, main함수에 있는 값이다.
 *           char ** type 이다.
 *
 *  Output :return을 통해 출력되는 값은 없다. 하지만, main에
 *          있는 두 string의 값을 변경시킨다.
 */

void swap(char **str1, char **str2) {
    char *temp;    /* string을 담을 매개변수이다. */

    temp = *str1;  /* *str1은 char pointer type 이므로, string을 나타낸다. */
    *str1 = *str2;
    *str2 = temp;
}

/*
 * 이 함수는 사용자에게 string하나를 입력받는 함수이다.
 * 그런데 만약 사용자가 아무 입력을 주지 않는다면,
 * 기존에 저장되어 있던 defualt값을 반환한다.
 * 그렇기 때문에 이 default값을 입력으로 받는다.
 *
 * 또, main함수에 있는 array의 값을 변경시켜야 하므로,
 * 그 array 역시 입력받는다.
 *
 * 또, gets함수를 통해 입력받는데, 이렇개 되면 맨 마지막
 * array에 굳이 필요하지 않은 newline character가 들어가게 되므로,
 * 그것을 '\0' 으로 바꿔준다.
 *
 *  Input  : main에 정의되어 있는 입력한 값을 저장할 array 하나를
 *           pointer형태로 입력받고, 사용자가 아무것도 입력하지 
 *           않은 경우에 줄 값인 default_str이라는 string을 입력받는다.
 *
 *  Output : gets 함수를 통해 main에 있는 array를 바꾸거나,
 *           strcpy 함수를 통해 default값을 array에 넣는다.
 *           그러나 return을 통한 출력은 없다.
 */
void getSentence(char *buffer, char *default_str) {
    /* 맨 마지막 값을 '\0'로 바꾸기 위해 필요한 string의 길이를 나타내는 변수 선언 */
    int length;

    /* 사용자에게 token으로 쪼개질 string 입력받음 */
    printf("Enter a string to be tokenized : ");
    gets(buffer);

    /* string의 첫 값이 '\0'이거나 엔터만 쳤을 경우 array에 default값 복사 */
    if (!(buffer[0]) || (buffer[0] == '\n' && buffer[1] == (char)0)) {
        strcpy(buffer, default_str);
        return; /* 더 이상 진행할 필요 없으므로 return */
    }

    /* 함수의 길이를 측정해서 맨 마지막 값이 \n이면 '\0'로 변환 */
    length = strlen(buffer);
    if (buffer[length-1] == '\n')
        buffer[length-1] = (char)0;
}

/* 이 함수는 string.h에 정의된 strtok함수와 비슷한 역할을 하는 함수이다.
 * string과 separator를 입력으로 받아, separator로 string을 token 단위로
 * 나눈다.
 *
 * 함수가 여러번 call되므로, modified_str이라는 static 변수를 이용해 string을 저장한다.
 * 그리고 이 외에도 여러 static 변수를 사용한다.
 *
 * string으로 NULL이 아닌 값을 입력받은 경우, 우선 modified_str에
 * 주어진 string을 대입한다. 그리고 modified_str의 처음 문자부터 마지막 문자까지
 * separator가 있는지를 찾아본다. 만약 찾을 경우, 그 문자를 NULL로 초기화시키고,
 * modified_str을 return한다. 이렇게 되면 이를 출력할 때 modified_str의 처음부터
 * NULL까지 출력하므로, token화 된다. 그러나 만약 separator가 처음에 나온다면
 * 그것을 0으로 초기화 시킨 후에 다음 문자부터 위 과정을 수행한다.
 *
 * 만약 string으로 NULL이 주어지는 경우는 먼저 NULL이 아닌 값을 입력받았어야 한다.
 * 그러면 static 변수 modified_str에 이미 NULL으로 초기화된 부분이 있으므로,
 * 그곳 다음부터 string을 출력한다. 이 위치를 기억하기 위해 static변수 count1과
 * static은 아닌 변수 save를 이용한다. 역시 separator를 검사하는 방법은 NULL이
 * 아닐 때와 같다. 또, separator가 연속해서 붙어있는 경우는 무시하고
 * 다음 문자로 넘어간다.
 *
 * 반환하는 값은 이전에 '\0'으로 초기화된 문자 다음부터의 string이다. 역시 이 경우도
 * 위와 마찬가지로 token화 된다.
 *
 * 또 더 이상 separator을 더 이상 찾을 수 없을 때에는 return_null이라는 변수를
 * 이용해 일단 마지막 token을 출력하고 다음 번 function call에서 NULL을 반환하게 한다.
 *
 *  Input  : main함수에서 정의된 string과 그것을 쪼갤 separator를 입력받는다.
 *           둘 다 모두 string이므로, pointer 표현을 이용한다.
 *
 *  Output : separator가 있는 지 없는지 검사한 첫 번째 지점의 문자의 주소를
 *           return한다. 이 곳이 token화 된 곳의 시작 점의 된다. 이외의
 *           출력은 없다.
 */
char *user_strtok(char *str, char *separator) {
    /* string의 몇 번째 문자를 세고 있나 알기 위한 변수 */
    static int count1;

    /* string의 반환을 어디서부터 해야 하는 지를 알기 위한 변수 */
    int save;

    /* 마지막 token을 출력하고 다음 번에 NULL을 반환하기 위한 변수
     * 0으로 초기화 한 이유는 if (return_null)꼴을 이용해 0이 아니면
     * NULL을 반환하기 위해 */
    static int return_null = 0;

    /* token화 되는 변경되는 string으로, 입력받은 string으로 초기화
     * NULL 입력시 계속 값 유지 */
    static char *modified_str;

    /* separator들을 처음부터 끝까지 세기 위한 변수 */
    int count2;

    /* 새로운 string 입력시 초기화 후 시작*/
    if (str != NULL) {
        modified_str = str;
        save = 0; /* string의 반환을 처음으로 */

        /* 문자를 처음부터 끝까지 검사 */
        for (count1 = 0; modified_str[count1] != (char)0; ++count1)

            /* 각 문자마다 separator들이 있는지 찾아냄 */
            for (count2 = 0; separator[count2] != (char)0; ++count2)

                /* separator 있으면 NULL로 초기화후 string의 처음 주소 반환 */
                if (modified_str[count1] == separator[count2]) {
                    modified_str[count1] = (char)0;

                    /* 처음에 separator가 나오면 return하지 않고 다음 문자를
                     * 검사하도록 함 */
                    if (save == count1) {
                        save++; /* 반환할 문자를 다음 문자로 변경시킴 */
                        break;
                    }

                    /* save를 더해 시작점을 0 뒤로 이동시킨 후 반환 */
                    return (modified_str + save);
                }

            /* 아무 문자도 separator가 없으면 다음 번에 NULL을 출력하도록
             * return_null의 값을 1로 만든 후 string의 주소 반환*/
            return_null++;
            return (modified_str + save);

    } else {
        /* return_null이 0이 아니면 NULL 반환. */
        if (return_null)
            return (char*)NULL;

        /* 이전에 계산한 문자의 다음 문자를 계산하기 위해 1을 더한 후 
         * return할 때 첫 문자를 제대로 반환하기 위해 그 값을 save라는 변수에 저장 */
        save = ++count1;

        for (; modified_str[count1] != (char)0; ++count1)
            for (count2 = 0; separator[count2] != (char)0; ++count2)
                if (modified_str[count1] == separator[count2]) {
                    modified_str[count1] = (char)0;

                    /* 연속해서 separator가 나오면 return하지 않고 다음 문자를
                     * 검사하도록 함 */
                    if (save == count1) {
                        save++; /* 반환할 문자를 다음 문자로 변경시킴 */
                        break;
                    }

                    /* save를 더해 token의 시작점을 NULL 다음으로 하게 함 */
                    return (modified_str + save);
                }

                /* 역시 아무 문자도 separator가 없으면 다음 번에 NULL을 출력하도록
                 * return_null의 값을 1로 만든 후 string의 시작점 반환 */
                return_null++;
                return (modified_str + save);
    }
}
