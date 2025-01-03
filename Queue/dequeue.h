bool dequeue(QUEUE* queue)
{
    NODE* tempNode;

    // Kuyruk bos ise islem yapilmaz, false dondurulur.
    if(queue->counter == 0)
    {
        return false;
    }

    // Kuyruktan cikarilacak dugum gecici bir degiskende saklanir.
    tempNode = queue->front;

    // Kuyrukta sadece bir eleman varsa, front ve rear sifirlanir.
    if(queue->counter == 1)
    {
        queue->rear = queue->front = NULL;
    }
    else
    {
        // Kuyrukta birden fazla eleman varsa, front bir sonraki elemana guncellenir.
        queue->front = queue->front->next;
    }

    // Kuyruk eleman sayisi azaltilir ve gecici dugum bellekten serbest birakilir.
    (queue->counter)--;
    free(tempNode);

    // Ýslem basariyla gerceklestigi icin true dondurulur.
    return true;
}
