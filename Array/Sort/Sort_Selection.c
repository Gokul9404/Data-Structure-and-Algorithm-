/*
    Time Complexcity -> O(n^2)

    Adaptive Algorithm - Not!
    Stable Algorithm   - Not!
    
    It can sort with minimum no. of swaps....
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

void Selection_sort(int* Ary, int size){
    int index_of_min_element = 0, tmp;
    for (int i = 0; i < size; i++){
        index_of_min_element = i;                       // The current index of small elemen is the element to swap itself
        for (int j = i+1; j < size; j++){               // looping the array to find smaller element
            if(Ary[j] < Ary[index_of_min_element]){     // If the element at 'index_of_min_element' is bigger than the element at'j' 
                index_of_min_element = j;               // the 'index_of_min_element' became 'j'
            }
        }
        tmp = Ary[i];                           // Swapping the i-th element  
        Ary[i] = Ary[index_of_min_element];     // with the smaller element 
        Ary[index_of_min_element] = tmp;        // in the remaining array
    }
}

int main(){
    int n = 0;
    printf("Enter number of elements in the array:- ");
    scanf("%d", &n);
    int Ary[n];
    get_array(Ary,n);
    Print_array(Ary,n);
    
    Selection_sort(Ary, n);
    
    printf("\nPrinting the sorted array:-");
    Print_array(Ary,n);
    return 0;
}
/*
    ::Process of Selection sort::
    Total no. of Passes -> Size of Array - 1
    -------------------------------------------------------
    0   1   2   3   4   5
    12| 65  54  7   23  9   -- Pass 1           index_of_min_element = 0
    _           _
    7   65  54  12  23  9   -- After Pass 1     index_of_min_element = 3
    -----------------------------------
    7   65| 54  12  23  9   -- Pass 2           index_of_min_element = 1
        _               _
    7   9   54  12  23  65  -- After Pass 2     index_of_min_element = 5
    -----------------------------------
    7   9   54| 12  23  65  -- Pass 3           index_of_min_element = 2
            _   _    
    7   9   12  54  23  65  -- After Pass 3     index_of_min_element = 3
    -----------------------------------
    7   9   12  54| 23  65  -- Pass 4           index_of_min_element = 3
                _   _
    7   9   12  23  54  65  -- After Pass 4     index_of_min_element = 4
    -----------------------------------
    7   9   12  23  54| 65  -- Pass 5 not req.  index_of_min_element = 4
    -------------------------------------------------------
    Array is sorted
*/