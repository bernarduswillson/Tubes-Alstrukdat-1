// #include <stdio.h>
// #include <stdlib.h>
// #include "makanan.h"
// #include "../PrioQueue/prioqueuetime.h"
// #include "../Tree/tree.h"
// // #include "../Tree/tree.c"
// // #include "../Mesin_Kata/wordmachine.c"
// // #include "../Mesin_Karakter/charmachine.c"


// void createListMakanan(listMakanan *l, int size)
//     {
//         CAPACITY(*l) = size;
//         CONTENT(*l) = (Makanan *) malloc(size * sizeof(Makanan));
//         LASTIDX(*l) = IDX_UNDEF;
//     }

// void createMakanan(listMakanan *l, listMakanan *BUY, listMakanan *FRY, listMakanan *BOIL, listMakanan *MIX, listMakanan *CHOP)
//     {


//         STARTWORDFILE("../../Config/makanan.txt");
//         int size;
//         WordToInt(&size);
//         CAPACITY(*l) = size;
//         createListMakanan(l, size);
//         createListMakanan(BUY, size);
//         createListMakanan(FRY, size);
//         createListMakanan(BOIL, size);
//         createListMakanan(MIX, size);
//         createListMakanan(CHOP, size);
//         for(int i = 0; i < size; i++){
//             ADVNEWLINE1();
//             int id;
//             WordToInt(&id);
//             ID(MAKANAN(*l, i)) = id;
//             ADVNEWLINE2();
//             Word nama = currentWord;
//             NAMA(MAKANAN(*l, i)) = nama;
//             ADVNEWLINE1();
//             TIME kedaluarsa;
//             BacaTIME(&kedaluarsa);
//             KEDALUWARSA(MAKANAN(*l, i)) = kedaluarsa;
//             ADVNEWLINE1();
//             TIME pengiriman;
//             BacaTIME(&pengiriman);
//             PENGIRIMAN(MAKANAN(*l, i)) = pengiriman;
//             ADVNEWLINE1();
//             Word aksi = currentWord;
//             AKSI(MAKANAN(*l, i)) = aksi;
//             int aksii;
//             WordToInt(&aksii);
//             LASTIDX(*l)++;
//             if (aksii == 2563){
//                 LASTIDX(*BUY)++;
//                 int indeks = LASTIDX(*BUY);
//                 ID(MAKANAN(*BUY, indeks)) = id;
//                 NAMA(MAKANAN(*BUY, indeks)) = nama;
//                 KEDALUWARSA(MAKANAN(*BUY, indeks)) = kedaluarsa;
//                 PENGIRIMAN(MAKANAN(*BUY, indeks)) = pengiriman;
//                 AKSI(MAKANAN(*BUY, indeks)) = aksi;
//             }
//             else if (aksii == 2933){
//                 LASTIDX(*FRY)++;
//                 int indeks = LASTIDX(*FRY);
//                 ID(MAKANAN(*FRY, indeks)) = id;
//                 NAMA(MAKANAN(*FRY, indeks)) = nama;
//                 KEDALUWARSA(MAKANAN(*FRY, indeks)) = kedaluarsa;
//                 PENGIRIMAN(MAKANAN(*FRY, indeks)) = pengiriman;
//                 AKSI(MAKANAN(*FRY, indeks)) = aksi;
//             }
//             else if (aksii == 24930){
//                 LASTIDX(*BOIL)++;
//                 int indeks = LASTIDX(*BOIL);
//                 ID(MAKANAN(*BOIL, indeks)) = id;
//                 NAMA(MAKANAN(*BOIL, indeks)) = nama;
//                 KEDALUWARSA(MAKANAN(*BOIL, indeks)) = kedaluarsa;
//                 PENGIRIMAN(MAKANAN(*BOIL, indeks)) = pengiriman;
//                 AKSI(MAKANAN(*BOIL, indeks)) = aksi;
//             }
//             else if (aksii == 3542){
//                 LASTIDX(*MIX)++;
//                 int indeks = LASTIDX(*MIX);
//                 ID(MAKANAN(*MIX, indeks)) = id;
//                 NAMA(MAKANAN(*MIX, indeks)) = nama;
//                 KEDALUWARSA(MAKANAN(*MIX, indeks)) = kedaluarsa;
//                 PENGIRIMAN(MAKANAN(*MIX, indeks)) = pengiriman;
//                 AKSI(MAKANAN(*MIX, indeks)) = aksi;
//             }
//             else if (aksii == 25294){
//                 LASTIDX(*CHOP)++;
//                 int indeks = LASTIDX(*CHOP);
//                 ID(MAKANAN(*CHOP, indeks)) = id;
//                 NAMA(MAKANAN(*CHOP, indeks)) = nama;
//                 KEDALUWARSA(MAKANAN(*CHOP, indeks)) = kedaluarsa;
//                 PENGIRIMAN(MAKANAN(*CHOP, indeks)) = pengiriman;
//                 AKSI(MAKANAN(*CHOP, indeks)) = aksi;
//             }
//         }
//     }


