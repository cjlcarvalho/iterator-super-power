#include "aluno.h"

Aluno::Aluno(const QString &nome, int idade, float coeficienteRendimento) :
    m_nome(nome),
    m_idade(idade),
    m_coeficienteRendimento(coeficienteRendimento)
{

}

QString Aluno::nome() const
{
    return m_nome;
}

int Aluno::idade() const
{
    return m_idade;
}

float Aluno::coeficienteRendimento() const
{
    return m_coeficienteRendimento;
}
