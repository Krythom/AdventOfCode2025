#include <stdio.h>
#include <stdlib.h>

void day1_part1()
{
    int solution = 0;
    int dial = 50;
    char dir;
    char buffer[10];
    int num;

    FILE* fp = fopen("inputs/inputDay1.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
        return;
    }

    while((dir = fgetc(fp)) != EOF)
    {
        num = atoi(fgets(buffer, 10, fp));

        if (dir == 'R')
        {
            dial = (dial + num) % 100;
        }
        else 
        {
            dial = (dial - num + 100) % 100;
        }

        if (dial == 0)
        {
            solution++;
        }
    }

    fclose(fp);
    printf("The dial hit '0' %d times.\n", solution);
}

void day1_part2()
{
    int solution = 0;
    int dial = 50;
    char dir;
    char buffer[10];
    int num;

    FILE* fp = fopen("inputs/inputDay1.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
        return;
    }

    while((dir = fgetc(fp)) != EOF)
    {
        num = atoi(fgets(buffer, 10, fp));

        if (dir == 'R')
        {
            dial += num;

            //count turns
            while (dial > 99)
            {
                dial -= 100;
                solution++;
            }
        }
        else 
        {
            dial -= num;

            if (dial == -num) //avoids counting movements starting from 0 as a new hit on 0
            {
                dial += 100;
            }

            //count turns
            while (dial < 0)
            {
                dial += 100;
                solution++;
            }

            if (dial == 0) //dial lands exactly on 0 (while loop doesn't catch this)
            {
                solution++;
            }
        }
    }

    fclose(fp);
    printf("The dial hit '0' %d times.\n", solution);
}