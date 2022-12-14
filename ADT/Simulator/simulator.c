#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void CreateSimulator(Simulator *S, Word nama,POINT P, PrioQueueTime Q){
    Nama(*S) = nama;
    Lokasi(*S) = P;
    Inventory(*S) = Q;
}

void BacaSimulator(Simulator *S){
    POINT P;
    PrioQueueTime Q;
    MakeEmpty(&Q, 50);
    printf("Input Username: ");
    STARTWORD1();
    // Nama(*S) = currentWord;
    Kolom(P) = 0;
    Baris(P) = 0;    
    // Lokasi(*S) = P;
    // Inventory(*S) = Q;
    CreateSimulator(S,currentWord,P,Q);
}

// void MoveSimulator(Simulator *S, int x){
//     switch (x){
//     case 1: //NORTH
//         Baris(Lokasi(*S)) --;
//         break;
//     case 2: //EAST
//         Kolom(Lokasi(*S)) ++;
//         break;
//     case 3: //SOUTH
//         Baris(Lokasi(*S)) ++;
//         break;
//     case 4: //WEST
//         Kolom(Lokasi(*S)) --;
//         break;
    
//     default:
//         break;
//     }
// }

void DisplaySimulator(Simulator S){
    // printf("Nama Pengguna :");
    // DisplayNama(S);

    // printf("Lokasi :");
    // DisplayLokasi(S);
    DisplayNama(S);
    printf("di posisi: ");
    DisplayLokasi(S);
    // printf("\n");
}

void DisplayNama(Simulator S){
    // printf("%s", Nama(S));
    DisplayWord(Nama(S));
}

void DisplayLokasi(Simulator S){
    printf("(%d,%d)\n", Baris(Lokasi(S)), Kolom(Lokasi(S)));
}


//////////////////////////////////////////////////////////////////////////////////////
boolean IsEmpty(PrioQueueTime Q) {
    return (Head(Q) == IDX_UNDEF && Tail(Q) == IDX_UNDEF);
}
/* Mengirim true jika Q kosong */

