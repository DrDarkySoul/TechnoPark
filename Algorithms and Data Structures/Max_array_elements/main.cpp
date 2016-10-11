//
//  main.cpp
//  Max_array_elements
//
//  Created by Rishat Valitov on 24.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

//2.1 Даны два массива целых чисел одинаковой длины A[0..n­1] и B[0..n­1]. Необходимо найти  первую  пару индексов i0 и j0,  i0 ≤ j0 , такую что A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i < n, 0 <= j < n,  i <= j }. Время работы ­ O(n).
#include <iostream>
#include <stdio.h>

using namespace std;

/* Функция ответа
 Идем по массиву, запоминаем максимумы обоих массивов и сумму максимальных
 Возвращаем индексы максимальных
 Сложность линейная*/
int* max_sum_of_arrays(int* arr_frst, int* arr_scnd, size_t frst_arr_size,  size_t scnd_arr_size)
{
    int* answer = new int[2];
    
    int max_el_frst = arr_frst[0];
    int max_el_scnd = arr_scnd[0];
    
    int max_el_frst_index = 0;
    
    int max_sum = max_el_frst + max_el_scnd;
    
    for(int i = 1; i < frst_arr_size; i++)
    {
        max_el_scnd = arr_scnd[i];
            
        if(max_el_frst< arr_frst[i])
        {
            max_el_frst = arr_frst[i];
            max_el_frst_index = i;
        }
        if(max_sum < max_el_frst+max_el_scnd)
        {
            max_sum = max_el_frst+max_el_scnd;
            answer[0] = max_el_frst_index;
            answer[1] = i;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    int* frst_arr = new int[n];
    int* scnd_arr = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> frst_arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> scnd_arr[i];
    }
    
    int* answer = max_sum_of_arrays(frst_arr, scnd_arr, n, n);
    
    cout << answer[0] << ' ' << answer[1];
    
    delete[] frst_arr;
    delete[] scnd_arr;
    delete[] answer;
    
    return 0;
}
