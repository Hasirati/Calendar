#ifndef GATHERINGINF_H
#define GATHERINGINF_H

#include <QWidget>
#include <QString>
#include <iostream>

using namespace std;
namespace Ui {
class gatheringInf;
}

class gatheringInf : public QWidget
{
    Q_OBJECT
    int HOUR, MINUTE;
    enum answer {Yes, No};
public:
    gatheringInf();
    explicit gatheringInf(QWidget *parent = nullptr);
    ~gatheringInf();
    void getWakeUp();
    void getResultDay();
    void getSelfControl();

private slots:
    void on_pb_next_clicked();

private:
    Ui::gatheringInf *ui;
};

#endif // GATHERINGINF_H
