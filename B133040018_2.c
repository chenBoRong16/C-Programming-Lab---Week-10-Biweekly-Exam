#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	int Array[1024];
	while (1){
		int i = 0;
		memset(Array, '\0', 1024*sizeof(int)); //對於int數組，memset比for還慢
		
		int inputCount=0;
		for (; i< 1024; i++){
			inputCount += scanf(" %d", &Array[i]);
		}
		char ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		if ((Array[0] == 0) && (inputCount == 1)){
			printf("Finish!");
			return 0;
		}

		
		int distance = abs(10000 - Array[0]), distance1;
		int answer = Array[0];

		for (i=0 ; Array[i] != '\0'; i++){
			distance1 = abs(10000 - Array[i]);
			if (distance1 < distance){
				distance = distance1;
				answer = Array[i];
			} else if ((distance1 == distance) && (answer < Array[i])){
				answer = Array[i];
			}
		}
		printf("%d\n", answer);
		
	}

	return 0;
}
