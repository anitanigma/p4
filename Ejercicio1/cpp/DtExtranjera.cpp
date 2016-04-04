#include "../include/DtExtranjera.h"

using namespace std;

DtExtranjera::DtExtranjera(string id, Direccion dir, string fan): DtEmpresa(id,dir){
	nombreFantasia = fan; 
}
	
string DtExtranjera::getDtExtranjeraFantasia(){
	return nombreFantasia;
}
	
DtExtranjera::~DtExtranjera(){
} 


ostream& operator << (ostream &o,DtExtranjera &emp){
	o<<"Nombre fantasía:"<< emp.getDtExtranjeraFantasia() << endl;
	return o;
}
