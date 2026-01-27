#include <stdio.h>
#define MAX 100

int main(void)
{
	int iCounter;
	int iCounter2;
	int iNoOfSwap;
	int iCountOfElement;
	int Array[MAX];

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

	for(iCounter = 0; iCounter < iCountOfElement -1; iCounter++)
	{
		iNoOfSwap = 0;

		for (iCounter2 = 0; iCounter2 < iCountOfElement - 1 - iCounter; iCounter2++)
		{
			if(Array[iCounter2] > Array[iCounter2 + 1])
			{
				Array[iCounter2] = Array[iCounter2] + Array[iCounter2 + 1];
				Array[iCounter2 + 1] = Array[iCounter2] - Array[iCounter2 + 1];
				Array[iCounter2] = Array[iCounter2] - Array[iCounter2 + 1];
				++iNoOfSwap;
			}
		}

		if (iNoOfSwap == 0)
			break;
	}

	printf("Sorted Array Is : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	return 0;
}