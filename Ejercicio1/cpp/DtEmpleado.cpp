#include "../include/DtEmpleado.h"


using namespace std;

DtEmpleado::DtEmpleado(){
    this->ci= this->nombre=this->apellido="";
    this->SueldoLiquido=0;
    this->direccion= Direccion ();
};

DtEmpleado::DtEmpleado(string ci, string nombre, string apellido, Direccion direccion, float sueldo){
    this->ci= ci;
    this->nombre= nombre;
    this->apellido=apellido;    
    this->SueldoLiquido=sueldo;
    this->direccion= direccion;
};
DtEmpleado::DtEmpleado(string ci, string nombre, string apellido, Direccion direccion ){
    this->ci= ci;
    this->nombre= nombre;
    this->apellido=apellido;    
    this->SueldoLiquido=0;
    this->direccion= direccion;
}; 
 string DtEmpleado::getCi() const{
	return this->ci; 
};
 string DtEmpleado::getNombre() const{
	return this->nombre;
};
 string DtEmpleado::getApellido() const{
	return this->apellido;
};
 Direccion DtEmpleado::getDireccion() const{
	return this->direccion;
};
 float DtEmpleado::getSueldoLiquido() const{
	return this->SueldoLiquido;
};
 
bool operator == (const DtEmpleado &e, const DtEmpleado &e2){
  return(e2.ci==e.ci);

}; 

ostream& operator << (ostream &o, DtEmpleado &empl){
	o<<"Ci:"<<empl.getCi()<<endl;
	o<<"Nombre:"<<empl.getNombre()<<endl;
	o<<"Apellido:"<<empl.getApellido()<<endl;
	o<<empl.getDireccion();
	return o;
};

DtEmpleado::~DtEmpleado(){
}
