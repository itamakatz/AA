#ifndef PROTEIN_MATCHING_AMINO_ACIDS_H
#define PROTEIN_MATCHING_AMINO_ACIDS_H

#include <map>

enum AA {
	A,
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

extern std::map<AA, double> AA_frequency;

void init_AA_frequency();


#endif //PROTEIN_MATCHING_AMINO_ACIDS_H
