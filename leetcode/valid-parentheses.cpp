//Solution to https://leetcode.com/problems/valid-parentheses/
class Solution {
  public:
    bool isValid(string s) {
      stack<char> stk;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
          stk.push(s[i]);
        }
        else {
          if (stk.size() == 0)
            return false;
          char ch = stk.top();
          if (s[i] == '}' && ch != '{')
            return false;
          if (s[i] == ']' && ch != '[')
            return false;
          if (s[i] == ')' && ch != '(')
            return false;
          stk.pop();
        }
      }
      return stk.empty();
    }
};
