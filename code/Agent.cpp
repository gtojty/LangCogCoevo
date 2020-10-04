// Agent.cpp: implement membership functions of Agent.h

#include "stdafx.h"
// ---- Include Files;
#include"Agent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CAgent's membership functions;
CAgent::CAgent()
{ // construction function;
	InitAgent();
}

CAgent::CAgent(const CAgent &init)
{ // copy construction function;
	(*this)=init;
}

CAgent::~CAgent()
{ // destruction function;
	DestAgent();
}

CAgent & CAgent::operator = (const CAgent &right)
{ // copy agent;
	if(&right!=this)
		{ // it is not self-copy;
		  DestAgent(); InitAgent();
		  setIndex(right.m_nIndex); setGroupIndex(right.m_nGroupIndex);
		  setLocX(right.m_nLocX); setLocY(right.m_nLocY);
		  setChildAdultAbiRatio(right.m_dChildAdultAbiRatio);
		  setOnlyHolist(right.m_nOnlyHolist);
		  
		  setRandCrtRateWord(right.m_dRandCrtRateWord); setRandCrtRatePhrase(right.m_dRandCrtRatePhrase); setRandCrtRateHolist(right.m_dRandCrtRateHolist);
		  setDetRecPatRate(right.m_dDetRecPatRate);

		  setCueReliabAg(right.m_dCueReliabAg);

		  setNoDetRecPatExm(right.m_nNoDetRecPatExm); setNoAcqCatSynExm(right.m_nNoAcqCatSynExm);
		  setDetLocOrdRate(right.m_dDetLocOrdRate);
		  setFeedbackTyp(right.m_nFeedbackTyp);
		  setSlope(right.m_dSlope); setHardFeedback(right.m_dHardFeedback);
		  setHandleFailedTyp(right.m_nHandleFailedTyp);
		  setAvoidLexFlag(right.m_nAvoidLexFlag); setAvoidSynFlag(right.m_nAvoidSynFlag);
		  setHandleBuf(right.m_nHandleBuf);
		  // communication interface;
		  *m_pMeanUtter=*right.m_pMeanUtter; *m_pCues=*right.m_pCues;
		  // memory system;
		  *m_pSemSpace=*right.m_pSemSpace; *m_pBuffer=*right.m_pBuffer; *m_pLTMem=*right.m_pLTMem; *m_pIMMem=*right.m_pIMMem;
		  // adjust mode;
		  setAdjMode(right.m_nAdjMode);
		  // perspective;
		  setTakePersp(right.m_nTakePersp); setPerspective(right.m_nPerspective);
		  setForget(right.m_nForget);
		  setPredCase(right.m_nPredCase);
		}
	return *this;
}

void CAgent::initLearnAbi()
{ // initialize agent's learning abilities;
	double value;
	if(overallpara.p_nVarCrtDec==0)
		{ setRandCrtRateWord(overallpara.p_dRandCrtRateWord);
		  setRandCrtRatePhrase(overallpara.p_dRandCrtRatePhrase);
		  setRandCrtRateHolist(overallpara.p_dRandCrtRateHolist);
		  setDetRecPatRate(overallpara.p_dDetRecPatRate);
		  setDetLocOrdRate(overallpara.p_dDetLocOrdRate);
		  setCueReliabAg(overallpara.p_dCueReliab);
		}
	else if(overallpara.p_nVarCrtDec==1)
		{ // Gaussian distribution of individual learning abilities; 
		  value=overallpara.p_dRandCrtRateWord+sqrt((double)(overallpara.p_dRandCrtRateWordVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRateWord(value);
		  
		  value=overallpara.p_dRandCrtRatePhrase+sqrt((double)(overallpara.p_dRandCrtRatePhraseVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRatePhrase(value);

		  value=overallpara.p_dRandCrtRateHolist+sqrt((double)(overallpara.p_dRandCrtRateHolistVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRateHolist(value);

		  value=overallpara.p_dDetRecPatRate+sqrt((double)(overallpara.p_dDetRecPatRateVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setDetRecPatRate(value);

		  value=overallpara.p_dDetLocOrdRate+sqrt((double)(overallpara.p_dDetLocOrdRateVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setDetLocOrdRate(value);

		  value=overallpara.p_dCueReliab+sqrt((double)(overallpara.p_dCueReliabVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);	
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setCueReliabAg(value);
		}
	else if(overallpara.p_nVarCrtDec==2)
		{ // random distribution of individual learning abilities;
		  value=(double)(Rand0_1*overallpara.p_dRandCrtRateWord);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRateWord(value);
		  
		  value=(double)(Rand0_1*overallpara.p_dRandCrtRatePhrase);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRatePhrase(value);

		  value=(double)(Rand0_1*overallpara.p_dRandCrtRateHolist);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setRandCrtRateHolist(value);

		  value=(double)(Rand0_1*overallpara.p_dDetRecPatRate);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setDetRecPatRate(value);

		  value=(double)(Rand0_1*overallpara.p_dDetLocOrdRate);
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setDetLocOrdRate(value);

		  value=(double)(Rand0_1*overallpara.p_dCueReliab);	
		  if(FLOAT_SM_EQ(value, overallpara.p_dLearnAbiLow)) value=overallpara.p_dLearnAbiLow;
		  else if(FLOAT_BG_EQ(value, overallpara.p_dLearnAbiUp)) value=overallpara.p_dLearnAbiUp;
		  setCueReliabAg(value);		
		}
}

void CAgent::destLearnAbi()
{ // destroy agent's learning abilities;
	setRandCrtRateWord(0.0); setRandCrtRatePhrase(0.0); setRandCrtRateHolist(0.0);
	setDetRecPatRate(0.0); setDetLocOrdRate(0.0);	
	setCueReliabAg(0.0);
}

void CAgent::InitAgent()
{ // initialization function;
	double rannum;
	
	setIndex(-1); setGroupIndex(-1);
	setLocX(-1); setLocY(-1);
	setChildAdultAbiRatio(overallpara.p_dChildAdultAbiRatio);
	setOnlyHolist(overallpara.p_nOnlyHolist);

	initLearnAbi();	// initialize agent's learning bailities;	

	setNoDetRecPatExm(overallpara.p_nNoDetRecPatExm); setNoAcqCatSynExm(overallpara.p_nNoAcqCatSynExm);
	setFeedbackTyp(overallpara.p_nFeedbackTyp);
	setSlope(overallpara.p_dSlope); setHardFeedback(overallpara.p_dHardFeedback);
	setHandleFailedTyp(overallpara.p_nHandleFailedTyp);
	setAvoidLexFlag(overallpara.p_nAvoidLexFlag); setAvoidSynFlag(overallpara.p_nAvoidSynFlag);
	setHandleBuf(overallpara.p_nHandleBuf);
	// communication interface;
	m_pMeanUtter=new CMeanUtter; assert(m_pMeanUtter!=NULL); 
	m_pCues=new CCue; assert(m_pCues!=NULL);
	// memory system;
	m_pSemSpace=new CSemSpace; assert(m_pSemSpace!=NULL); m_pBuffer=new CBuffer; assert(m_pBuffer!=NULL); 
	m_pLTMem=new CLTMem; assert(m_pLTMem!=NULL); m_pIMMem=new CIMMem; assert(m_pIMMem!=NULL);
	// adjust mode;
	setAdjMode(overallpara.p_nAdjMode);
	// perspective;
	setTakePersp(overallpara.p_nTakePersp);
	if((getTakePersp()==0)||(getTakePersp()==1)) setPerspective(overallpara.p_nPerspective);	// no perspective or specific perspective;
	else if(getTakePersp()==2) 
		{ // random take perspective; 
		  rannum=Rand0_1;
		  if(FLOAT_SM_EQ(rannum, _Third)) setPerspective(-1);	// no perspective;
		  else if(FLOAT_SM_EQ(rannum, 2*_Third)) setPerspective(0);	// agent-perspective;
		  else setPerspective(1);	// patient-perspective;
		}
	setForget(overallpara.p_nForget);
	setPredCase(overallpara.p_nPredCase);
}

void CAgent::DestAgent()
{ // destroy function;
	setIndex(-1); setGroupIndex(-1);
	setLocX(-1); setLocY(-1);
	setChildAdultAbiRatio(0.0);
	setOnlyHolist(-1);

	destLearnAbi();

	setNoDetRecPatExm(2); setNoAcqCatSynExm(2);	
	setFeedbackTyp(-1);
	setSlope(0.0); setHardFeedback(0.0);
	setHandleFailedTyp(-1);
	setAvoidLexFlag(-1); setAvoidSynFlag(-1);
	setHandleBuf(-1);
	// communication interface;
	if(getpMeanUtter()!=NULL) { delete m_pMeanUtter; m_pMeanUtter=NULL; }
	if(getpCues()!=NULL) { delete m_pCues; m_pCues=NULL; }
	// memory system;
	if(getpSemSpace()!=NULL) { delete m_pSemSpace; m_pSemSpace=NULL; }
	if(getpBuffer()!=NULL) { delete m_pBuffer; m_pBuffer=NULL; }
	if(getpLTMem()!=NULL) { delete m_pLTMem; m_pLTMem=NULL; }
	if(getpIMMem()!=NULL) { delete m_pIMMem; m_pIMMem=NULL; }
	// adjust mode;
	setAdjMode(-1);
	// perspective;
	setTakePersp(-1); setPerspective(-1);
	setForget(-1);
	setPredCase(-1);
}

// other operations;
// production part;
// build up OptionComb;
void CAgent::setCombHolist(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist)
{ // use holistic or rand holist rules;
	assert((meantype==1)||(meantype==2)); assert(((type==0)&&((*numHolist)!=0))||((type==1)&&(*numHolist==0)));
	int i;
	OptionComb *optiontemp=NULL;

  	if(type==0)
  		{ for(i=0;i<*numHolist;i++)
			{ // build up optiontemp; 
			  optiontemp=new OptionComb; assert(optiontemp!=NULL);

			  // meantype, type, subtype;
			  optiontemp->m_nMeanType=meantype;	optiontemp->m_nType=type; optiontemp->m_nSubType=subtype;
			  // lexical rule part;
			  optiontemp->m_nNumLexRules=1; 
			  optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
			  optiontemp->m_ppLexRules[0]=CandLexRule[i];
			  // category part;
			  optiontemp->m_nNumCats=1;
			  optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
			  optiontemp->m_ppCats[0]=CandLexRule[i]->getpCatList(0)->getpCat();
			  // syntactic rule part;
			  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
			  // combined strength;
			  optiontemp->m_dCombinStr=CandLexRule[i]->getLexStr()+getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
			  
			  getpIMMem()->UpdOptionComb(optiontemp);	// update optiontemp into IMMem;
			  optiontemp=NULL;	// recollect optiontemp;
  			}
  		}
  	else if(type==1)
  		{ // use rand holistic rule;
  		  // build up optiontemp; 
		  optiontemp=new OptionComb; assert(optiontemp!=NULL);

		  // type, subtype, and combined strength part;
		  optiontemp->m_nMeanType=meantype;	optiontemp->m_nType=type; optiontemp->m_nSubType=subtype;
		  // lexical rule part;
		  optiontemp->m_nNumLexRules=0; optiontemp->m_ppLexRules=NULL; 
		  // category part;
		  optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL; 
		  // syntactic rule part;
		  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
		  // combined strength;
		  optiontemp->m_dCombinStr=getpIMMem()->getNeuLexStr()+getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
		  
		  getpIMMem()->UpdOptionComb(optiontemp);	// update optiontemp into IMMem;
		  optiontemp=NULL;	// recollect optiontemp;
  		}
}

int CAgent::SelWinIndex()
{ // select winindex from m_ppOptionComb;
	int winindex=-1;	// default value;
	int i, j, numCombOption;
	double rannum, winstr, *CombOptionStr=NULL;	// store available CombOption's combstr;
	
	// create CombOptionStr;
	numCombOption=getpIMMem()->getNumCombOption();
	CombOptionStr=new double [numCombOption]; assert(CombOptionStr!=NULL);
	for(i=0;i<numCombOption;i++)
		CombOptionStr[i]=getpIMMem()->getpOptionComb(i)->m_dCombinStr;
		
	if(getpIMMem()->getChosWin()==0)
		{ // winner takes all; 
		  if(numCombOption==1) winindex=0;
		  else
		  	{ winstr=0.0;
		  	  // find highest combined strength;
		  	  for(i=0;i<numCombOption;i++)
			  	{ if(FLOAT_BG_EQ(CombOptionStr[i], winstr)) winstr=CombOptionStr[i];
		  	  	}
			  // check whether all OptionComb[i] have same combined strength;
			  for(i=0;i<numCombOption;i++)
		  		{ if(FLOAT_NE(CombOptionStr[i], winstr)) break;
		  		}
			  if(i==numCombOption)
		  		{ // all OptionComb[i] have same combined strength!
				  do{ winindex=(int)(Rand0_1*numCombOption);
			    	  }while(winindex==numCombOption);
			  	}
			  else
			  	{ // not all OptionComb[i] have same combined strength! 
	  	  	  	  do{ winindex=(int)(Rand0_1*numCombOption);
			  	  }while((winindex==numCombOption)||(FLOAT_NE(CombOptionStr[winindex], winstr)));
	  			}
		  	}
		}
	else if(getpIMMem()->getChosWin()==1)
		{ // probability;
		  if(numCombOption==1) winindex=0;
		  else
		  	{ // accumulate;
		  	  for(i=1;i<numCombOption;i++)
			  	CombOptionStr[i]+=CombOptionStr[i-1];
			  for(i=0;i<numCombOption-1;i++)
			  	CombOptionStr[i]/=CombOptionStr[numCombOption-1];
			  CombOptionStr[numCombOption-1]=1.0;
			  
			  rannum=Rand0_1; winindex=-1;
		 	  if(FLOAT_SM_EQ(rannum, CombOptionStr[0])) winindex=0;
			  else if(FLOAT_EQ(rannum, 1.0)) winindex=numCombOption-1;
			  else
				{ for(j=1;j<numCombOption;j++)
					{ if((FLOAT_BG(rannum, CombOptionStr[j-1]))&&(FLOAT_SM_EQ(rannum, CombOptionStr[j]))) 
						{ winindex=j; break; }
					}
				}
			  assert(winindex!=-1);							  
		  	}
		}
	else if(getpIMMem()->getChosWin()==2)
		{ // random adjust and winner takes all;
		  if(numCombOption==1) winindex=0;
		  else
		  	{ for(i=0;i<numCombOption;i++)
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) CombOptionStr[i]+=getpIMMem()->getAdjCombOptionStr();
		  		  else CombOptionStr[i]-=getpIMMem()->getAdjCombOptionStr();
		  		}
		  	  // winner takes all;
		  	  winstr=0.0;
		  	  // find highest combined strength;
		  	  for(i=0;i<numCombOption;i++)
			  	{ if(FLOAT_BG_EQ(CombOptionStr[i], winstr)) winstr=CombOptionStr[i];		    		
	  			}
		  	  // check whether all OptionComb[i] have same combined strength;
		 	  for(i=0;i<numCombOption;i++)
		  		{ if(FLOAT_NE(CombOptionStr[i], winstr)) break;
		  		}
			  if(i==numCombOption)
		  		{ // all OptionComb[i] have same combined strength!
	  		  	  do{ winindex=(int)(Rand0_1*numCombOption);
	  	  	  	  }while(winindex==numCombOption);
			  	}
			  else
	  			{ // not all OptionComb[i] have same combined strength! 
	  	  	  	  do{ winindex=(int)(Rand0_1*numCombOption);
	  	  	  	  }while((winindex==numCombOption)||(FLOAT_NE(CombOptionStr[winindex], winstr)));
	  			}
		  	}
		}
	delete [] CombOptionStr; CombOptionStr=NULL;
	assert(winindex!=-1);
	return winindex;
}

void CAgent::fillOptPro1(int meantype, int type, int subtype, CLexRule *rule, CatList *catlist)
{ // fill in optiontemp with 1 word rule or 1 phrase rule;
  // m_nMeanType=1, "Predicate<Agent>" meanings;
  	// m_nType=3, 1 word + 1 rand word;
  // m_nMeanType=2, "Predicate<Agent, Patient>" meanings;	
  	// m_nType=4, 1 phrase + 1 rand word;		
  	// m_nType=6, 1 word + 1 rand phrase rule;
  		// m_nSubType=1, 1 cat, 0 syn;
		// m_nSubType=2, 0 cat, 0 syn;
	assert(rule!=NULL); assert(((meantype==1)&&(type==3))||((meantype==2)&&((type==4)||(type==6))));
  	assert(((subtype==1)&&(catlist!=NULL))||((subtype==2)&&(catlist==NULL)));
  	OptionComb *optiontemp=NULL;
  	double lexstr, synstr;

	// build up optiontemp; 
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// meantype, type and subtype;
	optiontemp->m_nMeanType=meantype; optiontemp->m_nType=type; optiontemp->m_nSubType=subtype;
 	// lexical rule part;
	optiontemp->m_nNumLexRules=1; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=rule;
	// category, syntactic rule and combine strength part;
	if(subtype==1)
		{ // 1 cat, 0 syn;
		  // category part;
		  optiontemp->m_nNumCats=1;
  		  optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  optiontemp->m_ppCats[0]=catlist->getpCat();
		  // syntactic rule part;
		  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
		  // combine strength part;
		  lexstr=_Half*(rule->getLexStr()+getpIMMem()->getNeuLexStr());
		  synstr=_Half*(catlist->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
		  optiontemp->m_dCombinStr=lexstr+synstr;
		}
	else if(subtype==2)
		{ // 0 cat, 0 syn;
		  // category part;
		  optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL;
		  // syntactic rule part;
		  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
		  // combine strength;
		  lexstr=_Half*(rule->getLexStr()+getpIMMem()->getNeuLexStr());
		  synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
		  optiontemp->m_dCombinStr=lexstr+synstr;
		} 
	
	getpIMMem()->UpdOptionComb(optiontemp);	// update optiontemp into IMMem;					
	optiontemp=NULL;	// recollect optiontemp;
}

void CAgent::fillOptPro2(int meantype, int type, int subtype, CLexRule *rule1, CLexRule *rule2, CatList *catlist1, CatList *catlist2, CSynRule *syn12)
{ // fill in optiontemp with 2 word rules;
  // m_nMeanType=1, "Predicate<Agent>" meanings;
  	// m_nType=2, 2 word rules;
  // m_nMeanType=2, "Predicate<Agent, Patient>" meanings;
  	// m_nType=2, 1 word + 1 phrase rules;		
  	// m_nType=5, 2 word + 1 rand word rules;
  		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat (cat1), 0 syn;
		// m_nSubType=4, 1 cat (cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
  	assert((rule1!=NULL)&&(rule2!=NULL)); assert(((meantype==1)&&(type==2))||((meantype==2)&&((type==2)||(type==5))));
  	assert((1<=subtype)&&(subtype<=5));
	OptionComb *optiontemp=NULL;
	double lexstr, synstr;
	int comp2ret;

	// build up optiontemp; 
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// meantype, type and subtype;
	optiontemp->m_nMeanType=meantype; optiontemp->m_nType=type; optiontemp->m_nSubType=subtype;
	// lexical rule part;
	optiontemp->m_nNumLexRules=2; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=rule1; optiontemp->m_ppLexRules[1]=rule2;
	// category, syntactic rule and combine strength part;
	switch(subtype)
		{ case 1: // 2 cats, 1 syn;
				// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn12;
				// combine strength part;
				lexstr=synstr=0.0;
		  		if((meantype==1)||((meantype==2)&&(type==2)))
		  			{ lexstr=_Half*(rule1->getLexStr()+rule2->getLexStr());
		  	 		  synstr=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
		  			}
		  		else if((meantype==2)&&(type==5))
		  			{ lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+getpIMMem()->getNeuLexStr());
					  comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
					  if(comp2ret==1) 	synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  	  		  else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  			}
		  		optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 2: // 2 cats, 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=synstr=0.0;
				if((meantype==1)||((meantype==2)&&(type==2)))
					{ lexstr=_Half*(rule1->getLexStr()+rule2->getLexStr());
					  synstr=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
				  	}
				else if((meantype==2)&&(type==5))
				  	{ lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+getpIMMem()->getNeuLexStr());
					  comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
					  if(comp2ret==1)	synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				  	  else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				  	}
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 3: // 1 cat (cat1), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=0.0;
				if((meantype==1)||((meantype==2)&&(type==2))) lexstr=_Half*(rule1->getLexStr()+rule2->getLexStr());
				else if((meantype==2)&&(type==5)) lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+getpIMMem()->getNeuLexStr());
				synstr=_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 4: // 1 cat (cat2), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=0.0;
				if((meantype==1)||((meantype==2)&&(type==2))) lexstr=_Half*(rule1->getLexStr()+rule2->getLexStr());
 				else if((meantype==2)&&(type==5)) lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+getpIMMem()->getNeuLexStr());
				synstr=_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 5: // 0 cat, 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL;
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
		  		// combine strength part;
		  		lexstr=0.0;
				if((meantype==1)||((meantype==2)&&(type==2))) lexstr=_Half*(rule1->getLexStr()+rule2->getLexStr());
				else if((meantype==2)&&(type==5)) lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+getpIMMem()->getNeuLexStr());
			  	synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
		  		optiontemp->m_dCombinStr=lexstr+synstr;
		  		break;
		  default: break;
		}

	getpIMMem()->UpdOptionComb(optiontemp);	// update optiontemp into IMMem;					
	optiontemp=NULL;	// recollect optiontemp;
}

void CAgent::fillOptPro3(int meantype, int type, int subtype, CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13)
{ // fill in optiontemp with 3 word rules;
  // m_nMeanType=2, "Predicate<Agent, Patient>" meanings;
  	// m_nType=3, 3 word rules;
		// m_nSubType=1, 3 cats, 3 syn;
		// m_nSubType=2, 3 cats, 2 syn(12, 23);
		// m_nSubType=3, 3 cats, 2 syn(12, 13);
		// m_nSubType=4, 3 cats, 2 syn(23, 13);
		// m_nSubType=5, 3 cats, 1 syn(12);
		// m_nSubType=6, 3 cats, 1 syn(23);
		// m_nSubType=7, 3 cats, 1 syn(13);
		// m_nSubType=8, 3 cats, 0 syn;
		// m_nSubType=9, 2 cats(S+V), 1 syn(12);
		// m_nSubType=10, 2 cats(S+V), 0 syn;
		// m_nSubType=11, 2 cats(S+O), 1 syn(13);
		// m_nSubType=12, 2 cats(S+O), 0 syn;
		// m_nSubType=13, 2 cats(V+O), 1 syn(23);
		// m_nSubType=14, 2 cats(V+O), 0 syn;
		// m_nSubType=15, 1 cats(S), 0 syn;
		// m_nSubType=16, 1 cats(V), 0 syn;
		// m_nSubType=17, 1 cats(O), 0 syn;
		// m_nSubType=18, 0 cat, 0 syn;
	assert((rule1!=NULL)&&(rule2!=NULL)&&(rule3!=NULL));
  	assert((meantype==2)&&(type==3)); assert((1<=subtype)&&(subtype<=18));
	OptionComb *optiontemp=NULL;
	double lexstr, synstr, assowei12, assowei23, assowei13;
	int comp2ret, comp3ret;

	// build up optiontemp; 
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// meantype, type and subtype;
	optiontemp->m_nMeanType=meantype; optiontemp->m_nType=type; optiontemp->m_nSubType=subtype;
	// lexical rule part;
	optiontemp->m_nNumLexRules=3; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=rule1; optiontemp->m_ppLexRules[1]=rule2; optiontemp->m_ppLexRules[2]=rule3;
	// category, syntactic rule and combine strength part;
	switch(subtype)
		{ case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				// category part;
		  		optiontemp->m_nNumCats=3;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat(); optiontemp->m_ppCats[2]=catlist3->getpCat();
			  	// syntactic rule and combine strength;
		  		switch(subtype)
		  			{ case 1: // 3 cats, 3 syn;
		  					// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=3; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn23; optiontemp->m_ppSynRules[2]=syn13;
							// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
							assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Third*(assowei12+assowei23+assowei13);
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  					break;
		  			  case 2: // 3 cats, 2 syn(12, 23);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn23;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							synstr=_Half*(assowei12+assowei23);
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 3: // 3 cats, 2 syn(12, 13);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn13;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Half*(assowei12+assowei13);
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 4: // 3 cats, 2 syn(23, 13);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn23; optiontemp->m_ppSynRules[1]=syn13;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Half*(assowei23+assowei13);
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 5: // 3 cats, 1 syn(12);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=1; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
							if(comp2ret==1)
								{ assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp2ret==2)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 6: // 3 cats, 1 syn(23); 
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=1; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn23;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
							if(comp2ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
							else if(comp2ret==2)
								{ assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
		  	  					  synstr=_Half*(assowei23+assowei13);
								}
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 7: // 3 cats, 1 syn(13);
		  			  		// syntactic rule part;
			  				optiontemp->m_nNumSynRules=1; 
			  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
			  				optiontemp->m_ppSynRules[0]=syn13;
			  				// combine strength part;
			  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  	  				assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
							if(comp2ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp2ret==2)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei23+assowei13);
								}
		  	  				optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  case 8: // 3 cats, 0 syn;
		  			  		// syntactic rule part;
			  				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
			  				// combine strength part;
			  				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
							synstr=0.0;
							comp3ret=CGenFuncClass::comp3values_big(catlist1->getAssoWei(), catlist2->getAssoWei(), catlist3->getAssoWei());
							if(comp3ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
		  	  					  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp3ret==2)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
							else if(comp3ret==3)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
		  	  					  synstr=_Half*(assowei23+assowei13);
								}
							optiontemp->m_dCombinStr=lexstr+synstr;
		  			  		break;
		  			  default: break;
		  			}
				break;
		  case 9: // 2 cats(S+V), 1 syn(12);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn12;
		  		// combine strength part;
		  		lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		optiontemp->m_dCombinStr=lexstr+synstr;
		  		break;
		  case 10: // 2 cats(S+V), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 11: // 2 cats(S+O), 1 syn(13);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn13;
		  		// combine strength part;
		  		lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		optiontemp->m_dCombinStr=lexstr+synstr;
		  		break;
		  case 12: // 2 cats(S+O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		 		// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 13: // 2 cats(V+O), 1 syn (23);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist2->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn23;
		  		// combine strength part;
		  		lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		optiontemp->m_dCombinStr=lexstr+synstr;
		  		break;
		  case 14: // 2 cats(V+O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 15: // 1 cats(S), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
		 		optiontemp->m_dCombinStr=lexstr+synstr;
				break;
		  case 16: // 1 cats(V), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
	  			optiontemp->m_dCombinStr=lexstr+synstr;		  
				break;
		  case 17: // 1 cats(O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist3->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
				synstr=_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
	  			optiontemp->m_dCombinStr=lexstr+synstr;		  
				break;
		  case 18: // 0 cat, 0 syn; 
		  		// category part;
		  		optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL; 
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;		  		
		  		lexstr=_Third*(rule1->getLexStr()+rule2->getLexStr()+rule3->getLexStr());
		  		synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
		  		optiontemp->m_dCombinStr=lexstr+synstr;
		  		break;
		  default: break;		
		}	
	getpIMMem()->UpdOptionComb(optiontemp);	// update optiontemp into IMMem;					
	optiontemp=NULL;	// recollect optiontemp;
}

// "Predicate<Agent>" meanings;
void CAgent::setComb1Word1(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred)
{ // use 1 word + 1 rand word rules;
  // type=3, subtype=1, word 1 + rand word2; subtype=2, rand word 1 + word 2;
	assert(meantype==1); assert((type==3)&&((subtype==1)||(subtype==2)));
	int i;	
	CLexRule *wordrule=NULL;
	CatList *wordcatlist=NULL;
	
	if(subtype==1)
		{ // word 1 + rand word 2; 
		  for(i=*numHolist;i<*numHolist+*numAg;i++)
			{ wordrule=CandLexRule[i]; 
			  if(wordrule->getCatNum()!=0)
			  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 1, wordcatlist);
				  if(wordcatlist!=NULL) fillOptPro1(meantype, type, 1, wordrule, wordcatlist);	// wordrule has a cat;
				  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// wordrule has no cat;
				  wordcatlist=NULL;	// recollect wordcatlist;
			  	}
			  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// wordrule has no cat;
			  wordrule=NULL;	// recollect rule1;			  			  
			}
		}
	else if(subtype==2)
		{ // rand word 1 + word 2; 
		  for(i=*numHolist+*numAg;i<*numHolist+*numAg+*numPred;i++)
			{ wordrule=CandLexRule[i]; 
			  if(wordrule->getCatNum()!=0)
			  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 2, wordcatlist);
				  if(wordcatlist!=NULL) fillOptPro1(meantype, type, 1, wordrule, wordcatlist);	// wordrule has a cat;
				  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// wordrule has no cat;
				  wordcatlist=NULL;	// recollect wordcatlist;
			  	}
			  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// wordrule has no cat;
			  wordrule=NULL;	// recollect rule2;		  
			}
		}	
}

void CAgent::setComb2Word1(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred)
{ // use 2 word rules;
  // type=2; subtype=0;	
	assert(meantype==1); assert((type==2)&&(subtype==0));
	int i, j;
	CLexRule *rule1=NULL, *rule2=NULL;
	CatList *catlist1=NULL, *catlist2=NULL;
	CSynRule *syn12=NULL;
		
	for(i=*numHolist;i<*numHolist+*numAg;i++)
		for(j=*numHolist+*numAg;j<*numHolist+*numAg+*numPred;j++)
			{ rule1=CandLexRule[i]; rule2=CandLexRule[j];
			  if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0))
			  	{ catlist1=NULL; catlist2=NULL; 
			  	  syn12=NULL; 
			  	  getpLTMem()->ChkRela2CatPro(1, rule1, rule2, 1, 2, catlist1, catlist2, syn12);
				  if((catlist1!=NULL)&&(catlist2!=NULL))
				  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, rule1, rule2, catlist1, catlist2, syn12);	// 2 cat, 1 syn;
				  	  else fillOptPro2(meantype, type, 2, rule1, rule2, catlist1, catlist2, NULL);	// 2 cat, 0 syn;
				  	}
				  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
			  	  syn12=NULL;	// recollect syn12;
			  	}
			  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0))
			  	{ catlist1=NULL; rule1->FindCatListwithHighAsso(0, 1, catlist1);
			  	  if(catlist1!=NULL) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
				  catlist1=NULL;	// recollect catlist1;
			  	}
			  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0))
			  	{ catlist2=NULL; rule2->FindCatListwithHighAsso(0, 2, catlist2);
			  	  if(catlist2!=NULL) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
				  catlist2=NULL;	// recollect catlist2;
			  	}
			  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
			  rule1=NULL; rule2=NULL;	// recollect rule1 and rule2;			  
			}
}

void CAgent::BldComb1(int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred)
{ // build up OptionComb for "Predicate<Agent>" meanings;
  // type=0, holistic rules; 1, rand holistic rules; 2, two words; 
  // 3, 1, word 1 + rand word 2; 3, 2, rand word 1 + word 2; 
	assert(((0<=type)&&(type<=2)&&(subtype==0))||((type==3)&&((subtype==1)||(subtype==2))));

	switch(type)
		{ case 0: case 1: setCombHolist(1, type, subtype, CandLexRule, numCandLexRule, numHolist); break;	// use holistic or rand holist rules;
		  case 2: setComb2Word1(1, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred); break;	// use 2 word rules;
		  case 3: setComb1Word1(1, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred); break;	// use 1 word rule + 1 rand word rule;
		  default: break;
		}
}

void CAgent::SetCand1(int meantype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred)
{ // decide how many ways to express "Predicate<Agent>" meaning, and record related lexical rules/categories/syntactic rules into IMMem;
  	assert((meantype==1)||(meantype==3)||(meantype==5));
	
	// based on current rules, select candidate rules;
	if(meantype==1)
		{ if((*numHolist!=0)&&!((*numAg!=0)&&(*numPred!=0))) BldComb1(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use holistic rule;
		  else if((*numHolist==0)&&(*numAg!=0)&&(*numPred!=0)) BldComb1(2, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use 2 word rules;  		  
	  	  else if((*numHolist!=0)&&(*numAg!=0)&&(*numPred!=0))
	  	  	{ // compete between holistic rules and 2 word rules;
			  BldComb1(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);
 			  BldComb1(2, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	  		 
	  	  	}
		}
	else if(meantype==3)
		{ if(getOnlyHolist()==0)
			{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateWord()))
		  		{ if((*numAg!=0)&&(*numPred==0)) BldComb1(3, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use word 1 + rand word 2;
	  		  	  else if((*numAg==0)&&(*numPred!=0)) BldComb1(3, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use rand word 1 + word 2;
	  			}
			}
		  else if(getOnlyHolist()==1)
		  	{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateHolist())) BldComb1(1, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use rand holistic rule;
		  	}		  	
		}
	else if(meantype==5)
		{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateHolist())) BldComb1(1, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred);	// use rand holistic rule;
		}	
}

// "Predicate<Agent, Patient>" meanings;
void CAgent::setCombWordPhrase2(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // use 1 word + 1 phrase rule;
  // type=2, subtype=1, Ag+PredPat; subtype=2, Pred2+AgPat; 2, subtype=3, Pat+AgPred;
  	assert(meantype==2); assert((type==2)&&((subtype==1)||(subtype==2)||(subtype==3)));
	int i, j;
	CLexRule *wordrule=NULL, *phraserule=NULL;
	CatList *wordcatlist=NULL, *phrasecatlist=NULL;
	CSynRule *syn12=NULL;
	
	switch(subtype)
		{ case 1: // use Ag+PredPat;
				for(i=*numHolist;i<*numHolist+*numAg;i++)
					for(j=*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat;j<*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat+*numPredPat;j++)
						{ wordrule=CandLexRule[i]; phraserule=CandLexRule[j];
						  if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()!=0))
						  	{ wordcatlist=NULL; phrasecatlist=NULL; 
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(2, wordrule, phraserule, 1, 7, wordcatlist, phrasecatlist, syn12);
							  if((wordcatlist!=NULL)&&(phrasecatlist!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, wordrule, phraserule, wordcatlist, phrasecatlist, syn12);	// 2 cats, 1 syn;
		 			 		  	  else fillOptPro2(meantype, type, 2, wordrule, phraserule, wordcatlist, phrasecatlist, NULL);	// 2 cats, 0 syn;
							  	}
		 			 		  else if((wordcatlist!=NULL)&&(phrasecatlist==NULL)) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((wordcatlist==NULL)&&(phrasecatlist!=NULL)) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  wordcatlist=NULL; phrasecatlist=NULL;	// recollect wordcatlist, phrasecatlist;
						  	  syn12=NULL;	// recollect syn12;
						  	}
						  else if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()==0))
						  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 1, wordcatlist);
						  	  if(wordcatlist!=NULL) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 wordcat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;	
							  wordcatlist=NULL;	// recollect wordcatlist;
						  	}
						  else if((wordrule->getCatNum()==0)&&(phraserule->getCatNum()!=0))
						  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 7, phrasecatlist);
						  	  if(phrasecatlist!=NULL) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 phrasecat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  phrasecatlist=NULL;	// recollect phrasecatlist;
						  	}
						  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  wordrule=NULL; phraserule=NULL;	// recollect wordrule and phraserule;
						}
				break;
		  case 2: // use Pred2+AgPat;
		  		for(i=*numHolist+*numAg;i<*numHolist+*numAg+*numPred;i++)
					for(j=*numHolist+*numAg+*numPred+*numPat+*numAgPred;j<*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat;j++)
						{ wordrule=CandLexRule[i]; phraserule=CandLexRule[j];
						  if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()!=0))
						  	{ wordcatlist=NULL; phrasecatlist=NULL;
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(2, wordrule, phraserule, 3, 6, wordcatlist, phrasecatlist, syn12);
							  if((wordcatlist!=NULL)&&(phrasecatlist!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, wordrule, phraserule, wordcatlist, phrasecatlist, syn12);	// 2 cats, 1 syn;
		 			 		  	  else fillOptPro2(meantype, type, 2, wordrule, phraserule, wordcatlist, phrasecatlist, NULL);	// 2 cats, 0 syn;
							  	}
		 			 		  else if((wordcatlist!=NULL)&&(phrasecatlist==NULL)) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((wordcatlist==NULL)&&(phrasecatlist!=NULL)) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  wordcatlist=NULL; phrasecatlist=NULL;	// recollect wordcatlist, phrasecatlist;
						  	  syn12=NULL;	// recollect syn12;
						  	}
						  else if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()==0))
						  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 3, wordcatlist);
						  	  if(wordcatlist!=NULL) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 wordcat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  wordcatlist=NULL;	// recollect wordcatlist;	
						  	}
						  else if((wordrule->getCatNum()==0)&&(phraserule->getCatNum()!=0))
						  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 6, phrasecatlist);
						  	  if(phrasecatlist!=NULL) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 phrasecat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  phrasecatlist=NULL;	// recollect phrasecatlist;
						  	}
						  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  wordrule=NULL; phraserule=NULL;	// recollect wordrule and phraserule;
						}
		  		break;
		  case 3: // use Pat+AgPred;
		  		for(i=*numHolist+*numAg+*numPred;i<*numHolist+*numAg+*numPred+*numPat;i++)
					for(j=*numHolist+*numAg+*numPred+*numPat;j<*numHolist+*numAg+*numPred+*numPat+*numAgPred;j++)
						{ wordrule=CandLexRule[i]; phraserule=CandLexRule[j];
						  if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()!=0))
						  	{ wordcatlist=NULL; phrasecatlist=NULL;
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(2, wordrule, phraserule, 4, 5, wordcatlist, phrasecatlist, syn12);
							  if((wordcatlist!=NULL)&&(phrasecatlist!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, wordrule, phraserule, wordcatlist, phrasecatlist, syn12);	// 2 cats, 1 syn;
		 			 		  	  else fillOptPro2(meantype, type, 2, wordrule, phraserule, wordcatlist, phrasecatlist, NULL);	// 2 cats, 0 syn;
							  	}
		 			 		  else if((wordcatlist!=NULL)&&(phrasecatlist==NULL)) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((wordcatlist==NULL)&&(phrasecatlist!=NULL)) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  wordcatlist=NULL; phrasecatlist=NULL;	// recollect wordcatlist, phrasecatlist;
							  syn12=NULL;	// recollect syn12;
						  	}
						  else if((wordrule->getCatNum()!=0)&&(phraserule->getCatNum()==0))
						  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 4, wordcatlist);
						  	  if(wordcatlist!=NULL) fillOptPro2(meantype, type, 3, wordrule, phraserule, wordcatlist, NULL, NULL);	// 1 wordcat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
						 	  wordcatlist=NULL;	// recollect wordcatlist;
						  	}
						  else if((wordrule->getCatNum()==0)&&(phraserule->getCatNum()!=0))
						  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 5, phrasecatlist);
						  	  if(phrasecatlist!=NULL) fillOptPro2(meantype, type, 4, wordrule, phraserule, NULL, phrasecatlist, NULL);	// 1 phrasecat, 0 syn;
							  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  phrasecatlist=NULL;	// recollect phrasecatlist;
						  	}
						  else fillOptPro2(meantype, type, 5, wordrule, phraserule, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  wordrule=NULL; phraserule=NULL;	// recollect wordrule and phraserule;
						}
		  		break;
		  default: break;
		}	
}

