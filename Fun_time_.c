	#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkWin();//checking the winner
void drawBoard();//drawing the tic tac toe board
int main(){
	system("color 1f");   //changing the background color
	int player = 1, i ,choice;
	char mark; // X,O
	int game;
	printf("\t  ****** WELCOME TO FUN TIME *****\n");
	printf("\t     ** Select a game to play **\n");
	printf(" \n");
	games_again:
	printf(" \t [Enter 1 for TicTacToe] \n");
	printf(" \n");
	printf(" \t [Enter 2 for Rock,Paper,Scissors] \n");

	scanf("%d",&game);
	if(game==1){
	do {
		drawBoard();
		player = (player % 2) ? 1 : 2;
		error_tic:
		printf("Player %d, enter the choice : ",player);
		scanf("%d",&choice);
		mark = (player == 1) ? 'X' : 'O';
		if(choice == 1 && square[1] == '1')
			square[1] = mark;
		else if(choice == 2 && square[2] == '2')
			square[2] = mark;
		else if(choice == 3 && square[3] == '3')
			square[3] = mark;
		else if(choice == 4 && square[4] == '4')
			square[4] = mark;
		else if(choice == 5 && square[5] == '5')
			square[5] = mark;
		else if(choice == 6 && square[6] == '6')
			square[6] = mark;
		else if(choice == 7 && square[7] == '7')
			square[7] = mark;
		else if(choice == 8 && square[8] == '8')
			square[8] = mark;
		else if(choice == 9 && square[9] == '9')
			square[9] = mark;

			else {
				printf("Invalid option! Please choose an available number.\n");
				player--;
				goto error_tic;
			}
			i = checkWin();
			player++;	

	}while(i == -1);

	drawBoard();
	if(i==1){
		printf("********************\n");
		printf("*                  *\n");
		printf("*   Player %d Won  *\n",--player);
		printf("*                  *\n");
		printf("********************\n");
		}
	else {
		printf("********************\n");
		printf("*                  *\n");
		printf("*    Game Draw     *\n");
		printf("*                  *\n");
		printf("********************\n");
		}
	}
	else if(game==2)
	{
		system("cls");
    int cc[5]={1,0,1,2,2},uc,countuc=0,countcc=0;
    printf("\n\t*** Rock, Paper, Scissors ***\n");
    printf("\nYou have 5 chances.\n");
    printf("Computer is your opponent.\nWhoever gets more points out of 5 they win.\n");
    printf("Lets start !\n");
    play_again :
    for(int i=0;i<5;i++){
        printf("\nChance %d\n",i+1);
        printf("Enter your choice (0 for Rock , 1 for paper , 2 for scissors): ");
        scanf("%d",&uc);

        if(uc!=0 && uc!=2 && uc!=1)
        {
             printf("\nInvalid choice. Please enter a number between 0-2.\n");
             i--;
             continue;
        }

        //printing computer's choice 
        if(cc[i]==1)
            printf("  Computer chose: %d (Paper)\n",cc[i]);
        if(cc[i]==2)
            printf("  Computer chose: %d (Scissors)\n",cc[i]);
        if(cc[i]==0)
            printf("  Computer chose: %d (Rock)\n",cc[i]);

        //printing user's choice
        if(uc==0)
            printf("  You chose: %d (Rock)\n",uc);
        if(uc==1)
            printf("  You chose: %d (Paper)\n",uc);
        if(uc==2)
            printf("  You chose: %d (Scissors)\n",uc);
        if(cc[i]==uc)
        {
            printf("  It's a tie!\n");
        }
        else if((uc==0 && cc[i]==2) || (uc==1 && cc[i]==0) || (uc==2 && cc[i]==1))
        {
            printf("  You got a point!\n");
            countuc++;
        }
        else
        {
            printf("  Computer gets a point!\n");
            countcc++;
        }
    }

    //printing points and the winner
    printf("\n   Your total points = %d\n",countuc);
    printf("   Computer's total points = %d\n",countcc);
    if(countuc > countcc)
	{
		printf("\t********************\n");
		printf("\t*                  *\n");
		printf("\t*    YOU WON!      *\n");
		printf("\t*                  *\n");
		printf("\t********************\n");
	}
    else if(countuc<countcc)
	{
		printf("\t********************\n");
		printf("\t*                  *\n");
		printf("\t*  COMPUTER WON!   *\n");
		printf("\t*                  *\n");
		printf("\t********************\n");
	}
    else if(countuc==countcc)
	{
		printf("\t********************\n");
		printf("\t*                  *\n");
		printf("\t*    IT'S A TIE    *\n");
		printf("\t*                  *\n");
		printf("\t********************\n");
	}

    printf("\n\t*** GAME OVER! ***\n");
    countuc=0;
    countcc=0;
	}


	//checkeing if the player wants to play anyother game
	int play_games;
	printf("\nDo you want to play the games again\n");
	printf("Enter '1' for YES, '2' for NO\n");
	error_play_games:
	scanf("%d",&play_games);
	if(play_games==1)
	{
		system("cls");
		printf("\n");
		goto games_again;	
	}
	else if(play_games==2)
	{
		printf("\t*** THANK YOU FOR PLAYING THE GAMES ***\n");
	}
	else
	{
		printf("Error! Please enter 1 or 2: ");
		goto error_play_games;
	}
	return 0;
}



int checkWin(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else 
		return -1;	
}

void drawBoard(){

	system("cls");
	printf("\n\n\t *** Tic Tac Toe *** \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
	printf("     |     |     \n");	
}