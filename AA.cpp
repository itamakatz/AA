//
// Created by itamar on 4/17/17.
//

#include "AA.h"

AA::AA(const std::string &aa_str) {
	this->aa = AA_string_to_enum.at(aa_str);
}

AA::AA(const std::string &aa_str, int phi, int psi) {
	if((bool)std::islower(aa_str.at(0))){
		this->aa = AA_types::C;
		_contains_disulfide = true;
		_disulfide_id = aa_str;
	}else {
		this->aa = AA_string_to_enum.at(aa_str);
	}

	this->phi = phi;
	this->psi = psi;
}

bool AA::check_AA_valid(const std::string &AA_str) {
	if(illegal_AA.find(AA_str) != illegal_AA.end()){
		return false;
	}
	else if(AA_str.length() != 1){
		return false;
	}
	return true;
}

bool AA::contains_disulfide() {
	return _contains_disulfide;
}

AA_types AA::get_AA_type() {
	return this->aa;
}

int AA::get_phi() {
	return this->phi;
}

int AA::get_psi() {
	return this->psi;
}