void CAgent::setComb3Word2(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // use 3 word rules;
  // type=3, subtype=0; 
	assert(meantype==2); assert((type==3)&&(subtype==0));
	int i, j, k;
	CLexRule *rule1=NULL, *rule2=NULL, *rule3=NULL;
	CatList *catlist1=NULL, *catlist2=NULL, *catlist3=NULL;
	CSynRule *syn12=NULL, *syn23=NULL, *syn13=NULL;
	
	for(i=*numHolist;i<*numHolist+*numAg;i++)
		for(j=*numHolist+*numAg;j<*numHolist+*numAg+*numPred;j++)
			for(k=*numHolist+*numAg+*numPred;k<*numHolist+*numAg+*numPred+*numPat;k++)
				{ rule1=CandLexRule[i]; rule2=CandLexRule[j]; rule3=CandLexRule[k];
				  // 3 categories;
				  if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0)&&(rule3->getCatNum()!=0))
				  	{ catlist1=NULL; catlist2=NULL; catlist3=NULL;
				  	  syn12=NULL; syn23=NULL; syn13=NULL;
				  	  getpLTMem()->ChkRela3CatPro(rule1, rule2, rule3, 1, 3, 4, catlist1, catlist2, catlist3, syn12, syn23, syn13);
					  // 3 categories;
					  if((catlist1!=NULL)&&(catlist2!=NULL)&&(catlist3!=NULL))
					  	{ // 3 syntactic rules;
					  	  if((syn12!=NULL)&&(syn23!=NULL)&&(syn13!=NULL)) fillOptPro3(meantype, type, 1, rule1, rule2, rule3, catlist1, catlist2, catlist3, syn12, syn23, syn13);	// 3 cats, 3 syn;
					  	  // 2 syntactic rules;
					  	  else if((syn12!=NULL)&&(syn23!=NULL)&&(syn13==NULL)) fillOptPro3(meantype, type, 2, rule1, rule2, rule3, catlist1, catlist2, catlist3, syn12, syn23, NULL);	// 3 cats, 2 syn(12, 23);
					  	  else if((syn12!=NULL)&&(syn23==NULL)&&(syn13!=NULL)) fillOptPro3(meantype, type, 3, rule1, rule2, rule3, catlist1, catlist2, catlist3, syn12, NULL, syn13);	// 3 cats, 2 syn(12, 13);
					  	  else if((syn12==NULL)&&(syn23!=NULL)&&(syn13!=NULL)) fillOptPro3(meantype, type, 4, rule1, rule2, rule3, catlist1, catlist2, catlist3, NULL, syn23, syn13);	// 3 cats, 2 syn(23, 13);
					  	  // 1 syntactic rules;
					  	  else if((syn12!=NULL)&&(syn23==NULL)&&(syn13==NULL)) fillOptPro3(meantype, type, 5, rule1, rule2, rule3, catlist1, catlist2, catlist3, syn12, NULL, NULL);	// 3 cats, 1 syn(12);
					  	  else if((syn12==NULL)&&(syn23!=NULL)&&(syn13==NULL)) fillOptPro3(meantype, type, 6, rule1, rule2, rule3, catlist1, catlist2, catlist3, NULL, syn23, NULL);	// 3 cats, 1 syn(23);
					  	  else if((syn12==NULL)&&(syn23==NULL)&&(syn13!=NULL)) fillOptPro3(meantype, type, 7, rule1, rule2, rule3, catlist1, catlist2, catlist3, NULL, NULL, syn13);	// 3 cats, 1 syn(13);
					  	  // 0 syntactic rules;
					  	  else if((syn12==NULL)&&(syn23==NULL)&&(syn13==NULL)) fillOptPro3(meantype, type, 8, rule1, rule2, rule3, catlist1, catlist2, catlist3, NULL, NULL, NULL);	// 3 cats, 0 syn;
					  	}
					  // 2 categories;
					  else if((catlist1!=NULL)&&(catlist2!=NULL)&&(catlist3==NULL))
					  	{ if(syn12!=NULL) fillOptPro3(meantype, type, 9, rule1, rule2, rule3, catlist1, catlist2, NULL, syn12, NULL, NULL);	// 2 cat(S+V), 1 syn(12);
					  	  else fillOptPro3(meantype, type, 10, rule1, rule2, rule3, catlist1, catlist2, NULL, NULL, NULL, NULL);	// 2 cats(S+V), 0 syn;
					  	}
					  else if((catlist1!=NULL)&&(catlist2==NULL)&&(catlist3!=NULL))
					  	{ if(syn13!=NULL) fillOptPro3(meantype, type, 11, rule1, rule2, rule3, catlist1, NULL, catlist3, NULL, NULL, syn13);	// 2 cats(S+O), 1 syn(13);
					  	  else fillOptPro3(meantype, type, 12, rule1, rule2, rule3, catlist1, NULL, catlist3, NULL, NULL, NULL);	// 2 cats(S+O), 0 syn;
					  	}
					  else if((catlist1==NULL)&&(catlist2!=NULL)&&(catlist3!=NULL))
					  	{ if(syn23!=NULL) fillOptPro3(meantype, type, 13, rule1, rule2, rule3, NULL, catlist2, catlist3, NULL, syn23, NULL);	// 2 cats(V+O), 1 syn(23);
					  	  else fillOptPro3(meantype, type, 14, rule1, rule2, rule3, NULL, catlist2, catlist3, NULL, NULL, NULL);	// 2 cats(V+O), 0 syn;
					  	}
					  // 1 category;
					  else if((catlist1!=NULL)&&(catlist2==NULL)&&(catlist3==NULL)) fillOptPro3(meantype, type, 15, rule1, rule2, rule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
					  else if((catlist1==NULL)&&(catlist2!=NULL)&&(catlist3==NULL)) fillOptPro3(meantype, type, 16, rule1, rule2, rule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
					  else if((catlist1==NULL)&&(catlist2==NULL)&&(catlist3!=NULL)) fillOptPro3(meantype, type, 17, rule1, rule2, rule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;	
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
					  catlist1=NULL; catlist2=NULL; catlist3=NULL;	// recollect catlist1, catlist2, catlist3;
				  	  syn12=NULL; syn23=NULL; syn13=NULL;	// recollect syn12, syn23, syn13;
				  	}
				  // 2 categories;	
				  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0)&&(rule3->getCatNum()==0))
				  	{ catlist1=NULL; catlist2=NULL;
				  	  syn12=NULL;
				  	  getpLTMem()->ChkRela2CatPro(3, rule1, rule2, 1, 3, catlist1, catlist2, syn12);
					  if((catlist1!=NULL)&&(catlist2!=NULL))
					  	{ if(syn12!=NULL) fillOptPro3(meantype, type, 9, rule1, rule2, rule3, catlist1, catlist2, NULL, syn12, NULL, NULL);	// 2 cat(S+V), 1 syn(12);
					  	  else fillOptPro3(meantype, type, 10, rule1, rule2, rule3, catlist1, catlist2, NULL, NULL, NULL, NULL); // 2 cat(S+V), 0 syn;
					  	}
					  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPro3(meantype, type, 15, rule1, rule2, rule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
					  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPro3(meantype, type, 16, rule1, rule2, rule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  		  	  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
				  	  syn12=NULL;	// recollect syn12;
				  	}
				  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0)&&(rule3->getCatNum()!=0))
				  	{ catlist1=NULL; catlist3=NULL;
				  	  syn13=NULL;
					  getpLTMem()->ChkRela2CatPro(3, rule1, rule3, 1, 4, catlist1, catlist3, syn13);
					  if((catlist1!=NULL)&&(catlist3!=NULL))
					  	{ if(syn13!=NULL) fillOptPro3(meantype, type, 11, rule1, rule2, rule3, catlist1, NULL, catlist3, NULL, NULL, syn13);	// 2 cat(S+O), 1 syn(13);
		  			  	  else fillOptPro3(meantype, type, 12, rule1, rule2, rule3, catlist1, NULL, catlist3, NULL, NULL, NULL);	// 2 cat(S+O), 0 syn;
					  	}
					  else if((catlist1!=NULL)&&(catlist3==NULL)) fillOptPro3(meantype, type, 15, rule1, rule2, rule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
					  else if((catlist1==NULL)&&(catlist3!=NULL)) fillOptPro3(meantype, type, 17, rule1, rule2, rule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  			  catlist1=NULL; catlist3=NULL;	// recollect catlist1, catlist3;
				  	  syn13=NULL;	// recollect syn13;
				  	}
				  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0)&&(rule3->getCatNum()!=0))
				  	{ catlist2=NULL; catlist3=NULL;
				  	  syn23=NULL;
				  	  getpLTMem()->ChkRela2CatPro(3, rule2, rule3, 3, 4, catlist2, catlist3, syn23);
					  if((catlist2!=NULL)&&(catlist3!=NULL))
					  	{ if(syn23!=NULL) fillOptPro3(meantype, type, 13, rule1, rule2, rule3, NULL, catlist2, catlist3, NULL, syn23, NULL);	// 2 cat(V+O), 1 syn(23);
		  			  	  else fillOptPro3(meantype, type, 14, rule1, rule2, rule3, NULL, catlist2, catlist3, NULL, NULL, NULL);	// 2 cat(V+O), 0 syn;
					  	}
					  else if((catlist2!=NULL)&&(catlist3==NULL)) fillOptPro3(meantype, type, 16, rule1, rule2, rule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
					  else if((catlist2==NULL)&&(catlist3!=NULL)) fillOptPro3(meantype, type, 17, rule1, rule2, rule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  			  catlist2=NULL; catlist3=NULL;	// recollect catlist2, catlist3;
				  	  syn23=NULL;	// recollect syn23;
				  	}
				  // 1 category;
				  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0)&&(rule3->getCatNum()==0))
				  	{ catlist1=NULL; rule1->FindCatListwithHighAsso(0, 1, catlist1);
				  	  if(catlist1!=NULL) fillOptPro3(meantype, type, 15, rule1, rule2, rule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// cat1(S), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;	
					  catlist1=NULL;	// recollect catlist1;
				  	}
				  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0)&&(rule3->getCatNum()==0))
				  	{ catlist2=NULL; rule2->FindCatListwithHighAsso(0, 3, catlist2);
 					  if(catlist2!=NULL) fillOptPro3(meantype, type, 16, rule1, rule2, rule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;	
					  catlist2=NULL;	// recollect catlist2;
				  	}
				  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()==0)&&(rule3->getCatNum()!=0))
				  	{ catlist3=NULL; rule3->FindCatListwithHighAsso(0, 4, catlist3);
					  if(catlist3!=NULL) fillOptPro3(meantype, type, 17, rule1, rule2, rule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
					  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
					  catlist3=NULL;	// recollect catlist3;
				  	}
				  // 0 category;
				  else fillOptPro3(meantype, type, 18, rule1, rule2, rule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
				  rule1=NULL; rule2=NULL; rule3=NULL;	// recollect rule1, rule2, rule3;
				}
}

void CAgent::setCombPhrase2(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // use 1 phrase + 1 rand word rules;
  // type=4, subtype=1, rand Ag + PredPat; subtype=2, rand Pred2 + AgPat; subtype=3, rand Pat + AgPred;
	assert(meantype==2); assert((type==4)&&((subtype==1)||(subtype==2)||(subtype==3)));
	int i;
	CLexRule *phraserule=NULL;
	CatList *phrasecatlist=NULL;
	
	switch(subtype)
		{ case 1: // use rand Ag + PredPat;
				for(i=*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat;i<*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat+*numPredPat;i++)
					{ phraserule=CandLexRule[i];
					  if(phraserule->getCatNum()!=0)
					  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 7, phrasecatlist);
				 	 	  if(phrasecatlist!=NULL) fillOptPro1(meantype, type, 1, phraserule, phrasecatlist);	// 1 phrasecat, 1 syn;
						  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;	
						  phrasecatlist=NULL;	// recollect phrasecatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;
					  phraserule=NULL;	// recollect phraserule;					  
					}
				break;
		  case 2: // use rand Pred2 + AgPat;
		  		for(i=*numHolist+*numAg+*numPred+*numPat+*numAgPred;i<*numHolist+*numAg+*numPred+*numPat+*numAgPred+*numAgPat;i++)
					{ phraserule=CandLexRule[i];
					  if(phraserule->getCatNum()!=0)
					  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 6, phrasecatlist);
				 	 	  if(phrasecatlist!=NULL) fillOptPro1(meantype, type, 1, phraserule, phrasecatlist);	// 1 phrasecat, 0 syn;
						  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;
						  phrasecatlist=NULL;	// recollect phrasecatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;
					  phraserule=NULL;	// recollect phraserule;
					}
				break;
		  case 3: // use rand Pat + AgPred;
		  		for(i=*numHolist+*numAg+*numPred+*numPat;i<*numHolist+*numAg+*numPred+*numPat+*numAgPred;i++)
					{ phraserule=CandLexRule[i];
					  if(phraserule->getCatNum()!=0)
					  	{ phrasecatlist=NULL; phraserule->FindCatListwithHighAsso(0, 5, phrasecatlist);
				 	 	  if(phrasecatlist!=NULL) fillOptPro1(meantype, type, 1, phraserule, phrasecatlist);	// 1 phrasecat, 0 syn;
						  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;
						  phrasecatlist=NULL;	// recollect phrasecatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, phraserule, NULL);	// 0 cat, 0 syn;
					  phraserule=NULL;	// recollect phraserule;
					}
				break;
		  default: break;
		}
}

void CAgent::setComb2Word2(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // use 2 word + 1 rand word rules;
  // type=5, subtype=1, rand Ag + Pred2 + Pat; subtype=2, Ag + rand Pred2 + Pat; subtype=3, Ag + Pred2 + rand Pat;
  	assert(meantype==2); assert((type==5)&&((subtype==1)||(subtype==2)||(subtype==3)));
	int i, j;
	CLexRule *rule1=NULL, *rule2=NULL;
	CatList *catlist1=NULL, *catlist2=NULL;
	CSynRule *syn12=NULL;
	
	switch(subtype)
		{ case 1: // use rand Ag + Pred2 + Pat;
				for(i=*numHolist+*numAg;i<*numHolist+*numAg+*numPred;i++)
					for(j=*numHolist+*numAg+*numPred;j<*numHolist+*numAg+*numPred+*numPat;j++)
						{ rule1=CandLexRule[i]; rule2=CandLexRule[j];
						  if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0))
						  	{ catlist1=NULL; catlist2=NULL; 
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(3, rule1, rule2, 3, 4, catlist1, catlist2, syn12);
							  if((catlist1!=NULL)&&(catlist2!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, rule1, rule2, catlist1, catlist2, syn12);	// 2 cat, 1 syn;
		  					  	  else fillOptPro2(meantype, type, 2, rule1, rule2, catlist1, catlist2, NULL);	// 2 cat, 0 syn;
							  	}
					  		  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
				 		 	  syn12=NULL;	// recollect syn12;
						  	}
						  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0))
						  	{ catlist1=NULL; rule1->FindCatListwithHighAsso(0, 3, catlist1);
						  	  if(catlist1!=NULL) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// cat1, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist1=NULL;	// recollect catlist1;
						  	}
						  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0))
						  	{ catlist2=NULL; rule2->FindCatListwithHighAsso(0, 4, catlist2);
						  	  if(catlist2!=NULL) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// cat2, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist2=NULL;	// recollect catlist2;
						  	}
				  		  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  rule1=NULL; rule2=NULL;	// recollect rule1 and rule2;
						}
				break;
		  case 2: // use Ag + rand Pred2 + Pat;
		  		for(i=*numHolist;i<*numHolist+*numAg;i++)
					for(j=*numHolist+*numAg+*numPred;j<*numHolist+*numAg+*numPred+*numPat;j++)
						{ rule1=CandLexRule[i]; rule2=CandLexRule[j];
						  if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0))
						  	{ catlist1=NULL; catlist2=NULL;
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(3, rule1, rule2, 1, 4, catlist1, catlist2, syn12);
							  if((catlist1!=NULL)&&(catlist2!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, rule1, rule2, catlist1, catlist2, syn12);	// 2 cat, 1 syn;
		  					  	  else fillOptPro2(meantype, type, 2, rule1, rule2, catlist1, catlist2, NULL);	// 2 cat, 0 syn;
							  	}
					  		  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
						  	  syn12=NULL;	// recollect syn12;
						  	}
						  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0))
						  	{ catlist1=NULL; rule1->FindCatListwithHighAsso(0, 1, catlist1);
						  	  if(catlist1!=NULL) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// cat1, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist1=NULL;	// recollect catlist1;
						  	}
						  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0))
						  	{ catlist2=NULL; rule2->FindCatListwithHighAsso(0, 4, catlist2);
						  	  if(catlist2!=NULL) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// cat2, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist2=NULL;	// recollect catlist2;
						  	}
				  		  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  rule1=NULL; rule2=NULL;	// recollect rule1 and rule2;
						}
				break;
		  case 3: // use Ag + Pred2 + rand Pat;
		  		for(i=*numHolist;i<*numHolist+*numAg;i++)
					for(j=*numHolist+*numAg;j<*numHolist+*numAg+*numPred;j++)
						{ rule1=CandLexRule[i]; rule2=CandLexRule[j];
						  if((rule1->getCatNum()!=0)&&(rule2->getCatNum()!=0))
						  	{ catlist1=NULL; catlist2=NULL; 
						  	  syn12=NULL;
						  	  getpLTMem()->ChkRela2CatPro(3, rule1, rule2, 1, 3, catlist1, catlist2, syn12);
							  if((catlist1!=NULL)&&(catlist2!=NULL))
							  	{ if(syn12!=NULL) fillOptPro2(meantype, type, 1, rule1, rule2, catlist1, catlist2, syn12);	// 2 cat, 1 syn;
		  					  	  else fillOptPro2(meantype, type, 2, rule1, rule2, catlist1, catlist2, NULL);	// 2 cat, 0 syn;
							  	}
					  		  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  			  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  			  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn; 
		  		  			  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
						  	  syn12=NULL;	// recollect syn12;
						  	}
						  else if((rule1->getCatNum()!=0)&&(rule2->getCatNum()==0))
						  	{ catlist1=NULL; rule1->FindCatListwithHighAsso(0, 1, catlist1);
						  	  if(catlist1!=NULL) fillOptPro2(meantype, type, 3, rule1, rule2, catlist1, NULL, NULL);	// cat1, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist1=NULL;	// recollect catlist1;
						  	}
						  else if((rule1->getCatNum()==0)&&(rule2->getCatNum()!=0))
						  	{ catlist2=NULL; rule2->FindCatListwithHighAsso(0, 3, catlist2);
						  	  if(catlist2!=NULL) fillOptPro2(meantype, type, 4, rule1, rule2, NULL, catlist2, NULL);	// cat2, 0 syn;
							  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
							  catlist2=NULL;	// recollect catlist2;
						  	}
				  		  else fillOptPro2(meantype, type, 5, rule1, rule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
						  rule1=NULL; rule2=NULL;	// recollect rule1 and rule2;
						}
				break;
		  default: break;
		}
}

void CAgent::setComb1Word2(int meantype, int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // use 1 word + 1 rand phrase rule;
  // type=6, subtype=1, Ag + rand PredPat; subtype=2, Pred2 + rand AgPat; subtype=3, Pat + rand AgPred;
	assert(meantype==2); assert((type==6)&&((subtype==1)||(subtype==2)||(subtype==3)));
	int i;
	CLexRule *wordrule=NULL;
	CatList *wordcatlist=NULL;
	
	switch(subtype)
		{ case 1: // use Ag + rand PredPat;
				for(i=*numHolist;i<*numHolist+*numAg;i++)
					{ wordrule=CandLexRule[i];
					  if(wordrule->getCatNum()!=0)
					  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 1, wordcatlist);
				 	 	  if(wordcatlist!=NULL) fillOptPro1(meantype, type, 1, wordrule, wordcatlist);	// 1 wordcat, 0 syn;
						  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
						  wordcatlist=NULL;	// recollect wordcatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
					  wordrule=NULL;	// recollect rule;
					}
				break;
		  case 2: // use Pred2 + rand AgPat;
		  		for(i=*numHolist+*numAg;i<*numHolist+*numAg+*numPred;i++)
					{ wordrule=CandLexRule[i];
					  if(wordrule->getCatNum()!=0)
					  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 3, wordcatlist);
				 	 	  if(wordcatlist!=NULL) fillOptPro1(meantype, type, 1, wordrule, wordcatlist);	// 1 wordcat, 0 syn;
						  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
						  wordcatlist=NULL;	// recollect wordcatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
					  wordrule=NULL;	// recollect rule;
					}
				break;
		  case 3: // use Pat + rand AgPred;
		  		for(i=*numHolist+*numAg+*numPred;i<*numHolist+*numAg+*numPred+*numPat;i++)
					{ wordrule=CandLexRule[i];
					  if(wordrule->getCatNum()!=0)
					  	{ wordcatlist=NULL; wordrule->FindCatListwithHighAsso(0, 4, wordcatlist);
				 	 	  if(wordcatlist!=NULL) fillOptPro1(meantype, type, 1, wordrule, wordcatlist);	// 1 wordcat, 0 syn;
						  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
						  wordcatlist=NULL;	// recollect wordcatlist;
					  	}
					  else fillOptPro1(meantype, type, 2, wordrule, NULL);	// 0 wordcat, 0 syn;
					  wordrule=NULL;	// recollect rule;
					}
				break;
		  default: break;
		}
}

void CAgent::BldComb2(int type, int subtype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // build up OptionComb for "Predicate<Agent, Patient>" meanings;
  // build up OptionComb for "Predicate<Agent>" meanings;
  // type=0, holistic rules; 1, rand holistic rules; 
  // 2, 1, word 1 + phrase 23; 2, 2, word 2 + phrase 13; 2, 3, word 3 + phrase 12;
  // 3, word 1 + word 2 + word 3;
  // 4, 1, rand word 1 + phrase 23; 4, 2, rand word 2 + phrase 13; 4, 3, rand word 3 + phrase 12;
  // 5, 1, rand word 1 + word 2 + word 3; 5, 2, word 1 + rand word 2 + word 3; 5, 3, word 1 + word 2 + rand word 3;
  // 6, 1, word 1 + rand phrase 23; 6, 2, word 2 + rand phrase 13; 6, 3, word 3 + rand phrase 12;
	assert((((type==0)||(type==1)||(type==3))&&(subtype==0))||(((type==2)||(type==4)||(type==5)||(type==6))&&((subtype==1)||(subtype==2)||(subtype==3))));

  	switch(type)
		{ case 0: case 1: setCombHolist(2, type, subtype, CandLexRule, numCandLexRule, numHolist); break;	// use holistic or rand holist rules;
		  case 2: setCombWordPhrase2(2, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat); break;	// use 1 word + 1 phrase rule;
		  case 3: setComb3Word2(2, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat); break;	// use 3 word rules;
		  case 4: setCombPhrase2(2, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat); break;	// use 1 rand word + 1 phrase rule;
		  case 5: setComb2Word2(2, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat); break;	// 1 rand word + 2 words;
		  case 6: setComb1Word2(2, type, subtype, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat); break;	// use 1 word + 1 rand phrase rule;
		  default: break;
  		}
}

void CAgent::SetCand2(int meantype, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // decide how many ways to express "Predicate<Agent, Patient>" meaning, and record related lexical rules/categories/syntactic rules into IMMem;
	assert((meantype==1)||(meantype==2)||(meantype==4)||(meantype==5));
	
	// based on current rules, select candidate rules;
	if(meantype==1)
		{ if((*numAg==0)&&(*numPred==0)&&(*numPat==0)) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
		  // 1 word rule;
	  	  else if((*numAg!=0)&&(*numPred==0)&&(*numPat==0))
	  		{ if(*numHolist==0) BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + phrase 23;
	  	  	  else if(*numHolist!=0)
	  		  	{ if(*numPredPat!=0)
	  		  		{ // compete of holistic rule and word 1 + phrase 23; 
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numPredPat==0) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
	  		  	}
	  	  	}
	  	  else if((*numAg==0)&&(*numPred!=0)&&(*numPat==0))
		  	{ if(*numHolist==0) BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 2 + phrase 13;
	  		  else if(*numHolist!=0)
	  		  	{ if(*numAgPat!=0)
	  		  		{ // compete of holistic rule and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numAgPat==0) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
				}
		  	}
	  	  else if((*numAg==0)&&(*numPred==0)&&(*numPat!=0))
		  	{ if(*numHolist==0) BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 3 + phrase 12; 
	  	  	  else if(*numHolist!=0)
	  		  	{ if(*numAgPred!=0)
	  		  		{ // compete of holistic rule and word 3 + phrase 12;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numAgPred==0) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
	  		  	}
		  	}
	  	  // 2 word rules;
	  	  else if((*numAg!=0)&&(*numPred!=0)&&(*numPat==0))
	  		{ if((*numPredPat==0)&&(*numAgPat==0)) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule; 
	  	  	  else if((*numPredPat!=0)&&(*numAgPat==0))
	  			{ if(*numHolist==0) BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + phrase 23; 
	  		  	  else if(*numHolist!=0)
	  		  	  	{ // compete of holistic rule and word 1 + phrase 23;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	  			}
	  		  else if((*numPredPat==0)&&(*numAgPat!=0))
		  	  	{ if(*numHolist==0) BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 2 + phrase 13;
	  		  	  else if(*numHolist!=0)
	  		  	  	{ // compete of holistic rule and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	  		  	}
	  		  else if((*numPredPat!=0)&&(*numAgPat!=0))
	  		  	{ if(*numHolist==0)
	  		  		{ // compete word 1 + phrase 23 and word 2 + phrase 13;
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numHolist!=0)
	  		  	  	{ // compete holistic rule, word 1 + phrase 23 and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	  		  	}
	  	  	}
	  	  else if((*numAg==0)&&(*numPred!=0)&&(*numPat!=0))
	  	  	{ if((*numAgPat==0)&&(*numAgPred==0)) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
	  	  	  else if((*numAgPat!=0)&&(*numAgPred==0))
	  		  	{ if(*numHolist==0) BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 2 + phrase 13;
			  	  else if(*numHolist!=0)
	  		  	  	{ // compete of holistic rule and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}	  	  	
	  		  	}
			  else if((*numAgPat==0)&&(*numAgPred!=0))
	  	 	 	{ if(*numHolist==0) BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 3 + phrase 12;
			  	  else if(*numHolist!=0)
	  	  		  	{ // compete of holistic rule and word 3 + phrase 12;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  	  		  	}
	 	 	  	}
	 	 	  else if((*numAgPat!=0)&&(*numAgPred!=0))
	  		  	{ if(*numHolist==0)
	  		  		{ // compete word 2 + phrase 13 and word 3 + phrase 12;
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numHolist!=0)
	  		  	  	{ // compete holistic rules, word 2 + phrase 13 and word 3 + phrase 12;
	  		  	  	  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	 	 	  	}
	  	  	}
	  	  else if((*numAg!=0)&&(*numPred==0)&&(*numPat!=0))
	  	  	{ if((*numPredPat==0)&&(*numAgPred==0)) BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use holistic rule;
	  	  	  else if((*numPredPat!=0)&&(*numAgPred==0))
	  		  	{ if(*numHolist==0) BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + phrase 23; 
				  else if(*numHolist!=0)
	  		  	  	{ // compete holistic rule and word 1 + phrase 23;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	  		  	}
	  		  else if((*numPredPat==0)&&(*numAgPred!=0))
	  		  	{ if(*numHolist==0) BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 3 + phrase 12; 
			  	  else if(*numHolist!=0)
	  		  	  	{ // compete of holistic rule and word 3 + phrase 12;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
	  		  	}
	  		  else if((*numPredPat!=0)&&(*numAgPred!=0))
	  		  	{ if(*numHolist==0)
	  		  		{ // compete word 1 + phrase 23 and word 3 + phrase 12;
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  		}
	  		  	  else if(*numHolist!=0)
	  		  	  	{ // compete holistic rules, word 1 + phrase 23 and word 3 + phrase 12;
	  		  	  	  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  		  	  	}
				}
	  	  	}
	  	  // 3 word rules;
	  	  else if((*numAg!=0)&&(*numPred!=0)&&(*numPat!=0))
	  	  	{ // no phrase rule; 
	  	  	  if((*numAgPred==0)&&(*numPredPat==0)&&(*numAgPat==0))
	  			{ if(*numHolist==0) BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + word 2 + word 3; 
			  	  else if(*numHolist!=0)
	  			  	{ // compete of holistic rule and 3 word rules;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					}
	  			}
	  	  	  // 1 phrase rule;
	  	  	  else if((*numAgPred!=0)&&(*numPredPat==0)&&(*numAgPat==0))
	  		  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules and word 3 + phrase 12;
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules and word 3 + phrase 12;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  	  	}
	  	  	  	}
	  	  	  else if((*numAgPred==0)&&(*numPredPat!=0)&&(*numAgPat==0))
	  	  	  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules and word 1 + phrase 23;
	  	  	  		  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rule, 3 word rules and word 1 + phrase 23;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  	  	}
	  	  	  	}
	  	  	  else if((*numAgPred==0)&&(*numPredPat==0)&&(*numAgPat!=0))
	  	  	  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules and word 2 + phrase 13;
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  	  	}
	  	  	  	}
	  	  	  // 2 phrase rules;
	  	  	  else if((*numAgPred!=0)&&(*numPredPat!=0)&&(*numAgPat==0))
	  		  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules, word 3 + phrase 12, and word 1 + phrase 23;
	  	  	  		  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules, word 3 + phrase 12, and word 1 + phrase 23;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  	  	}	  		  	
	  	  	  	}
	  	  	  else if((*numAgPred==0)&&(*numPredPat!=0)&&(*numAgPat!=0))
	  		  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules, word 1 + phrase 23, and word 2 + phrase 13;
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules, word 1 + phrase 23, and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
		  	  	  	}	  		  	
	  	  	  	}
	  	  	  else if((*numAgPred!=0)&&(*numPredPat==0)&&(*numAgPat!=0))
	  		  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules, word 3 + phrase 12, and word 2 + phrase 13;
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules, word 3 + phrase 12, and word 2 + phrase 13;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  	  	}	  		  	
	  	  	  	}
	  	  	  // 3 phrase rules;
	  	  	  else if((*numAgPred!=0)&&(*numPredPat!=0)&&(*numAgPat!=0))
	  		  	{ if(*numHolist==0)
	  	  	  		{ // compete of 3 word rules, word 1 + phrase 23, word 2 + phrase 13, and word 3 + phrase 12;
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
			  		}
	  	  	  	  else if(*numHolist!=0)
	  	  	  	  	{ // compete of holistic rules, 3 word rules, word 1 + phrase 23, word 2 + phrase 13, and word 3 + phrase 12;
					  BldComb2(0, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(3, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  BldComb2(2, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
		  	  	  	}	  		  	
	  	  	  	}
	  	  	}
		}
	else if(meantype==2)
		{ if(getOnlyHolist()==0)
			{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateWord()))
				{ // no word rules;	
			  	  if((*numAg==0)&&(*numPred==0)&&(*numPat==0))
			  		{ // 1 phrase rule;
			 	 	  if((*numAgPred!=0)&&(*numPredPat==0)&&(*numAgPat==0)) BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 3 + phrase 12;	
					  else if((*numAgPred==0)&&(*numPredPat!=0)&&(*numAgPat==0)) BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 1 + phrase 23;
					  else if((*numAgPred==0)&&(*numPredPat==0)&&(*numAgPat!=0)) BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 2 + phrase 13;
					  // 2 phrase rules;
					  else if((*numAgPred!=0)&&(*numPredPat!=0)&&(*numAgPat==0))
			  	  		{ // compete of rand word 3 + phrase 12 and rand word 1 + phrase 23;	
						  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
				  		}
					  else if((*numAgPred==0)&&(*numPredPat!=0)&&(*numAgPat!=0))
	 			 	  	{ // compete of rand word 1 + phrase 23 and rand word 2 + phrase 13;
						  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  	}
	  				  else if((*numAgPred!=0)&&(*numPredPat==0)&&(*numAgPat!=0))
	  				  	{ // compete of rand word 3 + phrase 12 and rand word 2 + phrase 13;
						  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  	}
	 		 		  // 3 phrase rules;
	  				  else if((*numAgPred!=0)&&(*numPredPat!=0)&&(*numAgPat!=0))
	  				  	{ // compete of rand word 3 + phrase 12, rand word 1 + phrase 23, and rand word 2 + phrase 13;
						  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  	}
			  	  	}
		  		  // 1 word rule;
				  else if((*numAg!=0)&&(*numPred==0)&&(*numPat==0))
	  				{ if((*numAgPred!=0)&&(*numAgPat==0)) BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 3 + phrase 12;
				 	  else if((*numAgPred==0)&&(*numAgPat!=0)) BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 2 + phrase 13;
					  else if((*numAgPred!=0)&&(*numAgPat!=0))
				  	  	{ // compete of rand word 3 + phrase 12 and rand word 2 + phrase 13;
	 			 	  	  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						}
			  		}
				  else if((*numAg==0)&&(*numPred!=0)&&(*numPat==0))
			  		{ if((*numAgPred!=0)&&(*numPredPat==0)) BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 3 + phrase 12;
				  	  else if((*numAgPred==0)&&(*numPredPat!=0)) BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 1 + phrase 23;
					  else if((*numAgPred!=0)&&(*numPredPat!=0))
	 			 	  	{ // compete of rand word 3 + phrase 12 and rand word 1 + phrase 23;
	 			 	  	  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
				 	  	}
				  	}
				  else if((*numAg==0)&&(*numPred==0)&&(*numPat!=0))
	  				{ if((*numPredPat!=0)&&(*numAgPat==0)) BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 1 +  phrase 23;
				  	  else if((*numPredPat==0)&&(*numAgPat!=0)) BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 2 + phrase 13;
				  	  else if((*numPredPat!=0)&&(*numAgPat!=0))
	  				  	{ // compete of rand word 2 + phrase 13 and rand word 1 + phrase 23;
	  				  	  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
	  				  	  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						}
				  	}
				  // 2 word rules;
				  else if((*numAg!=0)&&(*numPred!=0)&&(*numPat==0))
  	 		 		{ if(*numAgPred==0) BldComb2(5, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + word 2 + rand word 3;
				  	  else if(*numAgPred!=0)
	 			 	  	{ // compete of word 1 + word 2 + rand word 3 and phrase 12 + rand word 3;
						  BldComb2(5, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
				  	  	}
				  	}
				  else if((*numAg==0)&&(*numPred!=0)&&(*numPat!=0))
  			  		{ if(*numPredPat==0) BldComb2(5, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// rand word 1 + word 2 + word 3;
			 	  	  else if(*numPredPat!=0)
  	 			 	  	{ // compete of rand word 1+ word 2 + word 3 and phrase 23 + rand word 1;
						  BldComb2(5, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
				  	  	}
				  	}
				  else if((*numAg!=0)&&(*numPred==0)&&(*numPat!=0))
  			  		{ if(*numAgPat==0) BldComb2(5, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word 1 + rand word 2 + word 3;
				 	  else if(*numAgPat!=0)
  				  	  	{ // compete of word 1 + rand word 2 + word 3 and phrase 13 + rand word 2;
						  BldComb2(5, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
						  BldComb2(4, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);
					  	}
				  	}
				}
			}
		  else if(getOnlyHolist()==1)
		  	{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateHolist())) BldComb2(1, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use rand holistic rule;
		  	}
		}
	else if(meantype==4)
		{ if(getOnlyHolist()==0)
			{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRatePhrase()))
				{ if((*numAg!=0)&&(*numPred==0)&&(*numPat==0)) BldComb2(6, 1, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word1+ rand phrase23; 
				  else if((*numAg==0)&&(*numPred!=0)&&(*numPat==0)) BldComb2(6, 2, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word2+ rand phrase13;
				  else if((*numAg==0)&&(*numPred==0)&&(*numPat!=0)) BldComb2(6, 3, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// word3+ rand phrase12;
				}
			}
		  else if(getOnlyHolist()==1)
		  	{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateHolist())) BldComb2(1, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use rand holistic rule;
		  	}
		}
	else if(meantype==5)
		{ if(FLOAT_SM_EQ(Rand0_1, getChildAdultAbiRatio()*getRandCrtRateHolist())) BldComb2(1, 0, CandLexRule, numCandLexRule, numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat);	// use rand holistic rule;
		}
}

void CAgent::Case2(CCat *newCat1, CCat *newCat2, CSynRule *newSyn1)
{ // Case 2: 2 cats, 1 syn;
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newSyn1!=NULL));
	int originaltype, mergetype;

	originaltype=0; newSyn1->getMatchTyp(&originaltype, newCat1, newCat2);
	mergetype=0; getpLTMem()->InSynRule(newSyn1, &mergetype);
	newSyn1->getReMatCat(originaltype, mergetype, newCat1, newCat2);
	getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	
	getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);
}

void CAgent::Case345(int type, CCat *newCat1, CCat *newCat2, CSynRule *newSyn1)
{ // case 3: 1 cat(cat1), 0 syn; case 4: 1 cat(cat2), 0 syn; case 5: 0 cat, 0 syn;
	assert((type==3)||(type==4)||(type==5)); assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newSyn1!=NULL));
	bool isCat1, isCat2;
	
	switch(type)
		{ case 3: // 1 cat(cat1), 0 syn;
				getpLTMem()->InCategory(newCat2); 
				isCat1=getpLTMem()->Judge_InCat(newCat1);
				if(isCat1==0)
					{ // newCat1 disappear; newCat2 and newSyn1 must disappear;
				  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					}					
				else Case2(newCat1, newCat2, newSyn1);	// Cat1 still exists; 
				break;
		  case 4: // 1 cat(cat2), 0 syn;
		  		getpLTMem()->InCategory(newCat1);
				isCat2=getpLTMem()->Judge_InCat(newCat2);
				if(isCat2==0)
					{ // Cat2 disappear; newCat1 and newSyn1 must disappear;
				  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					}
				else Case2(newCat1, newCat2, newSyn1);	// Cat2 still exists; 
				break;
		  case 5: // 0 cat, 0 syn;
				getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
				isCat1=getpLTMem()->Judge_InCat(newCat1);
				if(isCat1==0)
				  	{ // newCat1 disappear; newCat2 and newSyn1 must be disappear;
				  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					}
				else Case2(newCat1, newCat2, newSyn1);	// newCat1 still exists; 
				break;
		  default: break;
		}
}
			
void CAgent::StoreCatSyn(CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1)
{ // store newCat1-2, newSyn1 into LTMem;
  // m_nMeanType=1; "Predicate<Agent>" meaning;
  	// m_nType=2, 2 word rules;
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=2, 1 word + 1 phrase rules;
		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newSyn1!=NULL));
	
	switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
		{ case 1: break;	// 2 cats, 1 syn; no need to insert any new rules/categories;
		  case 2: Case2(newCat1, newCat2, newSyn1); break;	// 2 cats, 0 syn; insert newSyn1;
		  case 3: Case345(3, newCat1, newCat2, newSyn1); break;	// 1 cat(cat1), 0 syn; insert newCat2, newSyn1;
		  case 4: Case345(4, newCat1, newCat2, newSyn1); break;	// 1 cat(cat2), 0 syn; insert newCat1, newSyn1;
		  case 5: Case345(5, newCat1, newCat2, newSyn1); break;	// 0 cat, 0 syn; insert newCat1, newCat2, newSyn1;
		  default: break;
		}
}


void CAgent::StoreWordPhraCatSyn(CLexRule *&newWordPhra, CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1)
{ // 	store newWord/newPhrase, newCat1-2, newSyn1 into LTMem;
  // m_nMeanType=1; "Predicate<Agent>" meaning;
	// m_nType=3, 1 word + 1 rand word;
		// m_nSubType=1, word 1 + rand word 2, 1 cat, 0 syn;
		// m_nSubType=2, word 1 + rand word 2, 0 cat, 0 syn;
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=4, 1 phrase + 1 rand word;
		// m_nSubType=1, 1 phrase + rand word 2, 1 cat, 0 syn;
		// m_nSubType=2, 1 phrase + rand word 2, 0 cat, 0 syn;
	// m_nType=6, 1 word + 1 rand phrase rule;
		// m_nSubType=1, word 1 + rand phrase 2, 1 cat, 0 syn;
		// m_nSubType=2, word 1 + rand phrase 2, 0 cat, 0 syn;
	assert((newWordPhra!=NULL)&&(newCat1!=NULL)&&(newCat2!=NULL)&&(newSyn1!=NULL));
	CLexRule *lexTemp1=getpIMMem()->getpOptionComb(0)->m_ppLexRules[0]; CLexRule *lexTemp2=getpIMMem()->getpOptionComb(0)->m_ppLexRules[1];	// keep lex1-2;
	bool isLexTemp1, isLexTemp2, isCat1, isCat2;
	
	if(newWordPhra==lexTemp1)
		{ switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
			{ case 1: // rand word 1 + word/phrase 2; 1 cat(cat2), 0 syn;
					getpLTMem()->InLexRule(newWordPhra); 
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
					if(isLexTemp2==0)
						{ // lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(1, newWordPhra, NULL, NULL);	// newWordPhra exists;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
						  	{ // newCat2 disappear; newCat1 and newSyn1 must disappear;
							  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							}
						  else Case345(4, newCat1, newCat2, newSyn1);	// newCat2 still exists; 
						}
					else Case345(4, newCat1, newCat2, newSyn1);	// lex2 still exists; 
					break;
			  case 2: // rand word 1 + word/phrase 2; 0 cat, 0 syn;
				  	getpLTMem()->InLexRule(newWordPhra);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
					if(isLexTemp2==0)
						{ // lex2 disappear; newCat1, newCat2 and newSyn1 must disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(1, newWordPhra, NULL, NULL);	// newWordPhra exists;
						  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						}
					else Case345(5, newCat1, newCat2, newSyn1);	// lex2 still exists; 
					break;
			  default: break;
			}
		}
	else if(newWordPhra==lexTemp2)
	  	{ switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
	  		{ case 1: // word 1 + rand word/phrase 2; 1 cat(cat1), 0 syn;
					getpLTMem()->InLexRule(newWordPhra);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1);
					if(isLexTemp1==0)
						{ // lex1 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(1, newWordPhra, NULL, NULL);	// newWordPhra exists;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
							{ // newCat1 disappear; newCat2 and newSyn1 must disappear;
							  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							}
						  else Case345(3, newCat1, newCat2, newSyn1);	// newCat1 still exists; 
						}
					else Case345(3, newCat1, newCat2, newSyn1);	// lex1 still exists; 
					break;
	  		  case 2: // word 1 + rand word/phrase 2; 0 cat, 0 syn;
					getpLTMem()->InLexRule(newWordPhra);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1);
					if(isLexTemp1==0)
						{ // lex1 disappear; newCat1, newCat2 and newSyn1 must disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(1, newWordPhra, NULL, NULL);	// newWordPhra exists;
						  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						}
					else Case345(5, newCat1, newCat2, newSyn1);	// lex1 still exists; 
					break;
	  		  default: break;
	  		}
	  	}
}						  

