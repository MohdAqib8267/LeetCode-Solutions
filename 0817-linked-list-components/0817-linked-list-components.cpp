/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  
    int numComponents(ListNode* head, vector<int>& nums) {
     std::unordered_map<int, std::vector<int>> adj_list;
  ListNode* curr = head;
  while (curr != nullptr) {
    if (curr->next != nullptr) {
      adj_list[curr->val].push_back(curr->next->val);
      adj_list[curr->next->val].push_back(curr->val);
    }
    curr = curr->next;
  }

  // Mark all nodes in nums as visited
  std::unordered_map<int, bool> visited;
  for (int num : nums) {
    visited[num] = true;
  }

  // Perform a DFS on each node in nums to count the number of connected components
  int count = 0;
  for (int num : nums) {
    if (visited[num]) {
      count++;
      std::stack<int> stack;
      stack.push(num);
      visited[num] = false;
      while (!stack.empty()) {
        int curr = stack.top();
        stack.pop();
        for (int neighbor : adj_list[curr]) {
          if (visited[neighbor]) {
            stack.push(neighbor);
            visited[neighbor] = false;
          }
        }
      }
    }
  }

  return count;
    }
};