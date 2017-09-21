
//**********************************************************************************************************************
void inputScores(char *A)//Ввод множества в виде массива.

{
    char c;
    int i = 0;
    while ((c = getc(stdin)) != '\n' && i < U-1) {
        if (!checkArr(c, Universum) && checkArr(c, A) ) {
            A[i] = c;
            i++;
        }
    }
    A[i] = '\0';
}

//**********************************************************************************************************************
void genSet(char *A)// гненирация массива
{
    int j = 0;
    for (int i = 0; i < U; ++i)
        if (rand() % 3 > 1) {
            A[j] = Universum[i];
            j++;
        }
}
//**********************************************************************************************************************

void inputArr(char *A, char *B, char *C, char *D)//Меню  ввода данных
{
    memset(A, '\0', strlen(A));//подумуть
    memset(B, '\0', strlen(B));
    memset(C, '\0', strlen(C));
    memset(D, '\0', strlen(D));
    int point;
    std::cin >> point;
    getchar();
        switch (point) {
            case 1: {
                std::cout << "Введите А: ";
                inputScores(A);
                std::cout << "Введите B: ";
                inputScores(B);
                std::cout << "Введите C: ";
                inputScores(C);
                std::cout << "Введите D: ";
                inputScores(D);
                break;
            }

            case 2: {
                genSet(A);
                genSet(B);
                genSet(C);
                genSet(D);
                break;
            }

            case 0: {
                exit(0);
                break;
            }
            default :
                std::cout << "Ошибка!Введите пункт который есть в меню\n";
    }
}