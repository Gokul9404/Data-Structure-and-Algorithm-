#include<stdio.h>

void print_res_mat(int res[2][2]){
    /*
    Function used to print the result matrix
    */
    printf("Result matrix is :- \n");
    printf("[\n");
    for(int i= 0;i<2;i++){
        printf(" [ ");
        for(int j=0;j<2;j++){
            printf("%d ",res[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}

void add_matrix(int mat1[2][2],int mat2[2][2]){
    /*
    Function used to Add two Matrix
    */
    int res[2][2];
    for(int i= 0;i<2;i++){
        for(int j=0;j<2;j++){
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    print_res_mat(res);
}

void sub_matrix(int mat1[2][2],int mat2[2][2]){
    /*
    Function used to Subtract two Matrix
    */
    int res[2][2];
    for(int i= 0;i<2;i++){
        for(int j=0;j<2;j++){
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    print_res_mat(res);
}

void mult_matrix(int mat1m[2][2],int mat2m[2][2]){
    /*
    Function used to Multiply two Matrix
    */
    int resm[2][2];
    int m, n, p, q, tot=0;                  // m and p are the rows and, n and q are the columns of the matrices
    m=n=p=q=2;                              // n and p should be equal
    if (n == p){
        for (int c = 0; c < m; c++){        // first matrix no of rows tak   |^
            for (int d = 0; d < q; d++){    // mat2ond matrix no of columns tak  ->
                for (int k = 0; k < p; k++){
                    tot = tot + mat1m[c][k] * mat2m[k][d];
                }
                resm[c][d] = tot;
                tot = 0;
            }
        }
    }
    print_res_mat(resm);
}

int main(){
    int arr1[2][2], arr2[2][2];
    int a;
    for(int m=1;m<3;m++){
        printf("Please Enter the Matrix %d\n",m);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                printf("Matrix Element[%d][%d]- ",i,j);
                if (m == 1){ scanf("%d",&arr1[i][j]); }
                else{ scanf("%d",&arr2[i][j]); }
            }
        }        
    }
    printf("What do you like to do add[0] or subtract[1] or multiply[2]");
    scanf("%d",&a);
    if (a == 0){ add_matrix(arr1,arr2); }
    else if (a == 1){ sub_matrix(arr1,arr2); }
    else if (a == 2){ mult_matrix(arr1,arr2); }
    return 0;
}