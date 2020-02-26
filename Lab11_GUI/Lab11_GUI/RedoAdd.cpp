#include "RedoAdd.h"

void RedoAdd::executeRedo()
{
	this->repository.addTower(deletedTower);
}

RedoAdd::~RedoAdd()
{
}
