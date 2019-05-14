#pragma once 

#include "SBGEditor.hpp"
#include "SEProteinDesignEditorHelixGUI.hpp"

#include "SBBaseEvent.hpp"
#include "SBDocumentEvent.hpp"
#include "SBDynamicalEvent.hpp"
#include "SBStructuralEvent.hpp"
#include "SBAction.hpp"

// We will need to use construction points and carbon alpha
#include "SEProteinDesignNodeConstructionPoint.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"

// We will need to access the backbone visual model
#include "SEProteinDesignVisualModelBackbone.hpp"


/// This class implements an editor

class SEProteinDesignEditorHelix : public SBGEditor {

	SB_CLASS
	Q_OBJECT

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignEditorHelix();																													///< Builds an editor					
	virtual ~SEProteinDesignEditorHelix();																											///< Destructs the editor

	//@}

	/// \name Identity
	//@{

	virtual SBCContainerUUID									getUUID() const;														///< Returns the widget UUID
	virtual QString												getName() const;														///< Returns the class name
	virtual QString												getDescription() const;													///< Returns the menu item text
	virtual QPixmap												getLogo() const;														///< Returns the pixmap logo
	virtual int													getFormat() const;														///< Returns the format
	virtual QKeySequence										getShortcut() const;													///< Returns the shorcut
	virtual QString												getToolTip() const;														///< Returns the tool tip

	//@}

	///\name Settings
	//@{

	virtual void												loadSettings(SBGSettings* settings);									///< Loads \p settings
	virtual void												saveSettings(SBGSettings* settings);									///< Saves \p settings

	//@}

	/// \name Editing
	//@{

	virtual void												beginEditing();															///< Called when editing is about to begin
	virtual void												endEditing();															///< Called when editing is about to end

	//@}

	/// \name Actions
	//@{

	virtual void												getActions(SBVector<SBAction*>& actionVector);							///< Gets the editor's actions

	//@}

	/// \name Rendering
	//@{

	virtual void												display();																///< Displays the editor
	virtual void												displayForShadow();														///< Displays the editor for shadow purposes
	virtual void												displayInterface();														///< Displays the 2D interface in the viewport

	//@}

	/// \name GUI Events
	//@{

	virtual void												mousePressEvent(QMouseEvent* event);									///< Handles mouse press event
	virtual void												mouseReleaseEvent(QMouseEvent* event);									///< Handles mouse release event
	virtual void												mouseMoveEvent(QMouseEvent* event);										///< Handles mouse move event
	virtual void												mouseDoubleClickEvent(QMouseEvent* event);								///< Handles mouse double click event

	virtual void												wheelEvent(QWheelEvent* event);											///< Handles wheel event

	virtual void												keyPressEvent(QKeyEvent* event);										///< Handles key press event
	virtual void												keyReleaseEvent(QKeyEvent* event);										///< Handles key release event

	//@}

	/// \name SAMSON Events
	//@{

	virtual void												onBaseEvent(SBBaseEvent* baseEvent);									///< Handles base events
	virtual void												onDynamicalEvent(SBDynamicalEvent* dynamicalEvent);						///< Handles dynamical events
	virtual void												onDocumentEvent(SBDocumentEvent* documentEvent);						///< Handles document events
	virtual void												onStructuralEvent(SBStructuralEvent* documentEvent);					///< Handles structural events

	//@}

	/// \name GUI
	//@{

	SEProteinDesignEditorHelixGUI*											getPropertyWidget() const;												///< Returns the property widget of the editor
	
	void setLastCarbon(SEProteinDesignNodeCarbonAlpha& Carbon);
	const SEProteinDesignNodeCarbonAlpha getLastCarbon();
	void setPathLength(float& size);
	const float getPathLength();
	void setBeginning(SBPosition3& position);
	//void setEnd(SBPosition3& position);
	const SBPosition3 getBeginningPosition();
	//const SBPosition3 getEndPosition();
	//SEProteinDesignNodeConstructionPoint getBeginningPoint();
	//SEProteinDesignNodeConstructionPoint getEndPoint();
	//@}

private:

	// We store a pointer to the path that we create with the helix
	SBPointer<SEProteinDesignVisualModelBackbone> path;
	// This pointer will be non-zero whenever we are creating or updating an helix and zero otherwise
	
	// We store the length of the path to access it easily and the pointer to the last Carbon
	unsigned int pathLength;
	SEProteinDesignNodeCarbonAlpha LastCarbon;

	/*SEProteinDesignNodeConstructionPoint beginHelix;
	SEProteinDesignNodeConstructionPoint endHelix;*/
	
	// We store the beginning of the helix
	SBPosition3 beginning;


};


SB_REGISTER_TYPE(SEProteinDesignEditorHelix, "SEProteinDesignEditorHelix", "F85F4256-1864-1242-1761-E23D846D9941");
SB_DECLARE_BASE_TYPE(SEProteinDesignEditorHelix, SBGEditor);