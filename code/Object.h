// Object.h: define CArray, CParaMeters, CBasicMean, CSemSpace, CMeanUtter, CBuffer, these classes can be basic classes;

// ---- Include Files:
#include"CPara.h"

// ---- Define CGenFuncClass;
class CGenFuncClass
{ public:
	static int comp2values_big(double x, double y)
		{ // compare two double values x and y, find the biggest; 
		  int retVal=0;
		  if(FLOAT_BG(x, y)) retVal=1;	// x is bigger;
  		  else if(FLOAT_SM(x, y)) retVal=2;	// y is bigger;
  		  else if(FLOAT_EQ(x, y)) 
  			{ if(FLOAT_SM_EQ(Rand0_1, _Half)) retVal=1;	// x is bigger;
  	  	  	  else retVal=2;	// y is bigger;
  			}
		  return retVal;
		};

	static int comp3values_big(double x, double y, double z)
		{ // compare three double value x, y and z, find the biggest; 
  		  int retVal=0;
		  double rannum;
  		  if((FLOAT_BG(x, y))&&(FLOAT_BG(x, z))) retVal=1;	// x is the biggest;
  		  else if((FLOAT_BG(y, x))&&(FLOAT_BG(y, z))) retVal=2;	// y is the biggest;
  		  else if((FLOAT_BG(z, x))&&(FLOAT_BG(z, y))) retVal=3;	// z is the biggest;
  		  else if((FLOAT_EQ(x, y))&&(FLOAT_BG(x, z))) 
  			{ // x==y and x,y>z; 
  	  	  	  if(FLOAT_SM_EQ(Rand0_1, _Half)) retVal=1;	// x is the biggest;
  	  	  	  else retVal=2;	// y is the biggest;
			}
  		  else if((FLOAT_EQ(x, z))&&(FLOAT_BG(x, y)))
 		 	{ // x==z, and x,z>y; 
  			  if(FLOAT_SM_EQ(Rand0_1, _Half)) retVal=1;	// x is the biggest;
  			  else retVal=3;	// z is the biggest;
  			}
  		  else if((FLOAT_EQ(y, z))&&(FLOAT_BG(y, x)))
  			{ // y==z, and y,z>x; 
 	 		  if(FLOAT_SM_EQ(Rand0_1, _Half)) retVal=2;	// y is the biggest;
  			  else retVal=3;	// z is the biggest;
  			}
  		  else if((FLOAT_EQ(x, y))&&(FLOAT_EQ(x, z))) 
  			{ // all equal;
  			  rannum=Rand0_1;
			  if(FLOAT_SM_EQ(rannum, _Third)) retVal=1;	// x is the biggest;
			  else if((FLOAT_BG(rannum, _Third))&&(FLOAT_SM_EQ(rannum, 2*_Third))) retVal=2;	// y is the biggest;
			  else retVal=3;	// z is the biggest;
			}
		  return retVal;
		};
};

// ---- Define CArray;
class CArray
{ // private members; the length of array; the member of array;
  private:
  	int m_nLengthArray;	// array size; 
  	int *m_pArray;	// array member; copy by value!
  // membership functions;
  public:
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CArray();	// default construction function;
  	CArray(int lengtharray);		// construction function;
	CArray(const CArray &init);	// copy construction function;
  	~CArray();	// destruction function;
  	CArray & operator = (const CArray &right);	// copy array by value;
  	int &operator [] (int subscript);	// [] operator; get array subscript; only to be left operand!
	bool operator == (const CArray &);	// compare whether two arrays are same (1) or not (0);
	bool operator != (const CArray &);	// compare whether two arrays are not same (1) or same (0);
	void InitArray(int lengthArray);	// initialization function;
	void DestArray();	// destruction function;
	// inline retrieve and change private members;
  	inline void EmptypArray() 
		{ // empty m_pArray;
			int i; 
  		  	for(i=0;i<getLengthArray();i++) 
  			  	setElement(i, -1); 
		};	
	inline int getLengthArray() { return m_nLengthArray; };
  	inline void setLengthArray(int lengthArray) { assert(lengthArray>=0); m_nLengthArray=lengthArray; };
	inline int * getpArray() { return m_pArray; };
	inline void setpArray(int * parray) { *m_pArray=*parray; };
	inline int getElement(int i) { assert((0<=i)&&(i<getLengthArray())); return m_pArray[i]; };
	inline void setElement(int i, int element) { assert((0<=i)&&(i<getLengthArray())&&(element>=-1)); m_pArray[i]=element; };
  	// other operations;
	void setPartArray(CArray *parray, int start, int loc, int num);	// copy parray[loc]'s num elements into m_pArray[start];
	bool containArray(int type, int len, int start, int end, CArray *conArray);	// check if m_pArray include conArray;
	void maskArray(int len, CArray *mkArray);	// mask the same syllable in both sides as in mkArray with -1;
	void OutputArray();	// output CArray;
};



// ---- Define CNet;
class CNet
{ // private members;
  private:
	int m_nNetTyp;	// network type; -1, default value; 0, Random graph network; 1, Scale-free network; 2, Small world network; 3, Local world network; 4, Exponential network; 5, Cooper-Frieze network; 6, Directed scale-free network; 7, Multi-Local-World (MLW);
	int m_nBasicTyp;	// basic network type: -1, default value; 0, globally paired network; 1, star network; 2, neighbor network; 3, lace network; 4, lattice; 5, wheel; 6, regular random graph; 7, directional hierarchy network; 8, random graph;
	int m_nDirected;	// directed or not; -1, default value;
	
	int m_nSize;	// network size; m_nSize*m_nSize;
	double **m_ppAdjMatrix;	// network adjacent matrix;
	int m_nBigestCon;
	
