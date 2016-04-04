#include "../include/Empleado.h"

using namespace std;
//Constructores
Empleado::Empleado() {
	this->ci = "";
        this->nombre = "";
        this->apellido= "";
        this->direccion= Direccion();
        this->tope=-1;
};

Empleado::Empleado(string ci, string nombre, string apellido, Direccion  direccion){
        this->ci = ci;
        this->nombre = nombre;
        this->apellido= apellido;
        this->direccion = direccion;
        this->tope=-1;
};
Empleado::Empleado(const DtEmpleado &dtemp){


        this->ci = dtemp.getCi();

        nombre = dtemp.getNombre();
        apellido= dtemp.getApellido();
        direccion = Direccion(dtemp.getDireccion());
        tope=-1; 
};
//Getters 
string Empleado::getCi() const{
	return this->ci;
};
string Empleado::getNombre() const{
	return this->nombre;
};
string Empleado::getApellido() const{
	return this->apellido;
};
Direccion Empleado::getDireccion() const{
	return this->direccion;
};

//Setters
void Empleado::setCi(string ci){
	this->ci=ci;
};
void Empleado::setNombre(string nombre){
	this->nombre=nombre;
};
void Empleado::setApellido(string apellido){
	this->apellido=apellido;
};
void Empleado::setDireccion(Direccion direccion){
	this->direccion=direccion;
};
//Operaciones
void Empleado::AsociarEmpresa(  Empresa &emp, float sueldo){
    tope++;
    Rel[tope]= new RelacionLaboral( sueldo, emp); 
};


void Empleado::DesasociarEmpresa(string idempresa, Fecha desvinculacion){
    for (int i = 0; i <= tope; i++)
    { 
        if (Rel[i]->ApuntaEmpresa(idempresa))
        { 
           Rel[i]->setFechaDesvinculacion(desvinculacion);
        }
    }

};

DtEmpresa** Empleado::EmpresasActivas(int &cantEmpresas){
  DtEmpresa** dtemp = new DtEmpresa*[cantEmpresas]; 
  
  int j=0;
  int i = 0;
   while ((i <=tope) && ( j< cantEmpresas))
   { 
      if (Rel[i]->RelacionActiva()){ 
       
        Nacional * den = dynamic_cast<Nacional*> (&*Rel[i]->getPunteroEmpresa());
         if(den){ 
              dtemp[j] = new DtNacional(    den->getEmpresaId(), 
                                            den->getEmpresaDir(), 
                                            den->getNacionalrut()); 
          }else{
            Extranjera * dee = (Extranjera*)(&*Rel[i]->getPunteroEmpresa());
             dtemp[j] = new DtExtranjera(   dee->getEmpresaId(), 
                                            dee->getEmpresaDir(), 
                                            dee->getExtranjeraFantasia()); 
           };
            j++;
        };
         i++;
    }
    cantEmpresas=j;
    return dtemp; 
};

float Empleado::getSueldoNeto() const{

    float sueldo=0;
    for (int i = 0; i <= tope; i++)
    {
        if (Rel[i]->RelacionActiva())
        {
            sueldo+= Rel[i]->getSueldoLiquido();
        }
        
    }
    return sueldo;
};

bool Empleado::EmpresaAsociada(string idempresa)const{ 
    bool esta=false;
    int i=0;
    while(i<=tope && not esta){

        esta=(Rel[i]->ApuntaEmpresa(idempresa));
        
        i++;
    };
    return esta;
};

Empleado::~Empleado(){
    int i;
	for(i=0; i<=tope; i++){
		delete Rel[i];
	};
}

float* Empleado::SueldosEmpresas(){
    float* sueldos = new float[tope+1];
    int i = 0;
    int j= 0;
    while ((i<=tope) && (j<=tope)) {
        if (Rel[i]->RelacionActiva()){
            sueldos[j] = Rel[i]->getSueldoLiquido();
            j++;
        }
        i++;
    }
    return sueldos;
}

bool Empleado::ValidarRelacion(){
	return (tope<MAX_REL_LAB-1);
}
