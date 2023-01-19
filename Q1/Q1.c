#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD, SUB, MUL, DIV, FIB, 
    NUM // used when node is a value, NOT an operator
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *op1;
    struct Node *op2;
} Node;

Node* makeFunc(TypeTag type) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->type = type;
    return node;
}

int calc(Node *node) {
    if (node == NULL) {
        return 0;
    } else if (node->type == ADD) {
        return calc(node->op1) + calc(node->op2);
    } else if (node->type == SUB) {
        return -calc(node->op1) + calc(node->op2);
    } else if (node->type == MUL) {
        return calc(node->op1) * calc(node->op2);
    } else if (node->type == DIV) {
        return calc(node->op1) / calc(node->op2);
    } else if (node->type == FIB) {
        if (node->op1 == NULL || node->op1->value == 0 || node->op1->value == 1) {
            return 0;
        } else if (node->op1->value == 2) {
            return 1;
        } else {
            int n = node->op1->value;
            Node *prev = makeFunc(FIB);
            prev->op1 = (Node *) malloc(sizeof(Node));
            prev->op1->value = n - 1;

            Node *prevPrev = makeFunc(FIB);
            prevPrev->op1 = (Node *) malloc(sizeof(Node));
            prevPrev->op1->value = n - 2;
            
            Node *dpAdd = makeFunc(ADD);
            dpAdd->op1 = prev;
            dpAdd->op2 = prevPrev;

            return calc(dpAdd);
        }
    } else {
        return node->value;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    Node *fibo = makeFunc(FIB);
    Node *op1 = makeFunc(NUM);
    op1->value = atoi(argv[1]);
    fibo->op1 = op1;
    printf("%i\n", calc(fibo));
    return calc(fibo);
}