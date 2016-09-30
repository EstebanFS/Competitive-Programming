class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root = NULL;
    ListNode* aux = NULL;
    int carry;
    while(l1 != NULL || l2 != NULL || carry) {
        int n1 = 0, n2 = 0;
        if(l1 != NULL) {
            n1 = l1 -> val;
            l1 = l1 -> next;
        }
        if(l2 != NULL) {
            n2 = l2 -> val;
            l2 = l2 -> next;
        }
        int sum = n1 + n2 + carry;
        carry = (sum >= 10) ? 1 : 0;
        sum %= 10;
        if(root == NULL) {
            root = new ListNode(sum);
            aux = root;
        } else {
            aux -> next = new ListNode(sum);
            aux = aux -> next;
        }
    }
    return root;
  }
}
