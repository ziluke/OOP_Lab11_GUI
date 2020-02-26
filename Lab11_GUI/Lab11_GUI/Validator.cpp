#include "Validator.h"
#include "Exception.h"


Validator::Validator()
{
}

void Validator::validateTower(std::string auraLevel, std::string quantityOfParts)
{
	char* auraPointer;
	char* quantityPointer;
	strtol(auraLevel.c_str(), &auraPointer, 10);
	strtol(quantityOfParts.c_str(), &quantityPointer, 10);
	if (*auraPointer != 0)
	{
		throw Exception("Invalid Aura Level!\n");
	}
	else if (*quantityPointer != 0)
	{
		throw Exception("Invalid Quantity of parts!\n");
	}
}


Validator::~Validator()
{
}
