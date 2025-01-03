bool enqueue(QUEUE* queue, void* dataPtr)
{
    // Yeni bir NODE yapisi icin bellek tahsisi yapilir.
    NODE* newPtr = (NODE*)malloc(sizeof(NODE));

    // Bellek tahsisi basarisiz olduysa, false degeri dondurulur.
    if (!newPtr)
    {
        return false;
    }

    // Yeni NODE yapisinin veri alanina veri isaretcisi atanir.
    newPtr->data = dataPtr;

    // Yeni NODE yapisinin next alani NULL olarak ayarlanir.
    newPtr->next = NULL;

    // Eger kuyruk bossa, yeni NODE on uc (front) olarak atanir.
    if (queue->counter == 0)
    {
        queue->front = newPtr;
    }
    else
    {
        // Kuyruk bos degilse, yeni NODE rear'in next'ine atanir.
        queue->rear->next = newPtr;
    }

    // Kuyruktaki eleman sayisi arttirilir.
    (queue->counter)++;

    // Yeni NODE rear olarak atanir.
    queue->rear = newPtr;

    // Islem basariyla tamamlandi, true degeri dondurulur.
    return true;
}
