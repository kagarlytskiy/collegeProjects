// TODO: Задача А: Создать файл, содержащий информацию о сотрудниках университета. Структура записи: фамилия работающего, название отдела, год рождения, стаж работы, должность, оклад. Количество записей произвольная.
// Задача В: Написать программу, которая выдает позволяет получить следующую информацию:
// - список работников пенсионного возраста на сегодняшний день с указанием стажа работы;
// - средний стаж работающих в отделе Х.

#include <stdio.h>
#include <string.h>

#define LENGTH 40
#define CURRENT_YEAR 2020

typedef struct {
        char lastName[LENGTH];
        char depName[LENGTH];
        int yearBorn;
        int yearExp;
        char posName[LENGTH];
        int salary;
} uniWorker;

void inputInfo(uniWorker *worker, int n);
void outputInfo(uniWorker *worker, int n);

int averageAge(uniWorker *worker, char dep[], int n);
void countRetiree(uniWorker *worker, int n);

int main()
{
        int numberOfWorkers;
        int i;
        char reqDep[LENGTH];

        printf("введите название отделения: ");
        scanf("%s", reqDep);

        printf("введите кол-во работников: ");
        scanf("%d", &numberOfWorkers);

        printf("\n");

        uniWorker worker[numberOfWorkers];

        inputInfo(worker, numberOfWorkers);

        printf("средний возраст в %s - %d\n\n", reqDep, averageAge(worker, reqDep, numberOfWorkers));

        countRetiree(worker, numberOfWorkers);

        printf("\n");

        return 0;
}

void inputInfo(uniWorker *worker, int n)
{
        FILE *fp;
        fp = fopen("info.log", "w");

        for (int i = 0; i < n; i++) {
                printf("фамилия: ");
                scanf("%s", worker[i].lastName);
                                fprintf(fp, "%s\n", worker[i].lastName);
                printf("название отделения: ");
                scanf("%s", worker[i].depName);
                                fprintf(fp, "\tназвание отделения: %s\n", worker[i].depName);
                printf("год рождения: ");
                scanf("%d", &worker[i].yearBorn);
                                fprintf(fp, "\tгод рождения: %d\n", worker[i].yearBorn);
                printf("стаж работы: ");
                scanf("%d", &worker[i].yearExp);
                                fprintf(fp, "\tстаж работы: %d\n", worker[i].yearExp);
                printf("позиция: ");
                scanf("%s", worker[i].posName);
                                fprintf(fp, "\tпозиция: %s\n", worker[i].posName);
                printf("зарплата: ");
                scanf("%d", &worker[i].salary);
                                fprintf(fp, "\tзарплата: %d\n", worker[i].salary);
                printf("\n");
        }
}

void countRetiree(uniWorker *worker, int n)
{
        char correction[10];
        int count = 0;
        int age;

        for (int i = 0; i < n; i++)
                if (CURRENT_YEAR - (age = worker[i].yearBorn) >= 65) {
                        if (age > 4)
                                strcpy(correction, "лет");
                        else if (age == 1)
                                strcpy(correction, "год");
                        else
                                strcpy(correction, "год");
                        printf("%s - пенсионер. его стаж - %d %s\n", worker[i].lastName, worker[i].yearExp, correction);

                        count++;
                }
        printf("\n");

        printf("кол-во пенсионеров: %d\n", count);
}

int averageAge(uniWorker *worker, char dep[], int n)
{
        int result = 0;

        for (int i = 0; i < n; i++)
                if (!strcmp(worker[i].depName, dep))
                        result += CURRENT_YEAR - worker[i].yearBorn;

        return (result / n);
}
