#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        root.reset();
    }

    BinaryTree(const BinaryTree &other) {
        root = clone(other.root);
    }

    void insert(int value) {
        if (!root) {
            root = std::make_unique<Node>(value);
        } else {
            insertRecursively(root, value);
        }
    }

    void remove(int value) {
        root = removeRecursively(std::move(root), value);
    }

    void printTree() const {
        printTreeRecursively(root, 0);
    }

private:
    std::unique_ptr<Node> root;

    void insertRecursively(std::unique_ptr<Node> &node, int value) {
        if (!node) {
            node = std::make_unique<Node>(value);
        } else if (value < node->data) {
            insertRecursively(node->left, value);
        } else {
            insertRecursively(node->right, value);
        }
    }

    std::unique_ptr<Node> removeRecursively(std::unique_ptr<Node> node, int value) {
        if (!node) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = removeRecursively(std::move(node->left), value);
        } else if (value > node->data) {
            node->right = removeRecursively(std::move(node->right), value);
        } else {
            if (!node->left) {
                return std::move(node->right);
            } else if (!node->right) {
                return std::move(node->left);
            } else {
                node->data = findMin(node->right);
                node->right = removeRecursively(std::move(node->right), node->data);
            }
        }
        return node;
    }

    int findMin(const std::unique_ptr<Node> &node) const {
        auto current = node.get();
        while (current->left) {
            current = current->left.get();
        }
        return current->data;
    }

    std::unique_ptr<Node> clone(const std::unique_ptr<Node> &node) {
        if (!node) {
            return nullptr;
        }
        auto new_node = std::make_unique<Node>(node->data);
        new_node->left = clone(node->left);
        new_node->right = clone(node->right);
        return new_node;
    }

    void printTreeRecursively(const std::unique_ptr<Node> &node, int space) const {
        int count = 5;
        if (!node) {
            return;
        }
        space += count;
        printTreeRecursively(node->right, space);
        std::cout << std::endl;
        for (int i = count; i < space; i++) {
            std::cout << " ";
        }
        std::cout << node->data << "\n";
        printTreeRecursively(node->left, space);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Binary Tree:" << std::endl;
    tree.printTree();

    tree.remove(3);

    std::cout << "Binary Tree after removing 3:" << std::endl;
    tree.printTree();

    return 0;
}
