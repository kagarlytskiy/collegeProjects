// TODO: cтрока символов состоит из десятичных цифр, разделенных пробелами. подсчитать и вывести на экран количество парных и количество нечетных цифр.

#include <stdio.h>
 
int main()
{
        char string[17] = "1 2 3 4 5 6 7 8 9";
        int length = sizeof(string)/sizeof(string[0]);
        int odd = 0, even = 0;
 
        for (int i = 0; i < length; i++) {
                if (string[i] != ' ') {
                        if (string[i] % 2 == 0)
                                even++;
                        else
                                odd++;
                }
        }
 
        printf("кол-во нечетных чисел: %d\nкол-во четных чисел: %d\n", odd, even);
 
        return 0;
}

