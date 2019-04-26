#include "SEProteinDesignVisualModelCurveProperties.hpp"
#include "SEProteinDesignVisualModelCurve.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEProteinDesignVisualModelCurveProperties::SEProteinDesignVisualModelCurveProperties() {

	visualModel = 0;
	ui.setupUi( this );
	observer = new Observer(this);

}

SEProteinDesignVisualModelCurveProperties::~SEProteinDesignVisualModelCurveProperties() {

	if (!visualModel.isValid()) return;

	visualModel->disconnectBaseSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onBaseEvent));
	visualModel->disconnectVisualSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onVisualEvent));

}

void SEProteinDesignVisualModelCurveProperties::loadSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;
	
	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

void SEProteinDesignVisualModelCurveProperties::saveSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;

	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignVisualModelCurveProperties::getUUID() const { return SBCContainerUUID( "56EB4FD9-B2E9-BA1B-1F6D-6C4461862680" );}

QPixmap SEProteinDesignVisualModelCurveProperties::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your visual model.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignVisualModelCurvePropertiesIcon.png"));

}

QString SEProteinDesignVisualModelCurveProperties::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your visual model inside SAMSON

	return "SEProteinDesignVisualModelCurve properties"; 

}

int SEProteinDesignVisualModelCurveProperties::getFormat() const {

	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)

	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEProteinDesignVisualModelCurveProperties::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this visual model in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";

}

bool SEProteinDesignVisualModelCurveProperties::setup() {

	SBNodeIndexer nodeIndexer;
	SB_FOR(SBNode* node, *SAMSON::getActiveDocument()->getSelectedNodes()) node->getNodes(nodeIndexer, SBNode::GetClass() == std::string("SEProteinDesignVisualModelCurve") && SBNode::GetElement() == std::string("SEProteinDesign") && SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID));

	if (nodeIndexer.size() == 1) {

		visualModel = static_cast<SEProteinDesignVisualModelCurve*>((nodeIndexer)[0]);
		visualModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onBaseEvent));
		visualModel->connectVisualSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onVisualEvent));

		return true;

	}

	return false;

}

bool SEProteinDesignVisualModelCurveProperties::setup(SBNode* node) {

	if (node->getProxy()->getName() != "SEProteinDesignVisualModelCurve") return false;
	if (node->getProxy()->getElement() != "SEProteinDesign") return false;
	if (node->getProxy()->getElementUUID() != SBUUID(SB_ELEMENT_UUID)) return false;

	visualModel = static_cast<SEProteinDesignVisualModelCurve*>(node);
	visualModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onBaseEvent));
	visualModel->connectVisualSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelCurveProperties::Observer::onVisualEvent));

	return true;

}

SEProteinDesignVisualModelCurveProperties::Observer::Observer(SEProteinDesignVisualModelCurveProperties* properties) { this->properties = properties; }
SEProteinDesignVisualModelCurveProperties::Observer::~Observer() {}

void SEProteinDesignVisualModelCurveProperties::Observer::onBaseEvent(SBBaseEvent* baseEvent) {

	if (baseEvent->getType() == SBBaseEvent::NodeEraseBegin) properties->hide();

}

void SEProteinDesignVisualModelCurveProperties::Observer::onVisualEvent(SBVisualEvent* visualEvent) {

	if (visualEvent->getType() == SBVisualEvent::VisualModelChanged) {
		
		// SAMSON Element generator pro tip: modify this function if the property window
		// needs to be updated when the VisualModelChanged event is sent
				
	}

}
