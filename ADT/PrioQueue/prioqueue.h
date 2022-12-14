// /* File : prioqueue.h */
// /* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
// /* Model Implementasi Versi III dengan circular buffer */
// /* Elemen queue terurut mengecil berdasarkan elemen prio */

// #ifndef prioqueue_H
// #define prioqueue_H

// #include "../Boolean/boolean.h"
// // #include "../Map/matrix.h"
// #include "../PrioQueue/prioqueuetime.h"
// #include "../Makanan/makanan.h"


// #define Nil 0
// /* Konstanta untuk mendefinisikan address tak terdefinisi */

// /* Definisi elemen dan address */
// typedef Makanan infotypeQueue;
// typedef int address;   /* indeks tabel */
// /* Contoh deklarasi variabel bertype Queue : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct { infotypeQueue T[100];   /* tabel penyimpan elemen */
//                  address HEAD;  /* alamat penghapusan */
//                  address TAIL;  /* alamat penambahan */
//                  int MaxEl;     /* Max elemen queue */
//                } Queue;
// /* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
// /* Catatan implementasi: T[0] tidak pernah dipakai */

// /* ********* AKSES (Selektor) ********* */
// /* Jika e adalah infotypeQueue dan Q adalah Queue, maka akses elemen : */
// #define Prio(e)     PENGIRIMAN(e)
// //#define Sabar(e)    (e).sabar /* Tambahan infotypeQueue */
// //#define Jumlah(e)   (e).jumlah /* Tambahan infotypeQueue */
// #define Kepala(Q)     (Q).HEAD
// #define Ekor(Q)     (Q).TAIL
// #define InfoKepala(Q) (Q).T[(Q).HEAD]
// #define InfoEkor(Q) (Q).T[(Q).TAIL]
// #define MaxElmt(Q)    (Q).MaxEl
// #define Elment(Q,i)   (Q).T[(i)]

// /* ********* Prototype ********* */
// boolean IsQueueEmpty (Queue Q);
// /* Mengirim true jika Q kosong: lihat definisi di atas */

// boolean IsQueueFull (Queue Q);
// /* Mengirim true jika tabel penampung elemen Q sudah penuh */
// /* yaitu mengandung elemen sebanyak MaxEl */

// int NBQueueElmt (Queue Q);
// /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

// /* *** Kreator *** */
// void CreateEmpty (Queue * Q, int Max);
// /* I.S. sembarang */
// /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
// /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
// /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
// /* Proses : Melakukan alokasi, membuat sebuah Q kosong */

// /* *** Destruktor *** */
// void DeAlokasiQueue(Queue * Q);
// /* Proses: Mengembalikan memori Q */
// /* I.S. Q pernah dialokasi */
// /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

// /* *** Primitif Add/Delete *** */
// void AddQueue (Queue * Q, infotypeQueue X);
// /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
// /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
// /* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
//         elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
// void Del (Queue * Q, infotypeQueue * X);
// /* Proses: Menghapus X pada Q dengan aturan FIFO */
// /* I.S. Q tidak mungkin kosong */
// /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
//         Q mungkin kosong */

// /* Operasi Tambahan */
// void showDeliveryQueue (Queue Q);
// /* Mencetak isi queue Q ke layar */
// /* I.S. Q terdefinisi, mungkin kosong */
// /* F.S. Q tercetak ke layar dengan format:
// <prio-1> <elemen-1>
// ...
// <prio-n> <elemen-n>
// #
// */

// void Delivery(Queue *Q, PrioQueueTime *inv);
// /* Masukin makanan ke inventory kalo delivery timenya udah 0*/

// void waitDelivery(Queue *Q, PrioQueueTime *inv, int min);

// #endif
