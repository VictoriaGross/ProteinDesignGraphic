#include "SEProteinDesignVisualModelCurve.hpp"
#include "SAMSON.hpp"


SEProteinDesignVisualModelCurve::SEProteinDesignVisualModelCurve() {

	// SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

}

SEProteinDesignVisualModelCurve::SEProteinDesignVisualModelCurve(const SBNodeIndexer& nodeIndexer) {

	// SAMSON Element generator pro tip: implement this function if you want your visual model to be applied to a set of data graph nodes.
	// You might want to connect to various signals and handle the corresponding events. For example, if your visual model represents a sphere positioned at
	// the center of mass of a group of atoms, you might want to connect to the atoms' base signals (e.g. to update the center of mass when an atom is erased) and
	// the atoms' structural signals (e.g. to update the center of mass when an atom is moved).

}

SEProteinDesignVisualModelCurve::~SEProteinDesignVisualModelCurve() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

}

 bool SEProteinDesignVisualModelCurve::isSerializable() const {

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Modify the line below to "return true;" if you want this visual model be serializable (hence copyable, savable, etc.)

	return false;
	
}

void SEProteinDesignVisualModelCurve::serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) const {

	SBMVisualModel::serialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to serialize your visual model.

}

void SEProteinDesignVisualModelCurve::unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) {

	SBMVisualModel::unserialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);
	
	// SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc. 
	// Please refer to the SDK documentation for more information.
	// Complete this function to unserialize your visual model.

}

void SEProteinDesignVisualModelCurve::eraseImplementation() {

	// SAMSON Element generator pro tip: modify this function when you need to perform special tasks when your visual model is erased (e.g. disconnect from nodes you are connected to).
	// Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

}

