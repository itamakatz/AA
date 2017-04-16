#include "amino_acids.h"

std::map<AA, double> AA_frequency;

void init_AA_frequency(){
	AA_frequency.insert(std::pair<AA, double>(A, 7.4));
	AA_frequency.insert(std::pair<AA, double>(R, 4.2));
	AA_frequency.insert(std::pair<AA, double>(N, 4.4));
	AA_frequency.insert(std::pair<AA, double>(D, 5.9));
	AA_frequency.insert(std::pair<AA, double>(C, 3.3));
	AA_frequency.insert(std::pair<AA, double>(E, 5.8));
	AA_frequency.insert(std::pair<AA, double>(Q, 3.7));
	AA_frequency.insert(std::pair<AA, double>(G, 7.4));
	AA_frequency.insert(std::pair<AA, double>(H, 2.9));
	AA_frequency.insert(std::pair<AA, double>(I, 3.8));
	AA_frequency.insert(std::pair<AA, double>(L, 7.6));
	AA_frequency.insert(std::pair<AA, double>(K, 7.2));
	AA_frequency.insert(std::pair<AA, double>(M, 1.8));
	AA_frequency.insert(std::pair<AA, double>(F, 4.0));
	AA_frequency.insert(std::pair<AA, double>(P, 5.0));
	AA_frequency.insert(std::pair<AA, double>(S, 8.1));
	AA_frequency.insert(std::pair<AA, double>(T, 6.2));
	AA_frequency.insert(std::pair<AA, double>(W, 1.3));
	AA_frequency.insert(std::pair<AA, double>(Y, 3.3));
	AA_frequency.insert(std::pair<AA, double>(V, 6.8));
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