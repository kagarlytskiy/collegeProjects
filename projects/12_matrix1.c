// TODO: Сформируйте двумерный массив, состоящий из 3 строк и 3 столбцов по правилу a [i, j] = i-j * j и выведите его на экран. Найдите количество положительных элементов таблицы.

#include <stdio.h>
 
int main()
{
        int a[5][3];
        int i, j;
        int count = 0;
 
        for (i=0; i<5; i++) {
                for (j=0; j<3; j++) {
                        a[i][j] = i - j * j;
 
                        if (a[i][j] >= 0) {
                                count++;
                        }
                }
        }
 
        for (int x=0; x<5; x++) {
                for (int y=0; y<3; y++) {
                        printf("%2d ", a[x][y]);
                }
                printf("\n");
        }
 
        printf("кол-во положительных чисел: %d\n", count);
 
        return 0;
}