// different cases in StoreCat123Syn123;
void CAgent::Case567(int type, int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 5: 3 cats, 1 syn(12); case 6: 3 cats, 1 syn(23); case 7: 3 cats, 1 syn(13);
	assert((type==5)||(type==6)||(type==7)); assert((1<=index)&&(index<=3)); assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isSyn1, isSyn2, isCat1, isCat2, isCat3;
	
	switch(type)
		{ case 5: // case 5: 3 cats, 1 syn(12); 
				switch(index)
					{ case 1: // Syn1: Cat1<->Cat2; newSyn2: Cat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
							isSyn1=getpLTMem()->Judge_InSyn(newSyn1);
							if(isSyn1==0)
								{ // Syn1 disappear;
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
					  		  	  if(isCat1==0)
									{ // Cat1 disappear;
									  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, Cat3;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}
					  		  	  else
					  		  	  	{ // Cat1 still exists;
					  		  	  	  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}
								}
							else
								{ // Syn1 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
					  			}
							break;
		  			  case 2: // newSyn1: Cat2<->Cat3; newSyn2: Cat1<->Cat3;
							printf("Wrong in Case5\n");
		  					break;
		  			  case 3: // Syn1: Cat1<->Cat2; newSyn2: Cat1<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
							isSyn1=getpLTMem()->Judge_InSyn(newSyn1);
					  		if(isSyn1==0)
								{ // Syn1 disappear; 
								  isCat2=getpLTMem()->Judge_InCat(newCat2);
					  			  if(isCat2==0)
									{ // Cat2 disappear;
					  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, Cat3;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}
					  			  else
					  			  	{ // Cat2 still exists;
									  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}					  			  
								}
							else
								{ // Syn1 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
					  			}							
		  					break;
		  			  default: break;	
					}
				break;
		  case 6: // case 6: 3 cats, 1 syn(23);
				switch(index)
					{ case 1: // newSyn1: Cat1<->Cat2; Syn2: Cat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
							isSyn2=getpLTMem()->Judge_InSyn(newSyn2);
							if(isSyn2==0)
								{ // Syn2 disappear; 
								  isCat3=getpLTMem()->Judge_InCat(newCat3);
					  			  if(isCat3==0)
									{ // Cat3 disappear;
									  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, Cat2;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
					  			  else
					  			  	{ // Cat3 still exists;
									  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
					  			}
							else
								{ // newSyn2 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
								}							
		  					break;
		  			  case 2: // Syn1: Cat2<->Cat3; newSyn2: Cat1<->Cat3;
		  			   	 	originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
							isSyn1=getpLTMem()->Judge_InSyn(newSyn1);
					  		if(isSyn1==0)
								{ // Syn1 disappear; 
								  isCat2=getpLTMem()->Judge_InCat(newCat2);
					  			  if(isCat2==0)
									{ // Cat2 disappear;
									  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, Cat3;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}
					  			  else
					  			  	{ // Cat2 still exists;
									  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat3;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
					  				}
								}
							else
								{ // Syn1 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
					  			}
		  					break;
		  			  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->Cat3;
							printf("Wrong in Case6\n");
		  					break;
		  			  default: break;	
					}
		  		break;
		  case 7: // case 7: 3 cats, 1 syn(13);
				switch(index)
					{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->Cat3;
							printf("Wrong in Case7\n");
		  					break;
		  			  case 2: // newSyn1: Cat2<->Cat3; Syn2: Cat1<->Cat3;
							originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
							isSyn2=getpLTMem()->Judge_InSyn(newSyn2);
					  		if(isSyn2==0)
								{ // Syn2 disappear; 
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
					  			  if(isCat1==0)
									{ // Cat1 disappear;
									  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, Cat3;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
					  			  else
					  			  	{ // Cat1 still exists; 
					  			  	  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
					  			}
							else
								{ // Syn2 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
					  			}
		  					break;
		  			  case 3: // newSyn1: Cat1<->Cat2; Syn2: Cat1<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

		  			  	 	mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
							isSyn2=getpLTMem()->Judge_InSyn(newSyn2);
					  		if(isSyn2==0)
								{ // Syn2 disappear; 
								  isCat3=getpLTMem()->Judge_InCat(newCat3);
					  			  if(isCat3==0)
									{ // Cat3 disappear;
									  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, Cat2;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
					  			  else
					  			  	{ // Cat3 still exists;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
					  				}
								}
							else
								{ // Syn2 still exists;
								  getpIMMem()->getpOptionComb(0)->RemainCat(3, newCat1, newCat2, newCat3);	// Cat1, Cat2, Cat3;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(2, newSyn1, newSyn2, NULL);	// newSyn1, newSyn2 exist;
								}
		  					break;
		  			  default: break;	
					}
		  		break;
		  default: break;
		}	
}

void CAgent::Case8(int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 8: 3 cats, 0 syn;
	assert((1<=index)&&(index<=3)); assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1;
	
	switch(index)
		{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->Cat3;
				originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
				originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

				mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);				
				Case567(5, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// case 5, type1: 3 cats, 1 syn(12);
				break;
		  case 2: // newSyn1: Cat2<->Cat3; newSyn2: Cat1<->Cat3;
				originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
				originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

				mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);				
				Case567(6, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// case 6, type 2: 3 cats, 1 syn(23);
				break;
		  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->Cat3;
				originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
				originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

				mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);				
				Case567(5, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// case 5, type 3: 3 cats, 1 syn(12);
				break;
		  default: break;
		}
}

void CAgent::Case91113(int type, int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 9: 2 cats(cat1, cat2), 1 syn(12); case 11: 2 cats(cat1, cat3), 1 syn(13); case 13: 2 cats(cat2, cat3), 1 syn(23);
	assert((type==9)||(type==11)||(type==13)); assert((1<=index)&&(index<=3));
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isCat1, isCat2, isCat3;

	switch(type)
		{ case 9: // 2 cats(cat1, cat2), 1 syn(12); 
				switch(index)
					{ case 1: // Syn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat3);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat2=getpLTMem()->Judge_InCat(newCat2);
							if((isCat1==0)&&(isCat2==0))
								{ // Cat1, Cat2 disappear; newCat3, Syn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;								  	
								}
							else if((isCat1==1)&&(isCat2==0))
								{ // Cat1 exists, Cat2 disappear; newCat3, Syn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat1==0)&&(isCat2==1))
								{ // Cat1 disappear, Cat2 exist; Syn1 must disappear;
								  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else Case567(5, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat2 exist; case 5, type 1: 3 cats, 1 syn(12);
							break;
					  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
							printf("Wrong in StoreCat123Syn123\n");
					  		break;
					  case 3: // Syn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat3);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat2=getpLTMem()->Judge_InCat(newCat2);
							if((isCat1==0)&&(isCat2==0))
								{ // Cat1, Cat2 disappear; newCat3, Syn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;								  	
								}
							else if((isCat1==1)&&(isCat2==0))
								{ // Cat1 exist, Cat2 disapper; Syn1 must disappear;
								  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else if((isCat1==0)&&(isCat2==1))
								{ // Cat1 disappear, Cat2 exist; newCat3, Syn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case567(5, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat2 exist; case 5, type 3: 3 cats, 1 syn(12);
							break;
					  default: break;		
					}				
				break;
		  case 11: // 2 cats(cat1, cat3), 1 syn(13);
				switch(index)
					{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
							printf("Wrong in StoreCat123Syn123\n");
							break;
					  case 2: // newSyn1: newCat2<->Cat3; Syn2: Cat1<->Cat3;
					  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat3=getpLTMem()->Judge_InCat(newCat3);
					  		if((isCat1==0)&&(isCat3==0))
					  			{ // Cat1 disappear, Cat3 disappear; newCat2, newSyn1, Syn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  			}
					  		else if((isCat1==1)&&(isCat3==0))
					  			{ // Cat1 exist, Cat3 disappear; newCat2, newSyn1, Syn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1 exists;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  			}
					  		else if((isCat1==0)&&(isCat3==1))
					  			{ // Cat1 disappear, Cat3 exist; Syn2 must disappear;
					  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3 exist;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  			}
					  		else Case567(7, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat3 exist; case 7, type 2: 3 cats, 1 syn(13);
					  		break;
					  case 3: // newSyn1: Cat1<->newCat2; Syn2: Cat1<->Cat3;
					  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat3=getpLTMem()->Judge_InCat(newCat3);
					  		if((isCat1==0)&&(isCat3==0))
					  			{ // Cat1 disappear, Cat3 disappear; newCat2, newSyn1, Syn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  			}
					  		else if((isCat1==1)&&(isCat3==0))
					  			{ // Cat1 exist, Cat3 disappear; Syn2 must disappear;
					  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2 exist;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  			}
					  		else if((isCat1==0)&&(isCat3==1))
					  			{ // Cat1 disappear, Cat3 exist; newCat2, newSyn1, Syn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3 exists;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  			}
					  		else Case567(7, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat3 exist; case 7, type 3: 3 cats, 1 syn(13);
					  		break;
					  default: break;		
					}	
		  		break;
		  case 13: // 2 cats(cat2, cat3), 1 syn(23);
				switch(index)
					{ case 1: // newSyn1: newCat1<->Cat2; Syn2: Cat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat2==0)&&(isCat3==0))
					  			{ // Cat2, Cat3 disappear; newCat1, newSyn1, newSyn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat2==1)&&(isCat3==0))
								{ // Cat2 exist, Cat3 disappear; Syn2 must disappear;
								  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								}
							else if((isCat2==0)&&(isCat3==1))
								{ // Cat2 disappear, Cat3 exist; newCat1, newSyn1, Syn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case567(6, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2, Cat3 exist; case 6, type 1: 3 cats, 1 syn(23);
							break;
					  case 2: // Syn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
					  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat2==0)&&(isCat3==0))
					  			{ // Cat2, Cat3 disappear; newCat1, Syn1, newSyn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat2==1)&&(isCat3==0))
								{ // Cat2 exist, Cat3 disappear; newCat1, Syn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat2==0)&&(isCat3==1))
								{ // Cat2 disappear, Cat3 exist; Syn1 must disappear;
								  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else Case567(6, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2, Cat3 exist; case 6, type 2: 3 cats, 1 syn(23);
							break;
					  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
							printf("Wrong in StoreCat123Syn123\n");
					  		break;
					  default: break;		
					}
		  		break;
		  default: break;
		}
}

void CAgent::Case101214(int type, int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 10: 2 cats(cat1, cat2), 0 syn; case 12: 2 cats(cat1, cat3), 0 syn; case 14: 2 cats(cat2, cat3), 0 syn;
	assert((type==10)||(type==12)||(type==14)); assert((1<=index)&&(index<=3));
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isCat1, isCat2, isCat3;
	
	switch(type)
		{ case 10: // case 10: 2 cats(cat1, cat2);
				switch(index)
					{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat3);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat2=getpLTMem()->Judge_InCat(newCat2);
							if((isCat1==0)&&(isCat2==0))
						 		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat2 disappear; newCat3, newSyn1, newSyn2 must disappear;
						  		  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat1==1)&&(isCat2==0))
								{ // Cat1 exist, Cat2 disappear; newCat3, newSyn1, newSyn2 must disappear;
						  		  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1 exists;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat1==0)&&(isCat2==1))
								{ // Cat1 disappear, Cat2 exist; newSyn1 must disappear;
					  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3 exist;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else Case8(1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat2 exist; case 8, type 1: 3 cats, 0 syn;
							break;
		  			  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
							originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat3);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat2=getpLTMem()->Judge_InCat(newCat2);
		  					if((isCat1==0)&&(isCat2==0))
						 		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat2 disappear; newCat3, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
		  					else if((isCat1==1)&&(isCat2==0))
								{ // Cat1 exist, Cat2 disappear; newSyn1 must disappear;
					  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
					  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3 exists;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
		  						}
		  					else if((isCat1==0)&&(isCat2==1))
								{ // Cat1 disappear, Cat2 exist; newSyn2 must disappear;
					  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3 exists;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
		  						}
		  					else Case8(2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat2 exist; case 8, type 2: 3 cats, 0 syn;
							break;
		  			  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat3);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat2=getpLTMem()->Judge_InCat(newCat2);
							if((isCat1==0)&&(isCat2==0))
						 		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat2 disappear; newCat3, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat1==1)&&(isCat2==0))
								{ // Cat1 exist, Cat2 disappear; newSyn1 must disappear;
					  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
					  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3 exist;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else if((isCat1==0)&&(isCat2==1))
								{ // Cat1 disapppear, Cat2 exist; newCat3, newSyn1, newSyn2 must disappear;
						  		  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2 exists;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case8(3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat2 exist; case 8, type 3: 3 cats, 0 syn;
							break;
		  			  default: break;
					}
				break;
		  case 12: // case 12: 2 cats(cat1, cat3), 0 syn;
				switch(index)
					{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat1==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat3 disappear; newCat2, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat1==1)&&(isCat3==0))
								{ // Cat1 exist, Cat3 disappear; newSyn2 must disappear;		
								  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								}
							else if((isCat1==0)&&(isCat3==1))
					  			{ // Cat1 disappear, Cat3 exist; newSyn1 must disappear;
		 			 			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
		 			 			  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
		 			 			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else Case8(1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat3 exist; case 8, type 1: 3 cats, 0 syn;
							break;
					  case 2: // newSyn1: newCat2<->Cat3; newSyn2: Cat1<->Cat3;
					  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat3=getpLTMem()->Judge_InCat(newCat3);
					  		if((isCat1==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat3 disappear; newCat2, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
					  		else if((isCat1==1)&&(isCat3==0))
								{ // Cat1 exist, Cat3 disappear; newCat2, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  			}
		 			 		else if((isCat1==0)&&(isCat3==1))
		 			 			{ // Cat1 disappear, Cat3 exist; newSyn2 must disappear;
					  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
		 			 			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3 exist;
					  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  			}
					  		else Case8(2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat3 exist; case 8, type 2: 3 cats, 0 syn;
					  		break;
					  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->Cat3;
					  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1); isCat3=getpLTMem()->Judge_InCat(newCat3);
					  		if((isCat1==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat1 disappear, Cat3 disappear; newCat2, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
					  		else if((isCat1==1)&&(isCat3==0))
								{ // Cat1 exist, Cat3 disappear; newSyn2 must disappear;
								  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  			}
		  					else if((isCat1==0)&&(isCat3==1))
		 			 			{ // Cat1 disappear, Cat3 exist; newCat2, newSyn1, newSyn2 must disappear;
					  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
					  		else Case8(3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1, Cat3 exist; case 8, type 3: 3 cats, 0 syn;
					  		break;
					  default: break;
					}	
		  		break;
		  case 14: // case 14: 2 cats(cat2, cat3), 0 syn;
				switch(index)
					{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat2==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat2 disappear, Cat3 disappear; newCat1, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat2==1)&&(isCat3==0))
								{ // Cat2 exist, Cat3 disappear; newSyn2 must disappear;
								  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								}	
							else if((isCat2==0)&&(isCat3==1))
								{ // Cat2 disappear, Cat3 exist; newCat1, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case8(1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2, Cat3 exist; case 8, type 1: 3 cats, 0 syn;
							break;
					  case 2: // newSyn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
					  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat2==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat2 disappear, Cat3 disappear; newCat1, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat2==1)&&(isCat3==0))
								{ // Cat2 exist, Cat3 disappear; newCat1, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2 exists;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else if((isCat2==0)&&(isCat3==1))
								{ // Cat2 disappear, Cat3 exist; newSyn1 must disappear;
								  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								}
							else Case8(2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2, Cat3 exist; case 8, type 2: 3 cats, 0 syn;
							break;
					  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2); isCat3=getpLTMem()->Judge_InCat(newCat3);
							if((isCat2==0)&&(isCat3==0))
						  		{ // for case151617 use case101214;
						  		  // Cat2 disappear, Cat3 disappear; newCat1, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  		}
							else if((isCat2==1)&&(isCat3==0))
								{ // Cat2 exist, Cat3 disappear; newSyn2 must disappear;
								  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								}
							else if((isCat2==0)&&(isCat3==1))
								{ // Cat2 disappear, Cat3 exist; newSyn1 must disappear;
								  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3 exist;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;	
								}
							else Case8(3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2, Cat3 exist; case 8, type 3: 3 cats, 0 syn;
							break;
					  default: break;		
					}	
		  		break;
		  default: break;
		}	
}

void CAgent::Case151617(int type, int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 15: 1 cat(cat1), 0 syn; case 16: 1 cat(cat2), 0 syn; case 17: 1 cat(cat3), 0 syn;
	assert((type==15)||(type==16)||(type==17)); assert((1<=index)&&(index<=3));
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isCat1, isCat2, isCat3;

	switch(type)
		{ case 15: // case 15: 1 cat(cat1), 0 syn;
				switch(index)
					{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1);
							if(isCat1==0)
								{ // Cat1 disappear; newSyn1 must disappear;
								  getpLTMem()->InCategory(newCat3);
								  isCat2=getpLTMem()->Judge_InCat(newCat2);
								  if(isCat2==0)
								  	{ // newCat2 disappear; newCat3, newSyn2 must disappear;
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								  	}
								  else
								  	{ // newCat2 exist; 
								  	  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  	  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3 exist;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								  	}
								}
							else Case101214(10, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 10, type 1: 2 cats(cat1, cat2), 0 syn;
							break;
					  case 2: // newSyn1: newCat2<->newCat3; newSyn2: Cat1<->newCat3;
							originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1);
							if(isCat1==0)
								{ // Cat1 disappear; newSyn2 must disappear;
								  getpLTMem()->InCategory(newCat3);
								  isCat2=getpLTMem()->Judge_InCat(newCat2);
								  if(isCat2==0)
								  	{ // newCat2 disappear; newSyn1, newSyn3 must disappear; 
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								  	}
								  else 
								  	{ // newCat2 exist; 
								  	  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  	  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3 exist;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								  	}
								}
							else Case101214(10, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 exist; case 10, type 2: 2 cats(cat1, cat2), 0 syn;
							break;
					  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat2);
							isCat1=getpLTMem()->Judge_InCat(newCat1);
							if(isCat1==0)
								{ // Cat1 disappear; newCat2, newCat3, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case101214(10, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 exist; case 10, type 3: 2 cats(cat1, cat2), 0 syn;
							break;
					  default: break;
					}	
				break;
		  case 16: // case 16: 1 cat(cat2), 0 syn;
		  		switch(index)
					{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2);
							if(isCat2==0)
								{ // Cat2 disappear; newCat1, newCat3, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case101214(10, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 exists; case 10, type 1: 2 cats(cat1, cat2), 0 syn;
							break;
					  case 2: // newSyn1: Cat2<->newCat3; newSyn2: newCat1<->newCat3;
							originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2);
							if(isCat2==0)
								{ // Cat2 disappear; newSyn1 must disappear;
								  getpLTMem()->InCategory(newCat3);
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
								  if(isCat1==0)
								  	{ // newCat1 disappear; newSyn2, newCat3 must disappear;
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								  	}
								  else
								  	{ // newCat1 exists;
								  	  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
								  	  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3 exist;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
								  	}
								}
							else Case101214(10, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 exists; case 10, type 2: 2 cats(cat1, cat2), 0 syn;
							break;
					  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->newCat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat2=getpLTMem()->Judge_InCat(newCat2);
							if(isCat2==0)
								{ // Cat2 disappear; newSyn1 must disappear;
								  getpLTMem()->InCategory(newCat3);
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
								  if(isCat1==0)
								  	{ // newCat1 disappear; newCat3, newSyn2 must disappear;
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
							  	  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  		}
							  	  else
							  		{ // newCat1 exists;
							  		  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  		  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
							  		  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3 exist;
							  		  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  		}								  									  
								}
							else Case101214(10, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 exists; case 10, type 3: 2 cats(cat1, cat2), 0 syn;
							break;
					  default: break;		
					}	
		  		break;
		  case 17: // case 17, 1 cat(cat3), 0 syn;
		 		switch(index)
					{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat3=getpLTMem()->Judge_InCat(newCat3);
							if(isCat3==0)
								{ // Cat3 disappear; newSyn2 must disappear;
								  getpLTMem()->InCategory(newCat2);
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
								  if(isCat1==0)
								  	{ // newCat1 disappear; newSyn1, newCat2 must disappear;
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
							  	  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								  	}
								  else
								  	{ // newCat1 exists; 
								  	  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  	  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2 exist;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								  	}
								}
							else Case101214(12, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 exists; case 12, type 1: 2 cats(cat1, cat3), 0 syn;
							break;
					  case 2: // newSyn1: newCat2<->Cat3; newSyn2: newCat1<->Cat3;
							originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat3=getpLTMem()->Judge_InCat(newCat3);
							if(isCat3==0)
								{ // Cat3 disappear; newCat1, newCat2, newSyn1, newSyn2 must disappear;
								  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
							  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								}
							else Case101214(12, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 exists; case 12, type 2: 2 cats(cat1, cat3), 0 syn;
							break;
					  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->Cat3;
							originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
							originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

							getpLTMem()->InCategory(newCat1);
							isCat3=getpLTMem()->Judge_InCat(newCat3);
							if(isCat3==0)
								{ // Cat3 disappear; newSyn2 must disappear;
								  getpLTMem()->InCategory(newCat2);
								  isCat1=getpLTMem()->Judge_InCat(newCat1);
								  if(isCat1==0)
								  	{ // newCat1 disappear; newCat2, newSyn1, newSyn2 must disappear;
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
							  	  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
								  	}
								  else
								  	{ // newCat1 exist; 
								  	  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
								  	  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
								  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2 exist;
								  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
								  	}
								}
							else Case101214(12, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 exists; case 12, type 3: 2 cats(cat1, cat3), 0 syn;
							break;
					  default: break;		
					}	
		  		break;
		  default: break;
		}
}

void CAgent::Case18(int index, CCat *newCat1, CCat *newCat2, CCat *newCat3, CSynRule *newSyn1, CSynRule *newSyn2)
{ // case 18: 0 cat, 0 syn;
	assert((1<=index)&&(index<=3)); assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isCat1, isCat2;

	switch(index)
		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
				originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
				originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

				getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
				isCat1=getpLTMem()->Judge_InCat(newCat1);
				if(isCat1==0)
					{ // newCat1 disappear; newSyn1 must disappear;
					  getpLTMem()->InCategory(newCat3);
					  isCat2=getpLTMem()->Judge_InCat(newCat2);
					  if(isCat2==0)
					  	{ // newCat2 disappear; newSyn2, newCat3 must disappear;
					  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  	}
					  else
					  	{ // newCat2 exists;
					  	  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
					  	  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
					  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3 exist;
					  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
					  	}								  
					}
				else Case101214(10, 1, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// newCat1 still exists; case 10, type 1: 2 cats(cat1, cat2), 0 syn;
				break;
		  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
				originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
				originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

				getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
				isCat1=getpLTMem()->Judge_InCat(newCat1);
				if(isCat1==0)
					{ // newCat1 disappear; newSyn2 must disappear;
					  getpLTMem()->InCategory(newCat3);
					  isCat2=getpLTMem()->Judge_InCat(newCat2);
					  if(isCat2==0)
					  	{ // newCat2 disappear; newSyn1, newCat3 must disappear;
					  	  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  	  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  	}
					  else
					  	{ // newCat2 exists;
					  	  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  	  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
					  	  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3 exist;
					  	  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  	}
					}
				else Case101214(10, 2, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// newCat1 still exists; case 10, type 2: 2 cats(cat1, cat2), 0 syn;
				break;
		  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
				originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
				originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

				getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
				isCat1=getpLTMem()->Judge_InCat(newCat1);
				if(isCat1==0)
					{ // newCat1 disappear; newCat2, newCat3, newSyn1, newSyn2 must disappear;
					  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					}
				else Case101214(10, 3, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// newCat1 still exists; case 10, type 3: 2 cats(cat1, cat2), 0 syn;
				break;
		  default: break;		
		}	
}

void CAgent::StoreCat123Syn123(CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2, CSynRule *&newSyn3)
{ // store newCat1-3, newSyn1-3 to LTMem;
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=3, 3 word rules;
		// m_nSubType=1, 3 cats, 3 syn;
		// m_nSubType=2, 3 cats, 2 syn(12, 23);
		// m_nSubType=3, 3 cats, 2 syn(12, 13);
		// m_nSubType=4, 3 cats, 2 syn(23, 13);
		// m_nSubType=5, 3 cats, 1 syn(12);
		// m_nSubType=6, 3 cats, 1 syn(23);
		// m_nSubType=7, 3 cats, 1 syn(13);
		// m_nSubType=8, 3 cats, 0 syn;
		// m_nSubType=9, 2 cats(cat1, cat2), 1 syn(12);
		// m_nSubType=10, 2 cats(cat1, cat2), 0 syn;
		// m_nSubType=11, 2 cats(cat1, cat3), 1 syn(13);
		// m_nSubType=12, 2 cats(cat1, cat3), 0 syn;
		// m_nSubType=13, 2 cats(cat2, cat3), 1 syn(23);
		// m_nSubType=14, 2 cats(cat2, cat3), 0 syn;
		// m_nSubType=15, 1 cat(cat1), 0 syn;
		// m_nSubType=16, 1 cat(cat2), 0 syn;
		// m_nSubType=17, 1 cat(cat3), 0 syn;
		// m_nSubType=18, 0 cat, 0 syn;
	assert((newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));	// newSyn3 can be NULL!
	int SynMatCat=getpLTMem()->ChkSynMatCat(newSyn1, newSyn2, newCat1, newCat2, newCat3);	// check newSyn1, newSyn2's linking type;

	switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
		{ case 1: case 2: case 3: case 4: break;	// no operation;
		  case 5: Case567(5, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 3 cats, 1 syn(12); 
		  case 6: Case567(6, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 3 cats, 1 syn(23);
		  case 7: Case567(7, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 3 cats, 1 syn(13);
		  case 8: Case8(SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 3 cats, 0 syn;
		  case 9: Case91113(9, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat1, cat2), 1 syn(12);
		  case 10: Case101214(10, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat1, cat2), 0 syn;
		  case 11: Case91113(11, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat1, cat3), 1 syn(13);	
		  case 12: Case101214(12, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat1, cat3), 0 syn;
		  case 13: Case91113(13, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat2, cat3), 1 syn(23);
		  case 14: Case101214(14, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 2 cats(cat2, cat3), 0 syn;
		  case 15: Case151617(15, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 1 cat(cat1), 0 syn;
		  case 16: Case151617(16, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 1 cat(cat2), 0 syn;
		  case 17: Case151617(17, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 1 cat(cat3), 0 syn;
		  case 18: Case18(SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2); break;	// 0 cat, 0 syn;
		  default: break;
		}
}

void CAgent::StoreWordCat123Syn12(CLexRule *&newWord, CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2)
{ // store newWord, newCat1-3, newSyn1-2 into LTMem;
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=5, 2 word + 1 rand word rules;
  		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
	assert((newWord!=NULL)&&(newCat1!=NULL)&&(newCat2!=NULL)&&(newCat3!=NULL)&&(newSyn1!=NULL)&&(newSyn2!=NULL));
	int SynMatCat=getpLTMem()->ChkSynMatCat(newSyn1, newSyn2, newCat1, newCat2, newCat3);	// check newSyn1, newSyn2's linking type;

	CLexRule *lexTemp1=getpIMMem()->getpOptionComb(0)->m_ppLexRules[0]; CLexRule *lexTemp2=getpIMMem()->getpOptionComb(0)->m_ppLexRules[1]; CLexRule *lexTemp3=getpIMMem()->getpOptionComb(0)->m_ppLexRules[2];	// keep lex1-3;
	int originaltype12, originaltype23, originaltype13;
	int mergetype1, mergetype2;
	bool isLexTemp1, isLexTemp2, isLexTemp3, isCat1, isCat2, isCat3;

	if(newWord==lexTemp1)
		{ // rand word 1 + word 2 + word 3;
		  switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
		  	{ case 1: // 2 cats(cat2, cat3), 1 syn(23);
					getpLTMem()->InLexRule(newWord);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp2==0)&&(isLexTemp3==1))
		  				{ // lex2 disappear, lex3 exist;
		  	  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
							{ // Cat2 disappear; Syn must disappear;
							  switch(SynMatCat)
							  	{ case 1: // newSyn1: newCat1<->Cat2; Syn2: Cat2<->Cat3;
							  			isCat3=getpLTMem()->Judge_InCat(newCat3);
										if(isCat3==0)
											{ // Cat3 disappear;
											  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
											  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
											}
										else
											{ // Cat3 still exists;
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
											}
							  			break;
							  	  case 2: // Syn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
										originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
			  	  			  			if(isCat3==0)
			  	  							{ // Cat3 disappear;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  							}
			  	  			  			else
			  	  			  				{ // Cat3 still exists;
			  	  			  	  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
			  	  			  	  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
			  	  			  				}	
							  	  		break;
							  	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->Cat3;
							  	  		printf("Wrong in StoreWordCat123Syn123");
							  	  		break;
							  	  default: break;		
							  	}				  			  		  	  			  
			  				}
			  			  else Case91113(13, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 still exists; case 13, type1-3: 2 cats(cat2, cat3), 1 syn(23);
			  			}			 
		  			else if((isLexTemp2==1)&&(isLexTemp3==0))
		  				{ // lex2 exist, lex3 disappear;
			  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp2, NULL);	// newWord, lex2 exist;
						  isCat3=getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disappear; Syn must disappear;
						  	  switch(SynMatCat)
							  	{ case 1: // newSyn1: newCat1<->Cat2; Syn2: Cat2<->Cat3;
						  				originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat1);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
						  	  			if(isCat2==0)
						  	  				{ // Cat2 disappear;						  	  	  	
						  	  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  	  				}
						  	  			else
						  	  				{ // Cat2 still exists;
						  	  	  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  	  	  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  	  				}
						  				break;
						  	  	  case 2: // Syn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
						  	  	  		isCat2=getpLTMem()->Judge_InCat(newCat2);
						  	  	  		if(isCat2==0)
						  	  	  			{ // Cat2 disappear;
											  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  				  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  	  				}
						  	  	  		else
						  	  	  			{ // Cat2 still exists;
						  	  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
						  	  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  	  	  			}
										break;
						  	  	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->Cat3;
						  	  			printf("Wrong in StoreWordCat123Syn123");
						  	  			break;
						  	  	  default: break;		
						  		}						  	  
						  	}
						  else Case91113(13, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 13, type1-3: 2 cats(cat2, cat3), 1 syn(23);
			  			}
		  			else Case91113(13, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex2, lex3 exist; case 13, type1-3: 2 cats(cat2, cat3), 1 syn(23);
			  		break;
			  case 2: // 2 cats(cat2, cat3), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp2==0)&&(isLexTemp3==1))
		  				{ // lex2 disappear, lex3 exist;
		  	  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
							{ // Cat2 disappear; 
							  switch(SynMatCat)
							  	{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->Cat3;
							  			isCat3=getpLTMem()->Judge_InCat(newCat3);
							  			if(isCat3==0)
							  				{ // Cat3 disappear;
											  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  				  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat3 still exists;
											  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
			  	  			  				  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}									 	
										break;
							  	  case 2: // newSyn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
										originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
							  			if(isCat3==0)
							  				{ // Cat3 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat3 still exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3;
							  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
							  	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->Cat3;
							  	  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
							  			if(isCat3==0)
							  				{ // Cat3 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat3 still exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3;
							  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
								  default: break;		
							  	} 
			  			  	}
			  			  else Case101214(14, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 still exists; case 14, type1-3: 2 cats(cat2, cat3), 0 syn;
			  			}
		  			else if((isLexTemp2==1)&&(isLexTemp3==0))
		  				{ // lex2 exist, lex3 disappear;
			  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp2, NULL);	// newWord, lex2 exist;
						  isCat3=getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disappear;
							  switch(SynMatCat)
							  	{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->Cat3;
									 	originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat1);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
							  			if(isCat2==0)
							  				{ // Cat2 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat2 still exists;
							  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							  				  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2;
							  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
							  				}
										break;
							  	  case 2: // newSyn1: Cat2<->Cat3; newSyn2: newCat1<->Cat3;
										isCat2=getpLTMem()->Judge_InCat(newCat2);
										if(isCat2==0)
							  	  			{ // Cat2 disappear;
											  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  	  			}
							  	  		else
							  	  			{ // Cat2 still exists;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  	  			}										
							  			break;
							  	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->Cat3;
							  	  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat1);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
							  			if(isCat2==0)
							  				{ // Cat2 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat2 still exists;
							  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							  				  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2;
							  				  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
							  				}
							  			break;
								  default: break;		
							  	}						  	 
						  	}
						  else Case101214(14, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 14, type1-3: 2 cats(cat2, cat3), 0 syn;
						}
		  			else Case101214(14, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex2, lex3 exist; case 14, type1-3: 2 cats(cat2, cat3), 0 syn;
					break;
			  case 3: // 1 cat(cat2), 0 syn;
			  		getpLTMem()->InLexRule(newWord);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp2==0)&&(isLexTemp3==1))
		  				{ // lex2 disappear, lex3 exist;
		  	  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
				  			{ // Cat2 disappear;
				  	  		  switch(SynMatCat) 
				  	  			{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->newCat3;
				  	 		 			getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  			  			getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	 		 			break;
				  	 		 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: newCat1<->newCat3;
				  	  			  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  		if(isCat1==0)
				  	  	 		 			{ // newCat1 disappear;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	  			  			}
				  	  			  		else
				  	  	 		 			{ // newCat1 still exists;
				  	  			  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
				  	  			  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
				  	  			  			}
				  	  			  		break;
				  	 		 	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->newCat3;
										originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  		if(isCat1==0)
				  	  			  			{ // newCat1 disappear;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	  			  			}
				  	  			  		else
				  	  	 		 			{ // newCat1 still exists;
				  	  			  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
				  	  			  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
				  	  			  			}
				  	  			  		break;
				  	 		 	  default: break;		
				  	  			}					  	  
						  	}
						  else Case151617(16, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 still exists; case 16, type 1-3: 1 cat(cat2), 0 syn;
		  				}
		  			else if((isLexTemp2==1)&&(isLexTemp3==0))
		  				{ // lex2 exist, lex3 disappear;
			  			  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp2, NULL);	// newWord, lex2 exist;
						  // newCat3 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
									if(isCat2==0)
										{ // Cat2 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat2 still exists;
										  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
										  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
										}
			  	 		 			break;
			  	 		 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: newCat1<->newCat3;
									isCat2=getpLTMem()->Judge_InCat(newCat2);
									if(isCat2==0)
			  	 		 	  			{ // Cat2 disappear;
			  	 		 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  			}
			  	 		 	  		else
			  	 		 	  			{ // Cat2 still exists;
			  	 		 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  			}				  	 		 	  		
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
				  	  			  	if(isCat2==0)
				  	  		  			{ // Cat2 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // Cat2 still exists;
				  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  			  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, Cat2;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
		  				}						  
		  			else Case151617(16, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex2, lex3 exist; case 16, type 1-3: 1 cat(cat2), 0 syn;
		  			break;
			  case 4: // 1 cat(cat3), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp2==0)&&(isLexTemp3==1))
		  				{ // lex2 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  // newCat2 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->Cat3;
									isCat3=getpLTMem()->Judge_InCat(newCat3);
									if(isCat3==0)
			  	 		 	  			{ // Cat3 disappear;
			  	 		 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  			}
			  	 		 	  		else
			  	 		 	  			{ // Cat3 still exists;
			  	 		 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  			}
			  	 		 			break;
			  	 		 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: newCat1<->Cat3;
			  	 		 	  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1);
									isCat3=getpLTMem()->Judge_InCat(newCat3);
									if(isCat3==0)
										{ // Cat3 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat3 still exists;
										  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
										  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
										}				  	 		 	  		
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->Cat3;
									originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1);
									isCat3=getpLTMem()->Judge_InCat(newCat3);
				  	  			  	if(isCat3==0)
				  	  		  			{ // Cat3 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // Cat3 still exists;
				  			  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
				  			  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, Cat3;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
						}
		  			else if((isLexTemp2==1)&&(isLexTemp3==0))
		  				{ // lex2 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp2, NULL);	// newWord, lex2 exist;
						  isCat3=getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disappear;
						  	  switch(SynMatCat) 
				  	  			{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->Cat3;
				  	 		 			originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
										if(isCat1==0)
				  	  	 		 			{ // newCat1 disappear;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	  			  			}
				  	  			  		else
				  	  	 		 			{ // newCat1 still exists;
				  	  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  	  			  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  	  			  			}
				  	  			  		break;
				  	 		 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: newCat1<->Cat3;
				  	  			  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  			  			getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	 		 			break;
				  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->Cat3;
										originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  		if(isCat1==0)
				  	  			  			{ // newCat1 disappear;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  	  			  			}
				  	  			  		else
				  	  	 		 			{ // newCat1 still exists;
				  	  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  	  			  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
				  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  	  			  			}
				  	  			  		break;
				  	 		 	  default: break;		
						  	  	}
						  	}
						  else Case151617(17, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 17, type1-3: 1 cat(cat3), 0 syn;
		  				}
		  			else Case151617(17, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex2, lex3 exist; case 17, type1-3: 1 cat(cat3), 0 syn;
		  			break;
			  case 5: // 0 cat, 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp2==0)&&(isLexTemp3==1))
		  				{ // lex2 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  // newCat2 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // newCat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat1 still exists;
										  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
										  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
										}				  	 		 	  		
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  	if(isCat1==0)
				  	  		  			{ // newCat1 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat1 still exists;
				  			  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
				  			  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
						}
		  			else if((isLexTemp2==1)&&(isLexTemp3==0))
		  				{ // lex2 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp2, NULL);	// newWord, lex2 exist;
						  // newCat3 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // newCat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat1 still exists;
										  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
										  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
										}	
									break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  	if(isCat1==0)
				  	  		  			{ // newCat1 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat1 still exists;
				  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  			  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
		  				}
		  			else Case18(SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex2, lex3 exist; case 18, type1-3: 0 cat, 0 syn;
		  			break;
			  default: break;
			}		  
		}
	else if(newWord==lexTemp2)
		{ // word 1 +  rand word 2 + word 3;
		  switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
		  	{ case 1: // 2 cats(cat1, cat3), 1 syn(13);
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp1==0)&&(isLexTemp3==1))
		  				{ // lex1 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
			  			  	{ // Cat1 disappear; Syn must disappear;
							  switch(SynMatCat)
							  	{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
							  			printf("Wrong in StoreWordCat123Syn123");
							  	  		break;
							  	  case 2: // newSyn1: newCat2<->Cat3; Syn2: Cat1<->Cat3;
										originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
										
										getpLTMem()->InCategory(newCat2);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
			  	  			  			if(isCat3==0)
			  	  							{ // Cat3 disappear;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  							}
			  	  			  			else
			  	  			  				{ // Cat3 still exists;
			  	  			  	  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
			  	  			  	  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
			  	  			  				}	
							  	  		break;
							  	  case 3: // newSyn1: Cat1<->newCat2; Syn2: Cat1<->Cat3;
							  	  		isCat3=getpLTMem()->Judge_InCat(newCat3);
							  	  	 	if(isCat3==0)
							  	  	 		{ // Cat3 disappear;
							  	  	 		  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  	  	 	else
							  	  	 		{ // Cat3 still exists;
							  	  	 		  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  	  	 		}
							  	  		break;
							  	  default: break;		
							  	}		
			  			  	}
			  			  else Case91113(11, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 11, type1-3: 2 cats(cat1, cat3), 1 syn(13);  	  			  
			  			}
		  			else if((isLexTemp1==1)&&(isLexTemp3==0))
		  				{ // lex1 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat3=	getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disapear; Syn must disappear;
						  	  switch(SynMatCat)
							  	{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
							  			printf("Wrong in StoreWordCat123Syn123");
							  	  		break;
							  	  case 2: // newSyn1: newCat2<->Cat3; Syn2: Cat1<->Cat3;
							  	  		isCat1=getpLTMem()->Judge_InCat(newCat1);
							  	  		if(isCat1==0)
							  	  			{ // Cat1 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  	  		else
							  	  			{ // Cat1 still exists;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  	  			}
										break;
							  	  case 3: // newSyn1: Cat1<->newCat2; Syn2: Cat1<->Cat3;
							  	  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
			  	  			  			if(isCat1==0)
			  	  							{ // Cat1 disappear;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  							}
			  	  			  			else
			  	  			  				{ // Cat3 still exists;
			  	  			  	  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
			  	  			  	  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
			  	  			  				}	
			  	  			  			break;
							  	  default: break;		
							  	}		
						  	}
						  else Case91113(11, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 11, type1-3: 2 cats(cat1, cat3), 1 syn(13);	  	  			  
						}
		  			else Case91113(11, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex3 exist; case 11, type1-3: 2 cats(cat1, cat3), 1 syn(13);	  	  			  
		  			break;
		  	  case 2: // 2 cats(cat1, cat3), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp1==0)&&(isLexTemp3==1))
		  				{ // lex1 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
							{ // Cat1 disappear; 
							  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
									 	originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

										getpLTMem()->InCategory(newCat2);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
							  			if(isCat3==0)
							  				{ // Cat3 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat3 exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
						 	 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: Cat1<->Cat3;
										originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
										
										getpLTMem()->InCategory(newCat2);
										isCat3=getpLTMem()->Judge_InCat(newCat3);
						  				if(isCat3==0)
						  					{ // Cat3 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // Cat3 still exists;
						  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  					  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  					}
						  				break;
						  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->Cat3;
						  		  		isCat3=getpLTMem()->Judge_InCat(newCat3);
						  		  		if(isCat3==0)
						  		  			{ // Cat3 disappear;
						  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  		  		else
						  		  			{ // Cat3 still exists;
						  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  		  		break;
								  default: break;		
						  		}							  	
			  			  	}
			  			  else Case101214(12, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 12, type1-3: 2 cats(cat1, cat3), 0 syn;
			  			}
		  			else if((isLexTemp1==1)&&(isLexTemp3==0))
		  				{ // lex1 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat3=getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disappear;
						  	  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->Cat3;
									 	originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
							  			if(isCat1==0)
							  				{ // Cat1 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat1 still exists;
							  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							  				  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
							  				}
							  			break;
						 	 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: Cat1<->Cat3;
						 	 	  		isCat1=getpLTMem()->Judge_InCat(newCat1);
						 	 	  		if(isCat1==0)
						 	 	  			{ // Cat1 disappear;
						 	 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						 	 	  		else
						 	 	  			{ // Cat1 still exists;
						 	 	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
										break;
						  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->Cat3;
						  		  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
						  				if(isCat1==0)
						  					{ // Cat1 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // Cat1 still exists;
						  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  					  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  					}
						  				break;
								  default: break;		
						  		}			
						  	}
						  else Case101214(12, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 12, type1-3: 2 cats(cat1, cat3), 0 syn;
						}
		  			else Case101214(12, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex3 exist; case 12, type1-3: 2 cats(cat1, cat3), 0 syn;
					break;
		  	  case 3: // 1 cat(cat1), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp1==0)&&(isLexTemp3==1))
		  				{ // lex1 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
						  	{ // Cat1 disappear;
						  	  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->newCat3;
									 	originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);
										
										getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
							  			if(isCat2==0)
							  				{ // newCat2 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // newCat2 still exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
						 	 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: Cat1<->newCat3;
						 	 	  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
										
										getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
						  				if(isCat2==0)
						  					{ // newCat2 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // newCat2 still exists;
						  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  					  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  					}						  				
										break;
						  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->newCat3;
						  		  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				break;
								  default: break;		
						  		}
						  	}
						  else Case151617(15, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 15, type 1-3: 1 cat(cat1), 0 syn;
						}
		  			else if((isLexTemp1==1)&&(isLexTemp3==0))
		  				{ // lex1 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  // newCat3 must disappear;
						  switch(SynMatCat)
					  		{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->newCat3;
								 	originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
									
									getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
						  			if(isCat1==0)
						  				{ // Cat1 disappear;
						  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				}
						  			else
						  				{ // Cat1 still exists;
						  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  				  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  				}
						  			break;
					 	 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: Cat1<->newCat3;
					 	 	  		isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // Cat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat1 still exists;
										  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
					  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}				
									break;
					  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
									
									getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
					  				if(isCat1==0)
					  					{ // Cat1 disappear;
							  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  					}
					  				else
					  					{ // Cat1 still exists;
					  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  					  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// Cat1, newCat2;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  					}
					  		  		break;
							  default: break;		
					  		}
						}
		  			else Case151617(15, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex3 exist; case 15, type 1-3: 1 cat(cat1), 0 syn;
					break;
		  	  case 4: // 1 cat(cat3), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp1==0)&&(isLexTemp3==1))
		  				{ // lex1 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  // newCat1 must disappear;
						  switch(SynMatCat)
					  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->Cat3;
								 	originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);
									
									getpLTMem()->InCategory(newCat2);
									isCat3=getpLTMem()->Judge_InCat(newCat3);
						  			if(isCat3==0)
						  				{ // Cat3 disappear;
						  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				}
						  			else
						  				{ // Cat3 still exists;
						  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  				  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  				}
						  			break;
					 	 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: newCat1<->Cat3;
									originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
									
									getpLTMem()->InCategory(newCat2);
									isCat3=getpLTMem()->Judge_InCat(newCat3);
					  				if(isCat3==0)
					  					{ // Cat3 disappear;
							  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  					}
					  				else
					  					{ // Cat3 still exists;
					  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  					  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, Cat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  					}					  							
									break;
					  		  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->Cat3;
					  		  		isCat3=getpLTMem()->Judge_InCat(newCat3);
									if(isCat3==0)
										{ // Cat3 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
					  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat3 still exists;
										  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat3, NULL, NULL);	// Cat3;
					  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
					  		  		break;
							  default: break;		
					  		}
		  				}
		  			else if((isLexTemp1==1)&&(isLexTemp3==0))
		  				{ // lex1 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat3=getpLTMem()->Judge_InCat(newCat3);
						  if(isCat3==0)
						  	{ // Cat3 disappear;
						  	  switch(SynMatCat)
						  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->Cat3;
									 	originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
							  			if(isCat1==0)
							  				{ // newCat1 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // newCat1 still exists;
							  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							  				  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
							  				}
							  			break;
						 	 	  case 2: // newSyn1: newCat2<->Cat3; newSyn2: newCat1<->Cat3;
						 	 	  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
						  		  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				break;
						  		  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->Cat3;
						  		  		originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);
										
										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
						  				if(isCat1==0)
						  					{ // newCat1 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // newCat1 still exists;
						  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  					  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  					}						  				
										break;
								  default: break;		
						  		}
						  	}
						  else Case151617(17, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat3 still exists; case 17, type1-3: 1 cat(cat3), 0 syn;
						}
		  			else Case151617(17, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex3 exist; case 17, type1-3: 1 cat(cat3), 0 syn;
					break;
		  	  case 5: // 0 cat, 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp3=getpLTMem()->Judge_InLex(lexTemp3);
		  			if((isLexTemp1==0)&&(isLexTemp3==1))
		  				{ // lex1 disappear, lex3 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, newWord, lexTemp3, NULL);	// newWord, lex3 exist;
						  // newCat1 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
									if(isCat2==0)
										{ // newCat2 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat2 still exists;
										  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
										  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
										}
									break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
				  	  			  	if(isCat2==0)
				  	  		  			{ // newCat2 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat2 still exists;
				  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  			  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  			  			}
				  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
				  		 	  default: break;		
				  			}
		  				}
		  			else if((isLexTemp1==1)&&(isLexTemp3==0))
		  				{ // lex1 exist, lex3 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  // newCat3 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // newCat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat1 still exists;
										  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
										  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exist;
										}	
									break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									originaltype12=0; newSyn1->getMatchTyp(&originaltype12, newCat1, newCat2);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat2);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  	if(isCat1==0)
				  	  		  			{ // newCat1 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat1 still exists;
				  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  			  			  newSyn1->getReMatCat(originaltype12, mergetype1, newCat1, newCat2);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat2, NULL);	// newCat1, newCat2;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
		  				}
		  			else Case18(SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex3 exist; case 18, type1-3: 0 cat, 0 syn;
		  			break;
		  	  default: break;
		  	}
		}
	else if(newWord==lexTemp3)
		{ // word 1 + word 2 + rand word 3;
		  switch(getpIMMem()->getpOptionComb(0)->m_nSubType)
		  	{ case 1: // 2 cats(cat1, cat2), 1 syn(12);
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
		  			if((isLexTemp1==0)&&(isLexTemp2==1))
		  				{ // lex1 disappear, lex2 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp2, newWord, NULL);	// newWord, lex2 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
			  			  	{ // Cat1 disappear; Syn must disappear;
						  	  switch(SynMatCat)
							  	{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
							  			originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

										getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
			  	  			  			if(isCat2==0)
			  	  							{ // Cat2 disappear;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  							}
			  	  			  			else
			  	  			  				{ // Cat2 still exists;
			  	  			  	  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
			  	  			  	  			  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
			  	  			  				}
							  	  		break;
							  	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
										printf("Wrong in StoreWordCat123Syn123");	
							  	  		break;
							  	  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
							  	  		isCat2=getpLTMem()->Judge_InCat(newCat2);
							  	  		if(isCat2==0)
							  	  			{ // Cat2 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  	  		else
							  	  			{ // Cat2 still exists;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  	  		break;
							  	  default: break;		
							  	}					  	  
			  			  	}
			  			  else Case91113(9, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 9, type1-3: 2 cats(cat1, cat2), 1 syn(12);	  	  			  
			  			}
		  			else if((isLexTemp1==1)&&(isLexTemp2==0))
		  				{ // lex1 exist, lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
						  	{ // Cat2 disapear; Syn must disappear;
							  switch(SynMatCat)
							  	{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
							  			isCat1=getpLTMem()->Judge_InCat(newCat1);
							  			if(isCat1==0)
							  				{ // Cat1 disappear;
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat1 still exists;
							  				  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			break;
							  	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
										printf("Wrong in StoreWordCat123Syn123");	
							  	  		break;
							  	  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
							  	  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
			  	  			  			if(isCat1==0)
			  	  							{ // Cat1 disappear;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  							}
			  	  			  			else
			  	  			  				{ // Cat1 still exists;
			  	  			  	  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
			  	  			  	  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3;
			  	  			  	  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
			  	  			  				}
			  	  			  			break;
							  	  default: break;		
							  	}	
						  	}
						  else Case91113(9, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 still exists; case 9, type1-3: 2 cats(cat1, cat2), 1 syn(12);	  	  			  
		  				}
		  			else Case91113(9, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex2 exist; case 9, type1-3: 2 cats(cat1, cat2), 1 syn(12);		  	  			  
			  		break;
		  	  case 2: // 2 cats(cat1, cat2), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
		  			if((isLexTemp1==0)&&(isLexTemp2==1))
		  				{ // lex1 disappear, lex2 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp2, newWord, NULL);	// newWord, lex2 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
							{ // Cat1 disappear; 
							  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
									 	originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

										getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
							  			if(isCat2==0)
							  				{ // Cat2 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat2 exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
						 	 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
										originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);
										
										getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
						  				if(isCat2==0)
						  					{ // Cat2 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // Cat2 still exists;
						  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
						  					  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
						  					}
						  				break;
						  		  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
						  		  		isCat2=getpLTMem()->Judge_InCat(newCat2);
						  		  		if(isCat2==0)
						  		  			{ // Cat2 disappear;
						  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  		  		else
						  		  			{ // Cat2 still exists;
						  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  		  		break;
								  default: break;		
						  		}							  	
			  			  	}
			  			  else Case101214(10, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 10, type1-3: 2 cats(cat1, cat2), 0 syn;
			  			}
		  			else if((isLexTemp1==1)&&(isLexTemp2==0))
		  				{ // lex1 exist, lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
							{ // Cat2 disappear; 
							  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->Cat2; newSyn2: Cat2<->newCat3;
						  				isCat1=getpLTMem()->Judge_InCat(newCat1);
						  				if(isCat1==0)
						  					{ // Cat1 disappear;
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // Cat1 still exists;
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
									 	break;
						 	 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: Cat1<->newCat3;
										originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
						  				if(isCat1==0)
						  					{ // Cat1 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // Cat1 still exists;
						  					  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  					  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  					}
						  				break;
						  		  case 3: // newSyn1: Cat1<->Cat2; newSyn2: Cat1<->newCat3;
						  		  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
							  			if(isCat1==0)
							  				{ // Cat1 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // Cat1 exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
								  default: break;		
						  		}							  	
			  			  	}
			  			  else Case101214(10, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 10, type1-3: 2 cats(cat1, cat2), 0 syn;
			  			}
		  			else Case101214(10, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex2 exist; case 10, type1-3: 2 cats(cat1, cat2), 0 syn;
			  		break;
		  	  case 3: // 1 cat(cat1), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
		  			if((isLexTemp1==0)&&(isLexTemp2==1))
		  				{ // lex1 disappear, lex2 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp2, newWord, NULL);	// newWord, lex2 exist;
						  isCat1=getpLTMem()->Judge_InCat(newCat1);
						  if(isCat1==0)
						  	{ // Cat1 disappear;
							  switch(SynMatCat)
						  		{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->newCat3;
						  				originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

										getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
						  				if(isCat2==0)
						  					{ // newCat2 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // newCat2 still exists;
						  					  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  					  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  					}
						  				break;
						 	 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: Cat1<->newCat3;
										originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);

										getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
										isCat2=getpLTMem()->Judge_InCat(newCat2);
							  			if(isCat2==0)
							  				{ // newCat2 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // newCat2 still exists;
							  				  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
							  				  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
							  				}
							  			break;
						  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->newCat3;
						  		  		getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				break;
								  default: break;		
						  		}		
						  	}
						  else Case151617(15, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat1 still exists; case 15, type 1-3: 1 cat(cat1), 0 syn;
						}
		  			else if((isLexTemp1==1)&&(isLexTemp2==0))
		  				{ // lex1 exist, lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  // newCat2 must disappear;
						  switch(SynMatCat)
							{ case 1: // newSyn1: Cat1<->newCat2; newSyn2: newCat2<->newCat3;
									isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // Cat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat1 still exists;
										  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat1, NULL, NULL);	// Cat1;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
					  				break;
					 	 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: Cat1<->newCat3;
									originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
						  			if(isCat1==0)
						  				{ // Cat1 disappear;
						  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				}
						  			else
						  				{ // Cat1 still exists;
						  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  				  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  				}
						  			break;
					  		  case 3: // newSyn1: Cat1<->newCat2; newSyn2: Cat1<->newCat3;
					  		  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
					  				if(isCat1==0)
					  					{ // Cat1 disappear;
							  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			    				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  					}
					  				else
					  					{ // Cat1 still exists;
					  					  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
					  					  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// Cat1, newCat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
					  					}
					  				break;
							  default: break;		
					  		}		
						}
		  			else Case151617(15, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex2 exist; case 15, type 1-3: 1 cat(cat1), 0 syn;
					break;
		  	  case 4: // 1 cat(cat2), 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
		  			if((isLexTemp1==0)&&(isLexTemp2==1))
		  				{ // lex1 disappear, lex2 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp2, newWord, NULL);	// newWord, lex2 exist;
						  // newCat1 must disappear;
						  switch(SynMatCat)
							{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->newCat3;
									originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
						  			if(isCat2==0)
						  				{ // Cat2 disappear;
						  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				}
						  			else
						  				{ // Cat2 still exists;
						  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  				  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  				}
					  				break;
					 	 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: newCat1<->newCat3;
									originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
					  				if(isCat2==0)
					  					{ // Cat2 disappear;
							  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			    				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
					  					}
					  				else
					  					{ // Cat2 still exists;
					  					  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
					  					  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
					  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// Cat2, newCat3;
					  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
					  					}
						  			break;
					  		  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->newCat3;
					  		  		isCat2=getpLTMem()->Judge_InCat(newCat2);
					  		  		if(isCat2==0)
										{ // Cat2 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // Cat2 still exists;
										  getpIMMem()->getpOptionComb(0)->RemainCat(1, newCat2, NULL, NULL);	// Cat2;
			  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
					  				break;
							  default: break;		
					  		}		
		  				}
		  			else if((isLexTemp1==1)&&(isLexTemp2==0))
		  				{ // lex1 exist, lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  isCat2=getpLTMem()->Judge_InCat(newCat2);
						  if(isCat2==0)
						  	{ // Cat2 disappear;
						  	  switch(SynMatCat)
						  		{ case 1: // newSyn1: newCat1<->Cat2; newSyn2: Cat2<->newCat3;
						  				getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  				break;
						 	 	  case 2: // newSyn1: Cat2<->newCat3; newSyn2: newCat1<->newCat3;
										originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
							  			if(isCat1==0)
							  				{ // newCat1 disappear;
							  	  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
							  				}
							  			else
							  				{ // newCat1 still exists;
							  				  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
							  				  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
							  				}
							  			break;
						  		  case 3: // newSyn1: newCat1<->Cat2; newSyn2: newCat1<->newCat3;
						  		  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

										getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
										isCat1=getpLTMem()->Judge_InCat(newCat1);
						  				if(isCat1==0)
						  					{ // newCat1 disappear;
								  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  				  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
						  					}
						  				else
						  					{ // newCat1 still exists;
						  					  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
						  					  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
						  					  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
						  					  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
						  					}
						  				break;
								  default: break;
						  		}
						  	}
						  else Case151617(16, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// Cat2 still exists; case 16, type 1-3: 1 cat(cat2), 0 syn;
						}
		  			else Case151617(16, SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex2 exist; case 16, type 1-3: 1 cat(cat2), 0 syn;
					break;
		  	  case 5: // 0 cat, 0 syn;
					getpLTMem()->InLexRule(newWord);
					isLexTemp1=getpLTMem()->Judge_InLex(lexTemp1); isLexTemp2=getpLTMem()->Judge_InLex(lexTemp2);
		  			if((isLexTemp1==0)&&(isLexTemp2==1))
		  				{ // lex1 disappear, lex2 exist;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp2, newWord, NULL);	// newWord, lex2 exist;
						  // newCat1 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									originaltype23=0; newSyn2->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
									if(isCat2==0)
										{ // newCat2 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat2 still exists;
										  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
										  newSyn2->getReMatCat(originaltype23, mergetype2, newCat2, newCat3);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
										}	
									break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		originaltype23=0; newSyn1->getMatchTyp(&originaltype23, newCat2, newCat3);

									getpLTMem()->InCategory(newCat2); getpLTMem()->InCategory(newCat3);
									isCat2=getpLTMem()->Judge_InCat(newCat2);
				  	  			  	if(isCat2==0)
				  	  		  			{ // newCat2 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat2 still exists;
				  			  			  mergetype1=0; getpLTMem()->InSynRule(newSyn1, &mergetype1);
				  			  			  newSyn1->getReMatCat(originaltype23, mergetype1, newCat2, newCat3);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat2, newCat3, NULL);	// newCat2, newCat3;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn1, NULL, NULL);	// newSyn1 exists;
				  			  			}
				  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
				  		 	  default: break;		
				  			}
		  				}
		  			else if((isLexTemp1==1)&&(isLexTemp2==0))
		  				{ // lex1 exist, lex2 disappear;
						  getpIMMem()->getpOptionComb(0)->RemainLex(2, lexTemp1, newWord, NULL);	// newWord, lex1 exist;
						  // newCat2 must disappear;
						  switch(SynMatCat) 
				  	  		{ case 1: // newSyn1: newCat1<->newCat2; newSyn2: newCat2<->newCat3;
									getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
			  	  			  		getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
			  	  			  		break;
			  	 		 	  case 2: // newSyn1: newCat2<->newCat3; newSyn2: newCat1<->newCat3;
			  	 		 	  		originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
									if(isCat1==0)
										{ // newCat1 disappear;
										  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
										}
									else
										{ // newCat1 still exists;
										  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
										  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
										  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
										  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exist;
										}				  	 		 	  		
			  	  			  		break;
			  	 		 	  case 3: // newSyn1: newCat1<->newCat2; newSyn2: newCat1<->newCat3;
									originaltype13=0; newSyn2->getMatchTyp(&originaltype13, newCat1, newCat3);

									getpLTMem()->InCategory(newCat1); getpLTMem()->InCategory(newCat3);
									isCat1=getpLTMem()->Judge_InCat(newCat1);
				  	  			  	if(isCat1==0)
				  	  		  			{ // newCat1 disappear;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainCat(0, NULL, NULL, NULL);	// 0 cat;
				  	  		  			  getpIMMem()->getpOptionComb(0)->RemainSyn(0, NULL, NULL, NULL);	// 0 syn;
				  			  			}
				  			  		else
				  			 			{ // newCat1 still exists;
				  			  			  mergetype2=0; getpLTMem()->InSynRule(newSyn2, &mergetype2);
				  			  			  newSyn2->getReMatCat(originaltype13, mergetype2, newCat1, newCat3);
				  			  			  getpIMMem()->getpOptionComb(0)->RemainCat(2, newCat1, newCat3, NULL);	// newCat1, newCat3;
				  			  			  getpIMMem()->getpOptionComb(0)->RemainSyn(1, newSyn2, NULL, NULL);	// newSyn2 exists;
				  			  			}
				  			  		break;
				  		 	  default: break;		
				  			}
		  				}
		  			else Case18(SynMatCat, newCat1, newCat2, newCat3, newSyn1, newSyn2);	// lex1, lex2 exist; case 18, type1-3: 0 cat, 0 syn;
		  			break;
		  	  default: break;
		  	}
		}					  
}

void CAgent::SetUtter(CMeanUtter *meanutter, int NormOrTest)
{ // set up utterance for the chosen meaning; 
	assert(meanutter->getpMean()!=NULL); assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2));
	CLexRule *newWord=NULL, *newPhrase=NULL, *newHolist=NULL;
	CCat *newHolistCat=NULL, *newCat1=NULL, *newCat2=NULL, *newCat3=NULL;
	CSynRule *newSyn1=NULL, *newSyn2=NULL, *newSyn3=NULL;

	int meantype=getpIMMem()->getpOptionComb(0)->m_nMeanType;
	int type=getpIMMem()->getpOptionComb(0)->m_nType;
	int subtype=getpIMMem()->getpOptionComb(0)->m_nSubType;
	int oldCatThemRole;	// for new created category, keep its themrole in case of inserting new lexical/syntactic rules cause this category to be deleted;
	int sucInLex;

	// create related rules and store newly created rules into m_pIMM->m_pOptionComb[0];
	if(meantype==1)
		{ // "Predicate<Agent>" meaning; 
		  switch(type)
			{ case 0: // holistic rule; set up meanutter's utterance;
					getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem()->m_pOptionComb[0] to set up utterance;
					break;
			  case 1: // rand holistic rule;
			  		if(NormOrTest==0)
			  			{ // create newHolistic and newHolistCat and insert into IMMem->m_pOptionComb[0];
			  			  newHolist=NULL; newHolistCat=NULL;
						  getpLTMem()->RandCrtHolist(meantype, newHolist, newHolistCat, meanutter);	// "Predicate<Agent>" holistic utterance;
						  getpIMMem()->InHolist(meantype, newHolist, newHolistCat, meanutter);
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;

					   	  // store newHolist, newHolistCat into LTMem;
						  oldCatThemRole=newHolistCat->getThemRole();
						  getpLTMem()->InLexRule(newHolist);
						  if(oldCatThemRole==newHolistCat->getThemRole()) getpLTMem()->InCategory(newHolistCat);
			  			  else
			  				{ // recreate a holistic cat;
				  			  newHolistCat=new CCat; assert(newHolistCat!=NULL);
				  			  newHolistCat->setThemRole(0);
							  // link up newHolist and newHolistCat;	
				  			  newHolist->InCat(newHolistCat); 
							  sucInLex=0; newHolistCat->InLex(newHolist, &sucInLex);	// this insertion will always be successful;
							  
				  			  getpLTMem()->InCategory(newHolistCat);
				  			  // adjust IMMem()->m_ppOptionComb[0];
				  			  getpIMMem()->getpOptionComb(0)->m_ppCats[0]=newHolistCat;				  			  
			  				}

						  newHolist=NULL; newHolistCat=NULL;	// recollect newHolist and newHolistCat;
			  			}
					break;
			  case 2: // use 2 word rules;
			  		if((NormOrTest==1)||(NormOrTest==2))
			  			{ if((subtype==2)||(subtype==3)||(subtype==4)||(subtype==5)) break;
			  			  else getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						}
			  		else if(NormOrTest==0)
			  			{ // create newCat1-2 or newSyn1 and insert into IMMem->m_pOptionComb[0];
			  			  newCat1=NULL; newCat2=NULL;
			  			  newSyn1=NULL;
						  getpIMMem()->RandCrtCatSyn_InOC(newCat1, newCat2, newSyn1, meanutter);	// 2 word rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // store newCat1-2, newSyn1 into LTMem;
						  StoreCatSyn(newCat1, newCat2, newSyn1);						  
						  newCat1=NULL; newCat2=NULL;
			  			  newSyn1=NULL;	// recollect newCat1-2 and newSyn1;
			  			}
			  		break;
			  case 3: // 1 word + 1 rand word rules;
			  		if(NormOrTest==0)
			  			{ // create newWord, newCat1-2 or newSyn1 and insert into IMMem->m_pOptionComb[0];
						  newWord=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;
						  getpIMMem()->RandCrtWordPhr_InOC(newWord, newCat1, newCat2, newSyn1, meanutter);	// 1 word + 1 rand word rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // 	store newWord, newCat1-2, newSyn1 into LTMem;
						  StoreWordPhraCatSyn(newWord, newCat1, newCat2, newSyn1);
						  newWord=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;	// recollecr newWord, newCat1-2, newSyn1;
			  			}
			  		break;
			  default: break;		
			}
		}
	else if(meantype==2)
		{ // "Predicate<Agent, Patient>" meaning; 
		  switch(type)
			{ case 0: // holistic rule; set up meanutter's utterance;
					getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
					break;
			  case 1: // rand holistic rule;
			  		if(NormOrTest==0)
			  			{ // create newHolistic, newHolistCat and insert into IMMem()->m_pOptionComb[0];	
			  			  newHolist=NULL; newHolistCat=NULL;
						  getpLTMem()->RandCrtHolist(meantype, newHolist, newHolistCat, meanutter);	// "Predicate<Agent, Patient>" holistic utterance;
						  getpIMMem()->InHolist(meantype, newHolist, newHolistCat, meanutter);
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;

						  // 	store newHolistic, newHolistCat into LTMem;
						  oldCatThemRole=newHolistCat->getThemRole();
						  getpLTMem()->InLexRule(newHolist);
						  if(oldCatThemRole==newHolistCat->getThemRole()) getpLTMem()->InCategory(newHolistCat);
			  			  else
			  				{ // recreate a holistic cat;
				  			  newHolistCat=new CCat; assert(newHolistCat!=NULL);
				  			  newHolistCat->setThemRole(0);
				  			  // link up newHolist and newHolistCat;
				  			  newHolist->InCat(newHolistCat); 
							  sucInLex=0; newHolistCat->InLex(newHolist, &sucInLex);	// this insertion will always be successful;
							  
				  			  getpLTMem()->InCategory(newHolistCat);
				  			  // adjust IMMem->m_ppOptionComb[0];
				  			  getpIMMem()->getpOptionComb(0)->m_ppCats[0]=newHolistCat;	
			  				}						  

						  newHolist=NULL; newHolistCat=NULL;	// recollect newHolist and newHolistCat;
			  			}
			  		break;
			  case 2: // 1 word + 1 phrase rules;
			  		if((NormOrTest==1)||(NormOrTest==2))
			  			{ if((subtype==2)||(subtype==3)||(subtype==4)||(subtype==5)) break;
			  			  else getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						}
			  		else if(NormOrTest==0)
			  			{ // create newCat1-2 or newSyn1 and insert into IMMem->m_pOptionComb[0];
			  			  newCat1=NULL; newCat2=NULL;
			  			  newSyn1=NULL;
						  getpIMMem()->RandCrtCatSyn_InOC(newCat1, newCat2, newSyn1, meanutter);	// 1 word + 1 phrase rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // store newCat1-2, newSyn1 into LTMem;
						  StoreCatSyn(newCat1, newCat2, newSyn1);	
						  // store newCat1-2, newSyn1 into LTMem;
					 	  newCat1=NULL; newCat2=NULL;
			  			  newSyn1=NULL;	// recollect newCat1-2 and newSyn1;
			  			}
			  		break;
			  case 3: // 3 word rules;
			  		if((NormOrTest==1)||(NormOrTest==2))
			  			{ if((5<=subtype)&&(subtype<=18)) break;
			  			  else getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						}
			  		else if(NormOrTest==0)
			  			{ // create newCat1-3, newSyn1-2 and insert into IMMem->m_pOptionComb[0];
			  			  newCat1=NULL; newCat2=NULL; newCat3=NULL;
			  			  newSyn1=NULL; newSyn2=NULL; newSyn3=NULL;
						  getpIMMem()->RandCrtCatSyn2_InOC(getPerspective(), newCat1, newCat2, newCat3, newSyn1, newSyn2, newSyn3, meanutter);	// 3 word rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // store newCat1-3, newSyn1-3 into LTMem;
						  StoreCat123Syn123(newCat1, newCat2, newCat3, newSyn1, newSyn2, newSyn3);
						  newCat1=NULL; newCat2=NULL; newCat3=NULL;
			  			  newSyn1=NULL; newSyn2=NULL; newSyn3=NULL;	// recollect newCat1-3 and newSyn1-3;
			  			}
			  		break;
			  case 4: // 1 phrase + 1 rand word rules;
			  		if(NormOrTest==0)
			  			{ // create newWord, newCat1-2 or newSyn1 and insert into IMMem->m_pOptionComb[0];
						  newWord=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;
						  getpIMMem()->RandCrtWordPhr_InOC(newWord, newCat1, newCat2, newSyn1, meanutter);	// 1 phrase + 1 rand word rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // 	store newWord, newCat1-2, newSyn1 into LTMem;
						  StoreWordPhraCatSyn(newWord, newCat1, newCat2, newSyn1);
						  newWord=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;	// recollecr newWord, newCat1-2, newSyn1;
			  			}
			  		break;
			  case 5: // 2 words + 1 rand word rules;
			  		if(NormOrTest==0)
			  			{ // create newWord, newCat1-3 or newSyn1-2 and insert into IMMem()->m_pOptionComb[0];
						  newWord=NULL;
			  			  newCat1=NULL; newCat2=NULL; newCat3=NULL;
			  			  newSyn1=NULL; newSyn2=NULL;
			  			  getpIMMem()->RandCrtWord2_InOC(getPerspective(), newWord, newCat1, newCat2, newCat3, newSyn1, newSyn2, meanutter);	// 2 words + 1 rand word rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // store newWord, newCat1-3, newSyn1-2 into LTMem;
						  StoreWordCat123Syn12(newWord, newCat1, newCat2, newCat3, newSyn1, newSyn2);
						  newWord=NULL; 
						  newCat1=NULL; newCat2=NULL; newCat3=NULL;
						  newSyn1=NULL; newSyn2=NULL;	// recollecr newWord, newCat1-3, newSyn1-2;
			  			}
			  		break;
			  case 6: // 1 word + 1 rand phrase rules;
			  		if(NormOrTest==0)
			  			{ // create newWord, newCat1-2 or newSyn1 and insert into IMMem->m_pOptionComb[0];
						  newPhrase=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;
						  getpIMMem()->RandCrtWordPhr_InOC(newPhrase, newCat1, newCat2, newSyn1, meanutter);	// 1 word + 1 rand phrase rules;
						  // set up meanutter's utterance;
						  getpIMMem()->UseOptionCombSetUtter(meanutter);	// use rules in IMMem->m_pOptionComb[0] to set up utterance;
						  // 	store newWord, newCat1-2, newSyn1 into LTMem;
						  StoreWordPhraCatSyn(newPhrase, newCat1, newCat2, newSyn1);
						  newPhrase=NULL; 
						  newCat1=NULL; newCat2=NULL;
						  newSyn1=NULL;	// recollecr newWord, newCat1-2, newSyn1;
			  			}
			  		break;
			  default: break;
			}	
		}
}

void CAgent::SelWinSetUtter(CMeanUtter *meanutter, int NormOrTest)
{ // select winning rules and build up utterance from it;
	assert(meanutter->getpMean()!=NULL); assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2));
	int winindex;
	OptionComb *optiontemp=NULL;
	
	if(getpIMMem()->getNumCombOption()!=0)
		{ winindex=SelWinIndex();	// find the winning rules;
		  if((winindex!=-1)&&(winindex!=0))
		  	{ // exchange IMMem->m_pOptionComb[winindex] with IMMem->m_pOptionComb[0];
		  	  optiontemp=getpIMMem()->getpOptionComb(winindex);
		  	  getpIMMem()->setpOptionComb(winindex, getpIMMem()->getpOptionComb(0));
		  	  getpIMMem()->setpOptionComb(0, optiontemp);
		  	  optiontemp=NULL;	// recollect optiontemp;
		  	}
		  SetUtter(meanutter, NormOrTest);	// build up utterance using IMMem->m_pOptionComb[0]'s rules;
		}
}

void CAgent::ChoMeantoPro(CMeanUtter *meanutter, int NormOrTest, int meanindex)
{ // select meaning for production;
  // NormOrTest=0, normal communication, random select meaning; 1, testing UR, select meanindex; 2, testing Disp, select meanindex;
	assert(((NormOrTest==0)&&(meanindex==-1))||(((NormOrTest==1)||(NormOrTest==2))&&(0<=meanindex)&&(meanindex<getpSemSpace()->getNumIntgMean())));
	// copy meaning into pMU;
  	if(NormOrTest==0) meanutter->setpMean(getpSemSpace()->getpSemItem(getpSemSpace()->RandSelpIntgMeanIndex())->getpIntgMean());
  	else if((NormOrTest==1)||(NormOrTest==2)) meanutter->setpMean(getpSemSpace()->getpSemItem(meanindex)->getpIntgMean());
}

void CAgent::Production(CMeanUtter *meanutter, int NormOrTest)
{ // produce mean's utter in meanutter; if failed to produce, meanutter->m_pUtter[]=-1;
  // NormOrTest=0, normal communication; 1, testing UR; 2, testing Disp;
	assert(meanutter!=NULL); assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2));
  	int numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat;	// number of rules which match the whole or part of the meaning to be expressed;
	int meantype;	// meantype=0, initial value; 
		// 1, fully expressable meanings; 
		// 2, one meaning uncertain "Predicate<Agent, Patient>" meaning; 
		// 3, one meaning uncertain "Predicate<Agent>" meaning; 
		// 4, two meanings uncertain "Predicate<Agent, Patient>" meanings; 
		// 5, totally unexpressable meanings;
	CLexRule **CandLexRule=NULL;	// pointing to candidate lexical rules;
	int numCandLexRule;	// number of candidate lexical rules;

	// 1) copy meanutter's mean into m_pMeanUtter;
	getpMeanUtter()->EmptypMeanUtter(); getpMeanUtter()->setpMean(meanutter->getpMean());

	// 2) produce utterance for m_pMeanUtter's meaning;
	// first, set the chosen mean's meantype based on current lexical rules;
	meantype=0; getpLTMem()->getMeanType(getpMeanUtter(), &meantype, getpSemSpace());
	// 3) check LTMem for rules to express this mean;	
	getpIMMem()->EmpOptionComb();	// empty IMMem->m_ppOptionComb;

	if(getpIMMem()->getMaxNumCombOption()!=0)
		{ // allow working memory;
	  	  // decide candidate ways to express and record related lexical rules/categories/syntactic rules into IMMem;
		  CandLexRule=NULL; numCandLexRule=0;	// initialize CandLexRule;
		  numHolist=numAg=numPred=numPat=numAgPred=numAgPat=numPredPat=0;
		  if(getpMeanUtter()->getpMean()->getElement(2*(getpMeanUtter()->getLengthSem()))==-1)
			{ // Predicate<Agent> meaning;
			  getpLTMem()->SearchCand1(getpSemSpace(), getpMeanUtter(), CandLexRule, &numCandLexRule, &numHolist, &numAg, &numPred);
			  SetCand1(meantype, CandLexRule, &numCandLexRule, &numHolist, &numAg, &numPred);			 
			}
		  else
			{ // Predicate<Agent, Patient> meaning;
			  getpLTMem()->SearchCand2(getpSemSpace(), getpMeanUtter(), CandLexRule, &numCandLexRule, &numHolist, &numAg, &numPred, &numPat, &numAgPred, &numAgPat, &numPredPat);
			  SetCand2(meantype, CandLexRule, &numCandLexRule, &numHolist, &numAg, &numPred, &numPat, &numAgPred, &numAgPat, &numPredPat);
			}
		  SelWinSetUtter(getpMeanUtter(), NormOrTest);	// select winning rules and build up utterance from it;
		  // release memory space for CandLexRule;
		  if(numCandLexRule!=0) { delete [] CandLexRule; CandLexRule=NULL; }

		  // 4) copy m_pMeanUtter->m_pMean to meanutter;
		  meanutter->setpUtter(getpMeanUtter()->getpUtter());
		}
}

// perception part;
void CAgent::setFeedBack(double winrulestr, int *feedback, bool *inBufSuc, int NormOrTest)
{ // according to winrulestr, set up feedback and if feedback=1, store m_pMeanUtter into m_pBuffer;
	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3));
	CMeanUtter *MUbuffer=NULL;
	int bufLoc;	// store the newly inserted MU's location in the buffer;
	
	if(getFeedbackTyp()==0)
		{ // hard feedback;
		  if(FLOAT_BG_EQ(winrulestr, getHardFeedback())) 
  			{ *feedback=1;
			  if((NormOrTest==0)||(NormOrTest==3))
			  	{ // in normal communication; store m_pMeanUtter into m_pBuf;
				  bufLoc=-1; 
				  if(getpBuffer()->getMaxBufSize()!=0) 
				  	{ MUbuffer=new CMeanUtter; assert(MUbuffer!=NULL);
				  	  MUbuffer->copyMeanUtter(getpMeanUtter());
				  	  getpBuffer()->InBuffer(MUbuffer, &bufLoc);
					  MUbuffer=NULL;	// recollect MUbuffer;
				  	}
				  if(bufLoc==-1) *inBufSuc=0;	// MUbuffer is already in the buffer;
				  else *inBufSuc=1;	// new MUbuffer is inserted;				  
			  	}
  			}
  		  else *feedback=0;
		}
	else if(getFeedbackTyp()==1)
		{ // soft feedback;
		  if(FLOAT_SM_EQ(Rand0_1, 1.0/(double)(1+exp(-1.0*getSlope()*(winrulestr-getHardFeedback()))))) 
  			{ *feedback=1;
			  if((NormOrTest==0)||(NormOrTest==3))
			  	{ // in normal communication; store m_pMeanUtter into m_pBuf;
				  bufLoc=-1; 
				  if(getpBuffer()->getMaxBufSize()!=0)
				  	{ MUbuffer=new CMeanUtter; assert(MUbuffer!=NULL);
				  	  MUbuffer->copyMeanUtter(getpMeanUtter());
				   	  getpBuffer()->InBuffer(MUbuffer, &bufLoc);
				  	  MUbuffer=NULL;	// recollect MUbuffer;
				  	}
				  if(bufLoc==-1) *inBufSuc=0;	// MUbuffer is already in the buffer;
				  else *inBufSuc=1;	// new MUbuffer is inserted;				  
			  	}
  			}
  		  else *feedback=0;
		}
}

int CAgent::chkCues(int type, int subtype, CLexRule *lexrule1, CLexRule *lexrule2, CLexRule *lexrule3)
{ // check whether certain cues match the lexical rules;
  // type=1, holistic rule; 
  	// subtype=0;
  // type=2, 2 word rules for "Predicate<Agent>" meaning;
 	// subtype=0;
  // type=3, 1 word rule for "Predicate<Agent>" meaning; 
 	// subtype=1, Ag; subtype=2, Pred1;
  // type=4, 3 word rules for "Predicate<Agent, Patient>" meaning; 
  	// subtype=0; 
  // type=5, 1 word + 1 phrase rules for "Predicate<Agent, Patient>" meanings; 
  	// subtype=1, Ag + PredPat; 2, Pred2 + AgPat; 3, Pat + AgPred;
  // type=6, 2 word rules for "Predicate<Agent, Patient>" meaning; 
  	// subtype=1, Ag + Pred2; 2, Ag + Pat; 3, Pred2 + Pat;
  // type=7, 1 phrase rule for "Predicate<Agent, Patient>" meaning; 
  	// subtype=1, AgPred; 2, AgPat; 3, PredPat; 
  // type=8, 1 word rule for "Predicate<Agent, Patient>" meaning; 
  	// subtype=1, Ag; 2, Pred2; 3, Pat;
  // for complete rules (type=1, 2, 4, 5), check all cues no matter they are used by other complete rules;
  // for incomplete rules (type=3, 6, 7, 8), only check cues with !0 strength;
	assert(((type==1)&&(subtype==0)&&(lexrule1!=NULL)&&(lexrule2==NULL)&&(lexrule3==NULL))||((type==2)&&(subtype==0)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL))||((type==3)&&((subtype==1)||(subtype==2))&&(lexrule1!=NULL)&&(lexrule2==NULL)&&(lexrule3==NULL))||((type==4)&&(subtype==0)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3!=NULL))||(((type==5)||(type==6))&&((subtype==1)||(subtype==2)||(subtype==3))&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL))||(((type==7)||(type==8))&&((subtype==1)||(subtype==2)||(subtype==3))&&(lexrule1!=NULL)&&(lexrule2==NULL)&&(lexrule3==NULL)));
  	int i, j, k, m, cueindex;
  	int lenSemItem=getpSemSpace()->getLengthSemItem();
  	int lenPhrase=2*(getpSemSpace()->getLengthSem());  	
  	int posAg=getpSemSpace()->getLengthSemRole();
  	int posPred=getpSemSpace()->getLengthSem()+getpSemSpace()->getLengthSemRole();
  	int posPat=2*(getpSemSpace()->getLengthSem())+getpSemSpace()->getLengthSemRole();
  	int posPhrase1=0;
  	int posPhrase2=getpSemSpace()->getLengthSem();
  	int posPhrase3=2*(getpSemSpace()->getLengthSem());
  	CArray *cueMean=NULL;
  	
  	cueindex=-1;
	switch(type)
  		{ case 1: // holistic rule;
  				for(i=0;i<getpCues()->getNumCue();i++)
  					{ // for complete rules, check all cues no matter they are used by other complete rules;
    					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
  					  if(*cueMean==*(lexrule1->getpMeanUtter()->getpMean())) { cueindex=i; cueMean=NULL; break; }
  					}
  				break;
  		  case 2: // 2 word rules for "Predicate<Agent>" meaning;
  		  		for(i=0;i<getpCues()->getNumCue();i++)
  		  			{ // for complete rules, check all cues no matter they are used by other complete rules;
  		  			  cueMean=getpCues()->getpCueItem(i)->getpCueMean(); 
					  for(j=0;j<lenSemItem;j++)
					  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
					  		break;
					  	}
					  for(k=0;k<lenSemItem;k++)
					  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPred)!=cueMean->getElement(k+posPred))
					  		break;
					  	}
					  if((j==lenSemItem)&&(k==lenSemItem)) { cueindex=i; cueMean=NULL; break; }
  		  			} 
  		  		break;
  		  case 3: // 1 word rule for "Predicate<Agent>" meaning;
  		  		if(subtype==1)
				 	{ // Ag rule;
					  for(i=0;i<getpCues()->getNumCue();i++)
  		  				{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean(); 
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
							  		break;
							  	}
							  if(j==lenSemItem) { cueindex=i; cueMean=NULL; break; }
					 	 	}
					  	}
					}
				else if(subtype==2)
				  	{ // Pred rule;
					  for(i=0;i<getpCues()->getNumCue();i++)
  		  				{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean(); 
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPred)!=cueMean->getElement(j+posPred))
							  		break;
							  	}
							  if(j==lenSemItem) { cueindex=i; cueMean=NULL; break; }
						  	}
					  	}
				  	}
  		  		break;
  		  case 4: // 3 word rules for "Predicate<Agent, Patient>" meaning;
  		  		for(i=0;i<getpCues()->getNumCue();i++)
  		  			{ // for complete rules, check all cues no matter they are used by other complete rules;
  		  			  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
					  for(j=0;j<lenSemItem;j++)
					  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
					  		break;
					  	}
					  for(k=0;k<lenSemItem;k++)
					  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPred)!=cueMean->getElement(k+posPred))
					  		break;
					  	}
					  for(m=0;m<lenSemItem;m++)
					  	{ if(lexrule3->getpMeanUtter()->getpMean()->getElement(m+posAg)!=cueMean->getElement(m+posPat))
					  		break;
					  	}
					  if((j==lenSemItem)&&(k==lenSemItem)&&(m==lenSemItem)) { cueindex=i; cueMean=NULL; break; }
  		  			}
				break;
  		  case 5: // 1 word + 1 phrase rules for "Predicate<Agent, Patient>" meanings;
				if(subtype==1)
					{ // Ag + PredPat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ // for complete rules, check all cues no matter they are used by other complete rules;
					  	  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
						  for(j=0;j<lenSemItem;j++)
						  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
						  		break;
						  	}
						  for(k=0;k<lenPhrase;k++)
						  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPhrase2)!=cueMean->getElement(k+posPhrase2))
						  		break;
						  	}
						  if((j==lenSemItem)&&(k==lenPhrase)) { cueindex=i; cueMean=NULL; break; }
						}
					}
				else if(subtype==2)
					{ // Pred2 + AgPat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ // for complete rules, check all cues no matter they are used by other complete rules;
					  	  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
						  for(j=0;j<lenSemItem;j++)
						  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPred)!=cueMean->getElement(j+posPred))
						  		break;
						  	}
						  for(k=0;k<(int)(_Half*lenPhrase);k++)
						  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPhrase1)!=cueMean->getElement(k+posPhrase1))
						  		break;
						  	}
						  for(m=0;m<(int)(_Half*lenPhrase);m++)
						  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(m+posPhrase3)!=cueMean->getElement(m+posPhrase3))
						  		break;
						  	}
						  if((j==lenSemItem)&&(k==(int)(_Half*lenPhrase))&&(m==(int)(_Half*lenPhrase))) { cueindex=i; cueMean=NULL; break; }
						}
					}
				else if(subtype==3)
					{ // Pat + AgPred;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ // for complete rules, check all cues no matter they are used by other complete rules;
					  	  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
						  for(j=0;j<lenSemItem;j++)
						  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posPat))
						  		break;
						  	}
						  for(k=0;k<lenPhrase;k++)
						  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPhrase1)!=cueMean->getElement(k+posPhrase1))
						  		break;
						  	}
						  if((j==lenSemItem)&&(k==lenPhrase)) { cueindex=i; cueMean=NULL; break; }
						}
					}
  		  		break;
  		  case 6: // 2 word rules for "Predicate<Agent, Patient>" meaning;
				if(subtype==1)
					{ // Ag + Pred2;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
							  		break;
							  	}
							  for(k=0;k<lenSemItem;k++)
							  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posPred)!=cueMean->getElement(k+posPred))
							  		break;
							  	}
							  if((j==lenSemItem)&&(k==lenSemItem)) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
					}
				else if(subtype==2)
					{ // Ag + Pat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
							  		break;
							  	}
							  for(k=0;k<lenSemItem;k++)
							  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posAg)!=cueMean->getElement(k+posPat))
							  		break;
							  	}
							  if((j==lenSemItem)&&(k==lenSemItem)) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
					}
				else if(subtype==3)
					{ // Pred2 + Pat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();	
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPred)!=cueMean->getElement(j+posPred))
							  		break;
							  	} 
							  for(k=0;k<lenSemItem;k++)
							  	{ if(lexrule2->getpMeanUtter()->getpMean()->getElement(k+posAg)!=cueMean->getElement(k+posPat))
							  		break;
							  	}
							  if((j==lenSemItem)&&(k==lenSemItem)) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
					}
				break;
  		  case 7: // 1 phrase rule for "Predicate<Agent, Patient>" meaning; 
				if(subtype==1)
					{ // AgPred;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenPhrase;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPhrase1)!=cueMean->getElement(j+posPhrase1))
							  		break;
							  	}
							  if(j==lenPhrase) { cueindex=i; cueMean=NULL; break; }
							}
					  	} 
					}
				else if(subtype==2)
					{ // AgPat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
  		  					  for(j=0;j<(int)(_Half*lenPhrase);j++)
  		  					  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPhrase1)!=cueMean->getElement(j+posPhrase1))
  		  					  		break;
  		  					  	}
  		  					  for(k=0;k<(int)(_Half*lenPhrase);k++)
  		  					  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(k+posPhrase3)!=cueMean->getElement(k+posPhrase3))
  		  					  		break;
  		  					  	}
  		  					  if((j==(int)(_Half*lenPhrase))&&(k==(int)(_Half*lenPhrase))) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
					}
				else if(subtype==3)
					{ // PredPat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenPhrase;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPhrase2)!=cueMean->getElement(j+posPhrase2))
							  		break;
 							  	}
							  if(j==lenPhrase) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
					}
  		  		break;
  		  case 8: // 1 word rule for "Predicate<Agent, Patient>" meaning;
  		  		if(subtype==1)
  		  			{ // Ag;  	
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posAg))
							  		break;
							  	}
							  if(j==lenSemItem) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
  		  			}
  		  		else if(subtype==2)
  		  			{ // Pred; 
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posPred)!=cueMean->getElement(j+posPred))
							  		break;
							  	}
							  if(j==lenSemItem) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
  		  			}
  		  		else if(subtype==3)
  		  			{ // Pat;
					  for(i=0;i<getpCues()->getNumCue();i++)
					  	{ if(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))
  		  					{ // for incomplete rules, only check cues with !0 strength;
  		  					  cueMean=getpCues()->getpCueItem(i)->getpCueMean();
							  for(j=0;j<lenSemItem;j++)
							  	{ if(lexrule1->getpMeanUtter()->getpMean()->getElement(j+posAg)!=cueMean->getElement(j+posPat))
							  		break;
							  	}
							  if(j==lenSemItem) { cueindex=i; cueMean=NULL; break; }
							}
					  	}
  		  			}
  		  		break;
  		  default: break;
  		}
  	return cueindex;
}

