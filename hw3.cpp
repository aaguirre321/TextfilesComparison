/*
PIC 10B 
Discussion 2B
Homework 3: Textfiles
Arely Agurire
November 6,2021
*/

#include <iostream>
#include <string>
#include <fstream>
#include "textfile.h"
using namespace std;

bool operator==(Textfile& first, Textfile& second)
//takes in two Textfile objects and compares
{
	long l_1 = first.get_lines();
	long l_2 = second.get_lines();
	if (l_1 == l_2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(Textfile& first, Textfile& second)
// takes in two Textfile objects and compares
{
	long l_1 = first.get_lines();
	long l_2 = second.get_lines();
	if (l_1 > l_2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() 
{	
	string file1_name, file2_name;
	ifstream first,second;
	ofstream out;
	char temp;
	bool valid_1 = false;
	bool valid_2 = false;

	cout << " Enter the name of file 1: ";
	getline(cin, file1_name);
	while(valid_1==false)
	{ 
		first.open(file1_name);
		if (!first.is_open())
		//makes sure file is open and prompts for a new one if file doesn't exist
		{
			cout << " File does not exist. Enter new file 1 name: ";
			getline(cin, file1_name);
		}
		else
		{
			first.close();
			valid_1 = true;
		}
	}

	cout << " Enter the name of file 2: ";
	getline(cin, file2_name);
	while (valid_2 == false)
	{
		second.open(file2_name);
		if (!second.is_open())
		// makes sure file is open and prompts for a new one if it doesn't exist
		{
			cout << " File does not exist. Enter new file 2 name: ";
			getline(cin, file2_name);
		}
		else
		{
			second.close();
			valid_2 = true;
		}
	}

	cout << " Enter any letter to continue... ";
	cin >> temp;
	
	Textfile file1(file1_name);
	Textfile file2(file2_name);
	out.open("Properties.txt");
	// will output all necessary info to Properties.txt file using functions from file1 and file2

	out << " File name: " << file1_name <<endl<< " Number of characters: " << file1.get_characters() <<endl;
	out << " Number of words: " << file1.get_words() <<endl<<endl;
	out << " File name: " << file2_name <<endl<< " Number of characters: " << file2.get_characters() << endl;
	out << " Number of words: " << file2.get_words() << endl<<endl;
	if (file1 == file2)
	// compares two textfile objects for number of lines being equal
	{
		out <<" The files have the same amount of lines." << endl;
	}
	else if (file1 > file2)
	//compares two textfile objects for number of lines being different
	{
		out << " The file named \"" <<file2_name<<"\" has less lines than \""<<file1_name<<"\"." << endl;
	}
	else
	{
		out << " The file named \"" << file1_name << "\" has less lines than \"" << file2_name << "\"." << endl;
	}

	file1.close_file();
	file2.close_file();
	out.close();
	//ensures all files are closed

	return 0;

}