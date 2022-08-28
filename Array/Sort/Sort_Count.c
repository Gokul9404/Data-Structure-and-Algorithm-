/*
    Time Complexcity -> O(n^2)

    It count the no of element appeared in the array, and then it add the numbers in the increasing order of no. and add the same no. for the times it appeared in the Array 
*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

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

int Maximum_element_in_array(int* Ary, int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
        if (max < Ary[i]){
            max = Ary[i];
        }
    }
    return max;
}

void Count_sort(int* Ary, int n){
    int i, j;
    int max = Maximum_element_in_array(Ary,n);  // Finding the Maximum element in the array

    // Creating a Count array which count the no of each element appeared in the array and keep there count
    int* Count_array = (int *) malloc((max+1)*sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max+1; i++){
        Count_array[i] = 0; 
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++){
        Count_array[Ary[i]] = Count_array[Ary[i]] + 1; 
    }

    i =0; // counter for count array
    j =0; // counter for given array A

    while(i<= max){
        if(Count_array[i]>0){
            Ary[j] = i;
            Count_array[i] = Count_array[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 
}

int main(){
    int n = 0;
    printf("Enter number of elements in the array:-");
    scanf("%d", &n);
    int Ary[n];
    get_array(Ary,n);
    Print_array(Ary,n);
    
    Count_sort(Ary, n);
    
    printf("\nPrinting the sorted array:\n");
    Print_array(Ary,n);
    return 0;
}
