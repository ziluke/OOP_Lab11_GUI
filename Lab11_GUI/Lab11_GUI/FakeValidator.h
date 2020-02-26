#pragma once
#include "Validator.h"
#include "Exception.h"

class FakeValidator: public Validator
{
public:
	FakeValidator();
	void validateTower(std::string auraLevel, std::string quantityOfParts) { return; }
	~FakeValidator();
};

