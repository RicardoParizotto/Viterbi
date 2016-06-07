#include <iostream>
#include "inicio.hh"
#include "viterbi.hh"
using namespace std;

typedef map<string, int>::iterator mit;

int distance(const std::string &s1, const std::string &s2) {
    const int m(s1.size());
    const int n(s2.size());

    if (abs(m - n) > 5) return 100;
 
    if( m==0 ) return n;
    if( n==0 ) return m;
 
    int *costs = new int[n + 1];
 
    for( int k=0; k<=n; k++ ) costs[k] = k;
 
    int i = 0;
    for ( std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i ) {
        costs[0] = i+1;
        int corner = i;
 
        int j = 0;
        for ( std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j ) {
            int upper = costs[j+1];
            if ( *it1 == *it2 ) {
                costs[j+1] = corner;
            } else {
                int t(upper<corner?upper:corner);
                costs[j+1] = (costs[j]<t?costs[j]:t)+1;
            }
 
            corner = upper;
        }
    }
 
    int result = costs[n];
    delete [] costs;
 
    return result;
}


void menorDistancia(Inicio &ini, char *word) {
    int min = 100;
    mit menor;
    for (mit i = ini.mapWords.begin(); i != ini.mapWords.end(); i++) {
        int d = distance(word, i->first);
        if (d < min) {
            min = d;
            menor = i;
        }
    }

    cout << menor->first + " >> menor distancia " + "\n";

    Viterbi b;
    char *c = b.viterbi(ini, word);

    for (mit i = ini.mapWords.begin(); i != ini.mapWords.end(); i++) {
        int d = distance(c, i->first);
        if (d < min) {
            min = d;
            menor = i;
        }
    }

    cout << menor->first + " >> menor distancia c/ viterbi " + "\n";
}


void palavra(Inicio &ini, char * word) {
    printf("Entrada: %s\n---------\n", word);
    if (ini.dic(word)) {
        printf("%s >> existe no dicionário\n", word);
    } else {
        Viterbi v;
        printf("%s >> Viterbi\n", v.viterbi(ini, word));

        menorDistancia(ini, word);
    }

    printf("\n");
}

int main(int argc, char ** argv)  {
    Inicio teste("input/steve_jobs.txt");
    
    teste.loadDict();

    teste.readFile();
    teste.writeDict();
    teste.writeTransitions();

    for(int i = 1; i < argc; i++)    {
        palavra(teste, argv[i]);
    }
    return 0;
}
