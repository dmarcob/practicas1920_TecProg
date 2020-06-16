#*****************************************************************
# File:   Makefile
# Author: Diego Marco, 755232
# Date:   junio 2020
#*****************************************************************

#---------------------------------------------------------
RM = /bin/rm -f  # para limpiar
CC = g++         # para compilar
#---------------------------------------------------------
CPPFLAGS= -std=c++11     # opciones compilación
#---------------------------------------------------------
# vars
EJEC = main
BIBLIOTECA = ejercicio4
all: ${EJEC} 
#---------------------------------------------------------
${EJEC}: ${EJEC}.o ${BIBLIOTECA}.o
	${CC} ${EJEC}.o ${BIBLIOTECA}.o -o ${EJEC} ${CPPFLAGS} 

#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cpp
	${CC} -c ${EJEC}.cpp ${CPPFLAGS}

${BIBLIOTECA}.o: ${BIBLIOTECA}.hpp ${BIBLIOTECA}.cpp
	${CC} -c ${BIBLIOTECA}.cpp ${CPPFLAGS}
#---------------------------------------------------------
clean:
	$(RM) ${EJEC}.o ${BIBLIOTECA}.o ${BIBLIOTECA} ${EJEC}

