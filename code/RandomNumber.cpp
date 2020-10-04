/////////////////////////////////////////////////////////////////////////////
//
//	Namespace: JWM
//	Class:     CRandomNumber
//
/////////////////////////////////////////////////////////////////////////////
//
//	Version 1.00		December 20, 2005
//	Version 1.10		February 6, 2006
//
/////////////////////////////////////////////////////////////////////////////
//
//	Mersenne Twister Pseudo-Random Number Generator MT19937.
//
//	Ported from code written by M. Matsumoto and T. Nishimura:
//
//		http://www.math.keio.ac.jp/~matumoto/emt.html
//
//		Copyright (C) 1997 Makoto Matsumoto and Takuji Nishimura
//			<matumoto@math.keio.ac.jp>
//
//	which was iself adapted by Shawn Cokus
//			<cokus@math.washington.edu>
//
/////////////////////////////////////////////////////////////////////////////
//
//	This class generates pseudo-random integers in the range [0, 2^32 - 1].
//
//	This class has ONLY a static interface;
//	no objects of type CRandomNumber can be constructed.
//
//	To generate random numbers, first seed the random number generator.
//	The seed can be any integer in the range [0, 2^32 - 1], although 
//	odd integers work better as they avoid decidedly "un-random" sequences.
//
//	Then, call one of the following functions:
//
//		unsigned long CRandomNumber::Rand ();
//		double        CRandomNumber::Uniform (double lfHi);
//		unsigned long CRandomNumber::Integer (unsigned long unHi);
//		bool          CRandomNumber::Boolean ();
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
// ---- Include Files;
#include "RandomNumber.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
//	Static Initialization

const unsigned long CRandomNumber::RandomNumberMax = MT_RAND_MAX;
const unsigned long CRandomNumber::DefaultSeed = MT_SEED_DEFAULT;

unsigned long  CRandomNumber::m_ulSeed = MT_SEED_DEFAULT;
unsigned long  CRandomNumber::m_ulState [MT_N + 1];
unsigned long* CRandomNumber::m_pulNext = CRandomNumber::m_ulState;

int CRandomNumber::m_nLeft = -1;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
