#pragma once
#include "RedoAction.h"
class RedoUpdate :
	public RedoAction
{
private:
	Norven_Tower updatedTower;
	Repository& repository;
public:
	RedoUpdate(Norven_Tower tower, Repository& repo) :updatedTower{ tower }, repository{repo} {};
	void executeRedo() override;
	~RedoUpdate();
};

