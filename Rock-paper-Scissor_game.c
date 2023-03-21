#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rule(int u,int c){

    if((u==1&&c==3)||(u==2&&c==1)||(u==3&&c==2)){
        printf("\n\nYOU WIN....");
    }

    else if((u==0&&c==1)||(u==1&&c==2)||(u==3&&c==1)){
        printf("\n\nCOMPUTER WIN....");
    }

    else if(u==c){
        printf("\n\n DRAW.....");
    }

        printf("\n___________________________________\n");
}

int user_choice(){
    int a;

    printf("\nchoice --\n");
    printf("Enter 1 for Rock\n");
    printf("Enter 2 for paper\n");
    printf("Enter 3 for Scissor\n> > Enter your choice > > : ");
    scanf("%d",&a);
    return a;
}

int computer_choice(){

    srand(time(0));
    int m=(rand()%(3-1+1)+1);
    return m;
}
int choice(int num){

    switch(num){
        case 1 :
            printf("Rock");
            break;
        case 2 :
            printf("Paper");
            break;
        case 3 :
            printf("Scissor");
            break;
        default :
            printf("ERROR !!!");
            break;
    }
}

int main(){
    
    int user=0,computer=0,n=1;
    printf("_________ R O C K - P A P E R - S C I S S O R _ G A M E __________");

    while(n!=0){
        user=user_choice();
        computer=computer_choice();

        printf("\n\nYou : "); choice(user);
        printf("\ncomputer : "); choice(computer);

        rule(user,computer);

        printf("\n\nEnter any number to Play eny again\nEnter 0 to exit game\n");
        scanf("%d",&n);
    }
    
    return 0;
}
