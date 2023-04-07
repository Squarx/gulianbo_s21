//#include "glview.h"

//#include <QApplication>

// int main(int argc, char *argv[])
//{
//   QApplication a(argc, argv);
//   glView w;
//   w.show();
//   return a.exec();
// }
//  ____________________________________
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
