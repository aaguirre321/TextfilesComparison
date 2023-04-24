/*
PIC 10B
Discussion 2B
Homework 3: Textfiles
Arely Agurire
November 6,2021
*/

#include "textfile.h"
#include<string>


Textfile::Textfile(std::string file_name) : file(file_name) 
//opens file with user input file name
{
	in.open(file);
}
long Textfile::get_characters()
{
	characters = 0;
	while (std::getline(in, unused_s))
	{
		characters = characters + unused_s.length();
		//gets total characters by adding length of strings
	}
	in.clear();
	in.seekg(std::ios::beg);
	//points to beginning of file once all characters have been counted
	return characters;
}
long Textfile::get_lines()
{
	lines = 0;
	while (std::getline(in, unused_l))
	{
		lines++;
	}
	in.clear();
	in.seekg(std::ios::beg);
	//points to beginning of file once all lines have been counted
	return lines;
}
long Textfile::get_words()
{
	words = 0;
	while (in>>unused_s)
	//gets one word at a time
	{
		words++;
	}
	in.clear();
	in.seekg(std::ios::beg);
	//points to beginning of file once all words have been counted
	return words;
}
void Textfile::close_file()
{
	in.close();
}
