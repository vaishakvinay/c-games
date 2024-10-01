//rock paper scissor
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
int result(char attempt,char computer_choice)
{
    
        
      if (attempt == computer_choice) {
        printf("tie!your choice--->' %c 'and the computer chose ' %c '\n",attempt,computer_choice);
        return 0; 
    } else if (attempt == 'r' && computer_choice== 's' ||attempt == 's' && computer_choice == 'p' || attempt == 'p' && computer_choice == 'r'  ) {
        printf("you win this round!!! your choice--->' %c 'and the computer chose ' %c '\n",attempt,computer_choice);
        return 1;
    } else {
        printf("you lost this round!!!your choice--->' %c 'and the computer chose ' %c '\n",attempt,computer_choice);
        return-1;
    }
    }



int main()
{
    srand(time(0)); 
    char attempt ;
    const char choices[] = {'r', 'p', 's'};
    int random_word = rand() % 3; 
    int wins=0,losses=0,tie=0,invalid=0;
    
     
    printf("\n");
    printf("LET'S PLAY A GAME\n");
    sleep(2);
    printf("\n");
    printf("A game of rock paper scissor!!!\n");
    sleep(2);
    printf("\n");
    printf("enter 'r' for rock!!!\n");
    sleep(2);
    printf("\n");
    printf("enter 'p' for paper!!!\n");
    sleep(2);
    printf("\n");
    printf("enter 's' for scissor!!!\n");
    sleep(2);
    printf("\n");
    printf("THE BATTLE IS OF 7 ROUNDS---SEE YA AT THE FINISH POINT\n");
    sleep(3);
    printf("\n");
    sleep(2);
    printf("ready?\n");
    sleep(2);
    printf("set\n");
    sleep(2);
    printf("go!!!!\n");
    sleep(2);
    printf("\n"); 
    



        for (int i= 1; i <= 7; i++) {
        int random_word = rand() % 3; 
        char computer_choice=choices[random_word];
       
 
        printf("Enter \"r\" or \"p\" or \"s\" : ------>");
        scanf(" %c", &attempt);
        printf("\n");
        attempt = tolower(attempt);
        if (attempt !='r' && attempt != 'p' && attempt != 's' ) 
        {   printf("\n");
            printf("Invalid input! Please enter rock or paper or scissor\n");
            invalid++;
        }

        int rounds=result(attempt,computer_choice);

        if(rounds == 1){
            wins++;
        }
        else if(rounds == -1){
            losses++;
        }
        else{
            tie++;
        
        }
        printf("\n");
        printf("ROUNDS left : %d \n", 7-i);
        }
        
        printf("\n");

    
        printf("\nFinal Results:\n");
        printf("\n");
        printf("Wins: %d\n", wins);
        printf("\n");
        printf("Losses: %d\n", losses);
        printf("\n");
        printf("Ties: %d\n", tie);
        printf("\n");
        printf("invalid: %d\n", invalid);
        printf("\n");
        if(wins > losses){
        printf("you win show off\n");
            
        }
        else if(wins < losses){
            printf("you lost, on your knees sucka\n");
            
        }
        else{
            printf("draw!!! narrow escape, wanna try again???\n");
        }
            
}

    
    
