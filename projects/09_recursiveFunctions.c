// TODO: oписать рекурсивную функцию Digits (S) целого типа, находящую количество цифр в строке S без использования оператора цикла.

#include <stdio.h>
 
int main()
{
        char s[100];
 
        printf("Введите строку с цифрой:\n");
        scanf("%s", &s);
 
        printf("Количество цифр в строке: %d\n", digits(s, 0, 0));
 
        return 0;
}
 
int digits(char s[], int n, int count)
{
        if (s[n] == '\0')
                return count;
        if (s[n] >= '0' && s[n] <= '9')
                count++;
 
        return digits(s, n+1, count);
}

