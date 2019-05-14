#pragma once 

#include "SBIFileExporter.hpp"
#include "SEProteinDesignExporterGUI.hpp"


/// This class implements the functionality of the exporter

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SEProteinDesignExporterGUI class

class SEProteinDesignExporter : public SBIFileExporter {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignExporter();																													///< Constructs an exporter
	virtual ~SEProteinDesignExporter();																											///< Destructs the exporter

	//@}

	/// \name Properties
	//@{

	virtual std::string											getFilter() const;														///< Returns the filter of the exporter
	virtual std::string											getExtension() const;													///< Returns the extension of the exporter

	//@}

	/// \name Parsing
	//@{

	virtual bool												exportToFile(const SBNodeIndexer& nodeIndexer, const std::string& fileName, const SBList<std::string>* parameters = 0);		///< Exports data from SAMSON to a file

	//@}

};


SB_REGISTER_TARGET_TYPE(SEProteinDesignExporter, "SEProteinDesignExporter", "38D26BCA-D0FD-C0C5-08D7-4AB8704E8E3F");
SB_DECLARE_BASE_TYPE(SEProteinDesignExporter, SBIFileExporter);