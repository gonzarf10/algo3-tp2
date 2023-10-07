//
// Created by gonza on 7/9/2023.
//
#include "gtest-1.8.1/gtest.h"
#include "../grafo.h"

using namespace std;

void checkInicializar(pair<matrizAdyacencia, grados> &res, pair<matrizAdyacencia, grados> &resExpected, int N) {
    matrizAdyacencia &adyacencias = res.first;
    ASSERT_EQ(adyacencias.size(), N);

    for (int i = 0; i < adyacencias.size(); ++i) {
        ASSERT_EQ(adyacencias[i].size(), N);

        for (int j = 0; j < adyacencias[i].size(); ++j) {
            ASSERT_EQ(adyacencias[i][j], resExpected.first[i][j]);
        }
    }

    for (int i = 0; i < resExpected.second.size(); ++i) {
        ASSERT_EQ(res.second[i], resExpected.second[i]);
    }
}

void checkImportantes(vector<importante> &importantes, vector<importante> &expected) {
    ASSERT_EQ(importantes.size(), expected.size());

    for (int i = 0; i < importantes.size(); ++i) {
        ASSERT_EQ(importantes[i].first, expected[i].first);
        ASSERT_EQ(importantes[i].second, expected[i].second);
    }
}

/*TEST(tests_grafos, inicializarCaso1) {
    int N = 3;
    matrizAdyacencia resExpected = {
            {false, true,  true},
            {true,  false, true},
            {true,  true,  false},

    };
    grados gradosExpected = {2, 2, 2};

    pair<matrizAdyacencia, grados> res =
            inicializar(N, {
                    make_pair(0, 2),
                    make_pair(2, 1),
                    make_pair(1, 0)
            });

    pair<matrizAdyacencia, grados> r = make_pair(resExpected, gradosExpected);

    checkInicializar(res, r, N);
}

TEST(tests_grafos, inicializarCaso2) {
    int N = 4;
    matrizAdyacencia resExpected = {
            {false, true,  true,  true},
            {true,  false, true,  true},
            {true,  true,  false, true},
            {true,  true,  true,  false},
    };

    pair<matrizAdyacencia, grados> res =
            inicializar(N, {
                    make_pair(0, 1),
                    make_pair(0, 2),
                    make_pair(0, 3),
                    make_pair(1, 2),
                    make_pair(1, 3),
                    make_pair(2, 3),
            });
    grados gradosExpected = {3, 3, 3, 3};

    pair<matrizAdyacencia, grados> r = make_pair(resExpected, gradosExpected);

    checkInicializar(res, r, N);
}

TEST(tests_grafos, inicializarCaso3) {
    int N = 6;
    matrizAdyacencia resExpected = {
            {false, true,  true,  false, false, false},
            {true,  false, true,  false, false, false},
            {true,  true,  false, true,  true,  true},
            {false, false, true,  false, true,  true},
            {false, false, true,  true,  false, false},
            {false, false, true,  true,  false, false},
    };
    grados gradosExpected = {2, 2, 5, 3, 2, 2};


    pair<matrizAdyacencia, grados> res =
            inicializar(N, {
                    make_pair(0, 2),
                    make_pair(2, 1),
                    make_pair(1, 0),
                    make_pair(2, 3),
                    make_pair(3, 4),
                    make_pair(4, 2),
                    make_pair(2, 5),
                    make_pair(5, 3),
            });
    pair<matrizAdyacencia, grados> r = make_pair(resExpected, gradosExpected);

    checkInicializar(res, r, N);
}

TEST(tests_grafos, inicializarVacio) {
    int N = 3;
    matrizAdyacencia resExpected = {
            {false, false, false},
            {false, false, false},
            {false, false, false},

    };
    grados gradosExpected = {0, 0, 0};


    pair<matrizAdyacencia, grados> res =
            inicializar(N, {
            });

    pair<matrizAdyacencia, grados> r = make_pair(resExpected, gradosExpected);

    checkInicializar(res, r, N);
}

TEST(tests_grafos, inicializarVacio1) {
    int N = 0;
    matrizAdyacencia resExpected = {

    };
    grados gradosExpected = {};


    pair<matrizAdyacencia, grados> res =
            inicializar(N, {
            });

    pair<matrizAdyacencia, grados> r = make_pair(resExpected, gradosExpected);

    checkInicializar(res, r, N);
}*/

