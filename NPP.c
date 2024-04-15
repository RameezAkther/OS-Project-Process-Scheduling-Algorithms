#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,j;
    printf("\n---------------------------------------\n   PRIORITY NON PREEMPTIVE Scheduling\n---------------------------------------\n");
    printf("Enter number of processes for NON PREEMPTIVE PRIORITY SCHEDULING: ");
    scanf("%d",&n);
    int Arr[n],BT[n],PR[n];
    printf("\nArrival times: ");
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    printf("\nBurst times: ");
    for(i=0;i<n;i++)
    scanf("%d",&BT[i]);
    printf("\nPriority: ");
    for(i=0;i<n;i++)
    scanf("%d",&PR[i]);
    int Pr[n],Ct[n];
    for(i=0;i<n;i++)
    Pr[i]=PR[i];
    int count=0,dec=0;
    j=0;
    int choice;
    printf("\nOption:\n1.Lowest number Highest priority.\n2.Lowest number Lowest priority.\n>>>");
    scanf("%d",&choice);
    
    char gantt_chart[1000] = "0"; // Initialize Gantt chart string
    switch(choice)
    {
        case 1:
            while(j<n)
            {
                int min=1000,ind=-1;
                for(i=0;i<n;i++)
                {
                    if(Pr[i]==min)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]<min)
                    {
                        if(Arr[i]<=count)
                        {
                            min=Pr[i];
                            ind=i;
                        }
                    }
                    
                }
                if(ind!=-1)
                {
                    char temp[50];
                    sprintf(temp, "%d-P%d-", count, ind+1); // Format new Gantt chart entry
                    strcat(gantt_chart, temp); // Add new entry to Gantt chart string
                    Ct[ind]=BT[ind]+count;
                    count+=BT[ind];
                    j++;
                    Pr[ind]=1001;
                    dec=0;
                }
                else
                {
                    if(dec==0)
                    {
                        char temp[50];
                        sprintf(temp, "%d-Idle-", count); // Format new Gantt chart entry
                        strcat(gantt_chart, temp); // Add new entry to Gantt chart string
                        dec=1;
                    }
                    count++;
                }
            }
        break;
        case 2:
            while(j<n)
            {
                int max=-1,ind=-1;
                for(i=0;i<n;i++)
                {
                    if(Pr[i]==max)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]>max)
                    {
                        if(Arr[i]<=count)
                        {
                            max=Pr[i];
                            ind=i;
                        }
                    }
                    
                }
                if(ind!=-1)
                {
                    char temp[50];
                    sprintf(temp, "%d-P%d-", count, ind+1); // Format new Gantt chart entry
                    strcat(gantt_chart, temp); // Add new entry to Gantt chart string
                    Ct[ind]=BT[ind]+count;
                    count+=BT[ind];
                    j++;
                    Pr[ind]=-2;
                    dec=0;
                }
                else
                {
                    if(dec==0)
                    {
                        char temp[50];
                        sprintf(temp, "%d-Idle-", count); // Format new Gantt chart entry
                        strcat(gantt_chart, temp); // Add new entry to Gantt chart string
                        dec=1;
                    }
                    count++;
                }
            }
        break;
        default:
            printf("Wrong choice..\n");
        break;
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    printf("\nProcess Table:\nPid\tPr\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),PR[i],Arr[i],BT[i],Ct[i],TAT[i],WT[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
    sum+=(float)TAT[i];
    printf("Average TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);

    // Print Gantt Chart last
    printf("\n\nGantt Chart:\n|%s%d|\n", gantt_chart, count);

    return 0;
}
