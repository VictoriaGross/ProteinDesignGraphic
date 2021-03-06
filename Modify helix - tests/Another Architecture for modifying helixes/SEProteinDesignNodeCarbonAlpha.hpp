#pragma once 

#include "SBDDataGraphNode.hpp"

/// A carbon alpha is a Node wich contains its position
#include "SBDDataGraphNode.hpp"
#include "SBVector3.hpp"
// We have included all files concerning vectors

/// This class implements a node

class SEProteinDesignNodeCarbonAlpha : public SBDDataGraphNode{

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	/// CONSTRUCTORS

	SEProteinDesignNodeCarbonAlpha();	
	///< Builds a node that is void

	SEProteinDesignNodeCarbonAlpha(const SBPosition3& position);
	///< Builds a node according to a given position

	
	/// DESTRUCTORS
	virtual ~SEProteinDesignNodeCarbonAlpha();																											///< Destructs the node

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

	virtual SEProteinDesignNodeCarbonAlpha*										clone();																///< Returns a copy of the node and its descendants

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

// Let us get and set the position of a Carbon Alpha (Already in the atom description)
	SBPosition3 getPosition() const;
	void setPosition(const SBPosition3& position);

private:
	// A CarbonAlpha has a position
	SBPosition3 position;
};


SB_REGISTER_TARGET_TYPE(SEProteinDesignNodeCarbonAlpha, "SEProteinDesignNodeCarbonAlpha", "7D904072-BA01-4D89-057A-1569E7A2E11F");
SB_DECLARE_BASE_TYPE(SEProteinDesignNodeCarbonAlpha, SBDDataGraphNode);