	// other parameters for specific network;
	double m_dConWeiUp;	// connection weight's upper bound;
	double m_dConWeiLow;	// connection weight's lower bound;
	double m_dAdjWei;	// adjustment of connection weight;
	double m_dConWeiThres;	// connection weight's threshold;
	// for basic network;
  	int m_nEdgePerNode;	// m_nNumAgent/10.0, No. of edges for each new node; in local world network, m_nEdgePerNode<=m_nLocalView;
	int m_nLaceR;	// in lace network;
	int m_nLattice;	// in lattice network, each agent connects his nearest and next nearest neighbors; node i connect to node i-(int)(m_nLattice/2.0) to i+(int)(m_nLattice/2.0); 
	double m_dAvgDegree;	// in random network, it is 2*m_nEdgePerNode; in Scale-free, local world, exponential network, it is (2*m_nEdgePerNode*(m_nNumAgent-N0)+2*E0)/m_nNumAgent; N0, initial nodes; E0, already set connections among N0 nodes; 
	// for Scale-free, Small world, Local world network;
	int m_nLocalView;	// local view of each new agent; in exponential network, m_nLocalView==m_nEdgePerNode;
	double m_dReWire;	// prob to rewire one connection;
	double m_dAddWireProb;	// prob of adding new edges in building up Small Word network;
	double m_dRandomProb;	// random network, prob for adding an edge;
	// for Copper-Frieze network;
	int m_nNumAddEdge;	// No. of edges that one time step can add at most, uniformly distributed; 
	double m_dAlfaCF;	// prob of OLD process for generating new edge; 1-m_dAlfa, probability of NEW process for adding new vertex;
	double m_dBetaCF;	// In NEW process, prob that choices of terminal vertices are made uniformly; 1-m_dBeta, prob that choices of terminal vertices are made according to degree;
	double m_dGamaCF;	// In OLD process, prob that choices of terminal vertices are made uniformly; 1-m_dGama, prob that choices of terminal vertices are made according to degree;
	double m_dSetaCF;	// In OLD process, prob that the initial node is selected uniformly; 1-m_dSeta, prob that the initial node is selected according to degree;
	// for Directed scale-free network; 3 actions; 
	int m_nDegMode;	// for directed network, -1, record all degrees; 0, record out-degrees; 1, record in-degrees;
	double m_dSetaIN;	// in-degree constant;
	double m_dSetaOUT;	// out-degree constant;
	double m_dAlfaDS;	// prob that add a new vertex v together with an edge from v to an existing vertex w, where w is chosen according to din+m_dSetaIn;
	double m_dBetaDS;	// m_dAlfaDS+0.3, prob that add an edge from an existing vertex v to an existing vertex w, where v and w are chosen independently, v according to dout+m_dSetaOUT and w according to din+m_dSetaIN;
	double m_dGamaDS;	// prob that add a new vertex w and an edge from an existing vertex v to w, where v is chosen according to dout+m_dSetaOUT;
	// for Multi-Local-World (MLW); 3 actions; m_dP+m_dQ+m_dR=1.0
	double m_dAlfaMLW;	// constant to decide pow(T(i), m_dAlfaMLW); the newly created local world has more attractivity;
	int m_nM1;	// No. of new edges added in action 1;
	int m_nM2;	// No. of new edges added in action 2;
	int m_nM3;	// No. of new edges added in action 3;
	double m_dP;	// prob that a new local-world with 1 node is created. Its m_nM1 links to the existing local-worlds, decided by the prob of the existing local-worlds decided by their connctions; repeat m_nM1 times;
	double m_dQ;	// prob that a new node is added to an existing local-world, which has m_nM2 links with the nodes within the same local-world. The prob that local-world i is selected is proportional to pow(T(i), m_nAlfaMLW); repeat m_nM2 times;
	double m_dR;	// prob that a total of m_nM3 links are added to the network: first, a local-world and a node in this local-world are randomly selected; another node is randomly selected for each link with the prob decided by its degrees; repeat m_nM3 times; 

