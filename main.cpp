#include "aluno.h"
#include "iteratorsuperpower.h"

#include <QDebug>
#include <QList>

int main()
{
    QList<Aluno *> alunos;

    alunos << new Aluno("Dri", 22, 8.9) << new Aluno("Sobral", 23, 8.9);
    alunos << new Aluno("Caio", 24, 9.1) << new Aluno("Milena", 25, 9);
    alunos << new Aluno("Ramona", 17, 9.5);

    IteratorSuperPower<QList, Aluno, float> it(alunos, "coeficienteRendimento", ">", 9);

    for (it.first(); it.hasNext(); it.next())
        qDebug() << it.current()->nome();

    return 0;
}
