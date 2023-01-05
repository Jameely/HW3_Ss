#include <stdio.h>
#include "array_num.h"

#define ARRAY_LENGTH 50

int main(){

int Test[50];
for (size_t i = 0; i < ARRAY_LENGTH; i++)
{
scanf("%d", (Test+i));
}
insertion_sort(Test , 50);
print_array(Test , 50);
    return 0;
}