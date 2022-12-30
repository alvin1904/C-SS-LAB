#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  char label[10],opcode[10],operand[10],mnuem[10],code[10];
  int start,locctr,length;
  FILE *fp1,*fp2,*fp3,*fp4,*fp5;
  fp1 = fopen("inputfile.txt","r");
  fp2 = fopen("optab.txt","r");
  fp3 = fopen("symTable.txt","w");
  fp4 = fopen("intermediateFile.txt","w");
  fp5 = fopen("programLength.txt","w");
  fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

  if(strcmp(opcode,"START")==0)
  {
    start = atoi(operand);
    locctr = start;
    fprintf(fp4,"\t\t%s\t%s\t%s\n",label,opcode,operand);
  }
  else
  {
    start = 0;
    locctr = 0;
  }
  do
  {
    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    fscanf(fp2,"%s\t%s",code,mnuem);
    fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    if(strcmp(label,"**")!=0)
    {
      fprintf(fp3,"%s\t%d\n",label,locctr);
      if(strcmp(opcode,"WORD")==0)
      {
        locctr+=3;
      }
      else if(strcmp(opcode,"RESW")==0)
      {
        locctr+=(3*atoi(operand));
      }
      else if(strcmp(opcode,"RESB")==0)
      {
        locctr+=atoi(operand);
      }
      else if(strcmp(opcode,"BYTE")==0)
      {
        if(operand[0]=='X')
        {
          locctr+=1;
        }
        else if(operand[0]=='C')
        {
          locctr+=(strlen(operand)-3);
        }
      }
    }
    else
    {
      while (strcmp(code,"END")!=0)
      {
        if (strcmp(opcode,code)==0)
        {
          locctr+=3;
          break;
        }
        fscanf(fp2,"%s\t%s",code,mnuem);
      }
    }
  }
  while(strcmp(opcode,"END")!=0);
  length = locctr - start;
  printf("THE LENGTH OF THE CODE : %04d\n",length);
  fprintf(fp5,"%04d",length);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  fclose(fp5);
}
