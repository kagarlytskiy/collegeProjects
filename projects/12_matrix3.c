// TODO: Разработать программу, соблюдая следующие требования:
// • использовать статические массивы;
// • максимальные размеры массива [N] [M] - статические константы;
// • реальные размеры массива n i m (n <N, m <M) - ввести с клавиатуры (при этом
// осуществлять проверку правильности ввода данных);
// • элементы массива - псевдослучайные числа, сгенерированные на интервале [a, b], где a и b (a <b) вводятся с клавиатуры;
// • все входные данные и элементы массива выводить на экран.

#include <stdio.h>
#include <stdlib.h>
 
#define N 100
#define M 100
 
int randnum(int, int);
 
int main()
{
        int c[N][M];
        int d[N][M];
        int e[N][M];
        int n, m;
        int a, b;
        int i, j;
 
        printf("введите значения n и m\n");
        scanf("%d %d", &n, &m);
        printf("введите значения a и b\n");
        scanf("%d %d", &a, &b);
 
        if (n <= 0 || m <= 0 || n > N || m > M) {
                printf("неверные значения. введите снова\n");
                scanf("%d %d", &n, &m);
        }
 
        printf("n = %d, m = %d; a = %d, b = %d\n", n, m, a, b);
 
        printf("\nмассив с\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                        c[i][j] = randint(a, b);
                        d[i][j] = randint(a, b);
                        e[i][j] = c[i][j] * d[i][j];
                        printf("%d ", c[i][j]);
                }
                printf("\n");
        }
 
        printf("\nмассив d\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%d ", d[i][j]);
                printf("\n");
        }
 
        printf("\nмассив e (произведение с на d)\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%d ", e[i][j]);
                printf("\n");
        }
 
        return 0;
}
 
int randint(int a, int b)
{
        int rand_num = (rand() % (b - a + 1)) + a;
        return rand_num;
}
