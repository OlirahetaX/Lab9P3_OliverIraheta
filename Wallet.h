#pragma once
#include "UsuarioPaypal.h"
class Wallet{
	string name,contra;
	UsuarioPaypal* PtrUsuario;
	int doge,walter,eth;
public:
	Wallet();
	Wallet(string,string,UsuarioPaypal);
	~Wallet();
	string gName();
	string gContra();
	UsuarioPaypal* gUsu();
	
	void venderDoge();
	void vendecrWalter();
	void venderEth();

};

