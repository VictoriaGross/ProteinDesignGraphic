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

#include <QList>


/// This class implements an editor

class SEProteinDesignEditorHelix : public SBGEditor {

	SB_CLASS
		Q_OBJECT

public:

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

																																					//}@

																																					/*void setBegin(SBPosition3&);
																																					void setEnd(SBPosition3&);*/

	void setCurrentEnd(SEProteinDesignNodeConstructionPoint* point);
	void setCurrentBegin(SEProteinDesignNodeConstructionPoint* point);
	SEProteinDesignNodeConstructionPoint* getCurrentBegin();
	SEProteinDesignNodeConstructionPoint* getCurrentEnd();

	// Functions to manage the lists of construction points
	//void addBeginPoint(SEProteinDesignNodeConstructionPoint* pathNode, SEProteinDesignVisualModelBackbone* helix = 0);
	//void addEndPoint(SEProteinDesignNodeConstructionPoint* pathNode, SEProteinDesignVisualModelBackbone* helix = 0);
	//void removeEndPoint(SEProteinDesignNodeConstructionPoint* pathNode, SEProteinDesignVisualModelBackbone* helix = 0);
	//void removeBeginPoint(SEProteinDesignNodeConstructionPoint* pathNode, SEProteinDesignVisualModelBackbone* helix = 0);


	SEProteinDesignVisualModelBackbone* getHelix(SEProteinDesignNodeConstructionPoint* point);

private:

	//The pointers to the beginning and end of the current helix
	SEProteinDesignNodeConstructionPoint* beginHelixCurrent;
	SEProteinDesignNodeConstructionPoint* endHelixCurrent;
	SBPointer<SEProteinDesignVisualModelBackbone> path;

	// To manage the construction points and helixes
	//QList<SEProteinDesignNodeConstructionPoint*> beginHelixList;
	//QList<SEProteinDesignNodeConstructionPoint*> endHelixList;
	QList<SEProteinDesignVisualModelBackbone*> helixList;


	SEProteinDesignNodeConstructionPoint* selectedPathNode;


};


SB_REGISTER_TYPE(SEProteinDesignEditorHelix, "SEProteinDesignEditorHelix", "F85F4256-1864-1242-1761-E23D846D9941");
SB_DECLARE_BASE_TYPE(SEProteinDesignEditorHelix, SBGEditor);