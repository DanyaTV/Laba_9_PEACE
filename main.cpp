// main.cpp
#include <iostream>
#include <locale>
#include <string>
#include "ApartmentCollection.h"

// Цвета текста
#define RESET   "\033[0m"       // Сброс цвета
#define RED     "\033[31m"      // Красный
#define GREEN   "\033[32m"      // Зеленый
#define YELLOW  "\033[33m"      // Желтый
#define BLUE    "\033[34m"      // Синий
#define SECR "RU"



int main() {
    setlocale(LC_ALL, "Rus");

    ApartmentCollection collection;
    ApartmentCollection luxCollection;
    ApartmentCollection propertyCollection;

    int choice;
    std::cout << "   Выберите действие:\n";
    std::cout << "   1 - Добавить квартиру\n";
    std::cout << "   2 - Загрузить данные\n";
    std::cout << "   3 - Ввод данных с клавиатуры\n";
    std::cout << "   4 - Удалить квартиру по индексу\n";
    std::cout << "   5 - Подсчитать количество пельменей в квартире\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;



    while (choice != 0) {
        if (choice == 1010)
        {
            system("cls");
            std::cout << RESET << "=====================" << std::endl;
            std::cout << BLUE << "=====================" << RESET << std::endl;
            std::cout << RED << "=====================" << RESET << std::endl;
        }
        else if (choice == 2020)
        {
            system("cls");
            std::cout << YELLOW << "=====================" << RESET << std::endl;
            std::cout << BLUE << "=====================" << RESET << std::endl;

            std::cout << "       / \\__" << std::endl;
            std::cout << "      (    @\\___" << std::endl;
            std::cout << "      /         O" << std::endl;
            std::cout << "     /   (_____/" << std::endl;
            std::cout << "    /_____/   U" << std::endl;



        }
        else if (choice == 1) {
            system("cls");
            int numApart;
            std::cout << "Какую квартиру добавить : \n";
            std::cout << "1 - Обычная квартира\n";
            std::cout << "2 - Роскошная квартира\n";
            std::cout << "3 - ЕЩЕ НЕ ПРИДУМАЛ\n";
            std::cout << "Для выхода из цикла введите любое значение ;)\n";
            std::cout << "Ваш выбор: ";
            std::cin >> numApart;

            if (numApart == 1) {
                std::shared_ptr<Apartment> apartment = std::make_shared<Apartment>();
                std::cin >> *apartment;
                collection += apartment;
                std::cout << "Обычная квартира добавлена.\n";
                collection.saveToFile("apartments.txt");
                std::cout << "\nСодержимое контейнера 'Apartments':\n====================\n";
                std::cout << collection;
            }

            else if (numApart == 2) {
                std::shared_ptr<LuxApartment> luxApartment = std::make_shared<LuxApartment>();
                std::cin >> *luxApartment;
                luxCollection += luxApartment;
                std::cout << "Роскошная квартира добавлена.\n";
                luxCollection.saveLuxApartmentsToFile("lux_apartments.txt");
                std::cout << "\nСодержимое контейнера 'LuxApartments':\n====================\n";
                std::cout << luxCollection;
            }

            else if (numApart == 3) {
                std::shared_ptr<Property> property = std::make_shared<Property>();
                std::cin >> *property;
                propertyCollection += property;
                std::cout << "(ЕЩЕ НЕ ПРИДУМАЛ).\n";
                propertyCollection.savePropertiesToFile("properties.txt");
                std::cout << "\nСодержимое контейнера 'Properties':\n====================\n";
                std::cout << propertyCollection;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода, попробуйте снова" << std::endl;
                system("cls");
            }
        }
        else if (choice == 2) {
            system("cls");
            int numFileOpen;
            std::cout << "Для какой квартиры загрузить файл: \n";
            std::cout << "1 - Обычная квартира\n";
            std::cout << "2 - Роскошная квартира\n";
            std::cout << "3 - (ЕЩЕ НЕ ПРИДУМАЛ)\n";
            std::cout << "Для выхода из цикла введите любое значение ;)\n";
            std::cout << "Ваш выбор: ";
            std::cin >> numFileOpen;
            if (numFileOpen == 1)
            {
                collection.loadFromFile("apartments.txt");
                std::cout << "\nСодержимое контейнера 'Apartments':\n====================\n";
                std::cout << collection;
            }
            else if (numFileOpen == 2)
            {
                luxCollection.loadLuxApartmentsFromFile("lux_apartments.txt");
                std::cout << "\nСодержимое контейнера 'LuxApartments':\n====================\n";
                std::cout << luxCollection;
            }
            else if (numFileOpen == 3)
            {
                propertyCollection.loadPropertiesFromFile("properties.txt");
                std::cout << "\nСодержимое контейнера 'Properties':\n====================\n";
                std::cout << propertyCollection;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода, попробуйте снова" << std::endl;
                system("cls");
            }
        }
        else if (choice == 3) {
            system("cls");
            int numApartAdd;
            std::cout << "Какие объекты добавляем: \n";
            std::cout << "1 - Обычные квартиры\n";
            std::cout << "2 - Роскошные квартиры\n";
            std::cout << "3 - (ЕЩЕ НЕ ПРИДУМАЛ)\n";
            std::cout << "Для выхода из цикла введите любое значение ;)\n";
            std::cout << "Ваш выбор: ";
            std::cin >> numApartAdd;

            if (numApartAdd == 1)
            {
                int numApartments;
                std::cout << "Введите количество обычных квартир: ";
                std::cin >> numApartments;

                for (int i = 0; i < numApartments; i++) {
                    std::shared_ptr<Apartment> apartment = std::make_shared<Apartment>();
                    std::cin >> *apartment;
                    collection += apartment;
                }

                collection.saveToFile("apartments.txt");

                std::cout << "Данные обычных квартир сохранены в файле 'apartments.txt'.\n";
            }
            else if (numApartAdd == 2)
            {
                int numLuxApartments;
                std::cout << "Введите количество роскошных квартир: ";
                std::cin >> numLuxApartments;

                for (int i = 0; i < numLuxApartments; i++) {
                    std::shared_ptr<LuxApartment> luxApartment = std::make_shared<LuxApartment>();
                    std::cin >> *luxApartment;
                    luxCollection += luxApartment;
                }

                luxCollection.saveLuxApartmentsToFile("lux_apartments.txt");

                std::cout << "Данные роскошных квартир сохранены в файле 'lux_apartments.txt'.\n";
            }
            else if (numApartAdd == 3)
            {
                int numProperties;
                std::cout << "Введите количество объектов недвижимости: ";
                std::cin >> numProperties;

                for (int i = 0; i < numProperties; i++) {
                    std::shared_ptr<Property> property = std::make_shared<Property>();
                    std::cin >> *property;
                    propertyCollection += property;
                }

                propertyCollection.savePropertiesToFile("properties.txt");

                std::cout << "Данные (ЕЩЕ НЕ ПРИДУМАЛ) сохранены в файле 'properties.txt'.\n";
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода, попробуйте снова" << std::endl;
                system("cls");
            }

        }
        else if (choice == 4) {
            system("cls");
            int numDelApart;
            std::cout << "Какую квартиру удаляем: \n";
            std::cout << "1 - Обычная квартира\n";
            std::cout << "2 - Роскошная квартира\n";
            std::cout << "3 - (ЕЩЕ НЕ ПРИДУМАЛ)\n";
            std::cout << "Для выхода из цикла введите любое значение ;)\n";
            std::cout << "Ваш выбор: ";
            std::cin >> numDelApart;

            if (numDelApart == 1)
            {
                int index;
                std::cout << "Введите индекс обычной квартиры для удаления: ";
                std::cin >> index;
                collection.removeApartment(index);
                std::cout << "Обычная квартира удалена.\n";
                collection.saveToFile("apartments.txt");
                std::cout << "\nСодержимое контейнера 'Apartments':\n====================\n";
                std::cout << collection;
            }
            else if (numDelApart == 2)
            {
                int index;
                std::cout << "Введите индекс роскошной квартиры для удаления: ";
                std::cin >> index;
                luxCollection.removeLuxApartment(index);
                std::cout << "Роскошная квартира удалена.\n";
                luxCollection.saveLuxApartmentsToFile("lux_apartments.txt");
                std::cout << "\nСодержимое контейнера 'LuxApartments':\n====================\n";
                std::cout << luxCollection;
            }
            else if (numDelApart == 3)
            {
                int index;
                std::cout << "Введите индекс (ЕЩЕ НЕ ПРИДУМАЛ) для удаления: ";
                std::cin >> index;
                propertyCollection.removeProperty(index);
                std::cout << "Недвижимость удалена.\n";
                propertyCollection.savePropertiesToFile("properties.txt");
                std::cout << "\nСодержимое контейнера 'Properties':\n====================\n";
                std::cout << propertyCollection;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода, попробуйте снова" << std::endl;
                system("cls");
            }

        }
        else if (choice == 5) {
            system("cls");
            int numApart;
            std::cout << "Выберите где посчитать количество пельменей:\n";
            std::cout << "1 - Обычная квартира\n";
            std::cout << "2 - Роскошная квартира\n";
            std::cout << "3 - (ЕЩЕ НЕ ПРИДУМАЛ)\n";
            std::cout << "Для выхода из цикла введите любое значение ;)\n";
            std::cout << "Ваш выбор: ";
            std::cin >> numApart;

            if (numApart == 1)
            {
                collection.loadFromFile("apartments.txt");
                std::cout << "\nСодержимое контейнера 'Apartment':\n====================\n";
                std::cout << collection;
                int index;
                std::cout << "Введите индекс обычной квартиры: ";
                std::cin >> index;
                if (index >= 0 && index < collection.apartments.size()) {
                    int pelmeniCount = collection.apartments[index]->calculatePelmeni();
                    std::cout << "В Обычной квартире с индексом: " << index << " может находиться: " << pelmeniCount << " ПЕЛЬМЕНЕЙ\n===========\n" << std::endl;
                }
                else {
                    std::cerr << "Ошибка: недопустимый индекс квартиры.\n";
                }
            }
            else if (numApart == 2)
            {
                luxCollection.loadLuxApartmentsFromFile("lux_apartments.txt");
                std::cout << "\nСодержимое контейнера 'LuxApartment':\n====================\n";
                std::cout << luxCollection;
                int index;
                std::cout << "Введите индекс роскошной квартиры: ";
                std::cin >> index;
                if (index >= 0 && index < luxCollection.luxApartments.size()) {
                    int pelmeniCount = luxCollection.luxApartments[index]->calculatePelmeni();
                    std::cout << "\n===========\nВ Роскошной квартире с индексом: " << index << " может находиться: " YELLOW << pelmeniCount << RESET << GREEN" ПЕЛЬМЕНЕЙ" << RESET"\n===========\n" << std::endl;
                }
                else {
                    std::cerr << "Ошибка: недопустимый индекс роскошной квартиры.\n";
                }
            }
            else if (numApart == 3)
            {
                propertyCollection.loadPropertiesFromFile("properties.txt");
                std::cout << "\nСодержимое контейнера 'Properties':\n====================\n";
                std::cout << propertyCollection;
                int index;
                std::cout << "Введите  индекс (ЕЩЕ НЕ ПРИДУМАЛ): ";
                std::cin >> index;
                if (index >= 0 && index < propertyCollection.properties.size()) {
                    int pelmeniCount = propertyCollection.properties[index]->calculatePelmeni();
                    std::cout << "В (ЕЩЕ НЕ ПРИДУМАЛ) с индексом: " << index << " может находиться: " << YELLOW << pelmeniCount<< RESET << GREEN" ПЕЛЬМЕНЕЙ"<< RESET"\n===========\n" << std::endl;
                }
                else {
                    std::cerr << "Ошибка: недопустимый индекс для (ЕЩЕ НЕ ПРИДУМАЛ).\n";
                }
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("cls");
            }
        }
        else {
            system("cls");
            std::cerr << "Неверный выбор. Выберите снова.\n";
        }

        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить квартиру\n";
        std::cout << "2 - Загрузить данные\n";
        std::cout << "3 - Ввод данных с клавиатуры\n";
        std::cout << "4 - Удалить квартиру по индексу\n";
        std::cout << "5 - Подсчитать количество пельменей в квартире\n";
        std::cout << "0 - Продолжить ход программы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
    }


    std::string searchDistrict;
    std::cout << "Введите район для поиска обычных квартир на последнем этаже: ";
    std::cin >> searchDistrict;
    std::cout << "\n";

    collection.searchLastFloorApartmentsInDistrict(searchDistrict);

    std::cout << "Введите район для поиска роскошных квартир на последнем этаже: ";
    std::cin >> searchDistrict;
    std::cout << "\n";

    luxCollection.searchLastFloorLuxApartmentsInDistrict(searchDistrict);

    std::cout << "Введите район для поиска недвижимости на последнем этаже: ";
    std::cin >> searchDistrict;
    std::cout << "\n";

    propertyCollection.searchLastFloorPropertiesInDistrict(searchDistrict);

    return 0;
}