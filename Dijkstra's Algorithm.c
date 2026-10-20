#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {


  int distance[MAX], pred[MAX], visited[MAX];
    int i, j, count;
    int mindistance, nextnode;

    /* Initialize */
    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        pred[i] = 0;
        visited[i] = 0;
    }

    distance[startnode] = 0;

    /* Dijkstra algorithm */
    for (count = 1; count <= n - 1; count++) {

        mindistance = INFINITY;
        nextnode = -1;

        /* Find minimum distance unvisited node */
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < mindistance) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        if (nextnode == -1)
            break;

        visited[nextnode] = 1;

        /* Relax adjacent vertices */
        for (i = 1; i <= n; i++) {
            if (!visited[i] && G[nextnode][i] > 0) {
                if (distance[nextnode] + G[nextnode][i] < distance[i]) {
                    distance[i] = distance[nextnode] + G[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
    }

    printf("Node\tDistance\tPath\n");

    for (i = 1; i <= n; i++) {

        if (i == startnode)
            continue;

        if (distance[i] == INFINITY) {
            /*
             * Expected:
             *    1       INF    NO PATH
             *
             * 3 spaces + node + TAB + 5 spaces + INF + TAB
             */
            printf("   %d\t     INF\tNO PATH\n", i);
        }
        else {
            /*
             * Expected:
             *    2       4    2<-1
             *
             * 3 spaces + node + TAB + 7 spaces + distance + TAB
             */
            printf("   %d\t       %d\t", i, distance[i]);

            /* Print path */
            printf("%d", i);

            j = i;
            while (pred[j] != 0) {
                printf("<-%d", pred[j]);
                j = pred[j];
            }

            printf("\n");
        }
    }


}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 