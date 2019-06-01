#pragma once 

#include "SBDDataGraphNode.hpp"
#include "SBVector3.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"

/// This class implements a node

class SEProteinDesignNodeConstructionPoint : public SBDDataGraphNode {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{
	SEProteinDesignNodeConstructionPoint();
    SEProteinDesignNodeConstructionPoint(const SBPosition3& position);																													///< Builds a node
	virtual ~SEProteinDesignNodeConstructionPoint();																											///< Destructs the node

	//@}

	/// \name Serialization
	//@{

	virtual bool												isSerializable() const;													///< Returns true when the node is serializable

	virtual void												serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber = SB_SDK_VERSION_NUMBER, const SBVersionNumber& classVersionNumber = SBVersionNumber(1, 0, 0)) const;		///< Serializes the node
	virtual void												unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber = SB_SDK_VERSION_NUMBER, const SBVersionNumber& classVersionNumber = SBVersionNumber(1, 0, 0));			///< Unserializes the node

	//@}

	/// \name Topology
	//@{

	virtual SBDDataGraphNode*									getParent() const;														///< Returns the parent of the node

	virtual bool												addChild(SBDDataGraphNode* node, SBDDataGraphNode* nextNode=0);			///< Adds a child to the node
	virtual bool												removeChild(SBDDataGraphNode* node);									///< Removes a child from the node

	virtual SEProteinDesignNodeConstructionPoint*										clone();																///< Returns a copy of the node and its descendants

	virtual	void												eraseImplementation();													///< Erases the node

	//@}

	/// \name Identity
	//@{

	virtual Type												getType() const;														///< Returns the type of the data graph node

	//@}

	/// \name Selection functions
	//@{

	virtual void												getNodes(SBNodeIndexer& nodeIndexer, const SBNodePredicate& selectionPredicate = SBDDataGraphNode::All(), const SBNodePredicate& visitPredicate = SBDDataGraphNode::All(), bool includeDependencies = false);									///< Collects nodes into \p nodeIndexer, based on a \p selectionPredicate and a \p visitPredicate, with our without dependencies

	//@}

	/// \name Visitor functions
	//@{

	virtual void												forEachNodeDepthFirst(void(*action)(SBDDataGraphNode* node));									///< Performs an action on each node
	virtual void												forEachNodeDepthFirst(SBCClass* object, void (SBCClass::*action)(SBDDataGraphNode* node));		///< Performs an action on each node

	//@}

    SBPosition3 getPosition() const;
    void setPosition(const SBPosition3& position);
	void addNode(SEProteinDesignNodeCarbonAlpha* pathNodeCarbonAlpha);
	void removeNode(SEProteinDesignNodeCarbonAlpha* pathNodeCarboneAlpha);

	// getter and setter for the link
	void setLink(SEProteinDesignNodeConstructionPoint* pt);
	SEProteinDesignNodeConstructionPoint* getLink();

	//getter for the List
	SBPointerList<SEProteinDesignNodeCarbonAlpha>* getList();

	void eraseCarbonAlpha();
    private:

        SBPosition3 position;

		// The new setting
		SBPointerList<SEProteinDesignNodeCarbonAlpha> CarbonList; // The List of carbons associated to the Helix
		SEProteinDesignNodeConstructionPoint* LinkedPoint; // The begin point (if this an end point)


};


SB_REGISTER_TARGET_TYPE(SEProteinDesignNodeConstructionPoint, "SEProteinDesignNodeConstructionPoint", "1DD4EAA2-555D-4B66-38FE-034E5509A8A8");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeConstructionPoint, SBDDataGraphNode);
