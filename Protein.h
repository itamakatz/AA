#ifndef PROTEIN_MATCHING_PROTEIN_H
#define PROTEIN_MATCHING_PROTEIN_H

#include <vector>
#include "AA.h"

class Protein {
private:

	std::vector<AA> AA_chain;

	std::vector<unsigned long int> phi_angles;
	std::vector<unsigned long int> phi_AA;
	std::vector<unsigned long int> psi_angles;
	std::vector<unsigned long int> psi_AA;

public:
	void add_AA(AA new_AA);
};


#endif //PROTEIN_MATCHING_PROTEIN_H
