// TODO: Проверить (и исправить, если надо) чтобы каждое предложение в тексте начиналось с заглавной буквы и после каждой точки был хотя бы один пробел.

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
        char ch;
        FILE *source, *target;
        int isDot = 0;
        int count = 0;
        int newSentence;

        source = fopen("file1.txt", "r");

        target = fopen("file2.txt", "w");

        if (source == NULL || target == NULL)
                exit(EXIT_FAILURE);

        while ((ch = fgetc(source)) != EOF) {
                if (!count || newSentence) {
                        fputc(toupper(ch), target);
                        isDot = 0;
                        newSentence = 0;
                        count++;
                        continue;
                }

                if (isDot && ch == ' ') {
                        newSentence = 1;
                        isDot = 0;
                }

                if (isDot && ch != ' ' && ch != '\n') {
                        fputc(' ', target);
                        fputc(toupper(ch), target);
                        //newSentence = 1;
                        isDot = 0;
                        continue;
                }

                if (ch == '.') {
                        isDot = 1;
                }

                count++;
                fputc(ch, target);
        }

        fclose(source);
        fclose(target);

        return 0;
}
