#pragma once 

#include "SBGDataGraphNode.hpp"


/// This class implements the GUI of a node

class SEProteinDesignNodeConstructionPointGUI : public SBGDataGraphNode {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignNodeConstructionPointGUI();																														///< Builds a GUI class for a node				
	virtual ~SEProteinDesignNodeConstructionPointGUI();																											///< Destructs the GUI class of a node

	//@}

	/// \name Actions
	//@{

	virtual void												getActions(SBVector<SBAction*>& actionVector);											///< Gets the node's actions

	//@}

	/// \name Event
	//@{

	virtual void												mousePressEvent(SBNode* node, QMouseEvent* event, SBPosition3& pickingPoint);			///< Handles mouse press event
	virtual void												mouseReleaseEvent(SBNode* node, QMouseEvent* event);									///< Handles mouse release event
	virtual void												mouseMoveEvent(SBNode* node, QMouseEvent* event);										///< Handles mouse move event
	virtual void												mouseDoubleClickEvent(SBNode* node, QMouseEvent* event, SBPosition3& pickingPoint);		///< Handles mouse double click event

	virtual void												wheelEvent(SBNode* node, QWheelEvent* event);											///< Handles wheel event
																																						
	virtual void												keyPressEvent(SBNode* node, QKeyEvent* event);											///< Handles key press event
	virtual void												keyReleaseEvent(SBNode* node, QKeyEvent* event);										///< Handles key release event
																																						
	//@}

	
};


SB_REGISTER_TYPE(SEProteinDesignNodeConstructionPointGUI, "SEProteinDesignNodeConstructionPointGUI", "8BD4866B-66CC-9013-212F-F99E1D94ECC3");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeConstructionPointGUI, SBGDataGraphNode);
