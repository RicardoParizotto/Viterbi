/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Cálculo da probabilidade de transição e geração do arquivo de dicionário  *
 * --------------------------------------------------------------------------*/

#include "inicio.hh"

const char * Inicio::DICT_FILE = "dict.txt";
const char * Inicio::TRANSITIONS_FILE = "transitions.txt";

void Inicio::wordCount(char* str)    {
    char word[WORD_LEN];
    char ant = '$';
    int k = 0;
    char * ptr = str;
    sum = 0;

    for(int i = 0; i < 27; i++)
        for(int j = 0; j < 27; j++)
            transition[i][j] = 0;

    while(ptr != NULL && valid(*ptr)) {
        transition[posMtr(ant)][posMtr(*ptr)]+=1.0;
        ant = *ptr;
        sum++;

        if(*ptr != ' ')
            word[k++] = *ptr;
        else if(k) {
            word[k] = '\0';
            if(mapWords.count(word))
                mapWords[word]++;
            else
                mapWords[word] = 1;
            k = 0;
        }

        ptr++;
    }

    for(int i = 0; i < 27; i++)
        for(int j = 0; j < 27; j++)
            transition[i][j] = transition[i][j]/sum;
}

bool Inicio::readFile()    {
    ifstream inputFile;

    char buffer[BUF_LEN];
    try {
        if(loadDict() && loadTransitions())
            return true;

        inputFile.open(fileName, ifstream::in);

        if(inputFile.good()) {
            inputFile.readsome(buffer,BUF_LEN);
            wordCount(buffer);
        }
    }
    catch(exception& e) {
        return false;
    }
    return true;
}

bool Inicio::writeDict()    {
    ofstream fout;
    try {
        fout.open(DICT_FILE,ofstream::out);

        for(map<string,int>::iterator it=mapWords.begin(); it!=mapWords.end(); it++)
            fout << it->first << ' ' << it->second << '\n';

        fout.close();
    }
    catch(exception e)  {
        return false;
    }
    return true;
}

bool Inicio::writeTransitions()   {
    ofstream fout;
    try {
        fout.open(TRANSITIONS_FILE,ofstream::out);

        fout.precision(15);

        for(int i = 0; i < 27; i++)
            for(int j = 0; j < 27; j++)
                fout << mapMtr(i) << ' ' << mapMtr(j) << ' ' << (double)transition[i][j] << '\n';
    }
    catch(exception e)  {
        return false;
    }
    return true;
}

bool Inicio::loadDict() {
    if(!fileExists(DICT_FILE))
        return false;
    ifstream file;
    string word;
    int wordFrequency;
    try {
        file.open(DICT_FILE, ifstream::in);

        while(file.good())  {
            file >> word >> wordFrequency;

            mapWords[word] = wordFrequency;
        }
    } catch(exception e)    {
        return false;
    }
    #ifdef DEBUG2
        for(map<string,int>::iterator it=mapWords.begin(); it!=mapWords.end(); it++)
            cout << it->first << ' ' << it->second << '\n';
    #endif
    return true;
}

bool Inicio::loadTransitions() {
    if(!fileExists(TRANSITIONS_FILE))
        return false;
    ifstream file;
    char ant, next;
    double pTransition;
    try {
        file.open(TRANSITIONS_FILE, ifstream::in);

        while(file.good())  {
            file >> ant >> next >> pTransition;

            transition[posMtr(ant)][posMtr(next)] = pTransition;
        }
    } catch(exception e)    {
        return false;
    }

    return true;
}
