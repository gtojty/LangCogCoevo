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

#pragma once

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstring>

/////////////////////////////////////////////////////////////////////////////
//	Period parameters

#define MT_N			(624)			// length of state vector
#define MT_M			(397)			// period constant
#define MT_K			(0x9908B0DFU)	

#define MT_HIBIT(u)		((u) & 0x80000000U)				// mask all but the highest bit of u
#define MT_LOBIT(u)		((u) & 0x00000001U)				// mask all but the lowest bit of u
#define MT_LOBITS(u)	((u) & 0x7FFFFFFFU)				// mask	the highest bit of u

#define MT_MIXBITS(u,v)	(MT_HIBIT (u) | MT_LOBITS (v))	// move hi bit of u to hi bit of v		

/////////////////////////////////////////////////////////////////////////////
//	Other parameters

#define MT_SEED_DEFAULT				(4357U)
#define MT_RAND_MAX					(4294967295U)				// 2^32 - 1
#define MT_RAND_FLOAT_MULTIPLIER	(2.328306437080797e-010)	// 1.0 / (2^32 - 1)

/////////////////////////////////////////////////////////////////////////////
//	Class CRandomNumber

class CRandomNumber {

/////////////////////////////////////////////////////////////////////////////
//	Static Interface

public:

	/////////////////////////////////////////////////////////////////////////
	// Seed ()
	//	Call this function to apply a new seed.
	//	The seed can be any integer in the range [0, MT_RAND_MAX].
	//	Since odd seeds give better performance, the function forces an odd seed.

	static unsigned long Seed (unsigned long ulSeed = 0)    // seed (requested)
    	{
        	if (ulSeed == 0) ulSeed = (unsigned long) ::time (NULL);	// Set a random seed based on the current time
        	
        	m_ulSeed = (ulSeed | 1U) & 0xFFFFFFFFU;    // force odd seed

        	register unsigned long ulX = m_ulSeed, *pS = m_ulState;
        	register int j;

        	for (CRandomNumber::m_nLeft = 0, *pS++ = ulX, j = MT_N;
             	--j;
             	*pS++ = (ulX *= 69069U) & 0xFFFFFFFFU);
        	
        	return m_ulSeed;	// Return the seed
    	} 
	

	/////////////////////////////////////////////////////////////////////////
	// SeedDefault ()
	// Call this function to apply a default seed.

	inline static unsigned long SeedDefault () { return Seed (MT_SEED_DEFAULT); }
	

	/////////////////////////////////////////////////////////////////////////
	// Rand ()
	//	Call this function to generate a new random number.

	static unsigned long Rand ()
	{	unsigned long ulY;
		 
		if (--m_nLeft < 0) ulY = Reload ();
		else ulY = *m_pulNext++;
		
		ulY ^= (ulY >> 11);
		ulY ^= (ulY <<  7) & 0x9D2C5680U;
		ulY ^= (ulY << 15) & 0xEFC60000U;
		ulY ^= (ulY >> 18);

		return ulY;
	}


	/////////////////////////////////////////////////////////////////////////
	// Uniform ()
	//	Call this function to generate a uniform random number on [0.0, lfHi].

	inline static double Uniform (double lfHi = 1.0) { return lfHi * ((double) Rand () / MT_RAND_MAX); }


	/////////////////////////////////////////////////////////////////////////
	// Integer ()
	//	Call this function to generate a new uniform random integer in [0, unHi-1].

	inline static unsigned long Integer (unsigned long unHi) { return (unsigned long) (unHi * ((Rand () % MT_RAND_MAX) / (double) MT_RAND_MAX)); }


	/////////////////////////////////////////////////////////////////////////
	// Boolean ()
	//	Call this function to generate a new random boolean.

	inline static bool Boolean () { return (Uniform () > 0.5); }


	/////////////////////////////////////////////////////////////////////////
	// GetState ()
	//	Call this function to obtain the current state of the generator.

	static void GetState (unsigned long& rulSeed, int& rnLeft, unsigned long*& rpulNext, unsigned long*& rpulState)
	{
		rulSeed = m_ulSeed;
		rnLeft = m_nLeft;
		rpulNext = m_pulNext;

		rpulState = new unsigned long [MT_N + 1];
		for (int n = 0; n <= MT_N; n++)
			rpulState[n] = m_ulState[n];		
	}


	/////////////////////////////////////////////////////////////////////////
	// WriteState ()
	//	Call this function to write the current state of the generator to file.

