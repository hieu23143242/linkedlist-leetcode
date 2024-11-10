#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <stack>

using namespace std;

class ListNode {
public:
    int val;
    struct ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void insertAtHead(ListNode*& head, int val) {
    ListNode* node = new ListNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void insertAtTail(ListNode*& head, int val) {
    ListNode* node = new ListNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = node;
}

void insertAfterValue(ListNode*& head, int val, int target) {
    ListNode* node = new ListNode(val);
    if (head == nullptr) {
        head = node;
        return;
    }
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == target) {
            node->next = current->next;
            current->next = node;
            return ;
        }
        current = current->next;
    }
    if (current == nullptr) {
        insertAtTail(head, val);
    }
}

void removeAtHead(ListNode*& head) {
    if (head == nullptr) return ;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return ;
    }
    ListNode* newHead = head->next;
    delete head;
    head = newHead;
}

void removeAtTail(ListNode*& head) {
    if (head == nullptr) return ;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return ;
    }
    ListNode* prev = nullptr;;
    ListNode* current = head;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }
    delete current;
    prev->next = nullptr;
}

void removeAfterValue(ListNode*& head, int target) {
    if (head == nullptr) return ;
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == target && current->next != nullptr) {
            ListNode* delNode = current->next;
            current->next = delNode->next;
            delete delNode;
            return ;
        }
        current = current->next;
    }
}

void removeValue(ListNode*& head, int target) {
    if (head == nullptr) return ;
    if (head->val == target) {
        delete head;
        head = nullptr;
        return ;
    }
    ListNode* prev = nullptr;
    ListNode* current = head;
    while(current != nullptr) {
        if (current->val == target) {
            prev->next = current->next;
            delete current;
            return ;
        }
        prev = current;
        current = current->next;
    }
}

void print(ListNode* head) {
    if (head == nullptr) return ;
    ListNode* current = head;
    while (current != nullptr) {
        cout<<current->val<<" ";
        current = current->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    int carry = 0;
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        ListNode* node = new ListNode(sum % 10);
        current->next = node;
        carry = sum / 10;
        current = node;
    }
    return dummy->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    ListNode* early = head;
    for (int i=0; i<n; i++) {
        early = early->next;
    }
    ListNode* late = head;
    if (early == nullptr) {
        ListNode* newHead = head->next;
        delete head;
        head = newHead;
        return head;
    }
    while (early->next != nullptr) {
        late = late->next;
        early = early->next;
    }
    ListNode* delNode = late->next;
    late->next = delNode->next;
    delete delNode;
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 != nullptr) return list2;
    if (list1 != nullptr && list2 == nullptr) return list1;
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    ListNode* current1 = list1;
    ListNode* current2 = list2;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->val <= current2->val) {
            ListNode* node = new ListNode(current1->val);
            current->next = node;
            current = node;
            current1 = current1->next;
        } else {
            ListNode* node = new ListNode(current2->val);
            current->next = node;
            current = node;
            current2 = current2->next;
        }
    }
    while (current1 != nullptr) {
        ListNode* node = new ListNode(current1->val);
        current->next = node;
        current = node;
        current1 = current1->next;
    }
    while (current2 != nullptr) {
       ListNode* node = new ListNode(current2->val);
        current->next = node;
        current = node;
        current2 = current2->next;
    }
    return dummy->next;
}

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* current = dummy->next;
    while (current != nullptr && current->next != nullptr) {
        ListNode* p1 = current;
        ListNode* p2 = current->next;
        p1->next = p2->next;
        p2->next = p1;
        prev->next = p2;
        prev = p1;
        current = p1->next;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length ++;
        current = current->next;
    }
    k = k % length;
    if (k == 0) return head;
    ListNode* p1 = head;
    for (int i=0; i<k; i++) {
        p1 = p1->next;
    }
    ListNode* p2 = head;
    while (p1->next != nullptr) {
        p2 = p2->next;
        p1 = p1->next;
    }
    ListNode* newHead = p2->next;
    p2->next = nullptr;
    p1->next = head;
    return newHead;
}

ListNode* deleteDuplicates1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    ListNode* current = head;
    dummy->next = head;
    while (current != nullptr) {
        if (current->next != nullptr && current->val == current->next->val) {
            while (current->next != nullptr && current->val == current->next->val) {
                current = current->next;
            }
            if (current == nullptr) {
                prev->next = nullptr;
            } else {
                prev->next = current->next;
                current = current->next;
            }
        } else {
            prev->next = current;
            prev = prev->next;
            current = current->next;
        }
    }
    return dummy->next;
}

