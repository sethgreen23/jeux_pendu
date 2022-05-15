#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pendu.h"

pendu init(char** tab,int len){
  pendu p = malloc(sizeof(struct _pendu));
  copy_elements(p,tab,len); 
  p->dejavue = init_int_table();
  p->counter_till_word=0;
  p->word_length=word_len(p->word);
  printf("word: %s , mistake count: %d , word length: %d, counter until word %d. \n",p->word, p->mistake_count,p->word_length,p->counter_till_word);
  debug_int(p->dejavue,26);
  return p;
}
void copy_elements(pendu p,char** table, int len){
  if(len==1){
    p->word=to_uppercase("Thoraciquee") ;
    p->mistake_count=7;
    return;
  }
  if(len==2){
    p->word = to_uppercase(table[1]);
    p->mistake_count=7;
    return;
  }
  p->word = to_uppercase(table[1]);
  p->mistake_count = atoi(table[2]);
}
int word_len(char* word){
  int len =0;
  while(word[len]!='\0'){
    len++;
  }
  return len;
}
char from_input_uppercase(char input){
  if(input >='a' && input <='z')
      return input - 32;
  return input;
}
char* to_uppercase(char* word){
  int len = word_len(word);
  // printf("to_uppercase: len %d\n",len);
  char* new_word=malloc(sizeof(char)*len);
  int i;
  for(i=0;i<len;i++){
    new_word[i]=from_input_uppercase(word[i]); 
  }
  new_word[i]='\0';
  // printf("to_uppercase: word%sword\n",new_word);
  return new_word;
}
void debug_char(char** tab,int len){
  printf("[ ");
  for(int i=0;i<len;i++){
    if(i!=len-1)
      printf("%s, ",tab[i]);
    else
      printf("%s",tab[i]);
  }
  printf(" ]\n");
}
void debug_int(int* tab,int len){
  printf("[ ");
  for(int i=0;i<len;i++){
    if(i!=len-1)
      printf("%d, ",tab[i]);
    else
      printf("%d",tab[i]);
  }
  printf(" ]\n");
}
int* init_int_table(){
  int* tab = malloc(sizeof(int)*26);
  for(int i=0;i<26;i++){
    tab[i]=0;
  }
  return tab;
}

bool isLetter(char letter){
  bool result = true;
  if((letter <'a' || letter>'z')&&(letter <'A' || letter >'Z'))
    result = false;
  return result;
}

void print_return_line(){
  for(int i=0;i<40;i++){
    printf("\n");
  }
}

int letter_exist(char* word, int len, char letter){
  int count =0;
  for(int i=0;i<len;i++){
    if(letter == word[i])
      count++;
  }
  return count;
}
