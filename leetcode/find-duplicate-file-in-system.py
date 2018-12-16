# https://leetcode.com/problems/find-duplicate-file-in-system/description/
class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        content_map = {}
        for path in paths:
            splitted_path = path.split()
            directory_path = splitted_path[0]
            for file in splitted_path[1:]:
                content = file[file.find("(")+1:file.find(")")]
                if content in content_map:
                    content_map[content].append(directory_path + '/' + file[:file.find("(")])
                else:
                    content_map[content] = [directory_path + '/' + file[:file.find("(")]]
        return [val for key, val in content_map.items() if len(val) > 1]
