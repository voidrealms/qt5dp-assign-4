#include <QCoreApplication>

/*

  What
  Share Pointers

  Description
  Pointers that auto-delete when out of scope but can be used more than once

  Why
  Sometimes multiple things point to the same pointer

  Example
  Use QSharedPointer to avoid a memory leak - put pointers in a QList


 */

#include <QSharedPointer>
#include <QDebug>
#include "cat.h"

#define catList QList<QSharedPointer<Cat>>
#define catPointer QSharedPointer<Cat>

void makecats(catList &list)
{
    for(int i = 0; i < 10; i++)
    {
        catPointer p = catPointer(new Cat());
        p->setObjectName("Cat" + QString::number(i));
        list.append(p);
    }
}

void listCats(catList &list)
{
    foreach (catPointer p, list) {
        qInfo() << p->objectName();
    }
}

void testCats()
{
    catList list;
    makecats(list);
    listCats(list);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testCats();

    return a.exec();
}
