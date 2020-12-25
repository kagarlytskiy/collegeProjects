// TODO: Напишите перегруженые функции:
// - для деления десятичных дробей;
// - для деления дробей.

#include <iostream>

using namespace std;

template <class T>
void fractDivision(T num1, T den1, // деление обычных дробей
                   T num2, T den2) // num это числитель
{                                  // den это знаменатель
        T numR = num1*den2;
        T denR = den1*num2;
        cout << numR << "/" << denR;
}

template <class S>
S fractDivision(S num1, S num2)
{
        if (!num2) {
                printf("на ноль делить нельзя\n");
                return 0;
        }
        return (num1/num2);
}

int main()
{
        double numA, denA, numB, denB;
        double a, b;

        printf("введите дробное число A (вид - x/y): ");
        scanf("%lf/%lf", &numA, &denA);
        printf("введите дробное число B (вид - x/y): ");
        scanf("%lf/%lf", &numB, &denB);
        printf("A / B = ");
        fractDivision(numA, denA, numB, denB);
        printf("\n");

        printf("введите десятичное число А: ");
        scanf("%lf", &a);
        printf("введите десятичное число B: ");
        scanf("%lf", &b);
        printf("A / B = %.1lf\n", fractDivision(a, b));

        return 0;
}
