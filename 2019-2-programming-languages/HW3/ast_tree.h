#ifndef _AST_TREE_H
#define _AST_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "data_utils.h"

#define TRUE 1
#define FALSE 0


#define T_INT 100
#define T_STR 101
#define T_CHAR 102
#define T_FLOAT 103
#define T_DOUBLE 104
#define T_VOID 105


extern FILE * yyout;

#define INDEX_SIZE 1000
#define MAX_NAME_LENGTH 25
#define MAX_CONTENT_LENGTH 700

typedef struct ast_node{
    char* name;
    int id_type;
    int token_type;
    int fun_type;

    int space;

    struct ast_node* child;
    struct ast_node* parent;
    struct ast_node* next;
    struct ast_node* prev;

    int node_type;

}ast_node;

char* id_names[INDEX_SIZE] = { (char*)0 };
char* fun_names[INDEX_SIZE] = { (char*)0 };
int id_types[INDEX_SIZE] = { 0 };
int fun_types[INDEX_SIZE] = { 0 };

ast_node* create_node();
ast_node* create_node_enter();
ast_node* create_node_id(char* id_name, int id_type);
ast_node* create_node_fun(char* fun_name, int fun_type);
ast_node* create_node_token(char* token, int space);
ast_node* create_node_string(char* string, int id_type);
ast_node* create_child_dummy_node();

ast_node* add_child_last(ast_node* parent, ast_node* child);

//void print_tree(ast_node* root, int depth);
void traverse_tree(ast_node* root);

ast_node* create_node(){
  ast_node* node = (ast_node*)malloc(sizeof(ast_node));

  node -> parent = NULL;
  node -> next = NULL;
  node -> prev = NULL;
  node -> child = create_child_dummy_node();

  node -> name = NULL;
  node -> id_type = -1;
  node -> token_type = -1;
  node -> fun_type = -1;

  node -> space = FALSE;

  return node;
}

ast_node* create_node_enter(){
  ast_node* node = create_node();
  node -> name = ";\n\0";
  node -> space = FALSE;
  return node;
}

ast_node* create_node_id(char* id_name, int id_type){
  ast_node* node = create_node();

  node -> name = copy_name(id_name);
  node -> id_type = id_type;
  return node;
}

ast_node* create_node_string(char* string, int id_type){
  ast_node* node = create_node();

  node -> name = copy_string(string);
  node -> id_type = id_type;
  return node;
}

ast_node* create_node_fun(char* fun_name, int fun_type){
  ast_node* node = create_node();

  node -> name = copy_name(fun_name);
  node -> fun_type = fun_type;
  return node;
}

ast_node* create_node_token(char* token, int space){
  ast_node* node = create_node();

  node -> name = token;
  node -> space = space;

  return node;
}


ast_node* add_child_last(ast_node* parent, ast_node* child){
  ast_node* cur_node = parent -> child;

  while(cur_node -> next != NULL)
    cur_node = cur_node -> next;

  cur_node -> next = child;
  child -> prev = cur_node;

  child -> parent = parent;
  return parent;

}

ast_node* create_child_dummy_node(){
  ast_node* node = (ast_node*)malloc(sizeof(ast_node));
  node -> parent = NULL;
  node -> next = NULL;
  node -> prev = NULL;
  node -> child = NULL;

  return node;
}

/*
void print_tree(ast_node* root, int depth){
  for (int i = 0; i < depth; i++)
    printf("  ");

  printf("%s", root -> nodename);
  if ((root -> nodecontent)[0] != '\0'){
      printf(" : %s", root -> nodecontent);
  }
  printf("\n");

  ast_node* cur_node = root->child->next;

  while(cur_node != NULL) {
    print_tree(cur_node, depth + 1);
    cur_node = cur_node -> next;
  }
}
*/

void traverse_tree(ast_node* root){



  if(root->name != NULL){
    if (root -> id_type >= T_INT && root -> id_type <= T_DOUBLE){
        switch (root -> id_type) {
          case T_INT:
              printf("Integer ");
              fprintf(yyout, "Integer ");
              break;
          case T_STR:
          printf("String ");
          fprintf(yyout, "String ");
          break;
          case T_CHAR:
          printf("char ");
          fprintf(yyout, "char ");
          break;
          case T_FLOAT:
          printf("Float ");
          fprintf(yyout, "Float ");
          break;
          case T_DOUBLE:
          printf("Double ");
          fprintf(yyout, "Double ");
          break;
        }
    }


      if (strcmp(root->name, "println") == 0){
        printf("System.out.println");
        fprintf(yyout, "System.out.println");
      }

      else {
        printf("%s", root -> name);
        fprintf(yyout, "%s", root -> name);
      }

}


  if(root->space == TRUE){
    printf(" ");
    fprintf(yyout, " ");
  }


  ast_node* cur_node = root->child->next;

  while(cur_node != NULL) {
    traverse_tree(cur_node);
    cur_node = cur_node -> next;
  }
}

#endif
