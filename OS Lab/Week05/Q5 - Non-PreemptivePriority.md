## Q5 - Write a C program to simulate the following CPU scheduling algorithm: *Non-Preemptive Priority*

### C program - **algoNPP.c**
```
#include <stdlib.h>
#include <stdio.h>
void main()
{
	int pn = 0, CPU = 0, allTime = 0;
	
	printf("No. of Processes: ");
	scanf("%d",&pn);

	int AT[pn], ATt[pn], NoP = pn, PT[pn], PP[pn], PPt[pn], waittingTime[pn], turnaroundTime[pn];

	for(int i=0 ;i<pn ;i++){
		printf("Arrival Time P%d: ",i+1);
		scanf("%d",&AT[i]);
		ATt[i] = AT[i];
		
		printf("\nBurst Time P%d: ",i+1);
		scanf("%d",&PT[i]);
	
		printf("Piriorty P%d: ",i+1);
		scanf("%d",&PP[i]);
		PPt[i] = PP[i];
	}
	int LAT = 0;
	for(int i = 0; i < pn; i++)
		if(AT[i] > LAT)
	LAT = AT[i];
	int MAX_P = 0;
	for(int i = 0; i < pn; i++)
		if(PPt[i] > MAX_P)
	MAX_P = PPt[i];
	int ATi = 0;
	int P1 = PPt[0];
	int P2 = PPt[0];
	int j = -1;
	while(NoP > 0 && CPU <= 1000){
		for(int i = 0; i < pn; i++){
			if((ATt[i] <= CPU) && (ATt[i] != (LAT+10))){
				if(PPt[i] != (MAX_P+1)){
					P2 = PPt[i];
					j= 1;
					if(P2 < P1){
						j= 1;
						ATi = i;
						P1 = PPt[i];
						P2 = PPt[i];
					}
				}
			}
		}
		if(j == -1){
			CPU = CPU+1;
			continue;
		}else{
			waittingTime[ATi] = CPU - ATt[ATi];
			CPU = CPU + PT[ATi];
			turnaroundTime[ATi] = CPU - ATt[ATi];
			ATt[ATi] = LAT +10;
			j = -1;
			PPt[ATi] = MAX_P + 1;
			ATi = 0;
			P1 = MAX_P+1;
			P2 = MAX_P+1;
			NoP = NoP - 1;
		}
	}
	printf("\nPN\tPT\tPP\tAT\tWT\tTT\n\n");
	for(int i = 0; i < pn; i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,PT[i],PP[i],AT[i],waittingTime[i],
		turnaroundTime[i]);
	}
	int AvgWT = 0;
	int AVGTaT = 0;
	for(int i = 0; i < pn; i++){
		AvgWT = waittingTime[i] + AvgWT;
		AVGTaT = turnaroundTime[i] + AVGTaT;
	}
	printf("Avg Waitting Time = %d\nAvg Turnaround Time = %d\n",AvgWT/pn,AVGTaT/pn);
	return 49;
}
```

### Command to compile the C program
```
gcc -o algoNPP algoNPP.c
```

### Command to run the program
```
./algoNPP
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/17833c1e-b66f-4045-8f55-6d6fdc32e81e)
![image](https://github.com/shrudex/DSE/assets/91502997/84e205f3-fb5e-4364-8641-00fdec7fc078)

