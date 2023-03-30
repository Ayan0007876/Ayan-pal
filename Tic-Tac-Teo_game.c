#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char table[]={"123456789"};
int count_user=0;
int count_computer=0;

int display(){

    printf("\n        |        |        \n");
    printf("    %c   |   %c    |  %c\n",table[0],table[1],table[2]);
    printf("  _______________________\n");
    printf("        |        |        \n");
    printf("    %c   |   %c    |  %c\n",table[3],table[4],table[5]);
    printf("  _______________________\n");
    printf("        |        |        \n");
    printf("    %c   |   %c    |  %c\n\n",table[6],table[7],table[8]);

}

int win(char a){

    if(table[0]==a && table[1]==a && table[2]==a){
        table[0]=table[1]=table[2]='_';
        return 1;
    }
    else if(table[3]==a && table[4]==a && table[5]==a){
        table[3]=table[4]=table[5]='_';
        return 1;
    }
    else if(table[6]==a && table[7]==a && table[8]==a){
        table[6]=table[7]=table[8]='_';
        return 1;
    }
    else if(table[0]==a && table[3]==a && table[6]==a){
        table[3]=table[0]=table[6]='|';
        return 1;
    }
    else if(table[1]==a && table[4]==a && table[7]==a){
        table[1]=table[4]=table[7]='|';
        return 1;
    }
    else if(table[2]==a && table[5]==a && table[8]==a){
        table[2]=table[8]=table[5]='|';
        return 1;
    }
    else if(table[2]==a && table[4]==a && table[6]==a){
        table[2]=table[4]=table[6]='/';
        return 1;
    }
    else if(table[0]==a && table[4]==a && table[8]==a){
        table[0]=table[4]=table[8]='\\';
        return 1;
    }
    else{
        return 0;
    }

}

int computer_play(){

    int c,x;
    count_computer++;
    srand(time(NULL));

    do{
    c=rand() % 9;
    }while(table[c-1]=='O'||table[c-1]=='X'||c<1||c>9);

    printf("computer 'X': %d",c);
    table[c-1]='X';
    display();

    if(count_computer>=3){
        if(win('X')){
            printf("\n\n> > > > COMPUTER WIN > > > >\n\n");
            exit(1);
        }
    }
}

int  user_play(){

    int u;
    count_user++;

    do{
    printf("user 'O' : ");
    scanf("%d",&u);
    }while(table[u-1]=='O'||table[u-1]=='X'||u<1||u>9);

    table[u-1]='O';

     if(count_user>=3){
        if(win('O')){
            printf("\n\n > > > > YOU WIN > > > >\n\n");
            display();
            exit(1);
        }
        if(count_user>=5){
            display();
            printf("\n\n> > > > > > DRAW > > > > > >");
            exit(1);
        }
     }

    computer_play();
}

int main(){
    printf("\n\nEnter ----\n");
    display();
    user_play();
    user_play();
    user_play();
    user_play();
    user_play();
    return 0;
}
