/*********************************************
THINGS TO IMPROVE / RESOLVE
1. Power Faiure error adds extra weight.
2. Skips the file with error, meanwhile prints the error also for easier service
3. Remove overwriting of Report.csv every time csv being created.
****************************************************/

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
string time_stamp[1000];
string date_stamp[1000];
string prg_name[1000];
int kgs_washed[1000];
int RABC_file_number = 1;
char any_key_halt;

int main() 
{
	updateScreen("Heading");
	cout << yellow << "Analysing..." << white;
	WIN32_FIND_DATA search_data;
	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));
	HANDLE handle = FindFirstFile("./RABC/*.RABC", &search_data);
	while (handle != INVALID_HANDLE_VALUE)
	{
		analyse_RABC(search_data.cFileName);
		RABC_file_number++;
		if (FindNextFile(handle, &search_data) == FALSE)
		break;
	}
	FindClose(handle);
	total_rabc_files = RABC_file_number - 1;
	updateScreen("Heading");

	for (int k = 1; k <= total_rabc_files; k++)
	{
		total_kgs_washed = total_kgs_washed + kgs_washed[k];
		cout << "On " << date_stamp[k] << " at " << blue << time_stamp[k] << white << " program " << yellow << setw(21) << prg_name[k] << white << " washed " << green << setw(3) << kgs_washed[k] << white << " kg of cloth" << endl;
	}
	// Making sure total kgs washed is not 0;
	if (total_kgs_washed == 0) updateScreen("ZeroKGwash_Error");

	cout << endl << "Total Washes = " << yellow << total_kgs_washed << white << " kg";
	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	//Ask whether to exit or not
	std::string create_csv;
	do
	{
		std::cout << endl << "Would you like to create csv file? ";
		std::cin >> create_csv;
		if (create_csv == "yes" || create_csv == "y")
		{
			createCSV();
			break;
	
		}
		else if (create_csv == "no" || create_csv == "n")
		{
			break;
		}
	} while (1);

	cout << endl << green << setfill('-') << setw(25) << "-" << "End of Program" << setfill('-') << setw(25) << "-" << endl << endl << red << "Press any key and Enter to Exit..." << white << endl;
	cin >> any_key_halt;
	return (0);
}

void updateScreen(std::string region)
{
	if (region == "Heading")
	{
		system("CLS");
		cout << green << setw(55) << right << "RABC File Analyser for Danube Washer v1.3" << white << endl;
	}


	else if (region == "CSV_created")
	{
		cout << blue << "Success and saved near same RABC folder as Report.csv" << white << endl << endl;
	}
	
	else if (region == "ZeroKGwash_Error")
	{
		cout << endl << "This file should be along with RABC folder and make sure the RABC folder is not empty!" << endl << endl << red << "Press any key and Enter to Exit..." << white << endl;
		cin >> any_key_halt;
		exit(0);
	}

	else
	{
		cout << endl << endl << green << "OMG! How come you reach here o.O" << endl << "Little buggy needs to be renamed ;)" << white << endl;
		cin >> any_key_halt;
		exit(0);
	}
}

void analyse_RABC (string filepath)
{
	string line;
	int lineNumber = 0;
	int i;
	int program_name_length_finder = 0;
	string individual_char[21]; // as max 20 characters allowed on program name
	int int1, int2, int3;
	string colon = "./RABC/";  //Minimized use of extra string
	filepath = colon + filepath;
	colon = ":";
	string slash = "/";
	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 2)
			{
				for (i = 19; i < 175; i++)
						{
							if (line[i] == 'd' && line[i + 1] == 'a' && line[i + 2] == 't' && line[i + 3] == 'e')
							{
								//date
								individual_char[1] = line[i + 6];
								individual_char[2] = line[i + 7];
								individual_char[3] = line[i + 8];
								individual_char[4] = line[i + 9];
								individual_char[5] = line[i + 11];
								individual_char[6] = line[i + 12];
								individual_char[7] = line[i + 14];
								individual_char[8] = line[i + 15];
								date_stamp[RABC_file_number] = individual_char[1] + individual_char[2] + individual_char[3] + individual_char[4] + slash + individual_char[5] + individual_char[6] + slash + individual_char[7] + individual_char[8];

								//time
								individual_char[9] = line[i + 30];
								individual_char[10] = line[i + 31];
								individual_char[11] = line[i + 33];
								individual_char[12] = line[i + 34];
								individual_char[13] = line[i + 36];
								individual_char[14] = line[i + 37];
								time_stamp[RABC_file_number] = individual_char[9] + individual_char[10] + colon + individual_char[11] + individual_char[12] + colon + individual_char[13] + individual_char[14];
								
								// program name
							while (line[i + 54 + program_name_length_finder] != '"') program_name_length_finder++;
								for (int j = 1; j <= program_name_length_finder; j++)
								{
									individual_char[j] = line[i + 53 + j];
									prg_name[RABC_file_number] = prg_name[RABC_file_number] + individual_char[j];
								}
								i = i + 55 + program_name_length_finder; // updated i as loop can skip these values.
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
		cout << endl << endl << "Unable to open file on path: " << filepath << endl << endl << red << "Press any key and Enter to Exit..." << white << endl << endl << endl << endl;
		cin >> any_key_halt;
		exit(0);
	}
}

void createCSV(void)
{
	ofstream new_csv_file;
	new_csv_file.open("Report.csv");
	new_csv_file << "Date,Time,Program,kgs Washed\n";

	for (int l = 1; l <= total_rabc_files; l++)
	{

		new_csv_file << date_stamp[l] << "," << time_stamp[l] << "," << prg_name[l] << "," << kgs_washed[l] << endl;
	}
	new_csv_file << endl << ",,Total," << total_kgs_washed << endl; // Prints the total kg line
	new_csv_file.close();
	updateScreen("CSV_created");
}
