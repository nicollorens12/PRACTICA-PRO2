OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Area_Magatzem.o Cjt_Contenidors.o Hilera.o Segmento.o Contenedor.o Ubicacion.o
	g++ -o program.exe program.o Area_Magatzem.o Cjt_Contenidors.o Hilera.o Segmento.o Contenedor.o Ubicacion.o
	rm *.o

Area_Magatzem.o: Area_Magatzem.cc Area_Magatzem.hh
	g++ -c Area_Magatzem.cc $(OPCIONS)

Cjt_Contenidors.o: Cjt_Contenidors.cc Cjt_Contenidors.hh
	g++ -c Cjt_Contenidors.cc $(OPCIONS)

Hilera.o: Hilera.cc Hilera.hh
	g++ -c Hilera.cc $(OPCIONS)

Segmento.o: Segmento.cc Segmento.hh
	g++ -c Segmento.cc $(OPCIONS)

Contenedor.o: Contenedor.cc Contenedor.hh
	g++ -c Contenedor.cc $(OPCIONS)

Ubicacion.o: Ubicacion.cc Ubicacion.hh
	g++ -c Ubicacion.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)


clean:
	rm *.o
	rm *.exe

practica.tar:
	tar -cvf practica.tar *.cc *.hh Makefile
