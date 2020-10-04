// Mutual influence of Semantics and Syntax
// Ver.2 27 Feb 2006
// author: Gong, Tao (tgong@ee.cuhk.edu.hk), EE Dept., The Chinese University of Hong Kong, Shatin, New Territories, Hong Kong;

// CPara.h: define global parameters for the system;

// ---- Include Files;
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<io.h>
#include<iostream.h>
#include<dos.h>
#include<time.h>
#include<assert.h>
#include<windows.h>

#include"RandomNumber.h"

// Random number generator;
#define Rand0_1 ((CRandomNumber::Rand()%(MT_RAND_MAX))/(double)(MT_RAND_MAX-1))  // random number between 0 to 1;

// Global numbers for calculation;
#define _UnDef -1
#define _LineLength 500
#define _Half 0.5
#define _Third 1.0/3.0
#define _Twice 2.0
#define _PI 3.1415926
#define _DrawStarFreq 5.0
#define _FileLen 20
#define _MinDist 0.1
#define _NumFile 17

// Precision;
#define EPSILON overallpara.p_dEPLSILON
//#define EPSILON (1e-5)   // Define your own tolerance
#define FLOAT_EQ(x, v) (((x - EPSILON) < v) && ((x + EPSILON) > v))
#define FLOAT_NE(x, v) !(FLOAT_EQ(x, v))
#define FLOAT_SM(x, v) ((x + EPSILON) < v)
#define FLOAT_BG(x, v) ((x - EPSILON) > v)
#define FLOAT_SM_EQ(x, v) (FLOAT_EQ(x, v) || FLOAT_SM(x, v))
#define FLOAT_BG_EQ(x, v) (FLOAT_EQ(x, v) || FLOAT_BG(x, v))

/*
// places calling Rand0_1:
CSemSpace::RandSelpIntgMeanIndex;
CCue::CreateCue;
CMeanUtter::CrtSyl (2); Comb3Utter (6);
CBuffer::InBuffer;
CLexRule::InCat;
CCat::InLex; InSyn;
CIMMem::UpdOptionComb; Crt1SynRule_Persp; RandCrtWordPhra (6); RandCrtWord2 (24); RandCrtCatSyn (2); RandCrtCatSyn2 (16);
CLTMem::InLexRule; InCategory; InSynRule; UpdMeanUtter; CrtMeanUtter (10);
CAgent::InitAgent; SelWinIndex (2); SetCand1 (3); SetCand2 (5);
CSystem::SelInitRuleLoc; ObjLexSim;
*/

