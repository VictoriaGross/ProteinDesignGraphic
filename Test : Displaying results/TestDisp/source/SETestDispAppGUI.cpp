#include "SETestDispAppGUI.hpp"
#include "SETestDispApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SETestDispAppGUI::SETestDispAppGUI( SETestDispApp* t ) : SBGApp( t ) {

	ui.setupUi( this );

}

SETestDispAppGUI::~SETestDispAppGUI() {

}

SETestDispApp* SETestDispAppGUI::getApp() const { return static_cast<SETestDispApp*>(SBGApp::getApp()); }

void SETestDispAppGUI::loadSettings(SBGSettings* settings) {

	if (settings == NULL) return;
	
	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

void SETestDispAppGUI::saveSettings(SBGSettings* settings) {

	if (settings == NULL) return;

	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

SBCContainerUUID SETestDispAppGUI::getUUID() const { return SBCContainerUUID( "3C401350-2B57-8472-1B1E-820607B3E1B2" );}

QPixmap SETestDispAppGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your app.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SETestDispAppIcon.png"));

}

QString SETestDispAppGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your app inside SAMSON

	return "SETestDispApp"; 

}

int SETestDispAppGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)
	
	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SETestDispAppGUI::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this app in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";
	
}

void SETestDispAppGUI::compute(){
    MyModel model;
    ui.table->setModel(&model);
    ui.label->setText(QString("aaa"));
    ui.table->show();
}