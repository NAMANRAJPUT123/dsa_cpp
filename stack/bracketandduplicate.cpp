// application of stack : check for balanced parentheses in an expression
// #include <iostream>
// #include <cstring>
// using namespace std;
// #define MAX 1000
// class Stack {
//     int top;    // Index of the top element
//     char a[MAX]; // Maximum size of Stack
// public:
//     Stack() { top = -1; }
//     bool push(char x);
//     char pop();
//     char peek();
//     bool isEmpty();
// };
// bool Stack::push(char x) {
//     if (top >= (MAX - 1)) {
//         cout << "Stack Overflow";
//         return false;
//     } else {
//         a[++top] = x;
//         return true;
//     }
// }
// char Stack::pop() {
//     if (top < 0) {
//         cout << "Stack Underflow";
//         return 0;
//     } else {
//         char x = a[top--];
//         return x;
//     }
// }
// char Stack::peek() {
//     if (top < 0) {
//         cout << "Stack is Empty";
//         return 0;
//     } else {
//         return a[top];
//     }
// }
// bool Stack::isEmpty() {
//     return (top < 0);
// }
// bool isMatchingPair(char opening, char closing) {
//     return (opening == '(' && closing == ')') ||
//            (opening == '{' && closing == '}') ||
//            (opening == '[' && closing == ']');
// }
// bool areParenthesesBalanced(char exp[]) {
//     Stack s;
//     for (int i = 0; i < strlen(exp); i++) {
//         if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
//             s.push(exp[i]);
//         } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
//             if (s.isEmpty() || !isMatchingPair(s.pop(), exp[i])) {
//                 return false;
//             }
//         }
//     }
//     return s.isEmpty();
// }
// int main() {
//     char exp[] = "{()}[]";
//     if (areParenthesesBalanced(exp)) {
//         cout << "Balanced\n";
//     } else {
//         cout << "Not Balanced\n";
//     }
//     return 0;
// }

// application of stack : remove consecutive duplicates in a string
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000
class Stack {
    int top;     // Index of the top element
    char a[MAX]; // Array for stack
public:
    Stack() { top = -1; }
    bool push(char x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
            return false;
        }
        a[++top] = x;
        return true;
    }
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return 0;
        }
        return a[top--];
    }
    char peek() {
        if (top < 0) {
            return 0; // Empty
        }
        return a[top];
    }
    bool isEmpty() { return (top < 0); }
};
// Function to remove consecutive duplicates
void removeDuplicate(char str[], Stack &s) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (s.isEmpty() || str[i] != s.peek()) {
            s.push(str[i]);
        }
    }
}
// Reverse stack content into string
void buildString(Stack &s, char result[]) {
    int i = 0;
    while (!s.isEmpty()) {
        result[i++] = s.pop();
    }
    result[i] = '\0';
    // reverse the string since stack pops in reverse order
    int n = strlen(result);
    for (int j = 0; j < n / 2; j++) {
        swap(result[j], result[n - j - 1]);
    }
}
int main() {
    Stack s;
    char exp[] = "aaabbcddaabffg";
    removeDuplicate(exp, s);
    char result[MAX];
    buildString(s, result);
    cout << "After removing consecutive duplicates: " << result << endl;
    return 0;
}