  // public membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CNet();	// default construction function;
  	CNet(int size);		// construction function;
	CNet(const CNet &init);	// copy construction function;
  	~CNet();	// destruction function;
  	CNet & operator = (const CNet &right);	// copy array by value;
  	void InitNet(int size);	// initialization function;
	void DestNet();	// destruction function;
	// inline retrieve and change private members;
	inline int getNetTyp() { return m_nNetTyp; };
	inline void setNetTyp(int netTyp) { assert((-1<=netTyp)&&(netTyp<=7)); m_nNetTyp=netTyp; }; 
	inline int getBasicTyp() { return m_nBasicTyp; };
	inline void setBasicTyp(int basicTyp) { assert((-1<=basicTyp)&&(basicTyp<=8)); m_nBasicTyp=basicTyp; };
	inline int getDirected() { return m_nDirected; };
	inline void setDirected(int directed) { assert((directed==-1)||(directed==0)||(directed==1)); m_nDirected=directed; };
	inline int getSize() { return m_nSize; };
	inline void setSize(int size) { assert(size>=0); m_nSize=size; };
	inline double getAdjMatrixMember(int xLoc, int yLoc) { assert((0<=xLoc)&&(xLoc<getSize())&&(0<=yLoc)&&(yLoc<getSize())); return m_ppAdjMatrix[xLoc][yLoc]; };
	inline void setAdjMatrixMember(int xLoc, int yLoc, double member) { assert((0<=xLoc)&&(xLoc<getSize())&&(0<=yLoc)&&(yLoc<getSize())); assert(FLOAT_BG_EQ(member, 0.0)); m_ppAdjMatrix[xLoc][yLoc]=member; };
	inline void IncAdjMatrixMember(int xLoc, int yLoc, double adjValue=0.0) 
		{ assert((0<=xLoc)&&(xLoc<getSize())&&(0<=yLoc)&&(yLoc<getSize())); assert(FLOAT_BG_EQ(adjValue, 0.0)); 
		  if(FLOAT_EQ(adjValue, 0.0)) m_ppAdjMatrix[xLoc][yLoc]+=getAdjWei();
		  else m_ppAdjMatrix[xLoc][yLoc]+=adjValue; 
		  if(FLOAT_BG_EQ(m_ppAdjMatrix[xLoc][yLoc], getConWeiUp())) m_ppAdjMatrix[xLoc][yLoc]=getConWeiUp();
		};
	inline void DecAdjMatrixMember(int xLoc, int yLoc, double adjValue=0.0)
		{ assert((0<=xLoc)&&(xLoc<getSize())&&(0<=yLoc)&&(yLoc<getSize())); assert(FLOAT_BG_EQ(adjValue, 0.0)); 
		  if(FLOAT_EQ(adjValue, 0.0)) m_ppAdjMatrix[xLoc][yLoc]-=getAdjWei();
		  else m_ppAdjMatrix[xLoc][yLoc]-=adjValue;
		  if(FLOAT_SM_EQ(m_ppAdjMatrix[xLoc][yLoc], getConWeiLow())) m_ppAdjMatrix[xLoc][yLoc]=getConWeiLow();
		};
	inline void EmpAdjMatrix()
		{ assert(getSize()!=0);
		  int i, j;
		  for(i=0;i<getSize();i++)
			for(j=0;j<getSize();j++)
				setAdjMatrixMember(i, j, getConWeiLow());
		};
	inline int getBigestCon() { return m_nBigestCon; };
	inline void setBigestCon(int bigestCon) { assert(bigestCon>=0); m_nBigestCon=bigestCon; };
	// inline retrieve and change private members for specific network;
	inline double getConWeiUp() { return m_dConWeiUp; };
	inline void setConWeiUp(double ConWeiUp) { assert((FLOAT_SM_EQ(0.0, ConWeiUp))&&(FLOAT_SM_EQ(ConWeiUp, 1.0))); m_dConWeiUp=ConWeiUp; };
	inline double getConWeiLow() { return m_dConWeiLow; };
	inline void setConWeiLow(double ConWeiLow) { assert((FLOAT_SM_EQ(0.0, ConWeiLow))&&(FLOAT_SM_EQ(ConWeiLow, 1.0))); m_dConWeiLow=ConWeiLow; };
	inline double getAdjWei() { return m_dAdjWei; };
	inline void setAdjWei(double adjWei) { assert((FLOAT_SM_EQ(0.0, adjWei))&&(FLOAT_SM_EQ(adjWei, 1.0))); m_dAdjWei=adjWei; };
	inline double getConWeiThres() { return m_dConWeiThres; };
	inline void setConWeiThres(double conweithres) { assert((FLOAT_SM_EQ(0.0, conweithres))&&(FLOAT_SM_EQ(conweithres, 1.0))); m_dConWeiThres=conweithres; };
	// for basic network;
	inline int getEdgePerNode() { return m_nEdgePerNode; };
	inline void setEdgePerNode(int edgepernode) { assert((0<=edgepernode)&&(edgepernode<getSize())); m_nEdgePerNode=edgepernode; };
	inline int getLaceR() { return m_nLaceR; };
	inline void setLaceR(int laceR) { assert((0<=laceR)&&(laceR<getSize())); m_nLaceR=laceR; };
	inline int getLattice() { return m_nLattice; };
	inline void setLattice(int lattice) { assert((0<=lattice)&&(lattice<getSize())); m_nLattice=lattice; };
	inline double getAvgDegree() { return m_dAvgDegree; };
	inline void setAvgDegree(double avgdegree) { assert(avgdegree>=0); m_dAvgDegree=avgdegree; }; 
	// for Scale-free, Small world, Local world network;
	inline int getLocalView() { return m_nLocalView; };
	inline void setLocalView(int localview) { assert((0<=localview)&&(localview<getSize())); m_nLocalView=localview; }; 
	inline double getReWire() { return m_dReWire; };
	inline void setReWire(double rewire) { assert((FLOAT_SM_EQ(0.0, rewire))&&(FLOAT_SM_EQ(rewire, 1.0))); m_dReWire=rewire; };
	inline double getAddWireProb() { return m_dAddWireProb; };
	inline void setAddWireProb(double addwireprob) { assert((FLOAT_SM_EQ(0.0, addwireprob))&&(FLOAT_SM_EQ(addwireprob, 1.0))); m_dAddWireProb=addwireprob; };
	inline double getRandomProb() { return m_dRandomProb; };
	inline void setRandomProb(double randomprob) { assert((FLOAT_SM_EQ(0.0, randomprob))&&(FLOAT_SM_EQ(randomprob, 1.0))); m_dRandomProb=randomprob; };
	// for Copper-Frieze network;
	inline int getNumAddEdge() { return m_nNumAddEdge; }; 
	inline void setNumAddEdge(int numaddedge) { assert((0<=numaddedge)&&(numaddedge<getSize())); m_nNumAddEdge=numaddedge; };
	inline double getAlfaCF() { return m_dAlfaCF; };
	inline void setAlfaCF(double alfaCF) { assert((FLOAT_SM_EQ(0.0, alfaCF))&&(FLOAT_SM_EQ(alfaCF, 1.0))); m_dAlfaCF=alfaCF; };
	inline double getBetaCF() { return m_dBetaCF; };
	inline void setBetaCF(double betaCF) { assert((FLOAT_SM_EQ(0.0, betaCF))&&(FLOAT_SM_EQ(betaCF, 1.0))); m_dBetaCF=betaCF; };
	inline double getGamaCF() { return m_dGamaCF; };
	inline void setGamaCF(double gamaCF) { assert((FLOAT_SM_EQ(0.0, gamaCF))&&(FLOAT_SM_EQ(gamaCF, 1.0))); m_dGamaCF=gamaCF; };
	inline double getSetaCF() { return m_dSetaCF; };
	inline void setSetaCF(double setaCF) { assert((FLOAT_SM_EQ(0.0, setaCF))&&(FLOAT_SM_EQ(setaCF, 1.0))); m_dSetaCF=setaCF; };
	// for Directed scale-free network; 3 actions; 
	inline int getDegMode() { return m_nDegMode; };
	inline void setDegMode(int degmode) { assert((-2<=degmode)&&(degmode<=1)); m_nDegMode=degmode; };
	inline double getSetaIN() { return m_dSetaIN; };
	inline void setSetaIN(double setaIN) { assert((FLOAT_SM_EQ(0.0, setaIN))&&(FLOAT_SM_EQ(setaIN, 1.0))); m_dSetaIN=setaIN; }; 
	inline double getSetaOUT() { return m_dSetaOUT; };
	inline void setSetaOUT(double setaOUT) { assert((FLOAT_SM_EQ(0.0, setaOUT))&&(FLOAT_SM_EQ(setaOUT, 1.0))); m_dSetaOUT=setaOUT; };
	inline double getAlfaDS() { return m_dAlfaDS; };
	inline void setAlfaDS(double alfaDS) { assert((FLOAT_SM_EQ(0.0, alfaDS))&&(FLOAT_SM_EQ(alfaDS, 1.0))); m_dAlfaDS=alfaDS; };
	inline double getBetaDS() { return m_dBetaDS; };
	inline void setBetaDS(double betaDS) { assert((FLOAT_SM_EQ(0.0, betaDS))&&(FLOAT_SM_EQ(betaDS, 1.0))); m_dBetaDS=betaDS; };
	inline double getGamaDS() { return m_dGamaDS; };
	inline void setGamaDS(double gamaDS) { assert((FLOAT_SM_EQ(0.0, gamaDS))&&(FLOAT_SM_EQ(gamaDS, 1.0))); m_dGamaDS=gamaDS; };
	// for Multi-Local-World (MLW); 3 actions; m_dP+m_dQ+m_dR=1.0
	inline double getAlfaMLW() { return m_dAlfaMLW; };
	inline void setAlfaMLW(double alfaMLW) { assert((FLOAT_SM_EQ(0.0, alfaMLW))&&(FLOAT_SM_EQ(alfaMLW, 1.0))); m_dAlfaMLW=alfaMLW; };
	inline int getM1() { return m_nM1; };
	inline void setM1(int M1) { assert((0<=M1)&&(M1<getSize())); m_nM1=M1; };
	inline int getM2() { return m_nM2; };
	inline void setM2(int M2) { assert((0<=M2)&&(M2<getSize())); m_nM2=M2; };
	inline int getM3() { return m_nM3; };
	inline void setM3(int M3) { assert((0<=M3)&&(M3<getSize())); m_nM3=M3; };
	inline double getP() { return m_dP; };
	inline void setP(double P) { assert((FLOAT_SM_EQ(0.0, P))&&(FLOAT_SM_EQ(P, 1.0))); m_dP=P; };
	inline double getQ() { return m_dQ; };
	inline void setQ(double Q) { assert((FLOAT_SM_EQ(0.0, Q))&&(FLOAT_SM_EQ(Q, 1.0))); m_dQ=Q; };
	inline double getR() { return m_dR; };
	inline void setR(double R) { assert((FLOAT_SM_EQ(0.0, R))&&(FLOAT_SM_EQ(R, 1.0))); m_dR=R; }; 

