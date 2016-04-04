#include "../include/DtEmpresa.h"
using namespace std;

DtEmpresa::DtEmpresa(string id, Direccion dir){  
	this->id=id;
	this->direccion=dir;
}

string DtEmpresa::getDtEmpresaId(){
	return id;
}

Direccion DtEmpresa::getDtEmpresaDir(){
	return direccion;
}
	

DtEmpresa::~DtEmpresa(){  

}

bool operator == (const DtEmpresa &e1, const DtEmpresa &e2){
    return (e1.id==e2.id);
}

ostream& operator << (ostream &o, DtEmpresa &emp){
	o<<"Id Empresa:"<< emp.getDtEmpresaId()<< endl;
	o<<emp.getDtEmpresaDir();
	return o;
}
