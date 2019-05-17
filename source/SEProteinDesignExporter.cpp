#include "SEProteinDesignExporter.hpp"
#include "SEProteinDesignExporterGUI.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"
#include <fstream>
#include "SAMSON.hpp"

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

        return std::string("XYZ format (*.xyz)");

}

std::string SEProteinDesignExporter::getExtension() const {

        // SAMSON Element generator pro tip: modify this function to return the extension of the exporter

        return std::string("xyz");

}

bool SEProteinDesignExporter::exportToFile(const SBNodeIndexer& nodeIndexer, const std::string& fileName, const SBList<std::string>* parameters) {

        // SAMSON Element generator pro tip: modify this function to export the nodes contained in nodeIndexer to a file.
        // Please refer to tutorials for examples.
    SBNodeIndexer atomIndexer;
    SB_FOR(SBNode* node, nodeIndexer) node->getNodes(atomIndexer, SBNode::IsType(SBNode::Undefined));
    // create file
    ofstream file;
    file.open(fileName.c_str());
    // write the header
    file << atomIndexer.size() << std::endl; // number of atoms
    file << "SAMSON Export" << std::endl;

    for (unsigned int i = 0; i < atomIndexer.size(); i++) {
        SEProteinDesginCarbonAlpha* currentAtom = static_cast<SEProteinDesginCarbonAlpha*>(atomIndexer[i]);
        SBPosition3 const& currentAtomPosition = currentAtom->getPosition();
        // file << SAMSON::getElementSymbol(currentAtom->getElementType()) unnecessary because all atoms = carbonalpha
            << " " << SBQuantity::angstrom(currentAtomPosition.v[0]).getValue()
            << " " << SBQuantity::angstrom(currentAtomPosition.v[1]).getValue()
            << " " << SBQuantity::angstrom(currentAtomPosition.v[2]).getValue() << "\n";
    }

    // close the file
    file.close();
    return true;
}