// define COverAllPara
static class COverAllPara
{ // public members;
  public:
  	unsigned int seed;	// random seed (10 integer characters);
  	char *root_direct;	// root directory; use "\\" to indicate "\", including the last "\";
  	int numRun;	// number of running under same condition;
	double p_dEPLSILON;	// running precision;
  // Paramters for CNet;
	int p_nNetTyp;	// network type; -1, default value (self-grow); 0, Random graph network; 1, Scale-free network; 2, Small world network; 3, Local world network; 4, Exponential network; 5, Cooper-Frieze network; 6, Directed scale-free network; 7, Multi-Local-World (MLW);
	int p_nBasicTyp;	// basic network type: -1, default value; 0, globally paired network; 1, star network; 2, neighbor network; 3, lace network; 4, lattice; 5, wheel; 6, regular random graph; 7, directional hierarchy network; 8, random graph;
	int p_nDirected;	// directed or not; -1, default value; 0, undirected; 1, directed;
	double p_dConWeiUp;	// connection weight's upper bound;
	double p_dConWeiLow;	// connection weight's lower bound;
	double p_dAdjWei;	// adjustment of connection weight;
	double p_dConWeiThres;	// connection weight's threshold;
  	// for basic network;
  	int p_nEdgePerNode;	// p_nNumAgent/10.0, No. of edges for each new node; in local world network, p_nEdgePerNode<=p_nLocalView;
	int p_nLaceR;	// in lace network;
	int p_nLattice;	// in lattice network, each agent connects his nearest and next nearest neighbors; node i connect to node i-(int)(p_nLattice/(double)(_Twice)) to i+(int)(p_nLattice/(double)(_Twice)); 
	double p_dAvgDegree;	// in random network, it is 2*p_nEdgePerNode; in Scale-free, local world, exponential network, it is (2*p_nEdgePerNode*(p_nNumAgent-N0)+2*E0)/p_nNumAgent; N0, initial nodes; E0, already set connections among N0 nodes; 
	// for Scale-free, Small world, Local world network;
	int p_nLocalView;	// local view of each new agent; in exponential network, p_nLocalView==p_nEdgePerNode;
	double p_dReWire;	// prob to rewire one connection;
	double p_dAddWireProb;	// prob of adding new edges in building up Small Word network;
	double p_dRandomProb;	// random network, prob for adding an edge;
	// for Copper-Frieze network;
	int p_nNumAddEdge;	// No. of edges that one time step can add at most, uniformly distributed; 
	double p_dAlfaCF;	// prob of OLD process for generating new edge; 1-p_dAlfa, probability of NEW process for adding new vertex;
	double p_dBetaCF;	// In NEW process, prob that choices of terminal vertices are made uniformly; 1-p_dBeta, prob that choices of terminal vertices are made according to degree;
	double p_dGamaCF;	// In OLD process, prob that choices of terminal vertices are made uniformly; 1-p_dGama, prob that choices of terminal vertices are made according to degree;
	double p_dSetaCF;	// In OLD process, prob that the initial node is selected uniformly; 1-p_dSeta, prob that the initial node is selected according to degree;
	// for Directed scale-free network; 3 actions; 
	int p_nDegMode;	// for directed network, -1, record all degrees; 0, record out-degrees; 1, record in-degrees;
	double p_dSetaIN;	// in-degree constant;
	double p_dSetaOUT;	// out-degree constant;
	double p_dAlfaDS;	// prob that add a new vertex v together with an edge from v to an existing vertex w, where w is chosen according to din+p_dSetaIn;
	double p_dBetaDS;	// p_dAlfaDS+0.3, prob that add an edge from an existing vertex v to an existing vertex w, where v and w are chosen independently, v according to dout+p_dSetaOUT and w according to din+p_dSetaIN;
	double p_dGamaDS;	// prob that add a new vertex w and an edge from an existing vertex v to w, where v is chosen according to dout+p_dSetaOUT;
	// for Multi-Local-World (MLW); 3 actions; p_dP+p_dQ+p_dR=1.0
	double p_dAlfaMLW;	// constant to decide pow(T(i), p_dAlfaMLW); the newly created local world has more attractivity;
	int p_nM1;	// No. of new edges added in action 1;
	int p_nM2;	// No. of new edges added in action 2;
	int p_nM3;	// No. of new edges added in action 3;
	double p_dP;	// prob that a new local-world with 1 node is created. Its p_nM1 links to the existing local-worlds, decided by the prob of the existing local-worlds decided by their connctions; repeat _M1 times;
	double p_dQ;	// prob that a new node is added to an existing local-world, which has p_nM2 links with the nodes within the same local-world. The prob that local-world i is selected is proportional to pow(T(i), p_nAlfaMLW); repeat p_nM2 times;
	double p_dR;	// prob that a total of p_nM3 links are added to the network: first, a local-world and a node in this local-world are randomly selected; another node is randomly selected for each link with the prob decided by its degrees; repeat p_nM3 times; 

  // Parameters for CPara;
	int p_nCode;	// 2: using binary code to encode semantic item and semantic roles;
	int p_nNumSemRole;	// 4 types of semantic roles: Agent, Predicate1, Predicate2, Patient;
	int p_nNumSemAgent; int p_nNumSemPred1; int p_nNumSemPred2; int p_nNumSemPat;	// number of semantic items;
	int p_nLengthWord;	// length of utterance unit;
	int p_nAgSamePat;

  // Parameters for CSemSpace;
  	int p_nSemDist;	// semantic space's distribution; -1, initial value;
  		// 0, uniform dist; 1, identical Gaussian; 2, different Gaussian; 3, identical Power law; 4, different Power law; 5, identical random; 6, different random;
	double p_dRatioSV_SVO;	// default value: 1.0;
  	double p_dGausAvg; double p_dGausVar;
  	double p_dPowerLawA; double p_dPowerLawK;
  	
  // Parameters for CCue;
  	int p_nAtLeastOneCue;	// 1, at least one cue; 0, zero cue is possible;
  	int p_nMaxCueNum;	// maximum number of cues available in one communication;
  	int p_nWrongCueTyp;	//-1, default; 0, wrong cue is randomly selected; 1, wrong cue has no component to be identical to the correct meaning;
	double p_dDefCueStr; 
	double p_dCueReliab; double p_dCueReliabVar;	

  // Parameters for CMeanUtter;
  	int p_nNumUtterSyl;	// total number of utterance syllable;

