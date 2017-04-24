#include "list.h"

Lista::Lista(){
    first = NULL;
    this->quantity = 0;
}

Lista::~Lista(){

}

Host* Lista::getFirst(){
    return first;
}

void Lista::insertBegin(string site, string ip){
    Host* novo = new Host(site, ip);
    novo->setNext(first);
    first = novo;
    this->quantity++;
}

void Lista::insertEnd(string site, string ip){
    
    if(first == NULL){
        insertBegin(site, ip);
        return;
    }
   
    Host* busca = first;

    while(busca != NULL){
        if(busca->getIp() == ip){
            return;
        }
        busca = busca->getNext();
    }

    Host* novo = new Host(site, ip);
    Host* percorre = first;
    
    while(percorre->getNext() != NULL){
        percorre = percorre->getNext();
    }
    percorre->setNext(novo);
    this->quantity++;
}

void Lista::printSequence2(){
    Host *percorre = first;
    cout << "Não repetidos:" << endl;
    int i = 1;
    
    while(percorre != NULL){
        cout << i << ": " << percorre->getIp() << endl;
        i++;
        percorre = percorre->getNext();
    }
}