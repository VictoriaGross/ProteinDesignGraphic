#pragma once


#include "SBGDataGraphNodeProperties.hpp" 
#include "ui_SEProteinDesignNodeConstructionPointProperties.h"
#include "SBPointer.hpp"
#include "SEProteinDesignNodeConstructionPoint.hpp"


/// This class implements the property window of the node

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEProteinDesignNodeConstructionPoint class

// SAMSON Element generator pro tip: if you do not want to have a property window associated to your node, do not expose it in the descriptor. 
// Precisely, remove the line SB_ELEMENT_CLASS(SEProteinDesignNodeConstructionPointProperties); from the file SEProteinDesignDescriptor.cpp

class SEProteinDesignNodeConstructionPointProperties : public SBGDataGraphNodeProperties {

	SB_CLASS
	Q_OBJECT

public:

	/// \name Constructors and destructors
	//@{

	SEProteinDesignNodeConstructionPointProperties();																								///< Constructs a widget to show the properties of the node
	virtual ~SEProteinDesignNodeConstructionPointProperties();																						///< Destructs the widget

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

		Observer(SEProteinDesignNodeConstructionPointProperties* properties);
		virtual ~Observer();

		friend class SEProteinDesignNodeConstructionPointProperties;

		void														onBaseEvent(SBBaseEvent* baseEvent);								///< Base event management

		SEProteinDesignNodeConstructionPointProperties* properties;

	};

private:

	friend class SEProteinDesignNodeConstructionPoint;
	Ui::SEProteinDesignNodeConstructionPointPropertiesClass							ui;
	SBPointer<SEProteinDesignNodeConstructionPoint>									node;

	SBPointer<Observer>											observer;

};

SB_REGISTER_TYPE(SEProteinDesignNodeConstructionPointProperties, "SEProteinDesignNodeConstructionPointProperties", "F8C46B00-B2E5-AE0C-6FD5-D482FD7B4B4A");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeConstructionPointProperties, SBGDataGraphNodeProperties);