  // Parameters for CBuffer;
  	int p_nBufTyp;	// 0, no record instance; 1, record instance; 2, record instance, when deleting, according to instance;
  	int p_nRemBuf;	// 0, no removal of fully decomposible M-U mappings; 1, removal of fully decomposible M-U mappings;
	int p_nVarBufSize;	// 0, all agents have same buffer sizes; 1, agents have heterogeneous buffer sizes;
	int p_nMaxBufSize; int p_nMaxBufSizeVar;
  
  // Parameters for CLexRule;
	// lexical rule's strength;
  	double p_dInitBasicRuleStr; double p_dInitLexRuleStr;
	double p_dAdjLexRuleStrInc; double p_dAdjLexRuleStrDec; 
	double p_dLexRuleStrUp; double p_dLexRuleStrLow;
	// lexical rule's association weight;
	double p_dInitBasicAssoWei; double p_dInitAssoWei;
	double p_dAdjAssoWeiInc; double p_dAdjAssoWeiDec; 
	double p_dAssoWeiUp; double p_dAssoWeiLow;	
	int p_nMaxCatNum;	// maximum number of category one lexical rule can be associated with;
	// forget rate;
	double p_dForgetRateLexRule;	double p_dForgetRateAssoWei;
	
  // Parameters for CCat;
  	int p_nMaxLexNum; int p_nMaxSynNum;	// maximum number of lexical rules and syntactic rules one category can have;

  // Parameters for CSynRule;
    double p_dInitBasicSynRuleStr; double p_dInitSynRuleStr;
	double p_dAdjSynRuleStrInc; double p_dAdjSynRuleStrDec; 
	double p_dSynRuleStrUp; double p_dSynRuleStrLow;	// p_dLexRuleStrLow;
	double p_dForgetRateSynRule;	
	int p_nMaxNumCatRelated;	// 2: maximum number of catgeory one syntactic rule is related;
	int p_nNumOrderTyp1;	// SV, VS orders for "Predicate<Agent>" meanings;
	int p_nNumOrderTyp2;	// SVO, SOV, OSV, VSO, VOS, OVS orders for "Predicate<Agent, Patient>" meanings;

	// Parameters for CIMMem;
	int p_nChosWin; // 0, winner takes all; 1, probability; 2, random adjust and winner takes all;
	double p_dAdjCombOptionStr; // when p_nChosWin=2, adjustment of each CombOption;
	double p_dNeuLexStr; double p_dNeuAssoWei; double p_dNeuSynStr; // neutral strengths for lexical rule, associate weight and syntactic rule;
	int p_nMaxNumLexRules; int p_nMaxNumCats; int p_nMaxNumSynRules;
	int p_nVarIMMem;	// 0, all agents have same IMMem sizes; 1, agents can have heterogeneous IMMem sizes;
	int p_nMaxNumCombOption; int p_nMaxNumCombOptionVar;

  	// Parameters for CLTMem;
	int p_nProComp2_3; int p_nPerComp2_3;	// -1, default value; 0, in production/perception, select syntactic rules based on combined strength; 1, in production/perception, select syntactic rules based on whether 2 syntactic rules can get unique global order;
	int p_nChoIdentical;	// -1, default value; 0, not allow to choose repeated chosen syntactic rules; 1, allow to choose repeated chosen syntactic rules;  
	int p_nVarLTMem;	// 0, all agents have same LTMem sizes; 1, agents can have heterogeneous LTMem sizes;
  	int p_nMaxLexRule; int p_nMaxLexRuleVar; 
  	int p_nMaxCat; int p_nMaxCatVar;
	int p_nMaxSynRule; int p_nMaxSynRuleVar;	// maximum size and variance of for lexical rule list, category list and syntactic rule list;
	int p_nMaxRecPat;	// maximum number of recurrent patterns detected in one recurrent pattern dectection;
	int p_nDecHolistPhrase;	// 0, according to category and syntactic rules; 1, random combine;
	
