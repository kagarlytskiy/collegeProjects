// TODO: // TODO: Описать структуру с именем SCHL, которая содержит поля: NAME - фамилия и имя ученика; GROUP - номер группы; SUBJ - успеваемость по пяти предметам (массив из пяти элементов). 
// Написать программу, отдельными функциями выполняет действия 
// - ввод с клавиатуры данных в массив LEARN, состоящий из N переменных типа SCHL; 
// - вывод на экран фамилий и номеров групп для всех студентов, имеющих хотя бы одну оценку "2"; если таковых нет, то вывести соответствующее сообщение.

#include <stdio.h>
 
struct schl {
        char name[20];
        int group;
        int subj[3];
};
 
void inputLearn(struct schl *student, int length, int amount);
void markCheck(struct schl *student, int length, int amount);
 
int main()
{
        struct schl student[3];
 
        for (int i = 0; i < 3; i++) {
                printf("введите имя студента: ");
                scanf("%s", student[i].name);
                printf("введите номер группы студента: ");
                scanf("%d", &student[i].group);
                printf("\n");
        }
 
        inputLearn(&student, 3, 3);
 
        markCheck(&student, 3, 3);
 
        return 0;
}
 
void inputLearn(struct schl *student, int length, int amount) {
        for (int i = 0; i < length; i++) {
                for (int o = 0; o < amount; o++) {
                        printf("оценки %sa за предмет %d: ", student[i].name, o+1);
                        scanf("%d", &student[i].subj[o]);
                }
                printf("\n");
        }
}
 
void markCheck(struct schl *student, int length, int amount) {
        int count = 0;
 
        for (int i = 0; i < length; i++) {
                for (int o = 0; o < amount; o++)
                        if (student[i].subj[o] == 2) {
                                printf("%s имеет двойку\n", student[i].name);
                                count++;
                        }
        }
 
        if (count == 0)
                printf("двоек нет\n");
}
