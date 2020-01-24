#include<stdio.h>
#include<stdlib.h>
void sAnsadd(int sAlnum);
void fIllarrayagain(void);

struct Film{
	char fIlmname[20];
	int lEngth;
	char mOhtava[20];
	char sUmmary[100];
	char aCtors[50];
};

struct Sans{
	struct Film fIlm;
	char dAte[15];
	int sTarttime;
	int eNdtime;
	int rEmcapacity;
};

struct Saloon{
	struct Sans sAns[97];//hade aksar 96 sans 15 daghgheii(por kardanesh ro az khoone 1 om shoroo kardam na 0 om ke gij nasham)
};
struct Saloon sAloon[11];//hade aksar 10 salon darim(por kardanesh ro az khoone 1 om shoroo kardam na 0 om ke gij nasham)
int sAlnum,nUmofadd;//related to "add/delete sans as operator"

int main()
{
	fIllarrayagain();
	printf("%s\n",sAloon[1].sAns[1].fIlm.fIlmname);
	
	printf("\n\n		Welcome to the cinema control app\n********************************************************************");
	printf("\nEnter:\n\t1:To Reserve a Sans\n\t2:To Add/delete Sans As Operator\n\t3:To Show The List Of Reservations\n\n?:");
	int cHoice0,cHoice1;//kelid ha
	scanf("%d",&cHoice0);
	puts("\n");
	////////
	if(cHoice0==1){
		
	}
	////////
	if(cHoice0==2){
		printf("Enter:\n\t1:To Add Sans\n\t2:To Delete Sans\n\n?:");
		scanf("%d",&cHoice1);
		puts("\n");
		
		if(cHoice1==1){
			printf("Enter:\n\tNumber Of Saloons You Want To Add Sans In:");
			scanf("%d",&sAlnum);
			puts("\n");
			sAnsadd(sAlnum);
		}
		
		if(cHoice1==2){
			//Delete sans code
		}
		
	}
	////////
	if(cHoice0==3){
		
	}
	
}

void sAnsadd(int sAlnum){/*yadet bashe bayad add sans ro yejoori benevesi k age to oon time ghblan ye sans bood error bde.
ino mitooni ba moghayese 2 reshte dAte va baad moghayese time hashoon bezani*/
	FILE* fPtr;
	fPtr=fopen("sanses.txt","ab");
	if(fPtr!=NULL){
		printf("**File Successfully Opened**\n\n"); 
	}else{
		printf("**Error: File Could Not Be Opened**\n\n");
	}
	
	for(int j=1;j<=sAlnum;j++){
		printf("\tNumber Of Sanses You Want To Add For Saloon(%d):",j);
		scanf("%d",&nUmofadd);
		puts("\n");
		for(int i=1;i<=nUmofadd;i++){
			printf("please use ""-"" instead of space key\n");
			printf("Enter The Informaion Of Sans(%d):\n\tDate Of Sans:",i);
			scanf("%14s",sAloon[j].sAns[i].dAte);
			printf("\tStart Time:");
			scanf("%d",&sAloon[j].sAns[i].sTarttime);
			printf("\tEnd Time:");
			scanf("%d",&sAloon[j].sAns[i].eNdtime);
			printf("\tName Of Film:");
			scanf("%s",sAloon[j].sAns[i].fIlm.fIlmname);
			printf("\tLength:");
			scanf("%d",&sAloon[j].sAns[i].fIlm.lEngth);
			printf("\tMohtava:");
			scanf("%s",sAloon[j].sAns[i].fIlm.mOhtava);
			printf("\tSummary:");
			scanf("%s",sAloon[j].sAns[i].fIlm.sUmmary);
			printf("\tActors Name(seperate by "",""):");
			scanf("%s",sAloon[j].sAns[i].fIlm.aCtors);
			fwrite(&sAloon[j].sAns[i],sizeof(struct Sans),1,fPtr);	
			puts("\n");
		}
	}
	
	fclose(fPtr);
}

void sAnsdelete(void){
	
	
	
}

void fIllarrayagain(void){//in ye tabe baraye por kardane dobare etelaate vard shode tavasote karbar dar dafaate ghabli dar hamoon araye hast ke betoonam azashoon estefade konam bada age niaz shod;
	int sAloonsihad,sAnsesihad;
	FILE* fPtr;
	fPtr=fopen("sanses.txt","rb");
	printf("This Is A Semi-automatic Last-time-data Filling System\nHow Many Saloons Did You Have?(if you didnt, press 0):");
	scanf("%d",&sAloonsihad);
	puts("");
	
	for(int j=1;j<=sAloonsihad;j++){
		printf("How Many Sanses Did You Have In Saloon(%d)?:",j);
		scanf("%d",&sAnsesihad);
		for(int i=1;i<=sAnsesihad;i++){
	 		fread(&sAloon[j].sAns[i],sizeof(struct Sans),1,fPtr);
		}
	}
	fclose(fPtr);
}

/*alan ta hala 10 ta salon ijad kardam ke har kodoom 96 ta sans dare hade aksar va alan mitoonam poreshoon konam bar asase tedade salon va tedade sanse
har salon. vali yadet bashe ke vaghti az barname miri biroon va dobare miay toosh bayad hame in arayeha dobare por beshan va in etefagh 
az to file miofte ke ba fread e.pas bayad ye kari koni az dafe 2 om k barname ro baz mikoni dobare arayeha por beshan va bad betooni bahashoon kar koni;
 */
//alan bayad tabee add sans va delete sans robezanam(delete sans felan zaroori nist)
