// Object.cpp: implement CArray, CBasicMean, CSemSpace, CMeanUtter, CBuffer's membership functions;

#include "stdafx.h"
// ---- Include Files;
#include"Object.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CArray's membership functions;
CArray::CArray()
{ // default construction function;
	setLengthArray(0); m_pArray=NULL;
}

CArray::CArray(int lengthArray)
{ // construction function;
	InitArray(lengthArray); EmptypArray();			
}

CArray::CArray(const CArray & init)
{ // copy construction function;
	(*this)=init;
}

CArray::~CArray()
{ // destruction function;
	DestArray();
}

CArray &CArray::operator = (const CArray &right)
{ // copy array by value;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestArray(); InitArray(right.m_nLengthArray);
		  if(getLengthArray()!=0) 
		  	{ for(i=0;i<getLengthArray();i++)
		 	 	setElement(i, right.m_pArray[i]);
		  	}
		}
	return *this;
}

int &CArray::operator [] (int subscript)
{ // [] operator; get subscript; only to be left operand!
	assert((0<=subscript)&&(subscript<getLengthArray()));
	return m_pArray[subscript];
}

bool CArray::operator == (const CArray &right)
{ // compare whether two arrays are same (1) or not (0);
	int i;
	if(getLengthArray()!=right.m_nLengthArray) return 0;	// two arrays have different sizes;
	else
		{ for(i=0;i<getLengthArray();i++)
			{ if(getElement(i)!=right.m_pArray[i]) return 0;	// two arrays are not same;
			}
		  return 1;	// two arrays are same;
		}
}

bool CArray::operator != (const CArray &right)
{ // compare whether two arrays are not same (1) or same (0);
	int i;
	if(getLengthArray()!=right.m_nLengthArray) return 1;	// two arrays have different sizes;
	else
		{ for(i=0;i<getLengthArray();i++)
			{ if(getElement(i)!=right.m_pArray[i]) break;
			}
		  if(i==getLengthArray()) return 0;	// two arrays are same;
		  else return 1;	// two arrays are not same;
		}
}

void CArray::InitArray(int lengthArray)
{ // initialization function;
	assert(lengthArray>=0);
	setLengthArray(lengthArray);
	if(getLengthArray()==0) m_pArray=NULL;
	else { m_pArray=new int [getLengthArray()]; assert(m_pArray!=NULL); }
}

void CArray::DestArray()
{ // destroy function;
	if(getLengthArray()!=0)
		{ delete [] m_pArray; m_pArray=NULL;
		  setLengthArray(0);
		}	
}

// other operations;
void CArray::setPartArray(CArray *parray, int start, int loc, int num)
{ // copy parray[loc]'s num elements into m_pArray[start];
	assert(parray!=NULL);
	assert((0<=loc)&&(loc<parray->getLengthArray())&&(loc+num<=parray->getLengthArray()));
	assert((0<=start)&&(start<getLengthArray())&&(start+num<=getLengthArray()));
	int i;
	for(i=loc;i<loc+num;i++)
		m_pArray[start+i-loc]=parray->getElement(i);
}

bool CArray::containArray(int type, int len, int start, int end, CArray *conArray)
{ // check if m_pArray include conArray;
  // type=1, this and conArray are both continuous utterance; for "Pred<Ag>" meaning to extract word rule; for contain continuous UtterLib;
  // type=2, this and conArray are both continuous utterance; for "Pred<Ag, Pat>" meaning to extract word rule; 
  // type=3, this and conarray are separate utterance;
  // type=4, this and conarray are separate utterance;
	assert((type==1)||(type==2)||(type==3)||(type==4)); assert(conArray!=NULL);
  	assert((0<=start)&&(start<getLengthArray())); assert((0<=end)&&(end<getLengthArray()));
	assert((0<len)&&(len<=getLengthArray())); assert(end-start+1==len);
	int i, j, leftLenThis, rightLenThis, leftLenconArray, rightLenconArray;
	bool leftsame, rightsame, value;

	value=0;
	switch(type)
		{ case 1: // this and conArray are both continuous utterance; for "Pred<Ag>" meaning to extract word rule; for contain continuous UtterLib;
		  		if(len<=conArray->getLengthArray()) value=0;
		  		else
					{ for(i=start;i<start+len-conArray->getLengthArray()+1;i++)
		  				{ for(j=0;j<conArray->getLengthArray();j++)
		  					{ if(getElement(i+j)!=conArray->getElement(j)) break;
		  					}
		  		  		  if(j==conArray->getLengthArray()) { value=1; break; }
		  				}
					}
				break;
		  case 2: // this and conArray are both continuous utterance; for "Pred<Ag, Pat>" meaning to extract word rule;
				if(len<=conArray->getLengthArray()+1) value=0;
		  		else
					{ for(i=start;i<start+len-conArray->getLengthArray()+1;i++)
		  				{ for(j=0;j<conArray->getLengthArray();j++)
		  					{ if(getElement(i+j)!=conArray->getElement(j)) break;
		  					}
		  		  		  if(j==conArray->getLengthArray()) { value=1; break; }
		  				}
					}
		  		break;
		  case 3: // this is continuous, conArray is separate;
				leftLenconArray=rightLenconArray=-1;
				for(i=0;i<conArray->getLengthArray();i++)
					{ if(conArray->getElement(i)==-1) { leftLenconArray=i; break; }
					}
				for(i=conArray->getLengthArray()-1;i>=0;i--)
					{ if(conArray->getElement(i)==-1) { rightLenconArray=conArray->getLengthArray()-1-i; break; }
					}
				if(len<=leftLenconArray+rightLenconArray) value=0;
				else
					{ leftsame=0;
					  for(i=start;i<start+leftLenconArray;i++)
						{ if(getElement(i)!=conArray->getElement(i-start)) break;
					  	}
					  if(i==start+leftLenconArray) leftsame=1;
					  rightsame=0;
					  for(i=end-rightLenconArray+1;i<=end;i++)
					  	{ if(getElement(i)!=conArray->getElement(conArray->getLengthArray()-1+i-end)) break;
					  	}
					  if(i==end+1) rightsame=1;
					  if((leftsame==1)&&(rightsame==1)) value=1;
					}				
				break;
		  case 4: // this and conarray are separate utterance;
				leftLenThis=rightLenThis=-1;
				for(i=start;i<=end;i++)
					{ if(getElement(i)==-1) { leftLenThis=i-start; break; }
					}
				for(i=end;i>=start;i--)
					{ if(getElement(i)==-1) { rightLenThis=end-i; break; }
					}
				leftLenconArray=rightLenconArray=-1;
				for(i=0;i<conArray->getLengthArray();i++)
					{ if(conArray->getElement(i)==-1) { leftLenconArray=i; break; }
					}
				for(i=conArray->getLengthArray()-1;i>=0;i--)
					{ if(conArray->getElement(i)==-1) { rightLenconArray=conArray->getLengthArray()-1-i; break; }
					}
				if((leftLenThis<leftLenconArray)||(rightLenThis<rightLenconArray)) value=0;
				else
				 	{ leftsame=0;
				 	  for(i=0;i<leftLenconArray;i++)
						{ if(getElement(start+i)!=conArray->getElement(i)) break;
						}
				  	  if(i==leftLenconArray) leftsame=1;
					  rightsame=0;
					  for(i=0;i<rightLenconArray;i++)
					 	{ if(getElement(end-rightLenconArray+1+i)!=conArray->getElement(conArray->getLengthArray()-rightLenconArray+i)) break;
					 	}
					  if(i==rightLenconArray) rightsame=1;
					  if((leftsame==1)&&(rightsame==1)) value=1;
					}
		  		break;
		  default: break;		
		}	
	return value;
}

void CArray::maskArray(int len, CArray *mkArray)
{ // mask the same syllable in both sides as in mkArray with -1;
	assert(mkArray!=NULL); assert((0<len)&&(len<=getLengthArray()));
	int i, leftLen, rightLen;
	leftLen=rightLen=-1;
	for(i=0;i<mkArray->getLengthArray();i++)
		{ if(mkArray->getElement(i)==-1) { leftLen=i; break; }
		}
	for(i=mkArray->getLengthArray()-1;i>=0;i--)
		{ if(mkArray->getElement(i)==-1) { rightLen=mkArray->getLengthArray()-1-i; break; }
		}
	assert(leftLen+rightLen<len);
	for(i=0;i<leftLen;i++)
		setElement(i, -1);
	for(i=len-1;i>len-1-rightLen;i--)
		setElement(i, -1);
}

void CArray::OutputArray()
{ // output CArray;
	int i;
	printf("Size=%d: ", getLengthArray());
	for(i=0;i<getLengthArray();i++)
		printf("%d ", getElement(i));
	printf("\n");
}



// CNet's membership functions;
CNet::CNet()
{ // default construction function;
	InitNet(0);
}

CNet::CNet(int size)
{ // construction function;
	InitNet(size);
}

CNet::CNet(const CNet & init)
{ // copy construction function;
	(*this)=init;
}

CNet::~CNet()
{ // destruction function;
	DestNet();
}

CNet &CNet::operator = (const CNet &right)
{ // copy array by value;
	int i, j;
	if(&right!=this)
		{ // it is not self-copy;
		  DestNet(); InitNet(right.m_nSize);
		  // other parameters for specific network;
		  setNetTyp(right.m_nNetTyp); setBasicTyp(right.m_nBasicTyp); setDirected(right.m_nDirected);
		  setConWeiUp(right.m_dConWeiUp); setConWeiLow(right.m_dConWeiLow); setAdjWei(right.m_dAdjWei); setConWeiThres(right.m_dConWeiThres);
		  // for basic network;
  		  setEdgePerNode(right.m_nEdgePerNode);
		  setLaceR(right.m_nLaceR); setLattice(right.m_nLattice); 
		  setAvgDegree(right.m_dAvgDegree);
		  // for Scale-free, Small world, Local world network;
		  setLocalView(right.m_nLocalView);
		  setReWire(right.m_dReWire); setAddWireProb(right.m_dAddWireProb); setRandomProb(right.m_dRandomProb);
		  // for Copper-Frieze network;
		  setNumAddEdge(right.m_nNumAddEdge); 
		  setAlfaCF(right.m_dAlfaCF); setBetaCF(right.m_dBetaCF); setGamaCF(right.m_dGamaCF); setSetaCF(right.m_dSetaCF);
		  // for Directed scale-free network; 3 actions; 
		  setDegMode(right.m_nDegMode);
		  setSetaIN(right.m_dSetaIN); setSetaOUT(right.m_dSetaOUT);
		  setAlfaDS(right.m_dAlfaDS); setBetaDS(right.m_dBetaDS); setGamaDS(right.m_dGamaDS);
		  // for Multi-Local-World (MLW); 3 actions; m_dP+m_dQ+m_dR=1.0
		  setAlfaMLW(right.m_dAlfaMLW);
		  setM1(right.m_nM1); setM2(right.m_nM2); setM3(right.m_nM3);
		  setP(right.m_dP); setQ(right.m_dQ); setR(right.m_dR); 

		  if(getSize()!=0) 
		  	{ for(i=0;i<getSize();i++)
		  		for(j=0;j<getSize();j++)
		 	 		setAdjMatrixMember(i, j, right.m_ppAdjMatrix[i][j]);
		  	}
		}
	return *this;
}

void CNet::InitNet(int size)
{ // initialization function;
	int i;
	setNetTyp(overallpara.p_nNetTyp); setBasicTyp(overallpara.p_nBasicTyp); setDirected(overallpara.p_nDirected); 
	setConWeiUp(overallpara.p_dConWeiUp); setConWeiLow(overallpara.p_dConWeiLow); setAdjWei(overallpara.p_dAdjWei); setConWeiThres(overallpara.p_dConWeiThres);
	setSize(size);
	if(getSize()==0) m_ppAdjMatrix=NULL;
	else
		{ m_ppAdjMatrix=new double * [getSize()]; assert(m_ppAdjMatrix!=NULL);
		  for(i=0;i<getSize();i++)
		  	{ m_ppAdjMatrix[i]=new double [getSize()]; assert(m_ppAdjMatrix[i]!=NULL); }
		  EmpAdjMatrix();
		}
	setBigestCon(getSize()+1);

	// other parameters for specific network;
	// for basic network;
  	setEdgePerNode(overallpara.p_nEdgePerNode);
	setLaceR(overallpara.p_nLaceR); setLattice(overallpara.p_nLattice); 
	setAvgDegree(overallpara.p_dAvgDegree);
	// for Scale-free, Small world, Local world network;
	setLocalView(overallpara.p_nLocalView);
	setReWire(overallpara.p_dReWire); setAddWireProb(overallpara.p_dAddWireProb); setRandomProb(overallpara.p_dRandomProb);
	// for Copper-Frieze network;
	setNumAddEdge(overallpara.p_nNumAddEdge); 
	setAlfaCF(overallpara.p_dAlfaCF); setBetaCF(overallpara.p_dBetaCF); setGamaCF(overallpara.p_dGamaCF); setSetaCF(overallpara.p_dSetaCF);
	// for Directed scale-free network; 3 actions; 
	setDegMode(overallpara.p_nDegMode);
	setSetaIN(overallpara.p_dSetaIN); setSetaOUT(overallpara.p_dSetaOUT);
	setAlfaDS(overallpara.p_dAlfaDS); setBetaDS(overallpara.p_dBetaDS); setGamaDS(overallpara.p_dGamaDS);
	// for Multi-Local-World (MLW); 3 actions; m_dP+m_dQ+m_dR=1.0
	setAlfaMLW(overallpara.p_dAlfaMLW);
	setM1(overallpara.p_nM1); setM2(overallpara.p_nM2); setM3(overallpara.p_nM3);
	setP(overallpara.p_dP); setQ(overallpara.p_dQ); setR(overallpara.p_dR); 

	// initialize different types of networks;
	switch(getNetTyp())
		{ case 0: crtBasicNet(); break;	// different types of basic network;
		  case 1: crtSFnet(); break;	// Scale-free network;
		  case 2: crtSWnet(); break;	// Small world network;
		  case 3: crtLWnet(); break;	// Local world network;
		  case 4: crtExpnet(); break;	// Exponential network;
		  case 5: crtCFnet(); break;	// Cooper-Frieze network;
		  case 6: crtDSFnet(); break;	// Directed Scale-free network;
		  case 7: crtMLWnet(); break;	// Multiple Local world network;
		  default: break;
		}
}

void CNet::DestNet()
{ // destroy function;
	int i;
	// other parameters for specific network;
	// for basic network;
  	setEdgePerNode(0);
	setLaceR(0); setLattice(0); 
	setAvgDegree(0);
	// for Scale-free, Small world, Local world network;
	setLocalView(0);
	setReWire(0.0); setAddWireProb(0.0); setRandomProb(0.0);
	// for Copper-Frieze network;
	setNumAddEdge(0); 
	setAlfaCF(0.0); setBetaCF(0.0); setGamaCF(0.0); setSetaCF(0.0);
	// for Directed scale-free network; 3 actions; 
	setDegMode(-2);
	setSetaIN(0.0); setSetaOUT(0.0);
	setAlfaDS(0.0); setBetaDS(0.0); setGamaDS(0.0);
	// for Multi-Local-World (MLW); 3 actions; m_dP+m_dQ+m_dR=1.0
	setAlfaMLW(0.0);
	setM1(0); setM2(0); setM3(0);
	setP(0.0); setQ(0.0); setR(0.0); 

	setConWeiUp(0.0); setConWeiLow(0.0); setAdjWei(0.0); setConWeiThres(0.0);
	setBigestCon(0);
	if(getSize()==0) m_ppAdjMatrix=NULL;
	else
		{ EmpAdjMatrix();
		  for(i=0;i<getSize();i++)
		  	{ delete [] m_ppAdjMatrix[i]; m_ppAdjMatrix[i]=NULL; }
		  delete [] m_ppAdjMatrix; m_ppAdjMatrix=NULL;
		  setSize(0);
		}
	setNetTyp(-1); setBasicTyp(-1); setDirected(-1);
}

// other operations;
// checking network parameters; 
void CNet::depth_firstVisit(int *visit, int size, int i)
{ // deep first searching the network, type=0/1, search socialmatrix; 2, search naturalmatrix;
	assert(visit!=NULL); assert(size==getSize()); assert((0<=i)&&(i<getSize())); 
	int j, top;  // top of the stack;
  	int *stack=new int [size]; assert(stack!=NULL);	// stack for storing current searched nodes;
	for(j=0;j<size;j++)
  		stack[j]=0;
	for(j=0;j<size;j++)
		visit[j]=0;
	top=0; stack[top]=i; // starting nodes into the stack; 
  	visit[i]=1;
  	do{ for(j=0;j<size;j++)
    			{ if((FLOAT_BG_EQ(getAdjMatrixMember(stack[top], j), getConWeiThres()))&&(visit[j]==0))
    				{ top++; stack[top]=j; visit[j]=1; break; }
   	 		}
		if(j==size) { stack[top]=0; top--; }
    	}while(top!=-1);
	delete [] stack; stack=NULL;	// delete stack;
}

int CNet::chkCon(int netsize)
{ // check connectivity; 
	assert((0<netsize)&&(netsize<=getSize()));
	int i, j, split=1;
	int *visit=new int [netsize]; assert(visit!=NULL);	// visit[*] stores the results of visited nodes;
  	for(i=0;i<netsize;i++)
  		visit[i]=0;
	// deep priority search, from every nodes, try visiting all other nodes; if so, the network is connected;
  	for(i=0;i<netsize;i++)
  		{ depth_firstVisit(visit, netsize, i);  // search the network;
  		  // check if the whole group is searched;  	  
  	  	  for(j=0;j<netsize;j++)
  	  		{ if(visit[j]==0) break; }
	  	  if(j==netsize) { split=0; break; }  	  	
  		}
	delete [] visit; visit=NULL;	// delete visit;
	return split;
}

void CNet::updDeg(double **Local, int locSize1, int locSize2, int *localView, int i)
{ // update each node's degree in Local; 
	assert((Local!=NULL)&&(localView!=NULL)); 
	assert((0<=*localView)&&(*localView<=getSize())); assert((0<=i)&&(i<getSize()));
	int j, k;
  	double alldegree;  // for sorting the local;
  	// initialize the local;
  	for(j=0;j<locSize1;j++)
		Local[j][1]=0.0;
  	// select local view nodes;
  	for(j=0;j<*localView;j++)
  		for(k=0;k<i;k++)
 	   		{ if(FLOAT_BG_EQ(getAdjMatrixMember((int)(Local[j][0]), k), getConWeiThres())) Local[j][1]+=getAdjMatrixMember((int)(Local[j][0]), k); }
  	// calculate all degree and degree distribution;
  	for(j=0;j<*localView;j++)
   		{ if(FLOAT_EQ(Local[j][1], 0.0)) Local[j][1]+=getAdjWei();   		  		
  		}
 	alldegree=0.0;
  	for(j=0;j<*localView;j++)
  		alldegree+=Local[j][1];
  	for(j=1;j<*localView;j++)
  		Local[j][1]+=Local[j-1][1];
  	for(j=0;j<*localView;j++)
  		Local[j][1]/=alldegree;
}

void CNet::initDeg(double **Local, int locSize1, int locSize2, int *localView, int *edgePerNode, int i)
{ // initialize Local's node and its degree; 
  	assert((Local!=NULL)&&(localView!=NULL)&&(edgePerNode!=NULL));
	assert((0<=*localView)&&(*localView<=getSize())); assert((0<=*edgePerNode)&&(*edgePerNode<getSize())); 
	assert((0<=i)&&(i<getSize()));
	int j, k, selnode;  // select seen nodes for new nodes;

	// initialize the local[*][0], select local view nodes index;
  	for(j=0;j<locSize1;j++)
		Local[j][0]=-1.0;	  
  	if(getNetTyp()==1) 
		{ // scale-free network;
		  if(i<=*edgePerNode) *edgePerNode=i;
		  // all previous nodes are in the local view;
		  *localView=i;
		  for(j=0;j<*localView;j++)
		  	Local[j][0]=(double)j;
  		}
  	else if(getNetTyp()==3)
  		{ // local world network;
  		  if(i<=*edgePerNode) *edgePerNode=i;
  	  	  if(i<=*localView) 
		  	{ *localView=i;
		  	  // all previous nodes are in the local view;
			  for(j=0;j<*localView;j++)
				Local[j][0]=(double)j;
  	  	  	}
		  else
		  	{ // select local view nodes;
  		  	  for(j=0;j<*localView;j++)
   				{ // select local view nodes;
			  	  do{ do{ selnode=(int)(Rand0_1*i);
  			   	  	  }while(selnode==i);
			  	  	  for(k=0;k<j;k++)
			  			{ if(FLOAT_EQ(Local[k][0], (double)(selnode))) break;
						}
				  }while(k!=j);
   	 			  Local[j][0]=(double)selnode;
    			}
		  	}
  		}
  	else if(getNetTyp()==4) 
		{ // exponential network;
		  if(i<=*localView) 
		  	{ *localView=*edgePerNode=i; 
		  	  // all previous nodes are in the local view;
		  	  for(j=0;j<*localView;j++)
		  		Local[j][0]=(double)j;
		  	}
		  else
		  	{ // select local view nodes;
  			  for(j=0;j<*localView;j++)
    			{ // select local view nodes;
	  		  	  do{ do{ selnode=(int)(Rand0_1*i);
  	   	  	  	  	  }while(selnode==i);
	  	  	  	  	  for(k=0;k<j;k++)
	  					{ if(FLOAT_EQ(Local[k][0], (double)(selnode))) break;
						}
		  	  	  }while(k!=j);
    		  	  Local[j][0]=(double)selnode;
    			}
		  	}
		}
  	updDeg(Local, locSize1, locSize2, localView, i);	// calculate all degree and degree distribution;
}

