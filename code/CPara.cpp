// CPara.cpp: implement COverAllPara's membership functions;

#include "stdafx.h"
// ---- Include Files;
#include"CPara.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// COverAllPara's membership functions;
void COverAllPara::GetUnsignedIntPara(FILE *ParaFile, unsigned int *para)
{	assert(ParaFile!=NULL);
	int sizeline=_LineLength;
	char *line=new char [sizeline]; assert(line!=NULL);
	char sep[]="\t", *token=NULL;

	fgets(line, sizeline, ParaFile); token=strtok(line, sep);
   	while(token!=NULL) { *para=atoi(token); token=NULL; }
	delete line; line=NULL;
	token=NULL;
}

void COverAllPara::SetUnsignedIntPara(unsigned int *para, unsigned int value) { *para=value; }

void COverAllPara::GetStringPara(FILE *ParaFile, char *&s)
{	assert(ParaFile!=NULL);
	int sizeline=_LineLength;
	char *line=new char [sizeline]; assert(line!=NULL);
	char sep[]="\t", *token=NULL;

	fgets(line, sizeline, ParaFile); token=strtok(line, sep);
   	while(token!=NULL) 
		{ s=new char [strlen(token)+1]; assert(s!=NULL); 
		  strcpy(s, token); token=NULL; 
		}
	delete line; line=NULL;
	token=NULL;
}

void COverAllPara::SetStringPara(char *&s) { delete [] s; s=NULL; };

void COverAllPara::GetIntPara(FILE *ParaFile, int *para)
{ // get integer paramter;
	assert(ParaFile!=NULL);
	int sizeline=_LineLength;
	char *line=new char [sizeline]; assert(line!=NULL);
	char sep[]="\t", *token=NULL;

	fgets(line, sizeline, ParaFile); token=strtok(line, sep);
   	while(token!=NULL) { *para=atoi(token); token=NULL; }
	delete line; line=NULL;
	token=NULL;
}

void COverAllPara::SetIntPara(int *para, int value) { *para=value; }

void COverAllPara::GetDoublePara(FILE *ParaFile, double *para)
{ // get double paramter;
	assert(ParaFile!=NULL);
	int sizeline=_LineLength;
	char *line=new char [sizeline]; assert(line!=NULL);
	char sep[]="\t", *token=NULL;

	fgets(line, sizeline, ParaFile); token=strtok(line, sep);
   	while(token!=NULL) { *para=atof(token); token=NULL; }
	delete line; line=NULL;
	token=NULL;
}

void COverAllPara::SetDoublePara(double *para, double value) { *para=value; }

