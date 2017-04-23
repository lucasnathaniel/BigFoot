#include "main.h"

int main(int argc, const char * argv[]){
	
	system("clear");
	cout << "-------------------------------------------------------------------------            " << endl;
	cout << "88888888ba   88               88888888888   FootPrint Tool v0.1                      " << endl;
	cout << "88      \"8b  \"\"               88                                  ,d              " << endl;
	cout << "88      ,8P                   88                                  88                 " << endl;
	cout << "88aaaaaa8P'  88   ,adPPYb,d8  88aaaaa   ,adPPYba,    ,adPPYba,  MM88MMM              " << endl;
	cout << "88\"\"\"\"\"\"8b,  88  a8\"    `Y88  88\"\"\"\"\"  a8\"     \"8a  a8\"     \"8a   88 " << endl;
	cout << "88      `8b  88  8b       88  88       8b       d8  8b       d8   88                 " << endl;
	cout << "88      a8P  88  \"8a,   ,d88  88       \"8a,   ,a8\"  \"8a,   ,a8\"   88,           " << endl;
	cout << "88888888P\"   88   `\"YbbdP\"Y8  88        `\"YbbdP\"'    `\"YbbdP\"'    \"Y888      " << endl;
	cout << "                  aa,    ,88                                                         " << endl;
	cout << "                   \"Y8bbdP\"                 By: Lucas Nathaniel                    " << endl;
	cout << "-------------------------------------------------------------------------            " << endl;
	
	if(argc < 2 || argc > 3){
		cout << "Use: ./bin/BigFoot site.com (Opcoes)" << endl;
		cout << "Options:" << endl;
		cout << "  [+] Output:  -o" << endl;
		cout << "Exemple: ./bin/BigFoot google.com -o" << endl;
		return 0;
	}
		bool bool_output = false;
		if(argc > 2){
			if(strcmp(argv[2],"-o")==0){
				bool_output = true;	
			}	
		}
		string url(argv[1], strnlen(argv[1], 40)); // transformar o site(cons char*) em string
		ofstream saida("../out/Output.txt"); //Abre a saida
		
		//Dnsenum:
		stringstream entrada_sstr; //string especial para concatenar
		(bool_output) ? entrada_sstr << "dnsenum -o out/Output.xml " << url : entrada_sstr << "dnsenum " << url; //concatenacao de string com const char para string especial
		string entrada_str = entrada_sstr.str(); //transformando string especial em string
		const char *entrada_char = entrada_str.c_str(); // transformar string para const char
		system (entrada_char); // dnsenum
	
		//bruteforce dns:
		ifstream entrada("DatabaseDNS.txt"); //Abre o entrada com varios DNS's
		string dns, site;
		while(!entrada.eof()){ //Enquanto nao chegar no fim do banco de dns's
			getline(entrada, dns);
			site = dns + url; // concatena a dns com o site
			const char* site_char = site.c_str();
			struct hostent *host;
			host=gethostbyname(site_char);
			if(host == NULL){	
				continue;
			}
			cout << "Achou: " << site_char << endl;
			if(bool_output){saida << "Achou: " << site_char << endl;}
		}
		entrada.close();
		saida.close();
	
	return 0;
}