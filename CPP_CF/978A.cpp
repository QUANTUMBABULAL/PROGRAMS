/*
Petya has an array a
 consisting of n
 integers. He wants to remove duplicate (equal) elements.

Petya wants to leave only the rightmost entry (occurrence) for each element of the array. The relative order of the remaining unique elements should not be changed.

Input
The first line contains a single integer n
 (1≤n≤50
) — the number of elements in Petya's array.

The following line contains a sequence a1,a2,…,an
 (1≤ai≤1000
) — the Petya's array.

Output
In the first line print integer x
 — the number of elements which will be left in Petya's array after he removed the duplicates.

In the second line print x
 integers separated with a space — Petya's array after he removed the duplicates. For each unique element only the rightmost entry should be left.

Examples
InputCopy
6
1 5 5 1 6 1
OutputCopy
3
5 6 1 
InputCopy
5
2 4 2 4 4
OutputCopy
2
2 4 
InputCopy
5
6 6 6 6 6
OutputCopy
1
6 
*/

// #include<bits/stdc++.c>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     unordered_map<int,int> mp;
//     for(int j=n-1;j--){
//         mp[arr[j]]=j;
//     }
//     sort(mp.begin(),mp.end());
//     for(int k=0;k<mp.size();k++){
//         cout<<mp.first(k);
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    // Store the last occurrence index of each number
    for (int j = n - 1; j >= 0; j--) {
        if (mp.count(arr[j]) == 0) {
            mp[arr[j]] = j;
        }
    }

    // Store only the indices
    vector<int> indices;

    for (auto it : mp) {
        indices.push_back(it.second);
    }

    // Sort indices to preserve original order
    sort(indices.begin(), indices.end());

    cout << indices.size() << "\n";

    // Print elements using their sorted indices
    for (int index : indices) {
        cout << arr[index] << " ";
    }

    return 0;
}