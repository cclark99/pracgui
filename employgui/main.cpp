#include "stdafx.h"
#include "employgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    employgui w;
    w.show();
    return a.exec();
}
