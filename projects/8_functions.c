// TODO: cоздать функцию вычисления количества цифр числа и определить с ее помощью количества цифр для каждого из трех введенных чисел.

#include <stdio.h>

int main()
{
        int n;
        int c;

        for (c = 1; c < 4; c++) {
                printf("Введите число №%d\n", c);
                scanf("%d", &n);

                printf("кол-во цифр в числе: %d\n", counter(n));
        }

        return 0;
}

int counter(int n)
{
        int count;
        count = 0;

        while (n != 0) {
                n /= 10;
                count++;
        }

        return count;
}