ListNode* deleteDuplicates2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* prev = head;
    ListNode* current = head->next;
    while (current != nullptr) {
        if (prev->val == current->val) {
            current = current->next;
        } else {
            prev->next = current;
            prev = prev->next;
            current = current->next;
        }
    }
    if (current == nullptr) {
        prev->next = nullptr;
    }
    return head;
}

ListNode* partition(ListNode* head, int x) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    vector<ListNode*> v1;
    vector<ListNode*> v2;
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val < x) {
            v1.push_back(current);
        } else {
            v2.push_back(current);
        }
        current = current->next;
    }
    current = dummy;
    for (ListNode* node: v1) {
        current->next = node;
        current = current->next;
    }
    for (ListNode* node: v2) {
        current->next = node;
        current = current->next;
    }
    current->next = nullptr;
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;
    unordered_set<ListNode*> s;
    ListNode* current = head;
    while (current != nullptr) {
        if (s.count(current)) return true;
        s.insert(current);
        current = current->next;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    unordered_set<ListNode*> s;
    ListNode* current = head;
    while (current != nullptr) {
        if (s.count(current)) {
            return current;
        }
        s.insert(current);
        current = current->next;
    }
    return nullptr;
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return ;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    stack<ListNode*> s;
    ListNode* current = slow->next;
    slow->next = nullptr;
    while (current != nullptr) {
        s.push(current);
        current = current->next;
    }
    current = head;
    while (!s.empty()) {
        ListNode* top = s.top();
        s.pop();
        top->next = current->next;
        current->next = top;
        current = top->next;
    }
}

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    while (head->val == val) {
        ListNode* newHead = head->next;
        delete head;
        head = newHead;
    }
    ListNode* prev = head;
    ListNode* current = head->next;
    while (current != nullptr) {
        if (current->val == val) {
            ListNode* next = current->next;
            prev->next = next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}

ListNode* reverseListII(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    stack<ListNode*> stk;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != nullptr) {
        stk.push(slow);
        slow = slow->next;
    }
    ListNode* current = head;
    while (!stk.empty()) {
        if (stk.top()->val != current->val) return false;
        current = current->next;
        stk.pop();
    }
    return true;
}

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

class Solution {
private:
    vector<int> v;
public:
    Solution(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }
    }

    int getRandom() {
        if (this->v.size() == 1) return this->v[0];
        return this->v[rand() % (this->v.size())];
    }
};

ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
    stack<int> stk;
    stack<int> stk1;
    stack<int> stk2;
    ListNode* dummy = new ListNode(0);
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 != nullptr) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
    }
    while (!stk1.empty() || !stk2.empty()) {
        int sum = carry;
        if (!stk1.empty()) {
            sum += stk1.top();
            stk1.pop();
        }
        if (!stk2.empty()) {
            sum += stk2.top();
            stk2.pop();
        }
        stk.push(sum%10);
        carry = sum/10;
    }
    if (carry != 0) stk.push(carry);
    ListNode* current = dummy;
    while (!stk.empty()) {
        current->next = new ListNode(stk.top());
        stk.pop();
        current = current->next;
    }
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

class MyCircularQueue {
private:
    ListNode* head;
    ListNode* tail;
    int maxLength;
    int currentLength;
public:
    MyCircularQueue(int k) {
        this->head = nullptr;
        this->tail = nullptr;
        this->maxLength = k;
        this->currentLength = 0;
    }
    bool enQueue(int value) {
        if (this->isFull()) return false;
        ListNode* node = new ListNode(value);
        if (this->isEmpty()) {
            this->head = node;
            this->tail = node;
            this->tail->next = this->head;
        } else {
            this->tail->next = node;
            node->next = this->tail->next;
            this->tail = node;
        }
        this->currentLength ++;
        return true;
    }
    bool deQueue() {
        if (this->isEmpty()) return false;
        if (this->currentLength == 1) {
            delete head;
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            ListNode* del = this->head;
            this->head = del->next;
            this->tail->next = this->head;
            delete del;
        }
        this->currentLength --;
        return true;
    }
    int Front() {
        if (this->isEmpty()) return -1;
        return this->head->val;
    }
    int Rear() {
        if (this->isEmpty()) return -1;
        return this->tail->val;
    }
    bool isEmpty() {
        return this->currentLength == 0;
    }
    bool isFull() {
        return this->currentLength == this->maxLength;
    }
};

class MyHashSet {
private:
    ListNode* head;
public:
    MyHashSet() {
        this->head = nullptr;
    }
    void add(int key) {
        if (this->head == nullptr) {
            this->head = new ListNode(key);
            return ;
        }
        ListNode* current = this->head;
        while (current->next != nullptr) {
            if (current->val == key) return;
            current = current->next;
        }
        if (current->val == key) return;
        current->next = new ListNode(key);
    }

