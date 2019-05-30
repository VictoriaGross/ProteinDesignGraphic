#include "SEProteinDesignVisualModelBackbone.hpp"
#include "SAMSON.hpp"



SEProteinDesignVisualModelBackbone::SEProteinDesignVisualModelBackbone() {

	// SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

}

SEProteinDesignVisualModelBackbone::SEProteinDesignVisualModelBackbone(const SBNodeIndexer& nodeIndexer) {

	// SAMSON Element generator pro tip: implement this function if you want your visual model to be applied to a set of data graph nodes.
	// You might want to connect to various signals and handle the corresponding events. For example, if your visual model represents a sphere positioned at
	// the center of mass of a group of atoms, you might want to connect to the atoms' base signals (e.g. to update the center of mass when an atom is erased) and
	// the atoms' structural signals (e.g. to update the center of mass when an atom is moved).

}

SEProteinDesignVisualModelBackbone::~SEProteinDesignVisualModelBackbone() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

}

bool SEProteinDesignVisualModelBackbone::isSerializable() const {

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Modify the line below to "return true;" if you want this visual model be serializable (hence copyable, savable, etc.)

	return false;

}

void SEProteinDesignVisualModelBackbone::serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) const {

	SBMVisualModel::serialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to serialize your visual model.

}

void SEProteinDesignVisualModelBackbone::unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) {

	SBMVisualModel::unserialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to unserialize your visual model.

}

void SEProteinDesignVisualModelBackbone::eraseImplementation() {

	// SAMSON Element generator pro tip: modify this function when you need to perform special tasks when your visual model is erased (e.g. disconnect from nodes you are connected to).
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

}

void SEProteinDesignVisualModelBackbone::display() {
	if (pathNodeCarbonAlphaList.empty()) return;

	unsigned int numberOfPathNodes = pathNodeCarbonAlphaList.size();
	unsigned int numberOfPathLines = pathNodeCarbonAlphaList.size() - 1;

	//// allocate arrays and initialize them to zeros

	float* positionData = new float[3 * numberOfPathNodes]();
	float* pathNodeRadiusData = new float[numberOfPathNodes]();
	float* pathLineRadiusData = new float[numberOfPathNodes]();
	float* colorData = new float[4 * numberOfPathNodes]();
	unsigned int* capData = new unsigned int[numberOfPathNodes]();
	unsigned int* flagData = new unsigned int[numberOfPathNodes]();
	unsigned int* indexData = new unsigned int[2 * numberOfPathLines]();

	//// fill in the arrays

	unsigned int currentPathNodeIndex = 0;

	SB_FOR(SEProteinDesignNodeCarbonAlpha* currentPathNode, pathNodeCarbonAlphaList) {

		SBPosition3 position = currentPathNode->getPosition();
		positionData[3 * currentPathNodeIndex + 0] = (float)position.v[0].getValue();
		positionData[3 * currentPathNodeIndex + 1] = (float)position.v[1].getValue();
		positionData[3 * currentPathNodeIndex + 2] = (float)position.v[2].getValue();

		if (currentPathNodeIndex < numberOfPathLines) {
			indexData[2 * currentPathNodeIndex + 0] = currentPathNodeIndex;
			indexData[2 * currentPathNodeIndex + 1] = currentPathNodeIndex + 1;
		}

		//	// The covalent radius of a Carbon is 77 pm

		pathNodeRadiusData[currentPathNodeIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.25)).getValue();
		//	/*Unnecessary for now (no cylinders yet)
		pathLineRadiusData[currentPathNodeIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.05)).getValue();
		//	*/
		colorData[4 * currentPathNodeIndex + 0] = 0.0f;
		colorData[4 * currentPathNodeIndex + 1] = 0.0f;
		colorData[4 * currentPathNodeIndex + 2] = 0.0f;
		colorData[4 * currentPathNodeIndex + 3] = 0.0f;
		capData[currentPathNodeIndex] = 0;
		flagData[currentPathNodeIndex] = currentPathNode->getInheritedFlags() | getInheritedFlags();

		currentPathNodeIndex++;

	}

	//// display 

	SAMSON::displaySpheres(numberOfPathNodes, positionData, pathNodeRadiusData, colorData, flagData);
	///* Let's not display any cylinders for now
	SAMSON::displayCylinders(numberOfPathLines, numberOfPathNodes, indexData, positionData, pathLineRadiusData, capData, colorData, flagData);
	//*/

	//// clean 

	delete[] positionData;
	delete[] indexData;
	delete[] pathNodeRadiusData;
	delete[] pathLineRadiusData;
	delete[] capData;
	delete[] colorData;
	delete[] flagData;

}




