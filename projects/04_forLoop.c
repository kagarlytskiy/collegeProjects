// TODO: функция у=arcsin(x)
//	 функция z=cos(1/(x+pi/3))
//	 промежуток x є [-1, 1], шаг=0,05

#include <stdio.h>
#include <math.h>
 
int main()
{
        float x, limit, h;
        float y, z;
 
        x = -1.0;
        limit = 1.0;
        h = 0.05;
 
        for (x; x <= limit; x += h) {
                y = asin(x);
                z = cos(1/(x + (M_PI/3)));
 
                printf("y = %f\nz = %f\n", y, z);
        }
 
        return 0;
}

