int deleteNode(LIST* liste, void* dataOutPtr)
{
    // Tum listeyi dolanmak icin tempNode adında NODE pointeri olarak bir degisken tanimlanmistir.
    NODE* tempNode = liste->head;

    while(tempNode != NULL)
    {
        // liste icerisindeki compare fonksiyonundan donen degeri tutar.
        int compare_result = liste->compare(dataOutPtr,tempNode->data);

        // Eger silinmek istenen dugum bulunmussa calisir.
        if(compare_result==0)
        {
            // tempNode'dan onceki dugumun next'i tempNode'dan sonraki dugumun adresini tutar.
            tempNode->prev->next = tempNode->next;
            // tempNode'dan sonraki dugumun prev'i tempNod'dan onceki dugumun adresini tutar.
            tempNode->next->prev = tempNode->prev;

            // tempNodun gosterdigi adres hafızadan silinir.
            free(tempNode);
            return 1;
        }

        // tempNode'a kendinden sonraki dugumun adresi gonderilir.
        tempNode = tempNode->next;
    }

    // Silinmek istenen data degeri listede yok ise geriye 0 degerini dondurur.
    return 0;

}
