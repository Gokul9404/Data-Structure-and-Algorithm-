#include "stdio.h"

void delete_node(int a[], int n, int value){
    a[1] = a[n];
    n = n - 1;
    int i = 1;
    while(i < n){
        int left = a[i*2];
        int right = a[(i*2)+1];
        int larger = left>right ? 2*i : 2*i +1;
        if(a[i] < a[larger]){
            int temp = a[i];
            a[i] = a[larger];
            a[larger] = temp;
            i = larger;
        }
        else{
            return;
        }
    }
}

int main(){
    return 0;
}