void SEProteinDesignVisualModelCurve::display() {

    if (ConstructionNodeList.empty()) return;

    unsigned int numberOfNodes = ConstructionNodeList.size();
    int n = 50;


    // allocate arrays and initialize them to zeros

    float* positionData = new float[3 * numberOfNodes]();
    float* radiusData = new float[numberOfNodes]();
    float* colorData = new float[4 * numberOfNodes]();
    unsigned int* flagData = new unsigned int[numberOfNodes]();

    float* positionSpline = new float[3 * n * (numberOfNodes-1)]();
    float* radiusSpline = new float[n * (numberOfNodes-1)]();
    float* colorSpline = new float[4 * n * (numberOfNodes-1)]();
    unsigned int* flagSpline = new unsigned int[n * (numberOfNodes-1)]();


    // fill in the arrays

    unsigned int currentIndex = 0;


    SB_FOR(SEProteinDesignNodeConstructionPoint* currentNode, ConstructionNodeList){

        //main nodes


        SBPosition3 position = currentNode->getPosition();

        positionData[3*currentIndex+0] = (float)position.v[0].getValue();
        positionData[3*currentIndex+1] = (float)position.v[1].getValue();
        positionData[3*currentIndex+2] = (float)position.v[2].getValue();
        radiusData[currentIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.2)).getValue();
        colorData[4 * currentIndex + 0] = 1.0f;
        colorData[4 * currentIndex + 1] = 0.0f;
        colorData[4 * currentIndex + 2] = 0.0f;
        colorData[4 * currentIndex + 3] = 1.0f;

        flagData[currentIndex] = currentNode->getInheritedFlags() | getInheritedFlags();

        //spline nodes

        if (currentIndex>2){
            float x3 = positionData[3*currentIndex+0];
            float x2 = positionData[3*(currentIndex-1)+0];
            float x1 = positionData[3*(currentIndex-2)+0];
            float x0 = positionData[3*(currentIndex-3)+0];

            float y3 = positionData[3*currentIndex+1];
            float y2 = positionData[3*(currentIndex-1)+1];
            float y1 = positionData[3*(currentIndex-2)+1];
            float y0 = positionData[3*(currentIndex-3)+1];

            float z3 = positionData[3*currentIndex+2];
            float z2 = positionData[3*(currentIndex-1)+2];
            float z1 = positionData[3*(currentIndex-2)+2];
            float z0 = positionData[3*(currentIndex-3)+2];


            for(int i=0;i<n;i++){
                float t = float(i+1)/(n+1);

                float a = 0.5f*(-t+2*t*t-t*t*t);
                float b = 0.5f*(2-5*t*t+3*t*t*t);
                float c = 0.5f*(t+4*t*t-3*t*t*t);
                float d = 0.5f*(-t*t+t*t*t);

                positionSpline[3*n*(currentIndex-2)+3*i+0] = a*x0+b*x1+c*x2+d*x3;
                positionSpline[3*n*(currentIndex-2)+3*i+1] = a*y0+b*y1+c*y2+d*y3;
                positionSpline[3*n*(currentIndex-2)+3*i+2] = a*z0+b*z1+c*z2+d*z3;


                radiusSpline[n*(currentIndex-2)+i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

                colorSpline[4*n*(currentIndex-2)+4*i+0] = 1.0f;
                colorSpline[4*n*(currentIndex-2)+4*i+1] = 1.0f;
                colorSpline[4*n*(currentIndex-2)+4*i+2] = 0.0f;
                colorSpline[4*n*(currentIndex-2)+4*i+3] = 1.0f;

                flagSpline[n*(currentIndex-2)+i] = getInheritedFlags();
            }
        }




        currentIndex++;
    }

    if (numberOfNodes==2){

    float x3 = positionData[3];
    float x2 = positionData[3];
    float x1 = positionData[0];
    float x0 = positionData[0];

    float y3 = positionData[4];
    float y2 = positionData[4];
    float y1 = positionData[1];
    float y0 = positionData[1];

    float z3 = positionData[5];
    float z2 = positionData[5];
    float z1 = positionData[2];
    float z0 = positionData[2];


    for(int i=0;i<n;i++){
        float t = float(i+1)/(n+1);

        float a = 0.5f*(-t+2*t*t-t*t*t);
        float b = 0.5f*(2-5*t*t+3*t*t*t);
        float c = 0.5f*(t+4*t*t-3*t*t*t);
        float d = 0.5f*(-t*t+t*t*t);

        positionSpline[3*i+0] = a*x0+b*x1+c*x2+d*x3;
        positionSpline[3*i+1] = a*y0+b*y1+c*y2+d*y3;
        positionSpline[3*i+2] = a*z0+b*z1+c*z2+d*z3;


        radiusSpline[i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

        colorSpline[4*i+0] = 1.0f;
        colorSpline[4*i+1] = 1.0f;
        colorSpline[4*i+2] = 0.0f;
        colorSpline[4*i+3] = 1.0f;

        flagSpline[i] = getInheritedFlags();

    }
    }
    if(numberOfNodes>2){

        float x3 = positionData[6];
        float x2 = positionData[3];
        float x1 = positionData[0];
        float x0 = positionData[0];

        float y3 = positionData[7];
        float y2 = positionData[4];
        float y1 = positionData[1];
        float y0 = positionData[1];

        float z3 = positionData[8];
        float z2 = positionData[5];
        float z1 = positionData[2];
        float z0 = positionData[2];


        for(int i=0;i<n;i++){
            float t = float(i+1)/(n+1);

            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            positionSpline[3*i+0] = a*x0+b*x1+c*x2+d*x3;
            positionSpline[3*i+1] = a*y0+b*y1+c*y2+d*y3;
            positionSpline[3*i+2] = a*z0+b*z1+c*z2+d*z3;


            radiusSpline[i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

            colorSpline[4*i+0] = 1.0f;
            colorSpline[4*i+1] = 1.0f;
            colorSpline[4*i+2] = 0.0f;
            colorSpline[4*i+3] = 1.0f;

            flagSpline[i] = getInheritedFlags();
    }



        x3 = positionData[3*(numberOfNodes-1)+0];
        x2 = positionData[3*(numberOfNodes-1)+0];
        x1 = positionData[3*(numberOfNodes-2)+0];
        x0 = positionData[3*(numberOfNodes-3)+0];

        y3 = positionData[3*(numberOfNodes-1)+1];
        y2 = positionData[3*(numberOfNodes-1)+1];
        y1 = positionData[3*(numberOfNodes-2)+1];
        y0 = positionData[3*(numberOfNodes-3)+1];

        z3 = positionData[3*(numberOfNodes-1)+2];
        z2 = positionData[3*(numberOfNodes-1)+2];
        z1 = positionData[3*(numberOfNodes-2)+2];
        z0 = positionData[3*(numberOfNodes-3)+2];


        for(int i=0;i<n;i++){
            float t = float(i+1)/(n+1);

            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            positionSpline[3*n*(numberOfNodes-2)+3*i+0] = a*x0+b*x1+c*x2+d*x3;
            positionSpline[3*n*(numberOfNodes-2)+3*i+1] = a*y0+b*y1+c*y2+d*y3;
            positionSpline[3*n*(numberOfNodes-2)+3*i+2] = a*z0+b*z1+c*z2+d*z3;


            radiusSpline[n*(numberOfNodes-2)+i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

            colorSpline[4*n*(numberOfNodes-2)+4*i+0] = 1.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+1] = 1.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+2] = 0.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+3] = 1.0f;

            flagSpline[n*(numberOfNodes-2)+i] = getInheritedFlags();
    }
    }

    // display

    SAMSON::displaySpheres(numberOfNodes, positionData, radiusData, colorData, flagData);
    SAMSON::displaySpheres(n*(numberOfNodes-1), positionSpline, radiusSpline, colorSpline, flagSpline);

    // clean

    delete[] positionData;
    delete[] radiusData;
    delete[] colorData;
    delete[] flagData;
    delete[] positionSpline;
    delete[] radiusSpline;
    delete[] colorSpline;
    delete[] flagSpline;

}

