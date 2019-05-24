/// \headerfile SEProteinDesignNodeCarbonAlphaDescriptor.hpp "SEProteinDesignNodeCarbonAlphaDescriptor.hpp"
#include "SEProteinDesignNodeCarbonAlphaDescriptor.hpp"

/// \headerfile SEProteinDesignNodeCarbonAlphaGUIDescriptor.hpp "SEProteinDesignNodeCarbonAlphaGUIDescriptor.hpp"
#include "SEProteinDesignNodeCarbonAlphaGUIDescriptor.hpp"

/// \headerfile SEProteinDesignNodeCarbonAlphaPropertiesDescriptor.hpp "SEProteinDesignNodeCarbonAlphaPropertiesDescriptor.hpp"
#include "SEProteinDesignNodeCarbonAlphaPropertiesDescriptor.hpp"

/// \headerfile SEProteinDesignNodeConstructionPointDescriptor.hpp "SEProteinDesignNodeConstructionPointDescriptor.hpp"
#include "SEProteinDesignNodeConstructionPointDescriptor.hpp"

/// \headerfile SEProteinDesignNodeConstructionPointGUIDescriptor.hpp "SEProteinDesignNodeConstructionPointGUIDescriptor.hpp"
#include "SEProteinDesignNodeConstructionPointGUIDescriptor.hpp"

/// \headerfile SEProteinDesignNodeConstructionPointPropertiesDescriptor.hpp "SEProteinDesignNodeConstructionPointPropertiesDescriptor.hpp"
#include "SEProteinDesignNodeConstructionPointPropertiesDescriptor.hpp"

/// \headerfile SEProteinDesignEditorHelixDescriptor.hpp "SEProteinDesignEditorHelixDescriptor.hpp"
#include "SEProteinDesignEditorHelixDescriptor.hpp"

/// \headerfile SEProteinDesignEditorSplineDescriptor.hpp "SEProteinDesignEditorSplineDescriptor.hpp"
#include "SEProteinDesignEditorSplineDescriptor.hpp"

/// \headerfile SEProteinDesignVisualModelBackboneDescriptor.hpp "SEProteinDesignVisualModelBackboneDescriptor.hpp"
#include "SEProteinDesignVisualModelBackboneDescriptor.hpp"

/// \headerfile SEProteinDesignVisualModelBackbonePropertiesDescriptor.hpp "SEProteinDesignVisualModelBackbonePropertiesDescriptor.hpp"
#include "SEProteinDesignVisualModelBackbonePropertiesDescriptor.hpp"

/// \headerfile SEProteinDesignVisualModelCurveDescriptor.hpp "SEProteinDesignVisualModelCurveDescriptor.hpp"
#include "SEProteinDesignVisualModelCurveDescriptor.hpp"

/// \headerfile SEProteinDesignVisualModelCurvePropertiesDescriptor.hpp "SEProteinDesignVisualModelCurvePropertiesDescriptor.hpp"
#include "SEProteinDesignVisualModelCurvePropertiesDescriptor.hpp"

/// \headerfile SEProteinDesignExporterDescriptor.hpp "SEProteinDesignExporterDescriptor.hpp"
#include "SEProteinDesignExporterDescriptor.hpp"

#include "SEProteinDesignAppDescriptor.hpp"

// Describe the SAMSON Element

// SAMSON Element generator pro tip: modify the information below if necessary
// (for example when a new class is added, when the version number changes, to describe categories more precisely, etc.)

SB_ELEMENT_DESCRIPTION("Permet de tracer des proteines");
SB_ELEMENT_DOCUMENTATION("Resource/Documentation/doc.html");
SB_ELEMENT_VERSION_NUMBER("0.7.0");

SB_ELEMENT_CLASSES_BEGIN;

	SB_ELEMENT_CLASS(SEProteinDesignApp);
	SB_ELEMENT_CLASS(SEProteinDesignNodeCarbonAlpha);
	SB_ELEMENT_CLASS(SEProteinDesignNodeCarbonAlphaGUI);
	SB_ELEMENT_CLASS(SEProteinDesignNodeCarbonAlphaProperties);
	SB_ELEMENT_CLASS(SEProteinDesignNodeConstructionPoint);
	SB_ELEMENT_CLASS(SEProteinDesignNodeConstructionPointGUI);
	SB_ELEMENT_CLASS(SEProteinDesignNodeConstructionPointProperties);
	SB_ELEMENT_CLASS(SEProteinDesignEditorHelix);
	SB_ELEMENT_CLASS(SEProteinDesignEditorSpline);
	SB_ELEMENT_CLASS(SEProteinDesignVisualModelBackbone);
	SB_ELEMENT_CLASS(SEProteinDesignVisualModelBackboneProperties);
	SB_ELEMENT_CLASS(SEProteinDesignVisualModelCurve);
	SB_ELEMENT_CLASS(SEProteinDesignVisualModelCurveProperties);
	SB_ELEMENT_CLASS(SEProteinDesignExporter);

SB_ELEMENT_CLASSES_END;

SB_ELEMENT_CATEGORIES_BEGIN;

	SB_ELEMENT_CATEGORY(SBClass::Category::General);

SB_ELEMENT_CATEGORIES_END;
