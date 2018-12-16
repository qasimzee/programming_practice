# https://leetcode.com/problems/complex-number-multiplication/description/
class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a = a.split('+')
        b = b.split('+')
        a[0] = int(a[0])
        a[1] = int(a[1].replace('i', ''))
        b[0] = int(b[0])
        b[1] = int(b[1].replace('i', ''))
        c = [a[0] * b[0] + (a[1] * b[1] * -1), a[0] * b[1] + a[1] * b[0]]
        return '{}+{}i'.format(c[0], c[1])