void SEProteinDesignVisualModelBackbone::displayForShadow() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows. 
	// Implement this function so that your visual model can cast shadows to other objects in SAMSON, for example thanks to the utility
	// functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignVisualModelBackbone::displayForSelection() {
	// Carbon.getNodeIndex
	if (pathNodeCarbonAlphaList.empty()) return;


	// allocate arrays and initialize them to zeros

	float* positionData = new float[6]();
	float* pathNodeRadiusData = new float[2]();
	unsigned int* nodeIndexData = new unsigned int[2]();

	// fill in the arrays

	//begin point
	SBPosition3 position = beginHelix->getPosition();
	positionData[0] = (float)position.v[0].getValue();
	positionData[1] = (float)position.v[1].getValue();
	positionData[2] = (float)position.v[2].getValue();

	pathNodeRadiusData[0] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

	nodeIndexData[0] = beginHelix->getNodeIndex();


	//end point
	position = endHelix->getPosition();
	positionData[3] = (float)position.v[0].getValue();
	positionData[4] = (float)position.v[1].getValue();
	positionData[5] = (float)position.v[2].getValue();

	pathNodeRadiusData[1] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

	nodeIndexData[1] = beginHelix->getNodeIndex();

	// display

	SAMSON::displaySpheresSelection(2, positionData, pathNodeRadiusData, nodeIndexData);

	// clean

	delete[] positionData;
	delete[] pathNodeRadiusData;
	delete[] nodeIndexData;

}

void SEProteinDesignVisualModelBackbone::expandBounds(SBIAPosition3& bounds) const {

	// SAMSON Element generator pro tip: this function is called by SAMSON to determine the model's spatial bounds. 
	// When this function returns, the bounds interval vector should contain the visual model. 

}

void SEProteinDesignVisualModelBackbone::collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData) {

	// SAMSON Element generator pro tip: this function is called by SAMSON to determine your model's influence on ambient occlusion.
	// Implement this function if you want your visual model to occlude other objects in ambient occlusion calculations.
	//
	// The ambientOcclusionData represents a nCellsX x nCellsY x nCellsZ grid of occlusion densities over the spatial region (boxOrigin, boxSize).
	// If your model represents geometry at position (x, y, z), then the occlusion density in corresponding grid nodes should be increased.
	//
	// Assuming x, y and z are given in length units (SBQuantity::length, SBQuantity::angstrom, etc.), the grid coordinates are:
	// SBQuantity::dimensionless xGrid = nCellsX * (x - boxOrigin.v[0]) / boxSize.v[0];
	// SBQuantity::dimensionless yGrid = nCellsY * (x - boxOrigin.v[1]) / boxSize.v[1];
	// SBQuantity::dimensionless zGrid = nCellsZ * (x - boxOrigin.v[2]) / boxSize.v[2];
	//
	// The corresponding density can be found at ambientOcclusionData[((int)zGrid.getValue() + 0)*nCellsY*nCellsX + ((int)yGrid.getValue() + 0)*nCellsX + ((int)xGrid.getValue() + 0)] (beware of grid bounds).
	// For higher-quality results, the influence of a point can be spread over neighboring grid nodes.

}