void CNet::selNewCon(double **Local, int locSize1, int locSize2, int *localView, int *edgePerNode, int i)
{ // select new connection based on each node's degree;
  	assert((Local!=NULL)&&(localView!=NULL)&&(edgePerNode!=NULL));
	assert((0<=*localView)&&(*localView<=getSize())); assert((0<=*edgePerNode)&&(*edgePerNode<getSize())); 
	assert((0<=i)&&(i<getSize()));
	int j, k, newCon;  // record the nodes that new node connects to;
  	double rannum;
  	int *connect=NULL;
  	// initialize connected;
  	if(*localView==*edgePerNode)
		{ // exponential network, just add new edges to every local view nodes;
		  for(j=0;j<*localView;j++)
		  	{ setAdjMatrixMember((int)(Local[j][0]), i, getConWeiUp()); setAdjMatrixMember(i, (int)(Local[j][0]), getAdjMatrixMember((int)(Local[j][0]), i)); }
  		}
 	else if(*localView>*edgePerNode)
  		{ connect=new int [getSize()]; assert(connect!=NULL);  // make sure that there is only one edge between any two nodes;
  		  for(j=0;j<getSize();j++)
 		 	connect[j]=0;
 		  for(j=0;j<*edgePerNode;j++)
  			{ // set up random number to decide the connection;
			  do{ newCon=-1; rannum=Rand0_1; 
		 	 	 if((FLOAT_SM_EQ(rannum, Local[0][1]))&&(connect[(int)(Local[0][0])]==0)) newCon=(int)(Local[0][0]);
				 else if((FLOAT_EQ(rannum, 1.0))&&(connect[(int)(Local[*localView-1][0])]==0)) newCon=(int)(Local[*localView-1][0]);
				 else
				  	{ for(k=1;k<*localView;k++)
				  		{ if(((FLOAT_BG(rannum, Local[k-1][1]))&&(FLOAT_SM_EQ(rannum, Local[k][1])))&&(connect[(int)(Local[k][0])]==0)) { newCon=(int)(Local[k][0]); break; }
				  		}
				 	}
			  }while(newCon==-1);
			  setAdjMatrixMember(i, newCon, getConWeiUp()); setAdjMatrixMember(newCon, i, getAdjMatrixMember(i, newCon)); 
			  connect[newCon]=1;		  		  		  	  	
			}
		  delete [] connect; connect=NULL;	// delete connect;
  		}  	
}

double CNet::calDeg(int *degree, int degSize, int *index, int indexSize, int range1, int range2)
{ // calculate chosen nodes' degree and the average degree; 
	assert(degree!=NULL); assert((0<degSize)&&(degSize<=getSize()));
	assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	int i, j; 
	double degAvg;
  	// calculate chosen nodes degree;
  	if(!((getNetTyp()==6)||((getNetTyp()==0)&&(getBasicTyp()==7))))
  		{ // undirected network;
		  for(i=range1;i<range2;i++)
		 	for(j=range1;j<range2;j++)
 				{ if((FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres()))&&(FLOAT_BG_EQ(getAdjMatrixMember(index[j], index[i]), getConWeiThres()))) degree[index[i]]+=1;
  				}
  		}
  	else
  		{ // directed network;
		  for(i=range1;i<range2;i++)
		  	{ if(getDegMode()==-1)
		  		{ // all degrees; 
		  		  for(j=range1;j<range2;j++)
		  			{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres())) degree[index[i]]+=1; }
		  		  for(j=range1;j<range2;j++)
		  			{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[j], index[i]), getConWeiThres())) degree[index[i]]+=1; }
		  		}
		  	  else if(getDegMode()==0)
		  	  	{ // out-degrees; 
		  	  	  for(j=range1;j<range2;j++)
		  			{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres())) degree[index[i]]+=1; }
		  	  	}
		  	  else if(getDegMode()==1)
		  	  	{ // in-degrees; 
		  	  	  for(j=range1;j<range2;j++)
		  			{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[j], index[i]), getConWeiThres())) degree[index[i]]+=1; }
		  	  	}
		  	}
  		}
  	// calculate the average degree;
  	degAvg=0.0;
  	for(i=range1;i<range2;i++)
  		degAvg+=degree[index[i]];
  	degAvg/=(double)(range2-range1); 
	return degAvg;
}

double CNet::calClusterCoef(int *degree, int degSize, int *index, int indexSize, int range1, int range2)
{ // calculate cluster coefficient;
	assert(degree!=NULL); assert((0<degSize)&&(degSize<=getSize()));
	assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	int i, j, k, numComNeighbor;
	double coefAvg;
	// then, calculate average clustering coefficient;
  	coefAvg=0.0;
  	for(i=range1;i<range2;i++)
  		{ if((degree[index[i]]!=0)&&(degree[index[i]]!=1))
  		  	{ numComNeighbor=0;
  		  	  for(j=range1;j<range2;j++)
  				{ if((FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres()))||(FLOAT_BG_EQ(getAdjMatrixMember(index[j], index[i]), getConWeiThres())))
  					{ // check the number of common neighbors of the node i and node j;  			  
					  for(k=range1;k<range2;k++)
					  	{ if(((FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[k]), getConWeiThres()))||(FLOAT_BG_EQ(getAdjMatrixMember(index[k], index[i]), getConWeiThres())))&&((FLOAT_BG_EQ(getAdjMatrixMember(index[j], index[k]), getConWeiThres()))||(FLOAT_BG_EQ(getAdjMatrixMember(index[k], index[j]), getConWeiThres()))))
					  		numComNeighbor++;
					  	}
  					}
  		  	  	}
  			  coefAvg+=(double)(numComNeighbor/(double)(degree[index[i]]*(degree[index[i]]-1)/_Twice));  // some nodes may have one degree
  			}
  		}
  	coefAvg/=(double)(2*(range2-range1));
	return coefAvg;	
}

double CNet::calShortPath(int *index, int indexSize, int range1, int range2)
{ // calculate average shortest path length;
	assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	int i, j, k, numcon;
	double shortpathAvg;
	int **shortestpath=NULL;
	
	// calculate shortest path length;
  	if((range2-range1==getSize())&&(chkCon(indexSize)==1)) shortpathAvg=getBigestCon();  // all agents are in the group, check the connectivity, then calculate;
  	else
  		{ // calculate the cluster's shortest path length;
		  shortestpath=new int * [getSize()]; assert(shortestpath!=NULL);	// store shortest path;
		  for(i=0;i<getSize();i++)
			{ shortestpath[i]=new int [getSize()]; assert(shortestpath[i]!=NULL); }
		  for(i=0;i<getSize();i++)
  			{ for(j=0;j<getSize();j++)
  				shortestpath[i][j]=getBigestCon();
  		  	  shortestpath[i][i]=0;
  			}
  		  // build up shortestpart based on current network;
    		  for(i=range1;i<range2;i++)
 		 	for(j=i+1;j<range2;j++)
  				{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres())) 
  				  	{ shortestpath[index[i]][index[j]]=1; 
  				  	  if(getDirected()==0) shortestpath[index[j]][index[i]]=1;
  			  		}
  				}  				  
  		  // calculate shortest path;
  		  for(k=range1;k<range2;k++)
  			for(i=range1;i<range2;i++)
  				for(j=range1;j<range2;j++)
  					{ if((index[k]!=index[i])&&(index[k]!=index[j])&&(shortestpath[index[i]][index[k]]!=0)&&(shortestpath[index[k]][index[j]]!=0)&&(shortestpath[index[i]][index[k]]+shortestpath[index[k]][index[j]]<shortestpath[index[i]][index[j]]))
  						{ shortestpath[index[i]][index[j]]=shortestpath[index[i]][index[k]]+shortestpath[index[k]][index[j]];
  						  if(getDirected()==0) shortestpath[index[j]][index[i]]=shortestpath[index[i]][index[k]]+shortestpath[index[k]][index[j]];
  						}
  					}  			
 		  shortpathAvg=0.0; numcon=0;
		  
 	  	  // method 1: original method; 
  	  	  for(i=range1;i<range2;i++)
  			for(j=range1;j<range2;j++)
  				{ if(shortestpath[index[i]][index[j]]!=0) { shortpathAvg+=shortestpath[index[i]][index[j]]; numcon++; }
  				}
		  shortpathAvg/=(double)(numcon);
		  /*	
		  // method 2: calculate: 1/sum(1/shortestpath);
		  for(i=range1;i<range2;i++)
		  	for(j=range1;j<range2;j++)
		  		{ if(shortestpath[index[i]][index[j]]!=0)
		  			{ if(shortestpath[index[i]][index[j]]==getBigestCon()) shortpathAvg+=0.0;
					  else shortpathAvg+=1/(double)(shortestpath[index[i]][index[j]]);
					  numcon++;
		  			}
		  		}
		  shortpathAvg=1/(shortpathAvg)/(double)(numcon));
		  */
		  
		  // delete shortestpath;
		  for(i=0;i<getSize();i++)
			{ delete [] shortestpath[i]; shortestpath[i]=NULL; }
		  delete [] shortestpath; shortestpath=NULL;
  		}
	
	return shortpathAvg;
}

void CNet::nodeBetw(int n, int *index, int indexSize, int range1, int range2, double *path1, int path1Size, int *Comp1, int comp1Size, int **Pred1, int pred1Size1, int pred1Size2)
{ // calculate node n's node betweenness;
	assert((0<=n)&&(n<getSize())); assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	assert(path1!=NULL); assert(Comp1!=NULL); assert(Pred1!=NULL); 
	int i, j;
	int v1, v2, d2, qpush, qpop, count;
	
	int *d=new int [getSize()]; assert(d!=NULL);
	int *q=new int [getSize()]; assert(q!=NULL);
	int *p=new int [getSize()]; assert(p!=NULL);
	int *order=new int [getSize()]; assert(order!=NULL);
	int *npred=new int [getSize()]; assert(npred!=NULL);	// number of predecessors of each edge;
	
  	// calculate node betweenness;
  	// initialize npred, d, p;
  	for(i=0;i<getSize();i++)
  		{ npred[i]=0; d[i]=_UnDef; p[i]=0; }
	
  	// Put the first vertex in the queue and set its distance to zero;
	q[0]=n; d[n]=0; p[n]=1; order[0]=n;
  	qpush=1; qpop=0; count=1;
  
 	while(qpush>qpop)
  		{ // Pull a vertex off the stack and calculate the distance for each of its neighbors;
  		  v1=q[qpop++]; 
		  d2=d[v1]+1;
		  if(getDirected()==0)
		  	{ for(i=range1;i<range2;i++)
		  	  	{ if((FLOAT_BG_EQ(getAdjMatrixMember(v1, index[i]), getConWeiThres()))&&(FLOAT_BG_EQ(getAdjMatrixMember(index[i], v1), getConWeiThres())))
	    	  			{ v2=index[i];
    		  			  if(d[v2]==_UnDef)
    		  			  	{ d[v2]=d2; p[v2]=p[v1];
    		  			  	  Pred1[v2][npred[v2]++]=v1;
    		  			  	  q[qpush++]=v2;
    		  			  	  order[count++]=v2;
    		  			  	}
    		  			  else
    		  			  	{ if(d[v2]==d2)
    		  			  		{ p[v2]+=p[v1]; 
    		  			  		  Pred1[v2][npred[v2]++]=v1;
    		  			  		}
    		  	 		 	}
    		  			}
   	 	  		}
		  	}
		  else if(getDirected()==1)
		  	{ for(i=range1;i<range2;i++)
    		 	 	{ if(FLOAT_BG_EQ(getAdjMatrixMember(v1, index[i]), getConWeiThres()))
    		  			{ v2=index[i];
    		  			  if(d[v2]==_UnDef)
    		  			  	{ d[v2]=d2; p[v2]=p[v1];
    		  			  	  Pred1[v2][npred[v2]++]=v1;
    		  			  	  q[qpush++]=v2;
    		  			  	  order[count++]=v2;
    		  			  	}
    		  			  else
    		  			  	{ if(d[v2]==d2)
    		  			  		{ p[v2]+=p[v1]; 
    		  			  		  Pred1[v2][npred[v2]++]=v1;
    		  			  		}
    		  	 		 	}
    		  			}
    		  		}
		  	}
 	 	}  
  	/* 
  	Now use the tree to calculate the number of shortest paths through each vertex.  We go through each vertex in the opposite order to the
       order they were added to the tree, i.e., starting from the farthest one and working towards the nearest.  This guarantees that the paths
       to the ones above you in the tree will always have been calculated already;
       */    
  	// Everyone starts off with one path;
  	for(i=0;i<count;i++) 
 		path1[order[i]]=1.0;
  	// Main loop;
  	for(i=count-1;i>0;i--) 
  		{ v1=order[i];
    		  for(j=0;j<npred[v1];j++) 
    		  	{ v2=Pred1[v1][j];
      			  path1[v2]+=path1[v1]*p[v2]/(double)(p[v1]);
    			}
  		}
  	// And store the size of this component;
  	Comp1[n]=count;

	// delete d, q, p, order, npred;
	delete [] d; d=NULL; delete [] q; q=NULL; delete [] p; p=NULL;
	delete [] order; order=NULL; delete [] npred; npred=NULL;
}

void CNet::calBetwNode(double *betwNode, int betwNodeSize, int *index, int indexSize, int range1, int range2)
{ // calculate node betweenness;
	assert(betwNode!=NULL); assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	int i, j;
  	//double allbetw=0.0;
	
	double *path1=new double [getSize()]; assert(path1!=NULL);
	double *total1=new double [getSize()]; assert(total1!=NULL);
	int *Comp1=new int [getSize()]; assert(Comp1!=NULL);	// sizes of components that vertices belong to;
	int **Pred1=new int * [getSize()]; assert(Pred1!=NULL);	// number of predecessors of the vertex;
	for(i=0;i<getSize();i++)
		{ Pred1[i]=new int [getSize()]; assert(Pred1[i]!=NULL); }

	// initialize total1; 
	for(i=0;i<getSize();i++)
 		total1[i]=1.0;
	// initialize Pred1;
	for(i=0;i<getSize();i++)
		for(j=0;j<getSize();j++)
  	 	 	Pred1[i][j]=0;
  		
	// initialize betwNode;
  	for(i=0;i<betwNodeSize;i++)
 	 	betwNode[i]=0.0;
		
  	// calculate node betweenness; 
	for(i=range1;i<range2;i++)
  		{ // calculate node betweenness;
  		  nodeBetw(index[i], index, indexSize, range1, range2, path1, getSize(), Comp1, getSize(), Pred1, getSize(), getSize());
  		  for(j=range1;j<range2;j++)
  		  	total1[index[j]]+=path1[index[j]];
  		}
  	// record node betweenness;
  	for(i=range1;i<range2;i++)
		betwNode[index[i]]=total1[index[i]]/_Twice-Comp1[index[i]];
 	/*
  	// normalization of node betweenness;
  	for(i=range1;i<range2;i++)
 	 	allbetw+=betwNode[index[i]];
  	if(allbetw!=0.0)
 	 	{ for(i=range1;i<range2;i++)
  			betwNode[index[i]]/=allbetw;
  		}
  	*/
	// delete path1, total1, Comp1, Pred1;
	delete [] path1; path1=NULL; delete [] total1; total1=NULL; delete [] Comp1; Comp1=NULL; 
	for(i=0;i<getSize();i++)
		{ delete [] Pred1[i]; Pred1[i]=NULL; }
	delete [] Pred1; Pred1=NULL;
}

void CNet::edgeBetw(int n, int numedge, double **betwEdge, int betwEdgeSize1, int betwEdgeSize2, double *path2, int path2Size, int *Comp2, int comp2Size, int **Pred2, int pred2Size1, int pred2Size2)
{ // calculate edge n's edge betweenness;
	assert((0<=n)&&(n<getSize()*(getSize()-1))); assert(betwEdge!=NULL);
	assert(path2!=NULL); assert(Comp2!=NULL); assert(Pred2!=NULL);	
	int i, j;
  	int v1, v2, d2, qpush, qpop, count;
	
  	int *d=new int [getSize()*(getSize()-1)]; assert(d!=NULL);
	int *q=new int [getSize()*(getSize()-1)]; assert(q!=NULL);
	int *p=new int [getSize()*(getSize()-1)]; assert(p!=NULL);
	int *order=new int [getSize()*(getSize()-1)]; assert(order!=NULL);
  	int *npred=new int [getSize()*(getSize()-1)]; assert(npred!=NULL);	// number of predecessors of each edge;
    
  	// calculate edge betweenness;
  	// initialize npred, d, p;
  	for(i=0;i<getSize()*(getSize()-1);i++)
  		{ npred[i]=0; d[i]=_UnDef; p[i]=0; }
	
  	// Put the first edge in the queue and set its distance to zero;
  	q[0]=n; d[n]=0; p[n]=1; order[0]=n;
  	qpush=1; qpop=0; count=1;
  
  	while(qpush>qpop)
  		{ // Pull a vertex off the stack and calculate the distance for each of its neighbors;
  		  v1=q[qpop++];
    		  d2=d[v1]+1;
		  if(getDirected()==0)
		  	{ for(i=0;i<numedge;i++)
		  	  	{ if((i!=v1)&&((FLOAT_EQ(betwEdge[v1][0], betwEdge[i][0]))||(FLOAT_EQ(betwEdge[v1][1], betwEdge[i][1]))||(FLOAT_EQ(betwEdge[v1][0], betwEdge[i][1]))||(FLOAT_EQ(betwEdge[v1][1], betwEdge[i][0]))))
    		  			{ v2=i;
    		  			  if(d[v2]==_UnDef)
    		  			  	{ d[v2]=d2; p[v2]=p[v1];
    		  			  	  Pred2[v2][npred[v2]++]=v1;
    		  			  	  q[qpush++]=v2;
    		  			  	  order[count++]=v2;
    		  			  	}
    		  			  else
    		  			  	{ if(d[v2]==d2)
    		  			  		{ p[v2]+=p[v1]; 
    		  			  		  Pred2[v2][npred[v2]++]=v1;
    		  			  		}
    		  	 		 	}
    		  			}
    		  		}
		  	}
		  else if(getDirected()==1)
		  	{ for(i=0;i<numedge;i++)
    		 	 	{ if((i!=v1)&&((FLOAT_EQ(betwEdge[v1][0], betwEdge[i][1]))||(FLOAT_EQ(betwEdge[v1][1], betwEdge[i][0]))))
    		  			{ v2=i;
    		  			  if(d[v2]==_UnDef)
    		  			  	{ d[v2]=d2; p[v2]=p[v1];
    		  			  	  Pred2[v2][npred[v2]++]=v1;
    		  			  	  q[qpush++]=v2;
    		  			  	  order[count++]=v2;
    		  			  	}
    		  			  else
    	 	 			  	{ if(d[v2]==d2)
    		  			  		{ p[v2]+=p[v1]; 
    	  				  		  Pred2[v2][npred[v2]++]=v1;
    	  				  		}
    	  		 		 	}
    	  				}
    	  			}
		  	}
  		}  
  	/* 
  	Now use the tree to calculate the number of shortest vertex through each edge.  We go through each edge in the opposite order to the
       order they were added to the tree, i.e., starting from the farthest one and working towards the nearest.  This guarantees that the paths
       to the ones above you in the tree will always have been calculated already; 
  	*/

  	// Everyone starts off with one path;
  	for(i=0;i<count;i++) 
	 	path2[order[i]]=1.0;
  	// Main loop;
  	for(i=count-1;i>0;i--) 
  		{ v1=order[i];
    		  for(j=0;j<npred[v1];j++) 
    		  	{ v2=Pred2[v1][j];
      			  path2[v2]+=path2[v1]*p[v2]/(double)(p[v1]);
    			}
  		}
  	// And store the size of this component;
  	Comp2[n]=count;

	// delete d, q, p, order, npred;
	delete [] d; d=NULL; delete [] q; q=NULL; delete [] p; p=NULL;
	delete [] order; order=NULL; delete [] npred; npred=NULL;
}