COverAllPara::COverAllPara()
{ // read text file to get the parameters;
	FILE *ParaFile=NULL;
	int sizeline=_LineLength;
	char *line=new char [sizeline]; assert(line!=NULL);;
	
	if((ParaFile=fopen("OverAllPara.txt","r+"))==NULL) { printf("Can't open OverAllPara.txt\n"); exit(1); }
	fgets(line, sizeline, ParaFile);	// read title;

	GetUnsignedIntPara(ParaFile, &seed);	// read seed;
	GetStringPara(ParaFile, root_direct);	// read root directory;
	GetIntPara(ParaFile, &numRun);	// read number of running;
	GetDoublePara(ParaFile, &p_dEPLSILON);	// read running precision;
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CNet;
	GetIntPara(ParaFile, &p_nNetTyp); 
	GetIntPara(ParaFile, &p_nBasicTyp);
	GetIntPara(ParaFile, &p_nDirected);
	GetDoublePara(ParaFile, &p_dConWeiUp); GetDoublePara(ParaFile, &p_dConWeiLow);
	GetDoublePara(ParaFile, &p_dAdjWei);
	GetDoublePara(ParaFile, &p_dConWeiThres);
	fgets(line, sizeline, ParaFile);	// read for basic network;
	GetIntPara(ParaFile, &p_nEdgePerNode);
	GetIntPara(ParaFile, &p_nLaceR);
	GetIntPara(ParaFile, &p_nLattice); 
	GetDoublePara(ParaFile, &p_dAvgDegree);
	fgets(line, sizeline, ParaFile);	// read for Scale-free, Small world, Local world network;
	GetIntPara(ParaFile, &p_nLocalView);
	GetDoublePara(ParaFile, &p_dReWire);
	GetDoublePara(ParaFile, &p_dAddWireProb);
	GetDoublePara(ParaFile, &p_dRandomProb);	
	fgets(line, sizeline, ParaFile);	// read for Copper-Frieze network;
	GetIntPara(ParaFile, &p_nNumAddEdge); 
	GetDoublePara(ParaFile, &p_dAlfaCF);
	GetDoublePara(ParaFile, &p_dBetaCF);
	GetDoublePara(ParaFile, &p_dGamaCF);
	GetDoublePara(ParaFile, &p_dSetaCF);
	fgets(line, sizeline, ParaFile);	// read for Directed scale-free network; 3 actions; 
	GetIntPara(ParaFile, &p_nDegMode);
	GetDoublePara(ParaFile, &p_dSetaIN);
	GetDoublePara(ParaFile, &p_dSetaOUT);
	GetDoublePara(ParaFile, &p_dAlfaDS);
	GetDoublePara(ParaFile, &p_dBetaDS);
	GetDoublePara(ParaFile, &p_dGamaDS);
	fgets(line, sizeline, ParaFile);	// read for Multi-Local-World (MLW); 3 actions; p_dP+p_dQ+p_dR=1.0
	GetDoublePara(ParaFile, &p_dAlfaMLW);
	GetIntPara(ParaFile, &p_nM1);
	GetIntPara(ParaFile, &p_nM2);
	GetIntPara(ParaFile, &p_nM3);
	GetDoublePara(ParaFile, &p_dP);
	GetDoublePara(ParaFile, &p_dQ);
	GetDoublePara(ParaFile, &p_dR); 

	fgets(line, sizeline, ParaFile); // read Parameters for CPara;
	GetIntPara(ParaFile, &p_nCode);
	GetIntPara(ParaFile, &p_nNumSemRole);
	GetIntPara(ParaFile, &p_nNumSemAgent); GetIntPara(ParaFile, &p_nNumSemPred1); GetIntPara(ParaFile, &p_nNumSemPred2); GetIntPara(ParaFile, &p_nNumSemPat);
	GetIntPara(ParaFile, &p_nLengthWord);
	GetIntPara(ParaFile, &p_nAgSamePat);
	
   	fgets(line, sizeline, ParaFile); // read Parameters for CSemSpace;	
	GetIntPara(ParaFile, &p_nSemDist);
	GetDoublePara(ParaFile, &p_dRatioSV_SVO);
	GetDoublePara(ParaFile, &p_dGausAvg); GetDoublePara(ParaFile, &p_dGausVar);
	GetDoublePara(ParaFile, &p_dPowerLawA); GetDoublePara(ParaFile, &p_dPowerLawK);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CCue;
	GetIntPara(ParaFile, &p_nAtLeastOneCue); 
	GetIntPara(ParaFile, &p_nMaxCueNum); GetIntPara(ParaFile, &p_nWrongCueTyp);
	GetDoublePara(ParaFile, &p_dDefCueStr); 
	GetDoublePara(ParaFile, &p_dCueReliab); GetDoublePara(ParaFile, &p_dCueReliabVar);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CMeanUtter;
	GetIntPara(ParaFile, &p_nNumUtterSyl);
		
	fgets(line, sizeline, ParaFile);	// read Parameters for CBuffer;
	GetIntPara(ParaFile, &p_nBufTyp); GetIntPara(ParaFile, &p_nRemBuf);
	GetIntPara(ParaFile, &p_nVarBufSize);
	GetIntPara(ParaFile, &p_nMaxBufSize); GetIntPara(ParaFile, &p_nMaxBufSizeVar);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CLexRule;
	GetDoublePara(ParaFile, &p_dInitBasicRuleStr); GetDoublePara(ParaFile, &p_dInitLexRuleStr);
	GetDoublePara(ParaFile, &p_dAdjLexRuleStrInc); GetDoublePara(ParaFile, &p_dAdjLexRuleStrDec);
	GetDoublePara(ParaFile, &p_dLexRuleStrUp); GetDoublePara(ParaFile, &p_dLexRuleStrLow);

	GetDoublePara(ParaFile, &p_dInitBasicAssoWei); GetDoublePara(ParaFile, &p_dInitAssoWei);
	GetDoublePara(ParaFile, &p_dAdjAssoWeiInc); GetDoublePara(ParaFile, &p_dAdjAssoWeiDec);
	GetDoublePara(ParaFile, &p_dAssoWeiUp); GetDoublePara(ParaFile, &p_dAssoWeiLow);

	GetIntPara(ParaFile, &p_nMaxCatNum);
	GetDoublePara(ParaFile, &p_dForgetRateLexRule);
	GetDoublePara(ParaFile, &p_dForgetRateAssoWei);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CCat;
	GetIntPara(ParaFile, &p_nMaxLexNum); GetIntPara(ParaFile, &p_nMaxSynNum);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CSynRule;
	GetDoublePara(ParaFile, &p_dInitBasicSynRuleStr); GetDoublePara(ParaFile, &p_dInitSynRuleStr);
	GetDoublePara(ParaFile, &p_dAdjSynRuleStrInc); GetDoublePara(ParaFile, &p_dAdjSynRuleStrDec);
	GetDoublePara(ParaFile, &p_dSynRuleStrUp); GetDoublePara(ParaFile, &p_dSynRuleStrLow);

	GetDoublePara(ParaFile, &p_dForgetRateSynRule);
	GetIntPara(ParaFile, &p_nMaxNumCatRelated);
	GetIntPara(ParaFile, &p_nNumOrderTyp1); GetIntPara(ParaFile, &p_nNumOrderTyp2);
		
	fgets(line, sizeline, ParaFile);	// read Parameters for CIMMem;
	GetIntPara(ParaFile, &p_nChosWin);
	GetDoublePara(ParaFile, &p_dAdjCombOptionStr);
	GetDoublePara(ParaFile, &p_dNeuLexStr); GetDoublePara(ParaFile, &p_dNeuAssoWei); GetDoublePara(ParaFile, &p_dNeuSynStr);
	GetIntPara(ParaFile, &p_nMaxNumLexRules); GetIntPara(ParaFile, &p_nMaxNumCats); GetIntPara(ParaFile, &p_nMaxNumSynRules);
	GetIntPara(ParaFile, &p_nVarIMMem);
	GetIntPara(ParaFile, &p_nMaxNumCombOption); GetIntPara(ParaFile, &p_nMaxNumCombOptionVar);
			
	fgets(line, sizeline, ParaFile);	// read Parameters for CLTMem;
	GetIntPara(ParaFile, &p_nProComp2_3); GetIntPara(ParaFile, &p_nPerComp2_3);
	GetIntPara(ParaFile, &p_nChoIdentical);
	GetIntPara(ParaFile, &p_nVarLTMem);
	GetIntPara(ParaFile, &p_nMaxLexRule); GetIntPara(ParaFile, &p_nMaxLexRuleVar);
	GetIntPara(ParaFile, &p_nMaxCat); GetIntPara(ParaFile, &p_nMaxCatVar);
	GetIntPara(ParaFile, &p_nMaxSynRule); GetIntPara(ParaFile, &p_nMaxSynRuleVar);
	GetIntPara(ParaFile, &p_nMaxRecPat);
	GetIntPara(ParaFile, &p_nDecHolistPhrase);
	
	fgets(line, sizeline, ParaFile);	// Parameters for CAgent;
	GetDoublePara(ParaFile, &p_dChildAdultAbiRatio);
	GetIntPara(ParaFile, &p_nVarCrtDec);
	GetIntPara(ParaFile, &p_nOnlyHolist);
	GetDoublePara(ParaFile, &p_dRandCrtRateWord); GetDoublePara(ParaFile, &p_dRandCrtRateWordVar);
	GetDoublePara(ParaFile, &p_dRandCrtRatePhrase); GetDoublePara(ParaFile, &p_dRandCrtRatePhraseVar);
	GetDoublePara(ParaFile, &p_dRandCrtRateHolist); GetDoublePara(ParaFile, &p_dRandCrtRateHolistVar);
	GetDoublePara(ParaFile, &p_dDetRecPatRate); GetDoublePara(ParaFile, &p_dDetRecPatRateVar);
	GetIntPara(ParaFile, &p_nNoDetRecPatExm); GetIntPara(ParaFile, &p_nNoAcqCatSynExm);
	GetDoublePara(ParaFile, &p_dDetLocOrdRate); GetDoublePara(ParaFile, &p_dDetLocOrdRateVar);
	GetIntPara(ParaFile, &p_nFeedbackTyp);
	GetDoublePara(ParaFile, &p_dSlope); GetDoublePara(ParaFile, &p_dHardFeedback);
	GetIntPara(ParaFile, &p_nHandleFailedTyp);
	GetIntPara(ParaFile, &p_nAvoidLexFlag); GetIntPara(ParaFile, &p_nAvoidSynFlag);
	GetIntPara(ParaFile, &p_nHandleBuf);
	GetIntPara(ParaFile, &p_nAdjMode);
	GetIntPara(ParaFile, &p_nTakePersp); GetIntPara(ParaFile, &p_nPerspective);
	GetIntPara(ParaFile, &p_nForget);
	GetIntPara(ParaFile, &p_nPredCase);
	
	fgets(line, sizeline, ParaFile);	// read Parameters for CSystem;
	GetIntPara(ParaFile, &p_nNumAgent);	
	GetIntPara(ParaFile, &p_nCheckFre);
	GetIntPara(ParaFile, &p_nDecFlag); GetIntPara(ParaFile, &p_nSelfTalkFlag);
	GetIntPara(ParaFile, &p_nRecLocOrdNo_Str);

	GetIntPara(ParaFile, &p_nComMode);
	GetIntPara(ParaFile, &p_nNumGroup);

	GetIntPara(ParaFile, &p_nG1HolComp); 
	GetIntPara(ParaFile, &p_nG1CompTyp);
	GetIntPara(ParaFile, &p_nG1InitCompCat); GetIntPara(ParaFile, &p_nG1order1); GetIntPara(ParaFile, &p_nG1order2);
	GetIntPara(ParaFile, &p_nG1SV1); GetIntPara(ParaFile, &p_nG1VS1);
	GetIntPara(ParaFile, &p_nG1SV); GetIntPara(ParaFile, &p_nG1VS); 
	GetIntPara(ParaFile, &p_nG1VO); GetIntPara(ParaFile, &p_nG1OV); 
	GetIntPara(ParaFile, &p_nG1SO); GetIntPara(ParaFile, &p_nG1OS);

	GetDoublePara(ParaFile, &p_dG1LexNhomrate); GetDoublePara(ParaFile, &p_dG1LexVhomrate); GetDoublePara(ParaFile, &p_dG1LexNVhomrate);

	GetIntPara(ParaFile, &p_nG2HolComp); 
	GetIntPara(ParaFile, &p_nG2CompTyp);
	GetIntPara(ParaFile, &p_nG2InitCompCat); GetIntPara(ParaFile, &p_nG2order1); GetIntPara(ParaFile, &p_nG2order2);
	GetIntPara(ParaFile, &p_nG2SV1); GetIntPara(ParaFile, &p_nG2VS1);
	GetIntPara(ParaFile, &p_nG2SV); GetIntPara(ParaFile, &p_nG2VS); 
	GetIntPara(ParaFile, &p_nG2VO); GetIntPara(ParaFile, &p_nG2OV); 
	GetIntPara(ParaFile, &p_nG2SO);	GetIntPara(ParaFile, &p_nG2OS);

	GetDoublePara(ParaFile, &p_dG2LexNhomrate); GetDoublePara(ParaFile, &p_dG2LexVhomrate); GetDoublePara(ParaFile, &p_dG2LexNVhomrate);
	
	GetDoublePara(ParaFile, &p_dLexSim);

	GetIntPara(ParaFile, &p_nHorObliMix);
	GetIntPara(ParaFile, &p_nMixHorVer);
	
	fgets(line, sizeline, ParaFile);	// read when p_nHorObliMix=1 or p_nHorObliMix=2;
	GetIntPara(ParaFile, &p_nNumAgentRep);
	
	GetIntPara(ParaFile, &p_nCalTransMethod);
	GetDoublePara(ParaFile, &p_dAdultChildRatio); GetDoublePara(ParaFile, &p_dChildChildRatio); GetDoublePara(ParaFile, &p_dChildAdultRatio); GetDoublePara(ParaFile, &p_dVerProb);
	GetDoublePara(ParaFile, &p_dPCRatio); GetDoublePara(ParaFile, &p_dACRatio); GetDoublePara(ParaFile, &p_dCCRatio); GetDoublePara(ParaFile, &p_dCARatio);
	GetDoublePara(ParaFile, &p_dGrandCRatio); GetDoublePara(ParaFile, &p_dParentCRatio); GetDoublePara(ParaFile, &p_dChildCRatio);
	GetIntPara(ParaFile, &p_nGrandCType); GetIntPara(ParaFile, &p_nParentCType);
	
	GetIntPara(ParaFile, &p_nVerTranRandCrt); GetIntPara(ParaFile, &p_nVerTranWrongCue);
	GetIntPara(ParaFile, &p_nDifAdultChild); GetDoublePara(ParaFile, &p_dDifRatio);
	GetIntPara(ParaFile, &p_nSpUpd); GetDoublePara(ParaFile, &p_dSpUpdProb);
	
	GetIntPara(ParaFile, &p_nNumGen); GetIntPara(ParaFile, &p_nNumLearn);

	fgets(line, sizeline, ParaFile);	// read when p_nComMode=3, pop agent;
	GetIntPara(ParaFile, &p_nHumanChimp);
	GetDoublePara(ParaFile, &p_dA1); GetDoublePara(ParaFile, &p_dK1);
	GetDoublePara(ParaFile, &p_dA2); GetDoublePara(ParaFile, &p_dK2);
	GetDoublePara(ParaFile, &p_dScale);
	GetDoublePara(ParaFile, &p_dPopRat);
	GetDoublePara(ParaFile, &p_dIntraRat); GetDoublePara(ParaFile, &p_dInterRat);

	fgets(line, sizeline, ParaFile);	// read when p_nComMode=4, 2D world;
	GetIntPara(ParaFile, &p_nWorldX); GetIntPara(ParaFile, &p_nWorldY);
	GetIntPara(ParaFile, &p_nBlockDist);
	GetDoublePara(ParaFile, &p_dSucRat);
	GetIntPara(ParaFile, &p_nSucCri);
	GetIntPara(ParaFile, &p_nMoveStep);
	GetIntPara(ParaFile, &p_n1toMCom);

	fgets(line, sizeline, ParaFile);	// read when p_nComMode=5, SolCom;
	GetIntPara(ParaFile, &p_nSelfGrow);

	fgets(line, sizeline, ParaFile);	// read when p_nComMode=6, GA RandCom;
	GetIntPara(ParaFile, &p_nGATimeScale);
	GetIntPara(ParaFile, &p_nNumSp);
	GetIntPara(ParaFile, &p_nCulSelType); GetIntPara(ParaFile, &p_nGeneSelType);
	GetDoublePara(ParaFile, &p_dLearnAbiLow); GetDoublePara(ParaFile, &p_dLearnAbiUp);
	GetDoublePara(ParaFile, &p_dMutRate); GetDoublePara(ParaFile, &p_dMutStep);

	fgets(line, sizeline, ParaFile);	// read when p_nComMode=7, MemLang RandCom;
	GetIntPara(ParaFile, &p_nMemMutStep); GetIntPara(ParaFile, &p_nMemMutType);
	
	fgets(line, sizeline, ParaFile);	// read For whole system;	
	GetIntPara(ParaFile, &p_nNumCom); 
	GetIntPara(ParaFile, &p_nNumInfoChange);

	GetIntPara(ParaFile, &p_nCalAmbiguity);
	GetIntPara(ParaFile, &p_nRecMem);

	GetIntPara(ParaFile, &p_nShowComInfo);

	fgets(line, sizeline, ParaFile);	// read whether record individual's information;
	GetIntPara(ParaFile, &p_nIndURCalMethod);
	GetIntPara(ParaFile, &p_nRecIndInfo);
	GetIntPara(ParaFile, &p_nRecURiniser);

	delete line; line=NULL;
	fclose(ParaFile);
}

