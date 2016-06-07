#include <iostream>
#include "inicio.hh"
#include "viterbi.hh"

using namespace std;

int main()  {
    Inicio teste("input/steve_jobs.txt");
    
    teste.loadDict();

    teste.readFile();
    teste.writeDict();
    teste.writeTransitions();

    Viterbi v;
    v.viterbi(teste, "steva");
    return 0;
}
