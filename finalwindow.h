#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>

namespace Ui {
class finalWindow;
}

class finalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit finalWindow(QWidget *parent = nullptr);
    ~finalWindow();

private:
    Ui::finalWindow *ui;
};

#endif // FINALWINDOW_H
