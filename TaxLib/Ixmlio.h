#pragma once
#include "pugixml.hpp"
class Ixmlio
{
public:

	Ixmlio() {};
	virtual void fromXml(pugi::xml_node&) = 0;
	virtual void toXml(pugi::xml_node& parent) = 0;
	virtual ~Ixmlio() {}
};

