#ifndef QPAD2_H
#define QPAD2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Qpad2; }
QT_END_NAMESPACE

class Qpad2 : public QMainWindow
{
    Q_OBJECT

public:
    Qpad2(QWidget *parent = nullptr);
    ~Qpad2();

private slots:
    void on_actionNew_triggered();


    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionBold_triggered();

    void on_actionSub_Script_triggered();

    void on_actionSuper_Script_triggered();

private:
    Ui::Qpad2 *ui;
    QString CurrentFile = "";
};
#endif // QPAD2_H
