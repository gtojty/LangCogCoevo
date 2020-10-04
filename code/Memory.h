// Memory.h: define CIMMem, CLTMem;


// ---- Include Files;
#include"Rule.h"



class CIMMem; class CLTMem;	// pre-declare CIMMem, CLTMem;

// ---- Define IMMem;
// define MatLexRule: pointing to matched lexical rules in perception;
class MatLexRule
{ // public members;
  public:
	CLexRule *m_pMatLexRule;	// matched lexical rule;
	int m_nTag;	// 0, not chosen; 1, chosen; -1, temporary chosen;
	int m_nMatTyp;	// type of matched lexical rule; -1: default value, 
		// 0: holistic rule for "Predicate<Agent>" or "Predicate<Agent, Patient>"; 
		// 1: word rule "Agent"; 
		// 2: word rule "Pred1"; 3: word rule "Pred2"; 
		// 4: word rule "Patient";  
		// 5: continuous phrase AgPred; 6: continuous phrase AgPat; 7: continuous phrase PredPat;
		// 8: separate phrase AgPred; 9: separate phrase AgPat; 10: separate phrase rule PredPat;
	int m_nMatNum;	// how many times this rule matching the utterance;
	int *m_pMatLocStart; 	int *m_pMatLocEnd;	// end loction;
  // public membership function:
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	MatLexRule();	// construction function;
	~MatLexRule();	// destruction function;
	void InitMatLexRule();	// initialization function;
  	void DestMatLexRule();	// destroy function;
};

// define MUmatSet: number of lexical rules, lexical rules, and their matching type;
class MUmatSet
{ // public members;
  public:
  	int m_nNumLexRule;	// number of lexical rules that match m_pMU in one set of full match;
  	CLexRule **m_ppMatLexRule;	// matched lexical rules in each set of full match;
	int m_nNumMatSynTyp;	// number of matched types;
  	int *m_pMatSynTyp;	// matched type in each set of full match;
  // public membership function;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	MUmatSet();	// construction function;
	~MUmatSet();	// destruction function;
	void InitMUmatSet();	// initialization function;
  	void DestMUmatSet();	// destroy function;
};

// define CandMU: pointing to lexical rules for M-U mappings in buffer for acquiring new categories, syntactic rules;
class CandMU
{ // public members;
  public:
	CMeanUtter *m_pMU;	// meaning-utterance mapping;
	bool m_bComp;	// whether m_pMU's all meaning items are matched by lexical rules;
  	int m_nNumMatSet;	// number of set of lexical rules that fully match m_pMU;
  	MUmatSet **m_ppMatSet;	// MatSet, including number of lexical rules, lexical rules and their matching type;
  // public membership function;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CandMU();	// construction function;
	~CandMU();	// destruction function;
	void InitCandMU();	// initialization function;
  	void DestCandMU();	// destroy function;
};

// define OptionComb: store candidate lexical rules, categories, syntactic rules for production and perception;
class OptionComb
{ // public members; 
  public:
	// general information used in production;
	int m_nMeanType; int m_nType; int m_nSubType; double m_dCombinStr;
	// related rules/categories/syntax;
	int m_nNumLexRules; CLexRule **m_ppLexRules;
	int m_nNumCats; CCat **m_ppCats;
	int m_nNumSynRules; CSynRule **m_ppSynRules;
	CMeanUtter *m_pOptMeanUtter;	// candidate meanutter for production or perception;
  // public membership functions;	
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	OptionComb();	// construction function;
	~OptionComb();	// destruction function;
	void InitOptionComb();	// initialization function;
  	void DestOptionComb();	// destroy function;
	void setOC_GenInfo(int meantype, int type, int subtype, double combStr);	// set up general information;
	void setOC_LexPart(int numLex, CLexRule *lex1, CLexRule *lex2, CLexRule *lex3);	// set up lexical rules;
  	void setOC_CatPart(int numCat, CCat *cat1, CCat *cat2, CCat *cat3);	// set up categories;
  	void setOC_SynPart(int numSyn, CSynRule *syn1, CSynRule *syn2, CSynRule *syn3);	// set up syntactic rules;
	void RemainLex(int numLex, CLexRule *lex1, CLexRule *lex2, CLexRule *lex3);	// remain lexical rules;
	void RemainCat(int numCat, CCat *cat1, CCat *cat2, CCat *cat3);	// remain category;
	void RemainSyn(int numSyn, CSynRule *syn1, CSynRule *syn2, CSynRule *syn3);	// remain syntactic rules;
};
// In production:
// m_nMeanType=1; "Predicate<Agent>" meaning;
	// m_nType=0, holist rule;
		// m_nSubType=0;
	// m_nType=1, rand holistic rule;
		// m_nSubType=0;
	// m_nType=2, 2 word rules;
		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
	// m_nType=3, 1 word + 1 rand word;
		// m_nSubType=1, word 1 + rand word 2, 1 cat, 0 syn;
		// m_nSubType=2, word 1 + rand word 2, 0 cat, 0 syn;
// m_nMeanType=2; "Predicate<Agent, Patient>" meaning;
	// m_nType=0, holist rule; 
		// m_nSubType=0;
	// m_nType=1, rand holistic rule;
		// m_nSubTyp=0;
  	// m_nType=2, 1 word + 1 phrase rules;
		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
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
  	// m_nType=4, 1 phrase + 1 rand word;
		// m_nSubType=1, 1 phrase + rand word 2, 1 cat, 0 syn;
		// m_nSubType=2, 1 phrase + rand word 2, 0 cat, 0 syn;
	// m_nType=5, 2 word + 1 rand word rules;
  		// m_nSubType=1, 2 cats, 1 syn;
		// m_nSubType=2, 2 cats, 0 syn;
		// m_nSubType=3, 1 cat(cat1), 0 syn;
		// m_nSubType=4, 1 cat(cat2), 0 syn;
		// m_nSubType=5, 0 cat, 0 syn;
	// m_nType=6, 1 word + 1 rand phrase rule;
		// m_nSubType=1, word 1 + rand phrase 2, 1 cat, 0 syn;
		// m_nSubType=2, word 1 + rand phrase 2, 0 cat, 0 syn;
