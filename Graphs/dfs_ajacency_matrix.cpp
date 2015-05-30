int dfs(int i) {
   int j = 0;
   visited[i] = true;  // Mark node as "visited"
   // some print function or whatever! 
   for (j = 0; j < NNodes; j++) {
      if (adjMatrix[i][j] > 0 && !visited[j]) {
         dfs(j);       // Visit node
      }
   }
}

void dfs(int start) {
   int j,temp; 
   stack<int> s;
   s.push(start);
   vector<int>::iterator it;
   while (s.empty() == 0) {
      temp=s.top();
       s.pop();
       status[temp]=1; // marked as visited , 0 means unvisited
       cout << temp << endl;
      for(it = list[temp].begin(); it != list[temp].end(); it++) {
         j = *it;
         if (status[j]==0) {
            s.push(j);
            status[j] = 2; // means that it is in stack        
         }
      }
   }
}
