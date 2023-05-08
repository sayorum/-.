#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    float engine;
    int price;
};

struct CompareByPrice {
    bool operator()(const Car& a, const Car& b) const {
        return a.price < b.price;
    }
};

struct CompareByName {
    bool operator()(const Car& a, const Car& b) const {
        return a.name < b.name;
    }
};

void addCar(vector<Car>& cars) {
    setlocale(LC_ALL, "Russian");
    string name;
    int year, price;
    float engine;

    cout << "������� �������� ����������: ";
    cin >> name;

    cout << "������� ��� �������: ";
    cin >> year;

    cout << "������� ����� ���������: ";
    cin >> engine;

    cout << "������� ����: ";
    cin >> price;

    Car car = { name, year, engine, price };
    cars.push_back(car);

    cout << "���������� ������� ��������." << endl;
}

void removeCar(vector<Car>& cars) {
    string name;
    cout << "������� �������� ����������, ������� ����� �������: ";
    cin >> name;

    auto it = remove_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.name == name;
        });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "���������� ������� ������." << endl;
    }
    else {
        cout << "���������� �� ������." << endl;
    }
}

void displayCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "������ ����������� ����." << endl;
        return;
    }

    cout << "������ �����������:" << endl;
    for (const auto& car : cars) {
        cout << "��������: " << car.name << ", ��� �������: " << car.year << ", ����� ���������: " << car.engine << ", ����: " << car.price << endl;
    }
}

void sortByPrice(vector<Car>& cars) {
    sort(cars.begin(), cars.end(), CompareByPrice());
    cout << "������ ����������� ������������ �� ����." << endl;
}

void sortByName(vector<Car>& cars) {
    sort(cars.begin(), cars.end(), CompareByName());
    cout << "������ ����������� ������������ �� ��������." << endl;
}

void searchByName(const vector<Car>& cars) {
    string name;
    cout << "������� �������� ���������� ��� ������: ";
    cin >> name;

    auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.name == name;
        });

    if (it != cars.end()) {
        cout << "������ ����������." << endl;
    }
    else {
        cout << "���������� �� ������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Car> cars;
    int choice;
    while (true) {
        cout << "�������� ��������:" << endl;
        cout << "1. �������� ����������" << endl;
        cout << "2. ������� ����������" << endl;
        cout << "3. ���������� ������ �����������" << endl;
        cout << "4. ������������� ������ ����������� �� ����" << endl;
        cout << "5. ������������� ������ ����������� �� ��������" << endl;
        cout << "6. ����� ���������� �� ��������" << endl;
        cout << "7. ����� �� ���������" << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCar(cars);
            break;
        case 2:
            removeCar(cars);
            break;
        case 3:
            displayCars(cars);
            break;
        case 4:
            sortByPrice(cars);
            break;
        case 5:
            sortByName(cars);
            break;
        case 6:
            searchByName(cars);
            break;
        case 7:
            cout << "�� ��������!" << endl;
            return 0;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    }
}
