//
//  main.cpp
//  Pyramid
//
//  Created by Rishat Valitov on 28.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.

//Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду. Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего. N  ≤ 300.
#include <iostream>
#include <math.h>

using namespace std;

long long get_number_of_different_summand(int number)
{
    long long answer = 1;
    
    long long** array_cache = new long long* [number];
    
    // Обьявление
    for(int i = 0; i < number; i++)
    {
        array_cache[i] = new long long[number];
        for(int j = 0; j < number; j++)
        {
            array_cache[i][j] = 0;
        }
    }
    
    // Заполняем динамику
    for (int i=1; i <= number -1; i++)
    {
        array_cache[number-i][i] = 1;
    }
    
    for (int i = number-1; i >= 1; i--)
    {
        for(int j=1; j <= number-i; j++)
        {
            for( int q = j + 1; q <= i; q++)
            {
                array_cache[i-q][q]=array_cache[i-q][q]+array_cache[i][j];
            }
        }
    }
    
    // Подсчет ответа
    for(int i = 1; i <= number-1; i++)
    {
        answer+=array_cache[0][i];
    }
    return answer;
}

int main(int argc, const char * argv[])
{
    int number = 0;

    cin >> number;
        
    long long answer = get_number_of_different_summand(number);
        
    cout << answer;
    
    return 0;
}
