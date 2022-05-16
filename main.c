#include <stdio.h>
#include <stdlib.h>
#include "pendu.h"
int main(int argc, char** argv){
  pendu p = init(argv, argc);
  // get user input and enter on a loop game
  char input;
  print_return_line();
  do{
    printf("\n");
    show_word(p);
    printf("Please enter a letter:\n");
    scanf(" %c",&input);
    // check if it is not a character then continue we dont need
    //to keep what we are doing
    if(isLetter(input)==false){
      printf("\nYou have  %d mistakes left.\n",p->mistake_count);
      printf("The letter %c doesnt exist in the word.\n\n",input);
      continue;
    }
    // if it is a letter we continue the testing
    //upercase the input
    input = from_input_uppercase(input);
    // here we create a counter for the letter count
    int counter=0;
    counter = letter_exist(p->word,p->word_length,input);
    if(counter>0){
      //index of the specific letter in the table
      int index = input - 65;
      if(p->dejavue[index]==0){
        p->counter_till_word+=counter;
        p->dejavue[index]=1;
        printf("\nYou have  %d mistakes left.\n",p->mistake_count);
        printf("The letter %c exists in the word.\n",input);
      }else{
        printf("\nYou have  %d mistakes left.\n",p->mistake_count);
        printf("You choosed the letter %c.This letter exists in the word.\n",input);

      }
    }else{
      p->mistake_count--;
      printf("\nYou have  %d mistakes left.\n",p->mistake_count);
      printf("The letter %c doesnt exist in the word.\n",input);
    }
  }while(p->mistake_count>0 && p->counter_till_word!=word_len(p->word));
  printf("\n\n");
  if(p->mistake_count<=0){
    printf("You already used all your fehler\n");
    printf("The word you search is \"%s\" \n",p->word);
  }
  if(p->counter_till_word==word_len(p->word) && p->mistake_count>0){
    printf("Congratulation you won!!! \n",p->mistake_count);
    printf("The word you search is \"%s\"",p->word);
  }
  printf("\n\n");
  free_pendu(p);
}