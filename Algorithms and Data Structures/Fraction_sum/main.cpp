//
//  main.cpp
//  Fraction_sum
//
//  Created by Rishat Valitov on 24.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

// 1.3 Программа для нахождения несократимой суммы двух дробей

#include <iostream>
#include <stdio.h>

using namespace std;

// Наибольший общий делитель Евклид
int NOD(int first, int second)
{
    while (second)
    {
        int temp=second;
        
        second=first % second;
        first = temp;
    }
    return first;
}

// Сумма двух дробей
int* sum_fractions(int num_frst, int deno_frst, int num_scnd,  int deno_scnd)
{
    int* answer = new int[2];
    
    answer[1] = deno_frst*deno_scnd;
    answer[0] = (num_frst * deno_scnd) + (num_scnd * deno_frst);
    
    return answer;
}

// Находит сумму и сокращает
int* irreducible_fraction__sum(int num_frst, int deno_frst, int num_scnd,  int deno_scnd)
{
    int* answer = sum_fractions(num_frst, deno_frst, num_scnd, deno_scnd);
    
    int nod = NOD(answer[0], answer[1]);
    
    if (nod)
    {
        answer[0] /= nod;
        answer[1] /= nod;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int num_frst, deno_frst, num_scnd,  deno_scnd;
    
    cin >> num_frst >> deno_frst >> num_scnd >> deno_scnd;
    
    int* answer = irreducible_fraction__sum(num_frst, deno_frst, num_scnd, deno_scnd);
    cout << answer[0] << ' ' << answer[1];
    delete[] answer;
    return 0;
}
