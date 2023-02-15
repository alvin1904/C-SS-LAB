#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char label[10], opcode[10], operand[10], code[10], mnemonic[3];
int length;

void pass1()
{
    int start;
    int locctr = 0x0;
    FILE *f1, *f2, *f3, *f4, *f5;
    char operands[10][10];
    f1 = fopen("input.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("intermediate.txt", "w");
    f4 = fopen("symtab.txt", "w");
    f5 = fopen("length.txt", "w");

    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        start = strtol(operand, NULL, 16);
        locctr = (0x1) * start;
        fprintf(f3, "%x\t%s\t%s\t%s", locctr, label, opcode, operand);
        fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    {
        locctr = 0x0;
    }
    while (strcmp(operand, "END") == 0)
    {
        fprintf(f3, "%x\t%s\t%s\t%s", locctr, label, opcode, operand);
        if (strcmp(operand, "WORD") == 0)
        {
            locctr += 0x3;
        }
        else if (strcmp(operand, "RESW") == 0)
        {
            locctr += 0x3 * atoi(operand);
        }
        else if (strcmp(operand, "RESB") == 0)
        {
            locctr += 0x1 * atoi(operand);
        }
        else
        {
            locctr += strlen(operand) * 0x1;
        }
    }
}

void main()
{
    pass1();
}