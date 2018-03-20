#ifndef ITERATORSUPERPOWER_IMPL_H
#define ITERATORSUPERPOWER_IMPL_H

#include "iteratorsuperpower.h"

#include <QObject>
#include <QVariant>

template<template<class> class Collection, class Class, class Type>
IteratorSuperPower<Collection, Class, Type>::IteratorSuperPower(const Collection<Class *> &collection,
                                                                const char *property,
                                                                const QString &op,
                                                                Type compareValue) :
    m_collection(collection),
    m_property(property),
    m_op(op),
    m_compareValue(compareValue),
    m_top(0)
{

}

template<template<class> class Collection, class Class, class Type>
void IteratorSuperPower<Collection, Class, Type>::first()
{
    m_top = 0;

    if (m_collection.empty())
        return;

    QObject *obj = m_collection[m_top];

    QVariant attributeValue = obj->property(m_property);

    if (attributeValue.isValid())
        if (compare(attributeValue.value<Type>()))
            return;

    next();
}

template<template<class> class Collection, class Class, class Type>
void IteratorSuperPower<Collection, Class, Type>::next()
{
    if (m_top >= m_collection.size()) 
        return;

    m_top++;

    while(m_top < m_collection.size()) {

        QObject *obj = m_collection[m_top];

        QVariant attributeValue = obj->property(m_property);

        if (attributeValue.isValid())
            if (compare(attributeValue.value<Type>()))
                return;

        m_top++;
    }
}

template<template<class> class Collection, class Class, class Type>
bool IteratorSuperPower<Collection, Class, Type>::hasNext() const
{
    return m_top < m_collection.size();
}

template<template<class> class Collection, class Class, class Type>
Class *IteratorSuperPower<Collection, Class, Type>::current() const
{
    return (m_top < m_collection.size()) ? m_collection[m_top] : nullptr;
}

template<template<class> class Collection, class Class, class Type>
bool IteratorSuperPower<Collection, Class, Type>::compare(Type param) const
{
    if (m_op == "==")
        return param == m_compareValue;
    else if (m_op == "!=")
	    return param != m_compareValue;
    else if (m_op == ">=")
        return param >= m_compareValue;
    else if (m_op == ">")
        return param > m_compareValue;
    else if (m_op == "<=")
        return param <= m_compareValue;
    else if (m_op == "<")
        return param < m_compareValue;
    return false;
}

#endif // ITERATORSUPERPOWER_IMPL_H
