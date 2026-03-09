#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, time = 0, completed = 0;
    char pid[20][10];
    int at[20], bt[20], pr[20];
    int wt[20], tat[20], ct[20];
    int visited[20] = {0};

    float total_wt = 0, total_tat = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s %d %d %d", pid[i], &at[i], &bt[i], &pr[i]);
    }

    while(completed < n) {
        int idx = -1;
        int max_pr = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(pr[i] > max_pr) {
                    max_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];

            visited[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("Waiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
