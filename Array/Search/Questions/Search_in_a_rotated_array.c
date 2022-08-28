/*
    Time Complexcity -> log(n)
*/
#include <stdio.h>

int Binary_search(int* array ,int low, int high, int element){
    int middle;
    while (low <= high){
        middle = (low + high) / 2;
        if (array[middle] == element){
            printf("%d found at location %d.\n", element, middle);
            return middle;
        }
        if(array[low] < array[middle]){
            if(element >= array[low] && element < array[middle]){
                high = middle -1;
            }
            else {
                low = middle + 1; 
            }
        }
        else {
            if (element > array[middle] && array[high] >= element){
                low = middle + 1;
            
            }
            else{
                high = middle - 1;
            }
        }
    }
    printf("Not found! %d isn't present in the list.\n", element);
    return -1;
}

void main(){
    int i, n, element_to_search;
    printf("Enter number of elements in the array:-");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers to be inserted in the array:\n", n);
    for (i = 0; i < n; i++){
        array[i] = i*i;
    }
    // Second , we will find the element user want to search
    printf("Enter value to find:-");
    scanf("%d", &element_to_search);
    int Start=0, end=n-1;
    Binary_search(array,Start,end,element_to_search);
}