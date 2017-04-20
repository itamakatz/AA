#include "Protein.h"

void Protein::add_AA(AA new_AA) {
	if(new_AA.contains_disulfide()){
		_disulfide_bridges.push_back(std::make_pair(new_AA, _from_last_disulfide_count));
		_from_last_disulfide_count = 0;
	} else{
		_from_last_disulfide_count++;
	}

	AA_chain.push_back(new_AA);
}

Protein::Protein(std::string protein_ID) {
	this->protein_ID = protein_ID;
}



