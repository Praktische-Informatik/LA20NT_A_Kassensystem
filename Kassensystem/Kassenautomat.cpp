#include "Kassenautomat.h"


//{ {1000, 50}, {500, 50}, {100, 50}, {50, 50}, {20, 50}, {10, 50}, {5, 50}, {2, 50}, {1, 50} }
vector<vector<int>> Kassenautomat::a{ {1000, 50}, {500, 50}, {100, 50}, {50, 50}, {20, 50}, {10, 50}, {5, 50}, {2, 50}, {1, 50} };


vector<vector<int>> Kassenautomat::berechneWechselgeldstuecke(int betrag){
    vector<vector<int>> b{ {1000, 0}, {500, 0}, {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}, {1, 0} };
    for (int i = 0; i < a.size() && betrag > 0; i++) {
        b[i][1] = betrag / a[i][0];
        betrag = betrag - a[i][1] * b[i][1];
        a[i][1] -= b[i][1];
    }  
    return b;
}
