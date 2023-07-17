#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct profile
{
    char name[30];
    char email[30];
    struct profile *next;
} Profile;

Profile *first, *last;

void khoitao()
{
    first = NULL;
    last = NULL;
}

Profile *khoitaonode(char name[], char email[])
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

void themvaocuoi(char *name, char *email)
{
    Profile *node = khoitaonode(name, email);
    if (first == NULL)
    {
        first = last = node;
        return;
    }
    else
    {
        last->next = node;
        last = node;
    }

    /*while (first->next != NULL) {
        first = first->next;
    }
    first->next = node;*/
}

void indsach()
{
    for (Profile *k = first; k != NULL; k = k->next)
    {
        printf("%s %s\n", k->name, k->email);
    }
}

void timkiem()
{
    char name[30];
    int x = 0;
    printf("Nhap ten sinh vien muon tim: ");
    fflush(stdin);
    gets(name);
    for (Profile *k = first; k != NULL; k = k->next)
    {
        if (strcmp(k->name, name) == 0)
        {
            Profile *h = khoitaonode(k->name, k->email);
            printf("%s %s\n", h->name, h->email);
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("Khong ton tai sinh vien nay\n");
    }
}

void xoahoso()
{
    char name[30];
    int x = 0;
    printf("Nhap ten sinh vien muon xoa: ");
    fflush(stdin);
    gets(name);
    for (Profile *k = first; k != NULL; k = k->next)
    {
        Profile *h = khoitaonode(k->name, k->email);
        if (strcmp(first->name, name) == 0)
        {
            Profile *g = khoitaonode(k->name, k->email);
            g = first;
            first = first->next;
            free(g);
        }
        if (strcmp(last->name, name) == 0)
        {
            if (k->next == last)
            {
                free(last);
                k->next = NULL;
                last = k;
            }
        }
        Profile *p;
        if (strcmp(k->name, name) == 0)
        {
            p->next = k->next;
            free(k);
        }
        p = k;
    }
}

void taithongtin()
{
    char filename[30];
    fflush(stdin);
    gets(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Khong tai duoc thong tin\n");
        return;
    }
    while (!feof(f))
    {
        char name[30], email[30];
        fscanf(f, "%[^0]0 %s\n", name, email);
        themvaocuoi(name, email);
    }
    fclose(f);
}

void ghidulieuvaofile()
{
    char filename[30];
    fflush(stdin);
    gets(filename);
    FILE *f = fopen(filename, "w");
    for (Profile *k = first; k != NULL; k = k->next)
    {
        fprintf(f, "%s0 %s\n", k->name, k->email);
        //if (k->next != NULL)
            //fprintf(f, "%s %s\n", k->name, k->email);
    }
    fclose(f);
}

void menu()
{
    printf("1. Nhap thong tin cho node\n");
    printf("2. In danh sach\n");
    printf("3. Tim kiem mot node\n");
    printf("4. Xoa ho so\n");
    printf("5. Tai thong tin\n");
    printf("6. Ghi du lieu vao file\n");
    printf("0. Thoat chuong trinh\n");
}

void themnode()
{
    char name[30], email[30];
    fflush(stdin);
    printf("Name: ");
    gets(name);
    fflush(stdin);
    printf("Email: ");
    gets(email);
    themvaocuoi(name, email);
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
            themnode();
        }
        else if (luachon == 2)
        {
            indsach();
        }
        else if (luachon == 3)
        {
            timkiem();
        }
        else if (luachon == 4)
        {
            xoahoso();
        }
        else if (luachon == 5)
        {
            taithongtin();
        }
        else if (luachon == 6)
        {
            ghidulieuvaofile();
        }
        else
            return 0;
    }
}