/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点(下标1)。
*/

#include <unordered_set>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr) {};
    ListNode(int i) : val(i), next(nullptr) {};
    ListNode(int i,ListNode* n) : val(i), next(n) {};
};

class Solution{
    public:
    // 当前节点的next指向的节点是否有visited，有返回true，没有将next执指向的节点标记为visited，当前节点后移
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode * cur = head;
        while (cur) {
            if(isVisited(cur->next,visited)){
                return true;
            }else{
                cur = cur->next;
            }
        }
        return false;
    }
    bool isVisited(ListNode * ptr,unordered_set<ListNode*> &visited){
        if (visited.count(ptr)){
            return true;
        }else{
            visited.insert(ptr);
            return false;
        }
    }
};
