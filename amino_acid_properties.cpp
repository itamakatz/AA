#include "amino_acid_properties.h"

std::map<AA_types, double> AA_frequency;

std::map<AA_types, unsigned long int> AA_to_primes;

void init_AA_frequency(){
	AA_frequency.insert(std::pair<AA_types, double>(A, 7.4));
	AA_frequency.insert(std::pair<AA_types, double>(R, 4.2));
	AA_frequency.insert(std::pair<AA_types, double>(N, 4.4));
	AA_frequency.insert(std::pair<AA_types, double>(D, 5.9));
	AA_frequency.insert(std::pair<AA_types, double>(C, 3.3));
	AA_frequency.insert(std::pair<AA_types, double>(E, 5.8));
	AA_frequency.insert(std::pair<AA_types, double>(Q, 3.7));
	AA_frequency.insert(std::pair<AA_types, double>(G, 7.4));
	AA_frequency.insert(std::pair<AA_types, double>(H, 2.9));
	AA_frequency.insert(std::pair<AA_types, double>(I, 3.8));
	AA_frequency.insert(std::pair<AA_types, double>(L, 7.6));
	AA_frequency.insert(std::pair<AA_types, double>(K, 7.2));
	AA_frequency.insert(std::pair<AA_types, double>(M, 1.8));
	AA_frequency.insert(std::pair<AA_types, double>(F, 4.0));
	AA_frequency.insert(std::pair<AA_types, double>(P, 5.0));
	AA_frequency.insert(std::pair<AA_types, double>(S, 8.1));
	AA_frequency.insert(std::pair<AA_types, double>(T, 6.2));
	AA_frequency.insert(std::pair<AA_types, double>(W, 1.3));
	AA_frequency.insert(std::pair<AA_types, double>(Y, 3.3));
	AA_frequency.insert(std::pair<AA_types, double>(V, 6.8));
}

void set_AA_to_prime(){

	std::map<double, AA_types> AA_frequency_reversed;

	for (std::map<AA_types, double>::iterator it = AA_frequency.begin(); it != AA_frequency.end(); ++it){
		AA_frequency_reversed.insert(std::pair<double, AA_types>(it->second, it->first));
	}

	std::vector<unsigned long int>::iterator prime_it = prime_vector.begin();

	for (std::map<double, AA_types>::iterator it = AA_frequency_reversed.begin(); it != AA_frequency_reversed.end(); ++it, ++prime_it){
		AA_to_primes.insert(std::pair<AA_types, unsigned long int>(it->second, *prime_it));
	}
}

//{{Alanine, Ala, A},
//{Arginine, Arg, R},
//{Asparagine, Asn, N},
//{Aspartate, Asp, D},
//{Aspartate, Asx, B},
//{Cysteine, Cys, C},
//{Glutamate, Glu, E},
//{Glutamine, Gln, Q},
//{Glutamate, Glx, Z},
//{Glycine, Gly, G},
//{Histidine, His, H},
//{Isoleucine, Ile, I},
//{Leucine, Leu, L},
//{Lysine, Lys, K},
//{Methionine, Met, M},
//{Phenylalanine, Phe, F},
//{Proline, Pro, P},
//{Serine, Ser, S},
//{Threonine, Thr, T},
//{Tryptophan, Trp, W},
//{Tyrosine, Tyr, Y},
//{Valine, Val, V}}