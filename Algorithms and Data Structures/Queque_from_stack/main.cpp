//
//  main.cpp
//  Queque_from_stack
//
//  Created by Rishat Valitov on 28.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

// Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
#include <iostream>
#include <cassert>

using namespace std;

class CStack
{
    int *buffer;
    size_t buffer_size;
    int top;
public:
    explicit CStack(size_t);
    ~CStack();
    
    void push(int);
    int pop();
    bool is_empty() const;
};

CStack::CStack(size_t _buffer_size):
    buffer_size(_buffer_size),
    top(-1)
{
    buffer = new int[buffer_size];
}

CStack::~CStack()
{
    delete [] buffer;
}

void CStack::push(int number)
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

class CQueque
{
    CStack first;
    CStack second;
    size_t buffer_size_f;
    size_t buffer_size_s;
public:
    explicit CQueque(size_t);
    ~CQueque();
    
    void push_back(int);
    int pop_front();
    bool is_empty() const;
};

CQueque::CQueque(size_t _buffer_size):
first(CStack(_buffer_size)),
second(CStack(_buffer_size)),
buffer_size_f(0),
buffer_size_s(0)
{}

CQueque::~CQueque()
{
}

void CQueque::push_back(int number)
{
    first.push(number);
    buffer_size_f++;
}

/* Из первого стека во второй перекидываем
 все значения кроме последнего, запоминаем его, записываем все 
 значения обратно и возвращаем последний, который запомнили*/
int CQueque::pop_front()
{
    int answer = 0;
    
    if(second.is_empty())
    {
        for(int i = 0; i<buffer_size_f; i++)
        {
            second.push(first.pop());
            buffer_size_s++;
        }
        buffer_size_f = 0;
    }

    answer = second.pop();
    buffer_size_s--;
    
    return answer;
}

bool CQueque::is_empty() const
{
    
    return (first.is_empty()&&second.is_empty());
}

int main(int argc, const char * argv[])
{
    size_t buffer_size = 0;
    int* input  = new int[2];
    bool answer = true;
    
    cin >> buffer_size;
    
    CQueque queque = CQueque(buffer_size);
    
    for(int i = 0; i<buffer_size; i++)
    {
        cin >> input[0] >> input[1];
        
        if (input[0] == 3)
        {
            queque.push_back(input[1]);
        }
        else if (input[0] == 2)
        {
            if(queque.is_empty())
            {
                if (input[1] != -1)
                {
                    answer = false;
                }
            }
            else
            {
                if(input[1] != queque.pop_front())
                {
                    answer = false;
                }
            }
        }
        else
        {
            answer = false;
        }
    }
    
    if (answer)
        cout << "YES";
    else
        cout << "NO";
    
    delete[] input;
    
    return 0;
}
