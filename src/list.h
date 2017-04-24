#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
#include "host.h"
#include <string>

using namespace std;

class Lista{
	private:
		int quantity;
		Host* first;
	public:
		Lista();
    	~Lista();
    	Host* getFirst();
    	void insertBegin(string site, string ip);
    	void insertEnd(string site, string ip);
    	void printSequence2();
};

#endif