	static char* WriteState ()
	{
		char  pszBuffer [12];
		char* pszStateString = new char [(MT_N + 3) * 9 - 1];
		pszStateString[0] = '\0';

		if (pszStateString != NULL)
		{	
			sprintf(pszBuffer, "%x", MT_N);
			strcat (pszStateString, pszBuffer);
			strcat (pszStateString, ",");

			for (int n = 0; n <= MT_N; n++)
			{	sprintf(pszBuffer, "%lx", m_ulState[n]);
				strcat (pszStateString, pszBuffer);
				strcat (pszStateString, ",");
			}
			
			sprintf(pszBuffer, "%x", m_nLeft);
			strcat (pszStateString, pszBuffer);
			strcat (pszStateString, ",");

			sprintf(pszBuffer, "%lx", m_ulSeed);
			strcat (pszStateString, pszBuffer);
		}

		return pszStateString;
	}


	/////////////////////////////////////////////////////////////////////////
	// SetState ()
	//	Call this function to set the generator to the specified state.

	static void SetState (unsigned long ulSeed, int nLeft, unsigned long* rpulNext, unsigned long* pulState)
	{
		m_ulSeed = ulSeed;
		m_nLeft = nLeft;
		m_pulNext = rpulNext;

		for (int n = 0; n<= MT_N; n++)
			m_ulState[n] = pulState[n];
	}


	/////////////////////////////////////////////////////////////////////////
	// ReadState ()
	//	Call this function to read the current state of the generator from file.

	static void ReadState (const char* const cpcszStateString)
	{
		if ((cpcszStateString != NULL) &&
			(strlen (cpcszStateString) > 0))
		{
			char* psz = const_cast <char*> (cpcszStateString);

			unsigned long ulStateSize;
			sscanf (psz, "%lx", &ulStateSize);
			assert (ulStateSize == MT_N);

			// Read state vector
			for (unsigned long ul = 0; ul <= ulStateSize; ul++)
			{
				psz = strchr (psz, ',') + 1;
				sscanf (psz, "%lx", &m_ulState[ul]);
			}

			// Read number of calls remaining
			psz = strchr (psz, ',') + 1;
			sscanf (psz, "%x", &m_nLeft);

			// Read seed
			psz = strchr (psz, ',') + 1;
			sscanf (psz, "%lx", &m_ulSeed);
		}
	}

	
/////////////////////////////////////////////////////////////////////////////
//	Protected Interface

protected:

	/////////////////////////////////////////////////////////////////////////
	// Reload ()
	//	Call this function when all MT_N random numbers have been generated.

	static unsigned long Reload ()
	{
		register unsigned long *pul0 = m_ulState, 
						*pul2 = m_ulState + 2,
						*pulM = m_ulState + MT_M,
						ulS0,
						ulS1;
		register int j;

		// If the random number generator has not yet been seeded,
		// apply the current seed
		if (m_nLeft < -1)
		{
			Seed (m_ulSeed);
		}

		m_nLeft = MT_M - 1,
		m_pulNext = m_ulState + 1;

		for (ulS0 = m_ulState[0], ulS1 = m_ulState[1], j = MT_N - MT_M + 1;
			 --j;
			 ulS0 = ulS1, ulS1 = *pul2++)
		{
			*pul0++ = *pulM++ ^ (MT_MIXBITS(ulS0, ulS1) >> 1) ^ (MT_LOBIT(ulS1) ? (MT_K) : (0U));
		}

		for (pulM = m_ulState, j = MT_M;
			 --j;
			 ulS0 = ulS1, ulS1 = *pul2++)
		{
			*pul0++ = *pulM++ ^ (MT_MIXBITS(ulS0, ulS1) >> 1) ^ (MT_LOBIT(ulS1) ? (MT_K) : (0U));
		}
			 
		ulS1 = m_ulState[0],
		*pul0 = *pulM ^ (MT_MIXBITS(ulS0, ulS1) >> 1) ^ (MT_LOBIT(ulS1) ? MT_K : 0U);

		return ulS1;
	}


/////////////////////////////////////////////////////////////////////////////
//	Static Data

public:

	static const unsigned long RandomNumberMax;
	static const unsigned long DefaultSeed;

//protected:
private:

	static unsigned long  m_ulSeed;
	static unsigned long  m_ulState [MT_N + 1];
	static unsigned long* m_pulNext;
	static int m_nLeft;

};
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
