#include "../include/Extranjera.h"
using namespace std;

Extranjera::Extranjera(string id, Direccion dir, string fan): Empresa(id,dir){
	nombreFantasia = fan;
	
}
Extranjera::Extranjera(DtEmpresa *emp, string fanta):Empresa(emp->getDtEmpresaId(), emp->getDtEmpresaDir() ){ 
    nombreFantasia=fanta;

}

string Extranjera::getExtranjeraFantasia(){
	return nombreFantasia;
}

void Extranjera::setExtranjeraFantasia(string fan){
	nombreFantasia = fan;
}

float Extranjera::getDescuento(){
	return 0.20;
}

Extranjera::~Extranjera(){}
