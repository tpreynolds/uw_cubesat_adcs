# include "ecos.h"

void callecos(int n, int m, int p, int l, int ncones, double *c, int *Gjc, int *Gir, double *Gpr,
			  double* h, int* q, int* Ajc, int* Air, double *Apr, double *b, double *y) {
	/* Initialize */
	pwork* mywork = ECOS_setup(n, m, p, l, ncones, q, 0, Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);
	/* Solve */
	idxint exitflag = ECOS_solve(mywork);
	/* Extract optimal solution */
	int i;
	// Save optimal decision vector
	for(i=0;i<2;i++) {
		y[i] = mywork->x[i];
	}
	// Save exitflag
	y[2] = exitflag;
	// Save solution time
	y[3] = mywork->info->tsetup + mywork->info->tsolve;
	// Clean up memory
	ECOS_cleanup(mywork, 0);
}






