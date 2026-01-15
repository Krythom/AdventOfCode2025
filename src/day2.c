#include "day2.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>


void day2_part1()
{
    long lower, upper;
    char buffer[20];
    int digits;
    int diff;
    long solution = 0;

    FILE* fp = fopen("inputs/inputDay2.txt", "r");
    if (fp == NULL) 
    {
        printf("Error opening input file: %s\n", strerror(errno));
        return;
    }

    while (fscanf(fp, "%ld-%ld,", &lower, &upper) != EOF)
    {
        for (long i = lower; i <= upper; i++)
        {
            diff = 0;
            digits = sprintf(buffer, "%ld", i);

            if (digits % 2 == 0)
            {
                for (int j = 0; j < digits/2; j++)
                {
                    if(buffer[j] != buffer[j+digits/2])
                    {
                        diff = 1;
                    }
                }

                if (diff == 0)
                {
                    solution += i;
                }
            }
        }
    }

    printf("The sum of all invalid IDs is: %ld\n", solution);
    fclose(fp);
}


void day2_part2()
{
    long lower, upper;
    char buffer[20];
    int digits;
    int patternLength;
    long solution = 0;

    FILE* fp = fopen("inputs/inputDay2.txt", "r");
    if(fp == NULL) 
    {
        printf("Error opening input file: %s\n", strerror(errno));
        return;
    }

    while (fscanf(fp, "%ld-%ld,", &lower, &upper) != EOF)
    {
        for (long i = lower; i <= upper; i++)
        {
            patternLength = 1;
            digits = sprintf(buffer, "%ld", i);

            for (int j = 1; j < digits;)
            {
                for (int k = 0; k < patternLength; k++)
                {
                    if (buffer[j] != buffer[k])
                    {
                        // handles cases like 121121 where normally the correct pattern length (3) would be skipped
                        if (buffer[j] == buffer[0]) 
                        {
                            patternLength = j;
                        }
                        else 
                        {
                            patternLength = ++j;
                        }
                        
                        break;
                    }

                    if (j == digits - 1 && k == patternLength - 1)
                    {
                        solution += i;
                    }
                    
                    j++;
                }
                if (patternLength > digits/2)
                {
                    break;
                }
            }
        }
    }

    printf("The sum of all invalid IDs is: %ld\n", solution);
    fclose(fp);
}