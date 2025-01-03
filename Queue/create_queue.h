
// NODE yapisi, bagli listelerde her bir dugumu temsil eder.
typedef struct node
{
    void* data;          // Dugumun veri alani
    struct node* next;   // Bir sonraki dugume isaret eden pointer
} NODE;

typedef struct
{
    NODE* front;     // Kuyrugun önundeki (front) dugumu isaret eden pointer
    NODE* rear;      // Kuyrugun sonundaki (rear) dugumu isaret eden pointer
    int counter;      // Kuyruktaki eleman sayisini tutan sayac.
} QUEUE;

// Yen bir kuyruk olusturan fonksiyon
QUEUE* createQueue()
{
    // Bellekten QUEUE yapisi icin yer ayir
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));

    // Bellek ayirma islem basariliysa calisir.
    if(queue)
    {
        // Kuyrugun basi ve sonu baslangicta bos oldugu icin NULL'a ayarlanir
        queue->front = NULL;
        queue->rear = NULL;

        // Kuyruktaki eleman sayisini sifirla
        queue->counter = 0;
    }

    // Olusturulan kuyrugun ponter'ini geri döndur
    return queue;
}
