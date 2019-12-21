/// @file sorted_vector.cpp
/// @brief Clase Sorted Vector. Consiste en un vector desordenado
/// con una funcion mergesort para ordenarlo
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
#include <climits>
#include <iomanip>

#include "../include/sorted_vector.hpp"

/// @brief Constructor por defecto
/// @param v Vector de numeros pasado por referencia, por defecto es un vector vacio
sorted_vector::sorted_vector(const vector<int>& v) : vector<int>(v) {}

/// @brief Merge Sort en su forma iterativa
void sorted_vector::iterative_merge_sort() {	

	for (size_t i = 1; i <= size() - 1; i *= 2) {
		for (size_t j = 0; j < size() - 1; j += 2 * i) {
			
			size_t right = j + (2*i) - 1;
			if (right > (size() - 1)) {
				right = size() - 1;
			}
			
			size_t c = j + i - 1;
			if (c > right) {
				c = (j + right) / 2;
			}
			merge(j, c, right);
		}
	}
}

/// @brief Inicia el algoritmo
void sorted_vector::merge_sort() {
	merge_sort(0, size() - 1);
}

/// @brief Divide el vector en varios subvectores haciendo llamadas recursivas
/// @param l Limite izquierdo del subvector
/// @param r Limite derecho del subvector
void sorted_vector::merge_sort(int l, int r) {
	if (l < r) {
		int c = (l + r) / 2;
		merge_sort(l, c);
		merge_sort(c + 1, r);
		merge(l, c, r);
	}
}

/// @brief Crea los subvectores y añade el centinela, una vez acaba, junta los subvectores
/// @param l Limite izquierdo del subvector
/// @param c Centro del subvector
/// @param r Limite derecho del subvector
void sorted_vector::merge(int l, int c, int r) {
	vector<int> v1, v2;
	create_vector_sentinel(l, c, v1);
	create_vector_sentinel(c + 1, r, v2);
	
	merge(v1, v2, l);
}

/// @brief Junta los subvectores y da como resultado vectores ordenados
/// @param v1 Subvector 1
/// @param v2 Subvector 2
/// @param l Limite izquierdo del vector resultado
void sorted_vector::merge(const vector<int>& v1, const vector<int>& v2, int l) {
	const int sz = v1.size() + v2.size() - 2;
	int inx1 = 0, inx2 = 0;
	
	for (int i = 0; i < sz; ++i) {
		if (v1[inx1] < v2[inx2]) {
			at(l + i) = v1[inx1];
			inx1++;
		}
		else {
			at(l + i) = v2[inx2];
			inx2++;
		}
	}
}

/// @brief Crea el centinela del subvector, añadiendo un infinito
/// @param l Limite izquierdo del subvector
/// @param r Limite derecho del subvector
/// @param v Subvector
void sorted_vector::create_vector_sentinel(int l, int r, vector<int>& v) {
	v.clear();
	for (int i = l; i <= r; ++i)
		v.push_back(at(i));
	v.push_back(INT_MAX);
}

/// @brief Sobrecarga del operador de Salida
ostream& operator<<(ostream& os, const sorted_vector& v) {
    os << "< ";
    for (size_t i = 0; i < v.size(); i++)
        os << setw(5) << v.at(i);
    os << " >";
    return os;
}
