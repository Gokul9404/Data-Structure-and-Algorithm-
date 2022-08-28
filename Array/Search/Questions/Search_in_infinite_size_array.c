/*
    Time Complexcity -> log(n)
*/
#include <stdio.h>

int Binary_search(int* array ,int first, int last, int element){
    int middle;
    middle = (first + last) / 2;
    while (first <= last){                                              // finding the no using loop/itteration method
        if (array[middle] < element){
            first = middle + 1;
        }
        else if (array[middle] == element){
            printf("%d found at location %d.\n", element, middle);
            return middle;
        }
        else{
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last){                                                  // if element not found in the Array
        printf("Not found! %d isn't present in the list.\n", element);
        return -1;
    }
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
    int Start, end, key=1;
    while(array[key] < element_to_search){
        Start = key;
        key = key * 2;
    }
    end = key;
    Binary_search(array,Start,end,element_to_search);
}