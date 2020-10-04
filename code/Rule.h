// Rule.h: define CLexRule, CCat, CSynRule;

// ---- Include Files;
#include"Object.h"



class CLexRule; class CCat; class CSynRule;	// pre-declare CLexRule, CCat and CSynRule;

// ---- Define CLexRule class;
class CatList
{ // private members; 
  private:
  	CCat *m_pCat;	// category list, CatList number of categories that this lexical rule can be associated with;
  	double m_dAssoWei;	// association weights of this lexical rule towards those categories;
  	int m_nThemRole; 	// storing thematic role of each category; -1, initial value; 
		// 0, holistic meaning; 1, Ag; 2, Pred1; 3, Pred2; 4, Pat; 
		// 5, AgPred; 6, AgPat; 7, PredPat;
  // public membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CatList();	// construction function;
	~CatList();	// destruction function;
	void InitCatList();	// initialization function;
  	void DestCatList();	// destroy function;
  	// inline retrieve and change private members;
  	inline CCat * getpCat() { return m_pCat; };
  	inline void setpCat(CCat *cat) { m_pCat=cat; };
  	inline double getAssoWei() { return m_dAssoWei; };
  	inline void setAssoWei(double assowei) { assert((FLOAT_SM_EQ(0.0, assowei))&&(FLOAT_SM_EQ(assowei, 1.0))); m_dAssoWei=assowei; };
	inline int getThemRole() { return m_nThemRole; };
	inline void setThemRole(int themrole) { assert((-1<=themrole)&&(themrole<=7)); m_nThemRole=themrole; };
};

class CLexRule
{ // private members;
  private:
	// other parameters;
	double m_dInitBasicRuleStr; double m_dInitLexRuleStr; 
	double m_dAdjLexRuleStrInc; double m_dAdjLexRuleStrDec; 
	double m_dLexRuleStrUp; double m_dLexRuleStrLow;

	double m_dInitBasicAssoWei; double m_dInitAssoWei; 
	double m_dAdjAssoWeiInc; double m_dAdjAssoWeiDec; 
	double m_dAssoWeiUp; double m_dAssoWeiLow;
	double m_dForgetRateLexRule; double m_dForgetRateAssoWei;
	
