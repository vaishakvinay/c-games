//rock paper scissor
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
int result(char attempt,int random_word)
{
    
        
      if (attempt == random_word) {
        printf("tie!\n");
        return 0;
    } else if (attempt > random_word) {
        return 1;
    } else {
        return-1;
    }
    }



int main()
{
    srand(time(0)); 
    char attempt ;
    const char choices[] = {'r', 'p', 's'};
    int random_word = rand() % 3; 
    
    
     
    
    printf("lets play a game of rock paper scissor!!!\n");
    sleep(2);
    printf("enter 'r' for rock!!!\n");
    sleep(2);
    printf("enter 'p' for paper!!!\n");
    sleep(2);
    printf("enter 's' for scissor!!!\n");
    sleep(2);
    printf("lets see your score in 7 attempts\n");
    sleep(2);
    
        for (int i= 1; i <= 7; i++) {
        char computer_choice=choices[random_word];
 
        printf("Enter rock or paper or scissor: ");
        scanf(" %c", &attempt);
        
        if (attempt !='r' && attempt != 'p' && attempt != 's' ) 
        {
            printf("Invalid input! Please enter rock or paper or scissor\n");
            
        }
        else{
            result(attempt, random_word);
            
        }
        printf("attempts left : %d \n", 7-i);
        }
}

    
    