void CAgent::bltMeanUtter(CMeanUtter *meanutter, int type, int subtype, CLexRule *lexrule1, CLexRule *lexrule2, CLexRule *lexrule3)
{ // build up meanutter using lexical rules;
  // type=1, 2 word rules for "Predicate<Agent>" meaning;
  	// subtype=0;
  // type=2, 3 word rules for "Predicate<Agent, Patient>" meaning;
  	// subtype=0;
  // type=3, 1 word rule + 1 phrase rule for "Predicate<Agent, Patient>" meaning;
  	// subtype=1, Ag + PredPat;
  	// subtype=2, Pred2 + AgPat;
  	// subtype=3, Pat + AgPred;
	assert(meanutter!=NULL);
  	assert(((type==1)&&(subtype==0)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL))||((type==2)&&(subtype==0)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3!=NULL))||((type==3)&&(1<=subtype)&&(subtype<=3)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL)));

	int lenSemItem=getpSemSpace()->getLengthSemItem();
  	int lenPhrase=2*(getpSemSpace()->getLengthSem());
  	int posAg=getpSemSpace()->getLengthSemRole();
  	int posPred=getpSemSpace()->getLengthSem()+getpSemSpace()->getLengthSemRole();
  	int posPat=2*(getpSemSpace()->getLengthSem())+getpSemSpace()->getLengthSemRole();

  	if(type==1)
  		{ // create a "Predicate<Agent>" meaning using 2 word rules; 
  		  meanutter->setPartMean(getpSemSpace()->getpSemRole(0), 0, 0, getpSemSpace()->getLengthSemRole());	// Ag's semantic role;
  		  meanutter->setPartMean(lexrule1->getpMeanUtter()->getpMean(), posAg, posAg, lenSemItem);	// Ag's semantic item;
  		  meanutter->setPartMean(getpSemSpace()->getpSemRole(1), getpSemSpace()->getLengthSem(), 0, getpSemSpace()->getLengthSemRole());	// Pred1's semantic role;
  		  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), posPred, posPred, lenSemItem);	// Pred1's semantic item;  		  
  		}
  	else if(type==2)
  		{ // create a "Predicate<Agent, Patient>" meaning using 3 word rules;
  		  meanutter->setPartMean(getpSemSpace()->getpSemRole(0), 0, 0, getpSemSpace()->getLengthSemRole());	// Ag's semantic role;
  		  meanutter->setPartMean(lexrule1->getpMeanUtter()->getpMean(), posAg, posAg, lenSemItem);	// Ag's semantic item;
  		  meanutter->setPartMean(getpSemSpace()->getpSemRole(2), getpSemSpace()->getLengthSem(), 0, getpSemSpace()->getLengthSemRole());	// Pred2's semantic role;
  		  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), posPred, posPred, lenSemItem);	// Pred2's semantic item;
  		  meanutter->setPartMean(getpSemSpace()->getpSemRole(3), 2*(getpSemSpace()->getLengthSem()), 0, getpSemSpace()->getLengthSemRole());	// Pat's semantic role;
  		  meanutter->setPartMean(lexrule3->getpMeanUtter()->getpMean(), posPat, posAg, lenSemItem);	// Pat's semantic item;
  		}
  	else if(type==3)
  		{ if(subtype==1)
  			{ // Ag + PredPat;
			  meanutter->setPartMean(getpSemSpace()->getpSemRole(0), 0, 0, getpSemSpace()->getLengthSemRole());	// Ag's semantic role;
  		  	  meanutter->setPartMean(lexrule1->getpMeanUtter()->getpMean(), posAg, posAg, lenSemItem);	// Ag's semantic item;
  		  	  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), getpSemSpace()->getLengthSem(), getpSemSpace()->getLengthSem(), lenPhrase);	// PredPat phrase;
  			}
  		  else if(subtype==2)
  		  	{ // Pred2 + AgPat;
			  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), 0, 0, getpSemSpace()->getLengthSem());	// Ag's part from AgPat phrase;
			  meanutter->setPartMean(getpSemSpace()->getpSemRole(2), getpSemSpace()->getLengthSem(), 0, getpSemSpace()->getLengthSemRole());	// Pred2's semantic role;
			  meanutter->setPartMean(lexrule1->getpMeanUtter()->getpMean(), posPred, posPred, lenSemItem);	// Pred2's semantic item;
			  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), 2*(getpSemSpace()->getLengthSem()), 2*(getpSemSpace()->getLengthSem()), getpSemSpace()->getLengthSem());	// Pat's part from AgPat phrase;
  		  	}
  		  else if(subtype==3)
  		  	{ // Pat + AgPred;
			  meanutter->setPartMean(lexrule2->getpMeanUtter()->getpMean(), 0, 0, lenPhrase);	// AgPred phrase;
			  meanutter->setPartMean(getpSemSpace()->getpSemRole(3), 2*(getpSemSpace()->getLengthSem()), 0, getpSemSpace()->getLengthSemRole());	// Pat's semantic role;
			  meanutter->setPartMean(lexrule1->getpMeanUtter()->getpMean(), posPat, posAg, lenSemItem);	// Pat's semantic item;
  		  	}
  		}
}

