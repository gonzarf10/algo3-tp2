//
// Created by gonza on 16/9/2023.
//
#include "grafo.h"

pair<matrizAdyacencia, grados> inicializar(int N, conjuntoAristas ca) {
    matrizAdyacencia matriz(N);
    grados grad(N, 0);
    vector<bool> fila(N, false);


    for (int i = 0; i < N; ++i) { // O(N)
        matriz[i] = fila;
    }

    for (arista ar: ca) {
        matriz[ar.first][ar.second] = true;
        matriz[ar.second][ar.first] = true;

        grad[ar.first] += 1;
        grad[ar.second] += 1;
    }


    return make_pair(matriz, grad);
}

bool compareInterval(importante i1, importante i2) {
    return i1.first < i2.first;
}

vector<importante> buscarImportantes(int N, conjuntoAristas ca) {
    pair<matrizAdyacencia, grados> grafo = inicializar(N, ca);
    vector<importante> res;

    matrizAdyacencia &adyacencias = grafo.first;
    grados &gradosGrafo = grafo.second;

    for (int i = 0; i < adyacencias.size(); ++i) {
        if (gradosGrafo[i] <= 2) {
            for (int j = 0; j < adyacencias[i].size(); ++j) {
                if (adyacencias[i][j]) {
                    if (j > i) {
                        res.push_back(make_pair(i, j));
                    } else {
                        res.push_back(make_pair(j, i));
                    }
                    adyacencias[j][i] = false;
                }
            }
        }
    }

    sort(res.begin(), res.end(), compareInterval);

    return res;
}
