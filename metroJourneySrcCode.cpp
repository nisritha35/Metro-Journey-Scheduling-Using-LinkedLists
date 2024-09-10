#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node * prev;
    char st_name[40];
    struct node *next;
   
}*head_rl,*head_bl,*pres,*dest,*ar,*ab;

//pa and da determine the position of present and destination wrt Ameerpet
//-1 --> before Ameerpet ; 1--> after Ameerpet
//pa=5 -->  present and dest lie on same coloured line -->forward trav
//pa=-5 --> present and dest lie on same coloured line -->reverse trav

int i,pa,da,fare=0;
char present[30],destination[30];

//pc and dc determine the colour of line on which present and des lie resp.
//r-->red ; b-->blue ;

char pc,dc;

struct node * create()
{
    struct node * nn;
    nn= (struct node*) malloc(sizeof(struct node));
    nn->prev=NULL;
    nn->next=NULL;
    return nn;
}

void input()
{
    printf("* All the letters should be in caps *\n");
    printf("* The fare per station is rupees 5 *\n\n");
    printf("Enter the station you are present at\n");
    gets(present);
    printf("Enter the destination station\n");
    gets(destination);
}

void red_line()
{
    struct node *nn,*t;

    for(i=0;i<34;i++)
    {
        nn=create();
        if(head_rl==NULL)
        {
            head_rl=nn;
            t=nn;
        }
        nn->prev=t;
        t->next=nn;
        t=nn;
    }
   
    t=head_rl;
    strcpy(t->st_name,"MIYAPUR"); t=t->next;                  
    strcpy(t->st_name,"JNTU COLLEGE"); t=t->next;             
    strcpy(t->st_name,"KPHB COLONY"); t=t->next;              
    strcpy(t->st_name,"KUKATPALLY"); t=t->next;               
    strcpy(t->st_name,"BALANAGAR"); t=t->next;
    strcpy(t->st_name,"MOOSAPET"); t=t->next;
    strcpy(t->st_name,"BHARATH NAGAR"); t=t->next;
    strcpy(t->st_name,"ERRAGADDA"); t=t->next;
    strcpy(t->st_name,"ESI HOSPITAL"); t=t->next;
    strcpy(t->st_name,"S.R. NAGAR"); t=t->next;
    strcpy(t->st_name,"AMEERPET");ar=t; t=t->next;
    strcpy(t->st_name,"PUNJAGUTTA"); t=t->next;
    strcpy(t->st_name,"IRRUM MANZIL"); t=t->next;
    strcpy(t->st_name,"KHAIRATABAD"); t=t->next;
    strcpy(t->st_name,"LAKDI-KA-PUL"); t=t->next;
    strcpy(t->st_name,"ASSEMBLY"); t=t->next;
    strcpy(t->st_name,"NAMPALLY"); t=t->next;
    strcpy(t->st_name,"GANDHI BHAVAN"); t=t->next;
    strcpy(t->st_name,"OSMANIA MEDICAL COLLEGE"); t=t->next;
    strcpy(t->st_name,"GANDHI HOSPITAL"); t=t->next;
    strcpy(t->st_name,"MUSHEERABAD"); t=t->next;
    strcpy(t->st_name,"R.T.C. X ROADS"); t=t->next;
    strcpy(t->st_name,"CHIKKADPALLY"); t=t->next;
    strcpy(t->st_name,"NARAYANGUDA"); t=t->next;
    strcpy(t->st_name,"SULTAN BAZAAR"); t=t->next;                    //24
    strcpy(t->st_name,"MG BUS STATION"); t=t->next;
    strcpy(t->st_name,"MALAKPET"); t=t->next;
    strcpy(t->st_name,"NEW MARKET"); t=t->next;
    strcpy(t->st_name,"MUSARAMBAGH"); t=t->next;
    strcpy(t->st_name,"DILSUKHNAGAR"); t=t->next;
    strcpy(t->st_name,"CHAITANYAPURI"); t=t->next;
    strcpy(t->st_name,"MUSHEERABAD"); t=t->next;
    strcpy(t->st_name,"VICTORIA MEMORIAL"); t=t->next;
    strcpy(t->st_name,"LB NAGAR"); t=t->next;
}

