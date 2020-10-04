// Rule.cpp: implement membership functions in CLexRule, CCat, CSynRule;

#include "stdafx.h"

// ---- Include Files;
#include"Rule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CatList's membership function;
CatList::CatList()
{ // construction function;
	InitCatList();
}

CatList::~CatList()
{ // destruction function;
	DestCatList();
}

void CatList::InitCatList()
{ // initialization function;
	m_pCat=NULL; m_dAssoWei=0.0; m_nThemRole=-1;
}

void CatList::DestCatList()
{ // destroy function;
	m_pCat=NULL; m_dAssoWei=0.0; m_nThemRole=-1;
}


// CLexRule's membership functions;
CLexRule::CLexRule()
{ // construction function;
	InitLexRule(0);
}

CLexRule::CLexRule(const CLexRule &init)
{ // copy construction function;
	(*this)=init;
}

CLexRule::~CLexRule()
{ // destruction function;
	DestLexRule();
}

CLexRule & CLexRule::operator = (const CLexRule &right)
{ // copy lexrule; meanutter by value; catlist by address;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestLexRule(); InitLexRule(right.m_nCatNum);
		  // other parameters;
		  setInitBasicRuleStr(right.m_dInitBasicRuleStr); setInitLexRuleStr(right.m_dInitLexRuleStr);
		  setAdjLexRuleStrInc(right.m_dAdjLexRuleStrInc); setAdjLexRuleStrDec(right.m_dAdjLexRuleStrDec);
		  setLexRuleStrUp(right.m_dLexRuleStrUp); setLexRuleStrLow(right.m_dLexRuleStrLow);

		  setInitBasicAssoWei(right.m_dInitBasicAssoWei); setInitAssoWei(right.m_dInitAssoWei);
		  setAdjAssoWeiInc(right.m_dAdjAssoWeiInc); setAdjAssoWeiDec(right.m_dAdjAssoWeiDec);
		  setAssoWeiUp(right.m_dAssoWeiUp); setAssoWeiLow(right.m_dAssoWeiLow);

		  setForgetRateLexRule(right.m_dForgetRateLexRule); setForgetRateAssoWei(right.m_dForgetRateAssoWei);
		  // lexical rule part; copy by value;
		  *m_pMeanUtter=*right.m_pMeanUtter;
		  setLexTyp(right.m_nLexTyp); setLexStr(right.m_dLexStr);
		  // category part; copy by address;
		  setMaxCatNum(right.m_nMaxCatNum);
		  if(getCatNum()!=0)
		  	{ for(i=0;i<getCatNum();i++)
		  		m_ppCatList[i]=right.m_ppCatList[i];	// copy by address;			  
			}
		}
	return *this;
}

bool CLexRule::operator == (const CLexRule &right)
{ // judge whether two lexical rules are same; m_pMeanUtter same;
	assert((getpMeanUtter()!=NULL)&&(right.m_pMeanUtter!=NULL));
	bool value=0;
	if(this==&right) value=1;
	else if((getLexTyp()==right.m_nLexTyp)&&(*(getpMeanUtter())==*(right.m_pMeanUtter))) value=1;
	return value;
}

void CLexRule::InitLexRule(int numCat)
{ // initialization function;
	assert((0<=numCat)&&(numCat<=overallpara.p_nMaxCatNum));
	int i;
	// other parameters;
	setInitBasicRuleStr(overallpara.p_dInitBasicRuleStr); setInitLexRuleStr(overallpara.p_dInitLexRuleStr);
	setAdjLexRuleStrInc(overallpara.p_dAdjLexRuleStrInc); setAdjLexRuleStrDec(overallpara.p_dAdjLexRuleStrInc);
	setLexRuleStrUp(overallpara.p_dLexRuleStrUp); setLexRuleStrLow(overallpara.p_dLexRuleStrLow);

	setInitBasicAssoWei(overallpara.p_dInitBasicAssoWei); setInitAssoWei(overallpara.p_dInitAssoWei);
	setAdjAssoWeiInc(overallpara.p_dAdjAssoWeiInc); setAdjAssoWeiDec(overallpara.p_dAdjAssoWeiDec);
	setAssoWeiUp(overallpara.p_dAssoWeiUp); setAssoWeiLow(overallpara.p_dAssoWeiLow);

	setForgetRateLexRule(overallpara.p_dForgetRateLexRule); setForgetRateAssoWei(overallpara.p_dForgetRateAssoWei);
	// lexical rule part;
	m_pMeanUtter=new CMeanUtter; assert(m_pMeanUtter!=NULL);
	setLexTyp(-1); setLexStr(0.0);
	// category part;
	setMaxCatNum(overallpara.p_nMaxCatNum);
	m_nCatNum=numCat;
	if(getCatNum()==0) m_ppCatList=NULL;
	else
		{ m_ppCatList=new CatList * [getCatNum()]; assert(m_ppCatList!=NULL);
		  for(i=0;i<getCatNum();i++) 
		  	m_ppCatList[i]=NULL;
		}
}

void CLexRule::DestLexRule()
{ // destroy function; notify catgories in catlist, update their lexical rule list's pointers by pointing to NULL;
	// category part;
	EmpCatList();
	setMaxCatNum(0);
	// lexical rule part;
	delete m_pMeanUtter; m_pMeanUtter=NULL;	// release memory directly since it is copied by value!
	setLexTyp(-1); setLexStr(0.0);
	// other parameters;
	setInitBasicRuleStr(0.0); setInitLexRuleStr(0.0);
	setAdjLexRuleStrInc(0.0); setAdjLexRuleStrDec(0.0);
	setLexRuleStrUp(0.0); setLexRuleStrLow(0.0);

	setInitBasicAssoWei(0.0); setInitAssoWei(0.0); 
	setAdjAssoWeiInc(0.0); setAdjAssoWeiDec(0.0);
	setAssoWeiUp(0.0); setAssoWeiLow(0.0);
	
	setForgetRateLexRule(0.0); setForgetRateAssoWei(0.0);
}

