//
//  main.cpp
//  IT-conversation
//
//  Created by Rishat Valitov on 29.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.

//В большой IT ­фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено. Число заявок  ≤ 100000.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Класс запись в расписании
class TableNote
{
    int begining;
    int ending;
    
public:
    TableNote(int beg, int end):
    begining(beg),
    ending(end)
    {}
    
    void set_begining(int beg)
    {
        begining = beg;
    }
    
    void set_ending(int end)
    {
        ending = end;
    }
    
    int get_begining()
    {
        return begining;
    }
    
    int get_ending()
    {
        return ending;
    }
};

// Сортировка по убыванию конца встречи
struct sort_for_ending
{
    bool operator() (TableNote first, TableNote second)
    {
        return (first.get_ending() < second.get_ending());
    }
} sort_TableNote;

// Ввод
vector<TableNote> scan_vector()
{
    int begining(0), ending(0);

    vector<TableNote> input;
    TableNote element(0,0);

    while (cin)
    {
        cin >> begining >> ending;
    
        element.set_begining(begining);
        element.set_ending(ending);
        input.push_back(element);
    }
    input.pop_back();
    
    return input;
}

// если начало позже, то перезаписываем окончание 
int max_cover(vector<TableNote> appllications)
{
    int ending_time(0);
    int answer(0);
    
    sort (appllications.begin(), appllications.end(), sort_TableNote);
    vector<TableNote>::iterator i;
    
    for(i = appllications.begin(); i!=appllications.end(); ++i)
    {
        if((i->get_begining() >= ending_time)||(!ending_time))
        {
            ending_time = i->get_ending();
            answer++;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<TableNote> input = scan_vector();
    
    int answer = max_cover(input);
    
    cout << answer;
    
    return 0;
}
