#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            max_profit += arr[result[i]].profit;
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\nMaximum Profit: " << max_profit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the Job ID: ";
        cin >> arr[i].id;
        cout << "Enter the Job Deadline: ";
        cin >> arr[i].deadline;
        cout << "Enter the Job Profit: ";
        cin >> arr[i].profit;
    }

    cout << "Following is maximum profit sequence of jobs:\n";
    printJobScheduling(arr, n);
    return 0;
}

    // Job arr[] = {{'a', 2, 100},
    //              {'b', 1, 19},
    //              {'c', 2, 27},
    //              {'d', 1, 25},
    //              {'e', 3, 15}};