#pragma once
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class bad_open_file : public std::exception {
	const char* what() const noexcept {
		return "Blad otwierania pliku!";
	}
};


#endif // !MYEXCEPTIONS_H
