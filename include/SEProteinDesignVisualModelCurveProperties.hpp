#pragma once


#include "SBGDataGraphNodeProperties.hpp" 
#include "ui_SEProteinDesignVisualModelCurveProperties.h"
#include "SBPointer.hpp"
#include "SEProteinDesignVisualModelCurve.hpp"


/// This class implements the property window of the visual model

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEProteinDesignVisualModelCurve class

// SAMSON Element generator pro tip: if you do not want to have a property window associated to your visual model, do not expose it in the descriptor. 
// Precisely, remove the line SB_ELEMENT_CLASS(SEProteinDesignVisualModelCurveProperties); from the file SEProteinDesignDescriptor.cpp

class SEProteinDesignVisualModelCurveProperties : public SBGDataGraphNodeProperties {

	SB_CLASS
	Q_OBJECT

public:

	/// \name Constructors and destructors
	//@{

	SEProteinDesignVisualModelCurveProperties();																								///< Constructs a widget to show the properties of the visual model
	virtual ~SEProteinDesignVisualModelCurveProperties();																						///< Destructs the widget

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

		Observer(SEProteinDesignVisualModelCurveProperties* properties);
		virtual ~Observer();

		friend class SEProteinDesignVisualModelCurveProperties;

		void														onBaseEvent(SBBaseEvent* baseEvent);								///< Base event management
		void														onVisualEvent(SBVisualEvent* visualEvent);							///< Visual event management

		SEProteinDesignVisualModelCurveProperties* properties;

	};

private:

	friend class SEProteinDesignVisualModelCurve;
	Ui::SEProteinDesignVisualModelCurvePropertiesClass							ui;
	SBPointer<SEProteinDesignVisualModelCurve>									visualModel;

	SBPointer<Observer>											observer;

};

SB_REGISTER_TYPE(SEProteinDesignVisualModelCurveProperties, "SEProteinDesignVisualModelCurveProperties", "5995CCB5-65CD-0FDF-20AC-68E1D29E8C27");
SB_DECLARE_BASE_TYPE(SEProteinDesignVisualModelCurveProperties, SBGDataGraphNodeProperties);
