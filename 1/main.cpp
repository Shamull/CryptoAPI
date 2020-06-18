#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/md5.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
using namespace std;
int main()
{
	using CryptoPP::MD5;
	ifstream f("../f.txt");
	string s;
	string TextFile{0};
	while (!f.eof()) {
		getline(f, s);
		TextFile += s;
	}
	cout << "Текст из файла: " << TextFile << endl;
	string hesh;
	CryptoPP::Weak1::MD5 hashmd4;
	CryptoPP::StringSource(TextFile, true, new CryptoPP::HashFilter(hashmd4,new CryptoPP::HexEncoder(new CryptoPP::StringSink(hesh))));
	cout << hesh << endl;
}