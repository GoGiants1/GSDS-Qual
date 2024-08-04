// class Solution {
// public:
//     void dfs(vector<int> *visited, int num, vector<vector<int>> *rooms){
//         if(find((*visited).begin(), (*visited).end(), num) == (*visited).end()){
//             printf("%d\n",num);
//             (*visited).push_back(num);
//             for(int i = 0; i < (*rooms)[num].size(); i++) dfs(visited, (*rooms)[num][i], rooms);
//         }
//     }   

//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         vector<int> visited(0);
//         dfs(&visited, 0, &rooms);
//         return visited.size() == rooms.size();
//     }
// };

class Solution {
public:
    void dfs(vector<int> &visited, int num, vector<vector<int>> &rooms){
        if(find(visited.begin(), visited.end(), num) == visited.end()){
            printf("%d\n",num);
            visited.push_back(num);
            for(int i = 0; i < rooms[num].size(); i++) dfs(visited, rooms[num][i], rooms);
        }
    }   

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(0);
        dfs(visited, 0, rooms);
        return visited.size() == rooms.size();
    }
};
