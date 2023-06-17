#pragma once
#include "UsuarioPaypal.h"
#include <fstream>
class Paypal{
	vector<UsuarioPaypal> usuarios;
public:
	Paypal();
	~Paypal();
	vector<UsuarioPaypal> gUsuarios();
	void crearCuenta();
	bool verificarContra(string&);
	string getDato(string);
};

