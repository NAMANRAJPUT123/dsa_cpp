// // stack using array
// #include <iostream>
// using namespace std;
// #define MAX 1000
// class Stack {
//     int top;  // Index of the top element
//     int a[MAX]; // Maximum size of Stack
// public:
//     Stack() { top = -1; }
//     bool push(int x);
//     int pop();
//     int peek();
//     bool isEmpty();
// };
// bool Stack::push(int x) {
//     if (top >= (MAX - 1)) {
//         cout << "Stack Overflow";
//         return false;
//     } else {
//         a[++top] = x;
//         cout << x << " pushed into stack\n";
//         return true;
//     }
// }
// int Stack::pop() {
//     if (top < 0) {
//         cout << "Stack Underflow";
//         return 0;
//     } else {
//         int x = a[top--];
//         return x;
//     }
// }
// int Stack::peek() {
//     if (top < 0) {
//         cout << "Stack is Empty";
//         return 0;
//     } else {
//         int x = a[top];
//         return x;
//     }
// }
// bool Stack::isEmpty() {
//     return (top < 0);
// }
// // Driver program to test above functions
// int main() {
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     cout << s.pop() << " Popped from stack\n";
//     cout << "Top element is : " << s.peek() << endl;
//     cout << "Stack empty : " << s.isEmpty() << endl;
//     return 0;
// }
// C CODE 
// #include <stdio.h>
// #include <stdbool.h>
// #define MAX 1000
// typedef struct {
//     int top;
//     int a[MAX];
// } Stack;
// void initStack(Stack* s) {
//     s->top = -1;
// }
// bool push(Stack* s, int x) {
//     if (s->top >= (MAX - 1)) {
//         printf("Stack Overflow\n");
//         return false;
//     } else {
//         s->a[++(s->top)] = x;
//         printf("%d pushed into stack\n", x);
//         return true;
//     }
// }
// int pop(Stack* s) {
//     if (s->top < 0) {
//         printf("Stack Underflow\n");
//         return 0;
//     } else {
//         return s->a[(s->top)--];
//     }
// }
// int peek(Stack* s) {
//     if (s->top < 0) {
//         printf("Stack is Empty\n");
//         return 0;
//     } else {
//         return s->a[s->top];
//     }
// }
// bool isEmpty(Stack* s) {
//     return (s->top < 0);
// }
// // Driver program to test above functions
// int main() {
//     Stack s;
//     initStack(&s);
//     push(&s, 10);
//     push(&s, 20);
//     push(&s, 30);
//     printf("%d Popped from stack\n", pop(&s));
//     printf("Top element is : %d\n", peek(&s));
//     printf("Stack empty : %d\n", isEmpty(&s));
//     return 0;
// }

// stack using linked list ,ulti linked list socho 
#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { top = nullptr; }
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();             // Display top → bottom
    void displayReverse();      // Display bottom → top
private:
    void displayReverseHelper(StackNode* node); // Helper for recursion
};

void Stack::push(int x) {
    StackNode* newNode = new StackNode();
    if (!newNode) {
        cout << "Heap Overflow\n";
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " pushed into stack\n";
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return 0;
    }
    StackNode* temp = top;
    int popped = top->data;
    top = top->next;
    delete temp;
    return popped;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return 0;
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

// Display top → bottom
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    StackNode* temp = top;
    cout << "Stack (top → bottom): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Recursive helper to display bottom → top
void Stack::displayReverseHelper(StackNode* node) {
    if (node == nullptr) return;
    displayReverseHelper(node->next);
    cout << node->data << " ";
}
// Display bottom → top
void Stack::displayReverse() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack (bottom → top): ";
    displayReverseHelper(top);
    cout << endl;
}
// Driver program
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);  // Stack: 30 20 10
    s.display();         // top → bottom
    s.displayReverse();  // bottom → top
    cout << s.pop() << " Popped from stack\n";
    s.display();
    s.displayReverse();
    cout << "Top element is : " << s.peek() << endl;
    cout << "Stack empty : " << s.isEmpty() << endl;
    return 0;
}