void CNet::calBetwEdge(double **betwEdge, int betwEdgeSize1, int betwEdgeSize2, int *index, int indexSize, int range1, int range2, int *numedge)
{ // calculate node and edge betweenness;
	assert(betwEdge!=NULL); assert(index!=NULL); assert((0<indexSize)&&(indexSize<=getSize())); 
	assert((0<=range1)&&(range1<getSize())); assert((0<range2)&&(range2<=getSize())); assert(range1<=range2);
	int i, j;
  	//double allbetw=0.0;
	
	double *path2=new double [getSize()*(getSize()-1)]; assert(path2!=NULL);
	double *total2=new double [getSize()*(getSize()-1)]; assert(total2!=NULL);
	int *Comp2=new int [getSize()*(getSize()-1)]; assert(Comp2!=NULL);	// sizes of components that vertices belong to;
	int **Pred2=new int * [getSize()*(getSize()-1)]; assert(Pred2!=NULL);		// number of predecessors of the vertex;
	for(i=0;i<getSize()*(getSize()-1);i++)
		{ Pred2[i]=new int [getSize()*(getSize()-1)]; assert(Pred2[i]!=NULL); }

	// initialize total2;
  	for(i=0;i<getSize()*(getSize()-1);i++)
 	 	total2[i]=1.0;
	// initialize Pred2;
	for(i=0;i<getSize()*(getSize()-1);i++)
   		  for(j=0;j<getSize()*(getSize()-1);j++)
   		 	Pred2[i][j]=0;
  	 
	// initialize betwEdge;
	for(i=0;i<betwEdgeSize1;i++)
		for(j=0;j<betwEdgeSize2;j++)
			betwEdge[i][j]=0.0;

	// record edge;
  	*numedge=0;
  	if(getDirected()==0)
 	 	{ for(i=range1;i<range2;i++)
  			for(j=i+1;j<range2;j++)
  				{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres()))
  					{ betwEdge[*numedge][0]=(double)(index[i]); betwEdge[*numedge][1]=(double)(index[j]); betwEdge[*numedge][2]=0.0; 
  					   (*numedge)++;  				   
  					}
  				}
  		}
  	else if(getDirected()==1)
    		{ for(i=range1;i<range2;i++)
    			for(j=range1;j<range2;j++)
    				{ if(FLOAT_BG_EQ(getAdjMatrixMember(index[i], index[j]), getConWeiThres()))
  					{ betwEdge[*numedge][0]=(double)(index[i]); betwEdge[*numedge][1]=(double)(index[j]); betwEdge[*numedge][2]=0.0; 
  					   (*numedge)++;
  					}
    				}
  		}  

	// calculate edge betweenness;
  	for(i=0;i<*numedge;i++)
 	 	{ // calculate edge betweenness;
  		  edgeBetw(i, *numedge, betwEdge, betwEdgeSize1, betwEdgeSize2, path2, getSize()*(getSize()-1), Comp2, getSize()*(getSize()-1), Pred2, getSize()*(getSize()-1), getSize()*(getSize()-1));
  		  for(j=0;j<*numedge;j++)
  		  	total2[j]+=path2[j];
  		}
	// record edge betweenness;
  	for(i=0;i<*numedge;i++)
	  	betwEdge[i][2]=total2[i]/2-Comp2[i];
  	/*
  	// normalization of node betweenness;
  	for(i=0;i<*numedge;i++)
	  	allbetw+=betwEdge[i][2];
  	if(allbetw!=0.0)
  		{ for(i=0;i<*numedge;i++)
  			betwEdge[i][2]/=allbetw;
  		}
  	*/
  	// delete path2, total2, Comp2, Pred2;
  	delete [] path2; path2=NULL; delete [] total2; total2=NULL; delete [] Comp2; Comp2=NULL;
	for(i=0;i<getSize()*(getSize()-1);i++)
		{ delete [] Pred2[i]; Pred2[i]=NULL; }
	delete [] Pred2; Pred2=NULL;		
}

void CNet::updConCompList(int *visit, int visitSize, int **&ConCompList, int *numConCompList)
{ // update visit to BigestConComp;
	assert(visit!=NULL);
	int i, j, k, cur, nodeSame, temp;
	int **ConCompListTemp=NULL, *newConComp=NULL, numConCompTemp;

	if(*numConCompList==0)
		{ // create newConComp from visit; 
		  newConComp=new int [visitSize]; assert(newConComp!=NULL);
		  for(i=0;i<visitSize;i++)
		  	newConComp[i]=-1;
		  cur=0;
		  for(i=0;i<visitSize;i++)
		  	{ if(visit[i]==1) { newConComp[cur]=i; cur++; }
		  	}
		  // sort newConComp according to its member's index;
		  for(i=1;i<cur;i++)
		  	for(j=0;j<cur-1;j++)
		  		{ if(newConComp[j]>newConComp[j+1])
		  			{ // exchange newConComp[j] and newConComp[j+1];
					  temp=newConComp[j]; newConComp[j]=newConComp[j+1]; newConComp[j+1]=temp;
		  			}
		  		}
		  
		  // copy newConComp to ConCompList;
		  (*numConCompList)++;
		  ConCompList=new int * [*numConCompList]; assert(ConCompList!=NULL);
		  ConCompList[0]=newConComp;
		  newConComp=NULL;	// recollect newConComp;
		}
	else
		{ // create newConComp from visit;
		  newConComp=new int [visitSize]; assert(newConComp!=NULL);
		  for(i=0;i<visitSize;i++)
		  	newConComp[i]=-1;
		  cur=0;
		  for(i=0;i<getSize();i++)
		  	{ if(visit[i]==1) { newConComp[cur]=i; cur++; }
		  	}
		  // sort newConComp according to its member's index;
		  for(i=1;i<cur;i++)
		  	for(j=0;j<cur-1;j++)
		  		{ if(newConComp[j]>newConComp[j+1])
		  			{ // exchange newConComp[j] and newConComp[j+1];
					  temp=newConComp[j]; newConComp[j]=newConComp[j+1]; newConComp[j+1]=temp;
		  			}
		  		}	
		  
		  // copy newConComp to ConCompList;
		  // check whether some node in newConComp is already in ConCompList;
		  nodeSame=0;
		  for(i=0;i<visitSize;i++)
		  	{ if(newConComp[i]!=-1)
		  		{ for(j=0;j<*numConCompList;j++)
		 		 	{ for(k=0;k<visitSize;k++)
		  				{ if(ConCompList[j][k]==newConComp[i]) break;
		  				}
		 	 		  if(k!=visitSize) break;
		  			}
		  		  if(j!=*numConCompList) nodeSame=1;
		  		}
		  	}
		  if(nodeSame==0)
		  	{ // newConComp is a new ConComp;
		  	  numConCompTemp=(*numConCompList)++;
		  	  ConCompListTemp=new int * [numConCompTemp]; assert(ConCompListTemp!=NULL);
			  for(i=0;i<numConCompTemp;i++)
			  	ConCompListTemp[i]=NULL;
		  	  for(i=0;i<numConCompTemp-1;i++)
		  		ConCompListTemp[i]=ConCompList[i];
			  ConCompListTemp[numConCompTemp-1]=newConComp;
			  // delete original ConCompList;
			  *numConCompList=0;
			  delete [] ConCompList; ConCompList=NULL;
			  // copy ConCompListTemp to ConCompList;
			  *numConCompList=numConCompTemp; ConCompList=ConCompListTemp;
			  ConCompListTemp=NULL;	// recollect ConCompListTemp;
			  newConComp=NULL;	// recollect newConComp;
		  	}
		  else { delete [] newConComp; newConComp=NULL; }	// newConComp is already in ConCompList; delete newConComp;
		}
}

void CNet::resortConCompList(int **ConCompList, int *numConCompList)
{ // resort ConCompList according to the size;
	assert(ConCompList!=NULL); assert(numConCompList!=0);
	int i, j, k, range1, range2, *temp=NULL;
	for(i=1;i<*numConCompList;i++)
  		for(j=0;j<*numConCompList-1;j++)
  			{ // first calculate ConCompList[j][#] and ConCompList[j+1][#]'s size;
			  range1=range2=0;	
  			  for(k=0;k<getSize();k++)
  			  	{ if(ConCompList[j][k]!=-1) range1++;
  			  	  if(ConCompList[j+1][k]!=-1) range2++;
  			  	}
  			  if(range1<range2)
  			  	{ // exchange ConCompList[j] and ConCompList[j+1]
				  temp=ConCompList[j]; ConCompList[j]=ConCompList[j+1]; ConCompList[j+1]=temp;
				}
  			}
	temp=NULL;	// recollect temp;
}

void CNet::calBigestConComp(int **&ConCompList, int *numConCompList, int *sizeConCompList)
{ // calculate and store the biggest connected components;
  	int i, j, k, curnumNode;
	int *visit=new int [getSize()]; assert(visit!=NULL);  // visit[*] stores the results of visited nodes;stack for searching all nodes;
  	for(i=0;i<getSize();i++)
		visit[i]=0;

	// depth_first search from each node, try visiting all other nodes; if so, the network is connected;
  	*numConCompList=0;
  	for(i=0;i<getSize();i++)
  		{ // first, check if node i is in any connected components;
		  if(*numConCompList!=0)
		  	{ for(j=0;j<*numConCompList;j++)
  		 	 	{ for(k=0;k<getSize();k++)
  		  			{ if(ConCompList[j][k]==i) break;	// node i is in some sub connected components;
  		  			}
		  		  if(k!=getSize()) break;
  		  		}
		  	  if(j==*numConCompList)
			  	{ // search agent[i]'s subcluster;	
  		  		  depth_firstVisit(visit, getSize(), i);  // search the network;
  		  		  // calculate how many agent are visited;
  		  		  curnumNode=0;
  		  		  for(j=0;j<getSize();j++)
  				  	{ if(visit[j]==1) curnumNode++;
  				  	}
  				  if(curnumNode>1) updConCompList(visit, getSize(), ConCompList, numConCompList);	// component has at least 2 agents, update it into ConCompList;
		  		}
			}
		  else
		  	{ depth_firstVisit(visit, getSize(), i);  // search the network;
  		  	  // calculate how many agent are visited;
  		  	  curnumNode=0;
  		  	  for(j=0;j<getSize();j++)
  			  	{ if(visit[j]==1) curnumNode++;
  			  	}
  			  if(curnumNode>1) updConCompList(visit, getSize(), ConCompList, numConCompList);	// component has at least 2 agents, update it into ConCompList;
		  	}
  		}
	if(*numConCompList==0) *sizeConCompList=0;
	else
		{ resortConCompList(ConCompList, numConCompList);	// finally, resort the cluster with the size;
		  *sizeConCompList=0;
		  for(i=0;i<getSize();i++)
		  	{ if(ConCompList[0][i]!=-1) (*sizeConCompList)++;
		  	}
		}
	delete [] visit; visit=NULL;	// delete visit;
}

void CNet::setIndex(int type, int *index, int indexSize, int *range1, int *range2, int **ConCompList, int numConCompList, int sizeConCompList)
{ // set up index according to ConCompList; type=0, the whole group; type=1, only the biggest connected components;
	assert(((type==0)&&((ConCompList==NULL)&&(numConCompList==0)&&(sizeConCompList==0)))||((type==1)&&((ConCompList!=NULL)&&(numConCompList!=0)&&(sizeConCompList!=0)&&(sizeConCompList<getSize())))); 
	assert(index!=NULL);
	int i;
	for(i=0;i<indexSize;i++)
		index[i]=-1;
	
	if(type==0)
		{ *range1=0; *range2=getSize();
		  for(i=*range1;i<*range2;i++)
		  	index[i]=i;
		}
	else if(type==1)
		{ *range1=0; *range2=sizeConCompList;
		  for(i=*range1;i<*range2;i++)
		  	index[i]=ConCompList[0][i];
		}
}


// creating different networks;
void CNet::crtBasicNet()
{ // create different types of basic network;
	int i, j, k, m;
	int **RandCon=NULL;	// in random graph;
	
	switch(getBasicTyp())
		{ case -1: printf("Error, basicTyp=-1, No such Network!\n"); break;
		  case 0: printf("Building fully connected network:\n");	// fully connected network; 
				for(i=0;i<getSize();i++)
 	 				for(j=i+1;j<getSize();j++)
  						{ setAdjMatrixMember(i, j, getConWeiUp()); setAdjMatrixMember(j, i, getAdjMatrixMember(i, j)); }
				break;
		  case 1: printf("Building star network:\n");	// star network; node 0 is the star center; 
  	  	  		for(i=1;i<getSize();i++)
 	 				{ setAdjMatrixMember(i, 0, getConWeiUp()); setAdjMatrixMember(0, i, getAdjMatrixMember(i, 0)); }
				break;
		  case 2: printf("Building neighbor network:\n");	// neighbor network; 
  	  	  	 	for(i=1;i<getSize();i++)
  	  				{ setAdjMatrixMember(i, i-1, getConWeiUp()); setAdjMatrixMember(i-1, i, getAdjMatrixMember(i, i-1)); }
  	  	  		setAdjMatrixMember(0, getSize()-1, getConWeiUp()); setAdjMatrixMember(getSize()-1, 0, getAdjMatrixMember(0, getSize()-1));
				break;
		  case 3: printf("Building lace network:\n");	// lace network;
  	  	  		for(i=0;i<getSize();i++)
  	  	  			for(j=0;j<getSize();j++)
  	  	  				{ if(j==(i+getLaceR())%getSize()) { setAdjMatrixMember(i, j, getConWeiUp()); setAdjMatrixMember(j, i, getAdjMatrixMember(i, j)); }
  	  	  				}
				break;
		  case 4: printf("Building lattice network:\n");	// lattice network; 
  	  	  		for(i=0;i<getSize();i++)
  	  	  			{ for(j=i-(int)(getLattice()/_Twice);j<=i+(int)(getLattice()/_Twice);j++)
  	  	  				{ if(j!=i) { setAdjMatrixMember(i, (j+getSize())%getSize(), getConWeiUp()); setAdjMatrixMember((j+getSize())%getSize(), i, getAdjMatrixMember(i, (j+getSize())%getSize())); }
  	  	  				}
  	  	  			}
				break;
		  case 5: printf("Building wheel network:\n");	// wheel network; node 0 is the center of the wheel, other nodes around it;
		  		for(i=1;i<getSize();i++)
		  			{ setAdjMatrixMember(0, i, getConWeiUp()); setAdjMatrixMember(i, 0, getAdjMatrixMember(0, i)); }
		  		for(j=1;j<getSize()-1;j++)
		  			{ setAdjMatrixMember(j, (j+1)%getSize(), getConWeiUp()); setAdjMatrixMember((j+1)%getSize(), j, getAdjMatrixMember(j, (j+1)%getSize())); }
		  		setAdjMatrixMember(1, getSize()-1, getConWeiUp()); setAdjMatrixMember(getSize()-1, 1, getAdjMatrixMember(1, getSize()-1));
		  		break;
		  case 6: printf("Building regular network:\n");	// regular network;
		  		for(i=0;i<getSize();i++)
  	  	  			for(j=i+1;j<i+1+getAvgDegree();j++)
  	  	  				{ setAdjMatrixMember(i, j%getSize(), getConWeiUp()); setAdjMatrixMember(j%getSize(), i, getAdjMatrixMember(i, j%getSize())); }
		  		break;
		  case 7: printf("Building directional hierarchy network:\n");	// directional hierarchy network 
		  		// two types;
			 	// 1) directional network, upper triangle matrix;
  	  	  		for(i=0;i<getSize();i++)
  	  	  			for(j=i+1;j<getSize();j++)
  	  	  				setAdjMatrixMember(i, j, getConWeiUp());
		  		/*
		  		// 2) regular directional network
		  		for(i=0;i<getSize();i++)
  	  	  			for(j=i+1;j<i+1+getEdgePerNode();j++)
  	  	  				setAdjMatrixMember(i, j%getSize(), getConWeiUp());
  	  	  		*/
  	  	  		break;
		  case 8: printf("Building random network:\n");	// random graph; 
		  		// two ways, 1) total random graph; 2) random graph with same _AvgDegree;
		  		/*
  	  	  		// 1) total random graph;
		  		do{ EmpAdjMatrix();	// empty m_ppAdjMatrix; 	
					for(i=0;i<getSize();i++)
 	 					for(j=i+1;j<getSize();j++)
  							{ setAdjMatrixMember(i, j, (FLOAT_SM_EQ(Rand0_1, _Half))?getConWeiUp():getConWeiLow()); setAdjMatrixMember(j, i, getAdjMatrixMember(i, j)); }
 		  		}while(chkCon(getSize())==1);  // network is separated, rebuild!
				*/
				
				// 2) random graph with same _AvgDegree;
  	  	  		// initialize RandCon;
				RandCon=new int * [(int)(getAvgDegree()*getSize()/_Twice)]; assert(RandCon!=NULL);
				for(i=0;i<(int)(getAvgDegree()*getSize()/_Twice);i++)
					{ RandCon[i]=new int [2]; assert(RandCon[i]!=NULL); 
					  for(j=0;j<2;j++)
  	  	  				RandCon[i][j]=-1;
					}
  			  			
  	  	  		do { EmpAdjMatrix();	// empty m_ppAdjMatrix;
					// empty RandCon;
					for(i=0;i<(int)(getAvgDegree()*getSize()/_Twice);i++)
  	  	  				for(j=0;j<2;j++)
  	  	  					RandCon[i][j]=-1;
  	  	  	  		// random select connections;
			  		k=0;
  	  	  	  		do{ do{ i=(int)(Rand0_1*getSize()); j=(int)(Rand0_1*getSize());
  	  	  	  	 		}while((i==getSize())||(j==getSize())||(i==j));
  	  	  	  			for(m=0;m<k;m++)
  	  	 		 	  		{ if(((RandCon[m][0]==i)&&(RandCon[m][1]==j))||((RandCon[m][0]==j)&&(RandCon[m][1]==i)))
  	  	 		 	  			break;
  	  			  	  		}
  	  			  	  	if(m==k) { RandCon[k][0]=i; RandCon[k][1]=j; k++; }	// new connection;
  	 		 	  	}while(k<(int)(getAvgDegree()*getSize()/_Twice));
  	  	  	  		// copy connections to naturalmatrix;
  	  	  	  		for(i=0;i<(int)(getAvgDegree()*getSize()/_Twice);i++)
  			  	  		{ setAdjMatrixMember(RandCon[i][0], RandCon[i][1], getConWeiUp()); setAdjMatrixMember(RandCon[i][1], RandCon[i][0], getAdjMatrixMember(RandCon[i][0], RandCon[i][1])); }
  			  	}while(chkCon(getSize())==1);  	  
				// delete RandCon;
				for(i=0;i<(int)(getAvgDegree()*getSize()/_Twice);i++)
					{ delete [] RandCon[i]; RandCon[i]=NULL; }
				delete [] RandCon; RandCon=NULL;
				break;
		  default: break;		
		}  	  
}

void CNet::crtSFnet()
{ // Scale-free network;
	int i, localView, edgePerNode;
	double **Local=new double * [getSize()]; assert(Local!=NULL);	// store nodes that current agent can see, local[*][0] stores the index of that node, local[*][1] stores the degrees of that node;
	for(i=0;i<getSize();i++)
		{ Local[i]=new double [2]; assert(Local[i]!=NULL);
		  Local[i][0]=-1.0; Local[i][1]=0.0;
		}

	printf("Building Scale-free network:\n");
	do{ // reinitialize m_ppAdjMatrix and Local;
		EmpAdjMatrix();
  	 	for(i=0;i<getSize();i++)
 		 	{ Local[i][0]=-1.0; Local[i][1]=0.0; }
		setAdjMatrixMember(0, 1, getConWeiUp()); setAdjMatrixMember(1, 0, getAdjMatrixMember(0, 1));	// start with 2 nodes, 1 edge;
  	  	for(i=2;i<getSize();i++)
  	  		{ localView=getLocalView(); edgePerNode=getEdgePerNode();	// in scale-free network, localview is the whole number of previous nodes;
  	  		  initDeg(Local, getSize(), 2, &localView, &edgePerNode, i);	// update current degree distribution;
  			  selNewCon(Local, getSize(), 2, &localView, &edgePerNode, i);	// decide the new nodes connection;
  			}
  	  }while(chkCon(getSize())==1);
	// delete Local; 
	for(i=0;i<getSize();i++)
		{ delete [] Local[i]; Local[i]=NULL; }
	delete [] Local; Local=NULL;
}

