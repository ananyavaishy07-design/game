#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int ComputerChoice() {
   return (rand() %3) + 1;
}
void ShowMenu(){
	
	printf("\n***ROCK PAPER SCISSORS***\n\n");
	printf("1-> ROCK\n");
	printf("2-> PAPER\n");
	printf("3-> SCISSOR\n\n");
	printf("Enter your choice: ");
}
void PlayGame(){
	
	int user, comp, i;
	int UserScore=0, ComputerScore=0;
	
	const char *roundNames[] = {"FIRST ROUND", "SECOND ROUND", "THIRD ROUND"};

    for(i = 0; i < 3; i++) {       
        printf("\n=============================\n");
        printf("         %s\n", roundNames[i]);
        printf("=============================\n");

		ShowMenu();
		scanf("%d",&user);
		
		  if (user < 1 || user > 3) {
            printf("\nInvalid choice! Please choose 1, 2, or 3.\n");
            i--; 
            continue;
        }
		comp = ComputerChoice();
		printf("\nComputer Chose: %d\n\n",comp);
			
		if(user == comp){
		   printf("IT'S A DRAW!!\n");
		}
		else if((user == 1 && comp == 3) || 
		       (user == 2 && comp == 1) || 
		       (user == 3 && comp == 2))
		{
		printf("YOU WON!!\n");
		UserScore++;  
	}
	else{
		printf("THE COMPUTER WON!!\n");
		ComputerScore++;
    }   

	    printf("\nPress Enter to continue next round");
	while (getchar() != '\n'); 
        getchar();                 
	} 
       
        printf("\n-------FINAL RESULT-------\n");
        
         printf("    \nYou: %d || Computer: %d\n\n", UserScore, ComputerScore);

    if(UserScore > ComputerScore){
	    printf("\n***You Won The Game!***\n");
    }	
    else if(UserScore < ComputerScore){
	    printf("***Computer Won The Game!***\n");
    }
    else{
	    printf("***Match Draw!***\n");
    }
}
