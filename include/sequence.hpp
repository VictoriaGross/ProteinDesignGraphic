#include <string> /* string */
#include <cmath> /* round */

#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP


static const std::string aminoacid_list[22] =  {"ALA", "ARG", "ASN", "ASP", "CYS", "GLU", "GLN", "GLY", "HIS", "ILE", "LEU","LYS", "MET", "PHE", "PRO", "PYL", "SEL", "SER", "THR", "TRP", "TYR", "VAL"};

class Sequence
{
public:
    Sequence(double** predicted_protein, int protein_size);
    std::string** getSequence(); // returns a 2D-Array with probabilities

private:
       std::string** sequence;

       std::string writeAAProb(double prob, int aaNumber);
       std::string* sortAA(std::string* arrayToSort, double* weights);

};

#endif // SEQUENCE_HPP
