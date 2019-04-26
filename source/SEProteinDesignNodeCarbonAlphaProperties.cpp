#include "SEProteinDesignNodeCarbonAlphaProperties.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEProteinDesignNodeCarbonAlphaProperties::SEProteinDesignNodeCarbonAlphaProperties() {

	node = 0;
	ui.setupUi( this );
	observer = new Observer(this);

}

SEProteinDesignNodeCarbonAlphaProperties::~SEProteinDesignNodeCarbonAlphaProperties() {

	if (!node.isValid()) return;

	node->disconnectBaseSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignNodeCarbonAlphaProperties::Observer::onBaseEvent));

}

void SEProteinDesignNodeCarbonAlphaProperties::loadSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;
	
	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

void SEProteinDesignNodeCarbonAlphaProperties::saveSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;

	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignNodeCarbonAlphaProperties::getUUID() const { return SBCContainerUUID( "BF234364-EC9D-D4E5-C9F7-024342D40760" );}

QPixmap SEProteinDesignNodeCarbonAlphaProperties::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your node.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignNodeCarbonAlphaPropertiesIcon.png"));

}

QString SEProteinDesignNodeCarbonAlphaProperties::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your node inside SAMSON

	return "SEProteinDesignNodeCarbonAlpha properties"; 

}

int SEProteinDesignNodeCarbonAlphaProperties::getFormat() const {

	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)

	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEProteinDesignNodeCarbonAlphaProperties::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this node in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";

}

bool SEProteinDesignNodeCarbonAlphaProperties::setup() {

	SBNodeIndexer nodeIndexer;
	SB_FOR(SBNode* node, *SAMSON::getActiveDocument()->getSelectedNodes()) node->getNodes(nodeIndexer, SBNode::GetClass() == std::string("SEProteinDesignNodeCarbonAlpha") && SBNode::GetElement() == std::string("SEProteinDesign") && SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID));

	if (nodeIndexer.size() == 1) {

		node = static_cast<SEProteinDesignNodeCarbonAlpha*>((nodeIndexer)[0]);
		node->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignNodeCarbonAlphaProperties::Observer::onBaseEvent));

		return true;

	}

	return false;

}

bool SEProteinDesignNodeCarbonAlphaProperties::setup(SBNode* node) {

	if (node->getProxy()->getName() != "SEProteinDesignNodeCarbonAlpha") return false;
	if (node->getProxy()->getElement() != "SEProteinDesign") return false;
	if (node->getProxy()->getElementUUID() != SBUUID(SB_ELEMENT_UUID)) return false;

	node = static_cast<SEProteinDesignNodeCarbonAlpha*>(node);
	node->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignNodeCarbonAlphaProperties::Observer::onBaseEvent));

	return true;

}

SEProteinDesignNodeCarbonAlphaProperties::Observer::Observer(SEProteinDesignNodeCarbonAlphaProperties* properties) { this->properties = properties; }
SEProteinDesignNodeCarbonAlphaProperties::Observer::~Observer() {}

void SEProteinDesignNodeCarbonAlphaProperties::Observer::onBaseEvent(SBBaseEvent* baseEvent) {

	if (baseEvent->getType() == SBBaseEvent::NodeEraseBegin) properties->hide();

}
