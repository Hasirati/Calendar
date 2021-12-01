#ifndef START_H
#define START_H

#include <QWidget>
#include "gatheringinf.h"

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_pb_start_clicked();

private:
    Ui::Start *ui;
    gatheringInf obj;
};

#endif // START_H
