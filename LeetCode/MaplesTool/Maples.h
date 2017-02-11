//
// Created by maples on 1/28/17.
//

#ifndef LEETCODE_MAPLES_H
#define LEETCODE_MAPLES_H

#include <vector>
#include <string>

namespace Maples {
    struct ListNode {
        int val;
        ListNode * next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * listNodePtr1 = l1;
        ListNode * listNodePtr2 = l2;
        ListNode * returnValue = new ListNode(0);
        ListNode * tempPtr = returnValue;

        int carry = 0;
        int result;
        while (listNodePtr1 && listNodePtr2) {
            result = listNodePtr1->val + listNodePtr2->val + carry;
            if (result > 9) {
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }
            tempPtr->next = new ListNode(result);
            tempPtr = tempPtr->next;
            listNodePtr1 = listNodePtr1->next;
            listNodePtr2 = listNodePtr2->next;
        }

//        if (carry != 0) {
//            tempPtr->next = new ListNode(carry);
//        }

        while (listNodePtr1) {
            result = listNodePtr1->val + carry;
            if (result > 9) {
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }
            tempPtr->next = new ListNode(result);
            tempPtr = tempPtr->next;
            listNodePtr1 = listNodePtr1->next;
        }

        while (listNodePtr2) {
            result = listNodePtr2->val + carry;
            if (result > 9) {
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }
            tempPtr->next = new ListNode(result);
            tempPtr = tempPtr->next;
            listNodePtr2 = listNodePtr2->next;
        }

        if (carry != 0) {
            tempPtr->next = new ListNode(carry);
        }

        tempPtr = returnValue;
        returnValue = returnValue->next;
        delete(tempPtr);
        return returnValue;
    }

    int lengthOfLongestSubstring(std::string s) {
        return 0;
    }
}


#endif //LEETCODE_MAPLES_H
