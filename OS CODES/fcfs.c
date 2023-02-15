// NON PREEMPTIVE
// TAT=BT+WT=CT-AT

#include <stdio.h>
#include <string.h>
int takedetails();
void printtable(int num);
void fcfssort(int num);
void fcfcscalc(int num);

struct process
{
    int n, at, bt, ct, wt, tat, status;
} p[20], temp;

void main()
{
    int num;
    num = takedetails();
    printtable(num);
    fcfssort(num);
    printtable(num);
    fcfcscalc(num);
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
void fcfssort(int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
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
            if (p[j].at == p[j + 1].at && p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void fcfcscalc(int num)
{
    int i = 0, secs = 0, sum_wt = 0, sum_tat = 0;
    p[0].wt = p[0].at;
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].bt + p[0].wt;
    sum_wt += p[0].wt;
    sum_tat += p[0].tat;
    secs += p[0].ct;
    for (i = 1; i < num; i++)
    {
        secs += p[i].bt;
        p[i].tat = secs - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sum_tat += p[i].tat;
        sum_wt += p[i].wt;
    }
    float avg_tat = (float)sum_tat / num;
    float avg_wt = (float)sum_wt / num;
}