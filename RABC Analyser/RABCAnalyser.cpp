// RABCAnalyser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "ConsoleColor.h"

using namespace std;

//List of all functions
void analyse_RABC(string);
void updateScreen(string);
void createCSV(void);

//List of Global Variables
int total_rabc_files;
int total_kgs_washed = 0;
string dropped_folder_path;
string time_stamp[1000];
string prg_name[1000];
int kgs_washed[1000];
int RABC_file_number = 1;

int main() {
	int i;
	updateScreen("Heading");
	updateScreen("Rename_Instruction");
	cout << blue << "Enter total number of RABC files to analysis: " << white;
	cin >> total_rabc_files;

	if (!total_rabc_files > 0) updateScreen("File_Number_Incorrect");

	cout << endl << blue << "Drag and Drop the RABC folder here: " << white;
	cin >> dropped_folder_path;
	string temp_file_path1 = "\\RABC (";
	string temp_file_path2 = ").rabc";
	string temp_final_file_path;

	updateScreen("Heading");
	cout << yellow << "Analysing..." << white;

	for (i = 1; i <= total_rabc_files; i++)
	{
		temp_final_file_path = dropped_folder_path + temp_file_path1 + to_string(i) + temp_file_path2;
		analyse_RABC(temp_final_file_path);
		RABC_file_number++;
	}
	updateScreen("Heading");

	for (int k = 1; k <= total_rabc_files; k++)
	{
		total_kgs_washed = total_kgs_washed + kgs_washed[k];
		cout << "At " << blue << time_stamp[k] << white << " program " << yellow << setw(21) << prg_name[k] << white << " washed " << green << setw(3) << kgs_washed[k] << white << " kg of cloth" << endl;
	}

	cout << endl << "Total Washes = " << yellow << total_kgs_washed << white << " kg";
	cout << endl << endl << endl << endl << endl << endl << endl << endl << green << setfill('-') << setw(25) << "-" << "End of Program" << setfill('-') << setw(25) << "-" << white << endl;
	//Ask whether to exit or not
	std::string create_csv;
	do
	{
		std::cout << endl << "Would you like to create csv file? ";
		std::cin >> create_csv;
		if (create_csv == "yes" || create_csv == "y")
		{
			createCSV();
			exit(0);
	
		}
		else if (create_csv == "no" || create_csv == "n")
		{
			exit(0);
		}
	} while (1);
}

void updateScreen(std::string region)
{
	if (region == "Heading")
	{
		system("CLS");
		cout << green << setw(45) << right << "RABC File Analyser for Danube Washer" << white << endl;
	}

	else if (region == "Rename_Instruction")
	{
		cout << endl << "Please follow the following instructions to rename files:" << endl << endl << "1. Open the RABC folder." << endl << "2. Select the first file." << endl << "3. Press Ctrl + A and then F2." << endl << "4. Type RABC and Press Enter." << endl << endl;
	}

	else if (region == "CSV_created")
	{
		cout << blue << "Success and saved on same RABC folder as Report.csv" << white << endl << endl;
	}
	
	else if (region == "File_Number_Incorrect")
	{
		cout << red << "Incorrect Number of RABC files" << white << endl << endl;
		exit(0);
	}
}

void analyse_RABC (string filepath)
{
	string line;
	int lineNumber = 0;
	int i;
	int program_name_length_finder = 1;
	string individual_char[21]; // as max 20 characters allowed on program name
	int int1, int2, int3;
	string colon = ":";
	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 2)
			{
				for (i = 38; i < 175; i++)
						{
							// time and program name
							if (line[i] == 't' && line[i + 1] == '_' && line[i + 2] == 't' && line[i + 3] == 'i' && line[i + 4] == 'm' && line[i + 5] == 'e')
							{
								individual_char[1] = line[i + 8];
								individual_char[2] = line[i + 9];
								individual_char[3] = line[i + 11];
								individual_char[4] = line[i + 12];
								individual_char[5] = line[i + 14];
								individual_char[6] = line[i + 15];
								time_stamp[RABC_file_number] = individual_char[1] + individual_char[2] + colon + individual_char[3] + individual_char[4] + colon + individual_char[5] + individual_char[6];
								
							while (line[i + 32 + program_name_length_finder] != '"') program_name_length_finder++;
								for (int j = 1; j <= program_name_length_finder; j++)
								{
									individual_char[j] = line[i + 31 + j];
									prg_name[RABC_file_number] = prg_name[RABC_file_number] + individual_char[j];
								}
								i = i + 33 + program_name_length_finder; // updated i as loop can skip these values.
							}
							
							// kgs washed
							else if (line[i] == 'w' && line[i + 1] == 'e' && line[i + 2] == 'i' && line[i + 3] == 'g' && line[i + 4] == 'h' && line[i + 5] == 't')
							{
								if (line[i + 10] == '"')
								{
									int1 = line[i + 8] - '0';
									int2 = line[i + 9] - '0';
									kgs_washed[RABC_file_number] = int1 * 10 + int2;
								}
								else 
								{
									int1 = line[i + 8] - '0';
									int2 = line[i + 9] - '0';
									int3 = line[i + 10] - '0';
									kgs_washed[RABC_file_number] = int1 * 100 + int2 * 10 + int3;
								}
							}
					
				}
			}
			else if (lineNumber > 2)
			{
				break;
			}
		}
		myfile.close();
	}
	else
	{
		cout << endl << endl << "Unable to open file on path: " << filepath << endl << endl << red << "Exitting..." << white << endl << endl << endl << endl;
		exit(0);
	}
}

void createCSV(void)
{
	ofstream new_csv_file;
	string csvFileName = "\\Report.csv";
	dropped_folder_path = dropped_folder_path + csvFileName;
	new_csv_file.open(dropped_folder_path);
	new_csv_file << "Time,Program,kgs Washed\n";

	for (int l = 1; l <= total_rabc_files; l++)
	{

		new_csv_file << time_stamp[l] << "," << prg_name[l] << "," << kgs_washed[l] << endl;
	}
	new_csv_file << ",Total," << total_kgs_washed << endl; // Prints the total kg line
	new_csv_file.close();
	updateScreen("CSV_created");
}