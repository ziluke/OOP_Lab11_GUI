#pragma once
#include "RedoAction.h"
class RedoAdd :
	public RedoAction
{
private:
	Norven_Tower deletedTower;
	Repository& repository;
public:
	RedoAdd(Norven_Tower deletedTower, Repository& repo) :deletedTower{ deletedTower }, repository{ repo }{};

	void executeRedo() override;
	~RedoAdd();
};

