#ifndef _DATA_UTILS_H
#define _DATA_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* preprocess_id(char* name);
int is_valid_name(char n);

char* preprocess_id(char* name){
    int i = 0;
    while(is_valid_name(name[i]))
           i++;
    name[i] = '\0';
    return name;
}

char* copy_name(char* name){
    int i;
    char * copied_name = (char *)malloc(sizeof(char) * strlen(name));

    for(i = 0; is_valid_name(name[i]); i++)
      copied_name[i] = name[i];

    copied_name[i] = '\0';
    return copied_name;
}

char* copy_string(char* string){
    int i = 0;
    int cnt = 0;
    char * copied_string = (char *)malloc(sizeof(char) * strlen(string));

    while(cnt < 2){
      if (string[i] == '\"')
          cnt += 1;
      copied_string[i] = string[i];
      i++;
    }

    copied_string[i] = '\0';
    return copied_string;
}


int is_valid_name(char n){
  if('a' <= n && n <= 'z')
    return 1;
  if('A' <= n && n <= 'Z')
    return 1;
  if('0' <= n && n <= '9')
    return 1;
  if (n == '_')
    return 1;

  return 0;
}

int find_idx(char* names[], char* id){
  int i;
  char* temp = copy_name(id);
  for(i = 0; names[i] != 0; i++){
      if(strcmp(temp, names[i]) == 0){
          free(temp);
          return i;
      }
  }

  free(temp);
  return -1;
}


#endif
