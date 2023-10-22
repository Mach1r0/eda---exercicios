void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL) {
        return;
    }

    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}
