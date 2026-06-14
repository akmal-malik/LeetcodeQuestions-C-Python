#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;

        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step 3: Find maximum twin sum
        int maxSum = 0;

        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            maxSum = max(maxSum,
                         firstHalf->val + secondHalf->val);

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxSum;
    }
};