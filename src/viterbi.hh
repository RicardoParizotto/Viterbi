#ifndef VITERBI_INCLUDED
#define VITERBI_INCLUDED


#include "probtecla.hh"
#include "inicio.hh"


		
/*
* implementação da função de viterbi
*/
class Viterbi	{
    double ps[27][27];		//probabilidades auxiliares

public:
    char *viterbi( Inicio &ini, char * word);
};

#endif
