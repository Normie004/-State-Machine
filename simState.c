#include <stdlib.h>
#include <stdio.h>

typedef struct StateNode {
    char varS;
    struct StateNode *s0; // 0
    struct StateNode *s1; // 1
    struct StateNode *curr; // current 
} StateNode;

int main(int argc, char *argv[]) {

    char inputs[3];
    int unreachable[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int gar = 0;
    int end = 0;
    int deleted[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    struct StateNode *head = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *A = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *B = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *C = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *D = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *E = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *F = (struct StateNode *)malloc(sizeof(struct StateNode));
    struct StateNode *H = (struct StateNode *)malloc(sizeof(struct StateNode));

    // pointer for current state so as to direct node
    struct StateNode *currentState = (struct StateNode *)malloc(sizeof(struct StateNode));

    // My personalized state machine

    head->varS = 'G';
    head->s0 = E;
    head->s1 = A;

    A->varS = 'A';
    A->s0 = F;
    A->s1 = C;

    B->varS = 'B';
    B->s0 = D;
    B->s1 = F;

    C->varS = 'C';
    C->s0 = head;
    C->s1 = B;

    D->varS = 'D';
    D->s0 = D;
    D->s1 = H;

    E->varS = 'E';
    E->s0 = A;
    E->s1 = D;

    F->varS = 'F';
    F->s0 = B;
    F->s1 = E;

    H->varS = 'H';
    H->s0 = C;
    H->s1 = head;

    // given starting state in personalized data
    currentState->curr = head;
    printf("Starting State: %c\n", currentState->curr->varS);

    // commands for input in Lab manual

    while (end == 0) {
        char temp;
        int num = 0;
        for (int i = 0; i < 3; i++) {
            inputs[i] = ' ';
        }

        scanf("%c", &temp);
        while (temp != '\n') {

            if (temp != ' ') {
                inputs[num] = temp;
                num++;
            }
            scanf("%c", &temp);
        }

        if (inputs[0] == 'e') {
            end = 1;
        } else if (inputs[0] == '0') {
            currentState->curr = currentState->curr->s0;
            printf("%c\n", currentState->curr->varS);
        } else if (inputs[0] == '1') {
            currentState->curr = currentState->curr->s1;
            printf("%c\n", currentState->curr->varS);
        } else if (inputs[0] == 'c') {
            if (inputs[1] == '0') {
                if (inputs[2] == 'A' && deleted[0] == 0)
                    currentState->curr->s0 = A;
                else if (inputs[2] == 'B' && deleted[1] == 0)
                    currentState->curr->s0 = B;
                else if (inputs[2] == 'C' && deleted[2] == 0)
                    currentState->curr->s0 = C;
                else if (inputs[2] == 'D' && deleted[3] == 0)
                    currentState->curr->s0 = D;
                else if (inputs[2] == 'E' && deleted[4] == 0)
                    currentState->curr->s0 = E;
                else if (inputs[2] == 'F' && deleted[5] == 0)
                    currentState->curr->s0 = F;
                else if (inputs[2] == 'G' && deleted[6] == 0)
                    currentState->curr->s0 = head;
                else if (inputs[2] == 'H' && deleted[7] == 0)
                    currentState->curr->s0 = H;
            } else if (inputs[1] = '1') {
                if (inputs[2] == 'A' && deleted[0] == 0)
                    currentState->curr->s1 = A;
                else if (inputs[2] == 'B' && deleted[1] == 0)
                    currentState->curr->s1 = B;
                else if (inputs[2] == 'C' && deleted[2] == 0)
                    currentState->curr->s1 = C;
                else if (inputs[2] == 'D' && deleted[3] == 0)
                    currentState->curr->s1 = D;
                else if (inputs[2] == 'E' && deleted[4] == 0)
                    currentState->curr->s1 = E;
                else if (inputs[2] == 'F' && deleted[5] == 0)
                    currentState->curr->s1 = F;
                else if (inputs[2] == 'G' && deleted[6] == 0)
                    currentState->curr->s1 = head;
                else if (inputs[2] == 'H' && deleted[7] == 0)
                    currentState->curr->s1 = H;
            }
        } else if (inputs[0] == 'p') {
            printf("%c %c %c\n", A->varS, A->s0->varS, A->s1->varS);
            printf("%c %c %c\n", B->varS, B->s0->varS, B->s1->varS);
            printf("%c %c %c\n", C->varS, C->s0->varS, C->s1->varS);
            printf("%c %c %c\n", D->varS, D->s0->varS, D->s1->varS);
            printf("%c %c %c\n", E->varS, E->s0->varS, E->s1->varS);
            printf("%c %c %c\n", F->varS, F->s0->varS, F->s1->varS);
            printf("%c %c %c\n", head->varS, head->s0->varS, head->s1->varS);
            printf("%c %c %c\n", H->varS, H->s0->varS, H->s1->varS);

        } else if (inputs[0] == 'g') {
            int reachable[8] = {0, 0, 0, 0, 0, 0, 0, 0};

            struct StateNode *collectNode = (struct StateNode *)malloc(sizeof(struct StateNode));

            int counter;
            int switchNum = 0;
            gar = 0;

            collectNode->curr = currentState->curr;
            for (counter = 0; counter < 200; counter++) {

                if (collectNode->curr->varS == 'A' || collectNode->curr->s0->varS == 'A' || collectNode->curr->s1->varS == 'A')
                    reachable[0]++;
                if (collectNode->curr->varS == 'B' || collectNode->curr->s0->varS == 'B' || collectNode->curr->s1->varS == 'B')
                    reachable[1]++;
                if (collectNode->curr->varS == 'C' || collectNode->curr->s0->varS == 'C' || collectNode->curr->s1->varS == 'C')
                    reachable[2]++;
                if (collectNode->curr->varS == 'D' || collectNode->curr->s0->varS == 'D' || collectNode->curr->s1->varS == 'D')
                    reachable[3]++;
                if (collectNode->curr->varS == 'E' || collectNode->curr->s0->varS == 'E' || collectNode->curr->s1->varS == 'E')
                    reachable[4]++;
                if (collectNode->curr->varS == 'F' || collectNode->curr->s0->varS == 'F' || collectNode->curr->s1->varS == 'F')
                    reachable[5]++;
                if (collectNode->curr->varS == 'G' || collectNode->curr->s0->varS == 'G' || collectNode->curr->s1->varS == 'G')
                    reachable[6]++;
                if (collectNode->curr->varS == 'H' || collectNode->curr->s0->varS == 'H' || collectNode->curr->s1->varS == 'H')
                    reachable[7]++;

                if (switchNum == 0)
                    collectNode->curr = collectNode->curr->s0;
                else if (switchNum == 1)
                    collectNode->curr = collectNode->curr->s1;

                if (counter == 100)
                    switchNum = 1;

            }

            for (int i = 0; i < 8; i++) {
                if (reachable[i] == 0) {
                    if (gar == 0) {
                        printf("Garbage:  %c", 'A' + i);
                        gar = 1;

                    } else
                        printf(", %c", 'A' + i);

                    unreachable[i] = 1;
                }
            }

            if (gar == 1)
                printf(" \n");
            else
                printf("No garbage \n");
        } else if (inputs[0] == 'd') {
            int tempfirst = 0;

            if (inputs[1] == ' ') {
                if (gar == 0)
                    printf("Nothing deleted.\n");
                else {
                    printf("Deleted: ");
                    for (int i = 0; i < 8; i++) {
                        if (unreachable[i] == 1) {
                            if (tempfirst == 0) {
                                printf("%c", 'A' + i);
                                tempfirst++;
                            } else
                                printf(", %c", 'A' + i);

                            deleted[i] = 1;
                            switch (i) {
                            case 0:
                                A->varS = ' ';
                                break;
                            case 1:
                                B->varS = ' ';
                                break;
                            case 2:
                                C->varS = ' ';
                                break;
                            case 3:
                                D->varS = ' ';
                                break;
                            case 4:
                                E->varS = ' ';
                                break;
                            case 5:
                                F->varS = ' ';
                                break;
                            case 6:
                                head->varS = ' ';
                                break;
                            case 7:
                                H->varS = ' ';
                                break;
                            }

                        }

                    }
                    printf(" \n");
                }
            }
            if (inputs[1] != ' ') {

                if (inputs[1] == 'A' && deleted[0] == 0) {
                    A->varS = ' ';
                    deleted[0] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'B' && deleted[1] == 0) {
                    B->varS = ' ';
                    deleted[1] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'C' && deleted[2] == 0) {
                    C->varS = ' ';
                    deleted[2] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'D' && deleted[3] == 0) {
                    D->varS = ' ';
                    deleted[3] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'E' && deleted[4] == 0) {
                    E->varS = ' ';
                    deleted[4] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'F' && deleted[5] == 0) {
                    F->varS = ' ';
                    deleted[5] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'G' && deleted[6] == 0) {
                    head->varS = ' ';
                    deleted[6] = 1;
                    printf("Deleted.\n");
                } else if (inputs[1] == 'H' && deleted[7] == 0) {
                    H->varS = ' ';
                    deleted[7] = 1;
                    printf("Deleted.\n");
                } else
                    printf("Not Deleted. \n");

            }

        }

    }
    exit(0);
}