void SEProteinDesignVisualModelCurve::displayForShadow() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows. 
	// Implement this function so that your visual model can cast shadows to other objects in SAMSON, for example thanks to the utility
	// functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignVisualModelCurve::displayForSelection() {

    if (ConstructionNodeList.empty()) return;

    unsigned int numberOfNodes = ConstructionNodeList.size();

    // allocate arrays and initialize them to zeros

    float* positionData = new float[3 * numberOfNodes]();
    float* radiusData = new float[numberOfNodes]();
    unsigned int* indexData = new unsigned int[numberOfNodes]();

    // fill in the arrays

    unsigned int currentIndex = 0;


    SB_FOR(SEProteinDesignNodeConstructionPoint* currentNode, ConstructionNodeList){

        SBPosition3 position = currentNode->getPosition();

        positionData[3*currentIndex+0] = (float)position.v[0].getValue();
        positionData[3*currentIndex+1] = (float)position.v[1].getValue();
        positionData[3*currentIndex+2] = (float)position.v[2].getValue();

        radiusData[currentIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.2)).getValue();

        indexData[currentIndex] = currentNode->getNodeIndex();

        currentIndex++;

    }

    SAMSON::displaySpheresSelection(numberOfNodes, positionData, radiusData, indexData);

    delete[] positionData;
    delete[] radiusData;
    delete[] indexData;

}

void SEProteinDesignVisualModelCurve::expandBounds(SBIAPosition3& bounds) const {

	// SAMSON Element generator pro tip: this function is called by SAMSON to determine the model's spatial bounds. 
	// When this function returns, the bounds interval vector should contain the visual model. 

}

void SEProteinDesignVisualModelCurve::collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData) {

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

void SEProteinDesignVisualModelCurve::onBaseEvent(SBBaseEvent* baseEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle base events (e.g. when a node for which you provide a visual representation emits a base signal, such as when it is erased)

}

void SEProteinDesignVisualModelCurve::onDocumentEvent(SBDocumentEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle document events 

}

void SEProteinDesignVisualModelCurve::onStructuralEvent(SBStructuralEvent* documentEvent) {
	
	// SAMSON Element generator pro tip: implement this function if you need to handle structural events (e.g. when a structural node for which you provide a visual representation is updated)

}

void SEProteinDesignVisualModelCurve::addNode(SEProteinDesignNodeConstructionPoint* Node){
    if (!Node) return;
    ConstructionNodeList.addReferenceTarget(Node);
}

void SEProteinDesignVisualModelCurve::removeNode(SEProteinDesignNodeConstructionPoint* Node){
    if (!Node) return;
    ConstructionNodeList.removeReferenceTarget(Node);
}