	// lexical rule part; copy by value;
	CMeanUtter *m_pMeanUtter;	// meaning-utterance mapping;
	int m_nLexTyp;	// type of lexical rule; -1: default value, 
		// 0: holistic "Predicate<Agent>" or "Predicate<Agent, Patient>"; 
		// 1: Ag/Pat; 2: Pred;  
		// 3: continuous AgPred; 4: continuous AgPat; 5: continuous PredPat;
		// 6: seperate AgPred; 7: separate AgPat; 8: separate PredPat; 
	double m_dLexStr;	// lexical rule strength;
	// category part; copy by address;
	int m_nMaxCatNum;
	int m_nCatNum; CatList **m_ppCatList;
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CLexRule();	// construction function;
  	~CLexRule();	// destruction function;
  	CLexRule(const CLexRule &init);		// copy construction function;
  	CLexRule & operator = (const CLexRule &right);	// copy lexrule; meanutter by value; catlist by address;
	bool operator == (const CLexRule &);	// judge whether two lexical rules are same: m_pMeanUtter same;
	void InitLexRule(int numCat);	// initialization function;
	void DestLexRule();	// destroy function; notify catgories in catlist, update their lexical rule list's pointers by pointing to NULL;
	// inline retrieve and change private members;
	inline double getInitBasicRuleStr() { return m_dInitBasicRuleStr; };
	inline void setInitBasicRuleStr(double initbasicrulestr) { assert((FLOAT_SM_EQ(0.0, initbasicrulestr))&&(FLOAT_SM_EQ(initbasicrulestr, 1.0))); m_dInitBasicRuleStr=initbasicrulestr; };
	inline double getInitLexRuleStr() { return m_dInitLexRuleStr; };
	inline void setInitLexRuleStr(double initlexrulestr) { assert((FLOAT_SM_EQ(0.0, initlexrulestr))&&(FLOAT_SM_EQ(initlexrulestr, 1.0))); m_dInitLexRuleStr=initlexrulestr; };
	inline double getAdjLexRuleStrInc() { return m_dAdjLexRuleStrInc; };
	inline void setAdjLexRuleStrInc(double adjlexrulestrInc) { assert((FLOAT_SM_EQ(0.0, adjlexrulestrInc))&&(FLOAT_SM_EQ(adjlexrulestrInc, 1.0))); m_dAdjLexRuleStrInc=adjlexrulestrInc; };
	inline double getAdjLexRuleStrDec() { return m_dAdjLexRuleStrDec; };
	inline void setAdjLexRuleStrDec(double adjlexrulestrDec) { assert((FLOAT_SM_EQ(0.0, adjlexrulestrDec))&&(FLOAT_SM_EQ(adjlexrulestrDec, 1.0))); m_dAdjLexRuleStrDec=adjlexrulestrDec; };
	inline double getLexRuleStrUp() { return m_dLexRuleStrUp; };
	inline void setLexRuleStrUp(double lexrulestrup) { assert((FLOAT_SM_EQ(0.0, lexrulestrup))&&(FLOAT_SM_EQ(lexrulestrup, 1.0))); m_dLexRuleStrUp=lexrulestrup; };
	inline double getLexRuleStrLow() { return m_dLexRuleStrLow; };
	inline void setLexRuleStrLow(double lexrulestrlow) { assert((FLOAT_SM_EQ(0.0, lexrulestrlow))&&(FLOAT_SM_EQ(lexrulestrlow, 1.0))); m_dLexRuleStrLow=lexrulestrlow; };
	inline double getInitBasicAssoWei() { return m_dInitBasicAssoWei; };
	inline void setInitBasicAssoWei(double initbasicassowei) { assert((FLOAT_SM_EQ(0.0, initbasicassowei))&&(FLOAT_SM_EQ(initbasicassowei, 1.0))); m_dInitBasicAssoWei=initbasicassowei; }
	inline double getInitAssoWei() { return m_dInitAssoWei; };
	inline void setInitAssoWei(double initassowei) { assert((FLOAT_SM_EQ(0.0, initassowei))&&(FLOAT_SM_EQ(initassowei, 1.0))); m_dInitAssoWei=initassowei; };
	inline double getAdjAssoWeiInc() { return m_dAdjAssoWeiInc; };
	inline void setAdjAssoWeiInc(double adjassoweiInc) { assert((FLOAT_SM_EQ(0.0, adjassoweiInc))&&(FLOAT_SM_EQ(adjassoweiInc, 1.0))); m_dAdjAssoWeiInc=adjassoweiInc; };
	inline double getAdjAssoWeiDec() { return m_dAdjAssoWeiDec; };
	inline void setAdjAssoWeiDec(double adjassoweiDec) { assert((FLOAT_SM_EQ(0.0, adjassoweiDec))&&(FLOAT_SM_EQ(adjassoweiDec, 1.0))); m_dAdjAssoWeiDec=adjassoweiDec; };
	inline double getAssoWeiUp() { return m_dAssoWeiUp; };
	inline void setAssoWeiUp(double assoweiup) { assert((FLOAT_SM_EQ(0.0, assoweiup))&&(FLOAT_SM_EQ(assoweiup, 1.0))); m_dAssoWeiUp=assoweiup; };
	inline double getAssoWeiLow() { return m_dAssoWeiLow; };
	inline void setAssoWeiLow(double assoweilow) { assert((FLOAT_SM_EQ(0.0, assoweilow))&&(FLOAT_SM_EQ(assoweilow, 1.0))); m_dAssoWeiLow=assoweilow; };
	inline double getForgetRateLexRule() { return m_dForgetRateLexRule; };
	inline void setForgetRateLexRule(double forgetratelexrule) { assert((FLOAT_SM_EQ(0.0, forgetratelexrule))&&(FLOAT_SM_EQ(forgetratelexrule, 1.0))); m_dForgetRateLexRule=forgetratelexrule; };
	inline double getForgetRateAssoWei() { return m_dForgetRateAssoWei; };
	inline void setForgetRateAssoWei(double forgetrateassowei) { assert((FLOAT_SM_EQ(0.0, forgetrateassowei))&&(FLOAT_SM_EQ(forgetrateassowei, 1.0))); m_dForgetRateAssoWei=forgetrateassowei; };
	inline CMeanUtter * getpMeanUtter() { return m_pMeanUtter; };
	inline void setpMeanUtter(CMeanUtter *pMeanUtter) { *m_pMeanUtter=*pMeanUtter; };
	inline int getLexTyp() { return m_nLexTyp; };
  	inline void setLexTyp(int lextyp) { assert((-1<=lextyp)&&(lextyp<=8)); m_nLexTyp=lextyp; };
  	inline double getLexStr() { return m_dLexStr; };
  	inline void setLexStr(double lexstr) { assert((FLOAT_SM_EQ(0.0, lexstr))&&(FLOAT_SM_EQ(lexstr, 1.0))); m_dLexStr=lexstr; };
	inline int getMaxCatNum() { return m_nMaxCatNum; };
	inline void setMaxCatNum(int maxcatnum) { assert(maxcatnum>=0); m_nMaxCatNum=maxcatnum; };
	inline int getCatNum() { return m_nCatNum; };
  	inline void setCatNum(int numCat) 
  		{ assert((0<=numCat)&&(numCat<=getMaxCatNum())); 
		  int i;
		  EmpCatList();
		  m_nCatNum=numCat;
		  if(getCatNum()==0) m_ppCatList=NULL;
		  else
		  	{ m_ppCatList=new CatList * [getCatNum()]; assert(m_ppCatList!=NULL);
		  	  for(i=0;i<getCatNum();i++)
		  	  	m_ppCatList[i]=NULL;
		  	}
		};
	inline CatList * getpCatList(int i) { assert((0<=i)&&(i<getCatNum())); return m_ppCatList[i]; };
  	inline void setpCatList(int i, CCat *cat, double assowei, int themrole) 
  		{ assert((0<=i)&&(i<getCatNum())); assert((FLOAT_SM_EQ(0.0, assowei))&&(FLOAT_SM_EQ(assowei, 1.0))); assert((-1<=themrole)&&(themrole<=7));
		  if(m_ppCatList[i]==NULL) { m_ppCatList[i]=new CatList; assert(m_ppCatList[i]!=NULL); }
		  getpCatList(i)->setpCat(cat); getpCatList(i)->setAssoWei(assowei); getpCatList(i)->setThemRole(themrole);
  		};
	inline void setpCatListWhole(int i, CatList *catList) { assert((0<=i)&&(i<getCatNum())); m_ppCatList[i]=catList; };
  	inline void EmpCatList()
  		{ int i; 
  		  if(getCatNum()!=0)
  		  	{ for(i=0;i<getCatNum();i++)
  		  		{ delete m_ppCatList[i]; m_ppCatList[i]=NULL; }
  		  	  delete [] m_ppCatList; m_ppCatList=NULL;
  		  	  m_nCatNum=0;
  		  	}
  		};
  	// other operations;
	void updLexRule(int type);	// update CatList;
  		// type=1, m_dRuleStr<=m_dRuleStrLow: update CatList's categories, let all CatList[i]->m_pCat=NULL; release CatList and m_pMeanUtter; 
  		// type=2, m_dAssoWei[i]<=m_dAssoWeiLow: update CatList[i]'s category, let CatList[i]->m_pCat=NULL; delete CatList[i] and update m_nCatNum; if m_nCatNum=0, release CatList; for holistic rules, delete m_pMeanUtter; 
  		// type=3, CatList[i]->m_pCat=NULL: delete CatList[i] and update m_nCatNum; if m_nCatNum=0, release CatList; for holistic rules, delete m_pMeanUtter; 
    	void IncLexStr(double adjlexstr, int adjmode);	// increase m_dLexStr;
  	void DecLexStr(double adjlexstr);	// decrease m_dLexStr; if m_dLexStr==m_dLexRuleStrLow, update the lexical rule;
  	void IncAssoWei(int i, double adjassowei, int adjmode);	// increase CatList[i]->m_dAssoWei;
  	void DecAssoWei(int i, double adjassowei);	// decrease CatList[i]->m_pAssoWei; if CatList[i]->m_pAssoWei=m_dAssoWeiLow, update this lexical rule;
	void InCat(CCat *cat);	// insert cat into CatList;
	void AdjLex_Cat(CCat *cat);	// empty CatList[i]->m_pCat=cat to NULL;
	bool judge_InCat(CCat *cat);	// check if cat is in CatList->m_pCat;
	void FindCatListwithHighAsso(int type, int themrole, CatList *&catlist);	// find the catlist with themrole and with the highest association weight;
	// output part;
	void recLexTyp(FILE *f);	// record lexical rule's type;	
	void buildMUstr(char *MUstr, CSemSpace *semspace);	// copy M-U mapping to MUstr;
	void RecLexRule(FILE *f, CSemSpace *semspace);	// record lexical rule in f;
};



