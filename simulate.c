#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char cont;
    
    do {
        // Display the menu
        printf("--------------------------------------------------------\n");
        printf("Select the scheduling algorithm to simulate:\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. Non Pre-emptive Priority (NPP)\n");
        printf("3. Pre-emptive Priority (PP)\n");
        printf("4. Round Robin (RR)\n");
        printf("5. Shortest Job First (SJF)\n");
        printf("6. Shortest Remaining Time First (SRTF)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Execute the selected algorithm
        switch (choice) {
            case 1:
                // Call the FCFS program
                system("FCFS.exe");
                break;
            case 2:
                // Call the NPP program
                system("NPP.exe");
                break;
            case 3:
                // Call the PP program
                system("PP.exe");
                break;
            case 4:
                // Call the RR program
                system("RR.exe");
                break;
            case 5:
                // Call the SJF program
                system("SJF.exe");
                break;
            case 6:
                // Call the SRTF program
                system("SRTF.exe");
                break;
            case 7:
                // Exit the program
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
        
        // Ask if the user wants to continue
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
    
    return 0;
}