// void catalog(listMakanan l){
//     if (LASTIDX(l)==IDX_UNDEF){
//         printf("Tidak ada makanan kategori ini.\n");
//     }else{
//         printf("List Makanan ");
//         printf("\n");
//         printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
//         for (int i = 0; i<=LASTIDX(l); i++){
//             printf("%d. ", i+1);
//             DisplayWord(NAMA(MAKANAN(l, i)));
//             printf("- ");

//             TulisTIME1(KEDALUWARSA(MAKANAN(l, i)));
//             printf("- ");
//             DisplayWord(AKSI(MAKANAN(l,i)));
//             if((Hour(PENGIRIMAN(MAKANAN(l, i))) == 0) && (Minute(PENGIRIMAN(MAKANAN(l, i))) == 0)){
//                 // TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
//                 printf("- 0");
//             } else {
//                 printf("- ");
//                 TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
//             }
//             printf("\n");
//         }
//     }
// }

// int searchMakanan(listMakanan l, int id){
//     for (int i = 0; i<=LASTIDX(l); i++){
//         if (ID(MAKANAN(l, i))==id){
//             return i;
//         }
//     }
// }


// // void buy(listMakanan b, Queue *q){
// //     int pilihan;

// //     pilihan = -1;
// //     while (pilihan!=0){
// //         printf("=====================");
// //         printf("=        BUY        =");
// //         printf("=====================");
// //         printf("\n");
// //         printf("List Bahan Makanan:");
// //         printf("\n");
// //         for (int i = 0; i<=LASTIDX(b); i++){
// //             printf("    %d. ( ", i+1);
// //             DisplayWord(NAMA(MAKANAN(b, i)));
// //             TulisTIME1(PENGIRIMAN(MAKANAN(b, i)));
// //             printf(")\n");
// //         }
// //         printf("\nKetik 0 untuk exit\n");
// //         printf("\nEnter Command: ");
// //         scanf("%d", &pilihan);

// //         if ((pilihan<0)||(pilihan>LASTIDX(b)+1)){
// //             printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
// //         }else if(pilihan>0){
// //             printf("Berhasil memesan " );
// //             DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
// //             printf(", ");
// //             DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
// //             printf("akan diantar dalam ");
// //             TulisTIME1(PENGIRIMAN(MAKANAN(b, pilihan-1)));
// //             printf(".\n");
// //             AddQueue(q, (infotypeQueue) MAKANAN(b, pilihan-1));
// //         }
// //     }
// // }

// void fry(listMakanan l, listMakanan f, PrioQueueTime *inv, ListOfTree t){
//     PrioQueueTime child;
//     boolean available;
//     int pilihan;
//     node** childMakanan;
    

//     pilihan = -1;
//     while (pilihan!=0){
//         printf("=====================");
//         printf("=        FRY        =");
//         printf("=====================");
//         printf("\n");
//         printf("List Bahan Makanan yang Bisa Dibuat:");
//         printf("\n");
//         for (int i = 0; i<=LASTIDX(f); i++){
//             printf("    %d. %s", i+1, NAMA(MAKANAN(f, i)));
//         }
//         printf("\nKetik 0 untuk exit\n");
//         printf("\nEnter Command: ");
//         scanf("%d", &pilihan);
//         if ((pilihan<0)||(pilihan>LASTIDX(f)+1)){
//             printf("Pilih dari list makanan atau pilih 0 untuk exit.\n");
//         }else if(pilihan>0){
//             //cari child MAKANAN(f, pilihan-1) dari resep, masukin ke listMakanan child
//             //cek semua makanan di child ada di inventory atau ngga
//             //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
//             //kalau setelah di cek, childnya kosong, berarti available = true

