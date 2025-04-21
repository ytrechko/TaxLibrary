#pragma once
#include "Property.h"
#include "BasicValueTax.h"
#include <iostream>
#include "json.hpp"
#include "pugixml.hpp"

class Car : public Property
{
	double horsepower;
public:
	Car() :horsepower(0) {};
	Car(Car const& cr): Property(cr.worth), horsepower(cr.horsepower) {}
	Car(double worth, double horsepower) : Property(worth), horsepower(horsepower) {}

	void fromJson(nlohmann::json json);
	nlohmann::json toJson();

	void fromXml(pugi::xml_node& xml);
	void toXml(pugi::xml_node& XmlObj);

	inline std::string propertyName() const { return "Car"; }
	Property* cloneProperty() { return new Car(*this); }


	double CalculationPropertyTax() ;

	~Car() {};

};

