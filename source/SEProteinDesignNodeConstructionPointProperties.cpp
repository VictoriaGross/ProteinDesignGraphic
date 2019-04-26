#include "SEProteinDesignNodeConstructionPointProperties.hpp"
#include "SEProteinDesignNodeConstructionPoint.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEProteinDesignNodeConstructionPointProperties::SEProteinDesignNodeConstructionPointProperties() {

	node = 0;
	ui.setupUi( this );
	observer = new Observer(this);

}

SEProteinDesignNodeConstructionPointProperties::~SEProteinDesignNodeConstructionPointProperties() {

	if (!node.isValid()) return;

	node->disconnectBaseSignalFromSlot(observer(), SB_SLOT(&SEProteinDesignNodeConstructionPointProperties::Observer::onBaseEvent));

}

void SEProteinDesignNodeConstructionPointProperties::loadSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;
	
	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

void SEProteinDesignNodeConstructionPointProperties::saveSettings(SBGSettings* settings) {

	if ( settings == 0 ) return;

	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignNodeConstructionPointProperties::getUUID() const { return SBCContainerUUID( "711311EF-5EAC-C7EE-0EFA-DCBD9B34EE40" );}

QPixmap SEProteinDesignNodeConstructionPointProperties::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your node.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignNodeConstructionPointPropertiesIcon.png"));

}

QString SEProteinDesignNodeConstructionPointProperties::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your node inside SAMSON

	return "SEProteinDesignNodeConstructionPoint properties"; 

}

int SEProteinDesignNodeConstructionPointProperties::getFormat() const {

	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)

	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEProteinDesignNodeConstructionPointProperties::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this node in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";

}

bool SEProteinDesignNodeConstructionPointProperties::setup() {

	SBNodeIndexer nodeIndexer;
	SB_FOR(SBNode* node, *SAMSON::getActiveDocument()->getSelectedNodes()) node->getNodes(nodeIndexer, SBNode::GetClass() == std::string("SEProteinDesignNodeConstructionPoint") && SBNode::GetElement() == std::string("SEProteinDesign") && SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID));

	if (nodeIndexer.size() == 1) {

		node = static_cast<SEProteinDesignNodeConstructionPoint*>((nodeIndexer)[0]);
		node->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignNodeConstructionPointProperties::Observer::onBaseEvent));

		return true;

	}

	return false;

}

bool SEProteinDesignNodeConstructionPointProperties::setup(SBNode* node) {

	if (node->getProxy()->getName() != "SEProteinDesignNodeConstructionPoint") return false;
	if (node->getProxy()->getElement() != "SEProteinDesign") return false;
	if (node->getProxy()->getElementUUID() != SBUUID(SB_ELEMENT_UUID)) return false;

	node = static_cast<SEProteinDesignNodeConstructionPoint*>(node);
	node->connectBaseSignalToSlot(observer(), SB_SLOT(&SEProteinDesignNodeConstructionPointProperties::Observer::onBaseEvent));

	return true;

}

SEProteinDesignNodeConstructionPointProperties::Observer::Observer(SEProteinDesignNodeConstructionPointProperties* properties) { this->properties = properties; }
SEProteinDesignNodeConstructionPointProperties::Observer::~Observer() {}

void SEProteinDesignNodeConstructionPointProperties::Observer::onBaseEvent(SBBaseEvent* baseEvent) {

	if (baseEvent->getType() == SBBaseEvent::NodeEraseBegin) properties->hide();

}
