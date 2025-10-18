// Intersection of two linked lists
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int length(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* a, Node* b) {
    int lenA = length(a);
    int lenB = length(b);

    Node* longer = lenA > lenB ? a : b;
    Node* shorter = lenA > lenB ? b : a;

    int diff = abs(lenA - lenB);
    while (diff-- > 0) {
        longer = longer->next;
    }

    while (longer != nullptr && shorter != nullptr) {
        if (longer == shorter) {
            return longer;
        }
        longer = longer->next;
        shorter = shorter->next;
    }
    return nullptr;
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(3);

    Node* b = new Node(4);
    b->next = a->next;

    Node* intersection = getIntersection(a, b);

    return 0;
}