#include "aluno.h"
#include "iteratorsuperpower.h"

#include <QDebug>
#include <QList>
#include <QVector>

#include <vector>

int main()
{
    QList<Aluno *> alunos;

    alunos.push_back(new Aluno("Dri", 22, 8.9));
    alunos.push_back(new Aluno("Sobral", 23, 8.9));
    alunos.push_back(new Aluno("Caio", 24, 9.1));
    alunos.push_back(new Aluno("Milena", 25, 9));
    alunos.push_back(new Aluno("Ramona", 17, 9.5));

    IteratorSuperPower<QList, Aluno, QString> it(alunos, &Aluno::nome, "==", "Caio");

    for (it.first(); it.hasNext(); it.next())
        qDebug() << it.current()->nome();

    return 0;
}
