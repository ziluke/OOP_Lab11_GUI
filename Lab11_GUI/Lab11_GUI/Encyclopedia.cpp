#include "Encyclopedia.h"
#include <string.h>

/*template <typename T>
Encyclopedia<T>::Encyclopedia(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->towers = new T[this->capacity];
}

template <typename T>
bool Encyclopedia<T>::addTower(T newTower)
{
	if (this->size >= this->capacity)
	{
		this->capacity *= 2;
		T* newArrayOfTowers = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			newArrayOfTowers[i] = this->towers[i];
		}
		delete[] this->towers;
		this->towers = newArrayOfTowers;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->towers[i].getLocation() == newTower.getLocation())
		{
			return false;
		}
	}

	this->towers[this->size] = newTower;
	this->size++;
	return true;
}

template <typename T>
bool Encyclopedia<T>::removeTower(std::string & location)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->towers[i].getLocation() == location)
		{
			int j = i;
			while (j < this->size-1)
			{
				this->towers[j] = this->towers[j + 1];
				j++;
			}
			this->size--;
			return true;
		}
	}
	return false;
}

template <typename T>
bool Encyclopedia<T>::updateTower(std::string & location, std::string & newSize, int newAuraLevel, int newQuantitiOfParts, std::string & newVision)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->towers[i].getLocation() == location)
		{
			this->towers[i].setSize(newSize);
			this->towers[i].setQuantityOfParts(newQuantitiOfParts);
			this->towers[i].setAuraLevel(newAuraLevel);
			this->towers[i].setVision(newVision);
			return true;
		}
	}
	return false;
}

template <typename T>
T* Encyclopedia<T>::getAllTowers()
{
	return this->towers;
}

template <typename T>
Encyclopedia<T>::~Encyclopedia()
{
	delete[] this->towers;
}

template class Encyclopedia<Norven_Tower>;
*/

#include <assert.h>
void testEncyclopedia()
{
	std::string args[] = { "here", "there", "big", "small", "far", "near" , "11", "12" };
	std::string anywhere = "anywhere";
	Encyclopedia enc{ 150 };
	Norven_Tower newTower1 = Norven_Tower(args[0], args[2], stoi(args[6]), stoi(args[7]), args[4]);
	Norven_Tower newTower2 = Norven_Tower(args[1], args[3], 123, 333, args[5]);
	Norven_Tower newTower3 = Norven_Tower(args[1], args[2], 11, 144, args[4]);
	Norven_Tower newTower4 = Norven_Tower(anywhere, args[2], 11, 144, args[4]);
	std::string string = newTower1.toString();
	assert(string == "Location: here, Size: big, Aura Level: 11, Quantity of parts: 12, Vision: far");
	assert(enc.addTower(newTower1) == true);
	assert(enc.addTower(newTower2)== true);
	try
	{
		enc.addTower(newTower1);
	}
	catch (Exception exception)
	{
		assert(true);
	}
	assert(enc.removeTower(args[0])==true);
	assert(enc.updateTower(newTower3)==true);
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
	enc.setPath("nowhere");
	assert(towers.size() == 1);
}