#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> input, output;
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    QueueUsingStacks q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "Front: " << q.peek() << endl;  // 1
    cout << "Pop: " << q.pop() << endl;     // 1
    cout << "Pop: " << q.pop() << endl;     // 2
    
    q.push(4);
    
    cout << "Pop: " << q.pop() << endl;     // 3
    cout << "Pop: " << q.pop() << endl;     // 4
    cout << "Empty: " << (q.empty() ? "true" : "false") << endl;  // true
    
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> input, output;
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    QueueUsingStacks q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "Front: " << q.peek() << endl;  // 1
    cout << "Pop: " << q.pop() << endl;     // 1
    cout << "Pop: " << q.pop() << endl;     // 2
    
    q.push(4);
    
    cout << "Pop: " << q.pop() << endl;     // 3
    cout << "Pop: " << q.pop() << endl;     // 4
    cout << "Empty: " << (q.empty() ? "true" : "false") << endl;  // true
    
    return 0;
}