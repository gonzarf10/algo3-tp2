//
// Created by gonza on 16/9/2023.
//

#ifndef EJERCICIO1_GRAFO_H
#define EJERCICIO1_GRAFO_H

#include <vector>
#include <set>
#include <list>
#include <bits/stdc++.h>

using namespace std;

using arista = pair<int, int>;
using conjuntoAristas = set<arista>;
using iterador = vector<int>::iterator;
using listaAdyacenciasConexiones = vector<vector<iterador>>;
using listaAdyacencias = vector<list<int>>;
using grados = vector<int>;
using matrizAdyacencia = vector<vector<bool>>;
using importante = pair<int, int>;

pair<matrizAdyacencia, grados> inicializar(int N, conjuntoAristas ca); // O(N^2)

vector<importante> buscarImportantes(int N, conjuntoAristas ca);

#endif //EJERCICIO1_GRAFO_H
