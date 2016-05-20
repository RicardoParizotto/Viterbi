#include <iostream>
#include "inicio.hh"

using namespace std;

int main()  {
    Inicio teste("input/steve_jobs.txt");
    
    teste.loadDict();

    teste.readFile();
    teste.writeDict();
    teste.writeTransitions();
    return 0;
}
