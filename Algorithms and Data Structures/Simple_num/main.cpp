//
//  main.cpp
//  Simple_num
//
//  Created by Rishat Valitov on 24.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    
    size_t countSimple = n / log(n);
    int* lp = new int[n+1];
    int* pt = new int[countSimple];
    for (int i=2; i<=n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    return 0;
}