TEST(tests_grafos, caso1) {
    int N = 3;
    conjuntoAristas aristas = {
            make_pair(0, 2),
            make_pair(2, 1),
            make_pair(1, 0)
    };
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {make_pair(0, 1), make_pair(0, 2), make_pair(1, 2)};

    checkImportantes(importantes, expected);
}

TEST(tests_grafos, caso2) {
    int N = 4;
    conjuntoAristas aristas = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(0, 3),
            make_pair(1, 2),
            make_pair(1, 3),
            make_pair(2, 3),
    };
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);
    vector<importante> expected = {};

    checkImportantes(importantes, expected);

}

TEST(tests_grafos, caso3) {
    int N = 6;
    conjuntoAristas aristas = {
            make_pair(0, 2),
            make_pair(2, 1),
            make_pair(1, 0),
            make_pair(2, 3),
            make_pair(3, 4),
            make_pair(4, 2),
            make_pair(2, 5),
            make_pair(5, 3),
    };
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(1, 2),
            make_pair(2, 4),
            make_pair(2, 5),
            make_pair(3, 4),
            make_pair(3, 5),
    };

    checkImportantes(importantes, expected);
}

TEST(tests_grafos, caso4) {
    conjuntoAristas aristas = {
            make_pair(1, 3),
            make_pair(3, 2),
            make_pair(3, 0),
            make_pair(2, 0),
            make_pair(1, 0),
            make_pair(0, 4),
            make_pair(4, 5),
            make_pair(0, 5),
    };
    int N = 6;
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(0, 4),
            make_pair(0, 5),
            make_pair(1, 3),
            make_pair(2, 3),
            make_pair(4, 5),
    };

    checkImportantes(importantes, expected);
}

TEST(tests_grafos, caso5) {
    conjuntoAristas aristas = {
            make_pair(3, 0),
            make_pair(3, 2),
            make_pair(0, 2),
            make_pair(2, 1),
            make_pair(1, 0),
    };
    int N = 4;
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {
            make_pair(0, 1),
            make_pair(0, 3),
            make_pair(1, 2),
            make_pair(2, 3),
    };

    checkImportantes(importantes, expected);
}

TEST(tests_grafos, caso6) {
    conjuntoAristas aristas = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(0, 3),
            make_pair(0, 4),
            make_pair(2, 3),
            make_pair(2, 1),
            make_pair(3, 4),
    };
    int N = 5;
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {
            make_pair(0, 1),
            make_pair(0, 4),
            make_pair(1, 2),
            make_pair(3, 4),
    };

    checkImportantes(importantes, expected);
}

TEST(tests_grafos, caso7) {
    conjuntoAristas aristas = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(0, 3),
            make_pair(0, 4),
            make_pair(2, 3),
            make_pair(2, 1),
            make_pair(3, 5),
            make_pair(5, 4),
            make_pair(1, 5),
    };
    int N = 6;
    vector<vector<int>> listaAd = inicializar(N, aristas);
    vector<importante> importantes = buscarImportantes(N, aristas, listaAd);

    vector<importante> expected = {
            make_pair(0, 4),
            make_pair(4, 5),
    };

    checkImportantes(importantes, expected);
}

TEST(test_hay_puentes, 1) {
    int n = 3;
    vector<vector<int>> E = {
            {1, 2},
            {0, 2},
            {0, 1}
    };

    EXPECT_FALSE(hayPuentes(n, E, {-1, -1}));
}

TEST(test_hay_puentes, 2) {
    int n = 3;
    vector<vector<int>> E = {
            {2},
            {2},
            {0, 1}
    };

    EXPECT_TRUE(hayPuentes(n, E, {-1, -1}));
}

TEST(test_hay_puentes, 3) {
    int n = 4;
    vector<vector<int>> E = {
            {1, 2, 3},
            {0, 2, 3},
            {0, 1, 3},
            {0, 1, 2}
    };

    EXPECT_FALSE(hayPuentes(n, E, {-1, -1}));
}

TEST(test_hay_puentes, oculta1) {
    int n = 3;
    vector<vector<int>> E = {
            {1, 2},
            {0, 2},
            {0, 1}
    };

    EXPECT_TRUE(hayPuentes(n, E, {0, 1}));
}

TEST(test_hay_puentes, oculta2) {
    int n = 4;
    vector<vector<int>> E = {
            {1, 2, 3},
            {0, 2},
            {0, 1, 3},
            {0, 2}
    };

    EXPECT_TRUE(hayPuentes(n, E, {0, 1}));
    EXPECT_FALSE(hayPuentes(n, E, {0, 2}));
}