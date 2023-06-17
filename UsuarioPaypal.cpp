#include "UsuarioPaypal.h"

UsuarioPaypal::UsuarioPaypal()
{
}

UsuarioPaypal::~UsuarioPaypal()
{
}

UsuarioPaypal::UsuarioPaypal(string name, string contrasena, string numID) {
	this->name = name;
	this->contrasena = contrasena;
	this->numID = numID;
	money = 0;
}

string UsuarioPaypal::gName()
{
	return name;
}

string UsuarioPaypal::gContra()
{
	return contrasena;
}

string UsuarioPaypal::gId()
{
	return numID;
}

vector<string> UsuarioPaypal::gHisto()
{
	return historial;
}

void UsuarioPaypal::cHisto() {
	for (string h : historial) {
		cout << " - " << h << endl;
	}
}

float UsuarioPaypal::gMoney()
{
	return money;
}

void UsuarioPaypal::deposito(float money, bool wallet) {
	this->money += money;
	string depo = "Se ha depositado ";
	depo += money;
	if (wallet) //si se ha realizado el deposito desde la venta de crypto
		depo += " dolares desde su wallet.";
	else {
		cout << " -- Se ha relizado un deposito de " << money << " dolares.\n";
		cout << " SU SALDO ACTUAL ES DE: " << this->money;
		depo += " dolares desde su misma cuenta.";
	}
	historial.push_back(depo);
}

void UsuarioPaypal::retiro(float money, bool wallet) {
	if (this->money > money) {
		this->money -= money;
		string depo = "Se ha retirado ";
		depo += money;
		if (wallet) //si se ha realizado el retiro desde la  de crypto
			depo += " dolares desde su wallet.";
		else {
			cout << " -- Se ha relizado un retiro de " << money << " dolares.\n";
			cout << " SU SALDO ACTUAL ES DE: " << this->money;
			depo += " dolares desde su misma cuenta.";
		}
		historial.push_back(depo);
	}
	else {
		cout << " - FONDOS INSUFICIENTES -\n";
	}

}

