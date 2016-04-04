#include "../include/RelacionLaboral.h"

RelacionLaboral::RelacionLaboral (){
     this->sueldo=0;
     this->fechaDesvinculacion= new Fecha();
     this->RelacionEmpresa = NULL;
};

RelacionLaboral::RelacionLaboral (float sueldobrutus,   Empresa &emp){
    float desc= emp.getDescuento();
     this->sueldo= sueldobrutus - (desc * sueldobrutus);
     this->RelacionEmpresa = &emp;
     this->fechaDesvinculacion = NULL;
};

	//Getters, Setters 
float	RelacionLaboral::getSueldoLiquido(){
	return sueldo;
};
void 	RelacionLaboral::setSueldoLiquido(float Sueldo){
	this->sueldo = Sueldo;
};
bool    RelacionLaboral::RelacionActiva() const {
    return (fechaDesvinculacion == NULL);
}
Empresa* RelacionLaboral::getPunteroEmpresa() const{
    return ( RelacionEmpresa);


}
Fecha 	RelacionLaboral::getFechaDesvinculacion(){
	return *fechaDesvinculacion;
};
void 	RelacionLaboral::setFechaDesvinculacion(Fecha &fecha){
        
	this->fechaDesvinculacion = new Fecha(fecha);
};
bool RelacionLaboral::ApuntaEmpresa(string IdEmpresa) const{ 
    return (IdEmpresa == ( RelacionEmpresa->getEmpresaId()));
};

RelacionLaboral::~RelacionLaboral() {
    delete this->fechaDesvinculacion;

};


  
