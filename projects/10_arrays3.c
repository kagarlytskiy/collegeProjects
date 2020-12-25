// TODO: Дано целочисленный массив размера N. Удалить из массива все нечетные числа и вывести размер полученного массива и его содержание.

#include <stdio.h>

int main()
{
        int arr[5] = {11, 12, 37, 40, 55};
        int length = sizeof(arr)/sizeof(arr[0]);
        int n;

        for (n = 0; n < length; n++)
              if (arr[n] % 2 != 0) {
                  printf("%d нечетное число\n", arr[n]);

                  for (int o = n; o < length; o++) {
                    arr[o] = arr[o+1];
                  }

                length--;
                n--;
              }

        printf("конечный массив: ");
        for (int i = 0; i < length; i++)
                printf("%d ", arr[i]);
        printf("\n");

        return 0;
}
