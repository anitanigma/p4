#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include "include/DtEmpleado.h" 
#include "include/RelacionLaboral.h"
#include "include/Empleado.h"
#include "include/Fecha.h"
#include "include/Direccion.h"
#include "include/Empresa.h"
#include "include/DtEmpresa.h"
#include "include/DtExtranjera.h"
#include "include/DtNacional.h"
#include "include/Nacional.h"
#include <stdexcept>
#include "include/Extranjera.h"
#define MAX_EMPLEADOS 3
#define MAX_EMPRESAS 4


using namespace std;
bool terminar=false;
string opcion;
string CI;
string ID;
Direccion dir;
string Pais;
int cantempresas;
string Ciudad;
string Numero;
string Calle;
float sueldo;
int o;

int anio;
int mes;
int dia;
    Empleado* empleados[MAX_EMPLEADOS];
    int topempleado= -1;
    
     Empresa * empresas[MAX_EMPRESAS];
     int topempresa= -1;

void imprimirbienvenida(){
  cout << endl;
  cout << "La maxima cantidad de empleados es: " << MAX_EMPLEADOS << ", " << endl;
  cout << "La maxima cantidad de empresas es: " << MAX_EMPRESAS << "." << endl << endl;
  cout << "Ingrese el valor de la opcion deseada y presione enter" << endl << endl;
  cout << "1. Agregar empleado al sistema" << endl;
  cout << "2. Agregar empresa al sistema" << endl;
  cout << "3. Ver lista de empleados" << endl;
  cout << "4. Agregar relacion laboral" << endl;
  cout << "5. Eliminar relacion laboral" << endl;
  cout << "6. Listar empresas en las que trabaja un empleado" << endl;
  cout << "7. Salir" << endl << endl;
}

string pedirCI(){
  cout << endl;
  cout << "Ingrese la CI del empleado:" << endl;
  cin>>CI;
  return CI;
}

string pedirIdEmpresa(){
  cout << endl;
  cout << "Ingrese la Id de la empresa:" << endl;
  cin>>ID;
  return ID;
}

Direccion pedirDir(){
  cout << "Ingrese pais  " << endl;
  cin>> Pais;
  cout << "Ingrese ciudad " << endl;
  cin>> Ciudad;
  cout << "Ingrese calle" << endl;
  cin>> Calle;
  cout << "Ingrese numero de puerta:" << endl;
  cin>> Numero;
  Direccion dir= Direccion(Pais,Ciudad,Numero,Calle);
  return dir; 
}

float pedirSueldo(){
    cout << endl;
    cout << "Ingrese sueldo neto del empleado en la empresa:" << endl;
    cin >> sueldo;
    return sueldo;
}

bool esValidaFecha(int anio,int mes, int dia){
  bool valido=true;
  if (1900>anio){
    valido=false;
  }
  else if ((dia<1)||(dia>31)){
    valido=false;
  }
  else if ((mes<1)||(mes>12)){
    valido=false;
  }
  if (valido==false){
    throw std::invalid_argument("La fecha no es valida, presione una tecla y luego enter para continuar");
  }
  return valido;
}   

////////////////////////////////////////////////////////////////////////////////////////////////
///////////                    FUNCIONES          MAIN
//////////////////////////////////////////////////////////////////////////////////////////////
void   agregarEmpleado(string   ci,   string   nombre,   string  apellido,   Direccion   dir)  {
    //Crea un nuevo empleado en el sistema. En caso de ya existir, levanta la excepción ​std::invalid_argument.     

  //Se busca si ya existe el empleado
    bool existe=false;
    int i=0;
    while((!existe)&&(i<=topempleado)){
        if (empleados[i]->getCi()==ci){ 
            existe=true;
        }
        i++;
    }

        if (existe){
            throw std::invalid_argument("El empleado ya existe, presione una tecla y luego enter para continuar");
        }else{

            Empleado* emp = new Empleado(ci, nombre,apellido, dir);   
            empleados[++topempleado] = emp;
        }
};

