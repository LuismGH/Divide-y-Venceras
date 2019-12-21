/// @file sorted_vector.hpp
/// @brief Definiciones de la Clase Sorted Vector. Consiste en un
/// vector desordenado con una funcion mergesort para ordenarlo
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
#pragma once 
#include <vector>
#include <iostream>

using namespace std;

/// @class sorted_vector
class sorted_vector : public vector<int> {
	public:
    	sorted_vector(const vector<int>& = vector<int>());
    
    	void iterative_merge_sort();
    	void merge_sort();

	private:
    	void merge_sort(int, int);
    	void merge(int, int, int);
    	void merge(const vector<int>&, const vector<int>&, int);
    	void create_vector_sentinel(int, int, vector<int>&);    
};
ostream& operator<<(ostream&, const sorted_vector&);
