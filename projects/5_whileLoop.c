// TODO: ввести натуральное число и поменять
// 	 местами первую и последнюю цифру числа,
//	 например, из числа 1234 получить 4321

#include <stdio.h>

int main()
{
		int long n, helper, reversedN;
		reversedN = 0;

		printf("Введите число\n");
		scanf("%ld", &n);

		while (n != 0) {
			helper = n % 10;
			reversedN = reversedN * 10 + helper;
			n /= 10;
		}

		printf("%ld\n", reversedN);

		return 0;
}