void CAgent::fillOptPer1(int cond, int type, int cueindex, CLexRule *matlexrule, CatList *catlist)
{ // fill in optiontemp with 1 word rule or 1 phrase rule;
  // cond=1, "Predicate<Agent>" meaning (1 word);
  // cond=2, "Predicate<Agent, Patient>" meaning (1 phrase);
  // cond=3, "Predicate<Agent, Patient>" meaning (1 word);
  	// type=1, 1 cat, 0 syn;
  	// type=2, 0 cat, 0 syn;
  	assert((1<=cond)&&(cond<=3)&&(cueindex!=-1)); assert(matlexrule!=NULL); assert(((type==1)&&(catlist!=NULL))||((type==2)&&(catlist==NULL)));
	double lexstr, synstr, lingstr, cuestr;
	OptionComb *optiontemp=NULL;

	// build up optioncomb;
	optiontemp=new OptionComb; assert(optiontemp!=NULL);
	
	// no use meantype, type, subtype;
	optiontemp->m_nMeanType=-1; optiontemp->m_nType=-1; optiontemp->m_nSubType=-1;
	// lexical rule part;
	optiontemp->m_nNumLexRules=1; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=matlexrule;
	// category, syntactic rule and combine strength part;
	lexstr=synstr=0.0;
	switch(type)
		{ case 1: // 1 cat, 0 syn;
  		  		  // category part;
		  		  optiontemp->m_nNumCats=1;
				  optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				  optiontemp->m_ppCats[0]=catlist->getpCat(); 
				  // syntactic rule part;
				  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				  // combine strength part;
				  lexstr=_Half*(matlexrule->getLexStr()+getpIMMem()->getNeuLexStr());	
				  synstr=_Half*(catlist->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
				  break;
		  case 2: // 0 cat, 0 syn;
				  // category part;
				  optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL;					  	
				  // syntactic rule part;
				  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				  // combine strength part;
				  lexstr=_Half*(matlexrule->getLexStr()+getpIMMem()->getNeuLexStr());
				  synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
				  break;
		  default: break;
		}
	lingstr=lexstr+synstr;				
	cuestr=getpCues()->getpCueItem(cueindex)->getCueStr();
	optiontemp->m_dCombinStr=lingstr+cuestr;
   	getpCues()->getpCueItem(cueindex)->setCueStr(-1.0);	// temporary indicate that that cue has been used;
		  
	getpIMMem()->UpdOptionComb(optiontemp);	// update IMMem->OptionComb;
	optiontemp=NULL;	// recollect optiontemp;
}

void CAgent::fillOptPer2(int NormOrTest, int cond, int type, int subtype, CLexRule *matlexrule1, CLexRule *matlexrule2, CatList *catlist1, CatList *catlist2, CSynRule *syn12)
{ // update categories, syntactic rules and lingstr using 2 rules;
  // for complete rules;	
  	// cond=1, for "Predicate<Agent>" meaning (2 words);
  			// subtype=0;
  	// cond=2, for "Predicate<Agent, Patient>" meaning (1 word + 1 phrase);
  			// subtype=9(S+VO/OV); 10(VO/OV+S); 11(V(S)O or O(S)V); 
  			// subtype=12(V+SO/OS); 13(SO/OS+V); 14(S(V)O or O(V)S); 
  			// subtype=15(O+SV/VS); 16(SV/VS+O); 17(S(O)V or V(O)S);
  // for incomplete rules;
  	// cond=3, for "Predicate<Agent, Patient>" meaning (2 words);
  			// subtype=2(SV), 3(VS), 4(SO), 5(OS), 6(VO), 7(OV);
  		// type=1, 2 cats, 1 syn;
  		// type=2, 2 cats, 0 syn;
  		// type=3, 1 cat(cat1), 0 syn;
  		// type=4, 1 cat (cat2), 0 syn;
  		// type=5, 0 cat, 0 syn;  			
  	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3));
	assert(((cond==1)&&(1<=type)&&(type<=5)&&(subtype==0))||((cond==2)&&(1<=type)&&(type<=5)&&(9<=subtype)&&(subtype<=17))||((cond==3)&&(1<=type)&&(type<=5)&&(2<=subtype)&&(subtype<=7)));
  	assert((matlexrule1!=NULL)&&(matlexrule2!=NULL));
  	OptionComb *optiontemp=NULL;
	double lexstr, synstr, lingstr, cuestr;
	int cueindex;
	int comp2ret;
	
	// build up OptionComb;
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// no use meantype, type, subtype;
	optiontemp->m_nMeanType=-1; optiontemp->m_nType=-1; optiontemp->m_nSubType=-1;
	// lexical rule part;
	optiontemp->m_nNumLexRules=2; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=matlexrule1; optiontemp->m_ppLexRules[1]=matlexrule2;
	// category, syntactic rule and combine strength parts;
	lingstr=0.0;
	switch(type)
		{ case 1: // 2 cats, 1 syn;
  				// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=1; 
				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
				optiontemp->m_ppSynRules[0]=syn12;
				// combine strength part;
				lexstr=synstr=0.0;
				if((cond==1)||(cond==2))
					{ lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
					  synstr=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
					}
				else if(cond==3)
					{ lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
					  comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
					  if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuLexStr());
				  	  else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuLexStr());
					}
				lingstr=lexstr+synstr;
				break;
		  case 2: // 2 cats, 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=synstr=0.0;
				if((cond==1)||(cond==2)) 
				 	{ lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
				  	  synstr=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
				  	}
				else if(cond==3)
				  	{ lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
				  	  comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
					  if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuLexStr());
				  	  else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuLexStr());
				  	}
				lingstr=lexstr+synstr;
				break;
		  case 3: // cat1, 0 syn;
		  		// category part;
		  		optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
			  	optiontemp->m_ppCats[0]=catlist1->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=0.0;
				if((cond==1)||(cond==2)) lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
				else if(cond==3) lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
				synstr=_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
				lingstr=lexstr+synstr;
				break;
		  case 4: // cat2, 0 syn;
		  	 	// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=0.0;
				if((cond==1)||(cond==2)) lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
				else if(cond==3) lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
				synstr=_Half*(getpIMMem()->getNeuAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
				lingstr=lexstr+synstr;
				break;
		  case 5: // 0 cat, 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL;
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=0.0;
				if((cond==1)||(cond==2)) lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
			  	else if(cond==3) lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
				synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
				lingstr=lexstr+synstr;
		  		break;		  
		  default: break;		
		}

	if((NormOrTest==0)||(NormOrTest==2)||(NormOrTest==3))
	  	{ // in normal (horizontal or vertical) communication, check whether certain cue matches it;
	  	  cueindex=-1;
		  if(cond==1) cueindex=chkCues(2, 0, matlexrule1, matlexrule2, NULL);	
		  else if(cond==2)
		  	{ switch(subtype)
			  	{ case 9: case 10: case 11: cueindex=chkCues(5, 1, matlexrule1, matlexrule2, NULL); break;	// Ag + PredPat;
				  case 12: case 13: case 14: cueindex=chkCues(5, 2, matlexrule1, matlexrule2, NULL); break;	// Pred2 + AgPat;
				  case 15: case 16: case 17: cueindex=chkCues(5, 3, matlexrule1, matlexrule2, NULL); break;	// Pat + AgPred;
				  default: break;
				}
		  	}
		  else if(cond==3)
		  	{ switch(subtype)
		  		{ case 2: case 3: cueindex=chkCues(6, 1, matlexrule1, matlexrule2, NULL); break;	// Ag + Pred2: 2 word rules for "Predicate<Agent, Patient>" meaning;
				  case 4: case 5: cueindex=chkCues(6, 2, matlexrule1, matlexrule2, NULL); break;	// Ag + Pat: 2 word rules for "Predicate<Agent, Patient>" meaning;
				  case 6: case 7: cueindex=chkCues(6, 3, matlexrule1, matlexrule2, NULL); break;	// Pred2 + Pat: 2 word rules for "Predicate<Agent, Patient>" meaning;
				  default: break;
		  		}
		  	}
		  // calculate combstr;
		  if(cueindex!=-1) 
			{ cuestr=getpCues()->getpCueItem(cueindex)->getCueStr();
			  optiontemp->m_dCombinStr=lingstr+cuestr; 
			  if((cond==1)||(cond==2)) getpCues()->getpCueItem(cueindex)->setCueStr(0.0);	// indicate that that cue has been used;
			  else if(cond==3) getpCues()->getpCueItem(cueindex)->setCueStr(-1.0);	// temporary indicate that that cue has been used;
		  	}
		  else optiontemp->m_dCombinStr=lingstr;
		}
	else optiontemp->m_dCombinStr=lingstr;	// in testing, no cues;
					  
	getpIMMem()->UpdOptionComb(optiontemp);	// update IMMem->OptionComb;
	optiontemp=NULL;	// recollect optiontemp;
}

void CAgent::fillOptPer3(int NormOrTest, int type, CLexRule *matlexrule1, CLexRule *matlexrule2, CLexRule *matlexrule3, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13)
{ // update categories, syntactic rules and combine strength using 3 word rules;
  // "Predicate<Agent, Patient>" meaning (3 words);
   	// type=1, 3 cats, 3 syn;
	// type=2, 3 cats, 2 syn(12, 23);
	// type=3, 3 cats, 2 syn(12, 13);
	// type=4, 3 cats, 2 syn(23, 13);
	// type=5, 3 cats, 1 syn(12);
	// type=6, 3 cats, 1 syn(23);
	// type=7, 3 cats, 1 syn(13);
	// type=8, 3 cats, 0 syn;
	// type=9, 2 cats(S+V), 1 syn(12);
	// type=10, 2 cats(S+V), 0 syn;
	// type=11, 2 cats(S+O), 1 syn(13);
	// type=12, 2 cats(S+O), 0 syn;
	// type=13, 2 cats(V+O), 1 syn(23);
	// type=14, 2 cats(V+O), 0 syn;
	// type=15, 1 cats(S), 0 syn;
	// type=16, 1 cats(V), 0 syn;
	// type=17, 1 cats(O), 0 syn;
	// type=18, 0 cat, 0 syn;
  	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3)); assert((1<=type)&&(type<=18)); 
  	assert((matlexrule1!=NULL)&&(matlexrule2!=NULL)&&(matlexrule3!=NULL));
	OptionComb *optiontemp=NULL;
  	double lexstr, synstr, lingstr, cuestr;
  	double assowei12, assowei23, assowei13;
  	int cueindex;
	int comp2ret, comp3ret;

	// build up OptionComb;
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// no use meantype, type, subtype;
	optiontemp->m_nMeanType=-1; optiontemp->m_nType=-1; optiontemp->m_nSubType=-1;
	// lexical rule part;
	optiontemp->m_nNumLexRules=3; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=matlexrule1; optiontemp->m_ppLexRules[1]=matlexrule2; optiontemp->m_ppLexRules[2]=matlexrule3;
	// category, syntactic rule and combine strength part;
	lingstr=0.0;
	switch(type)
		{ case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				// category part;
		  		optiontemp->m_nNumCats=3;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat(); optiontemp->m_ppCats[2]=catlist3->getpCat();
			  	// syntactic rule and combine strength;
		  		switch(type)
		  			{ case 1: // 3 cats, 3 syn;
		  					// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=3; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn23; optiontemp->m_ppSynRules[2]=syn13;
							// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
							assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Third*(assowei12+assowei23+assowei13);
		  	  				lingstr=lexstr+synstr;
		  					break;
		  			  case 2: // 3 cats, 2 syn(12, 23);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn23;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							synstr=_Half*(assowei12+assowei23);
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 3: // 3 cats, 2 syn(12, 13);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12; optiontemp->m_ppSynRules[1]=syn13;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Half*(assowei12+assowei13);
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 4: // 3 cats, 2 syn(23, 13);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=2; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn23; optiontemp->m_ppSynRules[1]=syn13;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
		  	  				synstr=_Half*(assowei23+assowei13);
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 5: // 3 cats, 1 syn(12);
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=1; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn12;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
							if(comp2ret==1)
								{ assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
		  	  					  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp2ret==2)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 6: // 3 cats, 1 syn(23); 
		  			  		// syntactic rule part;
		  	  				optiontemp->m_nNumSynRules=1; 
		  	  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  	  				optiontemp->m_ppSynRules[0]=syn23;
		  	  				// combine strength part;
		  	  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
							if(comp2ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
							else if(comp2ret==2)
								{ assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
		  	  					  synstr=_Half*(assowei23+assowei13);
								}
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 7: // 3 cats, 1 syn(13);
		  			  		// syntactic rule part;
			  				optiontemp->m_nNumSynRules=1; 
			  				optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
			  				optiontemp->m_ppSynRules[0]=syn13;
			  				// combine strength part;
			  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  	  				assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr();
							synstr=0.0;
							comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
							if(comp2ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp2ret==2)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei23+assowei13);
								}
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  case 8: // 3 cats, 0 syn;
		  			  		// syntactic rule part;
			  				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
			  				// combine strength part;
			  				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
							synstr=0.0;
							comp3ret=CGenFuncClass::comp3values_big(catlist1->getAssoWei(), catlist2->getAssoWei(), catlist3->getAssoWei());
							if(comp3ret==1)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
							 	  synstr=_Half*(assowei12+assowei13);
								}
							else if(comp3ret==2)
								{ assowei12=_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  synstr=_Half*(assowei12+assowei23);
								}
							else if(comp3ret==3)
								{ assowei23=_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
								  assowei13=_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr();
							 	  synstr=_Half*(assowei23+assowei13);
								}
		  	  				lingstr=lexstr+synstr;
		  			  		break;
		  			  default: break;
		  			}
				break;
		  case 9: // 2 cats(S+V), 1 syn(12);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn12;
		  		// combine strength part;
		  		lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*syn12->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		lingstr=lexstr+synstr;
		  		break;
		  case 10: // 2 cats(S+V), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist2->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist2->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				lingstr=lexstr+synstr;
				break;
		  case 11: // 2 cats(S+O), 1 syn(13);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn13;
		  		// combine strength part;
		  		lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  		synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*syn13->getSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		lingstr=lexstr+synstr;
		  		break;
		  case 12: // 2 cats(S+O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		 		// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist1->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist1->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				lingstr=lexstr+synstr;
				break;
		  case 13: // 2 cats(V+O), 1 syn (23);
		  		// category part;
		  		optiontemp->m_nNumCats=2;
		  		optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
		  		optiontemp->m_ppCats[0]=catlist2->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=1; 
		  		optiontemp->m_ppSynRules=new CSynRule * [optiontemp->m_nNumSynRules]; assert(optiontemp->m_ppSynRules!=NULL);
		  		optiontemp->m_ppSynRules[0]=syn23;
		  		// combine strength part;
		  		lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  		synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		else if(comp2ret==2) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*syn23->getSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
		  		lingstr=lexstr+synstr;
		  		break;
		  case 14: // 2 cats(V+O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=2;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat(); optiontemp->m_ppCats[1]=catlist3->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=0.0;
				comp2ret=CGenFuncClass::comp2values_big(catlist2->getAssoWei(), catlist3->getAssoWei());
				if(comp2ret==1) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				else if(comp2ret==2) synstr=_Half*(_Half*(catlist2->getAssoWei()+catlist3->getAssoWei())*getpIMMem()->getNeuSynStr()+_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
				lingstr=lexstr+synstr;
				break;
		  case 15: // 1 cats(S), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist1->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=_Half*(catlist1->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
		 		lingstr=lexstr+synstr;
				break;
		  case 16: // 1 cats(V), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist2->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=_Half*(catlist2->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
	  			lingstr=lexstr+synstr;		  
				break;
		  case 17: // 1 cats(O), 0 syn;
		  		// category part;
				optiontemp->m_nNumCats=1;
				optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
				optiontemp->m_ppCats[0]=catlist3->getpCat();
				// syntactic rule part;
				optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;
				lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
				synstr=_Half*(catlist3->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr();
	  			lingstr=lexstr+synstr;		  
				break;
		  case 18: // 0 cat, 0 syn; 
		  		// category part;
		  		optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL; 
		  		// syntactic rule part;
		  		optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
				// combine strength part;		  		
		  		lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+matlexrule3->getLexStr());
		  		synstr=getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
		  		lingstr=lexstr+synstr;
		  		break;
		  default: break;		
		}

	if((NormOrTest==0)||(NormOrTest==2)||(NormOrTest==3))
	  	{ // in normal (horizontal or vertical) communication, check whether certain cue matches it;
		  cueindex=chkCues(4, 0, matlexrule1, matlexrule2, matlexrule3);	// 3 word rules "Predicate<Agent, Patient>" meaning;
		  // calculate combstr;
		  if(cueindex!=-1) 
			{ cuestr=getpCues()->getpCueItem(cueindex)->getCueStr();
		  	  optiontemp->m_dCombinStr=lingstr+cuestr;
		  	  getpCues()->getpCueItem(cueindex)->setCueStr(0.0);	// indicate that that cue has been used;
 			}
		  else optiontemp->m_dCombinStr=lingstr;
	  	}
	else optiontemp->m_dCombinStr=lingstr;	// in testing, no cues;

	getpIMMem()->UpdOptionComb(optiontemp);	// update IMMem->OptionComb;
	optiontemp=NULL;	// recollect optiontemp;	
}

