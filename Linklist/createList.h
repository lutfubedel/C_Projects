// Olusturulacak her bir nodun sahip olacagi ozellikleri bulunduran struct
typedef struct node
{
    void* data;
    struct node* next;
    struct node* prev;
}NODE;


// Liste icerisinde kolayca islem yapmamizi saglayan degiskenler ve fonksiyonlar bulunduran struct.
typedef struct
{
    // Listenin ilk dugumunun adresini tutan degisken.
    NODE* head;
    // Listedeki elemanlari karsilastiran fonksiyon.
    int (*compare)(void* arg1, void* arg2);
}LIST;

LIST* createList(int (*compare)(void* arg1, void* arg2))
{
    // Hafizada liste icin yer ayririr.
    LIST* liste = (LIST*)malloc(sizeof(LIST));
    if(liste)
    {
        // Baslangicda liste bos oldugu icin head degiskeni NULL a esitler.
        liste->head=NULL;
        // Liste icersindeki compare fonksiyonunu kullanicinin parametre olarak verecegi fonksiyona esitler.
        liste->compare = compare;
    }

    // Olusturulan liste geri dondurulur.
    return liste;
}


