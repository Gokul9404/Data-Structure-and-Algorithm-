/*
The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm.
In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner

Algorithm Working :
Step 1: If the array has not more than one elements then the array has already been sorted.

Step 2: Then we keep the half of the elements of the array in a new array named left and merge sorted them array.

Step 3: Then other half elements of array should kept in right array and merge sorted the array.

Step 4: Finally merge the two merge sorted array.

Time Complexcity -> O(n logn)
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

void Merge(int* Ary1, int mid, int low, int high){
    int i, j, k, res_ary[100];
    i = low;
    j = mid+1;
    k = low;
    while (i <= mid && j <= high){
        if(Ary1[i] < Ary1[j]){
            res_ary[k] = Ary1[i];
            i++;
            k++;
        }
        else{
            res_ary[k] = Ary1[j];
            j++;
            k++;
        }
    }
    while (i<=mid){
        res_ary[k] = Ary1[i];
        i++;
        k++;
    }
    while (j<=high){
        res_ary[k] = Ary1[j];
        j++;
        k++;
    }
    for(int i = low;i <= high;i++){
        Ary1[i] = res_ary[i];
    }
}

void Mergre_sort(int* Arry, int low, int high){
    int mid;
    if(low<high){
        mid = (low + high)/2;
        Mergre_sort(Arry, low, mid);
        Mergre_sort(Arry, mid+1, high);
        Merge(Arry,mid,low,high);
    }
}

int main(){
    int n = 0;
    printf("Enter number of elements in the array:- ");
    scanf("%d", &n);
    int Ary[n];
    get_array(Ary,n);
    Print_array(Ary,n);
    
    Mergre_sort(Ary,0,n-1);
    
    printf("\nPrinting the sorted array:-");
    Print_array(Ary,n);
    return 0;
}