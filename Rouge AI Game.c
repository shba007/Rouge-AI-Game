#include <stdio.h>
#include <windows.h>

int main()
{
	int i, j, flag, nmov;
	int input, storey = 32;
	int level[storey + 1], moves[] = {1, 3, 4};

	nmov = sizeof(moves) / sizeof(int);

	//Instructions
	printf("This is a Puzzle Game. The Rules are very simple\n");
	printf("\n1.You and AI takes turn lowering the water level exactly ");
	for (i = 0; i < nmov; i++)
		printf("%d, ", moves[i]);
	printf("%c%c stories", 8, 8);
	printf("\n2.The water starts at level %d\n3.Whoever lowers the water to level 0 wins", storey);
	printf("\n4.No one can skip a turn or lower the water below 0\n");

	//Wining Level & Losing Level Calculation
	//level[n] = 0 means lossing level & level[n] = 1 means winning level
	for (level[0] = 0, i = 1; i <= storey; i++)
	{
		for (j = 0, flag = 0; j < nmov; j++)
		{
			if (level[i - moves[j]] == 0)
			{
				level[i] = 1;
				flag = 1;
			}
		}
		if (flag == 0)
			level[i] = 0;
	}

	//Game iteration
	while (1)
	{
		//User's Turn
		printf("\nEnter the level of lowering water: ");
		scanf("%d", &input);

		//Input Check
		for (i = 0, flag = 0; i < nmov && flag == 0; i++)
		{
			if (input == moves[i])
				flag = 1;
		}
		if (flag == 0)
		{
			printf("\nYou can lower the water level exactly ");
			for (i = 0; i < nmov; i++)
				printf("%d, ", moves[i]);
			printf("%c%c stories\n", 8, 8);
			continue;
		}
		else if (storey - input < 0)
		{
			printf("\nYou cannot lower water level below 0\n");
			continue;
		}

		storey -= input;

		printf("Now the Water level is %d\n", storey);
		if (storey == 0)
		{
			printf("\nYou Win the game\n");
			break;
		}

		Sleep(1500);
		//Computer's Turn
		if (level[storey] == 0)
		{
			storey -= moves[0];
			printf("\nComputer lowered the water level by %d\n", moves[0]);
			flag = 1;
		}
		else
		{
			for (i = nmov - 1; i >= 0; i--)
			{
				if (level[storey - moves[i]] == 0)
				{
					storey -= moves[i];
					printf("\nComputer lowered the water level by %d\n", moves[i]);
					break;
				}
			}
		}

		printf("Now the Water level is %d\n", storey);
		if (storey == 0)
		{
			printf("\nComputer Win the game\n");
			break;
		}
	}

	getchar();
	return 0;
}