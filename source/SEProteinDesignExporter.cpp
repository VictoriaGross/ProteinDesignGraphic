#include "SEProteinDesignExporter.hpp"
#include "SEProteinDesignExporterGUI.hpp"

SEProteinDesignExporter::SEProteinDesignExporter() {

	propertyDialog = new SEProteinDesignExporterGUI(this);
	propertyDialog->loadDefaultSettings();

}

SEProteinDesignExporter::~SEProteinDesignExporter() {

	propertyDialog->saveDefaultSettings();
	delete propertyDialog;

}

std::string SEProteinDesignExporter::getFilter() const {

	// SAMSON Element generator pro tip: modify this function to return the filter of the exporter

	return std::string("TXT format (*.txt)");

}

std::string SEProteinDesignExporter::getExtension() const {

	// SAMSON Element generator pro tip: modify this function to return the extension of the exporter

	return std::string("txt");

}

bool SEProteinDesignExporter::exportToFile(const SBNodeIndexer& nodeIndexer, const std::string& fileName, const SBList<std::string>* parameters) {

	// SAMSON Element generator pro tip: modify this function to export the nodes contained in nodeIndexer to a file.
	// Please refer to tutorials for examples.

	return true;

}

