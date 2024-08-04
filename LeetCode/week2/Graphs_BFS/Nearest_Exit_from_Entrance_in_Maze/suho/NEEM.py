from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        G = dict()
        for i in range(len(maze)):
            for j in range(len(maze[0])):
                if maze[i][j]=='.' : 
                    adj = []
                    if(i+1<len(maze) and maze[i+1][j]=='.'): adj.append((i+1,j))
                    if(j+1<len(maze[0]) and maze[i][j+1]=='.'): adj.append((i,j+1))
                    if((i-1)>=0 and maze[i-1][j]=='.'): adj.append((i-1,j))
                    if((j-1)>=0 and maze[i][j-1]=='.'): adj.append((i,j-1))
                    G[(i,j)] = adj

        visit = deque()
        queue = deque()
        queue.append((tuple(entrance),0))
        sstep = 100000000
        while queue:
            pos, step = queue.pop()
            print(pos,step)
            if(pos!=tuple(entrance) and (pos[0]==0 or pos[0]==len(maze)-1 or pos[1]==0 or pos[1]==len(maze[0])-1)):
                if sstep > step: 
                    sstep = step
            if pos not in visit:
                visit.append(pos)
                for i in G[pos]:
                    if i not in visit: queue.append((i,step+1))
        
        return -1 if sstep==100000000 else sstep
 