	// other operations;
	// cheking network paramters;
	void depth_firstVisit(int *visit, int size, int i);	// deep first searching the network, type=0/1, search socialmatrix; 2, search naturalmatrix;
	int chkCon(int netsize);	// check connectivity;
	void updDeg(double **Local, int locSize1, int locSize2, int *localView, int i);	// update each node's degree in Local; 
	void initDeg(double **Local, int locSize1, int locSize2, int *localView, int *edgePerNode, int i);	// initialize Local's node and its degree; 
 	void selNewCon(double **Local, int locSize1, int locSize2, int *localView, int *edgePernode, int i);	// select new connection based on each node's degree;
	double calDeg(int *degree, int degSize, int *index, int indexSize, int range1, int range2);	// calculate chosen nodes' degree and the average degree; 
 	double calClusterCoef(int *degree, int degSize, int *index, int indexSize, int range1, int range2);	// calculate cluster coefficient;
	double calShortPath(int *index, int indexSize, int range1, int range2);	// calculate average shortest path length;
	void nodeBetw(int n, int *index, int indexSize, int range1, int range2, double *path1, int path1Size, int *Comp1, int comp1Size, int **Pred1, int pred1Size1, int pred1Size2);	// calculate node n's node betweenness;
	void calBetwNode(double *betwNode, int betwNodeSize, int *index, int indexSize, int range1, int range2);	// calculate node betweenness;
	void edgeBetw(int n, int numedge, double **betwEdge, int betwEdgeSize1, int betwEdgeSize2, double *path2, int path2Size, int *Comp2, int comp2Size, int **Pred2, int pred2Size1, int pred2Size2);	// calculate edge n's edge betweenness;
	void calBetwEdge(double **betwEdge, int betwEdgeSize1, int betwEdgeSize2, int *index, int indexSize, int range1, int range2, int *numedge);	// calculate node and edge betweenness;
	void updConCompList(int *visit, int visitSize, int **&ConCompList, int *numConCompList);	// update visit to BigestConComp;
	void resortConCompList(int **ConCompList, int *numConCompList);	// resort ConCompList according to the size;
	void calBigestConComp(int **&ConCompList, int *numConCompList, int *sizeConCompList);	// calculate and store the biggest connected components;
	void setIndex(int type, int *index, int indexSize, int *range1, int *range2, int **ConCompList, int numConCompList, int sizeConCompList);	// set up index according to ConCompList;
	// creating different networks;
 	void crtBasicNet();	// create different types of basic network;
	void crtSFnet();	// Scale-free network;
	void crtSWnet();	// Small world network; Two method: 1) Rewiring method; 2) Adding new wires;
	void crtLWnet();	// Local world network;
	void crtExpnet();	// Exponential network;
	// creating Cooper-Frieze network;
	int calCurEdge(int netsize);	// calculate current netsize nodes' edges;
	int genEdge(int netsize, int mode);	// generate new edges in Cooper-Frieze network; mode=0, OLD process; 1, NEW process;
	void calCurDeg(double **Local, int locSize1, int locSize2, int netsize, int mode=-1, int curEdge=-1);	// calclate current nodes' edges; mode=-1, undirected degrees; 0, directed out-degree; 1, directed in-degree;
	void selEdge(int numEdge, int netsize, int mode);	
			// in OLD process, selecte edges according to 4 conditions;
  			// mode=1, initial node is chosen uniformly; terminal node is chosen uniformly;
  			// mode=2, initial node is chosen uniformly; terminal node is chosen according to their degrees;
  			// mode=3, initial node is chosen according to their degrees; terminal node is chosen uniformly;
  			// mode=4, initial node is chosen according to their degrees; terminal node is chosen according to their degrees;
  			// in NEW process, select edges according to 2 conditions;
  			// mode=5, terminal nodes are chosen uniformly;
  			// mode=6, terminal nodes are chosen according to their degrees;
	void crtCFnet();	// Cooper-Frieze network;
	// creating Directed Scale-free network;
	void builDSFaction(int netsize, int step, int mode);	// build up Directed scale-free network;
  			// mode=1, add a new vertex v together with an edge from v to an existing vertex w, where w is chosen according to din+_SetaIN;
  			// mode=2, add an edge from an existing vertex v to an existing vertex w, where v and w are chosen independently, v according to dout+_SetaOUT and w according to din+_SetaIN;
  			// mode=3, add a new vertex w and an edge from an existing vertex v to w, where v is chosen according to dout+_SetaOUT;
	void crtDSFnet();	// Directed Scale-free network;
	// creating Multiple Local world network;
	void setLocalWorld(int *numlocal, double *curlocalset, int size, double **Localset, int size1, int size2, int mode);	// decide the probability of choosing existing local world; mode=0, based on creating time; 1, based on inner edges; 
	void selConNode(int selLocal, int netsize, int *numlocal, int *selNode1, int *selNode2, int mode, double **LocalRec, int size3, int size4, int *m);	// select nodes to connect in one local world; mode=1, select one node based on its degree; 2/3, select m nodes based on its degree; 
	void buildMLWaction(int netsize, int *numlocal, int step, double **Localset, int size1, int size2, double **LocalRec, int size3, int size4, int mode);	
			// mode=1, a new local-world with one node is created. Its _M1 links to the existing local-worlds are decided by the probability of the existing local-worlds decided by their connctions; repeat _M1 times;
  			// mode=2, a new node is added to an existing local-world, which has _M2 links with the nodes within the same local-world. The probability that local-world i is selected is proportional to pow(T(i), _AlfaMLW), where T(i) is the time at which local-world i is created and _AlfaMLW is a constant; repeat _M2 times;
  			// mode=3, a total of _M3 links are added to the network: first, a local-world and a node in this local-world are randomly selected; then, another node is randomly selected for each link with the probability decided by its degrees; repeat _M3 times; 
	void crtMLWnet();	// Multiple Local world network;
	// for self-grow network;
	double calNodeDeg(int node);	// calculate node's degree;
	int calAvaCon(int node);	// calculate node's available connections (degree);
	void AdjCon(int xLoc, int yLoc, bool SucCom);	// adjust m_ppAdjMatrix[xLoc][yLoc]'s value according to type;
};



