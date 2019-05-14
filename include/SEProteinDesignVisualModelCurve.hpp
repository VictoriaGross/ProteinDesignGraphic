#pragma once 

#include "SBMVisualModel.hpp"

#include "SBBaseEvent.hpp"
#include "SBDocumentEvent.hpp"
#include "SBStructuralEvent.hpp"
#include "SEProteinDesignNodeConstructionPoint.hpp"


/// This class implements a visual model

class SEProteinDesignVisualModelCurve : public SBMVisualModel {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEProteinDesignVisualModelCurve();																													///< Builds a visual model					
	SEProteinDesignVisualModelCurve(const SBNodeIndexer& nodeIndexer);																					///< Builds a visual model 
	virtual ~SEProteinDesignVisualModelCurve();																											///< Destructs the visual model

	//@}

	/// \name Serialization
	//@{

	virtual bool												isSerializable() const;													///< Returns true when the class is serializable

	virtual void												serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber = SB_SDK_VERSION_NUMBER, const SBVersionNumber& classVersionNumber = SBVersionNumber(1, 0, 0)) const;		///< Serializes the node
	virtual void												unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber = SB_SDK_VERSION_NUMBER, const SBVersionNumber& classVersionNumber = SBVersionNumber(1, 0, 0));			///< Unserializes the node

	//@}

	/// \name Topology
	//@{

	virtual	void												eraseImplementation();													///< Erases the visual model

	//@}

	/// \name Rendering
	//@{

	virtual void												display();																///< Displays the visual model
	virtual void												displayForShadow();														///< Displays the visual model for shadow purposes
	virtual void												displayForSelection();													///< Displays the visual model for selection purposes

	virtual void												expandBounds(SBIAPosition3& bounds) const;								///< Expands the bounds to make sure the visual model fits inside them

	virtual void												collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData);		///< To collect ambient occlusion data

	//@}

	/// \name Events
	//@{

	virtual void												onBaseEvent(SBBaseEvent* baseEvent);									///< Handles base events
	virtual void												onDocumentEvent(SBDocumentEvent* documentEvent);						///< Handles document events
	virtual void												onStructuralEvent(SBStructuralEvent* documentEvent);					///< Handles structural events

	//@}

    void addNode(SEProteinDesignNodeConstructionPoint* ConstructionNode);
    void removeNode(SEProteinDesignNodeConstructionPoint* ConstructionNode);

private :
    SBPointerList<SEProteinDesignNodeConstructionPoint> ConstructionNodeList;


};


SB_REGISTER_TARGET_TYPE(SEProteinDesignVisualModelCurve, "SEProteinDesignVisualModelCurve", "A94CACD0-52DC-8157-E843-FF5246F9CB94");
SB_DECLARE_BASE_TYPE(SEProteinDesignVisualModelCurve, SBMVisualModel);
