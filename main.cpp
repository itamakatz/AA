#include <string>
#include <iostream>
#include <sstream>
#include <boost/optional.hpp>
#include <gmp.h>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "amino_acid_properties.h"
#include "CSV.h"
#include "Protein.h"
#include "tests.h"

using namespace std;
using namespace cv;

int g_count_proteins = 0;

string g_protein_database_file = "/home/itamar/Documents/AA/Files/database_itamar.txt";

bool g_EXIT_PROGRAM = false;


std::vector<Protein> create_protein_database(std::ifstream &file){
	std::vector<Protein> proteins_vector;

	CSVRow row;
	while(file >> row) {
		g_count_proteins++;
		/**** PARSERING A SINGLE PROTEINS DATA ****/

//		read the line containing the Proteins ID
//		std::string protein_ID(row.get_m_data().at(0)); SOME BUG IN CLION
		std::string protein_ID;
		protein_ID = row.get_m_data().at(0);

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
			string current_AA_str(*AA_it);

			try {
				phi = std::stoi(*phi_it);
				psi = std::stoi(*psi_it);
			}catch (exception e){
				cout << e.what() << endl;
			}

			if(AA::check_AA_valid(current_AA_str)){
				try {
					new_Protein.add_AA(AA(current_AA_str ,phi, psi));
				} catch (std::exception e) {
					std::cout << e.what() << std::endl;
				}
			}
		}

		new_Protein.init_logic();
		proteins_vector.push_back(new_Protein);
	}

	return proteins_vector;
}

boost::optional<std::ifstream> get_user_protein(){
	string input_file_str = "";

	cout << "Please enter an absolute PATH or EXIT to exit the program:\n>";
	getline(cin, input_file_str);

	if(!input_file_str.compare("EXIT")){
		return boost::optional<std::ifstream>{};
	}

	std::ifstream file;

	while(true){

		try{

			file.open(input_file_str, std::ifstream::in);

		}catch(exception e) {

			cout << "You did not enter a correct path. Please try again." << endl << endl;

			cout << "Please enter an absolute PATH or EXIT to exit the program:\n>";
			getline(cin, input_file_str);

			if(!input_file_str.compare("EXIT")){
				return boost::optional<std::ifstream>{};
			}
			continue;
		}
		break;
	}

	cout << "You entered: " << input_file_str << endl << endl;

	return file;
}

int main() {

//	test_all();

	init_AA_properties_all();

	Mat img;
	img = imread("haus.jpg");

	// create UI and show the image
	namedWindow("HarrisCornerDetector", 1);

	imshow("HarrisCornerDetector", img);

	std::ifstream file;

	try{

		file.open(g_protein_database_file, std::ifstream::in);

	}catch(exception e) {

		cout << "The PATH to the database is incorrect. Fix and recompile." << endl << endl;
		return -1;
	}

	std::vector<Protein> all_Proteins = create_protein_database(file);

	unsigned long int max_phi_AA_all = 0;
	unsigned long int max_psi_AA_all = 0;
	Protein arg_max_phi;
	Protein arg_max_psi;

	for (std::vector<Protein>::iterator all_Proteins_it = all_Proteins.begin(); all_Proteins_it != all_Proteins.end(); ++all_Proteins_it){
		if(max_phi_AA_all < all_Proteins_it->max_phi_AA){
			max_phi_AA_all = all_Proteins_it->max_phi_AA;
			arg_max_phi = *all_Proteins_it;
		}

		if(max_psi_AA_all < all_Proteins_it->max_psi_AA){
			max_psi_AA_all = all_Proteins_it->max_psi_AA;
			arg_max_psi = *all_Proteins_it;
		}
	}

	printf("max_phi_AA_all is: %lu ", max_phi_AA_all);
	cout << "for protein %s\n" << arg_max_phi.get_protein_ID() << endl << endl;
	printf("max_psi_AA_all is: %lu ", max_psi_AA_all);
	cout << "for protein %s\n" << arg_max_psi.get_protein_ID() << endl << endl;

	file.close();

	while(true) {
		boost::optional<std::ifstream> input_file = get_user_protein();

		if(!input_file.is_initialized()){
			cout << "Its been a pleasure serving you. Please, come again. " << endl << endl;
			cout << "Bye bye now.. " << endl << endl;
			cout << "I can't belive it, i'm loosing to a rug ;) <3 <3 " << endl << endl;
			break;
		}

		Protein input_Protein = create_protein_database(*input_file).at(0);
	}
	return 0;
}