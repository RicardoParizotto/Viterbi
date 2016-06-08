/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Cálculo de distância de edição de palavras                                *
 * --------------------------------------------------------------------------*/

#ifndef DISTANCIA_INCLUDED /* Evita a dupla inclusão da biblioteca no programa */
#define DISTANCIA_INCLUDED

#include <string>
#include <iostream>
#include <map>
#include "inicio.hh"
#include "viterbi.hh"

using namespace std;

struct Distancia {
    typedef map<string, int>::iterator mit;
    /*Adaptado de:
	    Compute Levenshtein Distance
        Martin Ettl, 2012-10-05

        Esta função calcula a distncia de edição entre duas strings s1 e s2
        Por exemplo: Se a string s1 é "abacate" e a string s2 é "abacaxi"
            a distncia de edição entre s1 e s2 é 4, pois é necessário
            remover 2 letras de s1 ('t' e 'e') e adicionar mais 2 letras ('x' e 'i')
            para transformar s1 em s2
        */
    int distance(const std::string &s1, const std::string &s2);

    /*
     * Esta função verifica qual é a menor distncia de edição entre a string (estilo C) word
     * e as palavras do dicionário
     */
    void menorDistancia(Inicio &ini, char *word);

    /*
     *  Esta função verifica se uma palavra está no dicionário. Caso ela não esteja, é
     *  executado o algoritmo de viterbi para encontrar a palavra mais provável e depois
     *  verifica-se a menor distancia de edição com as palavras do dicionário.
     *
     */
    void palavra(Inicio &ini, char * word);
};

#endif
