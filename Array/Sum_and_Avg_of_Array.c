#include <stdio.h>
/*
In this Program we will find the Sum & Average/Meanof the Array
*/
int main()
{
    int i, sum, size;
    sum = 0;
    int array_of_numbers[12] = {1, 3, 2, 1, 19, 10, 8, 17, 9, 34, 10, 3};
    size = (sizeof(array_of_numbers) / sizeof(int));
    for (i = 0; i < size; i++)
    {
        sum = sum + array_of_numbers[i];
    }
    printf("The Sum of the Array is %d,\nAnd the Mean/Average of the Array is %d", sum, sum / i);
    return 0;
}