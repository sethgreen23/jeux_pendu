#include <stdio.h>
#include <stdlib.h>
#include "pendu.h"
int main(int argc, char** argv){
  // printf("length of the word: %d.\n",word_len("hello world"));
  // printf("uppercase is %c \n",from_input_uppercase('A'));
  // printf("the uppercase of %s is %s  .\n","hello w",to_uppercase("hello world"));
  // init(argv, argc);
  if(isLetter('"')==false){
    printf("it is not letter");
  }else{
    printf("it is a letter");
  }
}