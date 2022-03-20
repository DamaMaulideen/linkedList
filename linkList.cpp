#include <iostream>
#include <string.h>

using namespace std;

struct dtnilai
{
    char nrp[10];
    char nama[20];
    double nilai;
    struct dtnilai *next;
};

struct dtnilai *ujung;

void sisip_awal_LIFO()
{
    struct dtnilai *tampung;
    int j = 0;
    char jawab[2];
    while (1)
    {
        ujung = (struct dtnilai *)malloc(sizeof(struct dtnilai));
        fflush(stdin);
        printf("NRP :");
        scanf("%s", &ujung->nrp);
        printf("Nama :");
        scanf("%s", &ujung->nama);
        printf("Nilai Test :");
        scanf("%lf", &ujung->nilai);
        if (j == 0)
        {
            ujung->next = NULL;
            tampung = ujung;
        }
        else
        {
            ujung->next = tampung;
            tampung = ujung;
        }

        printf("Ada data lagi(y/t):");
        scanf("%s", &jawab);
        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        }
        else if ((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0))
            break;
    }
}

// void sisip_awal_FIFO(){
//     struct dtnilai *tampung, *awal;
//     int j=0;
//     char jawab[2];

//     while (/* condition */)
//     {
//         /* code */
//     }
    
// }

int main(){
    sisip_awal_LIFO();
    // sisip_awal_FIFO();
}