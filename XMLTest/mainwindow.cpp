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



    QDomElement dom_element = dom.documentElement();
    QDomNode noeud = dom_element.firstChild();
    QDomElement child = noeud.toElement(); // Transformation du noeud en élément
    QDomNode noeud2 = child.firstChild();
    QDomElement grandchild = noeud2.toElement();
    QDomNode noeud3 = grandchild.firstChild();




    int i = 0;

    while(!noeud.isNull())
    {
        child = noeud.toElement();
        if(child.attribute("ID").toInt() == i)
        {
            QMessageBox::information(NULL, "étape", child.attribute("ID"));
            noeud2 = child.firstChild();
            while(!noeud2.isNull()){
                QDomElement grandchild = noeud2.toElement();
                ids = 1; // On initialise ids à 1
                if(grandchild.tagName()== "eventD"){
                    QMessageBox::information(NULL, "eventD", grandchild.attribute("ID"));
                    noeud3 = grandchild.firstChild();
                    while(!noeud3.isNull())
                    {
                        QDomElement event = noeud3.toElement();
                        if(event.attribute("id").toInt() == ids)
                        {
                            QMessageBox::information(NULL, "event", "EVENT n° " + event.attribute("id","?") + "<br />ordre donné : " + event.attribute("ordre")+ + "<br />zone : " + event.attribute("zone") + "<br />label : " +event.attribute("label") + "<br />tableau : " +event.attribute("tab")+ "<br />variable : " + event.attribute("var"));
                            ids++;
                            noeud3 = noeud3.nextSibling();
                        }
                    }
                    noeud2 = noeud2.nextSibling();
                }

                if(grandchild.tagName()== "eventC"){
                    QMessageBox::information(NULL, "eventC", grandchild.attribute("ID"));
                    noeud2 = noeud2.nextSibling();
                }

                if(grandchild.tagName()== "eventI"){
                    QMessageBox::information(NULL, "eventI", grandchild.attribute("ID"));
                    noeud2 = noeud2.nextSibling();
                }
            }

            i++;
            noeud = noeud.nextSibling();

        }
    }




/**    if(child.attribute("ID").toInt() == 1)
    {
        QMessageBox::information(NULL, "étape", child.attribute("ID"));
        while(!noeud2.isNull())
        {
            QDomElement grandchild = noeud2.toElement();
            if(grandchild.attribute("id").toInt() == ids)
            {
                QMessageBox::information(NULL, "event", "EVENT n° " + grandchild.attribute("id","?") + "<br />ordre donné : " + grandchild.attribute("ordre")+ + "<br />zone : " + grandchild.attribute("zone") + "<br />label : " +grandchild.attribute("label") + "<br />tableau : " +grandchild.attribute("tab")+ "<br />variable : " + grandchild.attribute("var"));
                ids++;
                noeud2 = noeud2.nextSibling();
            }
        }

    }
**/





//    QListWidget *listeProjects = new QListWidget();


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
   /** QDomDocument dom("mon_xml");
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

     } **/
}

MainWindow::~MainWindow()
{
    delete ui;
}

