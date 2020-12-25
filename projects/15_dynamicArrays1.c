// TODO: добавить элемент в конец массива

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void * append(int * point, int size, int * length)
{
        int i;
        int new_size = size + 1;
        int * new_addr = (int *) realloc(point, new_size * (int)sizeof(int));

        printf("добавить в конец массива: ");
        scanf("%d", &new_addr[*length]);
        *length++;
}

int main()
{
        int *a;
        int i;
        int size = 0;
        int n = 5;

        a = (int*)malloc(size * sizeof(int));

        for (i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
        }

        append(a, size, &n);
        n++;

        for (i = 0; i < n; i++)
                printf("%d ", a[i]);
        printf("\n");

        free(a);

        return 0;
}
