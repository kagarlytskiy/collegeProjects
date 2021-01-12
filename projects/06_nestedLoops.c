// TODO: https://imgur.com/IlFwM5J

#include <stdio.h>
#include <math.h>

int main()
{
        double j, i;
        int k;
        double a = 0, p;

        printf("Введите k\n");
        scanf("%d", &k);

        for (j = 1; j <= k; j++) {
                if (j != 4) {
                        p = 1;
                        for (i = 0; i <= j && i != 1; i++)
                                p *= (sqrt(i+4))/(i-1);

                        a += (j-3)/(j-4);
                }
        }

        printf("a = %lf\n", a);

        return 0;
}
