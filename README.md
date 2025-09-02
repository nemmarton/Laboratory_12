# Laboratory_12

Tasks:

->Memory handling error

->List handling tasks (print, delete, add, search etc)

# Memo: Linked Lists in C

---

## 1. What is a Linked List?

- A **linked list** is a dynamic data structure consisting of **nodes**.
- Each node contains:
  - **Data** (the stored value(s))
  - **Pointer to the next node**
- Unlike arrays:
  - Size is not fixed.
  - Memory is allocated dynamically.
  - Elements are not stored contiguously.

---

## 2. Defining a Node

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

- `data` → stores the element.
- `next` → pointer to the next node (or `NULL` if it’s the last node).

---

## 3. Creating a New Node

```c
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
```

---

## 4. Inserting Elements

### Insert at the Beginning
```c
void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
```

### Insert at the End
```c
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
```

---

## 5. Traversing the List

```c
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

---

## 6. Deleting Elements

### Delete First Node
```c
void deleteFirst(Node** head) { //Think over how head will change!!! There is also another way!
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
```

### Delete Entire List
```c
void deleteList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}
```

---

## 7. Advantages and Disadvantages

**Advantages:**
- Dynamic size (no fixed limit).
- Easy insertion/deletion without shifting elements.

**Disadvantages:**
- More memory (extra pointer per node).
- Slower access (no direct indexing, must traverse).

---

## 8. Use Cases

- Stacks, Queues, and other abstract data types.
- Situations where frequent insertions/deletions are required.
- When memory reallocation costs of arrays are undesirable.



