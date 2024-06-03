// Property.cpp
#include "Property.h"

Property::Property() : Apartment(), propertyType(""), yearBuilt(0) {}

Property::Property(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district, const std::string& propertyType, int yearBuilt)
    : Apartment(rooms, total, living, balconies, floor, storeys, district), propertyType(propertyType), yearBuilt(yearBuilt) {}

void Property::input() {
    Apartment::input();

    std::cout << "Тип недвижимости: ";
    std::cin.ignore();
    std::getline(std::cin, propertyType);

    std::cout << "Год постройки: ";
    while (!(std::cin >> yearBuilt) || yearBuilt < 0) {
        std::cout << "Ошибка. Введите положительное число для года постройки: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Property::print() const {
    Apartment::print();
    std::cout << "Тип недвижимости: " << propertyType << std::endl;
    std::cout << "Год постройки: " << yearBuilt << std::endl;
    std::cout << "====================\n" << std::endl;
}

void Property::saveToFile(std::ostream& os) const {
    Apartment::saveToFile(os);
    os << propertyType << " " << yearBuilt << std::endl;
}

void Property::loadFromFile(std::istream& is) {
    Apartment::loadFromFile(is);
    std::getline(is, propertyType);
    is >> yearBuilt;
    is.ignore(); // Consume newline character
}

std::istream& operator>>(std::istream& is, Property& property) {
    is >> static_cast<Apartment&>(property);

    std::cout << "Тип недвижимости: ";
    is.ignore();
    std::getline(is, property.propertyType);

    std::cout << "Год постройки: ";
    while (!(is >> property.yearBuilt) || property.yearBuilt < 0) {
        std::cout << "Ошибка. Введите положительное число для года постройки: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Property& property) {
    os << static_cast<const Apartment&>(property);
    os << "Тип недвижимости: " << property.propertyType << std::endl;
    os << "Год постройки: " << property.yearBuilt << std::endl;
    os << "====================\n";
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, Property& property) {
    ifs >> static_cast<Apartment&>(property);
    ifs.ignore(); // Считываем пробел
    std::getline(ifs, property.propertyType);
    ifs >> property.yearBuilt;
    ifs.ignore(); // Считываем пробел
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const Property& property) {
    ofs << static_cast<const Apartment&>(property);
    ofs << property.propertyType << " " << property.yearBuilt << "\n";
    return ofs;
}

int Property::calculatePelmeni() const {
    double wallHeight = 2.5;
    double floorArea = getTotal();
    double volume = floorArea * (wallHeight + 0.2) * 1.2;
    int pelmeniCount = static_cast<int>(volume / 0.0016); // Предполагаем, что каждый пельмень занимает 0.01 м³
    return pelmeniCount;
}
