#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,j;
    printf("\n---------------------------------------\n\t      SJF Scheduling\n---------------------------------------\n");
    printf("Enter number of processes for SJF SCHEDULING: ");
    scanf("%d",&n);
    int Arr[n],BT[n];
    printf("\nArrival times: ");
    for(i=0;i<n;i++)
        scanf("%d",&Arr[i]);
    printf("\nBurst times: ");
    for(i=0;i<n;i++)
        scanf("%d",&BT[i]);
    int Bt[n],Ct[n],P[n];
    for(i=0;i<n;i++)
    {
        Bt[i]=BT[i];
        P[i]=i+1;  //storing process number
    }
    //int count=0;
    j=0;
    int current_time = 0; // Track current time
    char gantt_chart[1000] = "0"; // Initialize Gantt chart string
    while(j<n)
    {
        int min=1000,ind=-1;
        for(i=0;i<n;i++)
        {
            if(Bt[i]==min)
            {
                if(Arr[i]<Arr[ind])
                    ind=i;
            }
            
            else if(Bt[i]<min)
            {
                if(Arr[i]<=current_time)
                {
                    min=Bt[i];
                    ind=i;
                }
            }
        }
        if(ind!=-1)
        {
            Ct[ind]=BT[ind]+current_time;
            current_time+=BT[ind];
            j++;
            Bt[ind]=1001;
            char temp[50];
            sprintf(temp, " -> [P%d] -> %d", P[ind], current_time); // Format new Gantt chart entry
            strcat(gantt_chart, temp); // Add new entry to Gantt chart string
        }
        else
        {
            current_time++;
        }
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
        TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
        WT[i]=TAT[i]-BT[i];
    
    printf("\n\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
        sum+=(float)TAT[i];
    printf("Average TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
        sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);

    // Print Gantt Chart last
    printf("\n\nGantt Chart:\n%s|\n", gantt_chart);

    return 0;
}
