#include "Controler.h"
#include <iostream>
#include <assert.h>
#include <fstream>
#include <windows.h>
#include <shellapi.h>
#include <typeinfo>

Controler::Controler(Repository &repository, Validator validator) : repository{ repository }, validator{validator}
{
}

void Controler::undo()
{
	if (this->undo_stack.size() == 0)
		throw std::exception("No more undos are possible!\n");

	(*this->undo_stack[this->undo_stack.size() - 1]).executeUndo();
	std::string undoType = typeid((*this->undo_stack[this->undo_stack.size() - 1])).name();
	if (undoType == "class UndoAdd")
	{
		Norven_Tower tower = this->addedTowers[this->addedTowers.size() - 1];
		std::unique_ptr<RedoAction> redo = std::make_unique<RedoAdd>(tower, this->repository);
		this->redo_stack.push_back(std::move(redo));
		this->addedTowers.pop_back();
	}
	else if (undoType == "class UndoRemove")
	{
		Norven_Tower tower = this->deletedTowers[this->deletedTowers.size() - 1];
		std::unique_ptr<RedoAction> redo = std::make_unique<RedoDelete>(tower, this->repository);
		this->redo_stack.push_back(std::move(redo));

		this->deletedTowers.pop_back();
	}
	else if (undoType == "class UndoUpdate")
	{
		Norven_Tower tower = this->updatedTowers[this->updatedTowers.size() - 1];
		std::unique_ptr<RedoAction> redo = std::make_unique<RedoUpdate>(tower, this->repository);
		this->redo_stack.push_back(std::move(redo));

		this->updatedTowers.pop_back();
	}
	this->undo_stack.pop_back();
}

void Controler::redo()
{
	if (this->redo_stack.size() == 0)
		throw std::exception("No more redos are possible!\n");

	(*this->redo_stack[this->redo_stack.size() - 1]).executeRedo();
	this->redo_stack.pop_back();
}

std::vector<Norven_Tower> Controler::getMyList() const
{
	return this->myList;
}

bool Controler::add(std::string location, std::string size, std::string auraLevel, std::string quantityOfParts, std::string vision)
{
	validator.validateTower(auraLevel, quantityOfParts);
	Norven_Tower newTower = Norven_Tower(location, size, stoi(auraLevel), stoi(quantityOfParts), vision);
	std::unique_ptr<UndoAction> undo = std::make_unique<UndoAdd>(newTower, this->repository);
	this->undo_stack.push_back(std::move(undo));

	this->addedTowers.push_back(newTower);
	return this->repository.addTower(newTower);
}

bool Controler::remove(std::string &location)
{
	Norven_Tower tower = this->getTowerByLocation(location);
	std::unique_ptr<UndoAction> undo = std::make_unique<UndoRemove>(tower, this->repository);
	this->undo_stack.push_back(std::move(undo));

	this->deletedTowers.push_back(tower);
	return this->repository.removeTower(location);
}

bool Controler::update(std::string &location, std::string &size, std::string auraLevel, std::string quantityOfParts, std::string &vision)
{
	validator.validateTower(auraLevel, quantityOfParts); 
	Norven_Tower newTower = Norven_Tower(location, size, stoi(auraLevel), stoi(quantityOfParts), vision);
	Norven_Tower tower = this->getTowerByLocation(location);

	std::unique_ptr<UndoAction> undo = std::make_unique<UndoUpdate>(tower, this->repository);
	this->undo_stack.push_back(std::move(undo));

	this->updatedTowers.push_back(newTower);

	return this->repository.updateTower(newTower);
}

bool Controler::checkTowerByLocation(const std::string location)
{
	std::vector<Norven_Tower> towers = this->list();
	if (towers.empty() || std::any_of(towers.begin(), towers.end(), [location](Norven_Tower tower) {return tower.getLocation() == location; }) == false)
		throw Exception("Tower does not exist at location "+location+"!\n");
	return true;
}

std::vector<Norven_Tower> Controler::list()
{
	return this->repository.getAllTowers();
}

void Controler::setPath(std::string path)
{
	this->repository.setPath(path);
}

Norven_Tower Controler::getTowerByLocation(std::string location)
{
	/*std::vector<Norven_Tower> auxiliaryTowers = this->listService();
	int encyclopediaSize = this->encyclopedia.getSizeOfEncyclopedia();
	for (int i = 0; i < encyclopediaSize; i++)
	{
		if (auxiliaryTowers[i].getLocation() == location)
		{
			return auxiliaryTowers[i];
		}
	}*/
	std::vector<Norven_Tower> towers = this->list();
	auto iterator = std::find_if(towers.begin(), towers.end(), [location](Norven_Tower tower) {return tower.getLocation() == location; });
	if (iterator != towers.end())
	{
		return *iterator;
	}
	Norven_Tower tower{};
	return tower;
}

