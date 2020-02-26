#pragma once
#include <string>

class Validator
{
public:
	Validator();
	void validateTower(std::string auraLevel, std::string quantityOfParts);
	~Validator();
};

