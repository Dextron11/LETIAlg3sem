
//**********************************************************************************************************************
void pop(Set *head)//Удаление  односвязного списка
{
    while (head) {
        Set *tmp = head;
        head = head->next;
        delete tmp;
    }
}

//**********************************************************************************************************************
Set *ArrInSet(Set *A2, char *A)//Запись строки в список
{
    int d=strlen(A);
    for (int i = 0; i <d; i++)
        A2 = new Set(A[i], A2);
    return (A2);
}

//**********************************************************************************************************************
bool checkSet(char A, Set *B)//Проверка на сущесвтвание данного элемента в списке
{
    if (B == nullptr)
        return (true);
    do {
        if (A == (B->el))
            return (false);
        B = B->next;
    } while (B != nullptr);
    return true;
}

//**********************************************************************************************************************
Set *creatSet(Set *A2, Set *B2, Set *C2, Set *D2,
              Set *E2)// создние списка по форуле A&(~B)&(~C)&(~D)
{
    for (Set *head = A2; head != nullptr; head = head->next) {
        if (checkSet(head->el, B2) && checkSet(head->el, C2) && checkSet(head->el, D2)) {
            E2 = new Set(head->el, E2);
        }
    }
    return (E2);
}

//**********************************************************************************************************************
void wayList(char *A, char *B, char *C, char *D) {
    int i = 0;
    long long  t1=0,t2=0;
    Set *A2 = nullptr, *B2 = nullptr, *C2 = nullptr, *D2 = nullptr,*E2= nullptr;
    A2 = ArrInSet(A2, A);
    B2 = ArrInSet(B2, B);
    C2 = ArrInSet(C2, C);
    D2 = ArrInSet(D2, D);
    t1 = clock();
    while (i < numExe) {
        pop(E2);
        E2 = nullptr;
        E2 = creatSet(A2, B2, C2, D2, E2);
        i++;
    }
    t2 = clock();
    outputCommonSet(A2, B2, C2, D2, E2);
    outputTime(t1, t2);
}
