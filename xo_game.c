/*
 * xo_game.c
 *
 *
 *      Author: Bishoy Nabil
 */
#include "xo_game.h"

uint8_t ga_Player1[20];
uint8_t ga_Player2[20];
uint8_t ga_GridInput[3][3]={ {'1','2','3'} , {'4','5','6'} , {'7','8','9'} };
uint8_t gu8_Player=1,gu8_Choice,gu8_avail=9;

int main()
{
	printf("Welcome to X O Game, please insert player 1 name: ");
	fflush(stdout);
	gets(ga_Player1);
	printf("\n Please insert player 2 name: ");
	fflush(stdout);
	gets(ga_Player2);
	xoGame();

	return 0;
}

void xoGame()
{
	enu_GameStat_t gameStat=GameContinue;
	while(gameStat==GameContinue)
	{
		gu8_Player=!gu8_Player;
		gridDraw();
		getPlayerInput(gu8_Player);
		gridDraw();
		gameStat=winCheck();
		switch(gameStat)
		{
		case GameWin:
			(gu8_Player==0)?printf("%s has Won!",ga_Player1):printf("%s has Won!",ga_Player2);
			fflush(stdout);
			break;
		case GameDraw:
			printf("Game Draw!");
			fflush(stdout);
			break;
		}

	}
}

void getPlayerInput(uint8_t Player)
{
	uint8_t au8_flag=1,au8_grid;
	(gu8_Player==0)?printf("Insert number please, %s",ga_Player1):printf("Insert number please, %s",ga_Player2);
	fflush(stdout);
	scanf("%d",&gu8_Choice);
	if(gu8_Player==0)
		au8_grid='X';
	else
		au8_grid='O';
	while(au8_flag!=0)
	{
		if((gu8_Choice<1)||(gu8_Choice>9))
		{
			printf("Invalid choice, please enter a valid choice (1-9)");
			fflush(stdout);
			scanf("%d",&gu8_Choice);
		}else
		{
			switch(gu8_Choice)
			{
			case 1:
				if(ga_GridInput[0][0]=='1')
				{
					ga_GridInput[0][0]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 2:
				if(ga_GridInput[0][1]=='2')
				{
					ga_GridInput[0][1]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 3:
				if(ga_GridInput[0][2]=='3')
				{
					ga_GridInput[0][2]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 4:
				if(ga_GridInput[1][0]=='4')
				{
					ga_GridInput[1][0]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 5:
				if(ga_GridInput[1][1]=='5')
				{
					ga_GridInput[1][1]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 6:
				if(ga_GridInput[1][2]=='6')
				{
					ga_GridInput[1][2]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 7:
				if(ga_GridInput[2][0]=='7')
				{
					ga_GridInput[2][0]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 8:
				if(ga_GridInput[2][1]=='8')
				{
					ga_GridInput[2][1]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			case 9:
				if(ga_GridInput[2][2]=='9')
				{
					ga_GridInput[2][2]=au8_grid;
					--gu8_avail;
					au8_flag=0;
				}else
				{
					printf("Already Taken!, enter a new choice.");
					fflush(stdout);
					scanf("%d",&gu8_Choice);
				}
				break;
			}
		}
	}
}

enu_GameStat_t winCheck()
{
	if( (ga_GridInput[0][0]==ga_GridInput[0][1])&&(ga_GridInput[0][1]==ga_GridInput[0][2])
			|| (ga_GridInput[1][0]==ga_GridInput[1][1])&&(ga_GridInput[1][1]==ga_GridInput[1][2])
			|| (ga_GridInput[2][0]==ga_GridInput[2][1])&&(ga_GridInput[2][1]==ga_GridInput[2][2])
			|| (ga_GridInput[0][0]==ga_GridInput[1][0])&&(ga_GridInput[1][0]==ga_GridInput[2][0])
			|| (ga_GridInput[0][1]==ga_GridInput[1][1])&&(ga_GridInput[1][1]==ga_GridInput[2][1])
			|| (ga_GridInput[0][2]==ga_GridInput[1][2])&&(ga_GridInput[1][2]==ga_GridInput[2][2])
			|| (ga_GridInput[0][0]==ga_GridInput[1][1])&&(ga_GridInput[1][1]==ga_GridInput[2][2])
			|| (ga_GridInput[0][2]==ga_GridInput[1][1])&&(ga_GridInput[1][1]==ga_GridInput[2][0]))
		return GameWin;
	else if(gu8_avail==0)
		return GameDraw;
	else
		return GameContinue;
}

void gridDraw()
{
	system("cls");
	printf("\n\n\tX O Game\n\n");
	printf("%s (X)  -  %s (O)\n\n\n",ga_Player1,ga_Player2);


	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", ga_GridInput[0][0], ga_GridInput[0][1], ga_GridInput[0][2]);
	printf("     |     |     \n");
	printf("-----------------\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", ga_GridInput[1][0], ga_GridInput[1][1], ga_GridInput[1][2]);
	printf("     |     |     \n");
	printf("-----------------\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", ga_GridInput[2][0], ga_GridInput[2][1], ga_GridInput[2][2]);

	printf("     |     |     \n\n");
	fflush(stdout);
}
