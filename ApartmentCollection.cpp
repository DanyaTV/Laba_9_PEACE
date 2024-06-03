// ApartmentCollection.cpp
#include "ApartmentCollection.h"
#include <algorithm>

void ApartmentCollection::operator+=(const std::shared_ptr<Apartment>& apartment) {
    apartments.push_back(apartment);
}

void ApartmentCollection::operator+=(const std::shared_ptr<LuxApartment>& apartment) {
    luxApartments.push_back(apartment);
}

void ApartmentCollection::operator+=(const std::shared_ptr<Property>& property) {
    properties.push_back(property);
}

void ApartmentCollection::removeApartment(int index) {
    if (index >= 0 && index < apartments.size()) {
        apartments.erase(apartments.begin() + index);
    }
}

void ApartmentCollection::removeLuxApartment(int index) {
    if (index >= 0 && index < luxApartments.size()) {
        luxApartments.erase(luxApartments.begin() + index);
    }
}

void ApartmentCollection::removeProperty(int index) {
    if (index >= 0 && index < properties.size()) {
        properties.erase(properties.begin() + index);
    }
}

void ApartmentCollection::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& apartment : apartments) {
        file << *apartment;
    }
    file.close();
}

void ApartmentCollection::saveLuxApartmentsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& apartment : luxApartments) {
        file << *apartment;
    }
    file.close();
}

void ApartmentCollection::savePropertiesToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& property : properties) {
        file << *property;
    }
    file.close();
}

void ApartmentCollection::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла " << filename << "\n";
        return;
    }

    apartments.clear();

    while (!file.eof()) {
        auto apartment = std::make_shared<Apartment>();
        file >> *apartment;
        if (!file.eof()) {
            apartments.push_back(apartment);
        }
    }

    file.close();
}

void ApartmentCollection::loadLuxApartmentsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла " << filename << "\n";
        return;
    }

    luxApartments.clear();

    while (!file.eof()) {
        auto apartment = std::make_shared<LuxApartment>();
        file >> *apartment;
        if (!file.eof()) {
            luxApartments.push_back(apartment);
        }
    }

    file.close();
}

/*void ApartmentCollection::loadPropertiesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла " << filename << "\n";
        return;
    }

    properties.clear();

    while (!file.eof()) {
        auto property = std::make_shared<Property>();
        file >> *property;
        if (!file.eof()) {
            properties.push_back(property);
        }
    }

    file.close();
}*/

void ApartmentCollection::loadPropertiesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.fail()) {
        std::cerr << "Ошибка при открытии файла " << filename << "\n";
        return;
    }

    properties.clear();

    while (!file.eof() && !file.fail()) {
        auto property = std::make_shared<Property>();
        file >> *property;
        if (file.fail()) {
            break;
        }
        properties.push_back(property);
    }
}

void ApartmentCollection::searchLastFloorApartmentsInDistrict(const std::string& district) const {
    bool foundApartments = false;
    std::cout << "====================\nКвартиры на последнем этаже в районе " << district << ":\n";
    for (const auto& apartment : apartments) {
        if (apartment->getDistrict() == district && apartment->getFloor() == apartment->getStoreys()) {
            apartment->print();
            foundApartments = true;
        }
    }

    if (!foundApartments) {
        std::cout << "Квартиры на последнем этаже в заданном районе не найдены.\n";
    }

    double totalArea = 0.0;
    for (const auto& apartment : apartments) {
        if (apartment->getDistrict() == district) {
            totalArea += apartment->getTotal();
        }
    }
    std::cout << "Общая площадь квартир в районе " << district << ": " << totalArea << std::endl;
}

void ApartmentCollection::searchLastFloorLuxApartmentsInDistrict(const std::string& district) const {
    bool foundApartments = false;
    std::cout << "====================\nЛюкс-квартиры на последнем этаже в районе " << district << ":\n";
    for (const auto& apartment : luxApartments) {
        if (apartment->getDistrict() == district && apartment->getFloor() == apartment->getStoreys()) {
            apartment->print();
            foundApartments = true;
        }
    }

    if (!foundApartments) {
        std::cout << "Люкс-квартиры на последнем этаже в заданном районе не найдены.\n";
    }

    double totalArea = 0.0;
    for (const auto& apartment : luxApartments) {
        if (apartment->getDistrict() == district) {
            totalArea += apartment->getTotal();
        }
    }
    std::cout << "Общая площадь люкс-квартир в районе " << district << ": " << totalArea << std::endl;
}

void ApartmentCollection::searchLastFloorPropertiesInDistrict(const std::string& district) const {
    bool foundProperties = false;
    std::cout << "====================\nНедвижимость на последнем этаже в районе " << district << ":\n";
    for (const auto& property : properties) {
        if (property->getDistrict() == district && property->getFloor() == property->getStoreys()) {
            property->print();
            foundProperties = true;
        }
    }

    if (!foundProperties) {
        std::cout << "Недвижимость на последнем этаже в заданном районе не найдена.\n";
    }

    double totalArea = 0.0;
    for (const auto& property : properties) {
        if (property->getDistrict() == district) {
            totalArea += property->getTotal();
        }
    }
    std::cout << "Общая площадь недвижимости в районе " << district << ": " << totalArea << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ApartmentCollection& collection) {
    if (!collection.apartments.empty())
    {
        os << "Список квартир:\n\n";
        for (size_t i = 0; i < collection.apartments.size(); i++) {
            os << "=========Индекс: " << i << "=========" << std::endl;
            os << *collection.apartments[i];
        }
    }
    else if (!collection.luxApartments.empty()) {
        os << "Список люкс-квартир:\n\n";
        for (size_t i = 0; i < collection.luxApartments.size(); i++) {
            os << "=========Индекс: " << i << "=========" << std::endl;
            os << *collection.luxApartments[i];
        }
    }
    else if (!collection.properties.empty()) {
        os << "Список недвижимости:\n\n";
        for (size_t i = 0; i < collection.properties.size(); i++) {
            os << "=========Индекс: " << i << "=========" << std::endl;
            os << *collection.properties[i];
        }
    }
    return os;
}
