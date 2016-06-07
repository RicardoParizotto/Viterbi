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
using namespace std;
 
int distance(const std::string &s1, const std::string &s2);