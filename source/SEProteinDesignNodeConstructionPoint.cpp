#include "SEProteinDesignNodeConstructionPoint.hpp"
#include "SAMSON.hpp"

SEProteinDesignNodeConstructionPoint::SEProteinDesignNodeConstructionPoint() {}

SEProteinDesignNodeConstructionPoint::SEProteinDesignNodeConstructionPoint(const SBPosition3& position) {
	this->position = position;

}

SEProteinDesignNodeConstructionPoint::~SEProteinDesignNodeConstructionPoint() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

}

 bool SEProteinDesignNodeConstructionPoint::isSerializable() const {

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Modify the line below to "return true;" if you want this node to be serializable (hence copyable, savable, etc.)

	return false;
	
}

void SEProteinDesignNodeConstructionPoint::serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) const {

	SBDDataGraphNode::serialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to serialize your node.

}

void SEProteinDesignNodeConstructionPoint::unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) {

	SBDDataGraphNode::unserialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);
	
	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to unserialize your node.

}

SBDDataGraphNode* SEProteinDesignNodeConstructionPoint::getParent() const { 

	// SAMSON Element generator pro tip: modify this function if your node can be added as a child of another node.
	
	return 0; 
	
}

bool SEProteinDesignNodeConstructionPoint::addChild(SBDDataGraphNode* node, SBDDataGraphNode* nextNode) {
	
	// SAMSON Element generator pro tip: modify this function if your node can have descendants.
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

	return false;
	
}

bool SEProteinDesignNodeConstructionPoint::removeChild(SBDDataGraphNode* node) {
	
	// SAMSON Element generator pro tip: modify this function if your node can have descendants.
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

	return false;
	
}


SEProteinDesignNodeConstructionPoint* SEProteinDesignNodeConstructionPoint::clone() { return static_cast<SEProteinDesignNodeConstructionPoint*>(SBNode::clone()); }

void SEProteinDesignNodeConstructionPoint::eraseImplementation() {

	// SAMSON Element generator pro tip: modify this function when you need to perform special tasks when your node is erased (e.g. disconnect from nodes you are connected to).
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

}

SBNode::Type SEProteinDesignNodeConstructionPoint::getType() const { 

	// SAMSON Element generator pro tip: modify this function to return the node type closest to your node's type.

	return SBNode::Undefined; 
	
}

void SEProteinDesignNodeConstructionPoint::getNodes(SBNodeIndexer& nodeIndexer, const SBNodePredicate& selectionPredicate, const SBNodePredicate& visitPredicate, bool includeDependencies) {

	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.
	// If includeDependencies is true, you must add to the indexer all nodes that depend on this node without descending from it (for example, a bond would add the atoms it connects).

	if (visitPredicate(this) && selectionPredicate(this)) nodeIndexer.push_back(this);

}

void SEProteinDesignNodeConstructionPoint::forEachNodeDepthFirst(void(*action)(SBDDataGraphNode* node)) {

	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.

	action(this);

}

void SEProteinDesignNodeConstructionPoint::forEachNodeDepthFirst(SBCClass* object, void (SBCClass::*action)(SBDDataGraphNode* node)) {
	
	// SAMSON Element generator pro tip: modify this function if your node has descendants, in order to recursively call this function on these descendants.

	(*object.*action)(this);

}

/// Accessors to the position

SBPosition3 SEProteinDesignNodeConstructionPoint::getPosition() {
	return position;
}

void SEProteinDesignNodeConstructionPoint::setPosition( SBPosition3& position) {
	this->position = position;

}