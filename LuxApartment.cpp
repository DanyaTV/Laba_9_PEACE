// LuxApartment.cpp
#include "LuxApartment.h"

LuxApartment::LuxApartment() : Apartment(), hasSauna(false), hasJacuzzi(false) {}

LuxApartment::LuxApartment(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district, bool hasSauna, bool hasJacuzzi)
    : Apartment(rooms, total, living, balconies, floor, storeys, district), hasSauna(hasSauna), hasJacuzzi(hasJacuzzi) {}

void LuxApartment::input() {
    Apartment::input();

    std::cout << "Наличие сауны (0 - нет, 1 - да): ";
    while (!(std::cin >> hasSauna) || (hasSauna != 0 && hasSauna != 1)) {
        std::cout << "Ошибка. Введите 0 или 1: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Наличие джакузи (0 - нет, 1 - да): ";
    while (!(std::cin >> hasJacuzzi) || (hasJacuzzi != 0 && hasJacuzzi != 1)) {
        std::cout << "Ошибка. Введите 0 или 1: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void LuxApartment::print() const {
    Apartment::print();
    std::cout << "Наличие сауны: " << (hasSauna ? "Да" : "Нет") << std::endl;
    std::cout << "Наличие джакузи: " << (hasJacuzzi ? "Да" : "Нет") << std::endl;
    std::cout << "====================\n" << std::endl;
}

void LuxApartment::saveToFile(std::ostream& os) const {
    Apartment::saveToFile(os);
    os << hasSauna << " " << hasJacuzzi << std::endl;
}

void LuxApartment::loadFromFile(std::istream& is) {
    Apartment::loadFromFile(is);
    is >> hasSauna >> hasJacuzzi;
    is.ignore(); // Consume newline character
}

std::istream& operator>>(std::istream& is, LuxApartment& apartment) {
    is >> static_cast<Apartment&>(apartment);
    std::cout << "Наличие сауны (0 - нет, 1 - да): ";
    while (!(is >> apartment.hasSauna) || (apartment.hasSauna != 0 && apartment.hasSauna != 1)) {
        std::cout << "Ошибка. Введите 0 или 1: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Наличие джакузи (0 - нет, 1 - да): ";
    while (!(is >> apartment.hasJacuzzi) || (apartment.hasJacuzzi != 0 && apartment.hasJacuzzi != 1)) {
        std::cout << "Ошибка. Введите 0 или 1: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const LuxApartment& apartment) {
    os << static_cast<const Apartment&>(apartment);
    os << "Наличие сауны: " << (apartment.hasSauna ? "Да" : "Нет") << std::endl;
    os << "Наличие джакузи: " << (apartment.hasJacuzzi ? "Да" : "Нет") << std::endl;
    os << "====================\n";
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, LuxApartment& apartment) {
    ifs >> static_cast<Apartment&>(apartment);
    ifs >> apartment.hasSauna >> apartment.hasJacuzzi;
    ifs.ignore(); // Считываем пробел
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const LuxApartment& apartment) {
    ofs << static_cast<const Apartment&>(apartment);
    ofs << apartment.hasSauna << " " << apartment.hasJacuzzi << "\n";
    return ofs;
}

int LuxApartment::calculatePelmeni() const {
    double wallHeight = 3.0;
    double floorArea = getTotal();
    double volume = floorArea * (wallHeight + 0.2) * 1.2;
    int pelmeniCount = static_cast<int>(volume / 0.0016); // Предполагаем, что каждый пельмень занимает 0.01 м³
    return pelmeniCount;
}