// in perception:
	// m_nMeanType, m_nType, m_nSubType are not used;

class CIMMem
{ // private members;
  private:
	int m_nChosWin;	// 0, winner takes all; 1, probability; 2, random adjust and winner takes all;
	double m_dAdjCombOptionStr;	// when p_nChosWin=2, adjustment of each CombOption;
	double m_dNeuLexStr; double m_dNeuAssoWei; double m_dNeuSynStr;
	int m_nMaxNumLexRules; int m_nMaxNumCats; int m_nMaxNumSynRules;
	int m_nMaxNumCombOption;
	int m_nNumCombOption;
	OptionComb **m_ppOptionComb;
  // public functions;
  public:
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CIMMem();	// construction function;
	CIMMem(const CIMMem &init);	// copy construction function;
	~CIMMem();	// destruction function;
	CIMMem & operator = (const CIMMem &right);	// copy real-time memory;  	
  	void InitIMMem(int numcomboption, int maxnumcomboption);	// initialization function;
  	void DestIMMem();	// destroy function;
  	// inline retrieve and change private members;
	inline int getChosWin() { return m_nChosWin; };
	inline void setChosWin(int chosWin) { assert((-1<=chosWin)&&(chosWin<=2)); m_nChosWin=chosWin; };
	inline double getAdjCombOptionStr() { return m_dAdjCombOptionStr; };
	inline void setAdjCombOptionStr(double adjCombOptionStr) { assert((FLOAT_SM_EQ(0.0, adjCombOptionStr))&&(FLOAT_SM_EQ(adjCombOptionStr, 1.0))); m_dAdjCombOptionStr=adjCombOptionStr; };
	inline double getNeuLexStr() { return m_dNeuLexStr; };
	inline void setNeuLexStr(double neulexstr) { assert((FLOAT_SM_EQ(0.0, neulexstr))&&(FLOAT_SM_EQ(neulexstr, 1.0))); m_dNeuLexStr=neulexstr; };
	inline double getNeuAssoWei() { return m_dNeuAssoWei; };
	inline void setNeuAssoWei(double neuassowei) { assert((FLOAT_SM_EQ(0.0, neuassowei))&&(FLOAT_SM_EQ(neuassowei, 1.0))); m_dNeuAssoWei=neuassowei; };
	inline double getNeuSynStr() { return m_dNeuSynStr; };
	inline void setNeuSynStr(double neusynstr) { assert((FLOAT_SM_EQ(0.0, neusynstr))&&(FLOAT_SM_EQ(neusynstr, 1.0))); m_dNeuSynStr=neusynstr; };
	inline int getMaxNumLexRules() { return m_nMaxNumLexRules; };
	inline void setMaxNumLexRules(int maxnumlexrules) { assert(maxnumlexrules>=0); m_nMaxNumLexRules=maxnumlexrules; };
	inline int getMaxNumCats() { return m_nMaxNumCats; };
	inline void setMaxNumCats(int maxnumcats) { assert(maxnumcats>=0); m_nMaxNumCats=maxnumcats; };
	inline int getMaxNumSynRules() { return m_nMaxNumSynRules; };
	inline void setMaxNumSynRules(int maxnumsynrules) { assert(maxnumsynrules>=0); m_nMaxNumSynRules=maxnumsynrules; };
	inline int getMaxNumCombOption() { return m_nMaxNumCombOption; };
  	inline void setMaxNumCombOption(int maxnumcomboption) { assert(maxnumcomboption>=0); m_nMaxNumCombOption=maxnumcomboption; };
  	inline int getNumCombOption() { return m_nNumCombOption; };
  	inline void setNumCombOption(int numcomboption)
  		{ assert((0<=numcomboption)&&(numcomboption<=getMaxNumCombOption())); 
		  int i;
		  EmpOptionComb();
		  m_nNumCombOption=numcomboption;
		  if(getNumCombOption()==0) m_ppOptionComb=NULL;
		  else
		  	{ m_ppOptionComb=new OptionComb * [getNumCombOption()]; assert(m_ppOptionComb!=NULL);
		  	  for(i=0;i<getNumCombOption();i++) 
		  	  	m_ppOptionComb[i]=NULL;
		  	}
  		};
	inline OptionComb * getpOptionComb(int i) { assert((0<=i)&&(i<getNumCombOption())); return m_ppOptionComb[i]; };
  	inline void setpOptionComb(int i, OptionComb *optioncomb) { assert((0<=i)&&(i<getNumCombOption())); m_ppOptionComb[i]=optioncomb; };
	inline void EmpOptionComb()
		{ int i; 
		  if(getNumCombOption()==0) m_ppOptionComb=NULL;
		  else 
			{ for(i=0;i<getNumCombOption();i++)
				{ delete m_ppOptionComb[i]; m_ppOptionComb[i]=NULL; }
			  delete [] m_ppOptionComb; m_ppOptionComb=NULL;
			  m_nNumCombOption=0;
			}		  
		};
	// other operations;
  	void UpdOptionComb(OptionComb *&optioncomb);	// update optioncomb into OptionComb;
	void InHolist(int meantype, CLexRule *newHolist, CCat *newHolistCat, CMeanUtter *meanutter);	// insert newHolist, newHolistCat to OptionComb[0];
	void CrtLexRule(CLexRule *&newLexRule, CMeanUtter *meanutter, int LexTyp);	// create compositional newLexRule;
	void CrtCat(CCat *&newCat, int themrole, CLexRule *lexRule);	// create newCat and link newCat and lexRule;
	void CrtSynRule(CSynRule *&newSynRule, CCat *cat1, CCat *cat2, int SynTyp);	// create newSynRule
	void Crt1SynRule_Persp(int perspective, CSynRule *AvaSyn, CCat *AvaSynCat1, CCat *AvaSynCat2, CSynRule *&newSynRule, CCat *cat1, CCat *cat2);	// create newSynRule; consider perspective;
	void BuildNewCat(CCat *&newCat, int CatThemRole, int CatListThemRole, CLexRule *WordPhrase);	// create newCat and adjust related catlist's themrole of WordPhrase;
	void RandCrtWordPhr_InOC(CLexRule *&newWordPhrase, CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1, CMeanUtter *meanutter);	// randomly create newWord/newPhrase, newCat1-2, newSyn1 for meanutter->m_pMean; and insert them into OptionComb[0];
	void RandCrtWord2_InOC(int perspective, CLexRule *&newWord, CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2, CMeanUtter *meanutter);	// randomly create newWord/newPhrase, newCat1-3, newSyn1, newSyn2 for meanutter->m_pMean; and insert them into OptionComb[0];
	void RandCrtCatSyn_InOC(CCat *&newCat1, CCat *&newCat2, CSynRule *&newSyn1, CMeanUtter *meanutter);	// randomly create newCat1-2, newSyn1 for meanutter->m_pMean; and insert them into OptionComb[0];
	void RandCrtCatSyn2_InOC(int perspective, CCat *&newCat1, CCat *&newCat2, CCat *&newCat3, CSynRule *&newSyn1, CSynRule *&newSyn2, CSynRule *&newSyn3, CMeanUtter *meanutter);	// randomly create newCat1-3, newSyn1-2 for meanutter->m_pMean; and insert them into OptionComb[0];
	void UseOptionCombSetUtter(CMeanUtter *meanutter);	// use rules in IMMem->OptionComb[0] to set up utterance;
	void RecIMMem(FILE * f, CSemSpace *semspace, CLTMem *LTMem);	// record IMMem in f;
};



