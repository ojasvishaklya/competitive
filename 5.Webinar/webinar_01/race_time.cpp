//https://www.spoj.com/problems/RACETIME/
// RACETIME - Race Against Time
// #ad-hoc-1
// As another one of their crazy antics, the N (1 ≤ N ≤ 100,000) cows want Farmer John to race against the clock to answer some of their pressing questions.

// The cows are lined up in a row from 1 to N, and each one is holding a sign representing a number, Ai (1 ≤ Ai ≤ 1,000,000,000). The cows need FJ to perform Q (1 ≤ Q ≤ 50,000) operations, which can be either of the following:

// Modify cow i's number to X (1 ≤ X ≤ 1,000,000,000). This will be represented in the input as a line containing the letter M followed by the space-separated numbers i and X.
// Count how many cows in the range [P, Q] (1 ≤ P ≤ Q ≤ N) have Ai ≤ X (0 ≤ X ≤ 1,000,000,000). This will be represented in the input as a line containing the letter C followed by the space-separated numbers P, Q, and X.
// Of course, FJ would like your help.

// Input
// The first line gives the integers N and Q, and the next N lines give the initial values of Ai. Finally, the next Q lines each contain a query of the form "M i X" or "C P Q X".

// Output
// Print the answer to each 'C' query, one per line.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr, bucket;
int bs = 0;

int main()
{

    int n, q;
    cin >> n >> q;

    bs = sqrt(n) + 1;
    bucket.resize(bs + 1, 0);
    arr.resize(n);
    while(q-->0)
    {
        string s;

        cin>>s;

        if()
    }
}