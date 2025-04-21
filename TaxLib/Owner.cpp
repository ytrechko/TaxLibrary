#include "pch.h"
#include "json.hpp"
#include "PropertySimpleFactory.h"

using json = nlohmann::json;

Owner::Owner(Owner const& own)
{
	fullname = own.fullname;
	inn = own.inn;
	for (Property* prop : own.properties) {
		properties.push_back(prop->cloneProperty());
	}
}

Owner& Owner::operator=(Owner const& own)
{
	if (this == &own) {
		return *this;
	}

	fullname = own.fullname;
	inn = own.inn;
	for (Property* prop : properties) {
		delete prop;
	}
	properties.clear();
	for (Property* prop : own.properties) {
		properties.push_back(prop->cloneProperty());
	}
	return *this;
}

nlohmann::json Owner::toJson()
{
	json ArrayProperties = json::array();
	for (Property* prop : properties) {
		json FileObject = prop->toJson();
		ArrayProperties.push_back(FileObject);
	}
	json OwnerCell{
		{"fullname",fullname},
		{"inn",inn},
		{"sumtax",this->totalSumTax()},
		{"properties",ArrayProperties}
	};
	return OwnerCell;
}
void Owner::fromJson(nlohmann::json jOwner)
{
	jOwner.at("fullname").get_to(fullname);
	jOwner.at("inn").get_to(inn);

	json jsonVectorProp = jOwner["properties"];
	for (json const& it : jsonVectorProp) {
		if (it.contains("Car")) {
			json car = it["Car"];
			Property* prop = PropertySimpleFactory::createProperty("Car");
			prop->fromJson(car);
			properties.push_back(prop);
		}
		else if (it.contains("Apartment")) {
			json apartment = it["Apartment"];
			Property* prop = PropertySimpleFactory::createProperty("Apartment");
			prop->fromJson(apartment);
			properties.push_back(prop);
		}
		else if (it.contains("CountryHouse")) {
			json countryhouse = it["CountryHouse"];
			Property* prop = PropertySimpleFactory::createProperty("CountryHouse");
			prop->fromJson(countryhouse);
			properties.push_back(prop);
		}
	}
}

void Owner::addProperty(Property* prop)
{
	properties.push_back(prop->cloneProperty());
}
void Owner::removeProperty(int indexProperty)
{
	if (indexProperty < 0 || indexProperty >= properties.size()) {
		throw std::out_of_range("Invalid index for remove object\n");
	}
	delete properties[indexProperty];
	properties.erase(properties.begin() + indexProperty);
}

double Owner::totalSumTax() const
{
	double sum = 0;
	for (Property* prop : properties) {
		sum += prop->CalculationPropertyTax();
		sum += prop->CalculationIncomeTax();
	}
	return sum;
}

Owner::~Owner()
{
	for (Property* prop : properties) {
		delete prop;
	}
}

std::ostream& operator<<(std::ostream& out, Owner& owner)
{
	out << std::fixed << std::setprecision(2) << "Fullname: " << owner.fullname << "\t Inn: " << owner.inn << '\n';
	if (owner.properties.size() == 0) { out << "NO Property\n"; }
	for (Property* prop : owner.properties) {
		out << "Name property: " << prop->propertyName() << ' ' << prop->getWorth() << '\n';
	}
	return out;
}
