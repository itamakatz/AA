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

string protein_database_file = "plop.csv";

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
	std::vector<Protein> Proteins_vector;

	std::ifstream file(file_name);

	CSVRow row;
	while(file >> row) {

//		read the line containing the AA chain
		std::vector<std::string> protein_AA_data(row.m_data);

		file >> row;
//		read the line containing the angles of each AA
		std::vector<std::string> protein_angles_data(row.m_data);

//		inserting the chain data into a new Protein
		Protein new_Protein;

		std::vector<std::string>::iterator angles_it = protein_angles_data.begin();

//		ASSUMING PSI IS ON THE LEFT AND PHI ON THE RIGHT OF AN AA
		for (std::vector<std::string>::iterator AA_it = protein_AA_data.begin(); AA_it != protein_AA_data.end(); ++AA_it, ++angles_it){
			int psi = std::stoi(*angles_it);
			++angles_it;
			int phi = std::stoi(*angles_it);
			new_Protein.add_AA(AA(*AA_it ,phi, psi));
		}

		Proteins_vector.push_back(new_Protein);
	}

	return Proteins_vector;
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