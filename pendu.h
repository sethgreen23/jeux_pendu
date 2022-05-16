#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct _pendu* pendu;
typedef struct _pendu S_pendu;

struct _pendu{
  char* word;
  int word_length;
  int counter_till_word;
  char user_input;
  int mistake_count;
  int* dejavue;
};

pendu init(char** tab, int tab_len);
int word_len(char* word);
char from_input_uppercase(char input);
char* to_uppercase(char* word);
void copy_elements(pendu p,char** table,int tab_len);
void debug_char(char** tab,int len);
void debug_int(int* tab,int len);
int* init_int_table();
bool isLetter(char letter);
void print_return_line();
int letter_exist(char* word, int len, char letter);
void show_word(pendu p);
char* concatenate_words(char* word, char* concat);
int count_not_letter(char* word);
void free_pendu(pendu p);