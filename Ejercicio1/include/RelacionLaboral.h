#ifndef RelacionLaboral_h
#define RelacionLaboral_h
#include <iostream>
#include <string.h>
#include "Fecha.h"
#include "Empresa.h"

using namespace std;

class RelacionLaboral {
private:
	//Atributos 
        float sueldo;
        Fecha* fechaDesvinculacion;
        Empresa* RelacionEmpresa;
public:
	//Constructores 
        RelacionLaboral();
        RelacionLaboral(float sueldobrutus, Empresa &emp );

	//Getters, Setters 
        float	getSueldoLiquido();
        void 	setSueldoLiquido(float Sueldo);
        Fecha 	getFechaDesvinculacion();
        bool    RelacionActiva() const;
        void 	setFechaDesvinculacion(Fecha& fecha);
        Empresa* getPunteroEmpresa() const;
       
    //Operadores
        bool ApuntaEmpresa(string IdEmpresa) const;
        //Devuelve true si apunta a una empresa con el IDempresa
	//Destructores
        ~RelacionLaboral(); 
	 
}; 
#endif
