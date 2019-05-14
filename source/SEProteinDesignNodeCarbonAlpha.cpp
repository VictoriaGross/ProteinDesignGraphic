#include "SEProteinDesignNodeCarbonAlpha.hpp"
#include "SAMSON.hpp"

/// A constructor

SEProteinDesignNodeCarbonAlpha::SEProteinDesignNodeCarbonAlpha(){}

SEProteinDesignNodeCarbonAlpha::SEProteinDesignNodeCarbonAlpha(const SBPosition3& position) {
	// A CarbonAlpha is a carbon
	this->position = position;
}



/// The destructor
SEProteinDesignNodeCarbonAlpha::~SEProteinDesignNodeCarbonAlpha() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

}

 bool SEProteinDesignNodeCarbonAlpha::isSerializable() const {

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Modify the line below to "return true;" if you want this node to be serializable (hence copyable, savable, etc.)

	return false;
	
}

void SEProteinDesignNodeCarbonAlpha::serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) const {

	SBDDataGraphNode::serialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to serialize your node.

}

void SEProteinDesignNodeCarbonAlpha::unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) {

	SBDDataGraphNode::unserialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);
	
	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to unserialize your node.

}

SBDDataGraphNode* SEProteinDesignNodeCarbonAlpha::getParent() const { 

	// SAMSON Element generator pro tip: modify this function if your node can be added as a child of another node.
	
	return 0; 
	
}

bool SEProteinDesignNodeCarbonAlpha::addChild(SBDDataGraphNode* node, SBDDataGraphNode* nextNode) {
	
	// SAMSON Element generator pro tip: modify this function if your node can have descendants.
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

	return false;
	
}

bool SEProteinDesignNodeCarbonAlpha::removeChild(SBDDataGraphNode* node) {
	
	// SAMSON Element generator pro tip: modify this function if your node can have descendants.
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

	return false;
	
}


SEProteinDesignNodeCarbonAlpha* SEProteinDesignNodeCarbonAlpha::clone() { return static_cast<SEProteinDesignNodeCarbonAlpha*>(SBNode::clone()); }

void SEProteinDesignNodeCarbonAlpha::eraseImplementation() {

	// SAMSON Element generator pro tip: modify this function when you need to perform special tasks when your node is erased (e.g. disconnect from nodes you are connected to).
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

}

SBNode::Type SEProteinDesignNodeCarbonAlpha::getType() const { 

	// SAMSON Element generator pro tip: modify this function to return the node type closest to your node's type.

	return SBNode::Undefined; 
	
}

void SEProteinDesignNodeCarbonAlpha::getNodes(SBNodeIndexer& nodeIndexer, const SBNodePredicate& selectionPredicate, const SBNodePredicate& visitPredicate, bool includeDependencies) {

	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.
	// If includeDependencies is true, you must add to the indexer all nodes that depend on this node without descending from it (for example, a bond would add the atoms it connects).

	if (visitPredicate(this) && selectionPredicate(this)) nodeIndexer.push_back(this);

}

void SEProteinDesignNodeCarbonAlpha::forEachNodeDepthFirst(void(*action)(SBDDataGraphNode* node)) {

	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.

	action(this);

}

void SEProteinDesignNodeCarbonAlpha::forEachNodeDepthFirst(SBCClass* object, void (SBCClass::*action)(SBDDataGraphNode* node)) {
	
	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.

	(*object.*action)(this);

}

/// Getter and Setter for the position of the Carbon Alpha
SBPosition3 SEProteinDesignNodeCarbonAlpha::getPosition() const {
	return position;
}

void SEProteinDesignNodeCarbonAlpha::setPosition(const SBPosition3& position) {
	this->position = position;

}

