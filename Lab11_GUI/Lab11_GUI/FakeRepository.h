#pragma once
#include <algorithm>
#include "Repository.h"

class FakeRepository: public Repository
{
public:
	FakeRepository();
	bool addTower(Norven_Tower newTower) 
	{
		return true;
	}
	bool removeTower(std::string & location) { return false; };
	bool updateTower(Norven_Tower newTower) { return false; };
	void setPath(std::string path) {};
	int getSize() const { return 0; };
	std::vector<Norven_Tower> getAllTowers() const { std::vector<Norven_Tower> towers;  return towers; };
	~FakeRepository();
};

