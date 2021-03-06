#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int N, int K, int* s) {

	// printf("N=%d, K=%d\n", N, K);

	int meglio = 0;

	int somma = 0;
	int cont = 0;	// escluso
	int zeri = 0;
	while ( ( cont < N-1 ) && ( somma + s[cont] <= K ) ) {
		somma += s[cont];
		if ( s[cont] == 0 ) zeri++;
		cont++;
	}

	meglio = zeri;

	int dcont = N-1;	// escluso

	somma = 0;
	zeri = 0;

	while ( ( dcont >= 0 ) && ( somma + s[dcont] <= K ) ) {
		somma += s[dcont];
		if ( s[dcont] == 0 ) zeri++;
		dcont--;
	}

	meglio = max( meglio, zeri );

	return meglio;
}

