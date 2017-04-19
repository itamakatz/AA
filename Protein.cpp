#include "Protein.h"

void Protein::add_AA(AA new_AA) {
	AA_chain.push_back(new_AA);
}

Protein::Protein(std::string protein_ID) {
	this->protein_ID = protein_ID;
}



