#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for Binary Tree (Camp)
struct CampNode {
    string campName;
    CampNode* left;
    CampNode* right;
};

// Node structure for Binary Search Tree (Survivor)
struct SurvivorNode {
    string name;
    int skillLevel;
    SurvivorNode* left;
    SurvivorNode* right;
};

// Functions for Binary Tree (Camp Management)
CampNode* CreateCamp(string campName) {
    CampNode* newNode = new CampNode();
    newNode->campName = campName;
    newNode->left = newNode->right = NULL;
    return newNode;
}

CampNode* InsertCamp(CampNode* root, string campName) {
    if (root == NULL) {
        return CreateCamp(campName);
    }
    if (campName < root->campName) {
        root->left = InsertCamp(root->left, campName);
    } else {
        root->right = InsertCamp(root->right, campName);
    }
    return root;
}

bool SearchCamp(CampNode* root, string campName) {
    if (root == NULL) return false;
    if (root->campName == campName) return true;
    if (campName < root->campName) return SearchCamp(root->left, campName);
    return SearchCamp(root->right, campName);
}

CampNode* FindMinCamp(CampNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

CampNode* DeleteCamp(CampNode* root, string campName) {
    if (root == NULL) return root;
    if (campName < root->campName) {
        root->left = DeleteCamp(root->left, campName);
    } else if (campName > root->campName) {
        root->right = DeleteCamp(root->right, campName);
    } else {
        if (root->left == NULL) {
            CampNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            CampNode* temp = root->left;
            delete root;
            return temp;
        }
        CampNode* temp = FindMinCamp(root->right);
        root->campName = temp->campName;
        root->right = DeleteCamp(root->right, temp->campName);
    }
    return root;
}

void PreOrderCamp(CampNode* root) {
    if (root == NULL) return;
    cout << root->campName << " ";
    PreOrderCamp(root->left);
    PreOrderCamp(root->right);
}

void InOrderCamp(CampNode* root) {
    if (root == NULL) return;
    InOrderCamp(root->left);
    cout << root->campName << " ";
    InOrderCamp(root->right);
}

void PostOrderCamp(CampNode* root) {
    if (root == NULL) return;
    PostOrderCamp(root->left);
    PostOrderCamp(root->right);
    cout << root->campName << " ";
}

// Functions for Binary Search Tree (Survivor Management)
SurvivorNode* CreateSurvivor(string name, int skillLevel) {
    SurvivorNode* newNode = new SurvivorNode();
    newNode->name = name;
    newNode->skillLevel = skillLevel;
    newNode->left = newNode->right = NULL;
    return newNode;
}

SurvivorNode* InsertSurvivor(SurvivorNode* root, string name, int skillLevel) {
    if (root == NULL) {
        return CreateSurvivor(name, skillLevel);
    }
    if (skillLevel < root->skillLevel) {
        root->left = InsertSurvivor(root->left, name, skillLevel);
    } else {
        root->right = InsertSurvivor(root->right, name, skillLevel);
    }
    return root;
}

bool SearchSurvivor(SurvivorNode* root, int skillLevel) {
    if (root == NULL) return false;
    if (root->skillLevel == skillLevel) return true;
    if (skillLevel < root->skillLevel) return SearchSurvivor(root->left, skillLevel);
    return SearchSurvivor(root->right, skillLevel);
}

void PreOrderSurvivor(SurvivorNode* root) {
    if (root == NULL) return;
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
    PreOrderSurvivor(root->left);
    PreOrderSurvivor(root->right);
}

void InOrderSurvivor(SurvivorNode* root) {
    if (root == NULL) return;
    InOrderSurvivor(root->left);
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
    InOrderSurvivor(root->right);
}

void PostOrderSurvivor(SurvivorNode* root) {
    if (root == NULL) return;
    PostOrderSurvivor(root->left);
    PostOrderSurvivor(root->right);
    cout << root->name << " (Skill: " << root->skillLevel << ") ";
}

// Heap Functions
void insertMaxHeap(vector<SurvivorNode*>& heap, SurvivorNode* s) {
    heap.push_back(s);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index]->skillLevel > heap[parentIndex]->skillLevel) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void insertMinHeap(vector<SurvivorNode*>& heap, SurvivorNode* s) {
    heap.push_back(s);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index]->skillLevel < heap[parentIndex]->skillLevel) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}


void displayMaxHeapLeaderboard(const vector<SurvivorNode*>& heap) {
    cout << "Survivor of the Day Leaderboard (Max-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << ",     Skill Level: " << heap[i]->skillLevel << "\n";
    }
}

void displayMinHeapLeaderboard(const vector<SurvivorNode*>& heap) {
    cout << "Lowest Survivors Leaderboard (Min-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << "     Skill Level: " << heap[i]->skillLevel << "\n";
    }
}


void heapifyMax(vector<SurvivorNode*>& heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if left child exists and is greater than the current largest
    if (leftChild < heap.size() && heap[leftChild]->skillLevel > heap[largest]->skillLevel) {
        largest = leftChild;
    }

    // Check if right child exists and is greater than the current largest
    if (rightChild < heap.size() && heap[rightChild]->skillLevel > heap[largest]->skillLevel) {
        largest = rightChild;
    }

    // If largest is not the root, swap and recursively heapify
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyMax(heap, largest);
    }
}

