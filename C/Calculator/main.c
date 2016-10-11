//
//  main.c
//  Calculator
//
//  Created by Rishat Valitov on 10.10.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

#define BUFFER_SIZE 128
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* get_string_without_spaces(char* input, ssize_t* input_size)
{
    for(int i = 0; i < *input_size; i++)
    {
        while(isspace(input[i]))
        {
            for(int j = i; j < *input_size; j++)
            {
                input[j] = input[j+1];
            }
            input_size--;
        }
    }
    return input;
}

char* get_set(char* input, size_t input_size)
{
    int number_count = 0;
    
    
    
    printf("%lu\n %d\n", input_size, number_count);
    return input;
}

/*char* calculate(char* input)
{
    
    return answer;
}*/

int main(int argc, const char * argv[]) {
    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytes = 0;
    
    bytes = getline(&line, &line_size, stdin);
    
    if (line == NULL)
    {
        printf("[error]");
        return 0;
    }
    
    if (bytes == -1)
    {
        // read error
        free(line);
        printf("[error]");
        return 0;
    }
    
    printf("%s", line);
    
    char* answer = get_string_without_spaces(line, &bytes);
    
    printf("%lu \n", bytes);
    
    printf("%s", answer);
    
    return 0;
}
