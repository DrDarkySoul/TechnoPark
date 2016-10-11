//
//  main.cpp
//  Annagram
//
//  Created by Rishat Valitov on 28.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.

//Пара слов называется стековой анаграммой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова). Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные. Длина анаграммы ≤ 10000.
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class CStack
{
    char *buffer;
    size_t buffer_size;
    int top;
public:
    CStack(size_t);
    ~CStack();
    
    void push(char);
    int pop();
    bool is_empty() const;
};

CStack::CStack(size_t _buffer_size):
buffer_size(_buffer_size),
top(-1)
{
    buffer = new char[buffer_size];
}

CStack::~CStack()
{
    delete [] buffer;
}

void CStack::push(char number)
{
    assert(top+1 < buffer_size);
    buffer[++top] = number;
}

int CStack::pop()
{
    assert(top != -1);
    return buffer[top--];
}

bool CStack::is_empty()const
{
    return top == -1;
}

/* Функция ответ
 Пробуем преобразовать слово из первого стэка в слово во втором с использованием третьего
 */
bool is_stack_annagram(const string& first, const string& second)
{
    size_t string_size_f = first.length();
    size_t string_size_s = second.length();
    
    if (string_size_f != string_size_s)
    {
        return false;
    }
    
    CStack stack = CStack(string_size_s);
    CStack first_stack = CStack(string_size_s);
    CStack second_stack = CStack(string_size_s);
    
    for(int i = 1; i<=string_size_f; i++)
    {
        first_stack.push(first[string_size_f - i]);
        second_stack.push(second[string_size_s - i]);
    }

    while(!first_stack.is_empty())
    {
        if(second_stack.is_empty())
        {
            return true;
        }
        
        if(!stack.is_empty())
        {
            char second_el = second_stack.pop();
            char stack_el = stack.pop();
            
            if(stack_el != second_el)
            {
                second_stack.push(second_el);
                stack.push(stack_el);
            }
        }
        
        char second_el = second_stack.pop();
        char first_el = first_stack.pop();
        
        if( first_el != second_el)
        {
            stack.push(first_el);
            second_stack.push(second_el);
        }
    }
    
    while(!stack.is_empty())
    {
        if(second_stack.is_empty())
        {
            return true;
        }
        
        char stack_el = stack.pop();
        char second_el = second_stack.pop();
        
        if( stack_el != second_el)
        {
            return false;
        }
    }
    
    if(second_stack.is_empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char * argv[]) {
    string first = "";
    string second = "";
    bool answer = true;
    
    cin >> first >> second;
    
    answer = is_stack_annagram(first, second);
    
    if (answer)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
