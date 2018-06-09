#pragma once
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class bad_open_file : public std::exception {
public:
	const char* what() const noexcept {
		return "Blad otwierania pliku!";
	}
};
class bad_load_from_file : public std::exception {
	const char * content;
public:
	const char* what() const noexcept {
		return content;
	}
	bad_load_from_file(const char* con) :content(con) {};
};

#endif // !MYEXCEPTIONS_H
