// ApartmentCollection.h
#pragma once
#include <vector>
#include <memory>
#include "Apartment.h"
#include "LuxApartment.h"
#include "Property.h"

class ApartmentCollection {
public:
    void operator+=(const std::shared_ptr<Apartment>& apartment);
    void operator+=(const std::shared_ptr<LuxApartment>& apartment);
    void operator+=(const std::shared_ptr<Property>& property);

    void removeApartment(int index);
    void removeLuxApartment(int index);
    void removeProperty(int index);

    void saveToFile(const std::string& filename) const;
    void saveLuxApartmentsToFile(const std::string& filename) const;
    void savePropertiesToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);
    void loadLuxApartmentsFromFile(const std::string& filename);
    void loadPropertiesFromFile(const std::string& filename);

    void searchLastFloorApartmentsInDistrict(const std::string& district) const;
    void searchLastFloorLuxApartmentsInDistrict(const std::string& district) const;
    void searchLastFloorPropertiesInDistrict(const std::string& district) const;

    friend std::ostream& operator<<(std::ostream& os, const ApartmentCollection& collection);


    std::vector<std::shared_ptr<Apartment>> apartments;
    std::vector<std::shared_ptr<LuxApartment>> luxApartments;
    std::vector<std::shared_ptr<Property>> properties;
};

