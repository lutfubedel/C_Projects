int popStack(Stack* stack)
{
    void* dataOutPtr;
    NODE* tempNode;

    if((stack->counter == 0))
    {
        printf("X");
        return 0;
    }
    else
    {
        // tempNode 'a stack'in top'u atanir.
        tempNode = stack->top;
        // silinecek node'un verisi tutulur.
        dataOutPtr = stack->top->data;
        // Stack'in top'u bir altindaki elemana guncellenir.
        stack->top = stack->top->link;

        // tempNode bellekten serbest birakilir ve counter bir azaltilir.
        free(tempNode);
        (stack->counter)--;

        return 1;
    }


}
