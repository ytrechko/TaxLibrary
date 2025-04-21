#pragma once
#include "Property.h"
#include "BasicValueTax.h"
#include <iostream>
#include "json.hpp"

class Apartment : public Property
{
	double square;
public:
	Apartment() :square(0) {};
	Apartment(Apartment const& ap) :Property(ap.worth), square(ap.square) {}
	Apartment(double worth, double square): Property(worth), square(square) {}

	void fromJson(nlohmann::json json);
	nlohmann::json toJson();

	inline Property* cloneProperty() { return new Apartment(*this); }
	inline std::string propertyName() const { return "Apartment"; }

	double CalculationPropertyTax() ;

	~Apartment() {};

};

