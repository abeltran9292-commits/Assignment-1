#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

// Checks every possible pair
pair<int, int> twoSumBruteForce(
    const vector<int>& nums,
    int target
) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// Uses a hash table to find the pair faster
pair<int, int> twoSumHash(
    const vector<int>& nums,
    int target
) {
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];

        if (seen.find(needed) != seen.end()) {
            return {seen[needed], i};
        }

        seen[nums[i]] = i;
    }

    return {-1, -1};
}

// Prints and checks the answer
void printResult(
    string method,
    const vector<int>& nums,
    int target,
    pair<int, int> answer
) {
    int first = answer.first;
    int second = answer.second;

    bool valid = first >= 0 &&
                 second >= 0 &&
                 first != second &&
                 nums[first] + nums[second] == target;

    cout << method << endl;
    cout << "Indices: (" << first << ", " << second << ")" << endl;
    cout << "Values: " << nums[first] << " + " << nums[second] << endl;
    cout << "Valid: " << (valid ? "Yes" : "No") << endl;
    cout << endl;
}

// Runs both methods on one test
void runTest(
    string testName,
    const vector<int>& nums,
    int target
) {
    cout << "------------------------------" << endl;
    cout << testName << endl;
    cout << "Target: " << target << endl << endl;

    printResult(
        "Brute Force:",
        nums,
        target,
        twoSumBruteForce(nums, target)
    );

    printResult(
        "Hash Method:",
        nums,
        target,
        twoSumHash(nums, target)
    );
}

int main() {
    // Required test
    runTest(
        "Required Test",
        {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9},
        24
    );

    // Four additional tests
    runTest(
        "Test 2: Positive Numbers",
        {2, 7, 11, 15},
        9
    );

    runTest(
        "Test 3: Duplicate Numbers",
        {3, 3},
        6
    );

    runTest(
        "Test 4: Negative Number",
        {-5, 2, 9, 4},
        -1
    );

    runTest(
        "Test 5: Zeroes",
        {0, 4, 3, 0},
        0
    );

    return 0;
}