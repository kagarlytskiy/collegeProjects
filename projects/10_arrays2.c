// TODO: Дан массив размера N, все элементы которого, кроме первого, упорядочены по возрастанию. Сделать массив упорядоченным, переместив первый элемент на новую позицию.

#include <stdio.h>
 
int main()
{
        int arr[10] = {7, 1, 2, 3, 4, 5, 6, 8, 9, 10};
        int length = sizeof(arr)/sizeof(arr[0]);
        int saved1 = arr[1];
        int i, o;
 
        for (i = 0; i < length; i++) {
                if (arr[0] < arr[i]) {
                        for (o = i-1; o > 0; o--)
                                arr[o] += 1;
                        arr[i-1] = arr[0];
                        arr[0] = saved1;
                        break;
                }
        }
 
        for (int n = 0; n < length; n++)
                printf("%d ", arr[n]);
        printf("\n");
 
        return 0;
}

