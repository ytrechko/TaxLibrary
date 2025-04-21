#pragma once
#include "Property.h"
#include "BasicValueTax.h"
#include <iostream>
class Car : public Property
{
	double horsepower;
public:
	Car() :horsepower(0) {};
	Car(Car const& cr): Property(cr.worth), horsepower(cr.horsepower) {}
	Car(double worth, double horsepower) : Property(worth), horsepower(horsepower) {}
	inline std::string propertyName() const { return "Car"; }

	Property* cloneProperty() { return new Car(*this); }


	double CalculationPropertyTax() ;

	~Car() {};

};

