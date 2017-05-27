//
//  main.cpp
//  Leetcode
//
//  Created by 韩钊 on 2017/1/16.
//  Copyright © 2017年 韩钊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//vector<int> twoSum(vector<int> &numbers, int target)
//{
//    //Key is the number and value is its index in the vector.
//    unordered_map<int, int> hash;
//    vector<int> result;
//    for (int i = 0; i < numbers.size(); i++) {
//        int numberToFind = target - numbers[i];
//        
//        //if numberToFind is found in map, return them
//        if (hash.find(numberToFind) != hash.end()) {
//            //+1 because indices are NOT zero based
//            result.push_back(hash[numberToFind]);
//            result.push_back(i);
//            return result;
//        }
//        
//        //number was not found. Put it in the map.
//        hash[numbers[i]] = i;
//    }
//    return result;
//}
class Solution {
public:
     vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;
        
        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a({2,3,4,5});
//    vector<int> b = twoSum(a, 7);
    Solution so;
    vector<int> result = so.productExceptSelf(a);
    for(int i = 0 ;i < result.size(); i++)
        cout <<result[i]<< "\n";
    return 0;
}
/*

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new ListNode(1);
        return sentinel.next;
    }
}
*/