#include "Lab11_GUI.h"
#include <QtWidgets/QApplication>
#include "File_Encyclopedia.h"
#include "Controler.h"
#include "GUI.h"
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream file{ "settings.txt" };
	std::string setting;
	file >> setting;
	Repository* encyclopedia;
	if (setting == "file")
		encyclopedia = new File_Encyclopedia{};
	else if(setting == "inmemory")
		encyclopedia = new Encyclopedia{};
	QApplication a(argc, argv);
	Validator validator{};
	Controler controler{ *encyclopedia, validator };
	GUI gui{ controler };
	//Lab11_GUI gui{controler};
	gui.show();
	return a.exec();
}
