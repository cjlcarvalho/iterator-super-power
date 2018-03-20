#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

class Aluno : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nome READ nome)
    Q_PROPERTY(int idade READ idade)
    Q_PROPERTY(float coeficienteRendimento READ coeficienteRendimento)

public:
    Aluno(const QString &nome, int idade, float coeficienteRendimento);
    QString nome() const;
    int idade() const;
    float coeficienteRendimento() const;

private:
    QString m_nome;
    int m_idade;
    float m_coeficienteRendimento;
};

#endif // ALUNO_H
