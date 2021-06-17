#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int p1=0,p2=0,p3=0,p4=0,p5=0;
    int r_1='A'-1,r_2=0,r_3='a'-1,r_4=0,r_5='a'-1;
	
	// Wybor, ktory sposob konwersji 1 albo 2 dla menu
    int menu=1;
    int i, j;
	int count;

    FILE *f;
    f = fopen( "konwersja.txt", "rt" );
    char buff[50], line[50];

    while(!feof(f)) {
       count=0;
       fgets(buff, sizeof(buff), f);
       i=0;
       while(buff[i]!=' '){
		   count++;
		   i++;
	   }
	   for(i=count, j=0;i<50;i++,j++){
		   line[j]=buff[i];
	   }
	   if(menu==1){
	  		switch(count){
	   			case 1:
                    p1++;
                    p2=0;
                    p3=0;
                    p4=0;
                    p5=0;
                    printf("%d. %s", p1, line);
                    break;
	  	 		case 2:
                    p3=0;
                    p4=0;
                    p5=0;
                    p2++;
	 	  			printf("  %d.%d. %s", p1, p2, line);
		   			break;
	  	 		case 3:
	  	 			p4=0;
	 	  			p5=0;
	 	  			p3++;
	 		  		printf("    %d.%d.%d %s", p1, p2, p3, line);
	  	 			break;
	   			case 4:
	   				p5=0;
	   				p4++;
	   				printf("      %d.%d.%d.%d %s", p1, p2, p3, p4, line);
	   				break;
	   			case 5:
	   				p5++;
	   				printf("        %d.%d.%d.%d.%d %s", p1, p2, p3, p4,p5, line);
	   				break;
	   		}
	   	}
	   	if(menu==2){
	   		switch(count){
	   			case 1:
	   				r_2=0;
					r_3='a'-1;
					r_4=0;
					r_5='a'-1;
					r_1++;
					printf("%c. %s",r_1, line);
	   				break;
	   			case 2:
	   				r_3='a'-1;
					r_4=0;
					r_5='a'-1;
					r_2++;
					printf("  %d. %s",r_2, line);
	   				break;
	   			case 3:
	   				r_4=0;
					r_5='a'-1;
					r_3++;
					printf("    %c. %s",r_3, line);
	   				break;
	   			case 4:
	   				r_5='a'-1;
					r_4++;
					printf("      (%d) %s",r_4, line);
	   				break;
	   			case 5:
	   				r_5++;
	   				printf("        (%c) %s",r_5, line);
	   				break;
	   		}
	   	}
    }
    fclose(f);
    return 0;
}