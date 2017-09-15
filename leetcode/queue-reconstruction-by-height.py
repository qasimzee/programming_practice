#https://leetcode.com/problems/queue-reconstruction-by-height/description/
class Solution(object):
    def reconstructQueue(self, people):
        people.sort(key=lambda x: (-x[0], x[1]))
        res = []
        for i in range(len(people)):
            if (len(res) == 0):
                res.append(people[i])
            else:
                j = 0
                while (j < len(res) and res[j][0] < people[i][0]):
                    j = j + 1
                j = j + people[i][1]
                if (j >= len(res)):
                    res.append(people[i])
                else:
                    res.insert(j, people[i])

    return res
