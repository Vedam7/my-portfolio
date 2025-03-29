#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Call {
    string callerName;
    string phoneNumber;
};

queue<Call> callQueue;

void addCall(string name, string number) {
    Call newCall = {name, number};
    callQueue.push(newCall);
    cout << "Call added: " << name << " (" << number << ")\n";
}

void answerCall() {
    if (callQueue.empty()) {
        cout << "No calls in queue.\n";
        return;
    }
    Call currentCall = callQueue.front();
    callQueue.pop();
    cout << "Answering Call: " << currentCall.callerName << " (" << currentCall.phoneNumber << ")\n";
}

void showQueue() {
    if (callQueue.empty()) {
        cout << "No calls in queue.\n";
        return;
    }
    queue<Call> temp = callQueue;
    cout << "Call Queue:\n";
    while (!temp.empty()) {
        cout << temp.front().callerName << " (" << temp.front().phoneNumber << ")\n";
        temp.pop();
    }
}

int main() {
    int choice;
    string name, number;

    do {
        cout << "\nCall Management System\n";
        cout << "1. Add Call\n2. Answer Call\n3. Show Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Caller Name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, number);
                addCall(name, number);
                break;
            case 2:
                answerCall();
                break;
            case 3:
                showQueue();
                break;
        }
    } while (choice != 4);

    return 0;
}
