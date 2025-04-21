#include "pch.h"

double Apartment::CalculationPropertyTax() 
{
	return (square <= TAX_RATES::LIMIT_Apartment_SQUARE) ?
		(worth * TAX_RATES::Apartment_TAX) :
		(worth * TAX_RATES::Apartment_LUXURY_TAX);
}
