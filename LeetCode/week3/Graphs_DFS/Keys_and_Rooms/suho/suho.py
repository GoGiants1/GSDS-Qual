class Solution(object):
    def dfs(self, visited, num, rooms):
        if num not in visited:
            visited.append(num)
            for i in rooms[num]: self.dfs(visited, i, rooms)


    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        visited = []
        self.dfs(visited, 0, rooms)
        return len(visited) == len(rooms)
