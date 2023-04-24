/*
PIC 10B
Discussion 2B
Homework 3: Textfiles
Arely Agurire
November 6,2021
*/

#ifndef textfile_h
#define textfile_h
#include <iostream>
#include <fstream>

class Textfile
{	public:
	Textfile(std::string file);
	long get_characters();
	long get_words();
	long get_lines();
	void close_file();
	friend bool operator> ( Textfile& first,  Textfile& second);
	friend bool operator==(Textfile& first, Textfile& second);

	private:
		std::string file;
		long file_length = 0;
		std::ifstream in;
		std::ofstream out;
		std::string unused_s;
		std::string unused_l;
		long words = 0;
		long characters = 0;
		int lines = 0;
		

};

#endif

