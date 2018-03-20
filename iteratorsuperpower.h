#ifndef ITERATORSUPERPOWER_H
#define ITERATORSUPERPOWER_H

#include <functional>

using namespace std;

template<template<class> class Collection, class Class, typename Type>
class IteratorSuperPower
{
    typedef Type (Class::*MemberMethod)() const;

public:
    IteratorSuperPower(const Collection<Class *> &collection,
                       MemberMethod accessMethod,
                       const QString &op,
                       Type value);
    void first();
    void next();
    bool hasNext() const;
    Class *current() const;

private:
    bool compare(Type param, Type value) const;

private:
    Collection<Class *> m_collection;
    MemberMethod m_accessMethod;
    QString m_op;
    Type m_value;
    int m_top;
};

#include "iteratorsuperpower_impl.h"

#endif // ITERATORSUPERPOWER_H
