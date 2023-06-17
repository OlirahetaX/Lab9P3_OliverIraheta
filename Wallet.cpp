#include "Wallet.h"

Wallet::Wallet()
{
}

Wallet::Wallet(string name, string contra, UsuarioPaypal usuario){
	this->name = name;
	this->contra = contra;
	PtrUsuario = &usuario;
	doge = 0;
	walter = 0;
	eth = 0;
}

Wallet::~Wallet()
{
}

string Wallet::gName()
{
	return name;
}

string Wallet::gContra()
{
	return contra;
}

UsuarioPaypal* Wallet::gUsu()
{
	return &(*PtrUsuario);
}

void Wallet::fondos(){
	cout << "Doge coin disponible: " << doge << endl;
	cout << "Walter coin disponible: " << walter << endl;
	cout << "Etherium disponible: " << eth << endl;
}

void Wallet::venderDoge(){
	int cant = 0;
	cout << " Doge coin disponible: " << doge << endl;
	cout << " Cuanto desea vender: ";
	cin >> cant;
	if (cant <= doge) {
		cout << " - VENTA EXITOSA -\n";
		doge -= cant;
		PtrUsuario->deposito((cant*0.6),true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}

void Wallet::vendecrWalter(){
	int cant = 0;
	cout << " Walter coin disponible: " << walter << endl;
	cout << " Cuanto desea vender: ";
	cin >> cant;
	if (cant <= walter) {
		cout << " - VENTA EXITOSA -\n";
		walter -= cant;
		PtrUsuario->deposito((cant * 5), true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}

void Wallet::venderEth(){
	int cant = 0;
	cout << " Etherium disponible: " << eth << endl;
	cout << " Cuanto desea vender: ";
	cin >> cant;
	if (cant <= eth) {
		cout << " - VENTA EXITOSA -\n";
		eth -= cant;
		PtrUsuario->deposito((cant * 1000), true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}

void Wallet::comprarDoge(){
	int cant = 0;
	cout << "Cantidad a Comprar: ";
	cin >> cant;
	if (PtrUsuario->gMoney()>=(0.6*cant)) {
		cout << " -- Crypto Comprado --\n";
		doge += cant;
		PtrUsuario->retiro(0.6 * cant, true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}

void Wallet::comprarWalter(){
	int cant = 0;
	cout << "Cantidad a Comprar: ";
	cin >> cant;
	if (PtrUsuario->gMoney() >= (5 * cant)) {
		cout << " -- Crypto Comprado --\n";
		walter += cant;
		PtrUsuario->retiro(0.6 * cant, true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}

void Wallet::comprarEth(){
	int cant = 0;
	cout << "Cantidad a Comprar: ";
	cin >> cant;
	if (PtrUsuario->gMoney() >= (1000 * cant)) {
		cout << " -- Crypto Comprado --\n";
		eth += cant;
		PtrUsuario->retiro(0.6 * cant, true);
	}
	else {
		cout << " - Sin Fondos -\n";
	}
}