void CNet::crtSWnet()
{ // Small world network; Two method: 1) Rewiring method; 2) Adding new wires;
	int i, j, k, newNode;	// used for rewiring to build up small world network;

	printf("Building Small world network:\n");
	// 1) Rewiring method;
  	do{ // first create a lattice network;
		EmpAdjMatrix();
		// first, build up a lattice;	
	  	for(i=0;i<getSize();i++)
  	  		{ for(j=i-(int)(getLattice()/_Twice);j<=i+(int)(getLattice()/_Twice);j++)
  	  			{ if(j!=i) { setAdjMatrixMember(i, (j+getSize())%getSize(), getConWeiUp()); setAdjMatrixMember((j+getSize())%getSize(), i, getAdjMatrixMember(i, (j+getSize())%getSize())); }
	  	 		}
  	  		}
	  	// then rewiring;
	  	for(i=0;i<getSize();i++)
	  		{ for(j=i-(int)(getLattice()/_Twice);j<=i+(int)(getLattice()/_Twice);j++)
	  			{ if((j!=i)&&(FLOAT_EQ(getAdjMatrixMember(i, (j+getSize())%getSize()), getConWeiUp())))
	  				{ if(FLOAT_SM_EQ(Rand0_1, getReWire()))
		  				{ do{ do{ newNode=(int)(getSize()*Rand0_1);
		  	  			  	  }while((newNode==getSize())||(newNode==i)||(FLOAT_EQ(getAdjMatrixMember(i, newNode), getConWeiUp())));
		  				  	  // check if this new node is still in current neighbors;
		  				  	  for(k=i-(int)(getLattice()/_Twice);k<=i+(int)(getLattice()/_Twice);k++)
		  				  	  	{ if((k!=i)&&(newNode==(k+getSize())%getSize())) break;
		  				  	  	}
		  				  }while(k!=i+(int)(getLattice()/_Twice)+1);
		         			  // rewire!
			  			  setAdjMatrixMember(i, (j+getSize())%getSize(), getConWeiUp()); setAdjMatrixMember((j+getSize())%getSize(), i, getAdjMatrixMember(i, (j+getSize())%getSize()));  // delete this connection;
  		  	  			  setAdjMatrixMember(i, newNode, getConWeiUp()); setAdjMatrixMember(newNode, i, getAdjMatrixMember(i, newNode));  // add new connection;	
		  				}
	  				}
	  			}
	  	 	}
	}while(chkCon(getSize())==1);  // network is splited, rebuild;
	/*
	// 2) Adding new wires;
	// first, build up a lattice;
	EmpAdjMatrix();
	for(i=0;i<getSize();i++)
  	 	{ for(j=i-(int)(getLattice()/_Twice);j<=i+(int)(getLattice()/_Twice);j++)
  	    		{ if(j!=i) { setAdjMatrixMember(i, (j+getSize())%getSize(), getConWeiUp()); setAdjMatrixMember((j+getSize())%getSize(), i, getAdjMatrixMember(i, (j+getSize())%getSize())); }
	  	 	}
  	    	}
	// then, adding new wires with probability _AddWireProbability;
	for(i=0;i<getSize();i++)
	  	for(j=i+1;j<getSize();j++)
	  		{ if(FLOAT_EQ(getAdjMatrixMember(i, j), getConWeiLow()))
	  			{ if(FLOAT_SM_EQ(Rand0_1, getAddWireProb()))
	  				{ setAdjMatrixMember(i, j, getConWeiUp()); setAdjMatrixMember(j, i, getAdjMatrixMember(i, j)); }  // add a new edge!
	  			}
	  		}
	*/
}

void CNet::crtLWnet()
{ // Local world network;
	int i, localView, edgePerNode;
	double **Local=new double * [getSize()]; assert(Local!=NULL);	// store nodes that current agent can see, local[*][0] stores the index of that node, local[*][1] stores the degrees of that node;
	for(i=0;i<getSize();i++)
		{ Local[i]=new double [2]; assert(Local[i]!=NULL);
		  Local[i][0]=-1.0; Local[i][1]=0.0;
		}

	printf("Building Local world network:\n");
	do{ // reinitialize m_ppAdjMatrix and Local;
		EmpAdjMatrix();
  	 	for(i=0;i<getSize();i++)
 		 	{ Local[i][0]=-1.0; Local[i][1]=0.0; } 
  	 	setAdjMatrixMember(0, 1, getConWeiUp()); setAdjMatrixMember(1, 0, getAdjMatrixMember(0, 1));	// start with 2 nodes, 1 edge;
  	  	for(i=2;i<getSize();i++)
	  	  	{ localView=getLocalView(); edgePerNode=getEdgePerNode();  // in local world network, localview>=edgpernode; 	
  		  	  initDeg(Local, getSize(), 2, &localView, &edgePerNode, i); // initialize the local;
  		  	  selNewCon(Local, getSize(), 2, &localView, &edgePerNode, i); // decide the new nodes connection;
  		  	}
  	}while(chkCon(getSize())==1);  // network is splited, rebuild;
  	// delete Local; 
	for(i=0;i<getSize();i++)
		{ delete [] Local[i]; Local[i]=NULL; }
	delete [] Local; Local=NULL;
}

void CNet::crtExpnet()
{ // Exponential network;
	int i, localView, edgePerNode;
	double **Local=new double * [getSize()]; assert(Local!=NULL);	// store nodes that current agent can see, local[*][0] stores the index of that node, local[*][1] stores the degrees of that node;
	for(i=0;i<getSize();i++)
		{ Local[i]=new double [2]; assert(Local[i]!=NULL);
		  Local[i][0]=-1.0; Local[i][1]=0.0;
		}

	printf("Building Exponential network:\n");
	do{ // reinitialize m_ppAdjMatrix and Local;
		EmpAdjMatrix();
  	 	for(i=0;i<getSize();i++)
 		 	{ Local[i][0]=-1.0; Local[i][1]=0.0; } 
  	 	setAdjMatrixMember(0, 1, getConWeiUp()); setAdjMatrixMember(1, 0, getAdjMatrixMember(0, 1));	// start with 2 nodes, 1 edge;
  	  	for(i=2;i<getSize();i++)
	  	  	{ localView=getLocalView(); edgePerNode=getEdgePerNode();  // in local world network, localview>=edgpernode; 	
  		  	  initDeg(Local, getSize(), 2, &localView, &edgePerNode, i); // initialize the local;
  		  	  selNewCon(Local, getSize(), 2, &localView, &edgePerNode, i); // decide the new nodes connection;
  		  	}
  	}while(chkCon(getSize())==1);  // network is splited, rebuild;
  	// delete Local; 
	for(i=0;i<getSize();i++)
		{ delete [] Local[i]; Local[i]=NULL; }
	delete [] Local; Local=NULL;
}

// creating Cooper-Frieze network;
int CNet::calCurEdge(int netsize)
{ // calculate current netsize nodes' edges;
	assert((0<netsize)&&(netsize<=getSize()));
	int i, j;
	int edge=0;
  	for(i=0;i<netsize;i++)
  		for(j=i+1;j<netsize;j++)
  			{ if((FLOAT_EQ(getAdjMatrixMember(i, j), getConWeiUp()))||(FLOAT_EQ(getAdjMatrixMember(j, i), getConWeiUp()))) edge++; }
	return edge;	
}

int CNet::genEdge(int netsize, int mode)
{ // generate new edges in Cooper-Frieze network; mode=0, OLD process; 1, NEW process;
	assert((0<netsize)&&(netsize<getSize())); assert((mode==0)||(mode==1));
	int i, curEdge, leftEdge, genedEdge;  // store current number of edges;
	double rannum;
	double *p=new double [getNumAddEdge()]; assert(p!=NULL);  // store probability that new node generates i new edges;
	for(i=0;i<getNumAddEdge();i++)
  		p[i]=0.0;
	// according to different mode;
	leftEdge=-1;
  	if(mode==0)
  		{ curEdge=calCurEdge(netsize);  // calculate how many current edges;
		  leftEdge=(int)((netsize)*(netsize-1)/_Twice)-curEdge;
		  if(leftEdge>=getNumAddEdge()) leftEdge=getNumAddEdge();
		}
 	else if(mode==1)
  		{ if(netsize>getNumAddEdge()) leftEdge=getNumAddEdge();
  	  	  else leftEdge=netsize-1;
  		}
  	// decide numEdge;
  	for(i=0;i<leftEdge;i++)
 		p[i]=1.0/double(leftEdge);
  	for(i=1;i<leftEdge;i++)
  		p[i]+=p[i-1];
  	// decide how many new edges this new added vertex has;
  	genedEdge=-1; rannum=Rand0_1;
  	if(FLOAT_SM_EQ(rannum, p[0])) genedEdge=1;
	else if(FLOAT_EQ(rannum, 1.0)) genedEdge=leftEdge;
  	else
  		{ for(i=1;i<leftEdge;i++)
			{ if((FLOAT_BG(rannum, p[i-1]))&&(FLOAT_SM_EQ(rannum, p[i]))) { genedEdge=i+1; break; }
  			}
  		}
	delete [] p; p=NULL;	// delete p;
	return genedEdge;
}

void CNet::calCurDeg(double **Local, int locSize1, int locSize2, int netsize, int mode, int curEdge)
{ // calclate current nodes' edges; mode=-1, undirected degrees; 0, directed out-degree; 1, directed in-degree;
	assert(Local!=NULL); assert((0<netsize)&&(netsize<getSize())); assert((mode==-1)||(mode==0)||(mode==1));
	int i, j, cur, selnode;
  	double allDeg;
  	// randomize sequence of nodes;
  	cur=0;
  	for(i=0;i<netsize;i++)
    		{ // select local view nodes;
		  do{ do{ selnode=(int)(Rand0_1*netsize);
  	   	  	 }while(selnode==netsize);
	  	  	 for(j=0;j<cur;j++)
			  	{ if(FLOAT_EQ(Local[j][0], (double)(selnode))) break;
				}
		  }while(j!=cur);
    		  Local[cur][0]=(double)selnode;
    		  cur++;
  		}
  	// calculate their degrees;
  	for(i=0;i<netsize;i++)
  		{ if(mode==-1)
  			{ for(j=0;j<netsize;j++)
 	  		 	{ if(FLOAT_NE(getAdjMatrixMember((int)(Local[i][0]), j), getConWeiLow())) Local[i][1]+=getAdjMatrixMember((int)(Local[i][0]), j); }  // calculate degree;
  			}
  	  	  else if(mode==0)
  		  	{ for(j=0;j<netsize;j++)
  		  		{ if(FLOAT_NE(getAdjMatrixMember((int)(Local[i][0]), j), getConWeiLow())) Local[i][1]+=getAdjMatrixMember((int)(Local[i][0]), j); } // calculate out-degree;
 	 	  	}
  		  else if(mode==1)
  		  	{ for(j=0;j<netsize;j++)
  		  		{ if(FLOAT_NE(getAdjMatrixMember(j, (int)(Local[i][0])), getConWeiLow())) Local[i][1]+=getAdjMatrixMember(j, (int)(Local[i][0])); }  // calculate in-degree;
  		  	}
		}
  	// calculate all degree and degree distribution;
  	if(mode==-1)
  		{ for(i=0;i<netsize;i++)
 		  	{ if(FLOAT_EQ(Local[i][1], 0.0)) Local[i][1]+=getAdjWei();
			}
  		}
  	else if(mode==0)
  		{ for(i=0;i<netsize;i++)
  			Local[i][1]=(Local[i][1]+getSetaOUT())/(double)(curEdge+getSetaOUT()*netsize);
  		}
  	else if(mode==1)
  		{ for(i=0;i<netsize;i++)
 	 		Local[i][1]=(Local[i][1]+getSetaIN())/(double)(curEdge+getSetaIN()*netsize);
  		}
  
  	allDeg=0.0;
  	for(j=0;j<netsize;j++)
  		allDeg+=Local[j][1];
  	for(j=1;j<netsize;j++)
  		Local[j][1]+=Local[j-1][1];
  	for(j=0;j<netsize;j++)
  		Local[j][1]/=allDeg;
}

void CNet::selEdge(int numEdge, int netsize, int mode)
{ // in OLD process, selecte edges according to 4 conditions;
  // mode=1, initial node is chosen uniformly; terminal node is chosen uniformly;
  // mode=2, initial node is chosen uniformly; terminal node is chosen according to their degrees;
  // mode=3, initial node is chosen according to their degrees; terminal node is chosen uniformly;
  // mode=4, initial node is chosen according to their degrees; terminal node is chosen according to their degrees;
  // in NEW process, select edges according to 2 conditions;
  // mode=5, terminal nodes are chosen uniformly;
  // mode=6, terminal nodes are chosen according to their degrees;
	assert((0<netsize)&&(netsize<getSize())); assert((1<=mode)&&(mode<=6));
  	int i, j, startNode, endNode;
  	double rannum1, rannum2;
  	double **Local=new double * [getSize()]; assert(Local!=NULL);	// store nodes that current agent can see, local[*][0] stores the index of that node, local[*][1] stores the degrees of that node;
	for(i=0;i<getSize();i++)
		{ Local[i]=new double [2]; assert(Local[i]!=NULL); 
		  Local[i][0]=-1.0; Local[i][1]=0.0; 
		}

	switch(mode)
		{ case 1: for(i=0;i<numEdge;i++)
  					{ // select initial node and terminal node uniformly;
					  do{ startNode=(int)(Rand0_1*netsize); endNode=(int)(Rand0_1*netsize);
  					  }while((startNode==netsize)||(endNode==netsize)||(startNode==endNode)||(FLOAT_EQ(getAdjMatrixMember(startNode, endNode), getConWeiUp())));
  					  setAdjMatrixMember(startNode, endNode, getConWeiUp()); setAdjMatrixMember(endNode, startNode, getAdjMatrixMember(startNode, endNode));
  					}
  				  break;
		  case 2: calCurDeg(Local, getSize(), 2, netsize); // initialize degre local;
  		  		  for(i=0;i<numEdge;i++)
  					{ // select initial node uniformly;
  					  do{ startNode=(int)(Rand0_1*netsize); 
  					  }while(startNode==netsize);
  					  endNode=-1; rannum2=Rand0_1;
				   	  if((FLOAT_SM_EQ(rannum2, Local[0][1]))&&(((int)(Local[0][0]))!=startNode)&&(FLOAT_EQ(getAdjMatrixMember(startNode, (int)(Local[0][0])), getConWeiLow()))) endNode=(int)(Local[0][0]);
					  else if((FLOAT_EQ(rannum2, 1.0))&&((int)(Local[netsize-1][0])!=startNode)&&(FLOAT_EQ(getAdjMatrixMember(startNode, (int)(Local[netsize-1][0])), getConWeiLow()))) endNode=(int)(Local[netsize-1][0]); 
					  else
				   	  	{ for(j=1;j<netsize;j++)
		 		  	  		{ if((FLOAT_BG(rannum2, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum2, Local[j][1]))&&((int)(Local[j][0])!=startNode)&&(FLOAT_EQ(getAdjMatrixMember(startNode, (int)(Local[j][0])), getConWeiLow()))) { endNode=(int)(Local[j][0]); break; }
	   			 	 		}
		  		 	  	}
				   	  if(endNode==-1) i--;
				   	  else { setAdjMatrixMember(startNode, endNode, getConWeiUp()); setAdjMatrixMember(endNode, startNode, getAdjMatrixMember(startNode, endNode)); }
  					}
  				  break;
		  case 3: calCurDeg(Local, getSize(), 2, netsize); // initialize degree local;
 	 	  		  for(i=0;i<numEdge;i++)
  					{ // select end node uniformly;
  					  do{ endNode=(int)(Rand0_1*netsize); 
  					  }while(endNode==netsize);
 		 			  startNode=-1; rannum1=Rand0_1;
				   	  if((FLOAT_SM_EQ(rannum1, Local[0][1]))&&(((int)(Local[0][0]))!=endNode)&&(FLOAT_EQ(getAdjMatrixMember((int)(Local[0][0]), endNode), getConWeiLow()))) startNode=(int)(Local[0][0]);
					  else if((FLOAT_EQ(rannum1, 1.0))&&((int)(Local[netsize-1][0])!=endNode)&&(FLOAT_EQ(getAdjMatrixMember((int)(Local[netsize-1][0]), endNode), getConWeiLow()))) startNode=(int)(Local[netsize-1][0]);
					  else
				   	  	{ for(j=1;j<netsize;j++)
				   	  		{ if((FLOAT_BG(rannum1, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum1, Local[j][1]))&&((int)(Local[j][0])!=endNode)&&(FLOAT_EQ(getAdjMatrixMember((int)(Local[j][0]), endNode), getConWeiLow()))) { startNode=(int)(Local[j][0]); break; }
				   	  		}
				   	  	}
				   	  if(startNode==-1) i--;
				   	  else { setAdjMatrixMember(startNode, endNode, getConWeiUp()); setAdjMatrixMember(endNode, startNode, getAdjMatrixMember(startNode, endNode)); }
 	 				}
				  break;
		  case 4: calCurDeg(Local, getSize(), 2, netsize); // initialize out-degree local;
				  for(i=0;i<numEdge;i++)
				  	{ startNode=-1; rannum1=Rand0_1;
				      if(FLOAT_SM_EQ(rannum1, Local[0][1])) startNode=(int)(Local[0][0]);
 					  else if(FLOAT_EQ(rannum1, 1.0)) startNode=(int)(Local[netsize-1][0]);
					  else
				        { for(j=1;j<netsize;j++)
		 		        	{ if((FLOAT_BG(rannum1, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum1, Local[j][1]))) { startNode=(int)(Local[j][0]); break; }
		 		        	}
		 		        }
					  endNode=-1; rannum2=Rand0_1;
					  if(FLOAT_SM_EQ(rannum2, Local[0][1])) endNode=(int)(Local[0][0]);
					  else if(FLOAT_EQ(rannum2, 1.0)) endNode=(int)(Local[netsize-1][0]);
				      else
				       	{ for(j=1;j<netsize;j++)
		   		    		{ if((FLOAT_BG(rannum2, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum2, Local[j][1]))) { endNode=(int)(Local[j][0]); break; }
		  		     		}
				       	}
				      if((startNode==endNode)||(FLOAT_EQ(getAdjMatrixMember(startNode, endNode), getConWeiUp()))) i--;
				      else { setAdjMatrixMember(startNode, endNode, getConWeiUp()); setAdjMatrixMember(endNode, startNode, getAdjMatrixMember(startNode, endNode)); }
				  	}
				  break;
		  case 5: // terminal nodes are chosen uniformly;
		  		  if(netsize==1) { setAdjMatrixMember(netsize, 0, getConWeiUp()); setAdjMatrixMember(0, netsize, getAdjMatrixMember(netsize, 0)); }  
				  else
				  	{ for(i=0;i<numEdge;i++)
					 	{ do{ endNode=(int)(Rand0_1*netsize);	
						  }while(endNode==netsize);
	 		 			  if(FLOAT_EQ(getAdjMatrixMember(netsize, endNode), getConWeiUp())) i--;
			 			  else { setAdjMatrixMember(netsize, endNode, getConWeiUp()); setAdjMatrixMember(endNode, netsize, getAdjMatrixMember(netsize, endNode)); }
			  			}
					}
				  break;
		  case 6: // terminal nodes are chosen according to their current degree;
 		 		  if(netsize==1) { setAdjMatrixMember(netsize, 0, getConWeiUp()); setAdjMatrixMember(0, netsize, getAdjMatrixMember(netsize, 0)); }
				  else
				  	{ calCurDeg(Local, getSize(), 2, netsize); // initialize degree local;
				  	  for(i=0;i<numEdge;i++)
					  	{ endNode=-1; rannum2=Rand0_1;
				   		  if((FLOAT_SM_EQ(rannum2, Local[0][1]))&&(FLOAT_EQ(getAdjMatrixMember(netsize, (int)(Local[0][0])), getConWeiLow()))) endNode=(int)(Local[0][0]);
						  else if((FLOAT_EQ(rannum2, 1.0))&&(FLOAT_EQ(getAdjMatrixMember(netsize, (int)(Local[netsize-1][0])), getConWeiLow()))) endNode=(int)(Local[netsize-1][0]);
						  else
				   		  	{ for(j=1;j<netsize;j++)
				   		  		{ if((FLOAT_BG(rannum2, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum2, Local[j][1]))&&(FLOAT_EQ(getAdjMatrixMember(netsize, (int)(Local[j][0])), getConWeiLow()))) { endNode=(int)(Local[j][0]); break; }
				   		  		}
					   	  	}
				   		  if(endNode==-1) i--;
				   		  else { setAdjMatrixMember(netsize, endNode, getConWeiUp()); setAdjMatrixMember(endNode, netsize, getAdjMatrixMember(netsize, endNode)); }
				  		}
 		 			}
				  break;
		  default: break;		  
		}
  	// delete Local; 
	for(i=0;i<getSize();i++)
		{ delete [] Local[i]; Local[i]=NULL; }
	delete [] Local; Local=NULL;
}

void CNet::crtCFnet()
{ // Cooper-Frieze network;
	int netsize, numEdge;
	double rannum1, rannum2;

	printf("Building Cooper-Frieze network:\n");
	do{ EmpAdjMatrix(); netsize=1;  // initially, there is 1 node;
	  	do{ if((netsize!=1)&&(FLOAT_SM_EQ(Rand0_1, getAlfaCF())))
	  			{ // OLD process; decide the probability that generate i new edges; in all it currently has at most (netsize)*(netsize-1)/_Twice edges;
				  numEdge=genEdge(netsize, 0);
				  rannum1=Rand0_1; rannum2=Rand0_1;
				  if((FLOAT_SM_EQ(rannum1, getSetaCF()))&&(FLOAT_SM_EQ(rannum2, getGamaCF()))) selEdge(numEdge, netsize, 1);  // initial node is chosen uniformly; terminal node is chosen uniformly;
				  else if((FLOAT_SM_EQ(rannum1, getSetaCF()))&&(FLOAT_BG(rannum2, getGamaCF()))) selEdge(numEdge, netsize, 2);  // initial node is chosen uniformly; terminal node is chosen according to their degrees;
				  else if((FLOAT_BG(rannum1, getSetaCF()))&&(FLOAT_SM_EQ(rannum2, getGamaCF()))) selEdge(numEdge, netsize, 3);  // initial node is chosen according to their degrees; terminal node is chosen uniformly;
				  else if((FLOAT_BG(rannum1, getSetaCF()))&&(FLOAT_BG(rannum2, getGamaCF()))) selEdge(numEdge, netsize, 4);  // initial node is chosen according to their degrees; terminal node is chosen according to their degrees;			 
	  			}
		  	else
	  		  	{ // NEW process; decide the probability that new node generate i new edges;
				  numEdge=genEdge(netsize, 1);
				  if(FLOAT_SM_EQ(Rand0_1, getBetaCF())) selEdge(numEdge, netsize, 5);  // terminal nodes are chosen uniformly;
				  else selEdge(numEdge, netsize, 6);  // terminal nodes are chosen according to their in-degrees;
				}
			netsize++;
	  	}while(netsize<getSize());
  	  }while(chkCon(getSize())==1);
}

