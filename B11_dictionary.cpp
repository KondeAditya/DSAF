#include <iostream>
#include <string>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(string keyword, string meaning) {
    Node* newNode = new Node();
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a new keyword-meaning pair into the BST
Node* insert(Node* root, string keyword, string meaning) {
    if (root == nullptr) {
        return createNode(keyword, meaning);
    }
    if (keyword < root->keyword) {
        root->left = insert(root->left, keyword, meaning);
    } else if (keyword > root->keyword) {
        root->right = insert(root->right, keyword, meaning);
    }
    return root;
}

// Function to perform inorder traversal (ascending order) of the BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->keyword << ": " << root->meaning << endl;
        inorder(root->right);
    }
}

// Function to perform reverse inorder traversal (descending order) of the BST
void reverseInorder(Node* root) {
    if (root != nullptr) {
        reverseInorder(root->right);
        cout << root->keyword << ": " << root->meaning << endl;
        reverseInorder(root->left);
    }
}

// Function to find the meaning of a keyword in the BST
string findMeaning(Node* root, string keyword, int& comparisons) {
    comparisons++;
    if (root == nullptr) {
        return "Keyword not found.";
    }
    if (keyword < root->keyword) {
        return findMeaning(root->left, keyword, comparisons);
    } else if (keyword > root->keyword) {
        return findMeaning(root->right, keyword, comparisons);
    } else {
        return root->meaning;
    }
}

// Function to find the maximum number of comparisons required to find a keyword in the BST
int findMaxComparisons(Node* root, string keyword) {
    int comparisons = 0;
    findMeaning(root, keyword, comparisons);
    return comparisons;
}

// Function to delete a node with given keyword from the BST
Node* deleteNode(Node* root, string keyword) {
    if (root == nullptr) {
        return root;
    }
    if (keyword < root->keyword) {//to find in left subtree
        root->left = deleteNode(root->left, keyword);
    } else if (keyword > root->keyword) {//to find in right subtree
        root->right = deleteNode(root->right, keyword);
    } else {//if node is found
        if (root->left == nullptr) {//no left child
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {//no right child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != nullptr) {//both left and right is present 
            temp = temp->left;
        }
        root->keyword = temp->keyword;
        root->meaning = temp->meaning;
        root->right = deleteNode(root->right, temp->keyword);
    }
    return root;
}

// Function to update the meaning of a keyword in the BST
void updateMeaning(Node* root, string keyword, string newMeaning) {
    int comparisons = 0;
    string meaning = findMeaning(root, keyword, comparisons);
    if (meaning != "Keyword not found.") {
        deleteNode(root, keyword);
        insert(root, keyword, newMeaning);
        cout << "Meaning updated successfully." << endl;
    } else {
        cout << "Keyword not found. Cannot update meaning." << endl;
    }
}
int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a keyword-meaning pair\n";
        cout << "2. Delete a keyword-meaning pair\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Search for the meaning of a keyword\n";
        cout << "5. Display the dictionary in ascending order\n";
        cout << "6. Display the dictionary in descending order\n";
        cout << "7. Find the maximum number of comparisons required for any keyword\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string keyword, meaning;
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin >> ws; // Clear any whitespace characters from the buffer
                getline(cin, meaning);
                root = insert(root, keyword, meaning);
                cout << "Keyword-meaning pair added successfully.\n";
                break;
            }
            case 2: {
                string keyword;
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                cout << "Keyword-meaning pair deleted successfully.\n";
                break;
            }
            case 3: {
                string keyword, newMeaning;
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin >> ws; // Clear any whitespace characters from the buffer
                getline(cin, newMeaning);
                updateMeaning(root, keyword, newMeaning);
                break;
            }
            case 4: {
                string keyword;
                cout << "Enter keyword to search: ";
                cin >> keyword;
                int comparisons = 0;
                string meaning = findMeaning(root, keyword, comparisons);
                if (meaning != "Keyword not found.") {
                    cout << "Meaning of '" << keyword << "': " << meaning << endl;
                    cout << "Number of comparisons made: " << comparisons << endl;
                } else {
                    cout << "Meaning of '" << keyword << "': " << meaning << endl;
                }
                break;
            }
            case 5: {
                cout << "Dictionary in ascending order:" << endl;
                inorder(root);
                break;
            }
            case 6: {
                cout << "Dictionary in descending order:" << endl;
                reverseInorder(root);
                break;
            }
            case 7: {
                string keyword;
                cout << "Enter keyword to find maximum comparisons: ";
                cin >> keyword;
                int maxComparisons = findMaxComparisons(root, keyword);
                cout << "Maximum number of comparisons for finding '" << keyword << "': " << maxComparisons << endl;
                break;
            }
            case 8: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}
//123 "ABC" "abc" "123" high->low