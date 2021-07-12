#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <QtXml>
#include <QSpinBox>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFile xml_doc;
    QDomElement dom;
    QDomNode noeud;
    QDomElement element;
    QSpinBox *id_demand;
    QPushButton *open;
    int ids;

private slots:
    void openDom();
    void change(int change);

};

#endif // MAINWINDOW_H