void heapifyMin(vector<SurvivorNode*>& heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if left child exists and is smaller than the current smallest
    if (leftChild < heap.size() && heap[leftChild]->skillLevel < heap[smallest]->skillLevel) {
        smallest = leftChild;
    }

    // Check if right child exists and is smaller than the current smallest
    if (rightChild < heap.size() && heap[rightChild]->skillLevel < heap[smallest]->skillLevel) {
        smallest = rightChild;
    }

    // If smallest is not the root, swap and recursively heapify
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyMin(heap, smallest);
    }
}


void displayheapifyMin(const vector<SurvivorNode*>& heap) {
    cout << "Survivor of the Day Leaderboard (Max-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << ",     Skill Level: " << heap[i]->skillLevel << "\n";
    }
}

void displayheapifyMax(const vector<SurvivorNode*>& heap) {
    cout << "Lowest Survivors Leaderboard (Min-Heap):\n";
    for (int i = 0; i < heap.size(); i++) {
        cout << "Name: " << heap[i]->name << "     Skill Level: " << heap[i]->skillLevel << "\n";
    }
}



// Main Function
int main() {
    CampNode* campRoot = NULL;
    SurvivorNode* survivorRoot = NULL;
    vector<SurvivorNode*> maxHeap, minHeap;
    int choice, skillLevel;
    string campName, survivorName;

    while (true) {
        cout << "\n=== Zombie Apocalypse Survival System ===\n";
        cout << "1. Camp Management (Binary Tree)\n";
        cout << "2. Survivor Skills (BST)\n";
        cout << "3. Leaderboard Management (Heap)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int campChoice;
                while (true) {
                    cout << "\n--- Camp Management ---\n";
                    cout << "1. Add Camp\n2. Search Camp\n3. Delete Camp\n";
                    cout << "4. Display Preorder\n5. Display Inorder\n6. Display Postorder\n7. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> campChoice;

                    if (campChoice == 7) break;

                    switch (campChoice) {
                        case 1:
                            cout << "Enter camp name: ";
                            cin.ignore();
                            getline(cin, campName);
                            campRoot = InsertCamp(campRoot, campName);
                            break;
                        case 2:
                            cout << "Enter camp name to search: ";
                            cin.ignore();
                            getline(cin, campName);
                            if (SearchCamp(campRoot, campName)) {
                                cout << "Camp found: " << campName << "\n";
                            } else {
                                cout << "Camp not found.\n";
                            }
                            break;
                        case 3:
                            cout << "Enter camp name to delete: ";
                            cin.ignore();
                            getline(cin, campName);
                            campRoot = DeleteCamp(campRoot, campName);
                            break;
                        case 4:
                            cout << "Preorder Traversal: ";
                            PreOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        case 5:
                            cout << "Inorder Traversal: ";
                            InOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        case 6:
                            cout << "Postorder Traversal: ";
                            PostOrderCamp(campRoot);
                            cout << "\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 2: {
                int survivorChoice;
                while (true) {
                    cout << "\n--- Survivor Skills ---\n";
                    cout << "1. Add Survivor\n2. Search Survivor\n3. Display Preorder\n4. Display Inorder\n5. Display Postorder\n6. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> survivorChoice;

                    if (survivorChoice == 6) break;

                    switch (survivorChoice) {
                        case 1:
                            cout << "Enter survivor name: ";
                            cin.ignore();
                            getline(cin, survivorName);
                            cout << "Enter skill level: ";
                            cin >> skillLevel;
                            survivorRoot = InsertSurvivor(survivorRoot, survivorName, skillLevel);
                            insertMaxHeap(maxHeap, CreateSurvivor(survivorName, skillLevel));
                            insertMinHeap(minHeap, CreateSurvivor(survivorName, skillLevel));
                            break;
                        case 2:
                            cout << "Enter skill level to search: ";
                            cin >> skillLevel;
                            if (SearchSurvivor(survivorRoot, skillLevel)) {
                                cout << "Survivor found with skill level " << skillLevel << ".\n";
                            } else {
                                cout << "Survivor not found.\n";
                            }
                            break;
                        case 3:
                            cout << "Preorder Traversal: ";
                            PreOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        case 4:
                            cout << "Inorder Traversal: ";
                            InOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        case 5:
                            cout << "Postorder Traversal: ";
                            PostOrderSurvivor(survivorRoot);
                            cout << "\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 3: {
                int heapChoice;
                while (true) {
                    cout << "\n--- Leaderboard Management ---\n";
                    cout << "1. Display Survivor of the Day (Max-Heap)\n";
                    cout << "2. Display Lowest Survivors (Min-Heap)\n";
                    cout << "3. Display Heapify (Max-Heap)\n";
                    cout << "4. Display Heapify (Min-Heap)\n";
                    cout << "5. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> heapChoice;

                    if (heapChoice == 5) break;

                    switch (heapChoice) {
                        case 1:
                            displayMaxHeapLeaderboard(maxHeap);
                            break;
                        case 2:
                            displayMinHeapLeaderboard(minHeap);
                            break;
                        case 3:displayheapifyMax (maxHeap);
                            break;
                        case 4:displayheapifyMin (minHeap);
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting the program. Stay safe!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
