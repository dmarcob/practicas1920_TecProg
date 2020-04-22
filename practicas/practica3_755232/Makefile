#*****************************************************************
# File:   Makefile_p2_e1
# Author: Diego Marco, 755232
# Date:   abril 2020
#*****************************************************************

#---------------------------------------------------------
RM = /bin/rm -f  # para limpiar
CC = g++         # para compilar
#---------------------------------------------------------
CPPFLAGS= -std=c++11     # opciones compilación
#---------------------------------------------------------
# vars
EJEC = main
BIBLIOTECA = practica3
all: ${EJEC} 
#---------------------------------------------------------
${EJEC}: ${EJEC}.o ${BIBLIOTECA}.o
	${CC} ${EJEC}.o ${BIBLIOTECA}.o -o ${EJEC} ${CPPFLAGS} 

#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cc
	${CC} -c ${EJEC}.cc ${CPPFLAGS}

${BIBLIOTECA}.o: ${BIBLIOTECA}.h ${BIBLIOTECA}.cc
	${CC} -c ${BIBLIOTECA}.cc ${CPPFLAGS}
#---------------------------------------------------------
clean:
	$(RM) ${EJEC}.o ${BIBLIOTECA}.o ${BIBLIOTECA} ${EJEC}