// other operations;
void CLexRule::updLexRule(int type)
{ // update CatList;
  // type=1, m_dRuleStr<=m_dRuleStrLow: update CatList's categories, let all CatList[i]->m_pCat=NULL; release CatList and m_pMeanUtter; 
  // type=2, m_pAssoWei[i]<=m_dAssoWeiLow: update CatList[i]'s category, let CatList[i]->m_pCat=NULL; delete CatList[i] and update m_nCatNum; if m_nCatNum=0, release CatList; for holistic rules, delete m_pMeanUtter; 
  // type=3, CatList[i]->m_pCat=NULL: delete CatList[i] and update m_nCatNum; if m_nCatNum=0, release CatList; for holistic rules, delete m_pMeanUtter; 
  	assert((1<=type)&&(type<=3));
	int i, j;
  	CatList **catlisttemp=NULL, *originalcatlist=NULL;
  	int newcatnum;	// after deleteing CatList, the remaining number of category;
  	
  	switch(type)
  		{ case 1: // type=1, m_dRuleStr<=m_dRuleStrLow: update CatList's categories, let all CatList[i]->m_pCat=NULL; release CatList and m_pMeanUtter; 
				for(i=0;i<getCatNum();i++)
					{ if((getpCatList(i)->getpCat()!=NULL)&&(getpCatList(i)->getpCat()->getThemRole()!=-1))
						{ // update CatList's categories;
						  originalcatlist=getpCatList(i);	// keep CatList[i];
						  getpCatList(i)->getpCat()->AdjCat_Lex(this);
						  if(i>=getCatNum())
						  	{ // one of previous CatList is deleted caused by delete CatList[i];
						  	  for(j=getCatNum()-1;j>=0;j--)
						  	  	{ if(getpCatList(j)==originalcatlist) 
						  	  		{ getpCatList(j)->setpCat(NULL); i=j; break; }
						  	  	}
						  	}
						  else if(i<getCatNum())
							{ if(originalcatlist!=getpCatList(i))
						 	 	{ // one of previous CatList is deleted caused by delete CatList[i];
						  		  for(j=i-1;j>=0;j--)
						  		  	{ if(getpCatList(j)==originalcatlist) 
						  		  		{ getpCatList(j)->setpCat(NULL); i=j; break; }
							  	  	}
						  		}
						  	  else getpCatList(i)->setpCat(NULL);	// no other influence, let CatList[i]->m_pCat=NULL;
						  	}
						  originalcatlist=NULL;	// recollect originalcatlist;
						}
					}
				// delete CatList;
				for(i=0;i<getCatNum();i++)
					{ delete m_ppCatList[i]; m_ppCatList[i]=NULL; }
				delete [] m_ppCatList; m_ppCatList=NULL;
				m_nCatNum=0;
				// delete m_pMeanUtter;
				delete m_pMeanUtter; m_pMeanUtter=NULL;
				break;
  		  case 2: // type=2, m_pAssoWei[i]<=m_dAssoWeiLow: update CatList[i]'s category, let CatList[i]->m_pCat=NULL; 
				if(getCatNum()!=0)
					{ for(i=0;i<getCatNum();i++)
						{ if(FLOAT_SM_EQ(getpCatList(i)->getAssoWei(), getAssoWeiLow()))
							{ // update CatList[i]'s category; 
							  if((getpCatList(i)->getpCat()!=NULL)&&(getpCatList(i)->getpCat()->getThemRole()!=-1))
							  	{ // update CatList[i]'s category; 
							  	  originalcatlist=getpCatList(i);	// keep CatList[i];
							  	  getpCatList(i)->getpCat()->AdjCat_Lex(this);
								  if(i>=getCatNum())
								  	{ // one of previous CatList is deleted caused by delete CatList[i];
								  	  for(j=getCatNum()-1;j>=0;j--)
								  	  	{ if(getpCatList(j)==originalcatlist) 
								  	  		{ getpCatList(j)->setpCat(NULL); i=j; break; }
								  	  	}
								  	}
								  else if(i<getCatNum())
								  	{ if(originalcatlist!=getpCatList(i))
								 	 	{ // one of previous CatList is deleted caused by delete CatList[i];
								  		  for(j=i-1;j>=0;j--)
								  		  	{ if(getpCatList(j)==originalcatlist) 
								  		  		{ getpCatList(j)->setpCat(NULL); i=j; break; }
								  		  	}
								 	 	}
								  	  else getpCatList(i)->setpCat(NULL);	// let CatList[i]->m_pCat=NULL;
								  	}
								  originalcatlist=NULL;	// recollect originalcatlist;
							  	}
							}
						}
					}
				break;
 		  case 3: // type=3, CatList[i]->m_pCat=NULL: delete CatList[i] and update m_nCatNum; if m_nCatNum=0, release CatList; for holistic rules, delete m_pMeanUtter; 
  				// calculate the remaining category number;
				if(getCatNum()!=0)
					{ newcatnum=getCatNum();
					  for(i=0;i<getCatNum();i++)
						{ if(getpCatList(i)->getpCat()==NULL) newcatnum--;
						}
					  if((newcatnum!=getCatNum())&&(newcatnum!=0))
						{ // use cattemp and assoweitemp to record the remaining cat list and assoweight; 
						  catlisttemp=new CatList * [newcatnum]; assert(catlisttemp!=NULL);
						  for(i=0;i<newcatnum;i++)
						  	catlisttemp[i]=NULL;
						  i=0;
						  for(j=0;j<getCatNum();j++)
						  	{ if(getpCatList(j)->getpCat()!=NULL) { catlisttemp[i]=getpCatList(j); i++; }
						  	  else { delete m_ppCatList[j]; m_ppCatList[j]=NULL; }
						  	}
						  // delete original CatList;
						  delete [] m_ppCatList; m_ppCatList=NULL;
						  m_nCatNum=0;
						  // copy catlisttemp to CatList;
						  m_nCatNum=newcatnum; m_ppCatList=catlisttemp;
						  catlisttemp=NULL;	// recollect catlisttemp;
						}
					  else if(newcatnum==0)
						{ // delete original CatList;
						  for(i=0;i<getCatNum();i++)
						  	{ delete m_ppCatList[i]; m_ppCatList[i]=NULL; }
						  delete [] m_ppCatList; m_ppCatList=NULL;
						  m_nCatNum=0;
						  // if holistic rule is not successfully used, delete the whole lexical rule;
						  if(getLexTyp()==0) { delete m_pMeanUtter; m_pMeanUtter=NULL; }
						}
					}
				break;
  		  default: break;
  		}
}

void CLexRule::IncLexStr(double adjlexstr, int adjmode)
{ // increase m_dLexStr;
	assert((FLOAT_SM_EQ(0.0, adjlexstr))&&(FLOAT_SM_EQ(adjlexstr, 1.0))); assert((adjmode==0)||(adjmode==1));
	if(FLOAT_NE(adjlexstr, 0.0)) 
		{ if(adjmode==0) setLexStr((FLOAT_BG_EQ(getLexStr()+adjlexstr, getLexRuleStrUp()))?getLexRuleStrUp():(getLexStr()+adjlexstr));
		  else if(adjmode==1) setLexStr((FLOAT_BG_EQ(getLexStr()*(1+adjlexstr), getLexRuleStrUp()))?getLexRuleStrUp():(getLexStr()*(1+adjlexstr)));	// nonlinear increase;
		}
	else 
		{ if(adjmode==0) setLexStr((FLOAT_BG_EQ(getLexStr()+getAdjLexRuleStrInc(), getLexRuleStrUp()))?getLexRuleStrUp():(getLexStr()+getAdjLexRuleStrInc()));
		  else if(adjmode==1) setLexStr((FLOAT_BG_EQ(getLexStr()*(1+getAdjLexRuleStrInc()), getLexRuleStrUp()))?getLexRuleStrUp():(getLexStr()*(1+getAdjLexRuleStrInc())));	// nonlinear increase;
		}
}

void CLexRule::DecLexStr(double adjlexstr)
{ // decrease m_dLexStr; if m_dLexStr=m_dLexRuleStrLow, update this lexical rule;
	assert((FLOAT_SM_EQ(0.0, adjlexstr))&&(FLOAT_SM_EQ(adjlexstr, 1.0)));
	if(FLOAT_NE(adjlexstr, 0.0)) setLexStr((FLOAT_SM_EQ(getLexStr()-adjlexstr, getLexRuleStrLow()))?getLexRuleStrLow():(getLexStr()-adjlexstr));
	else setLexStr((FLOAT_SM_EQ(getLexStr()-getAdjLexRuleStrDec(), getLexRuleStrLow()))?getLexRuleStrLow():(getLexStr()-getAdjLexRuleStrDec()));
	if(FLOAT_SM_EQ(getLexStr(), getLexRuleStrLow())) updLexRule(1);	// type=1, m_dRuleStr<=m_dRuleStrLow; 
}

void CLexRule::IncAssoWei(int i, double adjassowei, int adjmode)
{ // increase CatList[i]->m_dAssoWei;
	assert((0<=i)&&(i<getCatNum())); assert((FLOAT_SM_EQ(0.0, adjassowei))&&(FLOAT_SM_EQ(adjassowei, 1.0))); assert((adjmode==0)||(adjmode==1));
	if(FLOAT_NE(adjassowei, 0.0)) 
		{ if(adjmode==0) getpCatList(i)->setAssoWei((FLOAT_BG_EQ(getpCatList(i)->getAssoWei()+adjassowei, getAssoWeiUp()))?getAssoWeiUp():(getpCatList(i)->getAssoWei()+adjassowei));
		  else if(adjmode==1) getpCatList(i)->setAssoWei((FLOAT_BG_EQ(getpCatList(i)->getAssoWei()*(1+adjassowei), getAssoWeiUp()))?getAssoWeiUp():(getpCatList(i)->getAssoWei()*(1+adjassowei)));	// nonlinear increase;
		}
	else 
		{ if(adjmode==0) getpCatList(i)->setAssoWei((FLOAT_BG_EQ(getpCatList(i)->getAssoWei()+getAdjAssoWeiInc(), getAssoWeiUp()))?getAssoWeiUp():(getpCatList(i)->getAssoWei()+getAdjAssoWeiInc()));
		  else if(adjmode==1) getpCatList(i)->setAssoWei((FLOAT_BG_EQ(getpCatList(i)->getAssoWei()*(1+getAdjAssoWeiInc()), getAssoWeiUp()))?getAssoWeiUp():(getpCatList(i)->getAssoWei()*(1+getAdjAssoWeiInc())));	// nonlinear increase;
		}
}

