#ifndef Extranjera_h
#define Extranjera_h
#include <iostream>
#include <string.h>
#include "Direccion.h"
#include "Empresa.h"
#include "DtEmpresa.h"
#include "Extranjera.h"

class Extranjera: public Empresa{
private:	
    string	nombreFantasia; 

public:
	Extranjera(string id, Direccion dir, string fan);
	Extranjera(DtEmpresa *emp, string fanta);
	string getExtranjeraFantasia();
	void setExtranjeraFantasia(string fan);
	float getDescuento();
	~Extranjera(); 
};

#endif
   
