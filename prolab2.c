//Beyhan KARADAĞ 190201012 Alperen KOLAT 200201006
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/*struct suffix_tree_node
{
    struct suffix_tree_node *child[100];
 
    struct suffix_tree_node *suf_link;

int start; //ağac veri yapisi
int *end;

int suf_index;
};

typedef struct suffix_tree_node Node;
 */

void suffixtreecontrol();

void reverse_string(char *str);

int main()
{
    int secim;

    while (1)
    {
        printf("%s\n\t* * * * * * * * * MENU * * * * * * * * *\n\n","\x1B[0m");
        printf("\tKatari icin sonek agaci olusturabilir mi ? \n\t\t\tGormek icin 1\'e basiniz ...\n\n");
        printf("\tKatari icinde p katari geciyor mu ?; \n\t Geciyorsa gectigi ilk pozisyon yeri\n\t Ve kac kez tekrar ettigini  \n\t\t\t gormek icin 2\'ye basiniz...\n\n");
        printf("\tKatari icin  en uzun tekrar eden altkatari bulmak; \n\t Ve kac kez tekrar ettigini \n\t\t\tGormek icin 3\'e basiniz...\n\n");
        printf("\tKatari icin en cok tekrar eden alt katari bulmak ;\n\t Ve kez tekrar ettigini \n\t\t\tGormek icin 4\'e basiniz..\n\n");
        printf("\tProgramdan cikmak icin 0\'a basiniz...\n\n");
        printf("Secim giriniz:\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:

        suffixtreecontrol();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;

        case 0:
        printf("%s\n\tPROGRAMDAN CIKIS YAPTINIZ...\n","\x1B[33m");
            exit(0);
            break;

        default:
            printf("böyle bir secim yok...");
            break;
        }
    }

    return 0;
}


void suffixtreecontrol()
{
    char str[40];
    int str_lentgh = 0;
    int str_yari_uzunluk = 0;
    int sonuc = 1;
    char str_orta[10];
    char str_1[10];
    char str_2[10];
    
    FILE *dosyaSTR = fopen("string.txt", "r"); //Kullanıcıdan alınmalı
    fscanf(dosyaSTR, "%s", str);
    str_lentgh = strlen(str);


    str_yari_uzunluk = str_lentgh / 2;
    rewind(dosyaSTR);
//bu satir sonrasıdan konrol kelime yarısı için yapılır.
//her sonek için for döngüsü konulup "i" ile farklı uzunluktaki içinde kontrol yapılması gerekir.
    fgets(str_1, str_yari_uzunluk + 1, dosyaSTR);

    if ((str_lentgh % 2) == 1)
    {
        fgets(str_orta, 2, dosyaSTR);

    }

    fgets(str_2, str_yari_uzunluk + 1, dosyaSTR);

    sonuc = strcmp(str_1, str_2);

    if (sonuc == 0)
    {
        printf("%s\n %s katari icin sonek agaci olusturulamaz!\n\n","\x1B[31m", str);
    }

    else
    {
        printf("%s\n katari icin sonek agaci olusturulabilir!\n\n","\x1B[34m", str);
    }

    fclose(dosyaSTR);
}



void reverse_string(char *str)
{
    char swap;
    int size = 0;
    for(;*(str+size) != '\0';size++);

    size -= 1;

    for(int i=0;i<=size/2;i++)
    {
        swap = *(str+i);
        *(str+i) = *(str+size-i);
        *(str+size-i) = swap;
    }
    
}