  // Parameters for CAgent;
	double p_dChildAdultAbiRatio;	// children and adult's learnability and creativity's ratio;
	int p_nVarCrtDec;	// 0, all agents have same creation and detection rates; 1, agents can have heterogeneous creation and detection rates;
	int p_nOnlyHolist;	// 0, allow agents to create compositional rules; 1, allow agents only create holistic rules;
	double p_dRandCrtRateWord; double p_dRandCrtRateWordVar; 
	double p_dRandCrtRatePhrase; double p_dRandCrtRatePhraseVar;
	double p_dRandCrtRateHolist; double p_dRandCrtRateHolistVar;
  	double p_dDetRecPatRate; double p_dDetRecPatRateVar;
	int p_nNoDetRecPatExm;	// 2, default value; number of M-U mappings which share the recurrent pattern to allow detecting this recurrent pattern;
	int p_nNoAcqCatSynExm;	// 2, default value; number of M-U mappings which share same use of lexical rules to allow building categories and syntactic rules; 
	double p_dDetLocOrdRate; double p_dDetLocOrdRateVar;
	int p_nFeedbackTyp;	// 0, hardfeedback; 1, softfeedback;
	double p_dSlope; double p_dHardFeedback;
	int p_nHandleFailedTyp; 
	int p_nAvoidLexFlag; int p_nAvoidSynFlag;
	int p_nHandleBuf;	// handle buffer; 0, acqlexcat after each communication; 1, acqlexcat when the buffer is full;
	int p_nAdjMode;	// -1, default value; 0, linear; 1, nonlinear;
	int p_nTakePersp;	// whether take perspective or not; -1, default; 0, no take; 1, take specific; 2, random take;
	int p_nPerspective;	// perspective influencing the local order rule creation; -1, default; 
		// 0, accusative-nominative, agent-perspective; OV orders are difference from SV orders;
		// 1, ergative-absolutive, patient-perspective; OV orders are same as SV orders;
	int p_nForget;	// 0, no forgetting; 1, forgetting;
	int p_nPredCase;	// 0, merge Pred1 and Pred2; 1, do not merge Pred1 and Pred2;
	
  // Parameters for CSystem;
	int p_nNumAgent;
	int p_nCheckFre;
	int p_nDecFlag; int p_nSelfTalkFlag;
	int p_nRecLocOrdNo_Str;	// whether record local order's number used (0) or strength (1);
	
	int p_nComMode;	// 0, randomcom; 1, paircom; 2, teach-learn; 3, popagent; 4, 2D world; 5, SolCom; 6, GA RandCom; 7, MemLang RandCom; 8, Lang-JA&LTM coevolution;
	int p_nNumGroup;	// 1, one group; 2, two groups;

	int p_nG1HolComp;	// -1, default value; 0, holistic; 1, compo, local orders by p_nG1order; 2, compo, local orders by p_nG1SV/p_nG1VS/p_nG1VO/p_nG1OV/p_nG1SO/p_nG1OS; 
	int p_nG1CompTyp;	// -1, default value; 0, random create compositional rules' utterance, allow homonyms; 1, do not allow homonyms; 2, use identical meaning as utterance syllable; 
	int p_nG1InitCompCat;	// -1, default value; 0, predicate category covers all predicates; 1, there are 2 predicate categories;
	int p_nG1order1;	// if((p_nG1HolComp==1)&&(p_nG1InitCompCat==1)) group1's "Pred<Ag>" meanings local order; 0, default value; 1, SV; 2, VS;
	int p_nG1order2;	// if((p_nG1HolComp==1)&&(p_nG1InitCompCat==0/1)) group1's "Pred<Ag, Pat>" meanings local order; 0, default value; 1, SVO; 2, SOV; 3, OSV; 4, VSO; 5, VOS; 6, OVS;
	int p_nG1SV1;	// if((p_nG1HolComp==2)&&(p_nG1InitCompCat==1)) 0, no SV local order; 1, SV local order for "Pred<Ag>" meanings;
	int p_nG1VS1;	// if((p_nG1HolComp==2)&&(p_nG1InitCompCat==1)) 0, no VS local order; 1, VS local order for "Pred<Ag>" meanings;
	int p_nG1SV;	// 0, no SV local order; 1, SV local order;
	int p_nG1VS;	// 0, no VS local order; 1, VS local order; 
	int p_nG1VO;	// 0, no VO local order; 1, VO local order; 
	int p_nG1OV;	// 0, no OV local order; 1, OV local order; 
	int p_nG1SO;	// 0, no SO local order; 1, SO local order; 
	int p_nG1OS;	// 0, no OS local order; 1, OS local order;

	double p_dG1LexNhomrate;
	double p_dG1LexVhomrate;
	double p_dG1LexNVhomrate;

