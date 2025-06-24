/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
*/
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr) {};
    ListNode(int i) : val(i), next(nullptr) {};
    ListNode(int i,ListNode* n) : val(i), next(n) {};
};

class Solution{
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = head;
        ListNode * tmp = nullptr;
        ListNode * pre = nullptr;
        while (cur != nullptr) {
            // 因为后面要改变cur-next，因此要先保存一份
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            // 更新cur
            cur = tmp;
        }
        return pre;
    }
};