void   agregarEmpresa(DtEmpresa&   empresa) {
  //Crea una nueva empresa en el sistema.
  
//En caso de ya existir, levanta una excepción std::invalid_argument.
  bool existe=false;
  int i=0;
  while((!existe)&&(i<=topempresa)){
      if (empresas[i]->getEmpresaId()==empresa.getDtEmpresaId()){
          existe=true;
      }
      i=i+1;
  }  
    if (existe){
        throw std::invalid_argument("La empresa ya existe, presione una tecla y luego enter para continuar");
    }else{
        Empresa* emp;

        //Tip de dynamic cast
        //Se hace este procedimiento para saber si la empresa era extranjera o nacional 
        DtNacional * den = dynamic_cast<DtNacional*> (&empresa);
        if(den){ 
            emp = new Nacional(den, den->getDtNacionalRut()); 
            
        }else{
            DtExtranjera * dee = (DtExtranjera*)(&empresa);
            emp = new Extranjera(dee, dee->getDtExtranjeraFantasia()); 
        };    
        empresas[++topempresa]= emp; 
        }
};

DtEmpleado** listarEmpleados(int &cantEmpleados){
    DtEmpleado** dtemp = new DtEmpleado*[cantEmpleados+1];
    for(int i=0; i<=cantEmpleados; i++){ 
        dtemp[i] = new DtEmpleado(empleados[i]->getCi(),empleados[i]->getNombre(),empleados[i]->getApellido(),empleados[i]->getDireccion());
    };
    return (dtemp);
};

void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo){
  //Se busca empleado
    int i=0;
    bool esta=false; 
    while((i<=topempleado)&&(!esta)){
        if (empleados[i]->getCi() == ciEmpleado){
            esta=true;
        }
        else{
            i=i+1;
        }
    }
    //Se busca empresa
    int j=0;
    bool estaemp=false; 
    while((j<=topempresa)&&(!estaemp)){
        if (empresas[j]->getEmpresaId() == idEmpresa){
            estaemp=true;
        }
        else{
            j++;
        }
    }
    if (!estaemp){
        cout << "No existe la empresa, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
		std::system ("clear");
    }else  if (!esta){
        cout << "No existe el empleado, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
        std::system ("clear");
    } else if (!(empleados[i]->ValidarRelacion())){
		cout<<"No se pueden agregar mas relaciones laborales a este empleado, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
		std::system ("clear");
	} else { 

      //Se busca si ya esta asociado
      if (empleados[i]->EmpresaAsociada(idEmpresa)){
        throw std::invalid_argument("La empresa ya esta o estuvo asociada al empleado, presione una tecla y luego enter para continuar");
      }else{
        
        //Se busca la empresa. 
        int j=0;
        while ((j<=topempresa) && (empresas[j]->getEmpresaId() != idEmpresa)){
          j++;
        }
        empleados[i]->AsociarEmpresa(*empresas[j],sueldo);
      }
     }
};

void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion)
//Desvincula al empleado de la
//empresa, registrando la fecha en que terminó el vinculo.
{
  int i = 0;
  while(i <=topempleado && empleados[i]->getCi() != ciEmpleado){
    i++;
    }
      empleados[i]->DesasociarEmpresa(idEmpresa,desvinculacion);
}; 

DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int& cantEmpresas){
   int i =0;
   while((i <=topempleado) && (empleados[i]->getCi() != ciEmpleado))
    i++;


  DtEmpresa** dtemp =empleados[i]->EmpresasActivas(cantEmpresas);

  return dtemp;

};

