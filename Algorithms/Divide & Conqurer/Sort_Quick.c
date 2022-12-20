/*
In Quick Sort, we divide the array of items to be sorted into two partitions and then call the quick sort procedure to sort the two partitions.
To partition the data elements, a pivot element is to be selected,
such that all the items in the lower part are smaller and the items in the upper part are greater then the pivot items.

There are many different versions of quickSort that pick pivot in different ways. 
->  Always pick the first element as a pivot.
->  Always pick the last element as a pivot (implemented below)
->  Pick a random element as a pivot.
->  Pick median as the pivot.

Time Complexcity -> O(n^2)
Adaptive Algorithm - Not!
Stable Algorithm   - Not!


Algorithm:
    low  –> Starting index,  high  –> Ending index 
    Quick Sort(arr[], low, high) {
        if (low < high) {
            //pi is partitioning index, arr[pi] is now at right place 
            pi = partition(arr, low, high);
            quick Sort(arr, low, pi – 1);  // Before pi
            quick Sort(arr, pi + 1, high); // After pi
        }
    }

    Partition (arr[], low, high){
    // pivot (Element to be placed at right position)
    pivot = arr[high];  

    i = (low – 1)  // Index of smaller element and indicates the 
    // right position of pivot found so far
    for (j = low; j <= high- 1; j++){

        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high])
    return (i + 1)
    }
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
