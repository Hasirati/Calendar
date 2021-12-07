#include "dbmanager.h"
#include "start.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  DataBase conn;
  conn.connectToDataBase();

  Start w;
  w.show();
  return a.exec();
}
