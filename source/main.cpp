#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "sequence.hpp" /* sequence */

using namespace std;

/* This program must be formatted in a SAMSON Element.
 * For the moment, it generates a distances 2D-array filled with zeros: the goal is to get the real distances 2D-array
 * (to be made using SAMSON).
 *
 * This distances 2D-array is written into a distances_file.csv.
 * For now on, it is written in a distances_file_test.csv,
 * the distances_file.csv is a real distances file used for testin (15 first aminoacids of matrix.csv).
 *
 * The program calls a python script which encapsulates the neural network, the problem is that you need to have
 * TF on your python installation, it would be great to find a way to get rid of this problem (maybe making an executable ?)*/

void write(double** distances, int protein_size, int input_shape){
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


double** read(){
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


int main()
{
    /* Add a function to get distances (depends on the SAMSON Element*/
    int protein_size = 15;
    int input_shape = 105;
    double** distances = new double*[protein_size];
    for(int i=0; i<protein_size; i++){ distances[i] = new double[input_shape];}

    // Write the distances file
    write(distances, protein_size, input_shape);

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
    double** predicted_protein = read();

    // Transform it into an array of strings
    Sequence seq(predicted_protein, protein_size);
    string** probabilities = seq.getSequence();

    for(int i=0; i<protein_size; i++){
        cout << i << endl;
        for(int j=0; j<22; j++){
            cout << probabilities[i][j] << endl;
        }
        cout << " " << endl;
    }

    /* Do some stuff */

    // Clean memory space
    delete[] distances;
    delete[] predicted_protein;
    delete[] probabilities;
}
