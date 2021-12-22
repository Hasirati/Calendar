#ifndef CHILDREN_H
#define CHILDREN_H

#include <QDebug>

class Children {
  int id;
  QString name;
  int points;
  int link;

public:
  Children();
  Children(int id, QString name, int points, int link);

  int getId();

  void setName(QString);
  QString getName();

  void setPoints(int);
  int getPoints();

  void setLink(int);
  int getLink();
};

#endif // CHILDREN_H
