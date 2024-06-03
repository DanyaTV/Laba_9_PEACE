// Property.h
#pragma once
#include "Apartment.h"

class Property : public Apartment {
public:
    Property();
    Property(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district, const std::string& propertyType, int yearBuilt);

    const std::string& getPropertyType() const { return propertyType; }
    void setPropertyType(const std::string& propertyType) { this->propertyType = propertyType; }

    int getYearBuilt() const { return yearBuilt; }
    void setYearBuilt(int yearBuilt) { this->yearBuilt = yearBuilt; }

    void input() override;
    void print() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    int calculatePelmeni() const;

    friend std::istream& operator>>(std::istream& is, Property& property);
    friend std::ostream& operator<<(std::ostream& os, const Property& property);
    friend std::ifstream& operator>>(std::ifstream& ifs, Property& property);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Property& property);

private:
    std::string propertyType;
    int yearBuilt;
};

