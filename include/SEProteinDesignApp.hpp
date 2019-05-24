#pragma once 

#include "SBDApp.hpp"
#include "SEProteinDesignAppGUI.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"
#include"SEProteinDesignNodeConstructionPoint.hpp"
#include "SEProteinDesignVisualModelBackbone.hpp"
#include "SEProteinDesignVisualModelCurve.hpp"



/// This class implements the functionality of the app

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SEProteinDesignAppGUI class

class SEProteinDesignApp : public SBDApp {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignApp();																													///< Constructs an app
	virtual ~SEProteinDesignApp();																											///< Destructs the app

	//@}

	/// \name GUI
	//@{

	SEProteinDesignAppGUI*											getGUI() const;															///< Returns a pointer to the GUI of the app

	//@}

	SBNodeIndexer getListNodes();
private: 
	SBPointerList< SBMVisualModel > const* visualModelList;

};


SB_REGISTER_TARGET_TYPE(SEProteinDesignApp, "SEProteinDesignApp", "7DED4BC1-3BA3-AB72-CCE1-881CECDF1267");
SB_DECLARE_BASE_TYPE(SEProteinDesignApp, SBDApp);
