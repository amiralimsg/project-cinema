#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sAnsadd(int sAlnum);
void fIllarrayagain(void);
int sAnscmp(int j,int z,char dAte[],int sTarttimenew,int eNdtimenew);
void rEservesans(void);
void sHowavailabelsanses(void);

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
int fLag0;
int sAloonsihad,sAnsesihad;

int main()
{	
	
	fIllarrayagain();
//	printf("%s\n",sAloon[2].sAns[1].fIlm.fIlmname);
	
	printf("\n\n		Welcome to the cinema control app\n********************************************************************");
	printf("\nEnter:\n\t1:To Reserve a Sans\n\t2:To Add/delete Sans As Operator\n\t3:To Show The List Of Reservations\n\n?:");
	int cHoice0,cHoice1;//kelid ha
	scanf("%d",&cHoice0);
	puts("\n");
	////////
	if(cHoice0==1){
		rEservesans();
		
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

void rEservesans(void){
	sHowavailabelsanses();
}

void sHowavailabelsanses(void){
	FILE* fPtr;
	fPtr=fopen("sanses.txt","ab");
	if(fPtr!=NULL){
		printf("**File Successfully Opened**\n\n"); 
	}else{
		printf("**Error: File Could Not Be Opened**\n\n");
	}

	printf("Saloon	Sans	Date	Start - End	Filmname	    Length    Mohtava		Actors\n**********************************************************************************************************\n");
	for(int j=1;j<=11;j++){
		for(int i=1;sAloon[j].sAns[i].fIlm.fIlmname[0]!='\0';i++){//in sharte vasat bara ine ke space khali bekhatere inke kolle fazaye salonha ba data por nistan chaap nakone
			printf("%d	",j);
			printf("%d	",i);
			printf("%s	",sAloon[j].sAns[i].dAte);
			printf("%d - %d	",sAloon[j].sAns[i].sTarttime,sAloon[j].sAns[i].eNdtime);
			printf("%-20s",sAloon[j].sAns[i].fIlm.fIlmname);
			printf("%-10d",sAloon[j].sAns[i].fIlm.lEngth);
			printf("%-10s	",sAloon[j].sAns[i].fIlm.mOhtava);
			printf("%s\n",sAloon[j].sAns[i].fIlm.aCtors);
			
		}
	}
}


void sAnsadd(int sAlnum){
	FILE* fPtr;
	fPtr=fopen("sanses.txt","ab");
	if(fPtr!=NULL){
		printf("**File Successfully Opened**\n\n"); 
	}else{
		printf("**Error: File Could Not Be Opened**\n\n");
	}
	
	for(int j=1;j<=sAlnum;j++){
		printf("\tNumber Of Sanses You Want To Have For Saloon(%d)(previous date will be kept):",j);
		scanf("%d",&nUmofadd);
		puts("\n");
		for(int i=1;i<=nUmofadd;i++){
			
			if(sAloon[j].sAns[i].fIlm.fIlmname[0]!='\0'){//in bara ine ke data ghabli ha pak nashe va berize to structure haye badi
				continue;
			}
			
			printf("please use ""-"" instead of space key\n");
			printf("Enter The Informaion Of Saloon(%d) Sans(%d):\n\tDate Of Sans:",j,i);
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
			puts("\n");
			fLag0=1;
			for(int z=1;z<i;z++){
				if(sAnscmp(j,z,sAloon[j].sAns[i].dAte,sAloon[j].sAns[i].sTarttime,sAloon[j].sAns[i].eNdtime)==0){
					fLag0=0;
					break;
				}
			}
			
			if(fLag0==0){
				printf("**Error:You Can't Add This Sans Because The Time Is Already Taken By Another Sans**\n");
				printf("                               Try Adding Another Sans                             ");
				--i;//baraye inke yebar dige betoone in marhale ro anjam bede va be hadafesh k masalan add kardan 2 ta sanse berese na inke be khaak bere;
			}else{
				fwrite(&sAloon[j].sAns[i],sizeof(struct Sans),1,fPtr);
			}
			puts("\n");
		}
	}
	
	fclose(fPtr);
}

/*void sAnsdelete(void){
	
	
	
}*/



void fIllarrayagain(void){//in ye tabe baraye por kardane dobare etelaate vard shode tavasote karbar dar dafaate ghabli dar hamoon araye hast ke betoonam azashoon estefade konam bada age niaz shod;
	
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


int sAnscmp(int j,int z,char dAte[],int sTarttimenew,int eNdtimenew){//in tabe baraye moghayese tarikh va zamane shoroo va payane sanse vard shode jadid dar ghesmate add va sans haye ghabli dar oon saloon ast ke 2 ta sans roo ham nayoftan
	if(strcmp(dAte,sAloon[j].sAns[z].dAte)==0){
		if((sTarttimenew>=sAloon[j].sAns[z].sTarttime&&sTarttimenew<sAloon[j].sAns[z].eNdtime)||(eNdtimenew>sAloon[j].sAns[z].sTarttime&&eNdtimenew<=sAloon[j].sAns[z].eNdtime)||(sAloon[j].sAns[z].sTarttime>=sTarttimenew&&sAloon[j].sAns[z].sTarttime<eNdtimenew)||(sAloon[j].sAns[z].eNdtime>sTarttimenew&&sAloon[j].sAns[z].eNdtime<=eNdtimenew)){
			return (0);			
		}else{
			return (1);
		}           
		
	}else{
		return (1);
	}
}
//alan yekari kardam k operator mitoone az dafaate badi ham k varede barname shod bazam sans add kone
//alan dg yekari kardam vaghti taraf mikhad reserv kone sans ha namayesh dade beshan
/*alan ta hala 10 ta salon ijad kardam ke har kodoom 96 ta sans dare hade aksar va alan mitoonam poreshoon konam bar asase tedade salon va tedade sanse
har salon. bedoone inke sans ha roo ham bioftan */
//alan bayad tabee delete sans robezanam(delete sans felan zaroori nist)
//dige fek konam add kardan sans tamoom shod va bayad beram soraghe zadane code reserve belit;
