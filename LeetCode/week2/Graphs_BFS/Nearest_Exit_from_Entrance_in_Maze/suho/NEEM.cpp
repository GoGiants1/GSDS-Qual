class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> visit(0);
        vector<vector<int>> queue(0);
        vector<int> step_queue(0);

        queue.push_back(entrance);
        step_queue.push_back(0);

        int sstep = 100000000;
        while(queue.size()>0){
            vector<int> pos = queue.back();
            int step = step_queue.back();
            queue.pop_back();
            step_queue.pop_back();

            if((pos[0]!= entrance[0] or pos[1]!=entrance[1]) and (pos[0]==0 or pos[0]==maze.size()-1 or pos[1]==0 or pos[1]==maze[0].size()-1)){
                if (sstep > step) sstep = step;
            }
            if(find(visit.begin(), visit.end(), pos) == visit.end()){
                visit.push_back(pos);
                if(pos[0]+1<maze.size() and maze[pos[0]+1][pos[1]]=='.' and (find(visit.begin(), visit.end(), vector<int>{pos[0]+1,pos[1]}) == visit.end())){
                    queue.push_back(vector<int>{pos[0]+1,pos[1]});
                    step_queue.push_back(step+1);
                }
                if(pos[1]+1<maze[0].size() and maze[pos[0]][pos[1]+1]=='.' and (find(visit.begin(), visit.end(), vector<int>{pos[0],pos[1]+1}) == visit.end())){
                    queue.push_back(vector<int>{pos[0],pos[1]+1});
                    step_queue.push_back(step+1);
                }
                if(pos[0]-1>=0 and maze[pos[0]-1][pos[1]]=='.' and (find(visit.begin(), visit.end(), vector<int>{pos[0]-1,pos[1]}) == visit.end())){
                    queue.push_back(vector<int>{pos[0]-1,pos[1]});
                    step_queue.push_back(step+1);
                }
                if(pos[1]-1>=0 and maze[pos[0]][pos[1]-1]=='.' and (find(visit.begin(), visit.end(), vector<int>{pos[0],pos[1]-1}) == visit.end())){
                    queue.push_back(vector<int>{pos[0],pos[1]-1});
                    step_queue.push_back(step+1);
                }
            }
        }
        return sstep==100000000 ? -1 : sstep;
    }
};
