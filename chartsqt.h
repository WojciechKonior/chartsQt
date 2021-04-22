#ifndef CHARTSQT_H
#define CHARTSQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChartsQt; }
QT_END_NAMESPACE

class ChartsQt : public QMainWindow
{
    Q_OBJECT

public:
    ChartsQt(QWidget *parent = nullptr);
    ~ChartsQt();

private:
    Ui::ChartsQt *ui;
};
#endif // CHARTSQT_H
