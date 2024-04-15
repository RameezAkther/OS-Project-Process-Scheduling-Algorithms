#include<stdio.h>
#include<string.h>

int main()
{
    printf("\n---------------------------------------\n\t ROUND ROBIN Scheduling\n---------------------------------------\n");
    int n,i,j,tq,len=0;
    printf("Enter number of processes for ROUND ROBIN :");
    scanf("%d",&n);
    int Arr[n],BT[n];
    printf("\nArrival times: ");
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    printf("\nBurst times: ");
    for(i=0;i<n;i++)
    scanf("%d",&BT[i]);
    printf("\nEnter Time Quanta: ");
    scanf("%d",&tq);
    int Bt[n],Ct[n],Rt[n];
    for(i=0;i<n;i++)
    {
        Bt[i]=BT[i];
        len+=BT[i];
        Rt[i]=-1;
    }
    int ready[len];
    int count=0,front=0,rear=-1,dec=0;
    j=0;
    char gantt_chart[1000] = "0"; // Initialize Gantt chart string
    while(j<n)
    {
        int found=0;
        if(front>rear)
        {
            for(i=0;i<n;i++)
            if(Arr[i]==count)
            {
                ready[++rear]=i;
                found=1;
            }
            if(found==0)
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
        else
        {
            int k,ind=ready[front++];
            
            char temp[50];
            sprintf(temp, "%d-P%d-", count, ind+1); // Format new Gantt chart entry
            strcat(gantt_chart, temp); // Add new entry to Gantt chart string
            
            if(Rt[ind]==-1)
            Rt[ind]=count-Arr[ind];
            
            if(Bt[ind]<=tq)
            {
                for(k=0;k<Bt[ind];k++)
                {
                    count++;
                    for(i=0;i<n;i++)
                    {
                        if(Arr[i]==count)
                        ready[++rear]=i;
                    }
                }
                Bt[ind]=0;
                Ct[ind]=count;
                j++;
            }
            else
            {
                for(k=0;k<tq;k++)
                {
                    count++;
                    for(i=0;i<n;i++)
                    {
                        if(Arr[i]==count)
                        ready[++rear]=i;
                    }
                }
                Bt[ind]-=tq;
                ready[++rear]=ind;
            }
        }
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    
    printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
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
    printf("\n\nGantt Chart:\n%s%d|\n", gantt_chart, count);

    return 0;
}
