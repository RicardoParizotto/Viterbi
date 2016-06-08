/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Função de início. Gera o dicionário a partir de um arquivo ou carrega um  *
 *      arquivo de dicionário já existente e, a partir deste dicionário,     *
 *      calcula-se as probabilidades e executa o algoritmo de viterbi        *
 * --------------------------------------------------------------------------*/

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
