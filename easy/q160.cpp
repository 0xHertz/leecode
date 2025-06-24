/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
题目数据 保证 整个链式结构中不存在环。

评测系统 的输入如下（你设计的程序 不适用 此输入）：

intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
listA - 第一个链表
listB - 第二个链表
skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。
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
    // 最简单的嵌套遍历，复杂度m*n
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA = headA;
        ListNode * curB = headB;
        while (curA) {
            curB = headB;
            while (curB) {
                if (curA == curB){
                    return curA;
                }
                curB = curB->next;
            }
            curA = curA->next;
        }
        return nullptr;
    }
};