//             childMakanan = searchChild(ID(MAKANAN(f, pilihan-1)),t);

//             //fungsi cek
//             for(int i=0; i<banyakChild(ID(MAKANAN(f, pilihan-1)),t); i++){
//                 int id = IDD(childMakanan[i]);
//                 if(IsMember(*inv, id)){
//                     available = true;
//                 }
//                 else{
//                     available = false;
//                     break;
//                 }
//             }

//             if (available){
//                 DisplayWord(NAMA(MAKANAN(f, pilihan-1)));
//                 printf(" selesai dibuat dan sudah masuk ke inventory.\n");
//                 Enqueue(inv, (infotype) MAKANAN(f, pilihan-1));
//             }else{
//                 printf("Gagal membuat ");
//                 DisplayWord(NAMA(MAKANAN(f, pilihan-1)));
//                 printf("karena kamu tidak memiliki bahan berikut: \n");
//                 int nomor = 1;
//                 for(int i=0; i<banyakChild(ID(MAKANAN(f, pilihan-1)),t); i++){
//                     int id = IDD(childMakanan[i]);
//                     if(!IsMember(*inv, id)){
//                         printf("%d. ", nomor);
//                         DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
//                         printf("\n");
//                         nomor++;
//                     }
//                 }
//             }
//         }
//     }
// }

// void boil(listMakanan l, listMakanan b, PrioQueueTime *inv, ListOfTree t){
//     PrioQueueTime child;
//     boolean available;
//     int pilihan;
//     node ** childMakanan;

//     pilihan = -1;
//     while (pilihan!=0){
//         printf("======================");
//         printf("=        BOIL        =");
//         printf("======================");
//         printf("\n");
//         printf("List Bahan Makanan yang Bisa Dibuat:\n");
//         for (int i = 0; i<=LASTIDX(b); i++){
//             printf("    %d.", i+1);
//             DisplayWord(NAMA(MAKANAN(b, i)));
//         }
//         printf("\nKetik 0 untuk exit\n");
//         printf("\nEnter Command: ");
//         scanf("%d", &pilihan);
//         if ((pilihan<0)||(pilihan>LASTIDX(b)+1)){
//             printf("Pilih dari list makanan atau pilih 0 untuk exit.");
//         }else if(pilihan>0){
//             //cari child MAKANAN(b, pilihan-1) dari resep, masukin ke listMakanan child
//             //cek semua makanan di child ada di inventory atau ngga
//             //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
//             //kalau setelah di cek, childnya kosong, berarti available = true

//             childMakanan = searchChild(ID(MAKANAN(b, pilihan-1)),t);

//             for(int i=0; i<banyakChild(ID(MAKANAN(b, pilihan-1)),t); i++){
//                 int id = IDD(childMakanan[i]);
//                 if(IsMember(*inv, id)){
//                     available = true;
//                 }
//                 else{
//                     available = false;
//                     break;
//                 }
//             }

//             if (available){
//                 DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
//                 printf(" selesai dibuat dan sudah masuk ke inventory.");
//                 Enqueue(inv, (infotype) MAKANAN(b, pilihan-1));
//             }else{
//                 printf("Gagal membuat ");
//                 DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
//                 printf("karena kamu tidak memiliki bahan berikut: \n");
//                 int nomor = 1;
//                 for(int i=0; i<banyakChild(ID(MAKANAN(b, pilihan-1)),t); i++){
//                     int id = IDD(childMakanan[i]);
//                     if(!IsMember(*inv, id)){
//                         printf("%d. ", nomor);
//                         DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
//                         printf("\n");
//                         nomor++;
//                     }
//                 }
//             }
//         }
//     }
// }

// void mix(listMakanan l, listMakanan m, PrioQueueTime *inv, ListOfTree t){
//     PrioQueueTime child;
//     boolean available;
//     int pilihan;
//     node ** childMakanan;

