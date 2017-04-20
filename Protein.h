#ifndef PROTEIN_MATCHING_PROTEIN_H
#define PROTEIN_MATCHING_PROTEIN_H

#include <vector>
#include <string>
#include "AA.h"

class Protein {
private:

	std::string protein_ID;
	std::vector<AA> AA_chain;

/*	stack implemented by a vector, which contains pairs of the AA that has
	a disulfide bridge and an integer FROM the LAST disulfide bridge*/
	int _from_last_disulfide_count = 0;
	std::vector<std::pair<AA, int>> _disulfide_bridges;

	std::vector<unsigned long int> phi_angles;
	std::vector<unsigned long int> phi_AA;
	std::vector<unsigned long int> psi_angles;
	std::vector<unsigned long int> psi_AA;

	Protein(){}

public:
	Protein(std::string protein_ID);
	void add_AA(AA new_AA);
};


#endif //PROTEIN_MATCHING_PROTEIN_H
