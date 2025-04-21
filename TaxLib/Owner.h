#pragma once
#include <vector>
#include <exception>
#include <iomanip>

#include "Apartment.h"
#include "Car.h"
#include "Property.h"
#include "CountryHouse.h"
class Owner 
{
	std::string fullname;
	std::string inn;
	std::vector<Property*> properties;
public:
	Owner() {};
	Owner(std::string fullname, std::string inn) :fullname(fullname), inn(inn) {};

	Owner(Owner const& own);
	Owner& operator=(Owner const& own);

	void addProperty(Property* prop);
	void removeProperty(int indexProperty);
	double totalSumTax() const;

	~Owner();

	friend std::ostream& operator<<(std::ostream& out, Owner& owner);
};