void CLexRule::DecAssoWei(int i, double adjassowei)
{ // decrease CatList[i]->m_pAssoWei; if CatList[i]->m_pAssoWei=m_dAssoWeiLow, update this lexical rule;
	assert((0<=i)&&(i<getCatNum())); assert((FLOAT_SM_EQ(0.0, adjassowei))&&(FLOAT_SM_EQ(adjassowei, 1.0)));
	if(FLOAT_NE(adjassowei, 0.0)) getpCatList(i)->setAssoWei((FLOAT_SM_EQ(getpCatList(i)->getAssoWei()-adjassowei, getAssoWeiLow()))?getAssoWeiLow():(getpCatList(i)->getAssoWei()-adjassowei));
	else getpCatList(i)->setAssoWei((FLOAT_SM_EQ(getpCatList(i)->getAssoWei()-getAdjAssoWeiDec(), getAssoWeiLow()))?getAssoWeiLow():(getpCatList(i)->getAssoWei()-getAdjAssoWeiDec()));
	if(FLOAT_SM_EQ(getpCatList(i)->getAssoWei(), getAssoWeiLow())) updLexRule(2);	// type=2, m_pAssoWei[i]<=m_dAssoWeiLow; 
}

void CLexRule::InCat(CCat *cat)
{ // insert cat into CatList;
  	assert(cat!=NULL);
	CatList **catlisttemp=NULL, *newcatlist=NULL, *originalcatlist=NULL;
	int newcatnum;	
	int i, j, catindex;
	double assowei;
		
	if(getCatNum()==0)
		{ m_nCatNum++; 
		  m_ppCatList=new CatList * [getCatNum()]; assert(m_ppCatList!=NULL);
		  m_ppCatList[0]=NULL; setpCatList(0, cat, m_dInitAssoWei, cat->getThemRole());
		}
	else if(getCatNum()==getMaxCatNum())
		{ // first, check if cat is already in CatList;
		  for(i=0;i<getCatNum();i++)
		  	{ if(getpCatList(i)->getpCat()==cat) break;	// here inCat, only check address!		  		
		  	}
		  if(i==getCatNum())
		  	{ // randomly delete one category with the lowest association weight;
			  assowei=m_dAssoWeiUp;
			  for(i=0;i<getCatNum();i++)
			  	{ if(FLOAT_SM_EQ(getpCatList(i)->getAssoWei(), assowei))
					assowei=getpCatList(i)->getAssoWei();
			  	}
			  do { catindex=(int)(Rand0_1*getCatNum());
			  }while((catindex==getCatNum())||(FLOAT_NE(getpCatList(catindex)->getAssoWei(), assowei)));
			  // update CatList[catindex]'s cat;
			  originalcatlist=getpCatList(catindex);	// temporary keep getpCatList(catindex);
			  getpCatList(catindex)->getpCat()->AdjCat_Lex(this);
			  if(getCatNum()<=catindex)
			  	{ // due to delete of getpCatList(catindex), one of the previous catlist is also deleted; 
			  	  for(j=getCatNum()-1;j>=0;j--)
					{ if(getpCatList(j)==originalcatlist) 
						{ catindex=j; break; }
			  		}
			  	}
			  else
			  	{ if(originalcatlist!=getpCatList(catindex))
					{ // due to delete of getpcatList(catindex), one of previous catList is also deleted;
					  for(j=catindex-1;j>=0;j--)
					  	{ if(getpCatList(j)==originalcatlist) 
					  		{ catindex=j; break; }
					  	}
					}
			  	}
			  originalcatlist=NULL;	// recollect originalcatlist;
		  	  setpCatList(catindex, cat, m_dInitAssoWei, cat->getThemRole());	// replace CatList[catindex] with new catlist;
			}
		}
	else
		{ // first, check if cat is already in CatList;
		  for(i=0;i<getCatNum();i++)
		  	{ if(getpCatList(i)->getpCat()==cat) break;	// here inCat, only check address!		
		  	}
		  if(i==getCatNum())
		  	{ // this is a new category;
			  // build up newcatlist;	
			  newcatlist=new CatList; assert(newcatlist!=NULL);
			  newcatlist->setpCat(cat); newcatlist->setAssoWei(m_dInitAssoWei); newcatlist->setThemRole(cat->getThemRole());
			  // build up catlisttemp;
		  	  newcatnum=getCatNum()+1;	
		  	  catlisttemp=new CatList * [newcatnum]; assert(catlisttemp!=NULL);
			  for(i=0;i<newcatnum;i++)
			  	catlisttemp[i]=NULL;
		  	  for(i=0;i<newcatnum-1;i++)
		  	  	catlisttemp[i]=getpCatList(i);
		  	  catlisttemp[newcatnum-1]=newcatlist;
		  	  // delete original CatList;
			  delete [] m_ppCatList; m_ppCatList=NULL;
			  m_nCatNum=0;
			  // copy catlisttemp to CatList;
		  	  m_nCatNum=newcatnum; m_ppCatList=catlisttemp;
		  	  catlisttemp=NULL;	// recollect catlisttemp;
		  	  newcatlist=NULL;	// recollect newcatlist;
		  	}
		}
}

void CLexRule::AdjLex_Cat(CCat *cat)
{ // empty CatList[i]->m_pCat=cat to NULL;
	assert(cat!=NULL);
	int i;
	for(i=0;i<getCatNum();i++)
		{ if(getpCatList(i)->getpCat()==cat) setpCatList(i, NULL, getAssoWeiLow(), -1); }	// set CatList[i]->m_pCat=NULL;
	updLexRule(3);	// type=3, CatList[i]->m_pCat=NULL;
}

bool CLexRule::judge_InCat(CCat *cat)
{ // check if cat is in CatList->m_pCat;
	int i;
	bool value=0;
	if(cat!=NULL)
		{ for(i=0;i<getCatNum();i++)
			{ if(getpCatList(i)->getpCat()==cat) { value=1; break; }
			}
		}
	return value;
}

void CLexRule::FindCatListwithHighAsso(int type, int themrole, CatList * &catlist)
{ // find the catlist with themrole and with the highest association weight; type=0, with specific themrole; 1, with no specific themrole;
	assert(((type==0)&&(0<=themrole)&&(themrole<=7))||((type==1)&&(themrole==-1)));
	int i, index;
	double assowei=0.0;
	if(type==0)
		{ // with specific themrole;
		  for(i=0;i<getCatNum();i++)
	 	 	{ if((getpCatList(i)->getThemRole()==themrole)&&(FLOAT_BG_EQ(getpCatList(i)->getAssoWei(), assowei))) assowei=getpCatList(i)->getAssoWei();
	  		}
		  if(FLOAT_NE(assowei, 0.0))
	 	 	{ do{ index=(int)(Rand0_1*getCatNum());
	  		  }while((index==getCatNum())||(getpCatList(index)->getThemRole()!=themrole)||(FLOAT_NE(getpCatList(index)->getAssoWei(), assowei)));
			  catlist=getpCatList(index);
			}
		}
	else if(type==1)
		{ // with no specific themrole;
		  for(i=0;i<getCatNum();i++)
	 	 	{ if(FLOAT_BG_EQ(getpCatList(i)->getAssoWei(), assowei)) assowei=getpCatList(i)->getAssoWei();
	  		}
		  if(FLOAT_NE(assowei, 0.0))
	 	 	{ do{ index=(int)(Rand0_1*getCatNum());
	  		  }while((index==getCatNum())||(FLOAT_NE(getpCatList(index)->getAssoWei(), assowei)));
			  catlist=getpCatList(index);
			}
		}
}

// output part;
void CLexRule::recLexTyp(FILE *f)
{ // record lexical rule's type;
	assert(f!=NULL);
	switch(getLexTyp())
		{ case 0: fprintf(f, "( Hol)"); break;
		  case 1: fprintf(f, "(A|Pt)"); break;
		  case 2: fprintf(f, "(  Pr)"); break;
		  case 3: case 6: fprintf(f, "( APr)"); break;
		  case 4: case 7: fprintf(f, "( APt)"); break;
		  case 5: case 8: fprintf(f, "(PrPt)"); break;
		  default: break;
		}
}

