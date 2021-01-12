// TODO: G = (|y+x|-(x+y))/((x+a)*x^5)

#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, a;
	double g;

	printf("Введите значение x, y, a\n");
	scanf("%d %d %d", &x, &y, &a);

	g = ((pow(cos(abs(y+x)), 3)) - (x + y)) / (pow(atan(x+a), 4) * pow(x, 5));
	printf("G = %lf\n", g);

	return 0;
}