    void remove(int key) {
        if (this->head == nullptr) return ;
        if (this->head->val == key) {
            ListNode* del = head;
            this->head = del->next;
            delete del;
            return;
        }
        ListNode* prev = nullptr;
        ListNode* current = this->head;
        while (current != nullptr) {
            if (current->val == key) {
                prev->next = current->next;
                delete current;
                return ;
            }
            prev = current;
            current = current->next;
        }
    }
    bool contains(int key) {
        if (this->head == nullptr) return false;
        ListNode* current = this->head;
        while (current != nullptr) {
            if (current->val == key) return true;
            current = current->next;
        }
        return false;
    }
};

class MyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int length;
public:
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    int get(int index) {
        if (index >= length) return -1;
        ListNode* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->val;
    }
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        if (head == nullptr) {
            head = node;
            tail = node;
            length ++;
            return ;
        }
        node->next = head;
        head = node;
        length ++;
    }
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (head == nullptr) {
            head = node;
            tail = node;
            length ++;
            return ;
        }
        tail->next = node;
        tail = node;
        length ++;
    }
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        ListNode* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNode* node = new ListNode(val);
        node->next = current->next;
        current->next = node;
        length++;
        if (node->next == nullptr) {
            tail = node;
        }
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {
            ListNode* del = head;
            head = del->next;
            delete del;
            if (head == nullptr) tail = nullptr;
            length --;
            return ;
        }
        ListNode* current = head;
        for (int i=0; i<index-1; i++) {
            current = current->next;
        }
        ListNode* del = current->next;
        current->next = del->next;
        delete del;
        length --;
        if (current->next == nullptr) {
            tail = current;
        }
    }
};

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    std::vector<ListNode*> ans(k, nullptr);
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        current = current->next;
        length ++;
    }
    int bunchSize = length / k;
    int ex = length < k ? 0 : length % k;
    current = head;
    for (int i=0; i<k; i++) {
        ListNode* _head = current;
        int currentBunchSize = bunchSize + (i<ex ? 1: 0)-1;
        for (int j=0; j<currentBunchSize; j++) {
            if (current != nullptr) current = current->next;
        }
        if (current != nullptr) {
            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }
        ans[i] = (_head);
    }
    return ans;
}

int numComponents(ListNode* head, vector<int>& nums) {
    int ans = 0;
    unordered_set<int> set;
    for (int num: nums) {
        set.insert(num);
    }
    ListNode* current = head;
    int connecting = false;
    while (current != nullptr) {
        if (set.find(current->val) != set.end()) {
            if (!connecting) {
                ans ++;
                connecting = true;
            }
        } else {
            connecting = false;
        }
        current = current->next;
    }
    return ans;
}

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s;
    for (int num: nums) {
        s.insert(num);
    }
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    while (head != nullptr) {
        if (s.find(head->val) == s.end()) {
            current->next = head;
            current = current->next;
        }
        head = head->next;
    }
    current->next = nullptr;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        ListNode* current = head;
        while (current != nullptr) {
            s.push(current->val);
            current = current->next;
        }
        current = head;
        int carry = 0;
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int newVal = top * 2 + carry;
            current->val = newVal % 10;
            carry = newVal / 10;
            if (current->next == nullptr && carry != 0) {
                current->next = new ListNode(carry);
                break;
            }

            current = current->next;
        }
        ListNode* newHead = nullptr;
        while (head != nullptr) {
            ListNode* current = head;
            head = head->next;
            current->next = newHead;
            newHead = current;
        }
        return newHead;
    }

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            int gcdVal = std::gcd(current->val, current->next->val);
            ListNode* node = new ListNode(gcdVal);
            node->next = current->next;
            current->next = node;
            current = node->next;
        }
        return head;
    }
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* currentResult = dummy;
    ListNode* current = head->next;
    int sum = 0;
    while (current != nullptr) {
        if (current->val == 0) {
            currentResult->next = new ListNode(sum);
            currentResult = currentResult->next;
            sum = 0;
        } else {
            sum += current->val;
        }
        current = current->next;
    }
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

int main() {
    int n;
    ListNode* head = nullptr;
    cin>>n;
    for (int i=0; i<n; i++) {
        int k;
        cin>>k;
        insertAtTail(head, k);
    }

    print(head);
    cout<<endl;
//    ListNode* cur = head;
//    for (int i=0; i<3; i++) {
//        cout<<cur->val<<" ";
//        cur = cur->next;
//    }
//    vector<ListNode*> res = splitListToParts(head, 3);

    return 0;
}
