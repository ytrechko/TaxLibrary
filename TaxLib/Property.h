#pragma once
#include <string>
#include "BasicValueTax.h"
#include "Ijsonio.h"
#include <iostream>
class Property : public Ijsonio
{
protected:
	double worth;
public:
	inline Property() :worth(0) {};
	inline Property(double worth) :worth(worth) {};
	virtual std::string propertyName() const = 0;

	double getWorth() const { return worth; }

	virtual Property* cloneProperty() = 0;

	virtual double CalculationPropertyTax()  = 0;
	inline double CalculationIncomeTax()  { return (TAX_RATES::INCOME_TAX * worth); };

	virtual ~Property() {};

};

