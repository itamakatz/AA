#include "lcs.h"

/* Dynamic Programming C/C++ implementation of LCS problem */

/* Utility function to get max of 2 integers */
size_t max(size_t a, size_t b)
{
	return (a > b)? a : b;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
size_t lcs(char *X, char *Y, size_t m, size_t n)
{
	size_t L[m+1][n+1];
	size_t i, j;

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	   that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;

			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return L[m][n];
}
