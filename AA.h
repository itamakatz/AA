//
// Created by itamar on 4/17/17.
//

#ifndef PROTEIN_MATCHING_AA_H
#define PROTEIN_MATCHING_AA_H

#include "amino_acid_properties.h"
#include <string>

class AA {
private:
	AA_types aa;
	int phi;
	int psi;

	AA(){}
public:
	AA(std::string aa_str);
	AA(std::string aa_str, int phi, int psi);
	void set_AA(AA_types aa);
	void set_phi(int phi);
	void set_psi(int psi);
};


#endif //PROTEIN_MATCHING_AA_H
