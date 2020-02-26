#include "Norven_Tower.h"
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

Norven_Tower::Norven_Tower():location{},size{},vision{},auraLevel{0},quantityOfParts{0}
{
}

Norven_Tower & Norven_Tower::operator=(const Norven_Tower & tower)
{
	if (this == &tower)
	{
		return *this;
	}
	this->auraLevel = tower.auraLevel;
	this->quantityOfParts = tower.quantityOfParts;
	this->location = tower.location;
	this->size = tower.size;
	this->vision = tower.vision;

	return *this;
}

Norven_Tower::Norven_Tower(std::string & location, std::string & size, int auraLevel, int quantityOfParts, std::string & vision)
{
	this->location = location;
	this->size = size;
	this->vision = vision;
	this->auraLevel = auraLevel;
	this->quantityOfParts = quantityOfParts;
}

std::string Norven_Tower::toString() const
{
	std::string towerString = "Location: " + this->location + ", Size: " + this->size + ", Aura Level: " + std::to_string(this->auraLevel) + ", Quantity of parts: " + std::to_string(this->quantityOfParts) + ", Vision: " + this->vision;
	return towerString;
}

Norven_Tower::~Norven_Tower()
{
}

vector<string> tokenize(string stream, char delimiter)
{
	vector<string> result;
	stringstream stringStream(stream);
	string token;
	while (getline(stringStream, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}

std::istream & operator>>(std::istream & inputStream, Norven_Tower & tower)
{
	string line;
	getline(inputStream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return inputStream;
	if (!stoi(tokens[3]) && !stoi(tokens[2]))
		return inputStream;
	tower.location = tokens[0];
	tower.size = tokens[1];
	tower.auraLevel = stoi(tokens[2]);
	tower.quantityOfParts = stoi(tokens[3]);
	tower.vision = tokens[4];
	
	return inputStream;
}

std::ostream & operator<<(std::ostream & outputStream, const Norven_Tower & tower)
{
	outputStream << tower.location + "," + tower.size + "," + std::to_string(tower.auraLevel) + "," + std::to_string(tower.quantityOfParts) + "," + tower.vision<<endl;
	return outputStream;
}
