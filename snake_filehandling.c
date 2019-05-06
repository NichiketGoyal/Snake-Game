#include<stdlib.h>
#include<stdio.h>
#include<time.h>
struct snake{
  int x;int y;
  struct snake *next;
  char value;
};

struct food{
  int x;int y;
  char value;
};

struct snake *initial(struct snake *head){
  struct snake *n,*ptr;
  ptr=head;
  if(ptr==NULL){
    n=(struct snake *)malloc(sizeof(struct snake));
    n->x=10;
    n->y=10;
    n->next=NULL;
    n->value='@';
    head=n;
  }
  n=(struct snake *)malloc(sizeof(struct snake));
  n->x=9;
  n->y=10;
  n->next=NULL;
  n->value='^';
  head->next=n;
  return head;
}

struct food *ini(struct food *f1){
struct food *n;
n=(struct food *)malloc(sizeof(struct food));
n->x=15;
n->y=25;
n->value='*';
f1=n;
return f1;
}

void print(struct snake *head,char mat[20][30],struct food *f1){
struct snake *ptr;
ptr=head;
mat[f1->x][f1->y]=f1->value;
while (ptr!=NULL) {
  mat[ptr->x][ptr->y]=ptr->value;
  ptr=ptr->next;
}

int i,j;
for(i=0;i<20;i++){
  for(j=0;j<30;j++){
    printf("%c",mat[i][j] );
  }printf("\n" );
}
for(i=0;i<20;i++){
  for(j=0;j<30;j++){
    if(i==0||i==19||j==0||j==29){
      mat[i][j]='*';
    }
    else{
      mat[i][j]=' ';
    }
  }
}

}


struct snake *add(struct snake *head,struct food *place){
struct snake *ptr,*n;
ptr=head;
n=(struct snake *)malloc(sizeof(struct snake));
n->x=ptr->x;
n->y=ptr->y;
n->next=ptr->next;
n->value='*';
head->x=place->x;
head->y=place->y;
head->next=n;
return head;
}

struct snake *shift(struct snake *head){
if(head->next!=NULL){
  head->next=shift(head->next);
  head->next->x=head->x;
  head->next->y=head->y;
}
return head;
}



int playgame(struct snake *head,char mat[20][30],struct food *f1){
print(head,mat,f1);
int count=0;

struct snake *ptr;

int flag,fx,fy;
char move,save;
while(head->x!=19&&head->y!=29&&head->x!=0&&head->y!=0){
flag=0;
  ptr=head;
scanf("%c",&move);
if(move=='a'){
  if(head->y-1!=head->next->y)
  {
  if(head->x==f1->x&&head->y-1==f1->y)
  {count++;
    head=add(head,f1);
    int fl=0;
    while(fl==0){
    fx=rand()%18;
    fy=rand()%28;
    fl=1;
    ptr=head;
    while(ptr!=NULL){
      if(ptr->x==fx&&ptr->y==fy){
        fl=0;break;
      }
      ptr=ptr->next;
    }
    if(fx==0||fy==0){
      fl=0;
    }
  }
    f1->x=fx;
    f1->y=fy;
  }
  else{
    head=shift(head);
  head->y=head->y - 1;}
}
else{
  printf("Snake can not move back to this position\n");
}
}
else if(move=='d'){
  if(head->y+1!=head->next->y){
  if(head->x==f1->x&&head->y+1==f1->y){
    head=add(head,f1);
    count++;
    int fl=0;
    while(fl==0){
    fx=rand()%18;
    fy=rand()%28;
    fl=1;
    ptr=head;
    while(ptr!=NULL){
      if(ptr->x==fx&&ptr->y==fy){
        fl=0;break;
      }
      ptr=ptr->next;
    }
    if(fx==0||fy==0){
      fl=0;
    }
  }
    f1->x=fx;
    f1->y=fy;
  }
  else{
  head=shift(head);
  head->y=head->y + 1;}
}
else{
  printf("Snake can not move back to this position\n");
}
}
else if(move=='w'){
  if(head->x-1!=head->next->x){
  if(head->x-1==f1->x&&head->y==f1->y){
    head=add(head,f1);
    count++;
    int fl=0;
    while(fl==0){
    fx=rand()%18;
    fy=rand()%28;
    fl=1;
    ptr=head;
    while(ptr!=NULL){
      if(ptr->x==fx&&ptr->y==fy){
        fl=0;break;
      }
      ptr=ptr->next;
    }
    if(fx==0||fy==0){
      fl=0;
    }
  }
    f1->x=fx;
    f1->y=fy;
  }
  else{
  head=shift(head);
  head->x=head->x - 1;}
}
else{
  printf("Snake can not move back to this position\n");
}
}
else if(move=='s'){
  if(head->x+1!=head->next->x){
  if(head->x+1==f1->x&&head->y==f1->y){
    head=add(head,f1);
    count++;
    int fl=0;
    while(fl==0){
    fx=rand()%18;
    fy=rand()%28;
    fl=1;
    ptr=head;
    while(ptr!=NULL){
      if(ptr->x==fx&&ptr->y==fy){
        fl=0;break;
      }
      ptr=ptr->next;
    }
    if(fx==0||fy==0){
      fl=0;
    }
  }
    f1->x=fx;
    f1->y=fy;
  }
  else{
  head=shift(head);
  head->x=head->x +1;}
}
else{
  printf("Snake can not move back to this position\n");
}

}
else if(move=='q'){
  FILE *fptr;
		fptr = fopen("emp.rec", "w");
		while(head!=NULL)
		{
			fprintf(fptr, "x->= %d  ", head->x);
			fprintf(fptr, "y->= %d\n", head->y);
			head=head->next;
		}
		return 0;
}

ptr=head->next;
while(ptr!=NULL){
if(ptr->x==head->x && ptr->y==head->y){
  flag=1;break;
}
ptr=ptr->next;
}
if(flag==1){
printf("the snake bit itself game over");
break;
}
else{
print(head,mat,f1);
}
}
if(flag==0){
printf("you banged in the wall");
}

return count;
}


int main(){
  struct snake *head;
  struct food *f1;
  f1=NULL;
  head=NULL;
  char c;
  char mat[20][30];
  int i,j,score;
  for(i=0;i<20;i++){
      for(j=0;j<30;j++){
        if(i==0||i==19||j==0||j==29){
          mat[i][j]='*';
        }
        else{
          mat[i][j]=' ';
        }
      }
    }
  head=initial(head);
  f1=ini(f1);
  score=playgame(head,mat,f1);
  printf("\n your score is %d \n",score );
}
