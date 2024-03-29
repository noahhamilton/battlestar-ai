/***************************************************************
 
 Battlestar-AI Battleship AI
 Pennsylvania State University - CMPSC 442
 
 This source file is developed and maintained by:
 + Jeremy Bridon jbridon@psu.edu
 
 File: GASinking.h
 Desc: The sinking AI which is based on a genetic program.
 
***************************************************************/

// Inclusion guard
#ifndef __GASINKING_H_
#define __GASINKING_H_

// Includes
#include "Util.h"
#include "Ships.h"
#include "Board1.h"
#include "GASinkingGene.h"

// Sinking management
class GASinking
{
public:

	// Build up gene pool
	GASinking(int Board1Width, int Board1Height, char *OpponentName);

	// Release all data and save best gene to drive
	~GASinking();

	// Save enemy board placement (Used for gene fitness management)
	void SaveEnemyBoard1(Ship *ShipsList, int ShipCount);

	// Update the entire gene pool by applying our gene-fitness and breeding functions
	// Prepare our main gene for the next round
	void Update();

	// Run through the current gene
	// Logic: Call this function and check the returned GARunState,
	// and if it is a request, fill out the given params correctly
	// and if it is a post-shot status update, fill out the given params correctly
	GARunState Run(int *DataX, int *DataY, bool Hit);

	// Get a pointer to the best gene
	GASinkingGene *GetBest();

private:

	// Gene pool
	GASinkingGene *GenePool[GA_MAX_POOL];

	// Board1 size
	int Board1Width, Board1Height;

	// Enemy name
	char OpponentName[128];

};

// End of inclusion guard
#endif
