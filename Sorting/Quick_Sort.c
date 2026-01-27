#include <stdio.h>
#define MAX 100

void Quick(int Array[],int iLow,int iUp);
int QuickSort(int Array[],int iLow,int iUp);

int main(void)
{
	int iCounter;
	int iCountOfElement;
	int Array[MAX] = {0};

	printf("How Many Element You Want To Enter: \t");
	scanf("%d", &iCountOfElement);

	for (iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("\n Enter %d Element : \t", iCounter);
		scanf("%d", &Array[iCounter]);
	}

	printf("\n");

	Quick(Array,0,iCountOfElement);

	printf("Sorted Array Is : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	return 0;
}

void Quick(int Array[],int iLow,int iUp)
{
	int iPivotLoc;

	if(iLow >= iUp)
		return;

	iPivotLoc = QuickSort(Array,iLow, iUp);
	Quick(Array,iLow,iPivotLoc - 1);
	Quick(Array,iPivotLoc + 1,iUp);
}

int QuickSort(int Array[],int iLow,int iUp)
{
	int iCounter = iLow + 1;
	int iCounter2 = iUp;
	int iPivot = Array[iLow];

	while(iCounter <= iCounter2)
	{
		while((Array[iCounter] < iPivot) && (iCounter < iUp))
			iCounter++;

		while(Array[iCounter2] > iPivot)
			iCounter2--;

		if (iCounter < iCounter2)
		{
			Array[iCounter] = Array[iCounter] + Array[iCounter2];
			Array[iCounter2] = Array[iCounter] - Array[iCounter2];
			Array[iCounter] = Array[iCounter] - Array[iCounter2];
			iCounter++;
			iCounter2--;
		}
		else
			iCounter++;
	}

	Array[iLow] = Array[iCounter2];
	Array[iCounter2] = iPivot;
	return iCounter2;
}

