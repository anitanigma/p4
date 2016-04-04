#include "../include/DtNacional.h"
using namespace std;

DtNacional::DtNacional(string id, Direccion dir, string rut): DtEmpresa(id,dir){
	this->rut = rut; 
}

 

string DtNacional::getDtNacionalRut(){
	return rut;
}

DtNacional::~DtNacional(){}

ostream& operator << (ostream &o, DtNacional &emp){
	o<<"RUT:"<< emp.getDtNacionalRut() << endl;
	return o;
}
