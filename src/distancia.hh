#ifndef DISTANCIA_INCLUDED
#define DISTANCIA_INCLUDED


/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Cálculo de distância de edição de palavras                                *
 * --------------------------------------------------------------------------*/

/*
Adaptado de:
	Compute Levenshtein Distance
	Martin Ettl, 2012-10-05
*/

#include <string>
#include <iostream>
#include <map>
#include "inicio.hh"
#include "viterbi.hh"

using namespace std;
 
struct Distancia {
    typedef map<string, int>::iterator mit;
    
    int distance(const std::string &s1, const std::string &s2);
    void menorDistancia(Inicio &ini, char *word);
    void palavra(Inicio &ini, char * word);
};

#endif
