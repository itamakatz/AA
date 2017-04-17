//
// Created by itamar on 4/17/17.
//

#include "AA.h"

AA::AA(std::string aa_str) {
	this->aa = AA_string_to_enum.at(aa_str);
}

AA::AA(std::string aa_str, int phi, int psi) {
	this->aa = AA_string_to_enum.at(aa_str);
	this->phi = phi;
	this->psi = psi;
}

void AA::set_AA(AA_types aa) {
	this->aa = aa;
}

void AA::set_phi(int phi) {
	this->phi = phi;
}

void AA::set_psi(int psi) {
	this->psi = psi;
}









