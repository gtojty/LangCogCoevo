// MutInflu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MutInflu.h"

// ---- Include Files;
#include "System.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

// file system files;
void CrtFileNam(char *subDirect, char **fileNam)
{ // create file names;
	assert(subDirect!=NULL);
	int i;
	char Nam1[]="LexCatSyn.txt", Nam2[]="Para.txt", Nam3[]="CommLexSyn.txt", Nam4[]="CommLexNet.txt", Nam5[]="MeanOrder.txt";
	char Nam6[]="eachAgOrd.txt", Nam7[]="Displacement.txt", Nam8[]="CatSize.txt", Nam9[]="AgentLoc.txt", Nam10[]="AgNeighbor.txt";
	char Nam11[]="NetPara.txt", Nam12[]="NetMatrix.txt", Nam13[]="CueReliab.txt", Nam14[]="Amb.txt", Nam15[]="Mem.txt", Nam16[]="PoPrate.txt", Nam17[]="JALTM.txt";
	char *root=new char [strlen(subDirect)+2+_FileLen]; assert(root!=NULL);	
	// create files;
	for(i=0;i<_NumFile;i++) { strcpy(root, subDirect); fileNam[i]=new char [strlen(subDirect)+2+_FileLen]; assert(fileNam[i]!=NULL); strcpy(fileNam[i], root); }
	strcat(fileNam[0], Nam1); strcat(fileNam[1], Nam2); strcat(fileNam[2], Nam3); strcat(fileNam[3], Nam4); strcat(fileNam[4], Nam5); 
	strcat(fileNam[5], Nam6); strcat(fileNam[6], Nam7); strcat(fileNam[7], Nam8); strcat(fileNam[8], Nam9); strcat(fileNam[9], Nam10); 
	strcat(fileNam[10], Nam11); strcat(fileNam[11], Nam12); strcat(fileNam[12], Nam13); strcat(fileNam[13], Nam14); strcat(fileNam[14], Nam15); 
	strcat(fileNam[15], Nam16); strcat(fileNam[16], Nam17);
	delete [] root; root=NULL;	// delete root;
}

void DetFileNam(char **fileNam)
{ // delete file names;
	int i;
	for(i=0;i<_NumFile;i++) { delete [] fileNam[i]; fileNam[i]=NULL; }
}

void InitFile(FILE **f, char **fileNam, int i)
{ // initiate files;
	assert((f!=NULL)&&(fileNam!=NULL)); assert((0<=i)&&(i<_NumFile));
	if((f[i]=fopen(fileNam[i],"w"))==NULL) { printf("Can't create %s\n", fileNam[i]); exit(1); } fclose(f[i]);
}

