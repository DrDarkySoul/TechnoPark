//
//  main.cpp
//  Intersection_sets
//
//  Created by Rishat Valitov on 28.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.

//3_3.  Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n­1] и B[0..m­1]. n >> m. Найдите их пересечение. Требуемое время работы: O(m * log k), где k ­ позиция элементта B[m­1] в массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i­1]. n, k ≤ 10000.
#include <iostream>
#include <stdlib.h>

using namespace std;

// Бинарный поиск для элемента B[i]
int binary_search_custom(int* array, int first_el_index, size_t array_size, int searched_el, bool check_last_el)
{
    int first_el = first_el_index;
    int last_el = (int)array_size;
    
    if(array_size == 0)
    {
        return -1;
    }
    else if (array[first_el_index] > searched_el)
    {
        return -1;
    }
    else if (array[array_size-1] < searched_el)
    {
        return -1;
    }
    
    while(first_el<last_el)
    {
        int middle_el = first_el + (last_el - first_el)/2;
        
        if (searched_el <= array[middle_el])
        {
            last_el = middle_el;
        }
        else
        {
            first_el = middle_el + 1;
        }
    }
    
    if(check_last_el)
    {
        return last_el;
    }
    else
    {
        if (array[last_el] == searched_el)
        {
            return last_el;
        }
        else
        {
            return -1;
        }
    }
}

/* Функция ответ
 Идем по второму массиву и ищем пересечения с первым
 Запоминаем максимальный элемент из первого, чтобы последующий поиск начать с него
 т.к. массивы упорядочены сравниваем до элементов больше исходного
 */
int* get_intersection(int* first_array,  int* second_array, size_t first_array_size, size_t second_array_size, size_t& intersection_size)
{
    int* answer = new int[intersection_size];
    intersection_size = 0;
    int last_searched_el_index = 0;
    
    int top_limit_index = binary_search_custom(first_array, last_searched_el_index, first_array_size, second_array[second_array_size-1], true);
    
    if(top_limit_index == -1)
    {
        top_limit_index = (int)first_array_size;
    }
    else
    {
        top_limit_index++;
    }
    
    for(int i = 0; i < second_array_size; i++)
    {
        int check = binary_search_custom(first_array, last_searched_el_index, top_limit_index, second_array[i], false);
        if (check != -1)
        {
                answer[intersection_size] = second_array[i];
                intersection_size++;
                last_searched_el_index = check;
        }
    }
    return answer;
}

int main(int argc, const char * argv[])
{
    size_t first_array_size = 0;
    size_t  second_array_size = 0;
    
    cin >> first_array_size;
    cin >> second_array_size;
    
    size_t intersection_size = min(first_array_size, second_array_size);
    
    int* first_array = new int[first_array_size];
    int* second_array = new int[second_array_size];
    
    for (int i = 0; i < first_array_size; i++)
    {
        cin >> first_array[i];
    }
    for (int i = 0; i < second_array_size; i++)
    {
        cin >> second_array[i];
    }
    
    int* answer = get_intersection(first_array, second_array, first_array_size, second_array_size, intersection_size);
    
    for(int i = 0; i < intersection_size; i++)
    {
        cout << answer[i] << ' ';
    }
    
    delete[] first_array;
    delete[] second_array;
    delete[] answer;
    
    return 0;
}
