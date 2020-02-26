#pragma once
#include "Encyclopedia.h"
#include "Validator.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "UndoAdd.h"
#include "RedoAdd.h"
#include "RedoDelete.h"
#include "UndoRemove.h"
#include "RedoUpdate.h"
#include "UndoUpdate.h"
#include <memory>
void testControler();

class Controler
{
private:
	std::vector<Norven_Tower> deletedTowers;
	std::vector<Norven_Tower> addedTowers;
	std::vector<Norven_Tower> updatedTowers;
	Repository &repository;
	std::vector<Norven_Tower> myList;
	std::string myListLocation;
	Validator validator;
	std::vector<std::unique_ptr<UndoAction>> undo_stack;
	std::vector<std::unique_ptr<RedoAction>> redo_stack;

public:
	Controler(Repository &repository, Validator validator);

	void undo();
	void redo();
	std::vector<Norven_Tower> getMyList() const;
	std::vector<Norven_Tower> getAllTowers() { return this->repository.getAllTowers(); };
	bool add(std::string location, std::string size, std::string auraLevel, std::string quantityOfParts, std::string vision);
	bool remove(std::string &location);
	bool update(std::string &location, std::string &size, std::string auraLevel, std::string quantityOfParts, std::string &vision);
	bool checkTowerByLocation(const std::string location);
	std::vector<Norven_Tower> list();
	void setPath(std::string path);
	void listGivenSize(std::string& size, int& sizeOfTowers, std::vector<Norven_Tower>& towersOfGivenSize, int quantityOfParts=0);
	Norven_Tower getTowerByLocation(std::string location);
	int getSizeOfEncyclopedia();
	void mylistLocation(std::string location);
	void writeMyList(std::vector<Norven_Tower> towers);
	void displayMyList();
	~Controler();
};

