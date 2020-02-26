#pragma once
#include <iostream>
#include <string>

class Norven_Tower
{
private:
	std::string location;
	std::string size;
	int auraLevel, quantityOfParts;
	std::string vision;
public:
	Norven_Tower();
	Norven_Tower& operator=(const Norven_Tower& tower);
	Norven_Tower(std::string &location, std::string &size, int auraLevel, int quantityOfParts, std::string &vision);
	std::string getLocation() const { return this->location; }
	std::string getSize() const { return this->size; }
	std::string getVision() const { return this->vision; }
	int getAuraLevel() const { return this->auraLevel; }
	int getQuantityOfParts() const { return this->quantityOfParts; }

	void setLocation(const std::string &location) { this->location = location; }
	void setSize(const std::string &size) { this->size = size; }
	void setVision(const std::string &vision) { this->vision = vision; }
	void setAuraLevel(const int auraLevel) { this->auraLevel = auraLevel; }
	void setQuantityOfParts(const int quantityOfParts) { this->quantityOfParts = quantityOfParts; }

	friend std::istream& operator>>(std::istream& inputStream, Norven_Tower& tower);
	friend std::ostream& operator<<(std::ostream& outputStream, const Norven_Tower& tower);
	std::string toString() const;
	~Norven_Tower();
};

