 #include<iostream>
 #include<set>
 #define p 5
 using namespace std;

 int graph[p][p] = { //adjacency matrix of the wait for graph COPY PASTE OUTPUT FROM PREVIOUS ALGORITHM
 {0, 1, 0, 0, 0}, //GRAPH TAKEN FROM YOUTUBE VIDEO
 {0, 0, 1, 1, 1},
 {0, 0, 0, 1, 0},
 {1, 0, 0, 0, 1},
 {0, 0, 0, 0, 0}
 };

 bool dfs(int curr, set<int>&wSet, set<int>&gSet, set<int>&bSet) { //class for depth first traversal

 wSet.erase(wSet.find(curr));
 gSet.insert(curr);

 for(int v = 0; v < p; v++) {
 if(graph[curr][v] != 0) {
 if(bSet.find(v) != bSet.end())
 continue;
 if(gSet.find(v) != gSet.end())
 return true;
 if(dfs(v, wSet, gSet, bSet))
 return true;
 }
 }


 gSet.erase(gSet.find(curr));
 bSet.insert(curr);
 return false;
 }

 bool hasCycle() { //class for cycle detection in adjacency matrix
 set<int> wSet, gSet, bSet;
 for(int i = 0; i<p; i++)
 wSet.insert(i);

 while(wSet.size() > 0) {
 for(int current = 0; current < p; current++) {
 if(wSet.find(current) != wSet.end())
 if(dfs(current, wSet, gSet, bSet))
 return true;
 }
 }
 return false;
 }

 int main() {
 bool res;
 res = hasCycle(); //output based on cycle detection in wait for graph
 if(res)
 cout << "There will be a deadlock/ there is a deadlock." << endl;
 else
 cout << "The will be no deadlock/ there is no deadlock." << endl;
 }