int main()
{
  std::system("clear");
  while (!(terminar)){
    imprimirbienvenida();
    cin>>opcion;
    if (opcion=="1"){
        if (topempleado>=MAX_EMPLEADOS-1){ // Se chequea que el arreglo no este lleno
            cout << "No se pueden agregar mas empleados, presione una tecla y luego enter para continuar" << endl;
	        cin>> opcion;
	        std::system ("clear");
        } else {
          string Nombre;
          string Apellido;
          CI=pedirCI();
          cout << "Ingrese el nombre del empleado:" << endl;
          cin>> Nombre;
          cout << "Ingrese el apellido del empleado:" << endl;
          cin>> Apellido;
          dir=pedirDir();
          try {
            std::system ("clear");
            agregarEmpleado(CI,Nombre,Apellido,dir);
          }
          catch (exception& e){
                cout << e.what() << endl;
                cin>>opcion;
                std::system ("clear");
          }
        }
    }
    else if (opcion=="2"){
	    if (topempresa>=MAX_EMPRESAS-1){ //se chequea que el arreglo no este lleno
		    cout << "No se pueden agregar mas empresas, presione una tecla y luego enter para continuar" << endl;
		    cin>> opcion;
		    std::system ("clear");
	    }
	    else{
          string esNac;
          cout << "¿La empresa es Nacional? (S o N)" << endl;
          cin>> esNac;
          
          if ((esNac=="S") || (esNac=="s")){
            ID=pedirIdEmpresa();
            dir=pedirDir();
            string RUT;
            cout << "Ingrese el RUT de la empresa:" << endl;
            cin>>RUT;
            DtNacional *cA = new DtNacional(ID,dir,RUT); 
            try {
                std::system ("clear");
                agregarEmpresa(*cA);
            }catch (exception& e){
                cout << e.what() << endl;
                cin>>opcion;
                std::system ("clear");
            }
          } else if ((esNac=="N") || (esNac=="n")){
            ID=pedirIdEmpresa();
            dir=pedirDir();
            string NombreFantasia;
            cout << "Ingrese el nombre fantasia de la empresa:" << endl;
            cin>> NombreFantasia;
            DtExtranjera *cA = new DtExtranjera(ID,dir,NombreFantasia);
            try {
                std::system ("clear");
                agregarEmpresa(*cA);
            }catch (exception& e){
                cout << e.what() << endl;
                cin>>opcion;
                std::system ("clear");
            }
          } else {
            cout << "El valor ingresado no es correcto, presione una tecla y luego enter para continuar" << endl;
            cin>>opcion;
            std::system ("clear");
          }
        }
    }
    else if (opcion=="3"){

        ///////////////////////////////////////
      /////  listar empleados
      ///////////////////////////////////////
      if (topempleado==-1) {
         cout << "No hay empleados en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else {
        std::system ("clear");
        DtEmpleado** dt;
        dt = listarEmpleados(topempleado);
        int i = 0;
            while (i<=topempleado) {
                cout << *dt[i] << endl;
                cout << "Sueldo liquido total (suma de todos los sueldos): "<< empleados[i]->getSueldoNeto()<< endl << endl;
                i++;
        } 
            cout << "Presione una tecla y luego enter para continuar" << endl;
            cin>> opcion;
            std::system ("clear");
            for(int iter=0; iter<=topempleado;iter++){
                delete dt[iter];
            }
            delete[] dt;
        }
        
    }
    else if (opcion=="4"){
      ///////////////////////////////////////
      ///// Agregar relacion laboral
      ///////////////////////////////////////
      if ((topempresa==-1) && (topempleado==-1)){
         cout << "No hay empleados ni empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else if (topempresa==-1) {
         cout << "No hay empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else if (topempleado==-1) {
         cout << "No hay empleados en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else {
          CI=pedirCI();
          ID=pedirIdEmpresa();
          sueldo=pedirSueldo(); //el sueldo liquido se calcula solo adentro de la clase
          try {
            std::system ("clear");
            agregarRelacionLaboral(CI, ID,  sueldo);
          }  
          catch (exception& e){
                cout << e.what() << endl;
                cin>>opcion;
            }
     }
     }
    else if (opcion=="5"){
      //////////////////////
      ///// Finalizar relacion laboral
      ////////////////////// 
        
      if ((topempresa==-1) && (topempleado==-1)){
         cout << "No hay empleados ni empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else if (topempresa==-1) {
         cout << "No hay empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");
      } else if (topempleado==-1) {
         cout << "No hay empleados en el sistema, presione una tecla y luego enter para continuar" << endl;
         cin>>opcion;
         std::system ("clear");   
      }  else {
        int i=0;
        bool esta=false; 
        CI=pedirCI();
        while((i<=topempleado)&&(!esta)){
            if (empleados[i]->getCi() == CI){
                esta=true;
            }
            else{
                i=i+1;
            }
        }
    if (!esta){
        cout << "No existe el empleado, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
        std::system ("clear");
    } else {
      ID=pedirIdEmpresa();
          //Se busca empresa
        int j=0;
        bool estaemp=false; 
        while((j<=topempresa)&&(!estaemp)){
            if (empresas[j]->getEmpresaId() == ID){
                estaemp=true;
            }
            else{
                j++;
            }
        }
      if (!estaemp){
        cout << "No existe la empresa, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
		std::system ("clear");
      } else if (!empleados[i]->EmpresaAsociada(empresas[j]->getEmpresaId())) {
        cout << "No existe la relacion laboral, presione una tecla y luego enter para continuar"<<endl;
		cin>> opcion;
		std::system ("clear");
      } else {
          
        int anio;
          int mes;
          int dia;
          cout << "Ingrese año de desvinculacion:" << endl;
          cin>> anio; 
          cout <<"Ingrese mes de desvinculacion:" << endl;
          cin>> mes; 
          cout <<"Ingrese dia de desvinculacion:"<< endl;
          cin>> dia; 
          try {
             esValidaFecha(anio,mes,dia); 
             Fecha  fecha(dia,mes,anio);
            finalizarRelacionLaboral(CI,ID, fecha);
             std::system ("clear");
          } catch (exception& e){
                cout << e.what() << endl;
                cin>>opcion;
          }
        }
        }
    }
    }else if (opcion=="6"){
      //////////////////////////////////////
      //// obtener empresas activas del empleado
      ////////////////////////////
            if ((topempresa==-1) && (topempleado==-1)){
                 cout << "No hay empleados ni empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
                 cin>>opcion;
                 std::system ("clear");
              } else if (topempresa==-1) {
                 cout << "No hay empresas en el sistema, presione una tecla y luego enter para continuar" << endl;
                 cin>>opcion;
                 std::system ("clear");
              } else if (topempleado==-1) {
                 cout << "No hay empleados en el sistema, presione una tecla y luego enter para continuar" << endl;
                 cin>>opcion;
                 std::system ("clear");   
              }  else {
                    CI=pedirCI();
                    cout << "ingrese cantidad de empresas" << endl;
                    cin >> cantempresas;
                    if ((cantempresas<=topempresa+1) && (cantempresas>0)){ //se chequea que no se pidan mas empresas de las que hay en el sistema
                        int i=0;
                        bool existe= false;
                        while ((!existe)&&(i<=topempleado)){
                            if (empleados[i]->getCi()==CI){ 
                                existe=true;
                            }
                            i=i+1;
                        }
                        i=0;
                        if (existe) {           
                            std::system ("clear");
                            float* sueldos = empleados[i]->SueldosEmpresas();
                            DtEmpresa ** empre = obtenerInfoEmpresaPorEmpleado(CI,cantempresas);
                            while((i < cantempresas) ){
                                
                                cout << *empre[i] << endl;
                                DtNacional * den = dynamic_cast<DtNacional*> (&*empre[i]);
                                if(den){ 
                                    cout << *den;
                                }else{
                                    DtExtranjera * dee = (DtExtranjera*)(&*empre[i]);
                                    cout << *dee;
                                };    
                              cout<< "Sueldo: "<< sueldos[i] << endl << endl;
                              
                              i++;
                            }
                        cout << "Se muestran las " << i << " primeras, presione una tecla y luego enter para continuar" << endl;
                        cin>>opcion;
                        std::system ("clear");   
                        delete[] sueldos;
                     } else {
                         cout << "El empleado no existe, presione una tecla y luego enter para continuar" << endl;
                         cin>>opcion;
                         std::system ("clear");   
                    }
                } else if (cantempresas>0){
                    cout << "La cantidad de empresas no puede superar la cantidad de empresas en el sistema (o la cantidad de empresas maxima, presione una tecla y luego enter para continuar" << endl;
                    cin>>opcion;
                    std::system ("clear");
                } else {
                    cout << "La cantidad de empresas no puede ser 0, presione una tecla y luego enter para continuar" << endl;
                    cin>>opcion;
                    std::system ("clear");
                }
            }
    }
    else if (opcion=="7"){
      std::system ("clear");
      terminar=true;
    }
    else{
      cout << "El valor ingresado no es correcto, presione una tecla y luego enter para continuar" << endl;
      cin>>opcion;
      std::system("clear");
    }
  }
  
  
  for (int o=0;o<=topempleado;o++){
    delete empleados[o];
  }
  
  for (int o=0;o<=topempresa;o++){
    delete empresas[o];
  }

 
  return 0;
}



