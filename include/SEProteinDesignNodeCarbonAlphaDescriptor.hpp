/// \headerfile SBProxy.hpp "SBProxy.hpp"
#include "SBProxy.hpp"

/// \headerfile SEProteinDesignNodeCarbonAlpha.hpp "SEProteinDesignNodeCarbonAlpha.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"


// Class descriptor

// SAMSON Element generator pro tip: complete this descriptor to expose this class to SAMSON and other SAMSON Elements

SB_CLASS_BEGIN(SEProteinDesignNodeCarbonAlpha);

	SB_CLASS_TYPE(SBCClass::Custom);
	SB_CLASS_DESCRIPTION("SEProteinDesignNodeCarbonAlpha : SAMSON Element generator pro tip: modify me");

	SB_FACTORY_BEGIN;

		SB_CONSTRUCTOR_0(SEProteinDesignNodeCarbonAlpha);
		//SB_CONSTRUCTOR_0(SEProteinDesignNodeCarbonAlpha, const SBPosition3&); // The constructor which creates a carbon according to a position
	SB_FACTORY_END;

	SB_INTERFACE_BEGIN;

	SB_INTERFACE_END;

SB_CLASS_END(SEProteinDesignNodeCarbonAlpha);

