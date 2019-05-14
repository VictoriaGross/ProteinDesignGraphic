#pragma once 

#include "SBDDataGraphNode.hpp"

/// This class implements a node
// A node with a position
#include "SBDDataGraphNode.hpp"
#include "SBVector3.hpp"


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

	// A ConstructionPoint has a position
	SBPosition3 getPosition() ;
	void setPosition( SBPosition3& position);

private:

	SBPosition3 position;

};


SB_REGISTER_TARGET_TYPE(SEProteinDesignNodeConstructionPoint, "SEProteinDesignNodeConstructionPoint", "798779E2-F348-ADFC-4A82-1D5CA9B85965");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeConstructionPoint, SBDDataGraphNode);