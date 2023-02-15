#include <stdio.h>
#include <string.h>
int takedetails();
void printtable(int num);
void sjfsort(int num);
void sjfcalc(int num);

struct process
{
    int n, at, bt, ct, wt, tat, status;
} p[20], temp;

void main()
{
    int num;
    num = takedetails();
    printtable(num);
    sjfsort(num);
    printtable(num);
    sjfcalc(num);
    printtable(num);
}
void printtable(int num)
{
    printf("N\tAT\tBT\tCT\tWT\tTAT\tSTATUS\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].n, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].status);
    }
}
int takedetails()
{
    int i, num;
    printf("Enter the number of process: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter details for P%d\n", i);
        p[i].n = i;
        printf("Enter the AT: ");
        scanf("%d", &p[i].at);
        printf("Enter the BT: ");
        scanf("%d", &p[i].bt);
    }
    return num;
}
void sjfsort(int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (p[j].bt == p[j + 1].bt && p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void sjfcalc(int num){
    
};