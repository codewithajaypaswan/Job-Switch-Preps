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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>>ans(n, vector<int>(m, -1));
        int rowBegin = 0, rowEnd = n-1, colBegin = 0, colEnd = m-1;
        while(head && rowBegin <= rowEnd && colBegin <= colEnd) {
            for(int i=colBegin; i<=colEnd && head; i++) {
                ans[rowBegin][i] = head->val;
                head = head->next;
            }
            rowBegin++;
            for(int i=rowBegin; i<=rowEnd && head; i++) {
                ans[i][colEnd] = head->val;
                head = head->next;
            }
            colEnd--;
            if(rowBegin <= rowEnd) {
                for(int i=colEnd; i>=colBegin && head; i--) {
                    ans[rowEnd][i] = head->val;
                    head = head->next;
                }
            }
            rowEnd--;
            if(colBegin <= colEnd) {
                for(int i=rowEnd; i>= rowBegin && head; i--) {
                    ans[i][colBegin] = head->val;
                    head = head->next;
                }
            }
            colBegin++;
        }
        return ans;
    }
};