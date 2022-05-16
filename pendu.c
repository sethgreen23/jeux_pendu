#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pendu.h"

pendu init(char** tab,int len){
  pendu p = malloc(sizeof(struct _pendu));
  copy_elements(p,tab,len); 
  p->dejavue = init_int_table();
  p->counter_till_word=0;
  p->word_length=strlen(p->word);
  // show the first and the last letter
  int index = p->word[0]-65;
  int index1= p->word[p->word_length-1]-65;
  int count=0;
  count = letter_exist(p->word,p->word_length,p->word[0]);
  p->counter_till_word+=count;
  count = letter_exist(p->word,p->word_length,p->word[p->word_length-1]);
  p->counter_till_word+=count;
  p->dejavue[index]=1;
  p->dejavue[index1]=1;
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
  int count = count_not_letter(word);
  return len-count;
}
char from_input_uppercase(char input){
  if(input >='a' && input <='z')
      return input - 32;
  return input;
}
char* to_uppercase(char* word){
  int len = strlen(word);
  char* new_word=malloc(sizeof(char)*len);
  int i;
  for(i=0;i<len;i++){
    new_word[i]=from_input_uppercase(word[i]); 
  }
  new_word[i]='\0';
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

void show_word(pendu p){

  char* display = malloc(sizeof(char)*p->word_length);
  int i;
  for(i=0;p->word[i]!='\0';i++){
    if(isLetter(p->word[i])==false){
      display[i]=p->word[i];
      continue;
    }
    if(p->dejavue[p->word[i]-65]==1){
      display[i]=p->word[i];
      continue;
    }
    if(p->dejavue[p->word[i]-65]==0){
      display[i]='-';
      continue;
    }
  }
  display[i]='\0';
  printf("\n%s\n",display);
  free(display);
}

int count_not_letter(char* word){
  int count =0;
  for(int i=0;word[i]!='\0';i++){
    if(isLetter(word[i])==false)
      count++;
  }
  return count;
}

char* concatenate_words(char* word, char* concat){
  char* news = malloc(sizeof(char)*(strlen(word)+strlen(concat)));
  int i;
  for(i=0;word[i]!='\0';i++){
      news[i]=word[i];
  }
  int j;
  for(j=0;concat[j]!='\0';j++){
      news[i++]=concat[j];
  }
  news[i]='\0';
  
  word = news;
  return word;
}
void free_pendu(pendu p){
  free(p->dejavue);
}