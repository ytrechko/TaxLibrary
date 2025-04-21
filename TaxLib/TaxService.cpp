#include "pch.h"
#include "TaxService.h"

TaxService::TaxService(string filenameIn)
{
	regex rTypeJson(R"(^.+\.json$)");
	regex rTypeXml(R"(^.+\.xml$)");
	if (regex_match(filenameIn, rTypeJson)) {
		owners = FromJsonFileToVector(filenameIn);
	}
	else if (regex_match(filenameIn, rTypeXml)) {
		owners = FromXmlFileToVector(filenameIn);
	}
	else {
		throw runtime_error("Invalid name of file -> " + filenameIn + '\n');

	}
}

void TaxService::upploadTaxOwnersToFile(string filenameOut)
{
	regex rTypeJson(R"(^.+\.json$)");
	regex rTypeXml(R"(^.+\.xml$)");
	if (regex_match(filenameOut, rTypeJson)) {
		ToJsonFile(filenameOut, owners);
	}
	else if (regex_match(filenameOut, rTypeXml)) {
		ToXmlFile(filenameOut, owners);
	}
	else {
		throw runtime_error("Invalid name of file -> " + filenameOut + '\n');

	}
}
