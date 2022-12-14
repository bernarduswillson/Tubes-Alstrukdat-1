/* File : queue.h */
/* Definisi ADT QueueN versi 3 dengan representasi array secara eksplisit dan alokasi statik */

#ifndef NOTIF_H
#define NOTIF_H

#include "../Boolean/boolean.h"

#define IDX_UNDEF -1
#define NOTIFCAP 100

/* Definisi elemen dan address */
typedef int ElTypeN;
typedef struct {
	ElTypeN buffer[NOTIFCAP]; 
	int idxHead;
	int idxTail;
} QueueN;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueN, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(QueueN *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(QueueN q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(QueueN q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(QueueN q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(QueueN *q, ElTypeN val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(QueueN *q, ElTypeN *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueN *** */
void displayNotif(QueueN q);
/* Proses : Menuliskan isi QueueN dengan traversal, QueueN ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueN kosong : menulis [] */


#endif