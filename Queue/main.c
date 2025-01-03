#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "create_queue.h"
#include "enqueue.h"
#include "dequeue.h"

int main()
{
    // Ifadeyi iceren karakter dizisi
    char prefix[50] = "- + * 9 + 2 8 * + 4 8 6 3";

    // strtok kullanarak ifadeyi parcala
    char* token = strtok(prefix, " ");

    // Kuyruk yapisini olustur
    QUEUE* myQueue = createQueue();

    // Ifadeyi kuyruga ekleyerek basla
    while (token != NULL)
    {
        enqueue(myQueue, token);
        token = strtok(NULL, " ");
    }

    // Kuyrugu yazdir
    printQueue(myQueue);
    printf("-----------------------------------\n");

    // Kuyrukta bir eleman kalana kadar islemleri tekrarla
    while (myQueue->counter != 1)
    {
        // Gecici bir kuyruk olustur
        QUEUE* tempQueue = createQueue();

        // Kuyruk elemanlarini kontrol et
        for (int i = 0; i < myQueue->counter; i++)
        {
            // Islem, sayi1 ve sayi2'yi al
            char* islem = myQueue->front->data;
            char* num1 = myQueue->front->next->data;
            char* num2 = myQueue->front->next->next->data;

            // Eger islem, sayi1 ve sayi2 sayisal ise
            if (isdigit(*num1) && isdigit(*num2) && !isdigit(*islem))
            {
                // Sayilari integer'a cevir ve sonucu hesapla
                int number1 = atoi(num1);
                int number2 = atoi(num2);
                int result;

                switch (*islem)
                {
                    case '+':
                        result = number1 + number2;
                        break;
                    case '-':
                        result = number1 - number2;
                        break;
                    case '*':
                        result = number1 * number2;
                        break;
                    case '/':
                        result = number1 / number2;
                        break;
                    default:
                        break;
                }

                // Sonucu string'e cevir ve gecici kuyruga ekle
                char* resultString = (char*)malloc(50 * sizeof(char));
                sprintf(resultString, "%d", result);

                enqueue(tempQueue, resultString);

                // Kullandigimiz elemanlari kuyruktan cikar
                dequeue(myQueue);
                dequeue(myQueue);
                dequeue(myQueue);

                break;
            }
            else
            {
                // Sayilar degilse veya islem degilse elemani gecici kuyruga ekle
                enqueue(tempQueue, myQueue->front->data);
                dequeue(myQueue);
            }
        }

        // Geri kalan elemanlari gecici kuyruga ekle
        for (int i = myQueue->counter; i >= 1; i--)
        {
            enqueue(tempQueue, myQueue->front->data);
            dequeue(myQueue);
        }

        // Ana kuyrugu güncelle
        myQueue = tempQueue;

        // Güncellenmis kuyrugu yazdir
        printQueue(myQueue);
        printf("-----------------------------------\n");
    }

    return 0;
}

// Kuyrugu yazdirmak icin yardimci fonksiyon
void printQueue(QUEUE* queue)
{
    NODE* current = queue->front;
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
