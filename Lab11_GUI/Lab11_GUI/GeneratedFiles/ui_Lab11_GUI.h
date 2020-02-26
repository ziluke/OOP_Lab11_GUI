/********************************************************************************
** Form generated from reading UI file 'Lab11_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11_GUI_H
#define UI_LAB11_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11_GUIClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *chartButton;
    QPushButton *modeButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab11_GUIClass)
    {
        if (Lab11_GUIClass->objectName().isEmpty())
            Lab11_GUIClass->setObjectName(QString::fromUtf8("Lab11_GUIClass"));
        Lab11_GUIClass->resize(806, 634);
        centralWidget = new QWidget(Lab11_GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 771, 551));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(horizontalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        updateButton = new QPushButton(horizontalLayoutWidget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(horizontalLayoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        chartButton = new QPushButton(horizontalLayoutWidget);
        chartButton->setObjectName(QString::fromUtf8("chartButton"));

        verticalLayout->addWidget(chartButton);

        modeButton = new QPushButton(horizontalLayoutWidget);
        modeButton->setObjectName(QString::fromUtf8("modeButton"));

        verticalLayout->addWidget(modeButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Lab11_GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lab11_GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 806, 26));
        Lab11_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab11_GUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lab11_GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lab11_GUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lab11_GUIClass->setStatusBar(statusBar);

        retranslateUi(Lab11_GUIClass);
        QObject::connect(addButton, SIGNAL(clicked()), Lab11_GUIClass, SLOT(addButtonClicked()));
        QObject::connect(updateButton, SIGNAL(clicked()), Lab11_GUIClass, SLOT(updateButtonClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), Lab11_GUIClass, SLOT(deleteButtonClicked()));
        QObject::connect(chartButton, SIGNAL(clicked()), Lab11_GUIClass, SLOT(chartButtonClicked()));
        QObject::connect(modeButton, SIGNAL(clicked()), Lab11_GUIClass, SLOT(modeButtonClicked()));

        QMetaObject::connectSlotsByName(Lab11_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab11_GUIClass)
    {
        Lab11_GUIClass->setWindowTitle(QApplication::translate("Lab11_GUIClass", "Lab11_GUI", nullptr));
        addButton->setText(QApplication::translate("Lab11_GUIClass", "Add", nullptr));
        updateButton->setText(QApplication::translate("Lab11_GUIClass", "Update", nullptr));
        deleteButton->setText(QApplication::translate("Lab11_GUIClass", "Delete", nullptr));
        chartButton->setText(QApplication::translate("Lab11_GUIClass", "Chart", nullptr));
        modeButton->setText(QApplication::translate("Lab11_GUIClass", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab11_GUIClass: public Ui_Lab11_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11_GUI_H
