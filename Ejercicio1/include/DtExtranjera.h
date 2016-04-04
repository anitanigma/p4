#ifndef DtExtranjera_h
#define DtExtranjera_h
#include <iostream>
#include <string.h>
#include "Direccion.h"
#include "DtEmpresa.h"

class DtExtranjera: public DtEmpresa{
private:
	string	nombreFantasia; 

public:
	DtExtranjera(string id, Direccion dir, string fan);
	string getDtExtranjeraFantasia();
	~DtExtranjera(); 
};

ostream& operator << (ostream &o,DtExtranjera &emp);

#endif
