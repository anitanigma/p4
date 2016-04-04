#ifndef Nacional_h
#define Nacional_h
#include <iostream>
#include <string.h>
#include "Direccion.h"
#include "Empresa.h"
#include "DtEmpresa.h"

class Nacional: public Empresa{
private:
    string	rut;

public:	 
	Nacional(string id, Direccion dir, string rut); 
	Nacional(DtEmpresa *emp, string rut);
	string getNacionalrut();
	void setNacionalrut(string fan);
	float getDescuento();
	~Nacional(); 
};

#endif