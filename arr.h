//**********************************************************************************************************************
bool checkArr(char A, char *a) //Проверка на сущесвтвание данного элемента в массиве
{
    int d=strlen(a);
    for (int i=0;i<d;i++) {
        if (a[i] == A)
            return (false);
    }
    return true;
}
//**********************************************************************************************************************
void creatArr(char *A, char *B, char *C,char *D, char *E)// создние массива по форуле A&(~B)&(~C)&(~D)
{

    int j = 0;
    int d=strlen(A);
    for (int i = 0; i < d; i++) {
        if (checkArr(A[i], B) && checkArr(A[i], C) && checkArr(A[i], D)) {
            E[j] = A[i];
            j++;
        }
    }
    E[j] = '\0';


}
//**********************************************************************************************************************
void wayArr(char *A,char *B,char *C,char *D)
{
    char E[U]={"\0"};
    long long  t1=0,t2=0;
    int i=0;
    t1 = clock();
    while (i < numExe) {
        memset(E, '\0', U);
        creatArr(A, B, C, D,E);
        i++;
    }
    t2 = clock();
    outputCommonArr(A, B, C, D, E);
    outputTime(t1, t2);

}