void CAgent::updCandMeanUtter(CMeanUtter *meanutter, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter)
{ // update CandMeanUtter;
	assert(meanutter!=NULL);
	int i, numnewCandMeanUtter;
	CMeanUtter **NewCandMeanUtter=NULL;
	
	if(*numCandMeanUtter==0)
		{ // create new CandMeanUtter; 
		  (*numCandMeanUtter)++;
		  CandMeanUtter=new CMeanUtter * [*numCandMeanUtter]; assert(CandMeanUtter!=NULL);
		  CandMeanUtter[0]=meanutter;
		}
	else
		{ // no check of whether meanutter is already in CandMeanUtter; 
		  // new optioncomb;
		  numnewCandMeanUtter=(*numCandMeanUtter)+1;
		  NewCandMeanUtter=new CMeanUtter * [numnewCandMeanUtter]; assert(NewCandMeanUtter!=NULL);
		  for(i=0;i<numnewCandMeanUtter;i++)
		  	NewCandMeanUtter[i]=NULL;
		  for(i=0;i<numnewCandMeanUtter-1;i++)
		  	NewCandMeanUtter[i]=CandMeanUtter[i];
		  NewCandMeanUtter[numnewCandMeanUtter-1]=meanutter;
		  // delete original CandMeanUtter;
		  delete [] CandMeanUtter; CandMeanUtter=NULL;
		  *numCandMeanUtter=0;
		  // copy NewCandMeanUtter to CandMeanUtter;
		  *numCandMeanUtter=numnewCandMeanUtter; CandMeanUtter=NewCandMeanUtter;
		  NewCandMeanUtter=NULL;	// recollect NewCandMeanUtter;
		}	
}

// for complete SV or SVO meanings;
void CAgent::BldCombPerHolist(int NormOrTest, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, CLexRule *matlexrule)
{ // check whether certain cue matches the holistic rule and build IMMem->CombOption;
	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3)); assert(matlexrule!=NULL);
	OptionComb *optiontemp=NULL;
	CMeanUtter *meanuttertemp=NULL;
	double lingstr, cuestr;
	int cueindex;
	
	// build up OptionComb;
	optiontemp=new OptionComb; assert(optiontemp!=NULL);

	// no use meantype, type, subtype;
	optiontemp->m_nMeanType=-1; optiontemp->m_nType=-1; optiontemp->m_nSubType=-1;
	// lexical rule part;
	optiontemp->m_nNumLexRules=1; 
	optiontemp->m_ppLexRules=new CLexRule * [optiontemp->m_nNumLexRules]; assert(optiontemp->m_ppLexRules!=NULL);
	optiontemp->m_ppLexRules[0]=matlexrule;
	// category part;
	optiontemp->m_nNumCats=1;
	optiontemp->m_ppCats=new CCat * [optiontemp->m_nNumCats]; assert(optiontemp->m_ppCats!=NULL);
	optiontemp->m_ppCats[0]=(matlexrule->getpCatList(0))->getpCat();
	// syntactic rule part;
	optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
	// combine strength part;
	lingstr=matlexrule->getLexStr()+getpIMMem()->getNeuAssoWei()*getpIMMem()->getNeuSynStr();
	if((NormOrTest==0)||(NormOrTest==2)||(NormOrTest==3))
		{ // in normal (horizontal or vertical) communication, check whether certain cue matches it;
		  cueindex=chkCues(1, 0, matlexrule, NULL, NULL);	// holist rule;
		  // calculate combstr;
		  if(cueindex!=-1) 
			{ cuestr=getpCues()->getpCueItem(cueindex)->getCueStr();
			  optiontemp->m_dCombinStr=lingstr+cuestr;
			  getpCues()->getpCueItem(cueindex)->setCueStr(0.0);	// indicate that that cue has been used;
 			}
		  else optiontemp->m_dCombinStr=lingstr;
		}
	else optiontemp->m_dCombinStr=lingstr;	// in testing, no cues;	

	getpIMMem()->UpdOptionComb(optiontemp);	// update IMMem->OptionComb;
	optiontemp=NULL;	// recollect optiontemp;

	// build up CandMeanUtter;
	meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
	meanuttertemp->setpMean(matlexrule->getpMeanUtter()->getpMean());
	updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
	meanuttertemp=NULL;	// recollect meanuttertemp;
}

