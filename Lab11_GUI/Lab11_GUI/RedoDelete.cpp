#include "RedoDelete.h"


void RedoDelete::executeRedo()
{
	this->repository.removeTower(addedTower.getLocation());
}

RedoDelete::~RedoDelete()
{
}
