#pragma once


#include "SBGDataGraphNodeProperties.hpp" 
#include "ui_SEProteinDesignNodeCarbonAlphaProperties.h"
#include "SBPointer.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"


/// This class implements the property window of the node

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEProteinDesignNodeCarbonAlpha class

// SAMSON Element generator pro tip: if you do not want to have a property window associated to your node, do not expose it in the descriptor. 
// Precisely, remove the line SB_ELEMENT_CLASS(SEProteinDesignNodeCarbonAlphaProperties); from the file SEProteinDesignDescriptor.cpp

class SEProteinDesignNodeCarbonAlphaProperties : public SBGDataGraphNodeProperties {

	SB_CLASS
	Q_OBJECT

public:

	/// \name Constructors and destructors
	//@{

	SEProteinDesignNodeCarbonAlphaProperties();																								///< Constructs a widget to show the properties of the node
	virtual ~SEProteinDesignNodeCarbonAlphaProperties();																						///< Destructs the widget

	//@}

	/// \name Identity
	//@{

	virtual SBCContainerUUID									getUUID() const;														///< Returns the widget UUID
	virtual QString												getName() const;														///< Returns the widget name (used as a title for the embedding window)
	virtual QPixmap												getLogo() const;														///< Returns the widget logo
	int															getFormat() const;														///< Returns the widget format
	virtual QString												getCitation() const;													///< Returns the citation information

	//@}

	///\name Settings
	//@{

	void														loadSettings(SBGSettings* settings);									///< Load GUI settings
	void														saveSettings(SBGSettings* settings);									///< Save GUI settings

	//@}

	///\name Setup
	//@{

	virtual bool												setup();																///< Initializes the properties widget
	virtual bool												setup(SBNode* node);													///< Initializes the properties widget

	//@}

	class Observer : public SBCReferenceTarget {

		Observer(SEProteinDesignNodeCarbonAlphaProperties* properties);
		virtual ~Observer();

		friend class SEProteinDesignNodeCarbonAlphaProperties;

		void														onBaseEvent(SBBaseEvent* baseEvent);								///< Base event management

		SEProteinDesignNodeCarbonAlphaProperties* properties;

	};

private:

	friend class SEProteinDesignNodeCarbonAlpha;
	Ui::SEProteinDesignNodeCarbonAlphaPropertiesClass							ui;
	SBPointer<SEProteinDesignNodeCarbonAlpha>									node;

	SBPointer<Observer>											observer;

};

SB_REGISTER_TYPE(SEProteinDesignNodeCarbonAlphaProperties, "SEProteinDesignNodeCarbonAlphaProperties", "986B3068-9F9F-FE9F-C541-476F959D9733");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeCarbonAlphaProperties, SBGDataGraphNodeProperties);
