#include <stdio.h>
#include <math.h>
#include "array_num.h"

/*
* function : shift_element 
* ....................
*
* Move the i cells of the array right  
*
* arr : our array 
*
* i: the number of cells that we have to move right
*
* return : default 0
  */
int shift_element(int* arr , int i){
    for (size_t j = i; j > 0; j--){
        *(arr+j)=*(arr+j-1);
    }
    return 0;
}

/*
* function : insertion_sort 
* ....................
*
* sort our array --> insertion sort algorethum 
*
* arr : array to sort 
*
* len : length of the array
*
  */
int insertion_sort(int* arr ,int len){
    int i , j , k , count ;
    for (i = 1; i < len; i++){
    count=0;
        k = *(arr+i);
        j=i-1;
            if(*(arr+j)>k){
            while (*(arr+count)<k && count<j){
                count++;
            }
            shift_element(arr+count,j-count+1);
            *(arr+count)=k;
    }
    }
}
/*
* function : print_array 
* ....................
*
* print the array 
*
* arr : array to print 
*
* len : length of the array
*
* return : default 0;
  */

int print_array(int* arr , int len){
    for (size_t i=0 ; i<len-1 ; i++){
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+len-1));
    return 0;
}
