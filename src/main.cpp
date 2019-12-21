/// @file main.cpp
/// @brief Codigo principal del programa.
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingenieria y Tecnologia\n
/// Grado en Ingenieria Informatica\n
/// Asignatura: Computabilidad y Algoritmia (CyA)\n
/// Curso: 2º\n
/// Practica #13: Algoritmos Divide y Venceras (Divide & Conquer)
/// @date 18/12/2019
/// @see Enunciado de la practica:
/// https://campusvirtual.ull.es/1920/mod/assign/view.php?id=21022
//////////////////////////////////////////////////////////////////
#include <random>
#include <chrono>
#include <cstdio>
#include <getopt.h>

#include "../include/sorted_vector.hpp"

#define LIMIT 999
#define SIZE  10

void help();
void error();

/// @brief Argumentos del programa
const option long_options[] = { {"help", 0, 0, 'h'}, {0, 0, 0, 0} };


/// @brief Crea un vector desordenado aleatorio, y entonces lo ordena mediante el mergesort
/// @param argc Numero de Argumentos
/// @param argv Vector de Argumentos
int main(int argc, char** argv) {
	
	int c, option_index;
    while ((c = getopt_long (argc, argv, "h", long_options, &option_index)) != -1) {
     	switch (c) {
      		case 'h':
      			help();
        		return 0;
        	case '?':
        		break;
        	default:
        		error();
        		return 1;
      	}
    }
    
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT);        
    
	sorted_vector v, x;
    for(int i = 0; i < SIZE; ++i)
        v.push_back(distribution(generator));
	x = v;
	
	cout << endl <<  "< |Merge Recursivo| >" << endl;
    cout << v << endl;
    v.merge_sort();
    cout << v << endl;
    
    cout << endl <<  "< |Merge Iterativo| >" << endl;
    cout << x << endl;
    x.merge_sort();
    cout << x << endl;
    
	return 0;
}

/// @brief Guia para los usuarios
void help() 
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Ejecución del Programa: ./Divide-and-Conquer"                                    << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Una vez iniciado el programa, se generará un vector aleatorio con el cual"       << endl;
	cout << "se procederá a aplicar el algoritmo mergesort para ordenarlo, una vez hecho"     << endl;
	cout << "se mostrará el resultado"                                                        << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}

/// @brief Mensaje de error
void error() {
	cout << "Modo de empleo: ./Divide-and-Conquer"                      << endl;
	cout << "Pruebe ’./Divide-and-Conquer --help’ para más información"	<< endl;
}
