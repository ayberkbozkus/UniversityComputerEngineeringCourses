#include <stdio.h> // printf, NULL
#include <stdlib.h> // srand, rand, EXIT_SUCCESS
#include <stdbool.h> // bool
#include <time.h> // time

#define N_ITERATIONS 10000

int main()
{
	srand(time(NULL));


	int strategy_1 = 0; //wins when not changing the door
	int strategy_2 = 0; // wins when changing the door
	for (int i = 0; i<N_ITERATIONS; i++)
	{
		int car_door = rand() % 3 + 1;
		int selected_door = rand() % 3 +1;

		int opened_door = 0;
		int unopened_door = 0;
		if (car_door != selected_door)
		{
			if ((car_door == 1) && (selected_door == 2))
			{
				opened_door = 3;
				unopened_door = 1;
			}
			else if ((car_door == 1) && (selected_door == 3))
			{
				opened_door = 2;
				unopened_door = 1;
			}
			else if ((car_door == 2) && (selected_door == 1))
			{
				opened_door = 3;
				unopened_door = 2;
			}
			else if ((car_door == 2) && (selected_door == 3))
			{
				opened_door = 1;
				unopened_door = 2;
			}
			else if ((car_door == 3) && (selected_door == 1))
			{
				opened_door = 2;
				unopened_door = 3;
			}
			else if ((car_door == 3) && (selected_door == 2))
			{
				opened_door = 1;
				unopened_door = 3;
			}
		}
		else
		{
			bool heads = rand() % 2 == 0;
			if (car_door ==1 )
			{
				opened_door = heads ? 2 : 3;
				unopened_door = heads ? 3 : 2;
			}
			else if (car_door ==2)
			{
				opened_door = heads ? 1 : 3;
				unopened_door = heads ? 3 : 1;		
			}
			else
			{
				opened_door = heads ? 1 : 2;
				unopened_door = heads ? 2 : 1;
			}
		}
		if (car_door == selected_door)
		{
			strategy_1++; // we win if we don't change the door
		}
		else if (car_door == unopened_door)
		{
			strategy_2++; // we win if we do change the door
		}
	}

	double win_ratio_1 = (double) strategy_1 / N_ITERATIONS;
	double win_ratio_2 = (double) strategy_2 / N_ITERATIONS;
	printf("win ratio for strategy 1: %.3lf \n", win_ratio_1);
	printf("win ratio for strategy 2: %.3lf \n", win_ratio_2);

	return EXIT_SUCCESS;
}