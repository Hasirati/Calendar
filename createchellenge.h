#ifndef CREATECHELLENGE_H
#define CREATECHELLENGE_H

#include <QWidget>

namespace Ui {
class CreateChellenge;
}

class CreateChellenge : public QWidget
{
    Q_OBJECT

public:
    explicit CreateChellenge(QWidget *parent = nullptr);
    ~CreateChellenge();

private:
    Ui::CreateChellenge *ui;
};

#endif // CREATECHELLENGE_H
