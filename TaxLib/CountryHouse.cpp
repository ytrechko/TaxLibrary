#include "pch.h"

double CountryHouse::CalculationPropertyTax() 
{
	return (distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY) ?
		worth * TAX_RATES::Apartment_TAX :
		worth * TAX_RATES::COUNTRY_HOUSE_TAX;
}