void blue_line()
{
    struct node *nn,*t;
    for(i=0;i<25;i++)
    {
        nn=create();
        if(head_bl==NULL)
        {
            head_bl=nn;
            t=nn;
        }
        nn->prev=t;
        t->next=nn;
        t=nn;
    }
    
    t=head_bl;
    strcpy(t->st_name,"RAIDURG"); t=t->next;
    strcpy(t->st_name,"HITEC CITY"); t=t->next;
    strcpy(t->st_name,"DURGAM CHERUVU"); t=t->next;
    strcpy(t->st_name,"MADHAPUR"); t=t->next;
    strcpy(t->st_name,"PEDDAMMA GUDI"); t=t->next;
    strcpy(t->st_name,"JUBILEE HILLS"); t=t->next;
    strcpy(t->st_name,"CHECK POST"); t=t->next;
    strcpy(t->st_name,"ROAD NO. 5 JUBILEE HILLS"); t=t->next;
    strcpy(t->st_name,"YUSUFGUDA"); t=t->next;
    strcpy(t->st_name,"MADHURA NAGAR"); t=t->next;
    strcpy(t->st_name,"AMEERPET");ab=t; t=t->next;
    strcpy(t->st_name,"BEGUMPET"); t=t->next;
    strcpy(t->st_name,"PRAKASH NAGAR"); t=t->next;
    strcpy(t->st_name,"RASOOLPURA"); t=t->next;
    strcpy(t->st_name,"PARADISE"); t=t->next;
    strcpy(t->st_name,"JBS PARADE GROUND"); t=t->next;
    strcpy(t->st_name,"PARADE GROUND"); t=t->next;
    strcpy(t->st_name,"SECUNDERABAD"); t=t->next;
    strcpy(t->st_name,"METTUGUDA"); t=t->next;
    strcpy(t->st_name,"TARNAKA"); t=t->next;
    strcpy(t->st_name,"HABSIGUDA"); t=t->next;
    strcpy(t->st_name,"NGRI"); t=t->next;
    strcpy(t->st_name,"STADIUM"); t=t->next;
    strcpy(t->st_name,"UPPAL"); t=t->next;
    strcpy(t->st_name,"NAGOLE"); t=t->next;
}

void search(char x)
{
    struct node *t;
    
    if(x=='r') t=head_rl;
    if(x=='b') t=head_bl;

    if(pres==NULL)
    {
         pa=-1; pc=x;
    }
    if(dest==NULL)
    {
         da=-1; dc=x;
    }
    
    while(t!=NULL)
    {
        if(strcmp(present,t->st_name)==0)
        {
            pres=t;
            if(dest!=NULL && dc==pc)
            {
                pa=-5;                  //reverse traversal from present                          //both on the same colored line
            }  
        }
        if(dest==NULL && strcmp(destination,t->st_name)==0)
        {
            dest=t;
            if(pres!=NULL && dc==pc)    //forward traversal from present
            {
                pa=5;
                                      //both on the same colored line
            }
        }
        if(pa==5 || pa==-5)
           break;
           
        if(t==ar || t==ab)
        {
            if(pres==NULL)pa=1;
            if(dest==NULL)da=1;
        }
        t = t->next;
    }
    
    if(x=='r' && (pres==NULL || dest==NULL))
    {
       search('b');
    }
    return;
}
   
void forward_traversal(struct node * t1, struct node * t2)
{
    struct node *t=t1;
    
    while(t!=t2)
    {
        printf("%s --> ",t->st_name);
        t=t->next;
        fare+=5;
    }
    printf("%s \n",t->st_name);
}

void reverse_traversal(struct node * t1, struct node * t2)
{
    struct node *t=t1;
    while(t!=t2)
    {
        printf("%s --> ",t->st_name);
        t=t->prev;
        fare+=5;
    }
    printf("%s \n",t->st_name);
}
 
void path_dis()
{
    search('r');
    struct node * tempp,*tempd;
    
    if(pres==NULL || dest==NULL)
    {
        printf("\n# ENTER VALID STATION NAMES #\n ");
        return ;
    }
    
   
    if(pa==5)
    {
        forward_traversal(pres,dest);return;
    }
    else if(pa==-5)
    {
        reverse_traversal(pres,dest);return;
    }
    else if(pa==-1 || pa==1)
    {
       
     if(pc=='r'){tempp=ar; tempd=ab;}
     
     else {tempp=ab; tempd=ar;}
        
    //present after ameerpet
     if(pa==1)  reverse_traversal(pres,tempp);
    
    //present before ameerpet
    else    forward_traversal(pres,tempp);                   
    
    
        printf("\nTrain change at Ameerpet station\n\n");
        
        if(da==1)
              forward_traversal(tempd,dest);
        else
              reverse_traversal(tempd,dest);
    }
    
}


int main()
{
	int flag = 5;
    red_line();
    blue_line();
    input();
    path_dis();
    printf("\nThe total fare is %d \n",fare);
    return 0;
}
