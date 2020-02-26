#include "File_Encyclopedia.h"
#include <algorithm>
#include <assert.h>
#include <fstream>
#include "Exception.h"

using namespace std;

File_Encyclopedia::File_Encyclopedia(std::string path): path{path}
{
	ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::trunc);
	file.close();
}

bool File_Encyclopedia::addTower(Norven_Tower newTower)
{
	vector<Norven_Tower> towers = this->getAllTowers();
	if (any_of(towers.begin(), towers.end(), [newTower](Norven_Tower tower) {return(tower.getLocation() == newTower.getLocation()); }) == true)
		throw Exception("A tower already exists at location "+newTower.getLocation()+"!\n");
	ofstream file;
	file.open(this->path, ios::app);
	file << newTower;
	file.close();
	return true;
}

bool File_Encyclopedia::removeTower(std::string & location)
{
	vector<Norven_Tower> towers = this->getAllTowers();
	auto removeIterator = std::find_if(towers.begin(), towers.end(), [location](Norven_Tower tower) { return (tower.getLocation() == location); });

	if (removeIterator == towers.end())
		throw Exception("Tower does not exist at location "+location+"!\n");
	towers.erase(removeIterator);
	writeToFile(towers);
	return true;
}

bool File_Encyclopedia::updateTower(Norven_Tower newTower)
{
	vector<Norven_Tower> towers = getAllTowers();
	auto updateIterator = find_if(towers.begin(), towers.end(), [newTower](Norven_Tower tower) { return (tower.getLocation() == newTower.getLocation()); });

	if (updateIterator == towers.end())
		throw Exception("Tower does not exist!\n");
	towers.erase(updateIterator);
	towers.push_back(newTower);
	writeToFile(towers);
	return true;
}

void File_Encyclopedia::setPath(std::string path)
{
	this->path = path;
}

int File_Encyclopedia::getSize() const
{
	return getAllTowers().size();
}

void File_Encyclopedia::writeToFile(vector<Norven_Tower> towers)
{
	ofstream file(this->path, ios::out);
	for (auto tower : towers)
	{
		file << tower;
	}
	file.close();
}

std::vector<Norven_Tower> File_Encyclopedia::getAllTowers() const
{
	vector<Norven_Tower> towers;
	ifstream file(this->path);
	Norven_Tower tower{};
	while (file >> tower)
	{
		towers.push_back(tower);
	}
	return towers;
}

File_Encyclopedia::~File_Encyclopedia()
{
}

void testFileEncyclopedia()
{
	File_Encyclopedia enc{};
	std::string args[] = { "here", "there", "big", "small", "far", "near" , "11", "12" };
	std::string anywhere = "anywhere";
	std::string path = "C:\\Users\\Lukas\\Desktop\\Test_File.txt";
	Norven_Tower newTower1 = Norven_Tower(args[0], args[2], stoi(args[6]), stoi(args[7]), args[4]);
	Norven_Tower newTower2 = Norven_Tower(args[1], args[3], 123, 333, args[5]);
	Norven_Tower newTower3 = Norven_Tower(args[1], args[2], 11, 144, args[4]);
	Norven_Tower newTower4 = Norven_Tower(anywhere, args[2], 11, 144, args[4]);
	assert(enc.addTower(newTower1) == true);
	assert(enc.addTower(newTower2) == true);
	try
	{
		enc.addTower(newTower1);
	}
	catch (Exception exception)
	{
		assert(true);
	}
	assert(enc.removeTower(args[0]) == true);
	assert(enc.updateTower(newTower3) == true);
	try
	{
		enc.updateTower(newTower4);
	}
	catch (Exception exception)
	{
		assert(true);
	}
	try
	{
		enc.removeTower(args[0]);
	}
	catch (Exception exception)
	{
		assert(true);
	}
	assert(enc.getSize() == 1);
	std::vector<Norven_Tower> towers = enc.getAllTowers();
	enc.setPath(path);
	assert(towers.size() == 1);
}
