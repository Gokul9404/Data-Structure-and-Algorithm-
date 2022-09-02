#include "stdio.h"

void insert(int a[], int n, int value){
    n = n+1;
    a[n] = value;
    int i = n;
    while(i>1){
        int parent = i/2;
        if(a[parent] < a[i]){
            int temp = a[i];
            a[i] = a[parent];
            a[parent] = temp;
            i = parent;
        }
        else{
            return;
        }
    }
}

int main(){
    return 0;
}
