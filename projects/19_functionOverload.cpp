// TODO: Напишите функцию mult с переменным числом параметров, которая находит произведение положительных чисел типа float.

#include <iostream>
 
float mult(float a, float b, float c)
{
        a = (a >= 0 ? a : 1);
        b = (b >= 0 ? b : 1);
        c = (c >= 0 ? c : 1);
 
        return (a*b*c);
}
 
float mult(float a, float b)
{
        a = (a >= 0 ? a : 1);
        b = (b >= 0 ? b : 1);
 
        return (a*b);
}
 
int main()
{
        float a, b, c;
 
        printf("введите числа А, В, C (отрицательные числа считаться не будут): ");
        scanf("%f %f %f", &a, &b, &c);
 
        printf("%.1f * %.1f = %.2f\n", a, b, mult(a, b));
        printf("%.1f * %.1f * %.1f = %.2f\n", a, b, c, mult(a, b, c));
 
        return 0;
}