// application of stack : reverse a string using stack
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
// bool Stack::isEmpty() {
//     return (top < 0);
// }
// void reverseString(char str[]) {
//     int n = strlen(str);
//     Stack s;
//     for (int i = 0; i < n; i++) {
//         s.push(str[i]);
//     }
//     for (int i = 0; i < n; i++) {
//         str[i] = s.pop();
//     }
// }
// int main() {
//     char str[] = "Hello, World!";
//     reverseString(str);
//     cout << "Reversed string is: " << str << endl;
//     return 0;
// }


//application of stack : evaluate a postfix expression
// #include <iostream>
// #include <cstring>
// #include <cctype>
// #include <cstdlib>
// using namespace std;
// #define MAX 1000
// class Stack {
//     int top;    // Index of the top element
//     int a[MAX]; // Maximum size of Stack
// public:
//     Stack() { top = -1; }
//     bool push(int x);
//     int pop();
//     bool isEmpty();
// };
// bool Stack::push(int x) {
//     if (top >= (MAX - 1)) {
//         cout << "Stack Overflow";
//         return false;
//     } else {
//         a[++top] = x;
//         return true;
//     }
// }
// int Stack::pop() {
//     if (top < 0) {
//         cout << "Stack Underflow";
//         return 0;
//     } else {
//         int x = a[top--];
//         return x;
//     }
// }
// bool Stack::isEmpty() {
//     return (top < 0);
// }
// int evaluatePostfix(char exp[]) {
//     Stack s;
//     for (int i = 0; i < strlen(exp); i++) {
//         if (isdigit(exp[i])) {
//             s.push(exp[i] - '0'); // Convert char to int
//         } else {
//             int val2 = s.pop();
//             int val1 = s.pop();
//             switch (exp[i]) {
//                 case '+': s.push(val1 + val2); break;
//                 case '-': s.push(val1 - val2); break;
//                 case '*': s.push(val1 * val2); break;
//                 case '/': s.push(val1 / val2); break;
//             }
//         }
//     }
//     return s.pop();
// }
// int main() {
//     char exp[] = "231*+9-";
//     cout << "Postfix Evaluation: " << evaluatePostfix(exp) << endl;
//     return 0;
// }

//application of stack : convert infix expression to postfix expression

// #include <iostream>
// #include <stack>
// #include <string>
// #include <cctype>
// using namespace std;
// int precedence(char op) {
//     if (op == '^') return 3;
//     if (op == '*' || op == '/') return 2;
//     if (op == '+' || op == '-') return 1;
//     return -1;
// }
// bool isRightAssociative(char op) {
//     return op == '^';
// }
// bool isOperator(char c) {
//     return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
// }
// string applyOp(const string &a, const string &b, char op) {
//     // For prefix, operator + left + right
//     // a and b are the *left* and *right* operands respectively
//     return string(1, op) + a + b;
// }
// string infixToPrefix(const string &infix) {
//     stack<char> ops;            // operator stack
//     stack<string> operands;     // operand (strings) stack

//     for (size_t i = 0; i < infix.size(); ++i) {
//         char c = infix[i];

//         if (isspace((unsigned char)c)) continue;

//         if (c == '(') {
//             ops.push(c);
//         } else if (c == ')') {
//             // process until '('
//             while (!ops.empty() && ops.top() != '(') {
//                 char op = ops.top(); ops.pop();
//                 if (operands.size() < 2) return ""; // malformed
//                 string right = operands.top(); operands.pop();
//                 string left  = operands.top(); operands.pop();
//                 operands.push(applyOp(left, right, op));
//             }
//             if (!ops.empty() && ops.top() == '(') ops.pop();
//             else return ""; // mismatched parentheses
//         } else if (isOperator(c)) {
//             // while top op has higher precedence or equal (and current is left-assoc), apply it
//             while (!ops.empty() && ops.top() != '(') {
//                 char topOp = ops.top();
//                 int pTop = precedence(topOp);
//                 int pCur = precedence(c);
//                 if (pTop > pCur || (pTop == pCur && !isRightAssociative(c))) {
//                     // apply topOp
//                     ops.pop();
//                     if (operands.size() < 2) return ""; // malformed
//                     string right = operands.top(); operands.pop();
//                     string left  = operands.top(); operands.pop();
//                     operands.push(applyOp(left, right, topOp));
//                 } else break;
//             }
//             ops.push(c);
//         } else {
//             // operand: single letter/digit (if you need multi-char tokens, tokenize here)
//             string operand(1, c);
//             operands.push(operand);
//         }
//     }

