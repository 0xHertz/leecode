/*
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。
输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
*/
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
    public:
    // 最长滑动窗口
    int totalFruit(vector<int>& fruits) {
        int begin = 0;
        int result = 0;
        queue<int> tmp = {};
        for (int end = 0; end < fruits.size(); end++) {
            if (!isElementInQueue(tmp, fruits[end])) {
                tmp.push(fruits[end]);
            }
            // 窗口内满足的条件
            while (tmp.size() > 2) {
                tmp.pop();
                begin++; // 这里有问题，我需要一个既能保证不重复，又能记录重复次数的数据结构
            }
            result = result > end - begin + 1 ? result : end - begin + 1;
        }
        return result;
    }
    bool isElementInQueue(std::queue<int> q, int element) {
        std::vector<int> temp_vector;
        while (!q.empty()) {
            temp_vector.push_back(q.front());
            q.pop();
        }
        return std::find(temp_vector.begin(), temp_vector.end(), element) != temp_vector.end();
    }
    void print_queue(queue<int> que){
        while (!que.empty()) {
    		cout << que.front() << " ";
    		que.pop();
    	}
        cout << endl;
    }
    int totalFruit2(vector<int>& fruits) {
        int begin = 0;
        int result = 0;
        unordered_map<int, int> cnt;
        for (int end = 0; end < fruits.size(); end++) {
            cnt[fruits[end]]++;
            while (cnt.size() > 2) {
                cnt[fruits[begin]]--;
                if (cnt[fruits[begin]] == 0) {
                    cnt.erase(fruits[begin]);
                }
                begin++;
            }
            result = max(result,end-begin+1);
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    Solution app;
    vector<int> test = {3,3,3,1,2,1,1,2,3,3,4};
    cout << app.totalFruit(test);
}
