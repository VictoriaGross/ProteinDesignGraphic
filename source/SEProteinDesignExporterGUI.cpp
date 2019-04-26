#include "SEProteinDesignExporterGUI.hpp"
#include "SEProteinDesignExporter.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"
#include <QShortcut>

SEProteinDesignExporterGUI::SEProteinDesignExporterGUI( SEProteinDesignExporter* t ) : SBGFileExporter( t ) {

	ui.setupUi( this );

}

SEProteinDesignExporterGUI::~SEProteinDesignExporterGUI() {

}

SEProteinDesignExporter* SEProteinDesignExporterGUI::getExporter() const { return static_cast<SEProteinDesignExporter*>(exporter); }

void SEProteinDesignExporterGUI::loadSettings(SBGSettings* settings) {

	if (settings == NULL) return;
	
	// SAMSON Element generator pro tip: complete this function so your exporter can save its GUI state from one session to the next

}

void SEProteinDesignExporterGUI::saveSettings(SBGSettings* settings) {

	if (settings == NULL) return;

	// SAMSON Element generator pro tip: complete this function so your exporter can save its GUI state from one session to the next

}

SBCContainerUUID SEProteinDesignExporterGUI::getUUID() const { return SBCContainerUUID( "A236BD73-C878-9C42-D931-5B9A801A1480" );}

QPixmap SEProteinDesignExporterGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your exporter.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEProteinDesignExporterIcon.png"));

}

QString SEProteinDesignExporterGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your exporter inside SAMSON

	return "SEProteinDesignExporter"; 

}

int SEProteinDesignExporterGUI::getFormat() const {

	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)

	return (SBGWindow::Lockable);

}

QString SEProteinDesignExporterGUI::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this exporter in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";

}
