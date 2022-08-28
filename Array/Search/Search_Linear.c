/*
    Time Complexcity -> O(n)
*/

#include<stdio.h>

int Linear_search_func(int *arr, int size, int element){
    for (int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,5,6};
    int size;
    size =  sizeof(arr)/ sizeof(int);
    int Item_index, element_to_find=5;
    Item_index = Linear_search_func(arr,size,element_to_find);
    if (Item_index != -1){
        printf("\nElement %d is at index %d",element_to_find, Item_index);
    }
    else{
        printf("\nItem is not in the array");
    }
    return 0;
}