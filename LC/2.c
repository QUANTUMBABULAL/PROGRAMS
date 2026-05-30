/*
1. Two Sum
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/


#include<stdio.h>
#define TABLE_SIZE 1001

typedef struct Node{
    int key;
    int value;
    struct Node *next;

}Node;

int hash(int key){
    if (key<0) return -key;
    return key%TABLE_SIZE;
}

void insert(Node** table ,int key ,int value){
    int index = hash(key);
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key=key;
    newnode->value=value;
    newnode->next=table[index];
    table[index]=newnode;
}

Node * find(Node **table , int key){
    int index=hash(key);
    Node *curr=table[index];
    while(curr){
        if(curr->key==key){
            return curr;
        }
        curr=curr->next;
    }
    return NULL;

}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* Table[TABLE_SIZE]={NULL};
    for(int i=0;i<numsSize;i++){
        int complement=target-nums[i];
        Node* found = find(Table ,complement);

        if(found){
            int * result = (int*)malloc(2*sizeof(int));
            result[0]=found->value;
            result[1]=i;
            *returnSize=2;
            return result;
        }
        insert(Table,nums[i],i);

    }
    *returnSize = 0;
    return NULL;
}



