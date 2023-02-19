#include <stdio.h>

int main()
{
    int arr_3d[2][3][3];
    int ari;
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the block %d Elements\n", i);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("\tEnter element [%d][%d]:- ", j, k);
                scanf("%d", &ari);
                arr_3d[i][j][k] = ari;
                ari = 0;
            }
        }
        printf("----------------------------------------\n");
    }

    for (int i = 0; i < 2; i++)
    {
        printf("{\n");
        for (int j = 0; j < 3; j++)
        {
            printf("\t{");
            for (int k = 0; k < 3; k++)
            {
                printf("%d ", arr_3d[i][j][k]);
            }
            printf("},\n");
        }
        printf("},\n");
    }

    return 0;
}