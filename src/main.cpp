#include <iostream>
#include "inicio.hh"
#include "viterbi.hh"
#include "distancia.hh"

using namespace std;

void print_help(const char * str)   {
    cout << "Digite: \n\t" << str << " palavra1 [palavra2] ... [palavra_n]" << endl;
}

int main(int argc, char ** argv)  {
    Inicio teste("input/steve_jobs.txt");
    
    teste.loadDict();

    teste.readFile();
    teste.writeDict();
    teste.writeTransitions();

    if(argc < 2) 
        print_help(argv[0]);

    for(int i = 1; i < argc; i++)    {
        Distancia d;
        d.palavra(teste, argv[i]);
    }
    return 0;
}
