#include <iostream>
#include "AdmArchivos.h"
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "Wallet.h"
void crearWallet(Paypal& paypal, vector<Wallet>& wallets) {
	string name = paypal.getDato("\nIngrese Usuario de Wallet: ");
	string contra = "";
	while (true) {
		contra = paypal.getDato("Ingrese Contrasenia de Wallet: ");
		if (paypal.verificarContra(contra))
			break;
		else
			cout << "\n\nVERIFIQUE SU CONTRASENIA.\n";
	}
	string nameUsuPP = "";//nombre de usuario de paypal
	bool flag = true;
	while (flag) {
		char salir = ' ';
		nameUsuPP = paypal.getDato("Ingrese Nombre de Usuario de Paypal: ");
		for (UsuarioPaypal upp : paypal.gUsuarios()) {
			if (upp.gName() == nameUsuPP) {
				wallets.push_back(Wallet(name, contra, upp));
				cout << "\n\n >-- Wallet Creada Exitosamente --< \n";
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "\n >La cuenta NO existe\n >Desea Ingresar Otra cuenta s/n\n";
			cin >> salir;
		}
		if (salir != 's')
			break;
	}
}
void deposito(UsuarioPaypal* ptrUsu) {
	float money;
	cout << "Cantidad a depositar a su cuenta: ";
	cin >> money;
	ptrUsu->deposito(money, false);
}
void retiro(UsuarioPaypal* ptrUsu) {
	float money;
	cout << "Cantidad a retirar a su cuenta: ";
	cin >> money;
	ptrUsu->retiro(money, false);
}
void accederPP(Paypal& paypal,AdmArchivos& admin) {
	cout << " ----- Iniciar Sesion ----- \n";
	string usuario = paypal.getDato("Ingrese Usuario: ");
	string contra = paypal.getDato("Ingrese Contrasenia: ");
	bool flag = false;
	UsuarioPaypal* ptrUsu = new UsuarioPaypal;//lo hice asi por que me tira un error
	for (UsuarioPaypal upp : paypal.gUsuarios()) {
		if (upp.gName() == usuario && upp.gContra() == contra) {
			flag = true;
			ptrUsu = &upp;
		}
	}
	if (flag) {
		int opc = 0;
		while (opc != 5) {
			cout << "\n ------- Bienvenido -------\n";
			cout << "1. Ver Estado de Cuenta: \n"
				<< "2. Hacer deposito a mi propia cuenta\n"
				<< "3. Hacer retiro de mi cuenta\n"
				<< "4. Ver historial de mi cuenta\n"
				<< "5.Salir\n > ";
			cin >> opc;
			switch (opc) {
			case 1: cout << "\nSALDO ACTUAL : " << ptrUsu->gMoney(); break;
			case 2: deposito(ptrUsu); break;
			case 3: retiro(ptrUsu); break;
			case 4: cout << "--- Historial ---\n";
				ptrUsu->cHisto(); break;
			case 5: admin.crearArchivos(paypal);
			}
		}
	}
	else
		cout << "\n -- Credenciales Incorrectas --\n";
	//delete ptrUsu;
}
void vender(Wallet*& ptrW) {
	int opc;
	cout << "-- Vender Crypto -- \n";
	cout << "1. Doge coin\n2. Walter Coin\n3. Etherium";
	cin >> opc;
	switch (opc) {
	case 1: ptrW->venderDoge();
	case 2: ptrW->vendecrWalter();
	case 3: ptrW->venderEth();
	}
}
void comprar(Wallet*& ptrW) {
	int opc;
	cout << "-- Comprar Crypto -- \n";
	cout << "1. Doge coin\n2. Walter Coin\n3. Etherium";
	cin >> opc;
	switch (opc) {
	case 1: ptrW->comprarDoge();
	case 2: ptrW->comprarWalter();
	case 3: ptrW->comprarEth();
	}
}
void accerderWallet(vector<Wallet>& wallets,Paypal& paypal) {
	cout << " ----- Iniciar Sesion Wallet ----- \n";
	string usuario = paypal.getDato("Ingrese Usuario: ");
	string contra = paypal.getDato("Ingrese Contrasenia: ");
	bool flag = false;
	Wallet* ptrW = new Wallet;//lo hice asi por que me tira un error
	for (Wallet w : wallets.g()) {
		if (w.gName() == usuario && w.gContra() == contra) {
			flag = true;
			ptrW = &w;
		}
	}
	if (flag) {
		int opc = 0;
		while (opc != 4) {
			cout << "\n ------- Bienvenido -------\n";
			cout << "1. Ver Estado de Cuenta: \n"
				<< "2. Vender Cryptos\n"
				<< "3. Comprar Cryptos\n"
				<< "4.Salir\n > ";
			cin >> opc;
			switch (opc) {
			case 1: cout << "\nSALDO ACTUAL : \n "; ptrW->fondos();
			case 2: vender(ptrW); break;
			case 3: comprar(ptrW); break;
			}
		}
	}
	else
		cout << "\n -- Credenciales Incorrectas --\n";
}
void menu() {
	AdmArchivos admin;
	Paypal paypal;
	vector<Wallet> wallets;
	int opc = 0;
	while (opc != 6) {
		cout << "1.Crear cuenta de paypal\n"
			<< "2.Crear Wallet\n"
			<< "3.Cargar informacion\n"
			<< "4.Acceder a paypal\n"
			<< "5.Acceder a wallet\n"
			<< "6.Salir\n> ";
		cin >> opc;
		switch (opc) {
		case 1: paypal.crearCuenta(); break;
		case 2:crearWallet(paypal, wallets); break;
		case 3:paypal = admin.cargarArchivos(); break;
		case 4:accederPP(paypal, admin); break;
		case 5: accerderWallet(wallets, paypal);
		}
	}
}
int main() {
	menu();
}
