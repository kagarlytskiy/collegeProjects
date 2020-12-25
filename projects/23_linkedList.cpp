// TODO: Создать очередь, элементами которого являются данные, которые создавались и обрабатывались в лабораторной работе №20.
// Реализовать различные функции: добавление новых элементов в очередь; удаление элемента с заданным номером очереди; вывод на экран информации, хранящейся в заданном элементе; вывод на экран всей информации по очереди.

#include <iostream>
 
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
 
struct Node {
        Car obj;
        struct Node* next;
};
 
Car* input(Car* obj, int size, Node** head);
void output(Car* obj, int size);
void output(Car obj, int step);
 
void remove(struct Node** head, int index);
void push(struct Node** head, Car node_obj);
 
int main()
{
        struct Node* head = NULL;
       Car* mainCar = nullptr;
       int size = 0;
       int another = 1;
        int command;
 
       while (another != 0) {
               mainCar = input(mainCar, size, &head);
               size++;
               cout << "\nдобавить автомобиль? [0/1]: ";
               cin >> another;
               cin.get();
       }
 
       output(mainCar, size);
 
        another = 1;
 
        while (another != 0) {
                cout << "\n";
                cout << "1) добавить элемент в линейный список" << "\n"
             	    << "2) удалить элемент с индексом" << "\n"
             	    << "3) вывести элемент с индексом" << "\n"
             	    << "4) вывести все элементы линейного списка" << "\n"
             	    << "5) выход" << "\n\n";
                cout << "команда: ";
                cin >> command;
                cin.get();
 
                switch (command) {
                        case (1): {
                                mainCar = input(mainCar, size, &head);
                                size++;
                                break;
                        }
                        case (2): {
                                int choice;
                                int first = 0;
                                printf("введите индекс: ");
                                scanf("%d", &choice);
 
                                remove(&head, choice);
 
                                break;
                        }
                        case (3): {
                                Node* headCopy = head;
                                int choice;
                                printf("введите индекс: ");
                                scanf("%d", &choice);
 
                                int first = 1;
 
                                for (int i = size-1; i >= 0; i--) {
                                        if (i == choice-1) {
                                                output(headCopy->obj, first);
                                                first = 0;
                                                break;
                                        }
                                        headCopy = headCopy->next;
                                }       
 
                                break;
                        }
                        case (4): {
                                Node* headCopy = head;
                                int first = 1;
                                Car arr[size];
 
                                while (headCopy != NULL) {
                                        output(headCopy->obj, first);
 
                                        headCopy = headCopy->next;
                                        first = 0;
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
 
Car* input(Car* obj, int size, struct Node** head)
{
        Car* newCar = new Car[size+1];
 
        for (int i = 0; i < size; i++) {
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
 
        push(head, obj[size]);
 
       return obj;
}
 
void output(Car* strk, int size)
{
       printf("\n№\tимя\tцвет\tномер\tрегестрация\tгод\tинспекция\tцена\t");
       printf("\n============================================================================\n");
 
       for (int i = size-1; i >= 0; i--)
               printf("%d\t%s\t%s\t%d\t%d\t\t%d\t%d\t\t%d\n", i+1, strk[i].name.c_str(),
                strk[i].color.c_str(), strk[i].serialNumber, strk[i].regestrationNumber,
                strk[i].yearMade, strk[i].yearInspection, strk[i].price);
}
 
void output(Car strk, int step)
{
        if (step) {
                printf("имя\tцвет\tномер\tрегестрация\tгод\tинспекция\tцена\t");
                printf("\n====================================================================\n");
        }
 
        printf("%s\t%s\t%d\t%d\t\t%d\t%d\t\t%d\n",
                strk.name.c_str(), strk.color.c_str(),
                strk.serialNumber, strk.regestrationNumber,
                strk.yearMade, strk.yearInspection, strk.price);
}
 
void push(struct Node** head, Car node_obj)
{
        Node* newNode = new Node;
        newNode->obj = node_obj;
        newNode->next = (*head);
        (*head) = newNode;
}
 
void remove(Node** head, int index)
{
        Node* temp = *head;
        Node* prev;
        
        if (index == 1) {
                *head = temp->next;
                free(temp);
                return;
        }
 
        for (int i = 1; i != index; i++) {
                prev = temp;
                temp = temp->next;
        }
 
        prev->next = temp->next;
        free(temp);
}
