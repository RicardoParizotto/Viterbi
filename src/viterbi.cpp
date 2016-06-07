#include "viterbi.hh"

#include <cstdio>


void Viterbi::viterbi( Inicio &ini, char * word){
    int k;
	double pa[27];
    char maxword[256];
    int mex;
	
	for ( int i = 0; i < 27; i++ ) pa[i] = ini.transition[26][i];	
    
    for ( k = 0; word[k] != '\0'; k++ ){
        for ( int i	= 0; i < 27; i++ ){
            double max = 0.;
            for ( int j = 0; j < 27; j++){
                ps[i][j] = pa[i]*ini.transition[i][posMtr(word[k])]*probTecla[posMtr(word[k])][j];
                max = (max < ps[i][j])? ps[i][j]:max;            
            }
            pa[i] = max;
        }

        double sum = 0.;
        mex = 0;
        for ( int n = 0; n < 27; n++ ) sum += pa[n];     /*faz a soma para a normalização*/
        for ( int j = 0; j < 27; j++ ) {
            pa[j]/=sum;                                 /*aqui está certo agora. Não precisa somar com EPS.*/
            mex = (pa[mex] < pa[j])? j : mex;          //seleciona o caracter que tem o máximo. Aqui que tem que mudar. Não pegar o máximo mais.
        }
        maxword[k] = Inicio::mapMtr(mex);               //Converte o máximo para um caracter e concatena na palavra
    }
    maxword[k] = '\0';

    printf("%s\n", maxword);
}