// ---- Define CLTMem;
// define RelaCatListSyn, store related catlist and syntactic rules;
class RelaCatListSyn
{ // private members;
  private:
	int m_nProPer;	// -1, initial value; 0, production; 1, perception;
	int m_nNoCatList;	// -1, initial value; 3, 3 catlists; 2, 2 catlists;
	int m_nNoSyn;	// -1, initial value; 3, 3 syntactic rules; 2, 2 syntactic rules; 1, 1 syntactic rules;
	int m_nSubTyp;	// -1, initial value; 
		// when m_nProper=0;
			// when m_nNoCatList=3, 
				// m_nNoSyn=3, 
					// m_nSubTyp=-1;
				// m_nNoSyn=2, 
					// m_nSubTyp=0, SV+VO; 1, SV+OV; 2, VS+VO; 3, VS+OV;
  			  		//    		   4, SV+SO; 5, SV+OS; 6, VS+SO; 7, VS+OS;
  					//		    	   8, VO+SO; 9, VO+OS; 10, OV+SO; 11, OV+OS;
  					// 0, 3, 5, 6, 9, 10: unique global word order;
  					// 1, 2, 4, 7, 8, 11: multiple global word order;
  				// m_nNoSyn=1, 
  					// m_nSubTyp=1, syn12; 2, syn23; 3, syn13;
  			// when m_nNoCatList=2,
  				// m_nNoSyn=1, 
					// m_nSubTyp=-1; word + phrase; 
  		// when m_nProper=1;
  			// when m_nNoCatList=3,
  				// m_nNoSyn=3,
  					// m_nSubType=-1;
  				// m_nNoSyn=2,
  					// m_nSubTyp=0, syn12, syn23, unique global order; 1, syn12, syn23, multiple global order;
  					//		    	   2, syn12, syn13, unique global order; 3, syn12, syn23, multiple global order;
  					//			   4, syn23, syn13, unique global order; 5, syn23, syn13, multiple global order;
				// m_nNoSyn=1,
					// m_nSubTyp=1, syn12 (or S+VO/OV); 2, syn23 (or V+SO/OS); 3, syn13 (or O+SV/VS);
			// when m_nNoCatList=2,
				// m_nNoSyn=1,
					// m_nSubTyp=-1; word + phrase; 1, syn12; 2, syn23; 3, syn13;
	double m_dCombStr;	// combined strength;
	CatList *m_pCatList1, *m_pCatList2, *m_pCatList3;	// catlist;
	CSynRule *m_pSyn12, *m_pSyn23, *m_pSyn13;	// syntactic rules;
  // public functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	RelaCatListSyn();	// construction function;
	~RelaCatListSyn();	// destruction function;
	void InitRelaCatListSyn();	// initialization function;
  	void DestRelaCatListSyn();	// destroy function;
  	// inline retrieve and change private members;
	inline int getProPer() { return m_nProPer; };
	inline void setProPer(int proper) { assert((proper==-1)||(proper==0)||(proper==1)); m_nProPer=proper; };
	inline int getNoCatList() { return m_nNoCatList; };
	inline void setNoCatList(int noCatList) { assert((noCatList==-1)||(noCatList==3)||(noCatList==2)); m_nNoCatList=noCatList; };
	inline int getNoSyn() { return m_nNoSyn; };
	inline void setNoSyn(int noSyn) { assert((noSyn==-1)||(noSyn==3)||(noSyn==2)||(noSyn==1)); m_nNoSyn=noSyn; };
	inline int getSubTyp() { return m_nSubTyp; };
	inline void setSubTyp(int subtyp) { assert((-1<=subtyp)&&(subtyp<=11)); m_nSubTyp=subtyp; };
	inline double getCombStr() { return m_dCombStr; };
	inline void setCombStr(double combstr) { assert(FLOAT_BG_EQ(combstr, 0.0)); m_dCombStr=combstr; };
	inline CatList * getpCatList1() { return m_pCatList1; };
  	inline void setpCatList1(CatList *catlist1) { m_pCatList1=catlist1; };
	inline CatList * getpCatList2() { return m_pCatList2; };
  	inline void setpCatList2(CatList *catlist2) { m_pCatList2=catlist2; };
	inline CatList * getpCatList3() { return m_pCatList3; };
  	inline void setpCatList3(CatList *catlist3) { m_pCatList3=catlist3; };
	inline CSynRule * getpSyn12() { return m_pSyn12; };
  	inline void setpSyn12(CSynRule *syn12) { m_pSyn12=syn12; };
	inline CSynRule * getpSyn23() { return m_pSyn23; };
  	inline void setpSyn23(CSynRule *syn23) { m_pSyn23=syn23; };
	inline CSynRule * getpSyn13() { return m_pSyn13; };
  	inline void setpSyn13(CSynRule *syn13) { m_pSyn13=syn13; };
	void setComponent(int proper, int noCatList, int noSyn, int subtyp, double combstr, CatList *catList1, CatList *catList2, CatList *catList3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13);	// set components;
};