void CAgent::BldCombPerSV2word(int NormOrTest, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule1, CLexRule *matlexrule2)
{ // check whether certain cue matches 2 SV word rules and build up CombOption;
  // type=1(SV); 2(VS);
	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3)); assert((type==1)||(type==2)); assert((matlexrule1!=NULL)&&(matlexrule2!=NULL));
	int i, j, m;
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist1=NULL, *catlist2=NULL;
	CSynRule *syn12=NULL;
	double lexstr, synstr, combwei;
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;

	if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()!=0)) 
		{ relaCatListSyn=NULL; numRelaCatListSyn=0;
		  for(i=0;i<matlexrule1->getCatNum();i++)
		  	{ if(matlexrule1->getpCatList(i)->getThemRole()==1)
		 	 	{ // matlexrule1's catgeory is Ag;
		 	 	  for(j=0;j<matlexrule2->getCatNum();j++)
		  		  	for(m=0;m<getpLTMem()->getNumSynRule();m++)
						{ if(getpLTMem()->chkSynCond1(type, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
						  	{ lexstr=_Half*(matlexrule1->getLexStr()+matlexrule2->getLexStr());
							  synstr=_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr();
							  combwei=lexstr+synstr;
							  getpLTMem()->rec2Cat1Syn(1, 1, combwei, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);	// 2 cats, 1 syn (SV/VS); 
					 	  	}
					  	}
				}
			}
		  catlist1=NULL; catlist2=NULL; 
		  syn12=NULL;
		  getpLTMem()->FindrelCatListSyn_Rela2Cat(relaCatListSyn, &numRelaCatListSyn, catlist1, catlist2, syn12);
		  if(syn12!=NULL) fillOptPer2(NormOrTest, 1, 1, 0, matlexrule1, matlexrule2, catlist1, catlist2, syn12);	// 2 cats, 1 syn;
		  else
			{ // use matlexrule1, matlexrule2's categories with highest assowei;
			  catlist1=NULL; matlexrule1->FindCatListwithHighAsso(0, 1, catlist1);
			  catlist2=NULL; matlexrule2->FindCatListwithHighAsso(1, -1, catlist2);
			  if((catlist1!=NULL)&&(catlist2!=NULL)) fillOptPer2(NormOrTest, 1, 2, 0, matlexrule1, matlexrule2, catlist1, catlist2, NULL);	// 2 cats, 0 syn;
			  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPer2(NormOrTest, 1, 3, 0, matlexrule1, matlexrule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
			  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPer2(NormOrTest, 1, 4, 0, matlexrule1, matlexrule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
			  else fillOptPer2(NormOrTest, 1, 5, 0, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  	}
		  catlist1=NULL; catlist2=NULL; // recollect catlist1, catlist2;
		  syn12=NULL;	// recollect syn12;	
		}
	else if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()==0)) 
		{ catlist1=NULL; matlexrule1->FindCatListwithHighAsso(0, 1, catlist1);
		  if(catlist1!=NULL) fillOptPer2(NormOrTest, 1, 3, 0, matlexrule1, matlexrule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
		  else fillOptPer2(NormOrTest, 1, 5, 0, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;	
		  catlist1=NULL;	// recollect catlist1;	
		}	
	else if((matlexrule1->getCatNum()==0)&&(matlexrule2->getCatNum()!=0)) 
		{ catlist2=NULL; matlexrule2->FindCatListwithHighAsso(1, -1, catlist2);
		  if(catlist2!=NULL) fillOptPer2(NormOrTest, 1, 4, 0, matlexrule1, matlexrule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
		  else fillOptPer2(NormOrTest, 1, 5, 0, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  catlist2=NULL;	// recollect catlist2;
		}
	else fillOptPer2(NormOrTest, 1, 5, 0, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;

	// build up CandMeanUtter;
	meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
	bltMeanUtter(meanuttertemp, 1, 0, matlexrule1, matlexrule2, NULL);	// build up meanutter using 2 SV word rules;
	updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
	meanuttertemp=NULL;	// recollect meanuttertemp;
}

void CAgent::BldCombPerSVO3word(int NormOrTest, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule1, CLexRule *matlexrule2, CLexRule *matlexrule3)
{ // check whether certain cue matches 3 SVO word rules and build up CombOption;
  // type=3(SVO); 4(SOV); 5(OSV); 6(VSO); 7(VOS); 8(OVS);
  	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3)); assert((3<=type)&&(type<=8)); assert((matlexrule1!=NULL)&&(matlexrule2!=NULL)&&(matlexrule3!=NULL));
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist1=NULL, *catlist2=NULL, *catlist3=NULL;	// temp category list;
	CSynRule *syn12=NULL, *syn23=NULL, *syn13=NULL;	// temp syntactic rule;
 			
	// 3 rules have categories;
	if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()!=0)&&(matlexrule3->getCatNum()!=0))
		{ catlist1=NULL; catlist2=NULL; catlist3=NULL;
		  syn12=NULL; syn23=NULL; syn13=NULL;
		  getpLTMem()->ChkRela3CatPer(type, matlexrule1, matlexrule2, matlexrule3, 1, 3, 4, catlist1, catlist2, catlist3, syn12, syn23, syn13);
		  // 3 categories;
		  if((catlist1!=NULL)&&(catlist2!=NULL)&&(catlist3!=NULL))
			{ if((syn12!=NULL)&&(syn23!=NULL)&&(syn13!=NULL)) fillOptPer3(NormOrTest, 1, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, syn12, syn23, syn13);	// 3 cats, 3 syn;
			  else if((syn12!=NULL)&&(syn23!=NULL)&&(syn13==NULL)) fillOptPer3(NormOrTest, 2, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, syn12, syn23, NULL);	// 3 cats, 2 syn(12, 23);
			  else if((syn12!=NULL)&&(syn23==NULL)&&(syn13!=NULL)) fillOptPer3(NormOrTest, 3, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, syn12, NULL, syn13);	// 3 cats, 2 syn(12, 13);
			  else if((syn12==NULL)&&(syn23!=NULL)&&(syn13!=NULL)) fillOptPer3(NormOrTest, 4, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, NULL, syn23, syn13);	// 3 cats, 2 syn(23, 23);
			  else if((syn12!=NULL)&&(syn23==NULL)&&(syn13==NULL)) fillOptPer3(NormOrTest, 5, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, syn12, NULL, NULL);	// 3 cats, 1 syn(12);
			  else if((syn12==NULL)&&(syn23!=NULL)&&(syn13==NULL)) fillOptPer3(NormOrTest, 6, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, NULL, syn23, NULL);	// 3 cats, 1 syn(23);
			  else if((syn12==NULL)&&(syn23==NULL)&&(syn13!=NULL)) fillOptPer3(NormOrTest, 7, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, NULL, NULL, syn13);	// 3 cats, 2 syn(13);
			  else fillOptPer3(NormOrTest, 8, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, catlist3, NULL, NULL, NULL);	// 3 cats, 0 syn;
		  	}
		  // 2 categories;
		  else if((catlist1!=NULL)&&(catlist2!=NULL)&&(catlist3==NULL))
		  	{ if(syn12!=NULL) fillOptPer3(NormOrTest, 9, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, NULL, syn12, NULL, NULL);	// 2 cats(S+V), 1 syn(12);
		  	  else fillOptPer3(NormOrTest, 10, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, NULL, NULL, NULL, NULL);	// 2 cats(S+V), 0 syn;
		  	}
		  else if((catlist1!=NULL)&&(catlist2==NULL)&&(catlist3!=NULL))
		  	{ if(syn13!=NULL) fillOptPer3(NormOrTest, 11, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, catlist3, NULL, NULL, syn13);	// 2 cats(S+O), 1 syn(13);
		  	  else fillOptPer3(NormOrTest, 12, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, catlist3, NULL, NULL, NULL);	// 2 cats(S+O), 0 syn;
		  	}
		  else if((catlist1==NULL)&&(catlist2!=NULL)&&(catlist3!=NULL))
		  	{ if(syn23!=NULL) fillOptPer3(NormOrTest, 13, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, catlist3, NULL, syn23, NULL);	// 2 cats(V+O), 1 syn(23);
		  	  else fillOptPer3(NormOrTest, 14, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, catlist3, NULL, NULL, NULL);	// 2 cats(V+O), 0 syn;
		  	}
		  // 1 categories;
		  else if((catlist1!=NULL)&&(catlist2==NULL)&&(catlist3==NULL)) fillOptPer3(NormOrTest, 15, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
		  else if((catlist1==NULL)&&(catlist2!=NULL)&&(catlist3==NULL)) fillOptPer3(NormOrTest, 16, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
		  else if((catlist1==NULL)&&(catlist2==NULL)&&(catlist3!=NULL)) fillOptPer3(NormOrTest, 17, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
	 	  catlist1=NULL; catlist2=NULL; catlist3=NULL;	// recollect catlist1, catlist2, catlist3;
		  syn12=NULL; syn23=NULL; syn13=NULL;	// recollect syn12, syn23, syn13;
		}
	// 2 rules have categories;
	else if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()!=0)&&(matlexrule3->getCatNum()==0))
		{ catlist1=NULL; catlist2=NULL;
		  syn12=NULL;
		  getpLTMem()->ChkRela2CatPer(type, 1, matlexrule1, matlexrule2, 1, 3, catlist1, catlist2, syn12);
		  if((catlist1!=NULL)&&(catlist2!=NULL))
		  	{ if(syn12!=NULL) fillOptPer3(NormOrTest, 9, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, NULL, syn12, NULL, NULL);	// 2 cats(S+V), 1 syn(12);
		  	  else fillOptPer3(NormOrTest, 10, matlexrule1, matlexrule2, matlexrule3, catlist1, catlist2, NULL, NULL, NULL, NULL);	// 2 cats(S+V), 0 syn;
		  	}
		  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPer3(NormOrTest, 15, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
		  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPer3(NormOrTest, 16, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
		  syn12=NULL;	// recollect syn12;
		}
	else if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()==0)&&(matlexrule3->getCatNum()!=0))
		{ catlist1=NULL; catlist3=NULL;
		  syn13=NULL;
		  getpLTMem()->ChkRela2CatPer(type, 2, matlexrule1, matlexrule3, 1, 4, catlist1, catlist3, syn13);
		  if((catlist1!=NULL)&&(catlist3!=NULL))
		  	{ if(syn13!=NULL) fillOptPer3(NormOrTest, 11, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, catlist3, NULL, NULL, syn13);	// 2 cats(S+O), 1 syn(13);
		  	  else fillOptPer3(NormOrTest, 12, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, catlist3, NULL, NULL, NULL);	// 2 cats(S+O), 0 syn;
		  	}
		  else if((catlist1!=NULL)&&(catlist3==NULL)) fillOptPer3(NormOrTest, 15, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// 1 cat(S), 0 syn;
		  else if((catlist1==NULL)&&(catlist3!=NULL)) fillOptPer3(NormOrTest, 17, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  catlist1=NULL; catlist3=NULL;	// recollect catlist1, catlist3;
		  syn13=NULL;	// recollect syn13;
		}
	else if((matlexrule1->getCatNum()==0)&&(matlexrule2->getCatNum()!=0)&&(matlexrule3->getCatNum()!=0))
		{ catlist2=NULL; catlist3=NULL;
		  syn23=NULL;
		  getpLTMem()->ChkRela2CatPer(type, 3, matlexrule2, matlexrule3, 3, 4, catlist2, catlist3, syn23);
		  if((catlist2!=NULL)&&(catlist3!=NULL))
		  	{ if(syn23!=NULL) fillOptPer3(NormOrTest, 13, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, catlist3, NULL, syn23, NULL);	// 2 cats(V+O), 1 syn(23);
		  	  else fillOptPer3(NormOrTest, 14, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, catlist3, NULL, NULL, NULL);	// 2 cats(V+O), 0 syn;
		  	}
		  else if((catlist2!=NULL)&&(catlist3==NULL)) fillOptPer3(NormOrTest, 16, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
		  else if((catlist2==NULL)&&(catlist3!=NULL)) fillOptPer3(NormOrTest, 17, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  catlist2=NULL; catlist3=NULL;	// recollect catlist2, catlist3;
		  syn23=NULL;	// recollect syn23;
		}
	// 1 rule has categories;
	else if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()==0)&&(matlexrule3->getCatNum()==0))
		{ catlist1=NULL; matlexrule1->FindCatListwithHighAsso(0, 1, catlist1);
		  if(catlist1!=NULL) fillOptPer3(NormOrTest, 15, matlexrule1, matlexrule2, matlexrule3, catlist1, NULL, NULL, NULL, NULL, NULL);	// cat1(S), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;	
		  catlist1=NULL;	// recollect catlist1;
		}
	else if((matlexrule1->getCatNum()==0)&&(matlexrule2->getCatNum()!=0)&&(matlexrule3->getCatNum()==0))
		{ catlist2=NULL; matlexrule2->FindCatListwithHighAsso(0, 3, catlist2);
 		  if(catlist2!=NULL) fillOptPer3(NormOrTest, 16, matlexrule1, matlexrule2, matlexrule3, NULL, catlist2, NULL, NULL, NULL, NULL);	// 1 cat(V), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;	
		  catlist2=NULL;	// recollect catlist2;
		}
	else if((matlexrule1->getCatNum()==0)&&(matlexrule2->getCatNum()==0)&&(matlexrule3->getCatNum()!=0))
		{ catlist3=NULL; matlexrule3->FindCatListwithHighAsso(0, 4, catlist3);
		  if(catlist3!=NULL) fillOptPer3(NormOrTest, 17, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, catlist3, NULL, NULL, NULL);	// 1 cat(O), 0 syn;
		  else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  catlist3=NULL;	// recollect catlist3;
		}
	else fillOptPer3(NormOrTest, 18, matlexrule1, matlexrule2, matlexrule3, NULL, NULL, NULL, NULL, NULL, NULL);	// 0 cat, 0 syn;
	
	// build up CandMeanUtter;
	meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
	bltMeanUtter(meanuttertemp, 2, 0, matlexrule1, matlexrule2, matlexrule3);	// build up meanutter using 2 SV word rules;
	updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
	meanuttertemp=NULL;	// recollect meanuttertemp;	
}
					  			  
void CAgent::BldCombPerSVOwordphra(int NormOrTest, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule, CLexRule *matphrarule)
{ // check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
  // type=9(S+VO/OV); 10(VO/OV+S); 11(V(S)O or O(S)V); 12(V+SO/OS); 13(SO/OS+V); 14(S(V)O or O(V)S); 15(O+SV/VS); 16(SV/VS+O); 17(S(O)V or V(O)S);
  	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3)); assert((9<=type)&&(type<=17)); assert((matlexrule!=NULL)&&(matphrarule!=NULL));
	int i, j, m;
	CMeanUtter *meanuttertemp=NULL;
	CatList *wordcatlist=NULL, *phrasecatlist=NULL;
	CSynRule *syn12=NULL;
	double lexstr, synstr, combwei;
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;
	
	if((matlexrule->getCatNum()!=0)&&(matphrarule->getCatNum()!=0)) 
		{ relaCatListSyn=NULL; numRelaCatListSyn=0;
		  switch(type)
			{ case 9: case 10: case 11: // S+VO/OV(9), VO/OV+S(10), V(S)O or O(S)V(11);
					for(i=0;i<matlexrule->getCatNum();i++)
		  				{ if(matlexrule->getpCatList(i)->getThemRole()==1)
					 	 	{ // matlexrule1's catgeory is Ag;
					 	 	  for(j=0;j<matphrarule->getCatNum();j++)
					  		  	for(m=0;m<getpLTMem()->getNumSynRule();m++)
									{ if(getpLTMem()->chkSynCond1(type, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
									  	{ lexstr=_Half*(matlexrule->getLexStr()+matphrarule->getLexStr());
										  synstr=_Half*(matlexrule->getpCatList(i)->getAssoWei()+matphrarule->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr();
										  combwei=lexstr+synstr;
										  getpLTMem()->rec2Cat1Syn(1, 1, combwei, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
										}
								  	}
							}
						}				
					break;
			  case 12: case 13: case 14: // V+SO/OS(12), SO/OS+V(13), S(V)O or O(V)S(14);
					for(i=0;i<matlexrule->getCatNum();i++)
						for(j=0;j<matphrarule->getCatNum();j++)
							{ for(m=0;m<getpLTMem()->getNumSynRule();m++)
								{ if(getpLTMem()->chkSynCond1(type, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
							  	  	{ lexstr=_Half*(matlexrule->getLexStr()+matphrarule->getLexStr());
									  synstr=_Half*(matlexrule->getpCatList(i)->getAssoWei()+matphrarule->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr();
									  combwei=lexstr+synstr;
									  getpLTMem()->rec2Cat1Syn(1, 2, combwei, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
									}
								}
							}
			  		break;
			  case 15: case 16: case 17: // O+SV/VS(15), SV/VS+O(16), S(O)V or V(O)S(17);
					for(i=0;i<matlexrule->getCatNum();i++)
						{ if(matlexrule->getpCatList(i)->getThemRole()==4)
					 	 	{ // matlexrule1's catgeory is Pat;
					 	 	  for(j=0;j<matphrarule->getCatNum();j++)
					  		  	for(m=0;m<getpLTMem()->getNumSynRule();m++)
									{ if(getpLTMem()->chkSynCond1(type, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
									  	{ lexstr=_Half*(matlexrule->getLexStr()+matphrarule->getLexStr());
										  synstr=_Half*(matlexrule->getpCatList(i)->getAssoWei()+matphrarule->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr();
										  combwei=lexstr+synstr;
										  getpLTMem()->rec2Cat1Syn(1, 3, combwei, matlexrule->getpCatList(i), matphrarule->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
										}
								  	}
							}
						}
			  		break;
			  default: break;
			}
		  wordcatlist=NULL; phrasecatlist=NULL;
  		  syn12=NULL;
		  getpLTMem()->FindrelCatListSyn_Rela2Cat(relaCatListSyn, &numRelaCatListSyn, wordcatlist, phrasecatlist, syn12);
		  if(syn12!=NULL) fillOptPer2(NormOrTest, 2, 1, type, matlexrule, matphrarule, wordcatlist, phrasecatlist, syn12);	// 2 cats, 1 syn;
		  else
			{ // use matlexrule1, matlexrule2's categories with highest assowei;
			  wordcatlist=NULL;
			  switch(type)
			  	{ case 9: case 10: case 11: matlexrule->FindCatListwithHighAsso(0, 1, wordcatlist); break;
			  	  case 12: case 13: case 14: matlexrule->FindCatListwithHighAsso(1, -1, wordcatlist); break;
			  	  case 15: case 16: case 17: matlexrule->FindCatListwithHighAsso(0, 4, wordcatlist); break;
			  	  default: break;
			  	}
			  phrasecatlist=NULL; matphrarule->FindCatListwithHighAsso(1, -1, phrasecatlist);
			  if((wordcatlist!=NULL)&&(phrasecatlist!=NULL)) fillOptPer2(NormOrTest, 2, 2, type, matlexrule, matphrarule, wordcatlist, phrasecatlist, NULL);	// 2 cats, 0 syn;
			  else if((wordcatlist!=NULL)&&(phrasecatlist==NULL)) fillOptPer2(NormOrTest, 2, 3, type, matlexrule, matphrarule, wordcatlist, NULL, NULL);	// 1 cat(cat1), 0 syn;
			  else if((wordcatlist==NULL)&&(phrasecatlist!=NULL)) fillOptPer2(NormOrTest, 2, 4, type, matlexrule, matphrarule, NULL, phrasecatlist, NULL);	// 1 cat(cat2), 0 syn;
			  else fillOptPer2(NormOrTest, 2, 5, type, matlexrule, matphrarule, NULL, NULL, NULL);	// 0 cat, 0 syn;
	  		}
		  wordcatlist=NULL; phrasecatlist=NULL;	// recollect wordcatlist, phrasecatlist;
		  syn12=NULL;	// recollect syn12;
		}
	else if((matlexrule->getCatNum()!=0)&&(matphrarule->getCatNum()==0)) 
		{ wordcatlist=NULL; 
		  switch(type)
		  	{ case 9: case 10: case 11: matlexrule->FindCatListwithHighAsso(0, 1, wordcatlist); break;
		  	  case 12: case 13: case 14: matlexrule->FindCatListwithHighAsso(1, -1, wordcatlist); break;
			  case 15: case 16: case 17: matlexrule->FindCatListwithHighAsso(0, 4, wordcatlist); break;
		  	  default: break;
		  	}
		  if(wordcatlist!=NULL) fillOptPer2(NormOrTest, 2, 3, type, matlexrule, matphrarule, wordcatlist, NULL, NULL);	// 1 cat(cat1), 0 syn;			
		  else fillOptPer2(NormOrTest, 2, 5, type, matlexrule, matphrarule, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  wordcatlist=NULL;	// recollect wordcatlist;		
		}
	else if((matlexrule->getCatNum()==0)&&(matphrarule->getCatNum()!=0)) 
		{ phrasecatlist=NULL; matphrarule->FindCatListwithHighAsso(1, -1, phrasecatlist);
		  if(phrasecatlist!=NULL) fillOptPer2(NormOrTest, 2, 4, type, matlexrule, matphrarule, NULL, phrasecatlist, NULL);	// 1 cat(cat2), 0 syn;
		  else fillOptPer2(NormOrTest, 2, 5, type, matlexrule, matphrarule, NULL, NULL, NULL);	// 0 cat, 0 syn;
		  phrasecatlist=NULL;	// recollect phrasecatlist;
		}
	else fillOptPer2(NormOrTest, 2, 5, type, matlexrule, matphrarule, NULL, NULL, NULL);	// 0 cat, 0 syn;

	// build up CandMeanUtter;
	meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
	if((type==9)||(type==10)||(type==11)) bltMeanUtter(meanuttertemp, 3, 1, matlexrule, matphrarule, NULL);	// build up meanutter using Ag + PredPat rules;
	else if((type==12)||(type==13)||(type==14)) bltMeanUtter(meanuttertemp, 3, 2, matlexrule, matphrarule, NULL);	// build up meanutter using Pred2 + AgPat rules;		
	else if((type==15)||(type==16)||(type==17)) bltMeanUtter(meanuttertemp, 3, 3, matlexrule, matphrarule, NULL);	// build up meanutter using Pat + PredPat rules; 			
	updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
	meanuttertemp=NULL;	// recollect meanuttertemp;	
}

// for incomplete SV or SVO meanings;
void CAgent::BldCombPerSV1word(CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule)
{ // check whether certain cue matches 1 SV word rules and build up CombOption;
  // type=0(Ag); 1(Pred1);
  	assert((type==0)||(type==1)); assert(matlexrule!=NULL);
	int cueindex, themrole;
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist=NULL;

	cueindex=-1; themrole=-1;
	if(type==0) 
		{ themrole=1;	// Ag;
		  cueindex=chkCues(3, 1, matlexrule, NULL, NULL);	// 1 SV word rules for "Predicate<Agent>" meaning;
		}
	else if(type==1)
		{ themrole=2;	// Pred1;
		  cueindex=chkCues(3, 2, matlexrule, NULL, NULL);	// 1 SV word rules for "Predicate<Agent>" meaning;
		}

	if(cueindex!=-1) 
		{ // build up OptionComb;
		  if(matlexrule->getCatNum()!=0)
		  	{ // use matlexrule's category with highest assowei;
		  	  catlist=NULL; matlexrule->FindCatListwithHighAsso(0, themrole, catlist);
		  	  if(catlist!=NULL) fillOptPer1(1, 1, cueindex, matlexrule, catlist);	// 1 cat, 0 syn;			  
			  else fillOptPer1(1, 2, cueindex, matlexrule, NULL);	// 0 cat, 0 syn;
			  catlist=NULL;	// recollect catlisttemp;
		  	}
		  else fillOptPer1(1, 2, cueindex, matlexrule, NULL);	// 0 cat, 0 syn;

		  // build up CandMeanUtter;
		  meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
		  meanuttertemp->setpMean(getpCues()->getpCueItem(cueindex)->getpCueMean());
		  updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
		  meanuttertemp=NULL;	// recollect meanuttertemp;
		}
}

void CAgent::BldCombPerSVO2word(CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule1, CLexRule *matlexrule2)
{ // for remaining 2 SVO word rules; check whether certain cue matches it;
  // type=2(SV); 3(VS); 4(SO); 5(OS); 6(VO); 7(OV);
  	assert((2<=type)&&(type<=7)); assert((matlexrule1!=NULL)&&(matlexrule2!=NULL));
	int i, j, m, cueindex;
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist1=NULL, *catlist2=NULL;
	CSynRule *syn12=NULL;
	double lexstr, synstr, combwei;
	int comp2ret;
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;

	cueindex=-1;
	if((type==2)||(type==3)) cueindex=chkCues(6, 1, matlexrule1, matlexrule2, NULL);	// Ag + Pred2: 2 word rules for "Predicate<Agent, Patient>" meaning;
	else if((type==4)||(type==5)) cueindex=chkCues(6, 2, matlexrule1, matlexrule2, NULL);	// Ag + Pat: 2 word rules for "Predicate<Agent, Patient>" meaning;
	else if((type==6)||(type==7)) cueindex=chkCues(6, 3, matlexrule1, matlexrule2, NULL);	// Pred2 + Pat: 2 word rules for "Predicate<Agent, Patient>" meaning;

	if(cueindex!=-1)
		{ // build up OptionComb;
		  if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()!=0)) 
		  	{ relaCatListSyn=NULL; numRelaCatListSyn=0;
  			  switch(type)
				{ case 2: case 3: // SV(2), VS(3);
						for(i=0;i<matlexrule1->getCatNum();i++)
		  					{ if(matlexrule1->getpCatList(i)->getThemRole()==1)
						 	 	{ // matlexrule1's catgeory is Ag;
						 	 	  for(j=0;j<matlexrule2->getCatNum();j++)
						  		  	for(m=0;m<getpLTMem()->getNumSynRule();m++)
										{ if(getpLTMem()->chkSynCond2(type, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
										  	{ lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
											  synstr=0.0;
											  comp2ret=CGenFuncClass::comp2values_big(matlexrule1->getpCatList(i)->getAssoWei(), matlexrule2->getpCatList(j)->getAssoWei());
											  if(comp2ret==1) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule1->getpCatList(i)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
											  else if(comp2ret==2) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule2->getpCatList(j)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
											  combwei=lexstr+synstr;
											  getpLTMem()->rec2Cat1Syn(1, 1, combwei, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
											}
									  	}
								}
							}
						break;
				  case 4: case 5: // SO(4), OS(5);
				  		for(i=0;i<matlexrule1->getCatNum();i++)
		  					{ if(matlexrule1->getpCatList(i)->getThemRole()==1)
						 	 	{ // matlexrule1's catgeory is Ag;
						 	 	   for(j=0;j<matlexrule2->getCatNum();j++)
				  					{ if(matlexrule2->getpCatList(j)->getThemRole()==4)
						 		 		{ // matlexrule2's catgeory is Pat;
						 	  		  	  for(m=0;m<getpLTMem()->getNumSynRule();m++)
											{ if(getpLTMem()->chkSynCond2(type, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
											  	{ lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
												  synstr=0.0;
											  	  comp2ret=CGenFuncClass::comp2values_big(matlexrule1->getpCatList(i)->getAssoWei(), matlexrule2->getpCatList(j)->getAssoWei());
												  if(comp2ret==1) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule1->getpCatList(i)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
												  else if(comp2ret==2) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule2->getpCatList(j)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
												  combwei=lexstr+synstr;
											  	  getpLTMem()->rec2Cat1Syn(1, 3, combwei, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
											  	}
										  	}
										}
									}
				  				}
				  			}
		  				break;
				  case 6: case 7: // VO(6), OV(7);
				  		for(i=0;i<matlexrule1->getCatNum();i++)
		  					for(j=0;j<matlexrule2->getCatNum();j++)
		  						{ if(matlexrule2->getpCatList(j)->getThemRole()==4)
							 	 	{ // matlexrule2's catgeory is Pat;
						 	 	   	  for(m=0;m<getpLTMem()->getNumSynRule();m++)
										{ if(getpLTMem()->chkSynCond2(type, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m))==1)
										  	{ lexstr=_Third*(matlexrule1->getLexStr()+matlexrule2->getLexStr()+getpIMMem()->getNeuLexStr());
											  synstr=0.0;
											  comp2ret=CGenFuncClass::comp2values_big(matlexrule1->getpCatList(i)->getAssoWei(), matlexrule2->getpCatList(j)->getAssoWei());
											  if(comp2ret==1) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule1->getpCatList(i)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
											  else if(comp2ret==2) synstr=_Half*(_Half*(matlexrule1->getpCatList(i)->getAssoWei()+matlexrule2->getpCatList(j)->getAssoWei())*getpLTMem()->getpSynRuleList(m)->getSynStr()+_Half*(matlexrule2->getpCatList(j)->getAssoWei()+getpIMMem()->getNeuAssoWei())*getpIMMem()->getNeuSynStr());
											  combwei=lexstr+synstr;
											  getpLTMem()->rec2Cat1Syn(1, 2, combwei, matlexrule1->getpCatList(i), matlexrule2->getpCatList(j), getpLTMem()->getpSynRuleList(m), relaCatListSyn, &numRelaCatListSyn);
											}
									  	}
									}
								}
		 		 		break;
				  default: break;
				}
  			  catlist1=NULL; catlist2=NULL;
  			  syn12=NULL;
			  getpLTMem()->FindrelCatListSyn_Rela2Cat(relaCatListSyn, &numRelaCatListSyn, catlist1, catlist2, syn12);
  			  if(syn12!=NULL) fillOptPer2(0, 3, 1, type, matlexrule1, matlexrule2, catlist1, catlist2, syn12);	// 2 cats, 1 syn;
			  else
				{ // use matlexrule1, matlexrule2's categories with highest assowei;
				  catlist1=NULL;
				  switch(type)
				  	{ case 2: case 3: case 4: case 5: matlexrule1->FindCatListwithHighAsso(0, 1, catlist1); break;	// SV(2), VS(3), SO(4), OS(5); 
					  case 6: case 7: matlexrule1->FindCatListwithHighAsso(1, -1, catlist1); break;	// VO(6), OV(7); 
					  default: break;
				  	}
				  catlist2=NULL;
				  switch(type)
				  	{ case 4: case 5: case 6: case 7: matlexrule2->FindCatListwithHighAsso(0, 4, catlist2); break;	// SO(4), OS(5), VO(6), OV(7);
					  case 2: case 3: matlexrule2->FindCatListwithHighAsso(1, -1, catlist2); break;	// SV(2), VS(3);
					  default: break;
				  	}
				  if((catlist1!=NULL)&&(catlist2!=NULL)) fillOptPer2(0, 3, 2, type, matlexrule1, matlexrule2, catlist1, catlist2, NULL);	// 2 cats, 0 syn;
				  else if((catlist1!=NULL)&&(catlist2==NULL)) fillOptPer2(0, 3, 3, type, matlexrule1, matlexrule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
				  else if((catlist1==NULL)&&(catlist2!=NULL)) fillOptPer2(0, 3, 4, type, matlexrule1, matlexrule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
				  else fillOptPer2(0, 3, 5, type, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
				  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
				}
			  catlist1=NULL; catlist2=NULL;	// recollect catlist1, catlist2;
		  	  syn12=NULL;	// recollect syntemp12;
			}
		  else if((matlexrule1->getCatNum()!=0)&&(matlexrule2->getCatNum()==0)) 
		  	{ catlist1=NULL;
			  switch(type)
			  	{ case 2: case 3: case 4: case 5: matlexrule1->FindCatListwithHighAsso(0, 1, catlist1); break;	// SV(2), VS(3), SO(4), OS(5); 
				  case 6: case 7: matlexrule1->FindCatListwithHighAsso(1, -1, catlist1); break;	// VO(6), OV(7); 
				  default: break;
			  	}
			  if(catlist1!=NULL) fillOptPer2(0, 3, 3, type, matlexrule1, matlexrule2, catlist1, NULL, NULL);	// 1 cat(cat1), 0 syn;
			  else fillOptPer2(0, 3, 5, type, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
			  catlist1=NULL;	// recollect catlist1;
		  	}	
	 	  else if((matlexrule1->getCatNum()==0)&&(matlexrule2->getCatNum()!=0)) 
	 	  	{ catlist2=NULL;
			  switch(type)
			  	{ case 4: case 5: case 6: case 7: matlexrule2->FindCatListwithHighAsso(0, 4, catlist2); break;	// SO(4), OS(5), VO(6), OV(7);
			  	  case 2: case 3: matlexrule2->FindCatListwithHighAsso(1, -1, catlist2); break;	// SV(2), VS(3);
				  default: break;
			  	}
			  if(catlist2!=NULL) fillOptPer2(0, 3, 4, type, matlexrule1, matlexrule2, NULL, catlist2, NULL);	// 1 cat(cat2), 0 syn;
			  else fillOptPer2(0, 3, 5, type, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
			  catlist2=NULL;	// recollect catlist2;
	 	  	}
		  else fillOptPer2(0, 3, 5, type, matlexrule1, matlexrule2, NULL, NULL, NULL);	// 0 cat, 0 syn;
			
		  // build up CandMeanUtter;
		  meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
		  meanuttertemp->setpMean(getpCues()->getpCueItem(cueindex)->getpCueMean());
		  updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
		  meanuttertemp=NULL;	// recollect meanuttertemp;		  
		}
}
								  
void CAgent::BldCombPerSVO1phra(CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matphrarule)
{ // for remaining 1 phrase rules; check whether certain cue matches it;
  // type=8(AgPred); 9(AgPat); 10(PredPat);
  	assert((8<=type)&&(type<=10)); assert(matphrarule!=NULL);
	int cueindex;
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist=NULL;

	cueindex=-1;
	if(type==8) cueindex=chkCues(7, 1, matphrarule, NULL, NULL);	// AgPred: 1 phrase rule for "Predicate<Agent, Patient>" meaning;
	else if(type==9) cueindex=chkCues(7, 2, matphrarule, NULL, NULL);	// AgPat: 1 phrase rule for "Predicate<Agent, Patient>" meaning;
	else if(type==10) cueindex=chkCues(7, 3, matphrarule, NULL, NULL);	// PredPat: 1 phrase rule for "Predicate<Agent, Patient>" meaning;
	
	if(cueindex!=-1) 
		{ // build up OptionComb;
		  if(matphrarule->getCatNum()!=0)
		  	{ // use matlexrule's category with highest assowei;
		  	  catlist=NULL; matphrarule->FindCatListwithHighAsso(1, -1, catlist);
		  	  if(catlist!=NULL) fillOptPer1(2, 1, cueindex, matphrarule, catlist);	// 1 cat, 0 syn;
			  else fillOptPer1(2, 2, cueindex, matphrarule, NULL);	// 0 cat, 0 syn;
		  	  catlist=NULL;	// recollect catlisttemp;
		  	}
		  else fillOptPer1(2, 2, cueindex, matphrarule, NULL);	// 0 cat, 0 syn;					  	  

		  // build up CandMeanUtter;
		  meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
		  meanuttertemp->setpMean(getpCues()->getpCueItem(cueindex)->getpCueMean());
		  updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
		  meanuttertemp=NULL;	// recollect meanuttertemp;
		}
}

void CAgent::BldCombPerSVO1word(CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int type, CLexRule *matlexrule)
{ // for remaining 1 SVO word rules; check whether certain cue matches it;
  // type=11(Ag); 12(Pred2); 13(Pat);
  	assert((11<=type)&&(type<=13)); assert(matlexrule!=NULL);
	int cueindex, themrole;
	CMeanUtter *meanuttertemp=NULL;
	CatList *catlist=NULL;

	cueindex=-1; themrole=-1;
	if(type==11)
		{ themrole=1;	// Ag;
		  cueindex=chkCues(8, 1, matlexrule, NULL, NULL);	// 1 S word rules for "Predicate<Agent, Patient>" meaning;
		}
	else if(type==12)
		{ themrole=3;	// Pred2;
		  cueindex=chkCues(8, 2, matlexrule, NULL, NULL);	// 1 V word rules for "Predicate<Agent, Patient>" meaning;
		}
	else if(type==13)
		{ themrole=4;	// Pat;
		  cueindex=chkCues(8, 3, matlexrule, NULL, NULL);	// 1 O word rules for "Predicate<Agent, Patient>" meaning;
		}
	
	if(cueindex!=-1) 
		{ // build up OptionComb;
		  if(matlexrule->getCatNum()!=0)
		  	{ // use matlexrule's category with highest assowei;
		  	  catlist=NULL; matlexrule->FindCatListwithHighAsso(0, themrole, catlist);
		  	  if(catlist!=NULL) fillOptPer1(3, 1, cueindex, matlexrule, catlist);	// 1 cat, 0 syn;
			  else fillOptPer1(3, 2, cueindex, matlexrule, NULL);	// 0 cat, 0 syn;
			  catlist=NULL;	// recollect catlisttemp;
		  	}
	  	  else fillOptPer1(3, 2, cueindex, matlexrule, NULL);	// 0 cat, 0 syn;

		  // build up CandMeanUtter;
		  meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
		  meanuttertemp->setpMean(getpCues()->getpCueItem(cueindex)->getpCueMean());
		  updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
		  meanuttertemp=NULL;	// recollect meanuttertemp;		  
		}
}

// for cues only;
void CAgent::BldCombPerCues(CMeanUtter **&CandMeanUtter, int *numCandMeanUtter)
{ // for remaining cues;
	int i, cueindex;
	OptionComb *optiontemp=NULL;
	CMeanUtter *meanuttertemp=NULL;

	for(i=0;i<getpCues()->getNumCue();i++)
		{ if((FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), 0.0))&&(FLOAT_NE(getpCues()->getpCueItem(i)->getCueStr(), -1.0)))
			{ cueindex=i;	
			  // build up OptionComb;
			  optiontemp=new OptionComb; assert(optiontemp!=NULL);

			  // no use meantype, type, subtype;
			  optiontemp->m_nMeanType=-1; optiontemp->m_nType=-1; optiontemp->m_nSubType=-1;
 			  // lexical rule part;
		  	  optiontemp->m_nNumLexRules=0; optiontemp->m_ppLexRules=NULL;		  	  
			  // category part;
			  optiontemp->m_nNumCats=0; optiontemp->m_ppCats=NULL;
			  // syntactic rule part;
			  optiontemp->m_nNumSynRules=0; optiontemp->m_ppSynRules=NULL;
			  // combine strength part;
			  optiontemp->m_dCombinStr=getpCues()->getpCueItem(cueindex)->getCueStr();
			  getpCues()->getpCueItem(cueindex)->setCueStr(-1.0);	// temporary indicate that that cue has been used;

			  getpIMMem()->UpdOptionComb(optiontemp);	// update IMMem->OptionComb;
		  	  optiontemp=NULL;	// recollect optiontemp;

		  	  // build up CandMeanUtter;
			  meanuttertemp=new CMeanUtter; assert(meanuttertemp!=NULL);
			  meanuttertemp->setpMean(getpCues()->getpCueItem(cueindex)->getpCueMean());
			  updCandMeanUtter(meanuttertemp, CandMeanUtter, numCandMeanUtter);	// update CandMeanUtter;
			  meanuttertemp=NULL;	// recollect meanuttertemp;
			}
		}
}

void CAgent::SetCombMat(int NormOrTest, MatLexRule **&MatchLexRule, int *numMatchLexRule, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter, int *numHolist, int *numAg, int *numPred1, int *numPred2, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // select combinable rules from matched rules, and record related lexical rules/categories/syntactic rules into IMMem;
  // NormOrTest=0, normal communication; 1, testing UR; 2, testing Disp; 3, in vertical transmission; same as 1;	
	assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3));
  	int i, j, k, m, n, p;
	int lenSemItem=getpSemSpace()->getLengthSemItem();
	int posAg=getpSemSpace()->getLengthSemRole();
  	int posPat=2*(getpSemSpace()->getLengthSem())+getpSemSpace()->getLengthSemRole();
	
  	// check complete rules; when certain rule is chosen, set MatchLexRule[i]->m_nTag=1;
	// 1) holistic rules;
	for(i=0;i<*numHolist;i++)
		BldCombPerHolist(NormOrTest, CandMeanUtter, numCandMeanUtter, MatchLexRule[i]->m_pMatLexRule);	// check whether certain cue matches it and build up CombOption;

	// 2) 2 word rules for "Predicate<Agent>" meanings;
	for(i=*numHolist;i<*numHolist+*numAg;i++)
		for(j=*numHolist+*numAg;j<*numHolist+*numAg+*numPred1;j++)
			{ // check if they can combine; and then, check if certain cue matches it;
			  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
			  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
			  		{ // check whether it is SV(1) or VS(2) matches; 
			  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			{ // SV(1);
			  			  BldCombPerSV2word(NormOrTest, CandMeanUtter, numCandMeanUtter, 1, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 2 SV word rules and build up CombOption;
						  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
			  			}
			  		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  		  	{ // VS(2);
						  BldCombPerSV2word(NormOrTest, CandMeanUtter, numCandMeanUtter, 2, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 2 SV word rules and build up CombOption;
						  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
			  		  	}
			  		}		  
			}
	
	// 3) 3 word rules for "Predicate<Agent, Patient>" meanings;
	for(i=*numHolist;i<*numHolist+*numAg;i++)
		for(j=*numHolist+*numAg+*numPred1;j<*numHolist+*numAg+*numPred1+*numPred2;j++)
			for(k=*numHolist+*numAg+*numPred1+*numPred2;k<*numHolist+*numAg+*numPred1+*numPred2+*numPat;k++)
				{ if(*(MatchLexRule[i]->m_pMatLexRule->getpMeanUtter()->getpMean())!=*(MatchLexRule[k]->m_pMatLexRule->getpMeanUtter()->getpMean()))
				  	{ // check if they can combine; and then, check if certain cue matches it;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
					  		for(p=0;p<MatchLexRule[k]->m_nMatNum;p++)
					  			{ // check whether it is SVO(3), SOV(4), OSV(5), VSO(6), VOS(7), OVS(8) matches; 
					  			  if((MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])&&(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[k]->m_pMatLocStart[p]))
			  						{ // SVO(3);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 3, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  				}
					  			  else if((MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[k]->m_pMatLocStart[p])&&(MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[j]->m_pMatLocStart[n]))
			  						{ // SOV(4);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 4, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  			  	}
					  			  else if((MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n]))
					  			  	{ // OSV(5);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 5, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  			  	}
					  			  else if((MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[k]->m_pMatLocStart[p]))
					  			  	{ // VSO(6);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 6, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  			  	}
					  			  else if((MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[k]->m_pMatLocStart[p])&&(MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[i]->m_pMatLocStart[m]))
					  			  	{ // VOS(7);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 7, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  			  	}
					  			  else if((MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[j]->m_pMatLocStart[n])&&(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m]))
					  			  	{ // OVS(8);
									  BldCombPerSVO3word(NormOrTest, CandMeanUtter, numCandMeanUtter, 8, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule);	// check whether certain cue matches 3 SVO word rules and build up CombOption;
						  			  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1; MatchLexRule[k]->m_nTag=1;	// for combinable rules, set them as chosen;
					  			  	}
						  		}
					}
				}

	// 4) 1 word + 1 phrase for "Predicate<Agent, Patient>" meanings;
	// Ag + PredPat;
	for(i=*numHolist;i<*numHolist+*numAg;i++)
		for(j=*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat;j<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat+*numPredPat;j++)
			{ for(k=0;k<lenSemItem;k++)
				{ if(MatchLexRule[i]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posAg)!=MatchLexRule[j]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posPat))
					break;
				}
			  if(k!=lenSemItem)
			    	{ // check if they can combine; and then, check if certain cue matches it;
  				  if(MatchLexRule[j]->m_nMatTyp==7)
  				  	{ // continuous PredPat phrase;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
							{ // check whether it is S+VO/OV(9) or VO/OV+S(10) matches;
							  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  				  	{ // S+VO/OV(9);
							  	  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 9, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
							  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  		  			{ // VO/OV+S(10);
								  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 10, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
					  		}
  				  	}
  				  else if(MatchLexRule[j]->m_nMatTyp==10)
  				  	{ // separate PredPat phrase;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
					  		{ // check whether it is V(S)O or O(S)V (11) matches; 
							  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
							  	{ BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 11, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
					  		}
  				  	}
				}
			}
	// Pred2 + AgPat;	
	for(i=*numHolist+*numAg+*numPred1;i<*numHolist+*numAg+*numPred1+*numPred2;i++)
		for(j=*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred;j<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat;j++)
			{ // check if they can combine; and then, check if certain cue matches it;
  			  if(MatchLexRule[j]->m_nMatTyp==6)
  			  	{ // continuous AgPat phrase;
				  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						{ // check whether it is V+SO/OS(12) or SO/OS+V(13) matches;
						  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			  	{ // V+SO/OS(12);
							  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 12, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  	  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
						  	}
						  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  		  		{ // SO/OS+V(13);
							  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 13, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  	  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
						  	}
				  		}
  			  	}
  			  else if(MatchLexRule[j]->m_nMatTyp==9)
  			  	{ // separate AgPat phrase;
				  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						{ // check whether it is S(V)O or O(V)S (14) matches; 
						  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
						 	{ BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 14, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  	  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
						 	}
				  		}
  			  	}
			}
	// Pat + AgPred;	
	for(i=*numHolist+*numAg+*numPred1+*numPred2;i<*numHolist+*numAg+*numPred1+*numPred2+*numPat;i++)
		for(j=*numHolist+*numAg+*numPred1+*numPred2+*numPat;j<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred;j++)
			{ for(k=0;k<lenSemItem;k++)
				{ if(MatchLexRule[i]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posAg)!=MatchLexRule[j]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posAg))
					break;
				}
			  if(k!=lenSemItem)
			  	{ // check if they can combine; and then, check if certain cue matches it;
  				  if(MatchLexRule[j]->m_nMatTyp==5)
  				  	{ // continuous AgPred phrase;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
							{ // check whether it is O+SV/VS(15) or SV/VS+O(16) matches;
							  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			 	 	{ // O+SV/VS(15);
							  	  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 15, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
							  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  		  			{ // SV/VS+O(16);
								  BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 16, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
					  		}
  				  	}
  				  else if(MatchLexRule[j]->m_nMatTyp==8)
  				  	{ // separate AgPred phrase;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
							{ // check whether it is S(O)V or V(O)S (17) matches; 
							  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
							  	{ BldCombPerSVOwordphra(NormOrTest, CandMeanUtter, numCandMeanUtter, 17, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// check whether certain cue matches 1 word + 1 phrase rules and build up CombOption;
						  		  MatchLexRule[i]->m_nTag=1; MatchLexRule[j]->m_nTag=1;	// for combinable rules, set them as chosen;
							  	}
					  		}
  				  	}
				}
			}
	
	// check incomplete rules;
	if((NormOrTest==0)||(NormOrTest==2)||(NormOrTest==3))
		{ // 1) 1 word rule for "Predicate<Agent>" meanings;
		  // Ag;
		  for(i=*numHolist;i<*numHolist+*numAg;i++)
			{ if(MatchLexRule[i]->m_nTag==0) 			
			  	BldCombPerSV1word(CandMeanUtter, numCandMeanUtter, 0, MatchLexRule[i]->m_pMatLexRule);	// for remaining Ag rules; check whether certain cue matches it;
			}
		  // Pred1;
		  for(i=*numHolist+*numAg;i<*numHolist+*numAg+*numPred1;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSV1word(CandMeanUtter, numCandMeanUtter, 1, MatchLexRule[i]->m_pMatLexRule);	// for remaining Pred1 rules; check whether certain cue matches it;
			}

		  // 2) 2 word rules for "Predicate<Agent, Patient>" meanings;
		  // Ag + Pred2;
		  for(i=*numHolist;i<*numHolist+*numAg;i++)
			for(j=*numHolist+*numAg+*numPred1;j<*numHolist+*numAg+*numPred1+*numPred2;j++)
				{ // select rules not chosen for complete combining; 
				  if((MatchLexRule[i]->m_nTag!=1)&&(MatchLexRule[j]->m_nTag!=1))
					{ // check if they can combine; and then, check if certain cue matches it;	
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
			 		 		{ // check whether it is SV(2) or VS(3) matches; 
					  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			 		 			{ // SV(2);
					  			  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 2, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
								  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  					}
			 		 		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			 		 		  	{ // VS(3);
								  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 3, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
								  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  				  	}
			  				}
					}
				}
		  // Ag + Pat;
		  for(i=*numHolist;i<*numHolist+*numAg;i++)
			for(j=*numHolist+*numAg+*numPred1+*numPred2;j<*numHolist+*numAg+*numPred1+*numPred2+*numPat;j++)
				{ // select rules not chosen for complete combining; 
				  if((MatchLexRule[i]->m_nTag!=1)&&(MatchLexRule[j]->m_nTag!=1))
					{ for(k=0;k<lenSemItem;k++)
				  		{ if(MatchLexRule[i]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posAg)!=MatchLexRule[j]->m_pMatLexRule->getpMeanUtter()->getpMean()->getElement(k+posAg))
				  			break;
				  		}
				  	  if(k!=lenSemItem)
					  	{ // check if they can combine; and then, check if certain cue matches it;	
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
			 		 			{ // check whether it is SO(4) or OS(5) matches; 
					  			  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			 		 				{ // SO(4);
					  				  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 4, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
									  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  						}
			 		 			  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			 		 			  	{ // OS(5);
									  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 5, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
									  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  					  	}
			  					}
						}
					}			  
				}
		  // Pred2 + Pat;
		  for(i=*numHolist+*numAg+*numPred1;i<*numHolist+*numAg+*numPred1+*numPred2;i++)
			for(j=*numHolist+*numAg+*numPred1+*numPred2;j<*numHolist+*numAg+*numPred1+*numPred2+*numPat;j++)
				{ // select rules not chosen for complete combining; 
				  if((MatchLexRule[i]->m_nTag!=1)&&(MatchLexRule[j]->m_nTag!=1))
					{ // check if they can combine; and then, check if certain cue matches it;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
			 		 		{ // check whether it is VO(6) or OV(7) matches; 
					  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			 		 			{ // VO(6);
					  			  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 6, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
								  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  					}
			 		 		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			 		 		  	{ // OV(7);
								  BldCombPerSVO2word(CandMeanUtter, numCandMeanUtter, 7, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule);	// for remaining 2 SVO word rules; check whether certain cue matches it;
								  MatchLexRule[i]->m_nTag=-1; MatchLexRule[j]->m_nTag=-1;	// for combinable rules, temporary set them as chosen;
			  				  	}
			  				}
					}
				}
		  			
		  // 3) 1 phrase rule for "Predicate<Agent, Patient>" meanings;
		  // AgPred;
		  for(i=*numHolist+*numAg+*numPred1+*numPred2+*numPat;i<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1phra(CandMeanUtter, numCandMeanUtter, 8, MatchLexRule[i]->m_pMatLexRule);	// for remaining AgPred phrase rules; check whether certain cue matches it;
		  	}
		  // AgPat;
		  for(i=*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred;i<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1phra(CandMeanUtter, numCandMeanUtter, 9, MatchLexRule[i]->m_pMatLexRule);	// for remaining AgPat phrase rules; check whether certain cue matches it;
		  	}
		  // PredPat;
		  for(i=*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat;i<*numHolist+*numAg+*numPred1+*numPred2+*numPat+*numAgPred+*numAgPat+*numPredPat;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1phra(CandMeanUtter, numCandMeanUtter, 10, MatchLexRule[i]->m_pMatLexRule);	// for remaining PredPat phrase rules; check whether certain cue matches it;
		  	}
			
		  // 4) 1 word rule for "Predicate<Agent, Patient>" meanings;
		  // Ag;
		  for(i=*numHolist;i<*numHolist+*numAg;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1word(CandMeanUtter, numCandMeanUtter, 11, MatchLexRule[i]->m_pMatLexRule);	// for remaining Ag rules; check whether certain cue matches it;
			}
		  // Pred2;
		  for(i=*numHolist+*numAg+*numPred1;i<*numHolist+*numAg+*numPred1+*numPred2;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1word(CandMeanUtter, numCandMeanUtter, 12, MatchLexRule[i]->m_pMatLexRule);	// for remaining Pred2 rules; check whether certain cue matches it;
			}
		  // Pat;
		  for(i=*numHolist+*numAg+*numPred1+*numPred2;i<*numHolist+*numAg+*numPred1+*numPred2+*numPat;i++)
			{ if(MatchLexRule[i]->m_nTag==0)
				BldCombPerSVO1word(CandMeanUtter, numCandMeanUtter, 13, MatchLexRule[i]->m_pMatLexRule);	// for remaining Pat rules; check whether certain cue matches it;
			}

		  // 5) for remaining cues;
		  BldCombPerCues(CandMeanUtter, numCandMeanUtter);	// for remaining cues;			
		}	
}

void CAgent::SelWinSetMean(CMeanUtter *meanutter, CMeanUtter **&CandMeanUtter, int *numCandMeanUtter)
{ // select winning rules and build up meaning from it;
	assert(meanutter->getpUtter()!=NULL); 
	int i, winindex;
	OptionComb *optiontemp=NULL;

	if(getpIMMem()->getNumCombOption()!=0)
		{ // first, copy CandMeanUtter to m_pIMMem->m_ppOptionComb;
		  for(i=0;i<getpIMMem()->getNumCombOption();i++)
			*(getpIMMem()->getpOptionComb(i)->m_pOptMeanUtter)=*(CandMeanUtter[i]);
		  // then, select winning rules;	
		  winindex=SelWinIndex();	// find the winning rules;
		  if((winindex!=-1)&&(winindex!=0))
		  	{ // interchange IMMem()->m_pOptionComb[winindex] with IMMem->m_pOptionComb[0];
		  	  optiontemp=getpIMMem()->getpOptionComb(winindex);
		  	  getpIMMem()->setpOptionComb(winindex, getpIMMem()->getpOptionComb(0));
		  	  getpIMMem()->setpOptionComb(0, optiontemp);
		  	  optiontemp=NULL;	// recollect optiontemp;
		  	}
		  meanutter->setpMean(getpIMMem()->getpOptionComb(0)->m_pOptMeanUtter->getpMean());	// build up meaning using CandMeanUtter[0];
		}
}

void CAgent::Perception(CMeanUtter *meanutter, int *feedback, bool *inBufSuc, int NormOrTest)
{ // percept mean based on meanutter's utter; if failed to comprehend, meanutter->m_pMean[]=-1;
  // NormOrTest=0, normal communication; 1, testing UR; 2, testing Disp; 3, in vertical transmission, listener always get the correct cue;
	assert(meanutter!=NULL); assert(feedback!=NULL); assert((NormOrTest==0)||(NormOrTest==1)||(NormOrTest==2)||(NormOrTest==3));
  	int i;
  	int numHolist, numAg, numPred1, numPred2, numPat, numAgPred, numAgPat, numPredPat;	// number of rules which match the whole or part of the meaning to be expressed;
	MatLexRule **MatchLexRule=NULL;	// pointing to matched lexical rules;
	int numMatchLexRule;	// number of matched lexical rules;
	double winrulestr;	// winning rules combined strength;
	CMeanUtter **CandMeanUtter=NULL;	// record meaning percepted in different conditions;
	int numCandMeanUtter;	// record number of such conditions;

	// 1) copy meanutter's utterance into m_pMeanUtter;
	getpMeanUtter()->EmptypMeanUtter(); getpMeanUtter()->setpUtter(meanutter->getpUtter());
	
	// 2) comprehend meaning for m_pMeanUtter's utterance; 
	// first, select cues;	
	if(NormOrTest==0) { getpCues()->DestCue(); getpCues()->createCue(getpSemSpace(), 0, meanutter->getpMean(), getCueReliabAg()); }	// in normal communication, select cues;
	else if(NormOrTest==2) { getpCues()->DestCue(); getpCues()->createCue(getpSemSpace(), 1, meanutter->getpMean(), getCueReliabAg()); }	// in testing Disp, select a wrong cue;
	else if(NormOrTest==3) { getpCues()->DestCue(); getpCues()->createCue(getpSemSpace(), 2, meanutter->getpMean(), getCueReliabAg()); }	// in vertical transmission, listener always get the correct cue;

	// then, check getpLTMem() for rules to comprehend this utter;	
	getpIMMem()->EmpOptionComb();	// empty IMMem->m_ppOptionComb;

	if(getpIMMem()->getMaxNumCombOption()!=0)
		{ // allow working memory;
		  // initialize MatchLexRule and numMatchLexRule; get the candidate lexical rules which can partially match the heard utterance;
		  MatchLexRule=NULL; numMatchLexRule=0;
		  numHolist=numAg=numPred1=numPred2=numPat=numAgPred=numAgPat=numPredPat=0;
		  getpLTMem()->GetCand(getpSemSpace(), getpMeanUtter(), MatchLexRule, &numMatchLexRule, &numHolist, &numAg, &numPred1, &numPred2, &numPat, &numAgPred, &numAgPat, &numPredPat);

		  // select combinable rules from matched rules, and record related lexical rules/categories/syntactic rules into IMMem;
		  CandMeanUtter=NULL; numCandMeanUtter=0;
		  SetCombMat(NormOrTest, MatchLexRule, &numMatchLexRule, CandMeanUtter, &numCandMeanUtter, &numHolist, &numAg, &numPred1, &numPred2, &numPat, &numAgPred, &numAgPat, &numPredPat);
		  SelWinSetMean(getpMeanUtter(), CandMeanUtter, &numCandMeanUtter);	// select winning rules and build up utterance from it;
	
		  // release MatchLexRule and CandMeanUtter;
		  if(numMatchLexRule!=0) 
			{ // release memory space for MatchLexRule;
			  for(i=0;i<numMatchLexRule;i++)
				{ delete MatchLexRule[i]; MatchLexRule[i]=NULL; }
			  delete [] MatchLexRule; MatchLexRule=NULL;
			} 
	 	  if(numCandMeanUtter!=0) 
			{ // release memory space for CandMeanUtter;
			  for(i=0;i<numCandMeanUtter;i++)
			  	{ delete CandMeanUtter[i]; CandMeanUtter[i]=NULL; }
			  delete [] CandMeanUtter; CandMeanUtter=NULL;
			}

		  // 3) copy m_pMeanUtter->m_pMean to meanutter; 
		  meanutter->setpMean(getpMeanUtter()->getpMean());
		}
	// 4) set up feedback;
	if(getpIMMem()->getNumCombOption()==0) { *feedback=0; *inBufSuc=0; }
	else
		{ // based on winning rules combined strength to set up feedback and store m_pMeanUtter into m_pBuffer;
		  *feedback=0; *inBufSuc=0; winrulestr=getpIMMem()->getpOptionComb(0)->m_dCombinStr;
		  setFeedBack(winrulestr, feedback, inBufSuc, NormOrTest);
		}
	// 5) recollect m_pCues;
	if((NormOrTest==0)||(NormOrTest==2)||(NormOrTest==3)) getpCues()->DestCue();	// in normal communication or testing Disp, recollect m_pCues;
}

void CAgent::getReal_PotOrdTyp(int recLocOrdtype, CMeanUtter *meanutter, int OptionCombInd, int *OrdTyp1, int *OrdTyp2, double *LocSynStr, int size)
{ // test which order agent used to produce/comprehend; 0(SV), 1(VS), 2(SVO), 3(SOV), 4(OSV), 5(VSO), 6(VOS), 7(OVS);
   // recLocOrdtype=0, record local order's number used; 1, record local order's strength;
    assert((recLocOrdtype==0)||(recLocOrdtype==1)); assert(meanutter!=NULL); assert((0<=OptionCombInd)&&(OptionCombInd<getpIMMem()->getNumCombOption()));
	assert(LocSynStr!=NULL);
	int i;
	CCat *cat1=NULL, *cat2=NULL, *cat3=NULL;
	CSynRule *syn1=NULL, *syn2=NULL, *syn3=NULL;
	int synTyp, syn1value, syn2value, syn3value;
	int posPat=2*(getpSemSpace()->getLengthSem())+getpSemSpace()->getLengthSemRole();

	*OrdTyp1=*OrdTyp2=-1;
	for(i=0;i<size;i++)
		LocSynStr[i]=0.0;
	if(meanutter->getpMean()->getElement(posPat)==-1)
		{ // "Predicate<Agent>" meaning;
		  if(getpIMMem()->getpOptionComb(OptionCombInd)->m_nNumSynRules==1)
		  	{ // Ag+Pred1; 
			  cat1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[0]; cat2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[1];
			  syn1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[0];
			  if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))
			  	{ if(syn1->getSynTyp()==0) *OrdTyp1=0;	// SV;
			  	  else if(syn1->getSynTyp()==1) *OrdTyp1=1;	// VS;
			  	}
			  else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
		  	  	{ if(syn1->getSynTyp()==0) *OrdTyp1=1;	// VS;
		  	  	  else if(syn1->getSynTyp()==1) *OrdTyp1=0;	// SV;
			  	}
			  cat1=NULL; cat2=NULL;	// recollect cat1, cat2; 
			  syn1=NULL;	// recollect syn1;
		  	}
		}
	else
		{ // "Predicate<Agent, Patient>" meaning;
		  if(getpIMMem()->getpOptionComb(OptionCombInd)->m_nNumSynRules==1)
		  	{ // only consider Ag+PredPat, Pred2+AgPat or Pat+AgPred;
			  cat1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[0]; cat2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[1];
			  syn1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[0];
			  switch(cat1->getThemRole())
			  	{ case 1: // Ag rule; 
			  			// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 6: // PredPat;
			  						// Ag+PredPat;
				  	  				if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))
				  	  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=2; *OrdTyp2=3; }	// either SVO or SOV;
				  	  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=6; *OrdTyp2=7; }	// either VOS or OVS;
					  	  				  else if(syn1->getSynTyp()==2) { *OrdTyp1=4; *OrdTyp2=5; }	// either OSV or VSO;
					  					}
				  	  				else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
				  	  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=6; *OrdTyp2=7; }	// either VOS or OVS;
				  	  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=2; *OrdTyp2=3; }	// either SVO or SOV;
				  	  	  				  else if(syn1->getSynTyp()==3) { *OrdTyp1=4; *OrdTyp2=5; }	// either OSV or VSO;
				  	  					}
									break;
							  default: break;		
			  				}
						break;
				  case 2: // Pred rule;
						// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 5: // AgPat;
			  						// Pred+AgPat;
									if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))
				  						{ if(syn1->getSynTyp()==0) { *OrdTyp1=5; *OrdTyp2=6; }	// either VSO or VOS;
				  	  					  else if(syn1->getSynTyp()==1) { *OrdTyp1=3; *OrdTyp2=4; }	// either SOV or OSV;
					  					  else if(syn1->getSynTyp()==2) { *OrdTyp1=2; *OrdTyp2=7; }	// either SVO or OVS; 
										}
				  				 	else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
				  						{ if(syn1->getSynTyp()==0) { *OrdTyp1=3; *OrdTyp2=4; }	// either SOV or OSV; 
				  	  					  else if(syn1->getSynTyp()==1) { *OrdTyp1=5; *OrdTyp2=6; }	// either VSO or VOS;
				  	  					  else if(syn1->getSynTyp()==3) { *OrdTyp1=2; *OrdTyp2=7; }	// either SVO or OVS;
				  						}
									break;
							  default: break;
							}
				  		break;
				  case 3: // Pat rule;
						// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 4: // AgPred;
			  						// Pat+AgPred;
									if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))	
					  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=4; *OrdTyp2=7; }	// either OSV or OVS; 
					  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=2; *OrdTyp2=5; }	// either SVO or VSO; 
					  	  				  else if(syn1->getSynTyp()==2) { *OrdTyp1=3; *OrdTyp2=6; }	// either SOV or VOS; 
					  					}
					  				else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
					  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=2; *OrdTyp2=5; }	// either SVO or VSO; 
					  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=4; *OrdTyp2=7; }	// either OSV or OVS; 
					  	  				  else if(syn1->getSynTyp()==3) { *OrdTyp1=3; *OrdTyp2=6; }	// either SOV or VOS;  
					  					}
									break;
							  default: break;
							}
				  		break;
				  case 4: // AgPred;
						// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 3: // Pat;
			  						// AgPred+Pat;
									if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))	
					  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=2; *OrdTyp2=5; }	// either SVO or VSO; 
					  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=4; *OrdTyp2=7; }	// either OSV or OVS; 
					  	  				  else if(syn1->getSynTyp()==3) { *OrdTyp1=3; *OrdTyp2=6; }	// either SOV or VOS; 
					  					}
					  				else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
					  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=4; *OrdTyp2=7; }	// either OSV or OVS; 
					  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=2; *OrdTyp2=5; }	// either SVO or VSO; 
					  	  				  else if(syn1->getSynTyp()==2) { *OrdTyp1=3; *OrdTyp2=6; }	// either SOV or VOS;  
					  					}
									break;
							  default: break;
							}
						break;
				  case 5: // AgPat;
						// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 2: // Pred;
			  						// AgPat+Pred;
									if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))
				  						{ if(syn1->getSynTyp()==0) { *OrdTyp1=3; *OrdTyp2=4; }	// either SOV or OSV;
				  	  					  else if(syn1->getSynTyp()==1) { *OrdTyp1=5; *OrdTyp2=6; }	// either VSO or VOS;
					  					  else if(syn1->getSynTyp()==3) { *OrdTyp1=2; *OrdTyp2=7; }	// either SVO or OVS; 
										}
				  				 	else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
				  						{ if(syn1->getSynTyp()==0) { *OrdTyp1=5; *OrdTyp2=6; }	// either VSO or VOS;
				  	  					  else if(syn1->getSynTyp()==1) { *OrdTyp1=3; *OrdTyp2=4; }	// either SOV or OSV; 
				  	  					  else if(syn1->getSynTyp()==2) { *OrdTyp1=2; *OrdTyp2=7; }	// either SVO or OVS;
				  						}
									break;
							  default: break;
							}
						break;
				  case 6: // PredPat;
						// further check cat2;
			  			switch(cat2->getThemRole())
			  				{ case 1: // Ag;
			  						// PredPat+Ag;
									if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))
				  	  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=6; *OrdTyp2=7; }	// either VOS or OVS;
				  	  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=2; *OrdTyp2=3; }	// either SVO or SOV;
					  	  				  else if(syn1->getSynTyp()==3) { *OrdTyp1=4; *OrdTyp2=5; }	// either OSV or VSO;
					  					}
				  	  				else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1))
				  	  					{ if(syn1->getSynTyp()==0) { *OrdTyp1=2; *OrdTyp2=3; }	// either SVO or SOV;
				  	  	  				  else if(syn1->getSynTyp()==1) { *OrdTyp1=6; *OrdTyp2=7; }	// either VOS or OVS;
				  	  	  				  else if(syn1->getSynTyp()==2) { *OrdTyp1=4; *OrdTyp2=5; }	// either OSV or VSO;
				  	  					}
									break;
							  default: break;
							}
						break;
				  default: break;
				}			
			  cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
			  syn1=NULL;	// recollect syn1;
		  	}
		  else if(getpIMMem()->getpOptionComb(OptionCombInd)->m_nNumSynRules==2)
		  	{ // Ag+Pred2+Pat;
			  cat1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[0]; cat2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[1]; cat3=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[2];
		  	  syn1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[0]; syn2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[1];
			  synTyp=getpLTMem()->ChkSynMatCat(syn1, syn2, cat1, cat2, cat3);
			  switch(synTyp)
			  	{ case 1: // syn1: cat1<->cat2; syn2: cat2<->cat3;
						if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat2)&&(syn2->getpCat(1)==cat3))
							{ // normal syn1, normal syn2; 
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+VO, SVO;
							  	  *OrdTyp1=2; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[2])++; } 
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); } 
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+VO, either VSO or VOS;
							  	  *OrdTyp1=5; *OrdTyp2=6;
							  	  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+OV, either SOV or OSV; 
							  	  *OrdTyp1=3; *OrdTyp2=4; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; }
							  	  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+OV, OVS;
							  	  *OrdTyp1=7; 
							  	  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); } 
								}	
							}
						else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat2)&&(syn2->getpCat(1)==cat3))
							{ // reverse syn1, normal syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+VO, either VSO or VOS; 
							  	  *OrdTyp1=5; *OrdTyp2=6;
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+VO, SVO;
							  	  *OrdTyp1=2;
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+OV, OVS;
							  	  *OrdTyp1=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+OV, either SOV or OSV; 
							  	  *OrdTyp1=3; *OrdTyp2=4; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); } 
								}	
							}
						else if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat2))
							{ // normal syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+OV, either SOV or OSV; 
							  	  *OrdTyp1=3; *OrdTyp2=4;
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+OV, OVS;
							  	  *OrdTyp1=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+VO, SVO;
							  	  *OrdTyp1=2; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+VO, either VSO or VOS; 
							  	  *OrdTyp1=5; *OrdTyp2=6; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							}						
						else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat2))
							{ // reverse syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+OV, OVS;
							  	  *OrdTyp1=7;
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+OV, either SOV or OSV; 
							  	  *OrdTyp1=3; *OrdTyp2=4;
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+VO, either VSO or VOS; 
							  	  *OrdTyp1=5; *OrdTyp2=6;
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+VO, SVO;
							  	  *OrdTyp1=2;
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[2])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); }
								}	
							}
						break;
			  	  case 2: // syn1: cat2<->cat3; syn2: cat1<->cat3;
						if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat3)&&(syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))
							{ // normal syn1, normal syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VO+SO, either SVO or VSO;
							  	  *OrdTyp1=2; *OrdTyp2=5;
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // OV+SO, SOV;
							  	  *OrdTyp1=3; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VO+OS, VOS;
							  	  *OrdTyp1=6;
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // OV+OS, either OSV or OVS;
							  	  *OrdTyp1=4; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[5])++; } 
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); } 
								}	
							}
						else if((syn1->getpCat(0)==cat3)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))
							{ // reverse syn1, normal syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // OV+SO, SOV;
							  	  *OrdTyp1=3; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VO+SO, either SVO or VSO;
							  	  *OrdTyp1=2; *OrdTyp2=5; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // OV+OS, either OSV or OVS;
							  	  *OrdTyp1=4; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VO+OS, VOS;
							  	  *OrdTyp1=6; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							}
						else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat3)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat1))
							{ // normal syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VO+OS, VOS;
							  	  *OrdTyp1=6; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // OV+OS, either OSV or OVS;
							  	  *OrdTyp1=4; *OrdTyp2=7;
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VO+SO, either SVO or VSO;
							  	  *OrdTyp1=2; *OrdTyp2=5; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // OV+SO, SOV;
							  	  *OrdTyp1=3; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							}
						else if((syn1->getpCat(0)==cat3)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat1))
							{ // reverse syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // OV+OS, either OSV or OVS;
							  	  *OrdTyp1=4; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VO+OS, VOS;
							  	  *OrdTyp1=6; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // OV+SO, SOV;
							  	  *OrdTyp1=3; 
								  if(recLocOrdtype==0) { (LocSynStr[3])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[3])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VO+SO, either SVO or VSO;
							  	  *OrdTyp1=2; *OrdTyp2=5; 
								  if(recLocOrdtype==0) { (LocSynStr[2])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[2])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							}			  	  		
			  			break;
			  	  case 3: // syn1: cat1<->cat2; syn2: cat1<->cat3;
						if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))
							{ // normal syn1, normal syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+SO, either SVO or SOV;
							  	  *OrdTyp1=2; *OrdTyp2=3; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+SO, VSO;
							  	  *OrdTyp1=5; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+OS, OSV;
							  	  *OrdTyp1=4; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+OS, either VOS or OVS;
							  	  *OrdTyp1=6; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							}
						else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))
							{ // reverse syn1, normal syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+SO, VSO;
							  	  *OrdTyp1=5;
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+SO, either SVO or SOV;
							  	  *OrdTyp1=2; *OrdTyp2=3; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+OS, either VOS or OVS;
							  	  *OrdTyp1=6; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+OS, OSV;
							  	  *OrdTyp1=4; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							}
						else if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat1))
							{ // normal syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+OS, OSV;
							  	  *OrdTyp1=4;
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+OS, either VOS or OVS;
							  	  *OrdTyp1=6; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+SO, either SVO or SOV;
							  	  *OrdTyp1=2; *OrdTyp2=3; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+SO, VSO;
							  	  *OrdTyp1=5; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[4])++; } 
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); } 
								}	
							}
						else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat1))
							{ // reverse syn1, reverse syn2;
							  if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==0)) 
							  	{ // VS+OS, either VOS or OVS;
							  	  *OrdTyp1=6; *OrdTyp2=7; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==0)) 
							  	{ // SV+OS, OSV;
							  	  *OrdTyp1=4; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[5])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[5])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==0)&&(syn2->getSynTyp()==1)) 
							  	{ // VS+SO, VSO;
							  	  *OrdTyp1=5; 
								  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							  else if((syn1->getSynTyp()==1)&&(syn2->getSynTyp()==1)) 
							  	{ // SV+SO, either SVO or SOV;
							  	  *OrdTyp1=2; *OrdTyp2=3; 
								  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[4])++; }
								  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[4])+=syn2->getSynStr(); }
								}	
							}						
			  	  		break;
			  	  default: break;
			  	}
			  cat1=NULL; cat2=NULL; cat3=NULL;	// recollect cat1, cat2, cat3;
			  syn1=NULL; syn2=NULL;	// recollect syn1, syn2;
		  	}
		  else if(getpIMMem()->getpOptionComb(OptionCombInd)->m_nNumSynRules==3)
		  	{ // Ag+Pred2+Pat;
			  cat1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[0]; cat2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[1]; cat3=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppCats[2];
			  syn1=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[0]; syn2=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[1]; syn3=getpIMMem()->getpOptionComb(OptionCombInd)->m_ppSynRules[2];

			  syn1value=syn2value=syn3value=-1;
			  if((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2)) syn1value=syn1->getSynTyp();
			  else if((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat1)) syn1value=!(syn1->getSynTyp());
			  if((syn2->getpCat(0)==cat2)&&(syn2->getpCat(1)==cat3)) syn2value=syn2->getSynTyp();
			  else if((syn2->getpCat(0)==cat3)&&(syn2->getpCat(1)==cat2)) syn2value=!(syn2->getSynTyp());
			  if((syn3->getpCat(0)==cat1)&&(syn3->getpCat(1)==cat3)) syn3value=syn3->getSynTyp();
			  else if((syn3->getpCat(0)==cat3)&&(syn3->getpCat(1)==cat1)) syn3value=!(syn3->getSynTyp());

			  if((syn1value==0)&&(syn2value==0)&&(syn3value==0)) 
			  	{ // SV+VO+SO, SVO;
			  	  *OrdTyp1=2;
				  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[2])++; (LocSynStr[4])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); (LocSynStr[4])+=syn3->getSynStr(); }
				}	
			  else if((syn1value==0)&&(syn2value==1)&&(syn3value==0)) 
			  	{ // SOV;
			  	  *OrdTyp1=3;
				  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; (LocSynStr[4])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); (LocSynStr[4])+=syn3->getSynStr(); }
				}	
			  else if((syn1value==0)&&(syn2value==1)&&(syn3value==1)) 
			  	{ // OSV;
			  	  *OrdTyp1=4;
				  if(recLocOrdtype==0) { (LocSynStr[0])++; (LocSynStr[3])++; (LocSynStr[5])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[0])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); (LocSynStr[5])+=syn3->getSynStr(); }
				}	
			  else if((syn1value==1)&&(syn2value==0)&&(syn3value==0)) 
			  	{ // VSO;
			  	  *OrdTyp1=5; 
				  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; (LocSynStr[4])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); (LocSynStr[4])+=syn3->getSynStr(); }
				}	
			  else if((syn1value==1)&&(syn2value==0)&&(syn3value==1)) 
			  	{ // VOS;
			  	  *OrdTyp1=6; 
				  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[2])++; (LocSynStr[5])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[2])+=syn2->getSynStr(); (LocSynStr[5])+=syn3->getSynStr(); }
				}	
			  else if((syn1value==1)&&(syn2value==1)&&(syn3value==1)) 
			  	{ // OVS;
			  	  *OrdTyp1=7; 
				  if(recLocOrdtype==0) { (LocSynStr[1])++; (LocSynStr[3])++; (LocSynStr[5])++; }
				  else if(recLocOrdtype==1) { (LocSynStr[1])+=syn1->getSynStr(); (LocSynStr[3])+=syn2->getSynStr(); (LocSynStr[5])+=syn3->getSynStr(); }
				}	

			  cat1=NULL; cat2=NULL; cat3=NULL;	// recollect cat1, cat2, cat3;	
			  syn1=NULL; syn2=NULL; syn3=NULL;	// recollect syn1, syn2, syn3;
		  	}
		}
}

