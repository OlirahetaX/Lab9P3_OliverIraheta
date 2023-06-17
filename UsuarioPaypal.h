#pragma once
#include <vector>
using namespace std;
#include <iostream>
class UsuarioPaypal{
	string name, contrasena, numID;
	float money;
	vector<string> historial;
public:
	UsuarioPaypal();
	~UsuarioPaypal();
	UsuarioPaypal(string,string,string);
	string gName();
	string gContra();
	string gId();
	vector<string> gHisto();
	void cHisto();
	float gMoney();
	void deposito(float,bool);
	void retiro(float,bool);

};

