#include "pch.h"

double Car::CalculationPropertyTax() 
{
	if (horsepower < TAX_RATES::LOW_HORSEPOWER) {
		return worth * TAX_RATES::CAR_TAX;
	}
	else
	{
		if (horsepower > TAX_RATES::HIGH_HORSEPOWER) {
			return worth * TAX_RATES::CAR_LUXURY_TAX;
		}
		return worth * TAX_RATES::CAR_TRUCK_TAX;
	}
}
