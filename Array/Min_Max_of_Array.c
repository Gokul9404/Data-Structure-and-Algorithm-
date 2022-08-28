#include<stdio.h>

int main()
{
    int i, min, max, size;
    size = 12;
    int array1[size];

    for(i=0; i < size;i++)
    {
        printf("Enter the array elemet[%d]",i);
        scanf("%d",array1[i]);
    }
    min = max = array1[0];
    for(i=0; i < size;i++)
    {
        if (min > array1[i]) 
        { 
            min = array1[i]; 
            continue;
        }
        if (max < array1[i] ) 
        {
            max = array1[i];
        }
    }
    printf("Min. no of the Array is %d\nMax. no of the Array is %d ",min,max);
    return 0;
}