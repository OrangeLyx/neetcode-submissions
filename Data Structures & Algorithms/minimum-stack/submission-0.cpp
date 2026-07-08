class MinStack {
private:
    stack<int> all;
    stack<int> min_res;

public:
    MinStack() {}

    void push(int val) {
        all.push(val);
        if (min_res.empty() || min_res.top() >= val) {
            min_res.push(val);
        }
    }

    void pop() {
        if (all.top() == min_res.top()) {
            min_res.pop();
        }
        all.pop();
    }

    int top() { return all.top(); }

    int getMin() { return min_res.top(); }
};
