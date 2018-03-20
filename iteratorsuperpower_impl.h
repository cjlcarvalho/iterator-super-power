#ifndef ITERATORSUPERPOWER_IMPL_H
#define ITERATORSUPERPOWER_IMPL_H

#include "iteratorsuperpower.h"

template<template<class> class Collection, class Class, typename Type>
IteratorSuperPower<Collection, Class, Type>::IteratorSuperPower(const Collection<Class *> &collection,
                                                                MemberMethod accessMethod,
                                                                const QString &op,
                                                                Type value) :
    m_collection(collection),
    m_accessMethod(accessMethod),
    m_op(op),
    m_value(value),
    m_top(0)
{

}

template<template<class> class Collection, class Class, typename Type>
void IteratorSuperPower<Collection, Class, Type>::first()
{
    m_top = 0;

    if (m_collection.empty())
        return;

    Type attributeValue = (m_collection[m_top]->*m_accessMethod)();

    if (compare(attributeValue, m_value))
        return;

    next();
}

template<template<class> class Collection, class Class, typename Type>
void IteratorSuperPower<Collection, Class, Type>::next()
{
    if (m_top >= m_collection.size()) return;

    m_top++;

    while(m_top < m_collection.size()) {

        Type attributeValue = (m_collection[m_top]->*m_accessMethod)();

        if (compare(attributeValue, m_value))
            break;

        m_top++;
    }
}

template<template<class> class Collection, class Class, typename Type>
bool IteratorSuperPower<Collection, Class, Type>::hasNext() const
{
    return m_top < m_collection.size();
}

template<template<class> class Collection, class Class, typename Type>
Class *IteratorSuperPower<Collection, Class, Type>::current() const
{
    return (m_top < m_collection.size()) ? m_collection[m_top] : nullptr;
}

template<template<class> class Collection, class Class, typename Type>
bool IteratorSuperPower<Collection, Class, Type>::compare(Type param, Type value) const
{
    if (m_op == "==")
        return value == param;
    else if (m_op == ">=")
        return value >= param;
    else if (m_op == ">")
        return value > param;
    else if (m_op == "<=")
        return value <= param;
    else if (m_op == "<")
        return value < param;
    return false;
}

#endif // ITERATORSUPERPOWER_IMPL_H
