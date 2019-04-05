#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	// some change
	int stones = 7000, max = 7000, num_of_stone_taken, calculated_taken_stone;
	int num = 0;
	char ch;
	printf("Main Menu\n1) Set number of stones in the pile\n2) Set maximum number of stones allowed to take from the pile\n4) Exit\nPlease enter your choice:");


	while (num != 4)
	{
		scanf("%d", &num);
		if (num == 3 && (stones == 7000 || max == 7000))
		{
			num = 7000;
		}

		switch (num)
		{
		case 1:
			printf("Please insert the number of stones in the pile :");
			do
			{
				scanf("%d", &stones);

				if (!(stones > 0 && stones <= 1023))
					printf("Not in range (1 - 1023), try again:");
			} while (!(stones > 0 && stones <= 1023));

			break;
		case 2:
			printf("Please insert the maximum number of stones allowed to take from the pile:");
			do
			{
				scanf("%d", &max);

				if (!(max > 0 && max <= 1023))
					printf("Not in range (1 - 1023), try again:");
			} while (!(max > 0 && max <= 1023));
			break;
		case 3:
			//stones = stones;
			printf("Choose who starts first: 'u' for User or 'p' for PC:");
			scanf("%*c%c", &ch);
			if (ch != 'u'&& ch != 'p')
			{
				printf("No such option\ n");
				break;
			}
			while (ch)
			{
				if (ch == 'u')
				{
					printf("There are %d stones in the pile.\nHow many stones would you like to take ?", stones);
					scanf("%d", &num_of_stone_taken);
					if (num_of_stone_taken > stones)
					{
						printf("Not enough stones in the pile, try again.\n");
					}
					else if (num_of_stone_taken > max)
					{
						printf("You are not allowed to take that much, try again.\n");
					}
					else if (num_of_stone_taken <= 0)
					{
						printf("Illegal value, try again.\n");
					}
					else
					{
						printf("You took %d stones from the pile\n", num_of_stone_taken);
						stones = stones - num_of_stone_taken;
						ch = 'p';
					}


				}

				if (ch == 'p')
				{
					if (num_of_stone_taken != max)
					{
						calculated_taken_stone = (stones - 1) / (max + 1);
						num_of_stone_taken = stones - (calculated_taken_stone*(max + 1) + 1);
					}
					else
					{
						num_of_stone_taken = 1;
					}

					printf("There are %d stones in the pile.\nPC took %d stones from the pile\n", stones, num_of_stone_taken);
					stones = stones - num_of_stone_taken;
					ch = 'u';
				}
				if (!stones)
					break;
			}

			if (ch == 'u')
			{
				printf("PC took the last stone. You win.\n");
			}
			else if (ch == 'p')
			{
				printf("You took the last stone. You lose.\n");

			}



			break;
		case 4:
			printf("Bye Bye...");
			break;

		default:
			printf("No such option, try again");
			continue;
		}

		printf("Main Menu");
		if (stones != 7000)
		{
			printf(" [stones=%d]", stones);
		}
		if (max != 7000)
		{
			printf(" [max=%d]", max);
		}

		printf("\n1) Set number of stones in the pile\n2) Set maximum number of stones allowed to take from the pile\n");
		if (max != 7000 && stones != 7000)
		{
			printf("3) play\n");
		}
		printf("4) Exit\nPlease enter your choice:");
	}











}