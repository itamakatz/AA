#ifndef PROTEIN_MATCHING_PROTEIN_H
#define PROTEIN_MATCHING_PROTEIN_H

#include <vector>
#include <string>
#include "AA.h"

#define MIN_ANGLE_VAL -180
#define MAX_ANGLE_VAL 180

class Protein {
private:

	std::string protein_ID;
	std::vector<AA> AA_chain;

/*	stack implemented by a vector, which contains pairs of the AA that has
	a disulfide bridge and an integer FROM the LAST disulfide bridge*/
	int _from_last_disulfide_count = 0;
	std::vector<std::pair<AA, int>> _disulfide_bridges;

	std::map<int, unsigned long int> phi_angles;
	std::map<int, unsigned long int> phi_AA;
	std::map<int, std::vector<unsigned long int>> phi_AA_factors;

	std::map<int, unsigned long int> psi_angles;
	std::map<int, unsigned long int> psi_AA;
	std::map<int, std::vector<unsigned long int>> psi_AA_factors;

public:

	unsigned long int max_phi_AA = 0;
	unsigned long int max_psi_AA = 0;

	Protein(std::string protein_ID);
	Protein(){}

	void add_AA(AA new_AA);

	void init_logic();

	std::string get_protein_ID();
};


#endif //PROTEIN_MATCHING_PROTEIN_H
