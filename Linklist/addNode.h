int addNode(LIST* liste, void* dataInPtr)
{
    // Eklenecek düğüm için bellekten yer ayrılır.
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    // Hafizada yeterli yer yok ise hata mesaji yazdirir.
    if (newNode == NULL)
    {
        printf("Hafiza hatasi\n");
        return -1;
    }

    // Yeni eklenecek dugumun datası dataInPtr ye esitlenir.
    newNode->data = dataInPtr;
    // Yeni nodun next ve prev parametreleri 
    newNode->next = NULL;
    newNode->prev = NULL;

    // Liste boşsa yeni düğüm head olarak atanır.
    if (liste->head == NULL)
    {
        liste->head = newNode;
        return 0;
    }

    // Liste boş değilse, listenin icinde gezinmek icin tempNode adında NODE pointeri tanımlanır.
    NODE* tempNode = liste->head;

    while (tempNode->next != NULL)
    {
        // liste icerisindeki compare fonksiyonundan donen degeri tutar.
        int compare_results = liste->compare(dataInPtr, tempNode->data);

        // Eğer yeni dugumun verisi, mevcut dugumun verisinden kucukse, yeni dugumu tempNodu'un gosterdigi düğümün önüne ekler.
        if (compare_results == -1)
        {
            // newNodun prev'i tempNodu'dan oceki nodu gosterir.
            newNode->prev = tempNode->prev;
            // newNodun next'i tempNodun kendisini gosterir.
            newNode->next = tempNode;
            // tempNodun previ newNodu gosterir.
            tempNode->prev = newNode;

            // Eger eklenen node'dan once baska bir node varsa o nodun next'i de newNodu gosterecek sekilde ayarlanır.
            if (newNode->prev != NULL)
            {
                newNode->prev->next = newNode;
            }
                
            // Eger eklenen node'dan once baska node yok ise newNode head olarak tanimlanir. 
            else
                liste->head = newNode;

            return 0;
        }
        // Eğer yeni dugumun verisi, mevcut dugumun verisinden kucuk degilse tempNode kendisinden sonraki dugumun adresini tutacak sekilde guncellenir.
        else
        {
            tempNode = tempNode->next;
        }
    }

    // Eğer yeni düğümün verisi en büyükse, sona eklenir.
    if (tempNode->prev != NULL && liste->compare(dataInPtr, tempNode->prev->data) == -1)
    {
        // newNodun prev'i tempNode'dan onceki dugumu gosterir.
        newNode->prev = tempNode->prev;
        // newNodun next'i tempNodun kendisini gosterir.
        newNode->next = tempNode;
        // tempNodun prev'i ise newNodu gosterecek sekilde ayarlanir.
        tempNode->prev = newNode;

        // Eger eklenen node'dan once baska bir node varsa o nodun next'i de newNodu gosterecek sekilde ayarlanır.
        if (newNode->prev != NULL)
        {
            newNode->prev->next = newNode;
        }
            
        // Eger eklenen node'dan once baska node yok ise newNode head olarak tanimlanir. 
        else
        {
            liste->head = newNode;
        }
            
        return 0;
    }
    // Eğer yeni dugumun verisi en küçükse, basa eklenir.
    else
    {
        newNode->prev = tempNode;
        tempNode->next = newNode;

        return 1;
    }
}
