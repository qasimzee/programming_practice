# https://leetcode.com/problems/all-paths-from-source-to-target/description/
import queue
class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        paths = []
        q = queue.Queue()
        q.put([0])
        while not q.empty():
            current_path = q.get()
            if current_path[-1] == len(graph) - 1:
                paths.append(current_path)
            for node in graph[current_path[-1]]:
                q.put(current_path + [node])
        return paths
        
