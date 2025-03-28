#include<stdio.h>

void printframe(int frame[10],int frames,int used[10]){
	int i;
	
	printf("Current Status of Frames: [");
	for(i=0;i<frames;i++){
		printf("%d, ",frame[i]);
		used[i]--;
	}
	printf("]\n");
}

void main(){
	int frames[10],pages[100],frame,page;
	int used[10]={0},lru;
	int i,j;
	int pagef=0,hit=0;
	float div;
	printf("Enter the number of frames in the system: ");
	scanf("%d",&frame);
	for(i=0;i<frame;i++){
		frames[i]=-1;
	}
	
	printf("Enter the number of pages in refereance string: ");
	scanf("%d",&page);
	printf("Enter the referance string (Space serperated): ");
	for(i=0;i<page;i++){
		scanf("%d",&pages[i]);
	}
	
	for(i=0;i<page;i++){
		int found=0;
		for(j=0;j<frame;j++){
			if(frames[j]==pages[i]){
				hit++;
				printf("HIT:\t");
				printframe(frames,frame,used);
				used[j]=10;
				found=1;
				break;
				
			}
		}
		if(!found){
			lru=-1;
			for(i=0;i<frame;i++){
				if(lru==-1||used[i]<used[lru]){
					lru=i;
				}
			}
			
			frames[lru]=pages[i];
			used[lru]=10;
			pagef++;
			printf("Miss:\t");
			printframe(frames,frame,used);
		}
	}
	div=page;
	printf("Total Pagefaults: %d\n",pagef);
	printf("Total Hits: %d\n",hit);
	printf("Hit ratio: %2f\n",hit/div);
	printf("Miss ratio: %2f\n",pagef/div);
	
	
}
		
			
	
	
