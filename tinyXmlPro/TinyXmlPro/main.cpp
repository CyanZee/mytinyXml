#include "tinyxmlpro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TinyXmlPro w;
    w.show();
    w.writexml("test.xml");
    w.readxml("test.xml");
    return a.exec();
}
