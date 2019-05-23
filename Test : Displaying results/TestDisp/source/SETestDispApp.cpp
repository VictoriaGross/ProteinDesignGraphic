#include "SETestDispApp.hpp"
#include "SETestDispAppGUI.hpp"


SETestDispApp::SETestDispApp() {

	setGUI(new SETestDispAppGUI(this));
	getGUI()->loadDefaultSettings();

}

SETestDispApp::~SETestDispApp() {

	getGUI()->saveDefaultSettings();
	delete getGUI();

}

SETestDispAppGUI* SETestDispApp::getGUI() const { return static_cast<SETestDispAppGUI*>(SBDApp::getGUI()); }



MyModel::MyModel(QObject *parent):QAbstractTableModel(parent){}

int MyModel::rowCount(const QModelIndex & /*parent*/) const{
   return 4;
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const{
    return 2;
}

string tab[2][2] = {{"ab","bc"},{"cd","de"}};

QVariant MyModel::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole){
       //return QString("%1")
       //            .arg(tab[index.row()][index.column()]);
        return QString("test");
    }
    return QVariant();
}

