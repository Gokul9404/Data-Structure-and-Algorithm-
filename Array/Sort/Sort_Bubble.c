/*
    Time Complexcity -> O(n^2)

    It is Stable algorithm
    It not Adaptive algorithm by default, but can be made adaptive
*/
#include <stdio.h>

void bubble_sort(int* a, int n){
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++){                // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++){    // last i elements are sorted already
            if (a[j] > a[j + 1]){           // swap if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void bubble_sort_adaptive(int* a, int n){   // If array is sorted then it will not take more passes/loops to check 
    int i = 0, j = 0, tmp;
    int Is_sorted = 0;
    for (i = 0; i < n; i++){                // loop/pass n times - 1 per element
        Is_sorted = 1;
        for (j = 0; j < n - i - 1; j++){    // last i elements are sorted already
            if (a[j] > a[j + 1]){           // swap if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                Is_sorted = 0;
            }
        }
        if (Is_sorted){
            break;
        }
    }
}

void Print_array(int* a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void get_array(int* a, int n){
    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++){
        printf("Enter Array[%d] element:- ", i);
        scanf("%d", &a[i]);
    }
}


int main(){
    int n = 0, i;

    printf("Enter number of elements in the array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Size of array :- %d \n",sizeof(a));
    get_array(a,n);

    Print_array(a,n);
    
    bubble_sort_adaptive(a, n);
    
    printf("\nPrinting the sorted array:\n");
    Print_array(a,n);
    return 0;
}