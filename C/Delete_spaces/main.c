//
//  main.c
//  Delete_spaces
//
//  Created by Rishat Valitov on 23.09.16.
//  Copyright © 2016 Rishat Valitov. All rights reserved.
//

#define BUFFER_SIZE 16
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* copy_str(const char *s, size_t n)
{
    char* new = malloc(n + 1);
    
    if (s == NULL)
    {
        return NULL;
    }
    new[n] = '\n';
    
    return memcpy(new, s, n);;
}

char** delete_spaces(char** array, size_t array_size)
{
    for(int k = 0; k < array_size; k++)
    {
        size_t size = strlen(array[k]) - 1;
        
        while (isspace(array[k][size - 1]))
        {
            --size;
        }
    
        while (*array[k] && isspace(*array[k]))
        {
            ++array[k];
            --size;
        }
    
        if (!array[k])
        {
            return NULL;
        }
    
        for(int i = 0; i<size; i++ )
        {
            while((isspace(array[k][i])) && (isspace(array[k][i+1])))
            {
                for(int j = i; j<size; j++)
                {
                    array[k][j] = array[k][j+1];
                }
                --size;
            }
        }
        array[k] = copy_str(array[k], size);
    }
    return array;
}

static inline void print_error()
{
    printf("[error]");
}

void print_array(char** array, size_t array_size)
{
    for (int i = 0; i< array_size; i++)
    {
        printf("%s\n", array[i]);
    }
}

void free_array(char** array, size_t array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        free(array[i]);
    }
    free(array);
}

int main (int argc, const char * argv[]) {
    
    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytes = 0;
    
    int buffer_check = 1;
    
    size_t line_counter = 0;
    size_t array_size = buffer_check * BUFFER_SIZE;
    
    char** array = (char**)malloc(array_size * sizeof(char*));
    
    while(!feof(stdin))
    {
        bytes = getline(&line, &line_size, stdin);
        
        if ((line != NULL)&&(bytes!= -1))
        {
            array[line_counter] = copy_str(line, line_size);
            line_counter++;
            free(line);
        }
        
        if(line_counter >= array_size - 1)
        {
            buffer_check++;
            array_size = buffer_check * BUFFER_SIZE;
            char** check = (char**)realloc(array, array_size * sizeof(char*));
            if(check == NULL)
            {
                print_error();
                return 0;
            }
            else
            {
                array = check;
            }
        }
    }
    array = delete_spaces(array,line_counter);

    print_array(array, line_counter);
    
    free_array(array, line_counter);
    
    return 0;
}

