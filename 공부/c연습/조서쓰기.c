#include <stdio.h>

//조서쓰기


int main() {
	int button = 0, age, height;
	double weight;
	char name[256], crime[256];	
	
	while(button == 0){
		printf("이름이 뭐야?\n");
		scanf("%s",name);
	
		printf("\n");
		
		printf("나이는?\n");
		scanf("%d",&age);
		
		printf("\n");	
		
		printf("몸무게는?\n");
		scanf("%lf",&weight);
	
		printf("\n");		
		
		printf("키는?\n");
		scanf("%d",&height);
	
		printf("\n");		
		
		printf("어떤 잘못을 했지?\n");
		scanf("%s",crime);
		
		printf("---------------------------\n");		
		
		printf("이름 : ");
		printf("%s\n",name);
		
		printf("\n");		
		
		printf("나이 : ");
		printf("%d살\n",age);
		
		printf("\n");		
		
		printf("몸무게 : ");
		printf("%.1lfkg\n",weight);

		printf("\n");		
		
		printf("키? : ");
	    printf("%dcm\n",height);

		printf("\n");		
		
		printf("범죄? : ");
		printf("%s\n",crime);
		
		printf("\n");		
		
		printf("다시하고싶으면 0 아니면 1 : ");
		scanf("%d",&button);
	}
	
	return 0;
}
