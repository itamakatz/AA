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

void Protein::init_logic() {
	for (std::vector<AA>::iterator AA_chain_it = AA_chain.begin(); AA_chain_it != AA_chain.end(); ++AA_chain_it){

		//	phi_angles;
		if(!phi_AA.emplace(AA_chain_it->get_phi(), AA_to_primes.at(AA_chain_it->get_AA_type())).second){
			phi_AA.at(AA_chain_it->get_phi()) *= AA_to_primes.at(AA_chain_it->get_AA_type());
			phi_AA_factors.at(AA_chain_it->get_phi()).push_back(AA_chain_it->get_AA_type());
		} else{
//			phi_AA_factors.emplace(AA_chain_it->get_phi()), std::vector<unsigned long int>();
			phi_AA_factors[AA_chain_it->get_phi()].push_back(AA_chain_it->get_AA_type());
		}

		if(max_phi_AA < phi_AA.at(AA_chain_it->get_phi())){
			max_phi_AA = phi_AA.at(AA_chain_it->get_phi());
		}

		//  psi_angles;
		if(!psi_AA.emplace(AA_chain_it->get_psi(), AA_to_primes.at(AA_chain_it->get_AA_type())).second){
			psi_AA.at(AA_chain_it->get_psi()) *= AA_to_primes.at(AA_chain_it->get_AA_type());
			psi_AA_factors.at(AA_chain_it->get_psi()).push_back(AA_chain_it->get_AA_type());
		} else{
//			psi_AA_factors.emplace(AA_chain_it->get_psi()), std::vector<unsigned long int>();
			psi_AA_factors[AA_chain_it->get_psi()].push_back(AA_chain_it->get_AA_type());
		}
		if(max_psi_AA < psi_AA.at(AA_chain_it->get_psi())){
			max_psi_AA = psi_AA.at(AA_chain_it->get_psi());
		}

	}
}

std::string Protein::get_protein_ID() {
	return this->protein_ID;
}



