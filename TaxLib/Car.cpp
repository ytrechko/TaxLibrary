#include "pch.h"

using json = nlohmann::json;

void Car::fromJson(nlohmann::json json)
{
	json["worth"].get_to(worth);
	json["horsepower"].get_to(horsepower);
}
nlohmann::json Car::toJson()
{
	json JsonTaxObject;
	JsonTaxObject["proprty_tax"] = this->CalculationPropertyTax();
	JsonTaxObject["income_tax"] = this->CalculationIncomeTax();
	json PropJsonObject;
	PropJsonObject[this->propertyName()] = JsonTaxObject;
	json FileObject = JsonTaxObject;
	return FileObject;
}
void Car::fromXml(pugi::xml_node& xml)
{
	if (!xml.attribute("worth").as_double()) { throw std::runtime_error("Ошибка чтения worth"); }
	worth = xml.attribute("worth").as_double();
	if (!xml.attribute("horsepower").as_double()) { throw std::runtime_error("Ошибка чтения horsepower"); }
	horsepower = xml.attribute("horsepower").as_double();
}

void Car::toXml(pugi::xml_node& XmlObj)
{
	pugi::xml_node XmlNode = XmlObj.append_child("Car");
	XmlNode.append_attribute("property_tax") = this->CalculationPropertyTax();
	XmlNode.append_child("income_tax").text().set(this->CalculationIncomeTax());
}

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
