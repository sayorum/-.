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

    cout << "Введите название автомобиля: ";
    cin >> name;

    cout << "Введите год выпуска: ";
    cin >> year;

    cout << "Введите объем двигателя: ";
    cin >> engine;

    cout << "Введите цену: ";
    cin >> price;

    Car car = { name, year, engine, price };
    cars.push_back(car);

    cout << "Автомобиль успешно добавлен." << endl;
}

void removeCar(vector<Car>& cars) {
    string name;
    cout << "Введите название автомобиля, который нужно удалить: ";
    cin >> name;

    auto it = remove_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.name == name;
        });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Автомобиль успешно удален." << endl;
    }
    else {
        cout << "Автомобиль не найден." << endl;
    }
}

void displayCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Список автомобилей пуст." << endl;
        return;
    }

    cout << "Список автомобилей:" << endl;
    for (const auto& car : cars) {
        cout << "Название: " << car.name << ", Год выпуска: " << car.year << ", Объем двигателя: " << car.engine << ", Цена: " << car.price << endl;
    }
}

void sortByPrice(vector<Car>& cars) {
    sort(cars.begin(), cars.end(), CompareByPrice());
    cout << "Список автомобилей отсортирован по цене." << endl;
}

void sortByName(vector<Car>& cars) {
    sort(cars.begin(), cars.end(), CompareByName());
    cout << "Список автомобилей отсортирован по названию." << endl;
}

void searchByName(const vector<Car>& cars) {
    string name;
    cout << "Введите название автомобиля для поиска: ";
    cin >> name;

    auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.name == name;
        });

    if (it != cars.end()) {
        cout << "Найден автомобиль." << endl;
    }
    else {
        cout << "Автомобиль не найден." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Car> cars;
    int choice;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить автомобиль" << endl;
        cout << "2. Удалить автомобиль" << endl;
        cout << "3. Отобразить список автомобилей" << endl;
        cout << "4. Отсортировать список автомобилей по цене" << endl;
        cout << "5. Отсортировать список автомобилей по названию" << endl;
        cout << "6. Найти автомобиль по названию" << endl;
        cout << "7. Выйти из программы" << endl;
        cout << "Ваш выбор: ";
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
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
}
