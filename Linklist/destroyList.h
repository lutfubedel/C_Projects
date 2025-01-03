void destroyList(LIST* liste)
{
    if(liste)
    {
        // Tum listeyi dolanmak icin tempNode adında NODE pointeri olarak bir degisken tanimlanmistir.
        NODE* tempNode = liste->head;
        NODE* next;

        while(tempNode)
        {
            // tempNode'dan sonraki dugumun adresini next Noduna verilir.
            next = tempNode->next;
            // tempNode'un tuttugu adresi hafızadan silinir.
            free(tempNode);
            // tempNode'a next değiskeninin tuttugu adres verilir.
            tempNode = next;
        }

        liste = NULL;

        // liste hafizadan silinir
        free(liste);
    }
}