COverAllPara::~COverAllPara()
{ // destruction function;
	SetUnsignedIntPara(&seed, 0);
	SetStringPara(root_direct);	// read root directory;
	SetIntPara(&numRun, -1);	// read number of running;
	SetDoublePara(&p_dEPLSILON, 0.0);
  // Parameters for CNet;	
	SetIntPara(&p_nNetTyp, -1); 
  	SetIntPara(&p_nBasicTyp, -1);
	SetIntPara(&p_nDirected, -1);
	SetDoublePara(&p_dConWeiUp, 0.0); SetDoublePara(&p_dConWeiLow, 0.0);
	SetDoublePara(&p_dAdjWei, 0.0);
  	SetDoublePara(&p_dConWeiThres, 0.0);
	// for basic network;
  	SetIntPara(&p_nEdgePerNode, 0);
	SetIntPara(&p_nLaceR, 0);
	SetIntPara(&p_nLattice, 0); 
	SetDoublePara(&p_dAvgDegree, 0.0);
	// for Scale-free network, Small world network, Local world network;
	SetIntPara(&p_nLocalView, 0);
	SetDoublePara(&p_dReWire, 0.0);
	SetDoublePara(&p_dAddWireProb, 0.0);
	SetDoublePara(&p_dRandomProb, 0.0);
	// for Copper-Frieze network;
	SetIntPara(&p_nNumAddEdge, 0); 
	SetDoublePara(&p_dAlfaCF, 0.0);
	SetDoublePara(&p_dBetaCF, 0.0);
	SetDoublePara(&p_dGamaCF, 0.0);
	SetDoublePara(&p_dSetaCF, 0.0);
	// for Directed scale-free network; 3 actions; 
	SetIntPara(&p_nDegMode, -2);
	SetDoublePara(&p_dSetaIN, 0.0);
	SetDoublePara(&p_dSetaOUT, 0.0);
	SetDoublePara(&p_dAlfaDS, 0.0);
	SetDoublePara(&p_dBetaDS, 0.0);
	SetDoublePara(&p_dGamaDS, 0.0);
	// for Multi-Local-World (MLW); 3 actions; p_dP+p_dQ+p_dR=1.0
	SetDoublePara(&p_dAlfaMLW, 0.0);
	SetIntPara(&p_nM1, 0);
	SetIntPara(&p_nM2, 0);
	SetIntPara(&p_nM3, 0);
	SetDoublePara(&p_dP, 0.0);
	SetDoublePara(&p_dQ, 0.0);
	SetDoublePara(&p_dR, 0.0); 

  // Parameters for CPara;
	SetIntPara(&p_nCode, 0);
	SetIntPara(&p_nNumSemRole, 0);
	SetIntPara(&p_nNumSemAgent, 0); SetIntPara(&p_nNumSemPred1, 0); SetIntPara(&p_nNumSemPred2, 0); SetIntPara(&p_nNumSemPat, 0);
	SetIntPara(&p_nLengthWord, 0);
	SetIntPara(&p_nAgSamePat, -1);
	
  // Parameters for CSemSpace;
  	SetIntPara(&p_nSemDist, -1);
	SetDoublePara(&p_dRatioSV_SVO, 1.0);
	SetDoublePara(&p_dGausAvg, 0.0); SetDoublePara(&p_dGausVar, 0.0);
	SetDoublePara(&p_dPowerLawA, 0.0); SetDoublePara(&p_dPowerLawK, 0.0);
			
  // Parameters for CCue;
  	SetIntPara(&p_nAtLeastOneCue, -1); 
  	SetIntPara(&p_nMaxCueNum, 0); SetIntPara(&p_nWrongCueTyp, -1);
	SetDoublePara(&p_dDefCueStr, 0.0); 
	SetDoublePara(&p_dCueReliab, 0.0); SetDoublePara(&p_dCueReliabVar, 0.0);
  
  // Parameters for CMeanUtter;
  	SetIntPara(&p_nNumUtterSyl, 0);	 
  	
  // Parameters for CBuffer;
	SetIntPara(&p_nBufTyp, -1); SetIntPara(&p_nRemBuf, -1);
	SetIntPara(&p_nVarBufSize, -1);
	SetIntPara(&p_nMaxBufSize, 0); SetIntPara(&p_nMaxBufSizeVar, 0);

  // Parameters for CLexRule;
  	SetDoublePara(&p_dInitBasicRuleStr, 0.0); SetDoublePara(&p_dInitLexRuleStr, 0.0);
	SetDoublePara(&p_dAdjLexRuleStrInc, 0.0); SetDoublePara(&p_dAdjLexRuleStrDec, 0.0);
	SetDoublePara(&p_dLexRuleStrUp, 0.0); SetDoublePara(&p_dLexRuleStrLow, 0.0);

	SetDoublePara(&p_dInitBasicAssoWei, 0.0); SetDoublePara(&p_dInitAssoWei, 0.0);
	SetDoublePara(&p_dAdjAssoWeiInc, 0.0); SetDoublePara(&p_dAdjAssoWeiDec, 0.0);
	SetDoublePara(&p_dAssoWeiUp, 0.0); SetDoublePara(&p_dAssoWeiLow, 0.0);

	SetIntPara(&p_nMaxCatNum, 0);
	SetDoublePara(&p_dForgetRateLexRule, 0.0); SetDoublePara(&p_dForgetRateAssoWei, 0.0);
	  	  	
  // Parameters for CCat;
  	SetIntPara(&p_nMaxLexNum, 0); SetIntPara(&p_nMaxSynNum, 0);
  	
  // Parameters for CSynRule;
	SetDoublePara(&p_dInitBasicSynRuleStr, 0.0); SetDoublePara(&p_dInitSynRuleStr, 0.0);
	SetDoublePara(&p_dAdjSynRuleStrInc, 0.0); SetDoublePara(&p_dAdjSynRuleStrDec, 0.0);
	SetDoublePara(&p_dSynRuleStrUp, 0.0); SetDoublePara(&p_dSynRuleStrLow, 0.0);

	SetDoublePara(&p_dForgetRateSynRule, 0.0);
	SetIntPara(&p_nMaxNumCatRelated, 0);
	SetIntPara(&p_nNumOrderTyp1, 0); SetIntPara(&p_nNumOrderTyp2, 0);
	
  // Parameters for CIMMem;
  	SetIntPara(&p_nChosWin, -1);
	SetDoublePara(&p_dAdjCombOptionStr, 0.0);
	SetDoublePara(&p_dNeuLexStr, 0.0); SetDoublePara(&p_dNeuAssoWei, 0.0); SetDoublePara(&p_dNeuSynStr, 0.0);
	SetIntPara(&p_nMaxNumLexRules, 0); SetIntPara(&p_nMaxNumCats, 0); SetIntPara(&p_nMaxNumSynRules, 0);
	SetIntPara(&p_nVarIMMem, -1);
	SetIntPara(&p_nMaxNumCombOption, 0); SetIntPara(&p_nMaxNumCombOptionVar, 0);
			  	
  // Parameters for CLTMem;
  	SetIntPara(&p_nProComp2_3, -1); SetIntPara(&p_nPerComp2_3, -1);
  	SetIntPara(&p_nChoIdentical, -1);
  	SetIntPara(&p_nVarLTMem, -1);
  	SetIntPara(&p_nMaxLexRule, 0); SetIntPara(&p_nMaxLexRuleVar, 0);
	SetIntPara(&p_nMaxCat, 0); SetIntPara(&p_nMaxCatVar, 0);
	SetIntPara(&p_nMaxSynRule, 0); SetIntPara(&p_nMaxSynRuleVar, 0);
	SetIntPara(&p_nMaxRecPat, 0);
	SetIntPara(&p_nDecHolistPhrase, -1);
	
  // Parameters for CAgent;
	SetDoublePara(&p_dChildAdultAbiRatio, 0.0);
  	SetIntPara(&p_nVarCrtDec, -1);
	SetIntPara(&p_nOnlyHolist, -1);
	SetDoublePara(&p_dRandCrtRateWord, 0.0); SetDoublePara(&p_dRandCrtRateWordVar, 0.0);
	SetDoublePara(&p_dRandCrtRatePhrase, 0.0); SetDoublePara(&p_dRandCrtRatePhraseVar, 0.0);
	SetDoublePara(&p_dRandCrtRateHolist, 0.0); SetDoublePara(&p_dRandCrtRateHolistVar, 0.0);
	SetDoublePara(&p_dDetRecPatRate, 0.0); SetDoublePara(&p_dDetRecPatRateVar, 0.0);
	SetIntPara(&p_nNoDetRecPatExm, 2); SetIntPara(&p_nNoAcqCatSynExm, 2);
	SetDoublePara(&p_dDetLocOrdRate, 0.0); SetDoublePara(&p_dDetLocOrdRateVar, 0.0);
	SetIntPara(&p_nFeedbackTyp, -1);
	SetDoublePara(&p_dSlope, 0.0); SetDoublePara(&p_dHardFeedback, 0.0);
	SetIntPara(&p_nHandleFailedTyp, -1);
	SetIntPara(&p_nAvoidLexFlag, -1); SetIntPara(&p_nAvoidSynFlag, -1);
	SetIntPara(&p_nHandleBuf, -1);
	SetIntPara(&p_nAdjMode, -1);
	SetIntPara(&p_nTakePersp, -1); SetIntPara(&p_nPerspective, -1);
	SetIntPara(&p_nForget, -1);
	SetIntPara(&p_nPredCase, -1);
	
  // Parameters for CSystem;
  	SetIntPara(&p_nNumAgent, 0);
	SetIntPara(&p_nCheckFre, 0);
	SetIntPara(&p_nDecFlag, -1); SetIntPara(&p_nSelfTalkFlag, -1);
	SetIntPara(&p_nRecLocOrdNo_Str, -1);
	
	SetIntPara(&p_nComMode, -1);
	SetIntPara(&p_nNumGroup, 0);
	
	SetIntPara(&p_nG1HolComp, -1); 
	SetIntPara(&p_nG1CompTyp, -1);
	SetIntPara(&p_nG1InitCompCat, -1); SetIntPara(&p_nG1order1, 0); SetIntPara(&p_nG1order2, 0);
	SetIntPara(&p_nG1SV1, 0); SetIntPara(&p_nG1VS1, 0);
	SetIntPara(&p_nG1SV, 0); SetIntPara(&p_nG1VS, 0); 
	SetIntPara(&p_nG1VO, 0); SetIntPara(&p_nG1OV, 0); 
	SetIntPara(&p_nG1SO, 0); SetIntPara(&p_nG1OS, 0); 
	
	SetDoublePara(&p_dG1LexNhomrate, 0.0); SetDoublePara(&p_dG1LexVhomrate, 0.0); SetDoublePara(&p_dG1LexNVhomrate, 0.0);

	SetIntPara(&p_nG2HolComp, -1); 
	SetIntPara(&p_nG2CompTyp, -1);
	SetIntPara(&p_nG2InitCompCat, -1); SetIntPara(&p_nG2order1, 0); SetIntPara(&p_nG2order2, 0);
	SetIntPara(&p_nG2SV1, 0); SetIntPara(&p_nG2VS1, 0);
	SetIntPara(&p_nG2SV, 0); SetIntPara(&p_nG2VS, 0); 
	SetIntPara(&p_nG2VO, 0); SetIntPara(&p_nG2OV, 0); 
	SetIntPara(&p_nG2SO, 0); SetIntPara(&p_nG2OS, 0);

	SetDoublePara(&p_dG2LexNhomrate, 0.0); SetDoublePara(&p_dG2LexVhomrate, 0.0); SetDoublePara(&p_dG2LexNVhomrate, 0.0);

	SetDoublePara(&p_dLexSim, 0.0);
	
	SetIntPara(&p_nHorObliMix, -1);
	SetIntPara(&p_nMixHorVer, -1);
	SetIntPara(&p_nNumAgentRep, 0);
	
	SetIntPara(&p_nCalTransMethod, -1);
	SetDoublePara(&p_dAdultChildRatio, 0.0); SetDoublePara(&p_dChildChildRatio, 0.0); SetDoublePara(&p_dChildAdultRatio, 0.0); SetDoublePara(&p_dVerProb, 0.0);
	SetDoublePara(&p_dPCRatio, 0.0); SetDoublePara(&p_dACRatio, 0.0); SetDoublePara(&p_dCCRatio, 0.0); SetDoublePara(&p_dCARatio, 0.0);
	SetDoublePara(&p_dGrandCRatio, 0.0); SetDoublePara(&p_dParentCRatio, 0.0); SetDoublePara(&p_dChildCRatio, 0.0);
	SetIntPara(&p_nGrandCType, -1); SetIntPara(&p_nParentCType, -1);

	SetIntPara(&p_nVerTranRandCrt, -1); SetIntPara(&p_nVerTranWrongCue, -1);
	SetIntPara(&p_nDifAdultChild, -1); SetDoublePara(&p_dDifRatio, 0.0);
	SetIntPara(&p_nSpUpd, -1); SetDoublePara(&p_dSpUpdProb, 0.0);
	
	SetIntPara(&p_nNumGen, 0); SetIntPara(&p_nNumLearn, 0);

	SetIntPara(&p_nHumanChimp, -1);
	SetDoublePara(&p_dA1, 0.0); SetDoublePara(&p_dK1, 0.0);
	SetDoublePara(&p_dA2, 0.0); SetDoublePara(&p_dK2, 0.0);
	SetDoublePara(&p_dScale, 0.0);
	SetDoublePara(&p_dPopRat, 0.0);
	SetDoublePara(&p_dIntraRat, 0.0); SetDoublePara(&p_dInterRat, 0.0);

	SetIntPara(&p_nWorldX, 0); SetIntPara(&p_nWorldY, 0);
	SetIntPara(&p_nBlockDist, 0);
	SetDoublePara(&p_dSucRat, 0.0);
	SetIntPara(&p_nSucCri, -1);
	SetIntPara(&p_nMoveStep, 0);
	SetIntPara(&p_n1toMCom, -1);

	SetIntPara(&p_nSelfGrow, -1);

	SetIntPara(&p_nGATimeScale, 0);
	SetIntPara(&p_nNumSp, 0);
	SetIntPara(&p_nCulSelType, -1); SetIntPara(&p_nGeneSelType, -1);
	SetDoublePara(&p_dLearnAbiLow, 0.0); SetDoublePara(&p_dLearnAbiUp, 0.0);
	SetDoublePara(&p_dMutRate, 0.0); SetDoublePara(&p_dMutStep, 0.0);

	SetIntPara(&p_nMemMutStep, 0); SetIntPara(&p_nMemMutType, -1);
	
	SetIntPara(&p_nNumCom, 0); 
	SetIntPara(&p_nNumInfoChange, 0);

	SetIntPara(&p_nCalAmbiguity, -1);
	SetIntPara(&p_nRecMem, -1);

	SetIntPara(&p_nShowComInfo, -1);

	SetIntPara(&p_nIndURCalMethod, -1);
	SetIntPara(&p_nRecIndInfo, -1);
	SetIntPara(&p_nRecURiniser, -1);
}