void CLexRule::buildMUstr(char *MUstr, CSemSpace *semspace)
{ // copy M-U mapping to MUstr;
	assert((MUstr!=NULL)&&(semspace!=NULL));
	int i, lenUtter, leftLenUtter, rightLenUtter;
	char *MUItem=new char [2*(int)(log10((double)(getpMeanUtter()->getNumUtterSyl()))+1)]; assert(MUItem!=NULL);
	switch(getLexTyp())
		{ case 0: // holistic rule;
				// build up M-U mapping;
				// meaning part;
				if(getpMeanUtter()->getpMean()->getElement(2*(getpMeanUtter()->getLengthSem())+getpMeanUtter()->getLengthSemRole())==-1)
					{ // "Predicate<Agent>" meaning;
					  strcpy(MUstr, "'"); 
					  sprintf(MUItem, "%d", getpMeanUtter()->getPred(semspace)); strcat(MUstr, (const char *)(MUItem));
					  strcat(MUstr, "<"); 
					  sprintf(MUItem, "%d", getpMeanUtter()->getAg(semspace)); strcat(MUstr, (const char *)(MUItem));
					  strcat(MUstr, ">'<->/");
					}
				else
					{ // "Predicate<Agent, Patient>" meaning;
					  strcpy(MUstr, "'"); 
					  sprintf(MUItem, "%d", getpMeanUtter()->getPred(semspace)); strcat(MUstr, (const char *)(MUItem));
					  strcat(MUstr, "<"); 
					  sprintf(MUItem, "%d", getpMeanUtter()->getAg(semspace)); strcat(MUstr, (const char *)(MUItem));
					  strcat(MUstr, ","); 
					  sprintf(MUItem, "%d", getpMeanUtter()->getPat(semspace)); strcat(MUstr, (const char *)(MUItem));
					  strcat(MUstr, ">'<->/");
					}
				// utterance part;
				lenUtter=getpMeanUtter()->getUtterLen();
				for(i=0;i<lenUtter;i++)
					{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
					  strcat(MUstr, " ");
					}
				strcat(MUstr,"/");
		  		break;
		  case 1:	// Ag/Pat rule;
				// build up M-U mapping;
				// meaning part;
				strcpy(MUstr, "'");
				strcat(MUstr, " ");
				if(getpMeanUtter()->getAg(semspace)!=-1) { sprintf(MUItem, "%d", getpMeanUtter()->getAg(semspace)); strcat(MUstr, (const char *)(MUItem)); }
				else { sprintf(MUItem, "%d", getpMeanUtter()->getPat(semspace)); strcat(MUstr, (const char *)(MUItem)); }
				strcat(MUstr, " '<->/");
				// utterance part;
				lenUtter=getpMeanUtter()->getUtterLen();
				for(i=0;i<lenUtter;i++)
					{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
					  strcat(MUstr, " ");
					}
				strcat(MUstr,"/");
		  		break;
		  case 2: // Pred rule;
		    	// build up M-U mapping;
				// meaning part;
				strcpy(MUstr, "'");
				sprintf(MUItem, "%d", getpMeanUtter()->getPred(semspace)); strcat(MUstr, (const char *)(MUItem));
				if(semspace->getNumMean2()==0) strcat(MUstr, "<#>'<->/");
				else
					{ if(getpMeanUtter()->getPred(semspace)<semspace->TransSemItem(semspace->getpSemPred(semspace->getNumSemPred1())))	
						strcat(MUstr, "<#>'<->/");
					  else strcat(MUstr, "<#,#>'<->/");
					}
				// utterance part;
				lenUtter=getpMeanUtter()->getUtterLen();
				for(i=0;i<lenUtter;i++)
					{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
					  strcat(MUstr, " ");
					}
				strcat(MUstr,"/");
		  		break;
		  case 3: case 6: // AgPred phrase rule;
		    	// build up M-U mapping;
				// meaning part;
				strcpy(MUstr, "'");
		    	sprintf(MUItem, "%d", getpMeanUtter()->getPred(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, "<");
				sprintf(MUItem, "%d", getpMeanUtter()->getAg(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, ",#>'<->/");
				// utterance;
				if(getLexTyp()==3)
					{ // continuous phrase;
					  lenUtter=getpMeanUtter()->getUtterLen();
					  for(i=0;i<lenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr,"/");
					}
				else if(getLexTyp()==6)
					{ // separate phrase;
					  leftLenUtter=getpMeanUtter()->getLeftUtterLen(); rightLenUtter=getpMeanUtter()->getRightUtterLen();
					  for(i=0;i<leftLenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr, "X ");
					  for(i=getpMeanUtter()->getLengthIntgUtter()-rightLenUtter;i<getpMeanUtter()->getLengthIntgUtter();i++)
					  	{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
					  	}
					  strcat(MUstr, "/");
					}
				break;
		  case 4: case 7: // AgPat phrase rule;
		    	// build up M-U mapping;
				// meaning part;
				strcpy(MUstr, "'");
		    	strcat(MUstr, "#<");
		    	sprintf(MUItem, "%d", getpMeanUtter()->getAg(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, ",");
				sprintf(MUItem, "%d", getpMeanUtter()->getPat(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, ">'<->/");
				// utterance;
				if(getLexTyp()==4)
					{ // continuous phrase;
					  lenUtter=getpMeanUtter()->getUtterLen();
					  for(i=0;i<lenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr,"/");
					}
				else if(getLexTyp()==7)
					{ // separate phrase;
					  leftLenUtter=getpMeanUtter()->getLeftUtterLen(); rightLenUtter=getpMeanUtter()->getRightUtterLen();
					  for(i=0;i<leftLenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr, "X ");
					  for(i=getpMeanUtter()->getLengthIntgUtter()-rightLenUtter;i<getpMeanUtter()->getLengthIntgUtter();i++)
					  	{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
					  	}
					  strcat(MUstr, "/");
					}
				break;
		  case 5: case 8:	// PredPat phrasal rule;
		    		// build up M-U mapping;
				// meaning part;
				strcpy(MUstr, "'");
		    	sprintf(MUItem, "%d", getpMeanUtter()->getPred(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, "<#,");
				sprintf(MUItem, "%d", getpMeanUtter()->getPat(semspace)); strcat(MUstr, (const char *)(MUItem));
				strcat(MUstr, ">'<->/");
				// utterance;
				if(getLexTyp()==5)
					{ // continuous phrase;
					  lenUtter=getpMeanUtter()->getUtterLen();
					  for(i=0;i<lenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr,"/");
					}
				else if(getLexTyp()==8)
					{ // separate phrase;
					  leftLenUtter=getpMeanUtter()->getLeftUtterLen(); rightLenUtter=getpMeanUtter()->getRightUtterLen();
					  for(i=0;i<leftLenUtter;i++)
						{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
						}
					  strcat(MUstr, "X ");
					  for(i=getpMeanUtter()->getLengthIntgUtter()-rightLenUtter;i<getpMeanUtter()->getLengthIntgUtter();i++)
					  	{ sprintf(MUItem, "%d", getpMeanUtter()->getpUtter()->getElement(i)); strcat(MUstr, (const char *)(MUItem)); 
						  strcat(MUstr, " ");
					  	}
					  strcat(MUstr, "/");
					}
				break;
		  default: break;
		}
	delete [] MUItem; MUItem=NULL;	// delete MUItem;
}

void CLexRule::RecLexRule(FILE *f, CSemSpace *semspace)
{ // record lexical rule in f;
	assert((f!=NULL)&&(semspace!=NULL));
	char *MUstr=new char [11+3*(int)(log10((double)(getpMeanUtter()->getNumUtterSyl()))+1)+3*getpMeanUtter()->getLengthWord()*((int)(log10((double)(getpMeanUtter()->getNumUtterSyl()))+1)+1)]; assert(MUstr!=NULL);	// there are at most 44 characters: "'2<2,2>'<->/333333333/\0"
	recLexTyp(f); 
	fprintf(f, "(%*.*f)[%*d]:", (int)(-1.0*log10((double)(getLexRuleStrUp()))+0.5)+(int)(-1.0*log10((double)(getLexRuleStrLow()))+0.5)+1, (int)(-1.0*log10((double)(getLexRuleStrLow()))+0.5), getLexStr(), (int)(log10((double)(getMaxCatNum()))+1), getCatNum());
	buildMUstr(MUstr, semspace); fprintf(f, "%s\n", MUstr);
	delete [] MUstr; MUstr=NULL;	// delete MUstr;
}



// CCat's membership functions;
CCat::CCat()
{ // construction function;
	InitCat(0, 0);
}

CCat::CCat(const CCat &init)
{ // copy construction function;
	(*this)=init;
}

CCat::~CCat()
{ // destruction function;
	DestCat();
}

CCat & CCat::operator = (const CCat &right)
{ // copy cat;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestCat(); InitCat(right.m_nLexNum, right.m_nSynNum);
		  setMaxLexNum(right.m_nMaxLexNum); setMaxSynNum(right.m_nMaxSynNum);
		  setThemRole(right.m_nThemRole);
		  if(getLexNum()!=0)
		  	{ for(i=0;i<getLexNum();i++)
			  	setpLexRule(i, right.m_ppLexRule[i]);	// copy by address;
		  	}
		  if(getSynNum()!=0)
		  	{ for(i=0;i<getSynNum();i++)
		 	  	setpSynRule(i, right.m_ppSynRule[i]);	// copy by address;
		  	}
		}
	return *this;
}

bool CCat::operator == (const CCat &right)
{ // check whether two categories are same (themrole same, towards another category, having same syntactic rule, test by address);
	assert((getThemRole()!=-1)&&(right.m_nThemRole!=-1));
	int i, j, lextyp1, lextyp2;
	bool value;
			
	if(this==&right) value=1;
	else
		{ if(getThemRole()!=right.m_nThemRole) value=0;	// themrole not same, they are not same;
		  else
			{ if(getThemRole()==0) value=1;	// if categories contain holistic rules, they are same;
	  	  	  else
		 		{ if((getThemRole()==4)||(getThemRole()==5)||(getThemRole()==6))
		 		  	{ // for phrase rule's category, make sure they contain same type of lexical rules (continuous or separate);
		 		  	  lextyp1=getpLexRule(0)->getLexTyp(); lextyp2=right.m_ppLexRule[0]->getLexTyp();
		 		  	  for(i=0;i<getLexNum();i++)
		 		  	  	{ if(getpLexRule(i)->getLexTyp()!=lextyp2) break;
		 		  	  	}
		 		  	  for(j=0;j<right.m_nLexNum;j++)
		 		  	  	{ if(right.m_ppLexRule[j]->getLexTyp()!=lextyp1) break;
		 		  	  	}
		 		  	  if((i==getLexNum())&&(j==right.m_nLexNum))
		 		  	  	{ // 2 methods to check common category;
						  
		 		  	  	  // method 1: check if they share some common lexical rule; 
		 		  	  	  value=0; 
		 		  	  	  for(i=0;i<getLexNum();i++)
		 		  	  	 	for(j=0;j<right.m_nLexNum;j++)
		 		  	 	 		{ if(*(getpLexRule(i)->getpMeanUtter())==*(right.m_ppLexRule[j]->getpMeanUtter()))
		 		  	  				value=1;
		 		  	  			}
		 		  	  	  /*
		 		  	  	  // method 2: no need to share common lexical rules;
		 		  	  	  value=1;
		 		  	  	  */
		 		  	  	}
		 		  	  else value=0;
		 		  	}
		 		  else
		 		  	{ // 2 methods to check common category;
					  
		 		  	  // method 1: check if they share some common lexical rule; 
		 		  	  value=0;
				  	  for(i=0;i<getLexNum();i++)
				 	 	for(j=0;j<right.m_nLexNum;j++)
				  			{ if(*(getpLexRule(i)->getpMeanUtter())==*(right.m_ppLexRule[j]->getpMeanUtter()))	
								value=1;
				  			}				  	
			  	  	  /*
		 		  	  // method 2: no need to share common lexical rules;
		 		  	  value=1;
		 		  	  */
	  	  	  		}
	  	  	  	}
			}
	  	}
	return value;
}

void CCat::InitCat(int numLex, int numSyn)
{ // initialization function;
	assert((0<=numLex)&&(numLex<=overallpara.p_nMaxLexNum)&&(0<=numSyn)&&(numSyn<=overallpara.p_nMaxSynNum));
	int i;
	setMaxLexNum(overallpara.p_nMaxLexNum); setMaxSynNum(overallpara.p_nMaxSynNum);
	setThemRole(-1);
	m_nLexNum=numLex;
	if(getLexNum()==0) m_ppLexRule=NULL;
	else
		{ m_ppLexRule=new CLexRule * [getLexNum()]; assert(m_ppLexRule!=NULL);
		  for(i=0;i<getLexNum();i++) 
		  	m_ppLexRule[i]=NULL;
		}
	m_nSynNum=numSyn;
	if(getSynNum()==0) m_ppSynRule=NULL;
	else
		{ m_ppSynRule=new CSynRule * [getSynNum()]; assert(m_ppSynRule!=NULL);
	 	  for(i=0;i<getSynNum();i++) 
	 	  	m_ppSynRule[i]=NULL;
		}
}

void CCat::DestCat()
{ // destroy function; notify lexical rules in lexlist and syntactic rules in synlist, update their cat list's pointers by pointing to NULL;
	EmpLexRule(); setMaxLexNum(0);
	setThemRole(-1);
	EmpSynRule(); setMaxSynNum(0);
}

// other operations;
void CCat::updCat(int type)
{ // update category; 2 conditions;
  // type=1, LexRule[i]=NULL: update m_nLexNum; if m_nLexNum=0, update all SynRule[i]'s category, let m_nThemRole=-1; 
  // type=2, SynRule[i]=NULL: update m_nSynNum; if m_nSynNum=0, update all LexRule[i]'s category, let m_nThemRole=-1;
  	assert((type==1)||(type==2));
	int i, j, newlexnum, newsynnum;
	CLexRule **lexruletemp=NULL;
  	CSynRule **synruletemp=NULL;
  	  	
  	switch(type)
  		{ case 1: // type=1, LexRule[i]=NULL: update m_nLexNum; if m_nLexNum=0, update all SynRule[i]'s category, let m_nThemRole=-1; 
  				if(getLexNum()!=0)
					{ newlexnum=getLexNum(); 
					  for(i=0;i<getLexNum();i++)
						{ if((getpLexRule(i)==NULL)||((getpLexRule(i)!=NULL)&&(getpLexRule(i)->getpMeanUtter()==NULL))) 
							newlexnum--;
						}
					  if((newlexnum!=getLexNum())&&(newlexnum!=0))
					  	{ // create new LexRule;
						  lexruletemp=new CLexRule * [newlexnum]; assert(lexruletemp!=NULL);
						  for(i=0;i<newlexnum;i++)
						  	lexruletemp[i]=NULL;
					  	  i=0;
					  	  for(j=0;j<getLexNum();j++)
					  	  	{ if((getpLexRule(j)!=NULL)&&(getpLexRule(j)->getpMeanUtter()!=NULL))
					  	  		{ lexruletemp[i]=getpLexRule(j); i++;
					  	  		}
					  	  	}
					  	  // delete original LexRule;
					  	  delete [] m_ppLexRule; m_ppLexRule=NULL;
					  	  m_nLexNum=0;
					  	  // copy lexruletemp to m_ppLexRule;
					  	  m_nLexNum=newlexnum; m_ppLexRule=lexruletemp;
					  	  lexruletemp=NULL;	// recollect lexruletemp;
					  	}
					  else if(newlexnum==0)
					  	{ // if m_nLexNum=0, update all SynRule[i]'s syntactic rule's category list, then let m_nThemRole=-1; 
					  	  delete [] m_ppLexRule; m_ppLexRule=NULL;
					  	  m_nLexNum=0;
					  	  if(getSynNum()!=0)
							{ for(i=0;i<getSynNum();i++)
								{ if((getpSynRule(i)!=NULL)&&(getpSynRule(i)->getSynTyp()!=-1))
									{ getpSynRule(i)->AdjSyn_Cat(this);
									  m_ppSynRule[i]=NULL;	// let SynRule[i]=NULL;
					  	  			}
								}
					  	  	}
					  	  delete [] m_ppSynRule; m_ppSynRule=NULL;
					  	  m_nSynNum=0;
					  	  setThemRole(-1);	// let m_nThemRole=-1;
					  	}
					}
  				break;
  		  case 2: // type=2, delete SynRule[i]=NULL, update m_nSynNum; 
  				if(getSynNum()!=0)
					{ newsynnum=getSynNum(); 
					  for(i=0;i<getSynNum();i++)
						{ if((getpSynRule(i)==NULL)||((getpSynRule(i)!=NULL)&&(getpSynRule(i)->getSynTyp()==-1))) 
							newsynnum--;
						}
					  if((newsynnum!=getSynNum())&&(newsynnum!=0))
					  	{ // create new m_pSynRule;
					  	  synruletemp=new CSynRule * [newsynnum]; assert(synruletemp!=NULL);
						  for(i=0;i<newsynnum;i++)
						  	synruletemp[i]=NULL;
					  	  i=0;
					  	  for(j=0;j<getSynNum();j++)
					  	  	{ if((getpSynRule(j)!=NULL)&&(getpSynRule(j)->getSynTyp()!=-1))
					  	  		{ synruletemp[i]=getpSynRule(j); i++;
					  	  		}
					  	  	}
					  	  // delete original SynRule;
					  	  delete [] m_ppSynRule; m_ppSynRule=NULL;
					  	  m_nSynNum=0;
					  	  // copy synruletemp to SynRule;
					  	  m_nSynNum=newsynnum; m_ppSynRule=synruletemp;
					  	  synruletemp=NULL;	// recollect synruletemp;
					  	}
					  else if(newsynnum==0)
					  	{ // if m_nSynNum=0, update all LexRule[i]'s lexical rule's category list, then let m_nThemRole=-1;
						  delete [] m_ppSynRule; m_ppSynRule=NULL;
						  m_nSynNum=0;
						  if(getLexNum()!=0)
							{ for(i=0;i<getLexNum();i++)
								{ if((getpLexRule(i)!=NULL)&&(getpLexRule(i)->getpMeanUtter()!=NULL))
									{ getpLexRule(i)->AdjLex_Cat(this);
									  m_ppLexRule[i]=NULL;	// let LexRule[i]=NULL;
									}
								}
					  	  	}
						  delete [] m_ppLexRule; m_ppLexRule=NULL;
						  m_nLexNum=0;
					  	  setThemRole(-1);	// let m_nThemRole=-1;					  
					  	}
					}
  				break;
  		  default: break;
  		}
}	

void CCat::InLex(CLexRule *lexrule, int *suc)
{ // insert lexrule into LexRule; suc indicates whether the insertion is successful or not;
	assert(lexrule!=NULL);
	CLexRule **lexrulelisttemp=NULL;
	int newlexnum;
	int i, j, lexindex;
	double assowei;
	
	if(getLexNum()==0)
		{ m_nLexNum++; 
		  m_ppLexRule=new CLexRule * [getLexNum()]; assert(m_ppLexRule!=NULL);
		  m_ppLexRule[0]=NULL; setpLexRule(0, lexrule);
		  *suc=1;	// insertion is successful;
		}
	else if(getLexNum()==getMaxLexNum())
		{ // first, check if lexrule is already in the category;
		  for(i=0;i<getLexNum();i++)
		  	{ if(*(getpLexRule(i))==*lexrule) break;	// check address;
		  	}
		  if(i==getLexNum())
		  	{ // randomly select a lexical rule with the lowest assowei to replace;
		  	  assowei=getpLexRule(0)->getAssoWeiUp();
		  	  for(i=0;i<getLexNum();i++)
		  	  	{ for(j=0;j<getpLexRule(i)->getCatNum();j++)
		  	  	  	{ if((getpLexRule(i)->getpCatList(j)->getpCat()==this)&&(FLOAT_SM_EQ(getpLexRule(i)->getpCatList(j)->getAssoWei(), assowei)))
		  	  	  		assowei=getpLexRule(i)->getpCatList(j)->getAssoWei();
		  	  		}
		  	  	}
		  	  do{ do{ lexindex=(int)(Rand0_1*getLexNum());
		  	  	  }while(lexindex==getLexNum());
				  for(j=0;j<getpLexRule(lexindex)->getCatNum();j++)
		  	  	  	{ if((getpLexRule(lexindex)->getpCatList(j)->getpCat()==this)&&(FLOAT_EQ(getpLexRule(lexindex)->getpCatList(j)->getAssoWei(), assowei)))
		  	  	  		break;
		  	  	  	}
		  	  }while(j==getpLexRule(lexindex)->getCatNum());
			  // update LexRule[lexindex]'s lexical rule;
			  getpLexRule(lexindex)->AdjLex_Cat(this);
			  setpLexRule(lexindex, lexrule);	// replace m_ppLexNum[lexindex]'s lexical rule with lexrule;
			  *suc=1;	// insertion is successful;
		  	}
		  else *suc=0;	// insertion is failed;
		}
	else
		{ // first, check if lexrule is already in the category;
		  for(i=0;i<getLexNum();i++)
		  	{ if(*(getpLexRule(i))==*lexrule) break;	// check value;
		  	}
		  if(i==getLexNum())
		  	{ // this is a new lexical rule;
			  newlexnum=getLexNum()+1;
		  	  lexrulelisttemp=new CLexRule * [newlexnum]; assert(lexrulelisttemp!=NULL);
			  for(i=0;i<newlexnum;i++)
			  	lexrulelisttemp[i]=NULL;
		  	  for(i=0;i<newlexnum-1;i++)
		  	  	lexrulelisttemp[i]=getpLexRule(i);
		  	  lexrulelisttemp[newlexnum-1]=lexrule;
		  	  // delete original LexRule;
			  delete [] m_ppLexRule; m_ppLexRule=NULL;
			  m_nLexNum=0;
			  // copy lexrulelisttemp to LexRule;
		  	  m_nLexNum=newlexnum; m_ppLexRule=lexrulelisttemp;
		  	  lexrulelisttemp=NULL;	// recollect lexrulelisttemp;
		  	  *suc=1;	// insertion is successful;
		  	}
		  else *suc=0;	// insertion is failed;
		}	
}

void CCat::InSyn(CSynRule *synrule)
{ // insert synrule into SynRule;
	assert(synrule!=NULL);
	int i, synindex;
	CSynRule **synrulelisttemp=NULL;
	int newsynnum;
	double synstr;
	
	if(getSynNum()==0)
		{ m_nSynNum++; 
		  m_ppSynRule=new CSynRule * [getSynNum()]; assert(m_ppSynRule!=NULL);
		  m_ppSynRule[0]=NULL; setpSynRule(0, synrule);
		}
	else if(getSynNum()==getMaxSynNum())
		{ // first, check if synrule is already in the category;
		  for(i=0;i<getSynNum();i++)
		  	{ if(getpSynRule(i)==synrule) break;	// here inSyn, only check address;
		  	}
		  if(i==getSynNum())
		  	{ // randomly select a syntactic rule with the lowest synstr to replace;
		  	  synstr=getpSynRule(0)->getSynRuleStrUp();
		  	  for(i=0;i<getSynNum();i++)
		  	  	{ if(((getpSynRule(i)->getpCat(0)==this)||(getpSynRule(i)->getpCat(1)==this))&&(FLOAT_SM_EQ(getpSynRule(i)->getSynStr(), synstr)))
		  	  	  	synstr=getpSynRule(i)->getSynStr();
		  	  	}
		  	  do{ synindex=(int)(Rand0_1*getSynNum());
		  	  }while((synindex==getSynNum())||(FLOAT_NE(getpSynRule(synindex)->getSynStr(), synstr)));
			  // update SynRule[synindex]'s syntactic rule;
			  getpSynRule(synindex)->AdjSyn_Cat(this);
			  setpSynRule(synindex, synrule);	// replace SynRule[synindex]'s syntactic rule with synrule;
		  	}
		}
	else
		{ // first, check if synrule is already in the category;
		  for(i=0;i<getSynNum();i++)
		  	{ if(getpSynRule(i)==synrule) break;	// here inSyn, only check address;
		  	}
		  if(i==getSynNum())
		  	{ // this is a new syntactic rule;
			  newsynnum=getSynNum()+1;
		  	  synrulelisttemp=new CSynRule * [newsynnum]; assert(synrulelisttemp!=NULL);
			  for(i=0;i<newsynnum;i++)
			  	synrulelisttemp[i]=NULL;
		  	  for(i=0;i<newsynnum-1;i++)
		  	  	synrulelisttemp[i]=getpSynRule(i);
		  	  synrulelisttemp[newsynnum-1]=synrule;
		  	  // delete original SynRule;
		  	  delete [] m_ppSynRule; m_ppSynRule=NULL;
		  	  m_nSynNum=0;
		  	  // copy synrulelisttemp to SynRule;
		  	  m_nSynNum=newsynnum; m_ppSynRule=synrulelisttemp;
		  	  synrulelisttemp=NULL;	// recollect synrulelisttemp;
		  	}
		}
}

void CCat::AdjCat_Lex(CLexRule *lexrule)
{ // empty LexRule[i]=lexrule to NULL;
	assert(lexrule!=NULL);
	int i;
	for(i=0;i<getLexNum();i++)
		{ if(getpLexRule(i)==lexrule) setpLexRule(i, NULL); }	// set LexRule[i]=NULL;
	updCat(1);	// type=1, LexRule[i]=NULL;
}

void CCat::AdjCat_Syn(CSynRule *synrule)
{ // empty SynRule[i]=synrule to NULL;
	assert(synrule!=NULL);
	int i;
	for(i=0;i<getSynNum();i++)
	  	{ if(getpSynRule(i)==synrule) setpSynRule(i, NULL); }	// set SynRule[i]=NULL;
	updCat(2);	// type=2, SynRule[i]=NULL;
}

bool CCat::judge_InLex(CLexRule *lexrule)
{ // check if lexrule in LexRuleList;
	int i;
	bool value=0;
	if(lexrule!=NULL)
		{ for(i=0;i<getLexNum();i++)
			{ if(getpLexRule(i)==lexrule) { value=1; break; }
			}
		}
	return value;
}

bool CCat::judge_InSyn(CSynRule *synrule)
{ // check if synrule in SynRuleList;
	int i;
	bool value=0;
	if(synrule!=NULL)
		{ for(i=0;i<getSynNum();i++) 
			{ if(getpSynRule(i)==synrule) { value=1; break; }
			}
		}
	return value;
}

// output part;
void CCat::recCatTyp(FILE *f)
{ // record category's type;
	assert(f!=NULL);
	switch(getThemRole())
	  	{ case 0: fprintf(f, "(H)"); break; 
	  	  case 1: fprintf(f, "(S)"); break;
	   	  case 2: fprintf(f, "(V)"); break;
	   	  case 3: fprintf(f, "(O)"); break;
	   	  case 4: fprintf(f, "(SV)"); break;
	   	  case 5: fprintf(f, "(SO)"); break;
	   	  case 6: fprintf(f, "(VO)"); break;
	   	  default: break;
	   	}
}



// CSyntaxRule's membership functions;
CSynRule::CSynRule()
{ // construction function;
	InitSynRule(0); setNumCatRelated(2);	
}

CSynRule::CSynRule(const CSynRule &init)
{ // copy construction function;
	(*this)=init;
}

CSynRule::~CSynRule()
{ // destruction function;
	DestSynRule();
}

CSynRule & CSynRule::operator = (const CSynRule &right)
{ // copy synrule;
	int i;
	if(&right!=this)
		{ // it is not self-copy; 
		  DestSynRule(); InitSynRule(right.m_nNumCatRelated);
		  // other parameters;
		  setInitBasicSynRuleStr(right.m_dInitBasicSynRuleStr); setInitSynRuleStr(right.m_dInitSynRuleStr);
		  setAdjSynRuleStrInc(right.m_dAdjSynRuleStrInc); setAdjSynRuleStrDec(right.m_dAdjSynRuleStrDec);
		  setSynRuleStrUp(right.m_dSynRuleStrUp); setSynRuleStrLow(right.m_dSynRuleStrLow);
		  setForgetRateSynRule(right.m_dForgetRateSynRule);
		  setMaxNumCatRelated(right.m_nMaxNumCatRelated);
		  setNumOrderTyp1(right.m_nNumOrderTyp1); setNumOrderTyp2(right.m_nNumOrderTyp2);
		  if(getNumCatRelated()!=0)
		  	{ for(i=0;i<getNumCatRelated();i++)
		  		setpCat(i, right.m_ppCat[i]);	// copy by address;
		  	}
		  setSynTyp(right.m_nSynTyp);
		  setSynStr(right.m_dSynStr);
		}
	return *this;
}

int CSynRule::operator == (const CSynRule &right)
{ // check whether two syntactic rules are same (normal or reverse same, with syntyp and catesemtyp); 
  	assert((getSynTyp()!=-1)&&(right.m_nSynTyp!=-1));
  	int syntyp0, syntyp1;
	CCat *cat00=NULL, *cat01=NULL, *cat10=NULL, *cat11=NULL;
	int value;
		
	if(this==&right) value=1;
	else
		{ syntyp0=getSynTyp(); syntyp1=right.m_nSynTyp;
		  cat00=getpCat(0); cat01=getpCat(1); cat10=right.m_ppCat[0]; cat11=right.m_ppCat[1];
		  if(((cat00->getThemRole()==cat10->getThemRole())&&(cat01->getThemRole()==cat11->getThemRole()))&&(syntyp0==syntyp1)) 
			{ if((*cat00==*cat10)&&(*cat01==*cat11)) value=1;	// normal same;
		  	  else value=0;	// not same;
		  	}
		  else if(((cat00->getThemRole()==cat11->getThemRole())&&(cat01->getThemRole()==cat10->getThemRole()))&&(((syntyp0==0)&&(syntyp1==1))||((syntyp0==1)&&(syntyp1==0))||((syntyp0==2)&&(syntyp1==3))||((syntyp0==3)&&(syntyp1==2)))) 
			{ if((*cat00==*cat11)&&(*cat01==*cat10)) value=2;	// reverse same;
		  	  else value=0;	// not same;
		  	}
		  else value=0; // not same;
		  cat00=NULL; cat01=NULL; cat10=NULL; cat11=NULL;	// recollect cat00, cat01, cat10, cat11;
		}
	return value;
}

void CSynRule::InitSynRule(int numCatRelated)
{ // initialization function;
	assert((0<=numCatRelated)&&(numCatRelated<=overallpara.p_nMaxNumCatRelated));
	int i;
	// other parameters;
	setInitBasicSynRuleStr(overallpara.p_dInitBasicSynRuleStr); setInitSynRuleStr(overallpara.p_dInitSynRuleStr);
	setAdjSynRuleStrInc(overallpara.p_dAdjSynRuleStrInc); setAdjSynRuleStrDec(overallpara.p_dAdjSynRuleStrDec);
	setSynRuleStrUp(overallpara.p_dSynRuleStrUp); setSynRuleStrLow(overallpara.p_dSynRuleStrLow);
	setForgetRateSynRule(overallpara.p_dForgetRateSynRule);
	// category part;
	setMaxNumCatRelated(overallpara.p_nMaxNumCatRelated);
	setNumOrderTyp1(overallpara.p_nNumOrderTyp1); setNumOrderTyp2(overallpara.p_nNumOrderTyp2);
	m_nNumCatRelated=numCatRelated;
	if(getNumCatRelated()==0) m_ppCat=NULL;
	else 
		{ m_ppCat=new CCat * [getNumCatRelated()]; assert(m_ppCat!=NULL);
		  for(i=0;i<getNumCatRelated();i++) 
		  	m_ppCat[i]=NULL;	// copy by address;
		}
	setSynTyp(-1); setSynStr(0.0);
}	

void CSynRule::DestSynRule()
{ // destroy function; notify cat list which pointing to this syntactic rule;
	// category part;
	EmpCat();
	setMaxNumCatRelated(0);
	setNumOrderTyp1(0); setNumOrderTyp2(0);
	setSynTyp(-1); setSynStr(0.0);
	setInitBasicSynRuleStr(0.0); setInitSynRuleStr(0.0);
	setAdjSynRuleStrInc(0.0); setAdjSynRuleStrDec(0.0); 
	setSynRuleStrUp(0.0); setSynRuleStrLow(0.0);
	setForgetRateSynRule(0.0);
}

// other operations; 
void CSynRule::updSynRule(int type)
{ // update syntactic rule; 2 conditions;
  // type=1, m_dSynStr<=m_dSynStrLow: update Cat's categories, let all Cat[i]=NULL; delete Cat and let m_nSynTyp=-1;
  // type=2, Cat[i]=NULL: update the other's categories, let all Cat[i]=NULL; delete Cat and let m_nSynTyp=-1;
  	assert((type==1)||(type==2));
	int i;
  	
  	switch(type)
  		{ case 1: // type=1, m_dSynStr<=m_dSynStrLow: update Cat's categories, let all Cat[i]=NULL; delete Cat and let m_nSynTyp=-1;
				for(i=0;i<getNumCatRelated();i++)
					{ if((getpCat(i)!=NULL)&&(getpCat(i)->getThemRole()!=-1))
						{ // update Cat's categories
						  getpCat(i)->AdjCat_Syn(this);
						  m_ppCat[i]=NULL;	// let Cat[i]=NULL;
						}
					}
				delete [] m_ppCat; m_ppCat=NULL;
				m_nNumCatRelated=0;
				setSynTyp(-1); // let SynTyp=-1;
				break;
  		  case 2: // type=2, Cat[i]=NULL: update the other's categories, let all Cat[i]=NULL; delete Cat and let m_nSynTyp=-1;
				for(i=0;i<getNumCatRelated();i++)
					{ if((getpCat(i)!=NULL)&&(getpCat(i)->getThemRole()!=-1))
						{ getpCat(i)->AdjCat_Syn(this);
						  m_ppCat[i]=NULL;	// let Cat[i]=NULL;
						}
					}
				delete [] m_ppCat; m_ppCat=NULL;
				m_nNumCatRelated=0;
				setSynTyp(-1); // let SynTyp=-1;
				break; 		  		
  		  default: break;
  		}
}

void CSynRule::IncSynStr(double adjsynstr, int adjmode)
{ // increase m_dSynStr;
	assert((FLOAT_SM_EQ(0.0, adjsynstr))&&(FLOAT_SM_EQ(adjsynstr, 1.0))); assert((adjmode==0)||(adjmode==1));
	if(FLOAT_NE(adjsynstr, 0.0)) 
		{ if(adjmode==0) setSynStr((FLOAT_BG_EQ(getSynStr()+adjsynstr, getSynRuleStrUp()))?getSynRuleStrUp():(getSynStr()+adjsynstr));
		  else if(adjmode==1) setSynStr((FLOAT_BG_EQ(getSynStr()*(1+adjsynstr), getSynRuleStrUp()))?getSynRuleStrUp():(getSynStr()*(1+adjsynstr)));	// nonlinear increase;
		}
	else 
		{ if(adjmode==0) setSynStr((FLOAT_BG_EQ(getSynStr()+getAdjSynRuleStrInc(), getSynRuleStrUp()))?getSynRuleStrUp():(getSynStr()+getAdjSynRuleStrInc()));
		  else if(adjmode==1) setSynStr((FLOAT_BG_EQ(getSynStr()*(1+getAdjSynRuleStrInc()), getSynRuleStrUp()))?getSynRuleStrUp():(getSynStr()*(1+getAdjSynRuleStrInc())));	// nonlinear increase;
		}
}

void CSynRule::DecSynStr(double adjsynstr)
{ // decrease m_dSynStr; if m_dSynStr==m_dSynStrLow, update this syntactic rule;
	assert((FLOAT_SM_EQ(0.0, adjsynstr))&&(FLOAT_SM_EQ(adjsynstr, 1.0)));
	if(FLOAT_NE(adjsynstr, 0.0)) setSynStr((FLOAT_SM_EQ(getSynStr()-adjsynstr, getSynRuleStrLow()))?getSynRuleStrLow():(getSynStr()-adjsynstr));
	else setSynStr((FLOAT_SM_EQ(getSynStr()-getAdjSynRuleStrDec(), getSynRuleStrLow()))?getSynRuleStrLow():(getSynStr()-getAdjSynRuleStrDec()));
	if(FLOAT_SM_EQ(getSynStr(), getSynRuleStrLow())) updSynRule(1);	// type=1, m_dSynStr<=m_dSynStrLow;
}

void CSynRule::AdjSyn_Cat(CCat * cat)
{ // empty Cat[i]=cat to NULL;
	assert(cat!=NULL);
	int i;
	for(i=0;i<getNumCatRelated();i++)
	  	{ if(getpCat(i)==cat) setpCat(i, NULL); }	// Cat[i]=NULL;  	  		
	updSynRule(2);	// type=2, Cat[0/1]=NULL;
}

bool CSynRule::ChkSynConsist(int order, CCat *cat1, CCat *cat2)
{ // decide 1 syntactic rule's condition;
  // order=0, before; 1, after; 2, in between; 3, surround;
	assert((0<=order)&&(order<=3)); assert((cat1!=NULL)&&(cat2!=NULL));
  	bool value=0;	
	if((getpCat(0)==cat1)&&(getpCat(1)==cat2)) { if(getSynTyp()==order) value=1; }
	else if((getpCat(0)==cat2)&&(getpCat(1)==cat1))
		{ if((order==0)||(order==1)) { if(getSynTyp()==!order) value=1; }
		  else if(order==2) { if(getSynTyp()==3) value=1; }
		  else if(order==3) { if(getSynTyp()==2) value=1; }
		}
	return value;
}

void CSynRule::getMatchTyp(int *matchTyp, CCat *cat1, CCat *cat2)
{ // get the match type for newCat1, newCat2 for this syntatcic rule;
	assert((cat1!=NULL)&&(cat2!=NULL));
	if((getpCat(0)==cat1)&&(getpCat(1)==cat2)) *matchTyp=1;
	else if((getpCat(1)==cat1)&&(getpCat(0)==cat2)) *matchTyp=2;
}

void CSynRule::getReMatCat(int originaltype, int mergetype, CCat *&cat1, CCat *&cat2)
{ // rematch the category;
	assert((originaltype==1)||(originaltype==2)); assert((mergetype==0)||(mergetype==1)||(mergetype==2));
	assert((getpCat(0)!=NULL)&&(getpCat(1)!=NULL));

	if((mergetype==0)||(mergetype==1))
		{ // normal match;
		  if(originaltype==1) { cat1=getpCat(0); cat2=getpCat(1); }	// original is normal match;
		  else if(originaltype==2) { cat1=getpCat(1); cat2=getpCat(0); }	// original is reverse match;
		}
	else if(mergetype==2) 
		{ // reverse match;
		  if(originaltype==1) { cat1=getpCat(1); cat2=getpCat(0); }	// original is normal match;
		  else if(originaltype==2) { cat1=getpCat(0); cat2=getpCat(1); }	// original is reverse match;
		}
}

bool CSynRule::judge_InCat(CCat *cat)
{ // check if cat in m_ppCat;
	int i;
	bool value=0;
	if(cat!=NULL)
		{ for(i=0;i<getNumCatRelated();i++)
			{ if(getpCat(i)==cat) { value=1; break; }
			}
		}
	return value;
}

// output part;
void CSynRule::recSynTyp(FILE *f)
{ // record syntactic rules' type;
	assert(f!=NULL);
	switch(getSynTyp())
	  	{ case 0: fprintf(f, "(BEF)"); break;
	  	  case 1: fprintf(f, "(AFT)"); break;
	  	  case 2: fprintf(f, "(MID)"); break;
	  	  case 3: fprintf(f, "(SUR)"); break;
		  default: break;
	  	}
}
