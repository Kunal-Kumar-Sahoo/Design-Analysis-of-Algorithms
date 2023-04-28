#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_min_dist(int dists[], int visited[], int num_of_vrtx) {
    int min_dist = -1;
    for(int i = 0; i < num_of_vrtx; i++) 
        if(visited[i] != 1 && (min_dist == -1 || dists[i] < dists[min_dist])) 
            min_dist = i;

    return min_dist;
}

void finding_shortest_path(int *mtrx, int num_of_vrtx) {
    int dists[num_of_vrtx], visited[num_of_vrtx], min_dist = 0, dist = 0;
    
    for(int i = 0; i < num_of_vrtx; i++) {
        dists[i] = INT_MAX;
        visited[i] = 0;
    }

    printf("\nAdjacency matrix:\n");
    for(int i = 0; i < num_of_vrtx; ++i) {
        for(int j = 0; j < num_of_vrtx; ++j) 
            printf("%d | ", *((mtrx + i * num_of_vrtx) + j));
        printf("\n");
    }

    dists[0] = 0;
    for(int i = 0; i < num_of_vrtx; ++i) {
        min_dist = find_min_dist(dists, visited, num_of_vrtx);
        visited[min_dist] = 1;
        for(int j = 0; j < num_of_vrtx; ++j) 
            if(*((mtrx + min_dist * num_of_vrtx) + j) != 0 && visited[j] != 1) {
                dist = dists[min_dist] + *((mtrx + min_dist * num_of_vrtx) + j);
                if(dist < dists[j]) 
                    dists[j] = dist;
            }   
    }

    printf("\nMinimum distance from vertex %c to other vertices:\n", 65);
    for(i = 1; i < num_of_vrtx; i++) 
        printf("%c: %d\n", i + 65, dists[i]);

    free(dists);
    free(visited);
}


int main() {
    int num_of_vrtx, w, *mtrx;
    
    printf("Number of vertices: ");
    scanf("%d", &num_of_vrtx);
    
    mtrx = (int *)malloc((num_of_vrtx * num_of_vrtx) * sizeof(int));
    for(int i = 0; i < num_of_vrtx; ++i) 
        for(int j = i; j < num_of_vrtx; ++j) {
            if(i == j)
                w = 0;
            else if(i < j) {
                printf("Between vertex %c and vertex %c: ", i + 65, j + 65);
                scanf("%d", &w);
            }
            if(w == 0) 
                w = 0;
            *((mtrx + i * num_of_vrtx) + j) = w;
            *((mtrx + j * num_of_vrtx) + i) = w;
        }
    
    finding_shortest_path(mtrx, num_of_vrtx);
    free(mtrx);

    return 0;
}
