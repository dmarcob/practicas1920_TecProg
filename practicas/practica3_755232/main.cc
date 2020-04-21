#include "practica3.h"
#include <iostream>

int main(int argc, char** argv)
{
	Camion camion(10);

	Contenedor<Generico> contenedor_generico(4);
	Contenedor<Toxico>   contenedor_toxico(3);
	Contenedor<SerVivo>  contenedor_servivo(2);
	Producto             apuntes_tepro(1.0,0.1,"Apuntes de Tecnologia de Programacion");

	Producto longaniza_graus(0.5,0.8,"Longaniza de Graus");
	contenedor_generico.guardar(longaniza_graus);

	Toxico discos_melendi(1,20,"Discos de Melendi");
	// contenedor_generico.guardar(discos_melendi); //Esto no deberia compilar
	contenedor_toxico.guardar(discos_melendi);

	SerVivo elvis_presley(0.1,100,"Elvis Presley");
	//camion.guardar(elvis_presley); //Esto no deberia compilar
	contenedor_servivo.guardar(elvis_presley);

	if (!camion.guardar(contenedor_generico)) std::cout<<"Camion lleno con contenedor generico"<<std::endl;
	if (!camion.guardar(contenedor_toxico))   std::cout<<"Camion lleno con contenedor toxico"<<std::endl;
	if (!camion.guardar(contenedor_servivo))  std::cout<<"Camion lleno con contenedor de seres vivos"<<std::endl;
	if (!camion.guardar(apuntes_tepro))       std::cout<<"Camion lleno con apuntes de tepro"<<std::endl;

	Producto trenzas_almudevar(0.5,0.8,"Trenzas de Almudevar");
	if (!camion.guardar(trenzas_almudevar))   std::cout<<"Camion lleno con trenzas de Almudevar"<<std::endl;
	std::cout<<camion.to_string()<<std::endl;

/* La salida del programa hasta aquí deberia ser parecida a lo siguiente

Camion lleno con trenzas de Almudevar
Camion [10 m3] [120.9 kg]
   Contenedor de genéricos [4 m3] [0.8 kg]
      Longaniza de Graus [0.5 m3] [0.8 kg]
   Contenedor de productos tóxicos [3 m3] [20 kg]
      Discos de Melendi [1 m3] [20 kg]
   Contenedor de seres vivos [2 m3] [100 kg]
      Elvis Presley [0.1 m3] [100 kg]
   Apuntes de Tecnologia de Programacion [1 m3] [0.1 kg]
*/


	Contenedor<Generico> otro_contenedor_generico(1);
	Contenedor<Toxico>   otro_contenedor_toxico(1);
	Contenedor<SerVivo>  otro_contenedor_servivo(1);
	contenedor_generico.guardar(otro_contenedor_generico);
	contenedor_generico.guardar(otro_contenedor_toxico);
	contenedor_generico.guardar(otro_contenedor_servivo);
	//contenedor_generico.guardar(camion); //Esto no deberia compilar
	//contenedor_toxico.guardar(otro_contenedor_toxico); //Esto no deberia compilar
	//contenedor_servivo.guardar(otro_contenedor_servivo); //Esto no deberia compilar
}

