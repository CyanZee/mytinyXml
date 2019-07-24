/********************************************************************************
** Form generated from reading UI file 'tinyxmlpro.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TINYXMLPRO_H
#define UI_TINYXMLPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TinyXmlPro
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TinyXmlPro)
    {
        if (TinyXmlPro->objectName().isEmpty())
            TinyXmlPro->setObjectName(QStringLiteral("TinyXmlPro"));
        TinyXmlPro->resize(400, 300);
        menuBar = new QMenuBar(TinyXmlPro);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TinyXmlPro->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TinyXmlPro);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TinyXmlPro->addToolBar(mainToolBar);
        centralWidget = new QWidget(TinyXmlPro);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TinyXmlPro->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TinyXmlPro);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TinyXmlPro->setStatusBar(statusBar);

        retranslateUi(TinyXmlPro);

        QMetaObject::connectSlotsByName(TinyXmlPro);
    } // setupUi

    void retranslateUi(QMainWindow *TinyXmlPro)
    {
        TinyXmlPro->setWindowTitle(QApplication::translate("TinyXmlPro", "TinyXmlPro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TinyXmlPro: public Ui_TinyXmlPro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TINYXMLPRO_H
