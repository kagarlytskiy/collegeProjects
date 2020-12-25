// TODO: удалить столбец с номером К

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
void removeRow(int **array, int *n, int row)
{
        int **tmp;
        tmp = malloc(sizeof(int*)*(*n-1));
 
        for (int i = row-1; i < *n-1; i++)
                array[i] = array[i+1];
        *n -= 1;
}
 
int main()
{
        int n;
        int m;
        int i, j;
        int k;
        int **array;
 
        printf("введите значение n и m: ");
        scanf("%d %d", &n, &m);
 
        array = malloc(sizeof(int*)*n);
 
        for (i = 0; i < n; i++)
                array[i] = malloc(sizeof(int)*m);
 
        for (i = 0; i < n; i++)
                for (j = 0; j < m; j++) {
                        printf("введите значение array[%d][%d]: ", i, j);
                        scanf("%d", &array[i][j]);
                }
 
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%d ", array[i][j]);
                printf("\n");
        }
        printf("\n");
 
        printf("строка для удаления: ");
        scanf("%d", &k);
        printf("\n");
 
        removeRow(array, &n, k);
 
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%d ", array[i][j]);
                printf("\n");
        }
        printf("\n");
 
        return 0;
}
