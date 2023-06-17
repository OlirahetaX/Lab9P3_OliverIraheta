#include "AdmArchivos.h"


AdmArchivos::AdmArchivos()
{
}

AdmArchivos::~AdmArchivos()
{
}
Paypal AdmArchivos::cargarArchivos()
{
	Paypal pp;
	ifstream archivo("Paypal.lab", ios::binary);
	if (archivo) {
		archivo.read(reinterpret_cast<char*>(&pp), sizeof(Paypal));
		cout << "\nArchivo binario cargado correctamente." << endl;
	}
	else {
		std::cout << "No se pudo cargar el archivo." << std::endl;
	}
	archivo.close();
	return pp;
}

void AdmArchivos::crearArchivos(Paypal& paypal){
	ofstream archivo("Paypal.lab", ios::binary);
	if (archivo.is_open()) {
		archivo.write(reinterpret_cast<const char*>(&paypal), sizeof(Paypal));
		cout << "\nArchivo binario creado correctamente." << endl;
	}
	else {
		std::cout << "No se pudo crear el archivo." << std::endl;
	}
	archivo.close();
}
