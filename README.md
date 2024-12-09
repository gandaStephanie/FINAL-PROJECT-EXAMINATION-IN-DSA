Project Overview

This project is a Zombie Apocalypse Survival System, which combines three functionalities:

Camp Management: Manages camps using a binary tree (BT).
Survivor Skills: Organizes survivors based on skill levels using a binary search tree (BST).
Leaderboard Management: Maintains leaderboards using max-heaps and min-heaps.
Each component contributes to creating a survival system to manage camps, survivors, and their rankings efficiently.

How to Run the Code

When you run the provided C++ code, you will be interacting with a Zombie Apocalypse Survival System program. It consists of three main components: Camp Management, Survivor Skills, and Leaderboard Management. Here's a breakdown of what you can expect:
---
1. Main Menu
When the program starts, you will see the following main menu:
=== Zombie Apocalypse Survival System ===
1. Camp Management (Binary Tree)
2. Survivor Skills (BST)
3. Leaderboard Management (Heap)
4. Exit
Enter your choice:
You will be prompted to enter a choice (1, 2, 3, or 4) for one of the three options or to exit the program.
---
2. Camp Management (Binary Tree)
3.  If you select 1 (Camp Management), you will enter a submenu for managing camps as a binary tree:
--- Camp Management ---
1. Add Camp
2. Search Camp
3. Delete Camp
4. Display Preorder
5. Display Inorder
6. Display Postorder
7. Exit to Main Menu
Enter your choice:
Here’s what you can do:

Add Camp: You can add a camp by entering its name. The system will insert the camp in a binary tree based on lexicographical order.
Search Camp: You can search for a camp by its name. The program will search the binary tree.
Delete Camp: You can delete a camp from the tree.
Display Traversals: You can view the tree in three different traversal orders (Preorder, Inorder, or Postorder).

3. Survivor Skills (Binary Search Tree)
If you select 2 (Survivor Skills), you enter a submenu for managing survivors, stored in a Binary Search Tree (BST):
--- Survivor Skills ---
1. Add Survivor
2. Search Survivor
3. Display Preorder
4. Display Inorder
5. Display Postorder
6. Exit to Main Menu
Enter your choice:
Here’s what you can do:

Add Survivor: You can add a survivor with a name and skill level. The system will insert the survivor into a BST ordered by the skill level.
Search Survivor: You can search for a survivor by skill level.
Display Traversals: You can view the tree in three different traversal orders (Preorder, Inorder, or Postorder).

4. Leaderboard Management (Heap)
If you select 3 (Leaderboard Management), you enter a submenu to manage the leaderboard using heaps:
--- Leaderboard Management ---
1. Display Survivor of the Day (Max-Heap)
2. Display Lowest Survivors (Min-Heap)
3. Display Heapify (Max-Heap)
4. Display Heapify (Min-Heap)
5. Exit to Main Menu
Enter your choice:
Here’s what you can do:

Display Survivor of the Day (Max-Heap): This will show the survivors ordered by skill level in descending order (max-heap).
Display Lowest Survivors (Min-Heap): This will show the survivors ordered by skill level in ascending order (min-heap).
Display Heapify (Max-Heap): This will show the heap after performing a heapify operation on the max-heap.
Display Heapify (Min-Heap): This will show the heap after performing a heapify operation on the min-heap.

5. Exit
If you select 4, the program will exit with the message:

Exiting the program. Stay safe!
Example Interaction:
Let’s walk through an example interaction:

Initial Main Menu:
=== Zombie Apocalypse Survival System ===
1. Camp Management (Binary Tree)
2. Survivor Skills (BST)
3. Leaderboard Management (Heap)
4. Exit
Enter your choice: 1
Camp Management Menu:
--- Camp Management ---
1. Add Camp
2. Search Camp
3. Delete Camp
4. Display Preorder
5. Display Inorder
6. Display Postorder
7. Exit to Main Menu
Enter your choice: 1
You add a new camp with a name:
Enter camp name: Camp Alpha
The system inserts the camp and prompts for another action:

--- Camp Management ---
1. Add Camp
2. Search Camp
3. Delete Camp
4. Display Preorder
5. Display Inorder
6. Display Postorder
7. Exit to Main Menu
Enter your choice: 4
You choose Display Preorder:

Preorder Traversal: Camp Alpha 
Exit Example:
After choosing Exit to Main Menu, you return to the main menu:

=== Zombie Apocalypse Survival System ===
1. Camp Management (Binary Tree)
2. Survivor Skills (BST)
3. Leaderboard Management (Heap)
4. Exit
Enter your choice: 4
Exiting the program. Stay safe!


Description of Each Functionality

1. Camp Management (Binary Tree)
CreateCamp: Creates a new camp node.
InsertCamp: Adds a camp to the binary tree.
SearchCamp: Searches for a camp by its name.
DeleteCamp: Deletes a camp by its name, maintaining the binary tree structure.
Tree Traversals:
Preorder (PreOrderCamp): Displays camps in the "Root-Left-Right" order.
Inorder (InOrderCamp): Displays camps in sorted order (alphabetically).
Postorder (PostOrderCamp): Displays camps in the "Left-Right-Root" order.


2. Survivor Skills (Binary Search Tree)
CreateSurvivor: Creates a new survivor node with a name and skill level.
InsertSurvivor: Inserts a survivor into the BST based on skill level.
SearchSurvivor: Searches for a survivor with a specific skill level.
Tree Traversals:
Preorder (PreOrderSurvivor): Displays survivors in "Root-Left-Right" order.
Inorder (InOrderSurvivor): Displays survivors sorted by skill levels.
Postorder (PostOrderSurvivor): Displays survivors in "Left-Right-Root" order.


3. Leaderboard Management (Heap)
Max-Heap:
insertMaxHeap: Inserts a survivor into the max-heap based on skill level.
displayMaxHeapLeaderboard: Displays the max-heap leaderboard (highest skill levels).
Min-Heap:
insertMinHeap: Inserts a survivor into the min-heap based on skill level.
displayMinHeapLeaderboard: Displays the min-heap leaderboard (lowest skill levels).
Heapify:
heapifyMax: Adjusts the max-heap to maintain the heap property.
heapifyMin: Adjusts the min-heap to maintain the heap property.
displayheapifyMax and displayheapifyMin: Display the results of heapification.
Menu Options
Option 1: Camp Management

Manage camps with operations like adding, searching, deleting, and displaying them using binary tree traversals.
Option 2: Survivor Skills

Add and search survivors or display them in different traversal orders in the BST.
Option 3: Leaderboard Management

Display leaderboards using max-heap (top survivors) or min-heap (least-skilled survivors).
Option 4: Exit

Safely exits the program.
This structure makes the system highly modular and intuitive for managing survival strategies during a zombie apocalypse.

