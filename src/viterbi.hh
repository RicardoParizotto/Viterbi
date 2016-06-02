#include "probtecla.hh"
#include "inicio.hh"


			

/*
* implementação da função de viterbi
*/
class Viterbi	{
    double ps[27][27];		//probabilidades auxiliares
public:
    void viterbi( Inicio &, char * );
};
