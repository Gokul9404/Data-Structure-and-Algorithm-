/*
    Time Complexcity -> O(n logn)

    It divides a array into two parts, and then it sorts the array..
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