#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <ctype.h>

namespace Module1 {

	class File {
	private:
		std::wifstream input;
		std::wstring str;
		std::string name;
		std::wstring word;
		std::map <std::wstring, int> mapOfWords;
		int count;
		int ptr;
	public:
		int open_file();
		File(std::string name);
		~File();
		std::map <std::wstring, int> Getmap();
		void count_words();
		void getWord();
		int Getcount();
	};
}