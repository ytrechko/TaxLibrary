#pragma once
#include "pch.h"
class PropertySimpleFactory
{
public:
	static Property* createProperty(std::string key) {
		if (key == "Car") {
			return new Car;
		}
		else if (key == "Apartment") {
			return new Apartment;
		}
		else if (key == "CountryHouse") {
			return new CountryHouse;
		}
		return nullptr;
	}
};

