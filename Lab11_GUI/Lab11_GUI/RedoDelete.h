#pragma once
#include "RedoAction.h"
class RedoDelete :
	public RedoAction
{
private:
	Norven_Tower addedTower;
	Repository& repository;
public:
	RedoDelete(Norven_Tower tower, Repository& repo) :addedTower{ tower }, repository{repo} {};
	void executeRedo() override;
	~RedoDelete();
};

