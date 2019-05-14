#pragma once


#include "SBGDataGraphNodeProperties.hpp" 
#include "ui_SEProteinDesignVisualModelBackboneProperties.h"
#include "SBPointer.hpp"
#include "SEProteinDesignVisualModelBackbone.hpp"


/// This class implements the property window of the visual model

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEProteinDesignVisualModelBackbone class

// SAMSON Element generator pro tip: if you do not want to have a property window associated to your visual model, do not expose it in the descriptor. 
// Precisely, remove the line SB_ELEMENT_CLASS(SEProteinDesignVisualModelBackboneProperties); from the file SEProteinDesignDescriptor.cpp

class SEProteinDesignVisualModelBackboneProperties : public SBGDataGraphNodeProperties {

	SB_CLASS
	Q_OBJECT

public:

	/// \name Constructors and destructors
	//@{

	SEProteinDesignVisualModelBackboneProperties();																								///< Constructs a widget to show the properties of the visual model
	virtual ~SEProteinDesignVisualModelBackboneProperties();																						///< Destructs the widget

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

		Observer(SEProteinDesignVisualModelBackboneProperties* properties);
		virtual ~Observer();

		friend class SEProteinDesignVisualModelBackboneProperties;

		void														onBaseEvent(SBBaseEvent* baseEvent);								///< Base event management
		void														onVisualEvent(SBVisualEvent* visualEvent);							///< Visual event management

		SEProteinDesignVisualModelBackboneProperties* properties;

	};

private:

	friend class SEProteinDesignVisualModelBackbone;
	Ui::SEProteinDesignVisualModelBackbonePropertiesClass							ui;
	SBPointer<SEProteinDesignVisualModelBackbone>									visualModel;

	SBPointer<Observer>											observer;

};

SB_REGISTER_TYPE(SEProteinDesignVisualModelBackboneProperties, "SEProteinDesignVisualModelBackboneProperties", "47352F94-1563-8A2A-67F5-5BE7ED21E183");
SB_DECLARE_BASE_TYPE(SEProteinDesignVisualModelBackboneProperties, SBGDataGraphNodeProperties);