boolean IsFull(PrioQueueTime Q) {
    return (MaxEl(Q) == NBElmt(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

boolean IsMember(PrioQueueTime Q, int id){
    address p;
    p = Head(Q);
    if (!IsEmpty(Q)){
        while (p!=Tail(Q)+1){
            if (InfoId(Elmt(Q, p))==id){
                return true;
            }
            p++;
        }
    }
    return false;
}

int NBElmt(PrioQueueTime Q) {    
    if (IsEmpty(Q)) {
        return 0;
    }
    else if (Tail(Q) >= Head(Q)) {
        return Tail(Q) - Head(Q)+1;
    }
    else {
        return MaxEl(Q) - Head(Q) + Tail(Q)+1;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueueTime *Q, int Max) {
    // (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
    Q->T[Max]; 
    if ((*Q).T == NULL) {
        MaxEl(*Q) = 0;
    }
    else {
        MaxEl(*Q) = Max;
        Head(*Q) = IDX_UNDEF;
        Tail(*Q) = IDX_UNDEF;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime *Q) {
    MaxEl(*Q) = 0;
    Head(*Q) = IDX_UNDEF;
    Tail(*Q) = IDX_UNDEF;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(Simulator *S, infotype X) {
    int idx;
    int i, j;
    infotype temp;
    if (IsEmpty(Inventory(*S))) {
        Head(Inventory(*S)) = 0;
        Tail(Inventory(*S)) = 0;
        InfoTail(Inventory(*S)) = X;

    }
    else {
        Tail(Inventory(*S)) = Tail(Inventory(*S)) == MaxEl(Inventory(*S)) - 1 ? 0 : Tail(Inventory(*S)) + 1;
        InfoTail(Inventory(*S)) = X;
        i = Tail(Inventory(*S));
        j = i == 0 ? MaxEl(Inventory(*S)) - 1 : i - 1;
        while ((i != Head(Inventory(*S))) /*&& (Time(Elmt(*Q, i)) < (Time(Elmt(*Q, j))))   pake compare time*/) {
            temp = Elmt(Inventory(*S), i);
            Elmt(Inventory(*S), i) = Elmt(Inventory(*S), j);
            Elmt(Inventory(*S), j) = temp;
            i = j;
            j = i == 0 ? MaxEl(Inventory(*S)) - 1 : i - 1;
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Dequeue(PrioQueueTime *Q, infotype *X) {
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = IDX_UNDEF;
        Tail(*Q) = IDX_UNDEF;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxEl(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

void DequeueID(PrioQueueTime *Q, infotype *X, int id) {
    boolean found;
    int idx;
    
    if (NBElmt(*Q) == 1) {
        if (ID(InfoHead(*Q))==id){
            *X = InfoHead(*Q);
            Head(*Q) = IDX_UNDEF;
            Tail(*Q) = IDX_UNDEF;
        }
    }
    else if (NBElmt(*Q)>1){
        idx = (int) Head(*Q);
        found = false;
        if (Tail(*Q)>Head(*Q)){
            while (!found&&idx<Tail(*Q)){
                if (ID(Elmt(*Q, idx))==id){
                    found = true;
                    *X = Elmt(*Q, idx);
                }
                if (!found){
                    idx++;
                }
            }
            for (int i = idx; i<Tail(*Q); i++){
                Elmt(*Q, i) = Elmt(*Q, i+1);
            }
            Tail(*Q)--;
        }else{
            while (!found&&idx<Tail(*Q)+NBElmt(*Q)){
                if (ID(Elmt(*Q, idx%NBElmt(*Q)))==id){
                    found = true;
                    *X = Elmt(*Q, idx%NBElmt(*Q));
                }
                if (!found){
                    idx++;

                }
            }
            for (int i = idx; i<Tail(*Q)+NBElmt(*Q); i++){
                Elmt(*Q, i%NBElmt(*Q)) = Elmt(*Q, (i+1)%NBElmt(*Q));
            }
            Tail(*Q)--;
        }
        
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueTime(Simulator S) {
    infotype val;
    PrioQueueTime temp;
    temp = Inventory(S);
    if (!IsEmpty(Inventory(S))){
        while (!IsEmpty(temp)){
            Dequeue(&temp, &val);
            TulisTIME1(Time(val));
            printf(" - ");
            DisplayWord(InfoNama(val));
            printf("\n");
        }
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
void Kedaluwarsa(Simulator *S, infotype *X, int *n){
    
    if (!IsEmpty(Inventory(*S))){
        for (int i = Head(Inventory(*S)); i<=Tail(Inventory(*S)); i++){
            Time(Elmt(Inventory(*S), i)) = PrevMenit(Time(Elmt(Inventory(*S), i)));
        }

        for (int i = 0; i<NBElmt(Inventory(*S)); i++){
            if (TIMEToMenit(Time(Elmt(Inventory((*S)), i)))<=0){
                    Dequeue(&Inventory(*S), X);
                    DisplayWord(NAMA(*X));
                    *n = 1;
                }
        } 
    }
}

void waitKedaluwarsa(Simulator *S, int min, infotype *X, int *n){
    if (!IsEmpty(Inventory(*S))){
        for (int i = Head(Inventory(*S)); i<=Tail(Inventory(*S)); i++){
            Time(Elmt(Inventory(*S), i)) = PrevNMenit(Time(Elmt(Inventory(*S), i)), min);
        }

        for (int i = 0; i<NBElmt(Inventory(*S)); i++){
            if (TIMEToMenit(Time(Elmt(Inventory((*S)), i)))<=0){
                    Dequeue(&Inventory(*S), X);
                    DisplayWord(NAMA(*X));
                    *n = 1;
                }
        }   
    }
}


///////////////////////////////////////////////////////////////////////////////////////
boolean IsQueueEmpty (Queue Q)
{
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q)==Nil && Ekor(Q)==Nil);
}


boolean IsQueueFull (Queue Q)
{
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    //kamus
    int hitung;
    //Algoritma
        hitung = ((Ekor(Q)-Head(Q)+MaxEl(Q)) % MaxEl(Q)) + 1;
    return (hitung == MaxEl(Q));
}


int NBQueueElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    //Kamus
    int count;
    //Algoritma
    if (IsQueueEmpty(Q))
    {
        count = 0;
    }
    else 
    {
        count = ((Ekor(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q) + 1);
    }
    return (count);
}


/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
     //Kamus
    //Algoritma
    // (*Q).T = (infotype *) malloc ((Max+1) * sizeof (infotype));
    Q->T[100];
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Ekor(*Q) = Nil;
    } 
    else //Alokasi gagal
    {
        MaxEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
{
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    //Kamus
   //Algoritma
    MaxEl(*Q) = 0;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void AddQueue(Queue * Q, infotype X)
{
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
    //Kamus
    int indeks;
    infotype temp;
    //Algoritma
    if (IsQueueEmpty(*Q))
    {
        Head(*Q)=1;
        Ekor(*Q)=1;
        InfoEkor(*Q)=X;

    } 
    else
    {
        Ekor(*Q) = Ekor(*Q) + 1;
        InfoEkor(*Q) = X;
        indeks = Ekor(*Q);
        while (( TLT(Prio(Elmt(*Q,indeks)), Prio(Elmt(*Q,indeks-1)))) && (indeks-1!=0)){
            temp = Elmt(*Q,indeks);
            Elmt(*Q,indeks) = Elmt(*Q,indeks-1);
            Elmt(*Q,indeks-1)=temp;
            indeks = indeks - 1;
        }
    }
}


void Del (Queue * Q, infotype * X)
{
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju";
        Q mungkin kosong */
    //Kamus Lokal
    int indeks;
    //Algoritma
    *X = InfoHead(*Q);
    if ((Ekor(*Q)==Kepala(*Q))&&Ekor(*Q)!=Nil) { /* Satu elemen */
        Kepala(*Q) = Nil;
        Ekor(*Q) = Nil;
    } else {
        Kepala(*Q)++;
    }
}

/* Operasi Tambahan */
void showDeliveryQueue (Queue Q)
{
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
Waiting Cust
<jumlah-1>
...
<jumlah-n>
#
*/
    printf("List Makanan di Perjalanan\n");
    printf("(nama - waktu sisa delivery)\n");
    if (!IsQueueEmpty(Q)) {
        for (int i = 1; i <= NBQueueElmt(Q); i++){
            printf("%d. ", i);
            DisplayWord(NAMA(Elmt(Q, i)));
            printf(" - ");
            TulisTIME1(PENGIRIMAN(Elmt(Q,i)));
            printf("\n");
        }
    }
}

void Delivery(Queue *Q, Simulator *S, int *n){
    infotype X;
    
    if (!IsQueueEmpty(*Q)){
        for (int i = Kepala(*Q); i<=Ekor(*Q); i++){
            Prio(Elment(*Q, i)) = PrevMenit(Prio(Elment(*Q, i)));
        }

        while ((Head(*Q)!=Nil)&&(TIMEToMenit(Prio(InfoKepala(*Q))))<=0){
            Del(Q, &X);
            Enqueue(S, (infotype) X);
            *n = 2;
        }
    }
}

void waitDelivery(Queue *Q, Simulator *S, int min, int *n){
    infotype X;
    
    if (!IsQueueEmpty(*Q)){
        for (int i = Kepala(*Q); i<=Ekor(*Q); i++){
            Prio(Elment(*Q, i)) = PrevNMenit(Prio(Elment(*Q, i)), min);
        }

        while ((Head(*Q)!=Nil)&&(TIMEToMenit(Prio(InfoKepala(*Q))))<=0){
            Del(Q, &X);
            Enqueue(S, (infotype) X);
            *n = 2;
        }
    }
}

void buy(listMakanan b, Queue *q){
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("=====================");
        printf("=        BUY        =");
        printf("=====================");
        printf("\n");
        printf("List Bahan Makanan:");
        printf("\n");
        for (int i = 0; i<=LASTIDX(b); i++){
            printf("    %d. ( ", i+1);
            DisplayWord(NAMA(MAKANAN(b, i)));
            TulisTIME1(PENGIRIMAN(MAKANAN(b, i)));
            printf(")\n");
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        // scanf("%d", &pilihan);
        STARTWORD1();
        WordToInt(&pilihan);

        if ((pilihan<0)||(pilihan>LASTIDX(b)+1)){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
        }else if(pilihan>0){
            printf("Berhasil memesan " );
            DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
            printf(", ");
            DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
            printf("akan diantar dalam ");
            TulisTIME1(PENGIRIMAN(MAKANAN(b, pilihan-1)));
            printf(".\n");
            AddQueue(q, (infotype) MAKANAN(b, pilihan-1));
        }else{
            break;
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////
void createListMakanan(listMakanan *l, int size)
    {
        CAPACITY(*l) = size;
        CONTENT(*l) = (Makanan *) malloc(size * sizeof(Makanan));
        LASTIDX(*l) = IDX_UNDEF;
    }

void createMakanan(listMakanan *l, listMakanan *BUY, listMakanan *FRY, listMakanan *BOIL, listMakanan *MIX, listMakanan *CHOP)
    {


        STARTWORDFILE("Config/makanan.txt");
        int size;
        WordToInt(&size);
        CAPACITY(*l) = size;
        createListMakanan(l, size);
        createListMakanan(BUY, size);
        createListMakanan(FRY, size);
        createListMakanan(BOIL, size);
        createListMakanan(MIX, size);
        createListMakanan(CHOP, size);
        for(int i = 0; i < size; i++){
            ADVNEWLINE1();
            int id;
            WordToInt(&id);
            ID(MAKANAN(*l, i)) = id;
            ADVNEWLINE2();
            Word nama = currentWord;
            NAMA(MAKANAN(*l, i)) = nama;
            ADVNEWLINE1();
            TIME kedaluarsa;
            BacaTIME(&kedaluarsa);
            KEDALUWARSA(MAKANAN(*l, i)) = kedaluarsa;
            ADVNEWLINE1();
            TIME pengiriman;
            BacaTIME(&pengiriman);
            PENGIRIMAN(MAKANAN(*l, i)) = pengiriman;
            ADVNEWLINE1();
            Word aksi = currentWord;
            AKSI(MAKANAN(*l, i)) = aksi;
            int aksii;
            WordToInt(&aksii);
            LASTIDX(*l)++;
            if (aksii == 2563){
                LASTIDX(*BUY)++;
                int indeks = LASTIDX(*BUY);
                ID(MAKANAN(*BUY, indeks)) = id;
                NAMA(MAKANAN(*BUY, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*BUY, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*BUY, indeks)) = pengiriman;
                AKSI(MAKANAN(*BUY, indeks)) = aksi;
            }
            else if (aksii == 2933){
                LASTIDX(*FRY)++;
                int indeks = LASTIDX(*FRY);
                ID(MAKANAN(*FRY, indeks)) = id;
                NAMA(MAKANAN(*FRY, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*FRY, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*FRY, indeks)) = pengiriman;
                AKSI(MAKANAN(*FRY, indeks)) = aksi;
            }
            else if (aksii == 24930){
                LASTIDX(*BOIL)++;
                int indeks = LASTIDX(*BOIL);
                ID(MAKANAN(*BOIL, indeks)) = id;
                NAMA(MAKANAN(*BOIL, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*BOIL, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*BOIL, indeks)) = pengiriman;
                AKSI(MAKANAN(*BOIL, indeks)) = aksi;
            }
            else if (aksii == 3542){
                LASTIDX(*MIX)++;
                int indeks = LASTIDX(*MIX);
                ID(MAKANAN(*MIX, indeks)) = id;
                NAMA(MAKANAN(*MIX, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*MIX, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*MIX, indeks)) = pengiriman;
                AKSI(MAKANAN(*MIX, indeks)) = aksi;
            }
            else if (aksii == 25294){
                LASTIDX(*CHOP)++;
                int indeks = LASTIDX(*CHOP);
                ID(MAKANAN(*CHOP, indeks)) = id;
                NAMA(MAKANAN(*CHOP, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*CHOP, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*CHOP, indeks)) = pengiriman;
                AKSI(MAKANAN(*CHOP, indeks)) = aksi;
            }
        }
    }


void catalog(listMakanan l){
    if (LASTIDX(l)==IDX_UNDEF){
        printf("Tidak ada makanan kategori ini.\n");
    }else{
        printf("List Makanan ");
        printf("\n");
        printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
        for (int i = 0; i<=LASTIDX(l); i++){
            printf("%d. ", i+1);
            DisplayWord(NAMA(MAKANAN(l, i)));
            printf("- ");

            TulisTIME1(KEDALUWARSA(MAKANAN(l, i)));
            printf("- ");
            DisplayWord(AKSI(MAKANAN(l,i)));
            if((Hour(PENGIRIMAN(MAKANAN(l, i))) == 0) && (Minute(PENGIRIMAN(MAKANAN(l, i))) == 0)){
                // TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
                printf("- 0");
            } else {
                printf("- ");
                TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
            }
            printf("\n");
        }
    }
}

int searchMakanan(listMakanan l, int id){
    for (int i = 0; i<=LASTIDX(l); i++){
        if (ID(MAKANAN(l, i))==id){
            return i;
        }
    }
}


// void buy(listMakanan b, Queue *q){
//     int pilihan;

//     pilihan = -1;
//     while (pilihan!=0){
//         printf("=====================");
//         printf("=        BUY        =");
//         printf("=====================");
//         printf("\n");
//         printf("List Bahan Makanan:");
//         printf("\n");
//         for (int i = 0; i<=LASTIDX(b); i++){
//             printf("    %d. ( ", i+1);
//             DisplayWord(NAMA(MAKANAN(b, i)));
//             TulisTIME1(PENGIRIMAN(MAKANAN(b, i)));
//             printf(")\n");
//         }
//         printf("\nKetik 0 untuk exit\n");
//         printf("\nEnter Command: ");
//         scanf("%d", &pilihan);

//         if ((pilihan<0)||(pilihan>LASTIDX(b)+1)){
//             printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
//         }else if(pilihan>0){
//             printf("Berhasil memesan " );
//             DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
//             printf(", ");
//             DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
//             printf("akan diantar dalam ");
//             TulisTIME1(PENGIRIMAN(MAKANAN(b, pilihan-1)));
//             printf(".\n");
//             AddQueue(q, (infotype) MAKANAN(b, pilihan-1));
//         }
//     }
// }

void fry(listMakanan l, listMakanan f, Simulator *S, ListOfTree t){
    PrioQueueTime child;
    boolean available;
    int pilihan;
    node** childMakanan;
    infotype Mak;

    pilihan = -1;
    while (pilihan!=0){
        printf("=====================");
        printf("=        FRY        =");
        printf("=====================");
        printf("\n");
        printf("List Bahan Makanan yang Bisa Dibuat:");
        printf("\n");
        for (int i = 0; i<=LASTIDX(f); i++){
            printf("    %d. %s", i+1, NAMA(MAKANAN(f, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        STARTWORD1();
        WordToInt(&pilihan);
        if ((pilihan<0)||(pilihan>LASTIDX(f)+1)){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
        }else if(pilihan>0){
            //cari child MAKANAN(f, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true

            childMakanan = searchChild(ID(MAKANAN(f, pilihan-1)),t);

            //fungsi cek
            for(int i=0; i<banyakChild(ID(MAKANAN(f, pilihan-1)),t); i++){
                int id = IDD(childMakanan[i]);
                if(IsMember(Inventory(*S), id)){
                    available = true;
                }
                else{
                    available = false;
                    break;
                }
            }

            if (available){
                for(int i=0; i<banyakChild(ID(MAKANAN(f, pilihan-1)),t); i++){
                    DequeueID(&Inventory(*S), &Mak, IDD(childMakanan[i]));
                }
                DisplayWord(NAMA(MAKANAN(f, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.\n");
                Enqueue(S, (infotype) MAKANAN(f, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(f, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: \n");
                int nomor = 1;
                for(int i=0; i<banyakChild(ID(MAKANAN(f, pilihan-1)),t); i++){
                    int id = IDD(childMakanan[i]);
                    if(!IsMember(Inventory(*S), id)){
                        printf("%d. ", nomor);
                        DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
                        printf("\n");
                        nomor++;
                    }
                }
            }
        }
    }
}

void boil(listMakanan l, listMakanan b, Simulator *S, ListOfTree t){
    PrioQueueTime child;
    boolean available;
    int pilihan;
    node ** childMakanan;
    infotype Mak;

    pilihan = -1;
    while (pilihan!=0){
        printf("======================");
        printf("=        BOIL        =");
        printf("======================");
        printf("\n");
        printf("List Bahan Makanan yang Bisa Dibuat:\n");
        for (int i = 0; i<=LASTIDX(b); i++){
            printf("    %d.", i+1);
            DisplayWord(NAMA(MAKANAN(b, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        STARTWORD1();
        WordToInt(&pilihan);
        if ((pilihan<0)||(pilihan>LASTIDX(b)+1)){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
        }else if(pilihan>0){
            //cari child MAKANAN(b, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true

            childMakanan = searchChild(ID(MAKANAN(b, pilihan-1)),t);

            for(int i=0; i<banyakChild(ID(MAKANAN(b, pilihan-1)),t); i++){
                int id = IDD(childMakanan[i]);
                if(IsMember(Inventory(*S), id)){
                    available = true;
                }
                else{
                    available = false;
                    break;
                }
            }

            if (available){
                for(int i=0; i<banyakChild(ID(MAKANAN(b, pilihan-1)),t); i++){
                    DequeueID(&Inventory(*S), &Mak, IDD(childMakanan[i]));
                }
                DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.\n");
                Enqueue(S, (infotype) MAKANAN(b, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: \n");
                int nomor = 1;
                for(int i=0; i<banyakChild(ID(MAKANAN(b, pilihan-1)),t); i++){
                    int id = IDD(childMakanan[i]);
                    if(!IsMember(Inventory(*S), id)){
                        printf("%d. ", nomor);
                        DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
                        printf("\n");
                        nomor++;
                    }
                }
            }
        }
    }
}

void mix(listMakanan l, listMakanan m, Simulator *S, ListOfTree t){
    PrioQueueTime child;
    boolean available;
    int pilihan;
    node ** childMakanan;
    infotype Mak;

    pilihan = -1;
    while (pilihan!=0){
        printf("=======================");
        printf("=         MIX         =");
        printf("=======================");
        printf("\n");
        printf("List Bahan Makanan yang Bisa Dibuat:\n");
        for (int i = 0; i<=LASTIDX(m); i++){
            printf("    %d. ", i+1);
            DisplayWord(NAMA(MAKANAN(m, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        // scanf("%d", &pilihan);
        STARTWORD1();
        WordToInt(&pilihan);
        if ((pilihan<0)||(pilihan>LASTIDX(m)+1)){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
        }else if(pilihan>0){
            //cari child MAKANAN(m, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true

            childMakanan = searchChild(ID(MAKANAN(m, pilihan-1)),t);

            for(int i=0; i<banyakChild(ID(MAKANAN(m, pilihan-1)),t); i++){
                int id = IDD(childMakanan[i]);
                if(IsMember(Inventory(*S), id)){
                    available = true;
                }
                else{
                    available = false;
                    break;
                }
            }
            if (available){
                for(int i=0; i<banyakChild(ID(MAKANAN(m, pilihan-1)),t); i++){
                    DequeueID(&Inventory(*S), &Mak, IDD(childMakanan[i]));
                }
                DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.\n");
                Enqueue(S, (infotype) MAKANAN(m, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: \n");
                int nomor = 1;
                for(int i=0; i<banyakChild(ID(MAKANAN(m, pilihan-1)),t); i++){
                    int id = IDD(childMakanan[i]);
                    if(!IsMember(Inventory(*S), id)){
                        printf("%d. ", nomor);
                        DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
                        printf("\n");
                        nomor++;
                    }
                }
            }
        }
    }
}


void chop(listMakanan l, listMakanan c, Simulator *S, ListOfTree t){
    PrioQueueTime child;
    boolean available;
    int pilihan;
    node ** childMakanan;
    infotype Mak;

    pilihan = -1;
    while (pilihan!=0){
        printf("======================");
        printf("=        CHOP        =");
        printf("======================");
        printf("\n");
        printf("List Bahan Makanan yang Bisa Dibuat:\n");
        for (int i = 0; i<=LASTIDX(c); i++){
            printf("    %d. ", i+1);
            DisplayWord(NAMA(MAKANAN(c, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        STARTWORD1();
        WordToInt(&pilihan);
        if ((pilihan<0)||(pilihan>LASTIDX(c)+1)){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
        }else if(pilihan>0){
            //cari child MAKANAN(c, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true

            childMakanan = searchChild(ID(MAKANAN(c, pilihan-1)),t);

            for(int i=0; i<banyakChild(ID(MAKANAN(c, pilihan-1)),t); i++){
                int id = IDD(childMakanan[i]);
                if(IsMember(Inventory(*S), id)){
                    available = true;
                }
                else{
                    available = false;
                    break;
                }
            }

            if (available){
                for(int i=0; i<banyakChild(ID(MAKANAN(c, pilihan-1)),t); i++){
                    DequeueID(&Inventory(*S), &Mak, IDD(childMakanan[i]));
                }
                DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.\n");
                Enqueue(S, (infotype) MAKANAN(c, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: \n");
                int nomor = 1;
                for(int i=0; i<banyakChild(ID(MAKANAN(c, pilihan-1)),t); i++){
                    int id = IDD(childMakanan[i]);
                    if(!IsMember(Inventory(*S), id)){
                        printf("%d. ", nomor);
                        DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
                        printf("\n");
                        nomor++;
                    }
                }
            }
        }
    }
}