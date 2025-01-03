int searchNode(LIST* liste, void* data)
{
    // Tum listeyi dolanmak icin tempNode adında NODE pointeri olarak bir degisken tanimlanmistir.
    NODE* tempNode = liste->head;

    while(tempNode != NULL)
    {
        // liste icerisindeki compare fonksiyonundan donen degeri tutar.
        int compare_result = liste->compare(data,tempNode->data);

        // Eger compare fonksiyonundan donen deger 0 ise yani data pointeri ile tempNode'un gosterdigi deger ayni ise geriye 1 dondurur.
        if(compare_result==0)
        {
            return 1;
        }

        // tempNode'a kendinden sonraki dugumun adresi gonderilir.
        tempNode = tempNode->next;
    }

    // Aranan data degeri listede yok ise geriye 0 degerini dondurur.
    return 0;

}
