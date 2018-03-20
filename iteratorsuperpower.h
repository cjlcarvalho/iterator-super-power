#ifndef ITERATORSUPERPOWER_H
#define ITERATORSUPERPOWER_H

#include <QString>

template<template<class> class Collection, class Class, class Type>
class IteratorSuperPower
{
public:
    IteratorSuperPower(const Collection<Class *> &collection, 
                       const char *property, 
                       const QString &op, 
                       Type compareValue);
    void first();
    void next();
    bool hasNext() const;
    Class *current() const;

private:
    bool compare(Type param) const;

private:
    Collection<Class *> m_collection;
    const char *m_property;
    QString m_op;
    Type m_compareValue;
    int m_top;
};

#include "iteratorsuperpower_impl.h"

#endif // ITERATORSUPERPOWER_H
