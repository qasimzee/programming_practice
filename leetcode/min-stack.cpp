//https://leetcode.com/problems/min-stack/
class MinStack {
  priority_queue<int, std::vector<int>, std::greater<int> > pq;
  stack<int> stk;
  public:
  void push(int x) {
    stk.push(x);
    pq.push(x);
  }
  void pop() {
    if (stk.top() == pq.top()) {
      pq.pop();
    }
    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return pq.top();
  }
};
