#include <bits/stdc++.h>
using namespace std;

#define N 4 // Number of regions (nodes)

bool isSafe(int graph[N][N], int color[], int node, int c) {
    for (int i = 0; i < N; i++) {
        if (graph[node][i] && color[i] == c) // Check if adjacent regions have the same color
            return false;
    }
    return true;
}

bool solveMapColoring(int graph[N][N], int m, int color[], int node) {
    if (node == N) return true; // All regions are colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, node, c)) {
            color[node] = c; // Assign color
            if (solveMapColoring(graph, m, color, node + 1)) 
                return true; // Recur for next region
            color[node] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(int color[]) {
    cout << "Color assignments: ";
    for (int i = 0; i < N; i++) cout << color[i] << " ";
    cout << endl;
}

void mapColoring(int graph[N][N], int m) {
    int color[N] = {0}; // Initialize all regions with no color

    if (solveMapColoring(graph, m, color, 0)) printSolution(color);
    else cout << "No solution exists.\n";
}

int main() {
    int graph[N][N] = { // Adjacency matrix representing the map
        {0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}  
    };

    int m = 3; // Number of colors
    mapColoring(graph, m);
    return 0;
}
