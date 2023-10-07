#include <iostream>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

using arista = pair<int, int>;
using conjuntoAristas = set<arista>;
using grados = vector<int>;
using matrizAdyacencia = vector<vector<bool>>;
using importante = pair<int, int>;


int NO_LO_VI = 0, EMPECE_A_VER = 1, TERMINE_DE_VER = 2;


vector<vector<int>> inicializar(int N, conjuntoAristas ca) {
    vector<vector<int>> aristas(N);

    for (arista ar: ca) {
        aristas[ar.first].push_back(ar.second);
        aristas[ar.second].push_back(ar.first);
    }

    return aristas;
}

void dfs(
        int v,
        vector<vector<int>> &tree_edges,
        vector<int> &estado,
        vector<vector<int>> &aristas,
        vector<int> &be_con_extremo_inferior_en,
        vector<int> &be_con_extremo_superior_en,
        int p = -1,
        pair<int, int> oculta = {-1, -1}
) {
    estado[v] = EMPECE_A_VER;
    for (int u: aristas[v]) {
        if ((v == oculta.first and u == oculta.second) or (u == oculta.first and v == oculta.second)) continue;
        if (estado[u] == NO_LO_VI) {
            tree_edges[v].push_back(u);
            dfs(u, tree_edges, estado, aristas, be_con_extremo_inferior_en, be_con_extremo_superior_en, v, oculta);
        } else if (u != p and estado[u] != TERMINE_DE_VER) {
            be_con_extremo_inferior_en[v]++;
            be_con_extremo_superior_en[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

int cubren(int v,
           vector<int> &memo,
           vector<int> &be_con_extremo_inferior_en,
           vector<int> &be_con_extremo_superior_en,
           vector<vector<int>> &tree_edges,
           int p = -1
) {

    if (memo[v] != -1) {
        //cout << "HIT" << v << endl;
        return memo[v];
    } else {
        //cout << "MISS" << v << endl;
    };
    int res = 0;
    for (int hijo: tree_edges[v]) {
        if (hijo != p) {
            res += cubren(hijo, memo, be_con_extremo_inferior_en, be_con_extremo_superior_en, tree_edges, v);
        }
    }
    res -= be_con_extremo_superior_en[v];
    res += be_con_extremo_inferior_en[v];
    memo[v] = res;
    return res;
}

bool hayPuentes(int n, vector<vector<int>> E, pair<int, int> oculta = {-1, -1}) {
    vector<int> estado(n), memo(n, -1), be_con_extremo_inferior_en(n), be_con_extremo_superior_en(n);
    vector<vector<int>> tree_edges(n);
    for (int i = 0; i < n; ++i) {
        vector<int> empty(n);
        tree_edges.push_back(empty);
    }

    dfs(0, tree_edges, estado, E, be_con_extremo_inferior_en, be_con_extremo_superior_en, -1, oculta);

    int puentes = 0;
    for (int i = 0; i < n; i++) {
        int c = cubren(i, memo, be_con_extremo_inferior_en, be_con_extremo_superior_en, tree_edges);
        if (c == 0) {
            puentes++;
        }
    }

    puentes -= 1; // 1 componente conexa
    return puentes > 0;
}

vector<importante> buscarImportantes(int N, conjuntoAristas ca) {
    vector<vector<int>> grafo = inicializar(N, ca);
    vector<importante> res;
    res.reserve(ca.size());

    for (auto arista: ca) {
        if (hayPuentes(N, grafo, arista)) {
            if (arista.first > arista.second) {
                res.emplace_back(arista.second, arista.first);
            } else {
                res.emplace_back(arista);
            }
        }
    }

    sort(res.begin(), res.end());

    return res;
}

pair<int, conjuntoAristas> pedir() {
    int n, m;
    cin >> n >> m;
    conjuntoAristas E;

    for (int i = 0; i < m; ++i) {
        pair<int, int> e;
        cin >> e.first >> e.second;
        E.insert(e);
    }

    return make_pair(n, E);
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i) {
        pair<int, conjuntoAristas> grafo = pedir();
        vector<importante> importantes = buscarImportantes(grafo.first, grafo.second);

        cout << importantes.size() << endl;

        for (auto imp: importantes) {
            cout << imp.first << " " << imp.second << endl;
        }
    }

    return 0;
}
