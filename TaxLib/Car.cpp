#include "pch.h"
#include "json.hpp"

using json = nlohmann::json;
inline void Car::fromJson(nlohmann::json json)
{
	json["worth"].get_to(worth);
	json["horsepower"].get_to(horsepower);
}
inline nlohmann::json Car::toJson()
{
	json JsonTaxObject;
	JsonTaxObject["proprty_tax"] = this->CalculationPropertyTax();
	JsonTaxObject["income_tax"] = this->CalculationIncomeTax();
	json PropJsonObject;
	PropJsonObject[this->propertyName()] = JsonTaxObject;
	json FileObject = JsonTaxObject;
	return FileObject;
};

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