// update part;
void CAgent::AdjIMMem(bool SucFail)
{ // adjust IMMem() based on SucFail;
  int i, j, k, m, n;
  bool identical;	// whether this lexical rule/syntactic rule is updated before;
  CLexRule *CurLexRule=NULL; CSynRule *CurSynRule=NULL; CCat *CurCat=NULL;
  bool isCurLexRule, isCurSynRule, isCurCat;

  if(SucFail==1)
  	{ // successful communication; 
  	  // increase rules in IMMem()->m_pOptionComb[0]; 
	  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumLexRules;i++)
	  	{ CurLexRule=getpIMMem()->getpOptionComb(0)->m_ppLexRules[i];
	  	  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
		  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))	
		  	{ // increase assoweight;
		  	  for(j=0;j<CurLexRule->getCatNum();j++)
		  		{ CurCat=CurLexRule->getpCatList(j)->getpCat();
			  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
				  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))	
				  	{ // check if CurCat is in IMMem()->m_ppOptionComb[0];
					  for(k=0;k<getpIMMem()->getpOptionComb(0)->m_nNumCats;k++)
		  				{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[k])
		  	  	  		  	{ CurLexRule->IncAssoWei(j, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiInc()), getAdjMode()); break; }
		  				}
					}
				  CurCat=NULL;	// recollect CurCat;
				}
		  	  CurLexRule->IncLexStr(getChildAdultAbiRatio()*(CurLexRule->getAdjLexRuleStrInc()), getAdjMode());	// increase lexical rules;
		  	}		  			  	
		  CurLexRule=NULL;	// recollect CurLexRule;
		}

	  // increase syntactic rules;
	  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumSynRules;i++)
	  	{ CurSynRule=getpIMMem()->getpOptionComb(0)->m_ppSynRules[i];
	  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
		  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
		  	CurSynRule->IncSynStr(getChildAdultAbiRatio()*(CurSynRule->getAdjSynRuleStrInc()), getAdjMode());
		  CurSynRule=NULL;	// recollect CurSynRule;
	  	}
	  
	  if((getHandleFailedTyp()==0)||(getHandleFailedTyp()==2))
	  	{ // decrease rules in IMMem->m_pOptionComb[i];
	  	  for(i=1;i<getpIMMem()->getNumCombOption();i++)
	 	 	{ for(j=0;j<getpIMMem()->getpOptionComb(i)->m_nNumLexRules;j++)
	  			{ CurLexRule=getpIMMem()->getpOptionComb(i)->m_ppLexRules[j];
		  		  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
				  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))
	  			  	{ // first, check if CurLexRule is in previous IMMem->m_pOptionComb[i]->m_ppLexRules;
				  	  identical=0; 
	  			  	  for(k=0;k<i;k++)
	  			  		for(m=0;m<getpIMMem()->getpOptionComb(k)->m_nNumLexRules;m++)
	  			  			{ if(CurLexRule==getpIMMem()->getpOptionComb(k)->m_ppLexRules[m])
	  			  		  		identical=1;
	  			  			}
	  			  	  if(identical==0)
	  			  		{ // CurLexRule is not in previous IMMem()->m_ppOptionComb[i]->m_ppLexRules;
	  			  		  // updated this rule;
	  			  	  	  // decrease assoweight;
				  	  	  for(k=0;k<CurLexRule->getCatNum();k++)
					  	 	{ CurCat=CurLexRule->getpCatList(k)->getpCat();
						  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
							  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
				  	  	  	  	{ for(m=0;m<getpIMMem()->getpOptionComb(i)->m_nNumCats;m++)
					  				{ if(CurCat==getpIMMem()->getpOptionComb(i)->m_ppCats[m])
					  		  		  	CurLexRule->DecAssoWei(k, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiDec())); 
				  	  	  			}
							  	}
							  CurCat=NULL;	// recollect CurCat;
					  		}
						  CurLexRule->updLexRule(3);	// type=3, m_ppCatList[i]=NULL;
				  	  	  if(CurLexRule->getpMeanUtter()!=NULL) CurLexRule->DecLexStr(getChildAdultAbiRatio()*(CurLexRule->getAdjLexRuleStrDec()));	// decrease lexical rules;					  	  
	  			  	  	}
	  			  	  else if(identical==1)
	  			  	   	{ // CurLexRule is in previous IMMem()->m_ppOptionComb[i]->m_ppLexRules;
	  			  	    	  // only update its used categories;
	  			  	    	  for(k=0;k<CurLexRule->getCatNum();k++)
					  	 	{ CurCat=CurLexRule->getpCatList(k)->getpCat();
							  isCurCat=getpLTMem()->Judge_InCat(CurCat);
							  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
				  	  	  	  	{ for(m=0;m<getpIMMem()->getpOptionComb(i)->m_nNumCats;m++)
					  				{ if(CurCat==getpIMMem()->getpOptionComb(i)->m_ppCats[m])
					  		  		  	{ // check if CurCat is in m_ppOptionComb[0]->m_ppCats;
					  		  		  	  for(n=0;n<getpIMMem()->getpOptionComb(0)->m_nNumCats;n++)
					  		  		  	  	{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[n]) break;
					  		  		  	  	}
					  		  		  	  if(n==getpIMMem()->getpOptionComb(0)->m_nNumCats)
					  		  		  	  	CurLexRule->DecAssoWei(k, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiDec()));					  		  		  	  	
					  		  		  	  break;
					  		  		  	}
					  	  			}
							  	}
							  CurCat=NULL;	// recollect CurCat;
					  		}
				  	  	  CurLexRule->updLexRule(3);	// type=3, m_ppCatList[i]=NULL;
				  	  	}		  	  		  
	  			  	}
		  		  CurLexRule=NULL;	// recollect CurLexRule;
		  		}
			  getpLTMem()->updLTMem();	// update LTMem;

		  	  for(j=0;j<getpIMMem()->getpOptionComb(i)->m_nNumSynRules;j++)
		  	 	{ CurSynRule=getpIMMem()->getpOptionComb(i)->m_ppSynRules[j];
			  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
				  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
		  	 	  	{ // first, check if CurSynRule is in previous IMMem->m_pOptionComb[i]->m_ppSynRules;
					  identical=0;
					  for(k=0;k<i;k++)
					  	for(m=0;m<getpIMMem()->getpOptionComb(k)->m_nNumSynRules;m++)
		  	 	  			{ if(CurSynRule==getpIMMem()->getpOptionComb(k)->m_ppSynRules[m])
		  	 	  		 	 	identical=1;	  	 	  				  
		  	 	  			}
		  	 	  	  if(identical==0)
		  	 	  		{ // CurSynRule is not in previous IMMem->m_ppOptionComb[i]->m_ppSynRules, updated!
		  	 	    	  	  CurSynRule->DecSynStr(getChildAdultAbiRatio()*(CurSynRule->getAdjSynRuleStrDec()));	// decrease syntactic rules;
		  	 	  		}
				  	}
		  	 	  CurSynRule=NULL;	// recollect CurSynRule;
		  	  	}
		  	  getpLTMem()->updLTMem();	// update LTMem;
		  	}
	  	}
	  
	  if(getAvoidLexFlag()==1)
	  	{ // decrease synonymous and homonymous rules;
	  	  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumLexRules;i++)
	  		{ CurLexRule=getpIMMem()->getpOptionComb(0)->m_ppLexRules[i];
		  	  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
		  	  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))
			  	{ // decrease other synonymous and homonymous rules inside same catgeories;
		  		  for(j=0;j<CurLexRule->getCatNum();j++)
		  			{ CurCat=CurLexRule->getpCatList(j)->getpCat();
				  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
					  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
					  	{ // check if CurCat is in IMMem->m_ppOptionComb[0]->m_ppCats;
						  for(k=0;k<getpIMMem()->getpOptionComb(0)->m_nNumCats;k++)
		  					{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[k])
		  			  		  	{ // CurCat is in IMMem->m_ppOptionComb[0]->m_ppCats;
		  			  		  	  getpLTMem()->AvoidSynonym(0, CurLexRule, CurCat, getAdjMode());	// punish other synonymous rules in the same category;
		  			  		  	  getpLTMem()->AvoidHomonym(0, CurLexRule, CurCat, getAdjMode());	// punish other homonymous rules in the same category; 
								  break;
						  		}
		  					}
						}
					  CurCat=NULL;	// recollect CurCat;
					}
				}	  		
			  CurLexRule=NULL;	// recollect CurLexRule;
		  	}
		  getpLTMem()->updLTMem();	// update LTMem;
	  	}
	  if(getAvoidSynFlag()==1)
		{ // punish similar syntactic rules;
		  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumSynRules;i++)
		  	{ CurSynRule=getpIMMem()->getpOptionComb(0)->m_ppSynRules[i];
		  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
			  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
			  	getpLTMem()->AvoidSyn(0, CurSynRule, getAdjMode());	// punish other similar syntactic rules;
			  CurSynRule=NULL;	// recollect CurSynRule;
		  	}
		  getpLTMem()->updLTMem();	// update LTMem;
	  	}
  	}
  else if(SucFail==0)
  	{ // failed communication; 2 cases, 1) no production/perception at all; 2) have production/perception but wrong!
	  if(getpIMMem()->getNumCombOption()!=0)
	  	{ // 2) have perception but wrong! 
	  	  // decrease rules in IMMem->m_pOptionComb[0]; 
	  	  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumLexRules;i++)
	 	 	{ CurLexRule=getpIMMem()->getpOptionComb(0)->m_ppLexRules[i];
		  	  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
			  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))
			  	{ // decrease related categorie's assoweight;
			  	  for(j=0;j<CurLexRule->getCatNum();j++)
			  		{ CurCat=CurLexRule->getpCatList(j)->getpCat();
				  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
					  // first, check if CurCat is in LTMem->m_ppCatList;
					  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
					  	{ for(k=0;k<getpIMMem()->getpOptionComb(0)->m_nNumCats;k++)
			  				{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[k])
			  	  	  		  	CurLexRule->DecAssoWei(j, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiDec()));
							}
					  	}
					  CurCat=NULL;	// recollect CurCat;
			  		}
			  	  CurLexRule->updLexRule(3);	// type=3, m_ppCatList[i]=NULL;
			  	  if(CurLexRule->getpMeanUtter()!=NULL) CurLexRule->DecLexStr(getChildAdultAbiRatio()*(CurLexRule->getAdjLexRuleStrDec()));	// decrease lexical rules;
			  	}  	  
			  CurLexRule=NULL;	// recollect CurLexRule;
		  	}
		  getpLTMem()->updLTMem();	// update LTMem;

		  // decrease syntactic rules;
		  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumSynRules;i++)
		  	{ CurSynRule=getpIMMem()->getpOptionComb(0)->m_ppSynRules[i];
		  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
			  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
			  	CurSynRule->DecSynStr(getChildAdultAbiRatio()*(CurSynRule->getAdjSynRuleStrDec()));
			  CurSynRule=NULL;	// recollect CurSynRule;
		  	}
		  getpLTMem()->updLTMem();	// update LTMem;

		  if(getHandleFailedTyp()==0)
		  	{ // increase rules in IMMem->m_ppOptionComb[i];
		  	  for(i=1;i<getpIMMem()->getNumCombOption();i++)
		 	 	{ for(j=0;j<getpIMMem()->getpOptionComb(i)->m_nNumLexRules;j++)
		  			{ CurLexRule=getpIMMem()->getpOptionComb(i)->m_ppLexRules[j];
			  		  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
					  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))
		  			  	{ // first, check if CurLexRule is in previous IMMem->m_ppOptionComb[i]->m_ppLexRules;
					  	  identical=0;
					  	  for(k=0;k<i;k++)
					  	  	for(m=0;m<getpIMMem()->getpOptionComb(k)->m_nNumLexRules;m++)
		  			  			{ if(CurLexRule==getpIMMem()->getpOptionComb(k)->m_ppLexRules[m])
		  			  			  	identical=1;
		  			  			}
		  			  	  if(identical==0)
		  			  		{ // CurLexRule is not in previous IMMem->getpOptionComb[i]->m_ppLexRules;
		  			  		  // update this rule;
		  			  		  // increase assoweight;
					  		  for(k=0;k<CurLexRule->getCatNum();k++)
								{ CurCat=CurLexRule->getpCatList(k)->getpCat();
							  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
								  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
								 	{ for(m=0;m<getpIMMem()->getpOptionComb(i)->m_nNumCats;m++)
						  				{ if(CurCat==getpIMMem()->getpOptionComb(i)->m_ppCats[m])
											{ CurLexRule->IncAssoWei(k, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiInc()), getAdjMode()); break;
											}
										}
								  	}
								  CurCat=NULL;	// recollect CurCat;
						  		}
					  	  	  CurLexRule->IncLexStr(getChildAdultAbiRatio()*(CurLexRule->getAdjLexRuleStrInc()), getAdjMode());	// increase lexical rules;					  	  	  
		  			  	  	}
		  			  	  else if(identical==1)
		  			  	   	{ // CurLexRule is in IMMem->m_ppOptionComb[0]->m_ppLexRules;
		  			  	    	  // only update its used category;
		  			  	    	  for(k=0;k<CurLexRule->getCatNum();k++)
						  		{ CurCat=CurLexRule->getpCatList(k)->getpCat();
								  isCurCat=getpLTMem()->Judge_InCat(CurCat);
								  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
								  	{ for(m=0;m<getpIMMem()->getpOptionComb(i)->m_nNumCats;m++)
						  				{ if(CurCat==getpIMMem()->getpOptionComb(i)->m_ppCats[m])
								  			{ // check if CurCat is in IMMem->m_ppOptionComb[0]->m_ppCats;
											  for(n=0;n<getpIMMem()->getpOptionComb(0)->m_nNumCats;n++)
											  	{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[n]) break;								  				  		
											  	}
											  if(n==getpIMMem()->getpOptionComb(0)->m_nNumCats)
										 	  	CurLexRule->IncAssoWei(k, getChildAdultAbiRatio()*(CurLexRule->getAdjAssoWeiInc()), getAdjMode());
								  	  	 	  break;
										 	}
										 }
									}
						  	  	  CurCat=NULL;	// recollect CurCat;
						  		}
			  		  	  	}	  		  	  	
			  		  	}
			  		  CurLexRule=NULL;	// recollect CurLexRule;
			  		}
			  	  for(j=0;j<getpIMMem()->getpOptionComb(i)->m_nNumSynRules;j++)
			  	  	{ CurSynRule=getpIMMem()->getpOptionComb(i)->m_ppSynRules[j];
				  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
					  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
			  	  	  	{ // first, check if CurSynRule is in IMMem->m_ppOptionComb[0]->m_ppSynRules;
					  	  identical=0;
					  	  for(k=0;k<i;k++)
					  	  	for(m=0;m<getpIMMem()->getpOptionComb(k)->m_nNumSynRules;m++)
			  	 	  			{ if(CurSynRule==getpIMMem()->getpOptionComb(k)->m_ppSynRules[m]) 
			  	 	  		  		identical=1;
			  	 	  			}
			  	 	  	  if(identical==0)
			  	 	  		{ // CurSynRule is not in IMMem->getpOptionComb[0]->m_ppSynRules, updated!
			  	 	  		  CurSynRule->IncSynStr(getChildAdultAbiRatio()*(CurSynRule->getAdjSynRuleStrInc()), getAdjMode());	// increase syntactic rules;
			  	 	  		}
			  	  		}
			  	  	  CurSynRule=NULL;	// recollect CurSynRule;
			  	  	}
			  	}
		  	}
	  
		  if(getAvoidLexFlag()==1)
		  	{ // 1) decrease synonymous and homonymous rules;
		  	  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumLexRules;i++)
		 	 	{ CurLexRule=getpIMMem()->getpOptionComb(0)->m_ppLexRules[i];
			  	  isCurLexRule=getpLTMem()->Judge_InLex(CurLexRule);
				  if((isCurLexRule==1)&&(CurLexRule!=NULL)&&(CurLexRule->getpMeanUtter()!=NULL))
				  	{ // decrease other synonymous and homonymous rules inside same catgeories;
				  	  for(j=0;j<CurLexRule->getCatNum();j++)
				  		{ CurCat=CurLexRule->getpCatList(j)->getpCat();
					  	  isCurCat=getpLTMem()->Judge_InCat(CurCat);
						  if((isCurCat==1)&&(CurCat!=NULL)&&(CurCat->getThemRole()!=-1))
						  	{ // check if CurCat is in IMMem->m_ppOptionComb[0]->m_ppCats;
							  for(k=0;k<getpIMMem()->getpOptionComb(0)->m_nNumCats;k++)
				  				{ if(CurCat==getpIMMem()->getpOptionComb(0)->m_ppCats[k])
				  	  			  	{ // CurCat is in IMMem->m_ppOptionComb[0]->m_ppCats;
				  	  			  	  getpLTMem()->AvoidSynonym(1, CurLexRule, CurCat, getAdjMode());	// punish other synonymous rules in the same category;
				  	  			  	  getpLTMem()->AvoidHomonym(1, CurLexRule, CurCat, getAdjMode());	// punish other homonymous rules in the same category; 
									  break;
							  		}
				  				}
						  	}
						  CurCat=NULL;	// recollect CurCat;
						}		  		  
				  	}		  	
				  CurLexRule=NULL;	// recollect CurLexRule;
			  	}
			  getpLTMem()->updLTMem();	// update LTMem;
		  	}
		  if(getAvoidSynFlag()==1)
		  	{ // punish similar syntactic rules;
			  for(i=0;i<getpIMMem()->getpOptionComb(0)->m_nNumSynRules;i++)
			  	{ CurSynRule=getpIMMem()->getpOptionComb(0)->m_ppSynRules[i];
			  	  isCurSynRule=getpLTMem()->Judge_InSyn(CurSynRule);
				  if((isCurSynRule==1)&&(CurSynRule!=NULL)&&(CurSynRule->getSynTyp()!=-1))
				  	getpLTMem()->AvoidSyn(1, CurSynRule, getAdjMode());	// punish other similar syntactic rules;
				  CurSynRule=NULL;	// recollect CurSynRule;
			  	}
			  getpLTMem()->updLTMem();	// update LTMem;
		  	}	  	
 	 	}  
  	}
}

void CAgent::UpdIMMem(int feedback)
{ // after one information exchange, based on feedback, update winning/losing lexical rules/categories/syntactic rules; 
	assert((feedback==0)||(feedback==1));
	if(feedback==1) AdjIMMem(1);	// successful communication;
	else if(feedback==0) AdjIMMem(0);	// failed communication;	
	getpIMMem()->EmpOptionComb();	// empty IMMem->m_ppOptionComb;
}

// acquire new rules part;
void CAgent::DecMUinBuf(CandMU **&newCandMU, int numCandMU)
{ // decompose M-U mappings in buffer and store indecomposible M-U mappings as holistic rules into lexical rule list;
	assert((newCandMU!=NULL)&&(numCandMU!=0));
	int i, j;
	int sucInLex;
	CLexRule *remainHolist=NULL;	// indecomposible M-U mapping as a holistic rule;
	CCat *remainHolistCat=NULL;	// holistic rules' category;
	bool *decTag=NULL;	// store whether certain newCandMU's m_pMU is fully decomposible;
	int oldCatThemRole;	// for new created category, keep its themrole in case of inserting new lexical/syntactic rules cause this category to be deleted;
	
	// initialize DecTag;
	decTag=new bool [numCandMU]; assert(decTag!=NULL);
	for(i=0;i<numCandMU;i++)
		decTag[i]=getpLTMem()->testComb(newCandMU[i]);	// test whether newCandMU[i]->m_pMU can be fully decomposed;

	// store indecomposible M-U mappings as holistic rules into lexical rule list;
	// 1) store decTag[i]=0's MU as holistic rule;
	for(i=0;i<numCandMU;i++)
		{ if(decTag[i]==0)
			{ // this MU is not fully decomposable, create remainHolist; 
			  remainHolist=new CLexRule; assert(remainHolist!=NULL);
			  // meanutter part;	
			  remainHolist->setpMeanUtter(newCandMU[i]->m_pMU);
  			  remainHolist->setLexTyp(0);
  			  remainHolist->setLexStr(remainHolist->getInitLexRuleStr());
		 	  // cat part;
  			  // search the LTMem's catlist to find the holistic category's address;
			  for(j=0;j<getpLTMem()->getNumCat();j++)
				{ if(getpLTMem()->getpCatList(j)->getThemRole()==0)
					{ remainHolistCat=getpLTMem()->getpCatList(j); break; }
				}
			  if(j==getpLTMem()->getNumCat())
				{ // no holistic category; create remainHolistCat;
				  remainHolistCat=new CCat; assert(remainHolistCat!=NULL);
				  remainHolistCat->setThemRole(0);	  
				}
			  // link remainHolist with remainHolistCat;
			  remainHolist->InCat(remainHolistCat); 
			  sucInLex=0; remainHolistCat->InLex(remainHolist, &sucInLex);
			  if(sucInLex==1)
			  	{ // insert remainHolist successful;
				  // insert remainHolist and remainHolistCat into LTMem;	
			  	  oldCatThemRole=remainHolistCat->getThemRole();
			  	  getpLTMem()->InLexRule(remainHolist); 

			  	  if(oldCatThemRole==remainHolistCat->getThemRole()) getpLTMem()->InCategory(remainHolistCat);
			  	  else
			 	 	{ // recreate a holistic cat;
					  remainHolistCat=new CCat; assert(remainHolistCat!=NULL);
					  remainHolistCat->setThemRole(0);
					  // link up remainHolist and remainHolistCat;
					  remainHolist->InCat(remainHolistCat); 
					  sucInLex=0; remainHolistCat->InLex(remainHolist, &sucInLex);	// this insertion will always be successful;
					  
					  getpLTMem()->InCategory(remainHolistCat);
				  	}
			  	}
			  else { delete remainHolist; remainHolist=NULL; }	// there is a holistic rule sharing same M-U mapping; delete remainHolist;
			  remainHolist=NULL; remainHolistCat=NULL;	// recollect remainHolist, remainHolistCat;
			}
		}
	// 2) store m_pBuffer->getBuf(i) which is not in newCandMU
	for(i=0;i<getpBuffer()->getCurBufSize();i++)
		{ for(j=0;j<numCandMU;j++)
			{ if((newCandMU[j]->m_pMU!=NULL)&&(decTag[j]==1)&&(*(getpBuffer()->getpBuf(i))==*(newCandMU[j]->m_pMU))) 
				{ // delete this buf;
				  if(getpBuffer()->getRemBuf()==1)
				  	{ getpBuffer()->OutBuffer(i); newCandMU[j]->m_pMU=NULL;	// collect m_pMU;
				  	}
				  break;
				}
			}
		  if(j!=numCandMU) { if(getpBuffer()->getRemBuf()==1) i--; }
		  else if(j==numCandMU)	
			{ // this m_pBuf[i] is not decomposable, create remainHolist; 
			  remainHolist=new CLexRule; assert(remainHolist!=NULL);
			  // meanutter part;
			  remainHolist->setpMeanUtter(getpBuffer()->getpBuf(i));
  			  remainHolist->setLexTyp(0);
  			  remainHolist->setLexStr(remainHolist->getInitLexRuleStr());
		 	  // cat part;
  			  // search the LTMem's catlist to find the holistic category's address;
			  for(j=0;j<getpLTMem()->getNumCat();j++)
				{ if(getpLTMem()->getpCatList(j)->getThemRole()==0)
					{ remainHolistCat=getpLTMem()->getpCatList(j); break; }
				}
			  if(j==getpLTMem()->getNumCat())
				{ // no holistic category;
				  remainHolistCat=new CCat; assert(remainHolistCat!=NULL);
				  remainHolistCat->setThemRole(0);	  
				}	
			  // link remainHolist with remainHolistCat;
			  remainHolist->InCat(remainHolistCat);
			  sucInLex=0; remainHolistCat->InLex(remainHolist, &sucInLex);
			  if(sucInLex==1)
			  	{ // insert remainHolist successful;
				  // insert remainHolist and remainHolistCat into LTMem;	
			  	  oldCatThemRole=remainHolistCat->getThemRole();
			  	  getpLTMem()->InLexRule(remainHolist); 

			  	  if(oldCatThemRole==remainHolistCat->getThemRole()) getpLTMem()->InCategory(remainHolistCat);
			  	  else
			 	 	{ // recreate a holistic cat;
					  remainHolistCat=new CCat; assert(remainHolistCat!=NULL);
					  remainHolistCat->setThemRole(0);
					  // link up remainHolist and remainHolistCat;
					  remainHolist->InCat(remainHolistCat); 
					  sucInLex=0; remainHolistCat->InLex(remainHolist, &sucInLex);	// this insertion will always be successful;
					  
					  getpLTMem()->InCategory(remainHolistCat);
				  	}
			  	}
			  else { delete remainHolist; remainHolist=NULL; }	// there is a holistic rule sharing same M-U mapping; delete remainHolist;
			  remainHolist=NULL; remainHolistCat=NULL;	// recollect remainHolist, remainHolistCat;
			}
		}
	delete [] decTag; decTag=NULL;
}

void CAgent::decMUinHolist()
{ // decompose holistic rule in LTMem;
	int i;
	for(i=0;i<getpLTMem()->getNumLexRule();i++)
		{ if((getpLTMem()->getpLexRuleList(i)->getLexTyp()==0)&&(getpLTMem()->decomHolist(getpLTMem()->getpLexRuleList(i), getpSemSpace())==1))
		  	{ // fully decomposable holistic rule; 
			  getpLTMem()->getpLexRuleList(i)->setLexStr(getpLTMem()->getpLexRuleList(i)->getLexRuleStrLow()); getpLTMem()->getpLexRuleList(i)->updLexRule(1);	// Method 1: direct delete decomposable holistic rule;
			  // getpLTMem()->getpLexRuleList(i)->DecLexStr(getpLTMem()->getNeuLexStr());	// Method 2: greatly decrease decomposable holistic rule's strength;
			}
		}
	getpLTMem()->updLTMem();	// update LTMem;
}

void CAgent::decMUinPhrase()
{ // decompose phrase rule in getpLTMem();
	int i;
	for(i=0;i<getpLTMem()->getNumLexRule();i++)
		{ if((3<=getpLTMem()->getpLexRuleList(i)->getLexTyp())&&(getpLTMem()->getpLexRuleList(i)->getLexTyp()<=8)&&(getpLTMem()->decomPhrase(getpLTMem()->getpLexRuleList(i), getpSemSpace())==1))
			{ // fully decomposable phrase rule;
			  // Method 1: direct delete decomposable holistic rule;	
		  	  getpLTMem()->getpLexRuleList(i)->setLexStr(getpLTMem()->getpLexRuleList(i)->getLexRuleStrLow()); getpLTMem()->getpLexRuleList(i)->updLexRule(1);
			  // Method 2: greatly decrease decomposable holistic rule's strength;
			  // getpLTMem()->getpLexRuleList(i)->DecLexStr(getpLTMem()->getNeuLexStr());
			}
		}
	getpLTMem()->updLTMem();	// update LTMem;
}

void CAgent::DecLex()
{ // decompose holistic and phrase rules;
  	decMUinHolist(); decMUinPhrase();
}

void CAgent::DetRecPat(int type)
{ // detection of recurrent pattern for acquiring new lexical rules; type=1, detect recurrent pattern after every communication; type=2, detect recurrent pattern when the buffer is full;
	assert((type==1)||(type==2));
	int i, numMUpat;
	CMeanUtter **newMUpat=NULL;	// for new M-U mappings;
	
	numMUpat=0; getpLTMem()->DetRecPat(type, getChildAdultAbiRatio(), getDetRecPatRate(), getNoDetRecPatExm(), getpBuffer(), newMUpat, &numMUpat);
	if(numMUpat!=0) 
		{ if(getpLTMem()->getMaxLexRule()!=0) getpLTMem()->InCompLexRule(newMUpat, &numMUpat);
		  // delete newMUpat;
		  for(i=0;i<numMUpat;i++)
		  	{ delete newMUpat[i]; newMUpat[i]=NULL; }
		  delete [] newMUpat; newMUpat=NULL;	
		}	
}

void CAgent::AcqCat()
{ // acquire new categories and syntactic rules;
	int i;
	CandMU **newCandMU=NULL;	// for learning new categories, syntactic rules;
  	int numCandMU;

	numCandMU=0;
  	for(i=0;i<getpBuffer()->getCurBufSize();i++)
  		getpLTMem()->SetCandMU(0, getpSemSpace(), getpBuffer()->getpBuf(i), newCandMU, &numCandMU);	// set up CandMU for each M-U mapping in the buffer;
  	if(numCandMU!=0)
  		{ getpLTMem()->AcqCat(getPredCase(), getChildAdultAbiRatio(), getNoAcqCatSynExm(), getDetLocOrdRate(), newCandMU, numCandMU, getpSemSpace());	// use newCandMU's information to acquire new categories and syntactic rules;
		  DecMUinBuf(newCandMU, numCandMU);	// try decomposing m-u mapping in buffer and store indecomposible M-U mappings as holistic rules into lexical rule list;
		  // delete newCandMU;
		  for(i=0;i<numCandMU;i++)
		  	{ delete newCandMU[i]; newCandMU[i]=NULL; }
		  delete [] newCandMU; newCandMU=NULL;
  		}
}

void CAgent::AcqLexCatSyn(CMeanUtter *MU, int feedback, bool inBufSuc)
{ // after one information exchange, gather information;
	assert(MU!=NULL); assert((feedback==1)||(feedback==0));
	
	if(getHandleBuf()==0)
		{ // always check after each communication;	
		  if((MU->getpMean()->getElement(0)!=-1)&&(feedback==1)&&(inBufSuc==1))
		  	{ // in this communication, listener "successfully" understands something, and insert newMU in the buffer;
		  	  DetRecPat(1);	// first, detect recurrent patterns in M-U mappings in the buffer;
			  AcqCat();	// then, use lexical rules to detect categories and syntax rules in MU mappings in the buffer;
		  	}		  
		}
	else if(getHandleBuf()==1)
		{ // check when the buffer is full;
  		  if(getpBuffer()->getBufTag()==1)
  			{ // after this communication, the buffer is full;
		  	  DetRecPat(2);	// first, detect recurrent patterns in M-U mappings in the buffer;
		  	  AcqCat();	// then, use lexical rules to detect categories and syntax rules in MU mappings in the buffer;  			  
  			  getpBuffer()->DestBuffer();	// finally, delete buffer;
		  	}
  		}
}

// forgetting;
double CAgent::calRatio()
{ // calculate the ratio for forgetting, using linear curve between number of lexical rules and the ratio (01. to 1.0) of forgetting rate;
	if(getpLTMem()->getNumLexRule()==0) return 0.1;
	else return (0.1+(getpLTMem()->getNumLexRule()-1)*(1-0.1)/(double)(getpLTMem()->getMaxLexRule()-1));
}

void CAgent::Forget()
{ // forget lexical rules, catgeories and syntactic rules;
	//double ratio=calRatio();	// forgetting based on the number of current lexical rules;
	double ratio=1.0;	// forgetting disregarded the number of current lexical rules;
	int i, j;
	if(getForget()==1)
		{ // decrease assowei;
		  for(i=0;i<getpLTMem()->getNumLexRule();i++)
			{ if(getpLTMem()->getpLexRuleList(i)->getpMeanUtter()!=NULL)
				{ for(j=0;j<getpLTMem()->getpLexRuleList(i)->getCatNum();j++)
					{ if((getpLTMem()->getpLexRuleList(i)->getpCatList(j)->getpCat()!=NULL)&&(getpLTMem()->getpLexRuleList(i)->getpCatList(j)->getpCat()->getThemRole()!=-1)) 
						getpLTMem()->getpLexRuleList(i)->DecAssoWei(j, ratio*(getpLTMem()->getpLexRuleList(i)->getForgetRateAssoWei()));
					}
				  getpLTMem()->getpLexRuleList(i)->updLexRule(3);
				}
			}
		  getpLTMem()->updLTMem();
		  // decrease lexical rule's strength;
		  for(i=0;i<getpLTMem()->getNumLexRule();i++)
			{ if(getpLTMem()->getpLexRuleList(i)->getpMeanUtter()!=NULL)
				getpLTMem()->getpLexRuleList(i)->DecLexStr(ratio*(getpLTMem()->getpLexRuleList(i)->getForgetRateLexRule()));
			}
		  getpLTMem()->updLTMem();		
		  // decrease syntactic rule's strength;
		  for(i=0;i<getpLTMem()->getNumSynRule();i++)
			{ if(getpLTMem()->getpSynRuleList(i)->getSynTyp()!=-1)
			  	getpLTMem()->getpSynRuleList(i)->DecSynStr(ratio*(getpLTMem()->getpSynRuleList(i)->getForgetRateSynRule()));
			}
		  getpLTMem()->updLTMem();	
	}
}
