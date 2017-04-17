#include <iostream>

#include "primes.h"
#include "lcs.h"
#include "gcd.h"
#include "amino_acid_properties.h"

using namespace std;

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

int main() {
//	test_all();
	init_AA_frequency();

	double sum = 0;
	for (std::map<AA_types, double>::iterator it = AA_frequency.begin(); it != AA_frequency.end(); ++it){
		sum += it->second;
	}
	cout << sum;

	return 0;
}