// ---- Define CParaMeters;
class CParaMeters
{ // private members;
  private:
  	int m_nCode;	// 2: using binary code to encode semantic item and semantic roles;
	int m_nNumSemRole;	int m_nLengthSemRole;

	int m_nNumSemAgent; int m_nNumSemPred1; int m_nNumSemPred2; int m_nNumSemPred; int m_nNumSemPat;
	int m_nNumSemItem; int m_nLengthSemItem;
	int m_nAgSamePat;	// whether Agent is same as Patient;

	int m_nLengthSem;	// m_nLengthSemRole+m_nLengthSemItem;
	int m_nLengthIntgMean1; int m_nLengthIntgMean2;
	int m_nLengthIntgMean;

	int m_nLengthWord; int m_nLengthPhrase;
	int m_nLengthHolist1; int m_nLengthHolist2;
	int m_nLengthIntgUtter;
  // public membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CParaMeters();	// construction function;
  	CParaMeters(const CParaMeters &init);	// copy construction function;
  	~CParaMeters();	// destruction function;
  	CParaMeters & operator = (const CParaMeters &right);	// copy parameter;
  	void InitPara();	// initialization function;
  	void DestPara();	// destroy function;
  	// inline retrieve and change private members functions;
	inline int getCode() { return m_nCode; };
	inline void setCode(int code) { assert(code>=0); m_nCode=code; };
	inline int getNumSemRole() { return m_nNumSemRole; };
	inline void setNumSemRole(int numsemrole) { assert(numsemrole>=0); m_nNumSemRole=numsemrole; };
	inline int getLengthSemRole() { return m_nLengthSemRole; };
	inline void setLengthSemRole(int lengthsemrole) { assert(lengthsemrole>=0); m_nLengthSemRole=lengthsemrole; };
	inline int getNumSemAgent() { return m_nNumSemAgent; };
	inline void setNumSemAgent(int numsemagent) { assert(numsemagent>=0); m_nNumSemAgent=numsemagent; };
	inline int getNumSemPred1() { return m_nNumSemPred1; };
	inline void setNumSemPred1(int numsempred1) { assert(numsempred1>=0); m_nNumSemPred1=numsempred1; };
	inline int getNumSemPred2() { return m_nNumSemPred2; };
	inline void setNumSemPred2(int numsempred2) { assert(numsempred2>=0); m_nNumSemPred2=numsempred2; };
	inline int getNumSemPred() { return m_nNumSemPred; };
	inline void setNumSemPred(int numsempred) { assert(numsempred>=0); m_nNumSemPred=numsempred; };
	inline int getNumSemPat() { return m_nNumSemPat; };
	inline void setNumSemPat(int numsempat) { assert(numsempat>=0); m_nNumSemPat=numsempat; };
	inline int getNumSemItem() { return m_nNumSemItem; };
	inline void setNumSemItem(int numsemitem) { assert(numsemitem>=0); m_nNumSemItem=numsemitem; };
	inline int getLengthSemItem() { return m_nLengthSemItem; };
	inline void setLengthSemItem(int lengthsemitem) { assert(lengthsemitem>=0); m_nLengthSemItem=lengthsemitem; };
	inline int getAgSamePat() { return m_nAgSamePat; };
	inline void setAgSamePat(int agsamepat) { assert((agsamepat==-1)||(agsamepat==0)||(agsamepat==1)); m_nAgSamePat=agsamepat; };
	inline int getLengthSem() { return m_nLengthSem; };
	inline void setLengthSem(int lengthsem) { assert(lengthsem>=0); m_nLengthSem=lengthsem; };
	inline int getLengthIntgMean1() { return m_nLengthIntgMean1; };
	inline void setLengthIntgMean1(int lengthintgmean1) { assert(lengthintgmean1>=0); m_nLengthIntgMean1=lengthintgmean1; };
	inline int getLengthIntgMean2() { return m_nLengthIntgMean2; };	
	inline void setLengthIntgMean2(int lengthintgmean2) { assert(lengthintgmean2>=0); m_nLengthIntgMean2=lengthintgmean2; };
	inline int getLengthIntgMean() { return m_nLengthIntgMean; };
  	inline void setLengthIntgMean(int lengthintgmean) { assert(lengthintgmean>=0); m_nLengthIntgMean=lengthintgmean; };
	inline int getLengthWord() { return m_nLengthWord; };
	inline void setLengthWord(int lengthword) { assert(lengthword>=0); m_nLengthWord=lengthword; };
	inline int getLengthPhrase() { return m_nLengthPhrase; };
	inline void setLengthPhrase(int lengthphrase) { assert(lengthphrase>=0); m_nLengthPhrase=lengthphrase; };
	inline int getLengthHolist1() { return m_nLengthHolist1; };
	inline void setLengthHolist1(int lengthholist1) { assert(lengthholist1>=0); m_nLengthHolist1=lengthholist1; };
	inline int getLengthHolist2() { return m_nLengthHolist2; };
	inline void setLengthHolist2(int lengthholist2) { assert(lengthholist2>=0); m_nLengthHolist2=lengthholist2; };
	inline int getLengthIntgUtter() { return m_nLengthIntgUtter; };
	inline void setLengthIntgUtter(int lengthintgutter) { assert(lengthintgutter>=0); m_nLengthIntgUtter=lengthintgutter; };
};



// ---- Define CBasicMean;
class CBasicMean: public CParaMeters
{ // private members; this class contains some general functions to build up semantic items or cues;
  private:
	CArray **m_ppSemRole, **m_ppSemAgent, **m_ppSemPred, **m_ppSemPat;	// copy by value;
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CBasicMean();	// construction function;
  	CBasicMean(const CBasicMean &init);		// copy construction function;
  	~CBasicMean();	// destruction function;
  	CBasicMean & operator = (const CBasicMean &right);	// copy basicmean by value;
  	void InitBasicMean();	// initialization function;
  	void DestBasicMean();	// destroy function;
  	int TransSemItem(CArray *semItem);	// translate semItem into integer value;
	void CreateSem();	// create this->m_pSemRole, this->m_pSemAgent, this->m_pSemPred, this->m_pSemPat;
	// inline retrieve and change private members;
	inline CArray * getpSemRole(int i) { assert((0<=i)&&(i<getNumSemRole())); return m_ppSemRole[i]; };
	inline void setpSemRole(int i, CArray *semrole) { assert(((0<=i)&&(i<getNumSemRole()))&&(semrole->getLengthArray()==getLengthSemRole())); m_ppSemRole[i]=semrole; };
  	inline CArray * getpSemAgent(int i) { assert((0<=i)&&(i<getNumSemAgent())); return m_ppSemAgent[i]; };
  	inline void setpSemAgent(int i, CArray *semagent) { assert(((0<=i)&&(i<getNumSemAgent()))&&(semagent->getLengthArray()==getLengthSemItem())); m_ppSemAgent[i]=semagent; };
	inline CArray * getpSemPred(int i) { assert((0<=i)&&(i<getNumSemPred())); return m_ppSemPred[i]; };
  	inline void setpSemPred(int i, CArray *sempred) { assert(((0<=i)&&(i<getNumSemPred()))&&(sempred->getLengthArray()==getLengthSemItem())); m_ppSemPred[i]=sempred; };
  	inline CArray * getpSemPat(int i){ assert((0<=i)&&(i<getNumSemPat())); return m_ppSemPat[i]; };
  	inline void setpSemPat(int i, CArray *sempat) { assert(((0<=i)&&(i<getNumSemPat()))&&(sempat->getLengthArray()==getLengthSemItem())); m_ppSemPat[i]=sempat; };
	// other operations;
	void OutputBasicMean();	// output CBasicMean;
};