	int p_nG2HolComp;	// -1, default value; 0, holistic; 1, compo, local orders by p_nG2order; 2, compo, local orders by p_nG2SV/p_nG2VS/p_nG2VO/p_nG2OV/p_nG2SO/p_nG2OS; 
	int p_nG2CompTyp;	// -1, default value; 0, random create compositional rules' utterance, allow homonyms; 1, do not allow homonyms; 2, use identical meaning as utterance syllable; 
	int p_nG2InitCompCat;	// -1, default value; 0 predicate category covers all predicates; 1, there are 2 predicate categories;
	int p_nG2order1;	// if((p_nG2HolComp==1)&&(p_nG2InitCompCat==1)) group2's "Pred<Ag>" meanings local order; 0, default value; 1, SV; 2, VS;
	int p_nG2order2;	// if((p_nG2HolComp==1)&&(p_nG2InitCompCat==0/1)) group2's "Pred<Ag, Pat>" meanings local order; 0, default value; 1, SVO; 2, SOV; 3, OSV; 4, VSO; 5, VOS; 6, OVS;
	int p_nG2SV1;	// if((p_nG2HolComp==2)&&(p_nG2InitCompCat==1)) 0, no SV local order; 1, SV local order for "Pred<Ag>" meanings;
	int p_nG2VS1;	// if((p_nG2HolComp==2)&&(p_nG2InitCompCat==1)) 0, no VS local order; 1, VS local order for "Pred<Ag>" meanings;
	int p_nG2SV;	// 0, no SV local order; 1, SV local order; 
	int p_nG2VS;	// 0, no VS local order; 1, VS local order; 
	int p_nG2VO;	// 0, no VO local order; 1, VO local order; 
	int p_nG2OV;	// 0, no OV local order; 1, OV local order; 
	int p_nG2SO;	// 0, no SO local order; 1, SO local order; 
	int p_nG2OS;	// 0, no OS local order; 1, OS local order; 

	double p_dG2LexNhomrate;
	double p_dG2LexVhomrate;
	double p_dG2LexNVhomrate;

	double p_dLexSim;	// for 2 groups, lexical rules similarity, for syntactic rules, use G1order, G2order to adjust;
	
	int p_nHorObliMix;	// 1 group: 0, horizontal transmission only; 1, oblique transmission only; 2, mixed horizontal and oblique transmission;
	int p_nMixHorVer;	// 0, no mix horizontal and vertical transmissions; 1, mixed horizontal and vertical transmissions;
	int p_nNumAgentRep;	// number of agents replaced every generation;

	int p_nCalTransMethod;	// -1, default value; 0, calculate using p_dAdultChildRatio, p_dChildChildRation, p_dChildAdultRatio, and p_dVerProb; 1, calculate using p_dPCRatio, p_dACRatio, p_dCCRatio, and p_dCARatio; 2, calculate using p_dGrandChildRatio, p_dParentChildRatio, and p_dChildChildRatio;

	double p_dAdultChildRatio;	// probability for adult-child communication;
	double p_dChildChildRatio;	// probability for child-child communication;
	double p_dChildAdultRatio;	// probability for child-adult communication; p_dAdultChildRatio+p_dChildChildRatio+p_dChildAdultRatio=1.0;
	double p_dVerProb;	// probability for bio-parent teaches to the newAgent;

	double p_dPCRatio;	// probability for bioparent-child communication;
	double p_dACRatio;	// probability for nonbioparent-child communication;
	double p_dCCRatio;	// probability for child-child communication;
	double p_dCARatio;	// probability for child-adult communication; p_dPCRatio+p_dACRatio+p_dCCRatio+p_dCARatio=1.0;

	double p_dGrandCRatio;	// probability for grandparent-child communication;
	double p_dParentCRatio;	// probability for parent-child communication;
	double p_dChildCRatio;	// probability for child-child communication; p_dGrandCRatio+p_dParentCRatio+p_dChildCRatio=1.0;
	int p_nGrandCType;	// 0, grandparents only talk to direct grandoffspring; 1, grandparents talk to any grandchildren;
	int p_nParentCType;	// 0, parents only talk to direct offspring; 1, parents talk to any children;

	int p_nVerTranRandCrt;	// in vertical transmission, allow speaker to random create;
	int p_nVerTranWrongCue;	// in vertical transmission, allow listener to select wrong cue;
	int p_nDifAdultChild;	// 0, no difference; 1, child and adult have different level of linguistic abilities;
	double p_dDifRatio;	// 1.0, no difference; the ratio between adult's ability and children's ability;
	int p_nSpUpd;	// 0, in oblique or vertical transmissions, speakers do not update their languages; 1, speakers occasionally update their languages;
	double p_dSpUpdProb;	// in oblique or vertical transmissions, the probability for speakers update their languages;

