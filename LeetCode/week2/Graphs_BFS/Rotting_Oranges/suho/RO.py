import copy
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        t=0
        grid_t = copy.deepcopy(grid)
        grid_t0 = copy.deepcopy(grid_t)
        cnt = 0

        while(1):
            cnt0 = cnt
            cnt = 0
            for i in range(len(grid)):
                for j in range(len(grid)):
                    if(grid_t0[i][j]==1):
                        cnt+=1
                        if( (i-1>=0 and grid_t0[i-1][j]==2) or (j-1>=0 and grid_t0[i][j-1]==2) or (i+1<len(grid) and grid_t0[i+1][j]==2) or (j+1<len(grid[0]) and grid_t0[i][j+1]==2)):
                            grid_t[i][j] = 2

            if cnt == 0 : return t
            elif cnt == cnt0 : return -1
            else : 
                grid_t0 = copy.deepcopy(grid_t)
                t += 1