//     pilihan = -1;
//     while (pilihan!=0){
//         printf("=======================");
//         printf("=         MIX         =");
//         printf("=======================");
//         printf("\n");
//         printf("List Bahan Makanan yang Bisa Dibuat:\n");
//         for (int i = 0; i<=LASTIDX(m); i++){
//             printf("    %d. ", i+1);
//             DisplayWord(NAMA(MAKANAN(m, i)));
//         }
//         printf("\nKetik 0 untuk exit\n");
//         printf("\nEnter Command: ");
//         scanf("%d", &pilihan);
//         if ((pilihan<0)||(pilihan>LASTIDX(m)+1)){
//             printf("Pilih dari list makanan atau pilih 0 untuk exit.");
//         }else if(pilihan>0){
//             //cari child MAKANAN(m, pilihan-1) dari resep, masukin ke listMakanan child
//             //cek semua makanan di child ada di inventory atau ngga
//             //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
//             //kalau setelah di cek, childnya kosong, berarti available = true

//             childMakanan = searchChild(ID(MAKANAN(m, pilihan-1)),t);

//             for(int i=0; i<banyakChild(ID(MAKANAN(m, pilihan-1)),t); i++){
//                 int id = IDD(childMakanan[i]);
//                 if(IsMember(*inv, id)){
//                     available = true;
//                 }
//                 else{
//                     available = false;
//                     break;
//                 }
//             }
//             if (available){
//                 DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
//                 printf(" selesai dibuat dan sudah masuk ke inventory.");
//                 Enqueue(inv, (infotype) MAKANAN(m, pilihan-1));
//             }else{
//                 printf("Gagal membuat ");
//                 DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
//                 printf("karena kamu tidak memiliki bahan berikut: \n");
//                 int nomor = 1;
//                 for(int i=0; i<banyakChild(ID(MAKANAN(m, pilihan-1)),t); i++){
//                     int id = IDD(childMakanan[i]);
//                     if(!IsMember(*inv, id)){
//                         printf("%d. ", nomor);
//                         DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
//                         printf("\n");
//                         nomor++;
//                     }
//                 }
//             }
//         }
//     }
// }


// void chop(listMakanan l, listMakanan c, PrioQueueTime *inv, ListOfTree t){
//     PrioQueueTime child;
//     boolean available;
//     int pilihan;
//     node ** childMakanan;

//     pilihan = -1;
//     while (pilihan!=0){
//         printf("======================");
//         printf("=        CHOP        =");
//         printf("======================");
//         printf("\n");
//         printf("List Bahan Makanan yang Bisa Dibuat:");
//         for (int i = 0; i<=LASTIDX(c); i++){
//             printf("    %d. ", i+1);
//             DisplayWord(NAMA(MAKANAN(c, i)));
//         }
//         printf("\nKetik 0 untuk exit\n");
//         printf("\nEnter Command: ");
//         scanf("%d", &pilihan);
//         if ((pilihan<0)||(pilihan>LASTIDX(c)+1)){
//             printf("Pilih dari list makanan atau pilih 0 untuk exit.");
//         }else if(pilihan>0){
//             //cari child MAKANAN(c, pilihan-1) dari resep, masukin ke listMakanan child
//             //cek semua makanan di child ada di inventory atau ngga
//             //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
//             //kalau setelah di cek, childnya kosong, berarti available = true

//             childMakanan = searchChild(ID(MAKANAN(c, pilihan-1)),t);

//             for(int i=0; i<banyakChild(ID(MAKANAN(c, pilihan-1)),t); i++){
//                 int id = IDD(childMakanan[i]);
//                 if(IsMember(*inv, id)){
//                     available = true;
//                 }
//                 else{
//                     available = false;
//                     break;
//                 }
//             }

//             if (available){
//                 DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
//                 printf(" selesai dibuat dan sudah masuk ke inventory.");
//                 Enqueue(inv, (infotype) MAKANAN(c, pilihan-1));
//             }else{
//                 printf("Gagal membuat ");
//                 DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
//                 printf("karena kamu tidak memiliki bahan berikut: ");
//                 int nomor = 1;
//                 for(int i=0; i<banyakChild(ID(MAKANAN(c, pilihan-1)),t); i++){
//                     int id = IDD(childMakanan[i]);
//                     if(!IsMember(*inv, id)){
//                         printf("%d. ", nomor);
//                         DisplayWord(NAMA(MAKANAN(l, searchMakanan(l, id))));
//                         printf("\n");
//                         nomor++;
//                     }
//                 }
//             }
//         }
//     }
// }