// ---- Define CCat class;
class CCat
{ // private members;
  private:
	int m_nMaxLexNum; int m_nMaxSynNum;
	int m_nThemRole;	// category's thematic type: -1, initial value; 
		// 0, holistic meaning; 1, Ag; 2, Pred; 3, Pat; 
		// 4, AgPred; 5, AgPat; 6, PredPat;
	int m_nLexNum; CLexRule **m_ppLexRule;
	int m_nSynNum; CSynRule **m_ppSynRule;
  // public membership functions;
  public:
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CCat();	// construction function;
	CCat(const CCat &init);	// copy construction function;
	~CCat();	// destruction function;
	CCat & operator = (const CCat &right);	// copy cat by address;
	bool operator == (const CCat &);	// check whether two categories are same (themrole same, towards another category, having same syntactic rule, test by address);
	void InitCat(int numLex, int numSyn);	// initialization function;
	void DestCat();	// destroy function; notify lexical rules in lexlist, update their cat list's pointers by pointing to NULL;
	// inline retrieve and change private members;
	inline int getMaxLexNum() { return m_nMaxLexNum; };
	inline void setMaxLexNum(int maxlexnum) { assert(maxlexnum>=0); m_nMaxLexNum=maxlexnum; };
	inline int getMaxSynNum() { return m_nMaxSynNum; };
	inline void setMaxSynNum(int maxsynnum) { assert(maxsynnum>=0); m_nMaxSynNum=maxsynnum; };
	inline int getThemRole() { return m_nThemRole; };
	inline void setThemRole(int themrole) { assert((-1<=themrole)&&(themrole<=6)); m_nThemRole=themrole; };
	inline int getLexNum() { return m_nLexNum; };
	inline void setLexNum(int numLex) 
		{ assert((0<=numLex)&&(numLex<=getMaxLexNum())); 
		  int i;
		  EmpLexRule();
		  m_nLexNum=numLex;
		  if(getLexNum()==0) m_ppLexRule=NULL;
		  else
		  	{ m_ppLexRule=new CLexRule * [getLexNum()]; assert(m_ppLexRule!=NULL);
		  	  for(i=0;i<getLexNum();i++) 
		  	  	m_ppLexRule[i]=NULL;
		  	}
		};
	inline CLexRule * getpLexRule(int i) { assert((0<=i)&&(i<getLexNum())); return m_ppLexRule[i]; };
	inline void setpLexRule(int i, CLexRule *lexrule) { assert((0<=i)&&(i<getLexNum())); m_ppLexRule[i]=lexrule; };
	inline void EmpLexRule()
		{ if(getLexNum()!=0) 
			{ delete [] m_ppLexRule; m_ppLexRule=NULL;
			  m_nLexNum=0;
			}		  
		};
	inline int getSynNum() { return m_nSynNum; };
	inline void setSynNum(int numSyn) 
		{ assert((0<=numSyn)&&(numSyn<=getMaxSynNum())); 
		  int i;
		  EmpSynRule();
		  m_nSynNum=numSyn; 
		  if(getSynNum()==0) m_ppSynRule=NULL;
		  else
		  	{ m_ppSynRule=new CSynRule * [getSynNum()]; assert(m_ppSynRule!=NULL);
		  	  for(i=0;i<getSynNum();i++) 
		  	  	m_ppSynRule[i]=NULL;
		  	}
		};
	inline CSynRule * getpSynRule(int i) { assert((0<=i)&&(i<getSynNum())); return m_ppSynRule[i]; };
	inline void setpSynRule(int i, CSynRule *synrule) { assert((0<=i)&&(i<getSynNum())); m_ppSynRule[i]=synrule; };
	inline void EmpSynRule()
		{ if(getSynNum()!=0) 
			{ delete [] m_ppSynRule; m_ppSynRule=NULL;
			  m_nSynNum=0;
			}		  
		};
	// other operations;
	void updCat(int type);	// update category; 2 conditions;
  		// type=1, LexRule[i]=NULL: update m_nLexNum; if m_nLexNum=0, update all SynRule[i]'s category, let m_nThemRole=-1; 
  		// type=2, SynRule[i]=NULL: update m_nSynNum; if m_nSynNum=0, update all LexRule[i]'s category, let m_nThemRole=-1;
 	void InLex(CLexRule *lexrule, int *sucInLex);	// insert lexrule into LexRule; suc indicates whether the insertion is successful;
	void InSyn(CSynRule *synrule);	// insert synrule into SynRule;
	void AdjCat_Lex(CLexRule *lexrule);	// empty LexRule[i]=lexrule to NULL;
	void AdjCat_Syn(CSynRule *synrule);	// empty SynRule[i]=synrule to NULL;
	bool judge_InLex(CLexRule *lexrule);	// check if lexrule in LexRuleList;
	bool judge_InSyn(CSynRule *synrule);	// check if synrule in SynRuleList;
	// output part;
	void recCatTyp(FILE *f);	// record category's type;
};



