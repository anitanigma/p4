#include "../include/Nacional.h"
using namespace std;

Nacional::Nacional(string id, Direccion dir, string rut):Empresa(id,dir){
	this->rut = rut;
	
}
Nacional::Nacional(DtEmpresa *emp, string rut):Empresa(emp->getDtEmpresaId(), emp->getDtEmpresaDir() ){
	 this->rut = rut;
} 

string Nacional::getNacionalrut(){
	return rut;
}

void Nacional::setNacionalrut(string rut){
	this->rut = rut;
}

float Nacional::getDescuento(){
	return 0.35;
}

Nacional::~Nacional(){} 


