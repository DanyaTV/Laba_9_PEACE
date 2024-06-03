// Apartment.cpp
#include "Apartment.h"

Apartment::Apartment() : rooms(0), total(0.0), living(0.0), balconies(0), floor(0), storeys(0), district("") {}

Apartment::Apartment(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district)
    : rooms(rooms), total(total), living(living), balconies(balconies), floor(floor), storeys(storeys), district(district) {}

void Apartment::input() {
    std::cout << "====================\nКол-во комнат: ";
    while (!(std::cin >> rooms) || rooms < 0) {
        std::cout << "Ошибка. Введите положительное число для количества комнат: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Площадь квартиры: ";
    while (!(std::cin >> total) || total < 0) {
        std::cout << "Ошибка. Введите верное значение для площади квартиры: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Жилая площадь: ";
    while (!(std::cin >> living) || living < 0 || living > total) {
        std::cout << "Ошибка. Введите верное значение для жилой площади квартиры: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Количество балконов: ";
    while (!(std::cin >> balconies) || balconies < 0 || balconies > rooms) {
        std::cout << "Ошибка. Введите положительное число для количества балконов: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Этажность здания: ";
    while (!(std::cin >> storeys) || storeys < 0) {
        std::cout << "Ошибка. Введите положительное число для этажности здания: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Этаж: ";
    while (!(std::cin >> floor) || floor < 0 || floor > storeys) {
        std::cout << "Ошибка. Введите положительное число для этажа: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Район: ";
    std::cin.ignore();
    std::getline(std::cin, district);

    std::cout << "====================\n\n";
}

void Apartment::print() const {
    std::cout << "Кол-во комнат: " << rooms << std::endl;
    std::cout << "Площадь квартиры: " << total << std::endl;
    std::cout << "Жилая площадь: " << living << std::endl;
    std::cout << "Кол-во балконов: " << balconies << std::endl;
    std::cout << "Этаж: " << floor << std::endl;
    std::cout << "Этажность дома: " << storeys << std::endl;
    std::cout << "Район: " << district << std::endl;
    std::cout << "====================\n" << std::endl;
}

void Apartment::saveToFile(std::ostream& os) const {
    os << rooms << " "
        << total << " "
        << living << " "
        << balconies << " "
        << floor << " "
        << storeys << " "
        << district << std::endl;
}

void Apartment::loadFromFile(std::istream& is) {
    is >> rooms
        >> total
        >> living
        >> balconies
        >> floor
        >> storeys;
    is.ignore(); // Consume newline character
    std::getline(is, district);
}

std::istream& operator>>(std::istream& is, Apartment& apartment) {
    std::cout << "====================\nКол-во комнат: ";
    while (!(is >> apartment.rooms) || apartment.rooms < 0) {
        std::cout << "Ошибка. Введите положительное число для количества комнат: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Площадь квартиры: ";
    while (!(is >> apartment.total) || apartment.total < 0) {
        std::cout << "Ошибка. Введите верное значение для площади квартиры: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Жилая площадь: ";
    while (!(is >> apartment.living) || apartment.living < 0 || apartment.living > apartment.total) {
        std::cout << "Ошибка. Введите верное значение для жилой площади квартиры: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Количество балконов: ";
    while (!(is >> apartment.balconies) || apartment.balconies < 0 || apartment.balconies > apartment.rooms) {
        std::cout << "Ошибка. Введите положительное число для количества балконов: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Этажность здания: ";
    while (!(is >> apartment.storeys) || apartment.storeys < 0) {
        std::cout << "Ошибка. Введите положительное число для этажности здания: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Этаж: ";
    while (!(is >> apartment.floor) || apartment.floor < 0 || apartment.floor > apartment.storeys) {
        std::cout << "Ошибка. Введите положительное число для этажа: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Район: ";
    is.ignore();
    std::getline(is, apartment.district);

    std::cout << "====================\n\n";

    return is;
}

std::ostream& operator<<(std::ostream& os, const Apartment& apartment) {
    os << "Кол-во комнат: " << apartment.getRooms() << "\n"
        << "Площадь квартиры: " << apartment.getTotal() << "\n"
        << "Жилая площадь: " << apartment.getLiving() << "\n"
        << "Количество балконов: " << apartment.getBalconies() << "\n"
        << "Этаж: " << apartment.getFloor() << "\n"
        << "Этажность здания: " << apartment.getStoreys() << "\n"
        << "Район: " << apartment.getDistrict() << "\n====================\n";
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Apartment& apartment) {
    ofs << apartment.rooms << " " << apartment.total << " " << apartment.living << " " << apartment.balconies << " " << apartment.floor << " " << apartment.storeys << " " << apartment.district << "\n";
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Apartment& apartment) {
    ifs >> apartment.rooms >> apartment.total >> apartment.living >> apartment.balconies >> apartment.floor >> apartment.storeys;
    ifs.ignore(); // Считываем пробел
    std::getline(ifs, apartment.district);
    return ifs;
}

int Apartment::calculatePelmeni() const {
    double wallHeight = 2.5;
    double floorArea = getTotal();
    double volume = floorArea * (wallHeight+0.2)*1.2;
    int pelmeniCount = static_cast<int>(volume / 0.0016); // Предполагаем, что каждый пельмень занимает 0.01 м³
    return pelmeniCount;
}