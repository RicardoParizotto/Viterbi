/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Cálculo da probabilidade de transição e geração do arquivo de dicionário  *
 * --------------------------------------------------------------------------*/
#ifndef INICIO_INCLUDED
#define INICIO_INCLUDED

#include <fstream>
#include <exception>
#include <string>
#include <unistd.h>
#include <map>
#include <utility>

#define DEBUG

using std::exception;
using std::string;
using std::map;
using std::pair;
using std::ifstream;
using std::ofstream;

class Inicio    {
    const char * fileName;
    static const int BUF_LEN = 500000;
    static const int WORD_LEN = 256;
    static const char * DICT_FILE;
    static const char * TRANSITIONS_FILE;
    int sum;

public:
    map<string, int> mapWords;
    Inicio(const char * fName): fileName(fName) {};

    /* Matriz de probabilidades de transição */
    double transition[27][27];

    /* Determina se um caractere é válido */
    inline bool valid(char c)   { return (c >= 'a' && c <= 'z') || c == ' '; };
    /* Retorna a posição de um caractere c na matriz,
     *  'a' =0, ..., z = '25' e espaço ou outros caracteres 27 */
    inline int posMtr(char c)   { return (c-'a' >= 0)? c-'a' : 26; };
    /* Retorna um caractere a partir de uma posição da matriz. '$' representa espaço */
    inline static char mapMtr(int k)    { return (k+'a' <= 'z')? k+'a' : '$'; };

    inline bool fileExists(const char * fName) { return access(fName, F_OK) != EOF; };

    /* Lê o arquivo de entrada. O arquivo é carregado para um buffer para acesso rápido
     * O BUFFER tem o tamanho definido pela constante BUF_LEN, que por padrão é de 500000 caracteres */
    bool readFile();
    /* Calcula as probabilidades de transição e gera o dicionário com as palavras do arquivo de entrada */
    void wordCount(char *);

    /* Escreve o dicionário em um arquivo de nome definido em DICT_FILE
     * O arquivo consiste em entradas com a palavra e a frequência desta palavra no arquivo de entrada */
    bool writeDict();
    /* Escreve as probabilidades de transição em um arquivo de nome definido em TRANSITIONS_FILE.
     * O arquivo consiste em 2 caracteres separados
     *  por espaço e a probabilidade também separada por espaço. */
    bool writeTransitions();

    /* Carrega um dicionário gerado anteriormente no arquivo DICT_FILE */
    bool loadDict();
    /* Carrega as probabilidades de transição geradas anteriormente no arquivo TRANSITIONS_FILE */
    bool loadTransitions();

    /* Verifica se uma palavra pertence ao dicionário */
    bool dic(string word){ return mapWords.find(word) != mapWords.end();}
};

#endif
