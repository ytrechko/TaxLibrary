#pragma once
#include <vector>
#include <exception>
#include <iomanip>

#include "Apartment.h"
#include "Car.h"
#include "Property.h"
#include "CountryHouse.h"
#include "Ijsonio.h"
#include "Ixmlio.h"


class Owner : public Ijsonio, public Ixmlio
{
	std::string fullname;
	std::string inn;
	std::vector<Property*> properties;
public:
	Owner() {};
	Owner(std::string fullname, std::string inn) :fullname(fullname), inn(inn) {};

	Owner(Owner const& own);
	Owner& operator=(Owner const& own);

	nlohmann::json toJson();
	void fromJson(nlohmann::json jOwner);

	void fromXml(pugi::xml_node& ovner);
	void toXml(pugi::xml_node& xmlOwner);

	void addProperty(Property* prop);
	void removeProperty(int indexProperty);
	double totalSumTax() const;

	~Owner();

	friend std::ostream& operator<<(std::ostream& out, Owner& owner);
};

std::vector<Owner> FromJsonFileToVector(std::string const& filename);
void ToJsonFile(std::string const& filename, std::vector<Owner>& owners);

std::vector<Owner> FromXmlFileToVector(std::string const& filename);
void ToXmlFile(std::string const& filename, std::vector<Owner>& owners);
