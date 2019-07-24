#ifndef TINYXMLPRO_H
#define TINYXMLPRO_H

#include <QMainWindow>
#include <iostream>
#include "tinyxml/tinyxml.h"

namespace Ui {
class TinyXmlPro;
}

class TinyXmlPro : public QMainWindow
{
    Q_OBJECT

public:
    explicit TinyXmlPro(QWidget *parent = 0);
    ~TinyXmlPro();

    void readxml(std::string xmlfile);
    void writexml(std::string xmlfile);

private:
    Ui::TinyXmlPro *ui;
};

#endif // TINYXMLPRO_H
