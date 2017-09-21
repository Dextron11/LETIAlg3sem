//**********************************************************************************************************************
void arrInArrBit(char *A, int *bit) //Перевод из сроки в Массив битов
{
    int d=strlen(A);
    for (int i = 0; i < U; bit[i] = 0, ++i);
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < U - 1; ++j) {
            if (A[i] == Universum[j]) {
                bit[j] = 1;
                break;
            }
        }
    }
}

//**********************************************************************************************************************
int arrInComWord(char *B)//Перевод из строки в Машинное слово
{
    int wb = 0;
    int d=strlen(B);
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < U; j++)
            if (B[i] == Universum[j])
                wb += 1 << j;
    return (wb);
}

//**********************************************************************************************************************
void wayArrBit(char *A, char *B, char *C, char *D) {
    int bA[U], bB[U], bC[U], bD[U], bE[U];
    int i = 0, t1 = 0, t2 = 0;
    arrInArrBit(A, bA);
    arrInArrBit(B, bB);
    arrInArrBit(C, bC);
    arrInArrBit(D, bD);
    t1 = clock();
    while (i < numExe) {
        memset(bE, 0, U);
        for (int i = 0; i < U - 1; ++i) {
            bE[i] = bA[i] && !(bB[i]) && !(bC[i]) && !(bD[i]);
        }
        i++;
    }
    t2 = clock();
    outputCommonArrBit(bA, bB, bC, bD, bE);
    outputTime(t1, t2);
}

//**********************************************************************************************************************
void wayComWord(char *A, char *B, char *C, char *D) {
    int i = 0;
    long long t1 = 0, t2 = 0;
    int wA = 0, wB = 0, wC = 0, wD = 0, wE = 0;
    wA = arrInComWord(A);
    wB = arrInComWord(B);
    wC = arrInComWord(C);
    wD = arrInComWord(D);
    t1 = clock();
    while (i < numExe) {
        wE = 0;
        wE = wA & (~wC) & (~wB) & (~wD);
        i++;
    }
    t2 = clock();
    outputCommonComWorld(wA, wB, wC, wD, wE);
    outputTime(t1, t2);
}