	int p_nNumGen; int p_nNumLearn;

	int p_nHumanChimp;	// 0, human society; 1, chimpanzee society with linear value of popularity; 2, chimpanzee society with scale value of popularity; 3, chimpanzee society with Power-Law distributed popularity; 4, speaker and listener with different Power-Law distributions; 5, normal distribution with same mean and std of power-law distribution;
	double p_dA1;	// p_dA1*pow(x, p_dK1);
	double p_dK1;	// p_dA1*pow(x, p_dK1);
	double p_dA2;	// p_dA2*pow(x, p_dK2);
	double p_dK2;	// p_dA2*pow(x, p_dK2);
	double p_dScale;	// for p_nHumanChimp=2, the scale for popularity;

	double p_dPopRat;	// for human society, for 1 group, popular rate;
	double p_dIntraRat, p_dInterRat;	// for human society, for 2 groups, intraRat and interRat;

	int p_nWorldX, p_nWorldY;	// 2D world size;
	int p_nBlockDist;	// the distance within which agents can communicate with each other;
	double p_dSucRat;	// the percentage of "successful" infochange that can bind agents together;
	int p_nSucCri;	// -1, default value; 0, using feedback to check success of communication; 1, using meaning to check success of communication;
	int p_nMoveStep;	// moving step; 0, default value;
	int p_n1toMCom;	// -1, default value; 0, normal one to one com; 1, one to many com;

	int p_nSelfGrow;	// 0, default network; 1, self-grow network based on degree; 2, self-grow network based on UR;

	int p_nGATimeScale;	// after how many communications let GA to adjust individual learning abilities;
	int p_nNumSp;	// number of speakers for children to learn from;
	int p_nCulSelType;	// cultural selection type; 0, randomly select 50% agents; 1, select best 50% agents;
	int p_nGeneSelType;	// genetic selection type; 0, setup children's reliability of cue from non-parents; 1, setup children's reliability of cue from parents; 
	double p_dLearnAbiLow;	// lower bound of CueReliab;
	double p_dLearnAbiUp;	// upper bound of CueReliab;
	double p_dMutRate;	// mutation rate;
	double p_dMutStep;	// mutation step;

	int p_nMemMutStep;	// mutation step for memory capacity; other parameters used: p_nGATimeScale, p_nCulSelType, p_nGeneSelType, p_dMutRate; also change p_nVarLTMem to 1 and adjust p_nMaxLexRuleVar, p_nMaxSynRuleVar, and p_nMaxCatVar;
	int p_nMemMutType;	// -1, default value; 0, no mutation; 1, IMMem mutation, adjust p_nMaxNumCombOption; 2, LTMem mutation, adjust p_nMaxLexRule, p_nMaxCat, and p_nMaxSynRule; 3, Buffer mutation, adjust p_nMaxBufSize; 4, LexRule mutation, adjust p_nMaxLexRule; 5, Cat mutation, adjust p_nMaxCat; 6, SynRule mutation, adjust p_nMaxSynRule; 7, multi-evolution, Buffer+ILMem+LTMem(LexRule);
	
	int p_nNumCom;
	int p_nNumInfoChange;

	int p_nCalAmbiguity;	// whether calculate ambiguity;
	int p_nRecMem;	// whether record memory capacity;

	int p_nShowComInfo;	// 0, do not show communication information (speaker or listener); 1, show such information;

	int p_nIndURCalMethod;	// method to calculate individual UR; 0, individual as listener; 1, individual as speaker;
	int p_nRecIndInfo;	// whether record each agent's lexical rules, syntactic rules and syntactic categories;
	int p_nRecURiniser;	// whether record URini and URser;

  // public membership functions;	
  public:
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	void GetUnsignedIntPara(FILE *ParaFile, unsigned int *para);	// get unsigned int parameter;
	void SetUnsignedIntPara(unsigned int *para, unsigned int value);	// set unsigned int paramter;
	void GetStringPara(FILE *ParaFile, char *&s);	// get char parameter;
	void SetStringPara(char *&s);	// set char parameter;
	void GetIntPara(FILE *ParaFile, int *para);	// get integer paramter;
	void SetIntPara(int *para, int value);	// set integer paramter;
	void GetDoublePara(FILE *ParaFile, double *para);	// get double paramter;
	void SetDoublePara(double *para, double value);	// set double paramter; 
	COverAllPara();	// read text file to get the parameters;
  	~COverAllPara();	// destruction function;
}overallpara;
