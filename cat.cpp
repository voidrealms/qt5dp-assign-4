#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

Cat::~Cat()
{
    qInfo() << this << "Destroyed";
}
