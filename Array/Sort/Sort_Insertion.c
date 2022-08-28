/*
    Time Complexcity -> O(n^2)

    It is neither Stable nor Adaptive
*/

#include<stdio.h>

void Print_array(int* array, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void get_array(int* array, int size){
    printf("Enter %d integers\n", size);
    for (int i = 0; i < size; i++){
        printf("Enter Array[%d] element:- ", i);
        scanf("%d", &array[i]);
    }
}

void Insetion_sort(int* Array, int size){
    int key=0, j=0;
    for(int i=0; i < size; i++){        // Loop for each pass
        key = Array[i];      // A key that has to be swaped
        j = i - 1;
        while (j>=0 && Array[j] > key){
            Array[j+1] = Array[j];
            j--;        
        }
        Array[j+1] = key;
    }
}

int main(){
    int n = 0;
    printf("Enter number of elements in the array:-");
    scanf("%d", &n);
    int Ary[n];
    get_array(Ary,n);
    Print_array(Ary,n);
    
    Insetion_sort(Ary, n);
    
    printf("\nPrinting the sorted array:\n");
    Print_array(Ary,n);
    return 0;
}

/*
Process of Insertion sort 
    0   1   2   3   4   5
    12| 54, 65, 7,  23, 9   -- Pass 1, key = 12, j=0
    
    12, 54| 65, 7,  23, 9   -- Pass 2, key = 54, j=1

    12, 54, 65| 7,  23, 9   -- Pass 3, key = 65, j=2

    12, 54, 65, 7|  23, 9   -- Pass 4, key = 7 , j=3
    12, 54, 65, 65, 23, 9   
    12, 54, 54, 65, 23, 9   
    12, 12, 54, 65, 23, 9   
    7,  12, 54, 65, 23, 9   -- Pass 4 completed
    
    7,  12, 54, 65, 23| 9   -- Pass 5, key = 23 , j=4
    7,  12, 54, 65, 65, 9    
    7,  12, 54, 54, 65, 9    
    7,  12, 23, 54, 65, 9   -- Pass 5 completed
    
    7,  12, 23, 54, 65, 9|  -- Pass 6, key = 9 , j=5
    7,  12, 23, 54, 65, 65
    7,  12, 23, 54, 54, 65
    7,  12, 23, 23, 54, 65
    7,  12, 12, 23, 54, 65
    7,   9, 12, 23, 54, 65  -- Pass 6 completed

    Array Sorted
*/