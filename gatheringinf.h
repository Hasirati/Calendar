#ifndef GATHERINGINF_H
#define GATHERINGINF_H

#include <QWidget>

namespace Ui {
class gatheringInf;
}

class gatheringInf : public QWidget
{
    Q_OBJECT

public:
    explicit gatheringInf(QWidget *parent = nullptr);
    ~gatheringInf();

private:
    Ui::gatheringInf *ui;
};

#endif // GATHERINGINF_H
