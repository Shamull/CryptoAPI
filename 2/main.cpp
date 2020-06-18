#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include "cryptopp/rc5.h"
#include "cryptopp/seed.h"
#include "cryptopp/modes.h"
#include "cryptopp/cbcmac.h"
using namespace std;
void encRC5() {
	string plaintext{0};
    string fname;
	
    cout << "Введите название файла, который необходимо считать" << endl;
    cin >> fname;
    ifstream f1(fname);
    char ch;
    while (f1.get(ch))
        plaintext.push_back(ch);

    byte key[CryptoPP::RC5::DEFAULT_KEYLENGTH], iv[CryptoPP::RC5::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::RC5::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::RC5::BLOCKSIZE);
    
    string ciphertext;
    cout << "Текст в файле:" << endl << plaintext << endl;
	
    CryptoPP::RC5::Encryption aesEncryption(key, CryptoPP::RC5::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());
    stfEncryptor.MessageEnd();	
	
    cout << "Зашифрованный текст:" << endl;
    for (int i = 0; i < ciphertext.size(); i++)
        cout << std::hex << (0xFF & static_cast<byte>(ciphertext[i]));
	
    cout << endl << "Введите имя файла для сохренения шифра в него" << endl;
	string fname2;
    cin >> fname2;
	ofstream f2(fname2);
    for (int i = 0; i < ciphertext.size(); i++)
        f2 << ciphertext[i];
    
}
void encSEED() {
	string plaintext{0};
    string fname;
	
    cout << "Введите название файла, который необходимо считать" << endl;
    cin >> fname;
    ifstream f1(fname);
    char ch;
    while (f1.get(ch))
        plaintext.push_back(ch);

    byte key[CryptoPP::SEED::DEFAULT_KEYLENGTH], iv[CryptoPP::SEED::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::SEED::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::SEED::BLOCKSIZE);
    
    string ciphertext;
    cout << "Текст в файле:" << endl << plaintext << endl;
	
    CryptoPP::SEED::Encryption aesEncryption(key, CryptoPP::SEED::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());
    stfEncryptor.MessageEnd();	
	
    cout << "Зашифрованный текст:" << endl;
    for (int i = 0; i < ciphertext.size(); i++)
        cout << std::hex << (0xFF & static_cast<byte>(ciphertext[i]));
	
    cout << endl << "Введите имя файла для сохренения шифра в него" << endl;
	string fname2;
    cin >> fname2;
	ofstream f2(fname2);
    for (int i = 0; i < ciphertext.size(); i++)
        f2 << ciphertext[i];
	
}
void decRC5() {
    string plaintext{};
    string fname;
	
    cout << "Введите название файла, который необходимо считать" << endl;
    cin >> fname;
    ifstream f1(fname);
    char ch;
    while (f1.get(ch))
        plaintext.push_back(ch);

	byte key[CryptoPP::RC5::DEFAULT_KEYLENGTH], iv[CryptoPP::RC5::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::RC5::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::RC5::BLOCKSIZE);

	string decryptedtext;
	string fname2;
    cout << "Введите имя файла для записи дешифрованного текста" << endl;
    cin >> fname2;
	ofstream ofile(fname2);
	
	
    CryptoPP::RC5::Decryption aesDecryption(key, CryptoPP::RC5::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    stfDecryptor.MessageEnd();
	
	cout << "Расшифрованный текст:" << endl;
    cout << decryptedtext << endl;
    ofile << decryptedtext;
}
void decSEED() {
    string plaintext{};
    string fname;
	
    cout << "Введите название файла, который необходимо считать" << endl;
    cin >> fname;
    ifstream f1(fname);
    char ch;
    while (f1.get(ch))
        plaintext.push_back(ch);

	byte key[CryptoPP::SEED::DEFAULT_KEYLENGTH], iv[CryptoPP::SEED::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::SEED::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::SEED::BLOCKSIZE);

	string decryptedtext;
	string fname2;
    cout << "Введите имя файла для записи дешифрованного текста" << endl;
    cin >> fname2;
	ofstream ofile(fname2);
	
	
    CryptoPP::SEED::Decryption aesDecryption(key, CryptoPP::SEED::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    stfDecryptor.MessageEnd();
	
	cout << "Расшифрованный текст:" << endl;
    cout << decryptedtext << endl;
    ofile << decryptedtext;
}
int main()
{
    setlocale(LC_ALL, "Russia");
    string v;
    string c;
	
	cout << "Выберете режим шифрования/дешифрования RC5 или SEED" << endl;
	cin >> v;
	cout << "Ведите E, чтобы зашифровать, D дешифровать" << endl;
	cin >> c;
	
	if (v == "RC5"){			
		if (c == "E")
			encRC5();
		else  if (c == "D")
			decRC5();
	}else if (v == "SEED"){
		if (c == "E")
			encSEED();
		else  if (c == "D")
			decSEED();
	}
	
    return 0;
}