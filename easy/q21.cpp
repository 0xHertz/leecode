/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr) {};
    ListNode(int i) : val(i), next(nullptr) {};
    ListNode(int i,ListNode* n) : val(i), next(n) {};
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 定义结果链表
        ListNode *cur;
        ListNode *result = new ListNode(-1);
        cur = result;
        // 从头对比两个链表的值，谁小把谁添加进结果
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (list1) {
            cur->next = list1;
        }else {
            cur->next = list2;
        }
        return result->next;
    }
};
