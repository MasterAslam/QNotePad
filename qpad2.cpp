#include "qpad2.h"
#include "ui_qpad2.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QFontDialog>
#include<QFont>
#include<QLabel>
#include<QTextCharFormat>
#include<QAction>
#include<QString>
#include<QMessageBox>

Qpad2::Qpad2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qpad2)
{
    ui->setupUi(this);
}

Qpad2::~Qpad2()
{
    delete ui;
    this->setCentralWidget(ui->textEdit);
}



void Qpad2::on_actionNew_triggered()
{
    CurrentFile.clear();
    ui->textEdit->setText(QString());
}



void Qpad2::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open this file");
    QFile file(fileName);
    CurrentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","Cannot open file: "+ file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void Qpad2::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"save");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning","cannot save file: "+file.errorString());
        return;
    }
    CurrentFile = fileName;
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void Qpad2::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save as");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text));
    {
        QMessageBox::warning(this,"Warning","Cannot open file: "+ file.errorString());
        return;
    }
    CurrentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void Qpad2::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Qpad2::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Qpad2::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Qpad2::on_actionBold_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    bool isBold = cursor.charFormat().font().bold();
    QTextCharFormat fmt;
    fmt.setFontWeight(isBold ? QFont::Normal : QFont::Bold);
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void Qpad2::on_actionSub_Script_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat fmt;
    fmt.setVerticalAlignment((cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSubScript)? QTextCharFormat::AlignNormal : QTextCharFormat::AlignSubScript);
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void Qpad2::on_actionSuper_Script_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat fmt;
    fmt.setVerticalAlignment((cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSuperScript)? QTextCharFormat::AlignNormal : QTextCharFormat::AlignSuperScript);
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

