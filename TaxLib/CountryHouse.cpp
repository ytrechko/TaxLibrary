#include "pch.h"

using json = nlohmann::json;

void CountryHouse::fromJson(nlohmann::json json)
{
	json["worth"].get_to(worth);
	json["distanceFromCity"].get_to(distanceFromCity);
}

nlohmann::json CountryHouse::toJson()
{
	json JsonTaxObject;
	JsonTaxObject["proprty_tax"] = this->CalculationPropertyTax();
	JsonTaxObject["income_tax"] = this->CalculationIncomeTax();
	json PropJsonObject;
	PropJsonObject[this->propertyName()] = JsonTaxObject;
	json FileObject = JsonTaxObject;
	return FileObject;
}

double CountryHouse::CalculationPropertyTax()
{
	return (distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY) ?
		worth * TAX_RATES::Apartment_TAX :
		worth * TAX_RATES::COUNTRY_HOUSE_TAX;
}
