// TODO: из 3 чисел узнать и вывести наименьшое.

#include <stdio.h>
 
int main()
{
        float a[3] = {23.0, 9.0, 36.0};
        float b[3] = {17.0, -8.1, 65.0};
        float c[3] = {47.0, 9.1, 62.0};
        float av, bv, cv;
        int i;
 
        for (i = 0; i < 3; i++) {
                av = a[i];
                bv = b[i];
                cv = c[i];
 
                switch(av < bv && av < cv) {
                        case 0:
                                break;
                        case 1:
                                printf("а");
                                break;
                }
                switch(bv < av && bv < cv) {
                        case 0:
                                break;
                        case 1:
                                printf("b");
                                break;
                }
                switch(cv < bv && cv < av) {
                        case 0:
                                break;
                        case 1:
                                printf("c");
                                break;
                }
                printf(" - наименьшее значение\n");
        }
        return 0;
}
