#include "SEProteinDesignEditorSpline.hpp"
#include "SAMSON.hpp"


SEProteinDesignEditorSpline::SEProteinDesignEditorSpline() {

	// SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

    propertyWidget = 0;

}

SEProteinDesignEditorSpline::~SEProteinDesignEditorSpline() {

}

SEProteinDesignEditorSplineGUI* SEProteinDesignEditorSpline::getPropertyWidget() const { return static_cast<SEProteinDesignEditorSplineGUI*>(propertyWidget); }

SBCContainerUUID SEProteinDesignEditorSpline::getUUID() const { return SBCContainerUUID("DF66FB05-F8D8-A79E-77DC-A3532B35B33A"); }

QString SEProteinDesignEditorSpline::getName() const { 

	// SAMSON Element generator pro tip: this name should not be changed

	return "SEProteinDesignEditorSpline"; 

}

QString SEProteinDesignEditorSpline::getDescription() const { 
	
	// SAMSON Element generator pro tip: modify this function to return a user-friendly string that will be displayed in menus

	return QObject::tr("SEProteinDesignEditorSpline"); 

}

QPixmap SEProteinDesignEditorSpline::getLogo() const {

	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your editor.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignEditorSplineIcon.png"));

}

int SEProteinDesignEditorSpline::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)
	
	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QKeySequence SEProteinDesignEditorSpline::getShortcut() const { 
	
	// SAMSON Element generator pro tip: modify this function to associate a tentative shortcut to your editor

	return QKeySequence(""); 

}

QString SEProteinDesignEditorSpline::getToolTip() const { 
	
	// SAMSON Element generator pro tip: modify this function to have your editor display a tool tip in the SAMSON GUI when the mouse hovers the editor's icon

	return QObject::tr("SAMSON Element generator pro tip: modify me"); 

}

void SEProteinDesignEditorSpline::loadSettings(SBGSettings* settings) {

	if (settings == NULL) return;
	
	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

}

void SEProteinDesignEditorSpline::saveSettings(SBGSettings* settings) {

	if (settings == NULL) return;

	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

}

void SEProteinDesignEditorSpline::beginEditing() {

    path = 0;
    selectedNode = 0;
}

void SEProteinDesignEditorSpline::endEditing() {

    path = 0;
    selectedNode = 0;
}

void SEProteinDesignEditorSpline::getActions(SBVector<SBAction*>& actionVector) {

	// SAMSON Element generator pro tip: SAMSON calls this function to show the user actions associated to your editor in context menus.
	// Append actions to the actionVector if necessary.
	// Please refer to tutorials for examples.

}

void SEProteinDesignEditorSpline::display() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop. 
	// Implement this function to display things in SAMSON, for example thanks to the utility functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignEditorSpline::displayForShadow() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows. 
	// Implement this function if your editor displays things in viewports, so that your editor can cast shadows
	// to other objects in SAMSON, for example thanks to the utility
	// functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignEditorSpline::displayInterface() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to display the editor 2D interface in viewports. 
	// Implement this function if your editor displays a 2D user interface. For example, a rectangle selection editor would display a 2D rectangle in the active viewport. 
	// You may use utility functions provided by SAMSON (e.g. displayLinesOrtho and displayTrianglesOrtho).

}

void SEProteinDesignEditorSpline::mousePressEvent(QMouseEvent* event) {

    SBNode* node = SAMSON::getNode(event->x(), event->y(),
            (SBNode::GetClass() == std::string("SEProteinDesignNodeConstructionPoint")) &&
            (SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID)));

        if (node) selectedNode = static_cast<SEProteinDesignNodeConstructionPoint*>(node);
        else selectedNode = 0;

}

void SEProteinDesignEditorSpline::mouseReleaseEvent(QMouseEvent* event) {

    if (selectedNode != 0) {

        selectedNode = 0;
        return;

    }

    if (path == 0 || (path != 0 && path->isErased())) {

            path = new SEProteinDesignVisualModelCurve;
            SAMSON::beginHolding("Create path");
            SAMSON::hold(path());
            path->create();
            SAMSON::getActiveLayer()->addChild(path());
            SAMSON::endHolding();

        }

        // get a world position from the mouse position when the user clicked

        SBPosition3 position = SAMSON::getWorldPositionFromViewportPosition(event->x(), event->y());

        // add a path node

        SAMSON::beginHolding("Add path node");
        SEProteinDesignNodeConstructionPoint* node = new SEProteinDesignNodeConstructionPoint(position);
        SAMSON::hold(node);
        node->create();
        path->addNode(node);
        SAMSON::endHolding();
        SAMSON::requestViewportUpdate();

}

void SEProteinDesignEditorSpline::mouseMoveEvent(QMouseEvent* event) {
    if (selectedNode != 0) {

            SBPosition3 position = SAMSON::getWorldPositionFromViewportPosition(event->x(), event->y());

            selectedNode->setPosition(position);

            SAMSON::requestViewportUpdate();

        }

}

void SEProteinDesignEditorSpline::mouseDoubleClickEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorSpline::wheelEvent(QWheelEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorSpline::keyPressEvent(QKeyEvent* event) {

    if (event->key() == Qt::Key_Escape) {

            path = 0;
            selectedNode = 0;
            event->accept();

        }

}

void SEProteinDesignEditorSpline::keyReleaseEvent(QKeyEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorSpline::onBaseEvent(SBBaseEvent* baseEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle base events

}

void SEProteinDesignEditorSpline::onDocumentEvent(SBDocumentEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle document events 

}

void SEProteinDesignEditorSpline::onDynamicalEvent(SBDynamicalEvent* dynamicalEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle dynamical events 

}

void SEProteinDesignEditorSpline::onStructuralEvent(SBStructuralEvent* documentEvent) {
	
	// SAMSON Element generator pro tip: implement this function if you need to handle structural events

}
