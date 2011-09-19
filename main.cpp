/*! @mainpage The Mainpage for the LimePipes-documentation.
 *
 * <p>Much text ...</p>
 */
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
