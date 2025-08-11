
class MinStack {
private:
    stack<long long> st;  // To handle overflow cases
    long long minVal;

public:
    MinStack() {
        minVal = LLONG_MAX;  // Initialize to a large value
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                // Push modified value (2*val - minVal) to encode previous min
                st.push(2LL * val - minVal);
                minVal = val;  // Update minVal to the new minimum
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < minVal) {
            // Restore previous minVal
            minVal = 2LL * minVal - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;  // Handle empty case

        long long topVal = st.top();
        if (topVal < minVal) {
            // The actual value is minVal (since we stored encoded value)
            return minVal;
        } else {
            return topVal;
        }
    }

    int getMin() {
        return minVal;
    }
};
