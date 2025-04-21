#pragma once
#include "Property.h"
#include "BasicValueTax.h"
#include <iostream>
class CountryHouse : public Property
{
	unsigned int distanceFromCity;
public:
	CountryHouse() :distanceFromCity(0) {};
	CountryHouse(double worth, unsigned int distanceFromCity): Property(worth), distanceFromCity(distanceFromCity) {}
	CountryHouse(CountryHouse const& ch) : Property(ch.worth), distanceFromCity(ch.distanceFromCity) {}

	void fromJson(nlohmann::json json);
	nlohmann::json toJson();

	inline std::string propertyName() const { return "CountryHouse"; }
	inline Property* cloneProperty() { return new CountryHouse(*this); }

	double CalculationPropertyTax() ;

	~CountryHouse() {};

};

