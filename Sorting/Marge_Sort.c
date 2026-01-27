#include<stdio.h>
#define MAX 100

void Copy(int arr[],int arrTemp[],int iLow,int iUp);
void Marge(int arr[],int arrTemp[],int iLow1,int iUp1, int iLow2,int iUp2);
void MargeSort(int arr[],int iLow, int iUp);

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

	MargeSort(Array,0,iCountOfElement - 1);

	printf("Sorted Array Is : \t");

	for(iCounter = 0; iCounter < iCountOfElement; iCounter++)
	{
		printf("%d\t", Array[iCounter]);
	}

	return 0;
}

void Marge(int arr[],int arrTemp[],int iLow1,int iUp1, int iLow2,int iUp2)
{
	int iCounter = iLow1;
	int iCounter2 = iLow2;
	int iPos = iLow1;

	while((iCounter <= iUp1) && (iCounter2 <= iUp2))
	{
		if(arr[iCounter] <= arr[iCounter2])
			arrTemp[iPos++] = arr[iCounter++];
		else
			arrTemp[iPos++] = arr[iCounter2++];

	}

	while(iCounter <= iUp1)
		arrTemp[iPos++] = arr[iCounter++];
	while(iCounter2 <= iUp2)
		arrTemp[iPos++] = arr[iCounter2++];
}

void MargeSort(int arr[],int iLow, int iUp)
{
	int iMid;
	int arrTemp[MAX];

	if (iLow < iUp)
	{
		iMid = (iLow + iUp) / 2;
		MargeSort(arr,iLow,iMid);
		MargeSort(arr,iMid +1, iUp);

		Marge(arr, arrTemp,iLow,iMid,iMid+1,iUp);
		Copy(arr,arrTemp,iLow,iUp);
	}
}

void Copy(int arr[],int arrTemp[],int iLow,int iUp)
{
	int iCounter;

	for(iCounter = iLow; iCounter <= iUp; iCounter++)
		arr[iCounter] = arrTemp[iCounter];
}

