#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
	
	ifstream a("Ahmad.txt");
	
	string texto, tmp;
	getline(a, texto);
	cout << texto << endl;
	ofstream b("Ahmad.txt");
	cin >> tmp;
	b << texto << endl << tmp;
	
	
	system("PAUSE");
	return 0;
	
}
