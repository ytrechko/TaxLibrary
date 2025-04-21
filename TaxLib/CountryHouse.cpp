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

void CountryHouse::fromXml(pugi::xml_node& xml)
{
	if (!xml.attribute("worth").as_double()) { throw std::runtime_error("Ошибка чтения worth"); }
	worth = xml.attribute("worth").as_double();
	if (!xml.attribute("distanceFromCity").as_double()) { throw std::runtime_error("Ошибка чтения distanceFromCity"); }
	distanceFromCity = xml.attribute("distanceFromCity").as_double();
}

void CountryHouse::toXml(pugi::xml_node& xmlObj)
{
	pugi::xml_node XmlNode = xmlObj.append_child("CountryHouse");
	XmlNode.append_attribute("property_tax") = this->CalculationPropertyTax();
	XmlNode.append_child("income_tax").text().set(this->CalculationIncomeTax());
}

double CountryHouse::CalculationPropertyTax()
{
	return (distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY) ?
		worth * TAX_RATES::Apartment_TAX :
		worth * TAX_RATES::COUNTRY_HOUSE_TAX;
}
