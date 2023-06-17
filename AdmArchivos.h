#pragma once
#include "Paypal.h"

class AdmArchivos{
public:
	AdmArchivos();
	~AdmArchivos();
	Paypal cargarArchivos();
	void crearArchivos(Paypal&);
};