// ---- Define CSynRule class;
class CSynRule
{ // private members;
  private:
	// other parameters;
	double m_dInitBasicSynRuleStr; double m_dInitSynRuleStr;
	double m_dAdjSynRuleStrInc; double m_dAdjSynRuleStrDec; 
	double m_dSynRuleStrUp; double m_dSynRuleStrLow;
	double m_dForgetRateSynRule;
	int m_nMaxNumCatRelated;
	int m_nNumOrderTyp1; int m_nNumOrderTyp2;
	int m_nNumCatRelated; CCat **m_ppCat;
	// syntactic rule part;
  	int m_nSynTyp;	// syntactic rule type: -1: initial value; 
  		// 0: before; 1: after; 2, in between; 3, outer;
  	double m_dSynStr;	// syntax rule strength;  	
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CSynRule();		// construction function;
  	CSynRule(const CSynRule &init);	// copy construction function
  	~CSynRule();	// destruction function;
  	CSynRule & operator = (const CSynRule &right);	// copy synrule;
	int operator == (const CSynRule &);	// check whether two syntactic rules are same (normal or reverse same, with syntyp and catesemtyp); ; 
			// 0, not same; 1, normal same; 2, reverse same;
	void InitSynRule(int numCatRelated);	// initialization function;
	void DestSynRule();	// destroy function; no need to notify anyone;
	// inline retrieve and change private members;
	inline double getInitBasicSynRuleStr() { return m_dInitBasicSynRuleStr; };
	inline void setInitBasicSynRuleStr(double initbasicsynrulestr) { assert((FLOAT_SM_EQ(0.0, initbasicsynrulestr))&&(FLOAT_SM_EQ(initbasicsynrulestr, 1.0))); m_dInitBasicSynRuleStr=initbasicsynrulestr; };
	inline double getInitSynRuleStr() { return m_dInitSynRuleStr; };
	inline void setInitSynRuleStr(double initsynrulestr) { assert((FLOAT_SM_EQ(0.0, initsynrulestr))&&(FLOAT_SM_EQ(initsynrulestr, 1.0)));; m_dInitSynRuleStr=initsynrulestr; };
	inline double getAdjSynRuleStrInc() { return m_dAdjSynRuleStrInc; };
	inline void setAdjSynRuleStrInc(double adjsynrulestrInc) { assert((FLOAT_SM_EQ(0.0, adjsynrulestrInc))&&(FLOAT_SM_EQ(adjsynrulestrInc, 1.0))); m_dAdjSynRuleStrInc=adjsynrulestrInc; };
	inline double getAdjSynRuleStrDec() { return m_dAdjSynRuleStrDec; };
	inline void setAdjSynRuleStrDec(double adjsynrulestrDec) { assert((FLOAT_SM_EQ(0.0, adjsynrulestrDec))&&(FLOAT_SM_EQ(adjsynrulestrDec, 1.0))); m_dAdjSynRuleStrDec=adjsynrulestrDec; };
	inline double getSynRuleStrUp() { return m_dSynRuleStrUp; };
	inline void setSynRuleStrUp(double synrulestrup) { assert((FLOAT_SM_EQ(0.0, synrulestrup))&&(FLOAT_SM_EQ(synrulestrup, 1.0))); m_dSynRuleStrUp=synrulestrup; };
	inline double getSynRuleStrLow() { return m_dSynRuleStrLow; };
	inline void setSynRuleStrLow(double synrulestrlow) { assert((FLOAT_SM_EQ(0.0, synrulestrlow))&&(FLOAT_SM_EQ(synrulestrlow, 1.0))); m_dSynRuleStrLow=synrulestrlow; };
	inline double getForgetRateSynRule() { return m_dForgetRateSynRule; };
	inline void setForgetRateSynRule(double forgetratesynrule) { assert((FLOAT_SM_EQ(0.0, forgetratesynrule))&&(FLOAT_SM_EQ(forgetratesynrule, 1.0))); m_dForgetRateSynRule=forgetratesynrule; };
	inline int getMaxNumCatRelated() { return m_nMaxNumCatRelated; };
	inline void setMaxNumCatRelated(int maxnumcatrelated) { assert(maxnumcatrelated>=0); m_nMaxNumCatRelated=maxnumcatrelated; };
	inline int getNumOrderTyp1() { return m_nNumOrderTyp1; };
	inline void setNumOrderTyp1(int numordertyp1) { assert(numordertyp1>=0); m_nNumOrderTyp1=numordertyp1; };
	inline int getNumOrderTyp2() { return m_nNumOrderTyp2; };
	inline void setNumOrderTyp2(int numordertyp2) { assert(numordertyp2>=0); m_nNumOrderTyp2=numordertyp2; }; 
	inline int getNumCatRelated() { return m_nNumCatRelated; };
	inline void setNumCatRelated(int numCatRelated) 
		{ assert((numCatRelated>=0)&&(numCatRelated<=getMaxNumCatRelated())); 
		  int i;	
		  EmpCat();
		  m_nNumCatRelated=numCatRelated;
		  if(getNumCatRelated()==0) m_ppCat=NULL;
		  else
		  	{ m_ppCat=new CCat * [getNumCatRelated()]; assert(m_ppCat!=NULL);
		  	  for(i=0;i<getNumCatRelated();i++) 
		  	  	m_ppCat[i]=NULL;
		  	}
		};
	inline CCat ** getCats() { return m_ppCat; };
	inline CCat * getpCat(int i) { assert((0<=i)&&(i<getNumCatRelated())); return m_ppCat[i]; };
	inline void setpCat(int i, CCat *pCat) { assert((0<=i)&&(i<getNumCatRelated())); m_ppCat[i]=pCat; };
	inline void EmpCat()
		{ if(getNumCatRelated()!=0) 
			{ delete [] m_ppCat; m_ppCat=NULL;
			  m_nNumCatRelated=0;
			}		  
		};
	inline int getSynTyp() { return m_nSynTyp; };
	inline void setSynTyp(int syntyp) { assert((-1<=syntyp)&&(syntyp<=3)); m_nSynTyp=syntyp; };
	inline double getSynStr() { return m_dSynStr; };
	inline void setSynStr(double synstr) { assert((FLOAT_SM_EQ(0.0, synstr))&&(FLOAT_SM_EQ(synstr, 1.0))); m_dSynStr=synstr; };
	// other operations;
	void updSynRule(int type);	// update syntactic rule; 2 conditions;
		// type=1, m_dSynStr<=m_dSynStrLow: update m_ppCat's categories, let all Cat[i]=NULL; delete Cat and let m_nSynTyp=-1;
  		// type=2, Cat[i]=NULL: update the other's categories, let all Cat[i]=NULL; delete m_ppCat and let m_nSynTyp=-1;
	void IncSynStr(double adjsynstr, int adjmode);		// increase m_dSynStr;
	void DecSynStr(double adjsynstr);	// decrease m_dSynStr; if m_dSynStr==m_dSynStrLow, update this syntactic rule;
	void AdjSyn_Cat(CCat *cat);	// empty Cat[i]=cat to NULL;
	bool ChkSynConsist(int order, CCat *cat1, CCat *cat2);	// decide 1 syntactic rule's condition; order=0, before; 1, after; 2, in between; 3, surround;
	void getMatchTyp(int *matchTyp, CCat *cat1, CCat *cat2);	// get the match type for newCat1, newCat2 for this syntatcic rule;
	void getReMatCat(int originaltype, int mergetype, CCat *&cat1, CCat *&cat2);	// rematch the category;
	bool judge_InCat(CCat *cat);	// check if cat in m_ppCat;
	// output part;
	void recSynTyp(FILE *f);	// record syntactic rules' type;
};
