//
// Created by itamar on 4/17/17.
//

#ifndef PROTEIN_MATCHING_AA_H
#define PROTEIN_MATCHING_AA_H

#include "amino_acid_properties.h"
#include <string>
#include <iostream>
#include <ctype.h>

class AA {
private:
	AA_types aa;
	int phi;
	int psi;

	bool _contains_disulfide = false;
	std::string _disulfide_id;

	AA(){}
public:
	AA(const std::string &aa_str);
	AA(const std::string &aa_str, int phi, int psi);

	bool contains_disulfide();

	static bool check_AA_valid(const std::string &AA_str);
};


#endif //PROTEIN_MATCHING_AA_H
