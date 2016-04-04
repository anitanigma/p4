#ifndef Empresa_h
#define Empresa_h
#include <iostream>
#include <string.h>
#include "Direccion.h"

using namespace std;

class Empresa{
	string id;
	Direccion direccion;

public:
	Empresa(string id, Direccion dir);
	void setEmpresaid(string id);	
	string getEmpresaId();
	void setEmpresadireccion(Direccion dir);
	Direccion getEmpresaDir();
	virtual float getDescuento() = 0;
	virtual ~Empresa();
};

#endif
