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
int file_kgs(string);
void updateScreen(string);

//List of Global Variables
int total_rabc_files;
int i;
int total_kgs_washed = 0;

int main() {
	updateScreen("Welcome");
	updateScreen("Rename_Instruction");
	cout << blue << "Enter total number of RABC files to analysis: " << white;
	cin >> total_rabc_files;

	if (!total_rabc_files > 0) updateScreen("File_Number_Incorrect");

	cout << endl << blue << "Drag and Drop the RABC folder here: " << white;
	string temp_file_path0;
	cin >> temp_file_path0;
	string temp_file_path1 = "\\RABC (";
	string temp_file_path2 = ").rabc";
	string temp_final_file_path;

	updateScreen("Welcome");
	cout << yellow << "Analysing..." << white;

	for (i = 1; i <= total_rabc_files; i++)
	{
		temp_final_file_path = temp_file_path0 + temp_file_path1 + to_string(i) + temp_file_path2;
		total_kgs_washed = total_kgs_washed + file_kgs(temp_final_file_path);
	}
	updateScreen("Welcome");
	cout << endl << "Total kgs Washer = " << yellow << total_kgs_washed << white;

	std::cout << endl << endl << endl << endl << endl << endl << endl << endl << green << setfill('-') << setw(25) << "-" << "End of Program" << setfill('-') << setw(25) << "-" << white << endl;
	//Ask whether to exit or not
	std::string any_key_to_exit;
	do
	{
		std::cout << endl << "Would you like to exit? ";
		std::cin >> any_key_to_exit;
		if (any_key_to_exit == "yes" || any_key_to_exit == "y") exit(0);
	} while (1);
}

void updateScreen(std::string region)
{
	if (region == "Welcome")
	{
		system("CLS");
		cout << green << setw(45) << right << "RABC File Analyser for Danube Washer" << white << endl;
	}


	else if (region == "Rename_Instruction")
	{
		cout << endl << "Please follow the following instructions to rename files:" << endl << endl << "1. Open the RABC folder." << endl << "2. Select the first file." << endl << "3. Press Ctrl + A and then F2." << endl << "4. Type RABC and Press Enter." << endl << endl;
	}

	else if (region == "File_Number_Incorrect")
	{
		cout << red << "Incorrect Number of RABC files" << white << endl << endl;
		exit(0);
	}
}

int file_kgs(string filepath)
{
	string line;
	int lineNumber = 0;
	int i;
	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 2)
			{
				for (i = 75; i < 175; i++)
				{
					if (line[i] == 'w' && line[i + 1] == 'e' && line[i + 2] == 'i' && line[i + 3] == 'g' && line[i + 4] == 'h' && line[i + 5] == 't')
					{
						if (line[i + 10] == '"') return ((line[i + 8] - '0') * 10 + (line[i + 9] - '0'));
						else return ((line[i + 8] - '0') * 100 + (line[i + 9] - '0') * 10 + (line[i + 10] - '0'));
					}
				}
			}
			else if (lineNumber > 2) break;
		}
		myfile.close();
	}
	else
	{
		cout << endl << endl << "Unable to open file" << endl << red << "Exitting..." << white << endl << endl << endl << endl;
		exit(0);
	}
}
