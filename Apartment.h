// Apartment.h
#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Apartment {
public:
    Apartment();
    Apartment(int rooms, double total, double living, int balconies, int floor, int storeys, const std::string& district);

    int getRooms() const { return rooms; }
    void setRooms(int rooms) { this->rooms = rooms; }

    double getTotal() const { return total; }
    void setTotal(double total) { this->total = total; }

    double getLiving() const { return living; }
    void setLiving(double living) { this->living = living; }

    int getBalconies() const { return balconies; }
    void setBalconies(int balconies) { this->balconies = balconies; }

    int getFloor() const { return floor; }
    void setFloor(int floor) { this->floor = floor; }

    int getStoreys() const { return storeys; }
    void setStoreys(int storeys) { this->storeys = storeys; }

    const std::string& getDistrict() const { return district; }
    void setDistrict(const std::string& district) { this->district = district; }

    virtual void input() ;
    virtual void print() const;
    virtual void saveToFile(std::ostream& os) const;
    virtual void loadFromFile(std::istream& is);
    
    int calculatePelmeni() const;

    friend std::istream& operator>>(std::istream& is, Apartment& apartment);
    friend std::ostream& operator<<(std::ostream& os, const Apartment& apartment);
    friend std::ifstream& operator>>(std::ifstream& ifs, Apartment& apartment);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Apartment& apartment);

private:
    int rooms;
    double total;
    double living;
    int balconies;
    int floor;
    int storeys;
    std::string district;
};
