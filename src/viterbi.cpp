/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Implementação do algoritmo de Viterbi                                     *
 * --------------------------------------------------------------------------*/


#include "viterbi.hh"
#include <cstdio>

char lcase(char a) {
    if (a >= 'A' && a <= 'Z')
        return a+32;
    return a;
}

void Viterbi::viterbi( Inicio &ini, char * word){
    int k;
    double pa[27];
    char maxword[256];
    int mex;

    for ( k = 0; k < 27; k++ ) pa[k] = ini.transition[26][k];

    for ( k = 0; word[k] != '\0'; k++ ){
        char c = lcase(word[k]);
        for ( int i = 0; i < 27; i++ ){
            double max = 0;
            for ( int j = 0; j < 27; j++){
                ps[i][j] = pa[posMtr(c)]*ini.transition[posMtr(c)][i]*probTecla[i][posMtr(c)];
                max = (max < ps[i][j])? ps[i][j]:max;            
            }
            pa[i] = max;
        }

        double sum = 0.;
        mex = 0;
        for ( int n = 0; n < 27; n++ ) sum += pa[n];     //faz a soma para a normalização
        for ( int j = 0; j < 27; j++ ) {
            pa[j]/=sum;                                 //aqui está certo agora. Não precisa somar com EPS.
            mex = (pa[mex] < pa[j])? j : mex;          //seleciona o caracter que tem o máximo. Aqui que tem que mudar. Não pegar o máximo mais.
        }
        maxword[k] = Inicio::mapMtr(mex);               //Converte o máximo para um caracter e concatena na palavra
    }
    maxword[k] = '\0';

    printf("%s\n", maxword);
}


