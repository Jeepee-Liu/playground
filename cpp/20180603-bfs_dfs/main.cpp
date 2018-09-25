#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


// Implementing the bfs and dfs algorithm for a graph search

#define N 5


int graph[N][N] = {
    {0,1,1,0,0},
    {0,0,1,1,0},
    {0,1,1,1,0},
    {1,0,0,0,0},
    {0,0,1,1,0}
};

vector<int> bfs(int start) {
    vector<int> elems{};
    queue<int> toVisit;
    bool visited[N] = {false,};
    // Initialization
    toVisit.push(start);
    visited[start] = true;
    while(!toVisit.empty()) {
        int front = toVisit.front();
        elems.push_back(front);
        toVisit.pop();
        for(int i = 0; i < N; ++i) {
            if(!visited[i] && graph[front][i] == 1) {
                visited[i] = true;
                toVisit.push(i);
            }
        }
    }
    return elems;
}

vector<int> dfs(int start) {
    vector<int> elems{};
    stack<int> toVisit;
    bool visited[N] = {false,};
    // Initialization
    toVisit.push(start);
    visited[start] = true;
    while(!toVisit.empty()) {
        int top = toVisit.top();
        elems.push_back(top);
        toVisit.pop();
        for(int i = 0; i < N; ++i) {
            if(!visited[i] && graph[top][i] == 1) {
                visited[i] = true;
                toVisit.push(i);
            }
        }
    }
    return elems;
}


int main() {
    for(auto n: bfs(0)) {
        cout << n << " ";
    }
    cout << endl;
    for(auto n: dfs(0)) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
