/*
    Time Complexcity -> O(n^2)

    Adaptive Algorithm - Not!
    Stable Algorithm   - Not!
    
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

int partition(int* Ary, int low, int high){
    int pivot = Ary[low], tmp;
    int i = low + 1, j = high;

    do{
        while (Ary[i] <= pivot){
            i++;
        }
        while (Ary[j] > pivot){
            j--;
        }
        if (i < j){
            tmp = Ary[i];           // Swapping the i-th element  
            Ary[i] = Ary[j];        // with the smaller element 
            Ary[j] = tmp;           // in the remaining array
        }
    }while (i <j);
    
    tmp = Ary[low];
    Ary[low] = Ary[j];
    Ary[j] = tmp;

    return j;
}

void Quick_sort(int* Ary,int low, int high){
    int partition_index;
    if(low < high){
        partition_index = partition(Ary,low,high);  // index of Pivot after partition
        Quick_sort(Ary, low, partition_index-1);    // Sorting left Sub-Array
        Quick_sort(Ary, partition_index+1, high);   // Sorting right Sub-Array
    }
}

int main(){
    int n = 0;
    printf("Enter number of elements in the array:- ");
    scanf("%d", &n);
    int Ary[n];
    get_array(Ary,n);
    Print_array(Ary,n);
    
    Quick_sort(Ary,0,n-1);
    
    printf("\nPrinting the sorted array:-");
    Print_array(Ary,n);
    return 0;
}