// creating Directed Scale-free network;
void CNet::builDSFaction(int netsize, int step, int mode)
{ // build up Directed scale-free network;
  // mode=1, add a new vertex v together with an edge from v to an existing vertex w, where w is chosen according to din+_SetaIN;
  // mode=2, add an edge from an existing vertex v to an existing vertex w, where v and w are chosen independently, v according to dout+_SetaOUT and w according to din+_SetaIN;
  // mode=3, add a new vertex w and an edge from an existing vertex v to w, where v is chosen according to dout+_SetaOUT;
	assert((0<netsize)&&(netsize<getSize())); assert((mode==1)||(mode==2)||(mode==3));
  	int i, j, startNode, endNode;
  	double rannum1, rannum2, **pIN=NULL, **pOUT=NULL;	// pIN/OUT[*][0] stores the index of that node, pIN/OUT[*][1] stores its in/out-degrees;
	pIN=new double * [getSize()]; assert(pIN!=NULL);
	pOUT=new double * [getSize()]; assert(pOUT!=NULL);
	for(i=0;i<getSize();i++)
		{ pIN[i]=new double [2]; assert(pIN[i]!=NULL); 
		  pOUT[i]=new double [2]; assert(pOUT[i]!=NULL); 
		  pIN[i][0]=pOUT[i][0]=-1.0; pIN[i][1]=pOUT[i][1]=0.0; 
		}
  	
  	if(mode==1)
  		{ // add a new vertex v with an edge from v to an existing vertex w, where w is chosen according to its din+_SetaIN;
  	  	  if(netsize==1) setAdjMatrixMember(netsize, 0, getConWeiUp());
		  else
		  	{ calCurDeg(pIN, getSize(), 2, netsize, 1, step);
		  	  // decide how to select w;
	  	  	  do{ rannum2=Rand0_1; endNode=-1;
		 	 	 if(FLOAT_SM_EQ(rannum2, pIN[0][1])) endNode=(int)(pIN[0][0]);
				 else if(FLOAT_EQ(rannum2, 1.0)) endNode=(int)(pIN[netsize-1][0]);
		 	 	 else
	 	 			{ for(j=1;j<netsize;j++)
	  					{ if((FLOAT_BG(rannum2, pIN[j-1][1]))&&(FLOAT_SM_EQ(rannum2, pIN[j][1]))) { endNode=(int)(pIN[j][0]); break; }
	  					}
	 	 			}
	  	  	  }while(endNode==-1);
	  	  	  setAdjMatrixMember(netsize, endNode, getConWeiUp());
  			}
  		}
  	else if(mode==2)
  		{ // add an edge from an existing vertex v to an existing vertex w, where v and w are chosen independently, v according to dout+_SetaOUT and w according to din+_SetaIN;
		  if(netsize==2) { setAdjMatrixMember(1, 0, getConWeiUp()); setAdjMatrixMember(0, 1, getConWeiUp()); }
		  else if(netsize!=1)
		  	{ calCurDeg(pOUT, getSize(), 2, netsize, 0, step); calCurDeg(pIN, getSize(), 2, netsize, 1, step);
   	  	  	  do{ rannum1=Rand0_1; rannum2=Rand0_1; startNode=endNode=-1;
   	  		 	if(FLOAT_SM_EQ(rannum1, pOUT[0][1])) startNode=(int)(pOUT[0][0]);
				else if(FLOAT_EQ(rannum1, 1.0)) startNode=(int)(pOUT[netsize-1][0]);
		 		else
		  			{ for(j=1;j<netsize;j++)
	  					{ if((FLOAT_BG(rannum1, pOUT[j-1][1]))&&(FLOAT_SM_EQ(rannum1, pOUT[j][1]))) { startNode=(int)(pOUT[j][0]); break; }
	  					}
	  				}
				 if(FLOAT_SM_EQ(rannum2, pIN[0][1])) endNode=(int)(pIN[0][0]);
				 else if(FLOAT_EQ(rannum2, 1.0)) endNode=(int)(pIN[netsize-1][0]);
				 else
		 		 	{ for(j=1;j<netsize;j++)
		  				{ if((FLOAT_BG(rannum2, pIN[j-1][1]))&&(FLOAT_SM_EQ(rannum2, pIN[j][1]))) { endNode=(int)(pIN[j][0]); break; }
		  				}
		  			}
   		  	  }while((startNode==-1)||(endNode==-1)||(startNode==endNode)||(FLOAT_EQ(getAdjMatrixMember(startNode, endNode), getConWeiUp())));
   		  	  setAdjMatrixMember(startNode, endNode, getConWeiUp());
		  	}
  		}
  	else if(mode==3)
  		{ // add a new vertex w and an edge from an existing vertex v to w, where v is chosen according to dout+_SetaOUT;
		  if(netsize==1) setAdjMatrixMember(0, netsize, getConWeiUp());
		  else
		  	{ calCurDeg(pOUT, getSize(), 2, netsize, 0, step);
	  	  	  // decide how to select w;
	  	  	  do{ rannum1=Rand0_1; startNode=-1;
		 	 	 if(FLOAT_SM_EQ(rannum1, pOUT[0][1])) startNode=(int)(pOUT[0][0]);
				 else if(FLOAT_EQ(rannum1, 1.0)) startNode=(int)(pOUT[netsize-1][0]);
		 	 	 else
		  			{ for(j=1;j<netsize;j++)
	 	 				{ if((FLOAT_BG(rannum1, pOUT[j-1][1]))&&(FLOAT_SM_EQ(rannum1, pOUT[j][1]))) { startNode=(int)(pOUT[j][0]); break; }
	  					}
	  				}
	  	  	  }while(startNode==-1);
	  	  	  setAdjMatrixMember(startNode, netsize, getConWeiUp());
	  		}
  		}
	// delete pIN, pOUT;
	for(i=0;i<getSize();i++)
		{ delete [] pIN[i]; pIN[i]=NULL; delete [] pOUT[i]; pOUT[i]=NULL; }
	delete [] pIN; pIN=NULL; delete [] pOUT; pOUT=NULL;
}

void CNet::crtDSFnet()
{ // Directed Scale-free network;
	int netsize;
	double rannum;

	printf("Building Directed Scale-free network:\n");
	do{ // initialize naturalmatrix;
		EmpAdjMatrix(); netsize=1;  // initially, there is 1 node;
		do{ // at time step t, there ar exactly t edges; 
	  		rannum=Rand0_1;  // decide which action to take;
	  		if(FLOAT_SM_EQ(rannum, getAlfaDS())) { builDSFaction(netsize, netsize-1, 1); netsize++; }  // action 1;
	  		else if((FLOAT_BG(rannum, getAlfaDS()))&&(FLOAT_SM_EQ(rannum, getBetaDS()))) builDSFaction(netsize, netsize-1, 2);  // action 2;
	  		else if((FLOAT_BG(rannum, getBetaDS()))&&(FLOAT_SM_EQ(rannum, getGamaDS()))) { builDSFaction(netsize, netsize-1, 3); netsize++; }  // action 3;
	  	}while(netsize<getSize());
	}while(chkCon(getSize())==1);
}

// creating Multiple Local world network;
void CNet::setLocalWorld(int *numlocal, double *curlocalset, int size, double **Localset, int size1, int size2, int mode)
{ // decide the probability of choosing existing local world; mode=0, based on creating time; 1, based on inner edges; 
	assert(numlocal!=NULL); assert(curlocalset!=NULL); assert(Localset!=NULL); assert((mode==0)||(mode==1));
	int i;
  	double allmag;
  	if(mode==0)
  		{ // based on creating time;
  	  	  for(i=0;i<*numlocal;i++)
  		  	curlocalset[i]=Localset[i][0];
  		}
  	else if(mode==1)
  		{ // based on inner edges;
  		  for(i=0;i<*numlocal;i++)
  		  	curlocalset[i]=Localset[i][1];
  		}
  	allmag=0.0;
  	for(i=0;i<*numlocal;i++)
  		{ if(FLOAT_EQ(curlocalset[i], 0.0)) curlocalset[i]=1.0;
  		  allmag+=curlocalset[i];
  		}
  	for(i=1;i<*numlocal;i++)
  		curlocalset[i]+=curlocalset[i-1];
  	for(i=0;i<*numlocal;i++)
 	 	curlocalset[i]/=allmag;
}

void CNet::selConNode(int selLocal, int netsize, int *numlocal, int *selNode1, int *selNode2, int mode, double **LocalRec, int size3, int size4, int *m)
{ // select nodes to connect in one local world; mode=1, select one node based on its degree; 2/3, select m nodes based on its degree; 
	assert((0<netsize)&&(netsize<getSize())); assert(numlocal!=NULL); assert((selNode1!=NULL)&&(selNode2!=NULL)); assert(LocalRec!=NULL); assert((mode==0)||(mode==1));
	int i, j, numNode, numUnc;  // number of nodes in chosen local world and number of unconnected nodes;
  	double allmag, rannum;
  	double **Local=new double * [getSize()]; assert(Local!=NULL);	// Local[*][0] stores the node in that local world, Local[*][1] stores the degrees of that node;
	for(i=0;i<getSize();i++)
		{ Local[i]=new double [2]; assert(Local[i]!=NULL); 
		  Local[i][0]=-1.0; Local[i][1]=0.0;
		} 
  	
  	// first, check if there are nodes that can be connected;
  	numNode=numUnc=0;
  	for(i=0;i<netsize;i++)
		{ if((i!=*selNode1)&&(FLOAT_EQ(LocalRec[selLocal][i], 1.0)))
			{ Local[numNode][0]=(double)i; 
			  numNode++;  // number of nodes in this local world;
  			  if(FLOAT_EQ(getAdjMatrixMember(*selNode1, i), getConWeiLow())) numUnc++;  // number of nodes in this local world that has not been connected;
  			}
		}
  	if((mode!=1)||(numUnc!=0))
  		{ // in mode 1, all nodes in this local world have been connected;
  		  // otherwise, there are nodes not connected; choose one to connect;
  		  // record degrees of these nodes;
  		  for(i=0;i<numNode;i++)
  			{ for(j=0;j<netsize;j++)
  				{ if((j!=(int)(Local[i][0]))&&(FLOAT_EQ(LocalRec[selLocal][j], 1.0))&&(FLOAT_EQ(getAdjMatrixMember((int)(Local[i][0]), j), getConWeiUp()))) Local[i][1]+=1.0;
  				}
  			}
  		 allmag=0.0;
  		 for(i=0;i<numNode;i++)
		  	{ if(FLOAT_EQ(Local[i][1], 0.0)) Local[i][1]=1.0;
  			  allmag+=Local[i][1];
  			}
  		for(i=1;i<numNode;i++)
 		 	Local[i][1]+=Local[i-1][1];
  		for(i=0;i<numNode;i++)
		  	Local[i][1]/=allmag;
  		// decide link(s);
  		if(mode==1)
		  	{ do{ rannum=Rand0_1; *selNode2=-1;
				  if((FLOAT_SM_EQ(rannum, Local[0][1]))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[0][0])), getConWeiLow()))) *selNode2=(int)(Local[0][0]);
				  else if((FLOAT_EQ(rannum, 1.0))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[numNode-1][0])), getConWeiLow()))) *selNode2=(int)(Local[numNode-1][0]);
  				  else
				 	{ for(i=1;i<numNode;i++)
  						{ if((FLOAT_BG(rannum, Local[i-1][1]))&&(FLOAT_SM_EQ(rannum, Local[i][1]))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[i][0])), getConWeiLow()))) { *selNode2=(int)(Local[i][0]); break; }
  						}
  					}
  			  }while(*selNode2==-1);
  			}
 		else if((mode==2)||(mode==3))
 		 	{ if(numUnc<=*m) 
  				{ *m=numUnc;  // connnect each node in this local world;
				  for(i=0;i<*m;i++)
  				  	{ setAdjMatrixMember(*selNode1, (int)(Local[i][0]), getConWeiUp()); setAdjMatrixMember((int)(Local[i][0]), *selNode1, getAdjMatrixMember(*selNode1, (int)(Local[i][0]))); }
   				}
  			  else
  			  	{ for(i=0;i<*m;i++)
 		 	  		{ rannum=Rand0_1; *selNode2=-1;
  			  		  if((FLOAT_SM_EQ(rannum, Local[0][1]))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[0][0])), getConWeiLow()))) *selNode2=(int)(Local[0][0]);
					  else if((FLOAT_EQ(rannum, 1.0))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[numNode-1][0])), getConWeiLow()))) *selNode2=(int)(Local[numNode-1][0]);
					  else
  			  		  	{ for(j=1;j<numNode;j++)
  			  		  		{ if((FLOAT_BG(rannum, Local[j-1][1]))&&(FLOAT_SM_EQ(rannum, Local[j][1]))&&(FLOAT_EQ(getAdjMatrixMember(*selNode1, (int)(Local[j][0])), getConWeiLow()))) { *selNode2=(int)(Local[j][0]); break; }
  			  		  		}
  			  		  	}
  			  		  if(*selNode2==-1) i--;
  			  		  else { setAdjMatrixMember(*selNode1, *selNode2, getConWeiUp()); setAdjMatrixMember(*selNode2, *selNode1, getAdjMatrixMember(*selNode1, *selNode2)); }
  			  		}
 	 		  	}
 	 		}
  		}
	// delete Local;
	for(i=0;i<getSize();i++)
		{ delete [] Local[i]; Local[i]=NULL; }
	delete [] Local; Local=NULL;
}

void CNet::buildMLWaction(int netsize, int *numlocal, int step, double **Localset, int size1, int size2, double **LocalRec, int size3, int size4, int mode)
{ // mode=1, a new local-world with one node is created. Its _M1 links to the existing local-worlds are decided by the probability of the existing local-worlds decided by their connctions; repeat _M1 times;
  // mode=2, a new node is added to an existing local-world, which has _M2 links with the nodes within the same local-world. The probability that local-world i is selected is proportional to pow(T(i), _AlfaMLW), where T(i) is the time at which local-world i is created and _AlfaMLW is a constant; repeat _M2 times;
  // mode=3, a total of _M3 links are added to the network: first, a local-world and a node in this local-world are randomly selected; then, another node is randomly selected for each link with the probability decided by its degrees; repeat _M3 times; 
	assert((0<netsize)&&(netsize<getSize())); assert(numlocal!=NULL); assert(Localset!=NULL); assert(LocalRec!=NULL); assert((mode==1)||(mode==2)||(mode==3));
  	int i, j, m1, m2, m3;  // record the number of new edges in different action;
  	int selLocal, selNode1, selNode2;  // store selected local world and selected nodes in it;
  	int numNode;  // number of nodes in each local world;
  	double rannum;
  	double *curlocalset=new double [getSize()]; assert(curlocalset!=NULL);  // decide the probability to choose existing local world;
  	for(i=0;i<getSize();i++)
  		curlocalset[i]=0.0;

  	if(mode==1)
  		{ // create a new local world with one node and m1 links;
	  	  setLocalWorld(numlocal, curlocalset, getSize(), Localset, size1, size2, 1);  // set up the probability to choose existing local world based on their inner edges localset[*][1]; 
 	 	  m1=getM1(); if(*numlocal<=m1) m1=*numlocal;
  		  // decide m1 links;
  		  for(i=0;i<m1;i++)
  		  	{ selNode1=netsize; 
  		  	  do{ rannum=Rand0_1; selLocal=-1; selNode2=-1;
		 	 	 if(FLOAT_SM_EQ(rannum, curlocalset[0])) { selLocal=0; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 1, LocalRec, size3, size4, NULL); }	// further check to connect which node in this local world;
				 else if(FLOAT_EQ(rannum, 1.0)) { selLocal=*numlocal-1; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 1, LocalRec, size3, size4, NULL); }	// further check to connect which node in this local world;
				 else
				  	{ for(j=1;j<*numlocal;j++)
				  		{ if((FLOAT_BG(rannum, curlocalset[j-1]))&&(FLOAT_SM_EQ(rannum, curlocalset[j]))) { selLocal=j; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 1, LocalRec, size3, size4, NULL); break; }	// further check to connect which node in this local world;
						}
				 	}
			  }while((selLocal==-1)||(selNode2==-1));	  
			  setAdjMatrixMember(selNode1, selNode2, getConWeiUp()); setAdjMatrixMember(selNode2, selNode1, getAdjMatrixMember(selNode1, selNode2));
  		  	}
 	 	  // update local world information;
  		  LocalRec[*numlocal][netsize]=1.0;  // store the new node into new local world; 
  		  Localset[*numlocal][0]=pow(step, getAlfaMLW()); Localset[*numlocal][1]=0.0; // store the creating time of this new local world;
  		  (*numlocal)++;
  		}
  	else if(mode==2)
  		{ // create a new node into one of the existing local world, with m2 links;
		  setLocalWorld(numlocal, curlocalset, getSize(), Localset, size1, size2, 0);  // set up the probabilitu to choose existing local world based on their creating time localset[*][0];	
		  selNode1=netsize;
		  do{ m2=getM2(); rannum=Rand0_1; selLocal=-1; selNode2=-1;
		  	 if(FLOAT_SM_EQ(rannum, curlocalset[0])) { selLocal=0; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 2, LocalRec, size3, size4, &m2); }	// further check to connect which node in this local world;
			 else if(FLOAT_EQ(rannum, 1.0)) { selLocal=*numlocal-1; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 2, LocalRec, size3, size4, &m2); }	// further check to connect which node in this local world;
			 else
		  	 	{ for(j=1;j<*numlocal;j++)
		  	 		{ if((FLOAT_BG(rannum, curlocalset[j-1]))&&(FLOAT_SM_EQ(rannum, curlocalset[j]))) { selLocal=j; selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 2, LocalRec, size3, size4, &m2); break; }	// further check to connect which node in this local world;			
					}
		  	 	}
		  }while(selLocal==-1);
		  // update local world information;
		  LocalRec[selLocal][netsize]=1.0;  // this new node belongs to current local world;
		  Localset[selLocal][1]+=(double)(m2);  // adding new edges;
		}
  	else if(mode==3)
  		{ // create m3 links; 
		  // randomly select a local world and a node in this local world;
		  // first, check if all local worlds are fully connected;
		  for(i=0;i<*numlocal;i++)
		  	{ numNode=0; 
			  for(j=0;j<size4;j++)
			  	{ if(FLOAT_EQ(LocalRec[i][j], 1.0)) numNode++;
			  	}
			  if(Localset[i][1]!=(int)(numNode*(numNode-1)/_Twice)) break;
		  	}
		  if(i!=*numlocal)
		  	{ do{ m3=getM3(); 
		  		  do{ selLocal=(int)(Rand0_1*(*numlocal)); selNode1=(int)(Rand0_1*(netsize));
		  	 	  }while((selLocal==*numlocal)||(selNode1==netsize)||(FLOAT_EQ(LocalRec[selLocal][selNode1], 0.0)));
		  	 	  // adding m3 links inside this local world;
		  	 	  selConNode(selLocal, netsize, numlocal, &selNode1, &selNode2, 3, LocalRec, size3, size4, &m3);  // further check to connect which node in this local world;
		  	  }while(m3==0);	
		  	  Localset[selLocal][1]+=(double)(m3);	// update local world information;		  	  
		  	}
  		}
}

void CNet::crtMLWnet()
{ // Multiple Local world network;
	int i, j, netsize, numlocal;
	double rannum;
	double **Localset=new double * [getSize()]; assert(Localset!=NULL);	// in Multi-Local-World network, Localset[*][0] stores exp(T(i), _AlfaMLW); Localset[*][1] stores number of edges inside this local world; 
	for(i=0;i<getSize();i++)
		{ Localset[i]=new double [2]; assert(Localset[i]!=NULL); 
		  Localset[i][0]=0.0; Localset[i][1]=0.0;
		}
	double **LocalRec=new double * [getSize()]; assert(LocalRec!=NULL);	// record the number of local world and its members;
	for(i=0;i<getSize();i++)
		{ LocalRec[i]=new double [getSize()]; assert(LocalRec[i]!=NULL); 
		  for(j=0;j<getSize();j++)
		  	LocalRec[i][j]=0.0;
		}

	printf("Building Multiple Local world network:\n");
	do{ // reinitialize m_ppAdjMatrix, LocalRec and Local;
		EmpAdjMatrix();
		for(i=0;i<getSize();i++)
			for(j=0;j<getSize();j++)
				LocalRec[i][j]=0.0;
		for(i=0;i<getSize();i++)
 		 	{ Localset[i][0]=Localset[i][1]=0.0; }
  	 	Localset[0][0]=pow(1, getAlfaMLW()); Localset[0][1]=0.0;
  	 	LocalRec[0][0]=1.0;
  	 	netsize=numlocal=1;  // initially, there is 1 node and 1 local world;
  	 	do{ // at each time t, there are possibly three actions; 
			rannum=Rand0_1;
  	 	  	if(FLOAT_SM_EQ(rannum, getP())) { buildMLWaction(netsize, &numlocal, i+1, Localset, getSize(), 2, LocalRec, getSize(), getSize(), 1); netsize++; }  // action 1;
  	 	 	else if((FLOAT_BG(rannum, getP()))&&(FLOAT_SM_EQ(rannum, getP()+getQ()))) { buildMLWaction(netsize, &numlocal, i+1, Localset, getSize(), 2, LocalRec, getSize(), getSize(), 2); netsize++; }  // action 2;
  	 	 	else if((FLOAT_BG(rannum, getP()+getQ()))&&(FLOAT_SM_EQ(rannum, getP()+getQ()+getR()))) { if(netsize!=1) buildMLWaction(netsize, &numlocal, i+1, Localset, getSize(), 2, LocalRec, getSize(), getSize(), 3); }	// action 3;
  	 	}while(netsize<getSize());
  	}while(chkCon(getSize())==1);
	// delete Localset;
	for(i=0;i<getSize();i++)
		{ delete [] Localset[i]; Localset[i]=NULL; }
	delete [] Localset; Localset=NULL;
	// delete LocalRec;
	for(i=0;i<getSize();i++)
		{ delete [] LocalRec[i]; LocalRec[i]=NULL; }
	delete [] LocalRec; LocalRec=NULL;		
}