// ---- Define CSemSpace class
class SemItem
{ // private members; 
  private:
	CArray *m_pIntgMean;	// integrated meaning;
  	double m_dFre;	// integrated menaing's frequency;
  // public membership functions;
  public: 
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	SemItem();	// construction function;
	~SemItem();	// destruction function;
	void InitSemItem();	// initialization function;
  	void DestSemItem();	// destroy function;
  	// inliner retrieve and change private members;
  	inline CArray * getpIntgMean() { return m_pIntgMean; };
  	inline void setpIntgMean(CArray *intgMean) { assert(intgMean!=NULL); m_pIntgMean=intgMean; };
  	inline double getFre() { return m_dFre; };
  	inline void setFre(double fre) { assert((FLOAT_SM_EQ(0.0, fre))&&(FLOAT_SM_EQ(fre, 1.0))); m_dFre=fre; };	
};

class CSemSpace: public CBasicMean
{ // private members;
  private:
  	int m_nNumMean1, m_nNumMean2; 
  	int m_nNumIntgMean;	// number of integrated meanings;
  	int m_nSemDist;	// semantic space's distribution; -1: initial value;
		// 0, uniform dist; 1, identical Gaussian; 2, different Gaussian; 3, identical Power law; 4, reverse identical Power law; 5, indetical random; 6, different random;
	double m_dRatioSV_SVO;
	double m_dGausAvg; double m_dGausVar;
	double m_dPowerLawA; double m_dPowerLawK;
	SemItem **m_ppSemItem;	// semantic item (both integrated meaning and its frequency);
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CSemSpace();	 // construction function;
  	CSemSpace(const CSemSpace &init);		// copy construction function;
  	~CSemSpace(); // destruction function;
  	CSemSpace & operator = (const CSemSpace &right);	// copy semspace by value; 
  	void InitSemSpace();	// initialization function;
  	void DestSemSpace();	// destroy function;
  	void CreateSemSpace();	// create semantic space;
  	// inline retrieve and change private members;
	inline int getNumMean1() { return m_nNumMean1; };
	inline void setNumMean1(int nummean1) { assert(nummean1>=0); m_nNumMean1=nummean1; };
	inline int getNumMean2() { return m_nNumMean2; };
	inline void setNumMean2(int nummean2) { assert(nummean2>=0); m_nNumMean2=nummean2; };
  	inline int getNumIntgMean() { return m_nNumIntgMean; };
  	inline void setNumIntgMean(int numintgmean) { assert(numintgmean>=0); m_nNumIntgMean=numintgmean; };
	inline int getSemDist() { return m_nSemDist; };
	inline void setSemDist(int semdist) { assert((-1<=semdist)&&(semdist<=6)); m_nSemDist=semdist; };
	inline double getRatioSV_SVO() { return m_dRatioSV_SVO; };
	inline void setRatioSV_SVO(double ratioSV_SVO) { assert(FLOAT_BG_EQ(ratioSV_SVO, 0.0)); m_dRatioSV_SVO=ratioSV_SVO; };
	inline double getGausAvg() { return m_dGausAvg; };
	inline void setGausAvg(double gausAvg) { assert((FLOAT_SM_EQ(0.0, gausAvg))&&(FLOAT_SM_EQ(gausAvg, 1.0))); m_dGausAvg=gausAvg; };
	inline double getGausVar() { return m_dGausVar; };
	inline void setGausVar(double gausVar) { assert((FLOAT_SM_EQ(0.0, gausVar))&&(FLOAT_SM_EQ(gausVar, 1.0))); m_dGausVar=gausVar; };
	inline double getPowerLawA() { return m_dPowerLawA; };
	inline void setPowerLawA(double powerlawA) { assert(FLOAT_BG_EQ(powerlawA, 0.0)); m_dPowerLawA=powerlawA; };
	inline double getPowerLawK() { return m_dPowerLawK; };
	inline void setPowerLawK(double powerlawK) { assert(FLOAT_SM_EQ(powerlawK, 0.0)); m_dPowerLawK=powerlawK; };
  	inline SemItem * getpSemItem(int i) { assert((0<=i)&&(i<getNumIntgMean())); return m_ppSemItem[i]; };
	inline void setpSemItem(int i, CArray *pmean, double fre) 
		{ assert(((0<=i)&&(i<getNumIntgMean()))&&(pmean->getLengthArray()==getLengthIntgMean())&&(FLOAT_BG_EQ(fre, 0.0))); 
		  getpSemItem(i)->setpIntgMean(pmean); getpSemItem(i)->setFre(fre);
		};
	inline void EmpSemItem(int i)
		{ assert((0<=i)&&(i<getNumIntgMean()));
		  m_ppSemItem[i]=NULL;
		};		
  	// other operations;
  	double gaussrand(double mean, double variance);	// generate a Gaussian distributed variable;
	int RandSelpIntgMeanIndex();	// randomly select an integrated meaning from the semantic space;	
};



