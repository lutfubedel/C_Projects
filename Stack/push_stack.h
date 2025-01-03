int pushStack(Stack* stack, void* dataInPtr)
{
    // Eklemek istedigimiz veri icin node olusturulur.
    NODE* newNode;
    newNode = (NODE*)malloc(sizeof(NODE));

    if(!newNode)
    {
        return 0;
    }

    //newNode un datasına eklemek istedigimiz datayi atariz.
    newNode->data = dataInPtr;
    //newNode un linkini stack'in topunu tutacak sekilde ayarlanir.
    newNode->link = stack->top;

    // yeni nodu stack'in top'u olarak atar.
    stack->top = newNode;
    stack->counter++;

    return 1;


}
