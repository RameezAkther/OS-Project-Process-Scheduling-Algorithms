#include<stdio.h>
#include<string.h>

int main()
{
    printf("\n---------------------------------------\n\t     SRTF Scheduling\n---------------------------------------\n");
    int n,i,j;
    printf("Enter number of processes for SRTF SCHEDULING: ");
    scanf("%d",&n);
    int Arr[n],BT[n];
    printf("Arrival times: ");
    for(i=0;i<n;i++){
        scanf("%d",&Arr[i]);
    }
    printf("\nBurst times: ");
    for(i=0;i<n;i++){
        scanf("%d",&BT[i]);
    }
    int Bt[n],Ct[n],Rt[n];
    for(i=0;i<n;i++)
    Bt[i]=BT[i];
    for(i=0;i<n;i++)
    Rt[i]=-1;
    int count=0,prev=-1;
    j=0;
    char gantt_chart[1000] = "0"; // Initialize Gantt chart string
    while(j<n)
    {
        int min=1000,ind=-1;
        for(i=0;i<n;i++)
        {
            if(Bt[i]==min && Bt[i]>0)
            {
                if(Arr[i]<Arr[ind])
                    ind=i;
            }
            
            else if(Bt[i]<min && Bt[i]>0)
            {
                if(Arr[i]<=count)
                {
                    min=Bt[i];
                    ind=i;
                }
            }
            
        }
        
        if(ind!=-1)
        {
            Bt[ind]-=1;
            char temp[50];
            sprintf(temp, " -> [P%d] -> %d", ind+1, count+1); // Format new Gantt chart entry
            strcat(gantt_chart, temp); // Add new entry to Gantt chart string
        }
        
        if(ind!=prev && Rt[ind]==-1)
        {
            Rt[ind]=count-Arr[ind];
        }
        
        count++;
        
        if(Bt[ind]==0 && ind!=-1)
        {
            Ct[ind]=count;
            j++;
        }
        prev=ind;
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    printf("\n\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i],Rt[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
    sum+=(float)TAT[i];
    printf("Average TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)Rt[i];
    printf("\nAverage RT: %f",sum/n);

    // Print Gantt Chart last
    printf("\n\nGantt Chart:\n%s|\n", gantt_chart);
    return 0;
}
