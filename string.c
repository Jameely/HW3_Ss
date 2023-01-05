#include <string.h>
#include <stdio.h>

/* Max characters in line*/
#define LINE 256

/* Max character in word*/
#define WORD 30

/*
* function :get_line 
* ....................
* reads a line from standard input
*
* s: the array to put the line
*
*return : the number of characters that the function has read.
  */
int get_line(char s[LINE]){
    int i=1;
    int num_of_chars=0;
    while (i!=0){
        if(scanf("%c" , &s[num_of_chars])==EOF){
            s[num_of_chars]='\0';
            i=0;
        }

        else if(s[num_of_chars]!='\n' && s[num_of_chars]!= '\r'){

                num_of_chars++;
        }
        else{
            s[num_of_chars]='\0';
            num_of_chars++;
            i=0;
        }
    }

return num_of_chars;
    }

/*
* function :getword 
* ....................
* reads a word from standard input
*
* s: the array to put the word
*
*return : the number of characters that the function has read.
  */

int getword(char w[30]){
    int i=1;
    int num_of_chars=0;    
    while (i!=0){
        if(scanf("%c" , &w[num_of_chars])==EOF){
            w[num_of_chars]='\0';
            i=0;
        }
        else if(w[num_of_chars]!='\n' && w[num_of_chars]!= '\r' && w[num_of_chars]!= '\t' && w[num_of_chars]!= ' '){

                num_of_chars++;
        }
        else{
            w[num_of_chars]='\0';
            num_of_chars++;
            
            i=0;
        }
    }

return num_of_chars;
    }

/*
* function : isEqualString  
* ....................
* chek if the strings is equal or not
*
* s1: The first String 
*
* s2: The second String
*
* n : The length of the string 
*
*return : 1 if the strings is equal /// 0 if the string is not equal.
  */
int isEqualString (char s1[] , char s2[] , int n){

    for (size_t i = 0; i < n; i++){
        if (s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}
/*
* function :substring 
* ....................
* chek if the second string is a substring of the first string
*
* str1: first string
*
* str2: second string
*
*return : 1 if the second string is a substring of the first /// 0 else
  */

int substring(char *str1 , char *str2){
    int len2 =strlen(str2);
    int len1 =strlen(str1);
    if(len2>len1){
        return 0;
    }
    else{
        for (size_t i = 1; i <= len1-len2; i++)
        {
            if (isEqualString(str2,str1+i,len2)){
                return 1;
            }
            
        }
        
    }
    return 0;
}

/*
* function :similiar 
* ....................
* chek if we can get the second string from the frist by ommite n characters.
*
* t: first string
*
* s: second string
*
* n: number of characters that we have to ommite
*
*return : 1 if we can get the second string from the first by ommite n characters /// 0 else
  */

int similiar(char* s , char* t , int n){
    int lent = strlen(t) , lens = strlen(s) , i=0 , j=0;

    if(lens-lent!=n){
        return 0;
    }
    
    for(i=0 ; i<lens && j<lent ; ++i){
        if (*(s+i) == *(t+j))
        ++j;
    }

return (lent==j);
}

/*
* function : print_lines 
* ....................
*
* print the lines that contains our string 
*
* str : the string that we have to search
*
  */

void print_lines(char* str){
    int temp=1;
    char s[LINE];
    while(temp >=1 && temp<=LINE){
         temp = get_line(s);
        if (substring(s,str)){
            printf("%s\n" ,s);
        }
    }
}
/*
* function : print_similiar_words 
* ....................
*
* print the words that can reach our string by ommite one character 
*
* str : the string that we have to search
*
  */
void print_similiar_words(char *str){
        char s[WORD] ={ 0 };
    while (getword(s)!=0)
    {
        if (similiar(s,str,1) || similiar(s,str,0))
                printf("%s\n" ,s);   
    }
}