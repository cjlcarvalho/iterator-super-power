#include <QApplication>

#include "aluno.h"
#include "iteratorsuperpower.h"

#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<Aluno *> alunos;

    alunos << new Aluno("Dri", 22, 8.9);
    alunos << new Aluno("Sobral", 23, 8.9);
    alunos << new Aluno("Caio", 24, 9.1);
    alunos << new Aluno("Milena", 25, 9);
    alunos << new Aluno("Ramona", 17, 9.5);

    IteratorSuperPower<QList, Aluno, QString> it(alunos,
                                                 &Aluno::nome,
                                                 [](QString comp, QString param) { return comp == param; },
                                                 "Caio");

    for (it.first(); it.hasNext(); it.next())
        qDebug() << it.current()->nome();

    return a.exec();
}
