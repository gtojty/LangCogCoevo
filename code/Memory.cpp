// Memory.cpp: implement membership functions in CIMMem, CLTMem;

#include "stdafx.h"
// ---- Include Files;
#include"Memory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// MatLexRule's membership functions;
MatLexRule::MatLexRule()
{ // construction function;
	InitMatLexRule();
}

MatLexRule::~MatLexRule()
{ // destruction function;
	DestMatLexRule();
}

void MatLexRule::InitMatLexRule()
{ // initialization function;
	m_pMatLexRule=NULL; m_nTag=0; m_nMatTyp=-1; 
	m_nMatNum=0; m_pMatLocStart=NULL; m_pMatLocEnd=NULL;	
}

void MatLexRule::DestMatLexRule()
{ // destroy function;
	m_pMatLexRule=NULL;	// recollect m_pMatLexRule;
	m_nTag=0;	// 0, not chosen; 1, chosen; -1, temporary chosen;
	m_nMatTyp=-1;	// type of matched lexical rule; -1: default value, 
	if(m_nMatNum!=0)
		{ delete [] m_pMatLocStart; m_pMatLocStart=NULL; 
		  delete [] m_pMatLocEnd; m_pMatLocEnd=NULL;
		  m_nMatNum=0;
		}
}

// MUmatSet's membership functions;
MUmatSet::MUmatSet()
{ // construction function;
	InitMUmatSet();
}

MUmatSet::~MUmatSet()
{ // destruction function;
	DestMUmatSet();
}

void MUmatSet::InitMUmatSet()
{ // initialization function;
	m_nNumLexRule=0; m_ppMatLexRule=NULL;
	m_nNumMatSynTyp=0; m_pMatSynTyp=NULL;
}

void MUmatSet::DestMUmatSet()
{ // destroy function;
	if(m_nNumLexRule!=0)
		{ delete [] m_ppMatLexRule; m_ppMatLexRule=NULL; 
		  m_nNumLexRule=0;
		}	
	if(m_nNumMatSynTyp!=0)
		{ delete [] m_pMatSynTyp; m_pMatSynTyp=NULL;
		  m_nNumMatSynTyp=0;
		}
}

// CandMU's membership functions;
CandMU::CandMU()
{ // construction function;
	InitCandMU();
}

CandMU::~CandMU()
{ // destruction function;
	DestCandMU();
}

void CandMU::InitCandMU()
{ // initialization function;
	m_pMU=NULL; m_bComp=0;
	m_nNumMatSet=0; m_ppMatSet=NULL;
}

void CandMU::DestCandMU()
{ // destroy function;
	int i;
	m_pMU=NULL; m_bComp=0;
	if(m_nNumMatSet!=0)
		{ for(i=0;i<m_nNumMatSet;i++)
			{ delete m_ppMatSet[i]; m_ppMatSet[i]=NULL; }
		  delete [] m_ppMatSet; m_ppMatSet=NULL;
		  m_nNumMatSet=0;
		}	
}

// OptionComb's membership functions;
OptionComb::OptionComb()
{ // construction function;
	InitOptionComb();
}

OptionComb::~OptionComb()
{ // destruction function;
	DestOptionComb();
}

void OptionComb::InitOptionComb()
{ // initialization function;
	m_nMeanType=-1; m_nType=-1; m_dCombinStr=0.0;
	m_nNumLexRules=0; m_ppLexRules=NULL;
	m_nNumCats=0; m_ppCats=NULL;
	m_nNumSynRules=0; m_ppSynRules=NULL;
	m_pOptMeanUtter=new CMeanUtter; assert(m_pOptMeanUtter!=NULL);
	m_pOptMeanUtter->EmptypMeanUtter();
}

void OptionComb::DestOptionComb()
{ // destroy function;
	if(m_nNumLexRules!=0)
		{ delete [] m_ppLexRules; m_ppLexRules=NULL; 
		  m_nNumLexRules=0;
		}	
	if(m_nNumCats!=0)
		{ delete [] m_ppCats; m_ppCats=NULL; 
		  m_nNumCats=0;
		}	
	if(m_nNumSynRules!=0)
		{ delete [] m_ppSynRules; m_ppSynRules=NULL; 
		  m_nNumSynRules=0;
		}	
	m_nMeanType=-1; m_nType=-1; m_nSubType=-1; m_dCombinStr=0.0;
	if(m_pOptMeanUtter!=NULL) { delete m_pOptMeanUtter; m_pOptMeanUtter=NULL; }
}
void OptionComb::setOC_GenInfo(int meantype, int type, int subtype, double combStr)
{ // set up general information;
	assert(((meantype==1)&&(0<=type)&&(type<=3)&&(0<=subtype)&&(subtype<=5))||((meantype==2)&&(0<=type)&&(type<=6)&&(0<=subtype)&&(subtype<=18)));
	m_nMeanType=meantype; m_nType=type; m_nSubType=subtype; m_dCombinStr=combStr;
}

void OptionComb::setOC_LexPart(int numLex, CLexRule * lex1, CLexRule * lex2, CLexRule * lex3)
{ // set up lexical rules;
	assert(((numLex==0)&&(lex1==NULL)&&(lex2==NULL)&&(lex3==NULL))||((numLex==1)&&(lex1!=NULL)&&(lex2==NULL)&&(lex3==NULL))||((numLex==2)&&(lex1!=NULL)&&(lex2!=NULL)&&(lex3==NULL))||((numLex==3)&&(lex1!=NULL)&&(lex2!=NULL)&&(lex3!=NULL)));
	switch(numLex)
		{ case 0: m_nNumLexRules=0; m_ppLexRules=NULL;
				break;
		  case 1: case 2: case 3:
		  		m_nNumLexRules=numLex;
				m_ppLexRules=new CLexRule * [m_nNumLexRules]; assert(m_ppLexRules!=NULL);
				if(m_nNumLexRules==1) m_ppLexRules[0]=lex1;
				else if(m_nNumLexRules==2) { m_ppLexRules[0]=lex1; m_ppLexRules[1]=lex2; }
				else if(m_nNumLexRules==3) { m_ppLexRules[0]=lex1; m_ppLexRules[1]=lex2; m_ppLexRules[2]=lex3; }
		  		break;
		  default: break;
		}		
}

void OptionComb::setOC_CatPart(int numCat, CCat * cat1, CCat * cat2, CCat * cat3)
{ // set up categories;
	assert(((numCat==0)&&(cat1==NULL)&&(cat2==NULL)&&(cat3==NULL))||((numCat==1)&&(cat1!=NULL)&&(cat2==NULL)&&(cat3==NULL))||((numCat==2)&&(cat1!=NULL)&&(cat2!=NULL)&&(cat3==NULL))||((numCat==3)&&(cat1!=NULL)&&(cat2!=NULL)&&(cat3!=NULL)));
	switch(numCat)
		{ case 0: m_nNumCats=0; m_ppCats=NULL;
			 	break;
		  case 1: case 2: case 3:
		  		m_nNumCats=numCat;
				m_ppCats=new CCat * [m_nNumCats]; assert(m_ppCats!=NULL);
				if(m_nNumCats==1) m_ppCats[0]=cat1;
				else if(m_nNumCats==2) { m_ppCats[0]=cat1; m_ppCats[1]=cat2;}
				else if(m_nNumCats==3) { m_ppCats[0]=cat1; m_ppCats[1]=cat2; m_ppCats[2]=cat3; }
		  		break;
		  default: break;
		}
}

void OptionComb::setOC_SynPart(int numSyn, CSynRule * syn1, CSynRule * syn2, CSynRule * syn3)
{ // set up syntactic rules;
	assert(((numSyn==0)&&(syn1==NULL)&&(syn2==NULL)&&(syn3==NULL))||((numSyn==1)&&(syn1!=NULL)&&(syn2==NULL)&&(syn3==NULL))||((numSyn==2)&&(syn1!=NULL)&&(syn2!=NULL)&&(syn3==NULL))||((numSyn==3)&&(syn1!=NULL)&&(syn2!=NULL)&&(syn3!=NULL)));
	switch(numSyn)
		{ case 0: m_nNumSynRules=0; m_ppSynRules=NULL;
				break;
		  case 1: case 2: case 3: 
		  		m_nNumSynRules=numSyn;
				m_ppSynRules=new CSynRule * [m_nNumSynRules]; assert(m_ppSynRules!=NULL);
				if(m_nNumSynRules==1) m_ppSynRules[0]=syn1;
				else if(m_nNumSynRules==2) { m_ppSynRules[0]=syn1; m_ppSynRules[1]=syn2; }
		  		else if(m_nNumSynRules==3) { m_ppSynRules[0]=syn1; m_ppSynRules[1]=syn2; m_ppSynRules[2]=syn3; }
		  		break;
		  default: break;
		}		
}

void OptionComb::RemainLex(int numLex, CLexRule *lex1, CLexRule *lex2, CLexRule *lex3)
{ // remain lexical rules;
	if(m_nNumLexRules!=0)
		{ delete [] m_ppLexRules; m_ppLexRules=NULL; 
		  m_nNumLexRules=0;
		}	
	setOC_LexPart(numLex, lex1, lex2, lex3);
}

void OptionComb::RemainCat(int numCat, CCat *cat1, CCat *cat2, CCat *cat3)
{ // remain category;
	if(m_nNumCats!=0)
		{ delete [] m_ppCats; m_ppCats=NULL; 
		  m_nNumCats=0; 
		}	
	setOC_CatPart(numCat, cat1, cat2, cat3);
}

void OptionComb::RemainSyn(int numSyn, CSynRule *syn1, CSynRule *syn2, CSynRule *syn3)
{ // remain syntactic rules;
	if(m_nNumSynRules!=0)
		{ delete [] m_ppSynRules; m_ppSynRules=NULL; 
		  m_nNumSynRules=0; 
		}	
	setOC_SynPart(numSyn, syn1, syn2, syn3);
}



// CIMMem's membership functions;
CIMMem::CIMMem()
{ // construction function;
	InitIMMem(0, 0);
}

CIMMem::CIMMem(const CIMMem &init)
{ // copy construction function;
	(*this)=init;
}

CIMMem::~CIMMem()
{ // destruction function;
	DestIMMem();
}

CIMMem & CIMMem::operator = (const CIMMem &right)
{ // copy real-time memory;
	int i;
	if(&right!=this)
		{ // it is not a self-copy;
		  DestIMMem(); InitIMMem(right.m_nNumCombOption, right.m_nMaxNumCombOption);
		  setChosWin(right.m_nChosWin);
		  setAdjCombOptionStr(right.m_dAdjCombOptionStr);
		  setNeuLexStr(right.m_dNeuLexStr); setNeuAssoWei(right.m_dNeuAssoWei); setNeuSynStr(right.m_dNeuSynStr);	
		  setMaxNumLexRules(right.m_nMaxNumLexRules); setMaxNumCats(right.m_nMaxNumCats); setMaxNumSynRules(right.m_nMaxNumSynRules);
		  setMaxNumCombOption(right.m_nMaxNumCombOption);
		  if(getNumCombOption()!=0)
		  	{ for(i=0;i<getNumCombOption();i++)
		  		setpOptionComb(i, right.m_ppOptionComb[i]);	// copy by address;
			}
		}
	return *this;
}

void CIMMem::InitIMMem(int numComboption, int maxnumComboption)
{ // initialization function;
	if(overallpara.p_nVarIMMem==0) assert((0<=numComboption)&&(numComboption<=overallpara.p_nMaxNumCombOption));
	else if(overallpara.p_nVarIMMem==1) assert(numComboption>=0);
	int i;
	int varCombOption;
	setChosWin(overallpara.p_nChosWin);
	setAdjCombOptionStr(overallpara.p_dAdjCombOptionStr);
	setNeuLexStr(overallpara.p_dNeuLexStr); setNeuAssoWei(overallpara.p_dNeuAssoWei); setNeuSynStr(overallpara.p_dNeuSynStr);
	setMaxNumLexRules(overallpara.p_nMaxNumLexRules); setMaxNumCats(overallpara.p_nMaxNumCats); setMaxNumSynRules(overallpara.p_nMaxNumSynRules);

	if(overallpara.p_nVarIMMem==0) setMaxNumCombOption(overallpara.p_nMaxNumCombOption);
	else if(overallpara.p_nVarIMMem==1) 
		{ if((numComboption==0)&&(maxnumComboption==0))
			{ // initialization!
		  	  varCombOption=overallpara.p_nMaxNumCombOption+(int)(sqrt((double)(overallpara.p_nMaxNumCombOptionVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1));
		  	  if(varCombOption<=1) varCombOption=1;
		  	  setMaxNumCombOption(varCombOption);
			}
		  else setMaxNumCombOption(maxnumComboption);
		}
	
	m_nNumCombOption=numComboption;
	if(getNumCombOption()==0) m_ppOptionComb=NULL;
	else
		{ m_ppOptionComb=new OptionComb * [getNumCombOption()]; assert(m_ppOptionComb!=NULL);
		  for(i=0;i<getNumCombOption();i++) 
		  	m_ppOptionComb[i]=NULL;
		}
}

void CIMMem::DestIMMem()
{ // destroy function;
	EmpOptionComb(); setMaxNumCombOption(0);
	setChosWin(-1);
	setAdjCombOptionStr(0.0);
	setNeuLexStr(0.0); setNeuAssoWei(0.0); setNeuSynStr(0.0);
	setMaxNumLexRules(0); setMaxNumCats(0); setMaxNumSynRules(0);
}

// other operations;
void CIMMem::UpdOptionComb(OptionComb *&optioncomb)
{ // update optioncomb into OptionComb;
	assert(optioncomb!=NULL);
	int i, m, n, p, optindex;
	OptionComb **NewOptionComb=NULL;
	int numNewOptionComb;
	double smallcombstr;
	bool identical;

	if(getNumCombOption()==0)
		{ // create new OptionComb; 
		  m_nNumCombOption++;
		  m_ppOptionComb=new OptionComb * [getNumCombOption()]; assert(m_ppOptionComb!=NULL);
		  m_ppOptionComb[0]=NULL; setpOptionComb(0, optioncomb);
		}
	else if(getNumCombOption()==getMaxNumCombOption())
		{ // check whether there is a same optioncomb in OptionComb; 
		  identical=0;
		  for(i=0;i<getNumCombOption();i++)
			{ if((getpOptionComb(i)->m_nMeanType==optioncomb->m_nMeanType)&&(getpOptionComb(i)->m_nType==optioncomb->m_nType)&&(getpOptionComb(i)->m_nSubType==optioncomb->m_nSubType)&&(getpOptionComb(i)->m_nNumLexRules==optioncomb->m_nNumLexRules)&&(getpOptionComb(i)->m_nNumCats==optioncomb->m_nNumCats)&&(getpOptionComb(i)->m_nNumSynRules==optioncomb->m_nNumSynRules))
				{ // check lexical rules;
				  for(m=0;m<optioncomb->m_nNumLexRules;m++)
		  			{ if(getpOptionComb(i)->m_ppLexRules[m]!=optioncomb->m_ppLexRules[m]) break;
				  	}
				  // check categories;
				  for(n=0;n<optioncomb->m_nNumCats;n++)
				  	{ if(getpOptionComb(i)->m_ppCats[n]!=optioncomb->m_ppCats[n]) break;
				  	}
				  // check syntactic rules;
				  for(p=0;p<optioncomb->m_nNumSynRules;p++)
				  	{ if(getpOptionComb(i)->m_ppSynRules[p]!=optioncomb->m_ppSynRules[p]) break;
				  	}
				  if((m==optioncomb->m_nNumLexRules)&&(n==optioncomb->m_nNumCats)&&(p==optioncomb->m_nNumSynRules)) identical=1;
		  		}		  	  
			}
		  if(identical==0)
			{ // select a OptionComb having smallest combstr to replace;
		  	  smallcombstr=getpOptionComb(0)->m_dCombinStr;
		  	  for(i=0;i<getNumCombOption();i++)
		 	 	{ if(FLOAT_SM_EQ(getpOptionComb(i)->m_dCombinStr, smallcombstr))
		  			smallcombstr=getpOptionComb(i)->m_dCombinStr;
			  	}
		  	  do{ optindex=(int)(Rand0_1*getNumCombOption());
		  	  }while((optindex==getNumCombOption())||(FLOAT_NE(getpOptionComb(optindex)->m_dCombinStr, smallcombstr)));
		  	  delete m_ppOptionComb[optindex]; m_ppOptionComb[optindex]=NULL;	// delete original m_ppOptionComb[chosecandindex];
		  	  setpOptionComb(optindex, optioncomb);	// replace OptionComb[chosecandindex] with optioncomb;
		  	}
		  else { delete optioncomb; optioncomb=NULL; }
		}
	else
		{ // check whether there is a same optioncomb in OptionComb; 
		  identical=0;
		  for(i=0;i<getNumCombOption();i++)
			{ if((getpOptionComb(i)->m_nMeanType==optioncomb->m_nMeanType)&&(getpOptionComb(i)->m_nType==optioncomb->m_nType)&&(getpOptionComb(i)->m_nSubType==optioncomb->m_nSubType)&&(getpOptionComb(i)->m_nNumLexRules==optioncomb->m_nNumLexRules)&&(getpOptionComb(i)->m_nNumCats==optioncomb->m_nNumCats)&&(getpOptionComb(i)->m_nNumSynRules==optioncomb->m_nNumSynRules))
				{ // check lexical rules;
				  for(m=0;m<optioncomb->m_nNumLexRules;m++)
		  			{ if(getpOptionComb(i)->m_ppLexRules[m]!=optioncomb->m_ppLexRules[m]) break;
				  	}
				  // check categories;
				  for(n=0;n<optioncomb->m_nNumCats;n++)
				  	{ if(getpOptionComb(i)->m_ppCats[n]!=optioncomb->m_ppCats[n]) break;
				  	}
				  // check syntactic rules;
				  for(p=0;p<optioncomb->m_nNumSynRules;p++)
				  	{ if(getpOptionComb(i)->m_ppSynRules[p]!=optioncomb->m_ppSynRules[p]) break;
				  	}
				  if((m==optioncomb->m_nNumLexRules)&&(n==optioncomb->m_nNumCats)&&(p==optioncomb->m_nNumSynRules)) identical=1;
		  		}		  	  
			}
		  if(identical==0)
			{ // create new optioncomb;
			  numNewOptionComb=getNumCombOption()+1;
			  NewOptionComb=new OptionComb * [numNewOptionComb]; assert(NewOptionComb!=NULL);
			  for(i=0;i<numNewOptionComb;i++)
			  	NewOptionComb[i]=NULL;
			  for(i=0;i<numNewOptionComb-1;i++)
			  	NewOptionComb[i]=getpOptionComb(i);
			  NewOptionComb[numNewOptionComb-1]=optioncomb;
			  // delete original OptionComb;
			  delete [] m_ppOptionComb; m_ppOptionComb=NULL;
			  m_nNumCombOption=0;
			  // copy NewOptionComb to OptionComb
			  m_nNumCombOption=numNewOptionComb; m_ppOptionComb=NewOptionComb;
			  NewOptionComb=NULL;	// recollect NewOptionComb;
			}
		  else { delete optioncomb; optioncomb=NULL; }		  	
		}
}

void CIMMem::InHolist(int meantype, CLexRule *newHolist, CCat *newHolistCat, CMeanUtter *meanutter)
{ // insert newHolist, newHolistCat to m_pOptionComb[0];
  // also, adjust already stored rules, let rules, categories and syntactic rules match!	
	assert((newHolist!=NULL)&&(newHolistCat!=NULL));
	// insert newHolist into OptionComb[0];
	getpOptionComb(0)->m_nNumLexRules=1;
	getpOptionComb(0)->m_ppLexRules=new CLexRule * [getpOptionComb(0)->m_nNumLexRules]; assert(getpOptionComb(0)->m_ppLexRules!=NULL);
	getpOptionComb(0)->m_ppLexRules[0]=newHolist;
	// insert newHolistCat into OptionComb[0];
	getpOptionComb(0)->m_nNumCats=1;
	getpOptionComb(0)->m_ppCats=new CCat * [getpOptionComb(0)->m_nNumCats]; assert(getpOptionComb(0)->m_ppCats!=NULL);
	getpOptionComb(0)->m_ppCats[0]=newHolistCat;		
}

void CIMMem::CrtLexRule(CLexRule *&newLexRule, CMeanUtter *meanutter, int LexTyp)
{ // create compositional newLexRule;
	assert(meanutter!=NULL); assert((LexTyp==11)||(LexTyp==13)||((2<=LexTyp)&&(LexTyp<=8)));
	CMeanUtter *newMU=NULL;
	int posAg=meanutter->getLengthSemRole();
	int posPred=meanutter->getLengthSem()+meanutter->getLengthSemRole();
	int posPat=2*(meanutter->getLengthSem())+meanutter->getLengthSemRole();
	int lenSemItem=meanutter->getLengthSemItem();
	int lenPhrase=2*(meanutter->getLengthSem());

	// create newMU;
	newMU=new CMeanUtter; assert(newMU!=NULL);
	switch(LexTyp)
		{ case 2: // Pred1/Pred2 rule;
		  		newMU->setPartMean(meanutter->getpMean(), posPred, posPred, lenSemItem);
		  		newMU->CrtUtter(3);	// word rule's utterance;
		  		break;
		  case 3: case 6: // continuous(3) or seperate(6) AgPred phrase rule;
		  		newMU->setPartMean(meanutter->getpMean(), 0, 0, lenPhrase);
		  		if(LexTyp==3) newMU->CrtUtter(4);	// continuous phrase rule's utterance;
				else if(LexTyp==6) newMU->CrtUtter(5);	// seperate phrase rule's utterance;
		  		break;
		  case 4: case 7: // continuous(4) or seperate(7) AgPat phrase rule;
		  		newMU->setPartMean(meanutter->getpMean(), 0, 0, (int)(_Half*lenPhrase));	// Agent part;
		  		newMU->setPartMean(meanutter->getpMean(), 2*(meanutter->getLengthSem()), 2*(meanutter->getLengthSem()), (int)(_Half*lenPhrase));	// Patient part;
		  		if(LexTyp==4) newMU->CrtUtter(4);	// continuous phrase rule's utterance;
			  	else if(LexTyp==7) newMU->CrtUtter(5);	// seperate phrase rule's utterance;
		  		break;
		  case 5: case 8: // continuous(5) or seperate(8) PredPat phrase rule;
		  		newMU->setPartMean(meanutter->getpMean(), meanutter->getLengthSem(), meanutter->getLengthSem(), lenPhrase);
		  		if(LexTyp==5) newMU->CrtUtter(4);	// continuous phrase rule's utterance;
				else if(LexTyp==8) newMU->CrtUtter(5);	// seperate phrase rule's utterance;
		  		break;
		  case 11: // Ag rule;	
		  		newMU->setPartMean(meanutter->getpMean(), posAg, posAg, lenSemItem);
		  		newMU->CrtUtter(3);	// word rule's utterance;
		  		break;
		  case 13: // Pat rule;
		  		newMU->setPartMean(meanutter->getpMean(), posAg, posPat, lenSemItem);
		  		newMU->CrtUtter(3);	// word rule's utterance;
		  		break;		
		  default: break;		
		}
	// create lexRule;
	newLexRule=new CLexRule; assert(newLexRule!=NULL);
	// meanutter part;
	if((LexTyp==11)||(LexTyp==13)) newLexRule->setLexTyp(1);
  	else newLexRule->setLexTyp(LexTyp);
  	newLexRule->setpMeanUtter(newMU);
	newLexRule->setLexStr(newLexRule->getInitLexRuleStr());
  	delete newMU; newMU=NULL;	// delete newMU;
}

void CIMMem::CrtCat(CCat *&newCat, int themrole, CLexRule *lexRule)
{ // create newCat and link newCat and lexRule;
	int sucInLex;	
	assert((1<=themrole)&&(themrole<=6)); assert(lexRule!=NULL);
	newCat=new CCat; assert(newCat!=NULL);
  	newCat->setThemRole(themrole);
	// link newCat with lexRule;
	sucInLex=0; newCat->InLex(lexRule, &sucInLex);	// this insertion will always be successful; 
	lexRule->InCat(newCat);
}

void CIMMem::CrtSynRule(CSynRule *&newSynRule, CCat *cat1, CCat *cat2, int SynTyp)
{ // create newSynRule;
	assert((0<=SynTyp)&&(SynTyp<=3)); assert((cat1!=NULL)&&(cat2!=NULL));
	newSynRule=new CSynRule; assert(newSynRule!=NULL);
	newSynRule->setSynTyp(SynTyp);
	newSynRule->setSynStr(newSynRule->getInitSynRuleStr());
	// link newSynRule with cat1, cat2;
	newSynRule->setpCat(0, cat1); newSynRule->setpCat(1, cat2);
	cat1->InSyn(newSynRule); cat2->InSyn(newSynRule);
}

void CIMMem::Crt1SynRule_Persp(int perspective, CSynRule *AvaSyn, CCat *AvaSynCat1, CCat *AvaSynCat2, CSynRule *&newSynRule, CCat *cat1, CCat *cat2)
{ // create newSynRule; consider perspective;
	assert((perspective==-1)||(perspective==0)||(perspective==1)); assert((AvaSyn!=NULL)&&(AvaSynCat1!=NULL)&&(AvaSynCat2!=NULL));
	assert((cat1!=NULL)&&(cat2!=NULL));

	switch(perspective)
	  	{ case -1: // no consideration of perspective;
				if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSynRule, cat1, cat2, 0);	// 0: before;
	  	  	 	else CrtSynRule(newSynRule, cat1, cat2, 1);	// 1: before;
	  	  	 	break;
	  	  case 0: // accusative-nominative, agent-perspective; OV orders are difference from SV orders;
	  	  		if(((AvaSynCat1->getThemRole()==1)&&(AvaSynCat2->getThemRole()==2)&&(cat1->getThemRole()==2)&&(cat2->getThemRole()==3))||((AvaSynCat1->getThemRole()==2)&&(AvaSynCat2->getThemRole()==3)&&(cat1->getThemRole()==1)&&(cat2->getThemRole()==2)))
	  	  			{ // the two orders are about SV/VS and VO/OV or VO/OV and SV/OS;
	  	  			  // SV/VS orders are different from VO/OV orders;
					  if((AvaSyn->getpCat(0)==AvaSynCat1)&&(AvaSyn->getpCat(1)==AvaSynCat2)) CrtSynRule(newSynRule, cat1, cat2, !(AvaSyn->getSynTyp()));	// normal order;
					  else if((AvaSyn->getpCat(0)==AvaSynCat2)&&(AvaSyn->getpCat(1)==AvaSynCat1)) CrtSynRule(newSynRule, cat1, cat2, AvaSyn->getSynTyp());	// reverse order;
	  	  			}
				else
					{ // no preference;
					  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSynRule, cat1, cat2, 0);	// 0: before;
	  	  	 		  else CrtSynRule(newSynRule, cat1, cat2, 1);	// 1: before;
					}
	  	  		break;
	  	  case 1: // ergative-absolutive, patient-perspective; OV orders are same as SV orders;
	  	  		if(((AvaSynCat1->getThemRole()==1)&&(AvaSynCat2->getThemRole()==2)&&(cat1->getThemRole()==2)&&(cat2->getThemRole()==3))||((AvaSynCat1->getThemRole()==2)&&(AvaSynCat2->getThemRole()==3)&&(cat1->getThemRole()==1)&&(cat2->getThemRole()==2)))
	  	  			{ // the two orders are about SV/VS and VO/OV or VO/OV and SV/OS;
	  	  			  // SV/VS orders are same as VO/OV orders;
	  	  			  if((AvaSyn->getpCat(0)==AvaSynCat1)&&(AvaSyn->getpCat(1)==AvaSynCat2)) CrtSynRule(newSynRule, cat1, cat2, AvaSyn->getSynTyp());	// normal order;
					  else if((AvaSyn->getpCat(0)==AvaSynCat2)&&(AvaSyn->getpCat(1)==AvaSynCat1)) CrtSynRule(newSynRule, cat1, cat2, !(AvaSyn->getSynTyp()));	// reverse order;	  	  		
	  	  			}
				else
					{ // no preference;
					  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSynRule, cat1, cat2, 0);	// 0: before;
					  else CrtSynRule(newSynRule, cat1, cat2, 1);	// 1: before;
					}
				break;
	  	  default: break;		
	  	}
}

void CIMMem::BuildNewCat(CCat *&newCat, int CatThemRole, int CatListThemRole, CLexRule *WordPhrase)
{ // create newCat and adjust related catlist's themrole of WordPhrase;
	assert(newCat==NULL); assert(WordPhrase!=NULL); assert((0<=CatThemRole)&&(CatThemRole<=6)); assert((0<=CatListThemRole)&&(CatListThemRole<=7));
	assert(CatThemRole+1==CatListThemRole);
	int i;
	double assowei;
	CrtCat(newCat, CatThemRole, WordPhrase);	// create newCat and link with WordPhrase;
	// adjust WordPhrase's CatList->m_nThemRole;
  	for(i=0;i<WordPhrase->getCatNum();i++)
	  	{ if(WordPhrase->getpCatList(i)->getpCat()==newCat)
			{ assowei=WordPhrase->getpCatList(i)->getAssoWei();
			  WordPhrase->setpCatList(i, newCat, assowei, CatListThemRole);
			}
		}
}

void CIMMem::RandCrtWordPhr_InOC(CLexRule *&newWordPhrase, CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1, CMeanUtter *meanutter)
{ // randomly create newWord/newPhrase, newCat1-2, newSyn1 for meanutter->m_pMean;
  // and insert them into m_pOptionComb[0];
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
  	int meantype=getpOptionComb(0)->m_nMeanType; int type=getpOptionComb(0)->m_nType; int subtype=getpOptionComb(0)->m_nSubType; double combwei=getpOptionComb(0)->m_dCombinStr;
  	assert(((meantype==1)&&(type==3))||((meantype==2)&&((type==4)||(type==6))));
	int j;
	CLexRule *avaRule=NULL;
	OptionComb *newOptionComb=NULL;	// new m_pOptionComb[0];
	int posAg=meanutter->getLengthSemRole();
	int posPred=meanutter->getLengthSem()+meanutter->getLengthSemRole();
	int posPat=2*(meanutter->getLengthSem())+meanutter->getLengthSemRole();
	int lenSemItem=meanutter->getLengthSemItem();
	int phrasetype;
	
	if(meantype==1)
		{ // find what word is to be created;
		  avaRule=getpOptionComb(0)->m_ppLexRules[0];
		  if(((avaRule->getpMeanUtter())->getpMean())->getElement(posAg)!=-1)
		  	{ // Ag rule is already there; check newCat1 for Ag; 
			  if(subtype==1) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
			  else if(subtype==2) CrtCat(newCat1, 1, avaRule);	// create newCat1 and link with avaRule;
			
			  // create newWordPhrase for Pred1; create newCat2 and link with newWordPhrase;
		  	  CrtLexRule(newWordPhrase, meanutter, 2);	
			  CrtCat(newCat2, 2, newWordPhrase);
		  	}
		  else
		  	{ // create newWordPhrase for Ag and newCat1; and link newCat1 with newWordPhrase;
		  	  CrtLexRule(newWordPhrase, meanutter, 11);	
			  CrtCat(newCat1, 1, newWordPhrase);
			  
			  // Pred1 rule is already there; check newCat2 for Pred1; 
			  if(subtype==1) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
			  else if(subtype==2) CrtCat(newCat2, 2, avaRule);	// create newCat2 and link with avaRule;
			}
		  // create newSyn1 and link newCat1, newCat2;
		  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  
		  // insert newWordPhrase, newCat1-2, newSyn1 into OptionComb[0];
		  if(((avaRule->getpMeanUtter())->getpMean())->getElement(posAg)!=-1)
		  	{ // avaRule is Ag rule;			  
			  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
			  // create new OptionComb[0];
		  	  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
			  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
			  newOptionComb->setOC_LexPart(2, avaRule, newWordPhrase, NULL);	// lexical rule par;
			  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
			  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
			  m_ppOptionComb[0]=newOptionComb;
			  newOptionComb=NULL;	// recollect newOptionComb;
		  	}
		  else 
		  	{ // avaRule is Pred1 rule;
			  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
			  // create new OptionComb[0];
		  	  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
			  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
			  newOptionComb->setOC_LexPart(2, newWordPhrase, avaRule, NULL);	// lexical rule par;
			  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
			  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
			  m_ppOptionComb[0]=newOptionComb;
			  newOptionComb=NULL;	// recollect newOptionComb;
		  	}
		  
		  avaRule=NULL;	// recollect avaRule;
		}
	else if(meantype==2)
		{ if(type==4)
			{ // find what word is to be created;
			  avaRule=getpOptionComb(0)->m_ppLexRules[0];
			  if(((avaRule->getpMeanUtter())->getpMean())->getElement(posAg)==-1)
			  	{ // create newWordPhrase for Ag; create newCat1 and link with newWordPhrase;
		  	  	  CrtLexRule(newWordPhrase, meanutter, 11);
				  CrtCat(newCat1, 1, newWordPhrase);
			  	  
			  	  // PredPat phrase is already there; check newCat2 for this phrase;
			  	  if(subtype==1) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 for the phrase is already there;
			  	  else if(subtype==2) BuildNewCat(newCat2, 6, 7, avaRule);	// create newCat2 and link with avaRule, and adjust avaRule's CatList->m_nThemRole;
				}
			  else if(((avaRule->getpMeanUtter())->getpMean())->getElement(posPred)==-1)
			  	{ // create newWordPhrase for Pred2; create newCat1 and link with newWordPhrase; 
				  CrtLexRule(newWordPhrase, meanutter, 2);
				  BuildNewCat(newCat1, 2, 3, newWordPhrase);	// and adjust newWordPhrase's CatList->m_nThemRole;

				  // AgPat phrase rule is already there; check newCat2 for this phrase;
				  if(subtype==1) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 for this phrase is already there;
				  else if(subtype==2) BuildNewCat(newCat2, 5, 6, avaRule);	// create newCat2 and link with avaRule, and adjust avaRule's CatList->m_nThemRole;
				}
			  else if(((avaRule->getpMeanUtter())->getpMean())->getElement(posPat)==-1)
			  	{ // create newWordPhrase for Pat; create newCat1 and link with newWordPhrase;
				  CrtLexRule(newWordPhrase, meanutter, 13);
				  BuildNewCat(newCat1, 3, 4, newWordPhrase);	// and adjust newWordPhrase's CatList->m_nThemRole;
				  
				  // AgPred phrase rule is already there; check newCat2 for this phrase;
				  if(subtype==1) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 for this phrase is already there;
				  else if(subtype==2) BuildNewCat(newCat2, 4, 5, avaRule);	// create newCat2 and link with avaRule, and adjust avaRule's CatList->m_nThemRole;
				}
			  // create newSyn1 and link with newCat1, newCat2;
			  // check avaRule's phrase type;
			  phrasetype=avaRule->getLexTyp();
			  if((phrasetype==3)||(phrasetype==4)||(phrasetype==5))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
			  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
			  	}
			  else if((phrasetype==6)||(phrasetype==7)||(phrasetype==8))
			  	CrtSynRule(newSyn1, newCat1, newCat2, 2);	// 2: in between;
			  	
			  // insert newWordPhrase, newCat1-2, newSyn1 into OptionComb[0];
			  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
			  // create new OptionComb[0];
			  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
			  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
			  newOptionComb->setOC_LexPart(2, newWordPhrase, avaRule, NULL);	// lexical rule par;
			  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
			  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
			  m_ppOptionComb[0]=newOptionComb;
			  newOptionComb=NULL;	// recollect newOptionComb;

		  	  avaRule=NULL;	// recollect avaRule;
			}
		  else if(type==6)
		  	{ // find what phrase is to be created;
			  avaRule=getpOptionComb(0)->m_ppLexRules[0];
			  if(((avaRule->getpMeanUtter())->getpMean())->getElement(posAg)!=-1)
			  	{ // further check whether it is Ag or Pat;
				  for(j=0;j<lenSemItem;j++)
				  	{ if(meanutter->getpMean()->getElement(j+posAg)!=avaRule->getpMeanUtter()->getpMean()->getElement(j+posAg))
				  		break;
				  	}
				  if(j==lenSemItem)
				  	{ // Ag rule is already there; check newCat1 for Ag rule;
				  	  if(subtype==1) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
				  	  else if(subtype==2) CrtCat(newCat1, 1, avaRule);	// create newCat1 and link with avaRule;
					
				  	  // create PredPat rule; create newCat2 and link with newWordPhrase;
					  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtLexRule(newWordPhrase, meanutter, 5);	// continuous phrase utterance;
					  else CrtLexRule(newWordPhrase, meanutter, 8);	// separate phrase utterance;
					  BuildNewCat(newCat2, 6, 7, newWordPhrase);	// and adjust newWordPhrase's CatList->m_nThemRole;
					}
				  else
				  	{ // Pat rule is already there; check newCat1 for Pat rule;
				  	  if(subtype==1) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
				  	  else if(subtype==2) BuildNewCat(newCat1, 3, 4, avaRule);	// create newCat1 and link with avaRule, and adjust avaRule's CatList->m_nThemRole;

					  // create AgPred rule; create newCat2 and link with newWordPhrase;
					  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtLexRule(newWordPhrase, meanutter, 3);	// continuous phrase utterance;
 					  else CrtLexRule(newWordPhrase, meanutter, 6);	// separate phrase utterance;
					  BuildNewCat(newCat2, 4, 5, newWordPhrase);	//and adjust newWordPhrase's CatList->m_nThemRole;
 					}
			  	}
			  else if(((avaRule->getpMeanUtter())->getpMean())->getElement(posPred)!=-1)
			  	{ // Pred2 rule is already there; check newCat1 for Pred2 rule;
			  	  if(subtype==1) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
			  	  else if(subtype==2) BuildNewCat(newCat1, 2, 3, avaRule);	// create newCat1 and link with avaRule, and adjust avaRule's CatList->m_nThemRole;

				  // create AgPat rule; create newCat2 and link with newWordPhrase;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtLexRule(newWordPhrase, meanutter, 4);	// continuous phrase utterace;
				  else CrtLexRule(newWordPhrase, meanutter, 7);	// separate phrase utterance;
				  BuildNewCat(newCat2, 5, 6, newWordPhrase);	// and adjust newWordPhrase's CatList->m_nThemRole;
				}
			  // create newSyn1 and link with newCat1, newCat2;
			  // check newWordPhrase's phrase type;
			  phrasetype=newWordPhrase->getLexTyp();
			  if((phrasetype==3)||(phrasetype==4)||(phrasetype==5))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
			  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
			  	}
			  else if((phrasetype==6)||(phrasetype==7)||(phrasetype==8))
			  	CrtSynRule(newSyn1, newCat1, newCat2, 2);	// 2: in between;

			  // insert newWordPhrase, newCat1-2, newSyn1 into OptionComb[0];
			  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
			  // create new OptionComb[0];
			  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
			  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
			  newOptionComb->setOC_LexPart(2, avaRule, newWordPhrase, NULL);	// lexical rule par;
			  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
			  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
			  m_ppOptionComb[0]=newOptionComb;
			  newOptionComb=NULL;	// recollect newOptionComb;

		  	  avaRule=NULL;	// recollect avaRule;
		  	}
		}
}

void CIMMem::RandCrtWord2_InOC(int perspective, CLexRule *&newWord, CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2, CMeanUtter *meanutter)
{ // randomly create newWord/newPhrase, newCat1-3, newSyn1, newSyn2 for meanutter->m_pMean; 
  // and insert them into m_pOptionComb[0];
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=5, 2 word + 1 rand word rules;
  		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
	assert((perspective==-1)||(perspective==0)||(perspective==1));
  	int meantype=getpOptionComb(0)->m_nMeanType; int type=getpOptionComb(0)->m_nType; int subtype=getpOptionComb(0)->m_nSubType; double combwei=getpOptionComb(0)->m_dCombinStr;
  	assert((meantype==2)&&(type==5));
  	int i, j;
  	CLexRule *avaRule1=NULL, *avaRule2=NULL;
	OptionComb *newOptionComb=NULL;	// new m_pOptionComb[0];
	int posAg=meanutter->getLengthSemRole();
	int posPred=meanutter->getLengthSem()+meanutter->getLengthSemRole();
	int cat1Index, cat2Index;
	double assowei1, assowei2;
	double rannum;
	int comp2ret;
	
	// find what word is to be created;
	avaRule1=getpOptionComb(0)->m_ppLexRules[0]; avaRule2=getpOptionComb(0)->m_ppLexRules[1];
	if((((avaRule1->getpMeanUtter())->getpMean())->getElement(posPred)!=-1)&&(((avaRule2->getpMeanUtter())->getpMean())->getElement(posAg)!=-1))
		{ // create Ag rule; create newCat1 and link with newWord;
		  CrtLexRule(newWord, meanutter, 11);
		  CrtCat(newCat1, 1, newWord);
		  
		  // Pred2 rule is already there; check newCat2 for Pred2; 
		  if((subtype==1)||(subtype==2)||(subtype==3)) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
		  else if((subtype==4)||(subtype==5)) BuildNewCat(newCat2, 2, 3, avaRule1);	// create newCat2 and link with avaRule1, and adjust avaRule1's CatList->m_nThemRole;
				  			  
		  // Pat rule is already there; check newCat3 for Pat; 
		  if((subtype==1)||(subtype==2)) newCat3=getpOptionComb(0)->m_ppCats[1];	// newCat3 is already there;
		  else if(subtype==4) newCat3=getpOptionComb(0)->m_ppCats[0];	// newCat3 is already there;
		  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat3, 3, 4, avaRule2);	// create newCat3 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
				  	
		  // create newSyn1, newSyn2;
		  if(subtype==1)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat2==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat3==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
				  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat2, newCat3, newSyn1, newCat1, newCat2);
				  // newSyn2 is already there;
				  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	  	}
			  else if(comp2ret==2)
			  	{ // newSyn1 is already there;
		  	  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	  	}		  	  
		  	}
		  else if(subtype==2)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat2==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat3==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat2, newCat3;
		  	  	  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	  	}
		  	  else if(comp2ret==2)
		  	  	{ // create newSyn1 and link with newCat2, newCat3;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	  	}
		  	}
		  else if(subtype==3)
		  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}
		  else if(subtype==4)
		  	{ // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}
		  else if(subtype==5)
		  	{ // random create newSyn1, newSyn2 with newCat1, newCat2 and newCat3;
			  rannum=Rand0_1;
		  	  if(FLOAT_SM_EQ(rannum, _Third))
		 	   	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	  	}
		  	  else if(FLOAT_SM_EQ(rannum, 2*_Third))
		 	   	{ // create newSyn1 and link with newCat2, newCat3;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	  	}
		  	  else
		  	  	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	  	}			  	  	  	  
		  	}

		  // insert avaRule1, avaRule2, newWord, newCat1-3, newSyn1-2 into OptionComb[0];
		  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(3, newWord, avaRule1, avaRule2);	// lexical rule par;
		  newOptionComb->setOC_CatPart(3, newCat1, newCat2, newCat3);	// category part;
		  newOptionComb->setOC_SynPart(2, newSyn1, newSyn2, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;
		}
	else if((((avaRule1->getpMeanUtter())->getpMean())->getElement(posAg)!=-1)&&(((avaRule2->getpMeanUtter())->getpMean())->getElement(posAg)!=-1))
		{ // Ag rule is already there; check newCat1 for Ag; 
		  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
		  else if((subtype==4)||(subtype==5)) CrtCat(newCat1, 1, avaRule1);	// create newCat1 and link with avaRule1;
		  
		  // create Pred2 rule; create newCat2 and link with newWord;
		  CrtLexRule(newWord, meanutter, 2);
		  BuildNewCat(newCat2, 2, 3, newWord);	// and adjust newWord's CatList->m_nThemRole;
		  
		  // Pat rule is already there; check newCat3 for Pat; 
		  if((subtype==1)||(subtype==2)) newCat3=getpOptionComb(0)->m_ppCats[1];	// newCat3 is already there;
		  else if(subtype==4) newCat3=getpOptionComb(0)->m_ppCats[0];	// newCat3 is already there;
		  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat3, 3, 4, avaRule2);	// create newCat3 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
		  
		  // create newSyn1, newSyn2;
		  if(subtype==1)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat3==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
		  	  	  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat1, newCat2);
				  // newSyn2 is already there;
				  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	  	}
		  	  else if(comp2ret==2)
		  	  	{ // create newSyn1 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat2, newCat3);
		  	  	  // newSyn2 is already there;
		  	  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	  	}
		  	}
		  else if(subtype==2)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat3==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	  	}
		  	  else if(comp2ret==2)
 		  	  	{ // create newSyn1 and link with newCat2, newCat3;
 				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	  	}
		  	}
		  else if((subtype==3))
		  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	}
		  else if(subtype==4)
		  	{ // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
			  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}
		  else if(subtype==5)
		  	{ // random create newSyn1, newSyn2 with newCat1, newCat2 and newCat3;
			  rannum=Rand0_1;
			  if(FLOAT_SM_EQ(rannum, _Third))
	  		  	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
	  		  	  // create newSyn2 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
	  		  	}
	  		  else if(FLOAT_SM_EQ(rannum, 2*_Third))
	  		  	{ // create newSyn1 and link with newCat2, newCat3;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
	  		  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
	  		  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
	  		  	}
	  		  else
		  	  	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	  	}
		  	}

		  // insert avaRule1, avaRule2, newWord, newCat1-3, newSyn1-2 into OptionComb[0];
		  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(3, avaRule1, newWord, avaRule2);	// lexical rule par;
		  newOptionComb->setOC_CatPart(3, newCat1, newCat2, newCat3);	// category part;
		  newOptionComb->setOC_SynPart(2, newSyn1, newSyn2, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;
		}
	else if((((avaRule1->getpMeanUtter())->getpMean())->getElement(posAg)!=-1)&&(((avaRule2->getpMeanUtter())->getpMean())->getElement(posPred)!=-1))
		{ // Ag rule is already there; check newCat1 for Ag; 
		  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
		  else if((subtype==4)||(subtype==5)) CrtCat(newCat1, 1, avaRule1);	// create newCat1 and link with avaRule1;
			  
		  // Pred2 rule is already there; check newCat2 for Pred2; 
		  if((subtype==1)||(subtype==2)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
		  else if(subtype==4) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
		  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat2, 2, 3, avaRule2);	// create newCat2 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
		
		  // create Pat rule; create newCat3 and link with newWord;
		  CrtLexRule(newWord, meanutter, 13);
		  BuildNewCat(newCat3, 3, 4, newWord);	// and adjust newWord's CatList->m_nThemRole;
		  
		  // create newSyn1, newSyn2;
		   if(subtype==1)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // newSyn1 is already there;
				  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
				  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	  	}
		  	  else if(comp2ret==2)
		  	  	{ // newSyn1 is already there;
		  	  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  	  // create newSyn2 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	  	}		  	  
		  	}
		  else if(subtype==2)
		  	{ // decide to create what newSyn1, newSyn2;
		  	  cat1Index=cat2Index=-1;
			  for(i=0;i<avaRule1->getCatNum();i++)
		  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
		  		}
		  	  for(j=0;j<avaRule2->getCatNum();j++)
		  	  	{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
		  	  	}
		  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
			  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
			  if(comp2ret==1)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
			  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
				  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
				}
		  	  else if(comp2ret==2)
		  	  	{ // create newSyn1 and link with newCat1, newCat2;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
			  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	  	}
		  	}
		  else if(subtype==3)
		  	{ // create newSyn1 and link with newCat1, newCat2; 
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
			  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	}
		  else if(subtype==4)
		  	{ // create newSyn1 and link with newCat1, newCat2; 
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}
		  else if(subtype==5)
		  	{ // random create newSyn1, newSyn2 with newCat1, newCat2 and newCat3;
			  rannum=Rand0_1;
		  	  if(FLOAT_SM_EQ(rannum, _Third))
			  	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
			  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
			  	  // create newSyn2 and link with newCat2, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	  	}
		  	  else if(FLOAT_SM_EQ(rannum, 2*_Third))
		  	  	{ // create newSyn1 and link with newCat2, newCat3;
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	  	}
		  	  else
		  	  	{ // create newSyn1 and link with newCat1, newCat2; 
				  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  	  // create newSyn2 and link with newCat1, newCat3;
				  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	  	}	
		  	}

		  // insert avaRule1, avaRule2, newWord, newCat1-3, newSyn1-2 into OptionComb[0];
		  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(3, avaRule1, avaRule2, newWord);	// lexical rule par;
		  newOptionComb->setOC_CatPart(3, newCat1, newCat2, newCat3);	// category part;
		  newOptionComb->setOC_SynPart(2, newSyn1, newSyn2, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;
		}
	
	avaRule1=NULL; avaRule2=NULL;	// recollect avaRule1, avaRule2;
}

void CIMMem::RandCrtCatSyn_InOC(CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1, CMeanUtter *meanutter)
{ // randomly create newCat1-2, newSyn1 for meanutter->m_pMean;
  // and insert them into m_pOptionComb[0];
  // m_nMeanType=1; "Predicate<Agent>" meaning;
  	// m_nType=2, 2 word rules;
		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
  // m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
  	// m_nType=2, 1 word + 1 phrase rules;
		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
  	int meantype=getpOptionComb(0)->m_nMeanType; int type=getpOptionComb(0)->m_nType;	int subtype=getpOptionComb(0)->m_nSubType; double combwei=getpOptionComb(0)->m_dCombinStr;		  
  	assert(((meantype==1)&&(type==2))||((meantype==2)&&(type==2)));
	int j;
  	CLexRule *avaRule1=NULL, *avaRule2=NULL;
	OptionComb *newOptionComb=NULL;	// new m_pOptionComb[0];
	int posAg=meanutter->getLengthSemRole();
	int posPred=meanutter->getLengthSem()+meanutter->getLengthSemRole();
	int lenSemItem=meanutter->getLengthSemItem();
	int phrasetype;
	
	if(meantype==1)
  		{ avaRule1=getpOptionComb(0)->m_ppLexRules[0]; avaRule2=getpOptionComb(0)->m_ppLexRules[1];
		  // check newCat1; Ag;
		  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
  		  else if((subtype==4)||(subtype==5)) CrtCat(newCat1, 1, avaRule1);	// create newCat1 and link with avaRule1;
		
  		  // check newCat2; Pred1;
  		  if((subtype==1)||(subtype==2)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
		  else if(subtype==4) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
  		  else if((subtype==3)||(subtype==5)) CrtCat(newCat2, 2, avaRule2);	// create newCat2 and link with avaRule2;
	 		    		  
		  // check newSyn1;
		  if(subtype==1) newSyn1=getpOptionComb(0)->m_ppSynRules[0];	// newSyn1 is already there;
		  else if((subtype==2)||(subtype==3)||(subtype==4)||(subtype==5))
		  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	}

		  // insert avaRule1-2, newCat1-2, newSyn1 into OptionComb[0];
		  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(2, avaRule1, avaRule2, NULL);	// lexical rule par;
		  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
		  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;

		  avaRule1=NULL; avaRule2=NULL;	// recollect avaRule1, avaRule2;
  		}
  	else if(meantype==2)
  		{ avaRule1=getpOptionComb(0)->m_ppLexRules[0]; avaRule2=getpOptionComb(0)->m_ppLexRules[1];
		  if((avaRule1->getpMeanUtter())->getpMean()->getElement(posAg)!=-1)
		  	{ // further check whether it is Ag or Pat;
			  for(j=0;j<lenSemItem;j++)
			  	{ if(meanutter->getpMean()->getElement(j+posAg)!=avaRule1->getpMeanUtter()->getpMean()->getElement(j+posAg))
			  		break;
			  	}
			  if(j==lenSemItem)
			  	{ // Ag rule is already there; check newCat1 for Ag rule;
				  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
				  else if((subtype==4)||(subtype==5)) CrtCat(newCat1, 1, avaRule1);	// create newCat1 and link with avaRule1;
				
				  // PredPat phrase rule is already there; check newCat2 for PredPat;
				  if((subtype==1)||(subtype==2)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
				  else if(subtype==4) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
				  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat2, 6, 7, avaRule2);	// create newCat2 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
				}
			  else
			  	{ // Pat rule is already there; check newCat1 for Pat rule;
			  	  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
				  else if((subtype==4)||(subtype==5)) BuildNewCat(newCat1, 3, 4, avaRule1);	// create newCat1 and link with avaRule1, and adjust avaRule1's CatList->m_nThemRole;
				  
				  // AgPred phrase rule is already there; check newCat2 for AgPred;
				  if((subtype==1)||(subtype==2)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
				  else if(subtype==4) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
				  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat2, 4, 5, avaRule2);	// create newCat2 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
				}
		  	}
		  else if((avaRule1->getpMeanUtter())->getpMean()->getElement(posPred)!=-1)
		  	{ // Pred2 rule is already there; check newCat1 for Pred2 rule;
		  	  if((subtype==1)||(subtype==2)||(subtype==3)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
			  else if((subtype==4)||(subtype==5)) BuildNewCat(newCat1, 2, 3, avaRule1);	// create newCat1 and link with avaRule1, and adjust avaRule1's CatList->m_nThemRole;
			  
			  // AgPat phrase rule is already there; check newCat2 for AgPat;
			  if((subtype==1)||(subtype==2)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
			  else if(subtype==4) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
			  else if((subtype==3)||(subtype==5)) BuildNewCat(newCat2, 5, 6, avaRule2);	// create newCat2 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
		  	}
  		  
		  // check newSyn1;
		  if(subtype==1) newSyn1=getpOptionComb(0)->m_ppSynRules[0];	// newSyn1 is already there;
		  else if((subtype==2)||(subtype==3)||(subtype==4)||(subtype==5))
		  	{ phrasetype=avaRule2->getLexTyp();
		  	  if((phrasetype==3)||(phrasetype==4)||(phrasetype==5)) 
		  	  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
		  	    	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: before;
		  		}
		    	  else if((phrasetype==6)||(phrasetype==7)||(phrasetype==8)) 
		    	  	CrtSynRule(newSyn1, newCat1, newCat2, 2);	// 2: in between;
		  	}

		  // insert avaRule1-2, newCat1-2, newSyn1 into OptionComb[0];
		  delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(2, avaRule1, avaRule2, NULL);	// lexical rule par;
		  newOptionComb->setOC_CatPart(2, newCat1, newCat2, NULL);	// category part;
		  newOptionComb->setOC_SynPart(1, newSyn1, NULL, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;

		  avaRule1=NULL; avaRule2=NULL;	// recollect avaRule1, avaRule2;
  		}	
}

void CIMMem::RandCrtCatSyn2_InOC(int perspective, CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2, CSynRule *&newSyn3, CMeanUtter *meanutter)
{ // randomly create newCat1-3, newSyn1-2 for meanutter->m_pMean;
  // and insert them into m_pOptionComb[0];
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
	assert((perspective==-1)||(perspective==0)||(perspective==1));
  	int meantype=getpOptionComb(0)->m_nMeanType; int type=getpOptionComb(0)->m_nType; int subtype=getpOptionComb(0)->m_nSubType; double combwei=getpOptionComb(0)->m_dCombinStr; 
	assert((meantype==2)&&(type==3));
	int i, j, k;
  	CLexRule *avaRule1=NULL, *avaRule2=NULL, *avaRule3=NULL;
  	OptionComb *newOptionComb=NULL;	// new m_pOptionComb[0];
	int cat1Index, cat2Index, cat3Index;
  	double assowei1, assowei2, assowei3;
  	double rannum;
	int comp2ret, comp3ret;
  	
	avaRule1=getpOptionComb(0)->m_ppLexRules[0]; avaRule2=getpOptionComb(0)->m_ppLexRules[1]; avaRule3=getpOptionComb(0)->m_ppLexRules[2];
	// check newCat1; Ag;
  	if(((1<=subtype)&&(subtype<=12))||(subtype==15)) newCat1=getpOptionComb(0)->m_ppCats[0];	// newCat1 is already there;
  	else CrtCat(newCat1, 1, avaRule1);	// create newCat1 and link with avaRule1;
		
  	// check newCat2; Pred2;
  	if((1<=subtype)&&(subtype<=10)) newCat2=getpOptionComb(0)->m_ppCats[1];	// newCat2 is already there;
  	else if((subtype==13)||(subtype==14)||(subtype==16)) newCat2=getpOptionComb(0)->m_ppCats[0];	// newCat2 is already there;
  	else BuildNewCat(newCat2, 2, 3, avaRule2);	// create newCat2 and link with avaRule2, and adjust avaRule2's CatList->m_nThemRole;
	
  	// check newCat3; Pat;
  	if((1<=subtype)&&(subtype<=8)) newCat3=getpOptionComb(0)->m_ppCats[2];	// newCat3 is already there;
  	else if((11<=subtype)&&(subtype<=14)) newCat3=getpOptionComb(0)->m_ppCats[1];	// newCat3 is already there;
  	else if(subtype==17) newCat3=getpOptionComb(0)->m_ppCats[0];	// newCat3 is already there;
  	else BuildNewCat(newCat3, 3, 4, avaRule3);	// create newCat3 and link with avaRule3, and adjust avaRule3's CatList->m_nThemRole;
	
	// create newSyn1, newSyn2 or newSyn3;
	if(subtype==1)
		{ // newSyn1, newSyn2, newSyn3 are already there; 
		  newSyn1=getpOptionComb(0)->m_ppSynRules[0]; newSyn2=getpOptionComb(0)->m_ppSynRules[1]; newSyn3=getpOptionComb(0)->m_ppSynRules[2];
		}
	else if((subtype==2)||(subtype==3)||(subtype==4))
		{ // newSyn1, newSyn2 are already there;
		  newSyn1=getpOptionComb(0)->m_ppSynRules[0]; newSyn2=getpOptionComb(0)->m_ppSynRules[1];
 		}
	else if(subtype==5)
		{ cat1Index=cat2Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
		  for(j=0;j<avaRule2->getCatNum();j++)
	  	  	{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
		  if(comp2ret==1)
	  	  	{ // newSyn1 is already there; 
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat1, newCat3;
		  	  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
	  	  	}
	  	  else if(comp2ret==2)
	  	  	{ // newSyn1 is already there; 
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}	  	  
		}
	else if(subtype==6)
		{ cat2Index=cat3Index=-1;
		  for(i=0;i<avaRule2->getCatNum();i++)
	  		{ if(newCat2==avaRule2->getpCatList(i)->getpCat()) { cat2Index=i; break; }
	  		}
		  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei2, assowei3);
		  if(comp2ret==1)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat2, newCat3, newSyn1, newCat1, newCat2);
	  	  	  // newSyn2 is already there;
	  	  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	}
		  else if(comp2ret==2)
		  	{ // newSyn1 is already there;
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}
		}
	else if(subtype==7)
		{ cat1Index=cat3Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
		  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei3);
		  if(comp2ret==1)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat1, newCat2);
	  	  	  // newSyn2 is already there;
	  	  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	}
		  else if(comp2ret==2)
		  	{ // create newSyn1 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat2, newCat3);
	  	  	  // newSyn2 is already there;
	  	  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
	  	  	}
		}
	else if(subtype==8)
		{ cat1Index=cat2Index=cat3Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
		  for(j=0;j<avaRule2->getCatNum();j++)
	  		{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
	  		}
		  for(k=0;k<avaRule3->getCatNum();k++)
	  	  	{ if(newCat3==avaRule3->getpCatList(k)->getpCat()) { cat3Index=k; break; }
	  	  	}
		  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp3ret=CGenFuncClass::comp3values_big(assowei1, assowei2, assowei3);
		  if(comp3ret==1)
			{ // crt syn1(12), syn2(13);
			  // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		  	}
		  else if(comp3ret==2)
			{ // crt syn1(12), syn2(23);
			  // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}		  
		  else if(comp3ret==3)
			{ // crt syn1(23), syn2(13);
			  // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
			  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
			  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}		  
		}
	else if(subtype==9)
		{ cat1Index=cat2Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule2->getCatNum();j++)
	  	  	{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
		  if(comp2ret==1)
	  	  	{ // newSyn1 is already there; 
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
	  	  	}
	  	  else if(comp2ret==2)
	  	  	{ // newSyn1 is already there; 
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}	  	  
		}
	else if(subtype==10)
		{ cat1Index=cat2Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule2->getCatNum();j++)
	  	  	{ if(newCat2==avaRule2->getpCatList(j)->getpCat()) { cat2Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei2);
		  if(comp2ret==1)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
	  	  	}
	  	  else if(comp2ret==2)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
	  	  	}
		}
	else if(subtype==11)
		{ cat1Index=cat3Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei3);
		  if(comp2ret==1)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat1, newCat2);
		  	  // newSyn2 is already there;
		  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
	  	  	}
	  	  else if(comp2ret==2)
	  	  	{ // create newSyn1 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat1, newCat3, newSyn1, newCat2, newCat3);
		  	  // newSyn2 is already there;
		  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
	  	  	}
		}
	else if(subtype==12)
		{ cat1Index=cat3Index=-1;
		  for(i=0;i<avaRule1->getCatNum();i++)
	  		{ if(newCat1==avaRule1->getpCatList(i)->getpCat()) { cat1Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei1=avaRule1->getpCatList(cat1Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei1, assowei3);
		  if(comp2ret==1)
	  	  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
	  	  	}
	  	  else if(comp2ret==2)
	  	  	{ // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
			  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
	  	  	}
		}
	else if(subtype==13)
		{ cat2Index=cat3Index=-1;
		  for(i=0;i<avaRule2->getCatNum();i++)
	  		{ if(newCat2==avaRule2->getpCatList(i)->getpCat()) { cat2Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei2, assowei3);
		  if(comp2ret==1)
		  	{ // create newSyn1 and link with newCat1, newCat2;
			  Crt1SynRule_Persp(perspective, getpOptionComb(0)->m_ppSynRules[0], newCat2, newCat3, newSyn1, newCat1, newCat2);
		  	  // newSyn2 is already there;
		  	  newSyn2=getpOptionComb(0)->m_ppSynRules[0];
		  	}
		  else if(comp2ret==2)
		  	{ // newSyn1 is already there;
		  	  newSyn1=getpOptionComb(0)->m_ppSynRules[0];
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}
		}
	else if(subtype==14)
		{ cat2Index=cat3Index=-1;
		  for(i=0;i<avaRule2->getCatNum();i++)
	  		{ if(newCat2==avaRule2->getpCatList(i)->getpCat()) { cat2Index=i; break; }
	  		}
	  	  for(j=0;j<avaRule3->getCatNum();j++)
	  	  	{ if(newCat3==avaRule3->getpCatList(j)->getpCat()) { cat3Index=j; break; }
	  	  	}
	  	  assowei2=avaRule2->getpCatList(cat2Index)->getAssoWei(); assowei3=avaRule3->getpCatList(cat3Index)->getAssoWei();
		  comp2ret=CGenFuncClass::comp2values_big(assowei2, assowei3);
		  if(comp2ret==1)
		  	{ // create newSyn1 and link with newCat1, newCat2;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		  	}
		  else if(comp2ret==2)
		  	{ // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
			  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
		  	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		  	}
		}
	else if(subtype==15)
		{ // create newSyn1 and link with newCat1, newCat2;
		  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  // create newSyn2 and link with newCat1, newCat3;
		  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
		}
	else if(subtype==16)
		{ // create newSyn1 and link with newCat1, newCat2;
		  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	  	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
		  // create newSyn2 and link with newCat2, newCat3;
		  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
		}
	else if(subtype==17)
		{ // create newSyn1 and link with newCat2, newCat3;
		  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
		  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
	  	  // create newSyn2 and link with newCat1, newCat3;
		  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
		}
	else if(subtype==18)
		{ // random create newSyn1, newSyn2 with newCat1, newCat2 and newCat3;
		  rannum=Rand0_1;
		  if(FLOAT_SM_EQ(rannum, _Third))
	    	{ // create newSyn1 and link with newCat1, newCat2; 
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	    	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
	    	  // create newSyn2 and link with newCat2, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat2, newCat3);
	    	}
		  else if(FLOAT_SM_EQ(rannum, 2*_Third))
	    	{ // create newSyn1 and link with newCat2, newCat3;
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat2, newCat3, 0);	// 0: before;
	    	  else CrtSynRule(newSyn1, newCat2, newCat3, 1);	// 1: after;
	    	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat2, newCat3, newSyn2, newCat1, newCat3);
	    	}
		  else
	    	{ // create newSyn1 and link with newCat1, newCat2; 
			  if(FLOAT_SM_EQ(Rand0_1, _Half)) CrtSynRule(newSyn1, newCat1, newCat2, 0);	// 0: before;
	    	  else CrtSynRule(newSyn1, newCat1, newCat2, 1);	// 1: after;
	    	  // create newSyn2 and link with newCat1, newCat3;
			  Crt1SynRule_Persp(perspective, newSyn1, newCat1, newCat2, newSyn2, newCat1, newCat3);
	    	}
		}

	// insert avaRule1-3, newCat1-3, newSyn1-2 into OptionComb[0];
	if(subtype==1)
		{ delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(3, avaRule1, avaRule2, avaRule3);	// lexical rule par;
		  newOptionComb->setOC_CatPart(3, newCat1, newCat2, newCat3);	// category part;
		  newOptionComb->setOC_SynPart(3, newSyn1, newSyn2, newSyn3);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;
		}
	else
		{ delete m_ppOptionComb[0]; m_ppOptionComb[0]=NULL;	// delete original OptionComb[0];
		  // create new OptionComb[0];
		  newOptionComb=new OptionComb; assert(newOptionComb!=NULL);
		  newOptionComb->setOC_GenInfo(meantype, type, subtype, combwei);
		  newOptionComb->setOC_LexPart(3, avaRule1, avaRule2, avaRule3);	// lexical rule par;
		  newOptionComb->setOC_CatPart(3, newCat1, newCat2, newCat3);	// category part;
		  newOptionComb->setOC_SynPart(2, newSyn1, newSyn2, NULL);	// syntax part;
		  m_ppOptionComb[0]=newOptionComb;
		  newOptionComb=NULL;	// recollect newOptionComb;
		}
	
	avaRule1=NULL; avaRule2=NULL; avaRule3=NULL;	// recollect avaRule1, avaRule2, avaRule3;	
}					 	  
	
void CIMMem::UseOptionCombSetUtter(CMeanUtter *meanutter)
{ // use rules in m_pIMMem->m_pOptionComb[0] to set up utterance;
	int meantype=getpOptionComb(0)->m_nMeanType; int type=getpOptionComb(0)->m_nType; int subtype=getpOptionComb(0)->m_nSubType;
	assert(((meantype==1)&&(0<=type)&&(type<=3))||((meantype==2)&&(0<=type)&&(type<=6)));
	int ordertype, ordertype1, ordertype2, ordertype3;
	CLexRule *Holistrule=NULL, *rule1=NULL, *rule2=NULL, *rule3=NULL;
	CCat *cat1=NULL, *cat2=NULL, *cat3=NULL;
	CSynRule *syn12=NULL, *syn23=NULL, *syn13=NULL;
	
	if(meantype==1)
		{ // "Predicate<Agent>" meanings;
		  switch(type)
			{ case 0: case 1: // use holistic or rand holistic rule;
					Holistrule=getpOptionComb(0)->m_ppLexRules[0];
					meanutter->setpUtter(Holistrule->getpMeanUtter()->getpUtter());
					Holistrule=NULL;	// recollect Holistrule;
					break;
			  case 2: case 3: // use 2 word rules or 1 word + 1 rand word rules;
			  		rule1=getpOptionComb(0)->m_ppLexRules[0]; rule2=getpOptionComb(0)->m_ppLexRules[1];
			  		cat1=getpOptionComb(0)->m_ppCats[0]; cat2=getpOptionComb(0)->m_ppCats[1];
					syn12=getpOptionComb(0)->m_ppSynRules[0];
					ordertype=-1;
					if((syn12->getpCat(0)==cat1)&&(syn12->getpCat(1)==cat2)) ordertype=syn12->getSynTyp();	// normal order;
					else if((syn12->getpCat(1)==cat1)&&(syn12->getpCat(0)==cat2)) ordertype=!(syn12->getSynTyp());	// reverse order; 
					meanutter->Comb2Utter(rule1->getpMeanUtter(), rule2->getpMeanUtter(), ordertype);
					rule1=NULL; rule2=NULL;	// recollect rule1, rule2;
					cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
					syn12=NULL;	// recollect syn12;
					break;
			  default: break;
			}
		}
	else if(meantype==2)
		{ // "Predicate<Agent, Patient>" meanings;
		  switch(type)
		  	{ case 0: case 1: // use holistic or rand holistic rule;
					Holistrule=getpOptionComb(0)->m_ppLexRules[0];
					meanutter->setpUtter(Holistrule->getpMeanUtter()->getpUtter());	
					Holistrule=NULL;	// recollect Holistrule;
					break;
		  	  case 2: case 4: case 6: // use 1 word + 1 phrase rules or 1 rand word +1 phrase, or 1 word + 1 rand phrase rules;
				    rule1=getpOptionComb(0)->m_ppLexRules[0]; rule2=getpOptionComb(0)->m_ppLexRules[1];
					cat1=getpOptionComb(0)->m_ppCats[0]; cat2=getpOptionComb(0)->m_ppCats[1];
					syn12=getpOptionComb(0)->m_ppSynRules[0];
					ordertype=-1;
					if((syn12->getpCat(0)==cat1)&&(syn12->getpCat(1)==cat2)) ordertype=syn12->getSynTyp();	// normal order;
					else if((syn12->getpCat(1)==cat1)&&(syn12->getpCat(0)==cat2))
						{ if((syn12->getSynTyp()==0)||(syn12->getSynTyp()==1)) ordertype=!(syn12->getSynTyp());
					      else if(syn12->getSynTyp()==2) ordertype=3;
						  else if(syn12->getSynTyp()==3) ordertype=2;
					    }
					meanutter->Comb2Utter(rule1->getpMeanUtter(), rule2->getpMeanUtter(), ordertype);
					rule1=NULL; rule2=NULL;	// recollect rule1, rule2;
					cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
					syn12=NULL;	// recollect syn12;
					break;
		  	  case 3: case 5: // use 3 word rules or 2 word + 1 rand word rules;
					rule1=getpOptionComb(0)->m_ppLexRules[0]; rule2=getpOptionComb(0)->m_ppLexRules[1]; rule3=getpOptionComb(0)->m_ppLexRules[2];
					cat1=getpOptionComb(0)->m_ppCats[0]; cat2=getpOptionComb(0)->m_ppCats[1]; cat3=getpOptionComb(0)->m_ppCats[2];
					if((type==3)&&(subtype==1))
						{ syn12=getpOptionComb(0)->m_ppSynRules[0]; syn23=getpOptionComb(0)->m_ppSynRules[1]; syn13=getpOptionComb(0)->m_ppSynRules[2];
						  ordertype1=ordertype2=ordertype3=-1; 
						  if((syn12->getpCat(0)==cat1)&&(syn12->getpCat(1)==cat2)) ordertype1=syn12->getSynTyp();	// normal order;
						  if((syn12->getpCat(1)==cat1)&&(syn12->getpCat(0)==cat2)) ordertype1=!(syn12->getSynTyp());	// reverse order;
						  if((syn23->getpCat(0)==cat2)&&(syn23->getpCat(1)==cat3)) ordertype2=syn23->getSynTyp();	// normal order;
						  if((syn23->getpCat(1)==cat2)&&(syn23->getpCat(0)==cat3)) ordertype2=!(syn23->getSynTyp());	// reverse order;
						  if((syn13->getpCat(0)==cat1)&&(syn13->getpCat(1)==cat3)) ordertype3=syn13->getSynTyp();	// normal order;
						  if((syn13->getpCat(1)==cat1)&&(syn13->getpCat(0)==cat3)) ordertype3=!(syn13->getSynTyp());	// reverse order;
						  meanutter->Comb3Utter(rule1->getpMeanUtter(), rule2->getpMeanUtter(), rule3->getpMeanUtter(), ordertype1, ordertype2, ordertype3);						  
						  syn12=NULL; syn23=NULL; syn13=NULL;	// recollect syn12, syn23, syn13;
						}
					else 
						{ syn12=getpOptionComb(0)->m_ppSynRules[0]; syn23=getpOptionComb(0)->m_ppSynRules[1];
						  ordertype1=ordertype2=ordertype3=-1; 
						  // check syn12 is 12 or 23;
						  if((syn12->getpCat(0)==cat1)&&(syn12->getpCat(1)==cat2)) ordertype1=syn12->getSynTyp();	// normal order;
						  if((syn12->getpCat(1)==cat1)&&(syn12->getpCat(0)==cat2)) ordertype1=!(syn12->getSynTyp());	// reverse order;
						  if((syn12->getpCat(0)==cat2)&&(syn12->getpCat(1)==cat3)) ordertype2=syn12->getSynTyp();	// normal order;
						  if((syn12->getpCat(1)==cat2)&&(syn12->getpCat(0)==cat3)) ordertype2=!(syn12->getSynTyp());	// reverse order;
						  // check syn23 is 23 or 13;
						  if((syn23->getpCat(0)==cat2)&&(syn23->getpCat(1)==cat3)) ordertype2=syn23->getSynTyp();	// normal order;
						  if((syn23->getpCat(1)==cat2)&&(syn23->getpCat(0)==cat3)) ordertype2=!(syn23->getSynTyp());	// reverse order;
						  if((syn23->getpCat(0)==cat1)&&(syn23->getpCat(1)==cat3)) ordertype3=syn23->getSynTyp();	// normal order;
						  if((syn23->getpCat(1)==cat1)&&(syn23->getpCat(0)==cat3)) ordertype3=!(syn23->getSynTyp());	// reverse order;
						  meanutter->Comb3Utter(rule1->getpMeanUtter(), rule2->getpMeanUtter(), rule3->getpMeanUtter(), ordertype1, ordertype2, ordertype3);
						  syn12=NULL; syn23=NULL;	// recollect syn1, syn2;
						}
					rule1=NULL; rule2=NULL; rule3=NULL;	// recollect rule1, rule2, rule3;
					cat1=NULL; cat2=NULL; cat3=NULL;	// recollect cat1, cat2, cat3;
			  		break;
		  	  default: break;
		  	}		  	
		}
}

void CIMMem::RecIMMem(FILE * f, CSemSpace *semspace, CLTMem *LTMem)
{ // record IMMem in f;
	assert(f!=NULL); assert(semspace!=NULL); assert(LTMem!=NULL);
	int i, j, k, m, n;
	CCat *Cat=NULL;	// record category;
	CSynRule *SynRule=NULL;	// record syntactic rule;
	
	int widthOpt=(int)(log10((double)(getMaxNumCombOption()))+1);
	int widthLex=(int)(log10((double)(getMaxNumLexRules()))+1);
	int widthCat=(int)(log10((double)(getMaxNumCats()))+1);
	int widthSyn=(int)(log10((double)(getMaxNumSynRules()))+1);
	int widthSynStr=(int)(-1.0*log10((double)(overallpara.p_dSynRuleStrUp))+0.5);
	int widthDecSynStr=(int)(-1.0*log10((double)(overallpara.p_dSynRuleStrLow))+0.5);
	int widthAssoWei=(int)(-1.0*log10((double)(overallpara.p_dAssoWeiUp))+0.5);
	int widthDecAssoWei=(int)(-1.0*log10((double)(overallpara.p_dAssoWeiLow))+0.5);

	fprintf(f, "ChoWin=%d\n", getChosWin());
	fprintf(f, "NumCombOption=%*d\n", widthOpt, getNumCombOption());
	for(i=0;i<getNumCombOption();i++)
	  	{ fprintf(f, "CombOption[%*d]:\n", widthOpt, i);
	  	  fprintf(f, "CombStr=%*.*f, Meantype=%d, Type=%d, Subtype=%d\n", widthSynStr+widthDecSynStr+1, widthDecSynStr, getpOptionComb(i)->m_dCombinStr, getpOptionComb(i)->m_nMeanType, getpOptionComb(i)->m_nType, getpOptionComb(i)->m_nSubType);
		  // record lexical rules;
		  fprintf(f, "NumLex=%*d\n", widthLex, getpOptionComb(i)->m_nNumLexRules);
		  for(j=0;j<getpOptionComb(i)->m_nNumLexRules;j++)
		  	{ if(LTMem->Judge_InLex(getpOptionComb(i)->m_ppLexRules[j])==1)
		  		{ fprintf(f, "Lex%*d ", widthLex, j);	
		  	  	  getpOptionComb(i)->m_ppLexRules[j]->RecLexRule(f, semspace);
		  		}
		  	  else fprintf(f, "Lex%*d disappear! ", widthLex, j);
		  	}
		  fprintf(f,"\n");
		  // record categores;
		  fprintf(f, "NumCat=%*d\n", widthLex, getpOptionComb(i)->m_nNumCats);
		  for(j=0;j<getpOptionComb(i)->m_nNumCats;j++)
		  	{ Cat=getpOptionComb(i)->m_ppCats[j];
		  	  if(LTMem->Judge_InCat(Cat)==1)
		  	  	{ fprintf(f, "Cat%*d", widthCat, j); Cat->recCatTyp(f);  
	  		  	  fprintf(f,"\n");
			  	  // list all lexrule and synrule;
			  	  fprintf(f, "NumLex=%*d: ", widthLex, Cat->getLexNum());
			  	  for(k=0;k<Cat->getLexNum();k++)
			 	 	{ if(LTMem->Judge_InLex(Cat->getpLexRule(k))==1)
			  	  		{ for(m=0;m<LTMem->getNumLexRule();m++)
			  				{ if(Cat->getpLexRule(k)==LTMem->getpLexRuleList(m))
			  					{ for(n=0;n<LTMem->getpLexRuleList(m)->getCatNum();n++)
			  						{ if(LTMem->getpLexRuleList(m)->getpCatList(n)->getpCat()==Cat) break;
			  						}
			  					   fprintf(f, "Lex%*d (%*.*f); ", widthLex, m, widthAssoWei+widthDecAssoWei+1, widthDecAssoWei, LTMem->getpLexRuleList(m)->getpCatList(n)->getAssoWei()); 
								   break; 
			  					 } 
			 	 			}
			  	  		}
				  	  else fprintf(f, "Lex %*d disappear! ", widthLex, k);
			 	 	}
			  	  if(Cat->getThemRole()!=0)
				  	{ fprintf(f, "\nNumSyn=%*d: ", widthSyn, Cat->getSynNum());
			  		  for(k=0;k<Cat->getSynNum();k++)
			  			{ if(LTMem->Judge_InSyn(Cat->getpSynRule(k))==1)
			  		  		{ for(m=0;m<LTMem->getNumSynRule();m++)
			  					{ if(Cat->getpSynRule(k)==LTMem->getpSynRuleList(m)) { fprintf(f, "Syn%*d; ", widthSyn, m); break; }
			  					}
			  		  		}
					  	  else fprintf(f, "Syn %*d disappear! ", widthLex, k);
			  			}
			  		}
			  	  else fprintf(f, "\n");
		  	  	}
			  else fprintf(f, "Cat%*d disappear ", widthCat, j);
			  Cat=NULL;	// recollect Cat;
			  fprintf(f, "\n");
			}
		  fprintf(f, "\n");
		  // record syntactic rules;
		  fprintf(f, "NumSyn=%*d\n", widthSyn, getpOptionComb(i)->m_nNumSynRules);
		  for(j=0;j<getpOptionComb(i)->m_nNumSynRules;j++)
	 	 	{ SynRule=getpOptionComb(i)->m_ppSynRules[j];
		  	  if(LTMem->Judge_InSyn(SynRule)==1)
		  	  	{ for(k=0;k<LTMem->getNumSynRule();k++)
		  	  		{ if(SynRule==LTMem->getpSynRuleList(k)) { fprintf(f, "Syn%*d", widthSyn, k); break; }
			  		}
			  	  SynRule->recSynTyp(f);		  
				  fprintf(f, "(%*.*f): ", widthSynStr+widthDecSynStr+1, widthDecSynStr, SynRule->getSynStr());
				  if(LTMem->Judge_InCat(SynRule->getpCat(0))==1)
				  	{ for(m=0;m<LTMem->getNumCat();m++)
	  				  	{ if(SynRule->getpCat(0)==LTMem->getpCatList(m)) { fprintf(f, "Cat%*d", widthCat, m); LTMem->getpCatList(m)->recCatTyp(f); break; }
	  			  		}
				  	}
				  else fprintf(f, "Cat%*d disappear! ", widthCat, 0);
				  if(SynRule->getSynTyp()==0) fprintf(f, " << ");
				  else if(SynRule->getSynTyp()==1) fprintf(f, " >> ");
				  else if(SynRule->getSynTyp()==2) fprintf(f, " %c ", 'A');
				  else if(SynRule->getSynTyp()==3) fprintf(f, " %c ", 'V');
				  if(LTMem->Judge_InCat(SynRule->getpCat(1))==1)
				  	{ for(m=0;m<LTMem->getNumCat();m++)
	  				  	{ if(SynRule->getpCat(1)==LTMem->getpCatList(m)) { fprintf(f, "Cat%*d", widthCat, m); LTMem->getpCatList(m)->recCatTyp(f); break; }
	  			  		}
				  	}
				  else fprintf(f, "Cat%*d disappear! ", widthCat, 1);
		  	  	}
			  else fprintf(f, "Syn%*d disappear! ", widthSyn, j);
	 	 	  SynRule=NULL;	// recollect SynRule;
	  		  fprintf(f, ";\n");
	 	 	}
		  fprintf(f,"\n");
	  	}
	  fprintf(f,"\n");
}



// RelaCatListSyn's membership functions;
RelaCatListSyn::RelaCatListSyn()
{ // construction function;
	InitRelaCatListSyn();
}

RelaCatListSyn::~RelaCatListSyn()
{ // destruction function;
	DestRelaCatListSyn();
}

void RelaCatListSyn::InitRelaCatListSyn()
{ // initialization function;
	m_nProPer=-1; 
	m_nNoCatList=-1; m_nNoSyn=-1; m_nSubTyp=-1; m_dCombStr=0.0;
	m_pCatList1=NULL; m_pCatList2=NULL; m_pCatList3=NULL;
	m_pSyn12=NULL; m_pSyn23=NULL; m_pSyn13=NULL;
}

void RelaCatListSyn::DestRelaCatListSyn()
{ // destroy function;
	m_nProPer=-1; 
	m_nNoCatList=-1; m_nNoSyn=-1; m_nSubTyp=-1; m_dCombStr=0.0;
	m_pCatList1=NULL; m_pCatList2=NULL; m_pCatList3=NULL;
	m_pSyn12=NULL; m_pSyn23=NULL; m_pSyn13=NULL;
}

void RelaCatListSyn::setComponent(int proper, int noCatList, int noSyn, int subtyp, double combstr, CatList *catList1, CatList *catList2, CatList *catList3, CSynRule * syn12, CSynRule * syn23, CSynRule * syn13)
{ // set components; 
  	setProPer(proper); 
  	setNoCatList(noCatList); setNoSyn(noSyn); setSubTyp(subtyp); setCombStr(combstr); 
	setpCatList1(catList1); setpCatList2(catList2); setpCatList3(catList3);
	setpSyn12(syn12); setpSyn23(syn23); setpSyn13(syn13);
}

// CLTMem's membership functions;
CLTMem::CLTMem()
{ // construction function;
	InitLTMem(0, 0, 0, 0, 0, 0);
}

CLTMem::CLTMem(const CLTMem &init)
{ // copy construction function;
	(*this)=init;
}

CLTMem::~CLTMem()
{ // destruction function;
	DestLTMem();
}

CLTMem & CLTMem::operator = (const CLTMem &right)
{ // copy long-term memory;
	int i;
	if(&right!=this)
		{ // it is not a self-copy;
		  DestLTMem(); InitLTMem(right.m_nNumLexRule, right.m_nMaxLexRule, right.m_nNumCat, right.m_nMaxCat, right.m_nNumSynRule, right.m_nMaxSynRule);
		  setProComp2_3(right.m_nProComp2_3); setPerComp2_3(right.m_nPerComp2_3);
		  setChoIdentical(right.m_nChoIdentical);
		  setNeuLexStr(right.m_dNeuLexStr); setNeuAssoWei(right.m_dNeuAssoWei); setNeuSynStr(right.m_dNeuSynStr);
		  setMaxLexRule(right.m_nMaxLexRule); setMaxCat(right.m_nMaxCat); setMaxSynRule(right.m_nMaxSynRule);
		  setMaxRecPat(right.m_nMaxRecPat);
		  setDecHolistPhrase(right.m_nDecHolistPhrase);
		  // lexical rules, categories and syntactic rules;	
		  if(getNumLexRule()!=0)
		  	{ for(i=0;i<getNumLexRule();i++) 
		  	  	setpLexRuleList(i, right.m_ppLexRuleList[i]);	// copy by address;
		  	}
		  if(getNumCat()!=0)
		  	{ for(i=0;i<getNumCat();i++) 
		  	  	setpCatList(i, right.m_ppCatList[i]);	// copy by address;
		  	}
		  if(getNumSynRule()!=0)
  		  	{ for(i=0;i<getNumSynRule();i++) 
  		  	  	setpSynRuleList(i, right.m_ppSynRuleList[i]);	// copy by address;
			}
		}
	return *this;
}

void CLTMem::InitLTMem(int numLex, int maxnumLex, int numCat, int maxnumCat, int numSyn, int maxnumSyn)
{ // initialization function;
	if(overallpara.p_nVarLTMem==0) assert((0<=numLex)&&(numLex<=overallpara.p_nMaxLexRule)&&(0<=numCat)&&(numCat<=overallpara.p_nMaxCat)&&(0<=numSyn)&&(numSyn<=overallpara.p_nMaxSynRule));
	else if(overallpara.p_nVarLTMem==1) assert((numLex>=0)&&(numCat>=0)&&(numSyn>=0));
	int i;
	int var;
	
	setProComp2_3(overallpara.p_nProComp2_3); setPerComp2_3(overallpara.p_nPerComp2_3);
	setChoIdentical(overallpara.p_nChoIdentical);
	setNeuLexStr(overallpara.p_dNeuLexStr); setNeuAssoWei(overallpara.p_dNeuAssoWei); setNeuSynStr(overallpara.p_dNeuSynStr);

	if(overallpara.p_nVarLTMem==0) 
		{ setMaxLexRule(overallpara.p_nMaxLexRule); 
		  setMaxCat(overallpara.p_nMaxCat);
		  setMaxSynRule(overallpara.p_nMaxSynRule);
		}
	else if(overallpara.p_nVarLTMem==1) 
		{ if((maxnumLex==0)&&(maxnumCat==0)&&(maxnumSyn==0))
			{ // initialization!
		  	  var=overallpara.p_nMaxLexRule+(int)(sqrt((double)(overallpara.p_nMaxLexRuleVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1));
		  	  if(var<1) var=1;
		  	  setMaxLexRule(var);
		  	  var=overallpara.p_nMaxCat+(int)(sqrt((double)(overallpara.p_nMaxCatVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1));
		  	  if(var<1) var=1;
		  	  setMaxCat(var);
		  	  var=overallpara.p_nMaxSynRule+(int)(sqrt((double)(overallpara.p_nMaxSynRuleVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1));
		  	  if(var<1) var=1;
		  	  setMaxSynRule(var);
			}
		  else
		  	{ setMaxLexRule(maxnumLex);
		  	  setMaxCat(maxnumCat);
			  setMaxSynRule(maxnumSyn);
		  	}
		}
	
	setMaxRecPat(overallpara.p_nMaxRecPat);
	setDecHolistPhrase(overallpara.p_nDecHolistPhrase);
	// lexical rules, categories and syntactic rules;
	m_nNumLexRule=numLex;
	if(getNumLexRule()==0) m_ppLexRuleList=NULL;
	else
		{ m_ppLexRuleList=new CLexRule * [getNumLexRule()]; assert(m_ppLexRuleList!=NULL);
		  for(i=0;i<getNumLexRule();i++) 
			m_ppLexRuleList[i]=NULL;
		}
	m_nNumCat=numCat;
	if(getNumCat()==0) m_ppCatList=NULL;
	else
		{ m_ppCatList=new CCat * [getNumCat()]; assert(m_ppCatList!=NULL);
		  for(i=0;i<getNumCat();i++) 
			m_ppCatList[i]=NULL;
		}
	m_nNumSynRule=numSyn;
	if(getNumSynRule()==0) m_ppSynRuleList=NULL;
	else
		{ m_ppSynRuleList=new CSynRule * [getNumSynRule()]; assert(m_ppSynRuleList!=NULL);
		  for(i=0;i<getNumSynRule();i++)
		  	m_ppSynRuleList[i]=NULL;
		}
}

void CLTMem::DestLTMem()
{ // destroy function;
	EmpLexList(); EmpCatList(); EmpSynList();
	setProComp2_3(-1); setPerComp2_3(-1);
	setChoIdentical(-1);
	setNeuAssoWei(0.0); setNeuLexStr(0.0); setNeuSynStr(0.0);
	setMaxLexRule(0); setMaxCat(0); setMaxSynRule(0);
	setMaxRecPat(0);
	setDecHolistPhrase(-1);
}

// other operations;
void CLTMem::updLexRuleList()
{ // update LexRuleList, if LexRuleList[i]'s lexical rule's meanutter=NULL, delete LexRuleList[i], and update NumLexRule;
	int i, j, numnewlexrule;
	CLexRule **lexlisttemp=NULL;
	
	if(getNumLexRule()!=0)
		{ // check whether there are lexical rules whose meanutter=NULL;
		  numnewlexrule=getNumLexRule();
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(getpLexRuleList(i)->getpMeanUtter()==NULL)
		  		{ delete m_ppLexRuleList[i]; m_ppLexRuleList[i]=NULL;
		  		  numnewlexrule--;
		  		}
			}
		  if((numnewlexrule!=getNumLexRule())&&(numnewlexrule!=0))
		  	{ // create new LexRuleList; 
		  	  lexlisttemp=new CLexRule * [numnewlexrule]; assert(lexlisttemp!=NULL);
			  for(i=0;i<numnewlexrule;i++)
			  	lexlisttemp[i]=NULL;
			  i=0;
			  for(j=0;j<getNumLexRule();j++)
			  	{ if(getpLexRuleList(j)!=NULL)
			  		{ lexlisttemp[i]=getpLexRuleList(j);
					  i++;
			  		}
			  	}
			  // delete original LexRuleList;
			  delete [] m_ppLexRuleList; m_ppLexRuleList=NULL;
			  m_nNumLexRule=0;
			  // copy lexlisttemp to LexRuleList;
			  m_nNumLexRule=numnewlexrule; m_ppLexRuleList=lexlisttemp;
			  lexlisttemp=NULL;	// recollect lexrulelisttemp;
			}
		  else if(numnewlexrule==0)
		  	{ delete [] m_ppLexRuleList; m_ppLexRuleList=NULL;
		  	  m_nNumLexRule=0;
		  	}
		}
}

void CLTMem::updCatList()
{ // update CatList, if CatList[i]'s category's ThemRole=-1, delete CatList[i], and update NumCat;
	int i, j, numnewcat;
	CCat **cattemp=NULL;
		
	if(getNumCat()!=0)
		{ // check whether there are categories whose m_nSemCatTyp=-1;
		  numnewcat=getNumCat();
		  for(i=0;i<getNumCat();i++)
		  	{ if(getpCatList(i)->getThemRole()==-1)
		  		{ delete m_ppCatList[i]; m_ppCatList[i]=NULL; 
		  		  numnewcat--;
		  		}
		  	}
		  if((numnewcat!=getNumCat())&&(numnewcat!=0))
		  	{ // create new CatList;
		  	  cattemp=new CCat * [numnewcat]; assert(cattemp!=NULL);
			  for(i=0;i<numnewcat;i++)
			  	cattemp[i]=NULL;
			  i=0;
			  for(j=0;j<getNumCat();j++)
			  	{ if(getpCatList(j)!=NULL)
			  		{ cattemp[i]=getpCatList(j);
					  i++;	
			  		}
			  	}
			  // delete original CatList;
			  delete [] m_ppCatList; m_ppCatList=NULL;
			  m_nNumCat=0;
			  // copy cattemp to CatList;
			  m_nNumCat=numnewcat; m_ppCatList=cattemp;
			  cattemp=NULL;	// recollect cattemp;
			}
		  else if(numnewcat==0)
		  	{ delete [] m_ppCatList; m_ppCatList=NULL;
		  	  m_nNumCat=0;
		  	}
		}
}

void CLTMem::updSynRuleList()
{ // update SynRuleList, if SynRuleList[i]'s SynTyp=-1, delete SynRuleList[i], and update NumSynRule;
	int i, j, numnewsynrule;	
	CSynRule **synlisttemp=NULL;
		
	if(getNumSynRule()!=0)
		{ // check whether there are syntactic rules whose SynTyp=-1;
		  numnewsynrule=getNumSynRule();
		  for(i=0;i<getNumSynRule();i++)
		  	{ if(getpSynRuleList(i)->getSynTyp()==-1)
		  		{ delete m_ppSynRuleList[i]; m_ppSynRuleList[i]=NULL;
		  		  numnewsynrule--;
		  		}
		  	}
		  if((numnewsynrule!=getNumSynRule())&&(numnewsynrule!=0))
		  	{ // create new SynRuleList; 
		  	  synlisttemp=new CSynRule * [numnewsynrule]; assert(synlisttemp!=NULL);
			  for(i=0;i<numnewsynrule;i++)
			  	synlisttemp[i]=NULL;
			  i=0;
			  for(j=0;j<getNumSynRule();j++)
			  	{ if(getpSynRuleList(j)!=NULL)
			  		{ synlisttemp[i]=getpSynRuleList(j);
					  i++;	
			  		}
			  	}
			  // delete original SynRuleList;
			  delete [] m_ppSynRuleList; m_ppSynRuleList=NULL;
			  m_nNumSynRule=0;
			  // copy synlisttemp to SynRuleList;
			  m_nNumSynRule=numnewsynrule; m_ppSynRuleList=synlisttemp;
			  synlisttemp=NULL;	// recollect synlisttemp;			  
		  	}
		  else if(numnewsynrule==0)
		  	{ delete [] m_ppSynRuleList; m_ppSynRuleList=NULL;
		  	  m_nNumSynRule=0;
		  	}		  
		}
}

void CLTMem::RedIdentSynRule()
{ // reduce identical syntactic rules to one with the highest strength;
	int i, j;
	CSynRule *curSyn=NULL;
	int *synchk=NULL, synTyp, revsynTyp, highsynIndex;
	double highsynStr;
	
	// initial synchk to record identical syntactic rules;
	synchk=new int [getNumSynRule()]; assert(synchk!=NULL);
	for(i=0;i<getNumSynRule();i++)
		synchk[i]=0;
			  
	for(i=0;i<getNumSynRule();i++)
		{ curSyn=getpSynRuleList(i); 
	  	  if(synchk[i]==0)
	 		{ synchk[i]=1;
			  // gather curSyn's info;
	  		  synTyp=curSyn->getSynTyp();
			  revsynTyp=-1;
	  	  	  if((synTyp==0)||(synTyp==1)) revsynTyp=!synTyp;
	  	  	  else if(synTyp==2) revsynTyp=3;
	  	  	  else if(synTyp==3) revsynTyp=2;
	  	  	  highsynIndex=i; highsynStr=curSyn->getSynStr();	

		  	  for(j=i+1;j<getNumSynRule();j++)
		  	  	{ if((curSyn->getpCat(0)==getpSynRuleList(j)->getpCat(0))&&(curSyn->getpCat(1)==getpSynRuleList(j)->getpCat(1))&&(synTyp==getpSynRuleList(j)->getSynTyp()))
		  	    	{ // normal identical syntactic rules;
					  synchk[j]=1;	
					  if(FLOAT_BG_EQ(getpSynRuleList(j)->getSynStr(), highsynStr)) { highsynIndex=j; highsynStr=getpSynRuleList(j)->getSynStr(); }
		  	    	}
		  	      else if((curSyn->getpCat(0)==getpSynRuleList(j)->getpCat(1))&&(curSyn->getpCat(1)==getpSynRuleList(j)->getpCat(0))&&(revsynTyp==getpSynRuleList(j)->getSynTyp()))
		  	    	{ // reverse identical syntactic rules;
					  synchk[j]=1;
					  if(FLOAT_BG_EQ(getpSynRuleList(j)->getSynStr(), highsynStr)) { highsynIndex=j; highsynStr=getpSynRuleList(j)->getSynStr(); }
		  	    	}
		  	  	}
		  	    	  
		  	  // set up the remain identical rule with the highest strength;
			  for(j=i;j<getNumSynRule();j++)
		  	    { if((synchk[j]==1)&&(j==highsynIndex))
		  	    	{ synchk[j]=2; break; }		  	  	  	   	  	  	  
			  		}
		    	}
	    	  curSyn=NULL;	// recollect curSyn;
		}

	// after searching identical syntactic rules, delete SynChk[j]=1's syntactic rules;
	for(i=0;i<getNumSynRule();i++)
		{ if(synchk[i]==1)
	 		{ // delete synchosen;
	  		  for(j=0;j<getpSynRuleList(i)->getNumCatRelated();j++)
	  		  	{ getpSynRuleList(i)->getpCat(j)->AdjCat_Syn(getpSynRuleList(i));
	  		  	  getpSynRuleList(i)->setpCat(j, NULL);
	  		  	}
	  		  getpSynRuleList(i)->updSynRule(2);	// m_ppCat[i]=NULL;
	  		}
	  	}
	updLTMem();	
	delete [] synchk; synchk=NULL;	// delete synchk;
}

// insert new lexical rule/category/syntactic rule;
void CLTMem::InLexRule(CLexRule *&lexrule)
{ // insert lexrule into LexRuleList;
	assert(lexrule!=NULL);
	int i, j, lexindex;
	CLexRule **lexrulelisttemp=NULL;
	int numnewlex;
	CatList *originalcatlist=NULL;
	double lexstr;

	updLTMem();	// before insert anything, updLTMem first in case any InCat, InLex or InSyn function of each rule delete some lexical rule/category/syntactic rule;, 
	
	if(getNumLexRule()==0)
		{ // create new LexRuleList; 
		  m_nNumLexRule++;
		  m_ppLexRuleList=new CLexRule * [getNumLexRule()]; assert(m_ppLexRuleList!=NULL);
		  m_ppLexRuleList[0]=NULL; setpLexRuleList(0, lexrule);
		}
	else if(getNumLexRule()==getMaxLexRule())
		{ // first, check if lexrule is already in LexRuleList;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(*(getpLexRuleList(i))==*lexrule) break;	// check value;
		  	}
		  if(i==getNumLexRule())
		  	{ // randomly select a lexical rule with smallest rule strength to replace;
			  lexstr=getpLexRuleList(0)->getLexRuleStrUp();
			  for(i=0;i<getNumLexRule();i++)
			  	{ if(FLOAT_SM_EQ(getpLexRuleList(i)->getLexStr(), lexstr)) lexstr=getpLexRuleList(i)->getLexStr();
			  	}
			  do{ lexindex=(int)(Rand0_1*getNumLexRule());
			  }while((lexindex==getNumLexRule())||(FLOAT_NE(getpLexRuleList(lexindex)->getLexStr(), lexstr)));
			  if(getpLexRuleList(lexindex)->getCatNum()!=0)
			  	{ for(i=0;i<getpLexRuleList(lexindex)->getCatNum();i++)
			  		{ // update LexRuleList[lexindex]'s cat;
			     		  originalcatlist=getpLexRuleList(lexindex)->getpCatList(i);	// keep m_ppLexRuleList[lexindex]->m_ppCatList[i];
			  		  getpLexRuleList(lexindex)->getpCatList(i)->getpCat()->AdjCat_Lex(getpLexRuleList(lexindex));
					  if(i>=getpLexRuleList(lexindex)->getCatNum())
						{ // one of previous CatList is deleted caused by delete CatList[i];
						  for(j=getpLexRuleList(lexindex)->getCatNum()-1;j>=0;j--)
						  	{ if(getpLexRuleList(lexindex)->getpCatList(j)==originalcatlist) 
						    		{ getpLexRuleList(lexindex)->getpCatList(j)->setpCat(NULL); i=j; break; }
						    	}
						}
					  else if(i<getpLexRuleList(lexindex)->getCatNum())
						{ if(originalcatlist!=getpLexRuleList(lexindex)->getpCatList(i))
					 	 	{ // one of previous CatList is deleted caused by delete CatList[i];
							  for(j=i-1;j>=0;j--)
							  	{ if(getpLexRuleList(lexindex)->getpCatList(j)==originalcatlist) 
							  		{ getpLexRuleList(lexindex)->getpCatList(j)->setpCat(NULL); i=j; break; }
						  	  	}
							}
						  else getpLexRuleList(lexindex)->getpCatList(i)->setpCat(NULL);	// no other influence, let CatList[i]->m_pCat=NULL;
						}
					  originalcatlist=NULL;	// recollect originalcatlist;
			  		}
			  	}
			  delete m_ppLexRuleList[lexindex]; m_ppLexRuleList[lexindex]=NULL;
			  setpLexRuleList(lexindex, lexrule);	// replace LexRuleList[lexindex] with lexrule;
			  
			  updLTMem();	// update lexical rule list, category list and syntactic rule; 
		  	}
		}
	else
		{ // first, check if lexrule is already in LexRuleList;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(*(getpLexRuleList(i))==*lexrule) break;	// check value;
		  	}
		  if(i==getNumLexRule())
		  	{ // this is a new lexical rule;
		  	  numnewlex=getNumLexRule()+1;
		  	  lexrulelisttemp=new CLexRule * [numnewlex]; assert(lexrulelisttemp!=NULL);
			  for(i=0;i<numnewlex;i++)
			  	lexrulelisttemp[i]=NULL;
		  	  for(i=0;i<numnewlex-1;i++)
		  	  	lexrulelisttemp[i]=getpLexRuleList(i);
		  	  lexrulelisttemp[numnewlex-1]=lexrule;
		  	  // delete original LexRuleList;
		  	  delete [] m_ppLexRuleList; m_ppLexRuleList=NULL;
		  	  m_nNumLexRule=0;
		  	  // copy lexrulelisttemp to LexRuleList;
		  	  m_nNumLexRule=numnewlex; m_ppLexRuleList=lexrulelisttemp;
		  	  lexrulelisttemp=NULL;	// recollect lexrulelisttemp;
		  	}		  	
		}
}

void CLTMem::MergeCat(int cond, CCat *&cat)
{ // merge categories;
	assert((cond==1)||(cond==2)); assert(cat!=NULL);
	int i, j, k, m;
	int catindex, sucInLex;
	CCat **catlisttemp=NULL;
	int numnewcat;
	double avgcombstr, combstr, smallcombstr;
	CLexRule *lexinCat=NULL; 
	CSynRule *syninCat=NULL;
	
	// check categories that can be merged;
	for(i=0;i<getNumCat();i++)
		{ if(*(getpCatList(i))==*cat)
  			{ // value same, merge m_ppLexRule and m_ppSynRule;
		  	  // merge m_ppLexRule;
  		  	  for(j=0;j<cat->getLexNum();j++)
  		   	 	{ lexinCat=cat->getpLexRule(j);
				  for(k=0;k<getpCatList(i)->getLexNum();k++)
	    		  	{ if(*lexinCat==*(getpCatList(i)->getpLexRule(k))) break;
	    		  	}
	    		  if(k==getpCatList(i)->getLexNum())
		    	  	{ // lexinCat not in CatList[i]->m_ppLexRule;
		    	  	  for(m=0;m<lexinCat->getCatNum();m++)
		    	  	  	{ if(lexinCat->getpCatList(m)->getpCat()==cat) { lexinCat->getpCatList(m)->setpCat(getpCatList(i)); break; }
		    	  	  	}
		    	  	  sucInLex=0; getpCatList(i)->InLex(lexinCat, &sucInLex);	// this insertion will always be successful; 		  			    	  	  
		    	  	}		  		  	  	  
		    	  else
		    	  	{ // lexinCat in both CatList[i]->m_ppLexRule and cat->m_ppLexRule;
		    	  	  // adjust lexinCat's CatList;
		    	  	  for(m=0;m<lexinCat->getCatNum();m++)
		    	  	  	{ if(lexinCat->getpCatList(m)->getpCat()==cat) { lexinCat->setpCatList(m, NULL, 0.0, -1); break; }
		    		  	}
		    	  	}
		    	  cat->setpLexRule(j, NULL);	// cat->getpLexRule[j] is not in cat anymore;
		    	  lexinCat=NULL;	// recollect lexinCat;
		    	}
	  		  // update CatList[i]'s m_ppLexRule;
		  	  for(j=0;j<getpCatList(i)->getLexNum();j++)
		  	  	getpCatList(i)->getpLexRule(j)->updLexRule(3);

		  	  // merge m_ppSynRule;
		  	  for(j=0;j<cat->getSynNum();j++)
		  	  	{ syninCat=cat->getpSynRule(j);
		  	  	  for(k=0;k<getpCatList(i)->getSynNum();k++)
		  	  	  	{ if(syninCat==getpCatList(i)->getpSynRule(k)) break;		  		  	  	  		
		  	  	  	}
		  	  	  if(k==getpCatList(i)->getSynNum())
		  	  	  	{ // syninCat not in CatList[i]->m_ppSynRule;
		  	  	  	  for(m=0;m<syninCat->getNumCatRelated();m++)
		  	  	  	  	{ if(syninCat->getpCat(m)==cat) { syninCat->setpCat(m, getpCatList(i)); break; }		  		  	  	  	  		
		  	  	  	  	}
		  	  	  	  getpCatList(i)->InSyn(syninCat);	  			  	  	  	  
		  	  	  	}
		  	  	  cat->setpSynRule(j, NULL);	// cat->getpSynRule(j) is not in cat anymore;
		  	  	  syninCat=NULL;	// recollect syninCat;
		  	  	}
	  			  	  
 		  	  // update cat;
	  		  cat->updCat(1); 
  		  	  delete cat; cat=NULL;	// delete current cat;
		  	  cat=getpCatList(i);	// for merge, let cat equal to the merged cat (CatList[i]);
		  	  break;
  			}
		}		  	
 	  if(i!=getNumCat()) updLTMem();	// cat (new or extent in CatList) merged to another category in CatList;
 	  else
	  	{ if(cond==1)
 	  		{ // the CatList is full, randomly select a cat with smallest average assowei to replace;
		  	  smallcombstr=2*getNeuAssoWei();
			  for(i=0;i<getNumCat();i++)
			  	{ avgcombstr=0.0; 
			  	  for(j=0;j<getpCatList(i)->getLexNum();j++)
			  		{ lexinCat=getpCatList(i)->getpLexRule(j);
					  combstr=0.0;
					  if(getpCatList(i)->getSynNum()==0) combstr=(lexinCat->getLexStr())*getNeuAssoWei()*getNeuSynStr();
					  else
					  	{ for(k=0;k<getpCatList(i)->getSynNum();k++)
					  		{ combstr+=(lexinCat->getLexStr())*(getpCatList(i)->getpSynRule(k)->getSynStr());
					  		}
					  	  combstr=combstr/(double)(getpCatList(i)->getSynNum());
					  	}
					  avgcombstr+=combstr;
					  lexinCat=NULL;	// recollect lexinCat;
			  		}
			  	  avgcombstr=avgcombstr/(double)(getpCatList(i)->getLexNum());
			  	  if(FLOAT_SM_EQ(avgcombstr, smallcombstr)) smallcombstr=avgcombstr;
			  	}				  
			  do{ do{ catindex=(int)(Rand0_1*getNumCat());
			  	  }while(catindex==getNumCat());
			  	  avgcombstr=0.0; 
			  	  for(j=0;j<getpCatList(catindex)->getLexNum();j++)
			  		{ lexinCat=getpCatList(catindex)->getpLexRule(j);
					  combstr=0.0;
					  if(getpCatList(catindex)->getSynNum()==0) combstr=(lexinCat->getLexStr())*getNeuAssoWei()*getNeuSynStr();
					  else
					  	{ for(k=0;k<getpCatList(catindex)->getSynNum();k++)
					  		{ combstr+=(lexinCat->getLexStr())*(getpCatList(catindex)->getpSynRule(k)->getSynStr());
					  		}
					  	  combstr=combstr/(double)(getpCatList(catindex)->getSynNum());
					  	}
					  avgcombstr+=combstr;
					  lexinCat=NULL;	// recollect lexinCat;
			  		}
			  	  avgcombstr=avgcombstr/(double)(getpCatList(catindex)->getLexNum());
			  }while(FLOAT_NE(avgcombstr, smallcombstr));
			  // update CatList[catindex]'s rules;
			  if(getpCatList(catindex)->getLexNum()!=0)
			  	{ for(i=0;i<getpCatList(catindex)->getLexNum();i++)
			  		getpCatList(catindex)->getpLexRule(i)->AdjLex_Cat(getpCatList(catindex));
				}
			  if(getpCatList(catindex)->getSynNum()!=0)
			  	{ for(i=0;i<getpCatList(catindex)->getSynNum();i++)
			  		getpCatList(catindex)->getpSynRule(i)->AdjSyn_Cat(getpCatList(catindex));
				}
			  delete m_ppCatList[catindex]; m_ppCatList[catindex]=NULL;
			  setpCatList(catindex, cat);	// replace CatList[catindex] with cat;				  
			  
			  updLTMem();	// update lexical rule list, category list and syntactic rule; 
		  	}
	  	  else if(cond==2)
	  		{ // the CatList is not full, insert cat as a new cat;
			  numnewcat=getNumCat()+1;
			  catlisttemp=new CCat * [numnewcat]; assert(catlisttemp!=NULL);
			  for(i=0;i<numnewcat;i++)
			  	catlisttemp[i]=NULL;
			  for(i=0;i<numnewcat-1;i++)
			  	catlisttemp[i]=getpCatList(i);
			  catlisttemp[numnewcat-1]=cat;
			  // delete original CatList;
			  delete [] m_ppCatList; m_ppCatList=NULL;
			  m_nNumCat=0;
			  // copy catlisttemp to CatList;
			  m_nNumCat=numnewcat; m_ppCatList=catlisttemp;
			  catlisttemp=NULL;	// recollect catlisttemp;
	  		}
		}
}

void CLTMem::InCategory(CCat *&cat)
{ // insert cat into CatList;
	assert(cat!=NULL);
	int i;
	
	updLTMem();	// before insert anything, updLTMem first in case any InCat, InLex or InSyn function of each rule delete some lexical rule/category/syntactic rule;, 
	
	if(getNumCat()==0)
		{ m_nNumCat++;
		  m_ppCatList=new CCat * [getNumCat()]; assert(m_ppCatList!=NULL);
		  m_ppCatList[0]=NULL; setpCatList(0, cat);
		}
	else if(getNumCat()==getMaxCat())
		{ // first, check if cat is already in CatList;
		  for(i=0;i<getNumCat();i++)
		  	{ if(getpCatList(i)==cat) break;	// check address same category;
		  	}
		  if(i==getNumCat()) MergeCat(1, cat);		  
		}
	else
		{ // first, check if cat is already in CatList;
		  for(i=0;i<getNumCat();i++)
		  	{ if(getpCatList(i)==cat) break;	// check address same category;
		  	}
		  if(i==getNumCat()) MergeCat(2, cat);
		}
}

void CLTMem::MergeSyn(int cond, CSynRule *&synrule, int *type)
{ // merge syntactic rules;
	assert((cond==1)||(cond==2)); assert(synrule!=NULL);
	int i, j, k, m;
	int synindex, sucInLex;
	CSynRule **synrulelisttemp=NULL;
	int numnewsyn;
	CCat *catinSyn=NULL;
	int sametype;
	double synstr;
	CLexRule *lexinCat=NULL;
	CSynRule *syninCat=NULL;

	// check syntactic rule that can be merged;
	for(i=0;i<getNumSynRule();i++)
		{ sametype=(*getpSynRuleList(i)==*synrule);
 	 	  if((sametype==1)||(sametype==2))
 		  	{ // value same, merge SynRuleList[i] and synrule;
	 	  	  // merge m_ppCats;
 		  	  if(sametype==1)
 		  	  	{ *type=1;	// normal same;
 		  	  	  // merge SynRuleList[i]->Cats[0] with synrule->Cats[0];
				  if(getpSynRuleList(i)->getpCat(0)!=synrule->getpCat(0))
 		  	  	  	{ // address different, merge!
					  catinSyn=synrule->getpCat(0);
 		  	  	  	  for(j=0;j<catinSyn->getLexNum();j++)
 		  	  			{ lexinCat=catinSyn->getpLexRule(j);
 		  	  	  		  for(k=0;k<getpSynRuleList(i)->getpCat(0)->getLexNum();k++)
 		  	  	  			{ if(*lexinCat==*(getpSynRuleList(i)->getpCat(0)->getpLexRule(k))) break;
 		  	  	  			}
 		  	  	  		  if(k==getpSynRuleList(i)->getpCat(0)->getLexNum())
 		  	  	  			{ // lexinCat not in SynRuleList[i]->getpCat(0)->LexRule;
 		  	  	  	  		  for(m=0;m<lexinCat->getCatNum();m++)
 		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->getpCatList(m)->setpCat(getpSynRuleList(i)->getpCat(0)); break; }
		  	  	  	  			}
 		  	  	  	  		  sucInLex=0; getpSynRuleList(i)->getpCat(0)->InLex(lexinCat, &sucInLex);	// this insertion will always be successful;	
		  	  	  			}
		  	  	  		  else
		  	  	  			{ // lexinCat in both SynRuleList[i]->getpCat(0)->LexRule and catinSyn->LexRule;
		  	  	  	  		  // adjust lexinCat's CatList;
					  		  for(m=0;m<lexinCat->getCatNum();m++)
		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->setpCatList(m, NULL, 0.0, -1); break; }
		  	  		  			}
		  	  	  			}
		  	  	  		  catinSyn->setpLexRule(j, NULL);	// catinSyn->getpLexRule(j) is not in catinSyn anymore;
					  	  lexinCat=NULL;	// recollect lexinCat;
		  	  			}
		  	  	  	  // adjust SynRuleList[i]->getpCat[0]'s LexRule;
		  	  	  	  for(j=0;j<getpSynRuleList(i)->getpCat(0)->getLexNum();j++)
		  	  	  	  	getpSynRuleList(i)->getpCat(0)->getpLexRule(j)->updLexRule(3);	

		  	  	  	  // merge SynRule;
					  for(j=0;j<catinSyn->getSynNum();j++)
					  	{ syninCat=catinSyn->getpSynRule(j);
						  if(syninCat!=synrule)
						  	{ for(m=0;m<getpSynRuleList(i)->getpCat(0)->getSynNum();m++)
						  		{ if(syninCat==getpSynRuleList(i)->getpCat(0)->getpSynRule(m)) break;
						  		}
						  	  if(m==getpSynRuleList(i)->getpCat(0)->getSynNum())
						  		{ // syninCat not in SynRuleList[i]->getpCat(0)'s SynRule;
						  	  	  for(m=0;m<syninCat->getNumCatRelated();m++)
					  	  			{ if(syninCat->getpCat(m)==catinSyn) { syninCat->setpCat(m, getpSynRuleList(i)->getpCat(0)); break; }
					  	  			}
						  	  	  getpSynRuleList(i)->getpCat(0)->InSyn(syninCat);								  	  	  
					  			}
						  	}
						  catinSyn->setpSynRule(j, NULL);	// catinSyn->getpSynRule(j) is not in catinSyn anymore;
						  syninCat=NULL;	// recollect syninCat;
					  	}
							  
					  // update catinSyn;
					  catinSyn->updCat(1);	// synrule->m_ppCats[0] is deleted in updLTMem();
  		  	  	  	  catinSyn=NULL;	// recollect catinSyn;

  		  	  	  	  synrule->setpCat(0, NULL);
  		  	  	  	}
						  
				  // merge SynRuleList[i]->Cats[1] with synrule->Cats[1];
				  if(getpSynRuleList(i)->getpCat(1)!=synrule->getpCat(1))
				  	{ // address different, merge!
					  catinSyn=synrule->getpCat(1);
  		  	  	  	  for(j=0;j<catinSyn->getLexNum();j++)
  		  	  			{ lexinCat=catinSyn->getpLexRule(j);
  		  	  	  		  for(k=0;k<getpSynRuleList(i)->getpCat(1)->getLexNum();k++)
  		  	  	  			{ if(*lexinCat==*(getpSynRuleList(i)->getpCat(1)->getpLexRule(k))) break;
  		  	  	  			}
  		  	  	  		  if(k==getpSynRuleList(i)->getpCat(1)->getLexNum())
  		  	  	  			{ // lexinCat not in SynRuleList[i]->getpCat(0)->LexRule;
  		  	  	  	  		  for(m=0;m<lexinCat->getCatNum();m++)
  		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->getpCatList(m)->setpCat(getpSynRuleList(i)->getpCat(1)); break; }
  		  	  	  	  			}
  		  	  	  	  		  sucInLex=0; getpSynRuleList(i)->getpCat(1)->InLex(lexinCat, &sucInLex);	// this insertion will always be successful;		  		  	  	  	  		  
  		  	  	  			}
  		  	  	  		  else
  		  	  	  			{ // lexinCat in both SynRuleList[i]->getpCat(0)->LexRule and catinSyn->LexRule;
  		  	  	  	  		  // adjust lexinCat's CatList;
					  		  for(m=0;m<lexinCat->getCatNum();m++)
  		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->setpCatList(m, NULL, 0.0, -1); break; }
  		  	  		  			}
  		  	  	  			}
  		  	  	  		  catinSyn->setpLexRule(j, NULL);	// catinSyn->getpLexRule(j) is not in catinSyn anymore;
  		  	  	  		  lexinCat=NULL;	// recollect lexinCat;
  		  	  			}
  		  	  	  	  // adjust SynRuleList[i]->getpCat[1]'s LexRule;
  		  	  	  	  for(j=0;j<getpSynRuleList(i)->getpCat(1)->getLexNum();j++)
  		  	  	  	  	getpSynRuleList(i)->getpCat(1)->getpLexRule(j)->updLexRule(3);	

		  	  	  	  // merge m_ppSynRule;
					  for(j=0;j<catinSyn->getSynNum();j++)
					  	{ syninCat=catinSyn->getpSynRule(j);
						  if(syninCat!=synrule)
						  	{ for(m=0;m<getpSynRuleList(i)->getpCat(1)->getSynNum();m++)
						  		{ if(syninCat==getpSynRuleList(i)->getpCat(1)->getpSynRule(m)) break;
						  		}
						  	  if(m==getpSynRuleList(i)->getpCat(1)->getSynNum())
						  		{ // syninCat not in SynRuleList[i]->getpCat(1)'s SynRule;
						  	  	  for(m=0;m<syninCat->getNumCatRelated();m++)
					  	  			{ if(syninCat->getpCat(m)==catinSyn) { syninCat->setpCat(m, getpSynRuleList(i)->getpCat(1)); break; }
					  	  			}
						  	  	  getpSynRuleList(i)->getpCat(1)->InSyn(syninCat);								  	  	  
					  			}
						  	}								  
						  catinSyn->setpSynRule(j, NULL);	// catinSyn->getpSynRule(j) is not in catinSyn anymore;
						  syninCat=NULL;	// recollect syninCat;
					  	}
							  
		  	  		  // update catinSyn;
					  catinSyn->updCat(1);	// synrule->m_ppCat[1] is deleted in updLTMem();
  		  	  	  	  catinSyn=NULL;	// recollect catinSyn;

 		  	  	  	  synrule->setpCat(1, NULL);
				  	}	

				  // update synrule;
			  	  synrule->updSynRule(2);
				  delete synrule; synrule=NULL;	// delete current synrule;
				  synrule=getpSynRuleList(i);	// for merged synrule, let synrule equal to the merged synrule (SynRuleList[i]);
				}
  		  	  else if(sametype==2)
  		  	  	{ *type=2;	// reverse same;
				  // merge SynRuleList[i]->Cats[0] with synrule->Cats[1];
				  if(getpSynRuleList(i)->getpCat(0)!=synrule->getpCat(1))
  		  	  	  	{ // address different, merge!
  		  	  	  	  catinSyn=synrule->getpCat(1);
  		  	  	  	  for(j=0;j<catinSyn->getLexNum();j++)
  		  	  			{ lexinCat=catinSyn->getpLexRule(j);
  		  	  	  		  for(k=0;k<getpSynRuleList(i)->getpCat(0)->getLexNum();k++)
  		  	  	  			{ if(*lexinCat==*(getpSynRuleList(i)->getpCat(0)->getpLexRule(k))) break;
  		  	  	  			}
  		  	  	  		  if(k==getpSynRuleList(i)->getpCat(0)->getLexNum())
  		  	  	  			{ // lexinCat not in SynRuleList[i]->getpCat(0)->LexRule;
  		  	  	  	  		  for(m=0;m<lexinCat->getCatNum();m++)
  		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->getpCatList(m)->setpCat(getpSynRuleList(i)->getpCat(0)); break; }
  		  	  	  	  			}
  		  	  	  	  		  sucInLex=0; getpSynRuleList(i)->getpCat(0)->InLex(lexinCat, &sucInLex);	// this insertion will always be successful;		  		  	  	  	  		  
  		  	  	  			}
  		  	  	  		  else
  		  	  	  			{ // lexinCat in both SynRuleList[i]->getpCat(0)->LexRule and catinSyn->LexRule;
  		  	  	  	  		  // adjust lexinCat's CatList;
					  		  for(m=0;m<lexinCat->getCatNum();m++)
  		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->setpCatList(m, NULL, 0.0, -1); break; }
  		  	  		  			}						  		  
  		  	  	  			}
  		  	  	  		  catinSyn->setpLexRule(j, NULL);	// catinSyn->getpLexRule(j) is not in catinSyn anymore;
  		  	  	  		  lexinCat=NULL;	// recollect lexinCat;
  		  	  			}
  		  	  	  	  // adjust SynRuleList[i]->getpCat[0]'s LexRule;
  		  	  	  	  for(j=0;j<getpSynRuleList(i)->getpCat(0)->getLexNum();j++)
  		  	  	  	  	getpSynRuleList(i)->getpCat(0)->getpLexRule(j)->updLexRule(3);	

 		  	  	  	  // merge m_ppSynRule;
					  for(j=0;j<catinSyn->getSynNum();j++)
					  	{ syninCat=catinSyn->getpSynRule(j);
						  if(syninCat!=synrule)
						  	{ for(m=0;m<getpSynRuleList(i)->getpCat(0)->getSynNum();m++)
						  		{ if(syninCat==getpSynRuleList(i)->getpCat(0)->getpSynRule(m)) break;
						  		}
						  	  if(m==getpSynRuleList(i)->getpCat(0)->getSynNum())
						  		{ // syninCat not in SynRuleList[i]->getpCat(0)'s SynRule;
						  	  	  for(m=0;m<syninCat->getNumCatRelated();m++)
					  	  			{ if(syninCat->getpCat(m)==catinSyn) { syninCat->setpCat(m, getpSynRuleList(i)->getpCat(0)); break; }
					  	  			}
						  	  	  getpSynRuleList(i)->getpCat(0)->InSyn(syninCat);								  	  	  
					  			}
						  	}
						  catinSyn->setpSynRule(j, NULL);	// catinSyn->getpSynRule(j) is not in catinSyn anymore;
						  syninCat=NULL;	// recollect syninCat;
					  	}
							  
		  	  	  	  // update catinSyn;
					  catinSyn->updCat(1);	// synrule->m_ppCat[1] is deleted in updLTMem();
					  catinSyn=NULL;	// recollect catinSyn;

					  synrule->setpCat(1, NULL);
  		  	  	  	}	

 		  	  	  // merge SynRuleList[i]->Cats[1] with synrule->Cats[0];
				  if(getpSynRuleList(i)->getpCat(1)!=synrule->getpCat(0))
				  	{ // address different, merge!
					  catinSyn=synrule->getpCat(0);
		  	  	  	  for(j=0;j<catinSyn->getLexNum();j++)
		  	  			{ lexinCat=catinSyn->getpLexRule(j);
		  	  	  		  for(k=0;k<getpSynRuleList(i)->getpCat(1)->getLexNum();k++)
		  	  	  			{ if(*lexinCat==*(getpSynRuleList(i)->getpCat(1)->getpLexRule(k))) break;
		  	  	  			}
		  	  	  		  if(k==getpSynRuleList(i)->getpCat(1)->getLexNum())
		  	  	  			{ // lexinCat not in SynRuleList[i]->getpCat(1)->LexRule;
		  	  	  	  		  for(m=0;m<lexinCat->getCatNum();m++)
 		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->getpCatList(m)->setpCat(getpSynRuleList(i)->getpCat(1)); break; }
  		  	  	  	  		  	}
  		  	  	  	  		  sucInLex=0; getpSynRuleList(i)->getpCat(1)->InLex(lexinCat, &sucInLex);	// this insertion will always be successful;
  		  	  	  			}
  		  	  	  		  else
  		  	  	  			{ // lexinCat in both SynRuleList[i]->getpCat(1)->LexRule and catinSyn->LexRule;
  		  	  	  	  		  // adjust lexinCat's CatList;
					  		  for(m=0;m<lexinCat->getCatNum();m++)
  		  	  	  	  			{ if(lexinCat->getpCatList(m)->getpCat()==catinSyn) { lexinCat->setpCatList(m, NULL, 0.0, -1); break; }
  		  	  		  			}
  		  	  	  			}
  		  	  	  		  catinSyn->setpLexRule(j, NULL);	// catinSyn->getpLexRule(j) is not in catinSyn anymore;
					  	  lexinCat=NULL;	// recollect lexinCat;
  		  	  			}
  		  	  	  	  // adjust SynRuleList[i]->getpCat[1]'s LexRule;
  		  	  	  	  for(j=0;j<getpSynRuleList(i)->getpCat(1)->getLexNum();j++)
  		  	  	  	  	getpSynRuleList(i)->getpCat(1)->getpLexRule(j)->updLexRule(3);	

		  	  	  	  // merge SynRule;
					  for(j=0;j<catinSyn->getSynNum();j++)
					  	{ syninCat=catinSyn->getpSynRule(j);
						  if(syninCat!=synrule)
						  	{ for(m=0;m<getpSynRuleList(i)->getpCat(1)->getSynNum();m++)
						  		{ if(syninCat==getpSynRuleList(i)->getpCat(1)->getpSynRule(m)) break;
						  		}
						  	  if(m==getpSynRuleList(i)->getpCat(1)->getSynNum())
						  		{ // syninCat not in SynRuleList[i]->getpCat(1)'s SynRule;
						  	  	  for(m=0;m<syninCat->getNumCatRelated();m++)
					  	  			{ if(syninCat->getpCat(m)==catinSyn) { syninCat->setpCat(m, getpSynRuleList(i)->getpCat(1)); break; }
					  	  			}
						  	  	  getpSynRuleList(i)->getpCat(1)->InSyn(syninCat);								  	  	  
					  			}
						  	}
						  catinSyn->setpSynRule(j, NULL);	// catinSyn->getpSynRule(j) is not in catinSyn anymore;
				 		  syninCat=NULL;	// recollect syninCat;
					  	}
							  
		  	  	  	  // update catinSyn;
				  	  catinSyn->updCat(1);	// synrule->m_ppCat[0] is deleted in updLTMem();
				  	  catinSyn=NULL;	// recollect catinSyn;

				  	  synrule->setpCat(0, NULL);
				  	}	

				  // update synrule;
			  	  synrule->updSynRule(2); 
			  	  delete synrule; synrule=NULL;	// delete current synrule;
				  synrule=getpSynRuleList(i);	// for merged synrule, let synrule equal to the merged synrule (SynRuleList[i]);
				}
  		  	  break;
  		  	}
  		}
  	  if(i!=getNumSynRule()) updLTMem();	// synrule(new or extent in SynRuleList) merged to another syntactic rule in SynRuleList;
  	  else
	  	{ *type=0;	// no merge;
	  	  if(cond==1)
	  	  	{ // the SynRuleList is full, randomly select a syntactic rule with smallest strength to replace;
		  	  synstr=getpSynRuleList(0)->getSynStr();
		  	  for(i=0;i<getNumSynRule();i++)
			  	{ if(FLOAT_SM_EQ(getpSynRuleList(i)->getSynStr(), synstr)) synstr=getpSynRuleList(i)->getSynStr();
			  	}
			  do{ synindex=(int)(Rand0_1*getNumSynRule());
			  }while((synindex==getNumSynRule())||(FLOAT_NE(getpSynRuleList(synindex)->getSynStr(), synstr)));
			  // update SynRuleList[synindex]'s syntactic rule;
			  for(i=0;i<getpSynRuleList(synindex)->getNumCatRelated();i++)
			  	getpSynRuleList(synindex)->getpCat(i)->AdjCat_Syn(getpSynRuleList(synindex));
			  delete m_ppSynRuleList[synindex]; m_ppSynRuleList[synindex]=NULL;
			  setpSynRuleList(synindex, synrule);	// replace SynRuleList[synindex] with synrule;				  
			  
			  updLTMem();	// update lexical rule list, category list and syntactic rule; 
		  	}
		  else if(cond==2)
		  	{ // the SynRuleList is not fulle, insert synrule as a new synrule;	
		  	  numnewsyn=getNumSynRule()+1;
		  	  synrulelisttemp=new CSynRule * [numnewsyn]; assert(synrulelisttemp!=NULL);
			  for(i=0;i<numnewsyn;i++)
			  	synrulelisttemp[i]=NULL;
		  	  for(i=0;i<numnewsyn-1;i++)
		  	  	synrulelisttemp[i]=getpSynRuleList(i);
		  	  synrulelisttemp[numnewsyn-1]=synrule;
		  	  // delete original SynRuleList;
		  	  delete [] m_ppSynRuleList; m_ppSynRuleList=NULL;
		  	  m_nNumSynRule=0;
		  	  // copy synrulelisttemp to SynRuleList;
		  	  m_nNumSynRule=numnewsyn; m_ppSynRuleList=synrulelisttemp;
		  	  synrulelisttemp=NULL;	// recollect synrulelisttemp;		  	  
		  	}
  	  	}
}

void CLTMem::InSynRule(CSynRule *&synrule, int *type)
{ // insert synrule into SynRuleList;
	assert(synrule!=NULL);
	int i;
	
	updLTMem();	// before insert anything, updLTMem first in case any InCat, InLex or InSyn function of each rule delete some lexical rule/category/syntactic rule;, 
	
	if(getNumSynRule()==0)
		{ m_nNumSynRule++;
		  m_ppSynRuleList=new CSynRule * [getNumSynRule()]; assert(m_ppSynRuleList!=NULL);
		  m_ppSynRuleList[0]=NULL; setpSynRuleList(0, synrule);
		}
	else if(getNumSynRule()==getMaxSynRule())
		{ // first, check if synrule is already in SynRuleList;
		  for(i=0;i<getNumSynRule();i++)
		  	{ if(getpSynRuleList(i)==synrule) break;	// check address same syntactic rule;
		  	}
		  if(i==getNumSynRule()) MergeSyn(1, synrule, type);
		  else *type=0;	// no merge;
		}
	else
		{ // first, check if synrule is already in SynRuleList;
		  for(i=0;i<getNumSynRule();i++)
		  	{ if(getpSynRuleList(i)==synrule) break;	// check address same syntactic rule;
		  	}
		  if(i==getNumSynRule()) MergeSyn(2, synrule, type);
		  else *type=0;	// no merge;
		}
}

bool CLTMem::chk2SideMeanUtter(int type, int subtype, CMeanUtter *MU, CLexRule *lexrule, CSemSpace *semspace)
{ // check MU and lexrule's meaning/utterance part match or not;
  // type=1, production/learn category part;
	// subtype=1, holistic rule;
	// subtype=2, Ag rule;
	// subtype=3, Pred rule;
	// subtype=4, Pat rule;
	// subtype=5, AgPred phrase;
	// subtype=6, AgPat phrase;
	// subtype=7, PredPat phrase;
  // type=2, perception part;
  	// subtype=1, holistic rule;
  	// subtype=2, Ag rule;
  	// subtype=3, Pred1 rule;
  	// subtype=4, Pred2 rule;
  	// subtype=5, Pat rule;
  	// subtype=6, AgPred phrase;
  	// subtype=7, AgPat phrase;
 	// subtype=8, PredPat phrase; 
    assert((MU!=NULL)&&(lexrule!=NULL)&&(semspace!=NULL));
  	assert(((type==1)&&(1<=subtype)&&(subtype<=7))||((type==2)&&(1<=subtype)&&(subtype<=8)));
  	int i, j;
  	int posAg=MU->getLengthSemRole();
	int posPred=MU->getLengthSem()+MU->getLengthSemRole();
	int posPat=2*(MU->getLengthSem())+MU->getLengthSemRole();
	int posPhra1=0;
	int posPhra2=MU->getLengthSem();
	int posPhra3=2*(MU->getLengthSem());
	int lenSemItem=MU->getLengthSemItem();
	int lenPhra=2*(MU->getLengthSem());
	bool value=0;
	
	if(type==1)
		{ // production/learn category part;
		  switch(subtype)
			{ case 1: // holistic rule; 
				 	if((lexrule->getLexTyp()==0)&&(*(lexrule->getpMeanUtter()->getpMean())==*(MU->getpMean()))) value=1;
					break;
			  case 2: // Ag rule;
			  		if(lexrule->getLexTyp()==1)
			  			{ for(i=0;i<lenSemItem;i++)
			  				{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posAg)!=MU->getpMean()->getElement(i+posAg))
			  					break;
			  				}
			  			  if(i==lenSemItem) value=1;
			  			}
			  		break;
			  case 3: // Pred rule;
			  		if(lexrule->getLexTyp()==2)
			  			{ for(i=0;i<lenSemItem;i++)
			  				{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posPred)!=MU->getpMean()->getElement(i+posPred))
			  					break;
			  				}
			  			  if(i==lenSemItem) value=1;
			  			}
			  		break;
			  case 4: // Pat rule;
			  		if(lexrule->getLexTyp()==1)
			  			{ for(i=0;i<lenSemItem;i++)
			  				{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posAg)!=MU->getpMean()->getElement(i+posPat))
			  					break;
			  				}
			  			  if(i==lenSemItem) value=1;
			  			}
			  		break;
			  case 5: // AgPred phrase;
					if((lexrule->getLexTyp()==3)||(lexrule->getLexTyp()==6))
						{ for(i=0;i<lenPhra;i++)
							{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posPhra1)!=MU->getpMean()->getElement(i+posPhra1))
								break;
							}
						  if(i==lenPhra) value=1;
						}
			  		break;
			  case 6: // AgPat phrase;
					if((lexrule->getLexTyp()==4)||(lexrule->getLexTyp()==7))
						{ for(i=0;i<(int)(_Half*lenPhra);i++)
							{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posPhra1)!=MU->getpMean()->getElement(i+posPhra1))
								break;
							}
						  for(j=0;j<(int)(_Half*lenPhra);j++)
						  	{ if(lexrule->getpMeanUtter()->getpMean()->getElement(j+posPhra3)!=MU->getpMean()->getElement(j+posPhra3))
						  		break;
						  	}
						  if((i==(int)(_Half*lenPhra))&&(j==(int)(_Half*lenPhra))) value=1;
						}
			  		break;
			  case 7: // PredPat phrase;
					if((lexrule->getLexTyp()==5)||(lexrule->getLexTyp()==8))
						{ for(i=0;i<lenPhra;i++)
							{ if(lexrule->getpMeanUtter()->getpMean()->getElement(i+posPhra2)!=MU->getpMean()->getElement(i+posPhra2))
								break;
							}
					 	  if(i==lenPhra) value=1;
						}
			  		break;
			  default: break;
			}
		}
	else if(type==2)
		{ // perception;
		  switch(subtype)
			{ case 1: // holistic rule; 
					if((lexrule->getLexTyp()==0)&&(*(lexrule->getpMeanUtter()->getpUtter())==*(MU->getpUtter()))) value=1; break;
			  case 2: // Ag rule;
			  		if(lexrule->getLexTyp()==1) value=1; break;
			  case 3: // Pred1 rule;
			  		if(lexrule->getLexTyp()==2)
			  			{ for(i=0;i<semspace->getNumSemPred1();i++)
			  				{ for(j=0;j<lenSemItem;j++)
			  			  		{ if(lexrule->getpMeanUtter()->getpMean()->getElement(j+posPred)!=semspace->getpSemPred(i)->getElement(j))
			  			  			break;
			  			  		}
			  				  if(j==lenSemItem) { value=1; break; }
			  			  	}
			  			}
			  		break;
			  case 4: // Pred2 rule;
			  		if(lexrule->getLexTyp()==2)
			  			{ for(i=semspace->getNumSemPred1();i<semspace->getNumSemPred();i++)
			  				{ for(j=0;j<lenSemItem;j++)
			  			  		{ if(lexrule->getpMeanUtter()->getpMean()->getElement(j+posPred)!=semspace->getpSemPred(i)->getElement(j))
			  			  			break;
			  			  		}
			  				  if(j==lenSemItem) { value=1; break; }
			  			  	}
			  			}
			  		break;
			  case 5: // Pat rule;
					if(lexrule->getLexTyp()==1) value=1; break;
			  case 6: // AgPred phrase;
					if((lexrule->getLexTyp()==3)||(lexrule->getLexTyp()==6)) value=1; break;
			  case 7: // AgPat phrase;
					if((lexrule->getLexTyp()==4)||(lexrule->getLexTyp()==7)) value=1; break;
			  case 8: // PredPat phrase;
					if((lexrule->getLexTyp()==5)||(lexrule->getLexTyp()==8)) value=1; break;
			  default: break;
			}
		}
	return value;
}

int CLTMem::ChkSynMatCat(CSynRule *syn1, CSynRule *syn2, CCat *cat1, CCat *cat2, CCat *cat3)
{ // check newSyn1, newSyn2's linking type;
  // return value: 0, incorrect;
  	// 1, syn1: cat1<->cat2, syn2: cat2<->cat3;
  	// 2, syn1: cat2<->cat3, syn2: cat1<->cat3;
  	// 3, syn1: cat1<->cat2, syn2: cat1<->cat3;
	assert((syn1!=NULL)&&(syn2!=NULL)); assert((cat1!=NULL)&&(cat2!=NULL)&&(cat3!=NULL));
  	int value;
	if((((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))||((syn1->getpCat(1)==cat1)&&(syn1->getpCat(0)==cat2)))&&(((syn2->getpCat(0)==cat2)&&(syn2->getpCat(1)==cat3))||((syn2->getpCat(1)==cat2)&&(syn2->getpCat(0)==cat3)))) value=1;
	else if((((syn1->getpCat(0)==cat2)&&(syn1->getpCat(1)==cat3))||((syn1->getpCat(1)==cat2)&&(syn1->getpCat(0)==cat3)))&&(((syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))||((syn2->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat3)))) value=2;
	else if((((syn1->getpCat(0)==cat1)&&(syn1->getpCat(1)==cat2))||((syn1->getpCat(1)==cat1)&&(syn1->getpCat(0)==cat2)))&&(((syn2->getpCat(0)==cat1)&&(syn2->getpCat(1)==cat3))||((syn2->getpCat(1)==cat1)&&(syn2->getpCat(0)==cat3)))) value=3;
	else value=0;
	assert(value!=0);
	return value;
}

void CLTMem::updRelaCatListSyn(RelaCatListSyn *newrelaCatListSyn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // update newrelaCatListSyn into relaCatListSyn;
	assert(newrelaCatListSyn!=NULL);
	int i;
	RelaCatListSyn **relaCatListSynTemp=NULL;
	int numnewrelaCatListSyn;

	if(*numRelaCatListSyn==0)
		{ // create new relaCatListSyn; 
		  (*numRelaCatListSyn)++;
		  relaCatListSyn=new RelaCatListSyn * [*numRelaCatListSyn]; assert(relaCatListSyn!=NULL);
		  relaCatListSyn[0]=newrelaCatListSyn;
		}
	else
		{ // no check whether newrelaCatListSyn is already in relaCatListSyn!
		  numnewrelaCatListSyn=(*numRelaCatListSyn)+1;	// increase the current number of relaCatListSyn;
		  relaCatListSynTemp=new RelaCatListSyn * [numnewrelaCatListSyn]; assert(relaCatListSynTemp!=NULL);
		  for(i=0;i<numnewrelaCatListSyn;i++)
		  	relaCatListSynTemp[i]=NULL;
		  for(i=0;i<numnewrelaCatListSyn-1;i++)
		  	relaCatListSynTemp[i]=relaCatListSyn[i];
		  relaCatListSynTemp[numnewrelaCatListSyn-1]=newrelaCatListSyn;
		  // delete original relaCatListSyn;
		  delete [] relaCatListSyn; relaCatListSyn=NULL;
		  *numRelaCatListSyn=0;
		  // copy relaCatListSynTemp to relaCatListSyn;
		  *numRelaCatListSyn=numnewrelaCatListSyn; relaCatListSyn=relaCatListSynTemp;
		  relaCatListSynTemp=NULL;	// recollect relaCatListSynTemp;
		}
}

void CLTMem::rec2Cat1Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CSynRule *syn12, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // according to consistency to decide 2 catlist and 1 syn rules to be chosen; proper=0, production; proper=1, perception;
	assert((proper==0)||(proper==1)); 
	RelaCatListSyn *newrelaCatListSyn=NULL;

	newrelaCatListSyn=new RelaCatListSyn; assert(newrelaCatListSyn!=NULL);
	newrelaCatListSyn->setComponent(proper, 2, 1, subtype, combwei, rule1CatList, rule2CatList, NULL, syn12, NULL, NULL);
	updRelaCatListSyn(newrelaCatListSyn, relaCatListSyn, numRelaCatListSyn);
}

void CLTMem::rec3Cat1Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // according to consistency to decide 3 catlist and 1 syn rules to be chosen; proper=0, production; proper=1, perception;
	assert((proper==0)||(proper==1));
	RelaCatListSyn *newrelaCatListSyn=NULL;

	newrelaCatListSyn=new RelaCatListSyn; assert(newrelaCatListSyn!=NULL);
	newrelaCatListSyn->setComponent(proper, 3, 1, subtype, combwei, rule1CatList, rule2CatList, rule3CatList, syn12, syn23, syn13);
	updRelaCatListSyn(newrelaCatListSyn, relaCatListSyn, numRelaCatListSyn);
}

void CLTMem::rec3Cat2Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // according to consistency to decide 3 catlist and 2 syn rules to be chosen; proper=0, production; proper=1, perception;
	assert((proper==0)||(proper==1)); assert((rule1CatList!=NULL)&&(rule2CatList!=NULL)&&(rule3CatList!=NULL));
	RelaCatListSyn *newrelaCatListSyn=NULL;

	newrelaCatListSyn=new RelaCatListSyn; assert(newrelaCatListSyn!=NULL);
	newrelaCatListSyn->setComponent(proper, 3, 2, subtype, combwei, rule1CatList, rule2CatList, rule3CatList, syn12, syn23, syn13);
	updRelaCatListSyn(newrelaCatListSyn, relaCatListSyn, numRelaCatListSyn);
}

void CLTMem::rec3Cat3Syn(int proper, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // according to consistency to decide 3 catlist and 3 syn rules to be chosen; proper=0, production; proper=1, perception;
  	assert((proper==0)||(proper==1)); assert((rule1CatList!=NULL)&&(rule2CatList!=NULL)&&(rule3CatList!=NULL)&&(syn12!=NULL)&&(syn23!=NULL)&&(syn13!=NULL));
	RelaCatListSyn *newrelaCatListSyn=NULL;
	double assowei12, assowei23, assowei13, combwei;
	
	// calculate combwei;
	assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*syn12->getSynStr(); 
	assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*syn23->getSynStr(); 
	assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*syn13->getSynStr();
	combwei=_Third*(assowei12+assowei23+assowei13);

	newrelaCatListSyn=new RelaCatListSyn; assert(newrelaCatListSyn!=NULL);
	newrelaCatListSyn->setComponent(proper, 3, 3, -1, combwei, rule1CatList, rule2CatList, rule3CatList, syn12, syn23, syn13);
	updRelaCatListSyn(newrelaCatListSyn, relaCatListSyn, numRelaCatListSyn);
}

void CLTMem::FindrelCatListSyn_Rela2Cat(RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12)
{ // find relaCatList with the biggest combstr; called by ChkRela2Cat
	int i, index;
	double combstrtemp;
	if((relaCatListSyn!=NULL)&&(*numRelaCatListSyn!=0))
		{ if(*numRelaCatListSyn==1) index=0;
		  else
		  	{ combstrtemp=0.0;
		  	  for(i=0;i<*numRelaCatListSyn;i++)
		  		{ if(FLOAT_BG_EQ(relaCatListSyn[i]->getCombStr(), combstrtemp)) combstrtemp=relaCatListSyn[i]->getCombStr();
		  		}
			  // check whether all relaCatListSyn[i]->m_dCombStr are equal;
			  for(i=0;i<*numRelaCatListSyn;i++)
			  	{ if(FLOAT_NE(relaCatListSyn[i]->getCombStr(), combstrtemp)) break;
			  	}
			  if(i==*numRelaCatListSyn)
			  	{ // all relaCatListSyn[i]->m_dCombStr are equal;
			  	  do{ index=(int)(Rand0_1*(*numRelaCatListSyn));
			  	  }while(index==*numRelaCatListSyn);
			  	}
			  else
			  	{ do{ index=(int)(Rand0_1*(*numRelaCatListSyn));
		  	  	}while((index==*numRelaCatListSyn)||(FLOAT_NE(relaCatListSyn[index]->getCombStr(), combstrtemp)));
		  		}
		  	}
		  catlist1=relaCatListSyn[index]->getpCatList1(); catlist2=relaCatListSyn[index]->getpCatList2();
		  syn12=relaCatListSyn[index]->getpSyn12();
		  
		  // release relaCatListSyn;
		  for(i=0;i<*numRelaCatListSyn;i++)
		  	{ delete relaCatListSyn[i]; relaCatListSyn[i]=NULL; }
		  delete [] relaCatListSyn; relaCatListSyn=NULL;
		  *numRelaCatListSyn=0;
		}
}

void CLTMem::FindrelCatListSyn_Rela3Cat(RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn, int *SubTyp, double *combWei, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13)
{ // find relaCatList with the biggest combstr; called by ChkRela3Cat
	int i, index;
	double combstrtemp;
	if((relaCatListSyn!=NULL)&&(*numRelaCatListSyn!=0))
		{ if(*numRelaCatListSyn==1) index=0;
		  else
		  	{ combstrtemp=0.0;
		  	  for(i=0;i<*numRelaCatListSyn;i++)
		  		{ if(FLOAT_BG_EQ(relaCatListSyn[i]->getCombStr(), combstrtemp)) combstrtemp=relaCatListSyn[i]->getCombStr();
		  		}
			  // check whether all relaCatListSyn[i]->m_dCombStr are equal;
			  for(i=0;i<*numRelaCatListSyn;i++)
			  	{ if(FLOAT_NE(relaCatListSyn[i]->getCombStr(), combstrtemp)) break;
			  	}
			  if(i==*numRelaCatListSyn)
			  	{ // all relaCatListSyn[i]->m_dCombStr are equal;
			  	  do{ index=(int)(Rand0_1*(*numRelaCatListSyn));
			  	  }while(index==*numRelaCatListSyn);
			  	}
			  else
			  	{ do{ index=(int)(Rand0_1*(*numRelaCatListSyn));
		  	  	  }while((index==*numRelaCatListSyn)||(FLOAT_NE(relaCatListSyn[index]->getCombStr(), combstrtemp)));
		  		}
		  	}
		  *SubTyp=relaCatListSyn[index]->getSubTyp(); *combWei=relaCatListSyn[index]->getCombStr();
		  catlist1=relaCatListSyn[index]->getpCatList1(); catlist2=relaCatListSyn[index]->getpCatList2(); catlist3=relaCatListSyn[index]->getpCatList3();
		  syn12=relaCatListSyn[index]->getpSyn12(); syn23=relaCatListSyn[index]->getpSyn23(); syn13=relaCatListSyn[index]->getpSyn13();

		  // release relaCatListSyn;
		  for(i=0;i<*numRelaCatListSyn;i++)
		  	{ delete relaCatListSyn[i]; relaCatListSyn[i]=NULL; }
		  delete [] relaCatListSyn; relaCatListSyn=NULL;
		  *numRelaCatListSyn=0;
		}
}

// production part;
// random creation of rules/categories/syntax;
void CLTMem::RandCrtHolist(int meantype, CLexRule *&newHolist, CCat *&newHolistCat, CMeanUtter *meanutter)
{ // randomly create holistic rule and holistic category for meanutter->m_pMean;
  // store this newly created rule into LTMem and IMMem, and update category/syntax; 
  // meantype=1, "Predicate<Agent>" meaning's utterance; 2, "Predicate<Agent, Patient>" meaning's utterance;
	assert((meantype==1)||(meantype==2)); assert((newHolist==NULL)&&(newHolistCat==NULL)); assert(meanutter!=NULL);
  	int i;
	int sucInLex;
  	CMeanUtter *newMU=NULL;
  	
  	// newMU of the holistic rule;
  	newMU=new CMeanUtter; assert(newMU!=NULL);
  	newMU->setpMean(meanutter->getpMean());
  	newMU->CrtUtter(meantype);

  	// new holistic rule;
  	newHolist=new CLexRule; assert(newHolist!=NULL);
	// meanutter part;
	newHolist->setpMeanUtter(newMU);
  	newHolist->setLexTyp(0);	// holistic rule;
  	newHolist->setLexStr(newHolist->getInitLexRuleStr());
	// cat part;
  	// search the m_pLTMem's catlist to find the holistic category's address;
	for(i=0;i<getNumCat();i++)
		{ if(getpCatList(i)->getThemRole()==0) { newHolistCat=getpCatList(i); break; }
		}
	if(i==getNumCat())
		{ // no holistic category;
		  newHolistCat=new CCat; assert(newHolistCat!=NULL);
		  newHolistCat->setThemRole(0);	// holistic rule;
		}	
	// link newHolist with newHolistCat;
	newHolist->InCat(newHolistCat); 
	sucInLex=0; newHolistCat->InLex(newHolist, &sucInLex);	// this insertion will always be successful;
	delete newMU; newMU=NULL;	// delete newMU;
}

int CLTMem::ChkMeanType1(int type, CMeanUtter *meanutter, CSemSpace *semspace)
{ // check whether meanutter ("Predicate<Agent>") can be expressed by various rules, and update meantype of semtype[index]->m_pIntgMean; 
  // type=1, check holistic and compositional rules; type=2, only check compositional rules; type=3, only check holistic rule;
	assert((type==1)||(type==2)||(type==3)); assert((meanutter!=NULL)&&(semspace!=NULL));
	int i;
  	int numHolist, numAg, numPred;
	int meantype=0;

	if(type==1)
		{ numHolist=numAg=numPred=0;
  		  if(getNumLexRule()!=0)
			{ for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1) numHolist++;	// check holistic rules;  		
			  	  if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1) numAg++;	// check Ag rules;
			  	  if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1) numPred++;	// check Pred rules;	  		
			  	}
			}  	
		  if(numHolist!=0) meantype=1;	// fully expressable meanings;
  		  else
  			{ if((numAg!=0)&&(numPred!=0)) meantype=1;	// fully expressable meanings;
  		  	  else if(((numAg!=0)&&(numPred==0))||((numAg==0)&&(numPred!=0))) meantype=3;	// 1 meaning uncertain "Predicate<Agent>" meaning;
  		  	  else meantype=5;	// totally unexpressable meanings;
  			}
		}
	else if(type==2)
		{ numAg=numPred=0;
		  if(getNumLexRule()!=0)
		  	{ for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1) numAg++;	// check Ag rules;
			  	  if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1) numPred++;	// check Pred rules;	  		
			  	}
			}
		  if((numAg!=0)&&(numPred!=0)) meantype=1;	// fully expressable meanings;
  		  else if(((numAg!=0)&&(numPred==0))||((numAg==0)&&(numPred!=0))) meantype=3;	// 1 meaning uncertain "Predicate<Agent>" meaning;
  		  else meantype=5;	// totally unexpressable meanings;
  		}
	else if(type==3)
		{ numHolist=0;
		  if(getNumLexRule()!=0)
			{ for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1) numHolist++;	// check holistic rules;  		
		  		}
		  	}
		  if(numHolist!=0) meantype=1;	// fully expressable meanings;
		  else meantype=5;	// totally unexpressable meanings;
		}
	return meantype;
}

int CLTMem::ChkMeanType2(int type, CMeanUtter *meanutter, CSemSpace *semspace)
{ // check whether meanutter ("Predicate<Agent, Patient>") can be expressed by various rules; 
  // type=1, check holistic and compositional rules; 2, only check compositional rules; 3, only check holistic rule;
	assert((type==1)||(type==2)||(type==3)); assert((meanutter!=NULL)&&(semspace!=NULL));
	int i;
  	int numHolist, numAg, numPred, numPat, numAgPred, numAgPat, numPredPat;
	int meantype=0;
	
	if(type==1)
		{ numHolist=numAg=numPred=numPat=numAgPred=numAgPat=numPredPat=0;
		  if(getNumLexRule()!=0)
			{ for(i=0;i<getNumLexRule();i++)
		  		{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1) numHolist++;	// check Holistic rules; 
		  		  if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1) numAg++;	// check Ag rules;
		  		  if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1) numPred++;	// check Pred rules;
			  	  if(chk2SideMeanUtter(1, 4, meanutter, getpLexRuleList(i), semspace)==1) numPat++;	// check Pat rules;
		  		  if(chk2SideMeanUtter(1, 5, meanutter, getpLexRuleList(i), semspace)==1) numAgPred++;	// check AgPred rules;
		  		  if(chk2SideMeanUtter(1, 6, meanutter, getpLexRuleList(i), semspace)==1) numAgPat++;	// check AgPat rules;
		  		  if(chk2SideMeanUtter(1, 7, meanutter, getpLexRuleList(i), semspace)==1) numPredPat++;	// check PredPat rules;	  		  
				}
			}
		  if(numHolist!=0) meantype=1;	// fully expressable meaning;
		  else
  			{ // according to different conditions to decide!
		  	  if(((numAg!=0)&&(numPred!=0)&&(numPat!=0))||((numAg!=0)&&(numPredPat!=0))||((numPred!=0)&&(numAgPat!=0))||((numPat!=0)&&(numAgPred!=0)))
		 	 	meantype=1;	// fully expressable meaning;
		  	  else if((((numAg!=0)&&(numPred!=0)&&(numPat==0))||((numAg!=0)&&(numPred==0)&&(numPat!=0))||((numAg==0)&&(numPred!=0)&&(numPat!=0)))||(numAgPred!=0)||(numAgPat!=0)||(numPredPat!=0))
				meantype=2;	// 1 meaning uncertain "Predicate<Agent, Patient>" meanings;
		  	  else if(((numAg!=0)&&(numPred==0)&&(numPat==0)&&(numAgPred==0)&&(numAgPat==0))||((numAg==0)&&(numPred!=0)&&(numPat==0)&&(numAgPred==0)&&(numPredPat==0))||((numAg==0)&&(numPred==0)&&(numPat!=0)&&(numAgPat==0)&&(numPredPat==0)))
				meantype=4;	// 2 meanings uncertain "Predicate<Agent, Patient>" meanings;
		  	  else meantype=5;	// totally unexpressable meanings;
  			}
		}
	else if(type==2)
		{ numAg=numPred=numPat=numAgPred=numAgPat=numPredPat=0;
		  if(getNumLexRule()!=0)
			{ for(i=0;i<getNumLexRule();i++)
		  		{ if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1) numAg++;	// check Ag rules;
		  		  if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1) numPred++;	// check Pred rules;
			  	  if(chk2SideMeanUtter(1, 4, meanutter, getpLexRuleList(i), semspace)==1) numPat++;	// check Pat rules;
		  		  if(chk2SideMeanUtter(1, 5, meanutter, getpLexRuleList(i), semspace)==1) numAgPred++;	// check AgPred rules;
		  		  if(chk2SideMeanUtter(1, 6, meanutter, getpLexRuleList(i), semspace)==1) numAgPat++;	// check AgPat rules;
		  		  if(chk2SideMeanUtter(1, 7, meanutter, getpLexRuleList(i), semspace)==1) numPredPat++;	// check PredPat rules;	  		  
				}
			}
		  // according to different conditions to decide!
		  if(((numAg!=0)&&(numPred!=0)&&(numPat!=0))||((numAg!=0)&&(numPredPat!=0))||((numPred!=0)&&(numAgPat!=0))||((numPat!=0)&&(numAgPred!=0)))
		  	meantype=1;	// fully expressable meaning;
		  else if((((numAg!=0)&&(numPred!=0)&&(numPat==0))||((numAg!=0)&&(numPred==0)&&(numPat!=0))||((numAg==0)&&(numPred!=0)&&(numPat!=0)))||(numAgPred!=0)||(numAgPat!=0)||(numPredPat!=0))
			meantype=2;	// 1 meaning uncertain "Predicate<Agent, Patient>" meanings;
		  else if(((numAg!=0)&&(numPred==0)&&(numPat==0)&&(numAgPred==0)&&(numAgPat==0))||((numAg==0)&&(numPred!=0)&&(numPat==0)&&(numAgPred==0)&&(numPredPat==0))||((numAg==0)&&(numPred==0)&&(numPat!=0)&&(numAgPat==0)&&(numPredPat==0)))
			meantype=4;	// 2 meanings uncertain "Predicate<Agent, Patient>" meanings;
		  else meantype=5;	// totally unexpressable meanings;
  		}
	else if(type==3)
		{ numHolist=0;
		  if(getNumLexRule()!=0)
			{ for(i=0;i<getNumLexRule();i++)
		  		{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1) numHolist++;	// check Holistic rules; 
		  		}
		  	}
		  if(numHolist!=0) meantype=1;	// fully expressable meanings;
		  else meantype=5;	// totally unexpressable meanings;
		}
	return meantype;
}

void CLTMem::getMeanType(CMeanUtter *meanutter, int *meantype, CSemSpace *semspace)
{ // check the chosen meaning's type based on current rules;
  // meantype=0, initial value; 1, fully expressable meanings; 2, 1 meaning uncertain "Predicate<Agent, Patient>" meaning; 3, 1 meaning uncertain "Predicate<Agent>" meaning; 4, 2 meanings uncertain "Predicate<Agent, Patient>" meanings; 5, totally unexpressable meanings;
	assert((meanutter!=NULL)&&(semspace!=NULL));
  	int i;	
	*meantype=0;
	for(i=0;i<semspace->getNumIntgMean();i++)
		{ if(*(semspace->getpSemItem(i)->getpIntgMean())==*(meanutter->getpMean()))
			{ if(i<semspace->getNumMean1()) *meantype=ChkMeanType1(1, meanutter, semspace);
		 	  else *meantype=ChkMeanType2(1, meanutter, semspace);
			}
		}
}

void CLTMem::updCandLexRule(CLexRule *lexrule, CLexRule **&CandLexRule, int *numCandLexRule)
{ // update this lexical rule into CandLexRule;
	assert(lexrule!=NULL);
	int i;
	CLexRule **candlexruletemp=NULL;
	int numnewcandlex;

	if(*numCandLexRule==0) 
		{ // create new CandLexRule; 
		  (*numCandLexRule)++;
		  CandLexRule=new CLexRule * [*numCandLexRule]; assert(CandLexRule!=NULL);
		  CandLexRule[0]=lexrule;
		}
	else
		{ // no check whether lexrule is already in CandLexRule!
		  numnewcandlex=(*numCandLexRule)+1;	// increase the current number of candidante lexical rules;
		  candlexruletemp=new CLexRule * [numnewcandlex]; assert(candlexruletemp!=NULL);
		  for(i=0;i<numnewcandlex;i++)
		  	candlexruletemp[i]=NULL;
		  for(i=0;i<numnewcandlex-1;i++)
		  	candlexruletemp[i]=CandLexRule[i];
		  candlexruletemp[numnewcandlex-1]=lexrule;
		  // delete original CandLexRule;
		  delete [] CandLexRule; CandLexRule=NULL;
		  *numCandLexRule=0;
		  // copy candlexruletemp to CandLexRule;
		  *numCandLexRule=numnewcandlex; CandLexRule=candlexruletemp;
		  candlexruletemp=NULL;	// recollect candlexruletemp;
		}
}

void CLTMem::SearchCand1(CSemSpace *semspace, CMeanUtter *meanutter, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred)
{ // search candidate lexical rules for expressing Predicate<Agent> meanings: meanutter;
	assert((semspace!=NULL)&&(meanutter!=NULL));
	int i;
		
	// gather candidate lexical rules;
	if(getNumLexRule()!=0)
		{ *numHolist=*numAg=*numPred=0;
		  // check holistic rules;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numHolist)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check Ag rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numAg)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check Pred rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numPred)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		}	
}

void CLTMem::SearchCand2(CSemSpace *semspace, CMeanUtter *meanutter, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // search candidate lexical rules for expressing Predicate<Agent, Patient> meanings: meanutter;
	assert((semspace!=NULL)&&(meanutter!=NULL));
	int i;
	
	// gather candidate lexical rules;
	if(getNumLexRule()!=0)
		{ *numHolist=*numAg=*numPred=*numPat=*numAgPred=*numAgPat=*numPredPat=0;
		  // check holistic rules;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 1, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numHolist)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check Ag rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 2, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numAg)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check Pred rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 3, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numPred)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check Pat rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 4, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numPat)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check AgPred phrase;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 5, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numAgPred)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check AgPat phrase;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 6, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numAgPat)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		  // check PredPat phrase;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(1, 7, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numPredPat)++;
		  		  updCandLexRule(getpLexRuleList(i), CandLexRule, numCandLexRule);	// update this lexical rule into CandLexRule;
		  		}
		  	}
		}
}

void CLTMem::ChkRela2CatPro(int situation, CLexRule *rule1, CLexRule *rule2, int themrole1, int themrole2, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12)
{ // check category relation of 2 word rules or 1 word + 1 phrase rules;
  // situation=1, 2 cats, 1 syn, 2 word rules for "Predicate<Agent>" meaning;	
  // situation=2, 2 cats, 1 syn, 1 word + 1 phrase for "Predicate<Agent, Patient>" meaning;
  // situation=3, 2 cats, 1 syn, 3 word rules for "Predicate<Agent, Patient>" meaning;
	assert((rule1!=NULL)&&(rule2!=NULL)); assert((1<=situation)&&(situation<=3));
  	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL;
	double combwei;
	int comp2ret;
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;
	
  	// check if there are syntax rules between these categories; if so, select the strongest combined one;
	relaCatListSyn=NULL; numRelaCatListSyn=0;
	for(i=0;i<rule1->getCatNum();i++)
	  	{ if(rule1->getpCatList(i)->getThemRole()==themrole1) 
	  	  	{ rule1CatList=rule1->getpCatList(i); 
			  for(j=0;j<rule2->getCatNum();j++)
	  			{ if(rule2->getpCatList(j)->getThemRole()==themrole2) 
	  		  		{ rule2CatList=rule2->getpCatList(j);
	  		  	  	  for(k=0;k<getNumSynRule();k++)
	  		 	 		{ if(((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat())))
	  		  				{ // calculate the combined strength of AssoWei and SynStr; 
							  combwei=0.0;
							  if((situation==1)||(situation==2)) combwei=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
  							  else if(situation==3)
							  	{ comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
								  if(comp2ret==1) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
							  	  else if(comp2ret==2) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
  							  	}
							  rec2Cat1Syn(0, -1, combwei, rule1CatList, rule2CatList, getpSynRuleList(k), relaCatListSyn, &numRelaCatListSyn);	// 2 cats, 1 syn;
	  		  	  	  		}
	  			  		}
	  			  	  rule2CatList=NULL;	// recollect rule2CatList;
			  		}
	  			}
			  rule1CatList=NULL;	// recollect rule2CatList;
	  		}
		}
	catlist1=NULL; catlist2=NULL;
	syn12=NULL;
	FindrelCatListSyn_Rela2Cat(relaCatListSyn, &numRelaCatListSyn, catlist1, catlist2, syn12);
	if(syn12==NULL)
	   	{ // there are no syntax rules between these two category; select the categories with the strongest association weight in rule1 and rule2;
		  catlist1=NULL; rule1->FindCatListwithHighAsso(0, themrole1, catlist1);
		  catlist2=NULL; rule2->FindCatListwithHighAsso(0, themrole2, catlist2);
		}	
}
					  	
void CLTMem::chk1ConsistSynPro(CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // check if there is 1 consistent syntactic rule;
	assert((rule1!=NULL)&&(rule2!=NULL)&&(rule3!=NULL));
	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL, *rule3CatList=NULL;
	double combwei, assowei12, assowei23, assowei13;
	int comp2ret;
	
	// check syn12;
	rule3CatList=NULL; rule3->FindCatListwithHighAsso(0, themrole3, rule3CatList); 
	for(i=0;i<rule1->getCatNum();i++)
		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
			  for(j=0;j<rule2->getCatNum();j++)
			  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
			  		{ rule2CatList=rule2->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
					  	{ if(((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat())))
					  		{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
							  if(comp2ret==1)
	  	  					  	{ if(rule3CatList==NULL)
	  	  					  		{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
									}
	  	  					  	  else
	  	  					  	  	{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
									}
	  	  					  	}
	  	  					  else if(comp2ret==2)
	  	  					  	{ if(rule3CatList==NULL)
	  	  					  		{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
									}
	  	  					  	  else
	  	  					  	  	{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
	  	  					  	  	  rec3Cat1Syn(0, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
									}
	  	  					  	}									  
					  		}
					  	}
					  rule2CatList=NULL;	// recollect rule2CatList;
			  		}
			  	}
			  rule1CatList=NULL;	// recollect rule1CatList;
	 		}
	  	}
	// check syn23;
	rule1CatList=NULL; rule1->FindCatListwithHighAsso(0, themrole1, rule1CatList);
	for(i=0;i<rule2->getCatNum();i++)
		{ if(rule2->getpCatList(i)->getThemRole()==themrole2)
			{ rule2CatList=rule2->getpCatList(i);
			  for(j=0;j<rule3->getCatNum();j++)
			  	{ if(rule3->getpCatList(j)->getThemRole()==themrole3)
			  		{ rule3CatList=rule3->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
	  				  	{ if(((getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat())))
					  		{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  comp2ret=CGenFuncClass::comp2values_big(rule2CatList->getAssoWei(), rule3CatList->getAssoWei());
							  if(comp2ret==1)
		  					  	{ if(rule1CatList==NULL)
		  					  		{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
									}
		  					  	  else
		  					  	  	{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
	  	  					  		  rec3Cat1Syn(0, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
									}
		  					  	}
		  					  else if(comp2ret==2)
		  					  	{ if(rule1CatList==NULL)
		  					  		{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
									}
		  					  	  else
		  					  	  	{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
	  	  					  		  rec3Cat1Syn(0, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
									}
		  					  	}
					  		}
	  					}
	  				  rule3CatList=NULL;	// recollect rule3CatList;
	  		  		}
	  		  	}
	  		  rule2CatList=NULL;	// recollect rule2CatList;
	  		}
	  	}
	// check syn13;
	rule2CatList=NULL; rule2->FindCatListwithHighAsso(0, themrole2, rule2CatList);
	for(i=0;i<rule1->getCatNum();i++)
		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
			  for(j=0;j<rule3->getCatNum();j++)
			  	{ if(rule3->getpCatList(j)->getThemRole()==themrole3)
			  		{ rule3CatList=rule3->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
					  	{ if(((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat())))
					  		{ assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule3CatList->getAssoWei());
							  if(comp2ret==1)
		  					  	{ if(rule2CatList==NULL)
		  					  		{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
  									  rec3Cat1Syn(0, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats(cat1, cat3), 1 syn (syn13);
									}
		  					  	  else
		  					  	  	{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
									  rec3Cat1Syn(0, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
									}
		  					  	}
		  					  else if(comp2ret==2)
		  					  	{ if(rule2CatList==NULL)
		  					  		{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  					  		  rec3Cat1Syn(0, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats(cat1, cat3), 1 syn (syn13);
									}
		  					  	  else
		  					  	  	{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
	  	  					  		  rec3Cat1Syn(0, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
									}
		  					  	}
					  		}
					  	}
					  rule3CatList=NULL;	// recollect rule3CatList;
			  		}
			  	}
			  rule1CatList=NULL;	// recollect rule1CatList;
			}
		}	  				  	
}

void CLTMem::DecCase2synTypPro(int type, int *case2synTyp, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13)
{ // decide case2synTyp in production;
  // case2synTyp=0, SV+VO; 1, SV+OV; 2, VS+VO; 3, VS+OV;
  //			      4, SV+SO; 5, SV+OS; 6, VS+SO; 7, VS+OS;
  //			      8, VO+SO; 9, VO+OS; 10, OV+SO; 11, OV+OS;
  // 0, 3, 5, 6, 9, 10: unique global word order;
  // 1, 2, 4, 7, 8, 11: multiple global word order;
 	assert((type==1)||(type==2)||(type==3));
	switch(type)
		{ case 1: // syn12, syn23;
				if((syn12->getpCat(0)==catlist1->getpCat())&&(syn12->getpCat(1)==catlist2->getpCat()))
					{ if((syn23->getpCat(0)==catlist2->getpCat())&&(syn23->getpCat(1)==catlist3->getpCat()))
						{ if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==0)) *case2synTyp=0;	// SV+VO;
						  else if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==1)) *case2synTyp=1;	// SV+OV;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==0)) *case2synTyp=2;	// VS+VO;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==1)) *case2synTyp=3;	// VS+OV;
						}
					  else if((syn23->getpCat(1)==catlist2->getpCat())&&(syn23->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==0)) *case2synTyp=1;	// SV+OV;
						  else if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==1)) *case2synTyp=0;	// SV+VO;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==0)) *case2synTyp=3;	// VS+OV;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==1)) *case2synTyp=2;	// VS+VO;
					  	}
					}
				else if((syn12->getpCat(1)==catlist1->getpCat())&&(syn12->getpCat(0)==catlist2->getpCat()))
					{ if((syn23->getpCat(0)==catlist2->getpCat())&&(syn23->getpCat(1)==catlist3->getpCat()))
						{ if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==0)) *case2synTyp=2;	// VS+VO;
						  else if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==1)) *case2synTyp=3;	// VS+OV;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==0)) *case2synTyp=0;	// SV+VO;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==1)) *case2synTyp=1;	// SV+OV;
						}
					  else if((syn23->getpCat(1)==catlist2->getpCat())&&(syn23->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==0)) *case2synTyp=3;	// VS+OV;
						  else if((syn12->getSynTyp()==0)&&(syn23->getSynTyp()==1)) *case2synTyp=2;	// VS+VO;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==0)) *case2synTyp=1;	// SV+OV;
						  else if((syn12->getSynTyp()==1)&&(syn23->getSynTyp()==1)) *case2synTyp=0;	// SV+VO;
						}
					}
				break;
		  case 2: // syn12, syn13;
		  		if((syn12->getpCat(0)==catlist1->getpCat())&&(syn12->getpCat(1)==catlist2->getpCat()))
					{ if((syn13->getpCat(0)==catlist1->getpCat())&&(syn13->getpCat(1)==catlist3->getpCat()))
						{ if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=4;	// SV+SO;
						  else if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=5;	// SV+OS;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=6;	// VS+SO;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=7;	// VS+OS;
						}
					  else if((syn13->getpCat(1)==catlist1->getpCat())&&(syn13->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=5;	// SV+OS;
						  else if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=4;	// SV+SO;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=7;	// VS+OS;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=6;	// VS+SO;
						}
					}
				else if((syn12->getpCat(1)==catlist1->getpCat())&&(syn12->getpCat(0)==catlist2->getpCat()))
					{ if((syn13->getpCat(0)==catlist1->getpCat())&&(syn13->getpCat(1)==catlist3->getpCat()))
						{ if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=6;	// VS+SO;
						  else if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=7;	// VS+OS;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=4;	// SV+SO;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=5;	// SV+OS;
						}
					  else if((syn13->getpCat(1)==catlist1->getpCat())&&(syn13->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=7;	// VS+OS;
						  else if((syn12->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=6;	// VS+SO;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=5;	// SV+OS;
						  else if((syn12->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=4;	// SV+SO;
						}
					}
		  		break;
		  case 3: // syn23, syn13;
		  		if((syn23->getpCat(0)==catlist2->getpCat())&&(syn23->getpCat(1)==catlist3->getpCat()))
					{ if((syn13->getpCat(0)==catlist1->getpCat())&&(syn13->getpCat(1)==catlist3->getpCat()))
						{ if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=8;	// VO+SO;
						  else if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=9;	// VO+OS;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=10;	// OV+SO;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=11;	// OV+OS;
						}
					  else if((syn13->getpCat(1)==catlist1->getpCat())&&(syn13->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=9;	// VO+OS;
						  else if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=8;	// VO+SO;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=11;	// OV+OS;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=10;	// OV+SO;
						}
					}
				else if((syn23->getpCat(1)==catlist2->getpCat())&&(syn23->getpCat(0)==catlist3->getpCat()))
					{ if((syn13->getpCat(0)==catlist1->getpCat())&&(syn13->getpCat(1)==catlist3->getpCat()))
						{ if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=10;	// OV+SO;
						  else if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=11;	// OV+OS;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=8;	// VO+SO;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=9;	// VO+OS;
						}
					  else if((syn13->getpCat(1)==catlist1->getpCat())&&(syn13->getpCat(0)==catlist3->getpCat()))
					  	{ if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==0)) *case2synTyp=11;	// OV+OS;
						  else if((syn23->getSynTyp()==0)&&(syn13->getSynTyp()==1)) *case2synTyp=10;	// OV+SO;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==0)) *case2synTyp=9;	// VO+OS;
						  else if((syn23->getSynTyp()==1)&&(syn13->getSynTyp()==1)) *case2synTyp=8;	// VO+SO;
						}
					}
		  		break;
		  default: break;
		}
}

void CLTMem::chk2ConsistSynPro(int cond, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12case3syn, CSynRule *syn23case3syn, CSynRule *syn13case3syn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // check if there are 2 consistent syntactic rules; 3 cats, 2 syn;
  // case2synTyp=0, SV+VO; 1, SV+OV; 2, VS+VO; 3, VS+OV;
  //			      4, SV+SO; 5, SV+OS; 6, VS+SO; 7, VS+OS;
  //			      8, VO+SO; 9, VO+OS; 10, OV+SO; 11, OV+OS;
  // 0, 3, 5, 6, 9, 10: unique global word order;
  // 1, 2, 4, 7, 8, 11: multiple global word order;
  // cond = 0; not allow to choose already chosen syntactic rules in 3 syn and 2 syn case; 1, allow to choose already chosen syntactic rules;
	assert((cond==1)||((cond==2)&&(syn12case3syn==NULL)&&(syn23case3syn==NULL)&&(syn13case3syn==NULL))); 
  	assert((rule1CatList!=NULL)&&(rule2CatList!=NULL)&&(rule3CatList!=NULL));
	int i, j, k;
	double combwei, assowei12, assowei23, assowei13;
	int case2synTyp;
	
	// check syn12, syn23;
	for(i=0;i<getNumSynRule();i++)
	 	{ if(((getpSynRuleList(i)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(1)==rule2CatList->getpCat()))||((getpSynRuleList(i)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(0)==rule2CatList->getpCat())))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(j=0;j<getNumSynRule();j++)
					{ if(((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat())))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
							{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
						  	  assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
						 	  combwei=_Half*(assowei12+assowei23);
							  case2synTyp=-1; DecCase2synTypPro(1, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL);
							  rec3Cat2Syn(0, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syn (12, 23);
							}
		  		  		}
		  		  	}
				}
			}
		}		  		  
	// check syn12, syn13;
	for(i=0;i<getNumSynRule();i++)
	 	{ if(((getpSynRuleList(i)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(1)==rule2CatList->getpCat()))||((getpSynRuleList(i)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(0)==rule2CatList->getpCat())))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if(((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat())))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  combwei=_Half*(assowei12+assowei13);
							  case2synTyp=-1; DecCase2synTypPro(2, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k));
							  rec3Cat2Syn(0, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syn (12, 13);
	  		  				}
						}
	  		  		}
		   		}
			}
		}
	// check syn23, syn13;
	for(j=0;j<getNumSynRule();j++)
	 	{ if(((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat())))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if(((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))||((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat())))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  combwei=_Half*(assowei23+assowei13);
						 	  case2synTyp=-1; DecCase2synTypPro(3, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k));
							  rec3Cat2Syn(0, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syn (23, 13);
							}
						}
	  			  	}
				}
			}
		}
}

bool CLTMem::Chk3Syn(int proper, int order, int type, int synTyp12, int synTyp23, int synTyp13)
{ // check whether these 3 types of syntactic rules are consistent; proper=0, production; proper=1, perception;
    	// type=1, 12, 23, 13; type=2, 12, 23, 31; type=3, 12, 32, 13; type=4, 12, 32, 31;	
  	// type=5, 21, 23, 13; type=6, 21, 23, 31; type=7, 21, 32, 13; type=8, 21, 32, 31;
	// if proper=0, order=-1;
	// if proper=1, order=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
	assert(((proper==0)&&(order==-1))||((proper==1)&&(3<=order)&&(order<=8))); assert((1<=type)&&(type<=8)); 
	assert(((synTyp12==0)||(synTyp12==1))&&((synTyp23==0)||(synTyp23==1))&&((synTyp13==0)||(synTyp13==1)));
	int binary;
	bool value=0;
	
	if((type==5)||(type==6)||(type==7)||(type==8)) synTyp12=!synTyp12;
	if((type==3)||(type==4)||(type==7)||(type==8)) synTyp23=!synTyp23;
	if((type==2)||(type==4)||(type==6)||(type==8)) synTyp13=!synTyp13;
		  
	if(proper==0)
		{ // production;
		  binary=synTyp12*(int)(pow(overallpara.p_nCode, 2))+synTyp23*(int)(pow(overallpara.p_nCode, 1))+synTyp13;
		  if((binary==0)||(binary==(int)(pow(overallpara.p_nCode, 1)))||(binary==(int)(pow(overallpara.p_nCode, 1))+1)||(binary==(int)(pow(overallpara.p_nCode, 2)))||(binary==(int)(pow(overallpara.p_nCode, 2))+1)||(binary==(int)(pow(overallpara.p_nCode, 2))+(int)(pow(overallpara.p_nCode, 1))+1)) 
 			value=1;
  		  else value=0;
		}
	else if(proper==1)
		{ // perception;
		  if((order==3)&&(synTyp12==0)&&(synTyp23==0)&&(synTyp13==0)) value=1;	// SVO;
		  else if((order==4)&&(synTyp12==0)&&(synTyp23==1)&&(synTyp13==0)) value=1;	// SOV;
		  else if((order==5)&&(synTyp12==0)&&(synTyp23==1)&&(synTyp13==1)) value=1;	// OSV;
		  else if((order==6)&&(synTyp12==1)&&(synTyp23==0)&&(synTyp13==0)) value=1;	// VSO;
		  else if((order==7)&&(synTyp12==1)&&(synTyp23==0)&&(synTyp13==1)) value=1;	// VOS;
		  else if((order==8)&&(synTyp12==1)&&(synTyp23==1)&&(synTyp13==1)) value=1;	// OVS;
		  else value=0;
		}
	return value;
}
								  
void CLTMem::chk3ConsistSyn(int proper, int type, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // check if there are 3 consistent syntactic rules; 3 cats, 3 syn; proper=0, production; 1, perception;
	assert((proper==0)||(proper==1)); assert((rule1CatList!=NULL)&&(rule2CatList!=NULL)&&(rule3CatList!=NULL));
	int i, j, k;
	int synTyp12, synTyp23, synTyp13;
	
	// check syn12, syn23, syn13;
	for(i=0;i<getNumSynRule();i++)
	 	{ if((getpSynRuleList(i)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(1)==rule2CatList->getpCat()))
			{ synTyp12=getpSynRuleList(i)->getSynTyp();
	  		  for(j=0;j<getNumSynRule();j++)
				{ if((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))
					{ synTyp23=getpSynRuleList(j)->getSynTyp();
			  		  for(k=0;k<getNumSynRule();k++)
					 	{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
	  						{ synTyp13=getpSynRuleList(k)->getSynTyp(); 
					  		  if(Chk3Syn(proper, type, 1, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 12, 23, 13;
							}
	  			  		  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
	  						{ synTyp13=getpSynRuleList(k)->getSynTyp(); 
					  		  if(Chk3Syn(proper, type, 2, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 12, 23, 31;
							}
						}
					}
		  		  else if((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat()))
		  			{ synTyp23=getpSynRuleList(j)->getSynTyp();
		  	  		  for(k=0;k<getNumSynRule();k++)
						{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp();					  		  
					  		  if(Chk3Syn(proper, type, 3, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 12, 32, 13;
							}
				  		  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp();				  	  		  
				  	  		  if(Chk3Syn(proper, type, 4, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 12, 32, 31;
							}
						}
					}
				}
			}
 		  else if((getpSynRuleList(i)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(0)==rule2CatList->getpCat()))
  			{ synTyp12=getpSynRuleList(i)->getSynTyp(); 
  	  		  for(j=0;j<getNumSynRule();j++)
  				{ if((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))
					{ synTyp23=getpSynRuleList(j)->getSynTyp();
			  		  for(k=0;k<getNumSynRule();k++)
						{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp();					  		  
				  	  	 	  if(Chk3Syn(proper, type, 5, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 21, 23, 13;
							}
				  		  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp();					  		  
				  	  	 	  if(Chk3Syn(proper, type, 6, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 21, 23, 31;
							}
						}
					}
		  		  else if((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat()))
		  			{ synTyp23=getpSynRuleList(j)->getSynTyp(); 
		  	  		  for(k=0;k<getNumSynRule();k++)
						{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp();					  		  
				  	  		  if(Chk3Syn(proper, type, 7, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 21, 32, 13;
							}
				  		  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
							{ synTyp13=getpSynRuleList(k)->getSynTyp(); 
					  		  if(Chk3Syn(proper, type, 8, synTyp12, synTyp23, synTyp13)==1) rec3Cat3Syn(proper, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 21, 32, 31;
							}
						}
					}
	  	  		}
 		  	}
	  	}
}
	  				  		  
void CLTMem::ChkRela3CatPro(CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13)
{ // check category relation of 3 word rules;
	assert((rule1!=NULL)&&(rule2!=NULL)&&(rule3!=NULL));
	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL, *rule3CatList=NULL;
	CatList *catlist1case3syn=NULL, *catlist2case3syn=NULL, *catlist3case3syn=NULL, *catlist1case2syn=NULL, *catlist2case2syn=NULL, *catlist3case2syn=NULL;	// for temporary storing catlists in 3 synrule, 2 synrule cases;
	CSynRule *syn12case3syn=NULL, *syn23case3syn=NULL, *syn13case3syn=NULL, *syn1case2syn=NULL, *syn2case2syn=NULL, *syn12temp=NULL, *syn23temp=NULL, *syn13temp=NULL;	// for temporary storing synrule for 3 synrule case;
	double combWeicase1syn, combWeicase2syn, combWeicase3syn;	// store the combined strength in 2 and 3 syntactic rules cases;
	int case1synTyp;	// store the cases in the 1 syntactic rule: 1, syn12; 2, syn23; 3, syn13;	
	int case2synTyp;	// store the cases in the 2 consistent syntactic rules;
  		// case2synTyp=0, SV+VO; 1, SV+OV; 2, VS+VO; 3, VS+OV;
  		//			      4, SV+SO; 5, SV+OS; 6, VS+SO; 7, VS+OS;
  		//			      8, VO+SO; 9, VO+OS; 10, OV+SO; 11, OV+OS;
  		// 0, 3, 5, 6, 9, 10: unique global word order;
  		// 1, 2, 4, 7, 8, 11: multiple global word order;
  	int case3synTyp;	
	RelaCatListSyn **relaCatListSyn=NULL;	// store related catlist and syntactic rules;
	int numRelaCatListSyn;
	
	// Try combinable categories and related syntatcic rules first, then, try partial combinable categories and related syntactic rules;	
	// check whether there are 3 consistent syntactic rules; 3 cats, 3 syn;
	relaCatListSyn=NULL; numRelaCatListSyn=0;
	for(i=0;i<rule1->getCatNum();i++)
	  	{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
	  	  	  for(j=0;j<rule2->getCatNum();j++)
	  	  	  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  	  		{ rule2CatList=rule2->getpCatList(j); 
	  				  for(k=0;k<rule3->getCatNum();k++)
	  					{ if(rule3->getpCatList(k)->getThemRole()==themrole3) 
	  						{ rule3CatList=rule3->getpCatList(k);
							  // check if there are 3 consistent syntactic rules: syn12, syn23, syn13;
							  chk3ConsistSyn(0, -1, rule1CatList, rule2CatList, rule3CatList, relaCatListSyn, &numRelaCatListSyn);	// check syn12, syn23, syn13;	
	  				  		  rule3CatList=NULL;	// recollect rule3CatList;
	  				  		}	  				  
	  					}
	  				  rule2CatList=NULL;	// recollect rule2CatList;
	  				}	  	  	  
	  	  	  	}
	  	  	  rule1CatList=NULL;	// recollect rule1CatList;
			}
		}
	catlist1case3syn=NULL; catlist2case3syn=NULL; catlist3case3syn=NULL; 
	syn12case3syn=NULL; syn23case3syn=NULL; syn13case3syn=NULL;
	case3synTyp=-1; combWeicase3syn=0.0;
	FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case3synTyp, &combWeicase3syn, catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn);	
	if((syn12case3syn!=NULL)&&(syn23case3syn!=NULL)&&(syn13case3syn!=NULL))
		{ // there are 3 consistent syntactic rules;
		  // check whether there are 2 consistent syntactic rules; 3 cats, 2 syns;
		  relaCatListSyn=NULL; numRelaCatListSyn=0;
		  for(i=0;i<rule1->getCatNum();i++)
	  		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
				{ rule1CatList=rule1->getpCatList(i);
	  	  		  for(j=0;j<rule2->getCatNum();j++)
	  	  		  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  		  		{ rule2CatList=rule2->getpCatList(j); 
	  					  for(k=0;k<rule3->getCatNum();k++)
	  						{ if(rule3->getpCatList(k)->getThemRole()==themrole3) 
	  							{ rule3CatList=rule3->getpCatList(k);
								  // check if there are 2 consistent syntactic rules: syn12, syn23 or syn12, syn13 or syn23, syn13;
	  					  		  chk2ConsistSynPro(1, rule1CatList, rule2CatList, rule3CatList, syn12case3syn, syn23case3syn, syn13case3syn, relaCatListSyn, &numRelaCatListSyn);
								  rule3CatList=NULL;	// recollect rule3CatList;
	  					  		}
	  					  	}
	  					  rule2CatList=NULL;	// recollect rule2CatList;
			  	  		}
	  	  		  	}
	  	  		  rule1CatList=NULL;	// recollect rule1CatList;
		  		}
		  	}
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  case2synTyp=-1; combWeicase2syn=0.0; 
		  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case2synTyp, &combWeicase2syn, catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp);
		  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
		  	{ // there are 2 consistent syntactic rules;
			  syn1case2syn=NULL; syn2case2syn=NULL;
			  switch(case2synTyp)
			  	{ case 0: case 1: case 2: case 3: syn1case2syn=syn12temp; syn2case2syn=syn23temp; break;	// syn12, syn23;
			  	  case 4: case 5: case 6: case 7: syn1case2syn=syn12temp; syn2case2syn=syn13temp; break;	// syn12, syn13;
			  	  case 8: case 9: case 10: case 11: syn1case2syn=syn23temp; syn2case2syn=syn13temp; break;	// syn23, syn13;
				  default: break;
			  	}

			  // compare combWeicase3syn and combWeicase2syn;
			  if(FLOAT_BG_EQ(combWeicase3syn, combWeicase2syn))
			  	{ // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn;
			  	  catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
				  syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;
				}
			  else
			  	{ // two methods to select;
				  if(getProComp2_3()==0)
				  	{ // method 1: use catlist1case2syn, catlist2case2syn, catlist3case2syn, syn1case2syn, syn2case2syn;
				  	  catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
				  	  switch(case2synTyp)
					  	{ case 0: case 1: case 2: case 3: syn12=syn1case2syn; syn23=syn2case2syn; syn13=NULL; break;	// syn12, syn23;
				  		  case 4: case 5: case 6: case 7: syn12=syn1case2syn; syn23=NULL; syn13=syn2case2syn; break;	// syn12, syn13;
			  			  case 8: case 9: case 10: case 11: syn12=NULL; syn23=syn1case2syn; syn13=syn2case2syn; break;	// syn23, syn13;
						  default: break;
			  			}
				  	}
				  else if(getProComp2_3()==1)
				  	{ // method 2: check if case2syn leads to unique global word order; use catlist1case2syn, catlist2case2syn, catlist3case2syn, syn1case2syn, syn2case2syn;
				  	  switch(case2synTyp)
					 	{ // unique global order 
					 	  case 0: case 3: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
										syn12=syn1case2syn; syn23=syn2case2syn; syn13=NULL;
										break;	// syn12, syn23;
					 	  case 5: case 6: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
										syn12=syn1case2syn; syn23=NULL; syn13=syn2case2syn;
										break;	// syn12, syn13;
						  case 9: case 10: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
										syn12=NULL; syn23=syn1case2syn; syn13=syn2case2syn; 
										break;	// syn23, syn13;
						  // multiple global orders;
						  case 1: case 2: case 4: case 7: case 8: case 11: // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn;
			  		  					catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
					  					syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;
										break;					  
					 	  default: break;
					 	}
				  	}
			  	}
			  syn1case2syn=NULL; syn2case2syn=NULL;	// recollect syn1case2syn, syn2case2syn;
			}
		  else if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			{ // there are no 2 consistent syntactic rules;
			  // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn as winning rules;
			  catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
			  syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;			  
		  	}
		  
  		  // recollect catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp;
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;		  	  
		}
	else if((syn12case3syn==NULL)&&(syn23case3syn==NULL)&&(syn13case3syn==NULL))
		{ // there are no 3 consistent syntactic rules;
		  // check whether there are 2 consistent syntactic rules; 3 cats, 2 syns;
		  relaCatListSyn=NULL; numRelaCatListSyn=0;
		  for(i=0;i<rule1->getCatNum();i++)
	  		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
				{ rule1CatList=rule1->getpCatList(i);
	  	  		  for(j=0;j<rule2->getCatNum();j++)
	  	  		  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  		  		{ rule2CatList=rule2->getpCatList(j); 
	  					  for(k=0;k<rule3->getCatNum();k++)
	  						{ if(rule3->getpCatList(k)->getThemRole()==themrole3) 
	  							{ rule3CatList=rule3->getpCatList(k);
								  // check if there are 2 consistent syntactic rules: syn12, syn23 or syn12, syn13 or syn23, syn13;
	  					  		  chk2ConsistSynPro(2, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, NULL, relaCatListSyn, &numRelaCatListSyn);
								  rule3CatList=NULL;	// recollect rule3CatList;
	  					  		}
	  					  	}
	  					  rule2CatList=NULL;	// recollect rule2CatList;
			  	  		}
	  	  		  	}
	  	  		  rule1CatList=NULL;	// recollect rule1CatList;
		  		}
		  	}
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  case2synTyp=-1; combWeicase2syn=0.0; 
		  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case2synTyp, &combWeicase2syn, catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp);	
		  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
		  	{ // there are 2 consistent syntactic rules;
		  	  catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
			  switch(case2synTyp)
			  	{ case 0: case 1: case 2: case 3: syn12=syn12temp; syn23=syn23temp; syn13=NULL; break;	// syn12, syn23;
				  case 4: case 5: case 6: case 7: syn12=syn12temp; syn23=NULL; syn13=syn13temp; break;	// syn12, syn13;
			  	  case 8: case 9: case 10: case 11: syn12=NULL; syn23=syn23temp; syn13=syn13temp; break;	// syn23, syn13;
				  default: break;
				}
		  	}
		  else if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			{ // there are no 2 consistent syntactic rules;
			  // check whether there is 1 consistent syntactic rule; syn12 or syn23 or syn13;
			  relaCatListSyn=NULL; numRelaCatListSyn=0;
			  chk1ConsistSynPro(rule1, rule2, rule3, themrole1, themrole2, themrole3, relaCatListSyn, &numRelaCatListSyn);
			  catlist1=NULL; catlist2=NULL; catlist3=NULL;
			  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
			  case1synTyp=-1; combWeicase1syn=0.0;
			  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case1synTyp, &combWeicase1syn, catlist1, catlist2, catlist3, syn12temp, syn23temp, syn13temp);	
			  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
			  	{ // there is 1 syntactic rule;
			  	  switch(case1synTyp)
			  	  	{ case 1: syn12=syn12temp; syn23=NULL; syn13=NULL; break;	// syn12;
			  	  	  case 2: syn12=NULL; syn23=syn23temp; syn13=NULL; break;	// syn23;
			  	  	  case 3: syn12=NULL; syn23=NULL; syn13=syn13temp; break;	// syn13;
			  	  	  default: break;
			  	  	}
			  	}
			  else if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			  	{ // there is no 1 consistent syntactic rule;
			  	  // select the strongest categories;
		  	  	  catlist1=NULL; rule1->FindCatListwithHighAsso(0, themrole1, catlist1);
				  catlist2=NULL; rule2->FindCatListwithHighAsso(0, themrole2, catlist2); 
			  	  catlist3=NULL; rule3->FindCatListwithHighAsso(0, themrole3, catlist3);		  	  
				}

			  // recollect syn12temp, syn23temp, syn13temp;
			  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  	}

		  // recollect catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp, syn1case2syn, syn2case2syn;
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		}

	// recollect catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn;
	catlist1case3syn=NULL; catlist2case3syn=NULL; catlist3case3syn=NULL;
	syn12case3syn=NULL; syn23case3syn=NULL; syn13case3syn=NULL;
}	

// Perception part;
bool CLTMem::Chk1SynPer(int order, int type, int subtype, int synTyp)
{ // check whether this syntactic rules is consistent;
  // order=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);	
  // type=1(12), 2(23), 3(13);
  // subtype=1, +; 2, -;
	assert((3<=order)&&(order<=8)); assert((1<=type)&&(type<=3)); assert((1<=subtype)&&(subtype<=2));
  	bool value=0;
	if(subtype==2) synTyp=!synTyp;
  	switch(order)
		{ case 3: // SVO;
				if((type==1)&&(synTyp==0)) value=1;	// 12;
				else if((type==2)&&(synTyp==0)) value=1;	// 23;
			 	else if((type==3)&&(synTyp==0)) value=1;	// 13;
			 	break;
		  case 4: // SOV;
				if((type==1)&&(synTyp==0)) value=1;	// 12;
				else if((type==2)&&(synTyp==1)) value=1;	// 23;
				else if((type==3)&&(synTyp==0)) value=1;	// 13;
				break;
		  case 5: // OSV;
				if((type==1)&&(synTyp==0)) value=1;	// 12;
				else if((type==2)&&(synTyp==1)) value=1;	// 23;
				else if((type==3)&&(synTyp==1)) value=1;	// 13;
				break;
		  case 6: // VSO;
				if((type==1)&&(synTyp==1)) value=1;	// 12;
				else if((type==2)&&(synTyp==0)) value=1;	// 23;
				else if((type==3)&&(synTyp==0)) value=1;	// 13;
				break;
		  case 7: // VOS;
				if((type==1)&&(synTyp==1)) value=1;	// 12
				else if((type==2)&&(synTyp==0)) value=1;	// 23;
				else if((type==3)&&(synTyp==1)) value=1;	// 13;
				break;
		  case 8: // OVS;
				if((type==1)&&(synTyp==1)) value=1;	// 12;
				else if((type==2)&&(synTyp==1)) value=1;	// 23;
				else if((type==3)&&(synTyp==1)) value=1;	// 13;
				break;
		  default: break;
		}
  	return value;  
}

void CLTMem::ChkRela2CatPer(int type, int cond, CLexRule *rule1, CLexRule *rule2, int themrole1, int themrole2, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12)
{ // check category relation of 3 word rules with 2 categories;
  // type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
  // cond=1, S+V; 2, S+O; 3, V+O;
	assert((3<=type)&&(type<=8)); assert((1<=cond)&&(cond<=3)); assert((rule1!=NULL)&&(rule2!=NULL));
	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL;
	double combwei;	// store the strongest candidate syntax rule's strength;
	int comp2ret;
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;
	
	// check if there are syntax rules between these categories; if so, select the strongest combined one;
	relaCatListSyn=NULL; numRelaCatListSyn=0;
	for(i=0;i<rule1->getCatNum();i++)
	  	{ if(rule1->getpCatList(i)->getThemRole()==themrole1) 
	  	  	{ rule1CatList=rule1->getpCatList(i); 
			  for(j=0;j<rule2->getCatNum();j++)
	  			{ if(rule2->getpCatList(j)->getThemRole()==themrole2) 
	  		  		{ rule2CatList=rule2->getpCatList(j);
	  		  	  	  for(k=0;k<getNumSynRule();k++)
	  		 	 		{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat()))
	  		  				{ if(Chk1SynPer(type, cond, 1, getpSynRuleList(k)->getSynTyp())==1)
	  		  				  	{ // calculate the combined strength of AssoWei and SynStr; 
								  combwei=0.0;
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
								  if(comp2ret==1) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
								  else if(comp2ret==2) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
								  rec2Cat1Syn(0, -1, combwei, rule1CatList, rule2CatList, getpSynRuleList(k), relaCatListSyn, &numRelaCatListSyn);	// 2 cats, 1 syn;
	  		  					}
	  		  				}
	  		  	  	  	  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat()))
	  		  	  	  	  	{ if(Chk1SynPer(type, cond, 2, getpSynRuleList(k)->getSynTyp())==1)
	  		  				  	{ // calculate the combined strength of AssoWei and SynStr; 
								  combwei=0.0;
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
								  if(comp2ret==1) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
								  else if(comp2ret==2) combwei=_Half*(_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr()+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
								  rec2Cat1Syn(0, -1, combwei, rule1CatList, rule2CatList, getpSynRuleList(k), relaCatListSyn, &numRelaCatListSyn);	// 2 cats, 1 syn;
	  		  					}
	  		  				}
	  			  		}
	  			  	  rule2CatList=NULL;	// recollect rule2CatList;
			  		}
	  			}
			  rule1CatList=NULL;	// recollect rule2CatList;
	  		}
		}
	catlist1=NULL; catlist2=NULL;
	syn12=NULL;
	FindrelCatListSyn_Rela2Cat(relaCatListSyn, &numRelaCatListSyn, catlist1, catlist2, syn12);
	if(syn12==NULL)
	    { // there are no syntax rules between these two category; select the categories with the strongest association weight in rule1 and rule2;
		  catlist1=NULL; rule1->FindCatListwithHighAsso(0, themrole1, catlist1);
		  catlist2=NULL; rule2->FindCatListwithHighAsso(0, themrole2, catlist2); 
	    }
}

void CLTMem::DecCase2synTypPer(int cond, int type, int *case2synTyp, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13)
{ // decide case2synTyp in perception;
  // cond=1, 12/21, 23/32; 2, 12/21, 13/31; 3, 23/32, 13/31;
  // type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
  // case2synTyp=0, syn12, syn23, unique global order; 1, syn12, syn23, multiple global order;
  //			      2, syn12, syn13, unique global order; 3, syn12, syn23, multiple global order;
  //			      4, syn23, syn13, unique global order; 5, syn23, syn13, multiple global order;
  	assert((1<=cond)&&(cond<=3)); assert((3<=type)&&(type<=8));
  	switch(type)
  		{ case 3: // SVO;
				switch(cond)
					{ case 1: *case2synTyp=0; break;	// syn12, syn23, unique global order;
					  case 2: *case2synTyp=3; break;	// syn12, syn13, multiple global order;
					  case 3: *case2synTyp=5; break;	// syn23, syn13, multiple global order;
					  default: break;
					}
				break;
		  case 4: // SOV;
				switch(cond)
					{ case 1: *case2synTyp=1; break;	// syn12, syn23, multiple global order;
					  case 2: *case2synTyp=3; break;	// syn12, syn13, multiple global order;
					  case 3: *case2synTyp=4; break;	// syn23, syn13, unique global order;
					  default: break;
					}
		  		break;
		  case 5: // OSV;
				switch(cond)
					{ case 1: *case2synTyp=1; break;	// syn12, syn23, multiple global order;
					  case 2: *case2synTyp=2; break;	// syn12, syn13, unique global order;
					  case 3: *case2synTyp=5; break;	// syn23, syn13, multiple global order;
					  default: break;
					}
		  		break;
		  case 6: // VSO;
				switch(cond)
					{ case 1: *case2synTyp=1; break;	// syn12, syn23, multiple global order;
					  case 2: *case2synTyp=2; break;	// syn12, syn13, unique global order;
					  case 3: *case2synTyp=5; break;	// syn23, syn13, multiple global order;
					  default: break;
					}
		  		break;
		  case 7: // VOS;
				switch(cond)
					{ case 1: *case2synTyp=1; break;	// syn12, syn23, multiple global order;
					  case 2: *case2synTyp=3; break;	// syn12, syn13, multiple global order;
					  case 3: *case2synTyp=4; break;	// syn23, syn13, unique global order;
					  default: break;
					}
		  		break;
		  case 8: // OVS;
				switch(cond)
					{ case 1: *case2synTyp=0; break;	// syn12, syn23, unique global order;
					  case 2: *case2synTyp=3; break;	// syn12, syn13, multiple global order;
					  case 3: *case2synTyp=5; break;	// syn23, syn13, multiple global order;
					  default: break;
					}
		  		break;
		  default: break;
  		}
}

void CLTMem::chk1ConsistSynPer(int type, CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // check if there is 1 consistent syntactic rule;
  // type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
  	assert((3<=type)&&(type<=8)); assert((rule1!=NULL)&&(rule2!=NULL)&&(rule3!=NULL));
	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL, *rule3CatList=NULL;
	double combwei, assowei12, assowei23, assowei13;
	int comp2ret;

	// check syn12;
	rule3CatList=NULL; rule3->FindCatListwithHighAsso(0, themrole3, rule3CatList);
	for(i=0;i<rule1->getCatNum();i++)
		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
			  for(j=0;j<rule2->getCatNum();j++)
			  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
			  		{ rule2CatList=rule2->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
					  	{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat()))
					  		{ if(Chk1SynPer(type, 1, 1, getpSynRuleList(k)->getSynTyp())==1)
					  			{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
								  if(comp2ret==1)
								  	{ if(rule3CatList==NULL)
	  	  					  			{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
										}
	  	  					  	  	  else
	  	  					  		  	{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
	  	  					  		  	}
	  	  						  	}
	  	  						  else if(comp2ret==2)
	  	  						  	{ if(rule3CatList==NULL)
	  	  						  		{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
										} 
								  	  else
	  	  						  	  	{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
	  	  						  	  	  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
	  	  					  		  	}
	  	  						  	}									  
						  		}
					  		}
					  	  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat()))
					  	  	{ if(Chk1SynPer(type, 1, 2, getpSynRuleList(k)->getSynTyp())==1)
					  			{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule2CatList->getAssoWei());
								  if(comp2ret==1)
								  	{ if(rule3CatList==NULL)
	  	  					  			{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
										}   
									  else
	  	  					  		  	{ combwei=_Half*(assowei12+_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
	  	  						  	  	  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
	  	  					  		  	}
	  	  						  	}
	  	  						  else if(comp2ret==2)
	  	  						  	{ if(rule3CatList==NULL)
	  	  						  		{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, NULL, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat2), 1 syn (syn12);
										}
	  	  						  	  else
	  	  						  	  	{ combwei=_Half*(assowei12+_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getNeuSynStr());
	  	  						  	  	  rec3Cat1Syn(1, 1, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(k), NULL, NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn12);
	  	  					  		  	}
	  	  						  	}									  
						  		}
					  	  	}
					  	}
					  rule2CatList=NULL;	// recollect rule2CatList;
			  		}
			  	}
			  rule1CatList=NULL;	// recollect rule1CatList;
	 		}
	  	}
	// check syn23;
	rule1CatList=NULL; rule1->FindCatListwithHighAsso(0, themrole1, rule1CatList);
	for(i=0;i<rule2->getCatNum();i++)
		{ if(rule2->getpCatList(i)->getThemRole()==themrole2)
			{ rule2CatList=rule2->getpCatList(i);
			  for(j=0;j<rule3->getCatNum();j++)
			  	{ if(rule3->getpCatList(j)->getThemRole()==themrole3)
			  		{ rule3CatList=rule3->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
	  				  	{ if((getpSynRuleList(k)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
					  		{ if(Chk1SynPer(type, 2, 1, getpSynRuleList(k)->getSynTyp())==1) 
					  		  	{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
								  comp2ret=CGenFuncClass::comp2values_big(rule2CatList->getAssoWei(), rule3CatList->getAssoWei());
								  if(comp2ret==1)
		  					  		{ if(rule1CatList==NULL)
		  					  			{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
		  						  		}
		  					 	 	  else
		  					  		  	{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
		  					  		  	}
		  						  	}
		  						  else if(comp2ret==2)
		  						  	{ if(rule1CatList==NULL)
		  						  		{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
		  						  		}
		  						  	  else
		  						  	  	{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
		  					  		  	}
		  						  	}
						  		}
					  		}
					  	  else if((getpSynRuleList(k)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	  	{ if(Chk1SynPer(type, 2, 2, getpSynRuleList(k)->getSynTyp())==1) 
					  		  	{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							 	  comp2ret=CGenFuncClass::comp2values_big(rule2CatList->getAssoWei(), rule3CatList->getAssoWei());
								  if(comp2ret==1)
		  					  		{ if(rule1CatList==NULL)
		  					  			{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  					  			  rec3Cat1Syn(1, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
		  						  		}
		  					 	 	  else
		  					  		  	{ combwei=_Half*(assowei23+_Half*(rule2CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
	  	  					  			  rec3Cat1Syn(1, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
		  					  		  	}
		  						  	}
		  						  else if(comp2ret==2)
		  						  	{ if(rule1CatList==NULL)
		  						  		{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 2, combwei, NULL, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat2, cat3), 1 syn (syn23);
		  						  		}
		  						  	  else
		  						  	  	{ combwei=_Half*(assowei23+_Half*(rule3CatList->getAssoWei()+rule1CatList->getAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 2, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(k), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn23);
		  					  		  	}
		  						  	}
						  		}
					  	  	}
	  					}
	  				  rule3CatList=NULL;	// recollect rule3CatList;
	  		  		}
	  		  	}
	  		  rule2CatList=NULL;	// recollect rule2CatList;
	  		}
	  	}
	// check syn13;
	rule2CatList=NULL; rule2->FindCatListwithHighAsso(0, themrole2, rule2CatList);
	for(i=0;i<rule1->getCatNum();i++)
		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
			  for(j=0;j<rule3->getCatNum();j++)
			  	{ if(rule3->getpCatList(j)->getThemRole()==themrole3)
			  		{ rule3CatList=rule3->getpCatList(j); 
					  for(k=0;k<getNumSynRule();k++)
					  	{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
					  		{ if(Chk1SynPer(type, 3, 1, getpSynRuleList(k)->getSynTyp())==1)
					  			{ assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule3CatList->getAssoWei());
								  if(comp2ret==1)
		  						  	{ if(rule2CatList==NULL)
		  					  			{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat3), 1 syn (syn13);
								  		}
		  					 	 	  else
		  					  		  	{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
										  rec3Cat1Syn(1, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
										}
		  						  	}
		  						  else if(comp2ret==2)
		  						  	{ if(rule2CatList==NULL)
		  						  		{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat3), 1 syn (syn13);
								  		}
		  						  	  else
		  						  	  	{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
										}
		  						  	}
						  		}
					  		}
					  	  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	  	{ if(Chk1SynPer(type, 3, 2, getpSynRuleList(k)->getSynTyp())==1)
					  			{ assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
								  comp2ret=CGenFuncClass::comp2values_big(rule1CatList->getAssoWei(), rule3CatList->getAssoWei());
								  if(comp2ret==1)
		  						  	{ if(rule2CatList==NULL)
		  					  			{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  					  			  rec3Cat1Syn(1, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat3), 1 syn (syn13);
								  		}
		  					 	 	  else
		  					  		  	{ combwei=_Half*(assowei13+_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
	  	  					  			  rec3Cat1Syn(1, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
										}
		  						  	}
		  						  else if(comp2ret==2)
		  						  	{ if(rule2CatList==NULL)
		  						  		{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+getNeuAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 3, combwei, rule1CatList, NULL, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 2 cats (cat1, cat3), 1 syn (syn13);
								  		}
		  						  	  else
		  						  	  	{ combwei=_Half*(assowei13+_Half*(rule3CatList->getAssoWei()+rule2CatList->getAssoWei())*getNeuSynStr());
	  	  						  		  rec3Cat1Syn(1, 3, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 1 syn (syn13);
										}
		  						  	}
						  		}
					  	  	}
					  	}
					  rule3CatList=NULL;	// recollect rule3CatList;
			  		}
			  	}
			  rule1CatList=NULL;	// recollect rule1CatList;
			}
		}	  	
}

bool CLTMem::Chk2SynPer(int order, int type, int subtype, int synTyp1, int synTyp2)
{ // check whether these 2 types of syntactic rules are consistent;
  // order=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);	
  // type=1(12, 23), 2(12, 13), 3(23, 13);
  // subtype=1, ++; 2, +-; 3, -+; 4, --;
	assert((3<=order)&&(order<=8)); assert((1<=type)&&(type<=3)); assert((1<=subtype)&&(subtype<=4));
  	bool value=0;
	if((subtype==3)||(subtype==4)) synTyp1=!synTyp1;
	if((subtype==2)||(subtype==4)) synTyp2=!synTyp2;
  	switch(order)
  		{ case 3: // SVO;
				if((type==1)&&(synTyp1==0)&&(synTyp2==0)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==0)&&(synTyp2==0)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==0)&&(synTyp2==0)) value=1;	// 23, 13;
				break;
		  case 4: // SOV;
				if((type==1)&&(synTyp1==0)&&(synTyp2==1)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==0)&&(synTyp2==0)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==1)&&(synTyp2==0)) value=1;	// 23, 13;
				break;
		  case 5: // OSV;
				if((type==1)&&(synTyp1==0)&&(synTyp2==1)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==0)&&(synTyp2==1)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==1)&&(synTyp2==1)) value=1;	// 23, 13;
				break;
		  case 6: // VSO;
				if((type==1)&&(synTyp1==1)&&(synTyp2==0)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==1)&&(synTyp2==0)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==0)&&(synTyp2==0)) value=1;	// 23, 13;
				break;
		  case 7: // VOS;
				if((type==1)&&(synTyp1==1)&&(synTyp2==0)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==1)&&(synTyp2==1)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==0)&&(synTyp2==1)) value=1;	// 23, 13;
				break;
		  case 8: // OVS;
				if((type==1)&&(synTyp1==1)&&(synTyp2==1)) value=1;	// 12, 23;
				else if((type==2)&&(synTyp1==1)&&(synTyp2==1)) value=1;	// 12, 13;
				else if((type==3)&&(synTyp1==1)&&(synTyp2==1)) value=1;	// 23, 13;
				break;
		  default: break;
  		}
	return value;
}
		  
void CLTMem::chk2ConsistSynPer(int cond, int type, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12case3syn, CSynRule *syn23case3syn, CSynRule *syn13case3syn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn)
{ // check if there are 2 consistent syntactic rules; 3 cats, 2 syn;
  // type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
  // case2synTyp=0, syn12, syn23, unique global order; 1, syn12, syn23, multiple global order;
  //			    2, syn12, syn13, unique global order; 3, syn12, syn23, multiple global order;
  //			    4, syn23, syn13, unique global order; 5, syn23, syn13, multiple global order;
  // cond = 0; not allow to choose already chosen syntactic rules in 3 syn and 2 syn case; 1, allow to choose already chosen syntactic rules;
  	assert((cond==1)||((cond==2)&&(syn12case3syn==NULL)&&(syn23case3syn==NULL)&&(syn13case3syn==NULL))); 
	assert((3<=type)&&(type<=8)); assert((rule1CatList!=NULL)&&(rule2CatList!=NULL)&&(rule3CatList!=NULL));
	int i, j, k;
	double combwei, assowei12, assowei23, assowei13;
	int case2synTyp;

	// check syn12, syn23;
	for(i=0;i<getNumSynRule();i++)
	 	{ if((getpSynRuleList(i)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(1)==rule2CatList->getpCat()))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(j=0;j<getNumSynRule();j++)
					{ if((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
							{ if(Chk2SynPer(type, 1, 1, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(j)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							   	  combwei=_Half*(assowei12+assowei23);
								  case2synTyp=-1; DecCase2synTypPer(1, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL);
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn23);
	  			  				}
							}
						}
					  else if((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
							{ if(Chk2SynPer(type, 1, 2, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(j)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							   	  combwei=_Half*(assowei12+assowei23);
								  case2synTyp=-1; DecCase2synTypPer(1, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL);
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn23);
	  			  				}
						  	}
					  	}
	  			  	}
				}
			}
		  else if((getpSynRuleList(i)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(0)==rule2CatList->getpCat()))
		  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(j=0;j<getNumSynRule();j++)
					{ if((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
							{ if(Chk2SynPer(type, 1, 3, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(j)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							   	  combwei=_Half*(assowei12+assowei23);
								  case2synTyp=-1; DecCase2synTypPer(1, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL);
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn23);
								}
		  					}
						}
					  else if((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
							{ if(Chk2SynPer(type, 1, 4, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(j)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							   	  combwei=_Half*(assowei12+assowei23);
								  case2synTyp=-1; DecCase2synTypPer(1, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL);
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), getpSynRuleList(j), NULL, relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn23);
	  			  				}
					  		}
					  	}
	  			  	}
		  		}
		  	}
		}		  		  
	// check syn12, syn13;
	for(i=0;i<getNumSynRule();i++)
	 	{ if((getpSynRuleList(i)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(1)==rule2CatList->getpCat()))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 2, 1, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei12+assowei13);
								  case2synTyp=-1; DecCase2synTypPer(2, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn13);
								}
	  				  		}
						}
					  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 2, 2, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei12+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(2, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn13);
								}
					  		}
	  			  		}
					}
				}
		   	}
		  else if((getpSynRuleList(i)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(i)->getpCat(0)==rule2CatList->getpCat()))
		  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(i)!=syn12case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 2, 3, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei12+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(2, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn13);
								}
		  					}
	  			  		}
					  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 2, 4, getpSynRuleList(i)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei12=_Half*(rule1CatList->getAssoWei()+rule2CatList->getAssoWei())*getpSynRuleList(i)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei12+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(2, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, getpSynRuleList(i), NULL, getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn12, syn13);
								}
					  		}
					  	}
		  			}
	  		  	}
		  	}
		}
	// check syn23, syn13;
	for(j=0;j<getNumSynRule();j++)
	 	{ if((getpSynRuleList(j)->getpCat(0)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(1)==rule3CatList->getpCat()))
			{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 3, 1, getpSynRuleList(j)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei23+assowei13);
								  case2synTyp=-1; DecCase2synTypPer(3, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn23, syn13);
								}
	  			  			}
						}
					  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 3, 2, getpSynRuleList(j)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei23+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(3, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn23, syn13);
								}
						  	}
					  	}
	  			  	}
				}
			}
		  else if((getpSynRuleList(j)->getpCat(1)==rule2CatList->getpCat())&&(getpSynRuleList(j)->getpCat(0)==rule3CatList->getpCat()))
		  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(j)!=syn23case3syn)))))
				{ for(k=0;k<getNumSynRule();k++)
					{ if((getpSynRuleList(k)->getpCat(0)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(1)==rule3CatList->getpCat()))
						{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 3, 3, getpSynRuleList(j)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei23+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(3, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn23, syn13);
								}
		  					}
	  			  		}
					  else if((getpSynRuleList(k)->getpCat(1)==rule1CatList->getpCat())&&(getpSynRuleList(k)->getpCat(0)==rule3CatList->getpCat()))
					  	{ if((cond==2)||((cond==1)&&((getChoIdentical()==1)||((getChoIdentical()==0)&&(getpSynRuleList(k)!=syn13case3syn)))))
							{ if(Chk2SynPer(type, 3, 4, getpSynRuleList(j)->getSynTyp(), getpSynRuleList(k)->getSynTyp())==1)
								{ assowei23=_Half*(rule2CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(j)->getSynStr();
							  	  assowei13=_Half*(rule1CatList->getAssoWei()+rule3CatList->getAssoWei())*getpSynRuleList(k)->getSynStr();
							  	  combwei=_Half*(assowei23+assowei13);
							  	  case2synTyp=-1; DecCase2synTypPer(3, type, &case2synTyp, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k));
								  rec3Cat2Syn(1, case2synTyp, combwei, rule1CatList, rule2CatList, rule3CatList, NULL, getpSynRuleList(j), getpSynRuleList(k), relaCatListSyn, numRelaCatListSyn);	// 3 cats, 2 syns (syn23, syn13);
								}
					  		}
					  	}
	  			  	}
		  		}
		  	}
		}
}
							  
void CLTMem::ChkRela3CatPer(int type, CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13)
{ // check category relation of 3 word rules;
  // type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);	
 	assert((3<=type)&&(type<=8)); assert((rule1!=NULL)&&(rule2!=NULL)&&(rule3!=NULL));
	int i, j, k;
	CatList *rule1CatList=NULL, *rule2CatList=NULL, *rule3CatList=NULL;
	CatList *catlist1case3syn=NULL, *catlist2case3syn=NULL, *catlist3case3syn=NULL, *catlist1case2syn=NULL, *catlist2case2syn=NULL, *catlist3case2syn=NULL;	// for temporary storing catlists in 3 synrule, 2 synrule cases;
	CSynRule *syn12case3syn=NULL, *syn23case3syn=NULL, *syn13case3syn=NULL, *syn1case2syn=NULL, *syn2case2syn=NULL, *syn12temp=NULL, *syn23temp=NULL, *syn13temp=NULL;	// for temporary storing synrule for 3 synrule case;
	double combWeicase1syn, combWeicase2syn, combWeicase3syn;	// store the combined strength in 2 and 3 syntactic rules cases;
	int case1synTyp;
	int case2synTyp;	// store the cases in the 2 consistent syntactic rules;
		// case2synTyp=0, syn12, syn23, unique global order; 1, syn12, syn23, multiple global order;
  		//			    2, syn12, syn13, unique global order; 3, syn12, syn23, multiple global order;
  		//			    4, syn23, syn13, unique global order; 5, syn23, syn13, multiple global order;
	int case3synTyp; 
	RelaCatListSyn **relaCatListSyn=NULL;
	int numRelaCatListSyn=0;
	
 	// check whether there are 3 consistent syntactic rules; 3 cats, 3 syn;
	relaCatListSyn=NULL; numRelaCatListSyn=0;
	for(i=0;i<rule1->getCatNum();i++)
		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
			{ rule1CatList=rule1->getpCatList(i);
			  for(j=0;j<rule2->getCatNum();j++)
				{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  	  		{ rule2CatList=rule2->getpCatList(j);
				  	  for(k=0;k<rule3->getCatNum();k++)
						{ if(rule3->getpCatList(k)->getThemRole()==themrole3)
							{ rule3CatList=rule3->getpCatList(k); 
							  chk3ConsistSyn(1, type, rule1CatList, rule2CatList, rule3CatList, relaCatListSyn, &numRelaCatListSyn);
							  rule3CatList=NULL;	// recollect rule3CatList;
				  			}
				  		}				  	  
				  	  rule2CatList=NULL;	// recollect rule2CatList;
			  		}
			  	}
			  rule1CatList=NULL;	// recollect rule1CatList;
	  		}
	  	}
	catlist1case3syn=NULL; catlist2case3syn=NULL; catlist3case3syn=NULL; 
	syn12case3syn=NULL; syn23case3syn=NULL; syn13case3syn=NULL;
	case3synTyp=-1; combWeicase3syn=0.0; 
	FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case3synTyp, &combWeicase3syn, catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn);	
	if((syn12case3syn!=NULL)&&(syn23case3syn!=NULL)&&(syn13case3syn!=NULL))
		{ // there are 3 consistent syntactic rules;
		  // check whether there are 2 consistent syntactic rules; 3 cats, 2 syns;
		  relaCatListSyn=NULL; numRelaCatListSyn=0;
		  for(i=0;i<rule1->getCatNum();i++)
	  		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
				{ rule1CatList=rule1->getpCatList(i);
	  	  		  for(j=0;j<rule2->getCatNum();j++)
	  	  		  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  		  		{ rule2CatList=rule2->getpCatList(j); 
	  					  for(k=0;k<rule3->getCatNum();k++)
	  						{ if(rule3->getpCatList(k)->getThemRole()==themrole3) 
	  							{ rule3CatList=rule3->getpCatList(k);
								  chk2ConsistSynPer(1, type, rule1CatList, rule2CatList, rule3CatList, syn12case3syn, syn23case3syn, syn13case3syn, relaCatListSyn, &numRelaCatListSyn);
							   	  rule3CatList=NULL;	// recollect rule3CatList;
	  					  		}
	  					  	}
	  					  rule2CatList=NULL;	// recollect rule2CatList;
	  	  		  		}
	  	  		  	}
	  	  		  rule1CatList=NULL;	// recollect rule1CatList;
		  		}
		  	}
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  case2synTyp=-1; combWeicase2syn=0.0; 
		  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case2synTyp, &combWeicase2syn, catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp);
		  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
		  	{ // there are 2 consistent syntactic rules;
			  syn1case2syn=NULL; syn2case2syn=NULL;
			  switch(case2synTyp)
			  	{ case 0: case 1: syn1case2syn=syn12temp; syn2case2syn=syn23temp; break;	// syn12, syn23;
			  	  case 2: case 3: syn1case2syn=syn12temp; syn2case2syn=syn13temp; break;	// syn12, syn13;
			  	  case 4: case 5: syn1case2syn=syn23temp; syn2case2syn=syn13temp; break;	// syn23, syn13;
				  default: break;
			  	};

			  // compare combWeicase3syn and combWeicase2syn;
			  if(FLOAT_BG_EQ(combWeicase3syn, combWeicase2syn))
			  	{ // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn;
			  	  catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
				  syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;
				}
			  else
			  	{ // two methods to select;
				  if(getPerComp2_3()==0)
				  	{ // method 1: use catlist1case2syn, catlist2case2syn, catlist3case2syn, syn1case2syn, syn2case2syn;
				  	  catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
					  switch(case2synTyp)
					  	{ case 0: case 1: syn12=syn1case2syn; syn23=syn2case2syn; syn13=NULL; break;	// syn12, syn23;
					  	  case 2: case 3: syn12=syn1case2syn; syn23=NULL; syn13=syn2case2syn; break;	// syn12, syn13;
				  		  case 4: case 5: syn12=NULL; syn23=syn1case2syn; syn13=syn2case2syn; break;	// syn23, syn13;
						  default: break;
				  		}
				  	}
				  else if(getPerComp2_3()==1)
				  	{ // method 2: check if case2syn leads to unique global word order; use catlist1case2syn, catlist2case2syn, catlist3case2syn, syn1case2syn, syn2case2syn;
					  switch(case2synTyp)
					 	{ // unique global order 
					 	  case 0: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
								syn12=syn1case2syn; syn23=syn2case2syn; syn13=NULL;
								break;	// syn12, syn23;
					 	  case 2: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
								syn12=syn1case2syn; syn23=NULL; syn13=syn2case2syn;
								break;	// syn12, syn13;
						  case 4: catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
								syn12=NULL; syn23=syn1case2syn; syn13=syn2case2syn; 
								break;	// syn23, syn13;
						  // multiple global orders;
						  case 1: case 3: case 5: // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn;
				  	  				catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
					  				syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;
									break;					  
					 	  default: break;
					 	}
				  	}
			  	}
			  syn1case2syn=NULL; syn2case2syn=NULL;	// recollect syn1case2syn, syn2case2syn;
		  	}
		  else if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			{ // there are no 2 consistent syntactic rules;
			  // use catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn as winning rules;
			  catlist1=catlist1case3syn; catlist2=catlist2case3syn; catlist3=catlist3case3syn;
			  syn12=syn12case3syn; syn23=syn23case3syn; syn13=syn13case3syn;			  
		  	}

		  // recollect catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp;
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL; 
		}
	else if((syn12case3syn==NULL)&&(syn23case3syn==NULL)&&(syn13case3syn==NULL))
	  	{ // there are no 3 consistent syntactic rules;
	  	  // check whether there are 2 consistent syntactic rules; 3 cats, 2 syns;
		  relaCatListSyn=NULL; numRelaCatListSyn=0;
		  for(i=0;i<rule1->getCatNum();i++)
	  		{ if(rule1->getpCatList(i)->getThemRole()==themrole1)
				{ rule1CatList=rule1->getpCatList(i);
	  	  		  for(j=0;j<rule2->getCatNum();j++)
	  	  		  	{ if(rule2->getpCatList(j)->getThemRole()==themrole2)
	  	  		  		{ rule2CatList=rule2->getpCatList(j); 
	  					  for(k=0;k<rule3->getCatNum();k++)
	  						{ if(rule3->getpCatList(k)->getThemRole()==themrole3) 
	  							{ rule3CatList=rule3->getpCatList(k);
								  chk2ConsistSynPer(2, type, rule1CatList, rule2CatList, rule3CatList, NULL, NULL, NULL, relaCatListSyn, &numRelaCatListSyn);
							   	  rule3CatList=NULL;	// recollect rule3CatList;
	  					  		}
	  					  	}
	  					  rule2CatList=NULL;	// recollect rule2CatList;
	  	  		  		}
	  	  		  	}
	  	  		  rule1CatList=NULL;	// recollect rule1CatList;
		  		}
		  	}
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  case2synTyp=-1; combWeicase2syn=0.0; 
		  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case2synTyp, &combWeicase2syn, catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp);
		  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
		  	{ // there are 2 consistent syntactic rules;
			  catlist1=catlist1case2syn; catlist2=catlist2case2syn; catlist3=catlist3case2syn;
			  switch(case2synTyp)
			  	{ case 0: case 1: syn12=syn12temp; syn23=syn23temp; syn13=NULL; break;	// syn12, syn23;
			  	  case 2: case 3: syn12=syn12temp; syn23=NULL; syn13=syn13temp; break;	// syn12, syn13;
				  case 4: case 5: syn12=NULL; syn23=syn23temp; syn13=syn13temp; break;	// syn23, syn13;
				  default: break;
				}
		  	}
		  else if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			{ // there are no 2 consistent syntactic rules;
			  // check whether there is 1 consistent syntactic rule; syn12 or syn23 or syn13;
			  relaCatListSyn=NULL; numRelaCatListSyn=0;
			  chk1ConsistSynPer(type, rule1, rule2, rule3, themrole1, themrole2, themrole3, relaCatListSyn, &numRelaCatListSyn);
			  catlist1=NULL; catlist2=NULL; catlist3=NULL; 
			  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
			  case1synTyp=-1; combWeicase1syn=0.0;
			  FindrelCatListSyn_Rela3Cat(relaCatListSyn, &numRelaCatListSyn, &case1synTyp, &combWeicase1syn, catlist1, catlist2, catlist3, syn12temp, syn23temp, syn13temp);	
			  if((syn12temp!=NULL)||(syn23temp!=NULL)||(syn13temp!=NULL))
			  	{ // there is 1 syntactic rule;
			  	  switch(case1synTyp)
			  	  	{ case 1: syn12=syn12temp; syn23=NULL; syn13=NULL; break;	// syn12;
			  	  	  case 2: syn12=NULL; syn23=syn23temp; syn13=NULL; break;	// syn23;
			  	  	  case 3: syn12=NULL; syn23=NULL; syn13=syn13temp; break;	// syn13;
			  	  	  default: break;
			  	  	}
			  	}
			  if((syn12temp==NULL)&&(syn23temp==NULL)&&(syn13temp==NULL))
			  	{ // there are no matching categories;
		  	  	  catlist1=NULL; rule1->FindCatListwithHighAsso(0, themrole1, catlist1);
		  	  	  catlist2=NULL; rule2->FindCatListwithHighAsso(0, themrole2, catlist2);
				  catlist3=NULL; rule3->FindCatListwithHighAsso(0, themrole3, catlist3);
			  	}

			  // recollect syn12temp, syn23temp, syn13temp;
			  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		  	}

		  // recollect catlist1case2syn, catlist2case2syn, catlist3case2syn, syn12temp, syn23temp, syn13temp;
		  catlist1case2syn=NULL; catlist2case2syn=NULL; catlist3case2syn=NULL;
		  syn12temp=NULL; syn23temp=NULL; syn13temp=NULL;
		}

	// recollect catlist1case3syn, catlist2case3syn, catlist3case3syn, syn12case3syn, syn23case3syn, syn13case3syn, combWeicase3syn;
	catlist1case3syn=NULL; catlist2case3syn=NULL; catlist3case3syn=NULL;
	syn12case3syn=NULL; syn23case3syn=NULL; syn13case3syn=NULL;	
}

bool CLTMem::chkSynCond1(int type, CatList *catlist1, CatList *catlist2, CSynRule *syn12)
{ // match syntactic rule: 2 lexical rules, 1 syntactic rule;
	assert((1<=type)&&(type<=17)); assert((catlist1!=NULL)&&(catlist2!=NULL)&&(syn12!=NULL));
	bool value=0;
	switch(type)
		{ case 1: case 3: case 4: case 5: case 9: case 12: case 15: if(syn12->ChkSynConsist(0, catlist1->getpCat(), catlist2->getpCat())==1) value=1; break;
		  case 2: case 6: case 7: case 8: case 10: case 13:case 16: if(syn12->ChkSynConsist(1, catlist1->getpCat(), catlist2->getpCat())==1) value=1; break;
		  case 11: case 14: case 17: if(syn12->ChkSynConsist(2, catlist1->getpCat(), catlist2->getpCat())==1) value=1; break;
		  default: break;
		}
	return value;
}

bool CLTMem::chkSynCond2(int type, CatList *catlist1, CatList *catlist2, CSynRule *syn12)
{ // match syntactic rule: 2 word rules, 1 syntactic rule;
	assert((2<=type)&&(type<=7)); assert((catlist1!=NULL)&&(catlist2!=NULL)&&(syn12!=NULL));
	bool value=0;
	if(((type==2)||(type==4)||(type==6))&&(syn12->ChkSynConsist(0, catlist1->getpCat(), catlist2->getpCat())==1)) value=1;
	else if(((type==3)||(type==5)||(type==7))&&(syn12->ChkSynConsist(1, catlist1->getpCat(), catlist2->getpCat())==1)) value=1;
	return value;
}

void CLTMem::updMatHolistRule(CLexRule *Holistrule, MatLexRule **&MatchLexRule, int *numMatchLexRule)
{ // update holistic rule into MatchLexRule;
	int i;
	MatLexRule **MatchLexRuletemp=NULL;
	int numnewMatchLexRule;

	if(*numMatchLexRule==0)
		{ // create new MatchLexRule; 
		  (*numMatchLexRule)++;
		  MatchLexRule=new MatLexRule * [*numMatchLexRule]; assert(MatchLexRule!=NULL);
		  MatchLexRule[0]=new MatLexRule; assert(MatchLexRule[0]!=NULL);
		  MatchLexRule[0]->m_pMatLexRule=Holistrule;
		  MatchLexRule[0]->m_nTag=1;	// for holistic rule, always chosen;
		  MatchLexRule[0]->m_nMatTyp=0;
		  MatchLexRule[0]->m_nMatNum=0;
		  MatchLexRule[0]->m_pMatLocStart=NULL; MatchLexRule[0]->m_pMatLocEnd=NULL;
		}
	else
		{ // no check whether Holistrule is already in MatchLexRule; 
		  numnewMatchLexRule=(*numMatchLexRule)+1;	// increase the current number of matchlexrule;
		  MatchLexRuletemp=new MatLexRule * [numnewMatchLexRule]; assert(MatchLexRuletemp!=NULL);
		  for(i=0;i<numnewMatchLexRule;i++)
		  	MatchLexRuletemp[i]=NULL;
		  for(i=0;i<numnewMatchLexRule-1;i++)
		  	MatchLexRuletemp[i]=MatchLexRule[i];
		  MatchLexRuletemp[numnewMatchLexRule-1]=new MatLexRule; assert(MatchLexRuletemp[numnewMatchLexRule-1]!=NULL);
		  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLexRule=Holistrule;
		  MatchLexRuletemp[numnewMatchLexRule-1]->m_nTag=1;	// for holistic rule, always chosen;
		  MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatTyp=0;
		  MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatNum=0;
		  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocStart=NULL; MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocEnd=NULL;
		  // delete original MatchLexRule;
		  delete [] MatchLexRule; MatchLexRule=NULL;
		  *numMatchLexRule=0;
		  // copy MatchLexRuletemp to MatchLexRule;
		  *numMatchLexRule=numnewMatchLexRule; MatchLexRule=MatchLexRuletemp;
		  MatchLexRuletemp=NULL;	// recollect MatchLexRuletemp;	
		}
}

void CLTMem::updMatCompRule(int type, CLexRule *comprule, MatLexRule **&MatchLexRule, int *numMatchLexRule, int mattype, int nummat, int start, int end)
{ // update compo rule into MatchLexRule; type=0, begin a new rule; type=1, begin a new match;
	assert((type==0)||(type==1));
	int i;
	int *locstarttemp=NULL, *locendtemp=NULL;
	MatLexRule **MatchLexRuletemp=NULL;
	int numnewMatchLexRule;

	if(type==0)
		{ if(*numMatchLexRule==0)
			{ (*numMatchLexRule)++;
			  MatchLexRule=new MatLexRule * [*numMatchLexRule]; assert(MatchLexRule!=NULL);
			  MatchLexRule[0]=new MatLexRule; assert(MatchLexRule[0]!=NULL);
			  MatchLexRule[0]->m_pMatLexRule=comprule;
			  MatchLexRule[0]->m_nTag=0;	// for compositional rule, at the beginning, not chosen;
			  MatchLexRule[0]->m_nMatTyp=mattype;
			  MatchLexRule[0]->m_nMatNum=nummat;
			  MatchLexRule[0]->m_pMatLocStart=new int [MatchLexRule[0]->m_nMatNum]; assert(MatchLexRule[0]->m_pMatLocStart!=NULL);
			  MatchLexRule[0]->m_pMatLocStart[0]=start;
			  MatchLexRule[0]->m_pMatLocEnd=new int [MatchLexRule[0]->m_nMatNum]; assert(MatchLexRule[0]->m_pMatLocEnd!=NULL);
			  MatchLexRule[0]->m_pMatLocEnd[0]=end;
			}
		else
			{ // no check whether comprule is already in MatchLexRule; 
			  numnewMatchLexRule=(*numMatchLexRule)+1;	// increase the current number of matchlexrule;
			  MatchLexRuletemp=new MatLexRule * [numnewMatchLexRule]; assert(MatchLexRuletemp!=NULL);
			  for(i=0;i<numnewMatchLexRule;i++)
			  	MatchLexRuletemp[i]=NULL;
			  for(i=0;i<numnewMatchLexRule-1;i++)
			  	MatchLexRuletemp[i]=MatchLexRule[i];
			  MatchLexRuletemp[numnewMatchLexRule-1]=new MatLexRule; assert(MatchLexRuletemp[numnewMatchLexRule-1]!=NULL);
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLexRule=comprule;
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_nTag=0;	// for compositional rule, at the beginning, not chosen;
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatTyp=mattype;
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatNum=nummat;
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocStart=new int [MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatNum]; assert(MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocStart!=NULL);
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocStart[0]=start;
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocEnd=new int [MatchLexRuletemp[numnewMatchLexRule-1]->m_nMatNum]; assert(MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocEnd!=NULL);
			  MatchLexRuletemp[numnewMatchLexRule-1]->m_pMatLocEnd[0]=end;
			  // delete original MatchLexRule;
			  delete [] MatchLexRule; MatchLexRule=NULL;
			  *numMatchLexRule=0;
			  // copy MatchLexRuletemp to MatchLexRule;
			  *numMatchLexRule=numnewMatchLexRule; MatchLexRule=MatchLexRuletemp;
			  MatchLexRuletemp=NULL;	// recollect MatchLexRuletemp;
			}
		}
	else if(type==1)
		{ // increase a matnum in MatchLexRule[*numMatchLexRule-1];
		  MatchLexRule[(*numMatchLexRule)-1]->m_nMatNum=nummat;
		  locstarttemp=new int [nummat]; assert(locstarttemp!=NULL);
		  locendtemp=new int [nummat]; assert(locendtemp!=NULL);
		  for(i=0;i<nummat;i++)
		  	{ locstarttemp[i]=-1; locendtemp[i]=-1; }
		  for(i=0;i<nummat-1;i++)
		  	{ locstarttemp[i]=MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocStart[i];
		  	  locendtemp[i]=MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocEnd[i];
		  	}
		  locstarttemp[nummat-1]=start; locendtemp[nummat-1]=end;
		  // delete original MatchLexRule[*numMatchLexRule-1]->m_pMatLocStart, MatchLexRule[*numMatchLexRule-1]->m_pMatLocEnd;
		  delete [] MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocStart; MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocStart=NULL;
		  MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocStart=locstarttemp;	// copy locstarttemp to MatchLexRule[*numMatchLexRule-1]->m_pMatLocStart;
		  delete [] MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocEnd; MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocEnd=NULL;
		  MatchLexRule[(*numMatchLexRule)-1]->m_pMatLocEnd=locendtemp;	// copy locendtemp to MatchLexRule[*numMatchLexRule-1]->m_pMatLocEnd;
		  locstarttemp=NULL, locendtemp=NULL;	// recollect locstarttemp, locendtemp;
		}	
}

void CLTMem::chkupdCompRule(int type, int subtype, int *numRule, CMeanUtter *MU, CLexRule *comprule, MatLexRule **&MatchLexRule, int *numMatchLexRule)
{ // check and upd compositional rule if they fully/partially matches the utterance;
  // MUtype=0, comtinuous; 1, separate;
  // type=2, subtype=1, Ag rule;
  // type=3, subtype=2, Pred1 rule;
  // type=4, subtype=3, Pred2 rule;
  // type=5, subtype=4, Pat rule;
  // type=6, subtype=0, AgPred phrase;
  // type=7, subtype=0, AgPat phrase;
  // type=8, subtype=0, PredPat phrase;
	assert((2<=type)&&(type<=8)); assert((0<=subtype)&&(subtype<=4));
  	assert((((type==6)||(type==7)||(type==8))&&(subtype==0))||((2<=type)&&(type<=5)&&(subtype==type-1)));
  	int i, j;
	int start, end, nummat;
	int lexrulelen;	// lexical rule's length;
	int leftlen, rightlen;
	int utterlen=MU->getUtterLen();
	
  	switch(type)
  		{ case 2: case 3: case 4: case 5: // Ag rule; Pred1 rule; Pred2 rule; Pat rule; 				
				 // continuous MU;
  				 lexrulelen=comprule->getpMeanUtter()->getUtterLen();
		  		 if(lexrulelen<utterlen)
		  		  	{ // check whether comprule partially matches meanutter's utter;
					  nummat=0;
		  			  for(i=0;i<utterlen-lexrulelen+1;i++)
		  			  	{ for(j=0;j<lexrulelen;j++)
		  			  		{ if(comprule->getpMeanUtter()->getpUtter()->getElement(j)!=MU->getpUtter()->getElement(i+j))
		  			  			break;
		  			  		}
		  			  	  if(j==lexrulelen)
		  			  	  	{ start=i; end=i+lexrulelen-1;	
							  nummat++;
							  if(nummat==1) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, subtype, nummat, start, end);
							  else updMatCompRule(1, comprule, MatchLexRule, numMatchLexRule, subtype, nummat, start, end);	
		  			  		}
		 	 		  	}
		 	 		  if(nummat!=0) (*numRule)++;
		 	 	  	}
		  		break;
		  case 6: case 7: case 8: // AgPred phrase; AgPat phrase; PredPat phrase;
		  		if((comprule->getLexTyp()==3)||(comprule->getLexTyp()==4)||(comprule->getLexTyp()==5))
		 	 		{ lexrulelen=comprule->getpMeanUtter()->getUtterLen();
					  if(lexrulelen<utterlen)
		  			  	{ // check whether comprule partially matches meanutter's utter;
						  nummat=0;
		  				  for(i=0;i<utterlen-lexrulelen+1;i++)
		  				  	{ for(j=0;j<lexrulelen;j++)
		  				  		{ if(comprule->getpMeanUtter()->getpUtter()->getElement(j)!=MU->getpUtter()->getElement(i+j))
		  				  			break;
		  				  		}
		  				  	  if(j==lexrulelen)
		  				  	  	{ start=i; end=i+lexrulelen-1;	
								  nummat++;
								  if(nummat==1) 
								  	{ if(type==6) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 5, nummat, start, end);
									  else if(type==7) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 6, nummat, start, end);
									  else if(type==8) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 7, nummat, start, end);	
								  	}
								  else 
								  	{ if(type==6) updMatCompRule(1, comprule, MatchLexRule, numMatchLexRule, 5, nummat, start, end);	
									  else if(type==7) updMatCompRule(1, comprule, MatchLexRule, numMatchLexRule, 6, nummat, start, end);	
									  else if(type==8) updMatCompRule(1, comprule, MatchLexRule, numMatchLexRule, 7, nummat, start, end);		
								  	}
								  }
		  				  	}
		  				  if(nummat!=0) (*numRule)++;
		  			  	}
		  			}
	 	  		else if((comprule->getLexTyp()==6)||(comprule->getLexTyp()==7)||(comprule->getLexTyp()==8))
	 	  		  	{ leftlen=comprule->getpMeanUtter()->getLeftUtterLen(); rightlen=comprule->getpMeanUtter()->getRightUtterLen();
	 	  		  	  if(leftlen+rightlen<utterlen)
	 	  		  	  	{ // check whether m_pLexRuleList[i] partially matches meanutter's utter;
						  for(i=0;i<leftlen;i++)
						  	{ if(comprule->getpMeanUtter()->getpUtter()->getElement(i)!=MU->getpUtter()->getElement(i))
						  		break;
						  	}
						  for(j=0;j<rightlen;j++)
						  	{ if(comprule->getpMeanUtter()->getpUtter()->getElement(comprule->getpMeanUtter()->getLengthIntgUtter()-rightlen+j)!=MU->getpUtter()->getElement(utterlen-rightlen+j))
						  		break;
						  	}
						  if((i==leftlen)&&(j==rightlen))
						  	{ start=leftlen-1; end=utterlen-rightlen;
							  if(type==6) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 8, 1, start, end);
							  else if(type==7) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 9, 1, start, end);
							  else if(type==8) updMatCompRule(0, comprule, MatchLexRule, numMatchLexRule, 10, 1, start, end);	
							  (*numRule)++;
	 	  		  	  	  	}
	 	  		  	  	}
	 	  			}
		  		break;
		  default: break;
  		}
}	

void CLTMem::GetCand(CSemSpace *semspace, CMeanUtter *meanutter, MatLexRule **&MatchLexRule, int *numMatchLexRule, int *numHolist, int *numAg, int *numPred1, int *numPred2, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat)
{ // get candidate lexical rules which can partially match the heard utterance;
	assert((semspace!=NULL)&&(meanutter!=NULL));
	int i;
	
	// gather candidate lexical rules;
	if(getNumLexRule()!=0)
		{ // check holistic rule;
		  for(i=0;i<getNumLexRule();i++)
			{ if(chk2SideMeanUtter(2, 1, meanutter, getpLexRuleList(i), semspace)==1)
		  		{ (*numHolist)++;
		  		  updMatHolistRule(getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		  		}
			}
		  // check Ag rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 2, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(2, 1, numAg, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		  	}
		  // check Pred1 rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 3, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(3, 2, numPred1, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		    	}
		  // check Pred2 rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 4, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(4, 3, numPred2, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		    	}
		  // check Pat rule;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 5, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(5, 4, numPat, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		   	}
		  // check AgPred phrase;
	 	  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 6, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(6, 0, numAgPred, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
	 	    	}
		  // check AgPat phrase;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 7, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(7, 0, numAgPat, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		    	}
		  // check PredPat phrase;
		  for(i=0;i<getNumLexRule();i++)
		  	{ if(chk2SideMeanUtter(2, 8, meanutter, getpLexRuleList(i), semspace)==1)
		  		chkupdCompRule(8, 0, numPredPat, meanutter, getpLexRuleList(i), MatchLexRule, numMatchLexRule);
		   	}		  
		}
}

// Synonym and Homonym avoidance;
void CLTMem::AvoidSynonym(int type, CLexRule *CurLexRule, CCat *CurCat, int adjmode)
{ // avoid synonyms; type=0, decrease; 1, increase;
	assert((CurLexRule!=NULL)&&(CurCat!=NULL)); assert((adjmode==0)||(adjmode==1));
	CLexRule *sameCatLex=NULL;
	int i, j, k;
	for(i=0;i<CurCat->getLexNum();i++)
		{ if((CurCat->getpLexRule(i)!=CurLexRule)&&(CurCat->getpLexRule(i)->getpMeanUtter()!=NULL))
			{ sameCatLex=CurCat->getpLexRule(i);
			  // first, make sure this lexical rule is in LexRuleList;
			  for(j=0;j<getNumLexRule();j++)
			  	{ if(getpLexRuleList(j)==sameCatLex)
			  		{ // check if sameCatLex is synonymous to CurLexRule; 
			  		  if((*(sameCatLex->getpMeanUtter()->getpMean())==*(CurLexRule->getpMeanUtter()->getpMean()))&&(*(sameCatLex->getpMeanUtter()->getpUtter())!=*(CurLexRule->getpMeanUtter()->getpUtter())))
			  		  	{ for(k=0;k<sameCatLex->getCatNum();k++)
			  		  		{ if(sameCatLex->getpCatList(k)->getpCat()==CurCat)
			  		  			{ if(type==0) sameCatLex->DecAssoWei(k, 0.0);
			  		  			  else if(type==1) sameCatLex->IncAssoWei(k, 0.0, adjmode);
			  		  			}
			  		  		}
			  		  	  sameCatLex->updLexRule(3);	// check if CatList[i]=NULL;
			  		  	}
			  		  break;
			  		}			  
			  	}
			  sameCatLex=NULL;	// recollect sameCatLex;
			}
		}
}

void CLTMem::AvoidHomonym(int type, CLexRule *CurLexRule, CCat *CurCat, int adjmode)
{ // avoid homonyms; type=0, decrease; 1, increase;
	assert((CurLexRule!=NULL)&&(CurCat!=NULL)); assert((adjmode==0)||(adjmode==1));
	CLexRule *sameCatLex=NULL;
	int i, j, k;
	for(i=0;i<CurCat->getLexNum();i++)
		{ if((CurCat->getpLexRule(i)!=CurLexRule)&&(CurCat->getpLexRule(i)->getpMeanUtter()!=NULL))
			{ sameCatLex=CurCat->getpLexRule(i);
			  // first, make sure this lexical rule is in LexRuleList;
			  for(j=0;j<getNumLexRule();j++)
			  	{ if(getpLexRuleList(j)==sameCatLex)
			  		{ // check if sameCatLex is homonymous to CurLexRule; 
			  		  if((*(sameCatLex->getpMeanUtter()->getpMean())!=*(CurLexRule->getpMeanUtter()->getpMean()))&&(*(sameCatLex->getpMeanUtter()->getpUtter())==*(CurLexRule->getpMeanUtter()->getpUtter())))
			  		  	{ for(k=0;k<sameCatLex->getCatNum();k++)
			  		  		{ if(sameCatLex->getpCatList(k)->getpCat()==CurCat)
			  		  			{ if(type==0) sameCatLex->DecAssoWei(k, 0.0);
			  		  			  else if(type==1) sameCatLex->IncAssoWei(k, 0.0, adjmode);
			  		  			}
			  		  		}
			  		  	  sameCatLex->updLexRule(3);	// check if CatList[i]=NULL;
			  		  	}
			  		  break;
			  		}
			  	}
			  sameCatLex=NULL;	// recollect sameCatLex;
			}
		}
}

void CLTMem::AvoidSyn(int type, CSynRule *CurSynRule, int adjmode)
{ // avoid similar syntactic rules; type=0, decrease; 1, increase;
	assert(CurSynRule!=NULL); assert((adjmode==0)||(adjmode==1));
	CSynRule *sameSyn=NULL;
	int i;
	for(i=0;i<getNumSynRule();i++)
		{ if((getpSynRuleList(i)!=CurSynRule)&&(getpSynRuleList(i)->getSynTyp()!=-1))
			{ sameSyn=getpSynRuleList(i);
			  // check if SynRuleList[i] is similar to CurSynRule;
			  if(((sameSyn->getpCat(0)==CurSynRule->getpCat(0))&&(sameSyn->getpCat(1)==CurSynRule->getpCat(1)))||((sameSyn->getpCat(0)==CurSynRule->getpCat(1))&&(sameSyn->getpCat(1)==CurSynRule->getpCat(0))))
			  	{ if(type==0) sameSyn->DecSynStr(0.0);	
			  	  else if(type==1) sameSyn->IncSynStr(0.0, adjmode);
			  	}
			  sameSyn=NULL;	// recollect sameSyn;
			}
		}
}

bool CLTMem::Judge_InLex(CLexRule *lexrule)
{ // check if lexrule is in LexRuleList;
	int i;
	bool value=0;
	if(lexrule!=NULL)
		{ for(i=0;i<getNumLexRule();i++)
			{ if(getpLexRuleList(i)==lexrule) { value=1; break; }
			}
		}
	return value;
}

bool CLTMem::Judge_InCat(CCat *cat)
{ // check if cat is in CatList;
	int i;
	bool value=0;
	if(cat!=NULL)
		{ for(i=0;i<getNumCat();i++)
			{ if(getpCatList(i)==cat) { value=1; break; }
			}
		}
	return value;
}

bool CLTMem::Judge_InSyn(CSynRule *synrule)
{ // check if synrule is in SynRuleList;
	int i;
	bool value=0;
	if(synrule!=NULL)
		{ for(i=0;i<getNumSynRule();i++) 
			{ if(getpSynRuleList(i)==synrule) { value=1; break; }
			}
		}
	return value;
}
		
// check recurrent meaning items;
double CLTMem::Factorial(int n)
{ // calculate n!;
  	if((n==0)||(n==1)) return 1;
	else return n*Factorial(n-1);
}

void CLTMem::CombinationM_N(int index, int **IndexMatrix, int IndexMatrixSize1, int IndexMatrixSize2, int oriM, int oriN, int curN, int m, int n)
{ // combinations of m out of n values; the indexes are stored in IndexMatrix;
	int i, j, curNo;
	
	if(m==1)
		{ for(i=index;i<index+oriN-(curN-1);i++)
			IndexMatrix[i][IndexMatrixSize2-m]=(curN-1)+i-index;
		}
	else
		{ for(i=curN;i<=oriN-m+1;i++)
			{ curNo=(int)(_Half+(Factorial(oriN-i))/(Factorial(m-1)*Factorial((oriN-i)-(m-1))));
		  	  for(j=index;j<index+curNo;j++)
		  		IndexMatrix[j][IndexMatrixSize2-m]=i-1;
		  	  CombinationM_N(index, IndexMatrix, IndexMatrixSize1, IndexMatrixSize2, oriM, oriN, i+1, m-1, n-1);
		  	  index+=curNo;
			}
		}
}

bool CLTMem::ChkAg(CMeanUtter **MUforComp, int sizeMUforComp)
{ // check Agent of multiple M-U mappings;
	assert(MUforComp!=NULL); assert(sizeMUforComp>=2);
	int i, j;
	int posAg=MUforComp[0]->getLengthSemRole();
	int lenSemItem=MUforComp[0]->getLengthSemItem();
	bool value=0;
	for(i=1;i<sizeMUforComp;i++)
		{ for(j=0;j<lenSemItem;j++)
			{ if(MUforComp[0]->getpMean()->getElement(j+posAg)!=MUforComp[i]->getpMean()->getElement(j+posAg)) break;
			}
		  if(j!=lenSemItem) break;
		}
	if((MUforComp[0]->getpMean()->getElement(posAg)!=-1)&&(i==sizeMUforComp)) value=1;
	return value;
}

bool CLTMem::ChkPred(CMeanUtter **MUforComp, int sizeMUforComp)
{ // check Predicate of multiple M-U mappings;
	assert(MUforComp!=NULL); assert(sizeMUforComp>=2);
	int i, j;
	int posPred=MUforComp[0]->getLengthSem()+MUforComp[0]->getLengthSemRole();
	int lenSemItem=MUforComp[0]->getLengthSemItem();
	bool value=0;
	for(i=1;i<sizeMUforComp;i++)
		{ for(j=0;j<lenSemItem;j++)
			{ if(MUforComp[0]->getpMean()->getElement(j+posPred)!=MUforComp[i]->getpMean()->getElement(j+posPred)) break;
			}
		  if(j!=lenSemItem) break;
		}
	if((MUforComp[0]->getpMean()->getElement(posPred)!=-1)&&(i==sizeMUforComp)) value=1;
	return value;
}

bool CLTMem::ChkPat(CMeanUtter **MUforComp, int sizeMUforComp)
{ // check Patient of multiple M-U mappings;
	assert(MUforComp!=NULL); assert(sizeMUforComp>=2);
	int i, j;
	int posPat=2*(MUforComp[0]->getLengthSem())+MUforComp[0]->getLengthSemRole();
	int lenSemItem=MUforComp[0]->getLengthSemItem();
	bool value=0;
	for(i=1;i<sizeMUforComp;i++)
		{ for(j=0;j<lenSemItem;j++)
			{ if(MUforComp[0]->getpMean()->getElement(j+posPat)!=MUforComp[i]->getpMean()->getElement(j+posPat)) break;
			}
		  if(j!=lenSemItem) break;
		}
	if((MUforComp[0]->getpMean()->getElement(posPat)!=-1)&&(i==sizeMUforComp)) value=1;
	return value;
}

bool CLTMem::ChkAg_Pat(CMeanUtter *temp1, CMeanUtter *temp2)
{ // check Agent/Patient or Patient/Agent;
	assert((temp1->getLengthIntgMean()==temp2->getLengthIntgMean())&&(temp1->getLengthIntgUtter()==temp2->getLengthIntgUtter()));
	assert((temp1->getpMean()->getElement(temp1->getLengthSemRole())!=-1)&&(temp2->getpMean()->getElement(2*(temp2->getLengthSem())+temp2->getLengthSemRole())!=-1));
	int i;
	int posAg=temp1->getLengthSemRole();
	int posPat=2*(temp1->getLengthSem())+temp1->getLengthSemRole();
	int lenSemItem=temp1->getLengthSemItem();
	bool value=0;
	for(i=0;i<lenSemItem;i++)
		{ if(temp1->getpMean()->getElement(i+posAg)!=temp2->getpMean()->getElement(i+posPat)) break;
		}
	if((temp1->getpMean()->getElement(posAg)!=-1)&&(temp2->getpMean()->getElement(posPat)!=-1)&&(i==lenSemItem)) value=1;
	return value;  
}

int CLTMem::chktypeMU_Mean(int type, CMeanUtter **MUforComp, int sizeMUforComp)
{ // check the M-U mappings' type; type=1, check holistic meanings; 2, check phrase meanings;
	assert((type==1)||(type==2)); assert(MUforComp!=NULL); assert(sizeMUforComp>=2);
	int i;
	int posAg=MUforComp[0]->getLengthSemRole();
	int posPred=MUforComp[0]->getLengthSem()+MUforComp[0]->getLengthSemRole();
	int posPat=2*(MUforComp[0]->getLengthSem())+MUforComp[0]->getLengthSemRole();
	int noPat, noAgPred, noAgPat, noPredPat;	// calculate the number of M-U mappings having Ag, Pred and Pat;
	int returnValue=0;	
		// for type=1; returnValue=1, all M-U mappings are "Pred<Ag>" meanings;
				// returnValue=2, all M-U mappings are "Pred<Ag, Pat>" meanings;
				// returnValue=3, some are "Pred<Ag>" meanings, some are "Pred<Ag, Pat>" meanings;
		// for type=2; returnValue=1, all M-U mappings are "Pred<Ag, #>" phrase meanings;
				// returnValue=2, all M-U mappings are "#<Ag, Pat>" phrase meanings;
				// returnValue=3, all M-U mappings are "Pred<#, Pat>" phrase meanings;
				// returnValue=4, some are "Pred<Ag, #>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
				// returnValue=5, some are "Pred<Ag, #>" phrase meanings, some are "Pred<#, Pat>" phrase meanings;
				// returnValue=6, some are "Pred<#, Pat>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
				// returnValue=0, for mixture;

	if(type==1)
		{ // check holistic meanings;
		  noPat=0;
		  for(i=0;i<sizeMUforComp;i++)
		  	{ if(MUforComp[i]->getpMean()->getElement(posPat)!=-1) noPat++;
		  	}
		  if(noPat==0) returnValue=1;	// all M-U mappings are "Pred<Ag>" meanings;
		  else if(noPat==sizeMUforComp) returnValue=2;	// all M-U mappings are "Pred<Ag, Pat>" meanings;
		  else returnValue=3;	// some are "Pred<Ag>" meanings, some are "Pred<Ag, Pat>" meanings;
		}
	else if(type==2)
		{ // check phrase meanings;
		  noAgPred=0; noAgPat=0; noPredPat=0;
		  for(i=0;i<sizeMUforComp;i++)
		  	{ if(MUforComp[i]->getpMean()->getElement(posAg)==-1) noPredPat++;
		  	  else if(MUforComp[i]->getpMean()->getElement(posPred)==-1) noAgPat++;
			  else if(MUforComp[i]->getpMean()->getElement(posPat)==-1) noAgPred++;
		  	}
		  if((noAgPred==sizeMUforComp)&&(noAgPat==0)&&(noPredPat==0)) returnValue=1;	// all M-U mappings are "Pred<Ag, #>" phrase meanings;
		  else if((noAgPred==0)&&(noAgPat==sizeMUforComp)&&(noPredPat==0)) returnValue=2;	// all M-U mappings are "#<Ag, Pat>" phrase meanings;
		  else if((noAgPred==0)&&(noAgPat==0)&&(noPredPat==sizeMUforComp)) returnValue=3;	// all M-U mappings are "Pred<#, Pat>" phrase meanings;
		  else
		   	{ if((noAgPred+noAgPat==sizeMUforComp)&&(noPredPat==0)) returnValue=4;	// some are "Pred<Ag, #>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
		   	  else if((noAgPred+noPredPat==sizeMUforComp)&&(noAgPat==0)) returnValue=5;	// some are "Pred<Ag, #>" phrase meanings, some are "Pred<#, Pat>" phrase meanings;
		   	  else if((noAgPat+noPredPat==sizeMUforComp)&&(noAgPred==0)) returnValue=6;	// some are "Pred<#, Pat>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
		  	}
		}
	return returnValue;
}

int CLTMem::DetRecMean(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp)
{ // detect recurrent pattern in meaning part of multiple M-U mappings;
	// -1, initial value, total same or no same at all;
  	// 0, Ag; 1, Pred; 2, Pat; 
  	// 3, Ag/Pat; 4, Pat/Ag;
  	// 5, AgPred; 6, AgPat; 7, PredPat;
  	// 8, Ag/Pat and Pred same; 9, Pat/Ag and Pred same; 
  	assert(MUforComp!=NULL); assert(typeMUforComp!=NULL); assert(sizeMUforComp>=2);
	int i, typeHolist_Phrase, typeMean, returnValue=-1;

	// check whether M-U mappings in MUforComp are all holistic or phrase mappings;
	typeHolist_Phrase=0;
	for(i=0;i<sizeMUforComp;i++)
		{ if((typeMUforComp[i]==0)||(typeMUforComp[i]==1)) typeHolist_Phrase=1;
		  else typeHolist_Phrase=2;
		}
	if(typeHolist_Phrase==1)
		{ // all M-U mappings in MUforComp are holistic meanings; 
		  typeMean=0; typeMean=chktypeMU_Mean(1, MUforComp, sizeMUforComp);	// check whether M-U mappings are all "Pred<Ag>" or "Pred<Ag, Pat>" meanings;
		  switch(typeMean)
		  	{ case 1: // all M-U mappings are "Pred<Ag>" meanings;
		  			if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
					else 
					  	{ if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=1;	// Pred;
					  	  else returnValue=-1;	// no same;
					  	}
					break;
			  case 2: // all M-U mappings are "Pred<Ag, Pat>" meanings;
					if(ChkAg(MUforComp, sizeMUforComp)==1)
					  	{ if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=5;	// AgPred;
						  else if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=6;	// AgPat;
						  else returnValue=0;	// Ag;
						}
					else
						{ if(sizeMUforComp==2)
							{ if(ChkAg_Pat(MUforComp[0], MUforComp[1])==1)
							  	{ if(ChkPred(MUforComp, sizeMUforComp)==1)
								  	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1) returnValue=10;	// reverse same;
								  	  else returnValue=8;	// Ag/Pat and Pred same;
								  	}
								  else returnValue=3;	// Ag/Pat;
							  	}
							  else
							  	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1)
								  	{ if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=9;	// Pat/Ag and Pred same;
								  	  else returnValue=4;	// Pat/Ag;
								  	}
								  else
								  	{ if(ChkPred(MUforComp, sizeMUforComp)==1)
								  	  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=7;	// PredPat;
								  		  else returnValue=1;	// Pred;	
								  	  	}
								  	  else
								  	  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=2;	// Pat;
								  		  else returnValue=-1;	// no same;
								  	  	}
								  	}
								}
							}
						  else
						  	{ if(ChkPred(MUforComp, sizeMUforComp)==1)
						  	  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=7;	// PredPat;
						  		  else returnValue=1;	// Pred;	
						  	  	}
						  	  else
						  	  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=2;	// Pat;
						  		  else returnValue=-1;	// no same;
						  	  	}
						  	}
						}
					break;
			  case 3: // some are "Pred<Ag>" meanings, some are "Pred<Ag, Pat>" meanings;
					if(sizeMUforComp==2)
						{ if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))!=-1)&&((MUforComp[1]->getpMean())->getElement(2*(MUforComp[1]->getLengthSem()))==-1))
							{ // MUforComp[0]: Predicate<Agent, Patient>; MUforComp[1]: Predicate<Agent>;
				  			  if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
				  			  else
							  	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1) returnValue=4;	// Pat/Ag;
							  	  else returnValue=-1;	// no same;
			  					}
							}
						  else if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))==-1)&&((MUforComp[1]->getpMean())->getElement(2*(MUforComp[1]->getLengthSem()))!=-1))
							{ // MUforComp[0]: Predicate<Agent>; MUforComp[1]: Predicate<Agent, Patient>;
			  				  if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
			  				  else
			  					{ if(ChkAg_Pat(MUforComp[0], MUforComp[1])==1) returnValue=3;	// Ag/Pat;
			  	  				  else returnValue=-1;	// no same;
			  					}
							}
						}
					else
						{ if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
						  else returnValue=-1;	// no same;
						}
			  		break;
			  default: break;		
		  	}
		}
	else if(typeHolist_Phrase==2)
		{ // all M-U mappings in MUforComp are phrase meanings;
		  if(sizeMUforComp==2)
		  	{ // this part keeps the original, no use returnValue; 
		  	  if(((MUforComp[0]->getpMean())->getElement(0)!=-1)&&((MUforComp[1]->getpMean())->getElement(0)!=-1))
			  	{ if(ChkAg(MUforComp, sizeMUforComp)==1) return 0;	// Ag;
			  	}
			  if(((MUforComp[0]->getpMean())->getElement(MUforComp[0]->getLengthSem())!=-1)&&((MUforComp[1]->getpMean())->getElement(MUforComp[1]->getLengthSem())!=-1))
			  	{ if(ChkPred(MUforComp, sizeMUforComp)==1) 
			  		{ if(((MUforComp[0]->getpMean())->getElement(0)!=-1)&&((MUforComp[1]->getpMean())->getElement(2*(MUforComp[1]->getLengthSem()))!=-1))
			  		  	{ if(ChkAg_Pat(MUforComp[0], MUforComp[1])==1) return 8;	// Ag/Pat and Pred same;
			  		  	  else return 1;	// Pred; 
			  			}
			  		  if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))!=-1)&&((MUforComp[1]->getpMean())->getElement(0)!=-1))
			  		  	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1) return 9;	// Pat/Ag and Pred same;
			  		  	  else return 1;	// Pred;
			  		  	}
			  		}
			  	}
			  if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))!=-1)&&((MUforComp[1]->getpMean())->getElement(2*(MUforComp[1]->getLengthSem()))!=-1))
			  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) return 2;	// Pat;
			  	}
			  if(((MUforComp[0]->getpMean())->getElement(0)!=-1)&&((MUforComp[1]->getpMean())->getElement(2*(MUforComp[1]->getLengthSem()))!=-1))
			    	{ if(ChkAg_Pat(MUforComp[0], MUforComp[1])==1) 
			    		{ if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))!=-1)&&((MUforComp[1]->getpMean())->getElement(0)!=-1))
					    	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1) return 10; // reverse same;
			 		 	}
			  	   	  return 3;	// Ag/Pat;
			  		}
			  	}
			  if(((MUforComp[0]->getpMean())->getElement(2*(MUforComp[0]->getLengthSem()))!=-1)&&((MUforComp[1]->getpMean())->getElement(0)!=-1))
			    	{ if(ChkAg_Pat(MUforComp[1], MUforComp[0])==1) return 4;	// Pat/Ag;
			  	}		  
			  return -1;
		  	}
		  else
		  	{ typeMean=0; typeMean=chktypeMU_Mean(2, MUforComp, sizeMUforComp);	// check whether M-U mappings are all "Pred<Ag, #>" or "#<Ag, Pat>" or "Pred<#, Pat>" phrase meanings;
		  	  switch(typeMean)
		  		{ case 1: // all M-U mappings are "Pred<Ag, #>" phrase meanings;
				  		if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
						else 
						  	{ if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=1;	// Pred;
					  		  else returnValue=-1;	// no same;
					  		}
						break;
				  case 2: // all M-U mappings are "#<Ag, Pat>" phrase meanings;
						if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
						else 
						  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=2;	// Pat;
					  		  else returnValue=-1;	// no same;
					  		}
				  		break;
				  case 3: // all M-U mappings are "Pred<#, Pat>" phrase meanings;
						if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=1;	// Pred;
						else 
						  	{ if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=2;	// Pat;
					  		  else returnValue=-1;	// no same;
					  		}
				  		break;
				  case 4: // some are "Pred<Ag, #>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
						if(ChkAg(MUforComp, sizeMUforComp)==1) returnValue=0;	// Ag;
						else returnValue=-1;	// no same;
				  		break;
				  case 5: // some are "Pred<Ag, #>" phrase meanings, some are "Pred<#, Pat>" phrase meanings;
						if(ChkPred(MUforComp, sizeMUforComp)==1) returnValue=1;	// Pred;
						else returnValue=-1;	// no same;
				  		break;
				  case 6: // some are "Pred<#, Pat>" phrase meanings, some are "#<Ag, Pat>" phrase meanings;
						if(ChkPat(MUforComp, sizeMUforComp)==1) returnValue=2;	// Pat;
						else returnValue=-1;	// no same;
				  		break;
				  default: break;	
		  		}
		  	}
		}
	return returnValue;
}

// check recurrent utterance syllables;
void CLTMem::updUtterPat(CArray *&newutter, CArray **&newutterpat, int *numutterpat)
{ // update newutter into newutterpat;
	assert(newutter!=NULL);
	int i, numnewutterpat;
	CArray **utterpattemp=NULL;
	
	if(*numutterpat==0)
		{ // create new newutterpat; 
		  (*numutterpat)++;
		  newutterpat=new CArray * [*numutterpat]; assert(newutterpat!=NULL);
		  newutterpat[0]=newutter;
		}
	else
		{ // check if newutter is same to some in newutterpat;
		  for(i=0;i<*numutterpat;i++)
			{ if(*(newutterpat[i])==*newutter)
				break;
			}
		  if(i==*numutterpat)
			{ // newutter is a new utterance pattern; 
			  numnewutterpat=(*numutterpat)+1;	// increase the current number of recutterpat;
			  utterpattemp=new CArray * [numnewutterpat]; assert(utterpattemp!=NULL);
			  for(i=0;i<numnewutterpat;i++)
			  	utterpattemp[i]=NULL;
			  for(i=0;i<numnewutterpat-1;i++)
		 	 	utterpattemp[i]=newutterpat[i];
			  utterpattemp[numnewutterpat-1]=newutter;
			  // delete original newutterpat;
			  delete [] newutterpat; newutterpat=NULL;
			  *numutterpat=0;
			  // copy utterpattemp to newutterpat;
			  *numutterpat=numnewutterpat; newutterpat=utterpattemp;
			  utterpattemp=NULL;	// recollect utterpattemp;
			}
		  else { delete newutter; newutter=NULL; }
		}
}

void CLTMem::setUtterLib(int type, CArray **&UtterLib, bool *&sameLoc, int *sizeUtterLib, int lenUtter, int start, int end, int lenUtterLibLow, int lenUtterLibUp, CMeanUtter *MU)
{ // set up UtterLib based on MU's utterance; type=1, continuous utterance; 2, separate utterance;
	assert(((type==1)&&(lenUtter>=2))||((type==2)&&(lenUtter>=3))); assert(MU!=NULL);	
	assert((0<=start)&&(start<MU->getLengthIntgUtter())); assert((0<=end)&&(end<MU->getLengthIntgUtter()));
	assert((0<lenUtter)&&(lenUtter<=MU->getLengthIntgUtter())); assert(end-start+1==lenUtter);
	int i, j, index;

	if(type==1)
		{ // continuous utterance;
		  *sizeUtterLib=(int)((lenUtterLibUp-lenUtterLibLow+1)*(lenUtter+1-lenUtterLibLow+lenUtter+1-lenUtterLibUp)/_Twice);
		  UtterLib=new CArray * [*sizeUtterLib]; assert(UtterLib!=NULL);
		  index=0;
		  for(i=lenUtterLibLow;i<=lenUtterLibUp;i++)
			{ for(j=start;j<start+lenUtter+1-i;j++)
				{ UtterLib[index]=new CArray (i); assert(UtterLib[index]!=NULL);
				  UtterLib[index]->setPartArray(MU->getpUtter(), 0, j, i);
				  index++;
				}
			}
		}
	else if(type==2)
		{ // separate utterance;
		  *sizeUtterLib=(int)((lenUtterLibUp-lenUtterLibLow+1)*(lenUtterLibLow-1+lenUtterLibUp-1)/_Twice);
		  UtterLib=new CArray * [*sizeUtterLib]; assert(UtterLib!=NULL);
		  index=0;
		  for(i=lenUtterLibLow;i<=lenUtterLibUp;i++)
		  	{ for(j=1;j<i;j++)
		  		{ UtterLib[index]=new CArray (MU->getLengthIntgUtter()); assert(UtterLib[index]!=NULL);
		  		  UtterLib[index]->setPartArray(MU->getpUtter(), 0, start, j);	// left part;
		  		  UtterLib[index]->setPartArray(MU->getpUtter(), MU->getLengthIntgUtter()-(i-j), end+1-(i-j), (i-j));	// right part;
				  index++;
		  		}
		  	}
		}
	sameLoc=new bool [*sizeUtterLib]; assert(sameLoc!=NULL);
	for(i=0;i<*sizeUtterLib;i++)
		sameLoc[i]=0;
}

void CLTMem::DetRecUtter(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp, int samemeantyp, CArray **&newutterpat, int *numutterpat)
{ // detect recurrent patterns in utterance part of multiple M-U mappings;
	assert(MUforComp!=NULL); assert(typeMUforComp!=NULL); assert(sizeMUforComp>=2); assert((samemeantyp!=-1)&&(samemeantyp!=10));
	CArray *newutter=NULL;
	int i, j, typeHolist_Phrase;
	CArray **UtterLib=NULL;	// store all possible utterance syllables that can be recurrent patterns;
	bool *sameLoc=NULL;	// store which utterance in UtterLib is shared;
	int sizeUtterLib, lenUtterLibLow, lenUtterLibUp;	// bound of UtterLib's length;
	int *lenUtter=NULL, *locleftUtter=NULL, *locrightUtter=NULL;
		
	*numutterpat=0;
	// check whether M-U mappings in MUforComp are all holistic or phrase mappings;
	typeHolist_Phrase=0;
	for(i=0;i<sizeMUforComp;i++)
		{ if((typeMUforComp[i]==0)||(typeMUforComp[i]==1)) typeHolist_Phrase=1;
		  else typeHolist_Phrase=2;
		}
	if(typeHolist_Phrase==1)
		{ // continuous utterance with holistic meanings;
		  lenUtter=new int [sizeMUforComp]; assert(lenUtter!=NULL);
		  for(i=0;i<sizeMUforComp;i++)
		  	lenUtter[i]=MUforComp[i]->getUtterLen();
		  locleftUtter=new int [sizeMUforComp]; assert(locleftUtter!=NULL);
		  for(i=0;i<sizeMUforComp;i++)
		  	locleftUtter[i]=0;
		  locrightUtter=new int [sizeMUforComp]; assert(locrightUtter!=NULL);
		  for(i=0;i<sizeMUforComp;i++)
		  	locrightUtter[i]=locleftUtter[i]+lenUtter[i]-1;

		  if((samemeantyp==0)||(samemeantyp==1)||(samemeantyp==2)||(samemeantyp==3)||(samemeantyp==4)||(samemeantyp==8)||(samemeantyp==9))
		  	{ // check continuous same utterance syllables (1 semantic item, at most word length);			  
			  if(lenUtter[0]>=2)
			  	{ sizeUtterLib=0; UtterLib=NULL; sameLoc=NULL; 
			  	  // for word rule, define the lower and upper bound of length; 
				  lenUtterLibLow=MUforComp[0]->getLengthWord()-2; 
				  if(MUforComp[0]->getpMean()->getElement(2*(MUforComp[0]->getLengthSem())+MUforComp[0]->getLengthSemRole())!=-1)
				  	{ // MUforComp[0]'s meaning is "Pred<Ag, Pat>";
					  if(MUforComp[0]->getLengthWord()>=lenUtter[0]-2)
					  	{ if(lenUtter[0]-2>=lenUtterLibLow) lenUtterLibUp=lenUtter[0]-2;
						  else lenUtterLibUp=lenUtterLibLow;
				  		}
				  	  else lenUtterLibUp=MUforComp[0]->getLengthWord();	
				  	}
				  else 
				  	{ // MUforComp[0]'s meaning is "Pred<Ag>";
					  if(MUforComp[0]->getLengthWord()>=lenUtter[0]-1)
					  	{ if(lenUtter[0]-1>=lenUtterLibLow) lenUtterLibUp=lenUtter[0]-1;
						  else lenUtterLibUp=lenUtterLibLow;
				  		}
				  	  else lenUtterLibUp=MUforComp[0]->getLengthWord();
				  	}				  			  
			  	  setUtterLib(1, UtterLib, sameLoc, &sizeUtterLib, lenUtter[0], locleftUtter[0], locrightUtter[0], lenUtterLibLow, lenUtterLibUp, MUforComp[0]);	// create UtterLib for MUforComp[0]'s utterance;
			  	  // check other M-U mappings in MUforComp to see if they share same utterance;
			  	  for(i=0;i<sizeUtterLib;i++)
				  	{ for(j=1;j<sizeMUforComp;j++)
			  			{ if(MUforComp[j]->getpMean()->getElement(2*(MUforComp[j]->getLengthSem())+MUforComp[j]->getLengthSemRole())!=-1) { if(MUforComp[j]->getpUtter()->containArray(2, lenUtter[j], locleftUtter[j], locrightUtter[j], UtterLib[i])==0) break; }
			  	  		  else { if(MUforComp[j]->getpUtter()->containArray(1, lenUtter[j], locleftUtter[j], locrightUtter[j], UtterLib[i])==0) break; }
			  			}
			  		  if(j==sizeMUforComp) { sameLoc[i]=1; }	// all other M-U mappings' utterance also contain the UtterLib[i] as recurrent patterns;
			  		}
				  // maximize the utterance syllables;
				  for(i=0;i<sizeUtterLib;i++)
				  	{ if(sameLoc[i]==1)
				  		{ for(j=i+1;j<sizeUtterLib;j++)
				  			{ if(sameLoc[j]==1) { if(UtterLib[j]->containArray(1, UtterLib[j]->getLengthArray(), 0, UtterLib[j]->getLengthArray()-1, UtterLib[i])==1) sameLoc[i]=0; }
				  			}
				  		}
				  	}
				  // copy the remaining utterance as recurrent pattern;
		 	  	  for(i=0;i<sizeUtterLib;i++)
		 	  	  	{ if(sameLoc[i]==1)
		 	  	  		{ newutter=new CArray (MUforComp[0]->getLengthIntgUtter()); assert(newutter!=NULL);
						  newutter->setPartArray(UtterLib[i], 0, 0, UtterLib[i]->getLengthArray());
						  updUtterPat(newutter, newutterpat, numutterpat);	// update newutter into newutterpat;
						  newutter=NULL;	// recollect newutter;
		 	  	  		}
		 	  	  	}

			  	  // delete UtterLib and sameLoc;
			  	  for(i=0;i<sizeUtterLib;i++)
				  	{ delete UtterLib[i]; UtterLib[i]=NULL; }
				  delete [] UtterLib; UtterLib=NULL;
				  delete [] sameLoc; sameLoc=NULL;
		  		}
		  	}
		  else if((samemeantyp==5)||(samemeantyp==6)||(samemeantyp==7))
		  	{ // first, check separate syllables (2 semantic items, at most phrase length);
			  if(lenUtter[0]>=3)
			  	{ sizeUtterLib=0; UtterLib=NULL; sameLoc=NULL; 
				  // for phrase rule, define the lower and upper bound of length;
				  lenUtterLibLow=MUforComp[0]->getLengthPhrase()-4;
				  if(MUforComp[0]->getLengthPhrase()>=lenUtter[0]-1)
				  	{ if(lenUtter[0]-1>=lenUtterLibLow) lenUtterLibUp=lenUtter[0]-1;
					  else lenUtterLibUp=lenUtterLibLow;
				  	}
				  else lenUtterLibUp=MUforComp[0]->getLengthPhrase();		
				  setUtterLib(2, UtterLib, sameLoc, &sizeUtterLib, lenUtter[0], locleftUtter[0], locrightUtter[0], lenUtterLibLow, lenUtterLibUp, MUforComp[0]);	// create UtterLib for MUforComp[0]'s utterance;
			  	  // check other M-U mappings in MUforComp to see if they share same utterance;
			  	  for(i=0;i<sizeUtterLib;i++)
				  	{ for(j=1;j<sizeMUforComp;j++)
			  			{ if(MUforComp[j]->getpUtter()->containArray(3, lenUtter[j], locleftUtter[j], locrightUtter[j], UtterLib[i])==0) break;
			  			}
			  		  if(j==sizeMUforComp) { sameLoc[i]=1; }	// all other M-U mappings' utterance also contain the UtterLib[i] as recurrent patterns;
			  		}
			  	  // maximize the utterance syllables;
			  	  for(i=0;i<sizeUtterLib;i++)
				  	{ if(sameLoc[i]==1)
				  		{ for(j=i+1;j<sizeUtterLib;j++)
				  			{ if(sameLoc[j]==1) { if(UtterLib[j]->containArray(4, UtterLib[j]->getLengthArray(), 0, UtterLib[j]->getLengthArray()-1, UtterLib[i])==1) sameLoc[i]=0; }
				  			}
				  		}
				  	}
				  // copy the remaining utterance as recurrent pattern;
	 		  	  for(i=0;i<sizeUtterLib;i++)
	 	  		  	{ if(sameLoc[i]==1)
	 	  		  		{ newutter=new CArray (MUforComp[0]->getLengthIntgUtter()); assert(newutter!=NULL);
						  newutter->setPartArray(UtterLib[i], 0, 0, UtterLib[i]->getLengthArray());
						  updUtterPat(newutter, newutterpat, numutterpat);	// update newutter into newutterpat;
						  newutter=NULL;	// recollect newutter;
						  // mask MUforComp with -1;
						  for(j=0;j<sizeMUforComp;j++)
						  	MUforComp[j]->getpUtter()->maskArray(lenUtter[j], UtterLib[i]);
	 	  	  			}
	 	  	  		}
			  	  // delete UtterLib and sameLoc;
			  	  for(i=0;i<sizeUtterLib;i++)
				  	{ delete UtterLib[i]; UtterLib[i]=NULL; }
				  delete [] UtterLib; UtterLib=NULL;
				  delete [] sameLoc; sameLoc=NULL;
			  
				  // then, check continuous syllables;
				  // recalculate lenUtter, locleftUtter, locrightUtter;
				  for(i=0;i<sizeMUforComp;i++)
				  	{ for(j=0;j<MUforComp[i]->getLengthIntgUtter();j++)
				  		{ if(MUforComp[i]->getpUtter()->getElement(j)!=-1) { locleftUtter[i]=j; break; }
				  		}
				  	  for(j=MUforComp[i]->getLengthIntgUtter()-1;j>=0;j--)
				  	  	{ if(MUforComp[i]->getpUtter()->getElement(j)!=-1) { locrightUtter[i]=j; break; }
				  	  	}
					  lenUtter[i]=locrightUtter[i]-locleftUtter[i]+1;
				  	}
				  
				  if(lenUtter[0]>=3)
				  	{ sizeUtterLib=0; UtterLib=NULL; sameLoc=NULL; 
					  // for phrase rule, define the lower and upper bound of length;
					  lenUtterLibLow=MUforComp[0]->getLengthPhrase()-4;
				  	  if(MUforComp[0]->getLengthPhrase()>=lenUtter[0]-1)
				  		{ if(lenUtter[0]-1>=lenUtterLibLow) lenUtterLibUp=lenUtter[0]-1;
					  	  else lenUtterLibUp=lenUtterLibLow;
				  		}
					  else lenUtterLibUp=MUforComp[0]->getLengthPhrase();	
				  	  setUtterLib(1, UtterLib, sameLoc, &sizeUtterLib, lenUtter[0], locleftUtter[0], locrightUtter[0], lenUtterLibLow, lenUtterLibUp, MUforComp[0]);	// create UtterLib for MUforComp[0]'s utterance;
				  	  // check other M-U mappings in MUforComp to see if they share same utterance;
				  	  for(i=0;i<sizeUtterLib;i++)
					  	{ for(j=1;j<sizeMUforComp;j++)
					  		{ if(MUforComp[j]->getpUtter()->containArray(1, lenUtter[j], locleftUtter[j], locrightUtter[j], UtterLib[i])==0) break;
					  		}
					  	  if(j==sizeMUforComp) { sameLoc[i]=1; }	// all other M-U mappings' utterance also contain the UtterLib[i] as recurrent patterns;
					  	}
					  // maximize the utterance syllables;
					  for(i=0;i<sizeUtterLib;i++)
					  	{ if(sameLoc[i]==1)
					  		{ for(j=i+1;j<sizeUtterLib;j++)
					  			{ if(sameLoc[j]==1) { if(UtterLib[j]->containArray(1, UtterLib[j]->getLengthArray(), 0, UtterLib[j]->getLengthArray()-1, UtterLib[i])==1) sameLoc[i]=0; }
					  			}
					  		}
					  	}
					  // copy the remaining utterance as recurrent pattern;
	 			  	  for(i=0;i<sizeUtterLib;i++)
	 			  	  	{ if(sameLoc[i]==1)
	 			  	  		{ newutter=new CArray (MUforComp[0]->getLengthIntgUtter()); assert(newutter!=NULL);
							  newutter->setPartArray(UtterLib[i], 0, 0, UtterLib[i]->getLengthArray());
							  updUtterPat(newutter, newutterpat, numutterpat);	// update newutter into newutterpat;
							  newutter=NULL;	// recollect newutter;
	 			  	  		}
	 			  	  	}
					  // delete UtterLib and sameLoc;
					  for(i=0;i<sizeUtterLib;i++)
					  	{ delete UtterLib[i]; UtterLib[i]=NULL; }
					  delete [] UtterLib; UtterLib=NULL;
					  delete [] sameLoc; sameLoc=NULL;
				  	}
		  		}
		  	}
		  
		  // delete lenUtter, locleftUtter, locrightUtter;
		  delete [] lenUtter; lenUtter=NULL;
		  delete [] locleftUtter; locleftUtter=NULL;
		  delete [] locrightUtter; locrightUtter=NULL;
		}
}
	
// detect recurrent patterns;
void CLTMem::updMeanUtter(CMeanUtter *&newMU, CMeanUtter **&newMUpat, int *numMUpat)
{ // update newMU into newMUpat;
	assert(newMU!=NULL);
	int i;
	CMeanUtter **MUtemp=NULL;
	int numnewMUpat;
	int delMUindex;
	
	if(*numMUpat==0)
		{ // create new newMU; 
		  (*numMUpat)++; 
		  newMUpat=new CMeanUtter * [*numMUpat]; assert(newMUpat!=NULL);
		  newMUpat[0]=newMU;
		}
	else if(*numMUpat==getMaxRecPat())
		{ // check if newMU is same to some in newMUpat;
		  for(i=0;i<*numMUpat;i++)
			{ if(*(newMUpat[i])==*newMU) break;
			}
		  if(i==*numMUpat)
		  	{ // randomly select a MU to replace;
		  	  do{ delMUindex=(int)(Rand0_1*(*numMUpat));
		  	  }while(delMUindex==*numMUpat);
			  delete newMUpat[delMUindex]; newMUpat[delMUindex]=NULL;
		  	  newMUpat[delMUindex]=newMU;
		  	}
		  else { delete newMU; newMU=NULL; }
		}
	else
		{ // check if newMU is same to some in newMUpat;
		  for(i=0;i<*numMUpat;i++)
			{ if(*(newMUpat[i])==*newMU) break;
			}
		  if(i==*numMUpat)
			{ // newMU is a new MU pattern; 
			  numnewMUpat=(*numMUpat)+1;	// increase the current number of newpat;
			  MUtemp=new CMeanUtter * [numnewMUpat]; assert(MUtemp!=NULL);
			  for(i=0;i<numnewMUpat;i++)
			  	MUtemp[i]=NULL;
			  for(i=0;i<numnewMUpat-1;i++)
		 	 	MUtemp[i]=newMUpat[i];
			  MUtemp[numnewMUpat-1]=newMU;
			  // delete original newMUpat;
			  delete [] newMUpat; newMUpat=NULL;
			  *numMUpat=0;
			  // copy MUtemp to newMU;
			  *numMUpat=numnewMUpat; newMUpat=MUtemp;
			  MUtemp=NULL;	// recollect MUtemp;
			}
		  else { delete newMU; newMU=NULL; }
		}
}

void CLTMem::CrtMeanUtter(double ChildAdultAbiRatio, double DetRecPatRate, int samemeantyp, CMeanUtter **MUforComp, int sizeMUforComp, CMeanUtter **&newMUpat, int *numMUpat, CArray **newutterpat, int numutterpat)
{ // according to samemeantyp to build up recurrent meanutter based on multiple M-U mappings;
  // samemeantyp=0, Ag; 1, Pred; 2, Pat; 
  // 3, Ag/Pat; 4, Pat/Ag;
  // 5, AgPred; 6, AgPat; 7, PredPat;
  // 8, Ag/Pat and Pred same; 9, Pat/Ag and Pred same; 
  // 10, reverse same;
	assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetRecPatRate))&(FLOAT_SM_EQ(DetRecPatRate, 1.0))); 
  	assert((samemeantyp!=-1)&&(samemeantyp!=10)); assert(MUforComp!=NULL); assert(sizeMUforComp>=2); assert(numutterpat!=0); 
  	int i;
	CMeanUtter *newMU=NULL;
	int posAg=MUforComp[0]->getLengthSemRole();
	int posPred=MUforComp[0]->getLengthSem()+MUforComp[0]->getLengthSemRole();
	int posPat=2*(MUforComp[0]->getLengthSem())+MUforComp[0]->getLengthSemRole();
  	int lenSemItem=MUforComp[0]->getLengthSemItem();
  	int lenPhrase=2*(MUforComp[0]->getLengthSem());
	
	switch(samemeantyp)
		{ case 0: case 3: // Ag or Ag/Pat;
				for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posAg, posAg, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}
				break;
		  case 1: // Pred;
		  		for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posPred, posPred, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}	
				break;
		  case 2: case 4: // Pat or Pat/Ag;
		  		for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ // for patient, still store in the location of Agent!
					  	  newMU=new CMeanUtter; assert(newMU!=NULL);
					   	  newMU->setPartMean(MUforComp[0]->getpMean(), posAg, posPat, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					   	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}
		  		break;
		  case 5: // AgPred;
		  		for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					 	  newMU->setPartMean(MUforComp[0]->getpMean(), 0, 0, lenPhrase);
					   	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}
		  		break;
		  case 6: // AgPat;
		  		for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), 0, 0, (int)(_Half*lenPhrase));	// Ag part;
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), lenPhrase, lenPhrase, (int)(_Half*lenPhrase));	// Pat part;
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}
		  		break;
		  case 7: // PredPat;
		  		for(i=0;i<numutterpat;i++)
					{ // for each recurrent pattern, decide whether record them;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), (int)(_Half*lenPhrase), (int)(_Half*lenPhrase), lenPhrase);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					}
		  		break;
		  case 8: // Ag/Pat and Pred same;
		  		for(i=0;i<numutterpat;i++)
		  			{ // for each recurrent pattern, decide whether record them;
					  // Ag/Pat;	
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posAg, posAg, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					  // Pred;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posPred, posPred, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
		  			}
		  	 	break;
		  case 9: // Pat/Ag and Pred same;
		  		for(i=0;i<numutterpat;i++)
		  			{ // for each recurrent pattern, decide whether record them;
					  // Pat/Ag;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posAg, posPat, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
					  	}
					  // Pred;
					  if(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetRecPatRate))
					  	{ newMU=new CMeanUtter; assert(newMU!=NULL);
					  	  newMU->setPartMean(MUforComp[0]->getpMean(), posPred, posPred, lenSemItem);
					  	  newMU->setpUtter(newutterpat[i]);
					  	  updMeanUtter(newMU, newMUpat, numMUpat);	// update newmeanutter into newpat;
					  	  newMU=NULL;	// recollect newmeanutter;
		  				}
		  			}
		  		break;
		  default: break;
		}
}

void CLTMem::AcqRecPat(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp, double ChildAdultAbiRatio, double DetRecPatRate, CMeanUtter **&newMUpat, int *numMUpat)
{ // detect recurrent patterns in M-U mappings in MUforComp;
 	assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetRecPatRate))&(FLOAT_SM_EQ(DetRecPatRate, 1.0))); 
	int i;
	bool sameMeanMUforComp;
	CArray **newutterpat=NULL;
	int numutterpat;
	int samemeantyp=-1;	// -1, initial value, no same;
		// 0, Ag; 1, Pred, 2, Pat; 
		// 3, Ag/Pat; 4, Pat/Ag; 
		// 5, AgPred; 6, AgPat; 7, PredPat;
  		// 8, Ag/Pat and Pred same; 9, Pat/Ag and Pred same; 
  		// 10, reverse same;

	sameMeanMUforComp=1;
	for(i=0;i<sizeMUforComp-1;i++)
		{ if(*(MUforComp[i]->getpMean())!=*(MUforComp[i+1]->getpMean())) { sameMeanMUforComp=0; break; }
		}
	if(sameMeanMUforComp==0)
		{ // meanings of M-U mappings in MUforComp are not all identical;
		  samemeantyp=DetRecMean(MUforComp, typeMUforComp, sizeMUforComp);	// detect whether there is recurrent pattern in mean part;
		  if((samemeantyp!=-1)&&(samemeantyp!=10)) 
			{ numutterpat=0; newutterpat=NULL; 
			  DetRecUtter(MUforComp, typeMUforComp, sizeMUforComp, samemeantyp, newutterpat, &numutterpat);
			  if(numutterpat!=0)
				{ CrtMeanUtter(ChildAdultAbiRatio, DetRecPatRate, samemeantyp, MUforComp, sizeMUforComp, newMUpat, numMUpat, newutterpat, numutterpat);	// there are recurrent patterns; according to samemeantyp to build up recurrent meanutter;
				  // delete newutterpat;
				  for(i=0;i<numutterpat;i++)
				  	{ delete newutterpat[i]; newutterpat[i]=NULL; }
				  delete [] newutterpat; newutterpat=NULL;
		 	  	}
		  	}
		}
}

void CLTMem::DetRecPat(int type, double ChildAdultAbiRatio, double DetRecPatRate, int NoDetRecPatExm, CBuffer *buf, CMeanUtter **&newMUpat, int *numMUpat)
{ // detect recurrent patterns; type=1, detect recurrent pattern after every communication; type=2, detect recurrent pattern when the buffer is full;
  	assert((type==1)||(type==2)); assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetRecPatRate))&(FLOAT_SM_EQ(DetRecPatRate, 1.0))); 
	assert(NoDetRecPatExm>=2); assert(buf!=NULL);
	int i, j;
	CMeanUtter **MUforComp=NULL;
	int *typeMUforComp=NULL, **IndexMatrix=NULL;	// typeMUforComp stores M-U mapping's type; // type=0, normal M-U mappings in buffer; 1, holistic rules in rule list; 2, continuous phrase rules; 3, separate phrase rules; IndexMatrix stores combinations' index in buffer;
	int sizeMUforComp, IndexMatrixSize1, IndexMatrixSize2, index, curN;
	
	if(buf->getCurBufSize()>=2)
		{ // at least there are 2 M-U mappings for comparing;
		  sizeMUforComp=0;
		  if(type==1)
			{ // type=1, detect recurrent pattern after every communication;
			  if(buf->getCurBufSize()<=NoDetRecPatExm)
			  	{ // M-U mappings in the buffer are less than NoDetRecPatExm;
				  // create MUforComp and typeMUforComp;
				  sizeMUforComp=buf->getCurBufSize();
				  MUforComp=new CMeanUtter * [sizeMUforComp]; assert(MUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
					{ MUforComp[i]=new CMeanUtter; assert(MUforComp[i]!=NULL); }
				  typeMUforComp=new int [sizeMUforComp]; assert(typeMUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
				  	typeMUforComp[i]=0;	// all M-U mappings in MUforComp are normal M-U mappings in buffer;
				  	
			 	  // put all M-U mappings into MUforComp;
				  MUforComp[0]->setpMean(buf->getpBuf(buf->getCurBufSize()-1)->getpMean()); MUforComp[0]->setpUtter(buf->getpBuf(buf->getCurBufSize()-1)->getpUtter());
				  for(i=1;i<sizeMUforComp;i++)
				  	{ MUforComp[i]->setpMean(buf->getpBuf(i-1)->getpMean()); MUforComp[i]->setpUtter(buf->getpBuf(i-1)->getpUtter()); }
				  AcqRecPat(MUforComp, typeMUforComp, sizeMUforComp, ChildAdultAbiRatio, DetRecPatRate, newMUpat, numMUpat);	// detection of recurrent patterns;
				}
		  	  else
			  	{ // M-U mappings in the buffer are more than NoDetRecPatExm;
			  	  // create MUforComp and typeMUforComp;
			  	  sizeMUforComp=NoDetRecPatExm;
				  MUforComp=new CMeanUtter * [sizeMUforComp]; assert(MUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
					{ MUforComp[i]=new CMeanUtter; assert(MUforComp[i]!=NULL); }
				  typeMUforComp=new int [sizeMUforComp]; assert(typeMUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
				  	typeMUforComp[i]=0;	// all M-U mappings in MUforComp are normal M-U mappings in buffer;

				  // create IndexMatrix;
				  IndexMatrixSize1=(int)(_Half+Factorial(buf->getCurBufSize()-1)/(Factorial(sizeMUforComp-1)*Factorial(buf->getCurBufSize()-sizeMUforComp))); 
				  IndexMatrixSize2=sizeMUforComp-1;
				  IndexMatrix=new int * [IndexMatrixSize1]; assert(IndexMatrix!=NULL);
				  for(i=0;i<IndexMatrixSize1;i++)
		 		  	{ IndexMatrix[i]=new int [IndexMatrixSize2]; assert(IndexMatrix[i]!=NULL);
				  	  for(j=0;j<IndexMatrixSize2;j++)
					  	IndexMatrix[i][j]=-1;
				  	}
				  index=0; curN=1; CombinationM_N(index, IndexMatrix, IndexMatrixSize1, IndexMatrixSize2, sizeMUforComp-1, buf->getCurBufSize()-1, curN, sizeMUforComp-1, buf->getCurBufSize()-1);

				  // for each combinations, detect recurrent patterns;
				  for(i=0;i<IndexMatrixSize1;i++)
				  	{ MUforComp[0]->setpMean(buf->getpBuf(buf->getCurBufSize()-1)->getpMean()); MUforComp[0]->setpUtter(buf->getpBuf(buf->getCurBufSize()-1)->getpUtter());
				    	  for(j=1;j<sizeMUforComp;j++)
				  		{ MUforComp[j]->setpMean(buf->getpBuf(IndexMatrix[i][j-1])->getpMean()); MUforComp[j]->setpUtter(buf->getpBuf(IndexMatrix[i][j-1])->getpUtter()); }
					  AcqRecPat(MUforComp, typeMUforComp, sizeMUforComp, ChildAdultAbiRatio, DetRecPatRate, newMUpat, numMUpat);	// detection of recurrent patterns;
				  	}

				  // delete IndexMatrix;
				  for(i=0;i<IndexMatrixSize1;i++)
				  	{ delete [] IndexMatrix[i]; IndexMatrix[i]=NULL; }
				  delete [] IndexMatrix; IndexMatrix=NULL;
			  	}			  
			}
		 else if(type==2)
			{ // type=2, detect recurrent pattern when the buffer is full;
			  if(buf->getCurBufSize()<=NoDetRecPatExm)
			  	{ // M-U mappings in the buffer are less than NoDetRecPatExm;
				  // create MUforComp and typeMUforComp;
				  sizeMUforComp=buf->getCurBufSize();
				  MUforComp=new CMeanUtter * [sizeMUforComp]; assert(MUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
					{ MUforComp[i]=new CMeanUtter; assert(MUforComp[i]!=NULL); }
			 	  typeMUforComp=new int [sizeMUforComp]; assert(typeMUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
				  	typeMUforComp[i]=0;	// all M-U mappings in MUforComp are normal M-U mappings in buffer;

				  // put all M-U mappings into MUforComp;
				  for(i=0;i<sizeMUforComp;i++)
				  	{ MUforComp[i]->setpMean(buf->getpBuf(i)->getpMean()); MUforComp[i]->setpUtter(buf->getpBuf(i)->getpUtter()); }
				  AcqRecPat(MUforComp, typeMUforComp, sizeMUforComp, ChildAdultAbiRatio, DetRecPatRate, newMUpat, numMUpat);	// detection of recurrent patterns;
			  	}
			  else
			  	{ // M-U mappings in the buffer are more than NoDetRecPatExm;
				  // create MUforComp and typeMUforComp;
				  sizeMUforComp=NoDetRecPatExm;
				  MUforComp=new CMeanUtter * [sizeMUforComp]; assert(MUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
					{ MUforComp[i]=new CMeanUtter; assert(MUforComp[i]!=NULL); }
				  typeMUforComp=new int [sizeMUforComp]; assert(typeMUforComp!=NULL);
				  for(i=0;i<sizeMUforComp;i++)
				  	typeMUforComp[i]=0;	// all M-U mappings in MUforComp are normal M-U mappings in buffer;

				  // create IndexMatrix;
				  IndexMatrixSize1=(int)(_Half+Factorial(buf->getCurBufSize())/(Factorial(sizeMUforComp)*Factorial(buf->getCurBufSize()-sizeMUforComp))); 
				  IndexMatrixSize2=sizeMUforComp;
				  IndexMatrix=new int * [IndexMatrixSize1]; assert(IndexMatrix!=NULL);
				  for(i=0;i<IndexMatrixSize1;i++)
	 			  	{ IndexMatrix[i]=new int [IndexMatrixSize2]; assert(IndexMatrix[i]!=NULL);
				  	  for(j=0;j<IndexMatrixSize2;j++)
					  	IndexMatrix[i][j]=-1;
				  	}
				  index=0; curN=1; CombinationM_N(index, IndexMatrix, IndexMatrixSize1, IndexMatrixSize2, sizeMUforComp, buf->getCurBufSize(), curN, sizeMUforComp, buf->getCurBufSize());

				  // for each combinations, detect recurrent patterns;
				  for(i=0;i<IndexMatrixSize1;i++)
				  	{ for(j=0;j<sizeMUforComp;j++)
				  		{ MUforComp[j]->setpMean(buf->getpBuf(IndexMatrix[i][j])->getpMean()); MUforComp[j]->setpUtter(buf->getpBuf(IndexMatrix[i][j])->getpUtter()); }
					  AcqRecPat(MUforComp, typeMUforComp, sizeMUforComp, ChildAdultAbiRatio, DetRecPatRate, newMUpat, numMUpat);	// detection of recurrent patterns;
				    	}

				  // delete IndexMatrix;
				  for(i=0;i<IndexMatrixSize1;i++)
				  	{ delete [] IndexMatrix[i]; IndexMatrix[i]=NULL; }
				  delete [] IndexMatrix; IndexMatrix=NULL;
			  	}		  
			}
		  // delete MUforComp and typeMUforComp;
		  for(i=0;i<sizeMUforComp;i++)
			{ delete MUforComp[i]; MUforComp[i]=NULL; }
		  delete [] MUforComp; MUforComp=NULL;
		  delete [] typeMUforComp; typeMUforComp=NULL;
		}
}

int CLTMem::ChkCompMUTyp(CMeanUtter *MU)
{ // check MU's type: -1: default value, only for compositional MU;
  // 0: holistic rule for "Predicate<Agent>" or "Predicate<Agent, Patient>"; 
  // 1: word rule "Ag/Pat"; 2: word rule "Pred";
  // 3: continuous phrase AgPred; 4: continueous phrase AgPat; 5: continuous phrase PredPat;
  // 6: seperate phrase AgPred; 7: separate phrase AgPat; 8: separate phrase PredPat; 
	assert(MU!=NULL);
  	int meanjudge1, meanjudge2, meanjudge3, utterjudge;
  	int posAg=MU->getLengthSemRole();
  	int posPred=MU->getLengthSem()+MU->getLengthSemRole();
  	int posPat=2*(MU->getLengthSem())+MU->getLengthSemRole();
  	int value=-1;
  	
	meanjudge1=((MU->getpMean())->getElement(posAg)!=-1)?1:0;
	meanjudge2=((MU->getpMean())->getElement(posPred)!=-1)?1:0;
	meanjudge3=((MU->getpMean())->getElement(posPat)!=-1)?1:0;
	utterjudge=((MU->getpUtter())->getElement(MU->getLengthIntgUtter()-1)!=-1)?1:0;
	if(utterjudge==1)
		{ // must be holistic rule or separate phrase rule;
		  if((meanjudge1==1)&&(meanjudge2==1)&&(meanjudge3==1)) value=0; 	
		  else if((meanjudge1==1)&&(meanjudge2==1)&&(meanjudge3==0)) value=6;
		  else if((meanjudge1==1)&&(meanjudge2==0)&&(meanjudge3==1)) value=7;
		  else if((meanjudge1==0)&&(meanjudge2==1)&&(meanjudge3==1)) value=8;
		}
	else 
		{ // must be holistic rule or continuous phrase or word rules;
		  if((meanjudge1==1)&&(meanjudge2==1)&&(meanjudge3==1)) value=0; 	
		  else if((meanjudge1==1)&&(meanjudge2==0)&&(meanjudge3==0)) value=1;	// Ag/Pat;
		  else if((meanjudge1==0)&&(meanjudge2==1)&&(meanjudge3==0)) value=2;
		  else if((meanjudge1==1)&&(meanjudge2==1)&&(meanjudge3==0)) value=3;
		  else if((meanjudge1==1)&&(meanjudge2==0)&&(meanjudge3==1)) value=4;
		  else if((meanjudge1==0)&&(meanjudge2==1)&&(meanjudge3==1)) value=5;
		}
	return value;
}

void CLTMem::InCompLexRule(CMeanUtter **&newMUpat, int *numMupat)
{ // update new compositional MU mappings into lexical rule list;
	assert(((*numMupat)!=0)&&(newMUpat!=NULL));
	int i, j, lextyp;
	CLexRule *newLex=NULL;
	
	for(i=0;i<*numMupat;i++)
		{ for(j=0;j<getNumLexRule();j++)
			{ // check whether newMUpat is equal to some lexical rule's meanutter;
			  if(*(newMUpat[i])==*(getpLexRuleList(j)->getpMeanUtter())) break;
			}
		  if(j==getNumLexRule())
		  	{ // this is a new MU, update it as a lexical rule without any category;
			  newLex=new CLexRule; assert(newLex!=NULL);
			  newLex->setpMeanUtter(newMUpat[i]);	// set up newLex's meanutter;
			  lextyp=-1; lextyp=ChkCompMUTyp(newMUpat[i]);
			  assert((lextyp!=0)&&(lextyp!=-1));
			  newLex->setLexTyp(lextyp);	// set up newLex's type;			
			  newLex->setLexStr(newLex->getInitLexRuleStr());	// set up newLex's str;
			  InLexRule(newLex);	// insert newLex;
			  newLex=NULL;	// recollect newLex;
		  	}
		}	
}

// category and syntactic rule forming based on M-U mappings in the buffer;
void CLTMem::updMUmatSet(MUmatSet *&MUmatSettemp, MUmatSet **&newMUmatSet, int *numMUmatSet)
{ // update MUmatSettemp into newMUmatSet;
	assert(MUmatSettemp!=NULL);
  	int i, j, k;
	MUmatSet **newMUmatSettemp=NULL;
	int numnewMUmatSet;
	bool same;

	if(*numMUmatSet==0) 
		{ // create new newMUmatSet; 
		  (*numMUmatSet)++;
		  newMUmatSet=new MUmatSet * [*numMUmatSet]; assert(newMUmatSet!=NULL);
		  newMUmatSet[0]=MUmatSettemp;
		}
	else
		{ // check whether MUmatSettemp is already in newMumatSet;
		  same=0;	
		  for(i=0;i<*numMUmatSet;i++)
		  	{ if((newMUmatSet[i]->m_nNumLexRule==MUmatSettemp->m_nNumLexRule)&&(newMUmatSet[i]->m_nNumMatSynTyp==MUmatSettemp->m_nNumMatSynTyp)) 
		  		{ for(j=0;j<MUmatSettemp->m_nNumLexRule;j++)
		  			{ if(newMUmatSet[i]->m_ppMatLexRule[j]!=MUmatSettemp->m_ppMatLexRule[j])
		  				break;
		  			}
		  		  if(j==MUmatSettemp->m_nNumLexRule)
		  		  	{ for(k=0;k<MUmatSettemp->m_nNumMatSynTyp;k++)
		  		  		{ if(*(newMUmatSet[i]->m_pMatSynTyp+k)!=*(MUmatSettemp->m_pMatSynTyp+k))
		  		  			break;
		  		  		}
		  		  	  if(k==MUmatSettemp->m_nNumMatSynTyp) same=1;
		  		  	}
		  		}		  	
		  	}
		  if(same==0)
		  	{ // new MUmatSet; 
		  	  numnewMUmatSet=(*numMUmatSet)+1;
		  	  newMUmatSettemp=new MUmatSet * [numnewMUmatSet]; assert(newMUmatSettemp!=NULL);
			  for(i=0;i<numnewMUmatSet;i++)
			  	newMUmatSettemp[i]=NULL;
		  	  for(i=0;i<numnewMUmatSet-1;i++)
		  		newMUmatSettemp[i]=newMUmatSet[i];
		  	  newMUmatSettemp[numnewMUmatSet-1]=MUmatSettemp;
		  	  // delete original newMUmatSet;
		  	  delete [] newMUmatSet; newMUmatSet=NULL;
		  	  *numMUmatSet=0;
		  	  // copy newMUmatSettemp to newMUmatSet;
		  	  *numMUmatSet=numnewMUmatSet; newMUmatSet=newMUmatSettemp;
		  	  newMUmatSettemp=NULL;	// recollect newMUmatSettemp;
			}
		  else { delete MUmatSettemp; MUmatSettemp=NULL; }
		}
}

void CLTMem::setupMUmatSet(int type, int order, bool *comp, CLexRule *lexrule1, CLexRule *lexrule2, CLexRule *lexrule3, MUmatSet **&newMUmatSet, int *numMUmatSet)
{ // set up members in MUmatSet;
  // type=1, word Ag + word Pred1 for "Predicate<Agent>" meaning;
  	// order=1, SV;
  	// order=2, VS;
  // type=2, word Ag + word Pred2 + word Pat for "Predicate<Agent, Patient>" meaning;	
  	// order=3, SVO;
  	// order=4, SOV;
  	// order=5, OSV;
  	// order=6, VSO;
  	// order=7, VOS;
  	// order=8, OVS;
  // type=3, word + phrase for "Predicate<Agent, Patient>" meaning;
  	// order=9, word before phhrase;
  	// order=10, word after phrase;
  	// order=11, word in between phrase;
  // type=4, 2 word rules for "Predicate<Agent, Patient>" meaning;
  	// order=9, word 1 before word 2;
  	// order=10, word 1 after word 2;
  // in type=1, 2, 3, comp=1; meaning part is fully matched;
  // in type=4, comp=0; meaning part is partially matched;
  	assert(((type==1)&&(1<=order)&&(order<=2)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL))||((type==2)&&(3<=order)&&(order<=8)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3!=NULL))||((type==3)&&(9<=order)&&(order<=11)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL))||((type==4)&&(9<=order)&&(order<=10)&&(lexrule1!=NULL)&&(lexrule2!=NULL)&&(lexrule3==NULL)));
	MUmatSet *MUmatSettemp=NULL;

	// initialize MUmatSettemp;
	MUmatSettemp=new MUmatSet; assert(MUmatSettemp!=NULL);
	// set up members;
	switch(type)
		{ case 1: // word Ag + word Pred1;
				// matched lexical rules;
				MUmatSettemp->m_nNumLexRule=2;
				MUmatSettemp->m_ppMatLexRule=new CLexRule * [MUmatSettemp->m_nNumLexRule]; assert(MUmatSettemp->m_ppMatLexRule!=NULL);
			 	MUmatSettemp->m_ppMatLexRule[0]=lexrule1; MUmatSettemp->m_ppMatLexRule[1]=lexrule2;
				// matched types;
				MUmatSettemp->m_nNumMatSynTyp=1;
				MUmatSettemp->m_pMatSynTyp=new int [MUmatSettemp->m_nNumMatSynTyp]; assert(MUmatSettemp->m_pMatSynTyp!=NULL);
				switch(order)
					{ case 1: MUmatSettemp->m_pMatSynTyp[0]=0; break;	// SV(1), S before V;							
					  case 2: MUmatSettemp->m_pMatSynTyp[0]=1; break;	// VS(2), S after V;
					  default: break;
					}
				*comp=1;	// meaning part is fully matched;
				break;
		  case 2: // word Ag + word Pred2 + word Pat;
				// matched lexical rules;
				MUmatSettemp->m_nNumLexRule=3;
				MUmatSettemp->m_ppMatLexRule=new CLexRule * [MUmatSettemp->m_nNumLexRule]; assert(MUmatSettemp->m_ppMatLexRule!=NULL);
				MUmatSettemp->m_ppMatLexRule[0]=lexrule1; MUmatSettemp->m_ppMatLexRule[1]=lexrule2; MUmatSettemp->m_ppMatLexRule[2]=lexrule3;
				// matched types;
				MUmatSettemp->m_nNumMatSynTyp=3;
				MUmatSettemp->m_pMatSynTyp=new int [MUmatSettemp->m_nNumMatSynTyp]; assert(MUmatSettemp->m_pMatSynTyp!=NULL);
				switch(order)
					{ case 3: // SVO;
							MUmatSettemp->m_pMatSynTyp[0]=0;	// S before V;
					  		MUmatSettemp->m_pMatSynTyp[1]=0;	// V before O;
					  		MUmatSettemp->m_pMatSynTyp[2]=0;	// S before O;
					  		break;
					  case 4: // SOV;
							MUmatSettemp->m_pMatSynTyp[0]=0;	// S before V;
					  		MUmatSettemp->m_pMatSynTyp[1]=1;	// V after O;
					  		MUmatSettemp->m_pMatSynTyp[2]=0;	// S before O;
					  		break;
					  case 5: // OSV;
 						  	MUmatSettemp->m_pMatSynTyp[0]=0;	// S before V;
					  		MUmatSettemp->m_pMatSynTyp[1]=1;	// V after O;
					  		MUmatSettemp->m_pMatSynTyp[2]=1;	// S after O;
					  		break;
					  case 6: // VSO;
							MUmatSettemp->m_pMatSynTyp[0]=1;	// S after V;
					  		MUmatSettemp->m_pMatSynTyp[1]=0;	// V before O;
					  		MUmatSettemp->m_pMatSynTyp[2]=0;	// S before O;
					  		break;
					  case 7: // VOS;
							MUmatSettemp->m_pMatSynTyp[0]=1;	// S after V;
					  		MUmatSettemp->m_pMatSynTyp[1]=0;	// V before O;
					  		MUmatSettemp->m_pMatSynTyp[2]=1;	// S after O;
					  		break;
					  case 8: // OVS;
							MUmatSettemp->m_pMatSynTyp[0]=1;	// S after V;
					  		MUmatSettemp->m_pMatSynTyp[1]=1;	// V after O;
					  		MUmatSettemp->m_pMatSynTyp[2]=1;	// S after O;
					  		break;
					  default: break;					  	
					}
				*comp=1;	// meaning part is fully matched;
		  		break;
		  case 3: // word + phrase;
				// matched lexical rules;
				MUmatSettemp->m_nNumLexRule=2;
				MUmatSettemp->m_ppMatLexRule=new CLexRule * [MUmatSettemp->m_nNumLexRule]; assert(MUmatSettemp->m_ppMatLexRule!=NULL);
				MUmatSettemp->m_ppMatLexRule[0]=lexrule1; MUmatSettemp->m_ppMatLexRule[1]=lexrule2;
				// matched types;
				MUmatSettemp->m_nNumMatSynTyp=1;
				MUmatSettemp->m_pMatSynTyp=new int [MUmatSettemp->m_nNumMatSynTyp]; assert(MUmatSettemp->m_pMatSynTyp!=NULL);
				switch(order)
					{ case 9: MUmatSettemp->m_pMatSynTyp[0]=0; break;	// word before phrase;
					  case 10: MUmatSettemp->m_pMatSynTyp[0]=1; break;	// word after phrase;
					  case 11: MUmatSettemp->m_pMatSynTyp[0]=2; break;	// word in between phrase;
					  default: break;
					}
				*comp=1;	// meaning part is fully matched;
		  		break;
		  case 4: // 2 word rules for "Predicate<Agent, Patient>" meaning;	
				// matched lexical rules;
				MUmatSettemp->m_nNumLexRule=2;
				MUmatSettemp->m_ppMatLexRule=new CLexRule * [MUmatSettemp->m_nNumLexRule]; assert(MUmatSettemp->m_ppMatLexRule!=NULL);
				MUmatSettemp->m_ppMatLexRule[0]=lexrule1; MUmatSettemp->m_ppMatLexRule[1]=lexrule2;
				// matched types;
				MUmatSettemp->m_nNumMatSynTyp=1;
				MUmatSettemp->m_pMatSynTyp=new int [MUmatSettemp->m_nNumMatSynTyp]; assert(MUmatSettemp->m_pMatSynTyp!=NULL);
				switch(order)
					{ case 9: MUmatSettemp->m_pMatSynTyp[0]=0; break;	// word 1 before word 2;
					  case 10: MUmatSettemp->m_pMatSynTyp[0]=1; break;	// word 1 after word 2;
					  default: break;
					}
				*comp=0;	// meaning part is partially matched;
		  		break;
		  default: break;
		}
	// update MUmatSettemp into newMUmatSet;
	updMUmatSet(MUmatSettemp, newMUmatSet, numMUmatSet);
	MUmatSettemp=NULL;	// recollect MUmatSettemp;
}

void CLTMem::ChoMUmatSet(CSemSpace *semspace, CMeanUtter *MU, MUmatSet **&newMUmatSet, int *numMUmatSet, bool *comp)
{ // select compositional lexical rules that can fully match MU's meaning part and partially match MU's utterance part;
	assert((semspace!=NULL)&&(MU!=NULL)); 
	int i, j, k, m, n, p;	
	int numAg, numPred1, numPred2, numPat, numAgPred, numAgPat, numPredPat;
	MatLexRule **MatchLexRule=NULL;	// store matched lexical rules;
	int numMatchLexRule;
	
	MatchLexRule=NULL; numMatchLexRule=0;
	if(MU->getpMean()->getElement(2*(MU->getLengthSem()))==-1)
		{ // MU is "Predicate<Agent>" meaning;
		  // first, check MU's matched lexical rules;
		  if(getNumLexRule()!=0)
		  	{ numAg=numPred1=0; 
			  // check Ag rule;
			  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 2, MU, getpLexRuleList(i), semspace)==1) 
			  		chkupdCompRule(2, 1, &numAg, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			  	}
		  	  // check Pred1 rule;
		 	  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 3, MU, getpLexRuleList(i), semspace)==1) 
			  		chkupdCompRule(3, 2, &numPred1, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			  	}
			  }
		  // then, select combinable and complete lexical rules into newMUmatSet;
		  if(numMatchLexRule!=0)
		  	{ for(i=0;i<numAg;i++)
				for(j=numAg;j<numAg+numPred1;j++)
					{ // check if they can combine; and then, check if certain cue matches it;
					  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
					  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
					  		{ // check whether it is SV(1) or VS(2) matches; 
					  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n]) 
					  		  	setupMUmatSet(1, 1, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// SV(1); 
					  		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m]) 
					  		  	setupMUmatSet(1, 2, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// VS(2);
					  		}
			  		}					
		  	}		  
		}
	else
		{ // MU is "Predicate<Agent, Patient>" meaning;
		  // first, check MU's matched lexical rules;
		  if(getNumLexRule()!=0)
		  	{ numAg=numPred2=numPat=numAgPred=numAgPat=numPredPat=0; 
			  // check Ag rule;
			  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 2, MU, getpLexRuleList(i), semspace)==1)
			  		chkupdCompRule(2, 1, &numAg, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			  	}
			  // check Pred2 rule;
		 	  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 3, MU, getpLexRuleList(i), semspace)==1)
			  		chkupdCompRule(4, 3, &numPred2, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			  	}
		 	  // check Pat rule;
		  	  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 4, MU, getpLexRuleList(i), semspace)==1)
			  		chkupdCompRule(5, 4, &numPat, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			    	}
		  	  // check AgPred phrase;
		  	  for(i=0;i<getNumLexRule();i++)
		 	 	{ if(chk2SideMeanUtter(1, 5, MU, getpLexRuleList(i), semspace)==1)
		 	 		chkupdCompRule(6, 0, &numAgPred, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
		 	   	}
	  		  // check AgPat phrase;
		  	  for(i=0;i<getNumLexRule();i++)
		 	 	{ if(chk2SideMeanUtter(1, 6, MU, getpLexRuleList(i), semspace)==1)
					chkupdCompRule(7, 0, &numAgPat, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
		 	 	}
		  	  // check PredPat phrase;
		  	  for(i=0;i<getNumLexRule();i++)
			  	{ if(chk2SideMeanUtter(1, 7, MU, getpLexRuleList(i), semspace)==1)
			  		chkupdCompRule(8, 0, &numPredPat, MU, getpLexRuleList(i), MatchLexRule, &numMatchLexRule);
			  	}
		  	}
		  // then, select combinable and complete lexical rules into newMUmatSet;
		  if(numMatchLexRule!=0)
		  	{ // check fully matched conditions; 
		  	  // 1) 3 word rules;
			  for(i=0;i<numAg;i++)
			  	for(j=numAg;j<numAg+numPred2;j++)
			  		for(k=numAg+numPred2;k<numAg+numPred2+numPat;k++)
			  			{ for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						  		for(p=0;p<MatchLexRule[k]->m_nMatNum;p++)
					  				{ if((MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])&&(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[k]->m_pMatLocStart[p]))
			  							setupMUmatSet(2, 3, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// SVO(3);
									  else if((MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[k]->m_pMatLocStart[p])&&(MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[j]->m_pMatLocStart[n]))
			  							setupMUmatSet(2, 4, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// SOV(4);
									  else if((MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n]))
										setupMUmatSet(2, 5, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// OSV(5);
									  else if((MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[k]->m_pMatLocStart[p]))
										setupMUmatSet(2, 6, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// VSO(6);
									  else if((MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[k]->m_pMatLocStart[p])&&(MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[i]->m_pMatLocStart[m]))
										setupMUmatSet(2, 7, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// VOS(7);
									  else if((MatchLexRule[k]->m_pMatLocEnd[p]<MatchLexRule[j]->m_pMatLocStart[n])&&(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m]))
					  				  	setupMUmatSet(2, 8, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, MatchLexRule[k]->m_pMatLexRule, newMUmatSet, numMUmatSet);	// OVS(8);
					  				}
			  			}
		  	  // 2) 1 word + 1 phrase rules;
		  	  // Ag + PredPat;
			  for(i=0;i<numAg;i++)
			  	for(j=numAg+numPred2+numPat+numAgPred+numAgPat;j<numAg+numPred2+numPat+numAgPred+numAgPat+numPredPat;j++)
			  		{ if(MatchLexRule[j]->m_nMatTyp==7)
  					  	{ // continuous PredPat phrase;
  					  	  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is S+VO/OV(9) or VO/OV+S(10) matches;
								  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  					  	setupMUmatSet(3, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S before VO/OV;
								  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  			  			setupMUmatSet(3, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S after VO/OV;
							 	}
			  			}
			  		  else if(MatchLexRule[j]->m_nMatTyp==10)
			  		  	{ // separate PredPat phrase;
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						  		{ // check whether it is V(S)O or O(S)V (11) matches; 
								  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
									setupMUmatSet(3, 11, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S in between VO/OV;
					  			}
			  		  	}
			  		}
		  	  // Pred2 + AgPat;
			  for(i=numAg;i<numAg+numPred2;i++)
			  	for(j=numAg+numPred2+numPat+numAgPred;j<numAg+numPred2+numPat+numAgPred+numAgPat;j++)
			  		{ if(MatchLexRule[j]->m_nMatTyp==6)
			  			{ // continuous AgPat phrase;
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is V+SO/OS(12) or SO/OS+V(13) matches;
								  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  					  	setupMUmatSet(3, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// V before SO/OS;
								  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  			  			setupMUmatSet(3, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// V after SO/OS;
							 	}
			  			}
			  		  else if(MatchLexRule[j]->m_nMatTyp==9)
			  		  	{ // continuous AgPat phrase;
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						  		{ // check whether it is S(V)O or O(V)S (14) matches; 
								  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
									setupMUmatSet(3, 11, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// V in between SO/OS;
					  			}
			  		  	}
			  		}
		  	  // Pat + AgPred;
		  	  for(i=numAg+numPred2;i<numAg+numPred2+numPat;i++)
		  	  	for(j=numAg+numPred2+numPat;j<numAg+numPred2+numPat+numAgPred;j++)
		  	  		{ if(MatchLexRule[j]->m_nMatTyp==5)
		  	  			{ // continuous AgPred phrase;
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is O+SV/VS(15) or SV/VS+O(16) matches;
								  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  					  	setupMUmatSet(3, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// O before SV/VS;
								  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  			  			setupMUmatSet(3, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// O after SV/VS;
							 	}
		  	  			}
		  	  		  else if(MatchLexRule[j]->m_nMatTyp==8)
		  	  		  	{ // separate AgPred phrase;
						  for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
						  	for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
						  		{ // check whether it is S(O)V or V(O)S (17) matches; 
								  if((MatchLexRule[j]->m_pMatLocStart[n]<MatchLexRule[i]->m_pMatLocStart[m])&&(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocEnd[n]))
									setupMUmatSet(3, 11, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// O in between SV/VS;
					  			}
		  	  		  	}
		  	  		}
		  	  if(*comp==0)
		  	  	{ // check partially matched conditions;
				  // 2 word rules;	
		  	  	  // Ag + Pred2;
				  for(i=0;i<numAg;i++)
				  	for(j=numAg;j<numAg+numPred2;j++)
				  		{ for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is S+V or V+S matches;
						  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			  			setupMUmatSet(4, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S before V;
						  		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  						setupMUmatSet(4, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S after V;
				  				}
				  		}
		  	  	  // Ag + Pat;
				  for(i=0;i<numAg;i++)
				  	for(j=numAg+numPred2;j<numAg+numPred2+numPat;j++)
				  		{ for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is S+O or O+S matches;
						  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			  			setupMUmatSet(4, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S before O;
						  		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  						setupMUmatSet(4, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// S after O;
				  				}
				  		}
		  	  	  // Pred2 + Pat;
				  for(i=numAg;i<numAg+numPred2;i++)
				  	for(j=numAg+numPred2;j<numAg+numPred2+numPat;j++)
				  		{ for(m=0;m<MatchLexRule[i]->m_nMatNum;m++)
							for(n=0;n<MatchLexRule[j]->m_nMatNum;n++)
								{ // check whether it is V+O or O+V matches;
						  		  if(MatchLexRule[i]->m_pMatLocEnd[m]<MatchLexRule[j]->m_pMatLocStart[n])
			  			  			setupMUmatSet(4, 9, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// V before O;
						  		  else if(MatchLexRule[j]->m_pMatLocEnd[n]<MatchLexRule[i]->m_pMatLocStart[m])
			  						setupMUmatSet(4, 10, comp, MatchLexRule[i]->m_pMatLexRule, MatchLexRule[j]->m_pMatLexRule, NULL, newMUmatSet, numMUmatSet);	// V after O;
				  				}
				  		}
		  	  	}
		  	}		  
		}
	
	if(numMatchLexRule!=0)
		{ // release memory for MatchLexRule; 
		  for(i=0;i<numMatchLexRule;i++)
			{ delete MatchLexRule[i]; MatchLexRule[i]=NULL; }
		  delete [] MatchLexRule; MatchLexRule=NULL;
		  numMatchLexRule=0;
		}
}

void CLTMem::FullMatPhrase(int type, CSemSpace *semspace, CMeanUtter *MU, MUmatSet **&newMUmatSet, int *numMUmatSet, bool *comp)
{ // select lexical rules that can fully match MU(phrase)'s meaning and utterance part;
	assert((3<=type)&&(type<=8)); assert((semspace!=NULL)&&(MU!=NULL));
	int i, j, numPair;
	CLexRule **MatLex=NULL;	// store matched lexical rules;
	int *MatTyp=NULL;	// store matched type;
	int numMatLex=0;

	switch(type)
		{ case 3: case 6: // continuous/separate AgPred phrase;
				numPair=0;
				if(getNumLexRule()!=0)
		  			{ // check Ag+Pred2 rule;
			  		  for(i=0;i<getNumLexRule();i++)
			  		  	{ if(chk2SideMeanUtter(1, 2, MU, getpLexRuleList(i), semspace)==1) 
			  		  		{ for(j=0;j<getNumLexRule();j++)
			  		  			{ if(chk2SideMeanUtter(1, 3, MU, getpLexRuleList(j), semspace)==1) 
			  						chkMatPhraseRule(type, MU, getpLexRuleList(i), 1, getpLexRuleList(j), 2, &numPair, MatLex, MatTyp, &numMatLex);
					  			}
			  		  		}
			  		  	}
			  		}
		  		if(numPair!=0)
		  			{ for(i=0;i<numPair;i++)
		  				setupMUmatSet(1, MatTyp[i], comp, MatLex[2*i], MatLex[2*i+1], NULL, newMUmatSet, numMUmatSet);
					}
				break;
		  case 4: case 7: // continuous/separate AgPat phrase;
				numPair=0;
				if(getNumLexRule()!=0)
		  			{ // check Ag+Pat rule;
			  		  for(i=0;i<getNumLexRule();i++)
			  		  	{ if(chk2SideMeanUtter(1, 2, MU, getpLexRuleList(i), semspace)==1) 
			  		  		{ for(j=0;j<getNumLexRule();j++)
			  		  			{ if(chk2SideMeanUtter(1, 4, MU, getpLexRuleList(j), semspace)==1) 
			  						chkMatPhraseRule(type, MU, getpLexRuleList(i), 1, getpLexRuleList(j), 3, &numPair, MatLex, MatTyp, &numMatLex);
					  			}
			  		  		}
			  		  	}
			  		}
		  		if(numPair!=0)
		  			{ for(i=0;i<numPair;i++)
		  				setupMUmatSet(1, MatTyp[i], comp, MatLex[2*i], MatLex[2*i+1], NULL, newMUmatSet, numMUmatSet);
					}
		  		break;
		  case 5: case 8: // continuous/separate PredPat phrase;
				numPair=0;
				if(getNumLexRule()!=0)
		  			{ // check Pred2+Pat rule;
			  		  for(i=0;i<getNumLexRule();i++)
			  		  	{ if(chk2SideMeanUtter(1, 3, MU, getpLexRuleList(i), semspace)==1) 
			  		  		{ for(j=0;j<getNumLexRule();j++)
			  		  			{ if(chk2SideMeanUtter(1, 4, MU, getpLexRuleList(j), semspace)==1) 
			  						chkMatPhraseRule(type, MU, getpLexRuleList(i), 2, getpLexRuleList(j), 3, &numPair, MatLex, MatTyp, &numMatLex);
					  			}
			  		  		}
			  		  	}
			  		}
		  		if(numPair!=0)
		  			{ for(i=0;i<numPair;i++)
		  				setupMUmatSet(1, MatTyp[i], comp, MatLex[2*i], MatLex[2*i+1], NULL, newMUmatSet, numMUmatSet);
					}
		  		break;
		  default: break;
		}

	if(numMatLex!=0)
		{ // release memory for MatLex; 
		  delete [] MatLex; MatLex=NULL;
		  delete [] MatTyp; MatTyp=NULL;
		  numMatLex=0;
		}	
}

void CLTMem::updCandMU(CandMU *&candMUtemp, CandMU **&newCandMU, int *numCandMU)
{ // update candMUtemp into newCandMU;
	assert(candMUtemp!=NULL);
	int i, j, k, m;
	CandMU **newCandMUtemp=NULL;
	int numnewCandMU;
	bool same;

	if(*numCandMU==0) 
		{ // create new newCandMU;
		  (*numCandMU)++;
		  newCandMU=new CandMU * [*numCandMU]; assert(newCandMU!=NULL);
		  newCandMU[0]=candMUtemp;
		}
	else
		{ // check whether candMUtemp is already in newCandMU; 
		  same=0;
		  for(i=0;i<*numCandMU;i++)
		  	{ if((*(newCandMU[i]->m_pMU)==*(candMUtemp->m_pMU))&&(newCandMU[i]->m_bComp==candMUtemp->m_bComp)&&(newCandMU[i]->m_nNumMatSet==candMUtemp->m_nNumMatSet)) 
		  		{ for(j=0;j<candMUtemp->m_nNumMatSet;j++)
		  			{ if((newCandMU[i]->m_ppMatSet[j]->m_nNumLexRule==candMUtemp->m_ppMatSet[j]->m_nNumLexRule)&&(newCandMU[i]->m_ppMatSet[j]->m_nNumMatSynTyp==candMUtemp->m_ppMatSet[j]->m_nNumMatSynTyp)) 
		  				{ for(k=0;k<candMUtemp->m_ppMatSet[j]->m_nNumLexRule;k++)
		  					{ if(newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[k]!=candMUtemp->m_ppMatSet[j]->m_ppMatLexRule[k])
		  						break;
		  					}
		  		  		  if(k==candMUtemp->m_ppMatSet[j]->m_nNumLexRule) 
		  		  		  	{ for(m=0;m<candMUtemp->m_ppMatSet[j]->m_nNumMatSynTyp;m++)
		  						{ if(*(newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp+m)!=*(candMUtemp->m_ppMatSet[j]->m_pMatSynTyp+m))
		  							break;
		  		  		  		}
		  		  		  	  if(m==candMUtemp->m_ppMatSet[j]->m_nNumLexRule) same=1;
		  		  		  	}
		  				}
		  			}
		  		}
		  	}
		  if(same==0)
		  	{ // new CandMU; 
		  	  numnewCandMU=(*numCandMU)+1;
		  	  newCandMUtemp=new CandMU * [numnewCandMU]; assert(newCandMUtemp!=NULL);
			  for(i=0;i<numnewCandMU;i++)
			  	newCandMUtemp[i]=NULL;
		  	  for(i=0;i<numnewCandMU-1;i++)
		  		newCandMUtemp[i]=newCandMU[i];
		   	  newCandMUtemp[numnewCandMU-1]=candMUtemp;
		   	  // delete original newCandMU;
		   	  delete [] newCandMU; newCandMU=NULL;
		   	  *numCandMU=0;
		   	  // copy newCandMUtemp to newCandMU;
		   	  *numCandMU=numnewCandMU; newCandMU=newCandMUtemp;
		  	  newCandMUtemp=NULL;	// recollect newCandMUtemp;
			}
		  else { delete candMUtemp; candMUtemp=NULL; }
		}
}

void CLTMem::SetCandMU(int type, CSemSpace *semspace, CMeanUtter *MU, CandMU **&newCandMU, int *numCandMU)
{ // set up CandMU for each M-U mapping in the buffer;
  // type=0, holistic or M-U mappings; 3-8, phrase rule;
	assert((type==0)||((3<=type)&&(type<=8))); assert((semspace!=NULL)&&(MU!=NULL));
	int i;
	CandMU *candMUtemp=NULL;
	MUmatSet **newMUmatSet=NULL;
	int numMUmatSet;
	bool comp;	// whether the meaning part is fully matched by lexical rules;

	// first, select lexical rules that can fully match MU's meaning part and partially match MU's utterance part;
	numMUmatSet=0; comp=0;
	if(type==0) ChoMUmatSet(semspace, MU, newMUmatSet, &numMUmatSet, &comp);	// select lexical rules that can fully match MU(holistic)'s meaning part and partially match MU's utterance part;
	else FullMatPhrase(type, semspace, MU, newMUmatSet, &numMUmatSet, &comp);	// select lexical rules that can fully match MU(phrase)'s meaning and utterance part;
	if(numMUmatSet!=0)
		{ // initialize candMUtemp;
		  candMUtemp=new CandMU; assert(candMUtemp!=NULL);
		  candMUtemp->m_pMU=MU;	// set up m_pMU;
		  candMUtemp->m_bComp=comp;
		  candMUtemp->m_nNumMatSet=numMUmatSet;
		  candMUtemp->m_ppMatSet=new MUmatSet * [candMUtemp->m_nNumMatSet]; assert(candMUtemp->m_ppMatSet!=NULL);
		  for(i=0;i<candMUtemp->m_nNumMatSet;i++)
		  	candMUtemp->m_ppMatSet[i]=newMUmatSet[i];
		  // delete newMUmatSet;
		  delete [] newMUmatSet; newMUmatSet=NULL;
		  numMUmatSet=0;
		  // update candMUtemp into newCandMU;
		  updCandMU(candMUtemp, newCandMU, numCandMU);
		  candMUtemp=NULL;	// recollect candMUtemp;
		}
}

// learn new category and syntactic rule;
bool CLTMem::LocTarRule(int tarThemRole, CLexRule *tarLexRule, CLexRule *tarrule, CMeanUtter *MU, CSemSpace *semspace)
{ // decide whether tarrule matches category requirement of tarLexRule;
	assert((1<=tarThemRole)&&(tarThemRole<=7)); assert((tarLexRule!=NULL)&&(tarrule!=NULL)); assert((MU!=NULL)&&(semspace!=NULL));
	bool value=0;
	if((tarThemRole==1)&&(tarrule==tarLexRule)&&(chk2SideMeanUtter(1, 2, MU, tarrule, semspace)==1)) value=1;
	else if(((tarThemRole==2)||(tarThemRole==3))&&(tarrule==tarLexRule)&&(chk2SideMeanUtter(1, 3, MU, tarrule, semspace)==1)) value=1;
	else if((tarrule==tarLexRule)&&(chk2SideMeanUtter(1, tarThemRole, MU, tarrule, semspace)==1)) value=1;
	return value;
}

bool CLTMem::LocRelRule(int type, double ChildAdultAbiRatio, double DetLocOrdRate, int locRel, int tarThemRole, int needThemRole, CLexRule *relrule, int matSynTyp, CMeanUtter *MU, CSemSpace *semspace)
{ // decide whether relrule matches the order requirement;
  // type=1, normal order; 2, reverse order;
  	assert((type==1)||(type==2)); 
  	assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetLocOrdRate))&&(FLOAT_SM_EQ(DetLocOrdRate, 1.0)));
  	assert((1<=tarThemRole)&&(tarThemRole<=7)); assert((1<=needThemRole)&&(needThemRole<=7));
  	assert((matSynTyp==0)||(matSynTyp==1)||(matSynTyp==2));
  	assert((MU!=NULL)&&(semspace!=NULL));
  	bool value=0;
  	if(type==1)
  		{ // normal order; tarThemRole can only be 1(Ag), 3(Pred2), 4(Pat);
		  switch(tarThemRole)
		  	{ case 1: // Ag; needThemRole can be 2(Pred1), 3(Pred2), 4(Pat), 7(PredPat);
					if(((needThemRole==2)||(needThemRole==3))&&(chk2SideMeanUtter(1, 3, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
					else if((chk2SideMeanUtter(1, needThemRole, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
					break;
		  	  case 3: case 4: // Pred2; needThemRole can be 4(Pat), 6(AgPat); Pat; needThemRole can be 5(AgPred);
		  	  		if((chk2SideMeanUtter(1, needThemRole, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
					break;			  		
		  	  default: break;
		  	}
  		}
  	else if(type==2)
  		{ // reverse order; tarThemRole can only be 2(Pred1), 3(Pred2), 4(Pat), 5(AgPred), 6(AgPat), 7(PredPat);
		  switch(tarThemRole)
		  	{ case 2: case 3: // Pred1; needThemRole can be 1(Ag); // Pred2; needThemRole can be 1(Ag);
					if((chk2SideMeanUtter(1, 2, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;	      
		  			break;
		  	  case 4: // Pat; needThemRole can be 1(Ag), 3(Pred2);
					if((needThemRole==1)&&(chk2SideMeanUtter(1, 2, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
					else if((needThemRole==3)&&(chk2SideMeanUtter(1, needThemRole, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
					break;
		  	  case 5: // AgPred; needThemRole can be 4(Pat);
					if((chk2SideMeanUtter(1, needThemRole, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
		  	  		break;
		  	  case 6: // AgPat; needThemRole can be 3(Pred2);
					if((chk2SideMeanUtter(1, needThemRole, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
		  	  		break;
		  	  case 7: // PredPat; needThemRole can be 1(Ag);
					if((chk2SideMeanUtter(1, 2, MU, relrule, semspace)==1)&&(locRel==matSynTyp)&&(FLOAT_SM_EQ(Rand0_1, ChildAdultAbiRatio*DetLocOrdRate))) value=1;
		  	  		break;
		  	  default: break;
		  	}
  		}
  	return value;
}

void CLTMem::updrelLexRule(CLexRule *lexrule, CLexRule **&relLexRule, int *numrelLexRule)
{ // update lexrule into relLexRule; not allow repetition;
	assert(lexrule!=NULL);
	int i;
	CLexRule **rellexruletemp=NULL;
	int numnewrelLexRule;

	if(*numrelLexRule==0) 
		{ // create new relLexRule; 
		  (*numrelLexRule)++;
		  relLexRule=new CLexRule * [*numrelLexRule]; assert(relLexRule!=NULL);
		  relLexRule[0]=lexrule;
		}
	else
		{ // check whether lexrule is already in relLexRule!
		  for(i=0;i<*numrelLexRule;i++)
		  	{ if(*(relLexRule[i])==*lexrule) break;
		  	}
		  if(i==*numrelLexRule)
		  	{ // a new lexrule;
		  	  numnewrelLexRule=(*numrelLexRule)+1;	// increase the current number of related lexical rules;
		  	  rellexruletemp=new CLexRule * [numnewrelLexRule]; assert(rellexruletemp!=NULL);
			  for(i=0;i<numnewrelLexRule;i++)
			  	rellexruletemp[i]=NULL;
		  	  for(i=0;i<numnewrelLexRule-1;i++)
		  		rellexruletemp[i]=relLexRule[i];
		  	  rellexruletemp[numnewrelLexRule-1]=lexrule;
		  	  // delete original relLexRule;
		  	  delete [] relLexRule; relLexRule=NULL;
		  	  *numrelLexRule=0;
		  	  // copy rellexruletemp to relLexRule;
		  	  *numrelLexRule=numnewrelLexRule; relLexRule=rellexruletemp;
		  	  rellexruletemp=NULL;	// recollect rellexruletemp;
		  	}
		}
}

void CLTMem::FindOtherRelRule(int type, double ChildAdultAbiRatio, double DetLocOrdRate, CLexRule *tarLexRule, int tarThemRole, int needThemRole, int locRel, CLexRule **&relLexRule, int *numrelLexRule, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace)
{ // for tarLexRule, update other related rules into relLexRule;
  // type=1, normal order; 2, reverse order;
	assert((type==1)||(type==2)); 
  	assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetLocOrdRate))&&(FLOAT_SM_EQ(DetLocOrdRate, 1.0)));
  	assert((1<=tarThemRole)&&(tarThemRole<=7)); assert((1<=needThemRole)&&(needThemRole<=7));
	assert(tarLexRule!=NULL);
	assert((newCandMU!=NULL)&&(numCandMU!=0));
	assert((locRel==0)||(locRel==1)||(locRel==2));
	assert(semspace!=NULL);
	int i, j, k;
	MUmatSet *curMUmatSet=NULL;
	CLexRule *tarrule=NULL, *relrule=NULL;
	bool istarrule, isrelrule;

	// search all lexical rules;
	for(i=0;i<numCandMU;i++)
		for(j=0;j<newCandMU[i]->m_nNumMatSet;j++)
			{ curMUmatSet=newCandMU[i]->m_ppMatSet[j];
			  for(k=0;k<curMUmatSet->m_nNumLexRule;k++)
				{ tarrule=curMUmatSet->m_ppMatLexRule[k];
			  	  istarrule=Judge_InLex(tarrule);
				  if((istarrule==1)&&(LocTarRule(tarThemRole, tarLexRule, tarrule, newCandMU[i]->m_pMU, semspace)==1))
					{ // find a tarrule that matches tarLexRule;
					  if(type==1)
					  	{ // normal order;
						  if(k==0)
						  	{ if(curMUmatSet->m_nNumLexRule==2)
						  		{ relrule=curMUmatSet->m_ppMatLexRule[1];
						  		  isrelrule=Judge_InLex(relrule);
						  		  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[0], newCandMU[i]->m_pMU, semspace)==1))
						  	  		updrelLexRule(relrule, relLexRule, numrelLexRule);
						  		  relrule=NULL;	// recollect relrule;
						  		}
						  	  else if(curMUmatSet->m_nNumLexRule==3)
						  	  	{ relrule=curMUmatSet->m_ppMatLexRule[1];
							  	  isrelrule=Judge_InLex(relrule);
						  	  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[0], newCandMU[i]->m_pMU, semspace)==1))
						  	  		updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  	  relrule=curMUmatSet->m_ppMatLexRule[2];
								  isrelrule=Judge_InLex(relrule);
						  	  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[2], newCandMU[i]->m_pMU, semspace)==1))
						  	  		updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  	  relrule=NULL;	// recollect relrule;
						  	  	}
						  	}
						  else if(k==1)
						  	{ if(curMUmatSet->m_nNumLexRule==3)
						  		{ relrule=curMUmatSet->m_ppMatLexRule[2];
						  		  isrelrule=Judge_InLex(relrule);
						  	  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[1], newCandMU[i]->m_pMU, semspace)==1))
						  	  		updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  	  relrule=NULL;	// recollect relrule;
						  		}
						  	}
					  	}
					  else if(type==2)
					  	{ // reverse order;
						  if(k==1)
						  	{ relrule=curMUmatSet->m_ppMatLexRule[0];
						  	  isrelrule=Judge_InLex(relrule);
						  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[0], newCandMU[i]->m_pMU, semspace)==1))
						  	  	updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  relrule=NULL;	// recollect relrule;
						  	}
						  else if(k==2)
						  	{ relrule=curMUmatSet->m_ppMatLexRule[0];
						  	  isrelrule=Judge_InLex(relrule);
						  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[2], newCandMU[i]->m_pMU, semspace)==1))
						  	  	updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  relrule=curMUmatSet->m_ppMatLexRule[1];
							  isrelrule=Judge_InLex(relrule);
						  	  if((isrelrule==1)&&(LocRelRule(type, ChildAdultAbiRatio, DetLocOrdRate, locRel, tarThemRole, needThemRole, relrule, curMUmatSet->m_pMatSynTyp[1], newCandMU[i]->m_pMU, semspace)==1))
						  	  	updrelLexRule(relrule, relLexRule, numrelLexRule);
						  	  relrule=NULL;	// recollect relrule;
						  	}
					  	}
				  	}
				  tarrule=NULL;	// recollect tarrule;
			  	}
			  curMUmatSet=NULL;	// recollect curMUmatSet;
			}
}

void CLTMem::AdjrelLexRule(CLexRule *lexRule, CCat *cat, int needThemRole, CSemSpace *semspace)
{ // adjust lexRule's CatList->m_nThemRole; if lexRule is a Pred1 or Pred2 rule, reset lexRule's CatList->m_nThemRole;
	assert((lexRule!=NULL)&&(cat!=NULL)); assert((1<=needThemRole)&&(needThemRole<=7)); assert(semspace!=NULL);
	int i, j;
	double assowei;
	int posPred=semspace->getLengthSem()+semspace->getLengthSemRole();
	int lenSemItem=semspace->getLengthSemItem();
	
	if(lexRule->getLexTyp()==2)
		{ // Pred rule, test whether it is Pred1 or Pred2;  
		  for(i=0;i<semspace->getNumSemPred1();i++)
			{ for(j=0;j<lenSemItem;j++)
		  		{ if(lexRule->getpMeanUtter()->getpMean()->getElement(j+posPred)!=semspace->getpSemPred(i)->getElement(j))
		  			break;
		  		}
			  if(j==lenSemItem) break;			  				  				  
			}
		  if(i!=semspace->getNumSemPred1())
		  	{ // this rule is Pred1;
			  for(j=0;j<lexRule->getCatNum();j++)
				{ if(lexRule->getpCatList(j)->getpCat()==cat)
					{ assowei=lexRule->getpCatList(j)->getAssoWei();
			  		  lexRule->setpCatList(j, cat, assowei, 2);
					}
				}
		  	}
		  else
		  	{ // this rule is Pred2;
			  for(j=0;j<lexRule->getCatNum();j++)
				{ if(lexRule->getpCatList(j)->getpCat()==cat)
					{ assowei=lexRule->getpCatList(j)->getAssoWei();
			  		  lexRule->setpCatList(j, cat, assowei, 3);
					}
				}
		  	}
		}
  	  else
  	  	{ // other type of lexrule; 
  	  	  for(j=0;j<lexRule->getCatNum();j++)
 			{ if(lexRule->getpCatList(j)->getpCat()==cat)
  				{ assowei=lexRule->getpCatList(j)->getAssoWei();
  				  lexRule->setpCatList(j, cat, assowei, needThemRole);
  				}
  			}
  	  	}
}

bool CLTMem::chkLexTypCons(CCat *cat, CLexRule **relLexRule, int numrelLexRule)
{ // check whether lexical rules in cat and lexical rules in relLexRule have common lexTyp;
	assert((cat!=NULL)&&(numrelLexRule>=2));
	int i, j;
	int lexTyp1=cat->getpLexRule(0)->getLexTyp(), lexTyp2=relLexRule[0]->getLexTyp();
	for(i=0;i<cat->getLexNum();i++) 
		{ if(cat->getpLexRule(i)->getLexTyp()!=lexTyp2) break; }
	for(j=0;j<numrelLexRule;j++) 
		{ if(relLexRule[j]->getLexTyp()!=lexTyp1) break; }
	if((i==cat->getLexNum())&&(j==numrelLexRule)) return 1;
	else return 0;
}

bool CLTMem::ChkNeedCat(int PredCase, CCat *cat, int needThemRole)
{ // check whether cat's lexical rules matches the needThemRole's requirement;
  // PredCase=0, merge pred1 and pred2; PredCase=1, do not merge pred1 and pred2;
  	assert((PredCase==0)||(PredCase==1)); assert(cat!=NULL); assert((1<=needThemRole)&&(needThemRole<=7));
	int i, j;
	bool value=0;
	
	if(PredCase==0) value=1;
  	else if(PredCase==1)
		{ for(i=0;i<cat->getLexNum();i++)
  			{ value=0; 
  			  for(j=0;j<cat->getpLexRule(i)->getCatNum();j++)
  				{ if((cat->getpLexRule(i)->getpCatList(j)->getpCat()==cat)&&(cat->getpLexRule(i)->getpCatList(j)->getThemRole()==needThemRole)) 
  					{ value=1; break; }
  				}
  			}
		}
	return value;
}

bool CLTMem::ChkNeedLex(int PredCase, CLexRule *lexRule, int needThemRole, CSemSpace *semspace)
{ // check whether lexRule matches needThemRole;
  // PredCase=0, merge pred1 and pred2; PredCase=1, do not merge pred1 and pred2;
   	assert((PredCase==0)||(PredCase==1)); assert(lexRule!=NULL); assert((1<=needThemRole)&&(needThemRole<=7)); assert(semspace!=NULL);
	int i, j;
	int posPred=semspace->getLengthSem()+semspace->getLengthSemRole();
	int lenSemItem=semspace->getLengthSemItem();
	bool value=0;
	
	if(PredCase==0) value=1;
	else if(PredCase==1) 
		{ if((needThemRole==2)||(needThemRole==3))
			{ // Pred rule, test whether it is Pred1 or Pred2;  
		  	  for(i=0;i<semspace->getNumSemPred1();i++)
				{ for(j=0;j<lenSemItem;j++)
			  		{ if(lexRule->getpMeanUtter()->getpMean()->getElement(j+posPred)!=semspace->getpSemPred(i)->getElement(j))
			  			break;
			  		}
				  if(j==lenSemItem) break;			  				  				  
				}
			  if(i!=semspace->getNumSemPred1())
			  	{ // this rule is Pred1; 
			  	  if(needThemRole==2) value=1;
			  	  else value=0;
			  	}
			  else
			  	{ // this rule is Pred2; 
			  	  if(needThemRole==3) value=1;
			  	  else value=0;
			  	}	
			}
		  else value=1;
		}
	return value;
}

void CLTMem::bltCatSyn(int type, int PredCase, int locRel, CLexRule *tarLexRule, int tarThemRole, int needThemRole, CLexRule **&relLexRule, int numrelLexRule, CSemSpace *semspace)
{ // build up new category and syntactic rules between tarLexRule and rules in relLexRule;
  // type=1, normal order; 2, reserve order;
  // PredCase=0, merge pred1 and pred2; PredCase=1, do not merge pred1 and pred2;
  	assert((type==1)||(type==2)); assert((PredCase==0)||(PredCase==1)); assert((locRel==0)||(locRel==1)||(locRel==2));
	assert((tarLexRule!=NULL)&&(relLexRule!=NULL)&&(numrelLexRule>=2)); 
	assert(semspace!=NULL);
	int i, j, k;
	int sucInLex;
	CCat *tarCat=NULL, *relCat=NULL;
	CSynRule *synRule=NULL;
	int tarCatThemRole, needCatThemRole, locRelNor, locRelRev;	// normal and reverse locRel;
	bool finish;	// finish tag;
	int mergetype;
	bool isrelLexRule;
	
	// adjust tarCatThemRole, needThemRole;
	if((tarThemRole==1)||(tarThemRole==2)) tarCatThemRole=tarThemRole;
	else tarCatThemRole=tarThemRole-1;
	if((needThemRole==1)||(needThemRole==2)) needCatThemRole=needThemRole;
	else needCatThemRole=needThemRole-1;

	// adjust locRel;
	locRelNor=locRelRev=-1;
	if(type==1)
		{ // normal order; 
		  locRelNor=locRel;
		  if((locRel==0)||(locRel==1)) locRelRev=!locRel;
		  else if(locRel==2) locRelRev=3;
		  else if(locRel==3) locRelRev=2;
		}
	else if(type==2)
		{ // reverse order;
		  if((locRel==0)||(locRel==1)) locRelNor=!locRel;
		  else if(locRel==2) locRelNor=3;
		  else if(locRel==3) locRelNor=2;
		  locRelRev=locRel;
		}

	finish=0;	// not finish yet; 
	// check tarCat;
	for(i=0;i<tarLexRule->getCatNum();i++)
		{ if(tarLexRule->getpCatList(i)->getThemRole()==tarThemRole)
			{ tarCat=tarLexRule->getpCatList(i)->getpCat();	// tarCat;
	  		  // check synRule and relCat;
	  		  for(j=0;j<getNumSynRule();j++)
	  		  	{ if(getpSynRuleList(j)->getSynTyp()!=-1)
	  		  		{ if(((getpSynRuleList(j)->getpCat(0)==tarCat)&&(getpSynRuleList(j)->getSynTyp()==locRelNor))&&(getpSynRuleList(j)->getpCat(1)->getThemRole()==needCatThemRole)&&(chkLexTypCons(getpSynRuleList(j)->getpCat(1), relLexRule, numrelLexRule)==1)) 
	  		  		  	{ if(ChkNeedCat(PredCase, getpSynRuleList(j)->getpCat(1), needThemRole)==1)
						  	{ relCat=getpSynRuleList(j)->getpCat(1);	// tarCat, synRule, relCat;						  
							  // put all lexical rules in relLexRule into this category;
						  	  for(k=0;k<numrelLexRule;k++)
						 	 	{ isrelLexRule=Judge_InLex(relLexRule[k]);
						 	 	  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
				  				  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
								  	  	{ // link up relCat and relLexRule[k]; 
				  				  	  	  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex);	// if it fails, it means that relLexRule[k] is already in relCat;
									  	  if(sucInLex==1) 
										  	{ relLexRule[k]->InCat(relCat);
						  		  	  	  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
						  					}
								  	  	}
					  				}
						  	  	}
					  	  	  relCat=NULL;	// recollect relCat;
					  	  	  finish=1;	// finish!
						  	}
					  	  break;
	  			  		}
	  			  	  else if(((getpSynRuleList(j)->getpCat(1)==tarCat)&&(getpSynRuleList(j)->getSynTyp()==locRelRev))&&(getpSynRuleList(j)->getpCat(0)->getThemRole()==needCatThemRole)&&(chkLexTypCons(getpSynRuleList(j)->getpCat(0), relLexRule, numrelLexRule)==1))
	  					{ if(ChkNeedCat(PredCase, getpSynRuleList(j)->getpCat(0), needThemRole)==1)
						  	{ relCat=getpSynRuleList(j)->getpCat(0);	// tarCat, synRule, relCat;						  
							  // put all lexical rules in relLexRule into this category;
						  	  for(k=0;k<numrelLexRule;k++)
						  		{ isrelLexRule=Judge_InLex(relLexRule[k]);
						  		  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
						  		  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
								  	  	{ // link up relCat and relLexRule[k]; 
					 	  	  	  		  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex);	// if it fails, it means that relLexRule[k] is already in relCat;
										  if(sucInLex==1)
										  	{ relLexRule[k]->InCat(relCat);
					  	  	  	  		  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
								  	  		}
								  	  	}
						  		  	}
						  	  	}
							  relCat=NULL;	// recollect relCat;
						  	  finish=1;	// finish;
						  	}
						  break;
	  					}
	  		  		}
	  		  	}
	  		  if(finish==1) { tarCat=NULL; break; }	// recollect tarCat; 
	  		  else if(finish==0)
	  		  	{ // tarCat, !synRule
	  		  	  // check relCat;
				  for(j=0;j<getNumCat();j++)
				  	{ if((getpCatList(j)->getThemRole()==needCatThemRole)&&(chkLexTypCons(getpCatList(j), relLexRule, numrelLexRule)==1))
				 		{ if(ChkNeedCat(PredCase, getpCatList(j), needThemRole)==1)
				 		  	{ // merge pred1 and pred2;	
				 		  	  relCat=getpCatList(j);	// tarCat, !synRule, relCat;						  
				 	  	  	  // merge all relLexRule into relCat; and create synRule;
					  	  	  for(k=0;k<numrelLexRule;k++)
						 	 	{ isrelLexRule=Judge_InLex(relLexRule[k]);
					 		 	  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
					  			  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
									  	{ // link up relCat and relLexRule[k]; 
					  			  	  	  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex);	// if it fails, it means that relLexRule[k] is already in relCat;
										  if(sucInLex==1)
										  	{ relLexRule[k]->InCat(relCat);
					  			  	  	  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
					  			  			}
									  	}
					 		 	  	}
					  			}
					  	  	  // create synRule;
					  	  	  synRule=new CSynRule; assert(synRule!=NULL);
					  	  	  // set synRule->m_nSynTyp;
					  	  	  synRule->setSynTyp(locRelNor);
					  	  	  synRule->setSynStr(synRule->getInitSynRuleStr());
					  	  	  // set synRule->m_pCats[];	
					  	  	  synRule->setpCat(0, tarCat); synRule->setpCat(1, relCat);
					  	  	  tarCat->InSyn(synRule); 
							  if(relCat->getThemRole()!=-1) 
							  	{ // when inserting synRule in tarCat does not cause relCat to be removed!
							  	  relCat->InSyn(synRule);
					  	  	  	  mergetype=0; InSynRule(synRule, &mergetype);	// insert synRule into m_pSynRuleList;
							  	}
							  else { delete synRule; }	// insering synRule causes relCat to be removed, delete synRule;
							  synRule=NULL;	// recollect synRule;
			  		  	  	  relCat=NULL;	// recollect relCat;
			  		  	  	  finish=1;	// finish!
				 		  	}
						  break;
				  		}
				  	}
				  if(finish==1) { tarCat=NULL; break; }	// recollect tarCat; 
				  else if(finish==0)
				  	{ // tarCat, !SynRule, !relCat;
				  	  // create relCat;
					  relCat=new CCat; assert(relCat!=NULL);
					  // set relCat->m_nThemRole;
				  	  relCat->setThemRole(needCatThemRole);
					  // set relCat->m_pLexRule;
				  	  for(k=0;k<numrelLexRule;k++)
				  	  	{ isrelLexRule=Judge_InLex(relLexRule[k]);
				  	  	  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
						  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
						  		{ // link up relCat and relLexRule[k]; 
					  	  		  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex);	// this insertion will always be successful;
								  if(sucInLex==1)
								  	{ relLexRule[k]->InCat(relCat);
					  	  		  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
						    		}
						  	  	}
				  	  	    }
					  	}
				  	  if(relCat->getLexNum()!=0)
				  	  	{ // relCat has members;
					  	  // create SynRule;
				  	  	  synRule=new CSynRule; assert(synRule!=NULL);
					  	  // set synRule->m_nSynTyp;
					  	  synRule->setSynTyp(locRelNor);
					  	  synRule->setSynStr(synRule->getInitSynRuleStr());
					  	  // set synRule->m_pCats[];	
					  	  synRule->setpCat(0, tarCat); synRule->setpCat(1, relCat);
					  	  tarCat->InSyn(synRule); relCat->InSyn(synRule);

					  	  InCategory(relCat);	// insert relCat into m_pCatList;
					  	  if(tarCat->getThemRole()!=-1)
					  	  	{ // when insering relCat does not cause tarCat and synRule to be removed;
					  	  	  mergetype=0; InSynRule(synRule, &mergetype);	// insert synRule into m_pSynRuleList;
					  	  	}
						  else 
						  	{ // inserting relCat causes tarCat to be removed, also remove synRule from relCat and delete synRule;;
							  relCat->AdjCat_Syn(synRule);
							  delete synRule;
						  	}
					  	  synRule=NULL;	// recollect synRule;
					  	  relCat=NULL;	// recollect relCat;
					  	  finish=1;	// finish!
				  	  	}
					  else { delete relCat; relCat=NULL; }
					}
				  if(finish==1) { tarCat=NULL; break; }	// recollect tarCat; 
				}
	  		}		  	  
		}
	if(finish==0)
	  	{ // !tarCat;
		  // create tarCat;
		  tarCat=new CCat; assert(tarCat!=NULL);
		  // set tarCat->m_nThemRole;
	  	  tarCat->setThemRole(tarCatThemRole);
		  // set tarCat->m_pLexRule
		  sucInLex=0; tarCat->InLex(tarLexRule, &sucInLex);	// this insertion will always be successful;
		  if(sucInLex==1)
		  	{ tarLexRule->InCat(tarCat);
		  	  AdjrelLexRule(tarLexRule, tarCat, tarThemRole, semspace);	// adjust tarLexRule's CatList->m_nThemRole;
		  	}
		  
		  // check relCat;
		  for(j=0;j<getNumCat();j++)
		  	{ if((getpCatList(j)->getThemRole()==needCatThemRole)&&(chkLexTypCons(getpCatList(j), relLexRule, numrelLexRule)==1))
	  			{ if(ChkNeedCat(PredCase, getpCatList(j), needThemRole)==1)
		  		  	{ relCat=getpCatList(j);	// tarCat, !Synrule, relCat; 
			  	  	  // merge all relLexRule into relCat; and create Synrule;
			  	  	  for(k=0;k<numrelLexRule;k++)
			 		 	{ isrelLexRule=Judge_InLex(relLexRule[k]);
			 		 	  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
						  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
						  	  	{ // link up relCat and relLexRule[k]; 
			  			  	  	  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex);	// if it fails, it means that relLexRule[k] is already in relCat; 
								  if(sucInLex==1)
								  	{ relLexRule[k]->InCat(relCat);
			  			  	  	  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
									}
						  	  	}
			 		 	  	}
					  	}
		  		  
				  	  // create synRule;
				  	  synRule=new CSynRule; assert(synRule!=NULL);
				  	  // set synRule->m_nSynTyp;
				  	  synRule->setSynTyp(locRelNor);
				  	  synRule->setSynStr(synRule->getInitSynRuleStr());
				  	  // set synRule->m_pCats[];
				  	  synRule->setpCat(0, tarCat); synRule->setpCat(1, relCat); 
				  	  tarCat->InSyn(synRule); relCat->InSyn(synRule);
					  
		  		  	  InCategory(tarCat);	// insert tarCat into m_pCatList;
				  	  if(relCat->getThemRole()!=-1)
					  	{ // when insering tarCat does not cause relCat to be removed;
					  	  mergetype=0; InSynRule(synRule, &mergetype);	// insert synRule into m_pSynRuleList;
					  	}
					  else 
					  	{ // inserting tarCat causes relCat to be removed, also remove synRule from tarCat and delete synRule;
					  	  tarCat->AdjCat_Syn(synRule);
					  	  delete synRule;
					  	}
				  	  synRule=NULL;	// recollect synRule;
		 		  	  relCat=NULL;	// recollect relCat;
		  		  	  finish=1;	// finish!
		  		  	}
				  break;
		  		}
		  	}
		  if(finish==1) { tarCat=NULL; }	// recollect tarCat; 
		  else if(finish==0)
		  	{ // tarCat, !SynRule, !relCat;
		  	  // create relCat;
			  relCat=new CCat; assert(relCat!=NULL);
			  // set relCat->m_nThemRole;
		  	  relCat->setThemRole(needCatThemRole);
			  // set relCat->m_pLexRule
		  	  for(k=0;k<numrelLexRule;k++)
		  	  	{ isrelLexRule=Judge_InLex(relLexRule[k]);
		  	  	  if((isrelLexRule==1)&&(relLexRule[k]!=NULL)&&(relLexRule[k]->getpMeanUtter()!=NULL)) 
				  	{ if(ChkNeedLex(PredCase, relLexRule[k], needThemRole, semspace)==1)
				  	  	{ // link up relCat and relLexRule[k]; 
			  	  	  	  sucInLex=0; relCat->InLex(relLexRule[k], &sucInLex); assert(sucInLex==1);	// this insertion will always be successful;
						  if(sucInLex==1)
						  	{ relLexRule[k]->InCat(relCat);
			  	  	  	  	  AdjrelLexRule(relLexRule[k], relCat, needThemRole, semspace);	// adjust relLexRule[k]'s CatList->m_nThemRole;
							}
				  	  	}
		  	  	  	}
			  	}
			  if(relCat->getLexNum()!=0)
			  	{ // create SynRule;
		  	  	  synRule=new CSynRule; assert(synRule!=NULL);
			  	  // set synRule->m_nSynTyp;
			  	  synRule->setSynTyp(locRelNor);
			  	  synRule->setSynStr(synRule->getInitSynRuleStr());
			  	  // set synRule->m_pCats[];
			  	  synRule->setpCat(0, tarCat); synRule->setpCat(1, relCat); 
			  	  tarCat->InSyn(synRule); relCat->InSyn(synRule);

			  	  InCategory(tarCat);	// insert tarCat into m_pCatList;		  	 
		  	  	  InCategory(relCat);	// insert relCat into m_pCatList;
		  	  	  if(tarCat->getThemRole()!=-1)
				  	{ // when insering relCat does not cause tarCat and synRule to be removed;
				  	  mergetype=0; InSynRule(synRule, &mergetype);	// insert synRule into m_pSynRuleList;
				  	}
				  else 
				  	{ // inserting relCat causes tarCat to be removed, also remove synRule from relCat and delete synRule;
				  	  relCat->AdjCat_Syn(synRule);
				  	  delete synRule;
				  	}
			  	  synRule=NULL;	// recollect synRule;
			  	  relCat=NULL;	// recollect relCat; 
				  tarCat=NULL;	// recollect tarCat;
			  	  finish=1;	// finish!				  
			  	}
			  else { delete relCat; relCat=NULL; }
			}		 
		}
	assert(finish==1);
	updLTMem();	// during insertion of new category or syntactic rules, some lexical rules/categories/syntactic rules might be deleted!
}

void CLTMem::SetRelRule(int PredCase, double ChildAdultAbiRatio, int NoAcqCatSynExm, double DetLocOrdRate, int locRel, CLexRule *lexrule1, int themrole1, CLexRule *lexrule2, int themrole2, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace)
{ // find related lexrules that follow same order; and set up new category, lexical rules;
  // 2 search: fix lexrule1 as target and fix lexrule as target;
  // PredCase=0, merge pred1 and pred2; PredCase=1, do not merge pred1 and pred2;
  	assert((locRel==0)||(locRel==1)||(locRel==2)); assert((PredCase==0)||(PredCase==1)); assert(NoAcqCatSynExm>=2); 
  	assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert((FLOAT_SM_EQ(0.0, DetLocOrdRate))&&(FLOAT_SM_EQ(DetLocOrdRate, 1.0))); assert((lexrule1!=NULL)&&(lexrule2!=NULL)); assert(semspace!=NULL);
	CLexRule **relLexRule=NULL;	// the related lexical rules that have same location relation to the target lexical rule;
	int numrelLexRule;	// number of related lexical rules;
	
	// use lexrule1 as target, update other related lexical rules into relLexRule;
	numrelLexRule=0; FindOtherRelRule(1, ChildAdultAbiRatio, DetLocOrdRate, lexrule1, themrole1, themrole2, locRel, relLexRule, &numrelLexRule, newCandMU, numCandMU, semspace);	
	if(numrelLexRule>=NoAcqCatSynExm) bltCatSyn(1, PredCase, locRel, lexrule1, themrole1, themrole2, relLexRule, numrelLexRule, semspace);	// build up new category and syntactic rules;
	if(numrelLexRule!=0) delete [] relLexRule; relLexRule=NULL;	// release memory for relRule;				  
	
	// use lexrule2 as target, update other related lexical rules into relLexRule;
	numrelLexRule=0; FindOtherRelRule(2, ChildAdultAbiRatio, DetLocOrdRate, lexrule2, themrole2, themrole1, locRel, relLexRule, &numrelLexRule, newCandMU, numCandMU, semspace);	
	if(numrelLexRule>=NoAcqCatSynExm) bltCatSyn(2, PredCase, locRel, lexrule2, themrole2, themrole1, relLexRule, numrelLexRule, semspace);	// build up new category and syntactic rules;
	if(numrelLexRule!=0) delete [] relLexRule; relLexRule=NULL;	// release memory for relRule;	
}

void CLTMem::AcqCat(int PredCase, double ChildAdultAbiRatio, int NoAcqCatSynExm, double DetLocOrdRate, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace)
{ // use newCandMU's information to acquire new categories and syntactic rules;
  // PredCase=0, merge pred1 and pred2; PredCase=1, do not merge pred1 and pred2;
  	assert((PredCase==0)||(PredCase==1)); assert((FLOAT_SM_EQ(0.0, ChildAdultAbiRatio))&&(FLOAT_SM_EQ(ChildAdultAbiRatio, 1.0))); assert(NoAcqCatSynExm>=2); 
  	assert((FLOAT_SM_EQ(0.0, DetLocOrdRate))&&(FLOAT_SM_EQ(DetLocOrdRate, 1.0))); assert((newCandMU!=NULL)&&(numCandMU!=0)); assert(semspace!=NULL);
	int i, j;
	CLexRule *lexrule1=NULL, *lexrule2=NULL, *lexrule3=NULL;	// each time choose 2 rules;
	bool islexrule1, islexrule2, islexrule3;

	// search all lexical rules in newCandMU; choose 2 by 2;
	for(i=0;i<numCandMU;i++)
		for(j=0;j<newCandMU[i]->m_nNumMatSet;j++)
		  	{ if(newCandMU[i]->m_ppMatSet[j]->m_nNumLexRule==3)
		  		{ // 3 word rules match;
				  lexrule1=newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[0]; lexrule2=newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[1]; lexrule3=newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[2];
				  islexrule1=Judge_InLex(lexrule1); islexrule2=Judge_InLex(lexrule2); islexrule3=Judge_InLex(lexrule3);
				  if((islexrule1==1)&&(islexrule2==1)&&(islexrule3==1))
				  	{ // check S and V, S and O and V and O; 
				  	  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 3, newCandMU, numCandMU, semspace);	// Ag+Pred2; before or after relation;
					  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[2], lexrule1, 1, lexrule3, 4, newCandMU, numCandMU, semspace);	// Ag+Pat; before or after relation;
					  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[1], lexrule2, 3, lexrule3, 4, newCandMU, numCandMU, semspace);	// Pred2+Pat; before or after relation;
				  	}
				  else if((islexrule1==1)&&(islexrule2==1)&&(islexrule3==0))
				  	{ // check S and V; 
				  	  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 3, newCandMU, numCandMU, semspace);	// Ag+Pred2; before or after relation;
				  	  newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[2]=NULL;	// recollect lexrule3's position;
				  	}
				  else if((islexrule1==1)&&(islexrule2==0)&&(islexrule3==1))
				  	{ // check S and O; 
				  	  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[2], lexrule1, 1, lexrule3, 4, newCandMU, numCandMU, semspace);	// Ag+Pat; before or after relation;
				  	  newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[1]=NULL;	// recollect lexrule2's position;
				  	}
				  else if((islexrule1==0)&&(islexrule2==1)&&(islexrule3==1))
				  	{ // check V and O; 
				  	  SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[1], lexrule2, 3, lexrule3, 4, newCandMU, numCandMU, semspace);	// Pred2+Pat; before or after relation;
				  	  newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[0]=NULL;	// recollect lexrule1's position;
				  	}
				  else
				  	{ if(islexrule1==0) newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[0]=NULL;	// recollect lexrule1's position;
				  	  if(islexrule2==0) newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[1]=NULL;	// recollect lexrule2's position;
				  	  if(islexrule3==0) newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[2]=NULL;	// recollect lexrule3's position;
				  	}
				  lexrule1=NULL; lexrule2=NULL; lexrule3=NULL;	// recollect lexrule1, lexrule2, lexrule3;				  		  
				}
		  	  else if(newCandMU[i]->m_ppMatSet[j]->m_nNumLexRule==2)
		  	  	{ // 2 word rules match; or 1 word + 1 phrase match;
				  lexrule1=newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[0]; lexrule2=newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[1];
				  islexrule1=Judge_InLex(lexrule1); islexrule2=Judge_InLex(lexrule2);
				  if((islexrule1==1)&&(islexrule2==1))
				  	{ if((lexrule2->getLexTyp()!=0)&&(lexrule2->getLexTyp()!=1)&&(lexrule2->getLexTyp()!=2))
					  	{ // lexrule2 is a phrase rule; according to lexrule2 to judge;
						  if(chk2SideMeanUtter(1, 7, newCandMU[i]->m_pMU, lexrule2, semspace)==1) 
						 	SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 7, newCandMU, numCandMU, semspace);	// Ag+PredPat; before, after or in between relation;
						  else if(chk2SideMeanUtter(1, 6, newCandMU[i]->m_pMU, lexrule2, semspace)==1) 
							SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 3, lexrule2, 6, newCandMU, numCandMU, semspace);	// Pred2+AgPat; before, after or in between relation;
						  else if(chk2SideMeanUtter(1, 5, newCandMU[i]->m_pMU, lexrule2, semspace)==1) 
						  	SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 4, lexrule2, 5, newCandMU, numCandMU, semspace);	// Pat+AgPred; before, after or in between relation;
						}
					  else
					  	{ // lexrule2 is a word rule; 
					  	  // check whether m_pMU is "Predicate<Agent>" meaning or "Predicate<Agent, Patient>" meaning;
						  if(newCandMU[i]->m_pMU->getpMean()->getElement(2*(newCandMU[i]->m_pMU->getLengthSem()))==-1)
						  	SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 2, newCandMU, numCandMU, semspace);	// "Predicate<Agent>" meaning; Ag+Pred1; before or after relation;
						  else
						  	{ // "Predicate<Agent, Patient>" meaning;
							  if((chk2SideMeanUtter(1, 2, newCandMU[i]->m_pMU, lexrule1, semspace)==1)&&(chk2SideMeanUtter(1, 3, newCandMU[i]->m_pMU, lexrule2, semspace)==1))
					  			SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 3, newCandMU, numCandMU, semspace);	// Ag+Pred2; before or after relation;
							  else if((chk2SideMeanUtter(1, 2, newCandMU[i]->m_pMU, lexrule1, semspace)==1)&&(chk2SideMeanUtter(1, 4, newCandMU[i]->m_pMU, lexrule2, semspace)==1))
					  			SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 1, lexrule2, 4, newCandMU, numCandMU, semspace);	// Ag+Pat; before or after relation;
							  else if((chk2SideMeanUtter(1, 3, newCandMU[i]->m_pMU, lexrule1, semspace)==1)&&(chk2SideMeanUtter(1, 4, newCandMU[i]->m_pMU, lexrule2, semspace)==1))
					  			SetRelRule(PredCase, ChildAdultAbiRatio, NoAcqCatSynExm, DetLocOrdRate, newCandMU[i]->m_ppMatSet[j]->m_pMatSynTyp[0], lexrule1, 3, lexrule2, 4, newCandMU, numCandMU, semspace);	// Pred2+Pat; before or after relation;
							}
					  	}
				  	}
				  else
				  	{ if(islexrule1==0) newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[0]=NULL;	// recollect lexrule1's position;
				  	  if(islexrule2==0) newCandMU[i]->m_ppMatSet[j]->m_ppMatLexRule[1]=NULL;	// recollect lexrule2's position;
				  	}
				  lexrule1=NULL; lexrule2=NULL;	// recollect lexrule1, lexrule2;
		  	  	}			  	  
		}	
}

// decompose fully composible M-U mappings in the buffer;
int CLTMem::TransOrderTyp(MUmatSet *matSet)
{ // translate matSet's m_pMatSynTyp into SVO(3), SOV(4), OSV(5), VSO(6), VOS(7), OVS(8);
  	assert(matSet!=NULL);
  	int value;
  	if((matSet->m_pMatSynTyp[0]==0)&&(matSet->m_pMatSynTyp[1]==0)&&(matSet->m_pMatSynTyp[2]==0)) value=3;	// SVO;
  	else if((matSet->m_pMatSynTyp[0]==0)&&(matSet->m_pMatSynTyp[1]==1)&&(matSet->m_pMatSynTyp[2]==0)) value=4;	// SOV;
  	else if((matSet->m_pMatSynTyp[0]==0)&&(matSet->m_pMatSynTyp[1]==1)&&(matSet->m_pMatSynTyp[2]==1)) value=5;	// OSV;
  	else if((matSet->m_pMatSynTyp[0]==1)&&(matSet->m_pMatSynTyp[1]==0)&&(matSet->m_pMatSynTyp[2]==0)) value=6;	// VSO;
  	else if((matSet->m_pMatSynTyp[0]==1)&&(matSet->m_pMatSynTyp[1]==0)&&(matSet->m_pMatSynTyp[2]==1)) value=7;	// VOS;
  	else if((matSet->m_pMatSynTyp[0]==1)&&(matSet->m_pMatSynTyp[1]==1)&&(matSet->m_pMatSynTyp[2]==1)) value=8;	// OVS;
	else value=-1;
  	return value;
}

bool CLTMem::Chk2Syn(int order, int type, CSynRule *syn1, CSynRule *syn2, CCat *cat11, CCat *cat12, CCat *cat21, CCat *cat22)
{ // check consistency of 2 syntactic rules;
  // type=1, SV+VO; 2, SV+SO; 3, VO+SO;
 	assert((3<=order)&&(order<=8)); assert((1<=type)&&(type<=3)); assert((syn1!=NULL)&&(syn2!=NULL));
 	bool value=0;	
 	switch(order)
 		{ case 3: // SVO;
				if((type==1)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// SV+VO;	
				else if((type==2)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// SV+SO;
				else if((type==3)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// VO+SO;
				break;
		  case 4: // SOV;
				if((type==1)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// SV+OV;
				else if((type==2)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// SV+SO;
				else if((type==3)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// OV+SO;
				break;
		  case 5: // OSV;
				if((type==1)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// SV+OV;
				else if((type==2)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// SV+OS;					  
				else if((type==3)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// OV+OS;
				break;
		  case 6: // VSO;
				if((type==1)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// VS+VO;
				else if((type==2)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// VS+SO; 
				else if((type==3)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// VO+SO;
				break;	
		  case 7: // VOS; 
				if((type==1)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(0, cat21, cat22)==1)) value=1;	// VS+VO; 
				else if((type==2)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	 // VS+OS; 
				else if((type==3)&&(syn1->ChkSynConsist(0, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// VO+OS;
				break;
		  case 8: // OVS;
				if((type==1)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// VS+OV;
				else if((type==2)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// VS+OS; 	
				else if((type==3)&&(syn1->ChkSynConsist(1, cat11, cat12)==1)&&(syn2->ChkSynConsist(1, cat21, cat22)==1)) value=1;	// OV+OS;	
				break;
		  default: break;
		}
 	return value;
}

bool CLTMem::Chk3Cat(int order, CatList *catlist1, CatList *catlist2, CatList *catlist3)
{ // check whether syntactic rules are consistent for three lexical rules' order requirement;
	assert((3<=order)&&(order<=8)); assert((catlist1!=NULL)&&(catlist2!=NULL)&&(catlist3!=NULL));
	CSynRule *syn12=NULL, *syn23=NULL, *syn13=NULL;
	int i, j, k;
	bool value=0;

	// 1) check SV/VS and VO/OV;
	for(i=0;i<getNumSynRule();i++)
		for(j=0;j<getNumSynRule();j++)
			{ syn12=getpSynRuleList(i); syn23=getpSynRuleList(j);
			  if(Chk2Syn(order, 1, syn12, syn23, catlist1->getpCat(), catlist2->getpCat(), catlist2->getpCat(), catlist3->getpCat())==1) value=1;
			  syn12=NULL; syn23=NULL;	// recollect syn12, syn23;
			}
	// 2) check SV/VS and SO/OS;
	for(i=0;i<getNumSynRule();i++)
		for(k=0;k<getNumSynRule();k++)
			{ syn12=getpSynRuleList(i); syn13=getpSynRuleList(k);
			  if(Chk2Syn(order, 2, syn12, syn13, catlist1->getpCat(), catlist2->getpCat(), catlist1->getpCat(), catlist3->getpCat())==1) value=1;
			  syn12=NULL; syn13=NULL;	// recollect syn12, syn13;
			}
	// 3) check VO/OV and SO/OS;
	for(j=0;j<getNumSynRule();j++)
		for(k=0;k<getNumSynRule();k++)
			{ syn23=getpSynRuleList(j); syn13=getpSynRuleList(k);
			  if(Chk2Syn(order, 3, syn23, syn13, catlist2->getpCat(), catlist3->getpCat(), catlist1->getpCat(), catlist3->getpCat())==1) value=1;
			  syn23=NULL; syn13=NULL;	// recollect syn23, syn13;
			}		  
	return value;
}

bool CLTMem::CombMUtemp(CMeanUtter *MU, MUmatSet *matSet)
{ // using matSet's rules to combine MUtemp and compare it with MU;
  // considering not only lexical rules, but also their catgeories and syntactic rules;
  	assert((MU!=NULL)&&(matSet!=NULL));
	int i, j, k, m;
  	CMeanUtter *MUtemp=NULL;
  	CatList *catlist1=NULL, *catlist2=NULL, *catlist3=NULL;
  	CSynRule *syn12=NULL;
  	bool value=0;

	// initialize MUtemp;
	MUtemp=new CMeanUtter; assert(MUtemp!=NULL);

	switch(matSet->m_nNumLexRule)
  		{ case 2: if((matSet->m_ppMatLexRule[0]->getLexTyp()==1)&&(matSet->m_ppMatLexRule[1]->getLexTyp()==2))
					{ // 2 word rules for "Predicate<Agent>" meaning;
					  if(getDecHolistPhrase()==0)
					  	{ // use category and syntactic rule to combine;
						  for(i=0;i<matSet->m_ppMatLexRule[0]->getCatNum();i++)
						  	{ if(matSet->m_ppMatLexRule[0]->getpCatList(i)->getThemRole()==1)
						  	  	{ // lexrule1's category is Ag; 
								  catlist1=matSet->m_ppMatLexRule[0]->getpCatList(i);
						  	  	  for(j=0;j<matSet->m_ppMatLexRule[1]->getCatNum();j++)
						  			{ catlist2=matSet->m_ppMatLexRule[1]->getpCatList(j);
						  			  if(matSet->m_pMatSynTyp[0]==0)
						  				{ // S before V;
						  				  for(m=0;m<getNumSynRule();m++)
										  	{ syn12=getpSynRuleList(m);
											  if(chkSynCond1(1, catlist1, catlist2, syn12)==1)
										  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
												  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												}
										  	  syn12=NULL;	// recollect syn12;
										  	}									  								  
						  				}
						  		  	  else if(matSet->m_pMatSynTyp[0]==1)
						 	 		  	{ // S after V;
										  for(m=0;m<getNumSynRule();m++)
										  	{ syn12=getpSynRuleList(m);
											  if(chkSynCond1(2, catlist1, catlist2, syn12)==1)
										  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
												  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
										  		}
										  	  syn12=NULL;	// recollect syn12;
									  		}								  	  
						  		  		}
						  		  	  catlist2=NULL;	// recollect catlist2;
						  			}
						  	  	  catlist1=NULL;	// recollect catlist1;
						 		}
							}
					  	}
					  else if(getDecHolistPhrase()==1)
					  	{ // direct combine;
						  if(matSet->m_pMatSynTyp[0]==0)
						  	{ // S before V; 
						  	  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
						  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
						  	}
						  else if(matSet->m_pMatSynTyp[0]==1)
						  	{ // S after V;
						  	  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
						  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
						  	}
						}
					}
				else
					{ // 1 word + 1 phrase for "Predicate<Agent, Patient>" meaning;
					  if((matSet->m_ppMatLexRule[1]->getLexTyp()==5)||(matSet->m_ppMatLexRule[1]->getLexTyp()==8))
					  	{ // Ag + PredPat;
						  if(getDecHolistPhrase()==0)
						  	{ // use category and syntactic rule to combine;
							  for(i=0;i<matSet->m_ppMatLexRule[0]->getCatNum();i++)
							  	{ if(matSet->m_ppMatLexRule[0]->getpCatList(i)->getThemRole()==1)
						  	  		{ // lexrule1's category is Ag;  
									  catlist1=matSet->m_ppMatLexRule[0]->getpCatList(i);
							  	  	  for(j=0;j<matSet->m_ppMatLexRule[1]->getCatNum();j++)
						  				{ catlist2=matSet->m_ppMatLexRule[1]->getpCatList(j);
						  				  if(matSet->m_pMatSynTyp[0]==0)
						  					{ // S before VO/OV;	
											  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(9, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
											  	  	}
											  	  syn12=NULL;	// recollect syn12;
									  			}
						  					}
						  		  	  	  else if(matSet->m_pMatSynTyp[0]==1)
						  		 	 		{ // S after VO/OV;
						  		  			  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(10, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
											  	  	}
											  	  syn12=NULL;	// recollect syn12;		
									  			}
						  		  			}
						  		  	  	  else if(matSet->m_pMatSynTyp[0]==2)
						  		  		  	{ // S in between VO/OV;
											  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(11, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
											  	  	}
											  	  syn12=NULL;	// recollect syn12;		
									  			}
						  		  	  		}
						  		  	  	  catlist2=NULL;	// recollect catlist2temp;
							  	  	  	}
							  	  	  catlist1=NULL;	// recollect catlist1temp;
							  		}
						  		}
							}
						  else if(getDecHolistPhrase()==1)
						  	{ // direct combine;
							  if(matSet->m_pMatSynTyp[0]==0)
						  		{ // S before VO/OV;	
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==1)
						  		{ // S after VO/OV;
						  		  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==2)
						  	  	{ // S in between VO/OV;
							  	  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
						  	}	
						}
					  else if((matSet->m_ppMatLexRule[1]->getLexTyp()==4)||(matSet->m_ppMatLexRule[1]->getLexTyp()==7))
					  	{ // Pred2 + AgPat;
						  if(getDecHolistPhrase()==0)
						  	{ // use category and syntactic rule to combine;
							  for(i=0;i<matSet->m_ppMatLexRule[0]->getCatNum();i++)
							  	for(j=0;j<matSet->m_ppMatLexRule[1]->getCatNum();j++)
						  			{ catlist1=matSet->m_ppMatLexRule[0]->getpCatList(i); catlist2=matSet->m_ppMatLexRule[1]->getpCatList(j);
						  			  if(matSet->m_pMatSynTyp[0]==0)
						  				{ // V before SO/OS;	
										  for(m=0;m<getNumSynRule();m++)
									  		{ syn12=getpSynRuleList(m);
										  	  if(chkSynCond1(12, catlist1, catlist2, syn12)==1)
										  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
												  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												}
											  syn12=NULL;	// recollect syn12;
									  		}
						  				}
						  		  	  else if(matSet->m_pMatSynTyp[0]==1)
						  		  		{ // V after SO/OS;
										  for(m=0;m<getNumSynRule();m++)
									  		{ syn12=getpSynRuleList(m);
										  	  if(chkSynCond1(13, catlist1, catlist2, syn12)==1)
										  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
												  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												}
											  syn12=NULL;	// recollect syn12;
									  		}
						  		  		}
						  		  	  else if(matSet->m_pMatSynTyp[0]==2)
						  		  	  	{ // V in between SO/OS;
										  for(m=0;m<getNumSynRule();m++)
									  		{ syn12=getpSynRuleList(m);
										  	  if(chkSynCond1(14, catlist1, catlist2, syn12)==1)
										  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
												  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												}
											  syn12=NULL;	// recollect syn12;
									  		}
						  		  	  	}
						  		  	  catlist1=NULL; catlist2=NULL;	// recollect catlist1temp, catlist2temp;
						  			}
							}
						  else if(getDecHolistPhrase()==1)
						  	{ // direct combine;
							  if(matSet->m_pMatSynTyp[0]==0)
						  		{ // V before SO/OS;	
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==1)
						  		{ // V after SO/OS;
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==2)
						  	  	{ // V in between SO/OS;
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							}
						}
					  else if((matSet->m_ppMatLexRule[1]->getLexTyp()==3)||(matSet->m_ppMatLexRule[1]->getLexTyp()==6))
					  	{ // Pat + AgPred;
						  if(getDecHolistPhrase()==0)
						  	{ // use category and syntactic rule to combine;
							  for(i=0;i<matSet->m_ppMatLexRule[0]->getCatNum();i++)
							  	{ if(matSet->m_ppMatLexRule[0]->getpCatList(i)->getThemRole()==4)
						  	  		{ // lexrule1's category is Pat;  
									  catlist1=matSet->m_ppMatLexRule[0]->getpCatList(i);
						  	  		  for(j=0;j<matSet->m_ppMatLexRule[1]->getCatNum();j++)
						  				{ catlist2=matSet->m_ppMatLexRule[1]->getpCatList(j);
						  				  if(matSet->m_pMatSynTyp[0]==0)
						  					{ // O before SV/VS;	
											  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(15, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												  	}
												  syn12=NULL;	// recollect syn12;
										  		}
						 	 				}
							  		  	  else if(matSet->m_pMatSynTyp[0]==1)
						  			  		{ // O after SV/VS;
											  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(16, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												  	}
											  	  syn12=NULL;	// recollect syn12;
										  		}
						  			  		}
						 	 		  	  else if(matSet->m_pMatSynTyp[0]==2)
						 	 		  	  	{ // O in between SV/VS;
											  for(m=0;m<getNumSynRule();m++)
										  		{ syn12=getpSynRuleList(m);
											  	  if(chkSynCond1(17, catlist1, catlist2, syn12)==1)
											  	  	{ MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
												  	  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
												  	}
											  	  syn12=NULL;	// recollect syn12;
											  	}
						  			  	  	}
						 	 		  	  catlist2=NULL;	// recollect catlist2temp;
						  				}
						  	  		  catlist1=NULL;	// recollect catlist1temp;
						  			}
							  	}
							}
						  else if(getDecHolistPhrase()==1)
						  	{ // direct combine;
							  if(matSet->m_pMatSynTyp[0]==0)
						  		{ // O before SV/VS;	
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 0);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==1)
						  		{ // O after SV/VS;
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 1);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							  else if(matSet->m_pMatSynTyp[0]==2)
						 	  	{ // O in between SV/VS;
								  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), 2);
								  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
								}
							}
					  	}
					}
				break;
  		  case 3: // 3 word rules for "Predicate<Agent, Patient>" meaning;
				if(getDecHolistPhrase()==0)
					{ // use category and syntactic rule to combine;
					  // all 3 rules must have their own categories;				
					  for(i=0;i<matSet->m_ppMatLexRule[0]->getCatNum();i++)
						{ if(matSet->m_ppMatLexRule[0]->getpCatList(i)->getThemRole()==1)
							{ // lexrule1's category is Ag;
							  catlist1=matSet->m_ppMatLexRule[0]->getpCatList(i);
							  for(j=0;j<matSet->m_ppMatLexRule[1]->getCatNum();j++)
								for(k=0;k<matSet->m_ppMatLexRule[2]->getCatNum();k++)
									{ if(matSet->m_ppMatLexRule[2]->getpCatList(k)->getThemRole()==4)
										{ // lexrule3's category is Pat;
										  catlist2=matSet->m_ppMatLexRule[1]->getpCatList(j); catlist3=matSet->m_ppMatLexRule[2]->getpCatList(k);
										  if(Chk3Cat(TransOrderTyp(matSet), catlist1, catlist2, catlist3)==1)
											{ MUtemp->EmptypUtter(); MUtemp->Comb3Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), matSet->m_ppMatLexRule[2]->getpMeanUtter(), matSet->m_pMatSynTyp[0], matSet->m_pMatSynTyp[1], matSet->m_pMatSynTyp[2]);
											  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
											}
										  catlist2=NULL; catlist3=NULL;	// recollect catlist2temp, catlist3temp;
										}
							  		}
							  catlist1=NULL;	// recollect catlist1temp;
							}
						}
					}
			  	else if(getDecHolistPhrase()==1)
			  		{ // direct combine;
					  MUtemp->EmptypUtter(); MUtemp->Comb3Utter(matSet->m_ppMatLexRule[0]->getpMeanUtter(), matSet->m_ppMatLexRule[1]->getpMeanUtter(), matSet->m_ppMatLexRule[2]->getpMeanUtter(), matSet->m_pMatSynTyp[0], matSet->m_pMatSynTyp[1], matSet->m_pMatSynTyp[2]);
					  if(*(MUtemp->getpUtter())==*(MU->getpUtter())) value=1;
					}
			  	break;
  		  default: break;
  		}
	delete MUtemp; MUtemp=NULL;	// release MUtemp;
	return value;
}

bool CLTMem::testComb(CandMU *candMU)
{ // test whether newCandMU's m_pMU can be fully decomposed;
	assert(candMU!=NULL);
	int i;
	bool value=0;
	for(i=0;i<candMU->m_nNumMatSet;i++)
		{ if(candMU->m_bComp==0) break;	// meaning part is not fully matched, indecomposible;
		  else
		  	{ value=CombMUtemp(candMU->m_pMU, candMU->m_ppMatSet[i]);
		  	  if(value==1) break;
		  	}
		}
	return value;
}
void CLTMem::updMatTypMatLex(int type, CLexRule *lex1, CLexRule *lex2, CLexRule **&MatLex, int *&MatTyp, int *numMatLex)
{ // update lex1, lex2 into MatLex and their type to MatTyp;
	assert((type==1)||(type==2)); assert((lex1!=NULL)&&(lex2!=NULL));
	int i;
	CLexRule **MatLextemp=NULL;
	int *MatTyptemp=NULL;
	int numnewMatLex, numnewMatTyp;

	if(*numMatLex==0)
		{ // update MatLex; 
		  (*numMatLex)+=2;
		  MatLex=new CLexRule * [*numMatLex]; assert(MatLex!=NULL);
		  MatLex[0]=lex1; MatLex[1]=lex2;
		  // update MatTyp;
		  MatTyp=new int [1]; assert(MatTyp!=NULL);
		  MatTyp[0]=type;
		}
	else
		{ // no need to check identical 
		  numnewMatLex=(*numMatLex)+2; 
		  numnewMatTyp=(int)((*numMatLex)/_Twice)+1;
		  // update MatLextemp;
		  MatLextemp=new CLexRule * [numnewMatLex]; assert(MatLextemp!=NULL);
		  for(i=0;i<numnewMatLex;i++)
		  	MatLextemp[i]=NULL;
		  for(i=0;i<numnewMatLex-2;i++)
		  	MatLextemp[i]=MatLex[i];
		  MatLextemp[numnewMatLex-2]=lex1; MatLextemp[numnewMatLex-1]=lex2;
		  // delete original MatLex;
		  delete [] MatLex; MatLex=NULL;
		  *numMatLex=0;
		  // copy MatLextemp to MatLex;
		  *numMatLex=numnewMatLex; MatLex=MatLextemp;
		  MatLextemp=NULL;	// recollect MatLextemp;
		  // update MatTyptemp;
		  MatTyptemp=new int [numnewMatTyp]; assert(MatTyptemp!=NULL);
		  for(i=0;i<numnewMatTyp-1;i++)
		  	MatTyptemp[i]=MatTyp[i];
		  MatTyptemp[numnewMatTyp-1]=type;
		  // delete original MatTyp;
		  delete [] MatTyp; MatTyp=NULL;
		  // copy MatTyptemp to MatTyp;
		  MatTyp=MatTyptemp;	
		  MatTyptemp=NULL;	// recollect MatTyptemp;
		}
}

void CLTMem::chkMatPhraseRule(int type, CMeanUtter *MU, CLexRule *lex1, int themRole1, CLexRule *lex2, int themRole2, int *numPair, CLexRule **&MatLex, int *&MatTyp, int *numMatLex)
{ // check whether lex1, lex2 can fully match phrase MU;
	assert((3<=type)&&(type<=8)); assert((MU!=NULL)&&(lex1!=NULL)&&(lex2!=NULL));
	int i, j, k;
	int len, leftlen, rightlen, lex1len, lex2len;
	CMeanUtter *MUtemp=NULL;	// store combined MU using lex1, lex2;
	CCat *cat1=NULL, *cat2=NULL;
	
	lex1len=lex1->getpMeanUtter()->getUtterLen(); lex2len=lex2->getpMeanUtter()->getUtterLen();
	switch(type)
		{ case 3: case 4: case 5: // continuous phrase;
				// initialize MUtemp;
				MUtemp=new CMeanUtter; assert(MUtemp!=NULL);
				len=MU->getUtterLen(); 
				if(len==lex1len+lex2len)
					{ if(getDecHolistPhrase()==0)
						{ // use related category and syntactic rule to combine; 
					  	  for(i=0;i<lex1->getCatNum();i++)
							for(j=0;j<lex2->getCatNum();j++)
								{ if((lex1->getpCatList(i)->getpCat()->getThemRole()==themRole1)&&(lex2->getpCatList(j)->getpCat()->getThemRole()==themRole2))
									{ cat1=lex1->getpCatList(i)->getpCat(); cat2=lex2->getpCatList(j)->getpCat();
									  for(k=0;k<getNumSynRule();k++)
									  	{ if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat1)&&(getpSynRuleList(k)->getpCat(1)==cat2))
									  		{ if(getpSynRuleList(k)->getSynTyp()==0)
									  			{ // before;
												  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 0);	// before;
												  if(*MUtemp==*MU) 
												  	{ updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
												  	  (*numPair)++;
												  	}
									  			}
											  else if(getpSynRuleList(k)->getSynTyp()==1)
											  	{ // after;
												  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 1);	// after;
												  if(*MUtemp==*MU) 
												  	{ updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
												  	  (*numPair)++;
												  	}
											  	}
									  		}
									  	  else if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat2)&&(getpSynRuleList(k)->getpCat(1)==cat1))
									  	  	{ if(getpSynRuleList(k)->getSynTyp()==0)
									  			{ // after;
												  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 1);	// after;
												  if(*MUtemp==*MU) 
												  	{ updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
												  	  (*numPair)++;
												  	}
											  	}
											  else if(getpSynRuleList(k)->getSynTyp()==1)
											  	{ // before;
												  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 0);	// before;
												  if(*MUtemp==*MU) 
												  	{ updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
												  	  (*numPair)++;
												  	}
									  			}
									  	  	}
									  	}
									  cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
									}
								}
						}
					  else if(getDecHolistPhrase()==1)
					  	{ // direct combine;	
					  	  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 0);	// before;
						  if(*MUtemp==*MU) 
						 	{ updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
						  	  (*numPair)++;					  	  
						  	}
						  MUtemp->EmptypUtter(); MUtemp->Comb2Utter(lex1->getpMeanUtter(), lex2->getpMeanUtter(), 1);	// after;
						  if(*MUtemp==*MU) 
						 	{ updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
						  	  (*numPair)++;
						  	}
						}
					}
				delete MUtemp; MUtemp=NULL;	// delete MUtemp;
				break;
		  case 6: case 7: case 8: // separate phrase;
				leftlen=MU->getLeftUtterLen(); rightlen=MU->getRightUtterLen();
				if((leftlen==lex1len)&&(rightlen==lex2len))
					{ for(i=0;i<leftlen;i++)
						{ if(MU->getpUtter()->getElement(i)!=lex1->getpMeanUtter()->getpUtter()->getElement(i))
							break;
						}
					  for(j=0;j<rightlen;j++)
					  	{ if(MU->getpUtter()->getElement(MU->getLengthIntgUtter()-rightlen+j)!=lex2->getpMeanUtter()->getpUtter()->getElement(j))
					  		break;
					  	}
					  if((i==leftlen)&&(j==rightlen))
					  	{ // before;
						  if(getDecHolistPhrase()==0)
						  	{ // use related category and syntactic rule;
					 	 	  for(i=0;i<lex1->getCatNum();i++)
					 		 	for(j=0;j<lex2->getCatNum();j++)
					  				{ if((lex1->getpCatList(i)->getpCat()->getThemRole()==themRole1)&&(lex2->getpCatList(j)->getpCat()->getThemRole()==themRole2))
					  					{ cat1=lex1->getpCatList(i)->getpCat(); cat2=lex2->getpCatList(j)->getpCat();
					  					  for(k=0;k<getNumSynRule();k++)
											{ if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat1)&&(getpSynRuleList(k)->getpCat(1)==cat2)&&(getpSynRuleList(k)->getSynTyp()==0))
												{ updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
												  (*numPair)++;
												}
											  else if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat2)&&(getpSynRuleList(k)->getpCat(1)==cat1)&&(getpSynRuleList(k)->getSynTyp()==1))
											  	{ updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
												  (*numPair)++;
											  	}
											}
										  cat1=NULL; cat2=NULL; // recollect cat1, cat2;
							  			}
							  		}
						  	}
						  else if(getDecHolistPhrase()==1)
						  	{ // direct combine;
						  	  updMatTypMatLex(1, lex1, lex2, MatLex, MatTyp, numMatLex);
						  	  (*numPair)++;
						  	}
					  	}
					}
				if((leftlen==lex2len)&&(rightlen==lex1len))
					{ for(i=0;i<leftlen;i++)
						{ if(MU->getpUtter()->getElement(i)!=lex2->getpMeanUtter()->getpUtter()->getElement(i))
							break;
						}
					  for(j=0;j<rightlen;j++)
					  	{ if(MU->getpUtter()->getElement(MU->getLengthIntgUtter()-rightlen+j)!=lex1->getpMeanUtter()->getpUtter()->getElement(j))
					  		break;
					  	}
					  if((i==leftlen)&&(j==rightlen))
					  	{ // after; 
						  if(getDecHolistPhrase()==0)
						  	{ // use related category and syntactic rule;
							  for(i=0;i<lex1->getCatNum();i++)
							  	for(j=0;j<lex2->getCatNum();j++)
							  		{ if((lex1->getpCatList(i)->getpCat()->getThemRole()==themRole1)&&(lex2->getpCatList(j)->getpCat()->getThemRole()==themRole2))
							  			{ cat1=lex1->getpCatList(i)->getpCat(); cat2=lex2->getpCatList(j)->getpCat();
							  			  for(k=0;k<getNumSynRule();k++)
											{ if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat1)&&(getpSynRuleList(k)->getpCat(1)==cat2)&&(getpSynRuleList(k)->getSynTyp()==1))
												{ updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
												  (*numPair)++;
												}
											  else if((getpSynRuleList(k)->getSynTyp()!=-1)&&(getpSynRuleList(k)->getpCat(0)==cat2)&&(getpSynRuleList(k)->getpCat(1)==cat1)&&(getpSynRuleList(k)->getSynTyp()==0))
											  	{ updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
												  (*numPair)++;
											  	}
											}
										  cat1=NULL; cat2=NULL; // recollect cat1, cat2;
							  			}
							  		}
							}
						  else if(getDecHolistPhrase()==1)
						  	{ // direct combine;
							  updMatTypMatLex(2, lex1, lex2, MatLex, MatTyp, numMatLex);
							  (*numPair)++;
							}
						}
					}
		  		break;
		  default: break;		  
		}
}

bool CLTMem::decomHolist(CLexRule *holistrule, CSemSpace *semspace)
{ // try decomposing holistic rule;
	assert((holistrule!=NULL)&&(semspace!=NULL));
	CMeanUtter *MU=NULL;
	CandMU **newCandMU=NULL;
  	int i, numCandMU;
  	bool value=0;

	numCandMU=0; MU=holistrule->getpMeanUtter();
	SetCandMU(0, semspace, MU, newCandMU, &numCandMU);
	if(numCandMU!=0)
		{ value=testComb(newCandMU[0]);	// test whether newCandMU[0]->m_pMU can be fully decomposed;
		  // release memory space for newCandMU;
		  for(i=0;i<numCandMU;i++)
		  	{ delete newCandMU[i]; newCandMU[i]=NULL; }
		  delete [] newCandMU; newCandMU=NULL;
		}	
	MU=NULL;	// recollect MU;
	return value;
}

bool CLTMem::decomPhrase(CLexRule *phraserule, CSemSpace *semspace)
{ // try decomposing phrase rule;
  	assert((phraserule!=NULL)&&(semspace!=NULL));
  	CMeanUtter *MU=NULL;
  	CandMU **newCandMU=NULL;
  	int i, numCandMU;
  	bool value=0;

  	numCandMU=0; MU=phraserule->getpMeanUtter();
  	SetCandMU(phraserule->getLexTyp(), semspace, MU, newCandMU, &numCandMU);
	if(numCandMU!=0)
		{ value=newCandMU[0]->m_bComp;	// test whether newCandMU[0]->m_pMU can be fully decomposed;
		  // release memory space for newCandMU;
		  for(i=0;i<numCandMU;i++)
		  	{ delete newCandMU[i]; newCandMU[i]=NULL; }
		  delete [] newCandMU; newCandMU=NULL;
		}	
	MU=NULL;	// recollect MU;
	return value;
}

// check category link;
void CLTMem::updCatLink(int *&newCatLink, int **&CatLink, int *numCatLink, int size)
{ // update newCatLink into CatLink;
	assert(newCatLink!=NULL);
	int i, j;
	int **CatLinktemp=NULL;
	int numnewCatLink;

	if(*numCatLink==0) 
		{ // create CatLink; 
		  (*numCatLink)++;
		  CatLink=new int * [*numCatLink]; assert(CatLink!=NULL);
		  CatLink[0]=newCatLink;
		}
	else
		{ // check whether newCatLink is already in CatLink!
		  for(i=0;i<*numCatLink;i++)
		  	{ for(j=0;j<size;j++)
		  	  	{ if(CatLink[i][j]!=newCatLink[j]) break;
		  	  	}
			  if(j==size) break;
		  	}
		  if(i==*numCatLink)
		  	{ // a new CatLink;
		  	  numnewCatLink=(*numCatLink)+1;	// increase the current number of CatLink;
		  	  CatLinktemp=new int * [numnewCatLink]; assert(CatLinktemp!=NULL);
			  for(i=0;i<numnewCatLink;i++)
			  	CatLinktemp[i]=NULL;
		  	  for(i=0;i<numnewCatLink-1;i++)
		  		CatLinktemp[i]=CatLink[i];
		  	  CatLinktemp[numnewCatLink-1]=newCatLink;
		  	  // delete original CatLink;
		  	  delete [] CatLink; CatLink=NULL;
		  	  *numCatLink=0;
		  	  // copy CatLinktemp to CatLink;
		  	  *numCatLink=numnewCatLink; CatLink=CatLinktemp;
		  	  CatLinktemp=NULL;	// recollect CatLinktemp;
		  	}
		  else { delete [] newCatLink; newCatLink=NULL; }
		}
}

void CLTMem::setLinkTyp(CCat *cat, int *newCatLink, int size, int index)
{ // set up newCatLink[index];
	assert((cat!=NULL)&&(newCatLink!=NULL)); assert((0<=index)&&(index<size));
	switch(cat->getThemRole())
		{ case 0: newCatLink[index]=1; break;	// holistic category;
		  case 1: newCatLink[index]=2; break;	// Ag category;
		  case 2: newCatLink[index]=3; break;	// Pred category;
		  case 3: newCatLink[index]=4; break;	// Pat category;
		  case 4: case 5: case 6: newCatLink[index]=5; break;	// phrasal category;
		  default: break;
		}
}

void CLTMem::chkCatLink(int **&CatLink, int *numCatLink, CLexRule **comLex, int numcomLex)
{ // check lexical rules in comLex's category relation;
	assert((comLex!=NULL)&&(numcomLex!=0));
	int i, j, k, m, n, p, q;
	CLexRule *lex1=NULL, *lexOther=NULL;
	CCat *cat=NULL;
	int *newCatLink=NULL;

	for(i=0;i<numcomLex;i++)
		{ // first, find the corresponding lexical rule in m_ppLTMem;
		  for(j=0;j<getNumLexRule();j++)
		  	{ if(*(comLex[i]->getpMeanUtter())==*(getpLexRuleList(j)->getpMeanUtter()))
		  		{ lex1=getpLexRuleList(j);
				  // check all category to see if there are comLex rules sharing in same category;
				  for(k=0;k<getNumCat();k++)
				  	{ cat=getpCatList(k);
				  	  for(m=0;m<cat->getLexNum();m++)
				  	  	{ if(cat->getpLexRule(m)==lex1)
				  	  		{ // initialize newCatLink;
				  			  newCatLink=new int [numcomLex]; assert(newCatLink!=NULL);
				  			  for(n=0;n<numcomLex;n++)
				  				newCatLink[n]=0;
							  setLinkTyp(cat, newCatLink, numcomLex, i);	// set up newCatLink[i]; itself;							  
				  			  for(n=0;n<numcomLex;n++)
				  				{ if(n!=i)
				  					{ // check if cat still has other comLex;
				  		  			  for(p=0;p<getNumLexRule();p++)
				  		  				{ if(*(comLex[n]->getpMeanUtter())==*(getpLexRuleList(p)->getpMeanUtter()))
				  		  					{ lexOther=getpLexRuleList(p);
											  // check whether lexOther is in cat;
											  for(q=0;q<cat->getLexNum();q++)
											  	{ if(cat->getpLexRule(q)==lexOther)
													setLinkTyp(cat, newCatLink, numcomLex, n);	// set up newCatLink[n];
											  	}
				  		  					}
				  		  				}
				  					}
				  				}
							  // update newCatLink into CatLink;
							  updCatLink(newCatLink, CatLink, numCatLink, numcomLex);
							  newCatLink=NULL;	// recollect newCatLink;
				  	  		}
				  	  	}
					  cat=NULL;	// recollect cat;
				  	}			  
		  		}
		  	}
		}	
}

// output part;
void CLTMem::RecLTMem(FILE * f, CSemSpace *semspace)
{ // record LTMem in f;
	assert((f!=NULL)&&(semspace!=NULL));
	int i, j, m, n;
	CCat *Cat=NULL;	// record category;
	CSynRule *SynRule=NULL;	// record syntactic rule;
	
	int widthLex=(int)(log10((double)(getMaxLexRule()))+1);
	int widthCat=(int)(log10((double)(getMaxCat()))+1);
	int widthSyn=(int)(log10((double)(getMaxSynRule()))+1);
	int widthSynStr=(int)(-1.0*log10((double)(overallpara.p_dSynRuleStrUp))+0.5);
	int widthDecSynStr=(int)(-1.0*log10((double)(overallpara.p_dSynRuleStrLow))+0.5);
	int widthAssoWei=(int)(-1.0*log10((double)(overallpara.p_dAssoWeiUp))+0.5);
	int widthDecAssoWei=(int)(-1.0*log10((double)(overallpara.p_dAssoWeiLow))+0.5);
	
	// record lexical rules;
	fprintf(f, "NumLexRule=%*d\n", widthLex, getNumLexRule());
	for(i=0;i<getNumLexRule();i++)
		{ fprintf(f, "Lex%*d ", widthLex, i);	
		  getpLexRuleList(i)->RecLexRule(f, semspace);
	  	}
	fprintf(f, "\n");
	// record category;
	fprintf(f, "NumCategory=%*d\n", widthCat, getNumCat());	
	for(i=0;i<getNumCat();i++)
	  	{ Cat=getpCatList(i);
	  	  fprintf(f, "Cat%*d", widthCat, i); Cat->recCatTyp(f);  
	  	  fprintf(f,"\n");
		  // list all lexrule and synrule;
		  fprintf(f, "NumLex=%*d: ", widthLex, Cat->getLexNum());
		  for(j=0;j<Cat->getLexNum();j++)
		  	{ for(m=0;m<getNumLexRule();m++)
		  		{ if(Cat->getpLexRule(j)==getpLexRuleList(m))
		  			{ for(n=0;n<getpLexRuleList(m)->getCatNum();n++)
		  				{ if(getpLexRuleList(m)->getpCatList(n)->getpCat()==Cat) break;
		  				}
		  			  fprintf(f, "Lex%*d (%*.*f); ", widthLex, m, widthAssoWei+widthDecAssoWei+1, widthDecAssoWei, getpLexRuleList(m)->getpCatList(n)->getAssoWei()); 
					  break; 
		  			}
		  		}
		  	}
		  if(Cat->getThemRole()!=0)
		  	{ fprintf(f, "\nNumSyn=%*d: ", widthSyn, Cat->getSynNum());
		  	  for(j=0;j<Cat->getSynNum();j++)
		  		{ for(m=0;m<getNumSynRule();m++)
		  			{ if(Cat->getpSynRule(j)==getpSynRuleList(m)) { fprintf(f, "Syn%*d; ", widthSyn, m); break; }
		  			}
		  		}
		  	}
		  else fprintf(f, "\n");
		  Cat=NULL;	// recollect Cat;
		  fprintf(f, "\n");
		}
	fprintf(f, "\n");
	// record syntactic rule;
	fprintf(f, "NumSynRule=%*d\n", widthSyn, getNumSynRule());
	for(i=0;i<getNumSynRule();i++)
	  	{ SynRule=getpSynRuleList(i);
		  fprintf(f, "Syn%*d", widthSyn, i); SynRule->recSynTyp(f);		  
		  fprintf(f, "(%*.*f): ", widthSynStr+widthDecSynStr+1, widthDecSynStr, SynRule->getSynStr());
		  for(m=0;m<getNumCat();m++)
	  	  	{ if(SynRule->getpCat(0)==getpCatList(m)) { fprintf(f, "Cat%*d", widthCat, m); getpCatList(m)->recCatTyp(f); break; }
	  	  	}
		  if(SynRule->getSynTyp()==0) fprintf(f, " << ");
		  else if(SynRule->getSynTyp()==1) fprintf(f, " >> ");
		  else if(SynRule->getSynTyp()==2) fprintf(f, " %c ", 'A');
		  else if(SynRule->getSynTyp()==3) fprintf(f, " %c ", 'V');
	  	  for(m=0;m<getNumCat();m++)
	  	  	{ if(SynRule->getpCat(1)==getpCatList(m)) { fprintf(f, "Cat%*d", widthCat, m); getpCatList(m)->recCatTyp(f); break; }
	  	  	}
	  	  SynRule=NULL;	// recollect SynRule;
	  	  fprintf(f, ";\n");
	  	}
	fprintf(f, "\n");
}
