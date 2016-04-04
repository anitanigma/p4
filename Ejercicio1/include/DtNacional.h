#ifndef DtNacional_h
#define DtNacional_h
#include <iostream>
#include <string.h>
#include "Direccion.h"
#include "DtEmpresa.h" 


using namespace std;

class DtNacional: public DtEmpresa{
protected:
	string	rut;

public:
	DtNacional(string id, Direccion dir, string rut); 
	string getDtNacionalRut();
        friend bool operator == (const DtNacional &n1, const DtNacional &n2);
	~DtNacional(); 
};

ostream& operator << (ostream &o, DtNacional &emp);

#endif
