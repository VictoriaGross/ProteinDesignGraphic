#include "SEProteinDesignVisualModelBackboneProperties.hpp"
#include "SEProteinDesignVisualModelBackbone.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEProteinDesignVisualModelBackboneProperties::SEProteinDesignVisualModelBackboneProperties() {

	visualModel = 0;
	ui.setupUi( this );
	observer = new Observer(this);

}

SEProteinDesignVisualModelBackboneProperties::~SEProteinDesignVisualModelBackboneProperties() {

	if (!visualModel.isValid()) return;

	visualModel->disconnectBaseSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onBaseEvent));
	visualModel->disconnectVisualSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onVisualEvent));

}

void SEProteinDesignVisualModelBackboneProperties::loadSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;
	
	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

void SEProteinDesignVisualModelBackboneProperties::saveSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;

	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignVisualModelBackboneProperties::getUUID() const { return SBCContainerUUID( "BAAC7F13-E48E-A446-8AA7-BFDF3421A9BF" );}

QPixmap SEProteinDesignVisualModelBackboneProperties::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your visual model.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignVisualModelBackbonePropertiesIcon.png"));

}

QString SEProteinDesignVisualModelBackboneProperties::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your visual model inside SAMSON

	return "SEProteinDesignVisualModelBackbone properties"; 

}

int SEProteinDesignVisualModelBackboneProperties::getFormat() const {

	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)

	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEProteinDesignVisualModelBackboneProperties::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this visual model in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";

}

bool SEProteinDesignVisualModelBackboneProperties::setup() {

	SBNodeIndexer nodeIndexer;
	SB_FOR(SBNode* node, *SAMSON::getActiveDocument()->getSelectedNodes()) node->getNodes(nodeIndexer, SBNode::GetClass() == std::string("SEProteinDesignVisualModelBackbone") && SBNode::GetElement() == std::string("SEProteinDesign") && SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID));

	if (nodeIndexer.size() == 1) {

		visualModel = static_cast<SEProteinDesignVisualModelBackbone*>((nodeIndexer)[0]);
		visualModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onBaseEvent));
		visualModel->connectVisualSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onVisualEvent));

		return true;

	}

	return false;

}

bool SEProteinDesignVisualModelBackboneProperties::setup(SBNode* node) {

	if (node->getProxy()->getName() != "SEProteinDesignVisualModelBackbone") return false;
	if (node->getProxy()->getElement() != "SEProteinDesign") return false;
	if (node->getProxy()->getElementUUID() != SBUUID(SB_ELEMENT_UUID)) return false;

	visualModel = static_cast<SEProteinDesignVisualModelBackbone*>(node);
	visualModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onBaseEvent));
	visualModel->connectVisualSignalToSlot(observer(), SB_SLOT(&SEProteinDesignVisualModelBackboneProperties::Observer::onVisualEvent));

	return true;

}

SEProteinDesignVisualModelBackboneProperties::Observer::Observer(SEProteinDesignVisualModelBackboneProperties* properties) { this->properties = properties; }
SEProteinDesignVisualModelBackboneProperties::Observer::~Observer() {}

void SEProteinDesignVisualModelBackboneProperties::Observer::onBaseEvent(SBBaseEvent* baseEvent) {

	if (baseEvent->getType() == SBBaseEvent::NodeEraseBegin) properties->hide();

}

void SEProteinDesignVisualModelBackboneProperties::Observer::onVisualEvent(SBVisualEvent* visualEvent) {

	if (visualEvent->getType() == SBVisualEvent::VisualModelChanged) {
		
		// SAMSON Element generator pro tip: modify this function if the property window
		// needs to be updated when the VisualModelChanged event is sent
				
	}

}
