#include "Lab11_GUI.h"
#include <qmessagebox>
Lab11_GUI::Lab11_GUI(Controler& controler, QWidget *parent)
	: QMainWindow(parent), controler{controler}
{
	ui.setupUi(this);
}

void Lab11_GUI::deleteButtonClicked()
{
	QMessageBox::information(this, tr("Title"), tr("This text"));
}

void Lab11_GUI::updateButtonClicked()
{
	QMessageBox::information(this, tr("Title"), tr("This text"));
}

void Lab11_GUI::modeButtonClicked()
{
	QMessageBox::information(this, tr("Title"), tr("This text"));
}

void Lab11_GUI::chartButtonClicked()
{
	QMessageBox::information(this, tr("Title"), tr("This text"));
}

void Lab11_GUI::addButtonClicked()
{
	QMessageBox::information(this, tr("Title"), tr("This text"));
}

