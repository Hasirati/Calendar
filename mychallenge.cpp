#include "mychallenge.h"

MyChallenge::MyChallenge() {}

MyChallenge::MyChallenge(int id, QString name, int points) {
  this->id = id;
  this->name = name;
  this->points = points;
}

int MyChallenge::getId() { return id; }

void MyChallenge::setName(QString name) { this->name = name; }
QString MyChallenge::getName() { return name; }

void MyChallenge::setPoints(int points) { this->points = points; }
int MyChallenge::getPoints() { return points; }
