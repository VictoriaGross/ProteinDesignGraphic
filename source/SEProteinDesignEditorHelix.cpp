#include "SEProteinDesignEditorHelix.hpp"
#include "SAMSON.hpp"




SEProteinDesignEditorHelix::SEProteinDesignEditorHelix() {

	// SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

	propertyWidget = new SEProteinDesignEditorHelixGUI(this);
	propertyWidget->loadDefaultSettings();
	SAMSON::addWidget(propertyWidget);

}

SEProteinDesignEditorHelix::~SEProteinDesignEditorHelix() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

	propertyWidget->saveDefaultSettings();
	delete propertyWidget;
	/*beginHelix.~SEProteinDesignNodeConstructionPoint();
	endHelix.~SEProteinDesignNodeConstructionPoint();*/
}

SEProteinDesignEditorHelixGUI* SEProteinDesignEditorHelix::getPropertyWidget() const { return static_cast<SEProteinDesignEditorHelixGUI*>(propertyWidget); }

SBCContainerUUID SEProteinDesignEditorHelix::getUUID() const { return SBCContainerUUID("496A08B6-A4D5-8CB4-774F-A57F9BC1E7D8"); }

QString SEProteinDesignEditorHelix::getName() const { 

	// SAMSON Element generator pro tip: this name should not be changed

	return "SEProteinDesignEditorHelix"; 

}

QString SEProteinDesignEditorHelix::getDescription() const { 
	
	// SAMSON Element generator pro tip: modify this function to return a user-friendly string that will be displayed in menus

	return QObject::tr("SEProteinDesignEditorHelix"); 

}

QPixmap SEProteinDesignEditorHelix::getLogo() const {

	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your editor.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignEditorHelixIcon.png"));

}

int SEProteinDesignEditorHelix::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)
	
	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QKeySequence SEProteinDesignEditorHelix::getShortcut() const { 
	
	// SAMSON Element generator pro tip: modify this function to associate a tentative shortcut to your editor

	return QKeySequence(""); 

}

QString SEProteinDesignEditorHelix::getToolTip() const { 
	
	// SAMSON Element generator pro tip: modify this function to have your editor display a tool tip in the SAMSON GUI when the mouse hovers the editor's icon

	return QObject::tr("Create an alpha-Helix by clicking and dragging"); 

}

void SEProteinDesignEditorHelix::loadSettings(SBGSettings* settings) {

	if (settings == NULL) return;
	
	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

}

void SEProteinDesignEditorHelix::saveSettings(SBGSettings* settings) {

	if (settings == NULL) return;

	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

}

void SEProteinDesignEditorHelix::beginEditing() {
	// We set the pointer path to zero as we begin editing (reinitialisation)

	path = 0;
	// If we don't edit end and beginning have the same value
	SBPosition3 pos=getBegin().getPosition();
	setEnd(pos);

}

void SEProteinDesignEditorHelix::endEditing() {
	// We set the pointer path to zero when we finish to edit (reinitialisation)

	path = 0;
	SBPosition3 pos = getBegin().getPosition();
	setEnd(pos);

	
}

void SEProteinDesignEditorHelix::getActions(SBVector<SBAction*>& actionVector) {

	// SAMSON Element generator pro tip: SAMSON calls this function to show the user actions associated to your editor in context menus.
	// Append actions to the actionVector if necessary.
	// Please refer to tutorials for examples.

}

void SEProteinDesignEditorHelix::display() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop. 
	// Implement this function to display things in SAMSON, for example thanks to the utility functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignEditorHelix::displayForShadow() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows. 
	// Implement this function if your editor displays things in viewports, so that your editor can cast shadows
	// to other objects in SAMSON, for example thanks to the utility
	// functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignEditorHelix::displayInterface() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to display the editor 2D interface in viewports. 
	// Implement this function if your editor displays a 2D user interface. For example, a rectangle selection editor would display a 2D rectangle in the active viewport. 
	// You may use utility functions provided by SAMSON (e.g. displayLinesOrtho and displayTrianglesOrtho).

}

