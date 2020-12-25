// TODO: ввести значения стороны квадрата А и радиуса
// 	 круга R и узнать чья площадь больше. Ответ
//	 вывести в виде сообщения.

#include <stdio.h>
#include <math.h>
 
int main()
{
        int unsigned square, circle;
        int squareArea, circleArea;
 
        printf("Введите сторону квадрата и радиус круга\n");
        scanf("%d %d", &square, &circle);
 
        squareArea = square * square;
        circleArea = (circle*circle) * M_PI;
 
        if (squareArea > circleArea)
                printf("Площадь квадрата больше чем площадь круга\n");
        else if (squareArea < circleArea)
                printf("Площадь квадрата меньше чем площадь круга\n");
        else
                printf("Площадь квадрата равна площади круга\n");
 
        return 0;
 
}
