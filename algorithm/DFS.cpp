//DFS : 深さ優先探索 Depth-First Search

#include <iostream>
#include <stack>

using namespace std;

typedef struct _Node {
    int val;
    struct _Node *left;
    struct _Node *right;
} Node;

void DFS(Node node[], int target_val) {
    stack<Node> open_list;

    open_list.push(node[1]);

    while (!open_list.empty()) {
        Node pop_node = open_list.top();
        open_list.pop();

        cout << pop_node.val << endl;

        if (pop_node.val == target_val) {
            cout << "find" << endl;
            return;
        } else {
            if (pop_node.right != nullptr) {
                open_list.push(*pop_node.right);
            }
            if (pop_node.left != nullptr) {
                open_list.push(*pop_node.left);
            }
        }
    }
    cout << "not find" << endl;
}

int main(void) {
    Node node[10];
    for (int i = 1; i < 10; ++i) {
        node[i].val = i;
        node[i].left = nullptr;
        node[i].right = nullptr;
    }
    node[1].left = &node[7];
    node[1].right = &node[2];

    node[2].left = &node[5];
    node[2].right = &node[3];

    node[3].left = nullptr;
    node[3].right = &node[4];

    node[5].left = nullptr;
    node[5].right = &node[6];

    node[7].left = &node[8];
    node[7].right = &node[9];



    DFS(node, 11);
}