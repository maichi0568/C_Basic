#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct covid
{
    char add[40];
    int hour;
    int minute;
    struct covid *next;
} Covid;

Covid *first, *last;

void khoitao()
{
    first = NULL;
    last = NULL;
}

Covid *khoitaonode(char add[], int hour, int minute)
{
    Covid *node = (Covid *)malloc(sizeof(Covid));
    strcpy(node->add, add);
    node->hour = hour;
    node->minute = minute;
    node->next = NULL;
    return node;
}

void themvaocuoi(char add[], int hour, int minute)
{
    Covid *node = khoitaonode(add, hour, minute);
    if (first == NULL && last == NULL)
    {
        first = last = node;
        return;
    }
    else
    {
        last->next = node;
        last = node;
    }
}

void docdulieutufile()
{
    char filename[30];
    printf("Nhap ten file: ");
    fflush(stdin);
    gets(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Doc du lieu khong thanh cong\n");
        return;
    }
    while (!feof(f))
    {
        char add[40];
        int hour, minute;
        fscanf(f, "%s %d %d\n", add, &hour, &minute);
        themvaocuoi(add, hour, minute);
    }
    printf("Doc du lieu thanh cong\n");
    fclose(f);
}

void indsach()
{
    for (Covid *k = first; k != NULL; k = k->next)
    {
        printf("%-50s %-10d %-10d\n", k->add, k->hour, k->minute);
    }
}

void timadd()
{
    char add[40];
    int std = 0;
    printf("Nhap ten dia diem muon tim: ");
    fflush(stdin);
    gets(add);
    for (Covid *k = first; k != NULL; k = k->next)
    {
        if (strcmp(k->add, add) == 0)
        {
            Covid *node = khoitaonode(k->add, k->hour, k->minute);
            ++std;
            if (std >= 2)
            {
                printf(", %d:%d\n", k->hour, k->minute);
            }
            else
            {
                printf("%d:%d", k->hour, k->minute);
            }
        }
    }
    if (std == 0)
    {
        printf("Ban chua toi dia diem do\n");
    }
}

void timtime()
{
    int hour;
    int minute;
    int std = 0;
    do
    {
        printf("Nhap thoi gian muon tim: ");
        scanf("%d %d", &hour, &minute);
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
        {
            printf("Nhap dung dinh dang 0<=gio<=23 va 00<=phut<=59\n");
        }
    } while (hour < 0 || hour > 23 || minute < 0 || minute > 59);
    for (Covid *k = first; k != NULL; k = k->next)
    {
        if (k->hour == hour && k->minute == minute)
        {
            printf("%s\n", k->add);
            std++;
        }
    }
    if (std == 0)
    {
        printf("Khong tim thay lich su di chuyen\n");
    }
}

void kiemtratruyvet()
{
    char add[40];
    int hour;
    int minute;
    do
    {
        printf("Nhap dia diem thoi gian muon tim: ");
        scanf("%d %d", &hour, &minute);
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
        {
            printf("Nhap dung dinh dang 0<=gio<=23 va 00<=phut<=59\n");
        }
    } while (hour < 0 || hour > 23 || minute < 0 || minute > 59);
    for (Covid *k = first; k != NULL; k = k->next)
    {
        if (strcmp(k->add, add) == 0)
        {
            if (k->hour == hour && k->minute >= minute)
            {
                printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                return;
            }
            if (k->hour > hour)
            {
                printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                return;
            }
        }
    }
    printf("Lich su di chuyen cua ban OK\n");
    return;
}

void menu()
{
    printf("1. Nap du lieu log lich su di chuyen\n");
    printf("2. In ra lich su di chuyen\n");
    printf("3. Tim kiem lich su di chuyen theo dia diem\n");
    printf("4. Tim kiem lich su di chuyen theo thoi gian\n");
    printf("5. Kiem tra truy vet moi nhat\n");
    printf("6. Thoat\n");
    printf("Nhap lua chon: ");
}

int main()
{
    int luachon;
    khoitao();
    while (1)
    {
        menu();
        scanf("%d", &luachon);
        if (luachon == 1)
        {
            docdulieutufile();
        }
        else if (luachon == 2)
        {
            indsach();
        }
        else if (luachon == 3)
        {
            timadd();
        }
        else if (luachon == 4)
        {
            timtime();
        }
        else if (luachon == 5)
        {
            kiemtratruyvet();
        }
        else if (luachon == 6)
        {
            return 0;
        }
    }
}
