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

    double transition[27][27];

    inline bool valid(char c)   { return (c >= 'a' && c <= 'z') || c == ' '; };
    inline int posMtr(char c)   { return (c-'a' >= 0)? c-'a' : 26; };
    inline static char mapMtr(int k)    { return (k+'a' <= 'z')? k+'a' : '$'; };
    inline bool fileExists(const char * fName) { return access(fName, F_OK) != EOF; };

    bool readFile();
    void wordCount(char *);   

    bool writeDict();
    bool writeTransitions();

    bool loadDict();
    bool loadTransitions();

    bool dic(string word){ return mapWords.find(word) != mapWords.end();}
};

#endif
