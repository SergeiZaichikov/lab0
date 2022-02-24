﻿#include "reader.h"

#include <codecvt>

namespace Module1 {

	File::File(std::string name) {

		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		input.open(name);
		input.imbue(utf8_locale);

	}

	int File::open_file() {

		if (!input.is_open()) {

			return Module4::END_PROGRAMM;

		}

	}

	std::string File::getWord() {
		word = L"";
		getline(input, str);

		while ((str[ptr] >= L"a" && str[ptr] <= L"z" ||
			(str[ptr] >= L"A" && str[ptr] <= L"Z") ||
			(str[ptr] >= L"0" && str[ptr] <= L"9") ||
			(str[ptr] >= L"а" && str[ptr] <= L"я") ||
			(str[ptr] >= L"А" && str[ptr] <= L"Я") && ptr <= str.length()) 
		{
			word += str[ptr];
			++ptr;
		}
		++ptr;
		return word;
	}

	void File::count_words() {
		std::string wordptr = "";
		while (!input.eof()) {
			wordptr = getWord();
			if(wordptr.lenght()>0) {
				++mapOfWords[wordptr];
				++count;
				wordptr = "";
			}
		}
	}


	/*void File::count_words() {

		word = L"";


		while (!input.eof()) {

			getline(input, str);

			for (int i = 0; i <= str.length(); ++i) {

				if ((str[i] >= L"a" && str[i] <= L"z" || 
					(str[i] >= L"A" && str[i] <= L"Z")||
					(str[i] >= L"0" && str[i] <= L"9") ||
					(str[i] >= L"а" && str[i] <= L"я") ||
					(str[i] >= L"А" && str[i] <= L"Я")) 
				{
					word += str[i];

				}

				else {

					++count;

					if (word.length() > 0) {

						++mapOfWords[word];

					}

					word = L"";

				}


			}

		}

	}*/

	std::map <std::wstring, int> File::Getmap() {
		return mapOfWords;

	}

	int File::Getcount() {

		return count;

	}

	File::~File() {

		input.close();

	}

}