// ---- Define CCue class;
class CueItem
{ // private members; 
  private:
	CArray *m_pCueMean;	// cue means array;
	int m_nCueTyp;	// copy by value; cue mean type: m_nCueTyp=-1, initialized value; 
		// m_nCueTyp=0, full meaning "Predicate<Agent>" or "Predicate<Agent, Patient>"; 
		// m_nCueTyp=1, word "Agent"; 2, word "Predicate"; 3, word "Patient"; 
		// m_nCueTyp=4, phrase "Agent+Predicate"; 5, phrase "Agent+Patient"; 6, phrase "Predicate+Patient"
	double m_dCueStr;	// cue's strength, all cues are treated equal with same strength;
  // public membership functions;
  public: 
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CueItem();	// construction function;
	~CueItem();	// destruction function;
	void InitCueItem();	// initialization function;
  	void DestCueItem();	// destroy function;
  	// inline retrieve and change private members;
  	inline CArray *getpCueMean() { return m_pCueMean; };
  	inline void setpCueMean(CArray *cueMean) { assert(cueMean!=NULL); m_pCueMean=cueMean; };
  	inline int getCueTyp() { return m_nCueTyp; };
  	inline void setCueTyp(int cueTyp) { assert((-1<=cueTyp)&&(cueTyp<=4)); m_nCueTyp=cueTyp; };
  	inline double getCueStr() { return m_dCueStr; };
  	inline void setCueStr(double cueStr) { assert((FLOAT_SM_EQ(-1.0, cueStr))&&(FLOAT_SM_EQ(cueStr, 1.0))); m_dCueStr=cueStr; };
};

class CCue: public CParaMeters
{ // private members;
  private:
  	int m_nAtLeastOneCue;	// 1, at least one cue; 0, zero cue is possible;
  	int m_nMaxCueNum;	// maximum cue number;
	int m_nWrongCueTyp;	// -1, default; 0, wrong cue is randomly selected; 1, wrong cue has no component to be identical to the correct meaning;
	double m_dDefCueStr; 
	double m_dCueReliab; double m_dCueReliabVar;	
	int m_nNumCue;
  	CueItem **m_ppCueItem;	// cueitem (cuemean, cuetype, cuestr);	
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CCue();		// construction function;
  	CCue(const CCue &init);	// copy construction function;
  	~CCue();	// destruction function;
  	CCue & operator = (const CCue &right);	// copy cue;  	
  	void InitCue(int numCue);	// initialization function;
  	void DestCue();	// destroy function;
  	// inline retrieve and change private members;
	inline int getAtLeastOneCue() { return m_nAtLeastOneCue; };
	inline void setAtLeastOneCue(int atLeastOneCue) { assert((-1<=atLeastOneCue)&&(atLeastOneCue<=1)); m_nAtLeastOneCue=atLeastOneCue; };
	inline int getMaxCueNum() { return m_nMaxCueNum; };
	inline void setMaxCueNum(int maxcuenum) { assert(maxcuenum>=0); m_nMaxCueNum=maxcuenum; };
	inline int getWrongCueTyp() { return m_nWrongCueTyp; };
	inline void setWrongCueTyp(int wrongCueTyp) { assert((wrongCueTyp==-1)||(wrongCueTyp==0)||(wrongCueTyp==1)); m_nWrongCueTyp=wrongCueTyp; };
	inline double getDefCueStr() { return m_dDefCueStr; };
	inline void setDefCueStr(double defCueStr) { assert((FLOAT_SM_EQ(0.0, defCueStr))&&(FLOAT_SM_EQ(defCueStr, 1.0))); m_dDefCueStr=defCueStr; };
	inline double getCueReliab() { return m_dCueReliab; };
	inline void setCueReliab(double cueReliab) { assert((FLOAT_SM_EQ(0.0, cueReliab))&&(FLOAT_SM_EQ(cueReliab, 1.0))); m_dCueReliab=cueReliab; };
	inline double getCueReliabVar() { return m_dCueReliabVar; };
	inline void setCueReliabVar(double cueReliabVar) { assert((FLOAT_SM_EQ(0.0, cueReliabVar))&&(FLOAT_SM_EQ(cueReliabVar, 1.0))); m_dCueReliabVar=cueReliabVar; };
	inline int getNumCue() { return m_nNumCue; };
	inline void setNumCue(int numcue) 
		{ assert((0<numcue)&&(numcue<=getMaxCueNum())); 
		  int i;
		  EmpCueItem();
		  m_nNumCue=numcue;
		  if(getNumCue()==0) m_ppCueItem=NULL;
		  else
		  	{ m_ppCueItem=new CueItem * [getNumCue()]; assert(m_ppCueItem!=NULL);
		  	  for(i=0;i<getNumCue();i++)
		  	  	m_ppCueItem[i]=NULL;
		  	}		  
		};	// set up this->m_nNumCue;
	inline CueItem * getpCueItem(int i) { assert((0<=i)&&(i<m_nNumCue)); return m_ppCueItem[i]; };
	inline void setpCueItem(int i, CArray *pcue, int cuetyp, double cuestr) 
  		{ assert((0<=i)&&(i<getNumCue())); assert((-1<=cuetyp)&&(cuetyp<=6)&&(FLOAT_SM_EQ(0.0, cuestr))&&(FLOAT_SM_EQ(cuestr, 1.0)));
		  if(m_ppCueItem[i]==NULL) { m_ppCueItem[i]=new CueItem; assert(m_ppCueItem[i]!=NULL); }
		  m_ppCueItem[i]->setpCueMean(pcue); m_ppCueItem[i]->setCueTyp(cuetyp); m_ppCueItem[i]->setCueStr(cuestr);
  		};
  	inline void EmpCueItem()
  		{ int i; 
  		  if(getNumCue()!=0)
  			{ for(i=0;i<getNumCue();i++)
  		  		{ delete m_ppCueItem[i]; m_ppCueItem[i]=NULL; }
  		  	  delete [] m_ppCueItem; m_ppCueItem=NULL; 
  		  	  m_nNumCue=0; 		  		  	
  		  	}
  		};
	// other operations;
	void createCue(CSemSpace *semspace, int type, CArray *pMean, double newCueReliab);	// according to the real mean to create cues; type=0, random select cues; 1, select a wrong cue; 2, select the correct cue;
};



