#include <stdio.h>
#include <stdlib.h>
#include "pendu.h"
int main(int argc, char** argv){
  pendu p = init(argv, argc);
  // get user input and enter on a loop game
  char input;
  print_return_line();
  do{
    printf("Please enter a number:\n");
    scanf(" %c",&input);
    // check if it is not a character then continue we dont need
    //to keep what we are doing
    if(isLetter(input)==false){
      printf("Il vous rest %d fehler.\n",p->mistake_count);
      printf("La character %c n'est pas une letter.\n\n",input);
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
        printf("Count to word %d , word lentgth %d \n",p->counter_till_word,p->word_length);
        printf("Il vous reste %d fehler.\n",p->mistake_count);
        printf("La letter %c exist dans le mot.\n",input);
      }else{
        printf("Count to word %d , word lentgth %d \n",p->counter_till_word,p->word_length);
        printf("Il vous reste %d fehler.\n",p->mistake_count);
        printf("Tu as deja chosie la letter %c.Elle exist dans le mot.\n",input);

      }
    }else{
      p->mistake_count--;
      printf("Il vous reste %d fehler.\n",p->mistake_count);
      printf("The letter %c n'exist pas das le mot.\n",input);
    }
  }while(p->mistake_count>0 && p->counter_till_word!=p->word_length);
  if(p->mistake_count<=0){
    printf("Your fehler are %d you lost\n",p->mistake_count);
    printf("The word you search is %s \n",p->word);
  }
  if(p->counter_till_word==p->word_length && p->mistake_count>0){
    printf("Your fehler  are %d you win \n",p->mistake_count);
    printf("The word you search is %s",p->word);
  }
}