#include <stdio.h>
#include <string.h>
#include "string.h"

#define LINE 256
#define WORD 30

int main(){
    char word[WORD] ;
    char option;

    getword(word);
    scanf(" %c\n" ,&option);

    if(option =='a'){
        print_lines(word);
    }
    else if(option=='b'){
        print_similiar_words(word);
    }

    return 0;
}