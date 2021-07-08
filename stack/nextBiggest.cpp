// // Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element 
// // for each element of the array in order of their appearance in the array.
// // Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// // If there does not exist next greater of current element, then next greater element for current element is -1. 
// // For example, next greater of the last element is always -1.



// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;

// int main(){                                     //not done

//     vector<int> arr;
//     stack<int> s;
//     vector<int> a;

//     arr.push_back(1);
//     arr.push_back(3);
//     arr.push_back(2);
//     arr.push_back(4);

//     s.push(arr[0]);
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (s.empty()) {
//             s.push(arr[i]);
//             continue;
//         }
 
//         /* if stack is not empty, then
//            pop an element from stack.
//            If the popped element is smaller
//            than next, then
//         a) print the pair
//         b) keep popping while elements are
//         smaller and stack is not empty */
//         while (s.empty() == false
//                && s.top() < arr[i])
//         {
//             a.push_back(arr[i]);
//             s.pop();
//         }
 
//         /* push next to stack so that we can find
//         next greater for it */
//         s.push(arr[i]);
//     }
 
//     /* After iterating over the loop, the remaining
//     elements in stack do not have the next greater
//     element, so print -1 for them */
//     while (s.empty() == false) {
//         a.push_back(-1);
//         s.pop();
//     }

//     for (auto i = a.begin(); i != a.end(); ++i)
//         cout << *i << " ";

//     return 0;
// }


// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;
 
/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;
 
    /* push the first element to stack */
    s.push(arr[0]);
 
    // iterate for rest of the elements
    for (int i = 1; i < n; i++)
    {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
 
        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        while (s.empty() == false
               && s.top() < arr[i])
        {
            cout << s.top()
                 << " --> " << arr[i] << endl;
            s.pop();
        }
 
        /* push next to stack so that we can find
        next greater for it */
        s.push(arr[i]);
    }
 
    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
 
/* Driver code */
int main()
{
    int arr[] = {7,8,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}