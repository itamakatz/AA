#ifndef PROTEIN_MATCHING_AMINO_ACIDS_H
#define PROTEIN_MATCHING_AMINO_ACIDS_H

#include "primes.h"
#include <map>

enum AA_types {
	A = 1,
	R,
	N,
	D,
	C,
	E,
	Q,
	G,
	H,
	I,
	L,
	K,
	M,
	F,
	P,
	S,
	T,
	W,
	Y,
	V};

extern std::map<AA_types, double> AA_frequency;

extern std::map<AA_types, unsigned long int> AA_to_primes;

void init_AA_frequency();

void set_AA_to_prime();



#endif //PROTEIN_MATCHING_AMINO_ACIDS_H
