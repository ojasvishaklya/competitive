
      vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto e: graph[i])
               indegree[e]++;
        }

        queue<int>que;
        for(int i=0;i<N;i++){
            if(indegree[i]==0) que.push(i);
        }

          vector<int>ans;


        while(que.size()!=0){
            int size=que.size();
            while(size--> 0){
                int rvtx=que.front();que.pop();
                ans.push_back(rvtx);
      
                for(int e: graph[rvtx]){
                    if(--indegree[e]==0)
                       que.push(e);
                }
            }
        }

        if(ans.size()!=N)return true;
        else return false;