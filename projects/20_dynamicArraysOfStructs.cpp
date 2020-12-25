// TODO: "Автомобиль":
// марка; цвет; серийный номер; регистрационный номер; год выпуска; год техосмотра; цена. Вывести данные об автомобилях, которым более 2 лет.

#include <iostream>
#define YEAR 2020
 
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
 
Car* input(Car* obj, int amount);
void output(Car* obj, int amount);
 
int main()
{
        Car* mainCar = nullptr;
        int amount = 0;
        int enough = 1;
	int request = 1;
 
        while (enough != 0) {
                mainCar = input(mainCar, amount);
                amount++;
                cout << "\nдобавить автомобиль? [0/1]: ";
                cin >> enough;
                cin.get();
        }
 
        output(mainCar, amount);
        delete[] mainCar;
        return 0;
}
 
Car* input(Car* obj, int amount) {
        if (amount == 0) {
                obj = new Car[amount+1];
        } else {
                Car* newCar = new Car[amount+1];
 
		for (int i = 0; i < amount; i++) {
			newCar[i] = obj[i];
		}
 
                for (int i = amount; i < amount+1; i++) {
                        cout << "имя: " ;
                        getline(cin, newCar[i].name);
                        cout << "цвет: ";
                        getline(cin, newCar[i].color);
                        cout << "серийный номер: ";
                        cin >> newCar[i].serialNumber;
			cout << "регестрационный номер: ";
			cin >> newCar[i].regestrationNumber;
			cout << "год выпуска: ";
			cin >> newCar[i].yearMade;
			cout << "год инспекции: ";
			cin >> newCar[i].yearInspection;
			cout << "цена: ";
			cin >> newCar[i].price;
			cin.get();
                }
 
                delete[] obj;
 
                obj = newCar;
        }
 
        return obj;
}
 
void output(Car* obj, int amount)
{
	int proceed = 0;
	printf("\n№\tимя\tцвет\tномер\tрегестрация\tгод\tинспекция\tцена\t"); 
	printf("\n============================================================================\n");
 
        for (int i = 1; i < amount; i++) 
		if ((YEAR-obj[i].yearMade) > 2)
			printf("%d\t%s\t%s\t%d\t%d\t\t%d\t%d\t\t%d\n", i, obj[i].name.c_str(), obj[i].color.c_str(), 
									  obj[i].serialNumber, obj[i].regestrationNumber,
									  obj[i].yearMade, obj[i].yearInspection, 
									  obj[i].price);
}

