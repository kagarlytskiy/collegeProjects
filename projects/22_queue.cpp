// TODO: Создать очередь, элементами которого являются данные, которые создавались и обрабатывались в лабораторной работе №20.
// Реализовать различные функции: добавление новых элементов в очередь; удаление элемента с заданным номером очереди; вывод на экран информации, хранящейся в заданном элементе; вывод на экран всей информации по очереди.

#include <iostream>
#include <queue>
 
using namespace std;
 
struct Car {
       string name;
       string color;
       int serialNumber;
       int regestrationNumber;
       int yearMade;
       int yearInspection;
       int price;
};
 
Car* input(Car* obj, int size);
void output(Car* obj, int size);
void output(Car obj, int first);
 
queue <Car> queueCar;
void toQueue(Car* obj, int size);
void remove(int index, int size);
 
int main()
{
       Car* mainCar = nullptr;
       int size = 0;
       int another = 1;
        int command;
 
       while (another != 0) {
               mainCar = input(mainCar, size);
               size++;
               cout << "\nдобавить автомобиль? [0/1]: ";
               cin >> another;
               cin.get();
       }
 
        toQueue(mainCar, size);
       output(mainCar, size);
 
        another = 1;
 
        while (another != 0) {
                cout << "\n";
                cout << "1) добавить элемент в очередь" << "\n"
             	    << "2) удалить элемент с индексом" << "\n"
             	    << "3) вывести элемент с индексом" << "\n"
             	    << "4) вывести все элементы очереди" << "\n"
             	    << "5) выход" << "\n\n";
                cout << "команда: ";
                cin >> command;
                cin.get();
 
                switch (command) {
                        case (1): {
                                mainCar = input(mainCar, size);
                                size++;
                                toQueue(mainCar, size);
                                break;
                        }
                        case (2): {
                                int size = queueCar.size();
                                int choice;
                                printf("введите индекс: ");
                                scanf("%d", &choice);
 
                                remove(choice, size);
 
                                break;
                        }
                        case (3): {
                                int choice;
                                printf("введите индекс: ");
                                scanf("%d", &choice);
 
                                queue <Car> queueCarCopy0;
                                queueCarCopy0 = queueCar;
                                int first = 0;
                                int size = queueCar.size();
 
                                for (int i = size-1; i >= 0; i--) {
                                        if (i == choice-1) {
                                                output(queueCarCopy0.front(), first);
                                                break;
                                        }
                                        queueCarCopy0.pop();
                                        first = 1;
                                }
 
                                break;
                        }
                        case (4): {
                                queue <Car> queueCarCopy1;
                                queueCarCopy1 = queueCar;
                                int first = 0;
 
                                for (int i = 0; i < queueCar.size(); i++) {
                                        output(queueCarCopy1.front(), first);
                                        queueCarCopy1.pop();
                                        first = 1;
                                }
                                break;
                        }
                        case (5): {
                                another = 0;
                                break;
                        }
                        default: {
                                cout << "несуществующая команда\n";
                        }
                }
        }
        
       delete[] mainCar;
       return 0;
}
 
Car* input(Car* obj, int size)
{
        Car* newCar = new Car[size+1];
 
        for (int i = 0; size > 0 && i < size; i++) {
                newCar[i] = obj[i];
        }
 
        cout << "имя: " ;
        getline(cin, newCar[size].name);
        cout << "цвет: ";
        getline(cin, newCar[size].color);
        cout << "серийный номер: ";
        cin >> newCar[size].serialNumber;
        cout << "регестрационный номер: ";
        cin >> newCar[size].regestrationNumber;
        cout << "год выпуска: ";
        cin >> newCar[size].yearMade;
        cout << "год инспекции: ";
        cin >> newCar[size].yearInspection;
        cout << "цена: ";
        cin >> newCar[size].price;
        cin.get();
 
        delete[] obj;
 
        obj = newCar;
 
       return obj;
}
 
void toQueue(Car* obj, int size) {
        while (!queueCar.empty())
                queueCar.pop();
        for (int i = size-1; i >= 0; i--)
                queueCar.push(obj[i]);
}
 
void output(Car* obj, int size)
{
       printf("\n№\tимя\tцвет\tномер\tрегестрация\tгод\tинспекция\tцена\t");
       printf("\n============================================================================\n");
 
       for (int i = size-1; i >= 0; i--)
               printf("%d\t%s\t%s\t%d\t%d\t\t%d\t%d\t\t%d\n", i+1, obj[i].name.c_str(),
                obj[i].color.c_str(), obj[i].serialNumber, obj[i].regestrationNumber,
                obj[i].yearMade, obj[i].yearInspection, obj[i].price);
}
 
void output(Car obj, int first)
{
        if (first == 0) {
                printf("имя\tцвет\tномер\tрегестрация\tгод\tинспекция\tцена\t");
                printf("\n====================================================================\n");
        }
 
        printf("%s\t%s\t%d\t%d\t\t%d\t%d\t\t%d\n",
                obj.name.c_str(), obj.color.c_str(),
                obj.serialNumber, obj.regestrationNumber,
                obj.yearMade, obj.yearInspection, obj.price);
                
}
 
void remove(int index, int size)
{
        Car holder[size];
        int i;
 
        for (i = size-1; i >= 0; i--) {
                holder[i] = queueCar.front();
                queueCar.pop();
        }
 
        for (i = 0; i < size; i++) {
                if (i == index-1)
                        continue;
                queueCar.push(holder[i]);
        }
}
