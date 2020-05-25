#*****************************************************************
# File:   Makefile
# Author: Diego Marco, 755232
# Date:   mayo 2020
#*****************************************************************

#---------------------------------------------------------
RM = /bin/rm -f  # para limpiar
CC = g++         # para compilar
#---------------------------------------------------------
CPPFLAGS= -std=c++11     # opciones compilación
#---------------------------------------------------------
# vars
EJEC = main
NODO = nodo
EXCEPCION = excepcion
DIRECTORIO = directorio
FICHERO = fichero
ENLACE = enlace
RUTA = ruta
all: ${EJEC} 
#---------------------------------------------------------
${EJEC}: ${EJEC}.o ${NODO}.o ${EXCEPCION}.o ${DIRECTORIO}.o ${FICHERO}.o  ${RUTA}.o 
	${CC} ${EJEC}.o ${NODO}.o ${EXCEPCION}.o ${DIRECTORIO}.o ${FICHERO}.o ${ENLACE}.h ${RUTA}.o  -o ${EJEC} ${CPPFLAGS} 

#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cc
	${CC} -c ${EJEC}.cc ${CPPFLAGS}


${NODO}.o: ${NODO}.h ${NODO}.cc
	${CC} -c ${NODO}.cc ${CPPFLAGS}

${EXCEPCION}.o: ${EXCEPCION}.h ${EXCEPCION}.cc
	${CC} -c ${EXCEPCION}.cc ${CPPFLAGS}


${DIRECTORIO}.o: ${DIRECTORIO}.h ${DIRECTORIO}.cc
	${CC} -c ${DIRECTORIO}.cc ${CPPFLAGS}

${FICHERO}.o: ${FICHERO}.h ${FICHERO}.cc
	${CC} -c ${FICHERO}.cc ${CPPFLAGS}


${RUTA}.o: ${RUTA}.h ${RUTA}.cc
	${CC} -c ${RUTA}.cc ${CPPFLAGS}
#---------------------------------------------------------
clean:
	$(RM) ${EJEC}.o ${NODO}.o ${EXCEPCION}.o ${DIRECTORIO}.o ${FICHERO}.o  ${RUTA}.o ${EJEC}

