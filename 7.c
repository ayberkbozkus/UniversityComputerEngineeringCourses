#include <stdio.h>
#include <stdlib.h>

void func(int array[], int size, int ascending)
{

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (ascending && array[j] > array[j+1])
				{
					int temp = array[j];
					array[j] = array [j+1];
					array[j+1] = temp;
				}
				else if (ascending && array[j] < array[j+1])
				{
					int temp = array[j];
					array[j] = array [j+1];
					array[j+1] = temp;
				}
			}
		}

	for (int i = 0; i < size; ++i)
	{
		printf("%d \n", array[i]);
	}
}

int main()
{
	int size = 0;
	printf("Enter your array size : \n");
	scanf("%d", &size);
	int array[size];
	printf("Enter your array elements : \n");
	for (int i = 0; i < size; ++i)
	{
		int temp = 0;
		scanf("%d", &temp);
		array[i] = temp;
	}
	printf("Sorted\n");
	func(array,size,true);


	return 0;
}