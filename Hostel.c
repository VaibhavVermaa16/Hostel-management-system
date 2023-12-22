#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//Creating a struct for hostel
typedef struct hostel{
    int rollno;
    char name[100];
    char gender[20];
    char location[50];
    int r_no;
} hostel; //aliasing the structure as hostel

int max = 500, min = 101;

//Function to check if any vacant room is available
int check_room(int room){
    int counter=0;
    FILE *fptr = fopen("Hostel.txt","r");
    hostel h2;
    while(fread(&h2, sizeof(hostel), 1, fptr)){
        if(h2.r_no == room) counter++;
    }
    if (counter !=0)
    {
       check_room((rand()%(max-min+1)+min)) ;
    }
    else return room;
    fclose(fptr);
}

//wrtitting allocate function for allocation of rooms
void allocate()
{
    hostel h;
    //creating variable h for hostel
    FILE *fptr;
    fptr = fopen("Hostel.txt", "a+");
    //Opening file named hostel in append mode.
    srand(time(NULL));
    int rnd = ((rand() % (max - min + 1)) + min);
    //Reading the values
    printf("\nEnter roll number: ");
    scanf("%d", &h.rollno);
    printf("\nEnter name: ");
    scanf("%s", h.name, sizeof(h.name));
    printf("\nEnter gender: ");
    scanf("%s", h.gender, sizeof(h.gender));
    printf("\nEnter location: ");
    scanf("%s", h.location, sizeof(h.location));
    h.r_no = check_room(rnd);
    //generating random integers between the range minimun to maximum.
    fwrite(&h, sizeof(hostel), 1, fptr);
    fclose(fptr);
    printf("\nEntries stored succesfully.\n");

}


void display()
{
    FILE *fptr;
    fptr = fopen("Hostel.txt", "r");
    hostel h1;
    printf("\t%-10s %-30s %-20s %-50s %-10s\n", "Rollno","Name", "Gender", "Location", "Room No");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    while(fread(&h1, sizeof(hostel), 1, fptr)){
        printf("\t%-10d %-30s %-20s %-50s %-10d\n", h1.rollno,h1.name, h1.gender, h1.location, h1.r_no);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(fptr);
    printf("\n");

}

void chk_passwd(){
    int pswd;
    printf("Please enter your password: ");
    scanf("%d", &pswd);
    FILE *pass = fopen("Password.txt", "r");
    int x;
    fread(&x, sizeof(int), 1, pass);
    if(x != pswd){
        system("cls");
        printf("You entered wrong password, try again!!!\n");
        chk_passwd();
    }
    else system("cls");

}

int main()
{
    system("cls");
    printf("\tWelcome to Hostel Allocation Program\n");
    chk_passwd();
    int ch;
    do
    {
        printf("----------------------------------------------------------------\n");
        printf("Please select a choice from the given options: \n");
        printf("\t1.Allocate new room.\n");
        printf("\t2.Display allocated rooms.\n");
        printf("\t0.Exit program.\n");
        printf("----------------------------------------------------------------\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
        case 1:
            allocate();
            break;
        case 2:
            display();
            break;
        case 0:
            printf("Thanks...");
            return 0;
        default:
            ch=0;
        }
        
    } while (ch != 0);
    return 0;
}