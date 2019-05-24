#include "SEProteinDesignApp.hpp"
#include "SEProteinDesignAppGUI.hpp"
#include "SAMSON.hpp"
#include "SEProteinDesignNodeCarbonAlpha.hpp"
#include <filesystem>
#include "QDirIterator"
#include "SBAtom.hpp"
#include "SBList.hpp"

using namespace std;

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


double**  SEProteinDesignApp::findAminoAcid() {

    //On recupere les alpha carbone des amino acid
    SBNodeIndexer listCA;
    listCA = getListNodes();

    int n = 0;


    SB_FOR(SBNode* node, listCA){
        n++;
    }

    SBAtom** list_alpha_carbon = new SBAtom*[n];

    int i=0;

    SB_FOR(SBNode* node, listCA){
        SBAtom* carbone_alpha = static_cast<SBAtom*>(node);
        list_alpha_carbon[i]= carbone_alpha;
        i++;
    }

    //On genere la matrice distance
    double** list_alpha_carbon_distance = new double*[n];

    for (int i =0;i<n;i++){
        list_alpha_carbon_distance[i] = new double[min(14, n-i-1)];
        for (int j=0;j<min(14, n-i-1);j++){
            list_alpha_carbon_distance[i][j] = distance(list_alpha_carbon[i],list_alpha_carbon[i+j+1]);
        }
    }

    return list_alpha_carbon_distance;
}

double SEProteinDesignApp :: distance(SBAtom* atom1,SBAtom* atom2){

    return SBQuantity::angstrom((atom1->getPosition()-atom2->getPosition()).norm()).getValue();

}

void SEProteinDesignApp::prediction_write(double** distances, int protein_size, int input_shape){
    ofstream file("../resource/prediction/distances_file.csv", ios::out | ios::trunc);
            if(file){
                file << protein_size << endl;
                file << 15 << "," << input_shape << endl; // size of one sequence, input shape

                for(int i = 0; i < protein_size; i++){
                    for(int j = 0; j < input_shape - 1; j++){ file << distances[i][j] << ",";}
                    file << distances[i][input_shape] << endl;
                }

                file.close();
            }
}



double** SEProteinDesignApp::prediction_read(){
    ifstream file("../resource/prediction/predicted_protein.csv", ios::in);  // on ouvre le fichier en lecture

    if(file){
        int protein_size;
        file >> protein_size;

        //initialization of prediction
        double** prediction = new double*[protein_size];
        for(int i = 0; i < protein_size; i++){ prediction[i] = new double[22];}

        for(int i = 0; i < protein_size; i ++){
            for(int j = 0; j < 22; j++) {
                file >> prediction[i][j];
                file.ignore();
            }
        }
        file.close();
        return prediction;
    }
    cerr << "ERROR: File predicted_protein.csv does not exist !!" << endl;
    return nullptr;
}


string** SEProteinDesignApp::prediction()
{
    // get distances
    double** distances = findAminoAcid();
    int protein_size = sizeof(distances)/sizeof(*distances);
    int input_shape = 105;

    // Write the distances file
    prediction_write(distances, protein_size, input_shape);

    // Call the script (depending on the platform)

    #if defined( __APPLE__) // Mac OS
        system("./../resource/prediction/mac/prediction");

    #elif defined(__WIN32) // Windows
        system("start ../resource/prediction/win/prediction.exe");

    #elif defined(__linux__) // Linux
        system("./../resource/prediction/linux/prediction");

    #else
        cerr << "ERROR : Platform not supported" << endl;

    #endif


    // Get back the predicted_protein.csv
    double** predicted_protein = prediction_read();

    // Transform it into an array of strings
    Sequence seq(predicted_protein, protein_size);
    string** probabilities = seq.getSequence();

    return probabilities;
}
