// TODO: Дан массив 100 целых чисел. Проверить, упорядоченный данный массив по росту (убыванию, неупорядоченный) и вывести соответствующее сообщение на экран и в файл.

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
        int array[100];
        int i;
        char str0[] = "масив идет не по порядку\n";
        char str1[] = "масив идет по порядку\n";
        size_t str0_size = sizeof *str0;
        size_t str1_size = sizeof *str1;
        size_t str0_to_write = sizeof str0;
        size_t str1_to_write = sizeof str1;
 
        FILE * fp;
        fp = fopen("result.bin", "wb");
 
        for (i = 1; i <= 100; i++)
                array[i] = rand() % 10;
 
        for (i = 1; i <= 100; i++)
                if (array[i] < array[i-1]) {
                        printf("%s\n", str0);
                        fwrite(str0, str0_size, str0_to_write, fp);
                        return 0;
                }
 
        printf("%s\n", str1);
        fwrite(str1, str1_size, str1_to_write, fp);
        fclose(fp);
 
        return 0;
}
