// TODO: среди правых элементах каждой строки найти кол-во элемента который отличается от наименьшого элемента на 10%

#include <stdio.h>
 
int main()
{
        int matrix[3][2] = {
                {8, 6},
                {4, 5},
                {2, 9}
        };
        int i;
        int min = matrix[0][0];
        int count = 0;
 
        for (i = 0; i < 3; i++)
                if (matrix[i][0] < min)
                        min = matrix[i][0];
 
        for (i = 0; i < 3; i++)
                if ((matrix[i][0]-min*0.1) <= min)
                        count++;
 
        printf("%d\n", count);
 
        return 0;
}
