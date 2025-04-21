#include "pch.h"

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
}
void Apartment::fromXml(pugi::xml_node& xml)
{
	if (!xml.attribute("worth").as_double()) { throw std::runtime_error("Ошибка чтения worth"); }
	worth = xml.attribute("worth").as_double();
	if (!xml.attribute("square").as_double()) { throw std::runtime_error("Ошибка чтения square"); }
	square = xml.attribute("square").as_double();
}

void Apartment::toXml(pugi::xml_node& XmlObj)
{
	pugi::xml_node XmlNode = XmlObj.append_child("Apartment");
	XmlNode.append_attribute("property_tax") = this->CalculationPropertyTax();
	XmlNode.append_child("income_tax").text().set(this->CalculationIncomeTax());
}

double Apartment::CalculationPropertyTax()
{
	return (square <= TAX_RATES::LIMIT_Apartment_SQUARE) ?
		(worth * TAX_RATES::Apartment_TAX) :
		(worth * TAX_RATES::Apartment_LUXURY_TAX);
}
