#include <string>
#include <iostream>
#include <sstream>

#include "primes.h"
#include "lcs.h"
#include "gcd.h"
#include "amino_acid_properties.h"
#include "CSV.h"
#include "Protein.h"

using namespace std;

int count_proteins = 0;

string protein_database_file = "/home/itamar/Documents/AA/Files/database_itamar.txt";

void test_prime_factors(){
	//	Finding the prime factors of a number

	printf("Finding the prime factors of a number\n");

	unsigned long int prime_product = 1;

	unsigned long int six_primes[] = {100, 199, 355, 666, 786};
	for (int i = 0; i < 5; ++i) {
		prime_product *= prime_vector.at(six_primes[i]);
		printf("Real prime factor is: %lu\n", prime_vector.at(six_primes[i]));
	}

	printf("The prime factors of %lu are:\n", prime_product);

	primeFactors(prime_product);

	int count = 0;
	int power_base = 3;
	unsigned long int power = 1;
	unsigned long int last_power = 1;
	while(power < prime_product){
		count++;
		last_power = power;
		power *= power_base;
	}
	printf("\nNumber of powers of %d is: %d\n", power_base, count);
	printf("%d power %d is %lu\n", power_base, count, last_power);
	printf("%d power %d + 1 is %lu\n", power_base, count, power);
}

void test_gcd(){
	//	running GCD non recursion method

	printf("\nrunning GCD non recursion method\n");

	size_t a,b,c;
	a = 299792458;
	b = 6447287;
	c = 256964964;

	printf("a=%lu, b=%lu, c=%lu\n", a,b,c);

	printf("gcd(a,b) = gcd(%lu ,%lu) = %lu\n", a, b, gcd(a,b));
}

void test_lcs(){
	//	running LCS Dynamic Programing

	printf("\nrunning LCS Dynamic Programing\n");

	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	size_t m = strlen(X);
	size_t n = strlen(Y);

	printf("Length of LCS is %lu\n", lcs( X, Y, m, n));
}

void test_all(){

	test_prime_factors();
	test_gcd();
	test_lcs();
}

std::vector<Protein> create_protein_database(string file_name){
	std::vector<Protein> proteins_vector;

	std::ifstream file(file_name);

	CSVRow row;
	while(file >> row) {
		count_proteins++;
		/**** PARSERING A SINGLE PROTEINS DATA ****/

//		read the line containing the Proteins ID
		std::string protein_ID(row.get_m_data().at(0));

		file >> row;
		if(row.get_m_data().at(0) == "") {
			while (true) {

				//		    if the protein has no data, ignore it. TODO NEED TO CHECK WHAT EXACTLY TO DO
				while (row.get_m_data().at(0) == "") {
					file >> row;
				}

				//			check whether this new protein has data
				protein_ID = row.get_m_data().at(0);
				file >> row;
				if (row.get_m_data().at(0) != "") {
					break;
				}
			}
		}

//		read the line containing the AA chain
		std::vector<std::string> protein_AA_sequence(row.get_m_data());
		protein_AA_sequence.pop_back();

		file >> row;
//		read the line containing the angles of each AA
		std::vector<std::string> protein_PHI_sequence(row.get_m_data());
		protein_PHI_sequence.pop_back();

		file >> row;
//		read the line containing the angles of each AA
		std::vector<std::string> protein_PSI_sequence(row.get_m_data());
		protein_PSI_sequence.pop_back();

		/**** ADDING THE PROTEINS DATA TO THE PROTEINS VECTOR ****/

		Protein new_Protein(protein_ID);

		std::vector<std::string>::iterator phi_it = protein_PHI_sequence.begin();
		std::vector<std::string>::iterator psi_it = protein_PSI_sequence.begin();

		for (std::vector<std::string>::iterator AA_it = protein_AA_sequence.begin(); AA_it != protein_AA_sequence.end();
		     ++AA_it, ++phi_it, ++psi_it){

			int phi;
			int psi;

//			for debugging purposes i define here the current AA
			string current_AA(*AA_it);

			try {
				phi = std::stoi(*phi_it);
				psi = std::stoi(*psi_it);
			}catch (exception e){
				cout << e.what() << endl;
			}

			try {
				new_Protein.add_AA(AA(*AA_it ,phi, psi));
			}catch (std::exception e){
				std::cout << e.what() << std::endl;
			}
		}

		proteins_vector.push_back(new_Protein);
	}

	return proteins_vector;
}

string get_user_protein(){
	string input_prtotein_file = "";

	// How to get a string/sentence with spaces
	cout << "Please enter a valid sentence (with spaces):\n>";
	getline(cin, input_prtotein_file);
	cout << "You entered: " << input_prtotein_file << endl << endl;

	return input_prtotein_file;
}

int main() {

//	test_all();

	init_AA_properties_all();

	std::vector<Protein> all_Proteins = create_protein_database(protein_database_file);

	string input_protein_file = get_user_protein();

	Protein input_Protein = create_protein_database(input_protein_file).at(0);

	return 0;
}