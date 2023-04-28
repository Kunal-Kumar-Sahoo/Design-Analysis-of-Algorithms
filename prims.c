#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int check_edge_validity(int i, int j, int visited[]) {
    if(i == j) 
        return 0;
    if(visited[i] == 0 && visited[j] == 0) 
        return 0;
    else if(visited[i] == 1 && visited[j] == 1) 
        return 0;
    
    return 1;
}

void finding_mst(int *mtrx, int num_of_vrtx) {
    int visited[num_of_vrtx], min, x = -1, y = -1, minCost = 0, edge_count = 0;
    
    for(int i = 0; i < num_of_vrtx; i++) 
        visited[i] = 0;
    
    visited[0] = 1;

    while (edge_count < num_of_vrtx - 1) {
        min = 9999, x = -1, y = -1;
        for(int i = 0; i < num_of_vrtx; ++i) 
            for(int j = 0; j < num_of_vrtx; ++j) 
                if(*((mtrx + i * num_of_vrtx) + j) < min) 
                    if(check_edge_validity(i, j, visited) == 1) {
                        min = *((mtrx + i * num_of_vrtx) + j);
                        x = i;
                        y = j;
                    }
        
        if(x != -1 && y != -1) {
            printf("\n(%c, %c): %d", x + 65, y + 65, min);
            minCost += min;
            visited[x] = visited[y] = 1;
            edge_count++;
        }
    }

    printf("\nMST cost: %d.", minCost);
}

int main() {
    int num_of_vrtx, *mtrx, w;

    printf("Number of vertices: ");
    scanf("%d", &num_of_vrtx);
    
    mtrx = (int *)malloc(((num_of_vrtx * (num_of_vrtx - 1)) / 2) * sizeof(int));
    
    for(int i = 0; i < num_of_vrtx; ++i) 
        for(int j = 0; j < num_of_vrtx; ++j) {
            *((mtrx + i * num_of_vrtx) + j) = INT_MAX;
           
            if(i >= j) 
                continue;
           
            printf("From vertex %c to vertex %c: ", i + 65, j + 65);
            scanf("%d", &w);
            
            if(w == 0) 
                w = INT_MAX;
            
            *((mtrx + i * num_of_vrtx) + j) = w;
        }
    
    finding_mst(mtrx, num_of_vrtx);
}
