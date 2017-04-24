#ifndef __HOST_H__
#define __HOST_H__

#include <string>
#include <iostream>

using namespace std;

class Host{
	private:
		string site;
		string ip;
		Host* next;
	public:
		Host(string site, string ip);
		Host();
		~Host();
		string getSite();
		void setSite(string Site);
		string getIp();
		void setIp(string Ip);
		Host* getNext();
		void setNext(Host* host);
};

#endif