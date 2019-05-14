/// \headerfile SBProxy.hpp "SBProxy.hpp"
#include "SBProxy.hpp"

/// \headerfile SEProteinDesignVisualModelBackbone.hpp "SEProteinDesignVisualModelBackbone.hpp"
#include "SEProteinDesignVisualModelBackbone.hpp"


// Class descriptor

// SAMSON Element generator pro tip: complete this descriptor to expose this class to SAMSON and other SAMSON Elements

SB_CLASS_BEGIN(SEProteinDesignVisualModelBackbone);

	SB_CLASS_TYPE(SBCClass::VisualModel);
	SB_CLASS_DESCRIPTION("SEProteinDesignVisualModelBackbone : SAMSON Element generator pro tip: modify me");

	SB_FACTORY_BEGIN;

		SB_CONSTRUCTOR_0(SEProteinDesignVisualModelBackbone);
		SB_CONSTRUCTOR_1(SEProteinDesignVisualModelBackbone, const SBNodeIndexer&);

	SB_FACTORY_END;

	SB_INTERFACE_BEGIN;

	SB_INTERFACE_END;

SB_CLASS_END(SEProteinDesignVisualModelBackbone);

