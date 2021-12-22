#include "children.h"

Children::Children() {}

Children::Children(int id, QString name, int points, int link) {
  this->id = id;
  this->name = name;
  this->points = points;
  this->link = link;
}

int Children::getId() { return id; }

void Children::setName(QString name) { this->name = name; }
QString Children::getName() { return name; }

void Children::setPoints(int point) { this->points = point; }
int Children::getPoints() { return points; }

void Children::setLink(int link) { this->link = link; }
int Children::getLink() { return link; }
