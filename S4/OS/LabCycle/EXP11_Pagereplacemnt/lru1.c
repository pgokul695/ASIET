#include<stdio.h>

typedef struct{
	int word;
	int freq;
}frame;

void print(frame f[10],int n){
	int i;
	printf("\tCurrent status of frame [");
	for(i=0;i<n;i++){
		printf(" %d ",f[i].word);
	}
	printf("]\n");
}

void hit(frame f[10],int n,int i,int word){
	printf("HIT: The page %d is in the frame",word);
	//print(f,n);
	f[i].freq=n;
	for(i=0;i<n;i++){
		f[i].freq--;
	}
	print(f,n);
}

void miss(frame f[10],int n,int i,int word){
	int lowfreq=11,ind;
	printf("MISS: The page %d is not in the frame",word);
	for(i=0;i<n;i++){
		if(f[i].freq<lowfreq){
			ind=i;
			lowfreq=f[i].freq;
		}
	}
	f[ind].word=word;
	f[ind].freq=n;
	for(i=0;i<n;i++){
		f[i].freq--;
	}
	print(f,n);
}

void main(){
	int n,page,i,j;
	int pages[100];
	frame f[10];
	for(i=0;i<10;i++){
		f[i].word=-1;
		f[i].freq=i-10;
	}
	int flag;
	int hi=0,mi=0;
	printf("Enter the number of Frames in the system: ");
	scanf("%d",&n);
	printf("Enter the length of the referance string: ");
	scanf("%d", &page);
	printf("Enter the referance string (Space seperated): ");
	for(i=0;i<page;i++){
		scanf("%d",&pages[i]);
	}
	for(i=0;i<page;i++){
		flag=0;
		for(j=0;j<n;j++){
			if(f[j].word==pages[i]){
				hit(f,n,j,f[j].word);
				flag=1;
				hi++;
			}
		}
		if(flag==0){
			miss(f,n,i,pages[i]);
			mi++;
		}
	}
	printf("Number of Pagefaults: %d\n",mi);
	printf("Number of Hits: %d\n",hi);
	
	printf("Miss ratio: %d\n", (mi/page));
	printf("Hit ratio: %d\n", (hi/page));
	printf("Execution completed \n");
}
				
	

	
	
	
