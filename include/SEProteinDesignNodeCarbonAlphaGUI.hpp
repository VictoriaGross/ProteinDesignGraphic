#pragma once 

#include "SBGDataGraphNode.hpp"


/// This class implements the GUI of a node

class SEProteinDesignNodeCarbonAlphaGUI : public SBGDataGraphNode {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignNodeCarbonAlphaGUI();																														///< Builds a GUI class for a node				
	virtual ~SEProteinDesignNodeCarbonAlphaGUI();																											///< Destructs the GUI class of a node

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


SB_REGISTER_TYPE(SEProteinDesignNodeCarbonAlphaGUI, "SEProteinDesignNodeCarbonAlphaGUI", "A8BA860F-DAF1-120B-012D-8AA06AD2F5F9");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeCarbonAlphaGUI, SBGDataGraphNode);
