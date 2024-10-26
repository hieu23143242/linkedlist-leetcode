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
    if (head == nullptr) return ;
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


int main() {
    int n;
    ListNode* head = nullptr;
    cin>>n;
    for (int i=0; i<n; i++) {
        int k;
        cin>>k;
        insertAtTail(head, k);
    }
//    print(head);
    reorderList(head);

    return 0;
}
