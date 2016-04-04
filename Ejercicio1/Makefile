todo: Lab1
main.o: main.cpp include/Direccion.h include/DtEmpresa.h include/DtNacional.h include/DtExtranjera.h include/DtEmpleado.h include/Empresa.h include/Extranjera.h include/Nacional.h include/Empleado.h include/Fecha.h
	g++ -Wall -Werror -c main.cpp 
Empleado.o: cpp/Empleado.cpp include/Empleado.h include/Direccion.h include/RelacionLaboral.h include/DtEmpleado.h include/DtEmpresa.h include/Nacional.h include/Extranjera.h include/DtNacional.h include/DtExtranjera.h
	g++ -Wall -Werror -c cpp/Empleado.cpp 
Empresa.o: cpp/Empresa.cpp include/Empresa.h include/Direccion.h
	g++ -Wall -Werror -c cpp/Empresa.cpp 
Extranjera.o: cpp/Extranjera.cpp include/Extranjera.h include/Direccion.h include/Empresa.h include/DtEmpresa.h 
	g++ -Wall -Werror -c cpp/Extranjera.cpp
Fecha.o: cpp/Fecha.cpp include/Fecha.h 
	g++ -Wall -Werror -c cpp/Fecha.cpp	
Nacional.o: cpp/Nacional.cpp include/Nacional.h include/Direccion.h include/Empresa.h include/DtEmpresa.h
	g++ -Wall -Werror -c cpp/Nacional.cpp		
DtNacional.o: cpp/DtNacional.cpp include/DtNacional.h include/Direccion.h include/DtEmpresa.h
	g++ -Wall -Werror -c cpp/DtNacional.cpp	
DtExtranjera.o: cpp/DtExtranjera.cpp include/DtExtranjera.h include/Direccion.h include/DtEmpresa.h
	g++ -Wall -Werror -c cpp/DtExtranjera.cpp	
Direccion.o: cpp/Direccion.cpp include/Direccion.h 
	g++ -Wall -Werror -c cpp/Direccion.cpp
DtEmpleado.o: cpp/DtEmpleado.cpp include/DtEmpleado.h include/DtEmpresa.h include/Direccion.h include/Empleado.h 
	g++ -Wall -Werror -c cpp/DtEmpleado.cpp
DtEmpresa.o: cpp/DtEmpresa.cpp include/DtEmpresa.h  include/Direccion.h 
	g++ -Wall -Werror -c cpp/DtEmpresa.cpp
RelacionLaboral.o: cpp/RelacionLaboral.cpp include/RelacionLaboral.h include/Fecha.h include/Empresa.h
	g++ -Wall -Werror -c cpp/RelacionLaboral.cpp
Lab1: main.o Empleado.o Empresa.o Extranjera.o Fecha.o Nacional.o DtNacional.o DtExtranjera.o Direccion.o DtEmpleado.o DtEmpresa.o RelacionLaboral.o
	g++ -Wall -Werror main.o Empleado.o Empresa.o Extranjera.o Fecha.o Nacional.o DtNacional.o DtExtranjera.o Direccion.o DtEmpleado.o DtEmpresa.o RelacionLaboral.o -o Lab1
