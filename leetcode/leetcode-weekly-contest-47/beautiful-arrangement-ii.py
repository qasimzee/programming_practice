class Solution(object):
    def constructArray(self, n, k):
        l = list(range(1, n + 1))
        count = 1
        oplist = [];
        c = 0
        while (count <= k):
            if (count % 2 == 1):
                oplist.append(l[0])
                del l[0]
            else:
                oplist.append(l[len(l) - 1])
                del l[len(l) - 1]
            count = count + 1
        oplist.extend(l)
        return oplist