void SEProteinDesignEditorHelix::mousePressEvent(QMouseEvent* event) {
	if (event->button() ==
		Qt::MouseButton::LeftButton) {
		if (path == 0 || (path != 0 && path->isErased())) {

			path = new SEProteinDesignVisualModelBackbone();
			path->create();
			SAMSON::getActiveLayer()->addChild(path());

		}
		SBPosition3 position = SAMSON::getWorldPositionFromViewportPosition(event->x(), event->y());
		setBegin(position);
		

		SAMSON::requestViewportUpdate();
	}
}

void SEProteinDesignEditorHelix::mouseReleaseEvent(QMouseEvent* event) {
	
	//if (getBegin().getPosition() == getEnd().getPosition()) {
		
		// In this case we start a new helix

		SBCamera* activeCamera = SAMSON::getActiveCamera();
		SBPosition3 MousePos = SAMSON::getWorldPositionFromViewportPosition(event->x(), event->y());
		// The coordinates of the Helix axis system in the General Fixed axis system
		float MouseLength = (float)SBQuantity::length(MousePos.norm()).getValue();
		SBVector3 MousePos2 = MousePos.normalizedVersion()*MouseLength;
		SBPosition3 AxisV = getBegin().getPosition() - MousePos;
		SBQuantity::length NormV = AxisV.norm();
		SBVector3 AxisVnormed = AxisV.normalizedVersion();
		SBVector3 AxisZ = activeCamera->getBasisZ();
		//	SBQuantity::length NormZ = AxisZ.norm();
		SBVector3 AxisZnormed = AxisZ.normalizedVersion();
		SBVector3 AxisTnormed = AxisVnormed^AxisZnormed;

		// Let us enter the parameters of the helix
		SBDQuantity::angstrom HelixLength = SBQuantity::angstrom(SBQuantity::length(NormV)); // The length of the Helix created by the user
		SBQuantity::angstrom LengthBwCarbons = SBQuantity::angstrom(1.15); // The pace of the Helix
		SBQuantity::angstrom HelixRadius = SBQuantity::angstrom(2.3); //The radius of the Helix
		SBQuantity::radian RotationPace = SBQuantity::degree(100);
		float NumberofCarbons = (float)SBQuantity::length(HelixLength).getValue() / ((float)SBQuantity::length(LengthBwCarbons).getValue());
		int numb = floor(NumberofCarbons);
		//// THE PROBLEM LIES IN THE TWO WHILE LOOPS

		for (int i = 0; i < numb + 1; i += 1) {

			//for (int i = 0; i < 1; i += 1) {
			SBPosition3 CurrentCarbonV = i*LengthBwCarbons*AxisVnormed;
			SBPosition3 CurrentCarbonT = HelixRadius*cos(i*RotationPace)*AxisTnormed;
			SBPosition3 CurrentCarbonZ = HelixRadius*sin(i*RotationPace)*AxisZnormed;
			SEProteinDesignNodeCarbonAlpha* CurrentCarbon = new SEProteinDesignNodeCarbonAlpha(CurrentCarbonV + CurrentCarbonT + CurrentCarbonZ + MousePos);

			path->addNode(CurrentCarbon);
			SAMSON::requestViewportUpdate();
			//path = 0;
		}
		SBPosition3 CurrentCarbonV = (numb + 1)*LengthBwCarbons*AxisVnormed;
		SBPosition3 CurrentCarbonT = HelixRadius*cos((numb + 1)*RotationPace)*AxisTnormed;
		SBPosition3 CurrentCarbonZ = HelixRadius*sin((numb + 1)*RotationPace)*AxisZnormed;
		setEnd(CurrentCarbonV + CurrentCarbonT + CurrentCarbonZ + MousePos);

		SAMSON::requestViewportUpdate();
	//}

	//else {
	//	// In this case we extend an helix

	//	SBCamera* activeCamera = SAMSON::getActiveCamera();
	//	SBPosition3 MousePos = SAMSON::getWorldPositionFromViewportPosition(event->x(), event->y());
	//	// The coordinates of the Helix axis system in the General Fixed axis system
	//	float MouseLength = (float)SBQuantity::length(MousePos.norm()).getValue();
	//	SBVector3 MousePos2 = MousePos.normalizedVersion()*MouseLength;

	//	// We consider that we have clicked at the end of the first helix

	//	SBPosition3 AxisV = getEnd().getPosition() - MousePos;
	//	SBQuantity::length NormV = AxisV.norm();
	//	SBVector3 AxisVnormed = AxisV.normalizedVersion();
	//	SBVector3 AxisZ = activeCamera->getBasisZ();
	//	//	SBQuantity::length NormZ = AxisZ.norm();
	//	SBVector3 AxisZnormed = AxisZ.normalizedVersion();
	//	SBVector3 AxisTnormed = AxisVnormed*AxisZnormed;

	//	// Let us enter the parameters of the helix
	//	SBDQuantity::angstrom HelixLength = SBQuantity::angstrom(SBQuantity::length(NormV)); // The length of the Helix created by the user
	//	SBQuantity::angstrom LengthBwCarbons = SBQuantity::angstrom(1.15); // The pace of the Helix
	//	SBQuantity::angstrom HelixRadius = SBQuantity::angstrom(2.3); //The radius of the Helix
	//	SBQuantity::radian RotationPace = SBQuantity::degree(100);
	//	float NumberofCarbons = (float)SBQuantity::length(HelixLength).getValue() / ((float)SBQuantity::length(LengthBwCarbons).getValue());
	//	int numb = floor(NumberofCarbons);
	//	//// THE PROBLEM LIES IN THE TWO WHILE LOOPS

	//	for (int i = 1; i < numb + 1; i += 1) {
	//		// The first carbon already exists

	//		//for (int i = 0; i < 1; i += 1) {
	//		SBPosition3 CurrentCarbonV = i*LengthBwCarbons*AxisVnormed;
	//		SBPosition3 CurrentCarbonT = HelixRadius*cos(i*RotationPace)*AxisTnormed;
	//		SBPosition3 CurrentCarbonZ = HelixRadius*sin(i*RotationPace)*AxisZnormed;
	//		SEProteinDesignNodeCarbonAlpha* CurrentCarbon = new SEProteinDesignNodeCarbonAlpha(CurrentCarbonV + CurrentCarbonT + CurrentCarbonZ + MousePos);

	//		path->addNode(CurrentCarbon);
	//		SAMSON::requestViewportUpdate();
	//		//path = 0;
	//	}
	//	SBPosition3 CurrentCarbonV = (numb + 1)*LengthBwCarbons*AxisVnormed;
	//	SBPosition3 CurrentCarbonT = HelixRadius*cos((numb + 1)*RotationPace)*AxisTnormed;
	//	SBPosition3 CurrentCarbonZ = HelixRadius*sin((numb + 1)*RotationPace)*AxisZnormed;
	//	setEnd(CurrentCarbonV + CurrentCarbonT + CurrentCarbonZ + MousePos);

	//	SAMSON::requestViewportUpdate();
	//}

	}