// for self-grow network;
double CNet::calNodeDeg(int node)
{ // calculate node's degree;
	assert((0<=node)&&(node<getSize()));
	int i;
	double nodeDeg=0.0;
	for(i=0;i<getSize();i++)
		{ if(FLOAT_NE(getAdjMatrixMember(node, i), getConWeiLow())) nodeDeg+=getAdjMatrixMember(node, i); }
	return nodeDeg;
}

int CNet::calAvaCon(int node)
{ // calculate node's available connections (degree);
	assert((0<=node)&&(node<getSize()));
	int i;
	int noAvaCon=0;
	for(i=0;i<getSize();i++)
		{ if(FLOAT_BG_EQ(getAdjMatrixMember(node, i), getConWeiThres())) noAvaCon++; }
	return noAvaCon;
}

void CNet::AdjCon(int xLoc, int yLoc, bool SucCom)
{ // adjust m_ppAdjMatrix[xLoc][yLoc]'s value according to type;
	assert((0<=xLoc)&&(xLoc<getSize())); assert((0<=yLoc)&&(yLoc<getSize()));
	if(SucCom==1) 
		{ if(xLoc!=yLoc) 
			{ IncAdjMatrixMember(xLoc, yLoc); 
			  if(FLOAT_BG_EQ(getAdjMatrixMember(xLoc, yLoc), getConWeiThres())) setAdjMatrixMember(xLoc, yLoc, getConWeiUp());	// build up a permanent connection;
			  if(getDirected()==0) 
			  	{ IncAdjMatrixMember(yLoc, xLoc);
			   	  if(FLOAT_BG_EQ(getAdjMatrixMember(yLoc, xLoc), getConWeiThres())) setAdjMatrixMember(yLoc, xLoc, getConWeiUp());	// build up a permanent connection;
			   	}
			}
		}
	else if(SucCom==0) 
		{ if(xLoc!=yLoc) 
			{ DecAdjMatrixMember(xLoc, yLoc); 
			   if(FLOAT_SM(getAdjMatrixMember(xLoc, yLoc), getConWeiThres())) setAdjMatrixMember(xLoc, yLoc, getConWeiLow());	// break down a permanent connection;
			  if(getDirected()==0)
			  	{ DecAdjMatrixMember(yLoc, xLoc);
			   	  if(FLOAT_SM(getAdjMatrixMember(yLoc, xLoc), getConWeiThres())) setAdjMatrixMember(yLoc, xLoc, getConWeiLow());	// break down a permanent connection;
			   	}
			}
		}
}



// CParaMeters's membership functions;
CParaMeters::CParaMeters()
{ // construction function;
	InitPara();
}

CParaMeters::CParaMeters(const CParaMeters &init)
{ // copy construction function;
	(*this)=init;
}
	
CParaMeters::~CParaMeters()
{ // destruction function;
	DestPara();
}

CParaMeters &CParaMeters::operator = (const CParaMeters &right)
{ // copy parameter;
	if(&right!=this)
		{ // it is not self-copy;
		  DestPara(); InitPara();
		  setCode(right.m_nCode);
		  setNumSemRole(right.m_nNumSemRole); 
		  setLengthSemRole(right.m_nLengthSemRole);

		  setNumSemAgent(right.m_nNumSemAgent); 
		  setNumSemPred1(right.m_nNumSemPred1); setNumSemPred2(right.m_nNumSemPred2); 
		  setNumSemPred(right.m_nNumSemPred); setNumSemPat(right.m_nNumSemPat);
		  setNumSemItem(right.m_nNumSemItem); setLengthSemItem(right.m_nLengthSemItem);
		  setAgSamePat(right.m_nAgSamePat);

		  setLengthSem(right.m_nLengthSem);
		  setLengthIntgMean1(right.m_nLengthIntgMean1); setLengthIntgMean2(right.m_nLengthIntgMean2); 
		  setLengthIntgMean(right.m_nLengthIntgMean);
		  
		  setLengthWord(right.m_nLengthWord); setLengthPhrase(right.m_nLengthPhrase); 
		  setLengthHolist1(right.m_nLengthHolist1); setLengthHolist2(right.m_nLengthHolist2); 
		  setLengthIntgUtter(right.m_nLengthIntgUtter);
		}
	return *this;
}

void CParaMeters::InitPara()
{ // initialization function;
	setCode(overallpara.p_nCode);	
	setNumSemRole(overallpara.p_nNumSemRole); 
	setLengthSemRole((int)(log10((double)(getNumSemRole()))/(double)(log10((double)(getCode())))+1));

	setNumSemAgent(overallpara.p_nNumSemAgent); 
	setNumSemPred1(overallpara.p_nNumSemPred1); setNumSemPred2(overallpara.p_nNumSemPred2); 
	setNumSemPred(getNumSemPred1()+getNumSemPred2());
	setNumSemPat(overallpara.p_nNumSemPat);
	setNumSemItem(getNumSemAgent()+getNumSemPred()+getNumSemPat());
	setLengthSemItem((int)(log10((double)(getNumSemItem()))/(double)(log10((double)(getCode())))+1));
	setAgSamePat(overallpara.p_nAgSamePat);
	
	setLengthSem(getLengthSemRole()+getLengthSemItem());
	setLengthIntgMean1(2*getLengthSem()); setLengthIntgMean2(3*getLengthSem());
	setLengthIntgMean(getLengthIntgMean2());

	setLengthWord(overallpara.p_nLengthWord); setLengthPhrase(2*getLengthWord()); 
	setLengthHolist1(2*getLengthWord()); setLengthHolist2(3*getLengthWord());
	setLengthIntgUtter(getLengthHolist2());
}

void CParaMeters::DestPara()
{ // destroy function;
	setCode(0);	
	setNumSemRole(0); setLengthSemRole(0);

	setNumSemAgent(0); 
	setNumSemPred1(0); setNumSemPred2(0); 
	setNumSemPred(0); 
	setNumSemPat(0);
	setNumSemItem(0); setLengthSemItem(0);
	setAgSamePat(-1);
	
	setLengthSem(0);
	setLengthIntgMean1(0); setLengthIntgMean2(0);
	setLengthIntgMean(0);

	setLengthWord(0); setLengthPhrase(0); 
	setLengthHolist1(0); setLengthHolist2(0);
	setLengthIntgUtter(0);
}



// CBasicMean's membership functions;
CBasicMean::CBasicMean()
{ // construction function;
	InitBasicMean(); CreateSem();
}

CBasicMean::CBasicMean(const CBasicMean & init)
{ // copy construction function;
	(*this)=init;
}

CBasicMean::~CBasicMean()
{ // destruction function;
	DestBasicMean();
}

CBasicMean &CBasicMean::operator = (const CBasicMean &right)
{ // copy basicmean by value;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestBasicMean();	InitBasicMean();
		  for(i=0;i<getNumSemRole();i++)
		  	setpSemRole(i, right.m_ppSemRole[i]);
		  for(i=0;i<getNumSemAgent();i++)
		  	setpSemAgent(i, right.m_ppSemAgent[i]);
		  for(i=0;i<getNumSemPred();i++)
		  	setpSemPred(i, right.m_ppSemPred[i]);
		  for(i=0;i<getNumSemPat();i++)
		  	setpSemPat(i, right.m_ppSemPat[i]);
		}
	return *this;
}

void CBasicMean::InitBasicMean()
{ // initialization function;
	int i;
	m_ppSemRole=new CArray * [getNumSemRole()]; assert(m_ppSemRole!=NULL);
	for(i=0;i<getNumSemRole();i++)	
		m_ppSemRole[i]=NULL; 

	m_ppSemAgent=new CArray * [getNumSemAgent()]; assert(m_ppSemAgent!=NULL);
	for(i=0;i<getNumSemAgent();i++) 
		m_ppSemAgent[i]=NULL; 

	m_ppSemPred=new CArray * [getNumSemPred()]; assert(m_ppSemPred!=NULL);
	for(i=0;i<getNumSemPred();i++) 
		m_ppSemPred[i]=NULL; 

	m_ppSemPat=new CArray * [getNumSemPat()]; assert(m_ppSemPat!=NULL);
	for(i=0;i<getNumSemPat();i++) 
		m_ppSemPat[i]=NULL;
}

void CBasicMean::DestBasicMean()
{ // destroy function;
	int i;
	if(getNumSemRole()!=0) 
		{ for(i=0;i<getNumSemRole();i++)
			{ delete m_ppSemRole[i]; m_ppSemRole[i]=NULL; }
		  delete [] m_ppSemRole; m_ppSemRole=NULL;
		}	
	if(getNumSemAgent()!=0) 
		{ for(i=0;i<getNumSemAgent();i++)
			{ delete m_ppSemAgent[i]; m_ppSemAgent[i]=NULL; }
		  delete [] m_ppSemAgent; m_ppSemAgent=NULL; 
		}	
	if(getNumSemPred()!=0) 
		{ for(i=0;i<getNumSemPred();i++)
			{ delete m_ppSemPred[i]; m_ppSemPred[i]=NULL; } 
		  delete [] m_ppSemPred; m_ppSemPred=NULL; 
		}	
	if(getNumSemPat()!=0) 
		{ for(i=0;i<getNumSemPat();i++)
			{ delete m_ppSemPat[i]; m_ppSemPat[i]=NULL; }
		  delete [] m_ppSemPat; m_ppSemPat=NULL;
		}	
}

int CBasicMean::TransSemItem(CArray *semItem)
{ // translate binary code into integer value;
	int i;
	int integvalue=0; 
	for(i=semItem->getLengthArray()-1;i>=0;i--)
		integvalue+=(int)(pow(getCode(), semItem->getLengthArray()-1-i)*(semItem->getElement(i)));
	return integvalue;					  		  
}

void CBasicMean::CreateSem()
{ // create m_ppSemRole, m_ppSemAgent, m_ppSemPred, m_ppSemPat;
  	int i, j, integer, size;  	

	for(i=0;i<getNumSemRole();i++)
		{ integer=i; size=getLengthSemRole();	// Create m_ppSemRole: Agent (00), Predicate1 (01), Predicate2 (10), Patient (11);
		  m_ppSemRole[i]=new CArray (size); assert(m_ppSemRole[i]!=NULL);
		  for(j=size-1;j>=0;j--)	
		  	{ getpSemRole(i)->setElement(j, integer%getCode());
	  		  integer=(int)(integer/getCode());
	  		}
		}
	for(i=0;i<getNumSemAgent();i++)
		{ integer=i; size=getLengthSemItem();	// Create m_ppSemAgent: 5 agents: 00000, 00001, 00010, 00011, 00100; 
		  m_ppSemAgent[i]=new CArray (size); assert(m_ppSemAgent[i]!=NULL);
		  for(j=size-1;j>=0;j--)
		  	{ getpSemAgent(i)->setElement(j, integer%getCode());
	  		  integer=(int)(integer/getCode());
	  		}
		}
	for(i=0;i<getNumSemPred();i++)
		{ integer=i+getNumSemAgent(); size=getLengthSemItem();	// Create m_ppSemPred: 10 predicates: 00101, 00110, 00111, 01000, 01001, 01010, 01011, 01100, 01101, 01110;
		  m_ppSemPred[i]=new CArray (size); assert(m_ppSemPred[i]!=NULL);
		  for(j=size-1;j>=0;j--)
		  	{ getpSemPred(i)->setElement(j, integer%getCode());
	  		  integer=(int)(integer/getCode());
	  		}
		}
	for(i=0;i<getNumSemPat();i++)
		{ integer=-1;
		  if(getAgSamePat()==0) integer=i+getNumSemAgent()+getNumSemPred(); // 5 new patients; 01111, 10000, 10001, 10010, 10011;
		  else if(getAgSamePat()==1) integer=i; // Create m_ppSemPat: 5 patients = 5 agents;
		  size=getLengthSemItem();	
		  m_ppSemPat[i]=new CArray (size); assert(m_ppSemPat[i]!=NULL);
		  for(j=size-1;j>=0;j--)
		  	{ getpSemPat(i)->setElement(j, integer%getCode());
	  		  integer=(int)(integer/getCode());
	  		}
		}
}

// other operations;
void CBasicMean::OutputBasicMean()
{ // output CBasicMean;
	int i;
	printf("SemRole:\n");
	for(i=0;i<getNumSemRole();i++)
		getpSemRole(i)->OutputArray();
	printf("SemAgent:\n");
	for(i=0;i<getNumSemAgent();i++)
		getpSemAgent(i)->OutputArray();	
	printf("SemPred1:\n");
	for(i=0;i<getNumSemPred1();i++)
		getpSemPred(i)->OutputArray();	
	printf("SemPred2:\n");
	for(i=getNumSemPred1();i<getNumSemPred();i++)
		getpSemPred(i)->OutputArray();
	printf("SemPat:\n");
	for(i=0;i<getNumSemPat();i++)
		getpSemPat(i)->OutputArray();
}



// SemItem's membership functions;
SemItem::SemItem()
{ // construction function;
	InitSemItem();
}

SemItem::~SemItem()
{ // destruction function;
	DestSemItem();
}

void SemItem::InitSemItem()
{ // initialization function;
	m_pIntgMean=NULL; m_dFre=0.0;
}

void SemItem::DestSemItem()
{ // destroy function;	 
	delete m_pIntgMean; m_pIntgMean=NULL;
  	m_dFre=0.0;
}

// CSemSpace's membership functions;
CSemSpace::CSemSpace()
{ // construction function;
	InitSemSpace(); CreateSemSpace();
}

CSemSpace::CSemSpace(const CSemSpace &init)
{ // copy construction function;
	(*this)=init;
}

CSemSpace::~CSemSpace()
{ // destruction function;
	DestSemSpace();
}

CSemSpace & CSemSpace::operator = (const CSemSpace &right)
{ // copy semspace by value;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestSemSpace();	InitSemSpace();
		  setNumMean1(right.m_nNumMean1); setNumMean2(right.m_nNumMean2); 
		  setNumIntgMean(right.m_nNumIntgMean);
		  setSemDist(right.m_nSemDist);
		  setRatioSV_SVO(right.m_dRatioSV_SVO);
		  setGausAvg(right.m_dGausAvg); setGausVar(right.m_dGausVar);
		  setPowerLawA(right.m_dPowerLawA); setPowerLawK(right.m_dPowerLawK);
		  for(i=0;i<getNumIntgMean();i++)
		  	m_ppSemItem[i]=right.m_ppSemItem[i];	// copy by address;
		}
	return *this;
}

void CSemSpace::InitSemSpace()
{ // initialization function;
	int i;
	setNumMean1(getNumSemAgent()*getNumSemPred1()); 
	if(getAgSamePat()==0) setNumMean2(getNumSemAgent()*getNumSemPred2()*getNumSemPat());	// Patient is not same as Agent;
	else if(getAgSamePat()==1) setNumMean2(getNumSemAgent()*getNumSemPred2()*(getNumSemPat()-1));	// Patient is same as Agent;
	setNumIntgMean(getNumMean1()+getNumMean2());
	setSemDist(overallpara.p_nSemDist);
	setRatioSV_SVO(overallpara.p_dRatioSV_SVO);
	setGausAvg(overallpara.p_dGausAvg); setGausVar(overallpara.p_dGausVar);
	setPowerLawA(overallpara.p_dPowerLawA); setPowerLawK(overallpara.p_dPowerLawK);
	// initialize this->m_ppSemSpace;
	m_ppSemItem=new SemItem * [getNumIntgMean()]; assert(m_ppSemItem!=NULL);
	for(i=0;i<getNumIntgMean();i++) 
		m_ppSemItem[i]=NULL;
}

void CSemSpace::DestSemSpace()
{ // destroy function;
	int i;
	if(getNumIntgMean()!=0) 
		{ for(i=0;i<getNumIntgMean();i++)
			{ delete m_ppSemItem[i]; m_ppSemItem[i]=NULL; } 
		  delete [] m_ppSemItem; m_ppSemItem=NULL;
		  setNumMean1(0); setNumMean2(0); setNumIntgMean(0);	
		}		  
	setSemDist(-1);
	setRatioSV_SVO(1.0);
	setGausAvg(0.0); setGausVar(0.0);
	setPowerLawA(0.0); setPowerLawK(0.0);
}

