#include "viterbi.hh"

#include <cstdio>

void Viterbi::viterbi( Inicio &ini, char * word){
    int k;
	double pa[27], sum;
    char maxword[256];
	
	for ( int i = 0; i < 26; i++ )pa[i] = 0;	
    pa[26] = 1;
    
    for ( k = 0; word[k] != '\0'; k++ ){
        for ( int i	= 0; i < 26; i++ ){
            double max = 0;
            for ( int j = 0; j < 26; j++){
                ps[i][j] = pa[i]*ini.transition[i][posMtr(word[k])]*probTecla[posMtr(word[k])][j];
                max = (max < ps[i][j])? ps[i][j]:max;            
            }
            pa[i] = max;
        }
        double max;
        for ( int n = 0, sum = 0; n < 27; n++ ) sum += pa[n];     /*faz a soma para a normalização*/
        for ( int j = 0, max = 0; j < 27; j++ ) {
            pa[j]/=sum; 
            max = (max < pa[j])? pa[j]: max; 
        }
        maxword[k] = Inicio::mapMtr(max);
    }
    maxword[k] = '\0';

    printf("%s\n", maxword);
}
