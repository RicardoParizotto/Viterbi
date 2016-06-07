/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto                                          *
 * --------------------------------------------------------------------------*
 * Cálculo de distância de edição de palavras                                *
 * --------------------------------------------------------------------------*/

/*
Adaptado de:
	Compute Levenshtein Distance
	Martin Ettl, 2012-10-05
*/

#include <string>
#include <iostream>
using namespace std;
 
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