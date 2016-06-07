#include "probtecla.hh"
#include "inicio.hh"


			

/*
* implementação da função de viterbi
*/
class Viterbi	{
    double ps[27][27];		//probabilidades auxiliares
//    const double EPS = 1e8;    lixo


public:
    void viterbi( Inicio &, char * );
};
