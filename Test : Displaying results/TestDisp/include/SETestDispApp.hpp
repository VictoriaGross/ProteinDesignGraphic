#pragma once 

#include "SBDApp.hpp"
#include "SETestDispAppGUI.hpp"
#include <QAbstractTableModel>



/// This class implements the functionality of the app

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SETestDispAppGUI class

class SETestDispApp : public SBDApp {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SETestDispApp();																													///< Constructs an app
	virtual ~SETestDispApp();																											///< Destructs the app

	//@}

	/// \name GUI
	//@{

	SETestDispAppGUI*											getGUI() const;															///< Returns a pointer to the GUI of the app

	//@}

};


SB_REGISTER_TARGET_TYPE(SETestDispApp, "SETestDispApp", "C45B8C93-BB8A-9CB7-C587-B9E232FA99AB");
SB_DECLARE_BASE_TYPE(SETestDispApp, SBDApp);


class MyModel : public QAbstractTableModel{
    Q_OBJECT
public:
    MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};