void Controler::listGivenSize(std::string& size, int& sizeOfTowers, std::vector<Norven_Tower>& towersOfGivenSize, int quantityOfParts)
{
	//int auxiliaryListIndex = 0, capacity = 150;
	std::vector<Norven_Tower> allTowers = this->list();
	towersOfGivenSize.resize(allTowers.size());
	auto iterator = std::copy_if(allTowers.begin(), allTowers.end(), towersOfGivenSize.begin(), [size, quantityOfParts, towersOfGivenSize](Norven_Tower tower)
	{
		if (size == "")
			return true;
		if (tower.getQuantityOfParts() >= quantityOfParts && tower.getSize() == " " + size)
			return true;
		return false;
	});
	sizeOfTowers = towersOfGivenSize.size();
	/*for (int i = 0; i < this->encyclopedia.getSizeOfEncyclopedia(); i++)
	{
		if(size == " ")
		{
			if (auxiliaryListIndex >= capacity)
			{
				capacity *= 2;
				Norven_Tower* newArrayOfTowers = new Norven_Tower[capacity];
				for (int i = 0; i < auxiliaryListIndex; i++)
				{
					newArrayOfTowers[i] = towersOfGivenSize[i];
				}
				delete[] towersOfGivenSize;
				towersOfGivenSize = newArrayOfTowers;
			}
			towersOfGivenSize[auxiliaryListIndex++] = allTowers[i];
		}
		else
		{
			if (allTowers[i].getQuantityOfParts() >= quantityOfParts && allTowers[i].getSize() == " " + size)
			{
				if (auxiliaryListIndex >= capacity)
				{
					capacity *= 2;
					Norven_Tower* newArrayOfTowers = new Norven_Tower[capacity];
					for (int i = 0; i < auxiliaryListIndex; i++)
					{
						newArrayOfTowers[i] = towersOfGivenSize[i];
					}
					delete[] towersOfGivenSize;
					towersOfGivenSize = newArrayOfTowers;
				}

				towersOfGivenSize[auxiliaryListIndex++] = allTowers[i];
			}
		}		
	}
	sizeOfTowers = auxiliaryListIndex;*/
}

int Controler::getSizeOfEncyclopedia()
{
	return this->repository.getSize();
}

void Controler::mylistLocation(std::string location)
{
	this->myListLocation = location;
}

void Controler::writeMyList(std::vector<Norven_Tower> towers)
{
	this->myList = towers;
	int extensionPosition = this->myListLocation.rfind('.');
	std::string extension = this->myListLocation.substr(extensionPosition + 1, this->myListLocation.length());
	if (extension == "csv")
	{
		std::ofstream file(this->myListLocation, std::ios::app);
		for (auto tower : towers)
		{
			file << tower;
		}
		file.close();
	}
	else if (extension == "html")
	{
		std::ofstream file(this->myListLocation);
		file << "<!DOCTYPE html><html><head><title>My List</title></head><body><table border=\"1\">";
		file << "<tr><td>Location</td><td>Size</td><td>Aura Level</td><td>Quantity of parts</td><td>Vision</td></tr>";
		for (auto  tower: towers)
			file << "<tr><td>"<<tower.getLocation()<<"</td><td>"<<tower.getSize()<<"</td><td>"<<tower.getAuraLevel()<<"</td><td>"<<tower.getQuantityOfParts()<<"</td><td>"<<tower.getVision()<<"</td></tr>";
		file << "</table></body></html>";
		file.close();
	}
	else if (extension == "txt")
	{
		std::ofstream file(this->myListLocation, std::ios::app);
		for (auto tower : towers)
		{
			file << tower;
		}
		file.close();
	}
}

void Controler::displayMyList()
{
	ShellExecuteA(NULL, "open", this->myListLocation.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	//system(this->myListLocation.c_str());
}

Controler::~Controler()
{
}

#include "FakeRepository.h"
#include "FakeValidator.h"

void testIsolatedAddFunction()
{
	FakeRepository fakeRepository{};
	FakeValidator fakevalidator{};
	Controler controler{ fakeRepository, fakevalidator };
	std::string location = "location";
	std::string size = "size";
	std::string vision = "vision";
	assert(controler.add(location, size, "100", "25", vision) == true);
}

void testControler()
{
	testIsolatedAddFunction();
	std::string args[] = { "here", "there", " big", " small", "far", "near" , "11", "12" };
	std::string anywhere = "anywhere";
	std::string someString = "big";
	Encyclopedia enc{ 150 };
	Norven_Tower newTower4 = Norven_Tower();
	Validator validator{};
	Controler ctrl{ enc, validator };
	assert(ctrl.add(args[0], args[2], args[6], args[7], args[4]) == true);
	assert(ctrl.add(args[1], args[3], "123", "333", args[5]) == true);
	try { ctrl.add(args[1], args[2], "11", "144", args[4]); }
	catch (Exception exception)
	{
		assert(true);
	}
	assert(ctrl.remove(args[0]) == true);
	try
	{
		ctrl.remove(args[2]);
	}
	catch (Exception exception)
	{
		assert(true);
	}
	assert(ctrl.update(args[1], args[2], "11", "144", args[4]) == true);
	assert(ctrl.checkTowerByLocation(args[1]) == true);
	try { ctrl.checkTowerByLocation(args[0]); }
	catch (Exception exception)
	{
		assert(true);
	}
	std::vector<Norven_Tower> towers = ctrl.list();
	assert(towers.size() == 1);
	ctrl.setPath(anywhere);
	assert(ctrl.getTowerByLocation(args[1]).getLocation() == args[1]);
	assert(ctrl.getTowerByLocation(args[2]).getLocation() == "");
	assert(ctrl.getSizeOfEncyclopedia() == 1);
	std::vector<Norven_Tower> towers2;
	std::vector<Norven_Tower> towers3;
	std::vector<Norven_Tower> towers4;
	int sizeTower2;
	int sizeTower3;
	int sizeTower4;
	ctrl.listGivenSize(someString, sizeTower2, towers2, 11);
	someString = " " + someString;
	assert(towers2[0].getSize() == someString);
	someString = "";
	ctrl.listGivenSize(someString, sizeTower3, towers3, 11);
	assert(sizeTower3 == 1);
	someString = "big";
	ctrl.listGivenSize(someString, sizeTower4, towers4, 555);
	assert(towers4[0].getLocation() == "");
}
