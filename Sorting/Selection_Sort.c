#include <stdio.h>
#define MAX 100

int main(void)
{
	int iTemp;
	int iCounter;
	int iCounter2;
	int iCountOfElement;
	int iSmallestElement;
	int Array[MAX] = {0};

	printf("How Many Element You Want To Enter: \t");
	scanf("%d", &iCountOfElement);

	for (iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("\n Enter %d Element : \t", iCounter);
		scanf("%d", &Array[iCounter]);
	}

	printf("\n Entered Element's Are : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	printf("\n");

	for (iCounter = 0; iCounter < iCountOfElement - 1; iCounter++)
	{
		iSmallestElement = iCounter;
		for (iCounter2 = iCounter +1; iCounter2 < iCountOfElement; iCounter2++)
		{
			if (Array[iSmallestElement] > Array [iCounter2])
			{
				iSmallestElement = iCounter2;
			}
		}

		if(iCounter != iSmallestElement)
		{
			iTemp = Array[iCounter];
			Array[iCounter] = Array[iSmallestElement];
			Array[iSmallestElement] = iTemp;
		}
	}

	printf("Sorted Array Is : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	return 0;
}

