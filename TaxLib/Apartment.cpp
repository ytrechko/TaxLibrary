#include "pch.h"
#include "json.hpp"

using json = nlohmann::json;

void Apartment::fromJson(nlohmann::json json)
{
	json["worth"].get_to(worth);
	json["square"].get_to(square);
};

nlohmann::json Apartment::toJson()
{
	json JsonTaxObject;
	JsonTaxObject["proprty_tax"] = this->CalculationPropertyTax();
	JsonTaxObject["income_tax"] = this->CalculationIncomeTax();
	json PropJsonObject;
	PropJsonObject[this->propertyName()] = JsonTaxObject;
	json FileObject = JsonTaxObject;
	return FileObject;
};

double Apartment::CalculationPropertyTax()
{
	return (square <= TAX_RATES::LIMIT_Apartment_SQUARE) ?
		(worth * TAX_RATES::Apartment_TAX) :
		(worth * TAX_RATES::Apartment_LUXURY_TAX);
}