void setupRun(CSystem *Allsystem, FILE **f, char **fileNam)
{ // set up particular run in particular condition;
	int j;
    switch(Allsystem->getComMode())
		{ case 0: for(j=1;j<8;j++) InitFile(f, fileNam, j);
				Allsystem->RandCom(f, fileNam); 
			    break;	// Rand Com;
	  	  case 1: for(j=1;j<8;j++) InitFile(f, fileNam, j);
				Allsystem->PairCom(f, fileNam); 
				break; // Pair Com;
		  case 2: for(j=1;j<8;j++) InitFile(f, fileNam, j);
				Allsystem->TeachLearn(f, fileNam); 
				break; // teacher-learner;
		  case 3: for(j=1;j<8;j++) InitFile(f, fileNam, j);
		  		InitFile(f, fileNam, 15);
				Allsystem->PopCom(f, fileNam); 
				break;	// popular agent;
		  case 4: for(j=1;j<10;j++) InitFile(f, fileNam, j);
				Allsystem->World2D(f, fileNam); 
				break;	// 2D world com;
		  case 5: for(j=1;j<8;j++) InitFile(f, fileNam, j);
				for(j=10;j<12;j++) InitFile(f, fileNam, j);
				Allsystem->SolCom(f, fileNam); 
				break;	// language and social structure emergence;
		  case 6: for(j=1;j<8;j++) InitFile(f, fileNam, j);
				InitFile(f, fileNam, 12);
				Allsystem->GACulrandCom(f, fileNam); 
				break;	// language and individual learning abilities can coevolve;
		  case 7: for(j=1;j<8;j++) InitFile(f, fileNam, j);
		  		Allsystem->MemLangrandCom(f, fileNam);
				break;  // language and memory coevolution;
		  case 8: for(j=1;j<8;j++) InitFile(f, fileNam, j);
		  		InitFile(f, fileNam, 16);
				Allsystem->JALTMrandCom(f, fileNam);
				break;	// language-JA&LTM coevolution;
		  default: break;
		}
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{	
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.		
		int i, iseq;
		char sep[]="\\", *locDirect=NULL, *seedDirect=NULL, *subDirect=NULL;
		FILE *fseed=NULL;
		unsigned long seed;
		CSystem *Allsystem=NULL;		

		// create f;
		FILE **f=NULL;
		f=new FILE * [_NumFile]; assert(f!=NULL);
		for(i=0;i<_NumFile;i++) f[i]=NULL;
		// create fileNam;
		char **fileNam=NULL;
		fileNam=new char * [_NumFile]; assert(fileNam!=NULL);
		for(i=0;i<_NumFile;i++) fileNam[i]=NULL;
		
		CreateDirectory(overallpara.root_direct, NULL);

		if(overallpara.numRun!=0)
			{ // serial run;
			  for(i=0;i<overallpara.numRun;i++)
				{ // create new subDirectory;
				  subDirect=new char [strlen(overallpara.root_direct)+2+(int)(log10((double)(overallpara.numRun))+1)+1]; assert(subDirect!=NULL);
				  locDirect=new char [(int)(log10((double)(overallpara.numRun))+1)+1]; assert(locDirect!=NULL);
				  sprintf(locDirect, "%d", i+1);
				  strcpy(subDirect, overallpara.root_direct); strcat(subDirect, locDirect); strcat(subDirect, sep); strcat(subDirect, sep);
				  CreateDirectory(subDirect, NULL);
			  
				  // set up seed;
				  seed=CRandomNumber::Seed(overallpara.seed);
				  printf("Run=%*d; Seed=%lu\n", (int)(log10((double)(overallpara.numRun))+1), i+1, seed);	// display seed;
			  
				  // create seed.txt;
				  seedDirect=new char [strlen(subDirect)+strlen("seed.txt")+1]; assert(seedDirect!=NULL);
				  strcpy(seedDirect, subDirect); strcat(seedDirect, "seed.txt");
				  if((fseed=fopen(seedDirect,"w"))==NULL) { printf("Can't create %s\n", seedDirect); exit(1); } fprintf(fseed, "Seed=%lu\n", seed); fclose(fseed);	// store seed into seed.txt;

				  CrtFileNam(subDirect, fileNam);	// create file names;

				  Allsystem=new CSystem; assert(Allsystem!=NULL);
				  if(Allsystem->getRecIndInfo()==1) InitFile(f, fileNam, 0);	// record individual linguistic knowledge;
				  if(Allsystem->getCalAmbiguity()==1) InitFile(f, fileNam, 13);	// record ambiguity;
				  if(Allsystem->getRecMem()==1) InitFile(f, fileNam, 14);	// record memory capacity;
				  setupRun(Allsystem, f, fileNam);
			  
				  printf("\n");
				  DetFileNam(fileNam);	// destroy file names; 
				  delete Allsystem; Allsystem=NULL;	// delete Allsystem;
				  delete [] seedDirect; seedDirect=NULL;	// delete seedDirect;
				  delete [] locDirect; locDirect=NULL;	// delete locDirect;
				  delete [] subDirect; subDirect=NULL;	// delete subDirect;
				}
			}
		else if(overallpara.numRun==0)
			{ // parallel run;
			  printf("input iseq: "); scanf("%d", &iseq); printf("iseq is %d\n", iseq);
			  // create new subDirectory;
			  subDirect=new char [strlen(overallpara.root_direct)+2+(int)(log10((double)(iseq))+1)+1]; assert(subDirect!=NULL);
			  locDirect=new char [(int)(log10((double)(iseq))+1)+1]; assert(locDirect!=NULL);
			  sprintf(locDirect, "%d", iseq);
			  strcpy(subDirect, overallpara.root_direct); strcat(subDirect, locDirect); strcat(subDirect, sep); strcat(subDirect, sep);
			  CreateDirectory(subDirect, NULL);
			  
			  // set up seed;
			  seed=CRandomNumber::Seed((unsigned long)::time(NULL)+100*iseq);
			  printf("Run=%*d; Seed=%lu\n", (int)(log10((double)(iseq))+1), iseq, seed);	// display seed;
				  
			  // create seed.txt;
			  seedDirect=new char [strlen(subDirect)+strlen("seed.txt")+1]; assert(seedDirect!=NULL);
			  strcpy(seedDirect, subDirect); strcat(seedDirect, "seed.txt");
			  if((fseed=fopen(seedDirect,"w"))==NULL) { printf("Can't create %s\n", seedDirect); exit(1); } fprintf(fseed, "Seed=%lu\n", seed); fclose(fseed);	// store seed into seed.txt;

			  CrtFileNam(subDirect, fileNam);	// create file names;

			  Allsystem=new CSystem; assert(Allsystem!=NULL);
			  if(Allsystem->getRecIndInfo()==1) InitFile(f, fileNam, 0);	// record individual linguistic knowledge;
			  if(Allsystem->getCalAmbiguity()==1) InitFile(f, fileNam, 13);	// record ambiguity;
			  if(Allsystem->getRecMem()==1) InitFile(f, fileNam, 14);	// record memory capacity;
			  setupRun(Allsystem, f, fileNam);
			  
			  printf("\n");
			  DetFileNam(fileNam);	// destroy file names; 
			  delete Allsystem; Allsystem=NULL;	// delete Allsystem;
			  delete [] seedDirect; seedDirect=NULL;	// delete seedDirect;
			  delete [] locDirect; locDirect=NULL;	// delete locDirect;
			  delete [] subDirect; subDirect=NULL;	// delete subDirect;
			}
		// delete fileNam;
		delete [] fileNam; fileNam=NULL;
		// delete f;
		delete [] f; f=NULL;
	}
	return nRetCode;
}
