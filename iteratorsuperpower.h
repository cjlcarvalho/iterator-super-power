#ifndef ITERATORSUPERPOWER_H
#define ITERATORSUPERPOWER_H

using namespace std;

template<template<class> class Collection, class Class, typename Type>
class IteratorSuperPower
{
public:
    IteratorSuperPower(const Collection<Class *> &collection, const char *attribute, const QString &op, Type value);
    void first();
    void next();
    bool hasNext() const;
    Class *current() const;

private:
    bool compare(Type param, Type value) const;

private:
    Collection<Class *> m_collection;
    const char *m_attribute;
    QString m_op;
    Type m_value;
    int m_top;
};

#include "iteratorsuperpower_impl.h"

#endif // ITERATORSUPERPOWER_H