void SEProteinDesignVisualModelBackbone::onBaseEvent(SBBaseEvent* baseEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle base events (e.g. when a node for which you provide a visual representation emits a base signal, such as when it is erased)

}

void SEProteinDesignVisualModelBackbone::onDocumentEvent(SBDocumentEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle document events 

}

void SEProteinDesignVisualModelBackbone::onStructuralEvent(SBStructuralEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle structural events (e.g. when a structural node for which you provide a visual representation is updated)

}


/*
class AddNodeCommand : public SBCUndoCommand {
public:
AddNodeCommand(SEProteinDesignVisualModelBackbone* path, SEProteinDesignNodeConstructionPoint* node) { this->path=path; this->node = node; }
/// \name Undo / Redo
//@{
virtual void												redo() { path->addNode(node());}
virtual void												undo() { path->removeNode(node());}
virtual std::string											getName() const { return "Add node"; }
private:
SBPointer<SEProteinDesignVisualModelBackbone>               path;
SBPointer<SEProteinDesignNodeConstructionPoint>             node;
};
class RemoveNodeCommand : public SBCUndoCommand {
public:
RemoveNodeCommand(SEProteinDesignVisualModelBackbone* path, SEProteinDesignNodeConstructionPoint* node) { this->path=path; this->node = node; }
/// \name Undo / Redo
//@{
virtual void												redo() { path->removeNode(node()); }
virtual void												undo() { path->addNode(node()); }
virtual std::string											getName() const { return "Remove node"; }
private:
SBPointer<SEProteinDesignVisualModelBackbone>               path;
SBPointer<SEProteinDesignNodeConstructionPoint>             node;
};
*/



void SEProteinDesignVisualModelBackbone::addNode(SEProteinDesignNodeCarbonAlpha* pathNodeCarbonAlpha) {

	if (!pathNodeCarbonAlpha) return;
	//if (SAMSON::isHolding()) SAMSON::addUndoCommand(new AddNodeCommand(this,node));
	pathNodeCarbonAlphaList.addReferenceTarget(pathNodeCarbonAlpha);

}

void SEProteinDesignVisualModelBackbone::removeNode(SEProteinDesignNodeCarbonAlpha* pathNodeCarbonAlpha) {

	if (!pathNodeCarbonAlpha) return;
	//if (SAMSON::isHolding()) SAMSON::addUndoCommand(new RemoveNodeCommand(this,node));
	pathNodeCarbonAlphaList.removeReferenceTarget(pathNodeCarbonAlpha);

}

SEProteinDesignNodeCarbonAlpha* SEProteinDesignVisualModelBackbone::last() {
	return pathNodeCarbonAlphaList.last();
}

SEProteinDesignNodeCarbonAlpha* SEProteinDesignVisualModelBackbone::first() {
	return pathNodeCarbonAlphaList.first();
}

SEProteinDesignNodeConstructionPoint* SEProteinDesignVisualModelBackbone::getBeginHelix() const {
	return beginHelix;
}

void SEProteinDesignVisualModelBackbone::setBeginHelix(SEProteinDesignNodeConstructionPoint* point) {
	this->beginHelix = point;
}

SEProteinDesignNodeConstructionPoint* SEProteinDesignVisualModelBackbone::getEndHelix() const {
	return endHelix;
}

void SEProteinDesignVisualModelBackbone::setEndHelix(SEProteinDesignNodeConstructionPoint* point) {
	this->endHelix = point;
}


SBPointerList<SEProteinDesignNodeCarbonAlpha> SEProteinDesignVisualModelBackbone::getCarbonAlphaList() const {
	return pathNodeCarbonAlphaList;
}


void SEProteinDesignVisualModelBackbone::eraseCarbonAlpha() {
	this->pathNodeCarbonAlphaList.erase(pathNodeCarbonAlphaList.begin(), pathNodeCarbonAlphaList.end());
}