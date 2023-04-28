#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dst, weight;
};

void swap_arr_element(struct Edge *dst_edge, struct Edge *src_edge) {
    int temp;
    temp = dst_edge->src;
    dst_edge->src = src_edge->src;
    src_edge->src = temp;
    temp = dst_edge->dst;
    dst_edge->dst = src_edge->dst;
    src_edge->dst = temp;
    temp = dst_edge->weight;
    dst_edge->weight = src_edge->weight;
    src_edge->weight = temp;
}

int check_edge_validity(int vrtx, int parents[]) {
    if(parents[vrtx] == vrtx) 
        return vrtx;

    return check_edge_validity(parents[vrtx], parents);
}

void sorting_edges(struct Edge *Edges[], int num_of_edges) {
    struct Edge *temp_edge = (struct Edge *)malloc(sizeof(struct Edge));
    
    for (int i = 1; i < num_of_edges; i++) {
        swap_arr_element(temp_edge, Edges[i]);
        int j = i - 1;
        while (j >= 0 && Edges[j]->weight > temp_edge->weight) {
            swap_arr_element(Edges[j + 1], Edges[j]);
            j--;
        }
        swap_arr_element(Edges[j + 1], temp_edge);
    }
}

void finding_mst(struct Edge *Edges[], int num_of_vrtx, int num_of_edges) {
    int parents[num_of_vrtx], parent_src, parent_dst, mst_cost = 0;

    struct Edge *temp_edge = (struct Edge *)malloc(sizeof(struct Edge));

    sorting_edges(Edges, num_of_edges);

    printf("\nMST using Kruskal's algorithm:\n");
    for(int i = 0; i < num_of_vrtx; ++i) 
        parents[i] = i;
    
    int j = 0;
    
    for(int i = 0; i < num_of_vrtx; ++i) {
        temp_edge->src = Edges[i]->src;
        temp_edge->dst = Edges[i]->dst;
        temp_edge->weight = Edges[i]->weight;
        
        parent_src = check_edge_validity(temp_edge->src, parents);
        parent_dst = check_edge_validity(temp_edge->dst, parents);
        
        if(parent_src != parent_dst) {
            printf("\n(%c, %c) -> %d", temp_edge->src + 65, temp_edge->dst + 65, temp_edge->weight);
            parents[parent_src] = parent_dst;
            mst_cost += temp_edge->weight;
        }
    }
    printf("\nMST Cost: %d\n", mst_cost);

}

int main() {
    int num_of_vrtx, edge_counter = 0, w;

    printf("Enter number of vertices: ");
    scanf("%d", &num_of_vrtx);

    int max_edges = (num_of_vrtx * (num_of_vrtx - 1)) / 2;
    printf("Max possible edges: %d\n", max_edges);
    
    struct Edge *Edges[max_edges];
    
    printf("Enter weightage between vertices:\n");
    for(int i = 0; i < num_of_vrtx; i++) {
        for(int j = i; j < num_of_vrtx; j++) {
            if(i == j)
                continue;
            
            printf("\nVertex %c and Vertex %c: ", i + 65, j + 65);
            scanf("%d", &w);
            
            if(w == 0) 
                continue;
            
            struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
            edge->src = i;
            edge->dst = j;
            edge->weight = w;
            Edges[edge_counter] = edge;
            edge_counter++;
        }
    }
    
    finding_mst(Edges, num_of_vrtx, edge_counter);

    return 0;
}
