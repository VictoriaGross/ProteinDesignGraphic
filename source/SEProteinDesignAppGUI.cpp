#include "SEProteinDesignAppGUI.hpp"
#include "SEProteinDesignApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEProteinDesignAppGUI::SEProteinDesignAppGUI( SEProteinDesignApp* t ) : SBGApp( t ) {

	ui.setupUi( this );

}

SEProteinDesignAppGUI::~SEProteinDesignAppGUI() {

}

SEProteinDesignApp* SEProteinDesignAppGUI::getApp() const { return static_cast<SEProteinDesignApp*>(SBGApp::getApp()); }

void SEProteinDesignAppGUI::loadSettings(SBGSettings* settings) {

	if (settings == NULL) return;
	
	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

void SEProteinDesignAppGUI::saveSettings(SBGSettings* settings) {

	if (settings == NULL) return;

	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignAppGUI::getUUID() const { return SBCContainerUUID( "A3740A57-EA30-78F5-A825-206EBDAB26B5" );}

QPixmap SEProteinDesignAppGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your app.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignAppIcon.png"));

}

QString SEProteinDesignAppGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your app inside SAMSON

	return "SEProteinDesignApp"; 

}

int SEProteinDesignAppGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)
	
	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEProteinDesignAppGUI::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this app in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";
	
}
