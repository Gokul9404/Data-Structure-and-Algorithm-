/*
    Time Complexcity -> log(n)
*/

#include <stdio.h>

void bubble_sort(int a[], int n){
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++){                // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++){    // last i elements are sorted already
            if (a[j] > a[j + 1]){           // swop if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void main(){
    int i, n;
    printf("Enter number of elements in the array:-");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers to be inserted in the array:\n", n);
    for (i = 0; i < n; i++){
        printf("\tEnter Array[%d] element:- ", i);
        scanf("%d", &array[i]);
    }
    // First, we will sort the array 
    bubble_sort(array, n);
    printf("The Array is going to be sorted using Bubble-sort Algorithm\n");

    // Second , we will find the element user want to search
    int first, last, middle, search;
    printf("Enter value to find:-");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    
    while (first <= last){                                              // finding the no using loop/itteration method
        if (array[middle] < search){
            first = middle + 1;
        }
        else if (array[middle] == search){
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        }
        else{
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last){                                                  // if element not found in the Array
        printf("Not found! %d isn't present in the list.\n", search);
    }

    printf("Sorted Array is :- \n[ ");
    for (i = 0; i < n; i++){
        printf("%d ,",array[i]);
    }
    printf("]");
}