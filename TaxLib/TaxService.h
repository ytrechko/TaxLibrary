#pragma once
#include "pch.h"
#include <vector>
#include <regex>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;

class TaxService
{
	vector<Owner> owners;
public:
	TaxService(string filenameIn);
	void upploadTaxOwnersToFile(string filenameOut);
	TaxService() {}
};

