// SystemClass.cpp: implement CSystemClass' membership functions

#include "stdafx.h"
// ---- Include Files;
#include"System.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CSystemClass' membership functions;
CSystem::CSystem()
{ // construction function;
	InitSystem();	
}

CSystem::CSystem(const CSystem &init)
{ // copy construction function;
	(*this)=init;
}

CSystem::~CSystem()
{ // destruction function;
	DestSystem();
}

CSystem & CSystem::operator = (const CSystem &right)
{ // copy system;
 	int i;
 	if(&right!=this)
 		{ // it is not self-copy;
		  DestSystem(); InitSystem();
		  setNumAgent(right.m_nNumAgent);
		  if(getNumAgent()!=0)
		  	{ for(i=0;i<getNumAgent();i++)
		  		{ setpAgent(i, right.m_ppAgent[i]);	// copy by address;
			 	  setpAgent1(i, right.m_ppAgent1[i]);
				  setpAgentN(i, right.m_ppAgentN[i]);
				}
 			}
		  setCheckFre(right.m_nCheckFre);
		  setDecFlag(right.m_nDecFlag); setSelfTalkFlag(right.m_nSelfTalkFlag);
		  setRecLocOrdNo_Str(right.m_nRecLocOrdNo_Str);

		  setComMode(right.m_nComMode);
		  setNumGroup(right.m_nNumGroup);
		  
		  setG1HolComp(right.m_nG1HolComp); 
		  setG1CompTyp(right.m_nG1CompTyp);
		  setG1InitCompCat(right.m_nG1InitCompCat); setG1order1(right.m_nG1order1); setG1order2(right.m_nG1order2);
		  setG1SV1(right.m_nG1SV1); setG1VS1(right.m_nG1VS1);
		  setG1SV(right.m_nG1SV); setG1VS(right.m_nG1VS);
		  setG1VO(right.m_nG1VO); setG1OV(right.m_nG1OV);
		  setG1SO(right.m_nG1SO); setG1OS(right.m_nG1OS);

		  setG1LexNhomrate(right.m_dG1LexNhomrate); setG1LexVhomrate(right.m_dG1LexVhomrate); setG1LexNVhomrate(right.m_dG1LexNVhomrate);

		  setG2HolComp(right.m_nG2HolComp); 
		  setG2CompTyp(right.m_nG2CompTyp);
		  setG2InitCompCat(right.m_nG2InitCompCat); setG2order1(right.m_nG2order1); setG2order2(right.m_nG2order2);
		  setG2SV1(right.m_nG2SV1); setG2VS1(right.m_nG2VS1);
		  setG2SV(right.m_nG2SV); setG2VS(right.m_nG2VS);
		  setG2VO(right.m_nG2VO); setG2OV(right.m_nG2OV);
		  setG2SO(right.m_nG2SO); setG2OS(right.m_nG2OS);

		  setG2LexNhomrate(right.m_dG2LexNhomrate); setG2LexVhomrate(right.m_dG2LexVhomrate); setG2LexNVhomrate(right.m_dG2LexNVhomrate);

		  setLexSim(right.m_dLexSim);
		  
		  setHorObliMix(right.m_nHorObliMix);
		  setMixHorVer(right.m_nMixHorVer);
		  setNumAgentRep(right.m_nNumAgentRep);

		  setCalTransMethod(right.m_nCalTransMethod);		  
		  setAdultChildRatio(right.m_dAdultChildRatio); setChildChildRatio(right.m_dChildChildRatio); setChildAdultRatio(right.m_dChildAdultRatio); setVerProb(right.m_dVerProb);
		  setPCRatio(right.m_dPCRatio); setACRatio(right.m_dACRatio); setCCRatio(right.m_dCCRatio); setCARatio(right.m_dCARatio);
		  setGrandCRatio(right.m_dGrandCRatio); setParentCRatio(right.m_dParentCRatio); setChildCRatio(right.m_dChildCRatio);
		  setGrandCType(right.m_nGrandCType); setParentCType(right.m_nParentCType);
		  
		  setVerTranRandCrt(right.m_nVerTranRandCrt); setVerTranWrongCue(right.m_nVerTranWrongCue);
		  setDifAdultChild(right.m_nDifAdultChild); setDifRatio(right.m_dDifRatio);
		  setSpUpd(right.m_nSpUpd); setSpUpdProb(right.m_dSpUpdProb);
		  
		  setNumGen(right.m_nNumGen); setNumLearn(right.m_nNumLearn);

		  setHumanChimp(right.m_nHumanChimp);
		  setA1(right.m_dA1); setK1(right.m_dK1);
		  setA2(right.m_dA2); setK2(right.m_dK2);
		  setScale(right.m_dScale);
		  setPopRat(right.m_dPopRat);
		  setIntraRat(right.m_dIntraRat); setInterRat(right.m_dInterRat);

		  setWorldX(right.m_nWorldX); setWorldY(right.m_nWorldY);
		  setBlockDist(right.m_nBlockDist);
		  setSucRat(right.m_dSucRat);
		  setSucCri(right.m_nSucCri);
		  setMoveStep(right.m_nMoveStep);
		  set1toMCom(right.m_n1toMCom);

		  setSelfGrow(right.m_nSelfGrow);

		  setGATimeScale(right.m_nGATimeScale);
		  setNumSp(right.m_nNumSp);
		  setCulSelType(right.m_nCulSelType); setGeneSelType(right.m_nGeneSelType);
		  setLearnAbiLow(right.m_dLearnAbiLow); setLearnAbiUp(right.m_dLearnAbiUp);
		  setMutRate(right.m_dMutRate); setMutStep(right.m_dMutStep);

		  setMemMutStep(right.m_nMemMutStep); setMemMutType(right.m_nMemMutType);
		  
		  setNumCom(right.m_nNumCom); 
		  setNumInfoChange(right.m_nNumInfoChange);

		  setCalAmbiguity(right.m_nCalAmbiguity);
		  setRecMem(right.m_nRecMem);

		  setShowComInfo(right.m_nShowComInfo);
		  
		  setIndURCalMethod(right.m_nIndURCalMethod);
		  setRecIndInfo(right.m_nRecIndInfo);
		  setRecURiniser(right.m_nRecURiniser);
		}
 	return *this;
}

void CSystem::selInitRuleLoc(int type, int Agindex, int *InitRuleLoc, int numInitRule)
{ // locate the initial shared rules location in SemSpace;
  // type=1, all agents shared same holistic/compositional rules; 2, select based on integrated meanings frequency;
	assert((type==1)||(type==2)); assert((0<=Agindex)&&(Agindex<getNumAgent())); assert(InitRuleLoc!=NULL);
	int i, j, cur;
	bool same;
	double rannum;
	
  	int rangeAgPred=(overallpara.p_nNumSemAgent>=overallpara.p_nNumSemPred1)?(overallpara.p_nNumSemAgent):(overallpara.p_nNumSemPred1);
	int rangeAgPredPat=(overallpara.p_nNumSemPred2>=overallpara.p_nNumSemPat)?(overallpara.p_nNumSemPred2):(overallpara.p_nNumSemPat);

	int numinitholist=0;
	if(overallpara.p_nNumSemPred1==0) numinitholist=rangeAgPredPat;
	if((overallpara.p_nNumSemPred2==0)&&(overallpara.p_nNumSemPat==0)) numinitholist=rangeAgPred;
	if((overallpara.p_nNumSemPred1!=0)&&(overallpara.p_nNumSemPred2!=0)) numinitholist=rangeAgPred+rangeAgPredPat;
		
	if(type==1)
  		{ // "Predicate<Agent>" meanings;
		  if(overallpara.p_nNumSemPred1==0)
		  	{ // "Predicate<Agent, Patient>" meanings;
			  if(overallpara.p_nAgSamePat==0)
		 	 	{ for(i=0;i<numinitholist;i++)
					InitRuleLoc[i]=((i%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred2)*(overallpara.p_nNumSemPat))+i*(overallpara.p_nNumSemPat)+i%(overallpara.p_nNumSemPat);
				}
		  	  else if(overallpara.p_nAgSamePat==1)
			  	{ for(i=0;i<numinitholist;i++)
					InitRuleLoc[i]=((i%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred2)*(overallpara.p_nNumSemPat-1))+i*(overallpara.p_nNumSemPat-1)+i%(overallpara.p_nNumSemPat-1);
				}
		  	}
		  if((overallpara.p_nNumSemPred2==0)&&(overallpara.p_nNumSemPat==0))
		  	{ // "Predicate<Agent>" meanings;
		  	  for(i=0;i<numinitholist;i++)
				InitRuleLoc[i]=(i%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred1)+(i%(overallpara.p_nNumSemPred1));
		  	}
		  if((overallpara.p_nNumSemPred1!=0)&&(overallpara.p_nNumSemPred2!=0))
		  	{ // "Predicate<Agent>" meanings;
		  	  for(i=0;i<rangeAgPred;i++)
				InitRuleLoc[i]=(i%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred1)+(i%(overallpara.p_nNumSemPred1));
		  	  // "Predicate<Agent, Patient>" meanings;
		  	  if(overallpara.p_nAgSamePat==0)
		 	 	{ for(i=rangeAgPred;i<numinitholist;i++)
					InitRuleLoc[i]=(overallpara.p_nNumSemAgent)*(overallpara.p_nNumSemPred1)+((i-rangeAgPred)%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred2)*(overallpara.p_nNumSemPat)+((i-rangeAgPred)%(overallpara.p_nNumSemPred1))*(overallpara.p_nNumSemPat)+(i-rangeAgPred)%(overallpara.p_nNumSemPat);
				}
		  	  else if(overallpara.p_nAgSamePat==1)
			  	{ for(i=rangeAgPred;i<numinitholist;i++)
					InitRuleLoc[i]=(overallpara.p_nNumSemAgent)*(overallpara.p_nNumSemPred1)+((i-rangeAgPred)%(overallpara.p_nNumSemAgent))*(overallpara.p_nNumSemPred2)*(overallpara.p_nNumSemPat-1)+((i-rangeAgPred)%(overallpara.p_nNumSemPred1))*(overallpara.p_nNumSemPat-1)+(i-rangeAgPred)%(overallpara.p_nNumSemPat-1);
				}
		  	}
		}
	else if(type==2)
		{ // select based on m_ppAgent[Agindex]'s semspace's integrated meanings' frequencies;
		  for(i=0;i<numInitRule;i++)
		  	{ cur=-1;
		  	  do{ rannum=Rand0_1;
		  	  	  if(FLOAT_SM_EQ(rannum, getpAgent(Agindex)->getpSemSpace()->getpSemItem(0)->getFre())) cur=0;
			  	  else if(FLOAT_EQ(rannum, 1.0)) cur=getpAgent(Agindex)->getpSemSpace()->getNumIntgMean()-1;
			  	  else
					{ for(j=1;j<getpAgent(Agindex)->getpSemSpace()->getNumIntgMean();j++)
						{ if((FLOAT_BG(rannum, getpAgent(Agindex)->getpSemSpace()->getpSemItem(j-1)->getFre()))&&(FLOAT_SM_EQ(rannum, getpAgent(Agindex)->getpSemSpace()->getpSemItem(j)->getFre()))) 
							{ cur=j; break; }
						}
					}
			  	  same=0;
			  	  for(j=0;j<i;j++)
			  	  	{ if(InitRuleLoc[j]==cur) { same=1; break; }
			  	  	}
		  	  }while(same==1);
		  	  InitRuleLoc[i]=cur;
		  	}
		}
}

void CSystem::getLocalOrder(int type, int SVOorder, int *SVtype, int *VOtype, int *SOtype)
{ // translate SVOorder into local order;
  // type=1, SV(1)/VS(2); type=2, SVO(1), SOV(2), OSV(3), VSO(4), VOS(5), OVS(6);
  	assert(((type==1)&&(0<=SVOorder)&&(SVOorder<=2))||((type==2)&&(0<=SVOorder)&&(SVOorder<=6))); 
	assert((SVtype!=NULL)&&(VOtype!=NULL)&&(SOtype!=NULL));
	if(type==1)
		{ // "Pred<Ag, Pat>" meanings' order;
		  switch(SVOorder)
		  	{ case 0: break;
		  	  case 1: *SVtype=0; *VOtype=-1; *SOtype=-1; break;	// SV;
		  	  case 2: *SVtype=1; *VOtype=-1; *SOtype=-1; break;	// VS;
		  	  default: break;
		  	}
		}
	else if(type==2)
		{ // "Pred<Ag, Pat>" meanings' orders;
		  switch(SVOorder)
			{ case 0: break;
			  case 1: *SVtype=0; *VOtype=0; *SOtype=0; break;	// SVO;
			  case 2: *SVtype=0; *VOtype=1; *SOtype=0; break;	// SOV;
			  case 3: *SVtype=0; *VOtype=1; *SOtype=1; break;	// OSV;
			  case 4: *SVtype=1; *VOtype=0; *SOtype=0; break;	// VSO;
			  case 5: *SVtype=1; *VOtype=0; *SOtype=1; break;	// VOS;
			  case 6: *SVtype=1; *VOtype=1; *SOtype=1; break;	// OVS;
			  default: break;
			}
		}
}

void CSystem::InitLexCatSyn(int type, int groupInd, int Agindex, CMeanUtter **meanutter, int numMeanUtter)
{ // initialize m_ppAgent[Agindex]'s initial lexical rules, categories, and syntactic rules;
  // type=1, initialize holistic rules and categories; 2, initialize lexical rules and categories and syntactic rules;
    assert((type==1)||(type==2)); assert((0<=Agindex)&&(Agindex<getNumAgent())); assert(meanutter!=NULL);
	int i, j;
	int sucInLex, HolComp, InitCompCat, Order1, Order2, SV1, VS1, SV, VS, VO, OV, SO, OS;
	CCat *newCat=NULL, *newCatAg=NULL, *newCatPred=NULL, *newCatPat=NULL, *newCatPred1=NULL, *newCatPred2=NULL;
	CLexRule *newLex=NULL;
	CSynRule *newSyn1=NULL, *newSyn2=NULL, *newSyn3=NULL, *newSyn4=NULL, *newSyn5=NULL, *newSyn6=NULL;
	int SVtype, VOtype, SOtype;	// specific local orders based on SVOorder1, SVOorder2;
	
	double assowei;
	int mergetype1, mergetype2, mergetype3, mergetype4, mergetype5, mergetype6;
	int numAg=overallpara.p_nNumSemAgent; 
	int numPred=overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2;
	int numPred1=overallpara.p_nNumSemPred1, numPred2=overallpara.p_nNumSemPred2;
	int numPat=overallpara.p_nNumSemPat;
	
	int numinitcomp=0;
	if(overallpara.p_nAgSamePat==0) numinitcomp=numAg+numPred+numPat;	// Patient is not same as Agent;
	else if(overallpara.p_nAgSamePat==1) numinitcomp=numAg+numPred;	// Patient is same as Agent;

	if(type==1)
		{ // initialize holistic rules and categories; 
		  // build up newCat;
		  newCat=new CCat; assert(newCat!=NULL);
		  newCat->setThemRole(0);	// holistic category;		  	
		  // build up lexical rule;
		  for(i=0;i<numMeanUtter;i++)
			{ // create new lexical rule;
		  	  newLex=new CLexRule; assert(newLex!=NULL);
		  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
		  	  newLex->setLexTyp(0);	// holistic rule;
		  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial holistic rule strength;
		  	  // link newLex with newCat;
		  	  newLex->InCat(newCat);
			  sucInLex=0; newCat->InLex(newLex, &sucInLex);	// this insertion will always be successful; 
		  	  // adjust newLex's assowei;
		  	  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
			  // store newLex into m_pLTMem->m_ppLexRuleList;
		  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
			}
		  // store newCat into m_pLTMem->m_ppCatList;
		  getpAgent(Agindex)->getpLTMem()->InCategory(newCat); newCat=NULL;
		}
	else if(type==2)
		{ // initialize lexical rules and categories and syntactic rules;
		  // build up newCatAg;
		  newCatAg=new CCat; assert(newCatAg!=NULL);
		  newCatAg->setThemRole(1);	// Ag category;
		  // build up newCatPat;
		  if((numPred2!=0)&&(numPat!=0))
		  	{ newCatPat=new CCat; assert(newCatPat!=NULL);
		  	  newCatPat->setThemRole(3);	// Pat category;
		  	}

		  if(overallpara.p_nAgSamePat==0)
		  	{ // Agent is not same as Patient;
			  // build up Ag lexical rule;
			  for(i=0;i<numAg;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  // lexical rule part;
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(1);	// Ag/Pat rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatAg;
			  	  newLex->InCat(newCatAg); 
				  sucInLex=0; newCatAg->InLex(newLex, &sucInLex);	// this insertion will always be successful;
			  	  // adjust newLex's assowei;
			  	  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
				}
			  // build up Pat lexical rule;
			  for(i=numAg+numPred;i<numinitcomp;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  // lexical rule part;
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(1);	// Ag/Pat rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatPat;
			  	  newLex->InCat(newCatPat); 
				  sucInLex=0; newCatPat->InLex(newLex, &sucInLex);	// this insertion will always be successful;
			  	  // adjust newLex's assowei;
			  	  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
			  	  // adjust newLex's catlist for newCatPat;
			  	  for(j=0;j<newLex->getCatNum();j++)
			  	  	{ if(newLex->getpCatList(j)->getpCat()==newCatPat)
			  	  		{ assowei=newLex->getpCatList(j)->getAssoWei();
			  	  		  newLex->setpCatList(j, newCatPat, assowei, 4);
			  	  		}
			  	  	}
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
			  	}
		  	}
		  else if(overallpara.p_nAgSamePat==1)
		  	{ // Agent is same as Patient;
		  	  // build up Ag/Pat lexical rule;
			  for(i=0;i<numAg;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(1);	// Ag/Pat rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatAg and newCatPat;
			  	  newLex->InCat(newCatAg); 
				  sucInLex=0; newCatAg->InLex(newLex, &sucInLex);	// this insertion will always be successful;
			  	  newLex->InCat(newCatPat); 
				  sucInLex=0; newCatPat->InLex(newLex, &sucInLex);	// this insertion will always be successful;
			  	  // adjust newLex's assowei;
			  	  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
			  	  newLex->getpCatList(1)->setAssoWei(newLex->getInitBasicAssoWei());
				  // adjust newLex's catlist for newCatPat;
			  	  for(j=0;j<newLex->getCatNum();j++)
			  	  	{ if(newLex->getpCatList(j)->getpCat()==newCatPat)
			  	  		{ assowei=newLex->getpCatList(j)->getAssoWei();
			  	  		  newLex->setpCatList(j, newCatPat, assowei, 4);
			  	  		}
			  	  	}
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
				}
		  	}

		 HolComp=InitCompCat=-1; Order1=Order2=-1; SV1=VS1=SV=VS=VO=OV=SO=OS=-1;
		 if(groupInd==1) 
		 	{ HolComp=getG1HolComp(); 
		 	  InitCompCat=getG1InitCompCat(); Order1=getG1order1(); Order2=getG1order2(); 
			  SV1=getG1SV1(); VS1=getG1VS1(); SV=getG1SV(); VS=getG1VS(); VO=getG1VO(); OV=getG1OV(); SO=getG1SO(); OS=getG1OS();
		 	}
		 else if(groupInd==2) 
		 	{ HolComp=getG2HolComp(); 
		 	  InitCompCat=getG2InitCompCat(); Order1=getG2order1(); Order2=getG2order2(); 
			  SV1=getG2SV1(); VS1=getG2VS1(); SV=getG2SV(); VS=getG2VS(); VO=getG2VO(); OV=getG2OV(); SO=getG2SO(); OS=getG2OS();
		 	}

		 if(InitCompCat==0)
		 	{ // predicate category is one; 
		 	  // build up newCatPred;
			  if(numPred!=0) 
			  	{ newCatPred=new CCat; assert(newCatPred!=NULL);
		 	  	  newCatPred->setThemRole(2);	// Pred category;
			  	}
		 	  // build up Pred lexical rule;
			  for(i=numAg;i<numAg+numPred;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  // lexical rule part;
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(2);	// Pred rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatPred;
			  	  newLex->InCat(newCatPred); 
				  sucInLex=0; newCatPred->InLex(newLex, &sucInLex);	// this insertion will always be successful;
				  // adjust newLex's assowei;
				  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
				  if(i>=numAg+overallpara.p_nNumSemPred1)
				  	{ // adjust newLex's catlist for newCatPred;
			  	  	  for(j=0;j<newLex->getCatNum();j++)
			  	  		{ if(newLex->getpCatList(j)->getpCat()==newCatPred)
			  	  			{ assowei=newLex->getpCatList(j)->getAssoWei();
			  	  			  newLex->setpCatList(j, newCatPred, assowei, 3);
			  	  			}
			  	  		}
				  	}
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
				}
		  
			  if(HolComp==1)
		 		{ // use m_nG1/2Order1, m_nG1/2Order2 to build up syntactic rules; 
		 	  	  // build up newSyn1, newSyn2, newSyn3;
				  SVtype=-1; VOtype=-1; SOtype=-1; getLocalOrder(2, Order2, &SVtype, &VOtype, &SOtype);
				  if(numPred!=0) 
				  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred, SVtype); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
				  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
					  if((numPred2!=0)&&(numPat!=0))
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn2, newCatPred, newCatPat, VOtype); newSyn2->setSynStr(newSyn2->getInitBasicSynRuleStr());	// adjust newSyn2's strength;
				  	  	  mergetype2=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn2, &mergetype2); newSyn2=NULL;	// store newSyn2 into m_pLTMem->m_ppSynRuleList;	  
				  		}
				  	}
				  if((numPred2!=0)&&(numPat!=0))
				  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn3, newCatAg, newCatPat, SOtype); newSyn3->setSynStr(newSyn3->getInitBasicSynRuleStr());	// adjust newSyn3's strength;
				  	  mergetype3=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn3, &mergetype3); newSyn3=NULL;	// store newSyn3 into m_pLTMem->m_ppSynRuleList;
				  	}				  
				}
			  else if(HolComp==2)
			  	{ // use m_nG1/2SV/VS/VO/OV/SO/OS to build up syntactic rules; 
			  	  // build up local syntactic rules;
				  if(SV==1)
			   		{ // S<<V local order;
					  if(numPred!=0)
				  		{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred, 0); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
					  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
						}
				  	}
				  if(VS==1)
				  	{ // S>>V local order;
					  if(numPred!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn2, newCatAg, newCatPred, 1); newSyn2->setSynStr(newSyn2->getInitBasicSynRuleStr());	// adjust newSyn2's strength;
					  	  mergetype2=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn2, &mergetype2); newSyn2=NULL;	// store newSyn2 into m_pLTMem->m_ppSynRuleList;
				  		}
				  	}
				  if(VO==1)
				  	{ // V<<O local order;
					  if((numPred!=0)&&(numPat!=0))
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn3, newCatPred, newCatPat, 0); newSyn3->setSynStr(newSyn3->getInitBasicSynRuleStr());	// adjust newSyn3's strength;
					  	  mergetype3=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn3, &mergetype3); newSyn3=NULL;	// store newSyn3 into m_pLTMem->m_ppSynRuleList;	  
						}
				  	}
				  if(OV==1)
				  	{ // V>>O local order;
					  if((numPred!=0)&&(numPat!=0))
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn4, newCatPred, newCatPat, 1); newSyn4->setSynStr(newSyn4->getInitBasicSynRuleStr());	// adjust newSyn4's strength;
					  	  mergetype4=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn4, &mergetype4); newSyn4=NULL;	// store newSyn4 into m_pLTMem->m_ppSynRuleList;	  
				  		}
				  	}
				  if(SO==1)
				  	{ // S<<O local order;
					  if(numPat!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn5, newCatAg, newCatPat, 0); newSyn5->setSynStr(newSyn5->getInitBasicSynRuleStr());	// adjust newSyn5's strength;
					  	  mergetype5=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn5, &mergetype5); newSyn5=NULL;	// store newSyn5 into m_pLTMem->m_ppSynRuleList;
				  		}
				  	}
				  if(OS==1)
				  	{ // S>>O local order;
					  if(numPat!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn6, newCatAg, newCatPat, 1); newSyn6->setSynStr(newSyn6->getInitBasicSynRuleStr());	// adjust newSyn6's strength;
					  	  mergetype6=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn6, &mergetype6); newSyn6=NULL;	// store newSyn6 into m_pLTMem->m_ppSynRuleList;
				   		}
				  	}
			  	}
  			  // store newCatAg, newCatPred and newCatPat into m_pLTMem->m_ppCatList;
			  getpAgent(Agindex)->getpLTMem()->InCategory(newCatAg); newCatAg=NULL;
			  if(numPred!=0) { getpAgent(Agindex)->getpLTMem()->InCategory(newCatPred); newCatPred=NULL; }
			  if((numPred2!=0)&&(numPat!=0)) { getpAgent(Agindex)->getpLTMem()->InCategory(newCatPat); newCatPat=NULL; }
			}
		  else if(InitCompCat==1)
			{ // 2 predicate categories with same or different local orders;
			  // build up newCatPred1 and newCatPred2;
			  if(numPred1!=0) 
			  	{ newCatPred1=new CCat; assert(newCatPred1!=NULL);	
		  	  	  newCatPred1->setThemRole(2);	// Pred category 1;
			  	}
			  if(numPred2!=0)
			  	{ newCatPred2=new CCat; assert(newCatPred2!=NULL);
		  	  	  newCatPred2->setThemRole(2);	// Pred category 2;
			  	}
			  
			  // build up CatPred1 lexical rule;
			  for(i=numAg;i<numAg+numPred1;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  // lexical rule part;
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(2);	// Pred rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatPred1;
			  	  newLex->InCat(newCatPred1); 
				  sucInLex=0; newCatPred1->InLex(newLex, &sucInLex);	// this insertion will always be successful;
				  // adjust newLex's assowei;
				  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
				}

		  	  // build up CatPred2 lexical rule;
		  	  for(i=numAg+numPred1;i<numAg+numPred1+numPred2;i++)
			  	{ // create new lexical rule;
			  	  newLex=new CLexRule; assert(newLex!=NULL);
			  	  // lexical rule part;
			  	  newLex->setpMeanUtter(meanutter[i]);	// copy meanutter;
			  	  newLex->setLexTyp(2);	// Pred rule;
			  	  newLex->setLexStr(newLex->getInitBasicRuleStr());	// initial lexical rule strength;
			  	  // link newLex with newCatPred2;
			  	  newLex->InCat(newCatPred2); 
				  sucInLex=0; newCatPred2->InLex(newLex, &sucInLex);	// this insertion will always be successful;
				  // adjust newLex's assowei;
				  newLex->getpCatList(0)->setAssoWei(newLex->getInitBasicAssoWei());
				  // adjust newLex's catlist for newCatPred;
			  	  for(j=0;j<newLex->getCatNum();j++)
			  	  	{ if(newLex->getpCatList(j)->getpCat()==newCatPred2)
			  	  		{ assowei=newLex->getpCatList(j)->getAssoWei();
			  	  		  newLex->setpCatList(j, newCatPred2, assowei, 3);
			  	  		}
			  	  	}					  
				  // store newLex into m_pLTMem->m_ppLexRuleList;
			  	  getpAgent(Agindex)->getpLTMem()->InLexRule(newLex); newLex=NULL;
				}

			if(HolComp==1)
		 		{ // use m_nG1/2Order1, m_nG1/2Order2 to build up syntactic rules; 
		 		  // build up newSyn1 for "Pred<Ag>" meanings;
				  SVtype=-1; VOtype=-1; SOtype=-1; getLocalOrder(1, Order1, &SVtype, &VOtype, &SOtype);
				  if(numPred1!=0)
				  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred1, SVtype); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
				  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
				  	}
				  
				  // build up newSyn1, newSyn2, newSyn3 for "Pred<Ag, Pat>" meanings;
				  SVtype=-1; VOtype=-1; SOtype=-1; getLocalOrder(2, Order2, &SVtype, &VOtype, &SOtype);
				  if(numPred2!=0)
				  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred2, SVtype); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
				  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
					  if(numPat!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn2, newCatPred2, newCatPat, VOtype); newSyn2->setSynStr(newSyn2->getInitBasicSynRuleStr());	// adjust newSyn2's strength;
				  	  	  mergetype2=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn2, &mergetype2); newSyn2=NULL;	// store newSyn2 into m_pLTMem->m_ppSynRuleList;	  
				  		}
				  	}
				  if((numPred2!=0)&&(numPat!=0))
				  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn3, newCatAg, newCatPat, SOtype); newSyn3->setSynStr(newSyn3->getInitBasicSynRuleStr());	// adjust newSyn3's strength;
				  	  mergetype3=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn3, &mergetype3); newSyn3=NULL;	// store newSyn3 into m_pLTMem->m_ppSynRuleList;
				  	}				  
				}
			  else if(HolComp==2)
			  	{ // use m_nG1/2SV1/VS1/SV/VS/VO/OV/SO/OS to build up syntactic rules;
				  // build up local syntactic rules for "Pred<Ag>" meanings;
				  if(SV1==1)
				  	{ // S<<V local order;
				  	  if(numPred1!=0)
				  		{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred1, 0); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
					  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
						}
				  	}
				  if(VS1==1)
				  	{ // S>>V local order;
					  if(numPred1!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn2, newCatAg, newCatPred1, 1); newSyn2->setSynStr(newSyn2->getInitBasicSynRuleStr());	// adjust newSyn2's strength;
					  	  mergetype2=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn2, &mergetype2); newSyn2=NULL;	// store newSyn2 into m_pLTMem->m_ppSynRuleList;
				  		}
				  	}

				  // build up local syntactic rules for "Pred<Ag, Pat>" meanings;
				  if(SV==1)
		    		{ // S<<V local order;
					  if(numPred2!=0)
				  		{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn1, newCatAg, newCatPred2, 0); newSyn1->setSynStr(newSyn1->getInitBasicSynRuleStr());	// adjust newSyn1's strength;
					  	  mergetype1=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn1, &mergetype1); newSyn1=NULL;	// store newSyn1 into m_pLTMem->m_ppSynRuleList;
						}
				  	}
				  if(VS==1)
				  	{ // S>>V local order;
					  if(numPred2!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn2, newCatAg, newCatPred2, 1); newSyn2->setSynStr(newSyn2->getInitBasicSynRuleStr());	// adjust newSyn2's strength;
					  	  mergetype2=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn2, &mergetype2); newSyn2=NULL;	// store newSyn2 into m_pLTMem->m_ppSynRuleList;
				  		}
				  	}
				  if(VO==1)
				  	{ // V<<O local order;
					  if((numPred2!=0)&&(numPat!=0))
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn3, newCatPred2, newCatPat, 0); newSyn3->setSynStr(newSyn3->getInitBasicSynRuleStr());	// adjust newSyn3's strength;
					  	  mergetype3=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn3, &mergetype3); newSyn3=NULL;	// store newSyn3 into m_pLTMem->m_ppSynRuleList;	  
						}
				  	}
				  if(OV==1)
				  	{ // V>>O local order;
					  if((numPred2!=0)&&(numPat!=0))
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn4, newCatPred2, newCatPat, 1); newSyn4->setSynStr(newSyn4->getInitBasicSynRuleStr());	// adjust newSyn4's strength;
					  	  mergetype4=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn4, &mergetype4); newSyn4=NULL;	// store newSyn4 into m_pLTMem->m_ppSynRuleList;	  
				  		}
				  	}
				  if(SO==1)
				  	{ // S<<O local order;
					  if(numPat!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn5, newCatAg, newCatPat, 0); newSyn5->setSynStr(newSyn5->getInitBasicSynRuleStr());	// adjust newSyn5's strength;
					  	  mergetype5=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn5, &mergetype5); newSyn5=NULL;	// store newSyn5 into m_pLTMem->m_ppSynRuleList;
				  		}
				  	}
				  if(OS==1)
				  	{ // S>>O local order;
					  if(numPat!=0)
					  	{ getpAgent(Agindex)->getpIMMem()->CrtSynRule(newSyn6, newCatAg, newCatPat, 1); newSyn6->setSynStr(newSyn6->getInitBasicSynRuleStr());	// adjust newSyn6's strength;
					  	  mergetype6=0; getpAgent(Agindex)->getpLTMem()->InSynRule(newSyn6, &mergetype6); newSyn6=NULL;	// store newSyn6 into m_pLTMem->m_ppSynRuleList;
				   		}
				  	}
			  	}
			  // store newCatAg, newCatPred1, newCatPred2 and newCatPat into m_pLTMem->m_ppCatList;
			  getpAgent(Agindex)->getpLTMem()->InCategory(newCatAg); newCatAg=NULL;
			  if(numPred1!=0) { getpAgent(Agindex)->getpLTMem()->InCategory(newCatPred1); newCatPred1=NULL; }
			  if(numPred2!=0) { getpAgent(Agindex)->getpLTMem()->InCategory(newCatPred2); newCatPred2=NULL; }
			  if(numPat!=0) { getpAgent(Agindex)->getpLTMem()->InCategory(newCatPat); newCatPat=NULL; }
			}
		}	
}

void CSystem::setGroupHolistRule(int groupInd, int lowBound, int upBound)
{ // m_ppAgent[lowBound] to m_ppAgent[upBound] share same holistic rules;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	assert((1<=groupInd)&&(groupInd<=getNumGroup()));
	int i, j;
	int *holistLoc=NULL;
	CMeanUtter **meanutter=NULL;
	int rangeAgPred=(overallpara.p_nNumSemAgent>=overallpara.p_nNumSemPred1)?(overallpara.p_nNumSemAgent):(overallpara.p_nNumSemPred1);
	int rangeAgPredPat=(overallpara.p_nNumSemPred2>=overallpara.p_nNumSemPat)?(overallpara.p_nNumSemPred2):(overallpara.p_nNumSemPat);

	int numinitholist=0;
	if(overallpara.p_nNumSemPred1==0) numinitholist=rangeAgPredPat;
	if((overallpara.p_nNumSemPred2==0)&&(overallpara.p_nNumSemPat==0)) numinitholist=rangeAgPred;
	if((overallpara.p_nNumSemPred1!=0)&&(overallpara.p_nNumSemPred2!=0)) numinitholist=rangeAgPred+rangeAgPredPat;

	// according to different semspace, set up initial shared rules;
	switch(overallpara.p_nSemDist)
		{ case 0: case 1: case 2:	// 0, uniform dist; 1, identical Gaussian; 2, different Gaussian; 
				// initialize holistLoc;
				holistLoc=new int [numinitholist]; assert(holistLoc!=NULL);
				selInitRuleLoc(1, 0, holistLoc, numinitholist);
				// build up meanutter; 
		  		meanutter=new CMeanUtter * [numinitholist]; assert(meanutter!=NULL);
				for(i=0;i<numinitholist;i++)
					{ meanutter[i]=new CMeanUtter; assert(meanutter[i]!=NULL);	
			  		  meanutter[i]->setpMean(getpAgent(0)->getpSemSpace()->getpSemItem(holistLoc[i])->getpIntgMean());
					  if(meanutter[i]->getpMean()->getElement(2*(getpAgent(0)->getpSemSpace()->getLengthSem())+getpAgent(0)->getpSemSpace()->getLengthSemItem())==-1) meanutter[i]->CrtUtter(1);	// "Predicate<Agent>" meaning;
					  else meanutter[i]->CrtUtter(2);	// "Predicate<Agent, Patient>" meaning;
					}
			  		
				// build up each agent's common holistic rules and category;
				for(i=lowBound;i<upBound;i++)
					InitLexCatSyn(1, groupInd, i, meanutter, numinitholist);
				
				// delete meanutter, holistLoc and semspace;
				for(i=0;i<numinitholist;i++)
					{ delete meanutter[i]; meanutter[i]=NULL; }
				delete [] meanutter; meanutter=NULL;	
				delete [] holistLoc; holistLoc=NULL;
				break;
		  case 3: case 4: case 5:	// 3, identical Power law; 4, reverse identical Power law; 5, identical random;
				// initialize holistLoc;
				holistLoc=new int [numinitholist]; assert(holistLoc!=NULL);
				selInitRuleLoc(2, 0, holistLoc, numinitholist);
				// build up meanutter; 
		  		meanutter=new CMeanUtter * [numinitholist]; assert(meanutter!=NULL);
				for(i=0;i<numinitholist;i++)
					{ meanutter[i]=new CMeanUtter; assert(meanutter[i]!=NULL);	
			  		  meanutter[i]->setpMean(getpAgent(0)->getpSemSpace()->getpSemItem(holistLoc[i])->getpIntgMean());
					  if(meanutter[i]->getpMean()->getElement(2*(getpAgent(0)->getpSemSpace()->getLengthSem())+getpAgent(0)->getpSemSpace()->getLengthSemItem())==-1) meanutter[i]->CrtUtter(1);	// "Predicate<Agent>" meaning;
					  else meanutter[i]->CrtUtter(2);	// "Predicate<Agent, Patient>" meaning;
					}
	  		
				// build up each agent's common holistic rules and category;
				for(i=lowBound;i<upBound;i++)
					InitLexCatSyn(1, groupInd, i, meanutter, numinitholist);
				
				// delete meanutter, holistLoc and semspace; 
				for(i=0;i<numinitholist;i++)
					{ delete meanutter[i]; meanutter[i]=NULL; }		
				delete [] meanutter; meanutter=NULL;	
				delete [] holistLoc; holistLoc=NULL;
		  		break;
		  case 6:	// 4, different Power law; 6, different random;
		  		for(i=lowBound;i<upBound;i++)
		  			{ // initialize holistLoc;
					  holistLoc=new int [numinitholist]; assert(holistLoc!=NULL);
					  selInitRuleLoc(2, i, holistLoc, numinitholist);
				  	  // build up meanutter; 
	  			  	  meanutter=new CMeanUtter * [numinitholist]; assert(meanutter!=NULL);
					  for(j=0;j<numinitholist;j++)
						{ meanutter[j]=new CMeanUtter; assert(meanutter[j]!=NULL);	
			  			  meanutter[j]->setpMean(getpAgent(0)->getpSemSpace()->getpSemItem(holistLoc[j])->getpIntgMean());
						  if(meanutter[j]->getpMean()->getElement(2*(getpAgent(i)->getpSemSpace()->getLengthSem())+getpAgent(i)->getpSemSpace()->getLengthSemItem())==-1) meanutter[j]->CrtUtter(1);	// "Predicate<Agent>" meaning;
						  else meanutter[j]->CrtUtter(2);	// "Predicate<Agent, Patient>" meaning;
						}

					  InitLexCatSyn(1, groupInd, i, meanutter, numinitholist);

					  // delete meanutter, holistLoc and semspace; 
					  for(j=0;j<numinitholist;j++)
						{ delete meanutter[j]; meanutter[j]=NULL; }		
					  delete [] meanutter; meanutter=NULL;	
					  delete [] holistLoc; holistLoc=NULL;
		  			}
				break;
		  default: break;
		}
}

void CSystem::setGroupCompoRule(int groupInd, int lowBound, int upBound)
{ // m_ppAgent[lowBound] to m_ppAgent[upBound] share same holistic rules;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	assert((1<=groupInd)&&(groupInd<=getNumGroup()));
	int i, j;
	bool uttersame;	// created compositional utterance syllables are same; 
	CMeanUtter **meanutter=NULL;

	int posAg=getpAgent(lowBound)->getpSemSpace()->getLengthSemRole();
	int posPred=getpAgent(lowBound)->getpSemSpace()->getLengthSem()+getpAgent(lowBound)->getpSemSpace()->getLengthSemRole();
	int lenSemItem=getpAgent(lowBound)->getpSemSpace()->getLengthSemItem();
	int numAg=overallpara.p_nNumSemAgent; 
	int numPred=overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2;
	int numPat=overallpara.p_nNumSemPat;
	
	int numinitcomp=0;
	if(overallpara.p_nAgSamePat==0) numinitcomp=numAg+numPred+numPat;	// Patient is not same as Agent;
	else if(overallpara.p_nAgSamePat==1) numinitcomp=numAg+numPred;	// Patient is same as Agent;

	int CompTyp=-1;
	if(groupInd==1) CompTyp=getG1CompTyp();
	else if(groupInd==2) CompTyp=getG2CompTyp();
	
	// build up meanutter; 
	meanutter=new CMeanUtter * [numinitcomp]; assert(meanutter!=NULL);
	if(overallpara.p_nAgSamePat==0)
		{ // Patient is not same as Agent;
		  for(i=0;i<numinitcomp;i++)
			{ meanutter[i]=new CMeanUtter; assert(meanutter[i]!=NULL);
			  if(i<numAg) meanutter[i]->setPartMean(getpAgent(lowBound)->getpSemSpace()->getpSemAgent(i), posAg, 0, lenSemItem);
			  else if(i<numAg+numPred) meanutter[i]->setPartMean(getpAgent(lowBound)->getpSemSpace()->getpSemPred(i-numAg), posPred, 0, lenSemItem);
			  else meanutter[i]->setPartMean(getpAgent(lowBound)->getpSemSpace()->getpSemPat(i-numAg-numPred), posAg, 0, lenSemItem);
			  switch(CompTyp)
			  	{ case 0: // random create compositional rules' utterance, allow homonyms;
			  			meanutter[i]->CrtUtter(3);
			  	  		break;
				  case 1: // do not allow homonyms;
				  		do{ uttersame=0;
							meanutter[i]->CrtUtter(3);
			  	 			for(j=0;j<i;j++)
			  	 				{ if(*(meanutter[i]->getpUtter())==*(meanutter[j]->getpUtter())) uttersame=1;
			  	 				}
			  			}while(uttersame==1);
				  		break;
				  case 2: // use identical meaning as utterance syllable;
				  		meanutter[i]->getpUtter()->setElement(0, i);
				  		break;
				  default: break;
			  	} 
			}
		}
	else if(overallpara.p_nAgSamePat==1)
		{ // Patient is same as Agent;
		  for(i=0;i<numinitcomp;i++)
			{ meanutter[i]=new CMeanUtter; assert(meanutter[i]!=NULL);
			  if(i<numAg) meanutter[i]->setPartMean(getpAgent(lowBound)->getpSemSpace()->getpSemAgent(i), posAg, 0, lenSemItem);
			  else meanutter[i]->setPartMean(getpAgent(lowBound)->getpSemSpace()->getpSemPred(i-numAg), posPred, 0, lenSemItem);
			  switch(CompTyp)
			  	{ case 0: // random create compositional rules' utterance, allow homonyms;
			  			meanutter[i]->CrtUtter(3);
			  	  		break;
				  case 1: // do not allow homonyms;
				  		do{ uttersame=0;
							meanutter[i]->CrtUtter(3);
			  	 			for(j=0;j<i;j++)
			  	 				{ if(*(meanutter[i]->getpUtter())==*(meanutter[j]->getpUtter())) uttersame=1;
			  	 				}
			  			}while(uttersame==1);
				  		break;
				  case 2: // use identical meaning as utterance syllable;
				  		meanutter[i]->getpUtter()->setElement(0, i);
				  		break;
				  default: break;
			  	} 
			}
		}
	
	// build up each agent's common comp rules and category;
	for(i=lowBound;i<upBound;i++)
		InitLexCatSyn(2, groupInd, i, meanutter, numinitcomp);
	
	// delete meanutter and basicmean; 
	for(i=0;i<numinitcomp;i++)
		{ delete meanutter[i]; meanutter[i]=NULL; }
	delete [] meanutter; meanutter=NULL;
}

void CSystem::adjHom(int groupInd, int lowBound, int upBound)
{ // adjust homonym among lexical rules;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	assert((1<=groupInd)&&(groupInd<=getNumGroup()));
	int i, j, numHomN, numHomV, numHomNV, LexRuleInd, *adjHomInd=NULL;
	
	int numAg=overallpara.p_nNumSemAgent; 
	int numPred=overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2;
	double LexNhomrate=0.0, LexVhomrate=0.0, LexNVhomrate=0.0;
	
	if(groupInd==1) { LexNhomrate=getG1LexNhomrate(); LexVhomrate=getG1LexVhomrate(); LexNVhomrate=getG1LexNVhomrate(); }
	else if(groupInd==2) { LexNhomrate=getG2LexNhomrate(); LexVhomrate=getG2LexVhomrate(); LexNVhomrate=getG2LexNVhomrate(); }
	
	// adjust LexN homonym;
	numHomN=(int)(LexNhomrate*numAg);
	if(numHomN!=0)
		{ // initialize adjHomInd;
		 adjHomInd=new int [2*numHomN]; assert(adjHomInd!=NULL);
		 for(i=0;i<2*numHomN;i++)
		  	adjHomInd[i]=-1;
		 
		 // select LexN to be common;
		 i=0;
		 do{ do{ LexRuleInd=(int)(Rand0_1*numAg);
			 }while(LexRuleInd==numAg);
			 for(j=0;j<i;j++)
				{ if(adjHomInd[j]==LexRuleInd) break;
				}
			 if(j==i) { adjHomInd[i]=LexRuleInd; i++; }
		 }while(i!=2*numHomN);
		 // adjust LexN to be common;
		 for(i=lowBound;i<upBound;i++)
			for(j=0;j<numHomN;j++)
		  		getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j])->getpMeanUtter()->setpUtter(getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j+numHomN])->getpMeanUtter()->getpUtter());
		 
		 delete [] adjHomInd; adjHomInd=NULL;	// delete adjHomInd;
		}

	// adjust LexV homonym;
	numHomV=(int)(LexVhomrate*numPred);
	if(numHomV!=0)
		{ // initialize adjHomInd;
		 adjHomInd=new int [2*numHomV]; assert(adjHomInd!=NULL);
		 for(i=0;i<2*numHomV;i++)
			adjHomInd[i]=-1;
		 
		 // select LexV to be common;
		 i=0;
		 do{ do{ LexRuleInd=numAg+(int)(Rand0_1*numPred);
			 }while(LexRuleInd==numAg+numPred);
			 for(j=0;j<i;j++)
				{ if(adjHomInd[j]==LexRuleInd) break;
				}
			 if(j==i) { adjHomInd[i]=LexRuleInd; i++; }
		 }while(i!=2*numHomV);
		 // adjust LexV to be common;
		 for(i=lowBound;i<upBound;i++)
			for(j=0;j<numHomV;j++)
				getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j])->getpMeanUtter()->setpUtter(getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j+numHomV])->getpMeanUtter()->getpUtter());
		 
		 delete [] adjHomInd; adjHomInd=NULL;	// delete adjHomInd;
		}

	// adjust LexNV homonym;
	numHomNV=(int)(LexNVhomrate*numAg);
	if(numHomNV!=0)
		{ // initialize adjHomInd;
		 adjHomInd=new int [2*numHomNV]; assert(adjHomInd!=NULL);
		 for(i=0;i<2*numHomNV;i++)
			adjHomInd[i]=-1;
		 
		 // select LexN;
		 i=0;
		 do{ do{ LexRuleInd=(int)(Rand0_1*numAg);
			 }while(LexRuleInd==numAg);
			 for(j=0;j<i;j++)
				{ if(adjHomInd[j]==LexRuleInd) break;
				}
			 if(j==i) { adjHomInd[i]=LexRuleInd; i++; }
		 }while(i!=numHomNV);
		 // select LexV;
		 i=numHomNV;		 
		 do{ do{ LexRuleInd=numAg+(int)(Rand0_1*numPred);
			 }while(LexRuleInd==numAg+numPred);
			 for(j=numHomNV;j<i;j++)
				{ if(adjHomInd[j]==LexRuleInd) break;
				}
			 if(j==i) { adjHomInd[i]=LexRuleInd; i++; }
		 }while(i!=2*numHomNV);
		 // adjust LexN and LexV to be common;
		 for(i=lowBound;i<upBound;i++)
		 	for(j=0;j<numHomNV;j++)
		 		getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j])->getpMeanUtter()->setpUtter(getpAgent(i)->getpLTMem()->getpLexRuleList(adjHomInd[j+numHomNV])->getpMeanUtter()->getpUtter());
		 
		 delete [] adjHomInd; adjHomInd=NULL;	// delete adjHomInd; 
		}		
}

void CSystem::adjLexSim(int G1low, int G1up, int G2low, int G2up)
{ // adjust lexical rules similarity between two groups' languages;
	assert((0<=G1low)&&(G1low<=getNumAgent())); assert((0<=G1up)&&(G1up<=getNumAgent())); assert(G1low<=G1up);
	assert((0<=G2low)&&(G2low<=getNumAgent())); assert((0<=G2up)&&(G2up<=getNumAgent())); assert(G2low<=G2up);
	int i, j, k, LexRuleInd, numAdj, *adjIndex=NULL;
	
	numAdj=(int)(getLexSim()*getpAgent(G1low)->getpLTMem()->getNumLexRule());
	if(numAdj!=0) 
		{ // initialize adjIndex;
		  adjIndex=new int [numAdj]; assert(adjIndex!=NULL);
		  for(i=0;i<numAdj;i++)
			adjIndex[i]=-1;
		  // select rules to be common;
		  i=0;
		  do{ do{ LexRuleInd=(int)(Rand0_1*getpAgent(G1low)->getpLTMem()->getNumLexRule());
			 }while(LexRuleInd==getpAgent(G1low)->getpLTMem()->getNumLexRule());
			 for(j=0;j<i;j++)
				{ if(adjIndex[j]==LexRuleInd) break;
				}
			 if(j==i)
				{ adjIndex[i]=LexRuleInd; i++;
				  // change all group2's agents' LexRuleList[k] to be same as group1's agents' LexRuleList[LexRuleInd];
				  for(j=G2low;j<G2up;j++)
				  	{ for(k=0;k<getpAgent(j)->getpLTMem()->getNumLexRule();k++)
				  		{ if(*(getpAgent(j)->getpLTMem()->getpLexRuleList(k)->getpMeanUtter()->getpMean())==*(getpAgent(G1low)->getpLTMem()->getpLexRuleList(LexRuleInd)->getpMeanUtter()->getpMean()))
				  	  		getpAgent(j)->getpLTMem()->getpLexRuleList(k)->setpMeanUtter(getpAgent(G1low)->getpLTMem()->getpLexRuleList(LexRuleInd)->getpMeanUtter());
						}
				  	}
			 	}
		  }while(i!=numAdj);
		  delete [] adjIndex; adjIndex=NULL;	// delete adjIndex;
		}
}

void CSystem::InitRuleAll()
{ // initializing all agents with holistic/compo rules;
	int G1low=-1, G1up=-1, G2low=-1, G2up=-1;
	if(getNumGroup()==1) { G1low=0; G1up=getNumAgent(); }
	else if(getNumGroup()==2) { G1low=0; G1up=(int)(getNumAgent()/_Twice+0.5); G2low=G1up; G2up=getNumAgent(); }
	
	if(getNumGroup()==1)
		{ // 1 group;
		  if(getG1HolComp()==0) setGroupHolistRule(1, G1low, G1up);
		  else if((getG1HolComp()==1)||(getG1HolComp()==2)) setGroupCompoRule(1, G1low, G1up);
		  adjHom(1, G1low, G1up);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  if(getG1HolComp()==0) setGroupHolistRule(1, G1low, G1up);
		  else if((getG1HolComp()==1)||(getG1HolComp()==2)) setGroupCompoRule(1, G1low, G1up);
		  if(getG2HolComp()==0) setGroupHolistRule(2, G2low, G2up);
		  else if((getG2HolComp()==1)||(getG2HolComp()==2)) setGroupCompoRule(2, G2low, G2up);
		  adjHom(1, G1low, G1up); adjHom(2, G2low, G2up);
		  if(((getG1HolComp()==0)&&(getG2HolComp()==0))||(((getG1HolComp()==1)||(getG1HolComp()==2))&&((getG2HolComp()==1)|(getG2HolComp()==2)))) adjLexSim(G1low, G1up, G2low, G2up);	// adjust lexical rules similarity between two groups' languages;
		}
}

void CSystem::InitTeacher(int teacher)
{ // initialize m_ppAgent[teacher] with compositional rules;
	assert(teacher==1);
	setGroupCompoRule(1, teacher, teacher);
}

void CSystem::InitAgentLoc()
{ // initialize agents' location;
	int i, j, G1size, G2size;
	int newlocX, newlocY, CenX, CenY, cen1X, cen1Y, cen2X, cen2Y;
	bool ident, sameloc;
	
	int G1low=-1, G1up=-1, G2low=-1, G2up=-1;
	if(getNumGroup()==1) { G1low=0; G1up=getNumAgent(); }
	else if(getNumGroup()==2) { G1low=0; G1up=(int)(getNumAgent()/_Twice+0.5); G2low=G1up; G2up=getNumAgent(); }
		  
	if(getNumGroup()==1)
		{ // 1 group;
		  CenX=(int)(getWorldX()*_Half); CenY=(int)(getWorldY()*_Half);
		  for(i=0;i<getNumAgent();i++)
		  	{ // set up each agent's initial location around center;
  		  	  ident=0;
		  	  do{ newlocX=CenX+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*getNumAgent()*_Half); 
			  	 while(newlocX>=getWorldX()) { newlocX-=getWorldX(); }
				 while(newlocX<=0) { newlocX+=getWorldX(); }
			  	 newlocY=CenY+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*getNumAgent()*_Half); 
				 while(newlocY>=getWorldY()) { newlocY-=getWorldY(); }
				 while(newlocY<=0) { newlocY+=getWorldY(); }
			  	 getpAgent(i)->setLocX(newlocX); getpAgent(i)->setLocY(newlocY);  	 
  	 	  	  	 sameloc=0; // check if two agents locations are identical;
	 	  	  	 for(j=0;j<i;j++) //check if two agents locate in the same position
					{ if((getpAgent(i)->getLocX()==getpAgent(j)->getLocX())&&(getpAgent(i)->getLocY()==getpAgent(j)->getLocY()))
						{ sameloc=1; break; }
	 			  	}
	 			 if(sameloc==0) ident=1;
  			  }while(ident==0);
 			}
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  cen1X=(int)(getWorldX()*_Half*_Half); cen1Y=(int)(getWorldY()*_Half*_Half);
		  cen2X=(int)(getWorldX()*_Half*_Half*3.0); cen2Y=(int)(getWorldY()*_Half*_Half*3.0);		  
		  G1size=G2size=0;
		  for(i=0;i<getNumAgent();i++)
		  	{ if(getpAgent(i)->getGroupIndex()==1) G1size++;
		  	  else if(getpAgent(i)->getGroupIndex()==2) G2size++;
		  	}
		  
		  // group 1's locations;
		  for(i=0;i<getNumAgent();i++)
		  	{ if(getpAgent(i)->getGroupIndex()==1)
		  		{ // group 1;
		  	  	  // set up each agent's initial location around center;
  		  	  	  ident=0;
		  	  	  do{ newlocX=cen1X+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*(G1up-G1low)*_Half); 
			  	 	 while(newlocX>=getWorldX()) { newlocX-=getWorldX(); }
				 	 while(newlocX<=0) { newlocX+=getWorldX(); }
			  	 	 newlocY=cen1Y+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*(G1up-G1low)*_Half); 
					 while(newlocY>=getWorldY()) { newlocY-=getWorldY(); }
				 	 while(newlocY<=0) { newlocY+=getWorldY(); }
			  	   	 getpAgent(i)->setLocX(newlocX); getpAgent(i)->setLocY(newlocY);  	 
  	 	  	  	  	 sameloc=0; // check if two agents locations are identical;
	 	  	  	  	 for(j=0;j<i;j++) //check if two agents locate in the same position
						{ if((getpAgent(j)->getGroupIndex()==1)&&(getpAgent(i)->getLocX()==getpAgent(j)->getLocX())&&(getpAgent(i)->getLocY()==getpAgent(j)->getLocY()))
							{ sameloc=1; break; }
	 				  	}
	 				 if(sameloc==0) ident=1;
  			  	  }while(ident==0);
 				}
		  	  else if(getpAgent(i)->getGroupIndex()==2)
		  	  	{ // group 2;
				  // set up each agent's initial location around center;
  		  	  	  ident=0;
		  	  	  do{ newlocX=cen2X+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*(G2up-G2low)*_Half); 
			  	 	 while(newlocX>=getWorldX()) { newlocX-=getWorldX(); }
				 	 while(newlocX<=0) { newlocX+=getWorldX(); }
			  	 	 newlocY=cen2Y+((FLOAT_SM_EQ(Rand0_1, _Half))?1:-1)*(int)(Rand0_1*(G2up-G2low)*_Half); 
				  	 while(newlocY>=getWorldY()) { newlocY-=getWorldY(); }
				 	 while(newlocY<=0) { newlocY+=getWorldY(); }
			  	   	 getpAgent(i)->setLocX(newlocX); getpAgent(i)->setLocY(newlocY);  	 
  	 	  	  	  	 sameloc=0; // check if two agents locations are identical;
	 	  	  	  	 for(j=0;j<i;j++) //check if two agents locate in the same position
						{ if((getpAgent(j)->getGroupIndex()==2)&&(getpAgent(i)->getLocX()==getpAgent(j)->getLocX())&&(getpAgent(i)->getLocY()==getpAgent(j)->getLocY()))
							{ sameloc=1; break; }
	 			  		}
	 			  	 if(sameloc==0) ident=1;
  			  	  }while(ident==0);
		  	  	}
		  	}		  
		}
}

void CSystem::setGroupIndex()
{ // set up group index for each agent;
	int i, j, start, end;
	start=0;
	for(i=0;i<getNumGroup();i++)
		{  end=((start+(int)(getNumAgent()/(double)(getNumGroup())+0.5))<getNumAgent())?(start+(int)(getNumAgent()/(double)(getNumGroup())+0.5)):getNumAgent();
		  for(j=start;j<end;j++)
			getpAgent(j)->setGroupIndex(i+1);
		  start+=(int)(getNumAgent()/(double)(getNumGroup())+0.5);
		}
	/*
	if(getNumGroup()==1) 
		{ for(i=0;i<getNumAgent();i++)
			getpAgent(i)->setGroupIndex(1);
		}
	else if(getNumGroup()==2)
		{ for(i=0;i<(int)(getNumAgent()/(double)(getNumGroup())+0.5);i++)
			getpAgent(i)->setGroupIndex(1);
		  for(i=(int)(getNumAgent()/(double)(getNumGroup())+0.5);i<getNumAgent();i++)
		  	getpAgent(i)->setGroupIndex(2);
		}
	*/
}

void CSystem::InitSystem()
{ // initialization function;
	int i, j;
	setNumAgent(overallpara.p_nNumAgent);
	m_ppAgent=new CAgent * [getNumAgent()]; assert(m_ppAgent!=NULL);
	for(i=0;i<getNumAgent();i++)
		{ m_ppAgent[i]=new CAgent; assert(m_ppAgent[i]!=NULL);
		  getpAgent(i)->setIndex(i);		  
		}
	setCheckFre(overallpara.p_nCheckFre);
	setDecFlag(overallpara.p_nDecFlag); setSelfTalkFlag(overallpara.p_nSelfTalkFlag);
	setRecLocOrdNo_Str(overallpara.p_nRecLocOrdNo_Str);
	
	setComMode(overallpara.p_nComMode);
	setNumGroup(overallpara.p_nNumGroup); setGroupIndex();

	setG1HolComp(overallpara.p_nG1HolComp); 
	setG1CompTyp(overallpara.p_nG1CompTyp);
	setG1InitCompCat(overallpara.p_nG1InitCompCat); setG1order1(overallpara.p_nG1order1); setG1order2(overallpara.p_nG1order2);
	setG1SV1(overallpara.p_nG1SV1); setG1VS1(overallpara.p_nG1VS1);
	setG1SV(overallpara.p_nG1SV); setG1VS(overallpara.p_nG1VS); 
	setG1VO(overallpara.p_nG1VO); setG1OV(overallpara.p_nG1OV); 
	setG1SO(overallpara.p_nG1SO); setG1OS(overallpara.p_nG1OS);
	
	setG1LexNhomrate(overallpara.p_dG1LexNhomrate); setG1LexVhomrate(overallpara.p_dG1LexVhomrate); setG1LexNVhomrate(overallpara.p_dG1LexNVhomrate);

	setG2HolComp(overallpara.p_nG2HolComp); 
	setG2CompTyp(overallpara.p_nG2CompTyp);
	setG2InitCompCat(overallpara.p_nG2InitCompCat); setG2order1(overallpara.p_nG2order1); setG2order2(overallpara.p_nG2order2);
	setG2SV1(overallpara.p_nG2SV1); setG2VS1(overallpara.p_nG2VS1);
	setG2SV(overallpara.p_nG2SV); setG2VS(overallpara.p_nG2VS); 
	setG2VO(overallpara.p_nG2VO); setG2OV(overallpara.p_nG2OV); 
	setG2SO(overallpara.p_nG2SO); setG2OS(overallpara.p_nG2OS);	

	setG2LexNhomrate(overallpara.p_dG2LexNhomrate); setG2LexVhomrate(overallpara.p_dG2LexVhomrate); setG2LexNVhomrate(overallpara.p_dG2LexNVhomrate);

	setLexSim(overallpara.p_dLexSim);

	setHorObliMix(overallpara.p_nHorObliMix);
	setMixHorVer(overallpara.p_nMixHorVer);
	setNumAgentRep(overallpara.p_nNumAgentRep);

	setCalTransMethod(overallpara.p_nCalTransMethod);	
	setAdultChildRatio(overallpara.p_dAdultChildRatio); setChildChildRatio(overallpara.p_dChildChildRatio); setChildAdultRatio(overallpara.p_dChildAdultRatio); setVerProb(overallpara.p_dVerProb);
	setPCRatio(overallpara.p_dPCRatio); setACRatio(overallpara.p_dACRatio); setCCRatio(overallpara.p_dCCRatio); setCARatio(overallpara.p_dCARatio);
	setGrandCRatio(overallpara.p_dGrandCRatio); setParentCRatio(overallpara.p_dParentCRatio); setChildCRatio(overallpara.p_dChildCRatio);
	setGrandCType(overallpara.p_nGrandCType); setParentCType(overallpara.p_nParentCType);
	
	setVerTranRandCrt(overallpara.p_nVerTranRandCrt); setVerTranWrongCue(overallpara.p_nVerTranWrongCue);
	setDifAdultChild(overallpara.p_nDifAdultChild); setDifRatio(overallpara.p_dDifRatio);
	setSpUpd(overallpara.p_nSpUpd); setSpUpdProb(overallpara.p_dSpUpdProb);
	
	setNumGen(overallpara.p_nNumGen); setNumLearn(overallpara.p_nNumLearn);

	setHumanChimp(overallpara.p_nHumanChimp);
	setA1(overallpara.p_dA1); setK1(overallpara.p_dK1);
	setA2(overallpara.p_dA2); setK2(overallpara.p_dK2);
	setScale(overallpara.p_dScale);
	setPopRat(overallpara.p_dPopRat);
	setIntraRat(overallpara.p_dIntraRat); setInterRat(overallpara.p_dInterRat);

	setWorldX(overallpara.p_nWorldX); setWorldY(overallpara.p_nWorldY);
	setBlockDist(overallpara.p_nBlockDist);
	setSucRat(overallpara.p_dSucRat);
	setSucCri(overallpara.p_nSucCri);
	setMoveStep(overallpara.p_nMoveStep);
	set1toMCom(overallpara.p_n1toMCom);

	setSelfGrow(overallpara.p_nSelfGrow);

	setGATimeScale(overallpara.p_nGATimeScale);
	setNumSp(overallpara.p_nNumSp);
	setCulSelType(overallpara.p_nCulSelType); setGeneSelType(overallpara.p_nGeneSelType);
	setLearnAbiLow(overallpara.p_dLearnAbiLow); setLearnAbiUp(overallpara.p_dLearnAbiUp);
	setMutRate(overallpara.p_dMutRate); setMutStep(overallpara.p_dMutStep);

	setMemMutStep(overallpara.p_nMemMutStep); setMemMutType(overallpara.p_nMemMutType);

	setNumCom(overallpara.p_nNumCom); 
	setNumInfoChange(overallpara.p_nNumInfoChange);

	setCalAmbiguity(overallpara.p_nCalAmbiguity);
	setRecMem(overallpara.p_nRecMem);

	setShowComInfo(overallpara.p_nShowComInfo);

	setIndURCalMethod(overallpara.p_nIndURCalMethod);
	setRecIndInfo(overallpara.p_nRecIndInfo);
	setRecURiniser(overallpara.p_nRecURiniser);
		
	// adjust m_pCues->SemSpace;
	switch(getpAgent(0)->getpSemSpace()->getSemDist())
		{ case 1: case 3: case 4: case 5: // identical distribution;
				// all agents shared the same distribution of m_ppAgent[0];
				for(i=1;i<getNumAgent();i++)
					{ for(j=0;j<getpAgent(0)->getpSemSpace()->getNumIntgMean();j++)
						getpAgent(i)->getpSemSpace()->getpSemItem(j)->setFre(getpAgent(0)->getpSemSpace()->getpSemItem(j)->getFre());
					}
				break;
		  default: break;
		}
	// initialize shared rules;
	switch(getComMode())
		{ case 2: InitTeacher(1); break; // initialize m_ppAgent[1] with holistic/compositional rules;		  			
		  default: InitRuleAll(); break;	// initialize all agents holistic/compo rules;
		}
	// initialize agents' location;
	if(getComMode()==4) InitAgentLoc();

	// copy m_ppAgent to m_ppAgent1 and m_ppAgentN;
	m_ppAgent1=new CAgent * [getNumAgent()]; assert(m_ppAgent1!=NULL);
	for(i=0;i<getNumAgent();i++)
		{ m_ppAgent1[i]=NULL; copyAgent(getpAgent(i), m_ppAgent1[i]); }
	m_ppAgentN=new CAgent * [getNumAgent()]; assert(m_ppAgentN!=NULL);
	for(i=0;i<getNumAgent();i++)
		{ m_ppAgentN[i]=NULL; copyAgent(getpAgent(i), m_ppAgentN[i]); }	
}

void CSystem::DestSystem()
{ // destroy function;
	int i;
	if(getNumAgent()!=0)
		{ for(i=0;i<getNumAgent();i++)
			{ delete m_ppAgentN[i]; m_ppAgentN[i]=NULL; }
		  delete [] m_ppAgentN; m_ppAgentN=NULL;
		  for(i=0;i<getNumAgent();i++)
			{ delete m_ppAgent1[i]; m_ppAgent1[i]=NULL; }
		  delete [] m_ppAgent1; m_ppAgent1=NULL;
 
		  for(i=0;i<getNumAgent();i++)
			{ delete m_ppAgent[i]; m_ppAgent[i]=NULL; }
		  delete [] m_ppAgent; m_ppAgent=NULL;
		  
		  setNumAgent(0);
		}
	setCheckFre(0);
	setDecFlag(-1); setSelfTalkFlag(-1);
	setRecLocOrdNo_Str(-1);
	
	setComMode(-1);
	setNumGroup(0);

	setG1HolComp(-1); 
	setG1CompTyp(-1);
	setG1InitCompCat(-1); 	setG1order1(0); setG1order2(0);
	setG1SV1(0); setG1VS1(0);
	setG1SV(0); setG1VS(0); 
	setG1VO(0); setG1OV(0); 
	setG1SO(0); setG1OS(0);

	setG1LexNhomrate(0.0); setG1LexVhomrate(0.0); setG1LexNVhomrate(0.0);

	setG2HolComp(-1); 
	setG2CompTyp(-1);
	setG2InitCompCat(-1); 	setG2order1(0); setG2order2(0);
	setG2SV1(0); setG2VS1(0);
	setG2SV(0); setG2VS(0); 
	setG2VO(0); setG2OV(0); 
	setG2SO(0); setG2OS(0);	

	setG2LexNhomrate(0.0); setG2LexVhomrate(0.0); setG2LexNVhomrate(0.0);

	setLexSim(0.0);

	setHorObliMix(-1);
	setMixHorVer(-1);
	setNumAgentRep(0);

	setCalTransMethod(-1);
	setAdultChildRatio(0.0); setChildChildRatio(0.0); setChildAdultRatio(0.0); setVerProb(0.0);
	setPCRatio(0.0); setACRatio(0.0); setCCRatio(0.0); setCARatio(0.0);
	setGrandCRatio(0.0); setParentCRatio(0.0); setChildCRatio(0.0);
	setGrandCType(-1); setParentCType(-1);
	
	setVerTranRandCrt(-1); setVerTranWrongCue(-1);
	setDifAdultChild(-1); setDifRatio(0.0);
	setSpUpd(-1); setSpUpdProb(0.0);
	
	setNumGen(0); setNumLearn(0);

	setHumanChimp(-1);
	setA1(0.0); setK1(0.0);
	setA2(0.0); setK2(0.0);
	setScale(0.0);
	setPopRat(0.0);
	setIntraRat(0.0); setInterRat(0.0);

	setWorldX(0); setWorldY(0);
	setBlockDist(0);
	setSucRat(0.0);
	setSucCri(-1);
	setMoveStep(0);
	set1toMCom(-1);

	setSelfGrow(-1);

	setGATimeScale(0);
	setNumSp(0);
	setCulSelType(-1); setGeneSelType(-1);
	setLearnAbiLow(0.0); setLearnAbiUp(0.0);
	setMutRate(0.0); setMutStep(0.0);

	setMemMutStep(0); setMemMutType(-1);
	
	setNumCom(0); 
	setNumInfoChange(0);

	setCalAmbiguity(-1);
	setRecMem(-1);

	setShowComInfo(-1);

	setIndURCalMethod(-1);
	setRecIndInfo(-1);
	setRecURiniser(-1);
}

void CSystem::copyAgent(CAgent *agent, CAgent *&agentCopy)
{ // copy agent to agentCopy;
	assert(agent!=NULL);
	int i, j, k;
	CLexRule *lexRule=NULL; CCat *cat=NULL; CatList *catList=NULL; CSynRule *synRule=NULL;
	if(agentCopy==NULL) { agentCopy=new CAgent; assert(agentCopy!=NULL); }
	*agentCopy=*agent;	// copy from SpAgent;
	
	// agentCopy->m_pMeanUtter and agentCopy->m_pCue do not need adjusting;
	
	// adjust agentCopy->m_pSemspace; recreate it;
	for(i=0;i<agentCopy->getpSemSpace()->getNumIntgMean();i++)
		agentCopy->getpSemSpace()->EmpSemItem(i);
	agentCopy->getpSemSpace()->DestSemSpace(); 
	agentCopy->getpSemSpace()->InitSemSpace(); agentCopy->getpSemSpace()->CreateSemSpace();
	switch(agentCopy->getpSemSpace()->getSemDist())
	  	{ case 1: case 3: case 5:	// identical distribution;
	  			for(i=0;i<agent->getpSemSpace()->getNumIntgMean();i++)
					agentCopy->getpSemSpace()->getpSemItem(i)->setFre(agent->getpSemSpace()->getpSemItem(i)->getFre());
				break;
		  default: break;
		}

	// adjust agentCopy->m_pBufer; empty it;
	if(agentCopy->getpBuffer()->getCurBufSize()!=0)
	  	{ for(i=0;i<agentCopy->getpBuffer()->getCurBufSize();i++)
	  		agentCopy->getpBuffer()->setpBuf(i, NULL);
	  	}
	agentCopy->getpBuffer()->DestBuffer(); agentCopy->getpBuffer()->InitBuffer(0, agent->getpBuffer()->getMaxBufSize());
	
	// adjust agentCopy->m_pLTMem;
	// first, recreate lexRule, cat and synRule;
	if(agentCopy->getpLTMem()->getNumLexRule()!=0)
	 	{ for(i=0;i<agentCopy->getpLTMem()->getNumLexRule();i++)
	  		{ // recreate lexRule
			  agentCopy->getpLTMem()->setpLexRuleList(i, NULL);
			  lexRule=new CLexRule; assert(lexRule!=NULL);
			  *lexRule=*(agent->getpLTMem()->getpLexRuleList(i));
			  agentCopy->getpLTMem()->setpLexRuleList(i, lexRule);
			}
	  	}
	if(agentCopy->getpLTMem()->getNumCat()!=0)
	 	{ for(i=0;i<agentCopy->getpLTMem()->getNumCat();i++)
	 		{ // recreate cat;
	 		  agentCopy->getpLTMem()->setpCatList(i, NULL);
			  cat=new CCat; assert(cat!=NULL);
			  *cat=*(agent->getpLTMem()->getpCatList(i));
	 		  agentCopy->getpLTMem()->setpCatList(i, cat);
			}
	  	}
	if(agentCopy->getpLTMem()->getNumSynRule()!=0)
	  	{ for(i=0;i<agentCopy->getpLTMem()->getNumSynRule();i++)
	  		{ // recreate synRule;
	  		  agentCopy->getpLTMem()->setpSynRuleList(i, NULL);
			  synRule=new CSynRule; assert(synRule!=NULL);
			  *synRule=*(agent->getpLTMem()->getpSynRuleList(i));
	  		  agentCopy->getpLTMem()->setpSynRuleList(i, synRule);
			}
	  	}
	// then, adjust the pointers among them;
	// adjust agentCopy's lexical rules' m_ppCatList;
	for(i=0;i<agentCopy->getpLTMem()->getNumLexRule();i++)
	  	{ for(j=0;j<agentCopy->getpLTMem()->getpLexRuleList(i)->getCatNum();j++)
	  		{ for(k=0;k<agent->getpLTMem()->getNumCat();k++)
	  			{ if(agentCopy->getpLTMem()->getpLexRuleList(i)->getpCatList(j)->getpCat()==agent->getpLTMem()->getpCatList(k)) 
	  				{ // recreate calList;
	  				  catList=new CatList; assert(catList!=NULL);
					  catList->setpCat(agentCopy->getpLTMem()->getpCatList(k));
					  catList->setThemRole(agentCopy->getpLTMem()->getpLexRuleList(i)->getpCatList(j)->getThemRole());
					  catList->setAssoWei(agentCopy->getpLTMem()->getpLexRuleList(i)->getpCatList(j)->getAssoWei());
					  agentCopy->getpLTMem()->getpLexRuleList(i)->setpCatListWhole(j, catList);
					  break;
					}
	  			}
	  		}
	  	}
	// adjust agentCopy's cat's m_ppLexRule and m_ppSynRule;
	for(i=0;i<agentCopy->getpLTMem()->getNumCat();i++)
	  	{ for(j=0;j<agentCopy->getpLTMem()->getpCatList(i)->getLexNum();j++)
	  		{ for(k=0;k<agent->getpLTMem()->getNumLexRule();k++)
	  			{ if(agentCopy->getpLTMem()->getpCatList(i)->getpLexRule(j)==agent->getpLTMem()->getpLexRuleList(k))
	  				{ agentCopy->getpLTMem()->getpCatList(i)->setpLexRule(j, agentCopy->getpLTMem()->getpLexRuleList(k)); break; }
	  			}
	  		}
	  	}
	for(i=0;i<agentCopy->getpLTMem()->getNumCat();i++)
	  	{ for(j=0;j<agentCopy->getpLTMem()->getpCatList(i)->getSynNum();j++)
	  		{ for(k=0;k<agent->getpLTMem()->getNumSynRule();k++)
	  			{ if(agentCopy->getpLTMem()->getpCatList(i)->getpSynRule(j)==agent->getpLTMem()->getpSynRuleList(k))
	  				{ agentCopy->getpLTMem()->getpCatList(i)->setpSynRule(j, agentCopy->getpLTMem()->getpSynRuleList(k)); break; }
	  			}
	  		}
	  	}
	// adjust agentCopy's syntactic rules' m_ppCat;
	for(i=0;i<agentCopy->getpLTMem()->getNumSynRule();i++)
	  	{ for(j=0;j<agentCopy->getpLTMem()->getpSynRuleList(i)->getNumCatRelated();j++)
	  		{ for(k=0;k<agent->getpLTMem()->getNumCat();k++)
	  			{ if(agentCopy->getpLTMem()->getpSynRuleList(i)->getpCat(j)==agent->getpLTMem()->getpCatList(k))
	  				{ agentCopy->getpLTMem()->getpSynRuleList(i)->setpCat(j, agentCopy->getpLTMem()->getpCatList(k)); break; }
	  			}
	  		}
	  	}
			
	// adjust agentCopy->m_pIMMem; empty it;
	if(agentCopy->getpIMMem()->getNumCombOption()!=0)
		{ for(i=0;i<agentCopy->getpIMMem()->getNumCombOption();i++)
			agentCopy->getpIMMem()->setpOptionComb(i, NULL);
		}
	agentCopy->getpIMMem()->EmpOptionComb();
}

void CSystem::updAgentN()
{ // update m_ppAgent into m_ppAgentN;
	int i;
	for(i=0;i<getNumAgent();i++)
		{ delete m_ppAgentN[i]; m_ppAgentN[i]=NULL;
		  copyAgent(getpAgent(i), m_ppAgentN[i]);
		}
}

// other operations;
void CSystem::ChkConsistAll()
{ // check all agents whether all lexical rules, categories and syntactic rules are linked together in m_pLTMem; 
  	int i, j, k, m;
  	bool cat_syn, syn_cat1, syn_cat2;	// check whether categories and syntactic rules are linked together; 
  	bool catlist_cat, cat_catlist;	// check whether lexical rules and categories are linked together;
  	bool catlist_syn, syn_catlist1, syn_catlist2;	// check whether lexical rules and syntactic rules are linked together;
	CLexRule *lexin=NULL; CCat *catin=NULL; CSynRule *synin=NULL;
	
  	int widthLex=(int)(log10((double)(getpAgent(0)->getpLTMem()->getMaxLexRule()))+1);
  	int widthCat=(int)(log10((double)(getpAgent(0)->getpLTMem()->getMaxCat()))+1);
  	int widthSyn=(int)(log10((double)(getpAgent(0)->getpLTMem()->getMaxSynRule()))+1);
	int widthMaxLex=(int)(log10((double)(getpAgent(0)->getpIMMem()->getMaxNumLexRules()))+1);
	int widthMaxCat=(int)(log10((double)(getpAgent(0)->getpIMMem()->getMaxNumCats()))+1);
	int widthMaxSyn=(int)(log10((double)(getpAgent(0)->getpIMMem()->getMaxNumSynRules()))+1);
	int widthAgent=(int)(log10((double)(getNumAgent()))+1);

	for(i=0;i<getNumAgent();i++)
	  	{ // basic check;
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
		  	{ if((FLOAT_BG(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexStr(), getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexRuleStrUp()))||(FLOAT_SM(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexStr(), getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexRuleStrLow())))
				printf("Agent[%*d]->Lex[%*d] strength outside!\n", widthAgent, i, widthLex, j);
		  	}
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
		  	{ if((FLOAT_BG(getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynStr(), getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynRuleStrUp()))||(FLOAT_SM(getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynStr(), getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynRuleStrLow())))
				printf("Agent[%*d]->Syn[%*d] strength outside!\n", widthAgent, i, widthSyn, j);
		  	}
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
	  	  	{ if((getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getpMeanUtter()==NULL)||(FLOAT_EQ(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexStr(), overallpara.p_dLexRuleStrLow))) printf("Agent[%*d]->Lex[%*d]: does not exist!\n", widthAgent, i, widthLex, j);
			  else
			  	{ for(k=0;k<getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getCatNum();k++)
			  		{ if((getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getpCatList(k)==NULL)||(FLOAT_EQ(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getAssoWei(), overallpara.p_dAssoWeiLow))) printf("Agent[%*d]->Lex[%*d]->CatList[%*d]: does not exist!\n", widthAgent, i, widthLex, j, widthMaxCat, k);
			  		  else
			  		  	{ if((getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getpCat()==NULL)||(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getpCat()->getThemRole()==-1))
			  		  		printf("Agent[%*d]->Lex[%*d]->CatList[%*d]'s cat does not exist!\n", widthAgent, i, widthLex, j, widthMaxLex, k);
			  		  	}
			  		}
			  	}
	  	  	}
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumCat();j++)
	  	  	{ if(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()==-1) printf("Agent[%*d]->Cat[%*d]: does not exist!\n", widthAgent, i, widthCat, j);
	  	  	  else
	  	  	  	{ for(k=0;k<getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum();k++)
	  	  			{ if(getpAgent(i)->getpLTMem()->getpCatList(j)->getpLexRule(k)->getpMeanUtter()==NULL)
	  	  				printf("Agent[%*d]->Cat[%*d]->Lex[%*d]: does not exist!\n", widthAgent, i, widthCat, j, widthMaxLex, k);
	  	  			}
	  	  		  for(k=0;k<getpAgent(i)->getpLTMem()->getpCatList(j)->getSynNum();k++)
	  	  		  	{ if(getpAgent(i)->getpLTMem()->getpCatList(j)->getpSynRule(k)->getCats()==NULL)
	  	  				printf("Agent[%*d]->Cat[%*d]->Syn[%*d]: does not exist!\n", widthAgent, i, widthCat, j, widthMaxSyn, k);
	  	  			}
	  	  		}
	  	  	}
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
		  	{ if((getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynTyp()==-1)||(FLOAT_EQ(getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getSynStr(), overallpara.p_dSynRuleStrLow))) printf("Agent[%*d]->Syn[%*d]: does not exist!\n", widthAgent, i, widthSyn, j);
		   	  else
		   	  	{ if((getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(0)->getThemRole()==-1)||(getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(1)->getThemRole()==-1))
					printf("Agent[%*d]->Syn[%*d]'s cat does not exist!\n", widthAgent, i, widthSyn, j);
		   	  	}
		  	}
		  	  	  
	  	  // check whether categories and syntactic rules are linked together; 
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumCat();j++)
			{ if(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()!=0)
				{ catin=getpAgent(i)->getpLTMem()->getpCatList(j);
	  	  		  for(k=0;k<catin->getSynNum();k++)
	  	  		  	{ cat_syn=0; 
	  	  		    	   if((getpAgent(i)->getpLTMem()->Judge_InSyn(catin->getpSynRule(k))==1)&&(catin->getpSynRule(k)->judge_InCat(catin)==1)) cat_syn=1;
	  	  		  	   if(cat_syn==0) printf("Agent[%*d]->Cat[%*d]: cat_syn not consistent\n", widthAgent, i, widthCat, j);
	  	  		  	}	  	  		  
	  	  		  catin=NULL;	  			  
				}
	  	  	}
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
	  		{ synin=getpAgent(i)->getpLTMem()->getpSynRuleList(j);
	  	  	  catin=synin->getpCat(0);
	  		  syn_cat1=0; 
			  if((getpAgent(i)->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InSyn(synin)==1)) syn_cat1=1;
	  		  if(syn_cat1==0) printf("Agent[%*d]->Syn[%*d]: syn_cat1 not consistent\n", widthAgent, i, widthSyn, j);
	  		  catin=NULL;	  		  
	  		  
	  		  catin=synin->getpCat(1);
	  		  syn_cat2=0; 
	  		  if((getpAgent(i)->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InSyn(synin)==1)) syn_cat2=1;
	  		  if(syn_cat2==0) printf("Agent[%*d]->Syn[%*d]: syn_cat2 not consistent\n", widthAgent, i, widthSyn, j);
			  catin=NULL;
	  		  
	  		  synin=NULL;
			}
		  // check whether lexical rules and categories are linked together;
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
	  		{ lexin=getpAgent(i)->getpLTMem()->getpLexRuleList(j); 
			  if(lexin->getCatNum()==0)
			  	{ catlist_cat=1;
				  for(m=0;m<getpAgent(i)->getpLTMem()->getNumCat();m++)
					{ if(getpAgent(i)->getpLTMem()->getpCatList(m)->judge_InLex(lexin)==1) printf("Abnormal! Agent[%*d]->Cat[%*d] has Lex [%*d] but Lex has no catnum\n", widthAgent, i, widthCat, m, widthMaxLex, j);
			  		}
			  	}
			  else
			  	{ for(k=0;k<lexin->getCatNum();k++)
					{ catin=lexin->getpCatList(k)->getpCat();
					  catlist_cat=0;
					  if((getpAgent(i)->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InLex(lexin)==1)) catlist_cat=1;
					  if(catlist_cat==0) printf("Agent[%*d]->Lex[%*d]->Catlist[%*d]: catlist_cat not consistent\n", widthAgent, i, widthLex, j, widthMaxCat, k);
					  catin=NULL;				  
	  				}	
			  	}
	  		  lexin=NULL;	  		  
	  		}
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumCat();j++)
		  	{ catin=getpAgent(i)->getpLTMem()->getpCatList(j);
		  	   for(k=0;k<catin->getLexNum();k++)
		  		{ lexin=catin->getpLexRule(k);
		  	   	  if(lexin->getCatNum()==0)
		  	   	  	{ cat_catlist=1;
		  	   	  	  printf("Abnormal! Agent[%*d]->Cat[%*d] has Lex[%*d] but lex has no catnum\n", widthAgent, i, widthCat, j, widthMaxLex, k);
		  	   	  	}
				  else
				  	{ cat_catlist=0;
					  if((getpAgent(i)->getpLTMem()->Judge_InLex(lexin)==1)&&(lexin->judge_InCat(catin)==1)) cat_catlist=1;
		  		  	  if(cat_catlist==0) printf("Agent[%*d]->Cat[%*d]->Lex[%*d]: cat_catlist not consistent\n", widthAgent, i, widthCat, j, widthMaxLex, k);
				  	}
		  		  lexin=NULL;
		  	   	}		  		  
		  	   catin=NULL;		  	   
  	  		}
	  	  
		  // check whether lexical rules and syntactic rules are linked together;
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
	  		{ lexin=getpAgent(i)->getpLTMem()->getpLexRuleList(j);
		  	  for(k=0;k<lexin->getCatNum();k++)
	  			{ if(lexin->getpCatList(k)->getpCat()->getThemRole()!=0)
					{ catin=lexin->getpCatList(k)->getpCat();
					  catlist_syn=0;
					  for(m=0;m<getpAgent(i)->getpLTMem()->getNumSynRule();m++)
				 		{ if(getpAgent(i)->getpLTMem()->getpSynRuleList(m)->judge_InCat(catin)==1) { catlist_syn=1; break; }  			  	  			  			  
			  			}
					  if(catlist_syn==0) printf("Agent[%*d]->Lex[%*d]->Catlist[%*d]: catlist_syn not consistent\n", widthAgent, i, widthLex, j, widthMaxCat, k);
					  catin=NULL;					  
			  		}
				}
		  	  lexin=NULL;
			}
	  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
			{ catin=getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(0);
			  syn_catlist1=0;
			  for(k=0;k<getpAgent(i)->getpLTMem()->getNumLexRule();k++)
	  	  		{ if(getpAgent(i)->getpLTMem()->getpLexRuleList(k)->judge_InCat(catin)==1) { syn_catlist1=1; break; }
	  	 		}
			  if(syn_catlist1==0) printf("Agent[%*d]->Syn[%*d]: syn_catlist1 not consistent\n", widthAgent, i, widthSyn, j);
			  catin=NULL;
	  	  	  
	  	  	  catin=getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(1);
			  syn_catlist2=0;
	  	  	  for(k=0;k<getpAgent(i)->getpLTMem()->getNumLexRule();k++)
	  	  		{ if(getpAgent(i)->getpLTMem()->getpLexRuleList(k)->judge_InCat(catin)==1) { syn_catlist2=1; break; }
	  	  		}			  
	  	  	  if(syn_catlist2==0) printf("Agent[%*d]->Syn[%*d]: syn_catlist2 not consistent\n", widthAgent, i, widthSyn, j);
	  	  	  catin=NULL;
	  	  	}

	  	  // check whether syntactic rules have 2 cats having same themrole;
		  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
  		  	{ if(getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(0)->getThemRole()==getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(1)->getThemRole())
  		  		printf("Agent[%*d]->Syn[%*d] has 2 cats having same themrole\n", widthAgent, i, widthSyn, j);
  		  	}
	  	}
}

void CSystem::ChkConsist(int type, CAgent *Ag)
{ // check one specific agent whether all lexical rules, categories and syntactic rules are linked together in m_pLTMem; 
  // type=1, speaker; 2, listener; 3, neighbor;
	assert((type==1)||(type==2)||(type==3)); assert(Ag!=NULL);
	int j, k, m;
  	bool cat_syn, syn_cat1, syn_cat2;	// check whether categories and syntactic rules are linked together; 
  	bool catlist_cat, cat_catlist;	// check whether lexical rules and categories are linked together;
  	bool catlist_syn, syn_catlist1, syn_catlist2;	// check whether lexical rules and syntactic rules are linked together;
	CLexRule *lexin=NULL; CCat *catin=NULL; CSynRule *synin=NULL;
	
  	int widthLex=(int)(log10((double)(Ag->getpLTMem()->getMaxLexRule()))+1);
  	int widthCat=(int)(log10((double)(Ag->getpLTMem()->getMaxCat()))+1);
  	int widthSyn=(int)(log10((double)(Ag->getpLTMem()->getMaxSynRule()))+1);
	int widthMaxLex=(int)(log10((double)(Ag->getpIMMem()->getMaxNumLexRules()))+1);
	int widthMaxCat=(int)(log10((double)(Ag->getpIMMem()->getMaxNumCats()))+1);
	int widthMaxSyn=(int)(log10((double)(Ag->getpIMMem()->getMaxNumSynRules()))+1);

	// basic check;
	for(j=0;j<Ag->getpLTMem()->getNumLexRule();j++)
	  	{ if((FLOAT_BG(Ag->getpLTMem()->getpLexRuleList(j)->getLexStr(), Ag->getpLTMem()->getpLexRuleList(j)->getLexRuleStrUp()))||(FLOAT_SM(Ag->getpLTMem()->getpLexRuleList(j)->getLexStr(), Ag->getpLTMem()->getpLexRuleList(j)->getLexRuleStrLow())))
			{ switch(type)
				{ case 1: printf("Speaker->Lex[%*d] strength outside!\n", widthLex, j); break;	// speaker;
				  case 2: printf("Listener->Lex[%*d] strength outside!\n", widthLex, j); break;	// listener;
				  case 3: printf("Neighbor->Lex[%*d] strength outside!\n", widthLex, j); break;	// neighbor;
				  default: break;
				}
			}
	  	}
	for(j=0;j<Ag->getpLTMem()->getNumSynRule();j++)
	  	{ if((FLOAT_BG(Ag->getpLTMem()->getpSynRuleList(j)->getSynStr(), Ag->getpLTMem()->getpSynRuleList(j)->getSynRuleStrUp()))||(FLOAT_SM(Ag->getpLTMem()->getpSynRuleList(j)->getSynStr(), Ag->getpLTMem()->getpSynRuleList(j)->getSynRuleStrLow())))
			{ switch(type)
				{ case 1: printf("Speaker->Syn[%*d] strength outside!\n", widthSyn, j); break;	// speaker;
				  case 2: printf("Listener->Syn[%*d] strength outside!\n", widthSyn, j); break;	// listener;
				  case 3: printf("Neighbor->Syn[%*d] strength outside!\n", widthSyn, j); break;	// neighbor;
				  default: break;
				}
			}
	  	}
	for(j=0;j<Ag->getpLTMem()->getNumLexRule();j++)
	  	{ if((Ag->getpLTMem()->getpLexRuleList(j)->getpMeanUtter()==NULL)||(FLOAT_EQ(Ag->getpLTMem()->getpLexRuleList(j)->getLexStr(), overallpara.p_dLexRuleStrLow))) 
	  		{ switch(type)
	  			{ case 1: printf("Speaker->Lex[%*d]: does not exist!\n", widthLex, j); break;	// speaker;
	  			  case 2: printf("Listener->Lex[%*d]: does not exist!\n", widthLex, j); break;	// listener;
	  			  case 3: printf("Neighbor->Lex[%*d]: does not exist!\n", widthLex, j); break;	// neighbor;
	  			  default: break;
				}
			}
		  else
		  	{ for(k=0;k<Ag->getpLTMem()->getpLexRuleList(j)->getCatNum();k++)
		  		{ if((Ag->getpLTMem()->getpLexRuleList(j)->getpCatList(k)==NULL)||(FLOAT_EQ(Ag->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getAssoWei(), overallpara.p_dAssoWeiLow))) 
		  			{ switch(type)
		  				{ case 1: printf("Speaker->Lex[%*d]->CatList[%*d]: does not exist!\n", widthLex, j, widthMaxCat, k); break;	// speaker;
		  				  case 2: printf("Listener->Lex[%*d]->CatList[%*d]: does not exist!\n", widthLex, j, widthMaxCat, k); break;	// listener;
		  				  case 3: printf("Neighbor->Lex[%*d]->CatList[%*d]: does not exist!\n", widthLex, j, widthMaxCat, k); break;	// neighbor;
		  				  default: break;
		  				}
		  			}
		  		  else
		  		  	{ if((Ag->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getpCat()==NULL)||(Ag->getpLTMem()->getpLexRuleList(j)->getpCatList(k)->getpCat()->getThemRole()==-1))
		  		  		{ switch(type)
		  		  			{ case 1: printf("Speaker->Lex[%*d]->CatList[%*d]'s cat does not exist!\n", widthLex, j, widthMaxLex, k); break;	// speaker;
		  		  			  case 2: printf("Listener->Lex[%*d]->CatList[%*d]'s cat does not exist!\n", widthLex, j, widthMaxLex, k); break;	// listener;
		  		  			  case 3: printf("Neighbor->Lex[%*d]->CatList[%*d]'s cat does not exist!\n", widthLex, j, widthMaxLex, k); break;	// neighbor;
		  		  			  default: break;
		  		  			}
		  		  		}
		  		  	}
		  		}
		  	}
	  	}
	for(j=0;j<Ag->getpLTMem()->getNumCat();j++)
	  	{ if(Ag->getpLTMem()->getpCatList(j)->getThemRole()==-1) 
	  		{ switch(type)
	  			{ case 1: printf("Speaker->Cat[%*d]: does not exist!\n", widthCat, j); break;	// speaker;
	  			  case 2: printf("Listener->Cat[%*d]: does not exist!\n", widthCat, j); break;	// listener;
	  			  case 3: printf("Neighbor->Cat[%*d]: does not exist!\n", widthCat, j); break;	// neighbor;
	  			  default: break;
				}
			}
	  	  else
	  	  	{ for(k=0;k<Ag->getpLTMem()->getpCatList(j)->getLexNum();k++)
	  			{ if(Ag->getpLTMem()->getpCatList(j)->getpLexRule(k)->getpMeanUtter()==NULL)
	  				{ switch(type)
	  					{ case 1: printf("Speaker->Cat[%*d]->Lex[%*d]: does not exist!\n", widthCat, j, widthMaxLex, k); break;	// speaker;
	  					  case 2: printf("Listener->Cat[%*d]->Lex[%*d]: does not exist!\n", widthCat, j, widthMaxLex, k); break;	// listener;
	  					  case 3: printf("Neighbor->Cat[%*d]->Lex[%*d]: does not exist!\n", widthCat, j, widthMaxLex, k); break;	// neighbor;
	  					  default: break;
	  	  				}
	  	  			}
	  			}
	  		  for(k=0;k<Ag->getpLTMem()->getpCatList(j)->getSynNum();k++)
	  		  	{ if(Ag->getpLTMem()->getpCatList(j)->getpSynRule(k)->getCats()==NULL)
	  				{ switch(type)
	  					{ case 1: printf("Speaker->Cat[%*d]->Syn[%*d]: does not exist!\n", widthCat, j, widthMaxSyn, k); break;	// speaker;
	  					  case 2: printf("Listener->Cat[%*d]->Syn[%*d]: does not exist!\n", widthCat, j, widthMaxSyn, k); break;	// listener;
	  					  case 3: printf("Neighbor->Cat[%*d]->Syn[%*d]: does not exist!\n", widthCat, j, widthMaxSyn, k); break;	// neighbor;
	  					  default: break;
	  		  			}
	  		  		}
	  			}
	  		}
	  	}
	for(j=0;j<Ag->getpLTMem()->getNumSynRule();j++)
	  	{ if((Ag->getpLTMem()->getpSynRuleList(j)->getSynTyp()==-1)||(FLOAT_EQ(Ag->getpLTMem()->getpSynRuleList(j)->getSynStr(), overallpara.p_dSynRuleStrLow))) 
	  		{ switch(type)
	  			{ case 1: printf("Speaker->Syn[%*d]: does not exist!\n", widthSyn, j); break;	// speaker;
	  			  case 2: printf("Listener->Syn[%*d]: does not exist!\n", widthSyn, j); break;	// listener;
	  			  case 3: printf("Neighbor->Syn[%*d]: does not exist!\n", widthSyn, j); break;	// neighbor;
	  			  default: break;
				}
			}
	   	  else
	   	  	{ if((Ag->getpLTMem()->getpSynRuleList(j)->getpCat(0)->getThemRole()==-1)||(Ag->getpLTMem()->getpSynRuleList(j)->getpCat(1)->getThemRole()==-1))
				{ switch(type)
					{ case 1: printf("Speaker->Syn[%*d]'s cat does not exist!\n", widthSyn, j); break;	// speaker;
					  case 2: printf("Listener->Syn[%*d]'s cat does not exist!\n", widthSyn, j); break;	// listener;
					  case 3: printf("Neighbor->Syn[%*d]'s cat does not exist!\n", widthSyn, j); break;	// neighbor;
					  default: break;
		  			}
	   	  		}
	   	  	}
	  	}
	  	  	  
	// check whether categories and syntactic rules are linked together; 
	for(j=0;j<Ag->getpLTMem()->getNumCat();j++)
		{ if(Ag->getpLTMem()->getpCatList(j)->getThemRole()!=0)
			{ catin=Ag->getpLTMem()->getpCatList(j);
	  		  for(k=0;k<catin->getSynNum();k++)
	  		  	{ cat_syn=0; 
	  		    	  if((Ag->getpLTMem()->Judge_InSyn(catin->getpSynRule(k))==1)&&(catin->getpSynRule(k)->judge_InCat(catin)==1)) cat_syn=1;
	  		  	  if(cat_syn==0) 
					{ switch(type)
						{ case 1: printf("Speaker->Cat[%*d]: cat_syn not consistent\n", widthCat, j); break;	// speaker;
						  case 2: printf("Listener->Cat[%*d]: cat_syn not consistent\n", widthCat, j); break;	// listener;
						  case 3: printf("Neighbor->Cat[%*d]: cat_syn not consistent\n", widthCat, j); break;	// neighbor;
						  default: break;
	  		    	   		}
	  		    	   	}
	  		  	}	  	  		  
	  		  catin=NULL;	  			  
			}
	    	}
	for(j=0;j<Ag->getpLTMem()->getNumSynRule();j++)
		{ synin=Ag->getpLTMem()->getpSynRuleList(j);
	  	  catin=synin->getpCat(0);
		  syn_cat1=0;
		  if((Ag->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InSyn(synin)==1)) syn_cat1=1;
		  if(syn_cat1==0) 
		  	{ switch(type)
		  		{ case 1: printf("Speaker->Syn[%*d]: syn_cat1 not consistent\n", widthSyn, j); break;	// speaker;
		  		  case 2: printf("Listener->Syn[%*d]: syn_cat1 not consistent\n", widthSyn, j); break;	// listener;
		  		  case 3: printf("Neighbor->Syn[%*d]: syn_cat1 not consistent\n", widthSyn, j); break;	// neighbor;
		  		  default: break;
		  		}
		  	}
		  catin=NULL;	  		  
	 		  
		  catin=synin->getpCat(1);
		  syn_cat2=0;
		  if((Ag->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InSyn(synin)==1)) syn_cat2=1;
		  if(syn_cat2==0) 
		  	{ switch(type)
		  		{ case 1: printf("Speaker->Syn[%*d]: syn_cat2 not consistent\n", widthSyn, j); break;	// speaker;
		  		  case 2: printf("Listener->Syn[%*d]: syn_cat2 not consistent\n", widthSyn, j); break;	// listener;
		  		  case 3: printf("Neighbor->Syn[%*d]: syn_cat2 not consistent\n", widthSyn, j); break;	// neighbor;
		  		  default: break;
		  		}
		  	}
		  catin=NULL;
	  		  
		  synin=NULL;
		}
  	// check whether lexical rules and categories are linked together;
	for(j=0;j<Ag->getpLTMem()->getNumLexRule();j++)
		{ lexin=Ag->getpLTMem()->getpLexRuleList(j); 
		  if(lexin->getCatNum()==0)
		  	{ catlist_cat=1;
			  for(m=0;m<Ag->getpLTMem()->getNumCat();m++)
				{ if(Ag->getpLTMem()->getpCatList(m)->judge_InLex(lexin)==1)
				  	{ switch(type)
		  		  		{ case 1: printf("Abnormal! Speaker->Cat[%*d] has Lex [%*d] but Lex has no catnum\n", widthCat, m, widthMaxLex, j); break;	// speaker;
		  		  		  case 2: printf("Abnormal! Listener->Cat[%*d] has Lex [%*d] but Lex has no catnum\n", widthCat, m, widthMaxLex, j); break;	// listener;
		  		  		  case 3: printf("Abnormal! Neighbor->Cat[%*d] has Lex [%*d] but Lex has no catnum\n", widthCat, m, widthMaxLex, j); break;	// neighbor;
		  		  		  default: break;
		  		  		}
		  		  	}
				}
		  	}
		  else
		  	{ for(k=0;k<lexin->getCatNum();k++)
				{ catin=lexin->getpCatList(k)->getpCat();
				  catlist_cat=0;
				  if((Ag->getpLTMem()->Judge_InCat(catin)==1)&&(catin->judge_InLex(lexin)==1)) catlist_cat=1;
				  if(catlist_cat==0) 
				  	{ switch(type)
				  		{ case 1: printf("Speaker->Lex[%*d]->Catlist[%*d]: catlist_cat not consistent\n", widthLex, j, widthMaxCat, k); break;	// speaker;
				  		  case 2: printf("Listener->Lex[%*d]->Catlist[%*d]: catlist_cat not consistent\n", widthLex, j, widthMaxCat, k); break;	// listener;
				  		  case 3: printf("Neighbor->Lex[%*d]->Catlist[%*d]: catlist_cat not consistent\n", widthLex, j, widthMaxCat, k); break;	// neighbor;
				  		  default: break;
				  		}
				  	}
				  catin=NULL;				  
				}
		  	}
		  lexin=NULL;	  		  
		}
	for(j=0;j<Ag->getpLTMem()->getNumCat();j++)
	 	{ catin=Ag->getpLTMem()->getpCatList(j);
	  	   for(k=0;k<catin->getLexNum();k++)
	  		{ lexin=catin->getpLexRule(k);
	  	   	  if(lexin->getCatNum()==0)
	  	   	  	{ cat_catlist=1;
	  	   	  	  switch(type)
				  	{ case 1: printf("Abnormal! Speaker->Cat[%*d] has Lex[%*d] but lex has no catnum\n", widthCat, j, widthMaxLex, k); break;	// speaker;
				  	  case 2: printf("Abnormal! Listener->Cat[%*d] has Lex[%*d] but lex has no catnum\n", widthCat, j, widthMaxLex, k); break;	// listener;
				  	  case 3: printf("Abnormal! Neighbor->Cat[%*d] has Lex[%*d] but lex has no catnum\n", widthCat, j, widthMaxLex, k); break;	// neighbor;
				  	  default: break;
	  	   	  	  	}
	  	   	  	}
			  else
			  	{ cat_catlist=0;
			  	  if((Ag->getpLTMem()->Judge_InLex(lexin)==1)&&(lexin->judge_InCat(catin)==1)) cat_catlist=1;
				  if(cat_catlist==0) 
				  	{ switch(type)
				  		{ case 1: printf("Speaker->Cat[%*d]->Lex[%*d]: cat_catlist not consistent\n", widthCat, j, widthMaxLex, k); break;	// speaker;
				  		  case 2: printf("Listener->Cat[%*d]->Lex[%*d]: cat_catlist not consistent\n", widthCat, j, widthMaxLex, k); break;	// listener;
				  		  case 3: printf("Neighbor->Cat[%*d]->Lex[%*d]: cat_catlist not consistent\n", widthCat, j, widthMaxLex, k); break;	// neighbor;
				  		  default: break;
			  	  		}
			  	  	}
			  	}
	  		  lexin=NULL;
	  	   	}		  		  
	  	   catin=NULL;		  	   
  		}
	 	  
	// check whether lexical rules and syntactic rules are linked together;
	for(j=0;j<Ag->getpLTMem()->getNumLexRule();j++)
		{ lexin=Ag->getpLTMem()->getpLexRuleList(j);
	  	  for(k=0;k<lexin->getCatNum();k++)
			{ if(lexin->getpCatList(k)->getpCat()->getThemRole()!=0)
				{ catin=lexin->getpCatList(k)->getpCat();
				  catlist_syn=0;
				  for(m=0;m<Ag->getpLTMem()->getNumSynRule();m++)
			 		{ if(Ag->getpLTMem()->getpSynRuleList(m)->judge_InCat(catin)==1)	{ catlist_syn=1; break; }			  			  	  			  			  
		  			}
				  if(catlist_syn==0) 
				  	{ switch(type)
				  		{ case 1: printf("Speaker->Lex[%*d]->Catlist[%*d]: catlist_syn not consistent\n", widthLex, j, widthMaxCat, k); break;	// speaker;
				  		  case 2: printf("Listener->Lex[%*d]->Catlist[%*d]: catlist_syn not consistent\n", widthLex, j, widthMaxCat, k); break;	// listener;
				  		  case 3: printf("Neighbor->Lex[%*d]->Catlist[%*d]: catlist_syn not consistent\n", widthLex, j, widthMaxCat, k); break;	// neighbor;
				  		  default: break;
				  		}
				  	}
				  catin=NULL;					  
		  		}
			}
	  	  lexin=NULL;
		}
	for(j=0;j<Ag->getpLTMem()->getNumSynRule();j++)
		{ catin=Ag->getpLTMem()->getpSynRuleList(j)->getpCat(0);
		  syn_catlist1=0;
		  for(k=0;k<Ag->getpLTMem()->getNumLexRule();k++)
	  		{ if(Ag->getpLTMem()->getpLexRuleList(k)->judge_InCat(catin)==1) { syn_catlist1=1; break; }
		  	}
		  if(syn_catlist1==0) 
		  	{ switch(type)
		  		{ case 1: printf("Speaker->Syn[%*d]: syn_catlist1 not consistent\n", widthSyn, j); break;	// speaker;
		  		  case 2: printf("Listener->Syn[%*d]: syn_catlist1 not consistent\n", widthSyn, j); break;	// listener;
		  		  case 3: printf("Neighbor->Syn[%*d]: syn_catlist1 not consistent\n", widthSyn, j); break;	// neighbor;
		  		  default: break;
		  		}
		  	}
		  catin=NULL;
		  	  
	  	  catin=Ag->getpLTMem()->getpSynRuleList(j)->getpCat(1);
		  syn_catlist2=0;
	  	  for(k=0;k<Ag->getpLTMem()->getNumLexRule();k++)
	  		{ if(Ag->getpLTMem()->getpLexRuleList(k)->judge_InCat(catin)==1) { syn_catlist2=1; break; }
	  		}			  
	  	  if(syn_catlist2==0) 
		  	{ switch(type)
		  		{ case 1: printf("Speaker->Syn[%*d]: syn_catlist2 not consistent\n", widthSyn, j); break;	// speaker;
		  		  case 2: printf("Listener->Syn[%*d]: syn_catlist2 not consistent\n", widthSyn, j); break;	// listener;
		  		  case 3: printf("Neighbor->Syn[%*d]: syn_catlist2 not consistent\n", widthSyn, j); break;	// neighbor;
		  		  default: break;
	  	  		}
	  	  	}
	  	  catin=NULL;
	  	}

	// check whether syntactic rules have 2 cats having same themrole;
	for(j=0;j<Ag->getpLTMem()->getNumSynRule();j++)
  	  	{ if(Ag->getpLTMem()->getpSynRuleList(j)->getpCat(0)->getThemRole()==Ag->getpLTMem()->getpSynRuleList(j)->getpCat(1)->getThemRole())
  	  		{ switch(type)
  	  			{ case 1: printf("Speaker->Syn[%*d] has 2 cats having same themrole\n", widthSyn, j); break;	// speaker;
  	  			  case 2: printf("Listener->Syn[%*d] has 2 cats having same themrole\n", widthSyn, j); break;	// listener;
  	  			  case 3: printf("Neighbor->Syn[%*d] has 2 cats having same themrole\n", widthSyn, j); break;	// neighbor;
  	  			  default: break;
				}
			}
  	  	}
}

void CSystem::calUseOrder(int type, int meanIndex, int Agindex, CMeanUtter *meanutter, double **syn, int size11, int size12, double **Localsyn, int size21, int size22, double **OrdPro_Per, int size31, int size32, double **eachAgOrdPro_Per, int size41, int size42)
{ // test which order agent used to produce/comprehend; 0(SV), 1(VS), 2(SVO), 3(SOV), 4(OSV), 5(VSO), 6(VOS), 7(OVS);
  // type=1, production; 2, perception (potential Per and Per);
	assert((type==1)||(type==2)); assert((0<=Agindex)&&(Agindex<getNumAgent())); assert(meanutter!=NULL); assert(syn!=NULL); assert(OrdPro_Per!=NULL); assert(eachAgOrdPro_Per!=NULL);
	int i, j, k, OrdTyp1, OrdTyp2, **potOrdTyp=NULL;	// the order type used in real comprehension and in potential comprehensions; 
	int feedback; bool inBufSuc;
	bool same1, same2;	// check whether the current OrdTyp is same as previous;
	double *localstr=NULL, **LocOrd=NULL;	// check used local orders' strengths;
	
	// initialize localstr;
	localstr=new double [size21]; assert(localstr!=NULL);
	for(i=0;i<size21;i++)
		localstr[i]=0.0;
	OrdTyp1=OrdTyp2=-1; getpAgent(Agindex)->getReal_PotOrdTyp(getRecLocOrdNo_Str(), meanutter, 0, &OrdTyp1, &OrdTyp2, localstr, size21);
	if((OrdTyp1!=-1)&&(OrdTyp2!=-1))
		{ // two possible orders for production/real perception; 
		  if(type==1)
			{ // production; 
			  (syn[OrdTyp1][2])+=_Half; (syn[OrdTyp2][2])+=_Half;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][2])+=localstr[i];
			}
		  else if(type==2)
		  	{ // real perception; 
		  	  (syn[OrdTyp1][1])+=_Half; (syn[OrdTyp2][1])+=_Half;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][1])+=localstr[i];
			}
 		  (OrdPro_Per[meanIndex][OrdTyp1])+=_Half; (eachAgOrdPro_Per[Agindex][OrdTyp1])+=_Half;	// update OrdPro_Per and eachAgOrdPro_Per;
		  (OrdPro_Per[meanIndex][OrdTyp2])+=_Half; (eachAgOrdPro_Per[Agindex][OrdTyp2])+=_Half;	// update OrdPro_Per and eachAgOrdPro_Per;
		}
	else if((OrdTyp1!=-1)&&(OrdTyp2==-1))
		{ // one possible order for production/real perception;
		  if(type==1) 
			{ // production; 
			  (syn[OrdTyp1][2])++;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][2])+=localstr[i];
			}
		  else if(type==2) 
		  	{ // real perception; 
		  	  (syn[OrdTyp1][1])++;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][1])+=localstr[i];
			}	
		  (OrdPro_Per[meanIndex][OrdTyp1])++; (eachAgOrdPro_Per[Agindex][OrdTyp1])++;	// update synUR_Exp, OrdPro_Per and eachAgOrdPro_Per;
		}
  	if(type==2)
	  	{ // for listener, also test the potential comprehension;
	  	  if(getpAgent(Agindex)->getpIMMem()->getNumCombOption()==1)
	  	  	{ // no other way to comprehend; 
	  	  	  if((OrdTyp1!=-1)&&(OrdTyp2!=-1)) { (syn[OrdTyp1][0])++; (syn[OrdTyp2][0])++; }
			  else if((OrdTyp1!=-1)&&(OrdTyp2==-1)) (syn[OrdTyp1][0])++;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][0])+=localstr[i];
	  	  	}
		  else
		  	{ // first, update real comprehension;
		  	  if((OrdTyp1!=-1)&&(OrdTyp2!=-1)) { (syn[OrdTyp1][0])++; (syn[OrdTyp2][0])++; }
			  else if((OrdTyp1!=-1)&&(OrdTyp2==-1)) (syn[OrdTyp1][0])++;
			  for(i=0;i<size21;i++)
			  	(Localsyn[i][0])+=localstr[i];

			  // then, test other potential way  
		  	  // initialize potOrdTyp;
			  potOrdTyp=new int * [getpAgent(Agindex)->getpIMMem()->getNumCombOption()]; assert(potOrdTyp!=NULL);
			  for(i=0;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
			  	{ potOrdTyp[i]=new int [2]; assert(potOrdTyp[i]!=NULL);
				  for(j=0;j<2;j++)
				  	potOrdTyp[i][j]=-1;
			  	}
			  potOrdTyp[0][0]=OrdTyp1; potOrdTyp[0][1]=OrdTyp2;	// potOrdTyp[0] stores real perception's OrdTyp;
			  // initialize LocOrd;
			  LocOrd=new double * [getpAgent(Agindex)->getpIMMem()->getNumCombOption()]; assert(LocOrd!=NULL);
			  for(i=0;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
			  	{ LocOrd[i]=new double [size21]; assert(LocOrd[i]!=NULL);
			  	  for(j=0;j<size21;j++)
				  	LocOrd[i][j]=0.0;
			  	}
			  for(i=0;i<size21;i++)
			  	LocOrd[0][i]=localstr[i];	// LocOrd[0] stores real perception's local order strength;

			  for(i=1;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
		  		{ feedback=0; inBufSuc=0; getpAgent(Agindex)->setFeedBack(getpAgent(Agindex)->getpIMMem()->getpOptionComb(i)->m_dCombinStr, &feedback, &inBufSuc, 1);
			   	  if(feedback==1)
			   	  //if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(Agindex)->getpIMMem()->getpOptionComb(i)->m_pOptMeanUtter->getpMean()))) 
				    { getpAgent(Agindex)->getReal_PotOrdTyp(getRecLocOrdNo_Str(), meanutter, i, &(potOrdTyp[i][0]), &(potOrdTyp[i][1]), LocOrd[i], size21); }	// this comoprehension is a potential one;
				}
			  // update syn and Localsyn;
			  for(i=1;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
			  	{ if((potOrdTyp[i][0]!=-1)&&(potOrdTyp[i][1]!=-1)) 
			  	  	{ same1=0; same2=0;
			  	  	  for(j=0;j<i;j++)
			  			{ if((potOrdTyp[i][0]==potOrdTyp[j][0])||(potOrdTyp[i][0]==potOrdTyp[j][1])) same1=1;
						  if((potOrdTyp[i][1]==potOrdTyp[j][0])||(potOrdTyp[i][1]==potOrdTyp[j][1])) same2=1;
			  			}
					  if(same1==0) (syn[potOrdTyp[i][0]][0])++;
					  if(same2==0) (syn[potOrdTyp[i][1]][0])++;
			  		}
			  	  else if((potOrdTyp[i][0]!=-1)&&(potOrdTyp[i][1]==-1))
			   	  	{ same1=0;
				  	  for(j=0;j<i;j++)
			  			{ if((potOrdTyp[i][0]==potOrdTyp[j][0])||(potOrdTyp[i][0]==potOrdTyp[j][1])) same1=1;
				  	  	}
					  if(same1==0) (syn[potOrdTyp[i][0]][0])++;
			  	  	}
				  for(j=0;j<size21;j++)
				  	{ if(LocOrd[i][j]!=0.0)
				  		{ for(k=0;k<i;k++)
				  			{ if(LocOrd[k][j]!=0.0) break;
				  			}
				  		  if(k==i) (Localsyn[j][0])+=LocOrd[i][j];
				  		}
				  	}
			  	}
			  // delete potOrdTyp;
			  for(i=0;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
			  	{ delete [] potOrdTyp[i]; potOrdTyp[i]=NULL; }
			  delete [] potOrdTyp; potOrdTyp=NULL;
			  // delete LocOrd;
			  for(i=0;i<getpAgent(Agindex)->getpIMMem()->getNumCombOption();i++)
			  	{ delete [] LocOrd[i]; LocOrd[i]=NULL; }
			  delete [] LocOrd; LocOrd=NULL;
		  	}
	  	}
	delete [] localstr; localstr=NULL;	// delete localstr;
}

double CSystem::calAgUR(int agind)
{ // calculate inidividual agent's UR;
	assert((0<=agind)&&(agind<getNumAgent()));
	int i, j, speaker, listener, numcom;
	double agUR;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	speaker=listener=-1;
	if(getIndURCalMethod()==0) listener=agind;
	else if(getIndURCalMethod()==1) speaker=agind;
	agUR=0.0; numcom=0;
	for(i=0;i<getNumAgent();i++)
		{ if(i!=agind)
			{ numcom++; 
			  if(getIndURCalMethod()==0) speaker=i;
			  else if(getIndURCalMethod()==1) listener=i;
			  for(j=0;j<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();j++)
				{ meanutter->EmptypMeanUtter();
	  			  // speaker's part;
				  getpAgent(speaker)->ChoMeantoPro(meanutter, 1, j); getpAgent(speaker)->Production(meanutter, 1);	// speaker produces the utterance;
	  			  if(meanutter->getpUtter()->getElement(0)!=-1)
	  				{ // speaker successfully produces the utterance; 
		  			  // listener's part;
	  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, 1);	// listener comprehends the utterance;
	  	  			  // test whether it is correct;
	  	  			  if(feedback==1) agUR++;	// wrong answer is accepted;
					}
				}
			}
		}
	delete meanutter; meanutter=NULL;
	return agUR/(double)(numcom);
}

void CSystem::testURini(int NormOrTest, int lowBound, int upBound, double *URini)
{ // test URini (m_ppAgent <-> m_ppAgent1);
	assert(NormOrTest==1); 
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, k, speaker, listener, numcom;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*URini=0.0; numcom=0;
	if(getComMode()!=2)
		{ // random com and pair com;
  		  for(i=lowBound;i<upBound;i++)
  			for(j=lowBound;j<upBound;j++)
  				{ numcom++; speaker=i; listener=j;
  				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
					  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
					  if(meanutter->getpUtter()->getElement(0)!=-1)
			  			{ // speaker successfully produces the utterance; 
				  		  // listener's part;
			  	  		  feedback=0; inBufSuc=0; getpAgent1(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
			  	  		  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URini)++;
			  			}
					}
				  numcom++; speaker=j; listener=i;
				  for(k=0;k<getpAgent1(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
					  // speaker's part;
					  getpAgent1(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent1(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
					  if(meanutter->getpUtter()->getElement(0)!=-1)
			  			{ // speaker successfully produces the utterance; 
				  		  // listener's part;
			  	  		  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
			  	  		  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent1(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URini)++;
			  			}
					}
				  if(numcom%(int)(((2*Gsize*Gsize<=(int)_DrawStarFreq)?_DrawStarFreq:(2*Gsize*Gsize))/_DrawStarFreq)==0) printf(".");
				}
	  	  (*URini)/=(double)(numcom);
	  	}
	else
		{ // teacher-learner;
		  speaker=1; listener=0;
  		  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgent1(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URini)++;
				}
			}
		  for(k=0;k<getpAgent1(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgent1(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent1(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent1(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URini)++;
				}
			}
		  (*URini)/=_Twice;
  		}
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testURser(int NormOrTest, int lowBound, int upBound, double *URser)
{ // test URser (m_ppAgent <-> m_ppAgentN);
	assert(NormOrTest==1); 
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, k, speaker, listener, numcom;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*URser=0.0; numcom=0;
	if(getComMode()!=2)
		{ // random com and pair com;
  		  for(i=lowBound;i<upBound;i++)
  			for(j=lowBound;j<upBound;j++)
  				{ numcom++; speaker=i; listener=j;
  				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
					  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
					  if(meanutter->getpUtter()->getElement(0)!=-1)
			  			{ // speaker successfully produces the utterance; 
				  		  // listener's part;
			  	  		  feedback=0; inBufSuc=0; getpAgentN(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
			  	  		  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URser)++;
			  			}
					}
				  numcom++; speaker=j; listener=i;
				  for(k=0;k<getpAgentN(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
					  // speaker's part;
					  getpAgentN(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgentN(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
					  if(meanutter->getpUtter()->getElement(0)!=-1)
			  			{ // speaker successfully produces the utterance; 
				  		  // listener's part;
			  	  		  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
			  	  		  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgentN(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URser)++;
			  			}
					}
				  if(numcom%(int)(((2*Gsize*Gsize<=(int)_DrawStarFreq)?_DrawStarFreq:(2*Gsize*Gsize))/_DrawStarFreq)==0) printf(".");
				}
	  	  (*URser)/=(double)(numcom);
	  	}
	else
		{ // teacher-learner;
		  speaker=1; listener=0;
  		  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgentN(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URser)++;
				}
			}
		  for(k=0;k<getpAgentN(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgentN(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgentN(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgentN(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))) (*URser)++;
				}
			}
		  (*URser)/=_Twice;
  		}
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testUR_Exp_Amb(int NormOrTest, int lowBound, int upBound, double *eachUR, int size, double *UR, double *REall, double *Amb_a, double *Amb_b, double *Amb_c, double **syn, int size11, int size12, double **Localsyn, int size21, int size22, double **OrdPro, double **OrdPer, int size31, int size32, double **eachAgOrdPro, double **eachAgOrdPer, int size41, int size42)
{ // test eachUR, UR, REall, synUR, synExp, OrdPro, OrdPer, eachAgOrdPro, eachAgOrdPer;
	assert(NormOrTest==1); assert(eachUR!=NULL);
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, k, m, speaker, listener, numcom, numSucSet, sucInd;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*UR=0.0; *REall=0.0; *Amb_a=0.0; *Amb_b=0.0; *Amb_c=0.0; numcom=0;
	if(getComMode()!=2)
		{ // random com and pair com;
  		  for(i=lowBound;i<upBound;i++)
  			for(j=lowBound;j<upBound;j++)
  				{ if(i!=j)
  					{ numcom++; speaker=i; listener=j;
  					  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
						{ meanutter->EmptypMeanUtter();
						  // speaker's part;
						  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
						  if(meanutter->getpUtter()->getElement(0)!=-1)
			  				{ // speaker successfully produces the utterance; 
				  			  (*REall)++; calUseOrder(1, k, speaker, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPro, size31, size32, eachAgOrdPro, size41, size42);
							  // listener's part;
			  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
							  // test whether it is correct;
			  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
							 	{ (*UR)++; (eachUR[listener])++; calUseOrder(2, k, listener, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPer, size31, size32, eachAgOrdPer, size41, size42);
			  	  			  	}
							  if(getCalAmbiguity()==1)
							  	{ // test ambiguity;
						  	  	  if(feedback==1)
									{ if(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))
								  	  	{ // listener accurately comprehends the heard utterance; calculate Amb_a;
								  	  	  numSucSet=1;
										  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
										  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
										  		numSucSet++;
										  	}
										  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
										  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
										  	  if(numSucSet>2) (*Amb_a)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
										  	}
										  else { if(numSucSet>1) (*Amb_a)++; }
								  	  	}
									  else
									  	{ // listener inaccurately comprehends the heard utterance; further check whether the candidate rules can accurately comprehend the heard utterance;
									  	 for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
									  	 	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&(*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
									  	 		break;
									  	 	}
										 if(m==getpAgent(listener)->getpIMMem()->getNumCombOption())
										 	{ // all candidate rules cannot accurately comprehend the heard utterance; calculate Amb_b;
										 	  numSucSet=1;
										  	  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
											  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
										  			numSucSet++;
										  		}
										  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
											  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
											  	  if(numSucSet>2) (*Amb_b)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
											  	}
											  else { if(numSucSet>1) (*Amb_b)++; }
										 	}
										 else
										 	{ // one set of candidate rules can accurately comprehend the heard utterance; calculate Amb_c;
										 	  sucInd=m; numSucSet=1;
										  	  for(m=0;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
											  	{ if((m!=sucInd)&&(FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_pOptMeanUtter->getpMean())))
										  			numSucSet++;
										  		}
										  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_nNumLexRules==3)
											  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
											  	  if(numSucSet>2) (*Amb_c)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
											  	}
											  else { if(numSucSet>1) (*Amb_c)++; }
										 	}
									  	}
									}
							  	}
			  				}
						}
  					   if(numcom%(int)(((Gsize*(Gsize-1)<=(int)_DrawStarFreq)?_DrawStarFreq:(Gsize*(Gsize-1)))/_DrawStarFreq)==0) printf(".");
  					}
  				}
	  	  (*UR)/=(double)(numcom); (*REall)/=(double)(numcom); 
		  if(getCalAmbiguity()==1) { (*Amb_a)/=(double)(numcom); (*Amb_b)/=(double)(numcom); (*Amb_c)/=(double)(numcom); }
	  	  for(i=0;i<size;i++)
	  	  	(eachUR[i])/=(double)(size-1);
  		  for(i=0;i<size11;i++)
  		  	for(j=0;j<size12;j++)
  		  		(syn[i][j])/=(double)(numcom);
		  for(i=0;i<size21;i++)
		  	for(j=0;j<size22;j++)
		  		(Localsyn[i][j])/=(double)(numcom);
		  for(i=0;i<size31;i++)
			for(j=0;j<size32;j++)
  		  		{ (OrdPro[i][j])/=(double)(numcom); (OrdPer[i][j])/=(double)(numcom); }
		  for(i=0;i<size41;i++)
		  	for(j=0;j<size42;j++)
		  		{ (eachAgOrdPro[i][j])/=(double)(size41-1); (eachAgOrdPer[i][j])/=(double)(size41-1); }
		}
	else
		{ // teacher-learner;
		  speaker=1; listener=0;
  		  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  (*REall)++; calUseOrder(1, k, speaker, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPro, size31, size32, eachAgOrdPro, size41, size42);
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
				 	{ (*UR)++; (eachUR[listener])++; calUseOrder(2, k, listener, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPer, size31, size32, eachAgOrdPer, size41, size42);
	  			  	}
				}
			}
  		}
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testCrossUR_Exp_Amb(int NormOrTest, int lowBound1, int upBound1, int lowBound2, int upBound2, double *eachUR, int size, double *UR, double *REall, double *Amb_a, double *Amb_b, double *Amb_c, double **syn, int size11, int size12, double **Localsyn, int size21, int size22, double **OrdPro, double **OrdPer, int size31, int size32, double **eachAgOrdPro, double **eachAgOrdPer, int size41, int size42)
{ // test cross group eachUR, UR, REall, synUR, synExp, OrdPro, OrdPer, eachAgOrdPro, eachAgOrdPer;
	assert(NormOrTest==1); assert(eachUR!=NULL);
	assert((0<=lowBound1)&&(lowBound1<=getNumAgent())); assert((0<=upBound1)&&(upBound1<=getNumAgent())); assert(lowBound1<=upBound1);
	assert((0<=lowBound2)&&(lowBound2<=getNumAgent())); assert((0<=upBound2)&&(upBound2<=getNumAgent())); assert(lowBound2<=upBound2);
	int G1size=upBound1-lowBound1, G2size=upBound2-lowBound2;
	int i, j, k, m, speaker, listener, numcom, numSucSet, sucInd;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*UR=0.0; *REall=0.0; *Amb_a=0.0; *Amb_b=0.0; *Amb_c=0.0; numcom=0;
	// random com and pair com;
  	for(i=lowBound1;i<upBound1;i++)
  		for(j=lowBound2;j<upBound2;j++)
  			{ if(i!=j)
  				{ numcom++; speaker=i; listener=j;
  				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
		  			  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
		  			  if(meanutter->getpUtter()->getElement(0)!=-1)
		  				{ // speaker successfully produces the utterance; 
			  			  (*REall)++; calUseOrder(1, k, speaker, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPro, size31, size32, eachAgOrdPro, size41, size42);
		  	  			  // listener's part;
		  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
		  	  			  // test whether it is correct;
		  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
						 	{ (*UR)++; (eachUR[listener])++; calUseOrder(2, k, listener, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPer, size31, size32, eachAgOrdPer, size41, size42);
		  	  			  	}
						  if(getCalAmbiguity()==1)
						  	{ // test ambiguity;
						  	  if(feedback==1)
								{ if(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))
							  	  	{ // listener accurately comprehends the heard utterance; calculate Amb_a;
							  	  	  numSucSet=1;
									  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
									  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
									  		numSucSet++;
									  	}
									  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
									  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
									  	  if(numSucSet>2) (*Amb_a)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
									  	}
									  else { if(numSucSet>1) (*Amb_a)++; }
							  	  	}
								  else
								  	{ // listener inaccurately comprehends the heard utterance; further check whether the candidate rules can accurately comprehend the heard utterance;
								  	 for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
								  	 	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&(*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
								  	 		break;
								  	 	}
									 if(m==getpAgent(listener)->getpIMMem()->getNumCombOption())
									 	{ // all candidate rules cannot accurately comprehend the heard utterance; calculate Amb_b;
									 	  numSucSet=1;
									  	  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
										  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
									  			numSucSet++;
									  		}
									  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
										  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
										  	  if(numSucSet>2) (*Amb_b)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
										  	}
										  else { if(numSucSet>1) (*Amb_b)++; }
									 	}
									 else
									 	{ // one set of candidate rules can accurately comprehend the heard utterance; calculate Amb_c;
									 	  sucInd=m; numSucSet=1;
									  	  for(m=0;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
										  	{ if((m!=sucInd)&&(FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_pOptMeanUtter->getpMean())))
									  			numSucSet++;
									  		}
									  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_nNumLexRules==3)
										  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
										  	  if(numSucSet>2) (*Amb_c)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
										  	}
										  else { if(numSucSet>1) (*Amb_c)++; }
									 	}
								  	}
								}
						  	}
		  				}
					}
				   numcom++; speaker=j; listener=i;
  				   for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
		  			  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
		  			  if(meanutter->getpUtter()->getElement(0)!=-1)
		  				{ // speaker successfully produces the utterance; 
			  			  (*REall)++; calUseOrder(1, k, speaker, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPro, size31, size32, eachAgOrdPro, size41, size42);
		  	  			  // listener's part;
		  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
		  	  			  // test whether it is correct;
		  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
						 	{ (*UR)++; (eachUR[listener])++; calUseOrder(2, k, listener, meanutter, syn, size11, size12, Localsyn, size21, size22, OrdPer, size31, size32, eachAgOrdPer, size41, size42);
		  	  			  	}
						  if(getCalAmbiguity()==1)
						  	{ // test ambiguity;
						  	  if(feedback==1)
								{ if(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean()))
							  	  	{ // listener accurately comprehends the heard utterance; calculate Amb_a;
							  	  	  numSucSet=1;
									  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
									  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
									  		numSucSet++;
									  	}
									  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
									  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
									  	  if(numSucSet>2) (*Amb_a)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
									  	}
									  else { if(numSucSet>1) (*Amb_a)++; }
							  	  	}
								  else
								  	{ // listener inaccurately comprehends the heard utterance; further check whether the candidate rules can accurately comprehend the heard utterance;
								  	 for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
								  	 	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&(*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
								  	 		break;
								  	 	}
									 if(m==getpAgent(listener)->getpIMMem()->getNumCombOption())
									 	{ // all candidate rules cannot accurately comprehend the heard utterance; calculate Amb_b;
									 	  numSucSet=1;
									  	  for(m=1;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
										  	{ if((FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(meanutter->getpMean())))
									  			numSucSet++;
									  		}
									  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(0)->m_nNumLexRules==3)
										  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
										  	  if(numSucSet>2) (*Amb_b)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
										  	}
										  else { if(numSucSet>1) (*Amb_b)++; }
									 	}
									 else
									 	{ // one set of candidate rules can accurately comprehend the heard utterance; calculate Amb_c;
									 	  sucInd=m; numSucSet=1;
									  	  for(m=0;m<getpAgent(listener)->getpIMMem()->getNumCombOption();m++)
										  	{ if((m!=sucInd)&&(FLOAT_BG_EQ(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_dCombinStr, getpAgent(listener)->getHardFeedback()))&&((*(getpAgent(listener)->getpIMMem()->getpOptionComb(m)->m_pOptMeanUtter->getpMean()))!=*(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_pOptMeanUtter->getpMean())))
									  			numSucSet++;
									  		}
									  	  if(getpAgent(listener)->getpIMMem()->getpOptionComb(sucInd)->m_nNumLexRules==3)
										  	{ // 3 word rules for comprehending a "Predicate<Agent, Patient>" meaning;
										  	  if(numSucSet>2) (*Amb_c)++;	// why >2? because when comprehending a "Predicate<Agent, Patient>" meaning using 3 word rules, since a noun can be either S or O, there will be 2 candidate comprehension as default; 
										  	}
										  else { if(numSucSet>1) (*Amb_c)++; }
									 	}
								  	}
								}
						  	}
		  				}
					}
  				   if(numcom%(int)(((2*G1size*G2size)<=(int)_DrawStarFreq)?_DrawStarFreq:(2*G1size*G2size)/_DrawStarFreq)==0) printf(".");
  				}
  			}
	(*UR)/=(double)(numcom); (*REall)/=(double)(numcom); 
	if(getCalAmbiguity()==1) { (*Amb_a)/=(double)(numcom); (*Amb_b)/=(double)(numcom); (*Amb_c)/=(double)(numcom); }
	for(i=0;i<size;i++)
	  	(eachUR[i])/=(double)(size-1);
  	for(i=0;i<size11;i++)
  	  	for(j=0;j<size12;j++)
  	  		(syn[i][j])/=(double)(numcom);
	for(i=0;i<size21;i++)
	  	for(j=0;j<size22;j++)
	  		(Localsyn[i][j])/=(double)(numcom);
	for(i=0;i<size31;i++)
		for(j=0;j<size32;j++)
  	  		{ (OrdPro[i][j])/=(double)(numcom); (OrdPer[i][j])/=(double)(numcom); }
	for(i=0;i<size41;i++)
	  	for(j=0;j<size42;j++)
	  		{ (eachAgOrdPro[i][j])/=(double)(size41-1); (eachAgOrdPer[i][j])/=(double)(size41-1); }
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testDisp(int NormOrTest, int lowBound, int upBound, double *displacement, int size, double *avgDisp)
{ // test displacement;
	assert(NormOrTest==2); assert(displacement!=NULL);
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, k, speaker, listener, numcom;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*avgDisp=0.0; numcom=0;
	if(getComMode()!=2)
		{ // random com and pair com;
		  for(i=lowBound;i<upBound;i++)
  			for(j=lowBound;j<upBound;j++)
  				{ if(i!=j)
  					{ numcom++; speaker=i; listener=j;
  					  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
						{ meanutter->EmptypMeanUtter();
			  			  // speaker's part;
						  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  			  if(meanutter->getpUtter()->getElement(0)!=-1)
			  				{ // speaker successfully produces the utterance; 
				  			  // listener's part;
							  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
							  // test whether it is correct;
			  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
							 	{ (*avgDisp)++; (displacement[listener])++; }
			  				}						
						  }
  					   if(numcom%(int)(((Gsize*(Gsize-1)<=(int)_DrawStarFreq)?_DrawStarFreq:(Gsize*(Gsize-1)))/_DrawStarFreq)==0) printf(".");
  					}
  				}
	  	  (*avgDisp)/=(double)(numcom);
	  	  for(i=lowBound;i<upBound;i++)
	  	  	(displacement[i])/=(double)(upBound-lowBound-1);
		}
	else
		{ // teacher-learner;
		  speaker=1; listener=0;
  		  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
			{ meanutter->EmptypMeanUtter();
			  // speaker's part;
			  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  if(meanutter->getpUtter()->getElement(0)!=-1)
				{ // speaker successfully produces the utterance; 
				  // listener's part;
				  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
				  // test whether it is correct;
				  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
				 	{ (*avgDisp)++; (displacement[listener])++; }
				}
			}
		}
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testCrossDisp(int NormOrTest, int lowBound1, int upBound1, int lowBound2, int upBound2, double *displacement, int size, double *avgDisp)
{ // test cross group displacement;
	assert(NormOrTest==2); assert(displacement!=NULL);
	assert((0<=lowBound1)&&(lowBound1<=getNumAgent())); assert((0<=upBound1)&&(upBound1<=getNumAgent())); assert(lowBound1<=upBound1);
	assert((0<=lowBound2)&&(lowBound2<=getNumAgent())); assert((0<=upBound2)&&(upBound2<=getNumAgent())); assert(lowBound2<=upBound2);
	int G1size=upBound1-lowBound1, G2size=upBound2-lowBound2;
	int i, j, k, speaker, listener, numcom;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	*avgDisp=0.0; numcom=0;
	// random com and pair com;
	for(i=lowBound1;i<upBound1;i++)
  		for(j=lowBound2;j<upBound2;j++)
  			{ if(i!=j)
  				{ numcom++; speaker=i; listener=j;
  				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
		  			  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
		  			  if(meanutter->getpUtter()->getElement(0)!=-1)
		  				{ // speaker successfully produces the utterance; 
			  			  // listener's part;
						  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
		  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
						 	{ (*avgDisp)++; (displacement[listener])++; }
		  				}
					}
				  numcom++; speaker=j; listener=i;
  				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
		  			  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
		  			  if(meanutter->getpUtter()->getElement(0)!=-1)
		  				{ // speaker successfully produces the utterance; 
			  			  // listener's part;
						  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
						  // test whether it is correct;
		  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
						 	{ (*avgDisp)++; (displacement[listener])++; }
		  				}
					}
  				   if(numcom%(int)(((2*G1size*G2size)<=(int)_DrawStarFreq)?_DrawStarFreq:(2*G1size*G2size)/_DrawStarFreq)==0) printf(".");
  				}
  			}
	(*avgDisp)/=(double)(numcom);
	for(i=lowBound1;i<upBound1;i++)
	  	(displacement[i])/=(double)(upBound1-lowBound1-1);
	for(i=lowBound2;i<upBound2;i++)
		(displacement[i])/=(double)(upBound2-lowBound2-1);
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::testHolistCompExp(int lowBound, int upBound, double *REholist, double *REcomp)
{ // test holistic rule and compositional rule's expressivity;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, learner;
	CMeanUtter *MU=new CMeanUtter; assert(MU!=NULL);
	
	*REholist=0.0; *REcomp=0.0;
	if(getComMode()!=2)
		{ // random com and pair com; 
		  for(i=lowBound;i<upBound;i++)
			{ // calculate REholist;
			  for(j=0;j<getpAgent(i)->getpSemSpace()->getNumIntgMean();j++)
			  	{ MU->EmptypMean(); MU->setpMean(getpAgent(i)->getpSemSpace()->getpSemItem(j)->getpIntgMean());
			  	  if(j<getpAgent(i)->getpSemSpace()->getNumMean1()) { if(getpAgent(i)->getpLTMem()->ChkMeanType1(3, MU, getpAgent(i)->getpSemSpace())==1) (*REholist)++; }
				  else { if(getpAgent(i)->getpLTMem()->ChkMeanType2(3, MU, getpAgent(i)->getpSemSpace())==1) (*REholist)++; }
			  	}
			  // calculate REcomp;
			  for(j=0;j<getpAgent(i)->getpSemSpace()->getNumIntgMean();j++)
			  	{ MU->EmptypMean(); MU->setpMean(getpAgent(i)->getpSemSpace()->getpSemItem(j)->getpIntgMean());
			  	  if(j<getpAgent(i)->getpSemSpace()->getNumMean1()) { if(getpAgent(i)->getpLTMem()->ChkMeanType1(2, MU, getpAgent(i)->getpSemSpace())==1) (*REcomp)++; }
				  else { if(getpAgent(i)->getpLTMem()->ChkMeanType2(2, MU, getpAgent(i)->getpSemSpace())==1) (*REcomp)++; }
			  	}
			}
		  (*REholist)/=(double)(Gsize); (*REcomp)/=(double)(Gsize);
		}
	else
		{ // teacher-learner;
		  learner=0; 
		  // calculate m_ppAgent[leaner]'s REholist;
		  for(j=0;j<getpAgent(learner)->getpSemSpace()->getNumIntgMean();j++)
		  	{ MU->EmptypMean(); MU->setpMean(getpAgent(learner)->getpSemSpace()->getpSemItem(j)->getpIntgMean());
			  if(j<getpAgent(learner)->getpSemSpace()->getNumMean1()) { if(getpAgent(learner)->getpLTMem()->ChkMeanType1(3, MU, getpAgent(1)->getpSemSpace())==1) (*REholist)++; }
			  else { if(getpAgent(learner)->getpLTMem()->ChkMeanType2(3, MU, getpAgent(learner)->getpSemSpace())==1) (*REholist)++; }
		  	}
		  // calculate m_ppAgent[learner]'s REcomp;
		  for(j=0;j<getpAgent(learner)->getpSemSpace()->getNumIntgMean();j++)
		  	{ MU->EmptypMean(); MU->setpMean(getpAgent(learner)->getpSemSpace()->getpSemItem(j)->getpIntgMean());
			  if(j<getpAgent(learner)->getpSemSpace()->getNumMean1()) { if(getpAgent(learner)->getpLTMem()->ChkMeanType1(2, MU, getpAgent(1)->getpSemSpace())==1) (*REcomp)++; }
			  else { if(getpAgent(learner)->getpLTMem()->ChkMeanType2(2, MU, getpAgent(learner)->getpSemSpace())==1) (*REcomp)++; }
		  	}
		}
	delete MU; MU=NULL;	// delete MU;
}

void CSystem::testAvgLexCatSyn(int lowBound, int upBound, double *AvgHolistLex, double *AvgCompLex, double *AvgCat, double *AvgSyn, double *AvgLocSyn, double *AvgSnum, double *AvgVnum, double *AvgOnum, double *AvgSsize, double *AvgVsize, double *AvgOsize, double **catSize)
{ // test average lexical rules, categories and syntactic rules, the numbers, average and biggest sizes of Subject, Verb and Object categories;;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, learner;
	CCat *cat1=NULL, *cat2=NULL;
	int numS, numV, numO;
	double sizeAvgS, sizeAvgV, sizeAvgO, sizeBigS, sizeBigV, sizeBigO;
	*AvgHolistLex=0.0; *AvgCompLex=0.0; *AvgCat=0.0; *AvgSyn=0.0; *AvgLocSyn=0.0; *AvgSnum=0.0; *AvgVnum=0.0; *AvgOnum=0.0; *AvgSsize=0.0; *AvgVsize=0.0; *AvgOsize=0.0;
	
	if(getComMode()!=2)
		{ // random com and pair com;
		  // test AvgLex, AvgCat, AvgSyn;
		  for(i=lowBound;i<upBound;i++)
			{ for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
		  		{ if(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexTyp()==0) (*AvgHolistLex)++;
		  		  else (*AvgCompLex)++;
		  		}
		  	  (*AvgCat)+=(double)(getpAgent(i)->getpLTMem()->getNumCat()); (*AvgSyn)+=(double)(getpAgent(i)->getpLTMem()->getNumSynRule()); 
			  for(j=0;j<getpAgent(i)->getpLTMem()->getNumSynRule();j++)
			  	{ cat1=getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(0); cat2=getpAgent(i)->getpLTMem()->getpSynRuleList(j)->getpCat(1);
			 	  if(((cat1->getThemRole()==1)||(cat1->getThemRole()==2)||(cat1->getThemRole()==3))&&((cat2->getThemRole()==1)||(cat2->getThemRole()==2)||(cat2->getThemRole()==3))) (*AvgLocSyn)++;
				   cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
			  	}
		  	}
		  (*AvgHolistLex)/=(double)(Gsize); (*AvgCompLex)/=(double)(Gsize); (*AvgCat)/=(double)(Gsize); (*AvgSyn)/=(double)(Gsize); (*AvgLocSyn)/=(double)(Gsize);
		  // test category information;
		  for(i=lowBound;i<upBound;i++)
		  	{ numS=0; numV=0; numO=0; 
		  	  sizeAvgS=0.0; sizeAvgV=0.0; sizeAvgO=0.0; sizeBigS=0.0; sizeBigV=0.0; sizeBigO=0.0;
		  	  for(j=0;j<getpAgent(i)->getpLTMem()->getNumCat();j++)
		  	  	{ switch(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole())
		  			{ case 1: // Subject category;
		  					numS+=1; sizeAvgS+=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
							if(FLOAT_SM_EQ(sizeBigS, (double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum()))) sizeBigS=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
		  					break;
					  case 2: // Verb category;
					  		numV+=1; sizeAvgV+=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
		  					if(FLOAT_SM_EQ(sizeBigV, (double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum()))) sizeBigV=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
		  					break;
					  case 3: // Object category;
					  		numO+=1; sizeAvgO+=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
		  					if(FLOAT_SM_EQ(sizeBigO, (double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum()))) sizeBigO=(double)(getpAgent(i)->getpLTMem()->getpCatList(j)->getLexNum());
		  					break;
					  default: break;	
		  			}
		  	  	}
			  if(numS!=0) sizeAvgS/=(double)(numS); 
			  if(numV!=0) sizeAvgV/=(double)(numV); 
			  if(numO!=0) sizeAvgO/=(double)(numO);
			  (*AvgSnum)+=(double)(numS); (*AvgVnum)+=(double)(numV); (*AvgOnum)+=(double)(numO); 
			  (*AvgSsize)+=sizeAvgS; (*AvgVsize)+=sizeAvgV; (*AvgOsize)+=sizeAvgO;
			  // store results;
			  catSize[i][0]=(double)(numS); catSize[i][1]=sizeAvgS; catSize[i][2]=sizeBigS;
		  	  catSize[i][3]=(double)(numV); catSize[i][4]=sizeAvgV; catSize[i][5]=sizeBigV;
		  	  catSize[i][6]=(double)(numO); catSize[i][7]=sizeAvgO; catSize[i][8]=sizeBigO;
		  	}
		  (*AvgSnum)/=(double)(Gsize); (*AvgVnum)/=(double)(Gsize); (*AvgOnum)/=(double)(Gsize); (*AvgSsize)/=(double)(Gsize); (*AvgVsize)/=(double)(Gsize); (*AvgOsize)/=(double)(Gsize);
		}
	else
		{ // teacher-learner;
		  // test AvgHolistLex, AvgCompLex, AvgCat, AvgSyn;
		  learner=0;
		  for(i=0;i<getpAgent(learner)->getpLTMem()->getNumLexRule();i++)
		  	{ if(getpAgent(learner)->getpLTMem()->getpLexRuleList(i)->getLexTyp()==0) (*AvgHolistLex)++;
		  	  else (*AvgCompLex)++;
		  	}
		  (*AvgCat)+=(double)(getpAgent(learner)->getpLTMem()->getNumCat()); (*AvgSyn)+=(double)(getpAgent(learner)->getpLTMem()->getNumSynRule());
		  for(i=0;i<getpAgent(learner)->getpLTMem()->getNumSynRule();i++)
		  	{ cat1=getpAgent(learner)->getpLTMem()->getpSynRuleList(i)->getpCat(0); cat2=getpAgent(learner)->getpLTMem()->getpSynRuleList(i)->getpCat(1);
		 	  if(((cat1->getThemRole()==1)||(cat1->getThemRole()==2)||(cat1->getThemRole()==3))&&((cat2->getThemRole()==1)||(cat2->getThemRole()==2)||(cat2->getThemRole()==3))) (*AvgLocSyn)++;
			  cat1=NULL; cat2=NULL;	// recollect cat1, cat2;
		  	}
		  // test category information;
		  numS=0; numV=0; numO=0; 
		  sizeAvgS=0.0; sizeAvgV=0.0; sizeAvgO=0.0; sizeBigS=0.0; sizeBigV=0.0; sizeBigO=0.0; 
		  for(i=0;i<getpAgent(learner)->getpLTMem()->getNumCat();i++)
		  	{ switch(getpAgent(learner)->getpLTMem()->getpCatList(i)->getThemRole())
		  		{ case 1: // Subject category;
		  				numS+=1; sizeAvgS+=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
						if(FLOAT_SM_EQ(sizeBigS, (double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum()))) sizeBigS=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
		  				break;
				  case 2: // Verb category;
				  		numV+=1; sizeAvgV+=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
		  				if(FLOAT_SM_EQ(sizeBigV, (double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum()))) sizeBigV=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
		  				break;
				  case 3: // Object category;
				  		numO+=1; sizeAvgO+=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
		  				if(FLOAT_SM_EQ(sizeBigO, (double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum()))) sizeBigO=(double)(getpAgent(learner)->getpLTMem()->getpCatList(i)->getLexNum());
		  				break;
				  default: break;	
		  		}
		  	}
		  if(numS!=0) sizeAvgS/=(double)(numS); 
		  if(numV!=0) sizeAvgV/=(double)(numV); 
		  if(numO!=0) sizeAvgO/=(double)(numO);
		  // store results;
		  catSize[learner][0]=(double)(numS); catSize[learner][1]=sizeAvgS; catSize[learner][2]=sizeBigS;
		  catSize[learner][3]=(double)(numV); catSize[learner][4]=sizeAvgV; catSize[learner][5]=sizeBigV;
		  catSize[learner][6]=(double)(numO); catSize[learner][7]=sizeAvgO; catSize[learner][8]=sizeBigO;
		  *AvgSnum=(double)(numS); *AvgVnum=(double)(numV); *AvgOnum=(double)(numO); *AvgSsize=sizeAvgS; *AvgVsize=sizeAvgV; *AvgOsize=sizeAvgO;
		}
}

void CSystem::updComLex(CLexRule *lex, CLexRule **&comLex, double avgstr, double *&comLexAvgStr, int *numcomLex)
{ // update lex into comLex;
	assert(lex!=NULL);
	int i;
	CLexRule **newcomLex=NULL;
	double *newcomLexAvgStr=NULL;
	int numnewcomLex;
	
	if(*numcomLex==0)
		{ (*numcomLex)++;
		  comLex=new CLexRule * [*numcomLex]; assert(comLex!=NULL);
		  comLex[0]=lex;
		  comLexAvgStr=new double [*numcomLex]; assert(comLexAvgStr!=NULL);
		  comLexAvgStr[0]=avgstr;
		}
	else
		{ // no check whether lex is already in comLex;
		  // update comLex;
		  numnewcomLex=(*numcomLex)+1;
		  newcomLex=new CLexRule * [numnewcomLex]; assert(newcomLex!=NULL);
		  for(i=0;i<numnewcomLex;i++)
		  	newcomLex[i]=NULL;
		  for(i=0;i<numnewcomLex-1;i++)
		  	newcomLex[i]=comLex[i];
		  newcomLex[numnewcomLex-1]=lex;
		  // delete original comLex;
		  delete [] comLex; comLex=NULL;
		  *numcomLex=0;
		  // copy newcomLex to comLex;
		  *numcomLex=numnewcomLex; comLex=newcomLex;
		  newcomLex=NULL;	// recollect newcomLex;
		  // update comLexAvgStr;
		  newcomLexAvgStr=new double [numnewcomLex]; assert(newcomLexAvgStr!=NULL);
		  for(i=0;i<numnewcomLex-1;i++)
		  	newcomLexAvgStr[i]=comLexAvgStr[i];
		  newcomLexAvgStr[numnewcomLex-1]=avgstr;
		  // delete original comLexAvgStr;
		  delete [] comLexAvgStr; comLexAvgStr=NULL;
		  // copy newcomLexAvgStr to comLexAvgStr;
		  comLexAvgStr=newcomLexAvgStr;
		  newcomLexAvgStr=NULL;	// recollect newcomLexAvg;
		}
}

void CSystem::testComLex(int lowBound, int upBound, CLexRule **&comLex, double *&comLexAvgStr, int *numcomLex, int *numcomHolist, int *numcomComp)
{ // test common lexical rules;
	assert((0<=lowBound)&&(lowBound<=getNumAgent())); assert((0<=upBound)&&(upBound<=getNumAgent())); assert(lowBound<=upBound);
	int Gsize=upBound-lowBound;
	int i, j, k;
	CLexRule *lex=NULL;
	double avgstr;
	bool samelex;

	if(getpAgent(lowBound)->getpLTMem()->getNumLexRule()!=0)
		{ // first, check common holistic/phrase rules; 
		  for(i=0;i<getpAgent(lowBound)->getpLTMem()->getNumLexRule();i++)
			{ if((getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i)->getLexTyp()==0)||((3<=getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i)->getLexTyp())&&(getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i)->getLexTyp()<=8)))
			  	{ lex=getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i); avgstr=lex->getLexStr();
			  	  // check whether all agents share same lex;
			  	  samelex=1;
				  for(j=lowBound+1;j<upBound;j++)
				  	{ for(k=0;k<getpAgent(j)->getpLTMem()->getNumLexRule();k++)
				  		{ if(*(getpAgent(j)->getpLTMem()->getpLexRuleList(k)->getpMeanUtter())==*(lex->getpMeanUtter()))
							break;
				  		}
				  	  if(k==getpAgent(j)->getpLTMem()->getNumLexRule()) samelex=0;	// not same!
				  	  if(samelex==1) 
				  	  	{ avgstr+=getpAgent(j)->getpLTMem()->getpLexRuleList(k)->getLexStr(); 
				  	  	  continue;
				  	  	}
				  	  else break;
				  	}
				  if(samelex==1) 
				  	{ avgstr/=(double)(Gsize); updComLex(lex, comLex, avgstr, comLexAvgStr, numcomLex);
				  	  (*numcomHolist)++;
				  	}
				  lex=NULL; avgstr=0.0;
				}
		  	}
		  // second, check common compositional rules;
		  for(i=0;i<getpAgent(lowBound)->getpLTMem()->getNumLexRule();i++)
		  	{ if((getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i)->getLexTyp()==1)||(getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i)->getLexTyp()==2))
		  		{ lex=getpAgent(lowBound)->getpLTMem()->getpLexRuleList(i); avgstr=lex->getLexStr();
			  	  // check whether all agents share same lex;
			  	  samelex=1;
				  for(j=lowBound+1;j<upBound;j++)
				  	{ for(k=0;k<getpAgent(j)->getpLTMem()->getNumLexRule();k++)
				  		{ if(*(getpAgent(j)->getpLTMem()->getpLexRuleList(k)->getpMeanUtter())==*(lex->getpMeanUtter()))
							break;
				  		}
				  	  if(k==getpAgent(j)->getpLTMem()->getNumLexRule()) samelex=0;	// not same!
				  	  if(samelex==1) 
				  	  	{ avgstr+=getpAgent(j)->getpLTMem()->getpLexRuleList(k)->getLexStr(); 
				  	  	  continue;
				  	  	}
				  	  else break;
				  	}
				  if(samelex==1) 
				  	{ avgstr/=(double)(Gsize); updComLex(lex, comLex, avgstr, comLexAvgStr, numcomLex);
					  (*numcomComp)++;
				  	}
				  lex=NULL; avgstr=0.0;
		  		}
		  	}
		}	
}

void CSystem::testHomo(CLexRule **comLex, int numcomLex, int numcomHolist, int numcomComp, int *numHomoN, int *numHomoV, int *numHomoNV)
{ // test numHomoN, numHomoV, numHomoNV based on comLex;
	assert((numHomoN!=NULL)&&(numHomoV!=NULL)&&(numHomoNV!=NULL));
	assert(((numcomLex==0)&&(comLex==NULL))||((numcomLex!=0)&&(comLex!=NULL)));
	int i, j;
	CLexRule *curLex=NULL;
	
	*numHomoN=0; *numHomoV=0; *numHomoNV=0;
	for(i=numcomHolist;i<numcomLex;i++)
		{ curLex=comLex[i];
		  if(curLex->getLexTyp()==1)
			{ // it is a noun, search the other noun rules to calculate numHomoN;
			  for(j=i+1;j<numcomLex;j++)
			  	{ if((comLex[j]->getLexTyp()==1)&&(*(curLex->getpMeanUtter()->getpMean())!=*(comLex[j]->getpMeanUtter()->getpMean()))&&(*(curLex->getpMeanUtter()->getpUtter())==*(comLex[j]->getpMeanUtter()->getpUtter())))
			  		(*numHomoN)++;
			  	}
			  // search other verb rules to calculate numHomoNV;
			  for(j=i+1;j<numcomLex;j++)
			  	{ if((comLex[j]->getLexTyp()==2)&&(*(curLex->getpMeanUtter()->getpUtter())==*(comLex[j]->getpMeanUtter()->getpUtter())))
			  		(*numHomoNV)++;
			  	}
			}
		  else if(curLex->getLexTyp()==2)
		  	{ // it is a verb, search the other verb rules to calculate numHomoV;
			  for(j=i+1;j<numcomLex;j++)
			  	{ if((comLex[j]->getLexTyp()==2)&&(*(curLex->getpMeanUtter()->getpMean())!=*(comLex[j]->getpMeanUtter()->getpMean()))&&(*(curLex->getpMeanUtter()->getpUtter())==*(comLex[j]->getpMeanUtter()->getpUtter())))
					(*numHomoV)++;
			  	}
			  // search other noun rules to calculate numHomoNV;
			  for(j=i+1;j<numcomLex;j++)
			  	{ if((comLex[j]->getLexTyp()==1)&&(*(curLex->getpMeanUtter()->getpUtter())==*(comLex[j]->getpMeanUtter()->getpUtter())))
			  		(*numHomoNV)++;
			  	}
		  	}
		  curLex=NULL;	// recollect curLex;
		}
}

bool CSystem::chkDist(CAgent *Ag1, CAgent *Ag2)
{ // check whether 2 agents' distance is within the block distance;
	assert((Ag1!=NULL)&&(Ag2!=NULL));
	int distX=abs(Ag1->getLocX()-Ag2->getLocX()); if(distX>(int)(getWorldX()/_Twice)) distX=getWorldX()-distX;
	int distY=abs(Ag1->getLocY()-Ag2->getLocY()); if(distY>(int)(getWorldY()/_Twice)) distY=getWorldY()-distY;
	if((distX<=getBlockDist())&&(distY<=getBlockDist())) return 1;
	else return 0;
}

double CSystem::calDist(CAgent *Ag1, CAgent *Ag2)
{ // calculate the distance of two agents;
	assert((Ag1!=NULL)&&(Ag2!=NULL));
	int distX=abs(Ag1->getLocX()-Ag2->getLocX()); if(distX>(int)(getWorldX()/_Twice)) distX=getWorldX()-distX;
	int distY=abs(Ag1->getLocY()-Ag2->getLocY()); if(distY>(int)(getWorldY()/_Twice)) distY=getWorldY()-distY;
	return sqrt((double)(distX*distX+distY*distY));
}

void CSystem::testNeighborUR_Size(int NormOrTest, double *AdjDist, int sizeAdjDist, double *neighborUR, int *neighborSize, CAgent ***Neighbor, int **NeighborInd, int size)
{ // test neighborUR and neighborSize;
	assert(NormOrTest==1); assert(AdjDist!=NULL); assert((neighborUR!=NULL)&&(neighborSize!=NULL)&&(Neighbor!=NULL)&&(NeighborInd!=NULL));
	int i, j, k, speaker, listener;
	int *numcom=NULL;	// store each agent's number of com in which this agent is the listener;
	int feedback; bool inBufSuc;
	CAgent **AgiNeighbor=NULL;	// each agent's neighbors;
	int *AgiNeighborInd=NULL;	// each agent's neighbors' index;	

	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;
	numcom=new int [size]; assert(numcom!=NULL);
	for(i=0;i<size;i++)
		numcom[i]=0;

	for(i=0;i<size;i++)
		{ neighborSize[i]=1; neighborUR[i]=0.0; }	// neighborSize include oneself;
	
	// calculate neighborUR and neighborSize; 
	for(i=0;i<size;i++)
		{ for(j=0;j<size;j++)
			{ if(j>i)
		  		{ //if(FLOAT_EQ(AdjDist[(getNumAgent()-1)*i-i*(i+1)/2+j-1], 1.0))
		  		  if(FLOAT_SM_EQ(AdjDist[(getNumAgent()-1)*i-i*(i+1)/2+j-1], sqrt(_Twice)*getBlockDist()))
 					{ speaker=j; listener=i; 
				  	  updNeighbor(getpAgent(speaker), speaker, AgiNeighbor, AgiNeighborInd, &neighborSize[listener]);	// update speaker into listener's neighbor;
					  (numcom[listener])++; 
  					  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
  					  	{ meanutter->EmptypMeanUtter();
			  			  // speaker's part;
						  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  			  if(meanutter->getpUtter()->getElement(0)!=-1)
			  				{ // speaker successfully produces the utterance; 
				  			  // listener's part;
			  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
			  	  			  // test whether it is correct;
			  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
							 	(neighborUR[listener])++;
			  				}
						}
  					}
				}			
			  else if(j<i)
			  	{ //if(FLOAT_EQ(AdjDist[(getNumAgent()-1)*j-j*(j+1)/2+i-1], 1.0))
		  		  if(FLOAT_SM_EQ(AdjDist[(getNumAgent()-1)*j-j*(j+1)/2+i-1], sqrt(_Twice)*getBlockDist()))
 					{ speaker=j; listener=i; 
				  	  updNeighbor(getpAgent(speaker), speaker, AgiNeighbor, AgiNeighborInd, &neighborSize[listener]);	// update speaker into listener's neighbor;
					  (numcom[listener])++; 
  					  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
  					  	{ meanutter->EmptypMeanUtter();
			  			  // speaker's part;
						  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
			  			  if(meanutter->getpUtter()->getElement(0)!=-1)
			  				{ // speaker successfully produces the utterance; 
				  			  // listener's part;
			  	  			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
			  	  			  // test whether it is correct;
			  	  			  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
							 	(neighborUR[listener])++;
			  				}
						}
  					}
				}			  
			}
		  NeighborInd[i]=AgiNeighborInd; AgiNeighborInd=NULL;
		  Neighbor[i]=AgiNeighbor; AgiNeighbor=NULL;
		  if(i%(int)((getNumAgent()<=(int)_DrawStarFreq)?_DrawStarFreq:(getNumAgent()/_DrawStarFreq))==0) printf(".");
		}
	for(i=0;i<getNumAgent();i++)
		{ if(numcom[i]!=0) (neighborUR[i])/=(double)(numcom[i]);		  
		}
	
	delete [] numcom; numcom=NULL;	// delete numcom;
	delete meanutter; meanutter=NULL;	// delete meanutter;	
	printf("\n");
}

void CSystem::testNeighborComLex(int *neighborSize, CAgent ***Neighbor, int **NeighborInd, CLexRule ***neighborComLex, double **NeighborComLexAvgStr, int *NoneighborComLex, int size)
{ // test neighbor's comLex;
	assert((neighborSize!=NULL)&&(Neighbor!=NULL)&&(NeighborInd!=NULL)&&(neighborComLex!=NULL));
	int i, j, k, m;
	CLexRule **comLex=NULL, *curLex=NULL;
	double *comLexAvgStr=NULL, avgStr;
	int numcomLex;
	bool sameLex;

	for(i=0;i<size;i++)
		{ numcomLex=0;
		  if((getpAgent(i)->getpLTMem()->getNumLexRule()!=0)&&(neighborSize[i]!=0))
			{ // agent[i] has lexical rules and some neighbors;
			  // check common lex;
			  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
		  	  	{ curLex=getpAgent(i)->getpLTMem()->getpLexRuleList(j); avgStr=curLex->getLexStr();
			  	  // check whether all agents in the neighbor share the same lexical rule;
				  sameLex=1;
		  		  for(k=0;k<neighborSize[i];k++)
				  	{ for(m=0;m<Neighbor[i][k]->getpLTMem()->getNumLexRule();m++)
			  			{ if(*(Neighbor[i][k]->getpLTMem()->getpLexRuleList(m))==*(curLex)) break;
			  			}
			  	  	  if(m==Neighbor[i][k]->getpLTMem()->getNumLexRule()) sameLex=0;	// not same!
			  	  	  if(sameLex==1) 
					  	{ avgStr+=Neighbor[i][k]->getpLTMem()->getpLexRuleList(m)->getLexStr();
					  	  continue;
			  	  	  	}
			  	  	  else break;
					}
			  	  if(sameLex==1) 
				  	{ avgStr/=(double)(neighborSize[i]+1); updComLex(curLex, comLex, avgStr, comLexAvgStr, &numcomLex);
			  	  	}
			  	  curLex=NULL;
		  	  	}		    	
			}
		  NoneighborComLex[i]=numcomLex;
		  if(numcomLex!=0) 
		  	{ neighborComLex[i]=comLex; comLex=NULL; 
		  	  NeighborComLexAvgStr[i]=comLexAvgStr; comLexAvgStr=NULL;
		  	}
		  else { neighborComLex[i]=NULL; NeighborComLexAvgStr[i]=NULL; }
		}
	printf("\n");
}

void CSystem::testChildUR(int NormOrTest, int *ChildAgInd, double *ChildUR)
{ // testing children's UR;
	assert(NormOrTest==1); assert(ChildAgInd!=NULL); assert(ChildUR!=NULL);
	int i, j, k, numcom, speaker, listener;
	int feedback; bool inBufSuc;
	CMeanUtter *meanutter=new CMeanUtter; assert(meanutter!=NULL);	// initialize meanutter;

	numcom=0; *ChildUR=0.0;
	for(i=0;i<getNumAgentRep();i++)
		for(j=0;j<getNumAgentRep();j++)
			{ if(i!=j)
				{ numcom++; speaker=ChildAgInd[i]; listener=ChildAgInd[j];
 				  for(k=0;k<getpAgent(speaker)->getpSemSpace()->getNumIntgMean();k++)
					{ meanutter->EmptypMeanUtter();
  					  // speaker's part;
					  getpAgent(speaker)->ChoMeantoPro(meanutter, NormOrTest, k); getpAgent(speaker)->Production(meanutter, NormOrTest);	// speaker produces the meaning;
  					  if(meanutter->getpUtter()->getElement(0)!=-1)
  						{ // speaker successfully produces the utterance; 
	 		 			  // listener's part;
  	 		 			  feedback=0; inBufSuc=0; getpAgent(listener)->Perception(meanutter, &feedback, &inBufSuc, NormOrTest);	// listener comprehends the utterance;
  	 		 			  // test whether it is correct;
  	  					  if((feedback==1)&&(*(meanutter->getpMean())==*(getpAgent(speaker)->getpSemSpace()->getpSemItem(k)->getpIntgMean())))
						 	(*ChildUR)++;
  						}
					}
 		   		  if(numcom%(int)(((getNumAgentRep()*(getNumAgentRep()-1)<=(int)_DrawStarFreq)?_DrawStarFreq:(getNumAgentRep()*(getNumAgentRep()-1)))/_DrawStarFreq)==0) printf(".");
  				}
  			}
   	if(numcom!=0) (*ChildUR)/=(double)(numcom); 
	delete meanutter; meanutter=NULL;	// delete meanutter;
	printf("\n");
}

void CSystem::TestPara(int gen, int com, FILE **f, char **fileNam, int *ChildAgInd, CNet *adjMatrix)
{ // testing parameters;
	assert((0<=gen)&&(gen<=getNumGen())); assert((0<=com)&&(com<=getNumCom())); assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, k;
	char *MUstr=NULL;
	int **CatLink=NULL, numCatLink;

	int numSVMean=getpAgent(0)->getpSemSpace()->getNumMean1();
	int numSVOMean=getpAgent(0)->getpSemSpace()->getNumMean2();
	int numIntgMean=numSVMean+numSVOMean;
	int numOrderTyp1=overallpara.p_nNumOrderTyp1;
	int numOrderTyp2=overallpara.p_nNumOrderTyp2;
	
	int widthUR=(int)(log10((double)(getpAgent(0)->getpSemSpace()->getNumIntgMean()))+1);
	int widthLocSyn=(int)(log10((double)(getpAgent(0)->getpSemSpace()->getNumMean2()))+1);
	int widthLex=(int)(log10((double)(overallpara.p_nMaxLexRule))+1);
	int widthCat=(int)(log10((double)(overallpara.p_nMaxCat))+1);
	int widthSyn=(int)(log10((double)(overallpara.p_nMaxSynRule))+1);
	int widthDec=(int)(-1.0*log10(overallpara.p_dLexRuleStrLow)+0.5);
	int widthIndLearnAbi=(int)(-1.0*log10(overallpara.p_dLearnAbiLow)+0.5);
	
	int widthS=(int)(log10((double)(overallpara.p_nNumSemAgent))+1)+1;	// 1 bit more than the biggest case;
	int widthV=(int)(log10((double)(overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2))+1)+1;	// 1 bit more than the biggest case;
	int widthO=(int)(log10((double)(overallpara.p_nNumSemPat))+1)+1;	// 1 bit more than the biggest case;

	int widthGroup=(int)(log10((double)(getNumGroup()))+1);
	int widthAgent=(int)(log10((double)(getNumAgent()))+1);
	
	int widthCom=0, widthGen=0;
	if(getHorObliMix()==0) widthCom=(int)(log10((double)(getNumCom()))+1);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) widthGen=(int)(log10((double)(getNumGen()))+1);

	int widthNetDec=0, widthDegShortPath=0, widthCoef=0, widthNetWei=0, widthNetWeiDec=0, widthbetwNode=0, widthbetwEdge=0;
	if(adjMatrix!=NULL)
		{ widthNetDec=2; widthDegShortPath=(int)(log10((double)(adjMatrix->getSize()))+1);
		  widthCoef=1; widthbetwNode=(int)(log10((double)(adjMatrix->getSize()))+1);
		  if(adjMatrix->getDirected()==0) widthbetwEdge=(int)(log10((double)(adjMatrix->getSize()*(adjMatrix->getSize()-1)/_Twice))+1);
		  else if(adjMatrix->getDirected()==1) widthbetwEdge=(int)(log10((double)(adjMatrix->getSize()*(adjMatrix->getSize()-1)))+1);
		  widthNetWei=(int)(log10((double)(adjMatrix->getConWeiUp()))+1); widthNetWeiDec=(int)(-1.0*log10((double)(adjMatrix->getConWeiLow()))+0.5);		  
		}

	double ChildUR;	// for vertical and mixed transmission, children's UR;
	double UR, REall, UR1, REall1, UR2, REall2;
	double URini, URini1, URini2, URser, URser1, URser2;
	double Amb_a, Amb_b, Amb_c, Amb1_a, Amb1_b, Amb1_c, Amb2_a, Amb2_b, Amb2_c;
	int numHomoN, numHomoN1, numHomoN2, numHomoV, numHomoV1, numHomoV2, numHomoNV, numHomoNV1, numHomoNV2;
	double *eachUR=NULL, *eachURGroup=NULL; 
	double **syn=NULL, **syn1=NULL, **syn2=NULL;	// syn[*][0]: potential Per; syn[*][1]: Per; syn[*][2]: Pro;
	double **Localsyn=NULL, **Localsyn1=NULL, **Localsyn2=NULL;	// Localsyn[*][0]: potential Per; Localsyn[*][1]: Per; Localsyn[*][2]: Pro;
	double **OrdPro=NULL, **OrdPer=NULL;
	double **OrdPro1=NULL, **OrdPer1=NULL;
	double **OrdPro2=NULL, **OrdPer2=NULL;	
	double **eachAgOrdPro=NULL, **eachAgOrdProGroup=NULL;
	double **eachAgOrdPer=NULL, **eachAgOrdPerGroup=NULL;
	double **catSize=NULL, **catSizeGroup=NULL;
	
	double REholist, REcomp, REholist1, REcomp1, REholist2, REcomp2;
	
	double AvgHolistLex, AvgCompLex, AvgCat, AvgSyn, AvgLocSyn, AvgSnum, AvgVnum, AvgOnum, AvgSsize, AvgVsize, AvgOsize;
	double AvgHolistLex1, AvgCompLex1, AvgCat1, AvgSyn1, AvgLocSyn1, AvgSnum1, AvgVnum1, AvgOnum1, AvgSsize1, AvgVsize1, AvgOsize1;
	double AvgHolistLex2, AvgCompLex2, AvgCat2, AvgSyn2, AvgLocSyn2, AvgSnum2, AvgVnum2, AvgOnum2, AvgSsize2, AvgVsize2, AvgOsize2;

	int numSynRole;
	int numcomLex, numcomHolist, numcomComp;
	int numcomLex1, numcomHolist1, numcomComp1;
	int numcomLex2, numcomHolist2, numcomComp2;
	CLexRule **comLex=NULL, **comLex1=NULL, **comLex2=NULL;
	double *comLexAvgStr=NULL, *comLexAvgStr1=NULL, *comLexAvgStr2=NULL;
	int numLex, numHolist, numLexCat;

	double *displacement=NULL, avgDisp, *displacementGroup=NULL, avgDisp1, avgDisp2;

	double *AdjDist=NULL;	// adjacent matrix or distance matrix;
	CAgent ***Neighbor=NULL;	// neighbor of each agent;
	int **NeighborInd=NULL;	// neighbor's index of each agent;
	int *neighborSize=NULL;	// number of agents (include oneself) of each agent within block distance;	
	double *neighborUR=NULL;	// average UR of each neighbor groups;
	CLexRule ***neighborComLex=NULL;	// common lexical rules of each agent's neighborhood;
	double **neighborComLexAvgStr=NULL;
	int *NoneighborComLex=NULL;

	int **ConCompList=NULL, numConCompList, sizeConCompList;	// biggest connected component;
	int *index=NULL, range1, range2;	// node indexes for calculation;
	int *degree=NULL, *degreeC=NULL;  // each node's degree;
  	double degAvg=0.0, coefAvg=0.0, shortPathAvg=0.0, degAvgC=0.0, coefAvgC=0.0, shortPathAvgC=0.0;  // average degree per node; average clustering coefficient; averge shortest path length;
	double *betwNode=NULL, **betwEdge=NULL;	// node and edge betweenness;
	double *indDeg_UR=NULL;	// each agent's connection weights or UR;
	int numedge=0;	// number of edge in total;

	double avgLearnAbi;	// calculate average learning abilities;
	double avgLTM, avgMaxLTM;	// calculate average LTM capacities;
	
	int G1low=-1, G1up=-1, G2low=-1, G2up=-1;
	if(getNumGroup()==1) { G1low=0; G1up=getNumAgent(); }
	else if(getNumGroup()==2) { G1low=0; G1up=(int)(getNumAgent()/_Twice+0.5); G2low=G1up; G2up=getNumAgent(); }
	
	// for keeping the state of random number generator;
	unsigned long rulSeed;
	int rnLeft;
	unsigned long *rpulNext=NULL;
	unsigned long *rpulState=NULL;
	// before testing values of parameters; keep the current state of random number generator;
	CRandomNumber::GetState(rulSeed, rnLeft, rpulNext, rpulState);
	
	// test eachUR, UR, REall, synUR, synExp, OrdPro, OrdPer, eachAgOrdPro, eachAgOrdPer;		
	if(getNumGroup()==1)
		{ // 1 group;
		  // initialize eachUR;
		  eachUR=new double [getNumAgent()]; assert(eachUR!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	eachUR[i]=0.0;

		  // initialize syn, Localsyn; 
		  syn=new double * [numOrderTyp1+numOrderTyp2]; assert(syn!=NULL);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
			{ syn[i]=new double [3]; assert(syn[i]!=NULL);
		  	  for(j=0;j<3;j++)
			  	syn[i][j]=0.0;
			}
		  Localsyn=new double * [numOrderTyp2]; assert(Localsyn!=NULL);
		  for(i=0;i<numOrderTyp2;i++)
		  	{ Localsyn[i]=new double [3]; assert(Localsyn[i]!=NULL);
		  	  for(j=0;j<3;j++)
			  	Localsyn[i][j]=0.0;
		  	}
		  		  
		  // initialize OrdPro and OrdPer;
		  OrdPro=new double * [numIntgMean]; assert(OrdPro!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPro[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPro[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPro[i][j]=0.0;
			}
		  OrdPer=new double * [numIntgMean]; assert(OrdPer!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPer[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPer[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPer[i][j]=0.0;
			}

		  // initialize eachAgOrdPro and eachAgOrdPer;
		  eachAgOrdPro=new double * [getNumAgent()]; assert(eachAgOrdPro!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdPro[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdPro[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdPro[i][j]=0.0;
			}
		  eachAgOrdPer=new double * [getNumAgent()]; assert(eachAgOrdPer!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdPer[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdPer[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdPer[i][j]=0.0;
			}
		  
		  printf("Testing UR, REall (and Amb):"); UR=0.0; REall=0.0; Amb_a=0.0; Amb_b=0.0; Amb_c=0.0; testUR_Exp_Amb(1, 0, getNumAgent(), eachUR, getNumAgent(), &UR, &REall, &Amb_a, &Amb_b, &Amb_c, syn, numOrderTyp1+numOrderTyp2, 3, Localsyn, numOrderTyp2, 3, OrdPro, OrdPer, numIntgMean, numOrderTyp1+numOrderTyp2, eachAgOrdPro, eachAgOrdPer, getNumAgent(), numOrderTyp1+numOrderTyp2);
		  if(((getComMode()==0)||(getComMode()==4)||(getComMode()==5))&&((getHorObliMix()==1)||(getHorObliMix()==2)))
		  	{ // test children's UR;
			  if(gen==0) ChildUR=0.0;
			  else { printf("Testing Children's UR:"); ChildUR=0.0; testChildUR(1, ChildAgInd, &ChildUR); }
		  	}
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  // initialize eachUR and eachURGroup;
		  eachUR=new double [getNumAgent()]; assert(eachUR!=NULL);	// the whole group;
		  for(i=0;i<getNumAgent();i++)
		  	eachUR[i]=0.0;
		  eachURGroup=new double [getNumAgent()]; assert(eachURGroup!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	eachURGroup[i]=0.0;
		  
		  // initialize syn, syn1, syn2 and Localsyn, Localsyn1, Localsyn2; 
		  syn=new double * [numOrderTyp1+numOrderTyp2]; assert(syn!=NULL);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ syn[i]=new double [3]; assert(syn[i]!=NULL);
		  	  for(j=0;j<3;j++)
			  	syn[i][j]=0.0;
		  	}
		  syn1=new double * [numOrderTyp1+numOrderTyp2]; assert(syn1!=NULL);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ syn1[i]=new double [3]; assert(syn1[i]!=NULL);
		  	  for(j=0;j<3;j++)
			  	syn1[i][j]=0.0;
		  	}
		  syn2=new double * [numOrderTyp1+numOrderTyp2]; assert(syn2!=NULL);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ syn2[i]=new double [3]; assert(syn2[i]!=NULL);
		  	  for(j=0;j<3;j++)
			  	syn2[i][j]=0.0;
		  	}
		  Localsyn=new double * [numOrderTyp2]; assert(Localsyn!=NULL);
		  for(i=0;i<numOrderTyp2;i++)
		  	{ Localsyn[i]=new double [3]; assert(Localsyn[i]!=NULL);
			  for(j=0;j<3;j++)
			  	Localsyn[i][j]=0.0;
		  	}
		  Localsyn1=new double * [numOrderTyp2]; assert(Localsyn1!=NULL);
		  for(i=0;i<numOrderTyp2;i++)
		  	{ Localsyn1[i]=new double [3]; assert(Localsyn1[i]!=NULL);
			  for(j=0;j<3;j++)
			  	Localsyn1[i][j]=0.0;
		  	}
		  Localsyn2=new double * [numOrderTyp2]; assert(Localsyn2!=NULL);
		  for(i=0;i<numOrderTyp2;i++)
		  	{ Localsyn2[i]=new double [3]; assert(Localsyn2[i]!=NULL);
			  for(j=0;j<3;j++)
			  	Localsyn2[i][j]=0.0;
		  	}
		  
		  // initialize OrdPro, OrdPro1, OrdPro2 and OrdPer, OrdPer1, OrdPer2;
		  OrdPro=new double * [numIntgMean]; assert(OrdPro!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPro[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPro[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPro[i][j]=0.0;
			}
		  OrdPro1=new double * [numIntgMean]; assert(OrdPro1!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPro1[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPro1[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPro1[i][j]=0.0;
			}
		  OrdPro2=new double * [numIntgMean]; assert(OrdPro2!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPro2[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPro2[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPro2[i][j]=0.0;
			}
		  
		  OrdPer=new double * [numIntgMean]; assert(OrdPer!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPer[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPer[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPer[i][j]=0.0;
			}
		  OrdPer1=new double * [numIntgMean]; assert(OrdPer1!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPer1[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPer1[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPer1[i][j]=0.0;
			}
		  OrdPer2=new double * [numIntgMean]; assert(OrdPer2!=NULL);
		  for(i=0;i<numIntgMean;i++)
			{ OrdPer2[i]=new double [numOrderTyp1+numOrderTyp2]; assert(OrdPer2[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	OrdPer2[i][j]=0.0;
			}
		  
		  // initialize eachAgOrdPro, eachAgOrdProGroup, eachAgOrdPer, eachAgOrdPerGroup;
		  eachAgOrdPro=new double * [getNumAgent()]; assert(eachAgOrdPro!=NULL);	// whole group;
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdPro[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdPro[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdPro[i][j]=0.0;
			}
		  eachAgOrdProGroup=new double * [getNumAgent()]; assert(eachAgOrdProGroup!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdProGroup[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdProGroup[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdProGroup[i][j]=0.0;
			}
		  
		  eachAgOrdPer=new double * [getNumAgent()]; assert(eachAgOrdPer!=NULL);	// whole group;
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdPer[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdPer[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdPer[i][j]=0.0;
			}
		  eachAgOrdPerGroup=new double * [getNumAgent()]; assert(eachAgOrdPerGroup!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ eachAgOrdPerGroup[i]=new double [numOrderTyp1+numOrderTyp2]; assert(eachAgOrdPerGroup[i]!=NULL);
			  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
			  	eachAgOrdPerGroup[i][j]=0.0;
			}
		  
		  printf("Testing UR, REall (and Amb) (whole group):"); UR=0.0; REall=0.0; Amb_a=0.0; Amb_b=0.0; Amb_c=0.0; testCrossUR_Exp_Amb(1, G1low, G1up, G2low, G2up, eachUR, getNumAgent(), &UR, &REall, &Amb_a, &Amb_b, &Amb_c, syn, numOrderTyp1+numOrderTyp2, 3, Localsyn, numOrderTyp2, 3, OrdPro, OrdPer, numIntgMean, numOrderTyp1+numOrderTyp2, eachAgOrdPro, eachAgOrdPer, getNumAgent(), numOrderTyp1+numOrderTyp2);
		  printf("Testing UR, REall (and Amb) (group 1):"); UR1=0.0; REall1=0.0; Amb1_a=0.0; Amb1_b=0.0; Amb1_c=0.0; testUR_Exp_Amb(1, G1low, G1up, eachURGroup, getNumAgent(), &UR1, &REall1, &Amb1_a, &Amb1_b, &Amb1_c, syn1, numOrderTyp1+numOrderTyp2, 3, Localsyn1, numOrderTyp2, 3, OrdPro1, OrdPer1, numIntgMean, numOrderTyp1+numOrderTyp2, eachAgOrdProGroup, eachAgOrdPerGroup, getNumAgent(), numOrderTyp1+numOrderTyp2);
		  printf("Testing UR, REall (and Amb) (group 2):"); UR2=0.0; REall2=0.0; Amb2_a=0.0; Amb2_b=0.0; Amb2_c=0.0; testUR_Exp_Amb(1, G2low, G2up, eachURGroup, getNumAgent(), &UR2, &REall2, &Amb2_a, &Amb2_b, &Amb2_c, syn2, numOrderTyp1+numOrderTyp2, 3, Localsyn2, numOrderTyp2, 3, OrdPro2, OrdPer2, numIntgMean, numOrderTyp1+numOrderTyp2, eachAgOrdProGroup, eachAgOrdPerGroup, getNumAgent(), numOrderTyp1+numOrderTyp2);
		}
	
	// test holistExp and compExp;	
	if(getNumGroup()==1) 
		{ // 1 group;
		  printf("Testing REholist and REcomp\n"); REholist=0.0; REcomp=0.0; testHolistCompExp(0, getNumAgent(), &REholist, &REcomp);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  printf("Testing REholist and REcomp (whole group)\n"); REholist=0.0; REcomp=0.0; testHolistCompExp(0, getNumAgent(), &REholist, &REcomp);	// whole group;
		  printf("Testing REholist and REcomp (group 1)\n"); REholist1=0.0; REcomp1=0.0; testHolistCompExp(G1low, G1up, &REholist1, &REcomp1);
		  printf("Testing REholist and REcomp (group 2)\n"); REholist2=0.0; REcomp2=0.0; testHolistCompExp(G2low, G2up, &REholist2, &REcomp2);
		}
	
	// test AvgHolistLex, AvgCompLex, AvgCat, AvgSyn, AvgLocSyn, AvgnumS, AvgnumV, AvgnumO and catSize, the number, average and biggest sizes of subject/verb/object categories of each agent;	
	numSynRole=overallpara.p_nNumSemRole-1;	// total number of lexical syntactic categories;
	if(getNumGroup()==1)
		{ // 1 group;
		  // initialize catSize;
		  catSize=new double * [getNumAgent()]; assert(catSize!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ catSize[i]=new double [3*numSynRole]; assert(catSize[i]!=NULL);
			  for(j=0;j<3*numSynRole;j++)
			  	catSize[i][j]=0.0;
			}		  
		  printf("Testing AvgLex (Holist&Comp), AvgCat, AvgSyn (Global&Local)\n"); AvgHolistLex=0.0; AvgCompLex=0.0; AvgCat=0.0; AvgSyn=0.0; AvgLocSyn=0.0; AvgSnum=0.0; AvgVnum=0.0; AvgOnum=0.0; AvgSsize=0.0; AvgVsize=0.0; AvgOsize=0.0; testAvgLexCatSyn(0, getNumAgent(), &AvgHolistLex, &AvgCompLex, &AvgCat, &AvgSyn, &AvgLocSyn, &AvgSnum, &AvgVnum, &AvgOnum, &AvgSsize, &AvgVsize, &AvgOsize, catSize);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  // initialize catSize, catSizeGroup;
		  catSize=new double * [getNumAgent()]; assert(catSize!=NULL);	// whole group;
		  for(i=0;i<getNumAgent();i++)
			{ catSize[i]=new double [3*numSynRole]; assert(catSize[i]!=NULL);
			  for(j=0;j<3*numSynRole;j++)
			  	catSize[i][j]=0.0;
			}
		  catSizeGroup=new double * [getNumAgent()]; assert(catSizeGroup!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ catSizeGroup[i]=new double [3*numSynRole]; assert(catSizeGroup[i]!=NULL);
			  for(j=0;j<3*numSynRole;j++)
			  	catSizeGroup[i][j]=0.0;
			}		  
		  printf("Testing AvgLex (Holist&Comp), AvgCat, AvgSyn (Global&Local) (whole group)\n"); AvgHolistLex=0.0; AvgCompLex=0.0; AvgCat=0.0; AvgSyn=0.0; AvgLocSyn=0.0; AvgSnum=0.0; AvgVnum=0.0; AvgOnum=0.0; AvgSsize=0.0; AvgVsize=0.0; AvgOsize=0.0; testAvgLexCatSyn(0, getNumAgent(), &AvgHolistLex, &AvgCompLex, &AvgCat, &AvgSyn, &AvgLocSyn, &AvgSnum, &AvgVnum, &AvgOnum, &AvgSsize, &AvgVsize, &AvgOsize, catSize);
		  printf("Testing AvgLex (Holist&Comp), AvgCat, AvgSyn (Global&Local) (group 1)\n"); AvgHolistLex1=0.0; AvgCompLex1=0.0; AvgCat1=0.0; AvgSyn1=0.0; AvgLocSyn1=0.0; AvgSnum1=0.0; AvgVnum1=0.0; AvgOnum1=0.0; AvgSsize1=0.0; AvgVsize1=0.0; AvgOsize1=0.0; testAvgLexCatSyn(G1low, G1up, &AvgHolistLex1, &AvgCompLex1, &AvgCat1, &AvgSyn1, &AvgLocSyn1, &AvgSnum1, &AvgVnum1, &AvgOnum1, &AvgSsize1, &AvgVsize1, &AvgOsize1, catSizeGroup);
		  printf("Testing AvgLex (Holist&Comp), AvgCat, AvgSyn (Global&Local) (group 2)\n"); AvgHolistLex2=0.0; AvgCompLex2=0.0; AvgCat2=0.0; AvgSyn2=0.0; AvgLocSyn2=0.0; AvgSnum2=0.0; AvgVnum2=0.0; AvgOnum2=0.0; AvgSsize2=0.0; AvgVsize2=0.0; AvgOsize2=0.0; testAvgLexCatSyn(G2low, G2up, &AvgHolistLex2, &AvgCompLex2, &AvgCat2, &AvgSyn2, &AvgLocSyn2, &AvgSnum2, &AvgVnum2, &AvgOnum2, &AvgSsize2, &AvgVsize2, &AvgOsize2, catSizeGroup);
		}

	// test common lexical rules;
	if(getNumGroup()==1)
		{ // 1 group; 
		  printf("Testing comLex\n"); numcomLex=0; numcomHolist=0; numcomComp=0; testComLex(0, getNumAgent(), comLex, comLexAvgStr, &numcomLex, &numcomHolist, &numcomComp);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  printf("Testing comLex (whole group)\n"); numcomLex=0; numcomHolist=0; numcomComp=0; testComLex(0, getNumAgent(), comLex, comLexAvgStr, &numcomLex, &numcomHolist, &numcomComp);
		  printf("Testing comLex (group 1)\n"); numcomLex1=0; numcomHolist1=0; numcomComp1=0; testComLex(G1low, G1up, comLex1, comLexAvgStr1, &numcomLex1, &numcomHolist1, &numcomComp1);
  		  printf("Testing comLex (group 2)\n"); numcomLex2=0; numcomHolist2=0; numcomComp2=0; testComLex(G2low, G2up, comLex2, comLexAvgStr2, &numcomLex2, &numcomHolist2, &numcomComp2);
		}
	
	// test numPn, numPv, numPnv based on comLex;
	if(getCalAmbiguity()==1)
		{ if(getNumGroup()==1) 
			{ // 1 group;
			  numHomoN=0; numHomoV=0; numHomoNV=0; testHomo(comLex, numcomLex, numcomHolist, numcomComp, &numHomoN, &numHomoV, &numHomoNV);
			}
		  else if(getNumGroup()==2)
		  	{ // 2 groups;
			  numHomoN=0; numHomoV=0; numHomoNV=0; testHomo(comLex, numcomLex, numcomHolist, numcomComp, &numHomoN, &numHomoV, &numHomoNV);	// whole group;
			  numHomoN1=0; numHomoV1=0; numHomoNV1=0; testHomo(comLex1, numcomLex1, numcomHolist1, numcomComp1, &numHomoN1, &numHomoV1, &numHomoNV1);	// group 1;
			  numHomoN2=0; numHomoV2=0; numHomoNV2=0; testHomo(comLex2, numcomLex2, numcomHolist2, numcomComp2, &numHomoN2, &numHomoV2, &numHomoNV2);	// group 2;
		  	}
		}

	// test displacement;
	if(getNumGroup()==1)
		{ // 1 group; 
		  // initialize displacement;
		  displacement=new double [getNumAgent()]; assert(displacement!=NULL);
		  for(i=0;i<getNumAgent();i++)
			displacement[i]=0.0;	
		  printf("Testing Disp:"); avgDisp=0.0; testDisp(2, 0, getNumAgent(), displacement, getNumAgent(), &avgDisp);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  // initialize displacement, displacementGroup;
		  displacement=new double [getNumAgent()]; assert(displacement!=NULL);	// the whole group;
		  for(i=0;i<getNumAgent();i++)
			displacement[i]=0.0;
		  displacementGroup=new double [getNumAgent()]; assert(displacementGroup!=NULL);
		  for(i=0;i<getNumAgent();i++)
			displacementGroup[i]=0.0;		  
		  printf("Testing Disp (whole group):"); avgDisp=0.0; 
		  testCrossDisp(2, G1low, G1up, G2low, G2up, displacement, getNumAgent(), &avgDisp);
		  //testDisp(2, 0, getNumAgent(), displacement, getNumAgent(), &avgDisp);
		  printf("Testing Disp (group 1):"); avgDisp1=0.0; testDisp(2, G1low, G1up, displacementGroup, getNumAgent(), &avgDisp1);
		  printf("Testing Disp (group 2):"); avgDisp2=0.0; testDisp(2, G2low, G2up, displacementGroup, getNumAgent(), &avgDisp2);
		}

	if((getComMode()==4)&&(f[8]!=NULL)&&(f[9]!=NULL))
		{ // test agent's location related paramters;
		  // initialize AdjDist;
		  AdjDist=new double [(int)(getNumAgent()*(getNumAgent()-1)/_Twice)]; assert(AdjDist!=NULL);
		  for(i=0;i<getNumAgent();i++)
			for(j=i+1;j<getNumAgent();j++)
				//AdjDist[(getNumAgent()-1)*i-i*(i+1)/2+j-1]=(double)(chkDist(getpAgent(i), getpAgent(j)));	// for adjacent matrix;
			  	AdjDist[(getNumAgent()-1)*i-i*(i+1)/2+j-1]=calDist(getpAgent(i), getpAgent(j));	// for distance;
		  // initialize Neighbor, NeighborInd, neighborUR, neighborSize;
		  Neighbor=new CAgent ** [getNumAgent()]; assert(Neighbor!=NULL);
		  for(i=0;i<getNumAgent();i++)
			Neighbor[i]=NULL;
		  NeighborInd=new int * [getNumAgent()]; assert(NeighborInd!=NULL);
		  for(i=0;i<getNumAgent();i++)
			NeighborInd[i]=NULL;
		  neighborUR=new double [getNumAgent()]; assert(neighborUR!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	neighborUR[i]=0.0;
		  neighborSize=new int [getNumAgent()]; assert(neighborSize!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	neighborSize[i]=0;
		  printf("Testing Neighbor UR and Size:"); testNeighborUR_Size(1, AdjDist, (int)(getNumAgent()*(getNumAgent()-1)/_Twice), neighborUR, neighborSize, Neighbor, NeighborInd, getNumAgent());	// test neighborUR and neighborSize;
 		  
		  // initialize neighborComLex, neighborComLexAvgStr, NoneighborComLex, diffNoneighborComLex;
		  neighborComLex=new CLexRule** [getNumAgent()]; assert(neighborComLex!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	neighborComLex[i]=NULL;
		  neighborComLexAvgStr=new double * [getNumAgent()]; assert(neighborComLexAvgStr!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	neighborComLexAvgStr[i]=NULL;
		  NoneighborComLex=new int [getNumAgent()]; assert(NoneighborComLex!=NULL);
		  for(i=0;i<getNumAgent();i++)
		  	NoneighborComLex[i]=0;
		  printf("Testing Neighbor's commUtter:"); testNeighborComLex(neighborSize, Neighbor, NeighborInd, neighborComLex, neighborComLexAvgStr, NoneighborComLex, getNumAgent());	// test neighbor's comLex;
		}

	if((getComMode()==5)&&(f[10]!=NULL)&&(f[11]!=NULL)&&(adjMatrix!=NULL))
		{ // testing agent's social network parameters;
		  if(((getSelfGrow()==1)||(getSelfGrow()==2))||((getSelfGrow()==0)&&(((getHorObliMix()==0)&&(com==0))||(((getHorObliMix()==1)||(getHorObliMix()==2))&&(gen==0)))))
		  	{ printf("Testing Network information:\n");
			  // initialize index;
			  index=new int [getNumAgent()]; assert(index!=NULL);
			  for(i=0;i<getNumAgent();i++)
			  	index[i]=-1;

			  // first, calculate the whole group's degAvg, coefAvg, shortPathAvg;
			  adjMatrix->setIndex(0, index, getNumAgent(), &range1, &range2, NULL, 0, 0);	// set up whole group's index;
			  // initialize degree;
			  degree=new int [getNumAgent()]; assert(degree!=NULL);
			  for(i=0;i<getNumAgent();i++)
			  	degree[i]=0;
			  degAvg=adjMatrix->calDeg(degree, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate average degree;
			  coefAvg=adjMatrix->calClusterCoef(degree, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate cluster coeffient;
			  shortPathAvg=adjMatrix->calShortPath(index, getNumAgent(), range1, range2);

			  // second, calculate the biggest connected component's degAvg, coefAvg, shortPathAvg;
			  numConCompList=0; sizeConCompList=0; adjMatrix->calBigestConComp(ConCompList, &numConCompList, &sizeConCompList);	// calculate biggest connected component; 
  		  	  if(numConCompList!=0)
			  	{ if(sizeConCompList==getNumAgent())
  		  	  		{ // the whole group is connected; only calculate betweenness;
  		  	  		  betwNode=new double [getNumAgent()]; assert(betwNode!=NULL);
					  adjMatrix->calBetwNode(betwNode, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate node betweenness;
					  if(adjMatrix->getDirected()==0) 
					  	{ betwEdge=new double * [(int)(getNumAgent()*(getNumAgent()-1)/_Twice)]; assert(betwEdge!=NULL);
					  	  for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					  		{ betwEdge[i]=new double [3]; assert(betwEdge[i]!=NULL); }
					  	  numedge=0; adjMatrix->calBetwEdge(betwEdge, (int)(getNumAgent()*(getNumAgent()-1)/_Twice), 3, index, getNumAgent(), range1, range2, &numedge);	// calculate edge betweenness;
					  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ betwEdge=new double * [getNumAgent()*(getNumAgent()-1)]; assert(betwEdge!=NULL);
					  	  for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					  		{ betwEdge[i]=new double [3]; assert(betwEdge[i]!=NULL); }
					  	  numedge=0; adjMatrix->calBetwEdge(betwEdge, getNumAgent()*(getNumAgent()-1), 3, index, getNumAgent(), range1, range2, &numedge);	// calculate edge betweenness;
					  	}
					}
			  	  else
			  	  	{ // there is a biggest connected component, smaller than the whole group;
					  adjMatrix->setIndex(1, index, getNumAgent(), &range1, &range2, ConCompList, numConCompList, sizeConCompList);
			  	  	  // initialize degreeC;
			  	  	  degreeC=new int [getNumAgent()]; assert(degreeC!=NULL);
			  	  	  for(i=0;i<getNumAgent();i++)
			  			degreeC[i]=0;
			  	  	  degAvgC=adjMatrix->calDeg(degreeC, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate average degree;
			  	  	  coefAvgC=adjMatrix->calClusterCoef(degreeC, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate cluster coeffient;
			 	  	  shortPathAvgC=adjMatrix->calShortPath(index, getNumAgent(), range1, range2);
					  // calculate betweenness;
					  betwNode=new double [getNumAgent()]; assert(betwNode!=NULL);
					  adjMatrix->calBetwNode(betwNode, getNumAgent(), index, getNumAgent(), range1, range2);	// calculate node betweenness;
					  if(adjMatrix->getDirected()==0) 
					  	{ betwEdge=new double * [(int)(getNumAgent()*(getNumAgent()-1)/_Twice)]; assert(betwEdge!=NULL);
					  	  for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					  		{ betwEdge[i]=new double [3]; assert(betwEdge[i]!=NULL); }
					  	  numedge=0; adjMatrix->calBetwEdge(betwEdge, (int)(getNumAgent()*(getNumAgent()-1)/_Twice), 3, index, getNumAgent(), range1, range2, &numedge);	// calculate edge betweenness;
					  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ betwEdge=new double * [getNumAgent()*(getNumAgent()-1)]; assert(betwEdge!=NULL);
					  	  for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					  		{ betwEdge[i]=new double [3]; assert(betwEdge[i]!=NULL); }
					  	  numedge=0; adjMatrix->calBetwEdge(betwEdge, getNumAgent()*(getNumAgent()-1), 3, index, getNumAgent(), range1, range2, &numedge);	// calculate edge betweenness;
					  	}
					}		  	  
  		  	  	}

			  // last, calculate each agent's connection weights or UR;
			  indDeg_UR=new double [getNumAgent()]; assert(indDeg_UR!=NULL);
			  for(i=0;i<getNumAgent();i++)
			  	indDeg_UR[i]=0.0;
			  for(i=0;i<getNumAgent();i++)
			  	{ if((getSelfGrow()==0)||(getSelfGrow()==1)) indDeg_UR[i]=adjMatrix->calNodeDeg(i);
			  	  else if(getSelfGrow()==2) indDeg_UR[i]=calAgUR(i);
			  	}		  	
			}
		}
	
	// test URini and URser;
	if(getRecURiniser()==1)
		{ if(getNumGroup()==1)
			{ // 1 group;
			  printf("Testing URini:"); URini=0.0; testURini(1, 0, getNumAgent(), &URini);
			  printf("Testing URser:"); URser=0.0; testURser(1, 0, getNumAgent(), &URser);
			}
		  else if(getNumGroup()==2)
			{ // 2 groups;
			  printf("Testing URini (group 1):"); URini1=0.0; testURini(1, G1low, G1up, &URini1);
			  printf("Testing URini (group 2):"); URini2=0.0; testURini(1, G2low, G2up, &URini2);
			  printf("Testing URser (group 1):"); URser1=0.0; testURser(1, G1low, G1up, &URser1);
			  printf("Testing URser (group 2):"); URser2=0.0; testURser(1, G2low, G2up, &URser2);
			}
		  updAgentN();	// update m_ppAgent into m_ppAgentN;
		}

	
	// display UR, REall, REholist, REcomp and common lexical rules;
	if(getNumGroup()==1) 
		{ // 1 group; 
		  printf("TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f); ComLex=%*d(%*d,%*d)\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(getCalAmbiguity()==1) printf("Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  if(getRecURiniser()==1) printf("URini=%*.*f; URser=%*.*f;\n", widthUR+widthDec+1, widthDec, URini, widthUR+widthDec+1, widthDec, URser);
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  printf("TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f); ComLex=%*d(%*d,%*d)\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(getCalAmbiguity()==1) printf("Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  printf("TotalMean=%*d(%*d+%*d); UR1=%*.*f; Disp1=%*.*f;\nREall1=%*.*f(%*.*f,%*.*f); ComLex1=%*d(%*d,%*d)\n", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, REall1, widthUR+widthDec+1, widthDec, REholist1, widthUR+widthDec+1, widthDec, REcomp1, widthLex, numcomLex1, widthLex, numcomHolist1, widthLex, numcomComp1);
		  if(getCalAmbiguity()==1) printf("Amb1_a=%*.*f; Amb1_b=%*.*f; Amb1_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb1_a, widthUR+widthDec+1, widthDec, Amb1_b, widthUR+widthDec+1, widthDec, Amb1_c);
		  if(getRecURiniser()==1) printf("URini1=%*.*f; URser1=%*.*f;\n", widthUR+widthDec+1, widthDec, URini1, widthUR+widthDec+1, widthDec, URser1);
		  printf("TotalMean=%*d(%*d+%*d); UR2=%*.*f; Disp2=%*.*f;\nREall2=%*.*f(%*.*f,%*.*f); ComLex2=%*d(%*d,%*d)\n", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, REall2, widthUR+widthDec+1, widthDec, REholist2, widthUR+widthDec+1, widthDec, REcomp2, widthLex, numcomLex2, widthLex, numcomHolist2, widthLex, numcomComp2);
		  if(getCalAmbiguity()==1) printf("Amb2_a=%*.*f; Amb2_b=%*.*f; Amb2_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb2_a, widthUR+widthDec+1, widthDec, Amb2_b, widthUR+widthDec+1, widthDec, Amb2_c);
		  if(getRecURiniser()==1) printf("URini2=%*.*f; URser2=%*.*f;\n", widthUR+widthDec+1, widthDec, URini2, widthUR+widthDec+1, widthDec, URser2);
		}		  

	if(getRecIndInfo()==1)
		{ // record each individual's linguistic knowledge to f[0]; 
		  if((f[0]=fopen(fileNam[0],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[0]); exit(1); }
		  if((com==0)&&(gen==0)) fprintf(f[0], "Initialization:\n");
		  else
			{ if(getHorObliMix()==0) fprintf(f[0], "Com=%*d:\n", widthCom, com);
		  	  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[0], "Gen=%*d:\n", widthGen, gen);
			}
	
		  // record UR, REall, REholist, REcomp and AvgLex, AvgCat, AvgSyn, AvgLoc;
		  if(getNumGroup()==1)
			{ // 1 group;
			  fprintf(f[0], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f); AvgHolistLex=%*.*f; AvgCompLex=%*.*f; AvgCat=%*.*f; AvgSyn=%*.*f; AvgLocSyn=%*.*f\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex+widthDec+1, widthDec, AvgHolistLex, widthLex+widthDec+1, widthDec, AvgCompLex, widthCat+widthDec+1, widthDec, AvgCat, widthSyn+widthDec+1, widthDec, AvgSyn, widthSyn+widthDec+1, widthDec, AvgLocSyn);
			  if(getCalAmbiguity()==1) fprintf(f[0], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
			  if(getRecURiniser()==1) fprintf(f[0], "URini=%*.*f; URser=%*.*f;\n", widthUR+widthDec+1, widthDec, URini, widthUR+widthDec+1, widthDec, URser);
	  		  fprintf(f[0], "ComLex=%*d(%*d,%*d)\n", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  	}
		  else if(getNumGroup()==2)
			{ // 2 groups;
		 	  fprintf(f[0], "Whole group (0 - %*d):\n", widthAgent, getNumAgent());
			  fprintf(f[0], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f); AvgHolistLex=%*.*f; AvgCompLex=%*.*f; AvgCat=%*.*f; AvgSyn=%*.*f; AvgLocSyn=%*.*f\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex+widthDec+1, widthDec, AvgHolistLex, widthLex+widthDec+1, widthDec, AvgCompLex, widthCat+widthDec+1, widthDec, AvgCat, widthSyn+widthDec+1, widthDec, AvgSyn, widthSyn+widthDec+1, widthDec, AvgLocSyn);
			  if(getCalAmbiguity()==1) fprintf(f[0], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
			  fprintf(f[0], "ComLex=%*d(%*d,%*d)\n", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
			  fprintf(f[0], "Group 1 (%*d - %*d):\n", widthAgent, G1low, widthAgent, G1up);
			  fprintf(f[0], "TotalMean=%*d(%*d+%*d); UR1=%*.*f; Disp1=%*.*f;\nREall1=%*.*f(%*.*f,%*.*f); AvgHolistLex1=%*.*f; AvgCompLex1=%*.*f; AvgCat1=%*.*f; AvgSyn1=%*.*f; AvgLocSyn1=%*.*f\n", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, REall1, widthUR+widthDec+1, widthDec, REholist1, widthUR+widthDec+1, widthDec, REcomp1, widthLex+widthDec+1, widthDec, AvgHolistLex1, widthLex+widthDec+1, widthDec, AvgCompLex1, widthCat+widthDec+1, widthDec, AvgCat1, widthSyn+widthDec+1, widthDec, AvgSyn1, widthSyn+widthDec+1, widthDec, AvgLocSyn1);
			  if(getCalAmbiguity()==1) fprintf(f[0], "Amb1_a=%*.*f; Amb1_b=%*.*f; Amb1_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb1_a, widthUR+widthDec+1, widthDec, Amb1_b, widthUR+widthDec+1, widthDec, Amb1_c);
			  if(getRecURiniser()==1) fprintf(f[0], "URini1=%*.*f; URser1=%*.*f;\n", widthUR+widthDec+1, widthDec, URini1, widthUR+widthDec+1, widthDec, URser1);
			  fprintf(f[0], "ComLex1=%*d(%*d,%*d)\n", widthLex, numcomLex1, widthLex, numcomHolist1, widthLex, numcomComp1);
			  fprintf(f[0], "Group 2 (%*d - %*d):\n", widthAgent, G2low, widthAgent, G2up);
			  fprintf(f[0], "TotalMean=%*d(%*d+%*d); UR2=%*.*f; Disp2=%*.*f;\nREall2=%*.*f(%*.*f,%*.*f); AvgHolistLex2=%*.*f; AvgCompLex2=%*.*f; AvgCat2=%*.*f; AvgSyn2=%*.*f; AvgLocSyn2=%*.*f\n", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, REall2, widthUR+widthDec+1, widthDec, REholist2, widthUR+widthDec+1, widthDec, REcomp2, widthLex+widthDec+1, widthDec, AvgHolistLex2, widthLex+widthDec+1, widthDec, AvgCompLex2, widthCat+widthDec+1, widthDec, AvgCat2, widthSyn+widthDec+1, widthDec, AvgSyn2, widthSyn+widthDec+1, widthDec, AvgLocSyn2);
			  if(getCalAmbiguity()==1) fprintf(f[0], "Amb2_a=%*.*f; Amb2_b=%*.*f; Amb2_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb2_a, widthUR+widthDec+1, widthDec, Amb2_b, widthUR+widthDec+1, widthDec, Amb2_c);
			  if(getRecURiniser()==1) fprintf(f[0], "URini2=%*.*f; URser2=%*.*f;\n", widthUR+widthDec+1, widthDec, URini2, widthUR+widthDec+1, widthDec, URser2);
			  fprintf(f[0], "ComLex2=%*d(%*d,%*d)\n", widthLex, numcomLex2, widthLex, numcomHolist2, widthLex, numcomComp2);
			}
		  fprintf(f[0], "\n");
		  // record lexical rules/categories/syntactic rules;
		  for(i=0;i<getNumAgent();i++)
			{ fprintf(f[0], "Agent[%*d]:\n", widthAgent, i);
			  getpAgent(i)->getpLTMem()->RecLTMem(f[0], getpAgent(i)->getpSemSpace());
			}
		  fprintf(f[0], "\n");
		  fclose(f[0]);
		}
	
	// record parameters in f[1];
	if((f[1]=fopen(fileNam[1],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[1]); exit(1); }
	if(getHorObliMix()==0) fprintf(f[1], "%*d ", widthCom, com);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[1], "%*d ", widthGen, gen);
	if(getNumGroup()==1)
		{ // 1 group;
		  fprintf(f[1], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  fprintf(f[1], "%*d %*d %*d %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex+widthDec+1, widthDec, AvgHolistLex, widthLex+widthDec+1, widthDec, AvgCompLex, widthCat+widthDec+1, widthDec, AvgCat, widthSyn+widthDec+1, widthDec, AvgSyn, widthSyn+widthDec+1, widthDec, AvgLocSyn);	
		  fprintf(f[1], "%*d %*d %*d ", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
			fprintf(f[1], "%*.*f %*.*f %*.*f ", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]);
		  for(i=0;i<numOrderTyp2;i++)
	  		fprintf(f[1], "%*.*f %*.*f %*.*f ", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]);
		  if(getRecURiniser()==1) fprintf(f[1], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, URini, widthUR+widthDec+1, widthDec, URser);
		  if(((getComMode()==0)||(getComMode()==4)||(getComMode()==5))&&((getHorObliMix()==1)||(getHorObliMix()==2)))
		  	fprintf(f[1], " %*.*f ", widthUR+widthDec+1, widthDec, ChildUR);	// record children's UR;
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  fprintf(f[1], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  // whole group;
		  fprintf(f[1], "%*d %*d %*d %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex+widthDec+1, widthDec, AvgHolistLex, widthLex+widthDec+1, widthDec, AvgCompLex, widthCat+widthDec+1, widthDec, AvgCat, widthSyn+widthDec+1, widthDec, AvgSyn, widthSyn+widthDec+1, widthDec, AvgLocSyn);	
		  fprintf(f[1], "%*d %*d %*d ", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
			fprintf(f[1], "%*.*f %*.*f %*.*f ", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]);
		  for(i=0;i<numOrderTyp2;i++)
		  	fprintf(f[1], "%*.*f %*.*f %*.*f ", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]);
		  // group 1;
		  fprintf(f[1], "%*d %*d %*d %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, REall1, widthUR+widthDec+1, widthDec, REholist1, widthUR+widthDec+1, widthDec, REcomp1, widthLex+widthDec+1, widthDec, AvgHolistLex1, widthLex+widthDec+1, widthDec, AvgCompLex1, widthCat+widthDec+1, widthDec, AvgCat1, widthSyn+widthDec+1, widthDec, AvgSyn1, widthSyn+widthDec+1, widthDec, AvgLocSyn1);	
		  fprintf(f[1], "%*d %*d %*d ", widthLex, numcomLex1, widthLex, numcomHolist1, widthLex, numcomComp1);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
			fprintf(f[1], "%*.*f %*.*f %*.*f ", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]);
		  for(i=0;i<numOrderTyp2;i++)
		  	fprintf(f[1], "%*.*f %*.*f %*.*f ", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]);
		  // group 2;
		  fprintf(f[1], "%*d %*d %*d %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, REall2, widthUR+widthDec+1, widthDec, REholist2, widthUR+widthDec+1, widthDec, REcomp2, widthLex+widthDec+1, widthDec, AvgHolistLex2, widthLex+widthDec+1, widthDec, AvgCompLex2, widthCat+widthDec+1, widthDec, AvgCat2, widthSyn+widthDec+1, widthDec, AvgSyn2, widthSyn+widthDec+1, widthDec, AvgLocSyn2);	
		  fprintf(f[1], "%*d %*d %*d ", widthLex, numcomLex2, widthLex, numcomHolist2, widthLex, numcomComp2);
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
			fprintf(f[1], "%*.*f %*.*f %*.*f ", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]);
		  for(i=0;i<numOrderTyp2;i++)
		  	fprintf(f[1], "%*.*f %*.*f %*.*f ", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]);
		  if(getRecURiniser()==1) fprintf(f[1], "%*.*f %*.*f %*.*f %*.*f ", widthUR+widthDec+1, widthDec, URini1, widthUR+widthDec+1, widthDec, URser1, widthUR+widthDec+1, widthDec, URini2, widthUR+widthDec+1, widthDec, URser2);
		}
	fprintf(f[1],"\n");
	fclose(f[1]);

	// record common lexical rules in f[2];
	if((f[2]=fopen(fileNam[2], "a+"))==NULL) { printf("Can't create %s\n", fileNam[2]); exit(1); }
	if((com==0)&&(gen==0)) fprintf(f[2], "Initialization:\n");
	else
		{ if(getHorObliMix()==0) fprintf(f[2], "Com=%*d:\n", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[2], "Gen=%*d:\n", widthGen, gen);
		}
	if(getNumGroup()==1)
		{ // 1 group;
		  // record comLex;
		  fprintf(f[2], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f);\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp);
		  if(getCalAmbiguity()==1) fprintf(f[2], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  if(getRecURiniser()==1) fprintf(f[2], "URini=%*.*f; URser=%*.*f;\n", widthUR+widthDec+1, widthDec, URini, widthUR+widthDec+1, widthDec, URser);
		  fprintf(f[2], "ComLex=%*d (%*d,%*d)\n", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(numcomLex!=0)
			{ for(i=0;i<numcomLex;i++)
				{ fprintf(f[2], "Lex%*d", widthLex, i); comLex[i]->recLexTyp(f[2]);
				  fprintf(f[2], "(%*.*f): ", (int)(-1.0*log10((double)(comLexAvgStr[i]))+0.5)+widthDec+1, widthDec, comLexAvgStr[i]);
				  // initialize MUstr;
				  MUstr=new char [11+3*(int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+3*overallpara.p_nLengthWord*((int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
				  comLex[i]->buildMUstr(MUstr, getpAgent(0)->getpSemSpace()); fprintf(f[2],"%s\n", MUstr);
				  delete [] MUstr; MUstr=NULL;	// delete MUstr;
				}
			  fprintf(f[2],"\n");
			}
		  else fprintf(f[2], "\n");		  	
		  fprintf(f[2], "Global orders:\n");	// record global order's potential per; per; pro;
		  for(i=0;i<numOrderTyp1;i++)
			{ if(i==0) { fprintf(f[2], " SV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SV;
			  else if(i==1) { fprintf(f[2], " VS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VS;	
			}
		  for(i=numOrderTyp1;i<numOrderTyp1+numOrderTyp2;i++)
			{ if(i==2) { fprintf(f[2], "SVO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SVO;
		  	  else if(i==3) { fprintf(f[2], "SOV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SOV;
		  	  else if(i==4) { fprintf(f[2], "OSV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// OSV;
		  	  else if(i==5) { fprintf(f[2], "VSO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VSO;
		  	  else if(i==6) { fprintf(f[2], "VOS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VOS;
		  	  else if(i==7) { fprintf(f[2], "OVS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// OVS;
			}
		  fprintf(f[2], "Local orders:\n");	// record local order's potential per; per; pro;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ if(i==0) { fprintf(f[2], "SV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// SV local order;
		  	  else if(i==1) { fprintf(f[2], "VS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// VS local order;
			  else if(i==2) { fprintf(f[2], "VO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// VO local order;
			  else if(i==3) { fprintf(f[2], "OV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// OV local order;
			  else if(i==4) { fprintf(f[2], "SO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// SO local order;
			  else if(i==5) { fprintf(f[2], "OS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// OS local order;			  	
		  	}
		  fprintf(f[2],"\n");
		  // delete syn;
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ delete [] syn[i]; syn[i]=NULL; }
		  delete [] syn; syn=NULL;
		  // delete Localsyn;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ delete [] Localsyn[i]; Localsyn[i]=NULL; }
		  delete [] Localsyn; Localsyn=NULL;
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  // record ComLex Whole group;
		  fprintf(f[2], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f; REall=%*.*f(%*.*f,%*.*f);\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp);
		  if(getCalAmbiguity()==1) fprintf(f[2], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  fprintf(f[2], "ComLex=%*d (%*d,%*d)\n", widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(numcomLex!=0)
			{ fprintf(f[2], "ComLexSim=(%4.3f,%4.3f)\n", numcomLex/(double)(numcomLex1), numcomLex/(double)(numcomLex2));	// lexical rules' similarity;
		  	  for(i=0;i<numcomLex;i++)
				{ fprintf(f[2], "Lex%*d", widthLex, i); comLex[i]->recLexTyp(f[2]);
				  fprintf(f[2], "(%*.*f): ", (int)(-1.0*log10((double)(comLexAvgStr[i]))+0.5)+widthDec+1, widthDec, comLexAvgStr[i]);
				  // initialize MUstr;
				  MUstr=new char [11+3*(int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+3*overallpara.p_nLengthWord*((int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
				  comLex[i]->buildMUstr(MUstr, getpAgent(0)->getpSemSpace()); fprintf(f[2],"%s\n", MUstr);
				  delete [] MUstr; MUstr=NULL;	// delete MUstr;
				}
			  fprintf(f[2],"\n");
			}
		  else fprintf(f[2], "\n");
		  fprintf(f[2], "Whole Group: Global orders:\n");	// record whole group's global order's potential per; per; pro;
		  for(i=0;i<numOrderTyp1;i++)
			{ if(i==0) { fprintf(f[2], " SV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SV;
			  else if(i==1) { fprintf(f[2], " VS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VS;	
			}
		  for(i=numOrderTyp1;i<numOrderTyp1+numOrderTyp2;i++)
			{ if(i==2) { fprintf(f[2], "SVO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SVO;
		  	  else if(i==3) { fprintf(f[2], "SOV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// SOV;
		  	  else if(i==4) { fprintf(f[2], "OSV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// OSV;
		  	  else if(i==5) { fprintf(f[2], "VSO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VSO;
		  	  else if(i==6) { fprintf(f[2], "VOS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// VOS;
		  	  else if(i==7) { fprintf(f[2], "OVS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn[i][0], widthUR+widthDec+1, widthDec, syn[i][1], widthUR+widthDec+1, widthDec, syn[i][2]); }	// OVS;
			}
		  fprintf(f[2], "Whole Group: Local orders:\n");	// record whole group's local order's potential per; per; pro;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ if(i==0) { fprintf(f[2], "SV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// SV local order;
		  	  else if(i==1) { fprintf(f[2], "VS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// VS local order;
			  else if(i==2) { fprintf(f[2], "VO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// VO local order;
			  else if(i==3) { fprintf(f[2], "OV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// OV local order;
			  else if(i==4) { fprintf(f[2], "SO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// SO local order;
			  else if(i==5) { fprintf(f[2], "OS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn[i][2]); }	// OS local order;			  	
		  	}		  
		  fprintf(f[2],"\n");
		  // delete syn;
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ delete [] syn[i]; syn[i]=NULL; }
		  delete [] syn; syn=NULL;
		  // delete Localsyn;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ delete [] Localsyn[i]; Localsyn[i]=NULL; }
		  delete [] Localsyn; Localsyn=NULL;

		  // record comLex Group 1;
		  fprintf(f[2], "TotalMean=%*d(%*d+%*d); UR1=%*.*f; Disp1=%*.*f;\nREall1=%*.*f(%*.*f,%*.*f);\n", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, REall1, widthUR+widthDec+1, widthDec, REholist1, widthUR+widthDec+1, widthDec, REcomp1);
		  if(getCalAmbiguity()==1) fprintf(f[2], "Amb1_a=%*.*f; Amb1_b=%*.*f; Amb1_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb1_a, widthUR+widthDec+1, widthDec, Amb1_b, widthUR+widthDec+1, widthDec, Amb1_c);
		  if(getRecURiniser()==1) fprintf(f[2], "URini1=%*.*f; URser1=%*.*f;\n", widthUR+widthDec+1, widthDec, URini1, widthUR+widthDec+1, widthDec, URser1);
		  fprintf(f[2], "ComLex1=%*d (%*d,%*d)\n", widthLex, numcomLex1, widthLex, numcomHolist1, widthLex, numcomComp1);
		  if(numcomLex1!=0)
			{ for(i=0;i<numcomLex1;i++)
				{ fprintf(f[2], "Lex%*d", widthLex, i); comLex1[i]->recLexTyp(f[2]);
				  fprintf(f[2], "(%*.*f): ", (int)(-1.0*log10((double)(comLexAvgStr1[i]))+0.5)+widthDec+1, widthDec, comLexAvgStr1[i]);
				  // initialize MUstr;
				  MUstr=new char [11+3*(int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+3*overallpara.p_nLengthWord*((int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
				  comLex1[i]->buildMUstr(MUstr, getpAgent(0)->getpSemSpace()); fprintf(f[2],"%s\n", MUstr);
				  delete [] MUstr; MUstr=NULL;	// delete MUstr;
				}
			  fprintf(f[2],"\n");
			}
		  else fprintf(f[2], "\n");
	 	  fprintf(f[2], "Group 1: Global orders:\n");	// record group 1's global order's potential per; per; pro;
		  for(i=0;i<numOrderTyp1;i++)
			{ if(i==0) { fprintf(f[2], " SV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// SV;
			  else if(i==1) { fprintf(f[2], " VS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// VS;	
			}
		  for(i=numOrderTyp1;i<numOrderTyp1+numOrderTyp2;i++)
			{ if(i==2) { fprintf(f[2], "SVO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// SVO;
		  	  else if(i==3) { fprintf(f[2], "SOV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// SOV;
		  	  else if(i==4) { fprintf(f[2], "OSV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// OSV;
		  	  else if(i==5) { fprintf(f[2], "VSO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// VSO;
		  	  else if(i==6) { fprintf(f[2], "VOS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// VOS;
		  	  else if(i==7) { fprintf(f[2], "OVS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn1[i][0], widthUR+widthDec+1, widthDec, syn1[i][1], widthUR+widthDec+1, widthDec, syn1[i][2]); }	// OVS;
			}
		  fprintf(f[2], "Group 1: Local orders:\n");	// record group 1's local order's potential per; per; pro;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ if(i==0) { fprintf(f[2], "SV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// SV local order;
		  	  else if(i==1) { fprintf(f[2], "VS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// VS local order;
			  else if(i==2) { fprintf(f[2], "VO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// VO local order;
			  else if(i==3) { fprintf(f[2], "OV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// OV local order;
			  else if(i==4) { fprintf(f[2], "SO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// SO local order;
			  else if(i==5) { fprintf(f[2], "OS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn1[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn1[i][2]); }	// OS local order;			  	
		  	}
		  fprintf(f[2],"\n");
		  // delete syn1;
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ delete [] syn1[i]; syn1[i]=NULL; }
		  delete [] syn1; syn1=NULL;
		  // delete Localsyn1;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ delete [] Localsyn1[i]; Localsyn1[i]=NULL; }
		  delete [] Localsyn1; Localsyn1=NULL;

		  // record comLex Group 2;
		  fprintf(f[2], "TotalMean=%*d(%*d+%*d); UR2=%*.*f; Disp2=%*.*f;\nREall2=%*.*f(%*.*f,%*.*f);\n", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, REall2, widthUR+widthDec+1, widthDec, REholist2, widthUR+widthDec+1, widthDec, REcomp2);
		  if(getCalAmbiguity()==1) fprintf(f[2], "Amb2_a=%*.*f; Amb2_b=%*.*f; Amb2_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb2_a, widthUR+widthDec+1, widthDec, Amb2_b, widthUR+widthDec+1, widthDec, Amb2_c);
		  if(getRecURiniser()==1) fprintf(f[2], "URini2=%*.*f; URser2=%*.*f;\n", widthUR+widthDec+1, widthDec, URini2, widthUR+widthDec+1, widthDec, URser2);
		  fprintf(f[2], "ComLex2=%*d (%*d,%*d)\n", widthLex, numcomLex2, widthLex, numcomHolist2, widthLex, numcomComp2);
		  if(numcomLex2!=0)
			{ for(i=0;i<numcomLex2;i++)
				{ fprintf(f[2], "Lex%*d", widthLex, i); comLex2[i]->recLexTyp(f[2]);
				  fprintf(f[2], "(%*.*f): ", (int)(-1.0*log10((double)(comLexAvgStr2[i]))+0.5)+widthDec+1, widthDec, comLexAvgStr2[i]);
				  // initialize MUstr;
				  MUstr=new char [11+3*(int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+3*overallpara.p_nLengthWord*((int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
				  comLex2[i]->buildMUstr(MUstr, getpAgent(G2low)->getpSemSpace()); fprintf(f[2],"%s\n", MUstr);
				  delete [] MUstr; MUstr=NULL;	// delete MUstr;
				}
			  fprintf(f[2],"\n");
			}
		  else fprintf(f[2], "\n");
		  fprintf(f[2], "Group 2: Global orders:\n");	// record group 2's global order's potential per; per; pro;
		  for(i=0;i<numOrderTyp1;i++)
			{ if(i==0) { fprintf(f[2], " SV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// SV;
			  else if(i==1) { fprintf(f[2], " VS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// VS;	
			}
		  for(i=numOrderTyp1;i<numOrderTyp1+numOrderTyp2;i++)
			{ if(i==2) { fprintf(f[2], "SVO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// SVO;
		  	  else if(i==3) { fprintf(f[2], "SOV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// SOV;
		  	  else if(i==4) { fprintf(f[2], "OSV(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// OSV;
		  	  else if(i==5) { fprintf(f[2], "VSO(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// VSO;
		  	  else if(i==6) { fprintf(f[2], "VOS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// VOS;
		  	  else if(i==7) { fprintf(f[2], "OVS(%*.*f,%*.*f,%*.*f);\n", widthUR+widthDec+1, widthDec, syn2[i][0], widthUR+widthDec+1, widthDec, syn2[i][1], widthUR+widthDec+1, widthDec, syn2[i][2]); }	// OVS;
			}
		  fprintf(f[2], "Group 2: Local orders:\n");	// record group 2's local order's potential per; per; pro;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ if(i==0) { fprintf(f[2], "SV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// SV local order;
		  	  else if(i==1) { fprintf(f[2], "VS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// VS local order;
			  else if(i==2) { fprintf(f[2], "VO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// VO local order;
			  else if(i==3) { fprintf(f[2], "OV(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// OV local order;
			  else if(i==4) { fprintf(f[2], "SO(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// SO local order;
			  else if(i==5) { fprintf(f[2], "OS(%*.*f %*.*f %*.*f);\n", widthLocSyn+widthDec+1, widthDec, Localsyn2[i][0], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][1], widthLocSyn+widthDec+1, widthDec, Localsyn2[i][2]); }	// OS local order;			  	
		  	}
		  fprintf(f[2],"\n");
		  // delete syn2;
		  for(i=0;i<numOrderTyp1+numOrderTyp2;i++)
		  	{ delete [] syn2[i]; syn2[i]=NULL; }
		  delete [] syn2; syn2=NULL;
		  // delete Localsyn2;
		  for(i=0;i<numOrderTyp2;i++)
		  	{ delete [] Localsyn2[i]; Localsyn2[i]=NULL; }
		  delete [] Localsyn2; Localsyn2=NULL;
		}
	fclose(f[2]);
	
	// test and record commLex's network in f[3];
	if((f[3]=fopen(fileNam[3], "a+"))==NULL) { printf("Can't create %s\n", fileNam[3]); exit(1); }
	if((gen==0)&&(com==0)) fprintf(f[3], "Initialization:\n");
	else
		{ if(getHorObliMix()==0) fprintf(f[3], "Com=%*d:\n", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[3], "Gen=%*d:\n", widthGen, gen);
		}
	if(getNumGroup()==1)
		{ // 1 group;
		  fprintf(f[3], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f;\nREall=%*.*f(%*.*f,%*.*f), ComLex=%*d (%*d,%*d)\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(getCalAmbiguity()==1) fprintf(f[3], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  if(getRecURiniser()==1) fprintf(f[3], "URini=%*.*f; URser=%*.*f;\n", widthUR+widthDec+1, widthDec, URini, widthUR+widthDec+1, widthDec, URser);
		  if(numcomLex!=0)
			{ // test and record commLex's network;
			  // check common categories among these common lexical rules;
			  for(i=0;i<getNumAgent();i++)
			  	{ numCatLink=0; getpAgent(i)->getpLTMem()->chkCatLink(CatLink, &numCatLink, comLex, numcomLex);
			  	  if(numCatLink!=0)
			  	  	{ fprintf(f[3], "Agent[%*d] has %d CatLink:\n", widthAgent, i, numCatLink); 
			  	  	  for(j=0;j<numCatLink;j++)
			  	  		{ for(k=0;k<numcomLex;k++)
			  	  			fprintf(f[3], "%d ", CatLink[j][k]);
				  		  fprintf(f[3],"\n");
			  	  		}
					  // delete CatLink;
					  for(j=0;j<numCatLink;j++)
					  	{ delete [] CatLink[j]; CatLink[j]=NULL; }
					  delete [] CatLink; CatLink=NULL;
			  	  	}
				  else fprintf(f[3], "Agent[%*d] has 0 CatLink\n", widthAgent, i);
			  	}
			  fprintf(f[3],"\n");
			}
		  else fprintf(f[3],"\n");
		  // recollect comLex and comLexAvgStr;
		  if(numcomLex!=0) 
			{ delete [] comLex; comLex=NULL; 
			  delete [] comLexAvgStr; comLexAvgStr=NULL;
			  numcomLex=0; 
			}
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  // Whole group;
		  fprintf(f[3], "TotalMean=%*d(%*d+%*d); UR=%*.*f; Disp=%*.*f; REall=%*.*f(%*.*f,%*.*f), ComLex=%*d (%*d,%*d)\n", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, REall, widthUR+widthDec+1, widthDec, REholist, widthUR+widthDec+1, widthDec, REcomp, widthLex, numcomLex, widthLex, numcomHolist, widthLex, numcomComp);
		  if(getCalAmbiguity()==1) fprintf(f[3], "Amb_a=%*.*f; Amb_b=%*.*f; Amb_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c);
		  if(numcomLex!=0)
			{ // test and record commLex's network;
			  // check common categories among these common lexical rules;
			  for(i=0;i<getNumAgent();i++)
			  	{ numCatLink=0; getpAgent(i)->getpLTMem()->chkCatLink(CatLink, &numCatLink, comLex, numcomLex);
			  	  if(numCatLink!=0)
			  	  	{ fprintf(f[3], "Agent[%*d] has %d CatLink:\n", widthAgent, i, numCatLink); 
			  	  	  for(j=0;j<numCatLink;j++)
			  	  		{ for(k=0;k<numcomLex;k++)
			  	  			fprintf(f[3], "%d ", CatLink[j][k]);
				  		  fprintf(f[3],"\n");
			  	  		}
					  // delete CatLink;
					  for(j=0;j<numCatLink;j++)
					  	{ delete [] CatLink[j]; CatLink[j]=NULL; }
					  delete [] CatLink; CatLink=NULL;
			  	  	}
				  else fprintf(f[3], "Agent[%*d] has 0 CatLink\n", widthAgent, i);
			  	}
			  fprintf(f[3],"\n");
			}
		  else fprintf(f[3],"\n");
		  // recollect comLex and comLexAvgStr;
		  if(numcomLex!=0) 
			{ delete [] comLex; comLex=NULL; 
			  delete [] comLexAvgStr; comLexAvgStr=NULL;
			  numcomLex=0; 
			}

		  // Group 1;
		  fprintf(f[3], "TotalMean=%*d(%*d+%*d); UR1=%*.*f; Disp1=%*.*f;\nREall1=%*.*f(%*.*f,%*.*f), ComLex1=%*d (%*d,%*d)\n", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, REall1, widthUR+widthDec+1, widthDec, REholist1, widthUR+widthDec+1, widthDec, REcomp1, widthLex, numcomLex1, widthLex, numcomHolist1, widthLex, numcomComp1);
		  if(getCalAmbiguity()==1) fprintf(f[3], "Amb1_a=%*.*f; Amb1_b=%*.*f; Amb1_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb1_a, widthUR+widthDec+1, widthDec, Amb1_b, widthUR+widthDec+1, widthDec, Amb1_c);
		  if(getRecURiniser()==1) fprintf(f[3], "URini1=%*.*f; URser1=%*.*f;\n", widthUR+widthDec+1, widthDec, URini1, widthUR+widthDec+1, widthDec, URser1);
		  if(numcomLex1!=0)
			{ // test and record commLex's network;
			  // check common categories among these common lexical rules;
			  for(i=G1low;i<G1up;i++)
			  	{ numCatLink=0; getpAgent(i)->getpLTMem()->chkCatLink(CatLink, &numCatLink, comLex1, numcomLex1);
			  	  if(numCatLink!=0)
			  	  	{ fprintf(f[3], "Agent[%*d] has %d CatLink:\n", widthAgent, i, numCatLink); 
			  	  	  for(j=0;j<numCatLink;j++)
			  	  		{ for(k=0;k<numcomLex1;k++)
			  	  			fprintf(f[3], "%d ", CatLink[j][k]);
				  		  fprintf(f[3],"\n");
			  	  		}
					  // delete CatLink;
					  for(j=0;j<numCatLink;j++)
					  	{ delete [] CatLink[j]; CatLink[j]=NULL; }
					  delete [] CatLink; CatLink=NULL;
			  	  	}
				  else fprintf(f[3], "Agent[%*d] has 0 CatLink\n", widthAgent, i);
			  	}
			  fprintf(f[3],"\n");
			}
		  else fprintf(f[3],"\n");
		  // recollect comLex1 and comLexAvgStr1;
		  if(numcomLex1!=0) 
			{ delete [] comLex1; comLex1=NULL; 
			  delete [] comLexAvgStr1; comLexAvgStr1=NULL;
			  numcomLex1=0; 
			}

		  // Group 2;
		  fprintf(f[3], "TotalMean=%*d(%*d+%*d); UR2=%*.*f; Disp2=%*.*f;\nREall2=%*.*f(%*.*f,%*.*f), ComLex2=%*d (%*d,%*d)\n", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, REall2, widthUR+widthDec+1, widthDec, REholist2, widthUR+widthDec+1, widthDec, REcomp2, widthLex, numcomLex2, widthLex, numcomHolist2, widthLex, numcomComp2);
		  if(getCalAmbiguity()==1) fprintf(f[3], "Amb2_a=%*.*f; Amb2_b=%*.*f; Amb2_c=%*.*f;\n", widthUR+widthDec+1, widthDec, Amb2_a, widthUR+widthDec+1, widthDec, Amb2_b, widthUR+widthDec+1, widthDec, Amb2_c);
		  if(getRecURiniser()==1) fprintf(f[3], "URini2=%*.*f; URser2=%*.*f;\n", widthUR+widthDec+1, widthDec, URini2, widthUR+widthDec+1, widthDec, URser2);
		  if(numcomLex2!=0)
			{ // test and record commLex's network;
			  // check common categories among these common lexical rules;
			  for(i=G2low;i<G2up;i++)
			  	{ numCatLink=0; getpAgent(i)->getpLTMem()->chkCatLink(CatLink, &numCatLink, comLex2, numcomLex2);
			  	  if(numCatLink!=0)
			  	  	{ fprintf(f[3], "Agent[%*d] has %d CatLink:\n", widthAgent, i, numCatLink); 
			  	  	  for(j=0;j<numCatLink;j++)
			  	  		{ for(k=0;k<numcomLex2;k++)
			  	  			fprintf(f[3], "%d ", CatLink[j][k]);
				  		  fprintf(f[3],"\n");
			  	  		}
					  // delete CatLink;
					  for(j=0;j<numCatLink;j++)
					  	{ delete [] CatLink[j]; CatLink[j]=NULL; }
					  delete [] CatLink; CatLink=NULL;
			  	  	}
				  else fprintf(f[3], "Agent[%*d] has 0 CatLink\n", widthAgent, i);
			  	}
			  fprintf(f[3],"\n");
			}
		  else fprintf(f[3],"\n");
		  // recollect comLex2 and comLexAvgStr2;
		  if(numcomLex2!=0) 
			{ delete [] comLex2; comLex2=NULL; 
			  delete [] comLexAvgStr2; comLexAvgStr2=NULL;
			  numcomLex2=0; 
			}
		}
	fclose(f[3]);
	
	// record order information in f[4];
	if((f[4]=fopen(fileNam[4],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[4]); exit(1); }
	// for each mean, record the used order in production and perception;
	if(getHorObliMix()==0) fprintf(f[4], "%*d ", widthCom, com);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[4], "%*d ", widthGen, gen);
	if(getNumGroup()==1)
		{ // 1 group;
		  fprintf(f[4], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  fprintf(f[4], "%*d %*d ", widthUR, getpAgent(0)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(0)->getpSemSpace()->getNumMean1());
		  for(i=0;i<numIntgMean;i++)
			{ if(i<numSVMean)
			  	{ // "Predicate<Agent>" meanings;
			  	  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPro[i][0], widthUR+widthDec+1, widthDec, OrdPro[i][1]);	// Production;
				  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPer[i][0], widthUR+widthDec+1, widthDec, OrdPer[i][1]);	// Perception;
			  	}
			  else
			  	{ // "Predicate<Agent, Patient>" meanings;
			  	  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
				  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPro[i][j]);	// Production;
				  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
			  	  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPer[i][j]);	// Perception;
				}
			}	
		  // delete OrdPro and OrdPer;
		  for(i=0;i<numIntgMean;i++)
			{ delete [] OrdPro[i]; OrdPro[i]=NULL; delete [] OrdPer[i]; OrdPer[i]=NULL; }
		  delete [] OrdPro; OrdPro=NULL; delete [] OrdPer; OrdPer=NULL;
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  fprintf(f[4], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  fprintf(f[4], "%*d %*d ", widthUR, getpAgent(0)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(0)->getpSemSpace()->getNumMean1());
		  // Whole group;
		  for(i=0;i<numIntgMean;i++)
			{ if(i<numSVMean)
			  	{ // "Predicate<Agent>" meanings;
			  	  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPro[i][0], widthUR+widthDec+1, widthDec, OrdPro[i][1]);	// Production;
				  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPer[i][0], widthUR+widthDec+1, widthDec, OrdPer[i][1]);	// Perception;
			  	}
			  else
			  	{ // "Predicate<Agent, Patient>" meanings;
			  	  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
				  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPro[i][j]);	// Production;
				  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
			  	  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPer[i][j]);	// Perception;
				}
			}	
		  // delete OrdPro and OrdPer;
		  for(i=0;i<numIntgMean;i++)
			{ delete [] OrdPro[i]; OrdPro[i]=NULL; delete [] OrdPer[i]; OrdPer[i]=NULL; }
		  delete [] OrdPro; OrdPro=NULL; delete [] OrdPer; OrdPer=NULL;

		  // Group 1;
		  for(i=0;i<numIntgMean;i++)
			{ if(i<getpAgent(G1low)->getpSemSpace()->getNumMean1())
			  	{ // "Predicate<Agent>" meanings;
			  	  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPro1[i][0], widthUR+widthDec+1, widthDec, OrdPro1[i][1]);	// Production;
				  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPer1[i][0], widthUR+widthDec+1, widthDec, OrdPer1[i][1]);	// Perception;
			  	}
			  else
			  	{ // "Predicate<Agent, Patient>" meanings;
			  	  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
				  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPro1[i][j]);	// Production;
				  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
			  	  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPer1[i][j]);	// Perception;
				}
			}	
		  // delete OrdPro1 and OrdPer1;
		  for(i=0;i<numIntgMean;i++)
			{ delete [] OrdPro1[i]; OrdPro1[i]=NULL; delete [] OrdPer1[i]; OrdPer1[i]=NULL; }
		  delete [] OrdPro1; OrdPro1=NULL; delete [] OrdPer1; OrdPer1=NULL;

		  // Group 2;
		  for(i=0;i<numIntgMean;i++)
			{ if(i<getpAgent(G2low)->getpSemSpace()->getNumMean1())
			  	{ // "Predicate<Agent>" meanings;
			  	  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPro2[i][0], widthUR+widthDec+1, widthDec, OrdPro2[i][1]);	// Production;
				  fprintf(f[4], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, OrdPer2[i][0], widthUR+widthDec+1, widthDec, OrdPer2[i][1]);	// Perception;
			  	}
			  else
			  	{ // "Predicate<Agent, Patient>" meanings;
			  	  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
				  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPro2[i][j]);	// Production;
				  for(j=numOrderTyp1;j<numOrderTyp1+numOrderTyp2;j++)
			  	  	fprintf(f[4], "%*.*f ", widthUR+widthDec+1, widthDec, OrdPer2[i][j]);	// Perception;
				}
			}	
		  // delete OrdPro2 and OrdPer2;
		  for(i=0;i<numIntgMean;i++)
			{ delete [] OrdPro2[i]; OrdPro2[i]=NULL; delete [] OrdPer2[i]; OrdPer2[i]=NULL; }
		  delete [] OrdPro2; OrdPro2=NULL; delete [] OrdPer2; OrdPer2=NULL;
		}
	fprintf(f[4],"\n");
	fclose(f[4]);
	
	// record each agent's order in f[5];
	if((f[5]=fopen(fileNam[5],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[5]); exit(1); }
	if(getHorObliMix()==0) fprintf(f[5], "%*d ", widthCom, com);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[5], "%*d ", widthGen, gen);
	if(getNumGroup()==1)
		{ // 1 group; 
		  fprintf(f[5], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  fprintf(f[5], "%*d %*d %*d %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR);
		  for(i=0;i<getNumAgent();i++)
			{ for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPro[i][j]);	// Production;		  
		  	  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPer[i][j]);	// Perception;
			}
		  // delete eachAgOrdPro and eachAgOrdPer;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] eachAgOrdPro[i]; eachAgOrdPro[i]=NULL; delete [] eachAgOrdPer[i]; eachAgOrdPer[i]=NULL; }
		  delete [] eachAgOrdPro; eachAgOrdPro=NULL; delete [] eachAgOrdPer; eachAgOrdPer=NULL;
		}
	else if(getNumGen()==2)
		{ // 2 groups;
		  fprintf(f[5], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  // Whole group;
		  fprintf(f[5], "%*d %*d %*d %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR);
		  for(i=0;i<getNumAgent();i++)
			{ for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPro[i][j]);	// Production;		  
		  	  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPer[i][j]);	// Perception;
			}
		  // delete eachAgOrdPro and eachAgOrdPer;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] eachAgOrdPro[i]; eachAgOrdPro[i]=NULL; delete [] eachAgOrdPer[i]; eachAgOrdPer[i]=NULL; }
		  delete [] eachAgOrdPro; eachAgOrdPro=NULL; delete [] eachAgOrdPer; eachAgOrdPer=NULL;

		  // Group 1;
		  fprintf(f[5], "%*d %*d %*d %*.*f ", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1);
		  for(i=G1low;i<G1up;i++)
			{ for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdProGroup[i][j]);	// Production;		  
		  	  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPerGroup[i][j]);	// Perception;
			}		  
		  // Group 2;
		  fprintf(f[5], "%*d %*d %*d %*.*f ", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2);
		  for(i=G2low;i<G2up;i++)
			{ for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdProGroup[i][j]);	// Production;		  
		  	  for(j=0;j<numOrderTyp1+numOrderTyp2;j++)
		  		fprintf(f[5], "%*.*f ", widthUR+widthDec+1, widthDec, eachAgOrdPerGroup[i][j]);	// Perception;
			}		  
		  // delete eachAgOrdProGroup and eachAgOrdPerGroup;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] eachAgOrdProGroup[i]; eachAgOrdProGroup[i]=NULL; delete [] eachAgOrdPerGroup[i]; eachAgOrdPerGroup[i]=NULL; }
		  delete [] eachAgOrdProGroup; eachAgOrdProGroup=NULL; delete [] eachAgOrdPerGroup; eachAgOrdPerGroup=NULL;
		}
	fprintf(f[5],"\n");
	fclose(f[5]);
	
	// record eachUR and displacement in f[6];
	if((f[6]=fopen(fileNam[6],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[6]); exit(1); }
	if(getHorObliMix()==0) fprintf(f[6], "%*d ", widthCom, com);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[6], "%*d ", widthGen, gen);
	if(getNumGroup()==1)
		{ // 1 group;
		  fprintf(f[6], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  fprintf(f[6], "%*d %*d %*d %*.*f %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp);
		  for(i=0;i<getNumAgent();i++)
			fprintf(f[6], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, eachUR[i], widthUR+widthDec+1, widthDec, displacement[i]);
		  // delete eachUR and displacement;
		  delete [] eachUR; eachUR=NULL;
		  delete [] displacement; displacement=NULL;
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  fprintf(f[6], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  // Whole group;
		  fprintf(f[6], "%*d %*d %*d %*.*f %*.*f ", widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp);
		  for(i=0;i<getNumAgent();i++)
			fprintf(f[6], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, eachUR[i], widthUR+widthDec+1, widthDec, displacement[i]);
		  // delete eachUR and displacement;
		  delete [] eachUR; eachUR=NULL;
		  delete [] displacement; displacement=NULL;

		  // Group 1;
		  fprintf(f[6], "%*d %*d %*d %*.*f %*.*f ", widthUR, getpAgent(G1low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G1low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1);
		  for(i=G1low;i<G1up;i++)
			fprintf(f[6], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, eachURGroup[i], widthUR+widthDec+1, widthDec, displacementGroup[i]);
		  // Group 2;
		  fprintf(f[6], "%*d %*d %*d %*.*f %*.*f ", widthUR, getpAgent(G2low)->getpSemSpace()->getNumIntgMean(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean1(), widthUR, getpAgent(G2low)->getpSemSpace()->getNumMean2(), widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2);
		  for(i=G2low;i<G2up;i++)
			fprintf(f[6], "%*.*f %*.*f ", widthUR+widthDec+1, widthDec, eachURGroup[i], widthUR+widthDec+1, widthDec, displacementGroup[i]);
		  // delete eachURGroup and displacementGroup;
		  delete [] eachURGroup; eachURGroup=NULL;
		  delete [] displacementGroup; displacementGroup=NULL;
		}
	fprintf(f[6],"\n");
	fclose(f[6]);

	// record category size to f[7];
	if((f[7]=fopen(fileNam[7],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[7]); exit(1); }
	if(getHorObliMix()==0) fprintf(f[7], "%*d ", widthCom, com);
	else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[7], "%*d ", widthGen, gen);
	if(getNumGroup()==1)
		{ // 1 group;
		  fprintf(f[7], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  fprintf(f[7], "%*d %*d ", widthCat, overallpara.p_nMaxCat, widthV, (overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2));
		  fprintf(f[7], "%*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, AvgSnum, widthCat+widthDec+1, widthDec, AvgVnum, widthCat+widthDec+1, widthDec, AvgOnum, widthS+widthDec+1, widthDec, AvgSsize, widthV+widthDec+1, widthDec, AvgVsize, widthO+widthDec+1, widthDec, AvgOsize);
		  for(i=0;i<getNumAgent();i++)
			{ for(j=0;j<numSynRole;j++)
				fprintf(f[7], "%*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, catSize[i][3*j], widthCat+widthDec+1, widthDec, catSize[i][3*j+1], widthCat+widthDec+1, widthDec, catSize[i][3*j+2]);
			}
		  // delete catSize;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] catSize[i]; catSize[i]=NULL; }
		  delete [] catSize; catSize=NULL;	
		}
	else if(getNumGroup()==2)
		{ // 2 groups;
		  fprintf(f[7], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  fprintf(f[7], "%*d %*d ", widthCat, overallpara.p_nMaxCat, widthV, (overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2));
		  // Whole group;
		  fprintf(f[7], "%*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, AvgSnum, widthCat+widthDec+1, widthDec, AvgVnum, widthCat+widthDec+1, widthDec, AvgOnum, widthS+widthDec+1, widthDec, AvgSsize, widthV+widthDec+1, widthDec, AvgVsize, widthO+widthDec+1, widthDec, AvgOsize);
		  for(i=0;i<getNumAgent();i++)
			{ for(j=0;j<numSynRole;j++)
				fprintf(f[7], "%*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, catSize[i][3*j], widthCat+widthDec+1, widthDec, catSize[i][3*j+1], widthCat+widthDec+1, widthDec, catSize[i][3*j+2]);
			}
		  // delete catSize;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] catSize[i]; catSize[i]=NULL; }
		  delete [] catSize; catSize=NULL;

		  // Group 1;
		  fprintf(f[7], "%*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, AvgSnum1, widthCat+widthDec+1, widthDec, AvgVnum1, widthCat+widthDec+1, widthDec, AvgOnum1, widthS+widthDec+1, widthDec, AvgSsize1, widthV+widthDec+1, widthDec, AvgVsize1, widthO+widthDec+1, widthDec, AvgOsize1);
		  for(i=G1low;i<G1up;i++)
			{ for(j=0;j<numSynRole;j++)
				fprintf(f[7], "%*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j], widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j+1], widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j+2]);
			}
		  // Group 2;
		  fprintf(f[7], "%*.*f %*.*f %*.*f %*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, AvgSnum2, widthCat+widthDec+1, widthDec, AvgVnum2, widthCat+widthDec+1, widthDec, AvgOnum2, widthS+widthDec+1, widthDec, AvgSsize2, widthV+widthDec+1, widthDec, AvgVsize2, widthO+widthDec+1, widthDec, AvgOsize2);
		  for(i=G2low;i<G2up;i++)
			{ for(j=0;j<numSynRole;j++)
				fprintf(f[7], "%*.*f %*.*f %*.*f ", widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j], widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j+1], widthCat+widthDec+1, widthDec, catSizeGroup[i][3*j+2]);
			}
		  // delete catSizeGroup;
		  for(i=0;i<getNumAgent();i++)
			{ delete [] catSizeGroup[i]; catSizeGroup[i]=NULL; }
		  delete [] catSizeGroup; catSizeGroup=NULL;
		}
	fprintf(f[7],"\n");
	fclose(f[7]);

	if((getComMode()==4)&&(f[8]!=NULL)&&(f[9]!=NULL))
		{ // record agent's location related paramters;
		  // record location information to f[8];
		  if((f[8]=fopen(fileNam[8],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[8]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[8], "%*d ", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[8], "%*d ", widthGen, gen);
		  if(getNumGroup()==1) fprintf(f[8], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, 0, widthAgent, getNumAgent(), widthAgent, 0, widthAgent, 0);	// store numGroup;
		  else if(getNumGroup()==2) fprintf(f[8], "%*d %*d %*d %*d %*d ", widthGroup, getNumGroup(), widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	// store numGroup;
		  fprintf(f[8], "%*d %*d %*d %*d %*d %*.*f ", (int)(log10((double)(getWorldX()))+1), getWorldX(), (int)(log10((double)(getWorldY()))+1), getWorldY(), widthUR, numIntgMean, widthUR, numSVMean, widthUR, numSVOMean, widthUR+widthDec+1, widthDec, UR);
		  // record LocX, LocY, neighborSize, neighborUR;
		  for(i=0;i<getNumAgent();i++)
		  	fprintf(f[8], "%*d %*d %*d %*.*f %*d ", (int)(log10((double)(getWorldX()))+1), getpAgent(i)->getLocX(), (int)(log10((double)(getWorldY()))+1), getpAgent(i)->getLocY(), widthAgent, neighborSize[i], widthUR+widthDec+1, widthDec, neighborUR[i], (int)(log10(overallpara.p_nMaxBufSize)+1), NoneighborComLex[i]);
		  // record upper triangle matrix of AdjMatrix;
		  for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
		  	//fprintf(f[8], "%2.1f ", ((FLOAT_SM_EQ(1.0-AdjDist[i], 0.0))?_MinDist:1.0-AdjDist[i]);	// for adjacent matrix;
		  	fprintf(f[8], "%*.*f ", (int)(log10((double)(sqrt((double)(getWorldX()*getWorldX()+getWorldY()*getWorldY()))))+1)+1+1, 1, AdjDist[i]);	// for distance matrix; 
		  fprintf(f[8],"\n");
		  fclose(f[8]);

		  // record each agent's neighbor information to f[9];
		  if((f[9]=fopen(fileNam[9],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[9]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[9], "Com=%*d\n", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[9], "Gen=%*d\n", widthGen, gen);
		  
		  // record neighborInd and NeighborComUtter;
		  fprintf(f[9], "Record eacg agent's neighbor and comUtter:\n");
		  for(i=0;i<getNumAgent();i++)
		  	{ fprintf(f[9], "Agent[%*d]'s neighbors (%*d): ", widthAgent, i, widthAgent, neighborSize[i]);
		  	  for(j=0;j<neighborSize[i];j++)
			  	fprintf(f[9], "Agent[%*d] ", widthAgent, NeighborInd[i][j]);
			  fprintf(f[9],"\n");
			  fprintf(f[9], "Agent[%*d]'s neighbors' common lexcial rules (%*d):\n", widthAgent, i, widthLex, NoneighborComLex[i]);
			  for(j=0;j<NoneighborComLex[i];j++)
			  	{ fprintf(f[9], "Lex%*d", widthLex, i); neighborComLex[i][j]->recLexTyp(f[9]);
				  fprintf(f[9], "(%*.*f): ", (int)(-1.0*log10((double)(neighborComLexAvgStr[i][j]))+0.5)+widthDec+1, widthDec, neighborComLexAvgStr[i][j]);
				  // initialize MUstr;
				  MUstr=new char [11+3*(int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+3*overallpara.p_nLengthWord*((int)(log10((double)(overallpara.p_nNumUtterSyl))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
				  neighborComLex[i][j]->buildMUstr(MUstr, getpAgent(0)->getpSemSpace()); fprintf(f[9],"%s\n", MUstr);
				  delete [] MUstr; MUstr=NULL;	// delete MUstr;	
			  	}
			  fprintf(f[9],"\n");
		  	}
		  fprintf(f[9],"\n");
		  fclose(f[9]);

		  delete [] NoneighborComLex; NoneighborComLex=NULL;	// delete NoneighborComLex;
		  delete [] neighborComLexAvgStr; neighborComLexAvgStr=NULL;	// delete neighborComLexAvgStr;
		  // delete neighborComLex;
		  for(i=0;i<getNumAgent();i++)
		  	{ delete [] neighborComLex[i]; neighborComLex[i]=NULL; }
		  delete [] neighborComLex; neighborComLex=NULL;
		  // delete NeighborInd;
		  for(i=0;i<getNumAgent();i++)
		  	{ delete [] NeighborInd[i]; NeighborInd[i]=NULL; }
		  delete [] NeighborInd; NeighborInd=NULL;
		  // delete Neighbor;
		  for(i=0;i<getNumAgent();i++)
		  	{ delete [] Neighbor[i]; Neighbor[i]=NULL; }
		  delete [] Neighbor; Neighbor=NULL;
		  delete [] neighborUR; neighborUR=NULL;	// delete neighborUR;
		  delete [] neighborSize; neighborSize=NULL;	// delete neighborSize;
		  delete [] AdjDist; AdjDist=NULL;	// delete AdjDist;
		}

	if((getComMode()==5)&&(f[10]!=NULL)&&(f[11]!=NULL)&&(adjMatrix!=NULL))
		{ // record agent's social network paramters;
		  if(((getSelfGrow()==1)||(getSelfGrow()==2))||((getSelfGrow()==0)&&(((getHorObliMix()==0)&&(com==0))||(((getHorObliMix()==1)||(getHorObliMix()==2))&&(gen==0)))))
		  	{ // record network parameters to f[10];
			  if((f[10]=fopen(fileNam[10],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[10]); exit(1); }
			  if(getHorObliMix()==0) fprintf(f[10], "%*d ", widthCom, com);
			  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[10], "%*d ", widthGen, gen);
			  // record the whole group's information;
			  if(numConCompList!=0) fprintf(f[10], "%*d %d %*d %*d %*d ", widthAgent, getNumAgent(), adjMatrix->getDirected(), widthAgent, numConCompList, widthAgent, sizeConCompList, widthbetwEdge, numedge);
			  else
			  	{ if(adjMatrix->getDirected()==0) fprintf(f[10], "%*d %d %*d %*d %*d ", widthAgent, getNumAgent(), adjMatrix->getDirected(), widthAgent, numConCompList, widthAgent, getNumAgent(), widthbetwEdge, (int)(getNumAgent()*(getNumAgent()-1)/_Twice));
				  else if(adjMatrix->getDirected()==1) fprintf(f[10], "%*d %d %*d %*d %*d ", widthAgent, getNumAgent(), adjMatrix->getDirected(), widthAgent, numConCompList, widthAgent, getNumAgent(), widthbetwEdge, getNumAgent()*(getNumAgent()-1));
			  	}
			  fprintf(f[10], "%*.*f %*.*f %*.*f ", widthDegShortPath+widthNetDec+1, widthNetDec, degAvg, widthCoef+widthNetDec+1, widthNetDec, coefAvg, widthDegShortPath+widthNetDec+1, widthNetDec, shortPathAvg);
			  for(i=0;i<getNumAgent();i++)
			  	fprintf(f[10], "%*d ", widthDegShortPath, degree[i]);
			  if(numConCompList!=0)
			  	{ if(sizeConCompList==getNumAgent())
			  		{ // record biggest connected component's network paramters (same as degAvg, coefAvg, shortPathAvg;
					  fprintf(f[10], "%*.*f %*.*f %*.*f ", widthDegShortPath+widthNetDec+1, widthNetDec, degAvg, widthCoef+widthNetDec+1, widthNetDec, coefAvg, widthDegShortPath+widthNetDec+1, widthNetDec, shortPathAvg);
			  		  // record biggest connected component's node index (same as index);  
			  	  	  for(i=0;i<getNumAgent();i++)
					  	fprintf(f[10], "%*d ", widthAgent, index[i]);
					  // record biggest connected component's degree (same as degree);
				  	  for(i=0;i<getNumAgent();i++)
					  	fprintf(f[10], "%*d ", widthDegShortPath, degree[i]);
					  // record biggest connected component's betweenness;
					  for(i=0;i<getNumAgent();i++)
					  	fprintf(f[10], "%*.*f ", widthbetwNode+widthNetDec+1, widthNetDec, betwNode[i]);
					  if(adjMatrix->getDirected()==0)
					  	{ for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					  		fprintf(f[10], "%*d %*d %*.*f ", widthAgent, (int)(betwEdge[i][0]), widthAgent, (int)(betwEdge[i][1]), widthbetwEdge+widthNetDec+1, widthNetDec, betwEdge[i][2]);
					  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					  		fprintf(f[10], "%*d %*d %*.*f ", widthAgent, (int)(betwEdge[i][0]), widthAgent, (int)(betwEdge[i][1]), widthbetwEdge+widthNetDec+1, widthNetDec, betwEdge[i][2]);
					  	}
					  
					  delete [] betwNode; betwNode=NULL;	// delete betwNode;
				  	  if(adjMatrix->getDirected()==0)
				  	  	{ for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					  		{ delete [] betwEdge[i]; betwEdge[i]=NULL; }
					  	  delete [] betwEdge; betwEdge=NULL;	// delete betwEdge;
				  	  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					  		{ delete [] betwEdge[i]; betwEdge[i]=NULL; }
					  	  delete [] betwEdge; betwEdge=NULL;	// delete betwEdge;
					  	}
			  		}
			  	  else
			  	  	{ // record biggest connected component's network paramters;
			  	  	  fprintf(f[10], "%*.*f %*.*f %*.*f ", widthDegShortPath+widthNetDec+1, widthNetDec, degAvgC, widthCoef+widthNetDec+1, widthNetDec, coefAvgC, widthDegShortPath+widthNetDec+1, widthNetDec, shortPathAvgC);
			  		  // record biggest connected component's node index;  
			  	  	  for(i=0;i<getNumAgent();i++)
			  	  		fprintf(f[10], "%*d ", widthAgent, index[i]);
				  	  // record biggest connected component's degree;
				  	  for(i=0;i<getNumAgent();i++)
					  	fprintf(f[10], "%*d ", widthDegShortPath, degreeC[i]);
					  // record biggest connected component's betweenness;
					  for(i=0;i<getNumAgent();i++)
					  	fprintf(f[10], "%*.*f ", widthbetwNode+widthNetDec+1, widthDec, betwNode[i]); 
					  if(adjMatrix->getDirected()==0)
					  	{ for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					   		fprintf(f[10], "%*d %*d %*.*f ", widthAgent, (int)(betwEdge[i][0]), widthAgent, (int)(betwEdge[i][1]), widthbetwEdge+widthNetDec+1, widthNetDec, betwEdge[i][2]);
					  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					   		fprintf(f[10], "%*d %*d %*.*f ", widthAgent, (int)(betwEdge[i][0]), widthAgent, (int)(betwEdge[i][1]), widthbetwEdge+widthNetDec+1, widthNetDec, betwEdge[i][2]);
					  	}
					  delete [] degreeC; degreeC=NULL;	// delete degreeC;
					  delete [] betwNode; betwNode=NULL;	// delete betwNode;
					  if(adjMatrix->getDirected()==0)
					  	{ for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)
					  		{ delete [] betwEdge[i]; betwEdge[i]=NULL; }
					  	  delete [] betwEdge; betwEdge=NULL;	// delete betwEdge;
					  	}
					  else if(adjMatrix->getDirected()==1)
					  	{ for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
					  		{ delete [] betwEdge[i]; betwEdge[i]=NULL; }
					  	  delete [] betwEdge; betwEdge=NULL;	// delete betwEdge;
					  	}
					}
				  for(i=0;i<numConCompList;i++)
				  	{ delete [] ConCompList[i]; ConCompList[i]=NULL; }
				  delete [] ConCompList; ConCompList=NULL;	// delete ConCompList;
			  	}
			  else
			  	{ // no biggest connected component; use -1 or 0.0 to fill the place;
			  	  fprintf(f[10], "0.00 0.00 %*d ", widthDegShortPath, adjMatrix->getBigestCon());	// degAvgC, coefAvgC, shortPathAvgC;
				  // record biggest connected component's node index;
				  for(i=0;i<getNumAgent();i++)
				  	fprintf(f[10], "%*d ", widthAgent, i);	// index;
				  // record biggest connected component's degree (same as degree);
				  for(i=0;i<getNumAgent();i++)
				  	fprintf(f[10], "0.00 ");
				  // record biggest connected component's betweenness;
				  for(i=0;i<getNumAgent();i++)
				  	fprintf(f[10], "0.00 ");
				  if(adjMatrix->getDirected()==0)
				  	{ for(i=0;i<(int)(getNumAgent()*(getNumAgent()-1)/_Twice);i++)	
				  		fprintf(f[10], "0 0 0.00 ");
				  	}
				  else if(adjMatrix->getDirected()==1)
				  	{ for(i=0;i<getNumAgent()*(getNumAgent()-1);i++)
				  		fprintf(f[10], "0 0 0.00 ");
				  	}
			  	}		  	
			  delete [] degree; degree=NULL;	// delete degree;
			  delete [] index; index=NULL;	// delete index;
			  fprintf(f[10],"\n");
			  fclose(f[10]);

			  // record adjMatrix to f[11];
			  if((f[11]=fopen(fileNam[11],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[11]); exit(1); }
			  if(getHorObliMix()==0) fprintf(f[11], "Com=%*d: NumAgent=%*d\n", widthCom, com, widthAgent, getNumAgent());
			  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[11], "Gen=%*d: NumAgent=%*d\n", widthGen, gen, widthAgent, getNumAgent());
			  for(i=0;i<adjMatrix->getSize();i++)
			  	{ for(j=0;j<adjMatrix->getSize();j++)
					{ if(getSelfGrow()==0)
			  			{ if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(i, j), adjMatrix->getConWeiLow())) fprintf(f[10], "0 ");
			  			  else if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(i, j), adjMatrix->getConWeiUp())) fprintf(f[10], "1 ");
			  			}
					  else fprintf(f[11], "%*.*f ", widthNetWei+widthNetWeiDec+1, widthNetWeiDec, adjMatrix->getAdjMatrixMember(i, j));
			  		}
				  fprintf(f[11],"\n");
			  	}
			  fprintf(f[11],"\n");

			  // record individual agent's connection weight or UR to f[11];
			  if((getSelfGrow()==0)||(getSelfGrow()==1)) fprintf(f[11], "Individual agent's connection weight:\n");
			  else if(getSelfGrow()==2) fprintf(f[11], "Individual agent's UR:\n");
			  for(i=0;i<getNumAgent();i++)
			  	fprintf(f[11], "%*.*f ", widthNetWei+widthNetWeiDec+1, widthNetWeiDec, indDeg_UR[i]);
			  fprintf(f[11],"\n");
			  delete [] indDeg_UR; indDeg_UR=NULL;	// delete indDeg_UR;
			  fprintf(f[11],"\n");
			  fclose(f[11]);		  
			}
		}

	if((getComMode()==6)&&(f[12]!=NULL))
		{ // record individual learning abilities to f[12];
		  if((f[12]=fopen(fileNam[12],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[12]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[12], "%*d ", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[12], "%*d ", widthGen, gen);
		  // 1 group;
		  avgLearnAbi=0.0;
		  for(i=0;i<getNumAgent();i++)
		  	{ avgLearnAbi+=getpAgent(i)->getCueReliabAg();
		  	  fprintf(f[12], "%*.*f ", 1+widthIndLearnAbi+1, widthIndLearnAbi, getpAgent(i)->getCueReliabAg());	// store DetLocOrdRate;
		  	}
		  fprintf(f[12], "%*.*f", 1+widthIndLearnAbi+1, widthIndLearnAbi, (double)(avgLearnAbi/(double)getNumAgent()));
		  fprintf(f[12], "\n");
		  fclose(f[12]);
		}
	
	if(getCalAmbiguity()==1)
		{ // record numPn, numPv, numPnv to f[13];
		  if((f[13]=fopen(fileNam[13],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[13]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[13], "%*d ", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[13], "%*d ", widthGen, gen);
		  fprintf(f[13], "%*d %*d ", (int)(log10((double)(overallpara.p_nNumSemAgent))+1), overallpara.p_nNumSemAgent, (int)(log10((double)(overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2))+1), overallpara.p_nNumSemPred1+overallpara.p_nNumSemPred2);
		  if(getNumGroup()==1) fprintf(f[13], "%*.*f %*.*f %*.*f %*.*f %*.*f %*d %*d %*d %*d %*d %*d", widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c, widthLex, numcomHolist+numcomComp, widthLex, numcomHolist, widthLex, numcomComp, widthLex, numHomoN, widthLex, numHomoV, widthLex, numHomoNV);	// 1 group;
		  else if(getNumGroup()==2)
		  	{ // 2 groups;
		  	  fprintf(f[13], "%*.*f %*.*f %*.*f %*.*f %*.*f %*d %*d %*d %*d %*d %*d ", widthUR+widthDec+1, widthDec, UR, widthUR+widthDec+1, widthDec, avgDisp, widthUR+widthDec+1, widthDec, Amb_a, widthUR+widthDec+1, widthDec, Amb_b, widthUR+widthDec+1, widthDec, Amb_c, widthLex, numcomHolist+numcomComp, widthLex, numcomHolist, widthLex, numcomComp, widthLex, numHomoN, widthLex, numHomoV, widthLex, numHomoNV);	// whole group;
			  fprintf(f[13], "%*.*f %*.*f %*.*f %*.*f %*.*f %*d %*d %*d %*d %*d %*d ", widthUR+widthDec+1, widthDec, UR1, widthUR+widthDec+1, widthDec, avgDisp1, widthUR+widthDec+1, widthDec, Amb1_a, widthUR+widthDec+1, widthDec, Amb1_b, widthUR+widthDec+1, widthDec, Amb1_c, widthLex, numcomHolist1+numcomComp1, widthLex, numcomHolist1, widthLex, numcomComp1, widthLex, numHomoN1, widthLex, numHomoV1, widthLex, numHomoNV1); // group 1;
			  fprintf(f[13], "%*.*f %*.*f %*.*f %*.*f %*.*f %*d %*d %*d %*d %*d %*d", widthUR+widthDec+1, widthDec, UR2, widthUR+widthDec+1, widthDec, avgDisp2, widthUR+widthDec+1, widthDec, Amb2_a, widthUR+widthDec+1, widthDec, Amb2_b, widthUR+widthDec+1, widthDec, Amb2_c, widthLex, numcomHolist2+numcomComp2, widthLex, numcomHolist2, widthLex, numcomComp2, widthLex, numHomoN2, widthLex, numHomoV2, widthLex, numHomoNV2);	// group 2;
			}
		  fprintf(f[13], "\n");
		  fclose(f[13]);
		}

	if(getRecMem()==1)
		{ // record memory capacity to f[14];
		  if((f[14]=fopen(fileNam[14],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[14]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[14], "%*d ", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[14], "%*d ", widthGen, gen);
		  fprintf(f[14], "%1d %*d %1d %*.*f ", getNumGroup(), widthAgent, getNumAgent(), getMemMutType(), widthUR+widthDec+1, widthDec, UR);
		  // record each individual's memory capacity;
		  for(i=0;i<getNumAgent();i++)
		  	{ // first, calculate the numbers of holistic and compositional lexical rules;
			  numLex=0; numHolist=0;
			  for(j=0;j<getpAgent(i)->getpLTMem()->getNumLexRule();j++)
			  	{ if(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexTyp()==0) numHolist++;
			  	  else if((getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexTyp()==1)||(getpAgent(i)->getpLTMem()->getpLexRuleList(j)->getLexTyp()==2)) numLex++;
			  	}
			  // second, calculate the number of compositional categories; 
			  numLexCat=0;
			  for(j=0;j<getpAgent(i)->getpLTMem()->getNumCat();j++)
			  	{ if((getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()==1)||(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()==2)||(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()==3)||(getpAgent(i)->getpLTMem()->getpCatList(j)->getThemRole()==4)) numLexCat++; 
			  	}
			  // finally, record results;
			  if((int)(log10((double)(getpAgent(i)->getpLTMem()->getNumLexRule()))+1)>widthLex) widthLex=(int)(log10((double)(getpAgent(i)->getpLTMem()->getNumLexRule()))+1);
			  if((int)(log10((double)(getpAgent(i)->getpLTMem()->getNumCat()))+1)>widthCat) widthCat=(int)(log10((double)(getpAgent(i)->getpLTMem()->getNumCat()))+1);
			  if((int)(log10((double)(getpAgent(i)->getpLTMem()->getNumSynRule()))+1)>widthSyn) widthSyn=(int)(log10((double)(getpAgent(i)->getpLTMem()->getNumSynRule()))+1);
			  fprintf(f[14], "%*d %*d %*d %*d %*d %*d %*d %*d %*d ", widthLex, getpAgent(i)->getpLTMem()->getNumLexRule(), widthLex, numLex, widthLex, numHolist, widthLex, getpAgent(i)->getpLTMem()->getMaxLexRule(), widthSyn, getpAgent(i)->getpLTMem()->getNumSynRule(), widthSyn, getpAgent(i)->getpLTMem()->getMaxSynRule(), widthCat, getpAgent(i)->getpLTMem()->getNumCat(), widthCat, numLexCat, widthCat, getpAgent(i)->getpLTMem()->getMaxCat());
			  // record buffer and IMMem sizes;
			  if(getpAgent(i)->getpBuffer()->getMaxBufSize()!=0) fprintf(f[14], "%*d ", (int)(log10((double)(getpAgent(i)->getpBuffer()->getMaxBufSize()))+1), getpAgent(i)->getpBuffer()->getMaxBufSize());
			  else fprintf(f[14], "0 ");
			  if(getpAgent(i)->getpIMMem()->getMaxNumCombOption()!=0) fprintf(f[14], "%*d ", (int)(log10((double)(getpAgent(i)->getpIMMem()->getMaxNumCombOption()))+1), getpAgent(i)->getpIMMem()->getMaxNumCombOption());
			  else fprintf(f[14], "0 ");			  
		  	}
		  fprintf(f[14], "\n");
		  fclose(f[14]);
		}

	if((getComMode()==8)&&(f[16]!=NULL))
		{ // record RC and memory capacity to f[16];
		  if((f[16]=fopen(fileNam[16],"a+"))==NULL) { printf("Can't open and append %s\n", fileNam[16]); exit(1); }
		  if(getHorObliMix()==0) fprintf(f[16], "%*d ", widthCom, com);
		  else if((getHorObliMix()==1)||(getHorObliMix()==2)) fprintf(f[16], "%*d ", widthGen, gen);
		  fprintf(f[16], "%1d %*d %*.*f ", getNumGroup(), widthAgent, getNumAgent(), widthUR+widthDec+1, widthDec, UR);
		  // first, record individuals' RC;
		  avgLearnAbi=0.0;
		  for(i=0;i<getNumAgent();i++)
			{ avgLearnAbi+=getpAgent(i)->getCueReliabAg();
			  fprintf(f[16], "%*.*f ", 1+widthIndLearnAbi+1, widthIndLearnAbi, getpAgent(i)->getCueReliabAg()); // store DetLocOrdRate;
			}
		  fprintf(f[16], "%*.*f ", 1+widthIndLearnAbi+1, widthIndLearnAbi, (double)(avgLearnAbi/(double)getNumAgent()));
		  // second, record individuals' memory capacity;
		  avgLTM=0.0; avgMaxLTM=0.0;
		  for(i=0;i<getNumAgent();i++)
		  	{ avgLTM+=(double)(getpAgent(i)->getpLTMem()->getNumLexRule());
		  	  avgMaxLTM+=(double)(getpAgent(i)->getpLTMem()->getMaxLexRule());
			  if((int)(log10((double)(getpAgent(i)->getpLTMem()->getNumLexRule()))+1)>widthLex) widthLex=(int)(log10((double)(getpAgent(i)->getpLTMem()->getNumLexRule()))+1);
			  fprintf(f[16], "%*d %*d ", widthLex, getpAgent(i)->getpLTMem()->getNumLexRule(), widthLex, getpAgent(i)->getpLTMem()->getMaxLexRule());
			}
		  fprintf(f[16], "%*.3f %*.3f", widthLex+4, (double)(avgLTM/(double)getNumAgent()), widthLex+4, (double)(avgMaxLTM/(double)getNumAgent()));
		  fprintf(f[16], "\n");
		  fclose(f[16]);
		}

	// after calculating the values of parameters, resume the random number generator's state;
	CRandomNumber::SetState(rulSeed, rnLeft, rpulNext, rpulState);
	rpulNext=NULL;	// recollect rpulNext;
	delete [] rpulState; rpulState=NULL;	// recollect rpulState;
}

void CSystem::HorInfoChange(CAgent *SpAgent, CAgent *LiAgent, int *NumPosFeedback)
{ // one information exchange in a horizontal transmission;
	assert((SpAgent!=NULL)&&(LiAgent!=NULL));
	CMeanUtter *MU=new CMeanUtter; assert(MU!=NULL);
	CMeanUtter *tempMU=new CMeanUtter; assert(tempMU!=NULL);	// keep speaker's meanutter to check whether the listener's comprehension accurately match the speaker's intended meaning;
	int feedback; bool inBufSuc;

  	// speaker's part;
  	SpAgent->ChoMeantoPro(MU, 0, -1); SpAgent->Production(MU, 0);	// speaker allows random creation;	
	if(MU->getpUtter()->getElement(0)!=-1)
		{ // speaker successfuly produces the utterance;
		  tempMU->setpMean(MU->getpMean());	// temporary store the speaker's intended meaning;
		  // listener's part;
		  feedback=0; inBufSuc=0; LiAgent->Perception(MU, &feedback, &inBufSuc, 0);	// horizontal transmission, listener randomly selects cues;
		  if(NumPosFeedback!=NULL)
		  	{ if(getSucCri()==0) { if(feedback==1) (*NumPosFeedback)++; }	// record the number of "successful" communication;
		 	  else if(getSucCri()==1) { if((feedback==1)&&(*(tempMU->getpMean())==*(MU->getpMean()))) (*NumPosFeedback)++; }	// record the number of successful communication;
		  	}
		  // update speaker;
	  	  SpAgent->UpdIMMem(feedback); SpAgent->getpLTMem()->RedIdentSynRule();
		  if(getDecFlag()==1) SpAgent->DecLex();	// decompose holistic and phrase rules;
	  	  // update listener;
		  LiAgent->UpdIMMem(feedback); LiAgent->AcqLexCatSyn(MU, feedback, inBufSuc);
		  LiAgent->getpLTMem()->RedIdentSynRule();
		  if(getDecFlag()==1) LiAgent->DecLex();	// decompose holistic and phrase rules;
		}
	delete MU; MU=NULL;	// release MU;
	delete tempMU; tempMU=NULL;	// release tempMU;
}

void CSystem::VerInfoChange(CAgent *SpAgent, CAgent *newAgent, int *NumPosFeedback)
{ // one information exchange in a vertical transmission;
	assert((SpAgent!=NULL)&&(newAgent!=NULL));
	CMeanUtter *MU=new CMeanUtter; assert(MU!=NULL);
	CMeanUtter *tempMU=new CMeanUtter; assert(tempMU!=NULL);	// keep speaker's meanutter to check whether the listener's comprehension accurately match the speaker's intended meaning;
	int feedback; bool inBufSuc;

	// speaker's part;
  	SpAgent->ChoMeantoPro(MU, 0, -1); 
	if(getVerTranRandCrt()==0) SpAgent->Production(MU, 1);	// speaker does not allow random creation;
	else if(getVerTranRandCrt()==1) SpAgent->Production(MU, 0);	// speaker allows to random create;
	if(MU->getpUtter()->getElement(0)!=-1)
		{ // speaker successfuly produces the utterance;
		  tempMU->setpMean(MU->getpMean());	// temporary store the speaker's intended meaning;
		  // listener's part;
		  if(getVerTranWrongCue()==0) { feedback=0; inBufSuc=0; newAgent->Perception(MU, &feedback, &inBufSuc, 3); }	// vertical transmission, listener always gets the correct cues;
		  else if(getVerTranWrongCue()==1) { feedback=0; inBufSuc=0; newAgent->Perception(MU, &feedback, &inBufSuc, 0); }	// vertical transmission, listener random selects cues;
		  if(NumPosFeedback!=NULL)
		  	{ if(getSucCri()==0) { if(feedback==1) (*NumPosFeedback)++; }	// record the number of "successful" communication;
		 	  else if(getSucCri()==1) { if((feedback==1)&&(*(tempMU->getpMean())==*(MU->getpMean()))) (*NumPosFeedback)++; }	// record the number of successful communication;
		  	}
		  if(getSpUpd()==1)
		  	{ // speakers occasionally update their languages;
		  	  if(FLOAT_SM_EQ(Rand0_1, getSpUpdProb()))
		  	  	{ SpAgent->UpdIMMem(feedback); SpAgent->getpLTMem()->RedIdentSynRule();
		  		  if(getDecFlag()==1) SpAgent->DecLex();	// decompose holistic and phrase rules;
		  	  	}
		  	}
		  SpAgent->getpIMMem()->EmpOptionComb();
	 	  // update listener only;
		  newAgent->UpdIMMem(feedback); newAgent->AcqLexCatSyn(MU, feedback, inBufSuc); 
		  newAgent->getpLTMem()->RedIdentSynRule();
	  	  if(getDecFlag()==1) newAgent->DecLex();	// decompose holistic and phrase rules;
		}
	delete MU; MU=NULL;	// release MU;
	delete tempMU; tempMU=NULL;	// release tempMU;
}

void CSystem::SelfTalk(CAgent *SpAgent, CAgent *selfcopy, int *NumPosFeedback)
{ // self-talk;
 	assert((SpAgent!=NULL)&&(selfcopy!=NULL));
	CMeanUtter *MU=new CMeanUtter; assert(MU!=NULL);
	CMeanUtter *tempMU=new CMeanUtter; assert(tempMU!=NULL);	// keep speaker's meanutter to check whether the listener's comprehension accurately match the speaker's intended meaning;
	int feedback; bool inBufSuc;

	// speaker's part;
  	SpAgent->ChoMeantoPro(MU, 0, -1); SpAgent->Production(MU, 0);	// speaker produces the meaning;
	if(MU->getpUtter()->getElement(0)!=-1)
		{ // speaker successfuly produces the utterance;
		  tempMU->setpMean(MU->getpMean());	// temporary store the speaker's intended meaning;
		  AdjLTMem(selfcopy, SpAgent);	// adjust selfcopy->m_pLTMem;
		  // listener's part;
		  feedback=0; inBufSuc=0; selfcopy->Perception(MU, &feedback, &inBufSuc, 0);	// listener comprehends the utterance;
		  if(NumPosFeedback!=NULL)
		  	{ if(getSucCri()==0) { if(feedback==1) (*NumPosFeedback)++; }	// record the number of "successful" communication;
		 	  else if(getSucCri()==1) { if((feedback==1)&&(*(tempMU->getpMean())==*(MU->getpMean()))) (*NumPosFeedback)++; }	// record the number of successful communication;
		  	}
		  // update speaker;
		  SpAgent->UpdIMMem(feedback); SpAgent->getpLTMem()->RedIdentSynRule();
		  if(getDecFlag()==1) SpAgent->DecLex();	// decompose holistic and phrase rules;		  
		  AdjBuffer(SpAgent, selfcopy);	// adjust SpAgent->m_pBuffer;		  
		}
	delete MU; MU=NULL;	// release MU;
	delete tempMU; tempMU=NULL;	// release tempMU;
}

void CSystem::OneToManyInfoChange(CAgent *SpAgent, CAgent **Neighbor, int numNeighbor, int *NumPosFeedback)
{ // one speaker, many listeners communication;
	assert(SpAgent!=NULL); assert(Neighbor!=NULL); assert(NumPosFeedback!=NULL);
	CMeanUtter *MU=new CMeanUtter; assert(MU!=NULL);
	CMeanUtter *tempMU=new CMeanUtter; assert(tempMU!=NULL);	// keep speaker's meanutter to check whether the listener's comprehension accurately match the speaker's intended meaning;
	int feedback; bool inBufSuc;
	int i, NumPosFeedbackTemp=*NumPosFeedback;
	CAgent *LiAgent=NULL, *selfcopy=NULL;
	
	// speaker's part;
	SpAgent->ChoMeantoPro(MU, 0, -1); SpAgent->Production(MU, 0);	// speaker produces the meaning;
	if(MU->getpUtter()->getElement(0)!=-1)
		{ // speaker successfuly produces the utterance;
		  *tempMU=*MU;	// temporary store the speaker's MU;
		  if(getSelfTalkFlag()==0)
		  	{ // not allow self-talk;
			  for(i=0;i<numNeighbor;i++)
			  	{ if(Neighbor[i]!=SpAgent)
			  		{ *MU=*tempMU;	// get speaker's original MU;
			  	  	  LiAgent=Neighbor[i];
					  // listener's part;
		  			  feedback=0; inBufSuc=0; LiAgent->Perception(MU, &feedback, &inBufSuc, 0);	// horizontal transmission, listener randomly selects cues;
		  			  if(getSucCri()==0) { if(feedback==1) (*NumPosFeedback)++; }	// record the number of "successful" communication;
		 	  		  else if(getSucCri()==1) { if((feedback==1)&&(*(tempMU->getpMean())==*(MU->getpMean()))) (*NumPosFeedback)++; }	// record the number of successful communication;
		  			  // update listener;
	  	  			  LiAgent->UpdIMMem(feedback); LiAgent->AcqLexCatSyn(MU, feedback, inBufSuc); 
					  LiAgent->getpLTMem()->RedIdentSynRule();
	  	  			  if(getDecFlag()==1) LiAgent->DecLex();	// decompose holistic and phrase rules;
	  	  			  LiAgent=NULL;	// recollect LiAgent;
			  		}
			  	}
			  // update speaker;
			  if(FLOAT_BG_EQ((*NumPosFeedback-NumPosFeedbackTemp)/(double)(numNeighbor-1), getSucRat())) SpAgent->UpdIMMem(1); 
			  else SpAgent->UpdIMMem(0);
			  SpAgent->getpLTMem()->RedIdentSynRule();
	  	  	  if(getDecFlag()==1) SpAgent->DecLex();	// decompose holistic and phrase rules;
			}
		  else if(getSelfTalkFlag()==1)
		  	{ // allow self-talk;
			  for(i=0;i<numNeighbor;i++)
			  	{ if(Neighbor[i]==SpAgent)
			  		{ // self-talk;
					  *MU=*tempMU;	// get speaker's original MU;
			  	  	  // listener's part;
			  	  	  CrtSelfCopy(SpAgent, selfcopy);	// create selfcopy;

					  // self-talk;
					  // listener's part;
		  			  feedback=0; inBufSuc=0; selfcopy->Perception(MU, &feedback, &inBufSuc, 0);	// listener comprehends the utterance;
		  			  // update speaker;
		  			  SpAgent->UpdIMMem(feedback); SpAgent->getpLTMem()->RedIdentSynRule();
		  			  if(getDecFlag()==1) SpAgent->DecLex();	// decompose holistic and phrase rules;		  
		  			  AdjBuffer(SpAgent, selfcopy);	// adjust SpAgent->m_pBuffer;		  

					  EmpSelfCopy(selfcopy);	// empty selfcopy;
			  		}
			  	  else if(Neighbor[i]!=SpAgent)
			  	  	{ // no self-talk; 
					  *MU=*tempMU;	// get speaker's original MU;
			  	  	  LiAgent=Neighbor[i];
					  // listener's part;
		  			  feedback=0; inBufSuc=0; LiAgent->Perception(MU, &feedback, &inBufSuc, 0);	// horizontal transmission, listener randomly selects cues;
		  			  if(getSucCri()==0) { if(feedback==1) (*NumPosFeedback)++; }	// record the number of "successful" communication;
		 	  		  else if(getSucCri()==1) { if((feedback==1)&&(*(tempMU->getpMean())==*(MU->getpMean()))) (*NumPosFeedback)++; }	// record the number of successful communication;
		  			  // update listener;
	  	  			  LiAgent->UpdIMMem(feedback); LiAgent->AcqLexCatSyn(MU, feedback, inBufSuc); 
					  LiAgent->getpLTMem()->RedIdentSynRule();
	  	  			  if(getDecFlag()==1) LiAgent->DecLex();	// decompose holistic and phrase rules;
	  	  			  LiAgent=NULL;	// recollect LiAgent;
			  	  	}
			  	}
		  	}		  
		}
	delete MU; MU=NULL;	// release MU;
	delete tempMU; tempMU=NULL;	// release tempMU;
}

void CSystem::HorCom(CAgent *SpAgent, CAgent *LiAgent, int *NumPosFeedback)
{ // horizontal communication;
	assert((SpAgent!=NULL)&&(LiAgent!=NULL));
	if(getSelfTalkFlag()==0) assert(SpAgent!=LiAgent);
	CAgent *selfcopy=NULL;	// for self-talk;
	int i;

	if(getSelfTalkFlag()==0)
		{ // no self-talk; 
		  // horizontal transmission;
	 	  for(i=0;i<getNumInfoChange();i++)
			{ HorInfoChange(SpAgent, LiAgent, NumPosFeedback); ChkConsist(1, SpAgent); ChkConsist(2, LiAgent);
			  if(getShowComInfo()==1)
			  	if(((i+1)%(int)(((getNumInfoChange()<=(int)_DrawStarFreq)?_DrawStarFreq:getNumInfoChange())/_DrawStarFreq))==0) printf("*");
	  	  	}
		  if(getShowComInfo()==1) printf("\n");
		}
	else if(getSelfTalkFlag()==1)
		{ // allow self-talk;
		  if(SpAgent!=LiAgent)
		  	{ // horizontal transmission;
		  	  for(i=0;i<getNumInfoChange();i++) 
				{ HorInfoChange(SpAgent, LiAgent, NumPosFeedback); ChkConsist(1, SpAgent); ChkConsist(2, LiAgent);
				  if(getShowComInfo()==1)
				  	if(((i+1)%(int)(((getNumInfoChange()<=(int)_DrawStarFreq)?_DrawStarFreq:getNumInfoChange())/_DrawStarFreq))==0) printf("*");
				}
			  if(getShowComInfo()==1) printf("\n");
		  	}
		  else
		  	{ CrtSelfCopy(SpAgent, selfcopy);	// create selfcopy;
			  // self-talk;
			  for(i=0;i<getNumInfoChange();i++)
			  	{ SelfTalk(SpAgent, selfcopy, NumPosFeedback); ChkConsist(1, SpAgent); ChkConsist(2, selfcopy);
				  if(getShowComInfo()==1)
				  	if(((i+1)%(int)(((getNumInfoChange()<=(int)_DrawStarFreq)?_DrawStarFreq:getNumInfoChange())/_DrawStarFreq))==0) printf("*");
				}
			  if(getShowComInfo()==1) printf(" Self-talk!\n");
			  EmpSelfCopy(selfcopy);	// empty selfcopy;
		  	}
		}
}

void CSystem::VerCom(int type, CAgent *SpAgent, CAgent *LiAgent, int Sp_LiInd, int *NumPosFeedback)
{ // vertical communication; type=0, adult->child; 1, child->adult;
	assert((type==0)||(type==1)); assert((SpAgent!=NULL)&&(LiAgent!=NULL)); assert((0<=Sp_LiInd)&&(Sp_LiInd<getNumAgent()));
	int i;
	for(i=0;i<getNumInfoChange();i++)
		{ VerInfoChange(SpAgent, LiAgent, NumPosFeedback); ChkConsist(1, SpAgent); ChkConsist(2, LiAgent);
	  	  if(getShowComInfo()==1)
		  	if(((i+1)%(int)(((getNumInfoChange()<=(int)_DrawStarFreq)?_DrawStarFreq:getNumInfoChange())/_DrawStarFreq))==0) printf("*");
		}
	if(getShowComInfo()==1)
		{ if(type==0)
			{ if(SpAgent==getpAgent(Sp_LiInd)) printf(" Parent->Child talk!\n");
			  else printf(" Oblique talk!\n");
			}
		  else if(type==1)
			{ if(LiAgent==getpAgent(Sp_LiInd)) printf(" Child->Parent talk!\n");
			  else printf(" Oblique talk!\n");
			}
		  else printf("\n");
		}
}

void CSystem::OneToManyCom(CAgent *SpAgent, CAgent **Neighbor, int numNeighbor, int *NumPosFeedback)
{ // one speaker, many listeners communication;
	assert(SpAgent!=NULL); assert(Neighbor!=NULL); assert(NumPosFeedback!=NULL);
	int i, j;
	for(i=0;i<getNumInfoChange();i++)
		{ OneToManyInfoChange(SpAgent, Neighbor, numNeighbor, NumPosFeedback);
		  for(j=0;j<numNeighbor;j++)
		  	{ if(Neighbor[j]==SpAgent) ChkConsist(1, Neighbor[j]);
		  	  else ChkConsist(3, Neighbor[j]);
		  	}
		  if(getShowComInfo()==1)
		  	if(((i+1)%(int)(((getNumInfoChange()<=(int)_DrawStarFreq)?_DrawStarFreq:getNumInfoChange())/_DrawStarFreq))==0) printf("*");
		}	
	if(getShowComInfo()==1) printf("\n");				  	
}

void CSystem::AdjBuffer(CAgent *SpAgent, CAgent *selfcopy)
{ // empty SpAgent->m_pBufer;
	assert((SpAgent!=NULL)&&(selfcopy!=NULL));
	int i;
	// empty SpAgent->m_pBuffer;
	if(SpAgent->getpBuffer()->getCurBufSize()!=0)
 	 	{ for(i=0;i<SpAgent->getpBuffer()->getCurBufSize();i++)
  			{ SpAgent->getpBuffer()->setpBuf(i, NULL); SpAgent->getpBuffer()->setpBufInst(i, 0);
			}
  		}
	SpAgent->getpBuffer()->DestBuffer(); SpAgent->getpBuffer()->InitBuffer(selfcopy->getpBuffer()->getCurBufSize(), selfcopy->getpBuffer()->getMaxBufSize());
	// copy selfcopy->m_pBuffer to SpAgent->m_pBuffer;
	if(SpAgent->getpBuffer()->getCurBufSize()==SpAgent->getpBuffer()->getMaxBufSize()) SpAgent->getpBuffer()->setBufTag(1);
	for(i=0;i<selfcopy->getpBuffer()->getCurBufSize();i++)
		{ SpAgent->getpBuffer()->setpBuf(i, selfcopy->getpBuffer()->getpBuf(i)); SpAgent->getpBuffer()->setpBufInst(i, selfcopy->getpBuffer()->getpBufInst(i));
		}
}

void CSystem::AdjLTMem(CAgent *selfcopy, CAgent *SpAgent)
{ // adjust selfcopy and SpAgent->m_pLTMem;
	assert((selfcopy!=NULL)&&(SpAgent!=NULL));
	int i;
	// empty selfcopy->m_pLTMem;
	if(selfcopy->getpLTMem()->getNumLexRule()!=0)
	 	{ for(i=0;i<selfcopy->getpLTMem()->getNumLexRule();i++)
			selfcopy->getpLTMem()->setpLexRuleList(i, NULL);
		}
	if(selfcopy->getpLTMem()->getNumCat()!=0)
	 	{ for(i=0;i<selfcopy->getpLTMem()->getNumCat();i++)
			selfcopy->getpLTMem()->setpCatList(i, NULL);
		}
	if(selfcopy->getpLTMem()->getNumSynRule()!=0)
	 	{ for(i=0;i<selfcopy->getpLTMem()->getNumSynRule();i++)
			selfcopy->getpLTMem()->setpSynRuleList(i, NULL);
		}
	selfcopy->getpLTMem()->DestLTMem(); selfcopy->getpLTMem()->InitLTMem(SpAgent->getpLTMem()->getNumLexRule(), SpAgent->getpLTMem()->getMaxLexRule(), SpAgent->getpLTMem()->getNumCat(), SpAgent->getpLTMem()->getMaxCat(), SpAgent->getpLTMem()->getNumSynRule(), SpAgent->getpLTMem()->getMaxSynRule());
	// copy SpAgent->m_pLTMem to selfcopy->m_pLTMem;
	for(i=0;i<SpAgent->getpLTMem()->getNumLexRule();i++)
	  	selfcopy->getpLTMem()->setpLexRuleList(i, SpAgent->getpLTMem()->getpLexRuleList(i));
	for(i=0;i<SpAgent->getpLTMem()->getNumCat();i++)
	  	selfcopy->getpLTMem()->setpCatList(i, SpAgent->getpLTMem()->getpCatList(i));
	for(i=0;i<SpAgent->getpLTMem()->getNumSynRule();i++)
	  	selfcopy->getpLTMem()->setpSynRuleList(i, SpAgent->getpLTMem()->getpSynRuleList(i));
}

void CSystem::CrtSelfCopy(CAgent *SpAgent, CAgent *&selfcopy)
{ // create a selfcopy of SpAgent;
	assert(SpAgent!=NULL);
	int i;
	selfcopy=new CAgent; assert(selfcopy!=NULL);
	*selfcopy=*SpAgent;	// copy from SpAgent;
	// recreate selfcopy's semspace;
	for(i=0;i<selfcopy->getpSemSpace()->getNumIntgMean();i++)
		selfcopy->getpSemSpace()->EmpSemItem(i);
	selfcopy->getpSemSpace()->DestSemSpace(); 
	selfcopy->getpSemSpace()->InitSemSpace(); selfcopy->getpSemSpace()->CreateSemSpace();
	switch(selfcopy->getpSemSpace()->getSemDist())
	  	{ case 1: case 3: case 5:	// identical distribution;
	  			for(i=0;i<SpAgent->getpSemSpace()->getNumIntgMean();i++)
					selfcopy->getpSemSpace()->getpSemItem(i)->setFre(SpAgent->getpSemSpace()->getpSemItem(i)->getFre());
				break;
		  default: break;
		}
	// empty selfcopy->m_pIMMem;
	if(selfcopy->getpIMMem()->getNumCombOption()!=0)
		{ for(i=0;i<selfcopy->getpIMMem()->getNumCombOption();i++)
			selfcopy->getpIMMem()->setpOptionComb(i, NULL);
		}
	selfcopy->getpIMMem()->EmpOptionComb();
}

void CSystem::CrtnewAgent(CAgent *RepAgent, CAgent *&newAgent)
{ // create newAgent from RepAgent;
	assert(RepAgent!=NULL);
	int i;
	newAgent=new CAgent; assert(newAgent!=NULL);
	newAgent->setIndex(RepAgent->getIndex());
	newAgent->setLocX(RepAgent->getLocX()); newAgent->setLocY(RepAgent->getLocY());
	
	// adjust newAgent's semspace;
	switch(newAgent->getpSemSpace()->getSemDist())
	  	{ case 1: case 3: case 5:	// identical distribution;
	  			for(i=0;i<RepAgent->getpSemSpace()->getNumIntgMean();i++)
					newAgent->getpSemSpace()->getpSemItem(i)->setFre(RepAgent->getpSemSpace()->getpSemItem(i)->getFre());
				break;
		  default: break;
		}
}

void CSystem::EmpSelfCopy(CAgent *&selfcopy)
{ // empty selfcopy;
	assert(selfcopy!=NULL);
	int i;
	// empty selfcopy->m_pBufer;
	if(selfcopy->getpBuffer()->getCurBufSize()!=0)
	  	{ for(i=0;i<selfcopy->getpBuffer()->getCurBufSize();i++)
	  		selfcopy->getpBuffer()->setpBuf(i, NULL);
	  	}
	// empty selfcopy->m_pLTMem;
	if(selfcopy->getpLTMem()->getNumLexRule()!=0)
	 	{ for(i=0;i<selfcopy->getpLTMem()->getNumLexRule();i++)
	  		selfcopy->getpLTMem()->setpLexRuleList(i, NULL);
	  	}
	if(selfcopy->getpLTMem()->getNumCat()!=0)
	 	{ for(i=0;i<selfcopy->getpLTMem()->getNumCat();i++)
	 		selfcopy->getpLTMem()->setpCatList(i, NULL);
	  	}
	if(selfcopy->getpLTMem()->getNumSynRule()!=0)
	  	{ for(i=0;i<selfcopy->getpLTMem()->getNumSynRule();i++)
	  		selfcopy->getpLTMem()->setpSynRuleList(i, NULL);
	  	}
	delete selfcopy; selfcopy=NULL;	// delete selfcopy;
}

void CSystem::RepnewAgent(CAgent *OldAgent, CAgent *&newAgent)
{ // replace OldAgent with newAgent;
	assert((OldAgent!=NULL)&&(newAgent!=NULL));
	int i;
	*OldAgent=*newAgent;	// copy newAgent to OldAgent;
	// empty newAgent->m_pSemSpace;
	for(i=0;i<newAgent->getpSemSpace()->getNumIntgMean();i++)
		newAgent->getpSemSpace()->EmpSemItem(i);
	// empty newAgent->m_pBufer;
	if(newAgent->getpBuffer()->getCurBufSize()!=0)
	  	{ for(i=0;i<newAgent->getpBuffer()->getCurBufSize();i++)
	  		newAgent->getpBuffer()->setpBuf(i, NULL);
	  	}
	// empty newAgent->m_pLTMem;
	if(newAgent->getpLTMem()->getNumLexRule()!=0)
	 	{ for(i=0;i<newAgent->getpLTMem()->getNumLexRule();i++)
	  		newAgent->getpLTMem()->setpLexRuleList(i, NULL);
	  	}
	if(newAgent->getpLTMem()->getNumCat()!=0)
	 	{ for(i=0;i<newAgent->getpLTMem()->getNumCat();i++)
	 		newAgent->getpLTMem()->setpCatList(i, NULL);
	  	}
	if(newAgent->getpLTMem()->getNumSynRule()!=0)
	  	{ for(i=0;i<newAgent->getpLTMem()->getNumSynRule();i++)
	  		newAgent->getpLTMem()->setpSynRuleList(i, NULL);
	  	}
	// empty newAgent->m_pIMMem;
	if(newAgent->getpIMMem()->getNumCombOption()!=0)
		{ for(i=0;i<newAgent->getpIMMem()->getNumCombOption();i++)
			newAgent->getpIMMem()->setpOptionComb(i, NULL);
		}
	delete newAgent; newAgent=NULL;	// delete selfcopy;
}

void CSystem::InitNewAgent(int *&repAgentInd, CAgent **&newAgent)
{ // create repAgentInd and newAgent;
	int i, j, rep;
	// initialize repAgentInd;
	repAgentInd=new int [getNumAgentRep()]; assert(repAgentInd!=NULL);
	for(i=0;i<getNumAgentRep();i++)
		repAgentInd[i]=-1;
	// initialize newAgent;
	newAgent=new CAgent * [getNumAgentRep()]; assert(newAgent!=NULL);
	for(i=0;i<getNumAgentRep();i++)
	 	newAgent[i]=NULL;

	if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8))
		{ // randomly choose replaced agent;
		  i=0;
		  do{ do{ rep=(int)(getNumAgent()*Rand0_1);
     		 	 }while(rep==getNumAgent());
			 for(j=0;j<i;j++)
			 	{ if(rep==repAgentInd[j]) break;
			  	}
			 if(j==i)
			  	{ repAgentInd[i]=rep;
			  	  CrtnewAgent(getpAgent(repAgentInd[i]), newAgent[i]);	// create newAgent[i] from m_ppAgent[repAgentInd[i]];
			  	  i++;
			  	}
		  }while(i!=getNumAgentRep());
		}
}

void CSystem::ReplaceAgent(int *repAgentInd, CAgent **newAgent)
{ // replace newAgent; 
	assert((repAgentInd!=NULL)&&(newAgent!=NULL));
	int i;
  	// adjust children to adult, and then replace old agent;
	if(getDifAdultChild()==1)
		{ // adjust adult's learnability; 
	  	  for(i=0;i<getNumAgentRep();i++)
	  		newAgent[i]->setChildAdultAbiRatio(getDifRatio()*newAgent[i]->getChildAdultAbiRatio());
		}
	// replace m_ppAgent by newAgent;
	for(i=0;i<getNumAgentRep();i++)
	 	RepnewAgent(getpAgent(repAgentInd[i]), newAgent[i]);	// replace m_ppAgent[repAgentInd[i]] by newAgent[i];
}

void CSystem::updNeighbor(CAgent *Ag, int AgInd, CAgent **&Neighbor, int *&NeighborInd, int *numNeighbor)
{ // insert Ag and AgInd into Neighbor and NeighborInd;
	assert((Ag!=NULL)&&(numNeighbor!=NULL)); assert((0<=AgInd)&&(AgInd<getNumAgent()));
	int i;
	int numnewNeighbor, *NeighborIndtemp=NULL;
	CAgent **Neighbortemp=NULL;
	
	if(*numNeighbor==0) 
		{ (*numNeighbor)++;
		  // create Neighbor and NeighborInd; 
		  Neighbor=new CAgent * [*numNeighbor]; assert(Neighbor!=NULL);
		  Neighbor[0]=Ag;
		  NeighborInd=new int [*numNeighbor]; assert(NeighborInd!=NULL);
		  NeighborInd[0]=AgInd;
		}
	else
		{ // a new Neighbor;
		  numnewNeighbor=(*numNeighbor)+1;	// increase the current number of neighbor;
		  // update Neighbor;
		  Neighbortemp=new CAgent * [numnewNeighbor]; assert(Neighbortemp!=NULL);
		  for(i=0;i<numnewNeighbor;i++)
		  	Neighbortemp[i]=NULL;
		  for(i=0;i<numnewNeighbor-1;i++)
		  	Neighbortemp[i]=Neighbor[i];
		  Neighbortemp[numnewNeighbor-1]=Ag;
		  // delete original Neighbor;
		  delete [] Neighbor; Neighbor=NULL;
		  *numNeighbor=0;
		  // copy Neighbortemp to Neighbor;
		  *numNeighbor=numnewNeighbor; Neighbor=Neighbortemp;
		  Neighbortemp=NULL;	// recollect Neighbortemp;
		  // update NeighborInd;
		  NeighborIndtemp=new int [*numNeighbor]; assert(NeighborIndtemp!=NULL);
		  for(i=0;i<*numNeighbor-1;i++)
		  	NeighborIndtemp[i]=NeighborInd[i];
		  NeighborIndtemp[*numNeighbor-1]=AgInd;
		  // delete original NeighborInd;
		  delete [] NeighborInd; NeighborInd=NULL;
		  NeighborInd=NeighborIndtemp;
		  NeighborIndtemp=NULL;	// recollect NeighborIndtemp;		  
		}
}

void CSystem::CrtNeighborAdult(CAgent *SpAgent, CAgent **&Neighbor, int *&NeighborInd, int *numNeighbor)
{ // build up SpAgent's adult neighbors;
	assert(SpAgent!=NULL);
	int i;
	for(i=0;i<getNumAgent();i++)
		{ if(chkDist(SpAgent, getpAgent(i))==1) updNeighbor(getpAgent(i), i, Neighbor, NeighborInd, numNeighbor);
		}
}

void CSystem::CrtNeighborChild(CAgent *SpAgent, CAgent **newAgent, int *repAgentInd, int numAgentRep, CAgent **&Neighbor, int *&NeighborInd, int *numNeighbor)
{ // build up SpAgent's child neighbor;
	assert(SpAgent!=NULL);
	int i;
	for(i=0;i<numAgentRep;i++)
		{  if(chkDist(SpAgent, newAgent[i])==1) updNeighbor(newAgent[i], repAgentInd[i], Neighbor, NeighborInd, numNeighbor);
		}
}
				 	  
void CSystem::MoveAgent(CAgent *Ag, CAgent **Neighbor, int numNeighbor, int SucCom)
{ // move Ag; SucCom=1, move Ag and keep constrains between Ag and Neighbors; SucCom=0, random move Ag;
	assert(Ag!=NULL); assert((SucCom==0)||(SucCom==1));
	assert(((SucCom==0)&&(Neighbor==NULL)&&(numNeighbor==0))||((SucCom==1)&&(Neighbor!=NULL)&&(numNeighbor!=0)));
	int LocX=Ag->getLocX(), LocY=Ag->getLocY(); // keep Ag's current position;
	int i, Direct, newLocX, newLocY;
  	int xm, xp, ym, yp; // new locations;
  	int numTry;	// times trying to move agent;
  	int taken, distCon;	// check if new location is taken by other agents;
	int distX, distY;
	
	numTry=0;
	if(SucCom==0)
		{ // random move Ag;
		  newLocX=newLocY=-1;
		  do{ numTry++;	// new try; 
			 xm=(LocX+getWorldX()-getMoveStep())%getWorldX(); ym=(LocY+getWorldY()-getMoveStep())%getWorldY(); 
			 xp=(LocX+getMoveStep())%getWorldX(); yp=(LocY+getMoveStep())%getWorldY();

			 do{ Direct=(int)(Rand0_1*8);      // random select a direction from 8 directions;
			 }while(Direct==8);
			 switch(Direct)
	  			{ case 0: newLocX=xm; newLocY=ym; break;	// NW
			   	  case 1: newLocX=LocX; newLocY=ym; break;	// N	    			
	   			  case 2: newLocX=xp; newLocY=ym; break;	// NE
	   			  case 3: newLocX=xm; newLocY=LocY; break;		// W
	   			  case 4: newLocX=xp; newLocY=LocY; break;		// E
			   	  case 5: newLocX=xm; newLocY=yp; break;	// SW
	   			  case 6: newLocX=LocX; newLocY=yp; break;		// S
	   			  case 7: newLocX=xp; newLocY=yp; break;	// SE
	   			  default: break;
			 	}
			 // check if the new location is taken by othe ragents;
			 taken=0;
	 		 for(i=0;i<getNumAgent();i++)
		 		{ if((getpAgent(i)!=Ag)&&((getpAgent(i)->getLocX()==newLocX)&&(getpAgent(i)->getLocY()==newLocY)))
	  				{ taken=1; break; }
		 		}
  			}while((numTry<10)&&(taken==1));  
  		  if(numTry==10) { newLocX=LocX; newLocY=LocY; }	// do not move! restore saved position;     
  		  Ag->setLocX(newLocX); Ag->setLocY(newLocY);
		}
	else if(SucCom==1)
		{ // move Ag and keep distance constrains;
		  newLocX=newLocY=-1; distCon=0;
		  do{ numTry++;	// new try; 
			 xm=(LocX+getWorldX()-getMoveStep())%getWorldX(); ym=(LocY+getWorldY()-getMoveStep())%getWorldY(); 
			 xp=(LocX+getMoveStep())%getWorldX(); yp=(LocY+getMoveStep())%getWorldY();

			 do{ Direct=(int)(Rand0_1*8);      // random select a direction from 8 directions;
			 }while(Direct==8);
			 switch(Direct)
	  			{ case 0: newLocX=xm; newLocY=ym; break;	// NW
			   	  case 1: newLocX=LocX; newLocY=ym; break;	// N	    			
	   			  case 2: newLocX=xp; newLocY=ym; break;	// NE
	   			  case 3: newLocX=xm; newLocY=LocY; break;		// W
	   			  case 4: newLocX=xp; newLocY=LocY; break;		// E
			   	  case 5: newLocX=xm; newLocY=yp; break;	// SW
	   			  case 6: newLocX=LocX; newLocY=yp; break;		// S
	   			  case 7: newLocX=xp; newLocY=yp; break;	// SE
	   			  default: break;
			 	}
			  // check if the new location is taken by othe ragents;
			  taken=0;
	 		  for(i=0;i<getNumAgent();i++)
		 		{ if((getpAgent(i)!=Ag)&&((getpAgent(i)->getLocX()==newLocX)&&(getpAgent(i)->getLocY()==newLocY)))
	  				{ taken=1; break; }
		 		}
			  if(taken==0)
			  	{ // further check if the new location makes the distance constrain failed;
			  	  distCon=1;
			  	  for(i=0;i<numNeighbor;i++)
			  		{ if(Neighbor[i]!=Ag)
			  			{ distX=abs(newLocX-Neighbor[i]->getLocX()); if(distX>(int)(getWorldX()/_Twice)) distX=getWorldX()-distX;
						  distY=abs(newLocY-Neighbor[i]->getLocY()); if(distY>(int)(getWorldY()/_Twice)) distY=getWorldY()-distY;	
						  if((distX>getBlockDist())||(distY>getBlockDist())) { distCon=0; break; }
			  			}
			  		}
			  	}
		  	}while((numTry<10)&&!((taken==0)&&(distCon==1)));
		  if(numTry==10) { newLocX=LocX; newLocY=LocY; }	// do not move! restore saved position;     
  		  Ag->setLocX(newLocX); Ag->setLocY(newLocY);
		}
}

void CSystem::MoveNeighbor(CAgent *MovAg, CAgent *OriAg)
{ // move MovAg and try keeping the distance between MovAg and OriAg within the block distance;
	assert((MovAg!=NULL)&&(OriAg!=NULL));
	int LocX=MovAg->getLocX(), LocY=MovAg->getLocY(); // keep MovAg's current position;
	int i, Direct, newLocX, newLocY;
  	int xm, xp, ym, yp; // new locations;
  	int numTry;	// times trying to move agent;
  	int taken, distCon;  // check if new location is taken by other agents;
  	int distX, distY;
  	
	newLocX=newLocY=-1; distCon=0;
	numTry=0;
	do{ numTry++;	// new try; 
		xm=(LocX+getWorldX()-getMoveStep())%getWorldX(); ym=(LocY+getWorldY()-getMoveStep())%getWorldY(); 
		xp=(LocX+getMoveStep())%getWorldX(); yp=(LocY+getMoveStep())%getWorldY();

		do{ Direct=(int)(Rand0_1*8);      // random select a direction from 8 directions;
		}while(Direct==8);
		switch(Direct)
	  		{ case 0: newLocX=xm; newLocY=ym; break;	// NW
		   	  case 1: newLocX=LocX; newLocY=ym; break;	// N	    			
	   		  case 2: newLocX=xp; newLocY=ym; break;	// NE
	   		  case 3: newLocX=xm; newLocY=LocY; break;		// W
	   		  case 4: newLocX=xp; newLocY=LocY; break;		// E
		   	  case 5: newLocX=xm; newLocY=yp; break;	// SW
	   		  case 6: newLocX=LocX; newLocY=yp; break;		// S
	   		  case 7: newLocX=xp; newLocY=yp; break;	// SE
	   		  default: break;
		 	}
		// check if the new location is taken by othe ragents;
		taken=0;
	 	for(i=0;i<getNumAgent();i++)
		 	{ if((getpAgent(i)!=MovAg)&&((getpAgent(i)->getLocX()==newLocX)&&(getpAgent(i)->getLocY()==newLocY)))
	  			{ taken=1; break; }
		 	}
		if(taken==0)
			{ // keep distance between MovAg and OriAg within the block distance;
			  distCon=1;
			  distX=abs(newLocX-OriAg->getLocX()); if(distX>(int)(getWorldX()/_Twice)) distX=getWorldX()-distX;
			  distY=abs(newLocY-OriAg->getLocY()); if(distY>(int)(getWorldY()/_Twice)) distY=getWorldY()-distY;
			  if((distX>getBlockDist())||(distY>getBlockDist())) distCon=0;
			}
  	}while((numTry<10)&&!((taken==0)&&(distCon==1)));
  	if(numTry==10) { newLocX=LocX; newLocY=LocY; }	// do not move! restore saved position;     
  	MovAg->setLocX(newLocX); MovAg->setLocY(newLocY);
}

void CSystem::RecNetTyp(FILE *f, CNet *adjMatrix)
{ // record network type;
	assert(adjMatrix!=NULL);
	if(f==NULL)
		{ // output to screen;
		  switch(adjMatrix->getNetTyp())
		  	{ case -1: printf("Self-grow network "); break;
		  	  case 0: switch(adjMatrix->getBasicTyp())
		  	  			{ case 0: printf("Basic network: Globally paired network "); break;
						  case 1: printf("Basic network: Star network "); break;
						  case 2: printf("Basic network: Neighbor network "); break;
						  case 3: printf("Basic network: Lace network "); break;
					  	  case 4: printf("Basic network: Lattice network "); break;
						  case 5: printf("Basic network: Wheel network "); break;
						  case 6: printf("Basic network: Regular random graph "); break;
						  case 7: printf("Basic network: Directional hierarchy network "); break;
						  case 8: printf("Basic network: Random graph "); break;
						  default: break;
		  	  			}
			  		break;
			  case 1: printf("Scale-free network "); break;
			  case 2: printf("Small world network "); break;
			  case 3: printf("Local world network "); break;
			  case 4: printf("Exponential network "); break;
			  case 5: printf("Cooper-Frieze network "); break;
			  case 6: printf("Directed Scale-free network "); break;
			  case 7: printf("Multi-Local-World (MLW) network "); break;
			  default: break;
		  	}
		  if(adjMatrix->getDirected()==0) printf("(Undirected): ");
		  else if(adjMatrix->getDirected()==1) printf("(Directed): ");		  
		}
	else
		{ // output to f;
		  switch(adjMatrix->getNetTyp())
			{ case -1: fprintf(f,"Self-grow network "); break;
			  case 0: switch(adjMatrix->getBasicTyp())
						{ case 0: fprintf(f,"Basic network: Globally paired network "); break;
						  case 1: fprintf(f,"Basic network: Star network "); break;
						  case 2: fprintf(f,"Basic network: Neighbor network "); break;
						  case 3: fprintf(f,"Basic network: Lace network "); break;
						  case 4: fprintf(f,"Basic network: Lattice network "); break;
						  case 5: fprintf(f,"Basic network: Wheel network "); break;
						  case 6: fprintf(f,"Basic network: Regular random graph "); break;
						  case 7: fprintf(f,"Basic network: Directional hierarchy network "); break;
						  case 8: fprintf(f,"Basic network: Random graph "); break;
						  default: break;
						}
					break;
			  case 1: fprintf(f,"Scale-free network "); break;
			  case 2: fprintf(f,"Small world network "); break;
			  case 3: fprintf(f,"Local world network "); break;
			  case 4: fprintf(f,"Exponential network "); break;
			  case 5: fprintf(f,"Cooper-Frieze network "); break;
			  case 6: fprintf(f,"Directed Scale-free network "); break;
			  case 7: fprintf(f,"Multi-Local-World (MLW) network "); break;
			  default: break;
			}
		  if(adjMatrix->getDirected()==0) fprintf(f,"(Undirected): ");
		  else if(adjMatrix->getDirected()==1) fprintf(f,"(Directed): ");		  
		}
}

void CSystem::RecComMode(FILE *f, char *fileName, CNet *adjMatrix)
{ // record ComMode, DecFlag, SelfTalkFlag;
	int widthAgent=(int)(log10((double)(getNumAgent()))+1);
	int G1low=-1, G1up=-1, G2low=-1, G2up=-1;
	if(getNumGroup()==1) { G1low=0; G1up=getNumAgent(); }
	else if(getNumGroup()==2) { G1low=0; G1up=(int)(getNumAgent()/_Twice+0.5); G2low=G1up; G2up=getNumAgent(); }

	if(f==NULL)
		{ // output to screen;
		  switch(getComMode())
		  	{ case 0: printf("Rand Com: "); break;
	  		  case 1: printf("Pair Com: "); break;
			  case 2: printf("Teach-Learn: "); break;
			  case 3: printf("Pop Agent: "); break;
			  case 4: printf("2D world (%*d*%*d): ", (int)(log10((double)(getWorldX()))+1), getWorldX(), (int)(log10((double)(getWorldY()))+1), getWorldY()); break;
			  case 5: printf("Sol Com: "); RecNetTyp(NULL, adjMatrix); break;
			  case 6: printf("GA Rand Com: "); break;
			  case 7: printf("Memory Language Rand Com: "); break;
			  case 8: printf("Language JA and LTM Rand Com: "); break;
			  default: break;
		  	}
		  if(getDecFlag()==0) printf("No DecHolist, ");
		  else if(getDecFlag()==1) printf("DecHolist, ");
		  if(getSelfTalkFlag()==0) printf("No Self-talk:\n");
		  else if(getSelfTalkFlag()==1) printf("Self-talk:\n");
		  if(getNumGroup()==1) 
		  	{ if(getG1HolComp()==0) printf("1 Group (%*d - %*d) Holist Rules ", widthAgent, 0, widthAgent, getNumAgent());
		      else if((getG1HolComp()==1)||(getG1HolComp()==2)) printf("1 Group (%*d - %*d) Compo Rules ", widthAgent, 0, widthAgent, getNumAgent());
		  	}
		  else if(getNumGroup()==2)
		  	{ if((getG1HolComp()==0)&&(getG2HolComp()==0)) printf("2 Groups: (%*d - %*d) Holist Rules; (%*d - %*d ) Holist Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
			  else if((getG1HolComp()==0)&&((getG2HolComp()==1)||(getG2HolComp()==2))) printf("2 Groups: (%*d - %*d) Holist Rules; (%*d - %*d ) Compo Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
			  else if(((getG1HolComp()==1)||(getG1HolComp()==2))&&(getG2HolComp()==0)) printf("2 Groups: (%*d - %*d) Compo Rules; (%*d - %*d ) Holist Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
			  else if(((getG1HolComp()==1)||(getG1HolComp()==2))&&((getG2HolComp()==1)||(getG2HolComp()==2))) printf("2 Groups: (%*d - %*d) Compo Rules; (%*d - %*d ) Compo Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);	
	  		}
		  if(getHorObliMix()==0) { printf("Horizontal transmission:\n"); printf("NumAgent=%*d; NumCom=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumCom()))+1), getNumCom(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange()); }
		  else if(getHorObliMix()==1) { printf("Vertical/Oblique transmission:\n"); printf("NumAgent=%*d; NumGen=%*d; NumLearn=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumGen()))+1), getNumGen(), (int)(log10((double)(getNumLearn()))+1), getNumLearn(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange());	}
		  else if(getHorObliMix()==2) { printf("Mixed transmission:\n"); printf("NumAgent=%*d; NumGen=%*d; NumLearn=%*d; NumCom=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumGen()))+1), getNumGen(), (int)(log10((double)(getNumLearn()))+1), getNumLearn(), (int)(log10((double)(getNumCom()))+1), getNumCom(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange()); }
		}
	else
		{ // output to f;
		  if((f=fopen(fileName,"a+"))==NULL) { printf("Can't open and append %s\n", fileName); exit(1); }
		  switch(getComMode())
			  { case 0: fprintf(f,"Rand Com: "); break;
				case 1: fprintf(f,"Pair Com: "); break;
				case 2: fprintf(f,"Teach-Learn: "); break;
				case 3: fprintf(f,"Pop Agent: "); break;
				case 4: fprintf(f,"2D world (%*d*%*d): ", (int)(log10((double)(getWorldX()))+1), getWorldX(), (int)(log10((double)(getWorldY()))+1), getWorldY()); break;
				case 5: fprintf(f,"Sol Com: "); RecNetTyp(f, adjMatrix); break;
				case 6: fprintf(f,"GA Rand Com: "); break;
				case 7: fprintf(f,"Memory Language Rand Com: "); break;
				case 8: fprintf(f,"Language JA LTM Rand Com: "); break;
				default: break;
			  }
		  if(getDecFlag()==0) fprintf(f,"No DecHolist, ");
		  else if(getDecFlag()==1) fprintf(f,"DecHolist, ");
		  if(getSelfTalkFlag()==0) fprintf(f,"No Self-talk:\n");
		  else if(getSelfTalkFlag()==1) fprintf(f,"Self-talk:\n");
		  if(getNumGroup()==1) 
			  { if(getG1HolComp()==0) fprintf(f,"1 Group (%*d - %*d) Holist Rules ", widthAgent, 0, widthAgent, getNumAgent());
				else if((getG1HolComp()==1)||(getG1HolComp()==2)) fprintf(f,"1 Group (%*d - %*d) Compo Rules ", widthAgent, 0, widthAgent, getNumAgent());
			  }
		  else if(getNumGroup()==2)
			  { if((getG1HolComp()==0)&&(getG2HolComp()==0)) fprintf(f,"2 Groups: (%*d - %*d) Holist Rules; (%*d - %*d ) Holist Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
				else if((getG1HolComp()==0)&&((getG2HolComp()==1)||(getG2HolComp()==2))) fprintf(f,"2 Groups: (%*d - %*d) Holist Rules; (%*d - %*d ) Compo Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
				else if(((getG1HolComp()==1)||(getG1HolComp()==2))&&(getG2HolComp()==0)) fprintf(f,"2 Groups: (%*d - %*d) Compo Rules; (%*d - %*d ) Holist Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up);
				else if(((getG1HolComp()==1)||(getG1HolComp()==2))&&((getG2HolComp()==1)||(getG2HolComp()==2))) fprintf(f,"2 Groups: (%*d - %*d) Compo Rules; (%*d - %*d ) Compo Rules ", widthAgent, G1low, widthAgent, G1up, widthAgent, G2low, widthAgent, G2up); 
			  }
		  if(getHorObliMix()==0) { fprintf(f,"Horizontal transmission:\n"); fprintf(f,"NumAgent=%*d; NumCom=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumCom()))+1), getNumCom(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange()); }
		  else if(getHorObliMix()==1) { fprintf(f,"Vertical/Oblique transmission:\n"); fprintf(f,"NumAgent=%*d; NumGen=%*d; NumLearn=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumGen()))+1), getNumGen(), (int)(log10((double)(getNumLearn()))+1), getNumLearn(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange()); }
		  else if(getHorObliMix()==2) { fprintf(f,"Mixed transmission:\n"); fprintf(f,"NumAgent=%*d; NumGen=%*d; NumLearn=%*d; NumCom=%*d; NumInfoChange=%*d\n", widthAgent, getNumAgent(), (int)(log10((double)(getNumGen()))+1), getNumGen(), (int)(log10((double)(getNumLearn()))+1), getNumLearn(), (int)(log10((double)(getNumCom()))+1), getNumCom(), (int)(log10((double)(getNumInfoChange()))+1), getNumInfoChange()); }
		  fclose(f);
		}
}

void CSystem::Forget(int TimScale, int NoCom_Gen, CAgent **AgSet, int NoAg)
{ // every TimScale, let all agents in AgSet to forget;
	assert(TimScale>=1); assert(NoCom_Gen>=0); assert(AgSet!=NULL); assert(NoAg>0);
	int i;
	if((NoCom_Gen+1)%TimScale==0)
		{ if(getShowComInfo()==1) printf("Forgetting after %*d Com/Learn;\n", (int)(log10((double)(NoCom_Gen+1))+1), NoCom_Gen+1); 
		  // forgetting; 
		  for(i=0;i<NoAg;i++) 
			AgSet[i]->Forget();
		}
}

void CSystem::Adult_RandCom(int numcom)
{ // Adult-Adult communication in random com mode;
	assert((0<=numcom)&&(numcom<getNumCom()));
	int speaker, listener;

	speaker=listener=-1;
	if(getSelfTalkFlag()==0)
		{ // not allow self-talk;
		  // random select speaker and listener;
  		  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
 	 	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener));
		}
	else if(getSelfTalkFlag()==1)
	  	{ // allow self-talk;
		  // random select speaker and listener;	
	  	  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
	  	  }while((speaker==getNumAgent())||(listener==getNumAgent()));
		}
	if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), numcom+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
	HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal communication;
}

void CSystem::Child_RandCom(int cond, int numlearn, int *repAgentInd, CAgent **newAgent, int *choseIndex, CAgent **grandAgent)
{ // Adult-Child, Child-Child, Child-Adult communication in random com mode; cond=0, no grandparent-child talks; 1, having grandparent-child talks;
	assert((cond==0)||(cond==1));
	assert((0<=numlearn)&&(numlearn<getNumLearn())); assert(repAgentInd!=NULL); assert(newAgent!=NULL);
	int index, speaker, listener, repA1, repA2;
	double rannum=Rand0_1;

	if(getShowComInfo()==1) printf("Learn=%*d, ", (int)(log10((double)(getNumLearn()))+1), numlearn+1);	// displace learn time;
	speaker=listener=repA1=repA2=-1;
	if(getCalTransMethod()==0)
		{ // decide using getAdultChildRatio(), getChildChildRatio(), getChildAdultRatio(), and getVerProb();
		  if(FLOAT_SM_EQ(rannum, getAdultChildRatio()))
		  	{ // parent-child talk;
		  	  // select listener from repAgent;
		  	  if(getNumAgentRep()==1) repA2=0;
			  else
			  	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
			  	  }while(repA2==getNumAgentRep());
				}
			  listener=repAgentInd[repA2];
		  	  // decide the teacher for repagent;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8))
			  	{ if(FLOAT_SM_EQ(Rand0_1, getVerProb())) speaker=listener;	// the parent is the speaker;
		  	  	  else
				  	{ // other agent as the speaker; 
		  			  do{ speaker=(int)(Rand0_1*getNumAgent());
		 	  		  }while((speaker==getNumAgent())||(speaker==listener));
			  		}
			  	}
			  else
			  	{ do{ index=(int)(Rand0_1*getNumSp());
			  	  }while(index==getNumSp());
			  	  speaker=choseIndex[index];
			  	}
			  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;					  
		  	}
		  else if((FLOAT_BG(rannum, getAdultChildRatio()))&&(FLOAT_SM_EQ(rannum, getAdultChildRatio()+getChildChildRatio())))
		  	{ // child-child talk;
		  	  // select speaker and listener;
		  	  if(getNumAgentRep()!=1)
		  	  	{ if(getSelfTalkFlag()==0)
		  	  		{ // no self-talk;
		  	  	  	  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
		  	  	  	  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep())||(repA1==repA2));
				  	  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
		  	  		}
			  	  else if(getSelfTalkFlag()==1)
			  	  	{ // allow self-talk;
			  	  	  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
		  	  	  	  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep()));
					  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
				 	}
				  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
				  HorCom(newAgent[repA1], newAgent[repA2], NULL);
			  	}
		  	}
		  else
			{ // child-adult talk;
			  // select speaker from repAgent;
		  	  if(getNumAgentRep()==1) repA1=0;
			  else
			  	{ do{ repA1=(int)(Rand0_1*getNumAgentRep());
			  	  }while(repA1==getNumAgentRep());
				}
			  speaker=repAgentInd[repA1];
		  	  // decide the listener for repagent;
		  	  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8))
		  	  	{ if(FLOAT_SM_EQ(Rand0_1, getVerProb())) listener=speaker;	// the parent is the listener;
		  	  	  else
			 	 	{ // other agent as the listener; 
		  			  do{ listener=(int)(Rand0_1*getNumAgent());
		 	  		  }while((listener==getNumAgent())||(listener==speaker));
			  		}
		  	  	}
			  else
			  	{ do{ index=(int)(Rand0_1*getNumSp());
			  	  }while(index==getNumSp());
			  	  listener=choseIndex[index];
			  	}
			  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;		
			}
		}
	else if(getCalTransMethod()==1)
		{ // decide using getPCRatio(), getACRatio(), getCCRatio(), and getCARatio();
		  if(FLOAT_SM_EQ(rannum, getPCRatio()))
		  	{ // bioparent-child talk;
			  // select listener from repAgent;
			  if(getNumAgentRep()==1) repA2=0;
			  else
			 	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
				  }while(repA2==getNumAgentRep());
				}
			  listener=repAgentInd[repA2];
			  // decide the teacher for repagent;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8)) speaker=listener;	// the parent is the speaker;
		  	  else
			  	{ do{ index=(int)(Rand0_1*getNumSp());
			  	  }while(index==getNumSp());
			  	  speaker=choseIndex[index];
			  	}
			  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;					  
		  	}
		  else if((FLOAT_BG(rannum, getPCRatio()))&&(FLOAT_SM_EQ(rannum, getPCRatio()+getACRatio())))
		  	{ // nonbioparent-child talk;
			  // select listener from repAgent;
			  if(getNumAgentRep()==1) repA2=0;
			  else
			 	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
				  }while(repA2==getNumAgentRep());
				}
			  listener=repAgentInd[repA2];
			  // decide the teacher for repagent;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8))
				{ // other agent as the speaker; 
				  do{ speaker=(int)(Rand0_1*getNumAgent());
				  }while((speaker==getNumAgent())||(speaker==listener));
				}
			  else
				{ do{ index=(int)(Rand0_1*getNumSp());
				  }while(index==getNumSp());
				  speaker=choseIndex[index];
				}
			  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;					  
			}
		  else if((FLOAT_BG(rannum, getPCRatio()+getACRatio()))&&(FLOAT_SM_EQ(rannum, getPCRatio()+getACRatio()+getCCRatio())))
		  	{ // child-child talk;
			  // select speaker and listener;
			  if(getNumAgentRep()!=1)
			  	{ if(getSelfTalkFlag()==0)
					{ // no self-talk;
					  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
					  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep())||(repA1==repA2));
					  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
					}
				  else if(getSelfTalkFlag()==1)
				 	{ // allow self-talk;
					  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
					  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep()));
					  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
					}
				  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);   // display learn agents;
				  HorCom(newAgent[repA1], newAgent[repA2], NULL);
				}
		  	}
		  else
		  	{ // child-adult talk;
			  // select speaker from repAgent;
			  if(getNumAgentRep()==1) repA1=0;
			  else
				{ do{ repA1=(int)(Rand0_1*getNumAgentRep());
				  }while(repA1==getNumAgentRep());
				}
			  speaker=repAgentInd[repA1];
			  // decide the listener for repagent;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8))
				{ // randomly select an agent as the listener; 
				  do{ listener=(int)(Rand0_1*getNumAgent());
				  }while(listener==getNumAgent());
				}
			  else
				{ do{ index=(int)(Rand0_1*getNumSp());
				  }while(index==getNumSp());
				  listener=choseIndex[index];
				}
			  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);   // display learn agents;
			  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);   // vertical communication;	  
		  	}
		}
	else if(getCalTransMethod()==2)
		{ // decide using p_dGrandCRatio, p_dParentCRatio, and p_dChildCRatio;
		  if(FLOAT_SM_EQ(rannum, getGrandCRatio()))
		  	{ // grandparent-child talk;
			  // select listener from repAgent;
			  if(getNumAgentRep()==1) repA2=0;
			  else
			  	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
				  }while(repA2==getNumAgentRep());
				}
			  listener=repAgentInd[repA2];
			  // decide the teacher from grand parents;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8)) 
				{ if(cond==0)
			  		{ // generation=1, no grandparents, treat it as parent-child talk;
			  		  if(getParentCType()==0) speaker=listener;	  // the parent is the speaker;
			  	  	  else
			  	 	 	{ do{ speaker=(int)(Rand0_1*getNumAgent());
				   	   	  }while(speaker==getNumAgent());	// randomly select speaker from parent generation;
			  	  		}
			  		}
				  else if(cond==1)
					{ // generation>1, having grandparents;
					  if(getGrandCType()==0) speaker=listener;	// the grandparent is the speaker;
					  else
						{ do{ speaker=(int)(Rand0_1*getNumAgent());
						  }while(speaker==getNumAgent());   // randomly select speaker from parent generation;
						}
					 }
			  	}
			  else
				{ do{ index=(int)(Rand0_1*getNumSp());
				  }while(index==getNumSp());
				  speaker=choseIndex[index];
				}
			  if(cond==0)
			  	{ // generation=1, no grandparents, treat it as parent-child talk; 
			  	  if(getShowComInfo()==1) printf("Parent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener); // display learn agents;
			      VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);   // vertical communication;
			  	}
			  else if(cond==1)
			  	{ // generation>1, having grandparents;
			  	  if(getShowComInfo()==1) printf("Grandparent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener); // display learn agents;
			  	  VerCom(0, grandAgent[speaker], newAgent[repA2], listener, NULL);   // vertical communication;
			  	}
		  	}
		  else if((FLOAT_BG(rannum, getGrandCRatio()))&&(FLOAT_SM_EQ(rannum, getGrandCRatio()+getParentCRatio())))
		  	{ // parent-child talk;
			  // select listener from repAgent;
			  if(getNumAgentRep()==1) repA2=0;
			  else
				{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
				  }while(repA2==getNumAgentRep());
				}
			  listener=repAgentInd[repA2];
			  // decide the teacher from parents;
			  if((getComMode()!=6)&&(getComMode()!=7)&&(getComMode()!=8)) 
			  	{ if(getParentCType()==0) speaker=listener;	  // the parent is the speaker;
			  	  else
			  	  	{ do{ speaker=(int)(Rand0_1*getNumAgent());
				      }while(speaker==getNumAgent());	// randomly select speaker from parent generation;
			  	  	}
			  	}
			  else
				{ do{ index=(int)(Rand0_1*getNumSp());
				  }while(index==getNumSp());
				  speaker=choseIndex[index];
				}
			  if(getShowComInfo()==1) printf("Parent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener); // display learn agents;
			  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);   // vertical communication;
		  	}
		  else
		  	{ // child-child talk;
			  // select speaker and listener;
			  if(getNumAgentRep()!=1)
			  	{ if(getSelfTalkFlag()==0)
					{ // no self-talk;
					  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
					  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep())||(repA1==repA2));
					  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
					}
				  else if(getSelfTalkFlag()==1)
				 	{ // allow self-talk;
					  do{ repA1=(int)(Rand0_1*getNumAgentRep()); repA2=(int)(Rand0_1*getNumAgentRep());
					  }while((repA1==getNumAgentRep())||(repA2==getNumAgentRep()));
					  speaker=repAgentInd[repA1]; listener=repAgentInd[repA2];
					}
				  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);   // display learn agents;
				  HorCom(newAgent[repA1], newAgent[repA2], NULL);
				}
		  	}
		}
}

void CSystem::adjAdultChild()
{ // adjust children to adults;
	int i;
	if(getDifAdultChild()==1)
	  	{ // adjust adult's learnability; 
	      for(i=0;i<getNumAgent();i++)
	  		getpAgent(i)->setChildAdultAbiRatio(getDifRatio()*getpAgent(i)->getChildAdultAbiRatio());
	  	}
}

void CSystem::RandCom(FILE **f, char **fileNam)
{ // Rand com Mode: one pair of agents randomly communicate in each com round;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	CAgent **grandAgent=NULL;	// grandAgent for grandparents;
	int numLearn, numCom;	// in mixed horizontal and vertical transmissions;

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;
	
	adjAdultChild();	// adjust children to adults;
	// horizontal/vertical transmission: random communication;
	if(getHorObliMix()==0)
		{ // horizontal transmission;
		  for(i=0;i<getNumCom();i++)
			{ Adult_RandCom(i);
			  Forget(getNumAgent(), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget with ratio to 10 agents (0.01);
			  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
		   	}
		}
	else if(getHorObliMix()==1)
		{ // vertical/oblique transmission;
		  if(getCalTransMethod()==2)
		  	{ // create grandparent agents;
			  grandAgent=new CAgent * [getNumAgent()]; assert(grandAgent!=NULL);
			  for(i=0;i<getNumAgent();i++)
				CrtnewAgent(getpAgent(i), grandAgent[i]);
		  	}

		  for(i=0;i<getNumGen();i++)
		  	{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
		  	  
			  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;			  
			  for(j=0;j<getNumAgentRep();j++)
			  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  printf("\n");

			  // learning from others;	
			  for(j=0;j<getNumLearn();j++)
			  	{ if(getCalTransMethod()==2) 
			  		{ if(i==0) Child_RandCom(0, j, repAgentInd, newAgent, NULL, grandAgent);	// no grandparent-child talks;
			  	  	  else Child_RandCom(1, j, repAgentInd, newAgent, NULL, grandAgent);	// having grandparent-child talks;
			  		}
			  	  else Child_RandCom(0, j, repAgentInd, newAgent, NULL, NULL);			  	  	
				  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
			  	}

			  if(getCalTransMethod()==2)
			  	{ for(j=0;j<getNumAgent();j++)
			  		{ delete grandAgent[j]; grandAgent[j]=NULL;
			  		  copyAgent(getpAgent(j), grandAgent[j]);
			  		}
			  	}			  
			  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  
			  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL);	// testing parameters;
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;			  
		  	}

		  if(getCalTransMethod()==2) 
		  	{ // delete grandAgent;
		  	  for(i=0;i<getNumAgent();i++) { delete grandAgent[i]; grandAgent[i]=NULL; }
		  	  delete [] grandAgent; grandAgent=NULL; 
			}
		}
	else if(getHorObliMix()==2)
		{ // mixed transmission;
		  if(getCalTransMethod()==2)
		  	{ // create grandparent agents;
			  grandAgent=new CAgent * [getNumAgent()]; assert(grandAgent!=NULL);
			  for(i=0;i<getNumAgent();i++)
				CrtnewAgent(getpAgent(i), grandAgent[i]);
		  	}

		  for(i=0;i<getNumGen();i++)
		  	{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
		  	
			  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;
			  for(j=0;j<getNumAgentRep();j++)
			  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  printf("\n");

			  if(getMixHorVer()==0)
			  	{ // no mix horizontal and vertical transmissions;
			  	  // learning from others;
			  	  for(j=0;j<getNumLearn();j++)
			  		{ if(getCalTransMethod()==2) 
			  			{ if(i==0) Child_RandCom(0, j, repAgentInd, newAgent, NULL, grandAgent);	// no grandparent-child talks;
			  	  		  else Child_RandCom(1, j, repAgentInd, newAgent, NULL, grandAgent);	// having grandparent-child talks;
			 	 		}
			  		  else Child_RandCom(0, j, repAgentInd, newAgent, NULL, NULL);	
					  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
			  		}
				  
				  if(getCalTransMethod()==2)
				    { for(j=0;j<getNumAgent();j++)
						{ delete grandAgent[j]; grandAgent[j]=NULL;
						  copyAgent(getpAgent(j), grandAgent[j]);
				  		}
					}
				  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  
			  	  // then, horizontal transmission; 
			  	  printf("Communicate:\n");
			  	  for(j=0;j<getNumCom();j++)
			  		{ Adult_RandCom(j);
				  	  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
			  	  	}
			  	}
			  else if(getMixHorVer()==1)
			  	{ numCom=0; numLearn=0;
			  	  for(j=0;j<getNumCom()+getNumLearn();j++)
			  	  	{ if((FLOAT_SM_EQ(Rand0_1, _Half))&&(numCom<getNumCom())) 
			  	  		{ Adult_RandCom(numCom);	// horizontal transmission;	
						  Forget(getNumAgent(), numCom, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
						  numCom++;
				  		}
				  	  else 
					  	{ if(getCalTransMethod()==2) 
			 		 		{ if(i==0) Child_RandCom(0, j, repAgentInd, newAgent, NULL, grandAgent);	// no grandparent-child talks;
			  	 		 	  else Child_RandCom(1, j, repAgentInd, newAgent, NULL, grandAgent);	// having grandparent-child talks;
			 		 		}
			  			  else Child_RandCom(0, j, repAgentInd, newAgent, NULL, NULL);	
						  Forget(getNumAgentRep(), numLearn, newAgent, getNumAgentRep());	// every getNumAgentRep() learn, let all new agents forget;
			  	  		  numLearn++;
						}
			  	  	}
				  
				  if(getCalTransMethod()==2)
				    { for(j=0;j<getNumAgent();j++)
						{ delete grandAgent[j]; grandAgent[j]=NULL;
						  copyAgent(getpAgent(j), grandAgent[j]);
				  		}
					}
				  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	}
			  
			  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL);	// testing parameters;
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;			  
		  	}

		  if(getCalTransMethod()==2) 
		  	{ // delete grandAgent;
		  	  for(i=0;i<getNumAgent();i++) { delete grandAgent[i]; grandAgent[i]=NULL; }
		  	  delete [] grandAgent; grandAgent=NULL; 
			}
		}
}

void CSystem::PairCom(FILE **f, char **fileNam)
{ // Pair com mode: pairs of agents communicate in each com round;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, speaker, listener;
	int *agentRand=NULL;	// used to randmize agents;
	int numPair=(int)(getNumAgent()/_Twice);	// how many paris;	

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	adjAdultChild();	// adjust children to adults;
	// horizontal transmission: pair communication;
	for(i=0;i<getNumCom();i++)
		{ // initialize agentRand;
		  agentRand=new int [getNumAgent()]; assert(agentRand!=NULL);
		  for(j=0;j<getNumAgent();j++)
		  	agentRand[j]=0;
		  if(getShowComInfo()==1) printf("Com=%*d: %*d pairs of communication:\n", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(numPair))+1), numPair);
		  // pair communication;
		  for(j=0;j<numPair;j++)
		  	{ do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
    	  	  }while((speaker==listener)||(speaker==getNumAgent())||(listener==getNumAgent())||(agentRand[speaker]==1)||(agentRand[listener]==1));
    	  	  agentRand[speaker]=1; agentRand[listener]=1;
			  if(getShowComInfo()==1) printf("Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication's speaker and listener;	
			  HorCom(getpAgent(speaker), getpAgent(listener), NULL);
			}
		  Forget(1, i, getppAgent(), getNumAgent());	// every 1 communication, let all agents forget;
		  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
		  delete [] agentRand; agentRand=NULL;	// delete agentRand;
		}
}

void CSystem::TeachLearn(FILE **f, char **fileNam)
{ // teacher-learner mode: teacher learner communicate in each com round;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, speaker, listener;

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	adjAdultChild();	// adjust children to adults;
	// Teach-Learn;
	for(i=0;i<getNumCom();i++)
		{ if(getSelfTalkFlag()==0)
		  	{ // no self-talk;
		  	  speaker=1; listener=0;
		  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  VerCom(0, getpAgent(speaker), getpAgent(listener), listener, NULL);	// vertical transmission;
		  	  getpAgent(listener)->Forget();	// forgetting listener;
		  	}
		  else if(getSelfTalkFlag()==1)
		  	{ // allow self-talk;
		  	  do{ speaker=(int)(Rand0_1*getNumAgent());
		  	  }while(speaker==getNumAgent());
			  listener=0;
			  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  if(speaker!=listener) VerCom(0, getpAgent(speaker), getpAgent(listener), listener, NULL);	// vertical transmission;
		  	  else if(speaker==listener) HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
		  	  getpAgent(listener)->Forget();	// forgetting listener;
		  	}
		  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
		}
}

void CSystem::recPoprate(int cond, double *Pop, int PopSize, FILE *f, char *fileNam)
{ // record popular rates of each individual to a file; cond=1, store values before normalization; cond=2, store values after normalization;
	assert((cond==1)||(cond==2)); assert((Pop!=NULL)&&(f!=NULL)&&(fileNam!=NULL));
	int i;
	if((f=fopen(fileNam,"a+"))==NULL) { printf("Can't open and append %s\n", fileNam); exit(1); }
	fprintf(f, "%d ", cond);
	for(i=0;i<PopSize;i++)
		fprintf(f, "%.6f ", Pop[i]);
	fprintf(f,"\n");
	fclose(f);		  
}

void CSystem::InitPopularity(int type, double *PopularitySP, double *PopularityLI, int PopSize, FILE **f, char **fileNam)
{ // initialize Popularity;
	assert((1<=type)&&(type<=5)); assert((PopularitySP!=NULL)&&(PopularityLI!=NULL)); assert((f!=NULL)&&(fileNam!=NULL));
	int i;
	double *TempPowerLaw=NULL, avgPowerLaw, stdPowerLaw, rangeLow, rangeUp;
	switch(type)
		{ case 1: // linear increase of Popularity;
				for(i=0;i<PopSize;i++)
					PopularitySP[i]=PopularityLI[i]=i+1;
				break;
		  case 2: // scale increase of Popularity;
		  		for(i=0;i<PopSize;i++)
					PopularitySP[i]=PopularityLI[i]=pow(getScale(), i);
				break;
		  case 3: // power-low distrobution of Popularity;
				for(i=0;i<PopSize;i++)
					PopularitySP[i]=PopularityLI[i]=getA1()*pow(i+1, getK1());
				break;
		  case 4: // speaker and listener have different power-law distributions;
				for(i=0;i<PopSize;i++)
					{ PopularitySP[i]=getA1()*pow(i+1, getK1()); PopularityLI[i]=getA2()*pow(i+1, getK2()); }
				break;
		  case 5: // normal distribution with same mean and std of power-law distribution;
				// first setup power-law distribution;
				TempPowerLaw=new double [PopSize]; assert(TempPowerLaw!=NULL);
				for(i=0;i<PopSize;i++)
					TempPowerLaw[i]=getA1()*pow(i+1, getK1());
				// second, calculate the mean and standard deviation of this power-law distribution;
				avgPowerLaw=0.0;
				for(i=0;i<PopSize;i++)
					avgPowerLaw+=TempPowerLaw[i];
				avgPowerLaw/=PopSize;
				stdPowerLaw=0.0;
				for(i=0;i<PopSize;i++)
					stdPowerLaw+=(TempPowerLaw[i]-avgPowerLaw)*(TempPowerLaw[i]-avgPowerLaw);
				stdPowerLaw=sqrt(stdPowerLaw/PopSize);
				if(FLOAT_BG_EQ(avgPowerLaw,2*stdPowerLaw)) { rangeLow=avgPowerLaw-2*stdPowerLaw; rangeUp=avgPowerLaw+2*stdPowerLaw; }
				else { rangeLow=0.0; rangeUp=avgPowerLaw+2*stdPowerLaw; }
				// third, create normal distribution;
				for(i=0;i<PopSize;i++)
					{ do{ PopularitySP[i]=PopularityLI[i]=avgPowerLaw+sqrt((double)(stdPowerLaw))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1);
					  }while((FLOAT_SM(PopularitySP[i],rangeLow))||(FLOAT_BG(PopularitySP[i],rangeUp)));
					}
				delete [] TempPowerLaw; TempPowerLaw=NULL;
		  		break;
		  default: break;
		}
	if(type!=4) recPoprate(1, PopularitySP, PopSize, f[15], fileNam[15]);	// record individual popularity before normalization;
	else
		{ recPoprate(1, PopularitySP, PopSize, f[15], fileNam[15]);	// speakers' power-law distributed individual popularities;
		  recPoprate(2, PopularityLI, PopSize, f[15], fileNam[15]);	// listeners' power-law distributed individual popularities;
		}
	// normalize and accumulate;
	for(i=1;i<PopSize;i++)
		{ PopularitySP[i]+=PopularitySP[i-1]; PopularityLI[i]+=PopularityLI[i-1]; }
	for(i=0;i<PopSize-1;i++)
		{ PopularitySP[i]/=PopularitySP[PopSize-1]; PopularityLI[i]/=PopularityLI[PopSize-1]; }
	PopularitySP[PopSize-1]=1.0; PopularityLI[PopSize-1]=1.0;
	if(type!=4) recPoprate(2, PopularitySP, PopSize, f[15], fileNam[15]);	// record individual popularity before normalization;
	else
		{ recPoprate(3, PopularitySP, PopSize, f[15], fileNam[15]);	// speakers' power-law distributed individual popularities;
		  recPoprate(4, PopularityLI, PopSize, f[15], fileNam[15]);	// listeners' power-law distributed individual popularities;
		}
}

int CSystem::ChoAgPopularity(double *Popularity, int PopSize)
{ // choose agent according to Popularity;
	assert(Popularity!=NULL);
	int i, AgInd;
	double rannum;

	AgInd=-1; rannum=Rand0_1;
	if(FLOAT_SM_EQ(rannum, Popularity[0])) AgInd=0;
	else if(FLOAT_EQ(rannum, 1.0)) AgInd=PopSize-1;
	else
		{ for(i=1;i<PopSize;i++)
			{ if((FLOAT_BG(rannum, Popularity[i-1]))&&(FLOAT_SM_EQ(rannum, Popularity[i]))) { AgInd=i; break; }
			}
		}
	return AgInd;
}

void CSystem::PopCom(FILE **f, char **fileNam)
{ // popular agent;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, speaker, listener;
	double *PopularitySP=NULL, *PopularityLI=NULL;	// storing popularity of each agent as speaker and listener;

	int G1low=-1, G1up=-1, G2low=-1, G2up=-1;
	if(getNumGroup()==1) { G1low=0; G1up=getNumAgent(); }
	else if(getNumGroup()==2) { G1low=0; G1up=(int)(getNumAgent()/_Twice+0.5); G2low=G1up; G2up=getNumAgent(); }

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	adjAdultChild();	// adjust children to adults;
	// horizontal transmission;
	speaker=listener=-1;
	if(getNumGroup()==1)
		{ // 1 group pop agent;
		  if(getHumanChimp()==0)
		  	{ // human society with or without popular agent;
		  	  // m_ppAgent[0] is the popular agent;
		  	  // adjust popular agent;
		  	  if(getDifAdultChild()==1) getpAgent(0)->setChildAdultAbiRatio(getDifRatio()*getpAgent(0)->getChildAdultAbiRatio());	// adjust popular agent's learnability; 
		  	
		  	  for(i=0;i<getNumCom();i++)
				{ if(getSelfTalkFlag()==0)
					{ // not allow self-talk;
					  if(FLOAT_SM_EQ(Rand0_1, getPopRat()))
					  	{ // m_ppAgent[0] participates into the communication;
						  if(FLOAT_SM_EQ(Rand0_1, _Half))
						  	{ speaker=0;	// the popular agent is the speaker;
						   	  do{ listener=(int)(Rand0_1*getNumAgent());
						   	  }while((listener==getNumAgent())||(listener==speaker));
						  	}
						  else
						  	{ listener=0;	// the popular agent is the listener;
						  	  do{ speaker=(int)(Rand0_1*getNumAgent());
						  	  }while((speaker==getNumAgent())||(speaker==listener));
						  	}
						  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] ( Pop):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
				  	  	}
					  else
					  	{ // random select speaker and listener, not the popular agent;
				  	  	  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
				  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||(speaker==0)||(listener==0));
				  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (!Pop):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
				  	  	}
				  	}
				  else if(getSelfTalkFlag()==1)
				  	{ // allow self-talk;
					  if(FLOAT_SM_EQ(Rand0_1, getPopRat()))
					  	{ // m_ppAgent[0] participates into the communication;
					  	  if(FLOAT_SM_EQ(Rand0_1, _Half))
						  	{ speaker=0;	// the popular agent is the speaker;
						   	  do{ listener=(int)(Rand0_1*getNumAgent());
						   	  }while(listener==getNumAgent());
						  	}
						  else
						  	{ listener=0;	// the popular agent is the listener;
						  	  do{ speaker=(int)(Rand0_1*getNumAgent());
						  	  }while(speaker==getNumAgent());
						  	}
						  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] ( Pop):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
				  	  	}
					  else
					  	{ // random select speaker and listener;
				  	  	  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
				  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==0)|(listener==0));
				  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (!Pop):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
				  	  	}
				  	}
				  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  Forget(getNumAgent(), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
				}
		  	}
		  else if((getHumanChimp()==1)||(getHumanChimp()==2)||(getHumanChimp()==3)||(getHumanChimp()==4)||(getHumanChimp()==5))
		  	{ // chimpanzee society with each agent having different popularity;
			  // initialize PopularitySP, PopularityLI;
			  PopularitySP=new double [getNumAgent()]; assert(PopularitySP!=NULL);
		  	  for(i=0;i<getNumAgent();i++)
			  	PopularitySP[i]=0.0;
			  PopularityLI=new double [getNumAgent()]; assert(PopularityLI!=NULL);
			  for(i=0;i<getNumAgent();i++)
			  	PopularityLI[i]=0.0;
			  InitPopularity(getHumanChimp(), PopularitySP, PopularityLI, getNumAgent(), f, fileNam);
			  
			  for(i=0;i<getNumCom();i++)
			  	{ if(getSelfTalkFlag()==0)
					{ // not allow self-talk;
					  do{ speaker=ChoAgPopularity(PopularitySP, getNumAgent()); listener=ChoAgPopularity(PopularityLI, getNumAgent());
					  }while(speaker==listener);
			  		}
			  	  else if(getSelfTalkFlag()==1)
			  	  	{ // allow self-talk;
					  speaker=ChoAgPopularity(PopularitySP, getNumAgent()); listener=ChoAgPopularity(PopularityLI, getNumAgent());
					}
				  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
				  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  Forget(getNumAgent(), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
			  	}
			  delete [] PopularityLI; PopularityLI=NULL;
			  delete [] PopularitySP; PopularitySP=NULL;	// delete PopularitySP and PopularityLI;
		  	}
		}
	else if(getNumGroup()==2)
		{ // 2 groups, intra and inter group communication;
		  for(i=0;i<getNumCom();i++)
			{ if(getSelfTalkFlag()==0)
				{ // not allow self-talk;
				  if(FLOAT_SM_EQ(Rand0_1, getIntraRat()))
				  	{ // group 1 intra com;
				 	  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||(speaker>=G1up)||(listener>=G1up));
			  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (Intra Group 1):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
			  	  	  
					  // group 2 intra com;
					  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||(speaker<G2low)||(listener<G2low));
			  	  	  if(getShowComInfo()==1) printf("     %*s Agent[%*d]->Agent[%*d] (Intra Group 2):", (int)(log10((double)(getNumCom()))+1), " ", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  	}
				  else
				  	{ // group 1, group 2 inter com; 
					  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||((speaker<G1up)&&(listener<G1up))||((speaker>=G2low)&&(listener>=G2low)));
			  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (Inter Group):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  	}
		  		}
		  	  else if(getSelfTalkFlag()==1)
		  	  	{ // allow self-talk;
				  if(FLOAT_SM_EQ(Rand0_1, getIntraRat()))
				  	{ // group 1 intra com;
				 	  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker>=G1up)||(listener>=G1up));
			  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (Intra Group 1):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
					  
					  // group 2 intra com;
					  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||(speaker<G2low)||(listener<G2low));
			  	  	  if(getShowComInfo()==1) printf("     %*s Agent[%*d]->Agent[%*d] (Intra Group 2):", (int)(log10((double)(getNumCom()))+1), " ", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  	}
				  else
				  	{ // group 1, group 2 inter com; 
					  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
			  	  	  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||((speaker<G1up)&&(listener<G1up))||((speaker>=G2low)&&(listener>=G2low)));
			  	  	  if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d] (Inter Group):", (int)(log10((double)(getNumCom()))+1), i+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
			  	  	  HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal transmission;
				  	}
		  	  	}			  
			  Forget((int)(getNumAgent()/_Twice), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
			  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
			}
		}
}

void CSystem::Adult_World2D(int numcom)
{ // Adult-Adult communication in world2d mode;
	assert((0<=numcom)&&(numcom<getNumCom()));
	int i, speaker, listener;
	int *AgentInd=NULL, *Moved=NULL;	// record agent index for selecting speaker and moving;
	CAgent **Neighbor=NULL, **SingNeighbor=NULL;	// each agent's neighbors, agents that within block dist, including himself;
	int *NeighborInd=NULL, numNeighbor;	// each agent's neighbors' index;
	int ind, NumPosFeedback;	// number of success infochange;
	bool SucCom;	// whether this communication is successful or not;

  	if(getShowComInfo()==1) printf("Com=%*d:\n", (int)(log10((double)(getNumCom()))+1), numcom+1);	// display communication time;				  
	// initialize AgentInd;
	AgentInd=new int [getNumAgent()]; assert(AgentInd!=NULL);
	for(i=0;i<getNumAgent();i++)
	 	AgentInd[i]=-1;
	// initialize Moved;
	Moved=new int [getNumAgent()]; assert(Moved!=NULL);
	for(i=0;i<getNumAgent();i++)
	 	Moved[i]=-1;
			  
	// in each round, select each agent and his neighbors as speaker and listener;
	do{ // select speaker; 
	 	do{ speaker=(int)(Rand0_1*getNumAgent());
	 	}while((speaker==getNumAgent())||(AgentInd[speaker]!=-1));
	  	AgentInd[speaker]=speaker;
			  	 	  	 
		numNeighbor=0; CrtNeighborAdult(getpAgent(speaker), Neighbor, NeighborInd, &numNeighbor);	// build up his neighbor;
		if(getSelfTalkFlag()==0)
			{ // no self-talk;
			  if(numNeighbor>=2)
			 	{ // at least there is another agent in the neighbor (not include himself); 
		 		  // select listener, 2 ways;
				  if(get1toMCom()==1)
				  	{ // 1) all neighbors are listeners;
				  	  if(getShowComInfo()==1)
					  	{ printf("Agent[%*d]->", (int)(log10((double)(getNumAgent()))+1), speaker);		// display speaker;
				  	  	  for(i=0;i<numNeighbor;i++)
						  	{ if(NeighborInd[i]!=speaker) printf("Agent[%*d];", (int)(log10((double)(getNumAgent()))+1), NeighborInd[i]);	// display listener;
				  	 	 	}
					  	  printf(":");
				  	  	}
					  NumPosFeedback=0; OneToManyCom(getpAgent(speaker), Neighbor, numNeighbor, &NumPosFeedback);
				  	  if(FLOAT_BG_EQ(NumPosFeedback/(double)(numNeighbor-1)/(double)(getNumInfoChange()), getSucRat())) SucCom=1;
				  	  else SucCom=0;
			  	 	  // move agents;
				  	  if(Moved[speaker]==-1) 
					  	{ // speaker is not moved; 
					  	  if(SucCom==0) { MoveAgent(getpAgent(speaker), NULL, 0, SucCom); Moved[speaker]=speaker; }	// random move speaker;
					  	  else if(SucCom==1) { MoveAgent(getpAgent(speaker), Neighbor, numNeighbor, SucCom); Moved[speaker]=speaker; }	// move speaker but keeping distance constrain;
						  // move its neighbors;
						  for(i=0;i<numNeighbor;i++)
						  	{ if((NeighborInd[i]!=speaker)&&(Moved[NeighborInd[i]]==-1)&&(SucCom==1))
					  		  	{ MoveNeighbor(getpAgent(NeighborInd[i]), getpAgent(speaker)); Moved[NeighborInd[i]]=NeighborInd[i];	// this agent is moved;
					  			}
					  		}
					  	}
				  	}
				  else if(get1toMCom()==0)
				  	{ // 2) random select one from the neighbor as listener;
					  do{ ind=(int)(Rand0_1*numNeighbor);
				  	  }while((ind==numNeighbor)||(NeighborInd[ind]==speaker));
				  	  listener=NeighborInd[ind];

					  if(getShowComInfo()==1) printf("Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);		// display speaker;
					  NumPosFeedback=0; HorCom(getpAgent(speaker), getpAgent(listener), &NumPosFeedback);	// horizontal transmission;
				  	  if(FLOAT_BG_EQ(NumPosFeedback/(double)(getNumInfoChange()), getSucRat())) SucCom=1;
				  	  else SucCom=0;					  
				  	  // move agents;
				  	  if(Moved[speaker]==-1) 
					  	{ // speaker is not moved; 
					  	  if(SucCom==0) { MoveAgent(getpAgent(speaker), NULL, 0, SucCom); Moved[speaker]=speaker; }	// random move speaker;
					  	  else if(SucCom==1) 
						  	{ // move speaker but keeping distance constrain;
						  	  SingNeighbor=new CAgent * [1]; assert(SingNeighbor!=NULL);
						  	  SingNeighbor[0]=getpAgent(listener);
						  	  MoveAgent(getpAgent(speaker), SingNeighbor, 1, SucCom); 
							  delete [] SingNeighbor; SingNeighbor=NULL;	// delete SingNeighbor; 
							  Moved[speaker]=speaker; 
							}	
						  if((listener!=speaker)&&(Moved[listener]==-1)&&(SucCom==1)) { MoveNeighbor(getpAgent(listener), getpAgent(speaker)); Moved[listener]=listener; }	// move this agent;
				  	  	}
				  	}			  
			  	}
			  else 
			  	{ if(getShowComInfo()==1) printf("Agent[%*d]: No neighbor, No talk; Random move!\n", (int)(log10((double)(getNumAgent()))+1), speaker);	// no neigbors, no talk;
				  if(Moved[speaker]==-1) 
				  	{ // speaker is not moved; 
				  	  MoveAgent(getpAgent(speaker), NULL, 0, 0); Moved[speaker]=speaker;	// move speaker;
				  	}	  	  
			  	}
		 	}
		 else if(getSelfTalkFlag()==1)
		 	{ // allow self-talk;
			  if(numNeighbor>=1)
			 	{ // at least there is himself in the neighbor; 
		 		  // select listener, 2 ways;
				  if(get1toMCom()==1)
				  	{ // 1) all neighbors are listeners;
					  if(getShowComInfo()==1)
					  	{ printf("Agent[%*d]->", (int)(log10((double)(getNumAgent()))+1), speaker);		// display speaker;
				  		  for(i=0;i<numNeighbor;i++)
						  	printf("Agent[%*d];", (int)(log10((double)(getNumAgent()))+1), NeighborInd[i]);	// display listener;
				  		  printf(":");
					  	}
					  NumPosFeedback=0; OneToManyCom(getpAgent(speaker), Neighbor, numNeighbor, &NumPosFeedback);
				  	  if(FLOAT_BG_EQ(NumPosFeedback/(double)(numNeighbor-1)/(double)(getNumInfoChange()), getSucRat())) SucCom=1;
					  else SucCom=0;
				  	  // move agents;
					  if(Moved[speaker]==-1) 
					  	{ // speaker is not moved; 
					  	  if(SucCom==0) { MoveAgent(getpAgent(speaker), NULL, 0, SucCom); Moved[speaker]=speaker; }	// random move speaker;
					  	  else if(SucCom==1) { MoveAgent(getpAgent(speaker), Neighbor, numNeighbor, SucCom); Moved[speaker]=speaker; }	// move speaker but keeping distance constrain;
						  // move its neighbors;
					  	  for(i=0;i<numNeighbor;i++)
					 	 	{ if((NeighborInd[i]!=speaker)&&(Moved[NeighborInd[i]]==-1)&&(SucCom==1))
					  		  	{ MoveNeighbor(getpAgent(NeighborInd[i]), getpAgent(speaker)); Moved[NeighborInd[i]]=NeighborInd[i];	// this agent is moved;
					  			}
						    	}
					  	}
				  	}
				  else if(get1toMCom()==0)
				  	{ // 2) random select one from the neighbor as listener;
					  if(numNeighbor==1) listener=speaker;
					  else
					  	{ do{ ind=(int)(Rand0_1*numNeighbor);
				  	  	  }while(ind==numNeighbor);
				  	  	  listener=NeighborInd[ind];
					  	}
					  
				  	  if(getShowComInfo()==1) printf("Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);		// display speaker;
					  NumPosFeedback=0; HorCom(getpAgent(speaker), getpAgent(listener), &NumPosFeedback);	// horizontal transmission;
				  	  if(FLOAT_BG_EQ(NumPosFeedback/(double)(getNumInfoChange()), getSucRat())) SucCom=1;
				  	  else SucCom=0;					  
				  	  // move agents;
				  	  if(Moved[speaker]==-1) 
					  	{ // speaker is not moved; 
					  	  if(SucCom==0) { MoveAgent(getpAgent(speaker), NULL, 0, SucCom); Moved[speaker]=speaker; }	// random move speaker;
					  	  else if(SucCom==1) 
						  	{ // move speaker but keeping distance constrain;
						  	  SingNeighbor=new CAgent * [1]; assert(SingNeighbor!=NULL);
						  	  SingNeighbor[0]=getpAgent(listener);
						  	  MoveAgent(getpAgent(speaker), SingNeighbor, 1, SucCom); 
							  delete [] SingNeighbor; SingNeighbor=NULL;	// delete SingNeighbor; 
							  Moved[speaker]=speaker; 
							}
						  if((listener!=speaker)&&(Moved[listener]==-1)&&(SucCom==1)) { MoveNeighbor(getpAgent(listener), getpAgent(speaker)); Moved[listener]=listener; }	// move this agent;
					  	}
				  	}				  
			  	}			  
		 	}		 
		 delete [] Neighbor; Neighbor=NULL;	// delete NeighBor;
		 delete [] NeighborInd; NeighborInd=NULL;	// delete NeighborInd;
		 numNeighbor=0;
				  
		 // check whether all agents speak;
		 for(i=0;i<getNumAgent();i++)
		 	{ if(AgentInd[i]==-1) break;
		 	}
	}while(i!=getNumAgent());
	delete [] AgentInd; AgentInd=NULL;	// delete AgentInd;
	delete [] Moved; Moved=NULL;	// delete Moved;
}

void CSystem::Child_World2D(int numlearn, int *repAgentInd, CAgent **newAgent)
{ // Adult-Child, Child-Child, Child-Adult communication in world2d mode;
	assert((0<=numlearn)&&(numlearn<getNumLearn())); assert((repAgentInd!=NULL)&&(newAgent!=NULL));
	int speaker, listener, repA1, repA2;
	CAgent **Neighbor=NULL;	// each agent's neighbors, agents that within block dist, including himself;
	int *NeighborInd=NULL, numNeighbor;	// each agent's neighbors' index;
	double rannum=Rand0_1;
	
	if(getShowComInfo()==1) printf("Learn=%*d, ", (int)(log10((double)(getNumLearn()))+1), numlearn+1);	// displace learn time;				  
	// decide whether it is parent-child talk or child-child talk;
	speaker=listener=repA1=repA2=-1;
	if(FLOAT_SM_EQ(rannum, getAdultChildRatio()))
	  	{ // parent-child talk;
	  	  // select listener from repAgent;
	  	  if(getNumAgentRep()==1) repA2=0;
		  else
		  	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA2==getNumAgentRep());						  
			}
		  listener=repAgentInd[repA2];
		  numNeighbor=0; CrtNeighborAdult(newAgent[repA2], Neighbor, NeighborInd, &numNeighbor);	// build up his neighbor;
	 	  if(numNeighbor>=1)
	 	  	{ // decide the teacher for repagent;
  	  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) 
			  	{ speaker=listener;	// the parent is the speaker;
			  	  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;
  	  	  	  	}
			  else
  			  	{ // other agent as the speaker; 
				  if((numNeighbor==1)&&(Neighbor[0]==getpAgent(listener)))
				  	{ // no other neighbor, has to bio-talk; 
				  	  speaker=listener;	// the parent is the speaker;
			  	  	  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  	  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;
  	  	  	  		}
				  else
				  	{ // there are other neighbors; 
				  	  do{ repA1=(int)(Rand0_1*numNeighbor);
	  	  		  	  }while((repA1==numNeighbor)||(NeighborInd[repA1]==listener));
					  speaker=NeighborInd[repA1];
					  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  	  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;
  	  	  	  		}
 		 	  	}						  
	 	  	}
		  delete [] Neighbor; Neighbor=NULL;	// delete Neighbor;
		  delete [] NeighborInd; NeighborInd=NULL;	// delete NeighborInd;
		  numNeighbor=0;
		}
	  else if((FLOAT_BG(rannum, getAdultChildRatio()))&&(FLOAT_SM_EQ(rannum, getAdultChildRatio()+getChildChildRatio())))
	  	{ // child-child talk;
	  	  // select speaker and listener;
		  if(getNumAgentRep()!=1)
	  	  	{ // select a child speaker;
	  	  	  do{ repA1=(int)(Rand0_1*getNumAgentRep());
	  	  	  }while(repA1==getNumAgentRep());
			  speaker=repAgentInd[repA1];
			  numNeighbor=0; CrtNeighborChild(newAgent[repA1], newAgent, repAgentInd, getNumAgentRep(), Neighbor, NeighborInd, &numNeighbor);	// build up his neighbor;
	 	  	  if(getSelfTalkFlag()==0)
	  	  		{ // no self-talk;
				  if(numNeighbor>=2)
				  	{ do{ repA2=(int)(Rand0_1*numNeighbor);
	  	  	  	  	  }while((repA2==numNeighbor)||(repA1==repA2));
			  	  	  listener=repAgentInd[repA2];
					  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  	  	 	  HorCom(newAgent[repA1], newAgent[repA2], NULL);
		  		  	}
				  else 
				  	{ // no other neighbor, has to bio-talk; 
				  	  listener=speaker;	// the parent is the speaker;
			  	  	  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  	  VerCom(0, getpAgent(speaker), newAgent[repA1], listener, NULL);	// vertical communication;
  	  	  	  		}
				}
		  	  else if(getSelfTalkFlag()==1)
		  	  	{ // allow self-talk;
		  	  	  if(numNeighbor>=1)
				  	{ do{ repA2=(int)(Rand0_1*numNeighbor);
	  	  	  	  	  }while(repA2==numNeighbor);
			  	  	  listener=repAgentInd[repA2];
					  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  	  	 	  HorCom(newAgent[repA1], newAgent[repA2], NULL);
		  		  	}
				}
			  delete [] Neighbor; Neighbor=NULL;	// delete Neighbor;
		  	  delete [] NeighborInd; NeighborInd=NULL;	// delete NeighborInd;
		  	  numNeighbor=0;
			}
	  	}
	  else
	  	{ // child-adult talk;
	  	  // select speaker from repAgent;
	  	  if(getNumAgentRep()==1) repA1=0;
		  else
		  	{ do{ repA1=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA1==getNumAgentRep());						  
			}
		  speaker=repAgentInd[repA1];
		  numNeighbor=0; CrtNeighborAdult(newAgent[repA1], Neighbor, NeighborInd, &numNeighbor);	// build up his neighbor;
	 	  if(numNeighbor>=1)
	 	  	{ // decide the listener for repagent;
  	  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) 
			  	{ listener=speaker;	// the parent is the listener;
			  	  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;
  	  	  	  	}
			  else
  			  	{ // other agent as the listener; 
				  if((numNeighbor==1)&&(Neighbor[0]==getpAgent(speaker)))
				  	{ // no other neighbor, has to bio-talk; 
				  	  listener=speaker;	// the parent is the listener;
			  	  	  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  	  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;
  	  	  	  		}
				  else
				  	{ // there are other neighbors; 
				  	  do{ repA2=(int)(Rand0_1*numNeighbor);
	  	  		  	  }while((repA2==numNeighbor)||(NeighborInd[repA2]==speaker));
					  listener=NeighborInd[repA2];
					  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
			  	  	  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;
  	  	  	  		}
 		 	  	}
	 	  	}
		  delete [] Neighbor; Neighbor=NULL;	// delete Neighbor;
		  delete [] NeighborInd; NeighborInd=NULL;	// delete NeighborInd;
		  numNeighbor=0;
	  	}
}

void CSystem::World2D(FILE **f, char **fileNam)
{ // 2D world com;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	int numCom, numLearn;	// for mixed horizontal and vertical transmissions;

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;
	
	adjAdultChild();	// adjust children to adults;
	// horizontal/vertical transmission: geo-restricted communication;
	if(getHorObliMix()==0)
		{ // horizontal transmission;
		  for(i=0;i<getNumCom();i++)
			{ Adult_World2D(i);
		  	  Forget(1, i, getppAgent(), getNumAgent());	// every 1 communication, let all agents forget;
			  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, NULL);	// testing parameters;
			}
		}
	else if(getHorObliMix()==2)
		{ // mixed transmission;
		  for(i=0;i<getNumGen();i++)
		  	{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
		  	
			  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;
			  for(j=0;j<getNumAgentRep();j++)
			  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  printf("\n");

			  if(getMixHorVer()==0)
			  	{ // no mix horizontal and vertical transmissions; 
			  	  // learning from others;
			  	  for(j=0;j<getNumLearn();j++)
			  		{ Child_World2D(j, repAgentInd, newAgent);
				  	  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
			  	  	}

				  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;

				  // then, horizontal transmission; 
			  	  printf("Communicate:\n");
			  	  for(j=0;j<getNumCom();j++)
			  		{ Adult_World2D(j);
					  Forget(1, j, getppAgent(), getNumAgent());	// every 1 communication, let all agents forget;
			  	  	}
			  	}
			  else if(getMixHorVer()==1)
			  	{ // mixed horizontal and vertical transmissions;
			  	  numCom=0; numLearn=0;
				  for(j=0;j<getNumCom()+getNumLearn();j++)
				  	{ if((FLOAT_SM_EQ(Rand0_1, _Half))&&(numCom<getNumCom())) 
				  		{ Adult_World2D(numCom);	// horizontal transmission; 
						  Forget(1, numCom, getppAgent(), getNumAgent());	// every 1 communication, let all agents forget;
						  numCom++;
						}
				  	  else 
					  	{ Child_World2D(numLearn, repAgentInd, newAgent);	// learning from others;
						  Forget(getNumAgentRep(), numLearn, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
						  numLearn++; 
						}
				  	}
				  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	}
			  		  	  
			  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL);	// testing parameters;
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;
			}
		}
}

void CSystem::Adult_SolCom(int numcom, CNet *adjMatrix)
{ // Adult-Adult communication in solcom mode (under different social structures);
	assert((0<=numcom)&&(numcom<getNumCom())); assert(adjMatrix!=NULL);
	int speaker, listener;

	speaker=listener=-1;
	if(getSelfTalkFlag()==0)
		{ // not allow self-talk;
		  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
		  }while((speaker==getNumAgent())||(listener==getNumAgent())||(speaker==listener)||(FLOAT_EQ(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiLow())));
		}
	else if(getSelfTalkFlag()==1)
		{ // allow self-talk;
		  do{ speaker=(int)(Rand0_1*getNumAgent()); listener=(int)(Rand0_1*getNumAgent());
		  }while((speaker==getNumAgent())||(listener==getNumAgent())||((speaker!=listener)&&(FLOAT_EQ(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiLow()))));
		}
	if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), numcom+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
	HorCom(getpAgent(speaker), getpAgent(listener), NULL);	// horizontal communication;
}

void CSystem::Child_SolCom(int numlearn, int *repAgentInd, CAgent **newAgent, CNet *adjMatrix)
{ // Adult-Child, Child-Child, Child-Adult communication in solcom mode (under different social structures);
	assert((0<=numlearn)&&(numlearn<getNumLearn())); assert((repAgentInd!=NULL)&&(newAgent!=NULL)); assert(adjMatrix!=NULL);
	int i, j, speaker, listener, repA1, repA2;
	bool NoNeighbor;
	double rannum=Rand0_1;
	
	if(getShowComInfo()==1) printf("Learn=%*d, ", (int)(log10((double)(getNumLearn()))+1), numlearn+1);	// displace learn time;	
	// decide whether it is parent-child talk or child-child talk;
	speaker=listener=repA1=repA2=-1;
	if(FLOAT_SM_EQ(rannum, getAdultChildRatio()))
	 	{ // parent-child talk;
	 	  // select listener from repAgent;
	 	  if(getNumAgentRep()==1) repA2=0;
		  else
		  	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA2==getNumAgentRep());						  
			}
		  listener=repAgentInd[repA2];
  	  	  // decide the teacher for repagent;
  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) speaker=listener;	// the parent is the speaker;
	  	  else
		  	{ // other agent as the speaker; 
			  // first check whether this agent has neighbors;
			  for(i=0;i<adjMatrix->getSize();i++)
			  	{ if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiUp())) break;
			  	}
			  if(i==adjMatrix->getSize()) speaker=listener;	// this agent has no neighbors;
			  else
			  	{ // this agent has neighbors; 
			  	  do{ speaker=(int)(Rand0_1*getNumAgent());
	  	  	  	  }while((speaker==getNumAgent())||(speaker==listener)||(FLOAT_EQ(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiLow())));
		  		}
	  	  	}
		  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;					  
	  	}
	else if((FLOAT_BG(rannum, getAdultChildRatio()))&&(FLOAT_SM_EQ(rannum, getAdultChildRatio()+getChildChildRatio())))
	 	{ // child-child talk;
	  	  // select speaker and listener;
	  	  if(getNumAgentRep()!=1)
	  	  	{ if(getSelfTalkFlag()==0)
	  	  		{ // no self-talk;
	  	  		  do{ repA2=(int)(Rand0_1*getNumAgentRep()); 
				  }while(repA2==getNumAgentRep());
				  listener=repAgentInd[repA2];
				  // check whether this agent has neighbors also replaced;
				  NoNeighbor=1;
				  for(i=0;i<adjMatrix->getSize();i++)
				  	{ if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiUp())) 
				  		{ for(j=0;j<getNumAgentRep();j++)
				  			{ if(repAgentInd[j]==i) NoNeighbor=0; 
				  			}
				  		}
				  	}
				  if(NoNeighbor==1) { repA1=repA2; speaker=listener; }	// no child neighbor, self-talk;
				  else if(NoNeighbor==0)
				  	{ // select anothe neighbor child to talk; 
				  	  do{ repA1=(int)(Rand0_1*getNumAgentRep());
	  	  	  	  	  }while((repA1==getNumAgentRep())||(repA1==repA2)||(FLOAT_EQ(adjMatrix->getAdjMatrixMember(repAgentInd[repA1], listener), adjMatrix->getConWeiLow())));
			  	  	  speaker=repAgentInd[repA1];
				  	}
	  	  		}
		  	  else if(getSelfTalkFlag()==1)
		  	  	{ // allow self-talk;
		  	  	  do{ repA2=(int)(Rand0_1*getNumAgentRep()); 
				  }while(repA2==getNumAgentRep());
				  listener=repAgentInd[repA2];
				  // check whether this agent has neighbors also replaced;
				  NoNeighbor=1;
				  for(i=0;i<adjMatrix->getSize();i++)
				  	{ if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiUp())) 
				  		{ for(j=0;j<getNumAgentRep();j++)
				  			{ if(repAgentInd[j]==i) NoNeighbor=0; 
				  			}
				  		}
				  	}
				  if(NoNeighbor==1) { repA1=repA2; speaker=listener; }	// no child neighbor, self-talk;
				  else if(NoNeighbor==0)
				  	{ // select anothe neighbor child to talk; 
				  	  do{ repA1=(int)(Rand0_1*getNumAgentRep());
	  	  	  	  	  }while((repA1==getNumAgentRep())||((repA1!=repA2)&&(FLOAT_EQ(adjMatrix->getAdjMatrixMember(repAgentInd[repA1], listener), adjMatrix->getConWeiLow()))));
			  	  	  speaker=repAgentInd[repA1];
				  	}
			 	}
			  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  	  HorCom(newAgent[repA1], newAgent[repA2], NULL);
		  	}
	  	}
	else
		{ // child-adult talk;
		  // select speaker from repAgent;
	 	  if(getNumAgentRep()==1) repA1=0;
		  else
		  	{ do{ repA1=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA1==getNumAgentRep());						  
			}
		  speaker=repAgentInd[repA1];
  	  	  // decide the listener for repagent;
  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) listener=speaker;	// the parent is the listener;
	  	  else
		  	{ // other agent as the listener; 
			  // first check whether this agent has neighbors;
			  for(i=0;i<adjMatrix->getSize();i++)
			  	{ if(FLOAT_EQ(adjMatrix->getAdjMatrixMember(speaker, i), adjMatrix->getConWeiUp())) break;
			  	}
			  if(i==adjMatrix->getSize()) listener=speaker;	// this agent has no neighbors;
			  else
			  	{ // this agent has neighbors; 
			  	  do{ listener=(int)(Rand0_1*getNumAgent());
	  	  	  	  }while((listener==getNumAgent())||(listener==speaker)||(FLOAT_EQ(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiLow())));
		  		}
	  	  	}
		  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;		
		}
}

void CSystem::setLocalView(int speaker, double **&LocalView, CNet *adjMatrix)
{ // set up LocalView for speaker;
	assert((0<=speaker)&&(speaker<getNumAgent())); assert(adjMatrix!=NULL);
	int i, j, AginLocalView, indavaConAg;
	int NoAvaCon;
	double rannum, **avaConAg=NULL;	// record the number of agents already connected to the speaker;
	
	// initialize LocalView;
	LocalView=new double * [adjMatrix->getLocalView()]; assert(LocalView!=NULL);
	for(i=0;i<adjMatrix->getLocalView();i++)
		{ LocalView[i]=new double [2]; assert(LocalView[i]!=NULL);
		  for(j=0;j<2;j++)
		  	LocalView[i][j]=-1.0;
		}
	LocalView[0][0]=(double)(speaker);
	if(getSelfGrow()==1) LocalView[0][1]=adjMatrix->calNodeDeg(speaker);
	else if(getSelfGrow()==2) LocalView[0][1]=calAgUR(speaker);

	// select other agent into localView;
	// calculate how many available connections of the speaker;
	NoAvaCon=0; NoAvaCon=adjMatrix->calAvaCon(speaker);
	if(NoAvaCon!=0)
		{ // record agents already connected to the speaker;
		  // initialize avaConAg;
		  avaConAg=new double * [NoAvaCon]; assert(avaConAg!=NULL);
		  for(i=0;i<NoAvaCon;i++)
		  	{ avaConAg[i]=new double [2]; assert(avaConAg[i]!=NULL);
		  	  for(j=0;j<2;j++)
			  	avaConAg[i][j]=-1;
		  	}
		  // record agents already connected to the speaker;
		  i=0;
		  for(j=0;j<adjMatrix->getSize();j++)
		  	{ if(FLOAT_BG_EQ(adjMatrix->getAdjMatrixMember(speaker, j), adjMatrix->getConWeiThres()))
		  		{ avaConAg[i][0]=(double)(j);
		  		  if(getSelfGrow()==1) avaConAg[i][1]=adjMatrix->calNodeDeg(j);
				  else if(getSelfGrow()==2) avaConAg[i][1]=calAgUR(j);
				  i++;
		  		}
		  	}
		  // normalize avaConAg;
		  for(i=1;i<NoAvaCon;i++)
		  	avaConAg[i][1]+=avaConAg[i-1][1];
		  if(avaConAg[NoAvaCon-1][1]==0.0)
		  	{ for(i=0;i<NoAvaCon-1;i++)
		  		avaConAg[i][1]=(i+1)*1.0/(double)(NoAvaCon);
		  	}
		  else
		  	{ for(i=0;i<NoAvaCon-1;i++)
		  		avaConAg[i][1]/=avaConAg[NoAvaCon-1][1];
		  	}
		  avaConAg[NoAvaCon-1][1]=1.0;
		}
	
	if(NoAvaCon>adjMatrix->getLocalView()-1)
		{ // select the agents with higher connection weights or understanding rate;
		  for(i=1;i<adjMatrix->getLocalView();i++)
		  	{ do{ // random select an agent in avaConAg;
		  	 	  indavaConAg=-1; rannum=Rand0_1;
		  		  if(FLOAT_SM_EQ(rannum, avaConAg[0][1])) indavaConAg=0;
				  else if(FLOAT_EQ(rannum, 1.0)) indavaConAg=NoAvaCon-1;
				  else
				  	{ for(j=1;j<NoAvaCon;j++)
				  		{ if((FLOAT_BG(rannum, avaConAg[j-1][1]))&&(FLOAT_SM_EQ(rannum, avaConAg[j][1]))) 
				  			{ indavaConAg=j; break; }
				  		}
				  	}
				  // check whether AginLocalView is already in LocalView;
				  for(j=0;j<i;j++)
				  	{ if((int)(LocalView[j][0])==(int)(avaConAg[indavaConAg][0])) break;
				  	}
		  	  }while(j!=i);
		  	  LocalView[i][0]=avaConAg[indavaConAg][0]; LocalView[i][1]=avaConAg[indavaConAg][1]; 
		  	}
		}
	else if(NoAvaCon==adjMatrix->getLocalView()-1)
		{ // select all agents already connected to the speaker;
		  for(i=1;i<adjMatrix->getLocalView();i++)
		  	{ LocalView[i][0]=avaConAg[i-1][0]; LocalView[i][1]=avaConAg[i-1][1]; }
		}
	else if(NoAvaCon<adjMatrix->getLocalView()-1)
		{ // select all agents already connected to the speaker;
		  for(i=1;i<NoAvaCon+1;i++)
		  	{ LocalView[i][0]=avaConAg[i-1][0]; LocalView[i][1]=avaConAg[i-1][1]; }
		  // randomly select other agents into LocalView;
		  for(i=NoAvaCon+1;i<adjMatrix->getLocalView();i++)
			{ do{ do{ AginLocalView=(int)(Rand0_1*getNumAgent());
			  	  }while((AginLocalView==getNumAgent())||(AginLocalView==speaker));
			  	  for(j=0;j<i;j++)
			  		{ if((int)(LocalView[j][0])==AginLocalView) break; 
				  	}
			  }while(j!=i);
		  	  LocalView[i][0]=(double)(AginLocalView);
			  if(getSelfGrow()==1) LocalView[i][1]=adjMatrix->calNodeDeg(AginLocalView);
			  else if(getSelfGrow()==2) LocalView[i][1]=calAgUR(AginLocalView);
			}
		}
	
	// adjust LocalView[*][1];
	for(i=1;i<adjMatrix->getLocalView();i++)
		LocalView[i][1]+=LocalView[i-1][1];
	if(LocalView[adjMatrix->getLocalView()-1][1]==0.0)
		{ for(i=0;i<adjMatrix->getLocalView()-1;i++)
			LocalView[i][1]=(i+1)*1.0/(double)(adjMatrix->getLocalView());	// equal distribution;
		}
	else
		{ for(i=0;i<adjMatrix->getLocalView()-1;i++)
			LocalView[i][1]/=LocalView[adjMatrix->getLocalView()-1][1];
		}
	LocalView[adjMatrix->getLocalView()-1][1]=1.0;

	if(NoAvaCon!=0)
		{ // release avaConAg; 
		  for(i=0;i<NoAvaCon;i++)
			{ delete [] avaConAg[i]; avaConAg[i]=NULL; }
		  delete [] avaConAg; avaConAg=NULL;
		}
}

void CSystem::Adult_SolGrowCom(int numcom, CNet *adjMatrix)
{ // Adult-Adult communication in solcom mode (under self-grow social structures);
	assert((0<=numcom)&&(numcom<getNumCom())); assert(adjMatrix!=NULL);
	int i, randAg, NumPosFeedback, speaker, listener;
	double rannum, **LocalView=NULL;	// LocalView[*][0] stores the index of agents in the speaker's local view; LocalView[*][1] stores these agents' degree or UR;
	bool SucCom;

	// select speaker;
	do{ speaker=(int)(Rand0_1*getNumAgent());
	}while(speaker==getNumAgent());
	setLocalView(speaker, LocalView, adjMatrix);	// initialize LocalView;
	
	listener=-1;
	if(getSelfTalkFlag()==0)
		{ // not allow self-talk;
		  do{ rannum=Rand0_1;
		  }while(FLOAT_SM(rannum, LocalView[0][1]));
		  if(FLOAT_EQ(rannum, 1.0)) listener=(int)(LocalView[adjMatrix->getLocalView()-1][0]);
		  else
		  	{ for(i=1;i<adjMatrix->getLocalView();i++)
		 	 	{ if((FLOAT_BG_EQ(rannum, LocalView[i-1][1]))&&(FLOAT_SM(rannum, LocalView[i][1]))) listener=(int)(LocalView[i][0]);
		  		}
		  	}
		}
	else if(getSelfTalkFlag()==1)
		{ // allow self-talk;
		  do{ randAg=(int)(Rand0_1*getNumAgent());
		  }while(randAg==getNumAgent());
		  if(randAg==speaker) listener=speaker;	// self-talk;
		  else
		  	{ do{ rannum=Rand0_1;
		  	  }while(FLOAT_SM(rannum, LocalView[0][1]));
		  	  if(FLOAT_EQ(rannum, 1.0)) listener=(int)(LocalView[adjMatrix->getLocalView()-1][0]);
		  	  else
		 	 	{ for(i=1;i<adjMatrix->getLocalView();i++)
		 		 	{ if((FLOAT_BG_EQ(rannum, LocalView[i-1][1]))&&(FLOAT_SM(rannum, LocalView[i][1]))) listener=(int)(LocalView[i][0]);
		  			}
		  		}
		  	}
		}
	if(getShowComInfo()==1) printf("Com=%*d, Agent[%*d]->Agent[%*d]:", (int)(log10((double)(getNumCom()))+1), numcom+1, (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display communication time, communication's speaker and listener;
	NumPosFeedback=0; HorCom(getpAgent(speaker), getpAgent(listener), &NumPosFeedback);
	if(FLOAT_BG_EQ(NumPosFeedback/(double)(getNumInfoChange()), getSucRat())) SucCom=1;
	else SucCom=0;					  
	adjMatrix->AdjCon(speaker, listener, SucCom);	// adjust connection weight;
	// delete LocalView;
	for(i=0;i<adjMatrix->getLocalView();i++)
		{ delete [] LocalView[i]; LocalView[i]=NULL; }
	delete [] LocalView; LocalView=NULL;
}

void CSystem::Child_SolGrowCom(int numlearn, int *repAgentInd, CAgent **newAgent, CNet *adjMatrix)
{ // Adult-Child, Child-Child, Child-Adult communication in solcom mode (under self-grow social structures);
	assert((0<=numlearn)&&(numlearn<getNumLearn())); assert((repAgentInd!=NULL)&&(newAgent!=NULL)); assert(adjMatrix!=NULL);
	int i, j, speaker, listener, repA1, repA2;
	bool NoNeighbor;
	double rannum=Rand0_1;
	
	if(getShowComInfo()==1) printf("Learn=%*d, ", (int)(log10((double)(getNumLearn()))+1), numlearn+1);	// displace learn time;	
	// decide whether it is parent-child talk or child-child talk;
	speaker=listener=repA1=repA2=-1;
	if(FLOAT_SM_EQ(rannum, getAdultChildRatio()))
	 	{ // parent-child talk;
	 	  // select listener from repAgent;
	 	  if(getNumAgentRep()==1) repA2=0;
		  else
		  	{ do{ repA2=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA2==getNumAgentRep());
			}
		  listener=repAgentInd[repA2];
  	  	  // decide the teacher for repagent;
  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) speaker=listener;	// the parent is the speaker;
	  	  else
		  	{ // other agent as the speaker; 
			  // first check whether this agent has neighbors;
			  for(i=0;i<adjMatrix->getSize();i++)
			  	{ if(FLOAT_BG_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiThres())) break;
			  	}
			  if(i==adjMatrix->getSize()) speaker=listener;	// this agent has no neighbors;
			  else
			  	{ // this agent has neighbors; 
			  	  do{ speaker=(int)(Rand0_1*getNumAgent());
	  	  	  	  }while((speaker==getNumAgent())||(speaker==listener)||(FLOAT_SM(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiThres())));
		  		}
	  	  	}
		  if(getShowComInfo()==1) printf("Agent[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  VerCom(0, getpAgent(speaker), newAgent[repA2], listener, NULL);	// vertical communication;					  
	  	}
	else if((FLOAT_BG(rannum, getAdultChildRatio()))&&(FLOAT_SM_EQ(rannum, getAdultChildRatio()+getChildChildRatio())))
	 	{ // child-child talk;
	  	  // select speaker and listener;
	  	  if(getNumAgentRep()!=1)
	  	  	{ if(getSelfTalkFlag()==0)
	  	  		{ // no self-talk;
	  	  		  do{ repA2=(int)(Rand0_1*getNumAgentRep()); 
				  }while(repA2==getNumAgentRep());
				  listener=repAgentInd[repA2];
				  // check whether this agent has neighbors also replaced;
				  NoNeighbor=1;
				  for(i=0;i<adjMatrix->getSize();i++)
				  	{ if(FLOAT_BG_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiThres())) 
				  		{ for(j=0;j<getNumAgentRep();j++)
				  			{ if(repAgentInd[j]==i) NoNeighbor=0; 
				  			}
				  		}
				  	}
				  if(NoNeighbor==1) { repA1=repA2; speaker=listener; }	// no child neighbor, self-talk;
				  else if(NoNeighbor==0)
				  	{ // select anothe neighbor child to talk; 
				  	  do{ repA1=(int)(Rand0_1*getNumAgentRep());
	  	  	  	  	  }while((repA1==getNumAgentRep())||(repA1==repA2)||(FLOAT_SM(adjMatrix->getAdjMatrixMember(repAgentInd[repA1], listener), adjMatrix->getConWeiThres())));
			  	  	  speaker=repAgentInd[repA1];
				  	}
	  	  		}
		  	  else if(getSelfTalkFlag()==1)
		  	  	{ // allow self-talk;
		  	  	  do{ repA2=(int)(Rand0_1*getNumAgentRep()); 
				  }while(repA2==getNumAgentRep());
				  listener=repAgentInd[repA2];
				  // check whether this agent has neighbors also replaced;
				  NoNeighbor=1;
				  for(i=0;i<adjMatrix->getSize();i++)
				  	{ if(FLOAT_BG_EQ(adjMatrix->getAdjMatrixMember(i, listener), adjMatrix->getConWeiThres())) 
				  		{ for(j=0;j<getNumAgentRep();j++)
				  			{ if(repAgentInd[j]==i) NoNeighbor=0; 
				  			}
				  		}
				  	}
				  if(NoNeighbor==1) { repA1=repA2; speaker=listener; }	// no child neighbor, self-talk;
				  else if(NoNeighbor==0)
				  	{ // select anothe neighbor child to talk; 
				  	  do{ repA1=(int)(Rand0_1*getNumAgentRep());
	  	  	  	  	  }while((repA1==getNumAgentRep())||((repA1!=repA2)&&(FLOAT_SM(adjMatrix->getAdjMatrixMember(repAgentInd[repA1], listener), adjMatrix->getConWeiThres()))));
			  	  	  speaker=repAgentInd[repA1];
				  	}
			 	}
			  if(getShowComInfo()==1) printf("Child[%*d]->Child[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  	  HorCom(newAgent[repA1], newAgent[repA2], NULL);
		  	}
	  	}
	else
		{ // child-adult talk;
		  // select speaker from repAgent;
	 	  if(getNumAgentRep()==1) repA1=0;
		  else
		  	{ do{ repA1=(int)(Rand0_1*getNumAgentRep());
		  	  }while(repA1==getNumAgentRep());						  
			}
		  speaker=repAgentInd[repA1];
  	  	  // decide the listener for repagent;
  	  	  if(FLOAT_SM_EQ(Rand0_1, getVerProb())) listener=speaker;	// the parent is the listener;
	  	  else
		  	{ // other agent as the listener; 
			  // first check whether this agent has neighbors;
			  for(i=0;i<adjMatrix->getSize();i++)
			  	{ if(FLOAT_BG_EQ(adjMatrix->getAdjMatrixMember(speaker, i), adjMatrix->getConWeiThres())) break;
			  	}
			  if(i==adjMatrix->getSize()) listener=speaker;	// this agent has no neighbors;
			  else
			  	{ // this agent has neighbors; 
			  	  do{ listener=(int)(Rand0_1*getNumAgent());
	  	  	  	  }while((listener==getNumAgent())||(listener==speaker)||(FLOAT_SM(adjMatrix->getAdjMatrixMember(speaker, listener), adjMatrix->getConWeiThres())));
		  		}
	  	  	}
		  if(getShowComInfo()==1) printf("Child[%*d]->Agent[%*d]:", (int)(log10((double)(getNumAgent()))+1), speaker, (int)(log10((double)(getNumAgent()))+1), listener);	// display learn agents;
		  VerCom(1, newAgent[repA1], getpAgent(listener), speaker, NULL);	// vertical communication;		
		}
}

void CSystem::SolCom(FILE **f, char **fileNam)
{ // language and social structure emergence;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	int numCom, numLearn;	// in mixed horizontal and vertical transmissions;
	CNet *adjMatrix=new CNet (getNumAgent()); assert(adjMatrix!=NULL);	// initialize adjMatrix;	

	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, adjMatrix);
	RecComMode(f[11], fileNam[11], adjMatrix);
	TestPara(0, 0, f, fileNam, NULL, adjMatrix);	// initial parameters;
	
	adjAdultChild();	// adjust children to adults;
	if(adjMatrix->getNetTyp()!=-1)
		{ // communication under fixed social network;
		  // horizontal/vertical transmission: random communication;
		  if(getHorObliMix()==0)
			{ // horizontal transmission;
			  for(i=0;i<getNumCom();i++)
				{ Adult_SolCom(i, adjMatrix);
			  	  Forget(getNumAgent(), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, adjMatrix);	// testing parameters;
				}
			}
		  else if(getHorObliMix()==1)
			{ // vertical/oblique transmission;
			  for(i=0;i<getNumGen();i++)
				{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
			  
			  	  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;			  
			  	  for(j=0;j<getNumAgentRep();j++)
				  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  	  printf("\n");
				
			  	  // learning from others;
			  	  for(j=0;j<getNumLearn();j++)
				  	{ Child_SolCom(j, repAgentInd, newAgent, adjMatrix);
					  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learn, let all new agents forget;
				  	}
				  	
			  	  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  
				  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, NULL, adjMatrix);	// testing parameters;
				  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  	  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;
			    	}
			}
		  else if(getHorObliMix()==2)
			{ // mixed transmission;
			  for(i=0;i<getNumGen();i++)
		  		{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;

				  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;			  
			  	  for(j=0;j<getNumAgentRep();j++)
				  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  	  printf("\n");

				  if(getMixHorVer()==0)
				  	{ // no mix horizontal and vertical transmissions;
				  	  // learning from others;	
			  	  	  for(j=0;j<getNumLearn();j++)
				 		{ Child_SolCom(j, repAgentInd, newAgent, adjMatrix);
					  	  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
				  		}
				  
				  	  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  	  
				  	  // then, horizontal transmission;
				  	  printf("Communicate:\n");
			  	  	  for(j=0;j<getNumCom();j++)
						{ Adult_SolCom(j, adjMatrix);
			  	  	  	  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				  		}
				  	}
				  else if(getMixHorVer()==1)
				  	{ // mixed horizontal and vertical transmission;
				  	  numCom=0; numLearn=0;
					  for(j=0;j<getNumCom()+getNumLearn();j++)
					  	{ if((FLOAT_SM_EQ(Rand0_1, _Half))&&(numCom<getNumCom())) 
					  		{ Adult_SolCom(numCom, adjMatrix);	// horizontal transmission;
							  Forget(getNumAgent(), numCom, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
							  numCom++; 
							}
						  else 
						  	{ Child_SolCom(numLearn, repAgentInd, newAgent, adjMatrix);	// learning from others;
						  	  Forget(getNumAgentRep(), numLearn, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
							  numLearn++;
							}
					  	}
					  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  	}
				  
 				  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, NULL, adjMatrix);	// testing parameters;
		  		  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  	  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;
				}
			}
		}
	else if(adjMatrix->getNetTyp()==-1)
		{ // self-growing network;
		  // horizontal/vertical transmission: random communication;
		  if(getHorObliMix()==0)
			{ // horizontal transmission;
			  for(i=0;i<getNumCom();i++)
				{ Adult_SolGrowCom(i, adjMatrix);
			  	  Forget(getNumAgent(), i, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				  if((i+1)%((int)(((getNumCom()<=getCheckFre())?(double)(getCheckFre()):getNumCom())/(double)(getCheckFre())))==0) TestPara(0, i+1, f, fileNam, NULL, adjMatrix);	// testing parameters;
				}
			}
		  else if(getHorObliMix()==1)
		  	{ // vertical/oblique transmission;
			  for(i=0;i<getNumGen();i++)
				{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
			  
			  	  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;			  
			  	  for(j=0;j<getNumAgentRep();j++)
				  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  	  printf("\n");
				
			  	  // learning from others;
			  	  for(j=0;j<getNumLearn();j++)
				  	{ Child_SolGrowCom(j, repAgentInd, newAgent, adjMatrix);
					  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
			  	  	}
				  	
			  	  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  
				  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, NULL, adjMatrix);	// testing parameters;
				  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  	  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;
			    	}
			}
		  else if(getHorObliMix()==2)
		  	{ // mixed transmission;
			  for(i=0;i<getNumGen();i++)
		  		{ InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;

				  printf("Gen=%*d: Replace ", (int)(log10((double)(getNumGen()))+1), i+1);	// displace generation time and replaced agent;			  
			  	  for(j=0;j<getNumAgentRep();j++)
				  	printf("Agent[%*d] ", (int)(log10((double)(getNumAgentRep()))+1), repAgentInd[j]);
			  	  printf("\n");

				  if(getMixHorVer()==0)
				  	{ // no mix horizontal and vertical transmissions;
				  	  // learning from others;	
			  	  	  for(j=0;j<getNumLearn();j++)
				 		{ Child_SolGrowCom(j, repAgentInd, newAgent, adjMatrix);
					  	  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
			  	  	  	}
				  
				  	  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;

					  // then, horizontal transmission;
				  	  printf("Communicate:\n");
			  	  	  for(j=0;j<getNumCom();j++)
						{ Adult_SolGrowCom(j, adjMatrix);
					  	  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
			  	  	  	}
				  	}
				  else if(getMixHorVer()==1)
				  	{ // mixed horizontal and vertical transmission;
				  	  numCom=0; numLearn=0;
					  for(j=0;j<getNumCom()+getNumLearn();j++)
					  	{ if((FLOAT_SM_EQ(Rand0_1, _Half))&&(numCom<getNumCom())) 
					  		{ Adult_SolGrowCom(numCom, adjMatrix);	// horizontal transmission;
					  		  Forget(getNumAgent(), numCom, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;								
							  numCom++; 
							}
						  else 
						  	{ Child_SolGrowCom(numLearn, repAgentInd, newAgent, adjMatrix);	// learning from others;
						  	  Forget(getNumAgentRep(), numLearn, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
						  	  numLearn++;
						  	}
					  	}
					  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
			  	  	}
				  
 				  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, NULL, adjMatrix);	// testing parameters;
		  		  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			  	  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;
				}
			}
		}	
	delete adjMatrix; adjMatrix=NULL;	// delete adjMatrix;
}

void CSystem::SelParRepSp(int type, int size, double **sort, double **fitness, int *chosenIndex)
{ // type=0, random select (different); 1, random select (identical is possible); 2, chose the best (identical is possible); 3, chose the worst (different);
	assert((type==0)||(type==1)||(type==2)||(type==3)); assert((sort!=NULL)&&(fitness!=NULL)); assert(chosenIndex!=NULL);
	int i, j, index, same;
	double rannum;

	switch(type)
		{ case 0: // random select (different);
		  		for(i=0;i<size;i++)
					{ do{ do{ index=(int)(Rand0_1*getNumAgent());
				 	  	  }while(index==getNumAgent());
				 	  	  same=0;
					  	  for(j=0;j<i;j++)
						 	{ if(chosenIndex[j]==index) 
						 		{ same=1; break; }
						  	}
				  	  }while(same==1);
				  	  chosenIndex[i]=index;
					}
				break;
		  case 1: // random select (identical is possible);
			    for(i=0;i<size;i++)
					{ do{ index=(int)(Rand0_1*getNumAgent());
					  }while(index==getNumAgent());
					  chosenIndex[i]=index;
					}
				break;
		  case 2: // select the best (identical is possible);
			  	for(i=0;i<size;i++)
					{ rannum=Rand0_1; index=-1;
					  if(FLOAT_SM_EQ(rannum, fitness[0][1])) index=0;
					  else if(FLOAT_EQ(rannum, fitness[getNumAgent()-1][1])) index=getNumAgent()-1;
					  else
						{ for(j=1;j<getNumAgent();j++)
							{ if((FLOAT_SM(fitness[j-1][1], rannum))&&(FLOAT_SM_EQ(rannum, fitness[j][1]))) 
								{ index=j; break; }
							}
						}
					  assert(index!=-1);
					  chosenIndex[i]=(int)(fitness[index][0]);
					}
				break;
		  case 3: // select the worst (different);
				for(i=0;i<size;i++)
					chosenIndex[i]=(int)(sort[getNumAgent()-1-i][0]);
				break;
		  default: break;
		}
}

void CSystem::GeneCulSel(int *repAgentInd, int *IndexParent, int *IndexSp, double **genome, int size1, int size2)
{ // gene-cultural selection of parents; getGeneSelType()=0, randomly select agents as parents; 1, select best agents; getCulSelType()=0, randomly select agents as speakers; 1, select best agents;
	assert(repAgentInd!=NULL); assert((IndexParent!=NULL)&&(IndexSp!=NULL)); assert(genome!=NULL); assert((size1!=0)&&(size2!=0));
	int i, j, k; 
	double **fitness=NULL, **sort=NULL, temp;
		
	// initialize fitness and sort;
	fitness=new double * [size1]; assert(fitness!=NULL);
	sort=new double * [size1]; assert(sort!=NULL);
	for(i=0;i<size1;i++)
		{ fitness[i]=new double [size2]; assert(fitness[i]!=NULL);
		  for(j=0;j<size2;j++)
		  	fitness[i][j]=genome[i][j];
		  sort[i]=new double [size2]; assert(sort[i]!=NULL);
		  for(j=0;j<size2;j++)
		  	sort[i][j]=genome[i][j];
		}	
	// sort sort;
	for(i=1;i<size1;i++)
		for(j=0;j<size1-i;j++)
			{ if(FLOAT_SM(sort[j][size2-1], sort[j+1][size2-1]))
				{ for(k=0;k<size2;k++)
					{ temp=sort[j+1][k];
					  sort[j+1][k]=sort[j][k];
					  sort[j][k]=temp;
					}
				}
			}
	// normalize fitness and sort;
	for(i=1;i<size1;i++)
		{ fitness[i][size2-1]+=fitness[i-1][size2-1];
		  sort[i][size2-1]+=sort[i-1][size2-1];
		}
	if((FLOAT_EQ(fitness[size1-1][size2-1], 0.0))&&(FLOAT_EQ(sort[size1-1][size2-1], 0.0)))
		{ // all members are 0.0, then, let each member equal to 1/size1;
		  for(i=0;i<size1;i++)
		  	{ fitness[i][size2-1]=(i+1)*1.0/(double)(size1);
		  	  sort[i][size2-1]=(i+1)*1.0/(double)(size1);
		  	}
		}
	else
		{ // normalize!
		  for(i=0;i<size1;i++)
			{ fitness[i][size2-1]/=fitness[size1-1][size2-1];
			  sort[i][size2-1]/=sort[size1-1][size2-1];
			}
		}

	// gene-cultural selection;	
	if((getGeneSelType()==0)&&(getCulSelType()==0))
		{ SelParRepSp(1, getNumAgentRep(), sort, fitness, IndexParent);	// random select parents;
		  SelParRepSp(0, getNumAgentRep(), sort, fitness, repAgentInd);	// random select agents to be replaced;
		  SelParRepSp(1, getNumSp(), sort, fitness, IndexSp);	// random select speakers;
		}
	else if((getGeneSelType()==0)&&(getCulSelType()==1))
		{ SelParRepSp(1, getNumAgentRep(), sort, fitness, IndexParent);	// random select parents;
		  SelParRepSp(0, getNumAgentRep(), sort, fitness, repAgentInd);	// random select agents to be replaced;
		  SelParRepSp(2, getNumSp(), sort, fitness, IndexSp);	// select the best as speakers;
		}
	else if((getGeneSelType()==1)&&(getCulSelType()==0))
		{ SelParRepSp(2, getNumAgentRep(), sort, fitness, IndexParent);	// select the best as parents;
		  SelParRepSp(3, getNumAgentRep(), sort, fitness, repAgentInd);	// select the worst to be replaced;
		  SelParRepSp(1, getNumSp(), sort, fitness, IndexSp);	// random select speakers;		 
		}
	else if((getGeneSelType()==1)&&(getCulSelType()==1))
		{ SelParRepSp(2, getNumAgentRep(), sort, fitness, IndexParent);	// select the best as parents;
		  SelParRepSp(3, getNumAgentRep(), sort, fitness, repAgentInd);	// select the worst to be replaced;
		  SelParRepSp(2, getNumSp(), sort, fitness, IndexSp);	// select the best as speakers;
		}

	// delete fitness and sort;
	for(i=0;i<size1;i++)
		{ delete [] fitness[i]; fitness[i]=NULL; 
		  delete [] sort[i]; sort[i]=NULL;	
		}
	delete [] fitness; fitness=NULL;
	delete [] sort; sort=NULL;
}

void CSystem::MutRCMem(int cond, double *newRC, int *newMem)
{ // mutation of RC or Mem; cond=1, mutation of RC; 2, mutation of memory capacity;
	assert((cond==1)||(cond==2));
	double rannum;
	if(cond==1)
		{ if(FLOAT_SM(Rand0_1, getMutRate())) 
			{ do{ rannum=Rand0_1;
				  if(FLOAT_SM(rannum, _Half)) *newRC-=getMutStep();
				  else if(FLOAT_BG(rannum, _Half)) *newRC+=getMutStep();
			  }while(FLOAT_EQ(rannum, _Half));
			  if(FLOAT_SM_EQ(*newRC, getLearnAbiLow())) *newRC=getLearnAbiLow();
			  else if(FLOAT_BG_EQ(*newRC, getLearnAbiUp())) *newRC=getLearnAbiUp();
			}
		}
	else if(cond==2)
		{ if(FLOAT_SM(Rand0_1, getMutRate())) 
			{ do{ rannum=Rand0_1;
				  if(FLOAT_SM(rannum, _Half)) *newMem-=getMemMutStep();
				  else if(FLOAT_BG(rannum, _Half)) *newMem+=getMemMutStep();
			  }while(FLOAT_EQ(rannum, _Half));
			  if(*newMem<0) *newMem=0;
			}
		}
}

void CSystem::GACulopt(int com_gen, CAgent **&newAgent, int *repAgentInd, int *IndexParent, int *IndexSp)
{ // using genetic selection and cultural selection to adjust indiviudals' learning abilities;
	assert(newAgent!=NULL); assert(repAgentInd!=NULL); assert((IndexParent!=NULL)&&(IndexSp!=NULL)); 
	int i;
	double **genome=NULL, newRC;	// record individual's CueReliab;

	if((com_gen+1)%getGATimeScale()==0)
		{ printf("GA optimization after %*d Com/Gen;\n", (int)(log10((double)(com_gen+1))+1), com_gen+1); 
		  // first, record individuals' CueReliab; create genome;
		  genome=new double * [getNumAgent()]; assert(genome!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ genome[i]=new double [2]; assert(genome[i]!=NULL);
			  genome[i][0]=(double)(getpAgent(i)->getIndex());	// agent's index;
			  genome[i][1]=calAgUR(i);	// agent's UR;
			}	  

		  GeneCulSel(repAgentInd, IndexParent, IndexSp, genome, getNumAgent(), 2);	// cultural selection of speakers;

		  for(i=0;i<getNumAgentRep();i++)
		  	{ CrtnewAgent(getpAgent(IndexParent[i]), newAgent[i]);
		  	  newAgent[i]->setIndex(repAgentInd[i]);
			  newRC=getpAgent(IndexParent[i])->getCueReliabAg(); MutRCMem(1, &newRC, NULL);	// possible mutation;
			  newAgent[i]->setCueReliabAg(newRC);			  
		  	}

		  // delete genome;
		  for(i=0;i<getNumAgent();i++) { delete [] genome[i]; genome[i]=NULL; }
		  delete [] genome; genome=NULL;
		}	
}

void CSystem::GACulrandCom(FILE **f, char **fileNam)
{ // language and individual learning abilities can coevolve;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL, *IndexParent=NULL, *IndexSp=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	
	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	adjAdultChild();	// adjust children to adults;
	// horizontal/vertical transmission: random communication;
	if(getHorObliMix()==2)
		{ // mixed transmission;
		  for(i=0;i<getNumGen();i++)
		  	{ // first, horizontal communication; 
		  	  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL);	// testing parameters;

			  printf("Gen=%*d: Communication:\n", (int)(log10((double)(getNumGen()))+1), i+1);
			  for(j=0;j<getNumCom();j++)
			  	{ Adult_RandCom(j);
			  	  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
			    }

			  printf("Replace All Agents\n"); InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;

			  // initialize IndexParent and IndexSp;
			  IndexParent=new int [getNumAgentRep()]; assert(IndexParent!=NULL);
			  for(j=0;j<getNumAgentRep();j++)
			  	IndexParent[j]=-1;
			  IndexSp=new int [getNumSp()]; assert(IndexSp!=NULL);
			  for(j=0;j<getNumSp();j++)
			  	IndexSp[j]=-1;
			  GACulopt(i, newAgent, repAgentInd, IndexParent, IndexSp);	// coevolution;

			  // learning from parents;
		  	  for(j=0;j<getNumLearn();j++)
		  		{ Child_RandCom(0, j, repAgentInd, newAgent, IndexSp, NULL);  
			  	  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
		  	  	}
			  
			  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;

			  delete [] IndexSp; IndexSp=NULL;	// delete IndexSp;
			  delete [] IndexParent; IndexParent=NULL;	// delete IndexParent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;			  
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
		  	}
		}
}

void CSystem::MemLangopt(int com_gen, CAgent **&newAgent, int *repAgentInd, int *IndexParent, int *IndexSp)
{ // using genetic selection and cultural selection to adjust indiviudals' memory capacity;
	assert(newAgent!=NULL); assert(repAgentInd!=NULL); assert((IndexParent!=NULL)&&(IndexSp!=NULL)); 
	int i, MemCap;
	double **genome=NULL;	// record individual's memory capacity;
	
	if((com_gen+1)%getGATimeScale()==0)
		{ printf("GA optimization after %*d Com/Gen;\n", (int)(log10((double)(com_gen+1))+1), com_gen+1); 
		  // first, record individuals' memory capacity; create genome;
		  genome=new double * [getNumAgent()]; assert(genome!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ genome[i]=new double [2]; assert(genome[i]!=NULL);
			  genome[i][0]=(double)(getpAgent(i)->getIndex());	// agent's index;
			  genome[i][1]=calAgUR(i);	// agent's UR;
			}	  

		  GeneCulSel(repAgentInd, IndexParent, IndexSp, genome, getNumAgent(), 2);	// cultural selection of speakers;

		  for(i=0;i<getNumAgentRep();i++)
		  	{ CrtnewAgent(getpAgent(IndexParent[i]), newAgent[i]);
		  	  newAgent[i]->setIndex(repAgentInd[i]);

			  // adjust memory capacity;
			  switch(getMemMutType())
			  	{ case 1: // IMMem mutation, adjust IMMem->m_nMaxNumCombOption;
			  			  MemCap=getpAgent(IndexParent[i])->getpIMMem()->getMaxNumCombOption(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpIMMem()->setMaxNumCombOption(MemCap);
						  break;
				  case 2: // LTMem mutation, adjust LTMem->m_nMaxLexRule, m_nMaxCat, and m_nMaxSynRule;
						  // lexical rule list size;	
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  // syntactic rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxSynRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxSynRule(MemCap);
						  // category list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxCat(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxCat(MemCap);
				  		  break;
				  case 3: // Buffer mutation, adjust Buffer->m_nMaxBufSize;
					  	  MemCap=getpAgent(IndexParent[i])->getpBuffer()->getMaxBufSize(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpBuffer()->setMaxBufSize(MemCap);
				  		  break;
				  case 4: // LexRule mutation, adjust LTMem->m_nMaxLexRule;
					  	  // lexical rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  break;
				  case 5: // Cat mutation, adjust LTMem->m_nMaxCat;
					      // syntactic rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxSynRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxSynRule(MemCap);
						  break;
				  case 6: // SynRule mutation, adjust LTMem->m_nMaxSynRule;
					   	  // category list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxCat(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxCat(MemCap);
				  		  break;
				  case 7: // multi-evolution, buffer+ILMem+LTMem(LexRule);
				  		  // Buffer;
					  	  MemCap=getpAgent(IndexParent[i])->getpBuffer()->getMaxBufSize(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpBuffer()->setMaxBufSize(MemCap);
						  // ILMem;
						  MemCap=getpAgent(IndexParent[i])->getpIMMem()->getMaxNumCombOption(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpIMMem()->setMaxNumCombOption(MemCap);
						  // LexRule;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  break;
				  default: break;
			  	}
		  	}

		  // delete genome;
		  for(i=0;i<getNumAgent();i++) { delete [] genome[i]; genome[i]=NULL; }
		  delete [] genome; genome=NULL;
		}	
}

void CSystem::MemLangrandCom(FILE **f, char **fileNam)
{ // language and memory capacity can coevolve;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL, *IndexParent=NULL, *IndexSp=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	
	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	// horizontal/vertical transmission: random communication;
	if(getHorObliMix()==2)
		{ // mixed transmission;
		  for(i=0;i<getNumGen();i++)
			{ // first, horizontal communication; 
			  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL); // testing parameters;
	
			  printf("Gen=%*d: Communication:\n", (int)(log10((double)(getNumGen()))+1), i+1);
			  for(j=0;j<getNumCom();j++)
				{ Adult_RandCom(j);
				  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				}
			  
			  printf("Replace All Agents\n"); InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
	
			  // initialize IndexParent and IndexSp;
			  IndexParent=new int [getNumAgentRep()]; assert(IndexParent!=NULL);
			  for(j=0;j<getNumAgentRep();j++)
				IndexParent[j]=-1;
			  IndexSp=new int [getNumSp()]; assert(IndexSp!=NULL);
			  for(j=0;j<getNumSp();j++)
				IndexSp[j]=-1;
			  MemLangopt(i, newAgent, repAgentInd, IndexParent, IndexSp); // coevolution;
	
			  // learning from parents;
			  for(j=0;j<getNumLearn();j++)
				{ Child_RandCom(0, j, repAgentInd, newAgent, IndexSp, NULL);  
				  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
				}
				  
			  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
	
			  delete [] IndexSp; IndexSp=NULL;	// delete IndexSp;
			  delete [] IndexParent; IndexParent=NULL;	// delete IndexParent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;			  
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			}
		}
}

void CSystem::JALTMLangopt(int com_gen, CAgent **&newAgent, int *repAgentInd, int *IndexParent, int *IndexSp)
{ // using genetic selection and cultural selection to adjust indiviudals' joint attention and LTM capacity;
	assert(newAgent!=NULL); assert(repAgentInd!=NULL); assert((IndexParent!=NULL)&&(IndexSp!=NULL)); 
	int i, MemCap;
	double **genome=NULL, newRC;	// record individual's memory capacity and RC;
	
	if((com_gen+1)%getGATimeScale()==0)
		{ printf("GA optimization after %*d Com/Gen;\n", (int)(log10((double)(com_gen+1))+1), com_gen+1); 
		  // first, record individuals' memory capacity; create genome;
		  genome=new double * [getNumAgent()]; assert(genome!=NULL);
		  for(i=0;i<getNumAgent();i++)
			{ genome[i]=new double [2]; assert(genome[i]!=NULL);
			  genome[i][0]=(double)(getpAgent(i)->getIndex());	// agent's index;
			  genome[i][1]=calAgUR(i);	// agent's UR;
			}	  

		  GeneCulSel(repAgentInd, IndexParent, IndexSp, genome, getNumAgent(), 2);	// cultural selection of speakers;

		  for(i=0;i<getNumAgentRep();i++)
		  	{ CrtnewAgent(getpAgent(IndexParent[i]), newAgent[i]);
		  	  newAgent[i]->setIndex(repAgentInd[i]);
			  // adjust RC;
			  newRC=getpAgent(IndexParent[i])->getCueReliabAg(); MutRCMem(1, &newRC, NULL);	// possible mutation;
			  newAgent[i]->setCueReliabAg(newRC);
			  // adjust memory capacity;
			  switch(getMemMutType())
			  	{ case 1: // IMMem mutation, adjust IMMem->m_nMaxNumCombOption;
			  			  MemCap=getpAgent(IndexParent[i])->getpIMMem()->getMaxNumCombOption(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpIMMem()->setMaxNumCombOption(MemCap);
						  break;
				  case 2: // LTMem mutation, adjust LTMem->m_nMaxLexRule, m_nMaxCat, and m_nMaxSynRule;
						  // lexical rule list size;	
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  // syntactic rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxSynRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxSynRule(MemCap);
						  // category list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxCat(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxCat(MemCap);
				  		  break;
				  case 3: // Buffer mutation, adjust Buffer->m_nMaxBufSize;
					  	  MemCap=getpAgent(IndexParent[i])->getpBuffer()->getMaxBufSize(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpBuffer()->setMaxBufSize(MemCap);
				  		  break;
				  case 4: // LexRule mutation, adjust LTMem->m_nMaxLexRule;
					  	  // lexical rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  break;
				  case 5: // Cat mutation, adjust LTMem->m_nMaxCat;
					      // syntactic rule list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxSynRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxSynRule(MemCap);
						  break;
				  case 6: // SynRule mutation, adjust LTMem->m_nMaxSynRule;
					   	  // category list size;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxCat(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxCat(MemCap);
				  		  break;
				  case 7: // multi-evolution, buffer+ILMem+LTMem(LexRule);
				  		  // Buffer;
					  	  MemCap=getpAgent(IndexParent[i])->getpBuffer()->getMaxBufSize(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpBuffer()->setMaxBufSize(MemCap);
						  // ILMem;
						  MemCap=getpAgent(IndexParent[i])->getpIMMem()->getMaxNumCombOption(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  newAgent[i]->getpIMMem()->setMaxNumCombOption(MemCap);
						  // LexRule;
						  MemCap=getpAgent(IndexParent[i])->getpLTMem()->getMaxLexRule(); MutRCMem(2, NULL, &MemCap); // possible mutation;
						  if(MemCap<1) MemCap=1;
						  newAgent[i]->getpLTMem()->setMaxLexRule(MemCap);
						  break;
				  default: break;
			  	}
		  	}

		  // delete genome;
		  for(i=0;i<getNumAgent();i++) { delete [] genome[i]; genome[i]=NULL; }
		  delete [] genome; genome=NULL;
		}	
}

void CSystem::JALTMrandCom(FILE **f, char **fileNam)
{ // Lang-JA&LTM coevolution;
	assert((f!=NULL)&&(fileNam!=NULL));
	int i, j, *repAgentInd=NULL, *IndexParent=NULL, *IndexSp=NULL;
	CAgent **newAgent=NULL;	// selfcopy for self-talk; newAgent for replacing agents;
	
	printf("Com=0, Initialization\n"); RecComMode(NULL, NULL, NULL);
	TestPara(0, 0, f, fileNam, NULL, NULL);	// initial parameters;

	// horizontal/vertical transmission: random communication;
	if(getHorObliMix()==2)
		{ // mixed transmission;
		  for(i=0;i<getNumGen();i++)
			{ // first, horizontal communication; 
			  if((i+1)%((int)(((getNumGen()<=getCheckFre())?(double)(getCheckFre()):getNumGen())/(double)(getCheckFre())))==0) TestPara(i+1, 0, f, fileNam, repAgentInd, NULL); // testing parameters;
	
			  printf("Gen=%*d: Communication:\n", (int)(log10((double)(getNumGen()))+1), i+1);
			  for(j=0;j<getNumCom();j++)
				{ Adult_RandCom(j);
				  Forget(getNumAgent(), j, getppAgent(), getNumAgent());	// every getNumAgent() communications, let all agents forget;
				}
			  
			  printf("Replace All Agents\n"); InitNewAgent(repAgentInd, newAgent);	// choose agents to replace;
	
			  // initialize IndexParent and IndexSp;
			  IndexParent=new int [getNumAgentRep()]; assert(IndexParent!=NULL);
			  for(j=0;j<getNumAgentRep();j++)
				IndexParent[j]=-1;
			  IndexSp=new int [getNumSp()]; assert(IndexSp!=NULL);
			  for(j=0;j<getNumSp();j++)
				IndexSp[j]=-1;
			  JALTMLangopt(i, newAgent, repAgentInd, IndexParent, IndexSp); // coevolution;
	
			  // learning from parents;
			  for(j=0;j<getNumLearn();j++)
				{ Child_RandCom(0, j, repAgentInd, newAgent, IndexSp, NULL);  
				  Forget(getNumAgentRep(), j, newAgent, getNumAgentRep());	// every getNumAgentRep() learns, let all new agents forget;
				}
				  
			  ReplaceAgent(repAgentInd, newAgent);	// replace newAgent;
	
			  delete [] IndexSp; IndexSp=NULL;	// delete IndexSp;
			  delete [] IndexParent; IndexParent=NULL;	// delete IndexParent;
			  delete [] repAgentInd; repAgentInd=NULL;	// delete repAgentInd;			  
			  delete [] newAgent; newAgent=NULL;	// delete newAgent;
			}
		}
}
