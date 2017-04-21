#ifndef PROTEIN_MATCHING_AMINO_ACIDS_H
#define PROTEIN_MATCHING_AMINO_ACIDS_H

#include "primes.h"
#include <map>
#include <set>
#include <string>

enum AA_types {
	A = 2,
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
	V,
	WILD_CARD /* can be paird with any AA */};

extern std::set<std::string> illegal_AA;

extern std::map<AA_types, double> AA_frequency;

extern std::map<AA_types, unsigned long int> AA_to_primes;

extern std::map<std::string, AA_types> AA_string_to_enum;

void init_AA_properties_all();

void init_AA_frequency();

void set_AA_to_prime();

void init_AA_string_to_enum();




#endif //PROTEIN_MATCHING_AMINO_ACIDS_H
