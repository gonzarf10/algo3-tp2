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
using grados = vector<int>;
using matrizAdyacencia = vector<vector<bool>>;
using importante = pair<int, int>;

vector<vector<int>> inicializar(int N, conjuntoAristas ca); // O(N^2)

vector<importante> buscarImportantes(int N, conjuntoAristas ca);

int cubren(int v,
           vector<int> &memo,
           vector<int> &be_con_extremo_inferior_en,
           vector<int> &be_con_extremo_superior_en,
           vector<vector<int>> &tree_edges,
           int p
);

void dfs(
        int v,
        vector<vector<int>> &tree_edges,
        vector<int> &estado,
        vector<vector<int>> &aristas,
        vector<int> &be_con_extremo_inferior_en,
        vector<int> &be_con_extremo_superior_en,
        int p,
        pair<int, int> oculta
);

bool hayPuentes(int n, vector<vector<int>> E, pair<int,int> oculta);

#endif //EJERCICIO1_GRAFO_H
