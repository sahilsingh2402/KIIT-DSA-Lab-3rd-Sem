#include <stdio.h>
#include <stdlib.h>

typedef struct Node_535
{
    int data_535;
    struct Node_535 *link_535;
} Node_535;

void menu_535();
void push_535(Node_535 **, int);
void display_535(Node_535 *);

void empty_the_list_535(Node_535 **);
int search_and_replace_beg_535(Node_535 **, int);
int middle_node_value_535(Node_535 *);
void reverse_first_m_nodes_535(Node_535 **, int);
int isSorted_535(Node_535 *);
void sorted_push_535(Node_535 **, int);
void make_unique_535(Node_535 *);

Node_535 *get_unique_list_535(Node_535 *);
Node_535 *make_intersection_535(Node_535 *, Node_535 *);

void even_first_535(Node_535 **);
void reverse_the_nodes_535(Node_535 **);
int isPalindrome_535(Node_535 *);
int isCyclic_535(Node_535 *);
void make_cycle_535(Node_535 **, int);
void rev_even_position_535(Node_535 *);
void swap_kth_pos_535(Node_535 **, int);
void rev_every_k_nodes_535(Node_535 **, int);
void rotate_cw_by_k_535(Node_535 **, int);

int main()
{
    Node_535 *list1_535 = NULL, *list2_535 = NULL, *list3_535 = NULL;
    int choice_535, pos_535, val_535;
    do
    {
        menu_535();
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("\nEnter an element: ");
            scanf("%d", &val_535);
            push_535(&list1_535, val_535);
            break;
        case 2:
            printf("\n");
            display_535(list1_535);
            break;
        case 3:
            printf("\nEnter an element: ");
            scanf("%d", &val_535);
            push_535(&list2_535, val_535);
            break;
        case 4:
            printf("\n");
            display_535(list2_535);
            break;
        case 5:
            printf("\nList cleared!\n");
            empty_the_list_535(&list1_535);
            empty_the_list_535(&list2_535);
            empty_the_list_535(&list3_535);
            break;
        case 6:
            printf("\nEnter the value at node to connect last node to: ");
            scanf("%d", &val_535);
            make_cycle_535(&list1_535, val_535);
            break;
        case 7:
            printf("\nEnter the number to search for: ");
            scanf("%d", &val_535);
            if (!search_and_replace_beg_535(&list1_535, val_535))
            {
                printf("Number not found!\n");
                break;
            }
            printf("Now the list is: ");
            display_535(list1_535);
            break;
        case 8:
            printf("\nMiddle node has: ");
            printf("%d\n", middle_node_value_535(list1_535));
            break;
        case 9:
            printf("\nEnter the number of elements: ");
            scanf("%d", &pos_535);
            reverse_first_m_nodes_535(&list1_535, pos_535);
            printf("Now the list is: ");
            display_535(list1_535);
            break;
        case 10:
            printf(isSorted_535(list1_535) ? "\nTrue\n" : "\nFalse\n");
            break;
        case 11:
            printf("\nEnter element to insert: ");
            scanf("%d", &val_535);
            sorted_push_535(&list1_535, val_535);
            printf("Now the list is: ");
            display_535(list1_535);
            break;
        case 12:
            list3_535 = make_intersection_535(list1_535, list2_535);
            display_535(list3_535);
            break;
        case 13:
            printf("\nModified list: ");
            even_first_535(&list1_535);
            display_535(list1_535);
            break;
        case 14:
            printf("\nThe list is palindrome: ");
            printf(isPalindrome_535(list1_535) ? "true\n" : "false\n");
            break;
        case 15:
            printf("\nCycle is present: ");
            printf((isCyclic_535(list1_535) ? "true\n" : "false\n"));
            break;
        case 16:
            rev_even_position_535(list1_535);
            printf("\nThe modified list: ");
            display_535(list1_535);
            break;
        case 17:
            printf("\nEnter position to swap: ");
            scanf("%d", &pos_535);
            swap_kth_pos_535(&list1_535, pos_535);
            printf("The modified list: ");
            display_535(list1_535);
            break;
        case 18:
            printf("\nInsert value of k: ");
            scanf("%d", &pos_535);
            rev_every_k_nodes_535(&list1_535, pos_535);
            printf("The modified list: ");
            display_535(list1_535);
            break;
        case 19:
            printf("\nEnter tha value of k: ");
            scanf("%d", &pos_535);
            rotate_cw_by_k_535(&list1_535, pos_535);
            printf("The modified list: ");
            display_535(list1_535);
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("---------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 19);
    return 0;
}
void menu_535()
{
    printf("Enter your choice: (all operations are on list 1, unless indicated otherwise)");
    printf("\n1) Create a new node \n2) Display the list \n");
    printf("3) Create a new node (list 2)\n4) Display the list (list 2)\n5) Drop all lists\n");
    printf("6) Create a cycle\n7) Search and move to begining\n8) Middle node\n");
    printf("9) Reverse first m elements\n10) The list is sorted\n11) Insert in sorted order\n");
    printf("12) Intersection of list 1 and 2\n13) Bring even elements at the begining\n");
    printf("14) Check if palindrome\n15) Check for cycles\n16) Even Position reverse\n");
    printf("17) Swap kth first and last node\n18) Reverse every k nodes\n");
    printf("19) Rotate the list in counter clockwise direction\n20) Exit\n->: ");
}
void push_535(Node_535 **start_535, int n)
{
    /*Making the new node*/
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = n;
    temp_535->link_535 = NULL;
    /*Connecting the new node*/
    if (!*start_535)
    {
        *start_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    //Travel to last node
    while (tempStart_535->link_535)
        tempStart_535 = tempStart_535->link_535;
    tempStart_535->link_535 = temp_535; //  Insert after last node
}
void display_535(Node_535 *start_535)
{
    if (isCyclic_535(start_535))
    {
        printf("List contains a cycle!\n");
        return;
    }
    while (start_535)
    {
        printf("%d->", start_535->data_535);
        start_535 = start_535->link_535;
    }
    printf("null\n");
}
void empty_the_list_535(Node_535 **start_535)
{
    while (*start_535)
    {
        Node_535 *ptr = *start_535;
        *start_535 = (*start_535)->link_535;
        free(ptr);
    }
}
int middle_node_value_535(Node_535 *start_535)
{
    if (!start_535)
        return -999;
    Node_535 *slowPtr = start_535;
    Node_535 *fastPtr = start_535;
    while (fastPtr && fastPtr->link_535)
    {
        fastPtr = fastPtr->link_535->link_535;
        slowPtr = slowPtr->link_535;
    }
    return slowPtr->data_535;
}
int search_and_replace_beg_535(Node_535 **start_535, int num_535)
{
    if (!*start_535)
        return 0;
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535->link_535 && tempStart_535->link_535->data_535 != num_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    if (!tempStart_535->link_535)
        return 0;
    Node_535 *ptr = tempStart_535->link_535;
    tempStart_535->link_535 = tempStart_535->link_535->link_535;
    ptr->link_535 = *start_535;
    *start_535 = ptr;
    return 1;
}
void reverse_first_m_nodes_535(Node_535 **start_535, int index)
{
    if (!*start_535)
        return;
    Node_535 *temp_535 = *start_535;              //current
    Node_535 *temp1_535 = (*start_535)->link_535; //next
    Node_535 *temp2_535;                          //previous
    while (temp1_535 && index - 1)
    {
        temp2_535 = temp1_535->link_535;
        temp1_535->link_535 = temp_535;
        temp_535 = temp1_535;
        temp1_535 = temp2_535;
        index--;
    }
    (*start_535)->link_535 = temp1_535;
    *start_535 = temp_535;
}
int isSorted_535(Node_535 *start_535)
{
    if (!start_535)
        return 1;
    while (start_535->link_535)
    {
        if (start_535->data_535 > start_535->link_535->data_535)
            return 0;
        start_535 = start_535->link_535;
    }
    return 1;
}
void sorted_push_535(Node_535 **start_535, int num_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = num_535;
    temp_535->link_535 = NULL;
    if (!*start_535)
    {
        *start_535 = temp_535;
        return;
    }
    else if ((*start_535)->data_535 > num_535)
    {
        temp_535->link_535 = *start_535;
        *start_535 = temp_535;
        return;
    }
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535->link_535 && tempStart_535->link_535->data_535 < num_535)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    temp_535->link_535 = tempStart_535->link_535;
    tempStart_535->link_535 = temp_535;
}
///////////////////////////////////////////////////////////////////////
void make_unique_535(Node_535 *start_535)
{
    while (start_535)
    {
        Node_535 *tempStart_535 = start_535;
        while (tempStart_535->link_535)
        {
            if (tempStart_535->link_535->data_535 == start_535->data_535)
            {
                Node_535 *ptr = tempStart_535->link_535;
                tempStart_535->link_535 = tempStart_535->link_535->link_535;
                free(ptr);
                continue;
            }
            tempStart_535 = tempStart_535->link_535;
        }
        if (start_535)
            start_535 = start_535->link_535;
    }
}
Node_535 *get_unique_list_535(Node_535 *start_535)
{
    Node_535 *list = NULL;
    while (start_535)
    {
        Node_535 *tempStart_535 = start_535;
        while (tempStart_535->link_535)
        {
            if (tempStart_535->link_535->data_535 == start_535->data_535)
            {
                push_535(&list, start_535->data_535);
            }
            tempStart_535 = tempStart_535->link_535;
        }
        if (start_535)
            start_535 = start_535->link_535;
    }
    make_unique_535(list);
    return list;
}
Node_535 *make_intersection_535(Node_535 *list1_535, Node_535 *list2_535)
{
    if (!list1_535 || !list2_535)
        return NULL;
    Node_535 *tempL1 = list1_535;
    while (tempL1->link_535)
    {
        tempL1 = tempL1->link_535;
    }
    tempL1->link_535 = list2_535;
    Node_535 *list3 = get_unique_list_535(list1_535);
    tempL1->link_535 = NULL;
    return list3;
}
///////////////////////////////////////////////////////////////////
void even_first_535(Node_535 **start_535)
{
    Node_535 *prev_535 = NULL;
    Node_535 *current_535 = *start_535;
    while (current_535)
    {
        if (current_535->data_535 % 2 == 0 && prev_535)
        {
            prev_535->link_535 = current_535->link_535;
            current_535->link_535 = *start_535;
            *start_535 = current_535;
            current_535 = prev_535;
        }
        prev_535 = current_535;
        current_535 = current_535->link_535;
    }
}
void reverse_the_nodes_535(Node_535 **start_535)
{
    if (!*start_535)
        return;
    Node_535 *temp_535 = *start_535;              //current
    Node_535 *temp1_535 = (*start_535)->link_535; //next
    Node_535 *temp2_535;                          //previous
    while (temp1_535 != NULL)
    {
        temp2_535 = temp1_535->link_535;
        temp1_535->link_535 = temp_535;
        temp_535 = temp1_535;
        temp1_535 = temp2_535;
    }
    (*start_535)->link_535 = NULL;
    *start_535 = temp_535;
}
int isPalindrome_535(Node_535 *start_535)
{
    if (!start_535)
        return 1;
    Node_535 *slowPtr = NULL;
    Node_535 *fastPtr = start_535;
    while (fastPtr && fastPtr->link_535)
    {
        //for first run slow ptr is updated as the head
        slowPtr = (!slowPtr) ? fastPtr : slowPtr->link_535;
        fastPtr = fastPtr->link_535->link_535;
    }
    Node_535 *firstTale = slowPtr;
    Node_535 *midnode = firstTale; //taking the tale of the first list as mid node
    if (!slowPtr)
        return 1;      //if the list contains only one element return true
    else if (!fastPtr) //if the list length is even
    {
        //Make the fast pointer point to the head of secoond list(even)
        fastPtr = slowPtr->link_535;
    }
    else if (!fastPtr->link_535) //if the list length is odd
    {
        //Make the fast pointer point to the head of the second list(odd)
        fastPtr = slowPtr->link_535->link_535;
        midnode = slowPtr->link_535; //the node after the tale node is the mid node
    }
    slowPtr->link_535 = NULL;        //Split the list in the middle
    reverse_the_nodes_535(&fastPtr); //reverse the second list
    Node_535 *midHead = fastPtr;
    int flag = 1;
    while (fastPtr) //compare the 2 lists until the head is null
    {
        if (start_535->data_535 != fastPtr->data_535)
        {
            flag = 0;
            break;
        }
        start_535 = start_535->link_535;
        fastPtr = fastPtr->link_535;
    }
    //reverse the second list again and append list 1 to list 2
    reverse_the_nodes_535(&midHead);
    firstTale->link_535 = midnode;
    midnode->link_535 = midHead;
    return flag;
}
int isCyclic_535(Node_535 *start_535)
{
    Node_535 *slowPtr = start_535;
    Node_535 *fastPtr = start_535;
    while ((fastPtr && fastPtr->link_535))
    {
        fastPtr = fastPtr->link_535->link_535;
        slowPtr = slowPtr->link_535;
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}
void make_cycle_535(Node_535 **start_535, int val_535)
{
    if (!*start_535)
        return;
    Node_535 *tale_535 = *start_535;
    Node_535 *cycle_head = NULL;
    if ((*start_535)->data_535 == val_535) //If first node is the only node
    {
        cycle_head = *start_535;
    }
    while (tale_535->link_535)
    {
        if (tale_535->data_535 == val_535)
            cycle_head = tale_535;
        tale_535 = tale_535->link_535;
    }
    tale_535->link_535 = cycle_head;
}
void rev_even_position_535(Node_535 *start_535)
{
    Node_535 *even_535 = NULL;
    Node_535 *odd_535 = start_535;
    Node_535 *temp = NULL;
    while (odd_535 && odd_535->link_535)
    {
        temp = odd_535->link_535;
        odd_535->link_535 = temp->link_535;
        temp->link_535 = even_535;
        even_535 = temp;
        odd_535 = odd_535->link_535;
    }
    odd_535 = start_535;
    while (odd_535 && odd_535->link_535)
    {
        temp = even_535;
        even_535 = even_535->link_535;
        temp->link_535 = odd_535->link_535;
        odd_535->link_535 = temp;
        odd_535 = temp->link_535;
    }
    if (odd_535)
        odd_535->link_535 = even_535;
}
void swap_kth_pos_535(Node_535 **start_535, int k)
{
    int length_535 = 0;
    Node_535 *tempStart_535 = *start_535;
    while (tempStart_535)
    {
        tempStart_535 = tempStart_535->link_535;
        length_535++;
    }
    if (k > length_535 || k <= 0)
        return;
    else if (k * 2 - 1 == length_535)
        return;
    tempStart_535 = *start_535;
    for (int i = 1; i < k - 1; i++)
    {
        tempStart_535 = tempStart_535->link_535;
    }
    Node_535 *tempEnd_535 = *start_535;
    for (int i = 1; i < length_535 - k; i++)
    {
        tempEnd_535 = tempEnd_535->link_535;
    }
    Node_535 *nowStart_535 = tempStart_535->link_535;
    Node_535 *nowEnd_535 = tempEnd_535->link_535;
    if (k == 1)
        nowStart_535 = tempStart_535;
    else
        tempStart_535->link_535 = nowEnd_535;
    tempEnd_535->link_535 = nowStart_535;
    Node_535 *temp_535 = nowStart_535->link_535; //Swap the links of the kth nodes
    nowStart_535->link_535 = nowEnd_535->link_535;
    nowEnd_535->link_535 = temp_535;
    if (k == 1)
        *start_535 = nowEnd_535;
    else if (k == length_535)
        *start_535 = nowStart_535;
}
void rev_every_k_nodes_535(Node_535 **start_535, int k)
{
    if (!*start_535 || k == 1)
        return;
    Node_535 *holder = (Node_535 *)malloc(sizeof(Node_535));
    holder->link_535 = *start_535; //Making a place holder node before head
    Node_535 *prev_535 = holder;
    Node_535 *current_535 = prev_535->link_535; //current is next to previous
    Node_535 *next_535 = current_535->link_535; //next is next to current
    while (next_535)
    {
        current_535 = prev_535->link_535;
        next_535 = current_535->link_535;
        for (int i = 1; i < k; i++)
        {
            if (!next_535)
                break;
            current_535->link_535 = next_535->link_535;
            next_535->link_535 = prev_535->link_535;
            prev_535->link_535 = next_535;
            next_535 = current_535->link_535;
        }
        prev_535 = current_535;
    }
    *start_535 = holder->link_535; //Update the head node
    free(holder);
}
void rotate_cw_by_k_535(Node_535 **start_535, int k)
{
    if (!*start_535)
        return;
    /*Goes to and splits the list upto where to rotate.*/
    Node_535 *tempStart_535 = *start_535;
    while (k - 1 && tempStart_535->link_535)
    {
        tempStart_535 = tempStart_535->link_535;
        k--;
    }
    Node_535 *secondaryHead_535 = tempStart_535->link_535;
    tempStart_535->link_535 = NULL;
    tempStart_535 = secondaryHead_535;
    if (!secondaryHead_535)
        return;
    /*Appends the first list to the second list*/
    while (secondaryHead_535->link_535)
    {
        secondaryHead_535 = secondaryHead_535->link_535;
    }
    secondaryHead_535->link_535 = *start_535;
    *start_535 = tempStart_535;
}