void CSemSpace::CreateSemSpace()
{ // create semantic space;
	// set up semantic space, its integrated meaning and the integrated meaning's distribution;
  	int i, j, k, cur, curloc; 
  	CArray *newintgmean=NULL;
  	double rannum, tot, value;

	for(i=0;i<getNumIntgMean();i++)
		{ m_ppSemItem[i]=new SemItem; assert(m_ppSemItem[i]!=NULL); }
  	// set up semitem->m_pIntgMean;
  	cur=0;
  	// Predicate<Agent> integrated meanings;
  	for(i=0;i<getNumSemAgent();i++)
  		{ for(j=0;j<getNumSemPred1();j++)
  			{ newintgmean=new CArray (getLengthIntgMean()); assert(newintgmean!=NULL);
  			  curloc=0;	
  			  newintgmean->setPartArray(getpSemRole(0), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  			  newintgmean->setPartArray(getpSemAgent(i), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  			  newintgmean->setPartArray(getpSemRole(1), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  			  newintgmean->setPartArray(getpSemPred(j), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  			  getpSemItem(cur)->setpIntgMean(newintgmean);
  			  newintgmean=NULL;	// recollect newintgmean;
  			  cur++;	// move to next integrated meaning;
  			}
  		}
  	// Predicate<Agent, Patient> integrated meanings;
  	for(i=0;i<getNumSemAgent();i++)
  		for(j=getNumSemPred1();j<getNumSemPred();j++)
  			for(k=0;k<getNumSemPat();k++)
  				{ if(getAgSamePat()==0)
  					{ // Patient is not same as Agent;
					  newintgmean=new CArray (getLengthIntgMean()); assert(newintgmean!=NULL);
				  	  curloc=0;	
  			  	  	  newintgmean->setPartArray(getpSemRole(0), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  			  	  	  newintgmean->setPartArray(getpSemAgent(i), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  	  newintgmean->setPartArray(getpSemRole(2), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  				  	  newintgmean->setPartArray(getpSemPred(j), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  	  newintgmean->setPartArray(getpSemRole(3), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  				 	  newintgmean->setPartArray(getpSemPat(k), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  	  getpSemItem(cur)->setpIntgMean(newintgmean);
  				  	  newintgmean=NULL;	// recollect newintgmean;
  					  cur++;
  					}
				  else if(getAgSamePat()==1)
				  	{ // Patient is same as Agent;
  				  	  if(k==i) continue;
  				  	  else
  				 	 	{ newintgmean=new CArray (getLengthIntgMean()); assert(newintgmean!=NULL);
				  		  curloc=0;	
  			  	  		  newintgmean->setPartArray(getpSemRole(0), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  			  	  		  newintgmean->setPartArray(getpSemAgent(i), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  		  newintgmean->setPartArray(getpSemRole(2), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  				  		  newintgmean->setPartArray(getpSemPred(j), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  		  newintgmean->setPartArray(getpSemRole(3), curloc, 0, getLengthSemRole()); curloc+=getLengthSemRole();
  				 	 	  newintgmean->setPartArray(getpSemPat(k), curloc, 0, getLengthSemItem()); curloc+=getLengthSemItem();
  				  		  getpSemItem(cur)->setpIntgMean(newintgmean);
  				  		  newintgmean=NULL;	// recollect newintgmean;
  					  	  cur++;
  					  	}
				  	}
  				}

	// set up semitem->m_dFre;
	tot=0.0;
	switch(getSemDist())
		{ case 0: // uniform distribution;
				for(i=0;i<getNumIntgMean();i++)
					{ if(i<getNumMean1()) getpSemItem(i)->setFre(1.0/(double)(getNumIntgMean()));
					  else getpSemItem(i)->setFre((1.0/(double)(getNumIntgMean()))/getRatioSV_SVO());
					  tot+=getpSemItem(i)->getFre();
					}
				break;
		  case 1: case 2: // Gaussian distribution;
				for(i=0;i<getNumIntgMean();i++)
		  			{ if(i<getNumMean1()) 
		  				{ value=gaussrand(getGausAvg(), getGausVar());
						  if(FLOAT_SM_EQ(value, 0.0)) value=0.0;
						  else if(FLOAT_BG_EQ(value, 1.0)) value=1.0;
		  				  getpSemItem(i)->setFre(value);
						}
					  else 
					  	{ value=gaussrand(getGausAvg(), getGausVar())/getRatioSV_SVO();
						  if(FLOAT_SM_EQ(value, 0.0)) value=0.0;
						  else if(FLOAT_BG_EQ(value, 1.0)) value=1.0;
		  				  getpSemItem(i)->setFre(value);
					  	}
					  tot+=getpSemItem(i)->getFre();
					}		  		  		
		  		break;
		  case 3: // Power law distribution;
		  		for(i=0;i<getNumIntgMean();i++)
		  			{ getpSemItem(i)->setFre(getPowerLawA()*pow(i+1, getPowerLawK()));
					  tot+=getpSemItem(i)->getFre();
					}
		  		break;
	  	  case 4: // reverse Power law distribution;
	  	  		for(i=0;i<getNumIntgMean();i++)
		  			{ getpSemItem(i)->setFre(getPowerLawA()*pow(getNumIntgMean()-i, getPowerLawK()));
					  tot+=getpSemItem(i)->getFre();
					}
		  		break;
		  case 5: case 6: // random distribution;
		  		for(i=0;i<getNumIntgMean();i++)
  					{ do{ rannum=Rand0_1;
  		  			  }while(FLOAT_EQ(rannum, 0.0));
  		  			  getpSemItem(i)->setFre(rannum);
  		  			  tot+=getpSemItem(i)->getFre();
					}
				break;
		  default: break;
		}
	// normalize;
	for(i=0;i<getNumIntgMean();i++)
		getpSemItem(i)->setFre(getpSemItem(i)->getFre()/tot);		
	// accumulate;
	for(i=1;i<getNumIntgMean()-1;i++)
		getpSemItem(i)->setFre(getpSemItem(i)->getFre()+getpSemItem(i-1)->getFre());
	getpSemItem(getNumIntgMean()-1)->setFre(1.0);
}

// other operations;
double CSemSpace::gaussrand(double mean, double variance)
{ // generate a Gaussian distributed variable;
	static double V1, V2, S;
	static int phase = 0;
	double X, U1, U2;
	if(phase==0) 
		{ do { U1=Rand0_1; U2=Rand0_1;
			   V1=2*U1-1; V2=2*U2-1;
			   S=V1*V1+V2*V2;
		  }while((S>=1)||(S==0));
		  X=V1*sqrt(-2.0*log(S)/S);
		} 
	else
		X=V2*sqrt(-2.0*log(S)/S);
	phase=1-phase;
	return (mean+variance*X);
}

int CSemSpace::RandSelpIntgMeanIndex()
{ // randomly select an integrated meaning from the semantic space;
	int i, cur;
	//int j; bool same;
	double rannum;
	cur=-1; rannum=Rand0_1;
	if(FLOAT_SM_EQ(rannum, getpSemItem(0)->getFre())) cur=0;
	else if(FLOAT_EQ(rannum, 1.0)) cur=getNumIntgMean()-1;
	else
		{ for(i=1;i<getNumIntgMean();i++)
			{ if((FLOAT_BG(rannum, getpSemItem(i-1)->getFre()))&&(FLOAT_SM_EQ(rannum, getpSemItem(i)->getFre()))) { cur=i; break; }
			}	 	  
		}	
	return cur;
}



// CueItem's membership functions;
CueItem::CueItem()
{ // construction function;
	InitCueItem();
}

CueItem::~CueItem()
{ // destruction function;
	DestCueItem();
}

void CueItem::InitCueItem()
{ // initialization function;
  	m_pCueMean=NULL; m_nCueTyp=-1; m_dCueStr=0.0;
}

void CueItem::DestCueItem()
{ // destroy function;
	m_pCueMean=NULL; m_nCueTyp=-1; m_dCueStr=0.0;
}

// CCue's membership functions;
CCue::CCue(void)
{ // construction function;
	InitCue(0);
}

CCue::CCue(const CCue &init)
{ // copy construction function;
	(*this)=init;
}

CCue::~CCue()
{ // destruction function;
	DestCue();
}

CCue & CCue::operator = (const CCue &right)
{ // copy cue;
	int i;
	if(&right!=this)
		{ // it is not self-copy;
		  DestCue(); InitCue(right.m_nNumCue);
		  setAtLeastOneCue(right.m_nAtLeastOneCue); 
		  setMaxCueNum(right.m_nMaxCueNum); setWrongCueTyp(right.m_nWrongCueTyp);
		  setDefCueStr(right.m_dDefCueStr); 
		  setCueReliab(right.m_dCueReliab); setCueReliabVar(right.m_dCueReliabVar);
		  if(getNumCue()!=0)
		  	{ for(i=0;i<getNumCue();i++)
		  		m_ppCueItem[i]=right.m_ppCueItem[i];	// copy by address;
			}
		}
	return *this;
}

void CCue::InitCue(int numCue)
{ // Initialization function;
	assert((0<=numCue)&&(numCue<=overallpara.p_nMaxCueNum));
	int i;
	// cue's meaning part;
	setAtLeastOneCue(overallpara.p_nAtLeastOneCue);
	setMaxCueNum(overallpara.p_nMaxCueNum); setWrongCueTyp(overallpara.p_nWrongCueTyp);
	setDefCueStr(overallpara.p_dDefCueStr); 
	setCueReliab(overallpara.p_dCueReliab); setCueReliabVar(overallpara.p_dCueReliabVar);
	m_nNumCue=numCue;
	if(getNumCue()==0) m_ppCueItem=NULL;
	else 
		{ m_ppCueItem=new CueItem * [getNumCue()]; assert(m_ppCueItem!=NULL);
		  for(i=0;i<getNumCue();i++) 
		  	m_ppCueItem[i]=NULL;
		}	
}

void CCue::DestCue()
{ // destroy function;
	EmpCueItem(); setAtLeastOneCue(-1);
	setMaxCueNum(0); setWrongCueTyp(-1);
	setDefCueStr(0.0); 
	setCueReliab(0.0); setCueReliabVar(0.0);
}

// other operations;
void CCue::createCue(CSemSpace *semspace, int type, CArray *pMean, double newCueReliab)
{ // according to the real mean to creat cues; type=0, random select cue; 1, select a wrong cue; 2, select the correct cue;
	assert(semspace!=NULL); assert((type==0)||(type==1)||(type==2)); 
	assert((pMean!=NULL)&&(pMean->getLengthArray()==semspace->getLengthIntgMean()));
	assert((FLOAT_SM_EQ(0.0, newCueReliab))&&(FLOAT_SM_EQ(newCueReliab, 1.0)));
	int i, j, posAg, posPred, posPat, numcue, same;
	bool sameAg, samePred, samePat;
	CArray *pWrongSem=NULL, *pCorrectSem=NULL;

	posAg=getLengthSemRole(); 
	posPred=getLengthSem()+getLengthSemRole();
	posPat=2*(getLengthSem())+getLengthSemRole();
	
	switch(type)
		{ case 0: // randomly select a cue;
				numcue=-1;
				if(overallpara.p_nAtLeastOneCue==0)
					{ if(overallpara.p_nMaxCueNum==1) { numcue=(FLOAT_SM_EQ(Rand0_1, _Half))?1:0; }
		  			  else { numcue=(int)(Rand0_1*overallpara.p_nMaxCueNum); }
					}
				else if(overallpara.p_nAtLeastOneCue==1)
					{ if(overallpara.p_nMaxCueNum==1) numcue=1;
					  else
					  	{ do{ numcue=(int)(Rand0_1*overallpara.p_nMaxCueNum);
					  	  }while(numcue==0);
					  	}
					}
				InitCue(numcue);	// create new cues;
				if(FLOAT_NE(newCueReliab, getCueReliab())) setCueReliab(newCueReliab);
				if(getNumCue()!=0)
				  	{ for(i=0;i<getNumCue();i++)
						{ m_ppCueItem[i]=new CueItem; assert(m_ppCueItem[i]!=NULL); }
					  for(i=0;i<getNumCue();i++)
						{ if(FLOAT_SM_EQ(Rand0_1, getCueReliab()))
							{ // choose the correct meaning as the cue;
							  // check whether the correct meaning is already as a cue;
							  for(j=0;j<i;j++)
							  	{ if(*(getpCueItem(j)->getpCueMean())==*pMean) break;
							  	}
							  if(j==i) setpCueItem(i, pMean, 0, getDefCueStr());	// store correct meaning as a cue in m_ppCueItem[i];
							  else i--;	// correct meaning is already as a cue, rechose cue;			  	
							}
						  else
						  	{ // choose a wrong meaning as the cue;
							  if(getWrongCueTyp()==0)
							  	{ // randomly select a wrong meaning as the cue;
							  	  do{ do{ pWrongSem=NULL; pWrongSem=semspace->getpSemItem(semspace->RandSelpIntgMeanIndex())->getpIntgMean();
							  	 	 }while(*pWrongSem==*pMean);
							  	 	 same=0;	// assume this cue is not same to mean and other previously set cues;
								 	 for(j=0;j<i;j++)
  						  	 	 		{ if(*(getpCueItem(j)->getpCueMean())==*pWrongSem) same=1;	// equals to a previously set cue;
  						  	 	 		}
  						  	  	  }while(same==1);
							  	  setpCueItem(i, pWrongSem, 0, getDefCueStr());	// store wrong cue in m_ppCueItem[i];
							  	  pWrongSem=NULL;	// recollect pWrongSem;
							  	}
							  else if(getWrongCueTyp()==1)
							  	{ // wrong cue has no component identical to the correct meaning;
							  	  do{ do{ pWrongSem=NULL; pWrongSem=semspace->getpSemItem(semspace->RandSelpIntgMeanIndex())->getpIntgMean();
								  	 	  // test sameAg;
									 	  sameAg=0;
									 	  for(j=0;j<getLengthSemItem();j++)
	  										{ if(pWrongSem->getElement(j+posAg)!=pMean->getElement(j+posAg)) break;
	  										}
	  	  							 	  if(j==getLengthSemItem()) sameAg=1;
									 	  // test samePred;
									 	  samePred=0;
									 	  for(j=0;j<getLengthSemItem();j++)
	  										{ if(pWrongSem->getElement(j+posPred)!=pMean->getElement(j+posPred)) break;
	  										}
	  	  							 	  if(j==getLengthSemItem()) samePred=1;
									 	  // test samePat;
									 	  samePat=0;
									 	  if(pWrongSem->getElement(posPat)!=-1)
										 	{ // "Pred<Ag, Pat>" meanings;
									 		  for(j=0;j<getLengthSemItem();j++)
	  											{ if(pWrongSem->getElement(j+posPat)!=pMean->getElement(j+posPat)) break;
	  											}
	  	  									  if(j==getLengthSemItem()) samePat=1;
										 	}									 
							  		  }while((*pWrongSem==*pMean)||(sameAg==1)||(samePred==1)||(samePat==1));
							  	 	  same=0;	// assume this cue is not same to mean and other previously set cues;
								 	  for(j=0;j<i;j++)
  						  	 	 		{ if(*(getpCueItem(j)->getpCueMean())==*pWrongSem) same=1;	// equals to a previously set cue;
  						  	 	 		}
  						  	  	  }while(same==1);
							  	  setpCueItem(i, pWrongSem, 0, getDefCueStr());	// store wrong cue in m_ppCueItem[i];
							  	  pWrongSem=NULL;	// recollect pWrongSem;
							  	}
					  		}
						}
					}
				break;
		  case 1: // randomly select a wrong cue;
		  		numcue=1;
				InitCue(numcue);	// create new cues;
				if(FLOAT_NE(newCueReliab, getCueReliab())) setCueReliab(newCueReliab);
				for(i=0;i<getNumCue();i++)
					{ // all cues are wrong! 
					  do{ do{ pWrongSem=NULL; pWrongSem=semspace->getpSemItem(semspace->RandSelpIntgMeanIndex())->getpIntgMean();
					  	 }while(*pWrongSem==*pMean);
					  	 same=0;	// assume this cue is not same to mean and other previously set cues;
						 for(j=0;j<i;j++)
  				  	 	 	{ if(*(getpCueItem(j)->getpCueMean())==*pWrongSem) same=1;	// equals to a previously set cue;
 		 		  	 	 	}  		  	 	  		  	 	 
  				  	  }while(same==1);
					  setpCueItem(i, pWrongSem, 0, getDefCueStr());	// store wrong cue in m_ppCueItem[i];
					  pWrongSem=NULL;	// recollect pWrongSemItem;  		  	 	 
					}
				break;
		  case 2: // select the correct cue;
				numcue=1;
				InitCue(numcue);	// create new cues;
				if(FLOAT_NE(newCueReliab, getCueReliab())) setCueReliab(newCueReliab);
				for(i=0;i<getNumCue();i++)
				  	{ // all cues are correct!
				  	  for(j=0;j<semspace->getNumIntgMean();j++)
				  	  	{ pCorrectSem=semspace->getpSemItem(j)->getpIntgMean();
					  	  if(*pCorrectSem==*pMean) break;
					  	}
					  setpCueItem(i, pCorrectSem, 0, getDefCueStr());	// store correct cue in m_ppCueItem[i];
					  pCorrectSem=NULL;	// recollect pCorrectSem;  	  	
		  			}
				break;
		  default: break;		
		}
}



// CMeanUtter's membership functions;
CMeanUtter::CMeanUtter()
{ // construction function;
	InitMeanUtter(); EmptypMeanUtter();
}

CMeanUtter::CMeanUtter(const CMeanUtter &init)
{ // copy construction function;
	(*this)=init;
}

CMeanUtter::~CMeanUtter()
{ // destruction function;
	DestMeanUtter();
}

CMeanUtter & CMeanUtter::operator = (const CMeanUtter &right)
{ // copy meanutter;
	if(&right!=this)
		{ // it is not self-copy;
		  DestMeanUtter(); InitMeanUtter();
		  setNumUtterSyl(right.m_nNumUtterSyl);
		  *m_pMean=*right.m_pMean; *m_pUtter=*right.m_pUtter;	// copy by value;
		}
	return *this;
}

bool CMeanUtter::operator == (const CMeanUtter &right)
{ // judge whether two meanutter are same;
	return ((*getpMean()==*(right.m_pMean))&&(*getpUtter()==*(right.m_pUtter)));
}

void CMeanUtter::InitMeanUtter()
{ // initialization function;
	setNumUtterSyl(overallpara.p_nNumUtterSyl);
	m_pMean=new CArray (getLengthIntgMean()); assert(m_pMean!=NULL);
	m_pUtter=new CArray (getLengthIntgUtter()); assert(m_pUtter!=NULL);
}

void CMeanUtter::DestMeanUtter()
{ // destroy function;
	delete m_pMean; m_pMean=NULL; delete m_pUtter; m_pUtter=NULL;
	setNumUtterSyl(0);	
}

// other operations;
void CMeanUtter::CrtSyl(int type, int size)
{ // create individual syllables; type=0, continuous; 1, separate;
	assert(((type==0)||(type==1))&&(size!=-1));
	int i, uttersize; 	// record the randomly created utterance's number of syllables;
	int front, back; 	// number of syllables in front and back of the utterance;
	int syl;	// randomly created synllable;
	
	if(type==0)
		{ // continuous; 
		  do{ uttersize=(int)(size*Rand0_1);	// the length of utterance is at most (0, size];
  		  }while(uttersize==0);
  	  	 for(i=0;i<uttersize;i++)
			{ do{ syl=(int)(Rand0_1*getNumUtterSyl());	// syl is in [0, m_nNumUtterSyl-1];
  	  	 	  }while(syl==getNumUtterSyl());
			  getpUtter()->setElement(i, syl);  			  		  
			}
		}
	else if(type==1)
		{ // separate;
		  do{ uttersize=(int)(size*Rand0_1);
    		  }while((uttersize==0)||(uttersize==1));	// for separate phrasal rule's utterance, at least 2 syllables; 
  	 	  do{ front=(int)(uttersize*Rand0_1);
		  }while((front==0)||(front==uttersize));
		  back=uttersize-front;
		  // front part; 
		  for(i=0;i<front;i++)
		  	{ do{ syl=(int)(Rand0_1*getNumUtterSyl());	// syl is in [0, m_nNumUtterSyl-1];
		   	  }while(syl==getNumUtterSyl());
		   	  getpUtter()->setElement(i, syl);		  
		  	}
		  // back part;
		  for(i=getLengthIntgUtter()-1;i>getLengthIntgUtter()-1-back;i--)
		  	{ do{ syl=(int)(Rand0_1*getNumUtterSyl());	// syl is in [0, m_nNumUtterSyl-1];
		   	  }while(syl==getNumUtterSyl());
		   	  getpUtter()->setElement(i, syl);
		  	}
		}
}

void CMeanUtter::CrtUtter(int type)
{ // according to different type, randomly create utterance;
  	assert((1<=type)&&(type<=5));
	int size=-1;	// initialized size for at most the length of created utterance;;
  	
  	EmptypUtter();	// empty this->pUtter;
	switch(type)
  		{ case 1: size=getLengthPhrase(); CrtSyl(0, size); break;	// type=1, Predicate<Agent> meaning's utterance, 1-6 syllables; size=m_nLengthPhrase; 
  		  case 2: size=getLengthIntgUtter(); CrtSyl(0, size); break;	// type=2, Predicate<Agent, Patient> meaning's utterance, 1-9 syllables; size=m_nLengthIntgUtter;
  		  case 3: size=getLengthWord(); CrtSyl(0, size); break;	// type=3, 1 semantic item's utterance, 1-3 syllables; size=m_nLengthWord; 
  		  case 4: size=getLengthPhrase(); CrtSyl(0, size); break;	// type=4, 2 semantic items' utterance, continuous, 1-6 syllables; size=m_nLengthPhrase;
  		  case 5: size=getLengthPhrase(); CrtSyl(1, size); break;	// type=5, 2 semantic items' utterance, separate, 1-6 syllables; size=m_nLengthPhrase;
  		  default: break;
  		}
}

int CMeanUtter::getLeftUtterLen()
{ // get left part of utterance syllables length;
	int i;
	for(i=0;i<getLengthIntgUtter();i++)
		{ if(getpUtter()->getElement(i)==-1) break;
		}
	return i;
}

int CMeanUtter::getRightUtterLen()
{ // get right part of utterance syllables length;
	int i;
	if(getpUtter()->getElement(getLengthIntgUtter()-1)!=-1)
		{ // check the right part;
		  for(i=getLengthIntgUtter()-1;i>=0;i--)
		  	{ if(getpUtter()->getElement(i)==-1) break;
		  	}
		  return getLengthIntgUtter()-1-i;
		}
	else return 0;
}

int CMeanUtter::getUtterLen()
{ // get total syllable length in the utterance part;
	if(getLeftUtterLen()!=getLengthIntgUtter()) 
		return getLeftUtterLen()+getRightUtterLen();
	else return getLeftUtterLen();
}

void CMeanUtter::Comb2Utter(CMeanUtter * meanutter1, CMeanUtter * meanutter2, int combtype)
{ // combine meanutter1's, meanutter2's utterance into m_pUtter under the regulation of combtype;
  // combtype=0, before; 1, after; 2, in between; 3, outer;
	assert((meanutter1!=NULL)&&(meanutter2!=NULL));
  	assert((meanutter1->getLengthIntgUtter()==getLengthIntgUtter())&&(meanutter2->getLengthIntgUtter()==getLengthIntgUtter()));
	assert((combtype==0)||(combtype==1)||(combtype==2)||(combtype==3));
	int len1, len2, lenleft, lenright;
	
	EmptypUtter();
	switch(combtype)
		{ case 0: // meanutter1's utter is before meanutter2's utter;	
			  	len1=meanutter1->getUtterLen(); len2=meanutter2->getUtterLen();
			  	if(len1+len2>getLengthIntgUtter()) printf("Wrong Comb2Utter(case 0)!\n");
				else { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter2->getpUtter(), len1, 0, len2); }
			  	break;
		  case 1: // meanutter1's utter is after meanutter2's utter;
				len1=meanutter1->getUtterLen(); len2=meanutter2->getUtterLen();
				if(len1+len2>getLengthIntgUtter()) printf("Wrong Comb2Utter(case 1)!\n");
			  	else { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter1->getpUtter(), len2, 0, len1); }
			  	break;
		  case 2: // meanutter1's utter is in between meanutter2's utter;
				len1=meanutter1->getUtterLen();
				lenleft=meanutter2->getLeftUtterLen(); lenright=meanutter2->getRightUtterLen();
				if(lenleft+len1+lenright>getLengthIntgUtter()) printf("Wrong Comb2Utter(case 2)!\n");
				else { setPartUtter(meanutter2->getpUtter(), 0, 0, lenleft); setPartUtter(meanutter1->getpUtter(), lenleft, 0, len1); setPartUtter(meanutter2->getpUtter(), lenleft+len1, meanutter2->getLengthIntgUtter()-lenright, lenright); }
				break;
		  case 3: // meanutter1's utter is surrounding meanutter2's utter;
				lenleft=meanutter1->getLeftUtterLen(); lenright=meanutter1->getRightUtterLen();
				len2=meanutter2->getUtterLen();
				if(lenleft+len2+lenright>getLengthIntgUtter()) printf("Wrong Comb2Utter(case 3)!\n");
				else { setPartUtter(meanutter1->getpUtter(), 0, 0, lenleft); setPartUtter(meanutter2->getpUtter(), lenleft, 0, len2); setPartUtter(meanutter1->getpUtter(), lenleft+len2, meanutter1->getLengthIntgUtter()-lenright, lenright); }
				break;
		  default: break;	
		}	
}

void CMeanUtter::Comb3Utter(CMeanUtter *meanutter1, CMeanUtter *meanutter2, CMeanUtter *meanutter3, int combtype12, int combtype23, int combtype13)
{ // combine meanutter1, meanutter2, meanutter3's utterances into this->m_pUtter under the regulation of combtype1, combtype2 or combtype3;
  // combtype=0: before; 1: after; 2;
	assert((meanutter1!=NULL)&&(meanutter2!=NULL)&&(meanutter3!=NULL));
  	assert((meanutter1->getLengthIntgUtter()==getLengthIntgUtter())&&(meanutter2->getLengthIntgUtter()==getLengthIntgUtter())&&(meanutter3->getLengthIntgUtter()==getLengthIntgUtter()));
	assert((-1<=combtype12)&&(combtype12<=1)&&(-1<=combtype23)&&(combtype23<=1)&&(-1<=combtype13)&&(combtype13<=1));
	assert(((combtype12!=-1)&&(combtype23!=-1)&&(combtype13!=-1))||((combtype12==-1)&&(combtype23!=-1)&&(combtype13!=-1))||((combtype12!=-1)&&(combtype23==-1)&&(combtype13!=-1))||((combtype12!=-1)&&(combtype23!=-1)&&(combtype13==-1)));
	int len1, len2, len3;
	
	EmptypUtter();
	len1=meanutter1->getUtterLen(); len2=meanutter2->getUtterLen(); len3=meanutter3->getUtterLen();
	if(len1+len2+len3>getLengthIntgUtter()) printf("Wrong Comb3Utter!\n");
	else
		{ if(combtype12==-1)
			{ // use combtype23, combtype13 to combine; 
			  if((combtype23==0)&&(combtype13==0))
				{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter2->getpUtter(), len1, 0, len2); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter1, utter2, utter3 (SVO);	
				  else { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter1->getpUtter(), len2, 0, len1); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter2, utter1, utter3 (VSO);
				}
			  else if((combtype23==1)&&(combtype13==0)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter3->getpUtter(), len1, 0, len3); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter1, utter3, utter2 (SOV);
			  else if((combtype23==0)&&(combtype13==1)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter3->getpUtter(), len2, 0, len3); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter2, utter3, utter1 (VOS);
			  else if((combtype23==1)&&(combtype13==1))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter1->getpUtter(), len3, 0, len1); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter3, utter1, utter2 (OSV);
				  else { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter2->getpUtter(), len3, 0, len2); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter3, utter2, utter1 (OVS);
			  	}
			}
		 else if(combtype23==-1)
			{ // use combtype12, combtype13 to combine; 
			  if((combtype12==0)&&(combtype13==0))
				{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter2->getpUtter(), len1, 0, len2); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter1, utter2, utter3 (SVO);
				  else { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter3->getpUtter(), len1, 0, len3); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter1, utter3, utter2 (SOV);
				}
			  else if((combtype12==1)&&(combtype13==0)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter1->getpUtter(), len2, 0, len1); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter2, utter1, utter3 (VSO);
			  else if((combtype12==0)&&(combtype13==1)) { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter1->getpUtter(), len3, 0, len1); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter3, utter1, utter2 (OSV);
			  else if((combtype12==1)&&(combtype13==1))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter3->getpUtter(), len2, 0, len3); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter2, utter3, utter1 (VOS);
			  	  else { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter2->getpUtter(), len3, 0, len2); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter3, utter2, utter1 (OVS);
			  	}
			}
		 else if(combtype13==-1)
			{ // use combtype12, combtype23 to combine; 
			  if((combtype12==0)&&(combtype23==0)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter2->getpUtter(), len1, 0, len2); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter1, utter2, utter3 (SVO);
			  else if((combtype12==1)&&(combtype23==0))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter1->getpUtter(), len2, 0, len1); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter2, utter1, utter3 (VSO);
			  	  else { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter3->getpUtter(), len2, 0, len3); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter2, utter3, utter1 (VOS);
			  	}
			  else if((combtype12==0)&&(combtype23==1))
			  	{ if(FLOAT_SM_EQ(Rand0_1, _Half)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter3->getpUtter(), len1, 0, len3); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter1, utter3, utter2 (SOV);
			  	  else { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter1->getpUtter(), len3, 0, len1); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter3, utter1, utter2 (OSV);
			  	}
			  else if((combtype12==1)&&(combtype23==1)) { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter2->getpUtter(), len3, 0, len2); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter3, utter2, utter1 (OVS);
			}
		 else
			{ // use combtype12, combtype23, combtype13 to combine; 000; 010; 011; 100; 101; 111;
			  if((combtype12==0)&&(combtype23==0)&&(combtype13==0)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter2->getpUtter(), len1, 0, len2); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter1, utter2, utter3 (SVO);
			  else if((combtype12==0)&&(combtype23==1)&&(combtype13==0)) { setPartUtter(meanutter1->getpUtter(), 0, 0, len1); setPartUtter(meanutter3->getpUtter(), len1, 0, len3); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter1, utter3, utter2 (SOV);
			  else if((combtype12==0)&&(combtype23==1)&&(combtype13==1)) { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter1->getpUtter(), len3, 0, len1); setPartUtter(meanutter2->getpUtter(), len1+len3, 0, len2); }	// utter3, utter1, utter2 (OSV);
			  else if((combtype12==1)&&(combtype23==0)&&(combtype13==0)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter1->getpUtter(), len2, 0, len1); setPartUtter(meanutter3->getpUtter(), len1+len2, 0, len3); }	// utter2, utter1, utter3 (VSO);
			  else if((combtype12==1)&&(combtype23==0)&&(combtype13==1)) { setPartUtter(meanutter2->getpUtter(), 0, 0, len2); setPartUtter(meanutter3->getpUtter(), len2, 0, len3); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter2, utter3, utter1 (VOS);
			  else if((combtype12==1)&&(combtype23==1)&&(combtype13==1)) { setPartUtter(meanutter3->getpUtter(), 0, 0, len3); setPartUtter(meanutter2->getpUtter(), len3, 0, len2); setPartUtter(meanutter1->getpUtter(), len2+len3, 0, len1); }	// utter3, utter2, utter1 (OVS);
			}
		}
}

int CMeanUtter::getPred(CSemSpace *semspace)
{ // get Pred;
	assert(semspace!=NULL);
	int i, j;
	int posPred=getLengthSem()+getLengthSemRole();
	
	for(i=0;i<semspace->getNumSemPred();i++)
	  	{ for(j=0;j<getLengthSemItem();j++)
	  		{ if(getpMean()->getElement(j+posPred)!=semspace->getpSemPred(i)->getElement(j)) break;
	  		}
	  	  if(j==getLengthSemItem()) break;
	  	}
	if(i==semspace->getNumSemPred()) return -1;
	else return semspace->TransSemItem(semspace->getpSemPred(i));
}

int CMeanUtter::getAg(CSemSpace *semspace)
{ // get Agent;
	assert(semspace!=NULL);
	int i, j;
	int posAg=getLengthSemRole();
	
	for(i=0;i<semspace->getNumSemAgent();i++)
	  	{ for(j=0;j<getLengthSemItem();j++)
	  		{ if(getpMean()->getElement(j+posAg)!=semspace->getpSemAgent(i)->getElement(j)) break;
	  		}
	  	  if(j==getLengthSemItem()) break;
	 	}
	if(i==semspace->getNumSemAgent()) return -1;
	else return semspace->TransSemItem(semspace->getpSemAgent(i));					  
}

int CMeanUtter::getPat(CSemSpace *semspace)
{ // get Patient;
	assert(semspace!=NULL);
	int i, j;
	int posPat=2*(getLengthSem())+getLengthSemRole();
	
	for(i=0;i<semspace->getNumSemPat();i++)
	 	{ for(j=0;j<getLengthSemItem();j++)
	  		{ if(getpMean()->getElement(j+posPat)!=semspace->getpSemPat(i)->getElement(j)) break;
	  		}
	  	  if(j==getLengthSemItem()) break;
	 	}
	if(i==semspace->getNumSemPat()) return -1;
	else return semspace->TransSemItem(semspace->getpSemPat(i));
}



// CBuffer's membership functions;
CBuffer::CBuffer()
{ // construction function;
	InitBuffer(0, 0);
}

CBuffer::CBuffer(const CBuffer &init)
{ // copy construction function;
	(*this)=init;
}

CBuffer::~CBuffer()
{ // destruction function;
	DestBuffer();
}

CBuffer & CBuffer::operator = (const CBuffer &right)
{ // copy buffer;
	int i;
	if(&right!=this)
		{ // it is not a self-copy;
		  DestBuffer(); InitBuffer(right.m_nCurBufSize, right.m_nMaxBufSize);
		  setBufTyp(right.m_nBufTyp); setRemBuf(right.m_nRemBuf); 
		  setBufTag(right.m_nBufTag);
		  setMaxBufSize(right.m_nMaxBufSize);
		  if(getCurBufSize()!=0)
		  	{ for(i=0;i<getCurBufSize();i++)
		  		{ setpBuf(i, right.m_ppBuf[i]); setpBufInst(i, right.m_pBufInst[i]);
		  		}
		  	}
		}
	return *this;
}

void CBuffer::InitBuffer(int curBufSize, int maxBufSize)
{ // initialization function;
	if(overallpara.p_nVarBufSize==0) assert((0<=curBufSize)&&(curBufSize<=overallpara.p_nMaxBufSize));
	else if(overallpara.p_nVarBufSize==1) assert(curBufSize>=0);
	int i;
	int varBufSize;
	setBufTyp(overallpara.p_nBufTyp); setRemBuf(overallpara.p_nRemBuf); 
	setBufTag(0);
	
	if(overallpara.p_nVarBufSize==0) setMaxBufSize(overallpara.p_nMaxBufSize);
	else if(overallpara.p_nVarBufSize==1) 
		{ if((curBufSize==0)&&(maxBufSize==0))
			{ // initialization!
			  varBufSize=overallpara.p_nMaxBufSize+(int)(sqrt((double)(overallpara.p_nMaxBufSizeVar))*sqrt((double)(-_Twice*log(Rand0_1)))*sin(_Twice*_PI*Rand0_1));
		  	  if(varBufSize<=2) varBufSize=2;
			  setMaxBufSize(varBufSize);
			}
		  else setMaxBufSize(maxBufSize);		  
		}
	
	m_nCurBufSize=curBufSize;
	if(getCurBufSize()==0) { m_ppBuf=NULL; m_pBufInst=NULL; }
	else 
		{ m_ppBuf=new CMeanUtter * [getCurBufSize()]; assert(m_ppBuf!=NULL);
		  m_pBufInst=new int [getCurBufSize()]; assert(m_pBufInst!=NULL);
		  for(i=0;i<getCurBufSize();i++) 
		  	{ m_ppBuf[i]=NULL; m_pBufInst[i]=0;
		  	}
		}		
}

void CBuffer::DestBuffer()
{ // destroy function;
	EmpBuf(); setBufTyp(-1); setRemBuf(-1); setMaxBufSize(0);	
}

// other operations;
void CBuffer::InBuffer(CMeanUtter *&meanutter, int *bufLoc)
{ // put in new meanutter into buffer;
	assert(meanutter!=NULL);
	int i, newBufsize, biginst, smallinst, chosenbuf;
	CMeanUtter **pNewBuf=NULL;
	int *pNewBufInst=NULL;
	bool identical;

	*bufLoc=-1;
	// check the current buffer's state;
	if(getCurBufSize()==0)
		{ // buffer is empty;
		  InitBuffer(1, getMaxBufSize());	// create a location for meanutter;
		  setpBuf(0, meanutter); setpBufInst(0, 1);
		  if(getCurBufSize()==getMaxBufSize()) m_nBufTag=1;
		  *bufLoc=0;
		}
	else if((getCurBufSize()==getMaxBufSize())&&(getBufTag()==1))
		{ // buff is full; 
		  if(getBufTyp()==0)
		  	{ // no consider instance;
		  	  delete m_ppBuf[0]; m_ppBuf[0]=NULL;
			  // store meanutter into m_ppBuf[m_nCurBufSize-1];	
			  for(i=0;i<getCurBufSize()-1;i++)
			  	setpBuf(i, getpBuf(i+1));	// moving m_pBuf[i] to m_ppBuf[i-1];
			  setpBuf(m_nCurBufSize-1, meanutter);	// store meanutter into m_ppBuf[m_nCurBufSize-1];	
			  *bufLoc=getCurBufSize()-1;
		  	}
		  else if((getBufTyp()==1)||(getBufTyp()==2))
		  	{ // consider instance;
		  	  // first, check if there is a same meanutter in the buffer;
		 	  identical=0;	// assume there is no same meanutter in it;
		  	  for(i=0;i<getCurBufSize();i++)
		  		{ if(*(getpBuf(i))==*meanutter) 
		  			{ identical=1; 
			  	 	  if(getBufTyp()==2) setpBufInst(i, getpBufInst(i)+1); 
			  	 	  break; 
					}
		  		}		 
		  	  if(identical==0) 
		 	 	{ if(getBufTyp()==1)
		  	  		{ // if not, empty this->m_ppBuf[0]; 	
				  	  delete m_ppBuf[0]; m_ppBuf[0]=NULL;
				  	  // store meanutter into m_ppBuf[m_nCurBufSize-1];	
				  	  for(i=0;i<getCurBufSize()-1;i++)
				  		setpBuf(i, getpBuf(i+1));	// moving m_pBuf[i] to m_ppBuf[i-1];
				  	  setpBuf(m_nCurBufSize-1, meanutter);	// store meanutter into m_ppBuf[m_nCurBufSize-1];	
					  *bufLoc=getCurBufSize()-1;
			  		}
			  	  else if(getBufTyp()==2)
			  	  	{ // delete m_ppBuf with smallest instance;
			  	  	  biginst=smallinst=1;
					  for(i=0;i<getCurBufSize();i++)
					  	{ if(getpBufInst(i)>=biginst) biginst=getpBufInst(i); }
					  smallinst=biginst;
					  for(i=0;i<getCurBufSize();i++)
					  	{ if(getpBufInst(i)<=smallinst) smallinst=getpBufInst(i); }
					  if(biginst==smallinst)
					  	{ delete m_ppBuf[0]; m_ppBuf[0]=NULL;
				  	  	  // store meanutter into m_ppBuf[m_nCurBufSize-1];	
				  	  	  for(i=0;i<getCurBufSize()-1;i++)
				  			setpBuf(i, getpBuf(i+1));	// moving m_pBuf[i] to m_ppBuf[i-1];
				  	  	  setpBuf(getCurBufSize()-1, meanutter);	// store meanutter into m_ppBuf[m_nCurBufSize-1];	
					 	  setpBufInst(getCurBufSize()-1, 1);
						  *bufLoc=getCurBufSize()-1;
					  	}
					  else
					  	{ do{ chosenbuf=(int)(Rand0_1*getCurBufSize());
					  	  }while((chosenbuf==getCurBufSize())||(getpBufInst(chosenbuf)!=smallinst));
					  	  delete m_ppBuf[chosenbuf]; m_ppBuf[chosenbuf]=NULL;
					  	  m_ppBuf[chosenbuf]=meanutter;
					  	  setpBufInst(chosenbuf, 1);	// reset the instance;
					  	  *bufLoc=chosenbuf;
			  	  		}
			  	  	}
		  	  	}
			  else { delete meanutter; meanutter=NULL; }
			}
		}
	else
		{ // buffer is not full;
		  if(getBufTyp()==0)
		  	{ newBufsize=getCurBufSize()+1;
			  pNewBuf=new CMeanUtter * [newBufsize]; assert(pNewBuf!=NULL);
			  for(i=0;i<newBufsize;i++)
			  	pNewBuf[i]=NULL;
			  pNewBufInst=new int [newBufsize]; assert(pNewBufInst!=NULL);
			  // copy original meanutter by address!
			  for(i=0;i<newBufsize-1;i++)
			  	{ pNewBuf[i]=getpBuf(i); pNewBufInst[i]=getpBufInst(i); }
			  pNewBuf[newBufsize-1]=meanutter; pNewBufInst[newBufsize-1]=1;
			  // delete original m_ppBuf, m_pBufInst;
			  delete [] m_ppBuf; m_ppBuf=NULL;
			  delete [] m_pBufInst; m_pBufInst=NULL;
			  m_nCurBufSize=0;
			  // copy pNewBuf to m_ppBuf;
			  m_nCurBufSize=newBufsize; 
			  m_ppBuf=pNewBuf; m_pBufInst=pNewBufInst;
			  if(getCurBufSize()==getMaxBufSize()) m_nBufTag=1;
			  pNewBuf=NULL;	// recollect pNewBuf;
			  *bufLoc=getCurBufSize()-1;
		  	}
		  else if((getBufTyp()==1)||(getBufTyp()==2))
		  	{ // first, check if there is a same meanutter in the buffer;
		  	  identical=0;	// assume there is no same meanutter in it;
		  	  for(i=0;i<getCurBufSize();i++)
		 	 	{ if(*(getpBuf(i))==*meanutter) 
		  			{ identical=1; 
			  		  if(getBufTyp()==2) setpBufInst(i, getpBufInst(i)+1); 
					  break;
					}
		  		}		 
		  	  if(identical==0)
			  	{ // if not, increase the current buffer size and insert meanutter;
				  newBufsize=getCurBufSize()+1;
				  pNewBuf=new CMeanUtter * [newBufsize]; assert(pNewBuf!=NULL);
				  for(i=0;i<newBufsize;i++)
				  	pNewBuf[i]=NULL;
				  pNewBufInst=new int [newBufsize]; assert(pNewBufInst!=NULL);
				  // copy original meanutter by address!
				  for(i=0;i<newBufsize-1;i++)
				  	{ pNewBuf[i]=getpBuf(i); pNewBufInst[i]=getpBufInst(i); }
				  pNewBuf[newBufsize-1]=meanutter; pNewBufInst[newBufsize-1]=1;
				  // delete original m_ppBuf, m_pBufInst;
				  delete [] m_ppBuf; m_ppBuf=NULL;
				  delete [] m_pBufInst; m_pBufInst=NULL;
				  m_nCurBufSize=0;
				  // copy pNewBuf to m_ppBuf;
				  m_nCurBufSize=newBufsize; 
				  m_ppBuf=pNewBuf; m_pBufInst=pNewBufInst;
				  if(getCurBufSize()==getMaxBufSize()) m_nBufTag=1;
				  pNewBuf=NULL;	// recollect pNewBuf;
				  *bufLoc=getCurBufSize()-1;
				}
			  else { delete meanutter; meanutter=NULL; }
			}
		}
}

void CBuffer::OutBuffer(int ind)
{ // remove from buffer;
	assert((0<=ind)&&(ind<getCurBufSize()));
	int i, j, newBufsize;
	CMeanUtter **pNewBuf=NULL;
	int *pNewBufInst=NULL;
	
	newBufsize=getCurBufSize()-1;
	if(newBufsize==0) DestBuffer();
	else
		{ delete m_ppBuf[ind]; m_ppBuf[ind]=NULL;
		  pNewBuf=new CMeanUtter * [newBufsize]; assert(pNewBuf!=NULL);
		  for(i=0;i<newBufsize;i++)
		  	pNewBuf[i]=NULL;
		  pNewBufInst=new int [newBufsize]; assert(pNewBufInst!=NULL);
		  // copy original meanutter by address!
		  j=0;
		  for(i=0;i<newBufsize+1;i++)
		 	{ if(i!=ind) 
				{ pNewBuf[j]=getpBuf(i); pNewBufInst[j]=getpBufInst(i);
				  j++;
				}
	  		}
		  // delete original m_ppBuf, m_pBufInst;
		  delete [] m_ppBuf; m_ppBuf=NULL;
		  delete [] m_pBufInst; m_pBufInst=NULL;
		  m_nCurBufSize=0;
		  // copy pNewBuf to m_ppBuf;
		  m_nCurBufSize=newBufsize; 
		  m_ppBuf=pNewBuf; m_pBufInst=pNewBufInst;
		  if(getCurBufSize()<getMaxBufSize()) m_nBufTag=0;
		}
}

void CBuffer::OutputBuf()
{ // output CBuffer;
	int i;
	printf("Buftag=%d, Curbufsize=%d, Maxbufzie=%d\n", getBufTag(), getCurBufSize(), getMaxBufSize());
	for(i=0;i<getCurBufSize();i++)
		{ printf("Buf[%d](%d):\n", i, getpBufInst(i));  
		  getpBuf(i)->getpMean()->OutputArray(); getpBuf(i)->getpUtter()->OutputArray();
		}		  
}
