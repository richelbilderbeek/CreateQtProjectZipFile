#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <QApplication>

#include <csignal>
#include <iostream>

#include "qtcreateqtprojectzipfilemenudialog.h"
#pragma GCC diagnostic pop

void OnAbort(int)
{
  std::cout << "Abort" << std::endl;
}

int main(int argc, char *argv[])
{
  std::signal(SIGABRT,OnAbort);
  QApplication a(argc, argv);
  ribi::QtCreateQtProjectZipFileMenuDialog w;
  w.show();
  return a.exec();
}

