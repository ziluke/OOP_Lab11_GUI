#pragma once
#include "Repository.h"

void testFileEncyclopedia();

class File_Encyclopedia: public Repository
{
private:
	std::string path;
public:
	File_Encyclopedia(std::string="File_Encyclopedia.txt");
	bool addTower(Norven_Tower newTower) override;
	bool removeTower(std::string & location) override;
	bool updateTower(Norven_Tower newTower) override;
	void setPath(std::string path) override;
	int getSize() const override;
	std::vector<Norven_Tower> getAllTowers() const override;
	void writeToFile(std::vector<Norven_Tower> towers);
	~File_Encyclopedia();
};

