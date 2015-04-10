#Variables
c = g++
PRINCIPAL = DOM_Tree.h
debug = -ggdb
EXE =p
#Compilando y Ejecutando
PRINCIPAL:
	@ clear
	@ echo --- Makefile ---    Compilando ...
	@ $(c) $(PRINCIPAL) -o $(EXE)
	@ echo
	@ echo
	@ echo --- Makefile: Ejecutando ---
	@ echo
#Ejecutable
	@ ./$(EXE) 

#Eliminando Temporales
borrar:
	rm DOM_Tree
	rm *.o *~
