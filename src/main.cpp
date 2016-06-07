#include <iostream>
#include "inicio.hh"
#include "viterbi.hh"

using namespace std;

int main(int argc, char ** argv)  {
    Inicio teste("input/steve_jobs.txt");
    
    teste.loadDict();

    teste.readFile();
    teste.writeDict();
    teste.writeTransitions();

    for(int i = 1; i < argc; i++)    {
        Viterbi v;
        v.viterbi(teste, argv[i]);
    }
    return 0;
}
