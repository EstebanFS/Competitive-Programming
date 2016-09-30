class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root = NULL;
    ListNode* ans = root;
    int carry = 0;
    while(l1 -> next != NULL || l2 -> next != NULL) {
        int n1 = 0, n2 = 0;
        if(l1 != NULL) {
            n1 = l1 -> val;
            l1 = l1 -> next;
        }
        if(l2 != NULL) {
            n2 = l2 -> val;
            l2 = l2 -> next;
        }
        int sum = (n1 + n2) % 10, carry;
        if(n1 + n2 >= 10) carry++;
        if(root == NULL) *ans = ListNode(sum);
        else {
            *(ans -> next) = ListNode(sum + carry);
            if(sum + carry >= 10) carry = 1;
            else carry = 0;
            ans = ans -> next;
        }
    }
    return root;
  }
}