// ---- Define Meaning Utterance mapping;
class CMeanUtter: public CParaMeters
{ // private members;
  private:
  	int m_nNumUtterSyl;	// number of possible syllables;
  	CArray *m_pMean, *m_pUtter;	// meaning and utterance part;
  // membership functions;
  public:
  	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CMeanUtter();	// construction function;
  	CMeanUtter(const CMeanUtter &init);		// copy construction function;
  	~CMeanUtter();	// destruction function;
  	CMeanUtter & operator = (const CMeanUtter &right);	// copy meanutter by value;
  	bool operator == (const CMeanUtter &);		// judge whether two meanutter are same;
	void InitMeanUtter();		// initialization function;
	void DestMeanUtter();		// destroy function;
	// inline retrieve and change private members;
	inline void EmptypMean() { getpMean()->EmptypArray(); };
	inline void EmptypUtter() { getpUtter()->EmptypArray(); };
	inline void EmptypMeanUtter() { EmptypMean(); EmptypUtter(); };
	inline int getNumUtterSyl() { return m_nNumUtterSyl; };
	inline void setNumUtterSyl(int numuttersyl) { assert(numuttersyl>=0); m_nNumUtterSyl=numuttersyl; };
	inline CArray * getpMean() { return m_pMean; };
	inline void setpMean(CArray *pMean) { assert((pMean!=NULL)&&(pMean->getLengthArray()==getLengthIntgMean())); *m_pMean=*pMean; };
	inline CArray * getpUtter() { return m_pUtter; };
	inline void setpUtter(CArray *pUtter) { assert((pUtter!=NULL)&&(pUtter->getLengthArray()==getLengthIntgUtter())); *m_pUtter=*pUtter; };
	inline void copyMeanUtter(CMeanUtter *meanutter) { assert(meanutter!=NULL); setpMean(meanutter->getpMean()); setpUtter(meanutter->getpUtter()); };
	inline void setPartMean(CArray * parray, int start, int loc, int num) { getpMean()->setPartArray(parray, start, loc, num); };
	inline void setPartUtter(CArray * parray, int start, int loc, int num) { getpUtter()->setPartArray(parray, start, loc, num); };
	// other operations;
	void CrtSyl(int type, int size);	// create individual syllables; type=0, continuous; 1, separate;
	void CrtUtter(int type);	// according to different type, randomly create utterance; 
		// type=1, Predicate<Agent> meaning's utterance, 1-6 syllables; 
  		// type=2, Predicate<Agent, Patient> meaning's utterance, 1-9 syllables;
  		// type=3, 1 semantic item's utterance, 1-3 syllables; 
  		// type=4, 2 semantic items' utterance, continuous, 1-6 syllables;
  		// type=5, 2 semantic items' utterance, separate, 1-6 syllables;
	int getLeftUtterLen();	// get left part of utterance syllables length;
	int getRightUtterLen();	// get right part of utterance syllables length;
	int getUtterLen();	// get the total syllable length in the utterance part;
	void Comb2Utter(CMeanUtter *meanutter1, CMeanUtter *meanutter2, int combtype);	// combine meanutter1's, meanutter2's utterance into m_pUtter under the regulation of combtype;
	void Comb3Utter(CMeanUtter *meanutter1, CMeanUtter *meanutter2, CMeanUtter *meanutter3, int combtype12, int combtype23, int combtype13);	// combine meanutter1, meanutter2, meanutter3's utterances into m_pUtter under the regulation of combtype12, combtype23 or combtype13;
	int getPred(CSemSpace *semspace);	// get Pred;
	int getAg(CSemSpace *semspace);	// get Agent;
	int getPat(CSemSpace *semspace);	// get Patient;
};



// ---- Define CBuffer class;
class CBuffer
{ // private members;
  private:
	int m_nBufTyp;	// buffer type; 0, no record instance; 1, record instance; 2, record instance, when deleting, according to instance;
	int m_nRemBuf;	// 0, no removal of fully decomposible M-U mappings; 1, removal of fully decomposible M-U mappings;
	bool m_nBufTag;	// indicate whether the buffer is not full (0) or full (1);
	int m_nMaxBufSize;	// maximun buffer size;
	int m_nCurBufSize;	// current buffer size;
	CMeanUtter **m_ppBuf;	// buffer storage;
	int *m_pBufInst;	// instance of each buffer element;
  // membership functions;
  public:	
	// overload new and delete;
  	//static void * operator new (size_t size) { return GlobalAlloc(GMEM_FIXED, size); };
	//static void operator delete (void *p) { GlobalUnlock(p); GlobalFree(p); };
	CBuffer();	// construction function;
	CBuffer(const CBuffer &init);	// copy construction function;
	~CBuffer();	// destruction function;
	CBuffer & operator = (const CBuffer &right);	// copy buffer;  	
  	void InitBuffer(int curBufSize, int maxBufSize);	// initialization function;
  	void DestBuffer();	// destroy function;
  	// inline retrieve and change private members;
	inline int getBufTyp() { return m_nBufTyp; };
	inline void setBufTyp(int bufTyp) { assert((-1<=bufTyp)&&(bufTyp<=2)); m_nBufTyp=bufTyp; };
	inline int getRemBuf() { return m_nRemBuf; };
	inline void setRemBuf(int remBuf) { assert((-1<=remBuf)&&(remBuf<=1)); m_nRemBuf=remBuf; };
	inline bool getBufTag() { return m_nBufTag; };
  	inline void setBufTag(bool buftag) { m_nBufTag=buftag; };
  	inline int getMaxBufSize() { return m_nMaxBufSize; };
  	inline void setMaxBufSize(int maxbufsize) { assert(maxbufsize>=0); m_nMaxBufSize=maxbufsize; };
  	inline int getCurBufSize() { return m_nCurBufSize; };
	inline void setCurBufSize(int curbufsize) 
  		{ assert((0<=curbufsize)&&(curbufsize<=getMaxBufSize())); 
		  int i;
		  EmpBuf();
		  m_nCurBufSize=curbufsize;
		  if(getCurBufSize()==0) { m_ppBuf=NULL; m_pBufInst=NULL; }
		  else
		  	{ m_ppBuf=new CMeanUtter * [getCurBufSize()]; assert(m_ppBuf!=NULL);
			  m_pBufInst=new int [getCurBufSize()]; assert(m_pBufInst!=NULL);
			  for(i=0;i<getCurBufSize();i++) 
			  	{ m_ppBuf[i]=NULL; m_pBufInst[i]=0;
			  	}
		  	}
		  if(getCurBufSize()==getMaxBufSize()) setBufTag(1);		  
		};
  	inline CMeanUtter * getpBuf(int i) { assert((0<=i)&&(i<getCurBufSize())); return m_ppBuf[i]; };
  	inline void setpBuf(int i, CMeanUtter *meanutter) { assert((0<=i)&&(i<getCurBufSize())); m_ppBuf[i]=meanutter; };
	inline void EmpBuf()
		{ int i; 
		  if(getCurBufSize()!=0) 
			{ for(i=0;i<getCurBufSize();i++)
		  		{ delete m_ppBuf[i]; m_ppBuf[i]=NULL; }
		 	  delete [] m_ppBuf; m_ppBuf=NULL;
			  delete [] m_pBufInst; m_pBufInst=NULL;
			  m_nCurBufSize=0;
		  	}
		  setBufTag(0);		  
		};
	inline int getpBufInst(int i) { assert((0<=i)&&(i<getCurBufSize())); return m_pBufInst[i]; };
	inline void setpBufInst(int i, int bufInst) { assert((0<=i)&&(i<getCurBufSize())); m_pBufInst[i]=bufInst; };
  	// other operations;
  	void InBuffer(CMeanUtter *&meanutter, int *bufLoc);	// put in new meanutter into buffer;
  	void OutBuffer(int ind);	// remove m_ppBuf[ind] from buffer;
  	void OutputBuf();	// output CBuffer;
};
