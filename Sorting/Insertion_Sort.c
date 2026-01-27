#include <stdio.h>
#define MAX 100

int main(void)
{
	int iTemp;
	int iCounter;
	int iCounter2;
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

	for(iCounter = 1; iCounter < iCountOfElement;iCounter++)
	{
		iTemp = Array[iCounter];

		for(iCounter2 = iCounter -1; iCounter >= 0 && iTemp < Array[iCounter2] ; iCounter2--)
			Array[iCounter2 + 1] = Array[iCounter2];

		Array[iCounter2 + 1] = iTemp;
	}

	printf("Sorted Array Is : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	return 0;
}
