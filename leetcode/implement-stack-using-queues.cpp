//Solution to https://leetcode.com/problems/implement-stack-using-queues/
class Stack {
  queue<int> q1, q2;
  public:

  void push(int x) {
    q1.push(x);
  }


  void pop() {
    while (q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }


  int top() {
    int x = -1;
    while (!q1.empty()) {
      x = q1.front();
      q2.push(x);
      q1.pop();
    }

    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
    return x;
  }


  bool empty() {
    return q1.empty();
  }
};
