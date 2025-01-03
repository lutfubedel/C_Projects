#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "createList.h"
#include "addNode.h"
#include "deleteNode.h"
#include "destroyList.h"
#include "searchNode.h"


// Ogrenc structi
typedef struct student
{
    char name[50];
    char surname[50];
    char department[50];
    int grade;
    int studentNo;
}Student;


int compare(void* a, void* b)
{
    // void degiskenler Student structi olarak castlanir.
    Student* student1 = (Student*)a;
    Student* student2 = (Student*)b;

    // Degiskenler arasindaki karsilastirmalar.
    if (student1->studentNo > student2->studentNo)
        return 1;
    else if (student1->studentNo < student2->studentNo)
        return -1;
    else if(student1->studentNo == student2->studentNo)
        return 0;
    else
        return -2;
}



int main()
{
    // Menu
    printf("Ogrenci Bilgi Islem\n--------------------------\n");
    printf("1-Ogrenci Listesi Olustur\n2-Ogrenci Ekle\n3-Ogrenci Sil\n4-Ogrenci Bul\n5-Ogrenci Listesini Sil\n6-Ogrenci Listesini Yazdir\n7-Cikis\n");
    printf("--------------------------\n");

    // MEnu kontrol degiskenleri
    int secim;
    bool cikis=false;

    // Kullanicagimiz liste
    LIST* myList;

    while(!cikis)
    {
        printf("Islem : ");
        scanf("%d",&secim);

        // Liste olusturur.
        if(secim==1)
        {
            myList=createList(compare);
            printf("Ogrenci listesi olusturuldu\n--------------------------\n");
        }
        // Listeye yeni ogrenci ekler.
        else if(secim==2)
        {
            // Student turunde yeni bir degisken tanimlanir.
            Student student_add;

            printf("Ogrenci ismi    : ");
            scanf("%s",student_add.name);

            printf("Ogrenci soyadi  : ");
            scanf("%s",student_add.surname);

            printf("Ogrenci bolum   : ");
            scanf("%s",student_add.department);

            printf("Ogrenci sinifi  : ");
            scanf(" %d",&student_add.grade);

            printf("Ogrenci No      : ");
            scanf("%d",&student_add.studentNo);

            // Tanimlanan Student degiskeni icin hafızada yer acilir.
            Student *newStudent = (Student*)malloc(sizeof(Student));
            *newStudent = student_add;

            // addNode fonksiyonu cagirilarak yeni ogrenci eklenir.
            addNode(myList,newStudent);
            printf("Ogrenci eklendi\n--------------------------\n");
        }
        
        // Listeden ogrenci siler.
        else if(secim==3)
        {
            // Student turunde yeni bir degisken tanimlanir.
            Student student_delete;

            // Kullanicidan silinmesi istenen ogrencinin nosu alinir.
            printf("Silinecek ogrenci no : ");
            scanf("%d",&student_delete.studentNo);

            // Tanimlanan Student degiskeni icin hafızada yer acilir.
            Student *oldStudent = (Student*)malloc(sizeof(Student));
            *oldStudent = student_delete;

            // deleteNode fonksiyonu cagirilarak istenilen ogrenci silinir.
            if(deleteNode(myList,oldStudent)==1)
                printf("%d nolu ogrenci silindi\n--------------------------\n",student_delete.studentNo);
            else
                printf("%d nolu ogrenci bulunamadi\n--------------------------\n",student_delete.studentNo);

        }

        // Listeden ogreci siler.
        else if(secim==4)
        {
            // Student turunde yeni bir degisken tanimlanir.
            Student student_search;

            // Kullanicidan silinmesi istenen ogrencinin nosu alinir.
            printf("Aranan ogrenci no : ");
            scanf("%d",&student_search.studentNo);

            // Tanimlanan Student degiskeni icin hafızada yer acilir.
            Student *findStudent = (Student*)malloc(sizeof(Student));
            *findStudent = student_search;

            // Ogrencinin tum bilgileri konsola yazdirilir.
            if(searchNode(myList,findStudent)==1)
            {
                printf("%d nolu ogrenci : \n",student_search.studentNo);

                printf("Name: %s\n", findStudent->name);
                printf("Surname: %s\n", findStudent->surname);
                printf("Department: %s\n", findStudent->department);
                printf("Grade: %d\n", findStudent->grade);
                printf("Student No: %d\n", findStudent->studentNo);
                printf("--------------------------\n");
            }
            else
                printf("%d nolu ogrenci bulunamadi\n--------------------------\n",student_search.studentNo);

        }
        // Listeyi tamamen siler.
        else if(secim==5)
        {
            destroyList(myList);
            printf("Ogrenci listeniz silindi\n--------------------------\n");
        }
        // Listeyi ekrana yazdirir.
        else if(secim==6)
        {
            displayList(myList);
            printf("\n--------------------------\n");
        }
        // Programdan cikar.
        else if(secim==7)
        {
            printf("Cikis yapildi\n--------------------------\n");
            return;
        }
        // Farkli bir komut girildigi zaman uyarı verir.
        else
        {
            printf("Gecersiz komut\n--------------------------\n");
        }
    }

    return 0;
}

// Listeyi ekrana yazdirir.
void displayList(LIST* liste)
{
    if(liste)
    {
        // Listenin head degeri head ismindeki NODE pointerine verilir.
        NODE* head = liste->head;
        // Liste bos ise ekrana uyari yazdirir.
        if (head == NULL)
        {
            printf("List is empty.\n");
            return;
        }

        // Tum listeyi dolanmak icin current adinda yeni bir NODE pointeri tanimlanir.
        NODE* current = head;

        printf("Ogrenci Listesi:\n--------------------------\n");

        // Sira ile tum listeyi gezerek her ogrencinin bilgilerini konsola yazdirir.
        while (current != NULL)
        {
            Student* currentStudent = (Student*)current->data;
            printf("Name: %s\n", currentStudent->name);
            printf("Surname: %s\n", currentStudent->surname);
            printf("Department: %s\n", currentStudent->department);
            printf("Grade: %d\n", currentStudent->grade);
            printf("Student No: %d\n", currentStudent->studentNo);
            printf("--------------------------\n");

            // current nodu'na current'dan sonraki nodun adresini tanimlar.
            current = current->next;
        }
    }

    else
    {
        printf("Liste bulunamadi\n--------------------------\n");
    }


}



