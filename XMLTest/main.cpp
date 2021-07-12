#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QDebug>
#include <QtXml>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

/**
    // Create a document to write XML
       QDomDocument document;

    // Making the root element
       QDomElement root = document.createElement("Evenement");
    // Adding the root element to the docuemnt
       document.appendChild(root);

    // Writing to a file
        QFile file("C:/Users/nguye/Projets Qt/XMLTest/myXLM.xml");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
             qDebug() << "Open the file for writing failed";
          }
          else
          {
              QTextStream stream(&file);
              stream << document.toString();
              file.close();
              qDebug() << "Writing is done";
          }
**/


/**    QDomDocument xml;
    QFile f("myXML.xml");
    if (!f.open(QFile::ReadOnly | QFile::Text)) // Ouverture du fichier XML en lecture seule et en mode texte
        {
             QMessageBox::warning(0, ("Erreur lors de l'ouvertur du fichier de mise à jour"), ("Impossible de lire le fichier <strong>%1</strong> à partir du serveur !"));
             return 0;
         }
    xml.setContent(&f);
    f.close();**/



    MainWindow w;
    w.show();
    return a.exec();
}
