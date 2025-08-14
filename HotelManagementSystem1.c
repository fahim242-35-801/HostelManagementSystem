/*-----------------------------------------------------------------------
        HOTEL MANAGEMENT SYSTEM
        STUDENT: Md Muntasir Fahim
        Student Id: 242-35-801
        COURSE: Data Structures
        Course Title: 132
        LAB FINAL : Summer 2025
   --------------------------------------------------------------------
   ------------------------------------------------------------------------ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Room{
    int no;
    char type[35];
    int price;
    struct Room*next;
};
struct Room*roomHead= NULL;

void addRoom(int no,char t[],int p){
    struct Room*r= malloc(sizeof(struct Room));
    r->no = no;
    strcpy(r->type, t);
    r->price = p;
    r->next = NULL;
    if(roomHead==NULL)
        roomHead = r;
    else{
        struct Room *temp = roomHead;
        while(temp->next)
        temp = temp->next;
        temp->next = r;
    }
}

void showRooms(){
    struct Room*t= roomHead;
    printf("\n--- Rooms ---\n");
    while(t){
        printf("Room %d | %s | %d\n",t->no,t->type,t->price);
        t=t->next;
    }
}

struct Guest{
    char name[30];
    struct Guest *next;
};
struct Guest*f=NULL, *r=NULL;

void addGuest(char name[]){
    struct Guest*g= malloc(sizeof(struct Guest));
    strcpy(g->name, name);
    g->next= NULL;
    if(r==NULL)
        f=r=g;
    else{ r->next=g;
         r=g;
    }
}
void serveGuest(){
    if(f==NULL){
        printf("No guests waiting!\n");
        return;}
    printf("Checked in: %s\n",f->name);
    struct Guest *tmp = f;
    f=f->next;
    if(f==NULL)
        r=NULL;
       free(tmp);
}
void showGuests(){
    struct Guest*t = f;
    printf("\n--- Waiting Guests ---\n");
    while(t){
            printf("%s\n", t->name);
            t=t->next;}
}
struct Bill{
    int amt;
    struct Bill*next;
};
struct Bill*top=NULL;

void pushBill(int amt){
    struct Bill*b = malloc(sizeof(struct Bill));
    b->amt = amt;
    b->next = top;
    top = b;
}
void popBill(){
    if(top==NULL) {
        printf("No bills!\n");
        return;}
    printf("Bill processed: %d\n", top->amt);
    struct Bill *tmp = top;
    top = top->next;
    free(tmp);
}
void showBills(){
    struct Bill *t = top;
    printf("\n--- Bills ---\n");
    while(t) {
            printf("%d\n", t->amt);
            t=t->next; }
}
struct Reserve{
    int no;
    struct Reserve*l,*r;
};
struct Reserve*root=NULL;
struct Reserve* newReserve(int no){
    struct Reserve*node= malloc(sizeof(struct Reserve));
    node->no= no;
    node->l= node->r = NULL;
    return node;
}
struct Reserve* insertReserve(struct Reserve *r, int no){
    if(r==NULL)
    return newReserve(no);
    if(no<r->no)
     r->l = insertReserve(r->l,no);
    else if(no>r->no)
    r->r = insertReserve(r->r,no);
    return r;
}

void showReserve(struct Reserve*r){
    if(r){
        showReserve(r->l);
        printf("Room %d reserved\n", r->no);
        showReserve(r->r);
    }
}
int main(){
    int ch;
    addRoom(101,"Single",1500);
    addRoom(102,"Double",2500);
    addRoom(201,"Suite",4000);
    addRoom(202,"VIP",9500);
    addRoom(203,"Normal",1000);

    printf("\n__________________________________________\n");
    printf("     >> HOTEL MANAGEMENT SYSTEM << \n");
    printf("-----------------------------------------\n");
    printf("                                           \n");


    while(1){
        printf("    HOTEL DOLPHINEIES    \n");
        printf(" *********************** \n");
        printf("   'Welcome TO OUR HOTEL'   \n");
        printf(" ------( SIR/MA'AM )------- \n");
        printf("\n1.Show Rooms  \n2.Add Guest  \n3.Check-in Guest  \n4.Show Guests");
        printf("\n5.Add Bill    \n6.Process Bill  \n7.Show Bills");
        printf("\n8.Reserve Room  \n9.Show Reservations  \n10.Exit\nChoice: ");
        scanf("%d",&ch);

        if(ch==1) showRooms();
        else if(ch==2){
            char name[30];
            printf("Guest name: ");
            scanf("%s",name);
            addGuest(name);
        }
        else if(ch==3) serveGuest();
        else if(ch==4) showGuests();
        else if(ch==5){
            int amt;
            printf("Bill amount: ");
            scanf("%d",&amt);
            pushBill(amt);
        }
        else if(ch==6) popBill();
        else if(ch==7) showBills();
        else if(ch==8){
            int no;
            printf("Room number to reserve: ");
            scanf("%d",&no);
            root = insertReserve(root,no);
        }
        else if(ch==9) showReserve(root);
        else if(ch==0) break;
        else printf("Invalid!\n");
    }
    return 0;
}
