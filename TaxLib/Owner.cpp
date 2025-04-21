#include "pch.h"

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
