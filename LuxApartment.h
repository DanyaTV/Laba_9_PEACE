// LuxApartment.h
#pragma once
#include "Apartment.h"

class LuxApartment : public Apartment {
public:
    LuxApartment();
    LuxApartment(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district, bool hasSauna, bool hasJacuzzi);

    bool getHasSauna() const { return hasSauna; }
    void setHasSauna(bool hasSauna) { this->hasSauna = hasSauna; }

    bool getHasJacuzzi() const { return hasJacuzzi; }
    void setHasJacuzzi(bool hasJacuzzi) { this->hasJacuzzi = hasJacuzzi; }

    void input() override;
    void print() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    int calculatePelmeni() const;

    friend std::istream& operator>>(std::istream& is, LuxApartment& apartment);
    friend std::ostream& operator<<(std::ostream& os, const LuxApartment& apartment);
    friend std::ifstream& operator>>(std::ifstream& ifs, LuxApartment& apartment);
    friend std::ofstream& operator<<(std::ofstream& ofs, const LuxApartment& apartment);

private:
    bool hasSauna;
    bool hasJacuzzi;
};