//     // apply remaining ops
//     while (!ops.empty()) {
//         if (ops.top() == '(' || ops.top() == ')') return ""; // mismatched
//         char op = ops.top(); ops.pop();
//         if (operands.size() < 2) return "";
//         string right = operands.top(); operands.pop();
//         string left  = operands.top(); operands.pop();
//         operands.push(applyOp(left, right, op));
//     }

//     if (operands.size() != 1) return ""; // malformed
//     return operands.top();
// }

// int main() {
//     string infix;
//     cout << "Enter an infix expression: ";
//     getline(cin, infix);

//     string prefix = infixToPrefix(infix);
//     if (prefix.empty()) {
//         cerr << "Error converting expression (check parentheses / tokens)\n";
//         return 1;
//     }
//     cout << "Infix:  " << infix << '\n';
//     cout << "Prefix: " << prefix << '\n';
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define SIZE 100
// int A[SIZE];
// int top1, top2;
// void initStacks(void) {
//     top1 = -1;     
//     top2 = SIZE;   
// }
// bool push1(int x) {
//     if (top1 + 1 == top2) {           
//         return false;
//     }
//     A[++top1] = x;
//     return true;
// }
// bool push2(int x) {
//     if (top2 - 1 == top1) {      
//         return false;
//     }
//     A[--top2] = x;
//     return true;
// }
// int pop1(bool *ok) {
//     if (top1 < 0) {
//         *ok = false;   
//         return 0;
//     }
//     *ok = true;
//     return A[top1--];
// }
// int pop2(bool *ok) {
//     if (top2 >= SIZE) {
//         *ok = false;  
//         return 0;
//     }
//     *ok = true;
//     return A[top2++];
// }
// bool isEmpty1(void) { return top1 < 0; }
// bool isEmpty2(void) { return top2 >= SIZE; }
// int peek1(bool *ok) {
//     if (top1 < 0) { *ok = false; return 0; }
//     *ok = true; return A[top1];
// }
// int peek2(bool *ok) {
//     if (top2 >= SIZE) { *ok = false; return 0; }
//     *ok = true; return A[top2];
// }
// int main(void) {
//     initStacks();
//     for (int i = 1; i <= 5; ++i) {
//         if (!push1(i)) printf("push1 overflow when pushing %d\n", i);
//     }
//     for (int i = 100; i <= 104; ++i) {
//         if (!push2(i)) printf("push2 overflow when pushing %d\n", i);
//     }
//     bool ok;
//     while (!isEmpty1()) {
//         int v = pop1(&ok);
//         if (ok) printf("pop1: %d\n", v);
//     }
//     while (!isEmpty2()) {
//         int v = pop2(&ok);
//         if (ok) printf("pop2: %d\n", v);
//     }
// }

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> 
#define MAX 100 
typedef struct {
    char data[MAX];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
bool push(Stack *s, char c) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow!\n");
        return false;
    }
    s->data[++(s->top)] = c;
    return true;
}
char pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->data[(s->top)--];
}
char peek(Stack *s) {
    if (s->top < 0) return '\0';
    return s->data[s->top];
}
bool isEmpty(Stack *s) {
    return s->top < 0;
}
bool isPalindrome(const char *str) {
    int n = strlen(str);
    Stack s;
    initStack(&s);
    int i;
    for (i = 0; i < n / 2; i++) {
        push(&s, str[i]);
    }
    if (n % 2 != 0) i++;
    for (; i < n; i++) {
        char c = pop(&s);
        if (c != str[i]) return false;  
    }

    return true;  
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str); 
    if (isPalindrome(str))
        printf("\"%s\" is a palindrome.\n", str);
    else
        printf("\"%s\" is not a palindrome.\n", str);

    return 0;
}
