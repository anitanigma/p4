#include "../include/Empresa.h" 


Empresa::Empresa(string id, Direccion dir){
	this->id = id;
	direccion = dir;
}

void Empresa::setEmpresaid(string id){
	id = id;
}
	
string Empresa::getEmpresaId(){
	return id;
}

void Empresa::setEmpresadireccion(Direccion dir){
	direccion = dir;
}

Direccion Empresa::getEmpresaDir(){
	return direccion;
}

Empresa::~Empresa(){}
