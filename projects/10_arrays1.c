// TODO: дан массив размера N. осуществить циклический сдвиг элементов массива вправо на одну позицию (при этом А [1] перейдет в А [2], а [2] - в А [3], ..., а [N] - в А [1 ]).

#include <stdio.h>
 
int main()
{
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int length = sizeof(arr)/sizeof(arr[0]);
        int n;
        int copyLast = arr[length-1];
 
        for (n = length-1; n > 0; n--)
                arr[n] = arr[n-1];
 
        arr[0] = copyLast;
 
        for (int i = 0; i < length; i++)
                printf("%d ", arr[i]);
        printf("\n");
 
        return 0;
}
