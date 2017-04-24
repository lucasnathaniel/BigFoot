#include "host.h"

Host::~Host(){

}

Host::Host(string site, string ip){
	this->setSite(site);
	this->setIp(ip);
	this->setNext(NULL);
}

Host::Host(){
	this->setNext(NULL);
}

string Host::getSite(){
	return site;
}

void Host::setSite(string Site){
	this->site = Site;
}

string Host::getIp(){
	return ip;
}

void Host::setIp(string Ip){
	this->ip = Ip;
}

Host* Host::getNext(){
    return this->next;
}

void Host::setNext(Host* host){
    this->next = host;
}