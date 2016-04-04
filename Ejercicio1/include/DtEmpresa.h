#ifndef DtEmpresa_h
#define DtEmpresa_h
#include <iostream>
#include <string.h>
#include "Direccion.h"

using namespace std;



class DtEmpresa {
protected:
	string id;
	Direccion direccion;

public:
	DtEmpresa(string id, Direccion dir);
	
	string getDtEmpresaId();
	Direccion getDtEmpresaDir();
	virtual void nada() {} // Forzar polimorfismo
	~DtEmpresa();
        friend bool operator == (const DtEmpresa &e1, const DtEmpresa &e2);
};

ostream& operator << (ostream &o, DtEmpresa &emp);

#endif
