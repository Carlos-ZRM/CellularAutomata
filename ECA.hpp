//
//  ECA.hpp
//  ECA_C
//
//  Created by Carlos Reyes on 25/12/17.
//  Copyright © 2017 Carlos Reyes. All rights reserved.
//

#ifndef ECA_hpp
#define ECA_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

void ECA(int rule, int l, int times );
void ECA(int rules, int l, int times, int block);
/**
 evolucion de un automata celular dados todos los parametros de entrada
 */
void evolution ( int * x, int * xi);
/**
 evolucion de un automata celular dados todos los parametros de entrada
    y devuelve un arreglo con las densidades de las configuraciones locales.
 */
int *  evolutionH ( int * x, int * xi);
/**
 evolucion de un automata celular dada una matriz para buscar la morfologias evolutivas
 */
void evolution( int ** x, int block);
/**
    devuelve el numero de unos de una configuracion local
 */
int count (int * x);
/**
 funcion de evolucion.
 */
int fi (int x, int y, int z );
/**
 agrega una configuracion inicial o semilla a una configuracion local
 */
void seed(int * x, char * s, int t);

/**
 metodo auxiliar para encontrar patrones.
 */
void recorrer(int ** matriz, int block);
/**
 genera las configuraciones posibles 
 */
string word(int ** matriz, int x, int y , int block);
void reglaGlobal(int * x, int * y);
void checkVector( std::vector<string> lista , string s);
void printVector( std::vector<string> lista );
void Histograma();
void Morphological();
void Elementary();

#endif /* ECA_hpp */
