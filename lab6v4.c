#include "header.h"
int askNY()
{
    printf("������ �, �᫨ �롨ࠥ� ��ਠ�� ��\n");
    printf("���� ������ �, �᫨ �롨ࠥ� ��ਠ�� ���\n");
    while (true)
    {
        char c = getch();
        if (c == '�' || c == '�' || c == 'Y' || c == 'y' || c == '1')
            return 1;
        if (c == '�' || c == '�' || c == 'N' || c == 'n' || c == '0')
            return 0;
        printf("������ ᨬ���\n");
    }
}
typedef struct stroom
{
    int number, floor, peoples, cost, empty;
    char class[255];
} stroom;
typedef struct stguests
{
    char FIO[255], passport[255], phone[255], inDate[255], outDate[255];
    int roomNumber, posRoom;
} stguests;

typedef struct sthotel
{
    char name[255];
    int floors;
    stroom room[1000];
    stguests guests[1000];
    int roomCount, guestsCount, emptyCount;
} sthotel;
void clearConsoleLine()
{
    int i;
    printf("\r");
    for (i = 0; i < 200; i++)
        printf(" ");
    printf("\r");
}
void addRooms(sthotel *hotel)
{
    int first = true, i = hotel->roomCount, flag = false;
    printf("������ ������� � �ଠ�:\n"
           "�����,�⠦,�����,�⮨�����,������⢮ ��\n");

    while (true)
    {
        int temp, error = 0, k = 0;
        char tempS[1000];
        i = hotel->roomCount;
        if (flag)
        {
            if (!first)
                printf("\n��।���஢��� �������?\n");
        }
        else
        {
            if (!first)
                printf("\n�������� ����� �������?\n");
            strcpy(hotel->room[i].class, "");
            hotel->room[i].cost = 0;
            hotel->room[i].floor = 0;
            hotel->room[i].number = 0;
            hotel->room[i].peoples = 0;
            hotel->room[i].empty = 0;
        }
        if (first || askNY())
        {
            int p = -1;
            first = false;            
            if (!flag)
                k = 5;

            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ᮧ����� �������)\n");
            while (k || flag)
            {
                p = (p + 1) % 5;
                clearConsoleLine();
                if (p == 0)
                {
                    int j;
                    char c;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ᮧ����� �������?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ����� �������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    for (j = 0; j < hotel->roomCount; j++)
                        if (temp == hotel->room[j].number)
                            temp = err;
                    if (temp == err || temp <= 0 || temp >= 10000)
                    {
                        p--;
                        printf("�����室�騩 ����� �������\n");
                        continue;
                    }
                    if (hotel->room[i].number != 0)
                    {
                        printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                        if (askNY())
                        {
                            hotel->room[i].number = temp;
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        k--;
                        hotel->room[i].number = temp;
                    }
                }
                if (p == 1)
                {
                    char c;
                    printf("�⠦ �������         <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ᮧ����� �������?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ �� ����� �⠦� ��室���� ������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0 || temp > hotel->floors)
                    {
                        p--;
                        printf("�����室�騩 �⠦ �������\n");
                        continue;
                    }
                    if (hotel->room[i].floor != 0)
                    {
                        printf("\n�� 㢥७� �� ��� �������� �⠦ �������?\n");
                        if (askNY())
                        {
                            hotel->room[i].floor = temp;
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        k--;
                        hotel->room[i].floor = temp;
                    }
                }
                if (p == 2)
                {
                    char c;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ᮧ����� �������?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ����� �������(� �ਬ��� ����� �����, ������, ���,��஫��᪨� �����): ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->room[i].class[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                        if (askNY())
                        {
                            strcpy(hotel->room[i].class, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->room[i].class, tempS);
                    }
                    else
                        p--;
                }
                if (p == 3)
                {
                    char c;
                    printf("������⢮ ��     <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ᮧ����� �������?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ������⢮ �� �� ���஥ ����⠭� ������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0 || temp >= 100)
                    {
                        p--;
                        printf("�����室�饥 ������⢮ ��\n");
                        continue;
                    }
                    if (hotel->room[i].peoples != 0)
                    {
                        printf("\n�� 㢥७� �� ��� �������� ������⢮ ��?\n");
                        if (askNY())
                        {
                            flag = false;
                            hotel->room[i].peoples = temp;
                            hotel->room[i].empty = temp;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        k--;
                        hotel->room[i].peoples = temp;
                        hotel->room[i].empty = temp;
                    }
                }
                if (p == 4)
                {
                    char c;
                    printf("�⮨����� �������    <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ᮧ����� �������?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ �⮨����� ��⮪ �஦������ � ������ � �.�.: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0)
                    {
                        p--;
                        printf("�����室��� �⮨�����\n");
                        continue;
                    }
                    if (hotel->room[i].cost != 0)
                    {
                        printf("\n�� 㢥७� �� ��� �������� �⮨����� �������?\n");
                        if (askNY())
                        {
                            flag = false;
                            hotel->room[i].cost = temp;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        k--;
                        hotel->room[i].cost = temp;
                    }
                }
            }
            if (error)
                continue;
            printf("\n�� 㢥७� �� ��� �������� �� %d �⠦ ������� ����� %d\n"
                   "����� '%s' �⮨������ %d �.�. ����⠭��� �� %d 祫����?\n",
                   hotel->room[i].floor, hotel->room[i].number, hotel->room[i].class, hotel->room[i].cost, hotel->room[i].peoples);
            if (askNY())
            {
                hotel->roomCount++;
                hotel->emptyCount += hotel->room[i].peoples;
                printf("������ �ᯥ譮 ��������� � ���⨭���\n");
            }
            else
            {
                printf("� ��� �� ��砥���\n");
                flag = true;
            }
        }
        else
            break;
    }    
}
void clearHotel(sthotel *hotel)
{
    int i;
    strcpy(hotel->name, "");
    hotel->floors = 0;
    hotel->roomCount = 0;
    hotel->guestsCount = 0;
    hotel->emptyCount = 0;
    for (i = 0; i < 1000; i++)
    {
        strcpy(hotel->room[i].class, "");
        hotel->room[i].cost = 0;
        hotel->room[i].floor = 0;
        hotel->room[i].number = 0;
        hotel->room[i].peoples = 0;
        hotel->room[i].empty = 0;
        strcpy(hotel->guests[i].FIO, "");
        strcpy(hotel->guests[i].passport, "");
        strcpy(hotel->guests[i].phone, "");
        strcpy(hotel->guests[i].inDate, "");
        strcpy(hotel->guests[i].outDate, "");
        hotel->guests[i].roomNumber = 0;
        hotel->guests[i].posRoom = 0;
    }
}
void Save(sthotel *hotel, int *saved)
{
    int i;
    FILE *fp1;
    FILE *fp2;
    if (!(*saved))
    {
        char c;
        FILE *fp2 = fopen("guests.txt", "r");
        FILE *fp2c = fopen("backupGuests.txt", "w");
        FILE *fp1 = fopen("hotel.txt", "r");
        FILE *fp1c = fopen("backupHotel.txt", "w");

        c = fgetc(fp1);
        while (!feof(fp1))
        {
            putc(c, fp1c);
            c = fgetc(fp1);
        }
        c = fgetc(fp2);
        while (!feof(fp2))
        {
            putc(c, fp2c);
            c = fgetc(fp2);
        }
        fclose(fp1);
        fclose(fp1c);
        fclose(fp2);
        fclose(fp2c);
        *saved = true;
    }
    fp1 = fopen("hotel.txt", "w");
    fprintf(fp1, "%s\n%d\n%d\n", hotel->name, hotel->floors, hotel->roomCount);
    for (i = 0; i < hotel->roomCount; i++)
        fprintf(fp1, "%s\n%d %d %d %d %d\n", hotel->room[i].class, hotel->room[i].cost, hotel->room[i].floor, hotel->room[i].number, hotel->room[i].peoples, hotel->room[i].empty);
    fp2 = fopen("guests.txt", "w");
    fprintf(fp2, "%d\n", hotel->guestsCount);
    for (i = 0; i < hotel->guestsCount; i++)
        fprintf(fp2, "%s\n%s\n%s\n%s\n%d\n%s\n%d\n",
                hotel->guests[i].FIO, hotel->guests[i].passport, hotel->guests[i].phone, hotel->guests[i].inDate, hotel->guests[i].roomNumber, hotel->guests[i].outDate, hotel->guests[i].posRoom);
    fclose(fp1);
    fclose(fp2);
}
void delLast(char *str)
{
    int i = 0;
    while (str[i] != '\n')
        i++;
    str[i] = '\0';
}
void LoadHotel(sthotel *hotel, FILE *fp1)
{
    int i;
    hotel->emptyCount = 0;
    fgets(hotel->name, 254, fp1);
    delLast(hotel->name);
    fscanf(fp1, "%d %d\n", &hotel->floors, &hotel->roomCount);
    for (i = 0; i < hotel->roomCount; i++)
    {
        fgets(hotel->room[i].class, 254, fp1);
        delLast(hotel->room[i].class);
        fscanf(fp1, "%d %d %d %d %d\n", &hotel->room[i].cost, &hotel->room[i].floor, &hotel->room[i].number, &hotel->room[i].peoples, &hotel->room[i].empty);
        hotel->emptyCount += hotel->room[i].peoples;
    }
    fclose(fp1);
}
void LoadGuests(sthotel *hotel, FILE *fp2)
{
    int i;
    fscanf(fp2, "%d\n", &hotel->guestsCount);
    for (i = 0; i < hotel->guestsCount; i++)
    {
        fgets(hotel->guests[i].FIO, 254, fp2);
        delLast(hotel->guests[i].FIO);
        fgets(hotel->guests[i].passport, 254, fp2);
        delLast(hotel->guests[i].passport);
        fgets(hotel->guests[i].phone, 254, fp2);
        delLast(hotel->guests[i].phone);
        fgets(hotel->guests[i].inDate, 254, fp2);
        delLast(hotel->guests[i].inDate);
        fscanf(fp2, "%d\n", &hotel->guests[i].roomNumber);
        fgets(hotel->guests[i].outDate, 254, fp2);
        delLast(hotel->guests[i].outDate);
        fscanf(fp2, "%d\n", &hotel->guests[i].posRoom);
        hotel->emptyCount--;
    }
}
void addGuest(sthotel *hotel)
{
    int first = true, flag = false;
    if (hotel->emptyCount == 0)
    {
        printf("�� ������� ������\n");
        return;
    }
    printf("������ ���⥩ � �ଠ�:\n"
           "���,��ᯮ��,⥫�䮭,��� ��ᥫ����,��� ��ᥫ����,����� �������\n");

    while (true)
    {
        int i = hotel->guestsCount, temp, error = 0, k = 0;
        char tempS[1000];
        if (flag)
        {
            if (!first)
                printf("\n��।���஢��� ����� � ����?\n");
        }
        else
        {
            if (!first)
                printf("\n�������� ������ �����?\n");
            strcpy(hotel->guests[i].FIO, "");
            strcpy(hotel->guests[i].passport, "");
            strcpy(hotel->guests[i].phone, "");
            strcpy(hotel->guests[i].inDate, "");
            strcpy(hotel->guests[i].outDate, "");
            hotel->guests[i].roomNumber = 0;
        }
        if (first || askNY())
        {
            int p = -1;
            first = false;            
            if (!flag)
                k = 6;

            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ��ᥫ���� �����)\n");
            while (k || flag)
            {
                p = (p + 1) % 6;
                clearConsoleLine();
                if (p == 0)
                {
                    char c;
                    printf("���                  <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ������� ��� ����⢮ �१ �஡��: ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->guests[i].FIO[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ���?\n");
                        if (askNY())
                        {
                            strcpy(hotel->guests[i].FIO, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->guests[i].FIO, tempS);
                    }
                    else
                        p--;
                }
                else if (p == 1)
                {
                    char c;
                    printf("��ᯮ��              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ �਩�� ����� ��ᯮ��: ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->guests[i].passport[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ��ᯮ��?\n");
                        if (askNY())
                        {
                            strcpy(hotel->guests[i].passport, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->guests[i].passport, tempS);
                    }
                    else
                        p--;
                }
                else if (p == 2)
                {
                    char c;
                    printf("����䮭              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ����� ⥫�䮭� ������: ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->guests[i].phone[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ����� ⥫�䮭�?\n");
                        if (askNY())
                        {
                            strcpy(hotel->guests[i].phone, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->guests[i].phone, tempS);
                    }
                    else
                        p--;
                }
                else if (p == 3)
                {
                    char c;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ����: ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->guests[i].inDate[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ���� ��ᥫ����?\n");
                        if (askNY())
                        {
                            strcpy(hotel->guests[i].inDate, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->guests[i].inDate, tempS);
                    }
                    else
                        p--;
                }
                else if (p == 4)
                {
                    char c;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ����: ");
                    fflush(stdin);
                    gets(tempS);
                    if (hotel->guests[i].outDate[0] != '\0')
                    {
                        printf("\n�� 㢥७� �� ��� �������� ���� ��ᥫ����?\n");
                        if (askNY())
                        {
                            strcpy(hotel->guests[i].outDate, tempS);
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else if (tempS[0] != '\0')
                    {
                        k--;
                        strcpy(hotel->guests[i].outDate, tempS);
                    }
                    else
                        p--;
                }
                else if (p == 5)
                {
                    char c;
                    int j,f;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    f = false;
                    printf("�������� �����: ");
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].empty != 0)
                        {
                            if (f)
                                printf(", ");
                            else
                                f = true;
                            printf("%d(%d/%d)", hotel->room[j].number, hotel->room[j].peoples - hotel->room[j].empty, hotel->room[j].peoples);
                        }

                    printf("\n������ ����� �������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    f = true;
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].number == temp && hotel->room[j].empty != 0)
                        {
                            f = false;
                            break;
                        }
                    if (f)
                    {
                        p--;
                        printf("�����室�騩 ����� �������\n");
                        continue;
                    }
                    if (hotel->guests[i].roomNumber != 0)
                    {
                        printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                        if (askNY())
                        {
                            hotel->room[hotel->guests[i].posRoom].empty++;
                            hotel->guests[i].posRoom = j;
                            hotel->guests[i].roomNumber = temp;
                            hotel->room[j].empty--;
                            flag = false;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        k--;
                        hotel->guests[i].posRoom = j;
                        hotel->guests[i].roomNumber = temp;
                        hotel->room[j].empty--;
                    }
                }
            }
            if (error)
                continue;
            printf("\n�� 㢥७� �� ��� ��ᥫ��� %s � ��ᯮ��� ����஬ %s � ⥫�䮭�� ����஬ %s\n"
                   "� ������� %d �� �஬���⮪ �६��� %s - %s?\n",
                   hotel->guests[i].FIO, hotel->guests[i].passport, hotel->guests[i].phone, hotel->guests[i].roomNumber, hotel->guests[i].inDate, hotel->guests[i].outDate);
            if (askNY())
            {
                hotel->guestsCount++;
                hotel->emptyCount--;
                printf("����� �ᯥ譮 ��ᥫ� � ���⨭���\n");
            }
            else
            {
                printf("�� � �����\n");
                flag = true;
            }
        }
        else
            break;
    }
}
void init(sthotel *hotel)
{
    char tempS[10000];

    printf("������ �������� ���⨭���: ");
    scanf("%s", hotel->name);
    while (true)
    {
        printf("������ ������⢮ �⠦�� � ��襩 ���⨭��: ");
        scanf("%s", tempS);
        hotel->floors = stod(tempS);
        if (hotel->floors == err || hotel->floors <= 0 || hotel->floors >= 1000)
            printf("�����室�饥 ������⢮ �⠦��\n");
        else
            break;
    }
    addRooms(hotel);
    addGuest(hotel);
    printf("�㯥� �⫨筮, ��� ������������ %d �⠦��� ���⨭�� %s\n"
           "�ᯥ譮 ���樠����஢��� � %d �����⠬� � %d ����ﬨ\n",
           hotel->floors, hotel->name, hotel->roomCount, hotel->guestsCount);
}
int myComp(char *str1, int d1, char *str2)
{
    int i = 0, j = 0, d2, mnk, k;
    char *tempS;
    int temp;
    while (true)
    {
        if (str2[j] == '\0')
            break;
        j++;
    }
    d2 = j;
    if (d1 > d2)
    {
        tempS = str1;
        str1 = str2;
        str2 = tempS;
        temp = d1;
        d1 = d2;
        d2 = temp;
    }

    mnk = 1001;
    for (i = 0; i <= d2 - d1; i++)
    {
        k = 0;
        for (j = 0; j < d1; j++)
        {
            char c1 = str1[j], c2;
            if (c1 >= 'A' && c1 <= 'Z')
                c1 = c1 - 'A' + 'a';
            if (c1 >= '�' && c1 <= '�')
                c1 = c1 - '�' + '�';
            c2 = str2[j + i];
            if (c2 >= 'A' && c2 <= 'Z')
                c2 = c2 - 'A' + 'a';
            if (c2 >= '�' && c2 <= '�')
                c2 = c2 - '�' + '�';
            if (c1 != c2)
                k++;
        }
        if (k < mnk)
            mnk = k;
    }
    return mnk + (d2 - d1) / 2;
}
void delGuest(sthotel *hotel)
{
    int first = true, flag, p = -1;
    printf("�롥�� ���� �� ���஬� ����� ����� ��� ��ᥫ����:\n");

    while (true)
    {
        int temp, error = 0;
        char tempS[1000];
        if (!first)
            printf("\n��ᥫ��� ��� ������ �����?\n");

        if (first || askNY())
        {
            int minp = 0;
            first = false;
            if (!first)
                p = -1;
            flag = true;

            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ��ᥫ���� �����)\n");
            while (flag)
            {
                int j;
                p = (p + 1) % 5;
                clearConsoleLine();
                if (p == 0)
                {
                    char c;
                    int min, d;
                    printf("���                  <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ������� ��� ����⢮ �१ �஡��: ");
                    fflush(stdin);
                    gets(tempS);
                    min = 1001;
                    d = 0;
                    minp = 0;
                    while (true)
                    {
                        if (tempS[d] == '\0')
                            break;
                        d++;
                    }
                    for (j = 0; j < hotel->guestsCount; j++)
                    {
                        temp = myComp(tempS, d, hotel->guests[j].FIO);
                        if (temp < min)
                        {
                            min = temp;
                            minp = j;
                        }
                    }
                    if (min > d / 3)
                    {
                        p--;
                        printf("����� �� ������\n");
                        continue;
                    }
                    flag = false;
                }
                else if (p == 1)
                {
                    char c;
                    int min, d;
                    printf("��ᯮ��              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ �਩�� ����� ��ᯮ��: ");
                    fflush(stdin);
                    gets(tempS);
                    min = 1001;
                    d = 0;
                    minp = 0;
                    while (true)
                    {
                        if (tempS[d] == '\0')
                            break;
                        d++;
                    }
                    for (j = 0; j < hotel->guestsCount; j++)
                    {
                        temp = myComp(tempS, d, hotel->guests[j].passport);
                        if (temp < min)
                        {
                            min = temp;
                            minp = j;
                        }
                    }
                    if (min > d / 3)
                    {
                        p--;
                        printf("����� �� ������\n");
                        continue;
                    }
                    flag = false;
                }
                else if (p == 2)
                {
                    char c;
                    int min, d;
                    printf("����䮭              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ⥫�䮭 �����: ");
                    fflush(stdin);
                    gets(tempS);
                    min = 1001;
                    d = 0;
                    minp = 0;
                    while (true)
                    {
                        if (tempS[d] == '\0')
                            break;
                        d++;
                    }
                    for (j = 0; j < hotel->guestsCount; j++)
                    {
                        temp = myComp(tempS, d, hotel->guests[j].phone);
                        if (temp < min)
                        {
                            min = temp;
                            minp = j;
                        }
                    }
                    if (min > d / 3)
                    {
                        p--;
                        printf("����� �� ������\n");
                        continue;
                    }
                    flag = false;
                }
                else if (p == 3)
                {
                    char c;
                    int min, d;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ���� �����: ");
                    fflush(stdin);
                    gets(tempS);
                    min = 1001;
                    d = 0;
                    minp = 0;
                    while (true)
                    {
                        if (tempS[d] == '\0')
                            break;
                        d++;
                    }
                    for (j = 0; j < hotel->guestsCount; j++)
                    {
                        temp = myComp(tempS, d, hotel->guests[j].inDate);
                        if (temp < min)
                        {
                            min = temp;
                            minp = j;
                        }
                    }
                    if (min > d / 3)
                    {
                        p--;
                        printf("����� �� ������\n");
                        continue;
                    }
                    flag = false;
                }
                else if (p == 4)
                {
                    char c;
                    int min, d;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {
                            error = err;
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ���� �����: ");
                    fflush(stdin);
                    gets(tempS);
                    min = 1001;
                    d = 0;
                    minp = 0;
                    while (true)
                    {
                        if (tempS[d] == '\0')
                            break;
                        d++;
                    }
                    for (j = 0; j < hotel->guestsCount; j++)
                    {
                        temp = myComp(tempS, d, hotel->guests[j].outDate);
                        if (temp < min)
                        {
                            min = temp;
                            minp = j;
                        }
                    }
                    if (min > d / 3)
                    {
                        p--;
                        printf("����� �� ������\n");
                        continue;
                    }
                    flag = false;
                }
            }
            if (error)
                continue;
            printf("\n�� 㢥७� �� ��� ��ᥫ��� %s � ��ᯮ��� ����஬ %s � ⥫�䮭�� ����஬ %s\n"
                   "�� ������� %d �஦����饣� � ���⨭�� � %s �� %s?\n",
                   hotel->guests[minp].FIO, hotel->guests[minp].passport, hotel->guests[minp].phone, hotel->guests[minp].roomNumber, hotel->guests[minp].inDate, hotel->guests[minp].outDate);
            if (askNY())
            {
                int i = minp,j;
                stguests temp;
                hotel->emptyCount++;
                hotel->room[hotel->guests[i].posRoom].empty++;
                strcpy(hotel->guests[i].FIO, "");
                strcpy(hotel->guests[i].passport, "");
                strcpy(hotel->guests[i].phone, "");
                strcpy(hotel->guests[i].inDate, "");
                strcpy(hotel->guests[i].outDate, "");
                hotel->guests[i].roomNumber = 0;
                hotel->guests[i].posRoom = 0;                                
                for (j = 0; j < hotel->guestsCount; j++)
                    if (hotel->guests[j].roomNumber == 0)
                    {
                        temp = hotel->guests[j];
                        hotel->guests[j] = hotel->guests[j + 1];
                        hotel->guests[j + 1] = temp;
                    }

                hotel->guestsCount--;
            }
            else
            {
                printf("����\n");
                first = true;
                p--;
            }
        }
        else
            break;
    }
}
void editRooms(sthotel *hotel, int i)
{
    int first = true;
    printf("�롥�� ���� �� ����� ��� ���������:\n"
           "�����,�⠦,�����,�⮨�����,������⢮ ��\n");    
    while (true)
    {
        int temp, flag = true;
        char tempS[1000];
        if (!first)
            printf("\n��।���஢��� ��� ������� ����� %d?\n", hotel->room[i].number);
        if (first || askNY())
        {
            int p = -1;
            first = false;            

            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ।���஢���� �������)\n");
            while (flag)
            {
                p = (p + 1) % 5;
                clearConsoleLine();
                if (p == 0)
                {
                    char c;
                    int j;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �������?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ���� ����� �������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);                    
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].number == temp)
                        {
                            temp = err;
                            break;
                        }
                    if (temp == err || temp <= 0 || temp >= 10000)
                    {
                        p--;
                        printf("�����室�騩 ����� �������\n");
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                    if (askNY())
                    {
                        int j;
                        for (j = 0; j < hotel->guestsCount; j++)
                            if (hotel->guests[j].roomNumber == hotel->room[i].number)
                                hotel->guests[j].roomNumber = temp;
                        hotel->room[i].number = temp;
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 1)
                {
                    char c;
                    printf("�⠦ �������         <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �������?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ���� �⠦ �������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0 || temp > hotel->floors)
                    {
                        p--;
                        printf("�����室�騩 �⠦ �������\n");
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� �⠦ �������?\n");
                    if (askNY())
                    {
                        hotel->room[i].floor = temp;
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 2)
                {
                    char c;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �������?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ���� ����� �������(� �ਬ��� ����� �����, ������, ���,��஫��᪨� �����): ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                    if (askNY())
                    {
                        strcpy(hotel->room[i].class, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 3)
                {
                    char c;
                    printf("������⢮ ��     <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �������?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ����� ������⢮ �� �� ���஥ ����⠭� ������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0 || hotel->room[i].peoples - hotel->room[i].empty > temp || temp >= 100)
                    {
                        p--;
                        printf("�����室�饥 ������⢮ ��\n");
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ������⢮ ��?\n");
                    if (askNY())
                    {
                        hotel->emptyCount += temp - hotel->room[i].peoples;
                        hotel->room[i].empty += temp - hotel->room[i].peoples;
                        hotel->room[i].peoples = temp;
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 4)
                {
                    char c;
                    printf("�⮨����� �������    <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �������?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ �⮨����� ��⮪ �஦������ � ������ � �.�.: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    if (temp == err || temp <= 0)
                    {
                        p--;
                        printf("�����室��� �⮨�����\n");
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� �⮨����� �������?\n");
                    if (askNY())
                    {
                        hotel->room[i].cost = temp;
                        flag = false;
                    }
                    else
                        continue;
                }
            }
        }
        else
            break;
    }
}
int findGuest(sthotel *hotel)
{
    int flag, p = -1, first = true;
    printf("�롥�� ���� �� ���஬� ����� ����� ��� ���������:\n");
    
    while (true)
    {
        int temp, error = 0, minp = 0;
        char tempS[1000];
        flag = true;
        if (!first)
        {
            printf("���஡����� ��� ࠧ ���� ����� ��� ���������?");
            if (!askNY())
                return err;
        }
        printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ���� �����)\n");
        while (flag)
        {
            int j;
            first = false;            
            p = (p + 1) % 5;            
            clearConsoleLine();
            if (p == 0)
            {
                char c;
                int min,d;
                printf("���                      <-");
                c = getch();
                if (c == 9)
                    continue;
                clearConsoleLine();
                if (c == 27)
                {
                    printf("\n�� 㢥७� �� ��� ��ࢠ�� ���� �����?\n");
                    if (askNY())
                    {
                        error = err;
                        break;
                    }
                }
                printf("������ ������� ��� ����⢮ �१ �஡��: ");
                fflush(stdin);
                gets(tempS);
                min = 1001; 
                d = 0;
                minp = 0;
                while (true)
                {
                    if (tempS[d] == '\0')
                        break;
                    d++;
                }
                for (j = 0; j < hotel->guestsCount; j++)
                {
                    temp = myComp(tempS, d, hotel->guests[j].FIO);
                    if (temp < min)
                    {
                        min = temp;
                        minp = j;
                    }
                }
                if (min > d / 3)
                {
                    p--;
                    printf("����� �� ������\n");
                    continue;
                }
                flag = false;
            }
            else if (p == 1)
            {
                char c;
                int min,d;
                printf("��ᯮ��                  <-");
                c = getch();
                if (c == 9)
                    continue;
                clearConsoleLine();
                if (c == 27)
                {
                    printf("\n�� 㢥७� �� ��� ��ࢠ�� ���� �����?\n");
                    if (askNY())
                    {
                        error = err;
                        break;
                    }
                }
                printf("������ �਩�� ����� ��ᯮ��: ");
                fflush(stdin);
                gets(tempS);
                min = 1001; 
                d = 0;
                minp = 0;
                while (true)
                {
                    if (tempS[d] == '\0')
                        break;
                    d++;
                }
                for (j = 0; j < hotel->guestsCount; j++)
                {
                    temp = myComp(tempS, d, hotel->guests[j].passport);
                    if (temp < min)
                    {
                        min = temp;
                        minp = j;
                    }
                }
                if (min > d / 3)
                {
                    p--;
                    printf("����� �� ������\n");
                    continue;
                }
                flag = false;
            }
            else if (p == 2)
            {
                char c;
                int min,d;
                printf("����䮭                  <-");
                c = getch();
                if (c == 9)
                    continue;
                clearConsoleLine();
                if (c == 27)
                {
                    printf("\n�� 㢥७� �� ��� ��ࢠ�� ���� �����?\n");
                    if (askNY())
                    {
                        error = err;
                        break;
                    }
                }
                printf("������ ⥫�䮭 �����: ");
                fflush(stdin);
                gets(tempS);
                min = 1001; 
                d = 0;
                minp = 0;
                while (true)
                {
                    if (tempS[d] == '\0')
                        break;
                    d++;
                }
                for (j = 0; j < hotel->guestsCount; j++)
                {
                    temp = myComp(tempS, d, hotel->guests[j].phone);
                    if (temp < min)
                    {
                        min = temp;
                        minp = j;
                    }
                }
                if (min > d / 3)
                {
                    p--;
                    printf("����� �� ������\n");
                    continue;
                }
                flag = false;
            }
            else if (p == 3)
            {
                char c;
                int min,d;
                printf("��� ��ᥫ����           <-");
                c = getch();
                if (c == 9)
                    continue;
                clearConsoleLine();
                if (c == 27)
                {
                    printf("\n�� 㢥७� �� ��� ��ࢠ�� ���� �����?\n");
                    if (askNY())
                    {
                        error = err;
                        break;
                    }
                }
                printf("������ ���� ��ᥫ���� �����: ");
                fflush(stdin);
                gets(tempS);
                min = 1001; 
                d = 0;
                minp = 0;
                while (true)
                {
                    if (tempS[d] == '\0')
                        break;
                    d++;
                }
                for (j = 0; j < hotel->guestsCount; j++)
                {
                    temp = myComp(tempS, d, hotel->guests[j].inDate);
                    if (temp < min)
                    {
                        min = temp;
                        minp = j;
                    }
                }
                if (min > d / 3)
                {
                    p--;
                    printf("����� �� ������\n");
                    continue;
                }
                flag = false;
            }
            else if (p == 4)
            {
                char c;
                int min,d;
                printf("��� ��ᥫ����           <-");
                c = getch();
                if (c == 9)
                    continue;
                clearConsoleLine();
                if (c == 27)
                {
                    printf("\n�� 㢥७� �� ��� ��ࢠ�� ���� �����?\n");
                    if (askNY())
                    {
                        error = err;
                        break;
                    }
                }
                printf("������ ���� ��ᥫ���� �����: ");
                fflush(stdin);
                gets(tempS);
                min = 1001; 
                d = 0;
                minp = 0;
                while (true)
                {
                    if (tempS[d] == '\0')
                        break;
                    d++;
                }
                for (j = 0; j < hotel->guestsCount; j++)
                {
                    temp = myComp(tempS, d, hotel->guests[j].outDate);
                    if (temp < min)
                    {
                        min = temp;
                        minp = j;
                    }
                }
                if (min > d / 3)
                {
                    p--;
                    printf("����� �� ������\n");
                    continue;
                }
                flag = false;
            }
        }
        if (error)
            continue;
        printf("\n�� 㢥७� �� ��� �������� %s � ��ᯮ��� ����஬ %s � ⥫�䮭�� ����஬ %s\n"
               "�஦����饣� � ������ %d � ��ਮ� �६��� � %s �� %s?\n",
               hotel->guests[minp].FIO, hotel->guests[minp].passport, hotel->guests[minp].phone, hotel->guests[minp].roomNumber, hotel->guests[minp].inDate, hotel->guests[minp].outDate);
        if (askNY())
        {
            return minp;
        }
        else
        {
            printf("����\n");
            first = true;
            p--;
        }
    }
}
void editGuest(sthotel *hotel, int i)
{
    int first = true;
    printf("��롥�� ���� ��� ��������� � ����� %s:\n"
           "���,��ᯮ��,⥫�䮭,��� ��ᥫ����,��� ��ᥫ����,����� �������\n",
           hotel->guests[i].FIO);    
    while (true)
    {
        int temp;
        char tempS[1000];
        if (!first)
            printf("\n��।��஢��� ��� ����� %s?\n", hotel->guests[i].FIO);
        if (first || askNY())
        {
            int p = -1, flag = true;
            first = false;            
            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ।���஢���� �����)\n");
            while (flag)
            {
                p = (p + 1) % 6;
                clearConsoleLine();
                if (p == 0)
                {
                    char c;
                    printf("���                  <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ������� ��� ����⢮ �१ �஡��: ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ���?\n");
                    if (askNY())
                    {
                        strcpy(hotel->guests[i].FIO, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 1)
                {
                    char c;
                    printf("��ᯮ��              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ �਩�� ����� ��ᯮ��: ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ��ᯮ��?\n");
                    if (askNY())
                    {
                        strcpy(hotel->guests[i].passport, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 2)
                {
                    char c;
                    printf("����䮭              <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ����� ⥫�䮭� ������: ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ����� ⥫�䮭�?\n");
                    if (askNY())
                    {
                        strcpy(hotel->guests[i].phone, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 3)
                {
                    char c;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ����: ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ���� ��ᥫ����?\n");
                    if (askNY())
                    {
                        strcpy(hotel->guests[i].inDate, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 4)
                {
                    char c;
                    printf("��� ��ᥫ����       <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��������� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ���� ��ᥫ����: ");
                    fflush(stdin);
                    gets(tempS);
                    if (tempS[0] == '\0')
                    {
                        p--;
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ���� ��ᥫ����?\n");
                    if (askNY())
                    {
                        strcpy(hotel->guests[i].outDate, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 5)
                {
                    char c;
                    int j,f;
                    printf("����� �������        <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ��ᥫ���� �����?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    f = false;
                    printf("�������� �����: ");
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].empty != 0)
                        {
                            if (f)
                                printf(", ");
                            else
                                f = true;
                            printf("%d(%d/%d)", hotel->room[j].number, hotel->room[j].peoples - hotel->room[j].empty, hotel->room[j].peoples);
                        }

                    printf("\n������ ����� �������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    f = true;
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].number == temp && hotel->room[j].empty != 0)
                        {
                            f = false;
                            break;
                        }
                    if (f)
                    {
                        p--;
                        printf("�����室�騩 ����� �������\n");
                        continue;
                    }
                    printf("\n�� 㢥७� �� ��� �������� ����� �������?\n");
                    if (askNY())
                    {
                        hotel->room[hotel->guests[i].posRoom].empty++;
                        hotel->guests[i].posRoom = j;
                        hotel->guests[i].roomNumber = temp;
                        hotel->room[j].empty--;
                        flag = false;
                    }
                    else
                        continue;
                }
            }
        }
        else
            break;
    }
}
void editHotel(sthotel *hotel)
{
    int first = true, flag = false;
    printf("�롥�� ���� ��� ���������:\n"
           "�������� ���⨭���, ������, �����\n");

    while (true)
    {
        int temp;
        char tempS[1000];
        if (!first)
            printf("\n��।���஢��� ��� ���⨭���?\n");

        if (first || askNY())
        {
            int p = -1;
            first = false;
            flag = true;
            printf("(�������� tab �⮡� ��३� � ��㣮�� ����; Esc �⮡� ��ࢠ�� ।���஢���� ���⨭���)\n");
            while (flag)
            {
                p = (p + 1) % 3;
                clearConsoleLine();
                if (p == 0)
                {
                    char c;
                    printf("�������� ���⨭���   <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� ���⨭���?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("������ ����� �������� ���⨭���: ");
                    fflush(stdin);
                    gets(tempS);
                    printf("\n�� 㢥७� �� ��� �������� �������� ���⨭���?\n");
                    if (askNY())
                    {
                        strcpy(hotel->name, tempS);
                        flag = false;
                    }
                    else
                        continue;
                }
                else if (p == 1)
                {
                    char c;
                    int j,f;
                    printf("������              <-");
                    c = getch();                    
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� ���⨭���?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    printf("����� ������ ���⨭���: ");
                    f = false;
                    for (j = 0; j < hotel->roomCount; j++)
                    {
                        if (f)
                            printf(", ");
                        else
                            f = true;
                        printf("%d", hotel->room[j].number);
                    }
                    printf("\n������ ����� ������� ��� ���������: ");
                    scanf("%s", tempS);
                    temp = stod(tempS);
                    f = true;
                    for (j = 0; j < hotel->roomCount; j++)
                        if (hotel->room[j].number == temp)
                        {
                            f = false;
                            break;
                        }
                    if (temp == err || temp <= 0 || f)
                    {
                        p--;
                        printf("�����室�騩 ����� �������\n");
                        continue;
                    }
                    editRooms(hotel, j);
                    flag = false;
                }
                else if (p == 2)
                {
                    char c;
                    printf("�����                <-");
                    c = getch();
                    if (c == 9)
                        continue;
                    clearConsoleLine();
                    if (c == 27)
                    {
                        printf("\n�� 㢥७� �� ��� ��ࢠ�� ।���஢���� ���⨭���?\n");
                        if (askNY())
                        {                            
                            break;
                        }
                    }
                    temp = findGuest(hotel);
                    if (temp == err)
                    {
                        p--;
                        continue;
                    }
                    editGuest(hotel, temp);
                    flag = false;
                }
            }
        }
        else
            break;
    }
}
int main()
{
    int saved;
    FILE *fp1,*fp2;
    sthotel hotel;
    setlocale(LC_ALL, "ru_RU.CP866");
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    fp1 = fopen("hotel.txt", "r");
    fp2 = fopen("guests.txt", "r");    
    clearHotel(&hotel);
    printf("�� ������ �������� �᪫���� �� ������.\n");
    saved = true;
    if (fp1 == NULL && fp2 == NULL)
    {
        printf("\n��宦� �� �, �� �� ��� ���� �����.\n"
               "���� �� �� ���樠����஢��� ����� � ���⨭��?\n");
        if (askNY())
        {
            FILE *fp1,*fp2;
            init(&hotel);
            fp1 = fopen("hotel.txt", "w");
            fp2 = fopen("guests.txt", "w");
            fclose(fp1);
            fclose(fp2);
            Save(&hotel, &saved);
        }
        else
        {
            printf("��� ��������� ᬥ���� �����頩���.\n");
            fclose(fp1);
            fclose(fp2);
            getch();
            return 0;
        }
    }
    else
    {
        LoadHotel(&hotel, fp1);
        LoadGuests(&hotel, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    while (true)
    {
        char c;
        printf("\n**************************\n");
        printf("(Esc �������� �믮������ �ணࠬ��; Ctrl+s ��࠭���)\n");
        printf("\n1. �뢥�� ����� � �������\n");
        printf("2. �뢥�� ����� � ������\n");
        printf("3. �������� ������� � ���⨭���\n");
        printf("4. ��ᥫ��� ������ �����\n");
        printf("5. ������஢��� ����� � ���⨭��\n");
        printf("6. ��ᥫ��� �����\n");

        printf("8. �������� � ��᫥����� ��࠭�����\n");
        printf("9. C����� �� �����᪨� ����஥�\n");
        printf("**************************\n");
        c = getch();
        if (c == 19)
        {
            Save(&hotel, &saved);
            printf("�ᯥ譮� ��࠭����\n");
        }
        else if (c == '1')
        {
            int i;
            printf("��� ������������ %d �⠦��� ���⨭�� '%s' ����� %d ������(%d ᢮������ ����):\n",
                   hotel.floors, hotel.name, hotel.roomCount, hotel.emptyCount);            
            for (i = 0; i < hotel.roomCount; i++)
                printf("%d. �� %d �⠦� ������ ����� %d ����� '%s' �⮨������ %d �.�. ����⠭��� �� %d 祫����(%d ���� ᢮�����)\n",
                       i + 1, hotel.room[i].floor, hotel.room[i].number, hotel.room[i].class, hotel.room[i].cost, hotel.room[i].peoples, hotel.room[i].empty);
        }
        else if (c == '2')
        {
            int i;
            printf("� ���� �㤥᭥���� ���⨭��� 㦥 ��ᥫ����� %d 祫����:\n", hotel.guestsCount);            
            for (i = 0; i < hotel.guestsCount; i++)
                printf("%d. �������� %s � ��ᯮ��� ����஬ %s � ⥫�䮭�� ����஬ %s\n"
                       "��ᥫ���� %s � ������� %d � ��ᥫ���� %s\n",
                       i + 1, hotel.guests[i].FIO, hotel.guests[i].passport, hotel.guests[i].phone, hotel.guests[i].inDate, hotel.guests[i].roomNumber, hotel.guests[i].outDate);
        }
        else if (c == '3')
        {
            addRooms(&hotel);
            saved = false;
        }
        else if (c == '4')
        {
            addGuest(&hotel);
            saved = false;
        }
        else if (c == '5')
        {
            editHotel(&hotel);
            saved = false;
        }
        else if (c == '6')
        {
            delGuest(&hotel);
            saved = false;
        }
        else if (c == '8')
        {
            FILE *fp1 = fopen("backupHotel.txt", "r");
            FILE *fp2 = fopen("backupGuests.txt", "r");
            if (fp1 == NULL || fp2 == NULL)
                printf("����⠭����� ����� ����������\n");
            else
            {
                clearHotel(&hotel);
                LoadHotel(&hotel, fp1);
                LoadGuests(&hotel, fp2);
                printf("�ᯥ譮� ����⠭�������\n");
                saved = false;
                fclose(fp1);
                fclose(fp2);
            }
        }
        else if (c == '9')
        {
            printf("\n�� 㢥७� �� ��� ����� �ணࠬ�� �� �����᪨� ����஥�?\n");
            if (askNY())
            {
                printf("\n��筮? �� ���짮��⥫�᪨� ����� ���� ������.\n");
                if (askNY())
                {
                    printf("\n� ����� ��� ⠪� ��।㬠��?\n");
                    if (askNY())
                    {
                        printf("�� � �⫨筮 �� ��।㬠��\n");
                    }
                    else
                    {
                        saved = false;
                        Save(&hotel, &saved);
                        remove("hotel.txt");
                        remove("guests.txt");
                        printf("��१������ �ணࠬ�� ��� �ᯥ譮�� �����襭�� ���.\n");
                        getch();
                        break;
                    }
                }
            }
        }
        else if (c == 27)
        {
            printf("\n�� 㢥७� �� ��� �������� �믮������ �ணࠬ��?\n");
            if (askNY())
            {
                printf("\n���࠭��� ��������� ��। ��室��?\n");
                if (askNY())
                {
                    Save(&hotel, &saved);
                    printf("�ᯥ譮� ��࠭����\n");
                }
                printf("�� ����� �����!\n");
                getch();
                break;
            }
        }
        else
            printf("�������⭠� �������\n");
    }
    return 0;
}
