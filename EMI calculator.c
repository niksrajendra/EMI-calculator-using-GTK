#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	float EMI, ratio, ROI, factor, duration;
	int principle, year, month;
	if(argc > 1)
	{
		for(int option = 1; option<argc && argv[option][0] == '-';option = option + 2)
		{
			switch(argv[option][1])
			{
				case 'p':principle = atoi(argv[option + 1]);
						 printf("principle is %d\n", principle);
						 break;
				case 'r':ROI = atof(argv[option + 1]);
						 printf("ROI is %f\n", ROI);
						 break;
				case 'y':year = atoi(argv[option + 1]);
						 printf("Number of years %d\n", year);
						 break; 
				case 'm':month = atoi(argv[option + 1]);
						 printf("Number of months %d\n", month);
						 break;
			}
		}
		duration = year + month/12.0;
	}
	else
	{
		printf("Enter amount and rate of interest and years:");
		scanf("%d%f%f", &principle, &ROI, &duration);
		printf("\n");	
	}
	ratio = 1 + ROI/1200;
	factor = pow(ratio, 12*duration);
	EMI = (principle*factor*(ratio - 1))/(factor - 1);
	printf("EMI value is %f\n", EMI);
	return 0;
}
