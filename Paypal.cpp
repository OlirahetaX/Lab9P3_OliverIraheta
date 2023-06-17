#include "Paypal.h"

Paypal::Paypal()
{
}

Paypal::~Paypal()
{
}

vector<UsuarioPaypal> Paypal::gUsuarios()
{
	return usuarios;
}

void Paypal::crearCuenta() {
	string nombre, contra, numID;
	bool flag = true;
	while (flag) {
		nombre = getDato("Ingrese Nombre Del Usuario: ");
		if (!usuarios.size())
			break;
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].gName() == nombre) {
				cout << "\nNombre ya esta en uso\n";
				break;
			}
			else {
				flag = false;
			}
		}
	}
	flag = true;
	while (true) {
		numID = getDato("Ingrese Numero De Identidad Del Usuario: ");
		if (!usuarios.size())
			break;
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].gId() == numID) {
				cout << "\nIdentidad ya esta en uso\n";
				break;
			}
			else {
				flag = false;
			}
		}
	}
	while (true) {
		contra = getDato("Ingrese Contrasenia del Usuario: ");
		if (verificarContra(contra))
			break;
		else
			cout << "\nVERIFIQUE SU CONTRASENIA.\n";
	}
	UsuarioPaypal upp(nombre, contra, numID);
	usuarios.push_back(upp);
	cout << "\n\n >-- Usuario Creado Exitosamente --<\n";
	//creando el archivo binario del usuario
	string nombreArchivo = numID;
	nombreArchivo += ".lab";
	ofstream archivo(nombreArchivo, ios::binary);
	if (archivo.is_open()) {
		archivo.write((char*)&upp, sizeof(UsuarioPaypal));
		archivo.close();
		cout << "\nArchivo binario creado correctamente." << endl;
	}
	else {
		std::cout << "No se pudo crear el archivo." << std::endl;
	}
}


string Paypal::getDato(string anun) {
	string aux;
	cout << anun;
	cin >> aux;
	return aux;
}

bool Paypal::verificarContra(string& contra) {
	bool letra = false, num = false, carEspecial = false;
	for (char c : contra) {
		if (isalpha(c))//verifico si es una letra
			letra = true;
		else if (isdigit(c))//verifico si es un numero
			num = true;
		else
			carEspecial = true;
	}
	if (letra && num && carEspecial)
		return true;
	else
		return false;
}
