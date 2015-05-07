
   int dfs(int i)
   {
      int j = 0;
      visited[i] = true;  // Mark node as "visited"
      // some print function or whatever! 
      for ( j = 0; j < NNodes; j++ )
      {
         if ( adjMatrix[i][j] > 0 && !visited[j] )       
         {
            dfs(j);       // Visit node
         }
      }
   }