void SEProteinDesignEditorHelix::mouseMoveEvent(QMouseEvent* event) {

	
}

void SEProteinDesignEditorHelix::mouseDoubleClickEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorHelix::wheelEvent(QWheelEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorHelix::keyPressEvent(QKeyEvent* event) {
	// It is possible to stop the current path by pressing Escape
	if (event->key() == Qt::Key_Escape) {
		path = 0;
		event->accept();
	}


}

void SEProteinDesignEditorHelix::keyReleaseEvent(QKeyEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEProteinDesignEditorHelix::onBaseEvent(SBBaseEvent* baseEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle base events

}

void SEProteinDesignEditorHelix::onDocumentEvent(SBDocumentEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle document events 

}

void SEProteinDesignEditorHelix::onDynamicalEvent(SBDynamicalEvent* dynamicalEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle dynamical events 

}

void SEProteinDesignEditorHelix::onStructuralEvent(SBStructuralEvent* documentEvent) {
	
	// SAMSON Element generator pro tip: implement this function if you need to handle structural events

}

// Enables us to get the position of the construction points and the construction points themselves



void SEProteinDesignEditorHelix::setBegin(SBPosition3& position) {
	beginHelix.setPosition(position);
 }

void SEProteinDesignEditorHelix::setEnd(SBPosition3& position) {
	endHelix.setPosition(position);
}

SEProteinDesignNodeConstructionPoint SEProteinDesignEditorHelix::getBegin() {
	return(beginHelix.getPosition());
}


SEProteinDesignNodeConstructionPoint SEProteinDesignEditorHelix::getEnd() {
	return(endHelix.getPosition());
}