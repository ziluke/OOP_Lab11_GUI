#pragma once
#include "Norven_Tower.h"
#include <vector>

class Repository
{
public:
	Repository();
	virtual bool addTower(Norven_Tower newTower) = 0;
	virtual bool removeTower(std::string & location) = 0;
	virtual bool updateTower(Norven_Tower newTower) = 0;
	virtual void setPath(std::string path) = 0;
	virtual int getSize() const = 0;
	virtual std::vector<Norven_Tower> getAllTowers() const = 0;
	~Repository();
};

