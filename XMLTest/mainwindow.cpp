#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDomDocument dom("mon_xml");
    QFile xml_doc("myXML.xml"); // On choisit le fichier contenant les informations XML.

    if(!xml_doc.open(QIODevice::ReadOnly)) // Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert.");
        return;
    }
    if (!dom.setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
        xml_doc.close();
        QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return;
    }

    ids = 1; // On initialise ids à 1



    QDomElement dom_element = dom.documentElement();
    QDomNode noeud = dom_element.firstChild();
    QDomElement child = noeud.toElement();
    QDomElement grandchild = child.firstChild().toElement();


    if(child.attribute("ID").toInt() == 1)
    {
        QMessageBox::information(NULL, "étape", child.attribute("ID"));
        if(grandchild.attribute("id").toInt() == ids)
        {
            QMessageBox::information(NULL, "event", grandchild.attribute("id","?") + "<br />ordre donné : " + grandchild.attribute("ordre"));
            ids++;
            grandchild.nextSibling();
        }

    }






//    QListWidget *listeProjects = new QListWidget();


/**
    while(!noeud.isNull())
    {
        QDomElement element = noeud.toElement(); // Transformation du noeud en élément
        if(!dom_element.isNull())
        {
             //QMessageBox::information(this, "Numéro de l'évènement", "Le numéro de l'évènement est " +  element.attribute("id","?"));
             QListWidgetItem *itemProject = new QListWidgetItem(QString(element.text()) + "(" + element.attribute("id","?") + ")"); // On met le texte de l'élément dans l'item de la liste
             listeProjects->addItem(itemProject); // Et on place l'item dans la liste
             if(element.attribute("id").toInt() == ids)
                 QMessageBox::information(NULL, "évènement", "EVENT n° " + element.attribute("id", "?") + "<br />ordre donné : " + element.attribute("ordre") + "<br />variable : " + element.attribute("var") + "<br />label : " +element.attribute("label"));
             ids++;
             noeud = noeud.nextSibling();
        }

    }

**/

/*    QSpinBox *id_demand = new QSpinBox(this);
        QPushButton *open = new QPushButton("Voir la prochaine news", this);
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(id_demand);
        layout->addWidget(open);
        setLayout(layout);

   connect(id_demand, SIGNAL(valueChanged(int)), this, SLOT(change(int)));
   connect(open, SIGNAL(clicked()), this, SLOT(openDom()));


*/

    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.

}


void MainWindow::change(int change)
{
   ids = change;
}

void MainWindow::openDom()
{
    QDomDocument dom("mon_xml");
     QFile file("xml_doc.xml");
     if (!file.open(QIODevice::ReadOnly))
         return;
     if (!dom.setContent(&file))
     {
         file.close();
         return;
     }
     file.close();
     QDomElement docElem = dom.documentElement();
     QDomNode n = docElem.firstChild();
     while(!n.isNull())
     {
         QDomElement e = n.toElement();
         // C'est ici que l'on va marquer le code
         if(element.attribute("id").toInt() == ids)
             QMessageBox::information(NULL, "Information", "La nouvelle news est :<br />" + e.attribute("value"));
         n = n.nextSibling();

     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

