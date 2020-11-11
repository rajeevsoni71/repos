#include<stdio.h>
#include <math.h>
/*
13 14 18 10 12 16 9 10
13-18=5 //max profit from 13
14-18=4 //max profit from 14
18 max  // NOT counted
10-16=6 //max profit from 10  this is max profit
12-16=4 //max profit from 12
16 max
9-10=1 //max profit from 9
*/
#define MAX_INPUT 1000
int main() {
	int input[MAX_INPUT] = { 13, 14, 18, 10, 12, 16, 19, 100 };
	int i = 0;
	int j = 1;
	int max_profit = 0;
	int current_profit = 0;
	while (input[i] != '\0') {
		//printf("i:%d,j:%d\n",i,j);
		if ((input[j] != '\0') && (input[i] <= input[j])) {
			current_profit = abs(input[i] - input[j]);
			//printf("CP:%d,MP:%d i:%d,j:%d\n",current_profit,max_profit,input[i],input[j]);
			if (max_profit < current_profit) {
				max_profit = current_profit;
			}
			j++;
			continue;
		}
		else {
			i++;
			j = i;
		}
	}
	printf("%d", max_profit);
	return 0;
}