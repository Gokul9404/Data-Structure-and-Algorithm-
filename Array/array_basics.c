/*
Arrays in C 
An Array is a collection of data itmes os same type
data_type_of_array array_name[array_size];
E.g.(int marks[4] = {1,3,2,1};)
    Anthor way to assign values
    (int marks[4];
    marks[0]=1;
    marks[1]=3;
    marks[2]=2;
    marks[3]=1;)
//// Pointers in Array
int marks[4] = {3,1,2,5};
int* pntr = marks;  // It will store address of first index element in the Array, 
                    //i.e. here it will store address of marks[0] or say addresss of 3 which is the first index in the Array 
*/
/*
Array Reversal
First   :- Get size of array using sizeof(Array_name)
Second  :- Use for loop to iterate the Array, if array size is odd go upto (size-1)/2 and if size is even go upto size/2
Third   :- Swap the N-th Index element with Size/Length of Array - N-th Index values

[Note:- Swap Can be done by using simple add-subtract swap, swap using the new variable(then return them to the place) or Via Using the Call by reference Method. ]
*/
//-------------------------------------------------------------------
#include<stdio.h>

int main(){
    int marks[4] = {1,3,2,1};
    int* pntr = marks;
    // Get Array Element
    printf("Array's First Element:-%d, it's Address is:-%p\n",marks[0],pntr);
    int a,b;
    // Set Array Element
    printf("No. you want to put in array:-");
    scanf("%d",&a);
    printf("No. to be placed at index :-");
    scanf("%d",&b);
    b = ( b % sizeof(marks) );
    marks[b] = a;
    printf("%d", marks[b]);
    return 0;
}