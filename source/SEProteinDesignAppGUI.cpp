#include "SEProteinDesignAppGUI.hpp"
#include "SEProteinDesignApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"
#include <QComboBox>
#include <string>

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



//string* a = new string[5]{"A : 10%","B : 20%","C : 30%","D : 40%","E : 0%"};

//string* b = new string[5]{"A : 20%","B : 40%","C : 10%","D : 0%","E : 30%"};

//string* c = new string[5]{"A : 0%","B : 40%","C : 20%","D : 30%","E : 10%"};

//string** resultat = new string*[3]{a,b,c};

void SEProteinDesignAppGUI::compute(){

    ui.label->setText(QString("test"));

    string** resultat = getApp()->prediction();
    int n = 3; //number of amino acids, not found yet
    int m = 22;
    ui.table->setColumnCount(2);
    ui.table->setRowCount(n);

    for (int i=0;i<n;i++){

        QTableWidgetItem *text = new QTableWidgetItem(QString("Amino Acid #") + QString("%1").arg(i));
        ui.table->setItem(i,0,text);

        QComboBox *combo = new QComboBox;
        for (int j=0;j<m;j++){
        std::string str = resultat[i][j];
        QString t = QString::fromStdString(str);
        combo->addItem(t);
        }

        ui.table->setCellWidget(i,1,combo);
    }

}