class CLTMem
{ // private members;
  private:
  	int m_nProComp2_3; int m_nPerComp2_3;
	int m_nChoIdentical;
	double m_dNeuLexStr; double m_dNeuAssoWei; double m_dNeuSynStr;
	int m_nMaxLexRule; int m_nMaxCat; int m_nMaxSynRule;
	int m_nMaxRecPat; 
	int m_nDecHolistPhrase;	// 0, according to category and syntactic rules; 1, random combine;
	// lexical rules, categories and syntactic rules;
	int m_nNumLexRule; CLexRule **m_ppLexRuleList;
	int m_nNumCat; CCat **m_ppCatList; 
	int m_nNumSynRule; CSynRule **m_ppSynRuleList;
  // public functions;
  public:
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CLTMem();	// construction function;
	CLTMem(const CLTMem &init);	// copy construction function;
	~CLTMem();	// destruction function;
	CLTMem & operator = (const CLTMem &right);	// copy long-term memory;  	
  	void InitLTMem(int numLex, int maxnumLex, int numCat, int maxnumCat, int numSyn, int maxnumSyn);	// initialization function;
  	void DestLTMem();	// destroy function;
  	// inline retrieve and change private members;
	inline int getProComp2_3() { return m_nProComp2_3; };
	inline void setProComp2_3(int ProComp2_3) { assert((-1<=ProComp2_3)&&(ProComp2_3<=1)); m_nProComp2_3=ProComp2_3; };
	inline int getPerComp2_3() { return m_nPerComp2_3; };
	inline void setPerComp2_3(int PerComp2_3) { assert((-1<=PerComp2_3)&&(PerComp2_3<=1)); m_nPerComp2_3=PerComp2_3; }; 
	inline int getChoIdentical() { return m_nChoIdentical; };
	inline void setChoIdentical(int ChoIdentical) { assert((-1<=ChoIdentical)&&(ChoIdentical<=1)); m_nChoIdentical=ChoIdentical; };
	inline double getNeuLexStr() { return m_dNeuLexStr; };
	inline void setNeuLexStr(double neulexstr) { assert((FLOAT_SM_EQ(0.0, neulexstr))&&(FLOAT_SM_EQ(neulexstr, 1.0))); m_dNeuLexStr=neulexstr; };
	inline double getNeuAssoWei() { return m_dNeuAssoWei; };
	inline void setNeuAssoWei(double neuassowei) { assert((FLOAT_SM_EQ(0.0, neuassowei))&&(FLOAT_SM_EQ(neuassowei, 1.0))); m_dNeuAssoWei=neuassowei; };
	inline double getNeuSynStr() { return m_dNeuSynStr; };
	inline void setNeuSynStr(double neusynstr) { assert((FLOAT_SM_EQ(0.0, neusynstr))&&(FLOAT_SM_EQ(neusynstr, 1.0))); m_dNeuSynStr=neusynstr; };
  	inline int getMaxLexRule() { return m_nMaxLexRule; };
  	inline void setMaxLexRule(int maxlexrule) { assert(maxlexrule>=0); m_nMaxLexRule=maxlexrule; };
  	inline int getMaxCat() { return m_nMaxCat; };
  	inline void setMaxCat(int maxcat) { assert(maxcat>=0); m_nMaxCat=maxcat; };
  	inline int getMaxSynRule() { return m_nMaxSynRule; };
  	inline void setMaxSynRule(int maxsynrule) { assert(maxsynrule>=0); m_nMaxSynRule=maxsynrule; };
	inline int getMaxRecPat() { return m_nMaxRecPat; };
	inline void setMaxRecPat(int maxrecpat) { assert(maxrecpat>=0); m_nMaxRecPat=maxrecpat; };
	inline int getDecHolistPhrase() { return m_nDecHolistPhrase; };
	inline void setDecHolistPhrase(int decholistphrase) { assert((-1<=decholistphrase)&&(decholistphrase<=1)); m_nDecHolistPhrase=decholistphrase; };
  	inline int getNumLexRule() { return m_nNumLexRule; };
  	inline void setNumLexRule(int numLex) 
  		{ assert((0<=numLex)&&(numLex<=getMaxLexRule())); 
		  int i;
		  EmpLexList();
  		  m_nNumLexRule=numLex; 
		  if(getNumLexRule()==0) m_ppLexRuleList=NULL;
		  else
		  	{ m_ppLexRuleList=new CLexRule * [getNumLexRule()]; assert(m_ppLexRuleList!=NULL);
		  	  for(i=0;i<getNumLexRule();i++) 
		  	  	m_ppLexRuleList[i]=NULL;
		  	}
  		};
	inline CLexRule * getpLexRuleList(int i) { assert((0<=i)&&(i<getNumLexRule())); return m_ppLexRuleList[i]; };
  	inline void setpLexRuleList(int i, CLexRule *lexrule) { assert((0<=i)&&(i<getNumLexRule())); m_ppLexRuleList[i]=lexrule; };
	inline void EmpLexList()
		{ int i; 
		  if(getNumLexRule()!=0) 
			{ for(i=0;i<getNumLexRule();i++)
				{ delete m_ppLexRuleList[i]; m_ppLexRuleList[i]=NULL; }
			  delete [] m_ppLexRuleList; m_ppLexRuleList=NULL;
			  m_nNumLexRule=0;
			}		  
		};
	inline int getNumCat() { return m_nNumCat; };
  	inline void setNumCat(int numCat) 
  		{ assert((0<=numCat)&&(numCat<=getMaxCat())); 
		  int i;
		  EmpCatList();
		  m_nNumCat=numCat;
		  if(getNumCat()==0) m_ppCatList=NULL;
		  else
		  	{ m_ppCatList=new CCat * [getNumCat()]; assert(m_ppCatList!=NULL);
		  	  for(i=0;i<getNumCat();i++) 
		  	  	m_ppCatList[i]=NULL;
		  	}
		};
	inline CCat * getpCatList(int i) { assert((0<=i)&&(i<getNumCat())); return m_ppCatList[i]; };
  	inline void setpCatList(int i, CCat *cat) { assert((0<=i)&&(i<getNumCat())); m_ppCatList[i]=cat; };
	inline void EmpCatList()
		{ int i; 
		  if(getNumCat()!=0) 
			{ for(i=0;i<getNumCat();i++)
				{ delete m_ppCatList[i]; m_ppCatList[i]=NULL; }
			  delete [] m_ppCatList; m_ppCatList=NULL;
			  m_nNumCat=0;
			}		  
		};
	inline int getNumSynRule() { return m_nNumSynRule; };
  	inline void setNumSynRule(int numSyn) 
  		{ assert((0<=numSyn)&&(numSyn<=getMaxSynRule())); 
  		  int i;
  		  EmpSynList();
  		  m_nNumSynRule=numSyn; 
  		  if(getNumSynRule()==0) m_ppSynRuleList=NULL;
  		  else
  		  	{ m_ppSynRuleList=new CSynRule * [getNumSynRule()]; assert(m_ppSynRuleList!=NULL);
  		  	  for(i=0;i<getNumSynRule();i++) 
  		  	  	m_ppSynRuleList[i]=NULL;
  		  	}
  		};
	inline CSynRule * getpSynRuleList(int i) { assert((0<=i)&&(i<getNumSynRule())); return m_ppSynRuleList[i]; };
  	inline void setpSynRuleList(int i, CSynRule *synrule) { assert((0<=i)&&(i<getNumSynRule())); m_ppSynRuleList[i]=synrule; };
	inline void EmpSynList()
		{ int i; 
		  if(getNumSynRule()!=0) 
			{ for(i=0;i<getNumSynRule();i++)
				{ delete m_ppSynRuleList[i]; m_ppSynRuleList[i]=NULL; }
			  delete [] m_ppSynRuleList; m_ppSynRuleList=NULL;
			  m_nNumSynRule=0;
			}		  
		};
  	// other operations;
  	void updLexRuleList();	// update LexRuleList, if LexRuleList[i]'s lexical rule's meanutter=NULL, delete LexRuleList[i], and update NumLexRule;
	void updCatList(); // update CatList, if CatList[i]'s category's ThemRole=-1, delete CatList[i], and update NumCat;
	void updSynRuleList();	
  	void updLTMem() { updLexRuleList(); updCatList(); updSynRuleList(); };	// update LexRuleList, CatList, SynRuleList;
	void RedIdentSynRule();	// reduce identical syntactic rules to one with the highest strength;
	// insert new lexical rule/category/syntactic rule;
	void InLexRule(CLexRule *&lexrule);	// insert lexrule into LexRuleList;
	void MergeCat(int cond, CCat *&cat);	// merge categories;
	void InCategory(CCat *&cat);	// insert cat into CatList;
	void MergeSyn(int cond, CSynRule *&synrule, int *type);	// merge syntactic rules;
	void InSynRule(CSynRule *&synrule, int *type);	// insert synrule into this->m_ppSynRuleList;
	bool chk2SideMeanUtter(int type, int subtype, CMeanUtter *MU, CLexRule *lexrule, CSemSpace *semspace);	// check MU and lexrule's meaning/utterance part match or not; type=1, production/learn category part; 2, perception part;
	int ChkSynMatCat(CSynRule *syn1, CSynRule *syn2, CCat *cat1, CCat *cat2, CCat *cat3);	// check newSyn1, newSyn2's linking type;
	void updRelaCatListSyn(RelaCatListSyn *newrelaCatListSyn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// update newrelaCatListSyn into relaCatListSyn;
	void rec2Cat1Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CSynRule *syn12, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// according to consistency to decide 2 catlist and 1 syn rules to be chosen; proper=0, production; proper=1, perception;
	void rec3Cat1Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// according to consistency to decide 3 catlist and 1 syn rules to be chosen; proper=0, production; proper=1, perception;
	void rec3Cat2Syn(int proper, int subtype, double combwei, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// according to consistency to decide 3 catlist and 2 syn rules to be chosen; proper=0, production; proper=1, perception;
	void rec3Cat3Syn(int proper, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// according to consistency to decide 3 catlist and 3 syn rules to be chosen; proper=0, production; proper=1, perception;
	void FindrelCatListSyn_Rela2Cat(RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12);	// find relaCatList with the biggest combstr; called by ChkRela2Cat
	void FindrelCatListSyn_Rela3Cat(RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn, int *SubTyp, double *combWei, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13);	// find relaCatList with the biggest combstr; called by ChkRela3Cat

	// production part;
	// random creation of rules/categories/syntax;
	void RandCrtHolist(int meantype, CLexRule *&newHolist, CCat *&newHolistCat, CMeanUtter *meanutter);	// randomly create holistic rule and holistic category for meanutter->m_pMean;
	int ChkMeanType1(int type, CMeanUtter *meanutter, CSemSpace *semspace);	// check whether meanutter ("Predicate<Agent>") can be expressed by various rules; 
	int ChkMeanType2(int type, CMeanUtter *meanutter, CSemSpace *semspace);	// check whether meanutter ("Predicate<Agent, Patient>") can be expressed by various rules; 
	void getMeanType(CMeanUtter *mean, int *meantype, CSemSpace *semspace);	// check the chosen meaning's type based on current rules;
	void updCandLexRule(CLexRule *lexrule, CLexRule **&CandLexRule, int *numCandLexRule);	// update this lexical rule into CandLexRule;
	void SearchCand1(CSemSpace *semspace, CMeanUtter *meanutter, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred);	// search candidate lexical rules for expressing Predicate<Agent> meanings: meanutter;
	void SearchCand2(CSemSpace *semspace, CMeanUtter *meanutter, CLexRule **&CandLexRule, int *numCandLexRule, int *numHolist, int *numAg, int *numPred, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat);	// search candidate lexical rules for expressing Predicate<Agent, Patient> meanings: meanutter;
	void ChkRela2CatPro(int situation, CLexRule *rule1, CLexRule *rule2, int themrole1, int themrole2, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12);	// check category relation of 2 word rules or 1 word + 1 phrase rules;
	void chk1ConsistSynPro(CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// check if there is 1 consistent syntactic rule;
	void DecCase2synTypPro(int type, int *case2synTyp, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13);	// decide case2synTyp in production;
		// case2synTyp=0, SV+VO; 1, SV+OV; 2, VS+VO; 3, VS+OV;
  		//			      4, SV+SO; 5, SV+OS; 6, VS+SO; 7, VS+OS;
  		//			      8, VO+SO; 9, VO+OS; 10, OV+SO; 11, OV+OS;
  		// 0, 3, 5, 6, 9, 10: unique global word order;
  		// 1, 2, 4, 7, 8, 11: multiple global word order;
	void chk2ConsistSynPro(int cond, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12case3syn, CSynRule *syn23case3syn, CSynRule *syn13case3syn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// check if there are 2 consistent syntactic rules; 3 cats, 2 syn;
	bool Chk3Syn(int proper, int order, int type, int synTyp12, int synTyp23, int synTyp13);	// check whether these 3 types of syntactic rules are consistent; proper=0, production; proper=1, perception;
	void chk3ConsistSyn(int proper, int type, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// check if there are 3 consistent syntactic rules; 3 cats, 3 syn; proper=0, production; 1, perception;
	void ChkRela3CatPro(CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13);	// check category relation of 3 word rules;

	// Perception part;
	bool Chk1SynPer(int order, int type, int subtype, int synTyp);	// check whether this syntactic rules is consistent;
	void ChkRela2CatPer(int type, int cond, CLexRule *rule1, CLexRule *rule2, int themrole1, int themrole2, CatList *&catlist1, CatList *&catlist2, CSynRule *&syn12);	// check category relation of 3 word rules with 2 categories;
	void DecCase2synTypPer(int cond, int type, int *case2synTyp, CatList *catlist1, CatList *catlist2, CatList *catlist3, CSynRule *syn12, CSynRule *syn23, CSynRule *syn13);	// decide case2synTyp in perception;
		// cond=1, 12/21, 23/32; 2, 12/21, 13/31; 3, 23/32, 13/31;
  		// type=3(SVO), 4(SOV), 5(OSV), 6(VSO), 7(VOS), 8(OVS);
  		// case2synTyp=0, syn12, syn23, unique global order; 1, syn12, syn23, multiple global order;
  		//			    2, syn12, syn13, unique global order; 3, syn12, syn23, multiple global order;
  		//			    4, syn23, syn13, unique global order; 5, syn23, syn13, multiple global order;
	void chk1ConsistSynPer(int type, CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// check if there is 1 consistent syntactic rule;
	bool Chk2SynPer(int order, int type, int subtype, int synTyp1, int synTyp2);	// check whether these 2 types of syntactic rules are consistent;
	void chk2ConsistSynPer(int cond, int type, CatList *rule1CatList, CatList *rule2CatList, CatList *rule3CatList, CSynRule *syn12case3syn, CSynRule *syn23case3syn, CSynRule *syn13case3syn, RelaCatListSyn **&relaCatListSyn, int *numRelaCatListSyn);	// check if there are 2 consistent syntactic rules; 3 cats, 2 syn;
	void ChkRela3CatPer(int type, CLexRule *rule1, CLexRule *rule2, CLexRule *rule3, int themrole1, int themrole2, int themrole3, CatList *&catlist1, CatList *&catlist2, CatList *&catlist3, CSynRule *&syn12, CSynRule *&syn23, CSynRule *&syn13);	// check category relation of 3 word rules;
	bool chkSynCond1(int type, CatList *catlist1, CatList *catlist2, CSynRule *syn12);	// match syntactic rule: 2 lexical rules, 1 syntactic rule;
	bool chkSynCond2(int type, CatList *catlist1, CatList *catlist2, CSynRule *syn12);	// match syntactic rule: 2 word rules, 1 syntactic rule;
	void updMatHolistRule(CLexRule *Holistrule, MatLexRule **&MatchLexRule, int *numMatchLexRule);	// update holistic rule into MatchLexRule;
	void updMatCompRule(int type, CLexRule *comprule, MatLexRule **&MatchLexRule, int *numMatchLexRule, int mattype, int nummat, int start, int end);	// update compo rule into MatchLexRule;
	void chkupdCompRule(int type, int subtype, int *numRule, CMeanUtter *MU, CLexRule *comprule, MatLexRule **&MatchLexRule, int *numMatchLexRule);	// check and upd compositional rule if they fully/partially matches the utterance;
	void GetCand(CSemSpace *semspace, CMeanUtter *meanutter, MatLexRule **&MatchLexRule, int *numMatchLexRule, int *numHolist, int *numAg, int *numPred1, int *numPred2, int *numPat, int *numAgPred, int *numAgPat, int *numPredPat);	// get candidate lexical rules which can partially match the heard utterance;

	// Synonym and Homonym avoidance;
	void AvoidSynonym(int type, CLexRule *CurLexRule, CCat *CurCat, int adjmode);	// avoid synonyms; 
	void AvoidHomonym(int type, CLexRule *CurLexRule, CCat *CurCat, int admode); // avoid homonyms;
	void AvoidSyn(int type, CSynRule *CurSynRule, int adjmode);	// avoid similar syntactic rules;
	bool Judge_InLex(CLexRule *lexrule);	// check if lexrule is in LexRuleList;
	bool Judge_InCat(CCat *cat);	// check if cat is in CatList;
	bool Judge_InSyn(CSynRule *synrule);	// check if synrule is in m_ppSynRuleList;

	// check recurrent meaning items;
	double Factorial(int n);	// calculate n!;
  	void CombinationM_N(int index, int **IndexMatrix, int IndexMatrixSize1, int IndexMatrixSize2, int oriM, int oriN, int curN, int m, int n);	// combinations of m out of n values; the indexes are stored in IndexMatrix;
	bool ChkAg(CMeanUtter **MUforComp, int sizeMUforComp);	// check Agent of multiple M-U mappings;
	bool ChkPred(CMeanUtter **MUforComp, int sizeMUforComp);	// check Predicate of multiple M-U mappings;
	bool ChkPat(CMeanUtter **MUforComp, int sizeMUforComp);	// check Patient of multiple M-U mappings;
	bool ChkAg_Pat(CMeanUtter * temp1, CMeanUtter * temp2);	// check Agent/Patient or Patient/Agent;
	int chktypeMU_Mean(int type, CMeanUtter **MUforComp, int sizeMUforComp);	// check the M-U mappings' type; type=1, check holistic meanings; 2, check phrase meanings;
	int DetRecMean(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp);	// detect recurrent pattern in meaning part of multiple M-U mappings;
	// check recurrent utterance syllables;
	void updUtterPat(CArray *&newutter, CArray **&newutterpat, int *numutterpat);	// update newutter into newutterpat;
	void setUtterLib(int type, CArray **&UtterLib, bool *&sameLoc, int *sizeUtterLib, int lenUtter, int start, int end, int lenUtterLibLow, int lenUtterLibUp, CMeanUtter *MU);	// set up UtterLib based on MU's utterance; type=1, continuous utterance; 2, separate utterance;
	void DetRecUtter(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp, int samemeantyp, CArray **&newutterpat, int *numutterpat);	// detect recurrent patterns in utterance part of multiple M-U mappings; 
	// detect recurrent patterns;
	void updMeanUtter(CMeanUtter *&newMU, CMeanUtter **&newMUpat, int *numMUpat); // update newMU into newMUpat;
	void CrtMeanUtter(double ChildAdultAbiRatio, double DetRecPatRate, int samemeantyp, CMeanUtter **MUforComp, int sizeMUforComp, CMeanUtter **&newMUpat, int *numMUpat, CArray **newutterpat, int numutterpat);	// according to samemeantyp to build up recurrent meanutter based on multiple M-U mappings;
	void AcqRecPat(CMeanUtter **MUforComp, int *typeMUforComp, int sizeMUforComp, double ChildAdultAbiRatio, double DetRecPatRate, CMeanUtter **&newMUpat, int *numMUpat);	// detect recurrent patterns in M-U mappings in MUforComp;
	void DetRecPat(int type, double ChildAdultAbiRatio, double DetRecPatRate, int NoDetRecPatExm, CBuffer *buf, CMeanUtter **&newMUpat, int *numMUpat);	// detect recurrent patterns; type=1, detect recurrent pattern after every communication; type=2, detect recurrent pattern when the buffer is full;
	int ChkCompMUTyp(CMeanUtter *MU); // check MU's type: -1: default value, only for compositional MU;
  		// 0: holistic rule for "Predicate<Agent>" or "Predicate<Agent, Patient>"; 
  		// 1: word rule "Agent/Patient"; 2: word rule "Predicate";
  		// 3: continuous phrase AgPred; 4: continueous phrase AgPat; 5: continuous phrase PredPat;
  		// 6: seperate phrase AgPred; 7: separate phrase AgPat; 8: separate phrase PredPat; 
	void InCompLexRule(CMeanUtter **&newMUpat, int *numMUpat);	// update new compositional MU mappings into lexical rule list;

	// category and syntactic rule forming based on M-U mappings in the buffer;
	void updMUmatSet(MUmatSet *&MUmatSettemp, MUmatSet **&newMUmatSet, int *numMUmatSet);	// update MUmatSettemp into newMUmatSet;
	void setupMUmatSet(int type, int order, bool *comp, CLexRule *lexrule1, CLexRule *lexrule2, CLexRule *lexrule3, MUmatSet **&newMUmatSet, int *numMUmatSet);	// set up members in MUmatSet;
	void ChoMUmatSet(CSemSpace *semspace, CMeanUtter *MU, MUmatSet **&newMUmatSet, int *numMUmatSet, bool *comp);	// select compositional lexical rules that can fully match MU's meaning part and partially match MU's utterance part;
	void FullMatPhrase(int type, CSemSpace *semspace, CMeanUtter *MU, MUmatSet **&newMUmatSet, int *numMUmatSet, bool *comp);	// select lexical rules that can fully match MU(phrase)'s meaning and utterance part;
	void updCandMU(CandMU *&candMUtemp, CandMU **&newCandMU, int *numCandMU);	// update candMUtemp into newCandMU;
	void SetCandMU(int type, CSemSpace *semspace, CMeanUtter *MU, CandMU **&newCandMU, int *numCandMU);	// set up CandMU for each M-U mapping in the buffer;
	
	// learn new category and syntactic rule;
	bool LocTarRule(int tarThemRole, CLexRule *tarLexRule, CLexRule *tarrule, CMeanUtter *MU, CSemSpace *semspace);	// decide whether tarrule matches category requirement of tarLexRule;
	bool LocRelRule(int type, double ChildAdultAbiRatio, double DetLocOrdRate, int locRel, int tarThemRole, int needThemRole, CLexRule *relrule, int matSynTyp, CMeanUtter *MU, CSemSpace *semspace);	// decide whether relrule matches the order requirement;
	void updrelLexRule(CLexRule *lexrule, CLexRule **&relLexRule, int *numrelLexRule);	// update lexrule into relLexRule; not allow repetition;
	void FindOtherRelRule(int type, double ChildAdultAbiRatio, double DetLocOrdRate, CLexRule *tarLexRule, int tarThemRole, int needThemRole, int locRel, CLexRule **&relLexRule, int *numrelLexRule, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace);	// for tarLexRule, update other related rules into relLexRule;
	void AdjrelLexRule(CLexRule *lexRule, CCat *cat, int needThemRole, CSemSpace *semspace);	// adjust lexRule's CatList->m_nThemRole; if lexRule is a Pred1 or Pred2 rule, reset lexRule's CatList->m_nThemRole;
	bool chkLexTypCons(CCat *cat, CLexRule **relLexRule, int numrelLexRule);	// check whether lexical rules in cat and lexical rules in relLexRule have common lexTyp;
	bool ChkNeedCat(int PredCase, CCat *cat, int needThemRole);	// check whether cat's lexical rules matches the needThemRole's requirement;
	bool ChkNeedLex(int PredCase, CLexRule *lexRule, int needThemRole, CSemSpace *semspace);	// check whether lexRule matches needThemRole;
	void bltCatSyn(int type, int PredCase, int locRel, CLexRule *tarLexRule, int tarThemRole, int needThemRole, CLexRule **&relLexRule, int numrelLexRule, CSemSpace *semspace);	// build up new category and syntactic rules between tarLexRule and rules in relLexRule;
	void SetRelRule(int PredCase, double ChildAdultAbiRatio, int NoAcqCatSynExm, double DetLocOrdRate, int locRel, CLexRule *lexrule1, int themrole1, CLexRule *lexrule2, int themrole2, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace);	// find related lexrules that follow same order; and set up new category, lexical rules;
	void AcqCat(int PredCase, double ChildAdultAbiRatio, int NoAcqCatSynExm, double DetLocOrdRate, CandMU **&newCandMU, int numCandMU, CSemSpace *semspace);	// use newCandMU's information to acquire new categories and syntactic rules;

	// decompose fully composible M-U mappings in the buffer;
	int TransOrderTyp(MUmatSet *matSet);	// translate matSet's m_pMatSynTyp into SVO(3), SOV(4), OSV(5), VSO(6), VOS(7), OVS(8);
	bool Chk2Syn(int order, int type, CSynRule *syn1, CSynRule *syn2, CCat *cat11, CCat *cat12, CCat *cat21, CCat *cat22);	// check consistency of 2 syntactic rules;
	bool Chk3Cat(int order, CatList *catlist1, CatList *catlist2, CatList *catlist3);	// check whether syntactic rules are consistent for three lexical rules' order requirement;
	bool CombMUtemp(CMeanUtter *MUtemp, MUmatSet *matSet);	// using matSet's rules to combine MUtemp;
	bool testComb(CandMU *candMU);	// test whether newCandMU's m_pMU can be fully decomposed;
	void updMatTypMatLex(int type, CLexRule *lex1, CLexRule *lex2, CLexRule **&MatLex, int *&MatTyp, int *numMatLex);	// update lex1, lex2 into MatLex and their type to MatTyp;
	void chkMatPhraseRule(int type, CMeanUtter *MU, CLexRule *lex1, int themRole1, CLexRule *lex2, int themRole2, int *numPair, CLexRule **&MatLex, int *&MatTyp, int *numMatLex);	// check whether lex1, lex2 can fully match phrase MU;
	bool decomHolist(CLexRule *holistrule, CSemSpace *semspace);	// try decomposing holistic rule;
	bool decomPhrase(CLexRule *phraserule, CSemSpace *semspace);	// try decomposing phrase rule;

	// check category link;
	void updCatLink(int *&newCatLink, int **&CatLink, int *numCatLink, int size);	// update newCatLink into CatLink;
	void setLinkTyp(CCat *cat, int *newCatLink, int size, int index);	// set up newCatLink[index];
	void chkCatLink(int **&CatLink, int *numCatLink, CLexRule **comLex, int numcomLex);	// check lexical rules in comLex's category relation;
	
	// output part;
	void RecLTMem(FILE *f, CSemSpace *semspace);	// record m_ppLTMem in f;
};
