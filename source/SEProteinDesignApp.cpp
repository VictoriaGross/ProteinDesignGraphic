#include "SEProteinDesignApp.hpp"
#include "SEProteinDesignAppGUI.hpp"
#include "SAMSON.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"

SEProteinDesignApp::SEProteinDesignApp() {

	setGUI(new SEProteinDesignAppGUI(this));
	getGUI()->loadDefaultSettings();

}

SEProteinDesignApp::~SEProteinDesignApp() {

	getGUI()->saveDefaultSettings();
	delete getGUI();

}

SEProteinDesignAppGUI* SEProteinDesignApp::getGUI() const { return static_cast<SEProteinDesignAppGUI*>(SBDApp::getGUI()); }


SBNodeIndexer SEProteinDesignApp::getListNodes() {

	visualModelList = SAMSON::getActiveLayer()->getVisualModelList();
	//SBPointerList<SEProteinDesignNodeCarbonAlpha> listCarbonAlpha;
	SBNodeIndexer listCarbonAlpha; 
	SBNodeIndexer currentList; 

	SEProteinDesignNodeCarbonAlpha* last;
	SEProteinDesignNodeCarbonAlpha* first;
	//SBDDataGraphNode* first; 
	SEProteinDesignNodeCarbonAlpha* current;


	double dist, curvelength;
	SBPosition3 positionlast, positionfirst, positioncurent;
	float error = (float)SBQuantity::length(SBQuantity::angstrom(0.001)).getValue();
	float step = (float)SBQuantity::length(SBQuantity::angstrom(3.8)).getValue();
	int count = 0;
	SB_FOR(SBMVisualModel* currentVisualModel, *visualModelList) {
		
		/*if (currentVisualModel->getType() == "SEProteinDesignVisualModelBackbone") {
			SEProteinDesignVisualModelBackbone currentBackbone = *currentVisualModel; 


		 }*/ 
		currentVisualModel->getNodes(currentList);
		if (count > 0) {
			first = (SEProteinDesignNodeCarbonAlpha*)currentVisualModel->getNode(0);

			// get Nodes of current Visual Model 

			// if not the first visual model get the first Node, calculate the distance between this one and the last one of the previous model. 

			// calculate a curve of the length divisible by 3.8 and calculate CarbonAlphas on this curve. 

			positionlast = last->getPosition();
			positionfirst = first->getPosition();


			float x1, x2, y1, y2, z1, z2;
			x1 = positionlast.v[0].getValue();
			y1 = positionlast.v[1].getValue();
			z1 = positionlast.v[2].getValue();
			x2 = positionfirst.v[0].getValue();
			y2 = positionfirst.v[1].getValue();
			z2 = positionfirst.v[2].getValue();

			dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));



			int numberofnodesmin = (int)(dist  / step);
			curvelength = step * numberofnodesmin;

			double R = sqrt(pow(dist, 3) * 1. / 24 / (curvelength - dist));
			double x0, y0, z0, x, y, z;
			double A, B, C, D;

			A = 1 + (x2 - x1) * (x2 - x1) / (y2 - y1) / (y2 - y1);
			B = -2 * x1 - (x2 - x1) / (y2 - y1) * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1) / (y2 - y1) + 2 * y1 * (x2 - x1) / (y2 - y1);
			C = x1 * x1 + y1 * y1 - R * R + (z2 - z1) * (z2 - z1) / 4. + 1. / 4 * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1) / (y2 - y1) / (y2 - y1) - y1 * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1) / (y2 - y1);


			z0 = (z1 + z2) * 1. / 2;
			x0 = (-B + sqrt(B * B - 4. * A * C)) / 2. / A;
			y0 = -(x2 - x1) / (y2 - y1) * x0 + 1 / 2. * (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1) / (y2 - y1);

			double xmin, ymin, zmin, xmax, ymax, zmax;
			xmin = min(x1, x2);
			ymin = min(y1, y2);
			zmin = min(z1, z2);
			xmax = max(x1, x2);
			ymax = max(y1, y2);
			zmax = max(z1, z2);

			double forstepx = error;
			double forstepy = error;
			double forstepz = error;

			if (x2 < x1) forstepx = -forstepx;
			if (y2 < y1) forstepy = -forstepy;
			if (z2 < z1) forstepz = -forstepz;

			A = (y2 - y0) * (z1 - z0) - (y1 - y0) * (z2 - z0);
			B = -(x2 - x0) * (z2 - z0) + (z1 - z0) * (x2 - x0);
			C = (x2 - x0) * (y1 - y0) - (x1 - x0) * (y2 - y0);

			double xcur = x1, ycur = y1, zcur = z1;

			for (x = x1; x < x1; x += forstepx) {
				for (y = y1; y < y2; y += forstepy) {
					for (z = z1; z < z2; z += forstepz) {
						if ((A * (x - x0) + B * (y - y0) + C * (z - z0) == 0) && ((x - x0) * (x - x0) + (y - y0) * (y - y0) + (z - z0) * (z - z0) == R * R)) {
							if ((x - xcur) * (x - xcur) + (y - ycur) * (y - ycur) + (z - zcur) * (z - zcur) == step * step) {
								positioncurent.v[0].setValue(x);
								positioncurent.v[1].setValue(y);
								positioncurent.v[2].setValue(z);
								current = new SEProteinDesignNodeCarbonAlpha(positioncurent);
								listCarbonAlpha.addNode(current);
							}
						}
					}
				}
			}
		}


		// add the rest of the nodes 
		int count_nodes = 0;
		SB_FOR(SBDDataGraphNode* node, currentList) {
			listCarbonAlpha.addNode(node);
			count_nodes++;
		}
		last = (SEProteinDesignNodeCarbonAlpha*)currentList.getNode(count_nodes - 1); 
		

//		SB_FOR(SEProteinDesignNodeCarbonAlpha* currentNode, currentVisualModel->pathNodeCarbonAlphaList) {
	//		listCarbonAlpha.addReferenceTarget(currentNode);
//		}
	}
	return listCarbonAlpha;

}