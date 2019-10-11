class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }

    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }

    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_val;
    }
private:
    int min_val;
    stack<int> st;
};