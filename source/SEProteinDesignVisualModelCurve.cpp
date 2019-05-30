#include "SEProteinDesignVisualModelCurve.hpp"
#include "SAMSON.hpp"
#include "SEProteinDesignEditorSpline.hpp"

#include<deque>


SEProteinDesignVisualModelCurve::SEProteinDesignVisualModelCurve() {

    // SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

}

SEProteinDesignVisualModelCurve::SEProteinDesignVisualModelCurve(const SBNodeIndexer& nodeIndexer) {

    // SAMSON Element generator pro tip: implement this function if you want your visual model to be applied to a set of data graph nodes.
    // You might want to connect to various signals and handle the corresponding events. For example, if your visual model represents a sphere positioned at
    // the center of mass of a group of atoms, you might want to connect to the atoms' base signals (e.g. to update the center of mass when an atom is erased) and
    // the atoms' structural signals (e.g. to update the center of mass when an atom is moved).

}

SEProteinDesignVisualModelCurve::~SEProteinDesignVisualModelCurve() {

    // SAMSON Element generator pro tip: disconnect from signals you might have connected to.

}

bool SEProteinDesignVisualModelCurve::isSerializable() const {

    // SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc.
    // Please refer to the SDK documentation for more information.
    // Modify the line below to "return true;" if you want this visual model be serializable (hence copyable, savable, etc.)

    return false;

}

void SEProteinDesignVisualModelCurve::serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) const {

    SBMVisualModel::serialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

    // SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc.
    // Please refer to the SDK documentation for more information.
    // Complete this function to serialize your visual model.

}

void SEProteinDesignVisualModelCurve::unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer, const SBVersionNumber& sdkVersionNumber, const SBVersionNumber& classVersionNumber) {

    SBMVisualModel::unserialize(serializer, nodeIndexer, sdkVersionNumber, classVersionNumber);

    // SAMSON Element generator pro tip: serialization is used in SAMSON to e.g. save documents, copy nodes, etc.
    // Please refer to the SDK documentation for more information.
    // Complete this function to unserialize your visual model.

}

void SEProteinDesignVisualModelCurve::eraseImplementation() {

    // SAMSON Element generator pro tip: modify this function when you need to perform special tasks when your visual model is erased (e.g. disconnect from nodes you are connected to).
    // Important: this function must be undoable (i.e. only call undoable functions or add an undo command to the undo stack)

}

double SEProteinDesignVisualModelCurve::dist(float t, float x1,float x2,
                                             float y1,float y2,float z1,float z2,float x3,float x0,
                                             float y3,float y0,float z3,float z0, float d, float xa, float ya, float za) {
    double Ax= 2*x1 - 2*xa;
    double Bx= x2-x0;
    double Cx= 2*x0-5*x1+4*x2-x3;
    double Dx = -x0+3*x1-3*x2+x3;
    double Ay= 2*y1 - 2*ya;
    double By= y2-y0;
    double Cy= 2*y0-5*y1+4*y2-y3;
    double Dy = -y0+3*y1-3*y2+y3;
    double Az= 2*z1 - 2*za;
    double Bz= z2-z0;
    double Cz= 2*z0-5*z1+4*z2-z3;
    double Dz = -z0+3*z1-3*z2+z3;

    double calcx=0.25*(Ax*Ax+2*Ax*Bx*t+t*t*(2*Ax*Cx+pow(Bx,2))+t*t*t*(2*Ax*Dx+2*Bx*Cx)
                       +t*t*t*t*(Cx*Cx+2*Bx*Dx)+t*t*t*t*t*(2*Cx*Dx)+t*t*t*t*t*t*(Dx*Dx));
    double calcy=0.25*(Ay*Ay+2*Ay*By*t+t*t*(2*Ay*Cy+pow(By,2))+t*t*t*(2*Ay*Dy+2*By*Cy)
                       +t*t*t*t*(Cy*Cy+2*By*Dy)+t*t*t*t*t*(2*Cy*Dy)+t*t*t*t*t*t*(Dy*Dy));
    double calcz=0.25*(Az*Az+2*Az*Bz*t+t*t*(2*Az*Cz+pow(Bz,2))+t*t*t*(2*Az*Dz+2*Bz*Cz)
                       +t*t*t*t*(Cz*Cz+2*Bz*Dz)+t*t*t*t*t*(2*Cz*Dz)+t*t*t*t*t*t*(Dz*Dz));

    return calcx+calcy+calcz-d*d;

}


SBInterval SEProteinDesignVisualModelCurve::dist(SBInterval t, float x1,float x2,
                                                 float y1,float y2,float z1,float z2,float x3,float x0,
                                                 float y3,float y0,float z3,float z0, float d, float xa, float ya, float za) {
    SBInterval Ax(SBQuantity::dimensionless (2*x1 - 2*xa));
    SBInterval Bx(SBQuantity::dimensionless (x2-x0));
    SBInterval Cx(SBQuantity::dimensionless( 2*x0-5*x1+4*x2-x3));
    SBInterval Dx(SBQuantity::dimensionless (-x0+3*x1-3*x2+x3));
    SBInterval Ay(SBQuantity::dimensionless (2*y1 - 2*ya));
    SBInterval By(SBQuantity::dimensionless(y2-y0));
    SBInterval Cy(SBQuantity::dimensionless( 2*y0-5*y1+4*y2-y3));
    SBInterval Dy(SBQuantity::dimensionless( -y0+3*y1-3*y2+y3));
    SBInterval Az(SBQuantity::dimensionless( 2*z1 - 2*za));
    SBInterval Bz(SBQuantity::dimensionless( z2-z0));
    SBInterval Cz(SBQuantity::dimensionless( 2*z0-5*z1+4*z2-z3));
    SBInterval Dz(SBQuantity::dimensionless( -z0+3*z1-3*z2+z3));

    SBInterval calcx=0.25*(Ax*Ax+2*Ax*Bx*t+t*t*(2*Ax*Cx+Bx*Bx)+t*t*t*(2*Ax*Dx+2*Bx*Cx)
                           +t*t*t*t*(Cx*Cx+2*Bx*Dx)+t*t*t*t*t*(2*Cx*Dx)+t*t*t*t*t*t*(Dx*Dx));
    SBInterval calcy=0.25*(Ay*Ay+2*Ay*By*t+t*t*(2*Ay*Cy+By*By)+t*t*t*(2*Ay*Dy+2*By*Cy)
                           +t*t*t*t*(Cy*Cy+2*By*Dy)+t*t*t*t*t*(2*Cy*Dy)+t*t*t*t*t*t*(Dy*Dy));
    SBInterval calcz=0.25*(Az*Az+2*Az*Bz*t+t*t*(2*Az*Cz+Bz*Bz)+t*t*t*(2*Az*Dz+2*Bz*Cz)
                           +t*t*t*t*(Cz*Cz+2*Bz*Dz)+t*t*t*t*t*(2*Cz*Dz)+t*t*t*t*t*t*(Dz*Dz));

    return calcx+calcy+calcz-SBInterval(SBQuantity::dimensionless(d*d));

}

double SEProteinDesignVisualModelCurve::derivdist(float t, float x1,float x2,
                                                  float y1,float y2,float z1,float z2,float x3,float x0,
                                                  float y3,float y0,float z3,float z0, float d, float xa, float ya, float za) {
    double Ax= 2*x1 - 2*xa;
    double Bx= x2-x0;
    double Cx= 2*x0-5*x1+4*x2-x3;
    double Dx = -x0+3*x1-3*x2+x3;
    double Ay= 2*y1 - 2*ya;
    double By= y2-y0;
    double Cy= 2*y0-5*y1+4*y2-y3;
    double Dy = -y0+3*y1-3*y2+y3;
    double Az= 2*z1 - 2*za;
    double Bz= z2-z0;
    double Cz= 2*z0-5*z1+4*z2-z3;
    double Dz = -z0+3*z1-3*z2+z3;

    double calcx=0.25*(2*Ax*Bx+2*t*(2*Ax*Cx+pow(Bx,2))+3*t*t*(2*Ax*Dx+2*Bx*Cx)
                       +4*t*t*t*(Cx*Cx+2*Bx*Dx)+5*t*t*t*t*(2*Cx*Dx)+6*t*t*t*t*t*(Dx*Dx));
    double calcy=0.25*(2*Ay*By+2*t*(2*Ay*Cy+pow(By,2))+3*t*t*(2*Ay*Dy+2*By*Cy)
                       +4*t*t*t*(Cy*Cy+2*By*Dy)+5*t*t*t*t*(2*Cy*Dy)+6*t*t*t*t*t*(Dy*Dy));
    double calcz=0.25*(2*Az*Bz+2*t*(2*Az*Cz+pow(Bz,2))+3*t*t*(2*Az*Dz+2*Bz*Cz)
                       +4*t*t*t*(Cz*Cz+2*Bz*Dz)+5*t*t*t*t*(2*Cz*Dz)+6*t*t*t*t*t*(Dz*Dz));

    return calcx+calcy+calcz;
}

double SEProteinDesignVisualModelCurve::Newton(float x1,float x2,
                                               float y1,float y2,float z1,float z2,float x3,float x0,
                                               float y3,float y0,float z3,float z0, float d, float xa, float ya, float za) {
    int n =0;
    double sol = 1;
    double nsol;
    if (sqrt(dist(1,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,0,xa,ya,za))<d) {
        return -1;
    }
    while (sqrt((sol-nsol)*(sol-nsol))>0.1 || n<20) {
        nsol = sol - (dist(sol,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,d,xa,ya,za)/derivdist(sol,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,d,xa,ya,za));
        sol=nsol;
        n++;
    }
    return nsol;
}

double SEProteinDesignVisualModelCurve::Dichotomie(float x1,float x2,
                                                   float y1,float y2,float z1,float z2,float x3,float x0,
                                                   float y3,float y0,float z3,float z0, float d, float xa, float ya, float za, float a, float b) {
    if (sqrt(dist(1,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,0,xa,ya,za))<d) {
        return -1;
    } else {
        float m;
        while (b-a>0.01) {
            m = (a+b)/2;
            if (dist(m,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,d,xa,ya,za)*dist(a,x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,d,xa,ya,za)<=0) {
                b=m;
            } else {
                a=m;
            }
        }
    }
    return (a+b)/2;
}

double SEProteinDesignVisualModelCurve::Dichotomie(float x1,float x2,
                                                   float y1,float y2,float z1,float z2,float x3,float x0,
                                                   float y3,float y0,float z3,float z0, float d, float xa, float ya, float za, SBInterval t) {

    std::cout << "Starting dichotomy" << std::endl;
    std::cout << "x0=" << x0 << std::endl;
    std::cout << "y0=" << x0 << std::endl;
    std::cout << "z0=" << y0 << std::endl;
    std::cout << "x1=" << x1 << std::endl;
    std::cout << "y1=" << x1 << std::endl;
    std::cout << "z1=" << y1 << std::endl;
    std::cout << "x2=" << x2 << std::endl;
    std::cout << "y2=" << x2 << std::endl;
    std::cout << "z2=" << y2 << std::endl;
    std::cout << "x3=" << x3 << std::endl;
    std::cout << "y3=" << x3 << std::endl;
    std::cout << "z3=" << y3 << std::endl;


    std::deque<SBInterval> intervalQueue;
    intervalQueue.push_back(t);

    while (!intervalQueue.empty()) {

        SBInterval timeInterval = intervalQueue.front();
        intervalQueue.pop_front();
        SBInterval distBounds = dist(timeInterval, x1, x2, y1, y2, z1, z2, x3, x0, y3, y0, z3, z0,  d,  xa,  ya,  za);
        double d0 = dist(timeInterval.center().getValue(), x1, x2, y1, y2, z1, z2, x3, x0, y3, y0, z3, z0,  d,  xa,  ya,  za);
        std::cout << timeInterval << ":  " << distBounds << std::endl;
        std::cout << timeInterval.center().getValue() << ":  " << d0 << std::endl;
        std::cout << std::endl;

        if (distBounds.i[0]*distBounds.i[1]>SBQuantity::dimensionless(0.0)) {

            if (intervalQueue.empty()) return -1;
            else continue;

        }

        if (timeInterval.diameter() < SBQuantity::dimensionless(1e-10)) return timeInterval.center().getValue();

        SBQuantity::dimensionless middle = timeInterval.center();
        intervalQueue.push_front(SBInterval(middle,timeInterval.i[1]));
        intervalQueue.push_front(SBInterval(timeInterval.i[0],middle));

    }

    return -1;

}

void SEProteinDesignVisualModelCurve::display() {

    if (ConstructionNodeList.empty()) return;

    unsigned int numberOfNodes = ConstructionNodeList.size();
    int n = 50;



    // allocate arrays and initialize them to zeros

    float* positionData = new float[3 * numberOfNodes]();
    float* radiusData = new float[numberOfNodes]();
    float* colorData = new float[4 * numberOfNodes]();
    unsigned int* flagData = new unsigned int[numberOfNodes]();

    float* positionSpline = new float[3 * n * (numberOfNodes-1)]();
    float* radiusSpline = new float[n * (numberOfNodes-1)]();
    float* colorSpline = new float[4 * n * (numberOfNodes-1)]();
    unsigned int* flagSpline = new unsigned int[n * (numberOfNodes-1)]();


    // fill in the arrays

    unsigned int currentIndex = 0;
    std::vector<float> positionCarbon;
    float xa;
    float ya;
    float za;


    SB_FOR(SEProteinDesignNodeConstructionPoint* currentNode, ConstructionNodeList){

        //main nodes


        SBPosition3 position = currentNode->getPosition();

        positionData[3*currentIndex+0] = (float)position.v[0].getValue();
        positionData[3*currentIndex+1] = (float)position.v[1].getValue();
        positionData[3*currentIndex+2] = (float)position.v[2].getValue();
        radiusData[currentIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.2)).getValue();
        colorData[4 * currentIndex + 0] = 1.0f;
        colorData[4 * currentIndex + 1] = 0.0f;
        colorData[4 * currentIndex + 2] = 0.0f;
        colorData[4 * currentIndex + 3] = 1.0f;
        xa=positionData[0];
        ya=positionData[1];
        za=positionData[2];


        flagData[currentIndex] = currentNode->getInheritedFlags() | getInheritedFlags();

        currentIndex++;
    }

    if (numberOfNodes==2){

        float x3 = positionData[3];
        float x2 = positionData[3];
        float x1 = positionData[0];
        float x0 = positionData[0];

        float y3 = positionData[4];
        float y2 = positionData[4];
        float y1 = positionData[1];
        float y0 = positionData[1];

        float z3 = positionData[5];
        float z2 = positionData[5];
        float z1 = positionData[2];
        float z0 = positionData[2];

        xa =x1;
        ya =y1;
        za =z1;
        double t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(0), SBQuantity::dimensionless(1))); //finding the first t such as the distance between two AA is 3.8 A
        double oldt=0;

        while ((t>0) && (t!=-1) && (t<1-0.03)) { // while we can add a carbon alpha
            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            xa=a*x0+b*x1+c*x2+d*x3;
            ya=a*y0+b*y1+c*y2+d*y3;
            za=a*z0+b*z1+c*z2+d*z3;

            positionCarbon.push_back(xa); //adding the coordonnates
            positionCarbon.push_back(ya);
            positionCarbon.push_back(za);
            SBPosition3 positionC=SBPosition3( SBQuantity::length(xa),SBQuantity::length(ya),SBQuantity::length(za));
            SEProteinDesignNodeCarbonAlpha* Carbon = new SEProteinDesignNodeCarbonAlpha(positionC);
            CarbonAlphaList.addReferenceTarget(Carbon);
            oldt = t+0.02;
            t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(oldt), SBQuantity::dimensionless(1))); // finding new t
        }

        for(int i=0;i<n;i++){
            float t = float(i+1)/(n+1);

            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            positionSpline[3*i+0] = a*x0+b*x1+c*x2+d*x3;
            positionSpline[3*i+1] = a*y0+b*y1+c*y2+d*y3;
            positionSpline[3*i+2] = a*z0+b*z1+c*z2+d*z3;


            radiusSpline[i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

            colorSpline[4*i+0] = 1.0f;
            colorSpline[4*i+1] = 1.0f;
            colorSpline[4*i+2] = 0.0f;
            colorSpline[4*i+3] = 1.0f;

            flagSpline[i] = getInheritedFlags();

        }
    }



    if(numberOfNodes>2){

        float x3 = positionData[6];
        float x2 = positionData[3];
        float x1 = positionData[0];
        float x0 = positionData[0];

        float y3 = positionData[7];
        float y2 = positionData[4];
        float y1 = positionData[1];
        float y0 = positionData[1];

        float z3 = positionData[8];
        float z2 = positionData[5];
        float z1 = positionData[2];
        float z0 = positionData[2];

        double t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(0), SBQuantity::dimensionless(1))); //finding the first t such as the distance between two AA is 3.8 A
        double oldt=0;

        while ((t>0) && (t!=-1) && (t<1-0.03)) { // while we can add a carbon alpha
            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            xa=a*x0+b*x1+c*x2+d*x3;
            ya=a*y0+b*y1+c*y2+d*y3;
            za=a*z0+b*z1+c*z2+d*z3;

            positionCarbon.push_back(xa); //adding the coordonnates
            positionCarbon.push_back(ya);
            positionCarbon.push_back(za);
            SBPosition3 positionC=SBPosition3( SBQuantity::length(xa),SBQuantity::length(ya),SBQuantity::length(za));
            SEProteinDesignNodeCarbonAlpha* Carbon = new SEProteinDesignNodeCarbonAlpha(positionC);
            CarbonAlphaList.addReferenceTarget(Carbon);
            oldt = t+0.02;
            t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(oldt), SBQuantity::dimensionless(1))); // finding new t
        }

        for(int i=0;i<n;i++){
            float t = float(i+1)/(n+1);

            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            positionSpline[3*i+0] = a*x0+b*x1+c*x2+d*x3;
            positionSpline[3*i+1] = a*y0+b*y1+c*y2+d*y3;
            positionSpline[3*i+2] = a*z0+b*z1+c*z2+d*z3;


            radiusSpline[i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

            colorSpline[4*i+0] = 1.0f;
            colorSpline[4*i+1] = 1.0f;
            colorSpline[4*i+2] = 0.0f;
            colorSpline[4*i+3] = 1.0f;

            flagSpline[i] = getInheritedFlags();
        }

        for (int currentIndex; currentIndex<numberOfNodes; currentIndex++ ) {

            //spline nodes

            if (currentIndex>2){
                float x3 = positionData[3*currentIndex+0];
                float x2 = positionData[3*(currentIndex-1)+0];
                float x1 = positionData[3*(currentIndex-2)+0];
                float x0 = positionData[3*(currentIndex-3)+0];

                float y3 = positionData[3*currentIndex+1];
                float y2 = positionData[3*(currentIndex-1)+1];
                float y1 = positionData[3*(currentIndex-2)+1];
                float y0 = positionData[3*(currentIndex-3)+1];

                float z3 = positionData[3*currentIndex+2];
                float z2 = positionData[3*(currentIndex-1)+2];
                float z1 = positionData[3*(currentIndex-2)+2];
                float z0 = positionData[3*(currentIndex-3)+2];

                double t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(0), SBQuantity::dimensionless(1))); //finding the first t such as the distance between two AA is 3.8 A
                double oldt=0;

                while (t!=-1) { // while we can add a carbon alpha
                    float a = 0.5f*(-t+2*t*t-t*t*t);
                    float b = 0.5f*(2-5*t*t+3*t*t*t);
                    float c = 0.5f*(t+4*t*t-3*t*t*t);
                    float d = 0.5f*(-t*t+t*t*t);

                    xa=a*x0+b*x1+c*x2+d*x3;
                    ya=a*y0+b*y1+c*y2+d*y3;
                    za=a*z0+b*z1+c*z2+d*z3;

                    positionCarbon.push_back(xa); //adding the coordonnates
                    positionCarbon.push_back(ya);
                    positionCarbon.push_back(za);
                    SBPosition3 positionC=SBPosition3( SBQuantity::length(xa),SBQuantity::length(ya),SBQuantity::length(za));
                    SEProteinDesignNodeCarbonAlpha* Carbon = new SEProteinDesignNodeCarbonAlpha(positionC);
                    CarbonAlphaList.addReferenceTarget(Carbon);
                    oldt = t;
                    t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(oldt), SBQuantity::dimensionless(1))); // finding new t
                }


                for(int i=0;i<n;i++){
                    float t = float(i+1)/(n+1);

                    float a = 0.5f*(-t+2*t*t-t*t*t);
                    float b = 0.5f*(2-5*t*t+3*t*t*t);
                    float c = 0.5f*(t+4*t*t-3*t*t*t);
                    float d = 0.5f*(-t*t+t*t*t);

                    positionSpline[3*n*(currentIndex-2)+3*i+0] = a*x0+b*x1+c*x2+d*x3;
                    positionSpline[3*n*(currentIndex-2)+3*i+1] = a*y0+b*y1+c*y2+d*y3;
                    positionSpline[3*n*(currentIndex-2)+3*i+2] = a*z0+b*z1+c*z2+d*z3;


                    radiusSpline[n*(currentIndex-2)+i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

                    colorSpline[4*n*(currentIndex-2)+4*i+0] = 1.0f;
                    colorSpline[4*n*(currentIndex-2)+4*i+1] = 1.0f;
                    colorSpline[4*n*(currentIndex-2)+4*i+2] = 0.0f;
                    colorSpline[4*n*(currentIndex-2)+4*i+3] = 1.0f;

                    flagSpline[n*(currentIndex-2)+i] = getInheritedFlags();
                }
            }
        }

        x3 = positionData[3*(numberOfNodes-1)+0];
        x2 = positionData[3*(numberOfNodes-1)+0];
        x1 = positionData[3*(numberOfNodes-2)+0];
        x0 = positionData[3*(numberOfNodes-3)+0];

        y3 = positionData[3*(numberOfNodes-1)+1];
        y2 = positionData[3*(numberOfNodes-1)+1];
        y1 = positionData[3*(numberOfNodes-2)+1];
        y0 = positionData[3*(numberOfNodes-3)+1];

        z3 = positionData[3*(numberOfNodes-1)+2];
        z2 = positionData[3*(numberOfNodes-1)+2];
        z1 = positionData[3*(numberOfNodes-2)+2];
        z0 = positionData[3*(numberOfNodes-3)+2];

        t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(0), SBQuantity::dimensionless(1))); //finding the first t such as the distance between two AA is 3.8 A
        oldt=0;

        while ((t>0) && (t!=-1) && (t<1-0.03)) { // while we can add a carbon alpha
            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            xa=a*x0+b*x1+c*x2+d*x3;
            ya=a*y0+b*y1+c*y2+d*y3;
            za=a*z0+b*z1+c*z2+d*z3;

            positionCarbon.push_back(xa); //adding the coordonnates
            positionCarbon.push_back(ya);
            positionCarbon.push_back(za);
            SBPosition3 positionC=SBPosition3( SBQuantity::length(xa),SBQuantity::length(ya),SBQuantity::length(za));
            SEProteinDesignNodeCarbonAlpha* Carbon = new SEProteinDesignNodeCarbonAlpha(positionC);
            CarbonAlphaList.addReferenceTarget(Carbon);
            oldt = t+0.02;
            t= Dichotomie(x1,x2,y1,y2,z1,z2,x3,x0,y3,y0,z3,z0,380,xa,ya,za, SBInterval(SBQuantity::dimensionless(oldt), SBQuantity::dimensionless(1))); // finding new t
        }




        for(int i=0;i<n;i++){
            float t = float(i+1)/(n+1);

            float a = 0.5f*(-t+2*t*t-t*t*t);
            float b = 0.5f*(2-5*t*t+3*t*t*t);
            float c = 0.5f*(t+4*t*t-3*t*t*t);
            float d = 0.5f*(-t*t+t*t*t);

            positionSpline[3*n*(numberOfNodes-2)+3*i+0] = a*x0+b*x1+c*x2+d*x3;
            positionSpline[3*n*(numberOfNodes-2)+3*i+1] = a*y0+b*y1+c*y2+d*y3;
            positionSpline[3*n*(numberOfNodes-2)+3*i+2] = a*z0+b*z1+c*z2+d*z3;


            radiusSpline[n*(numberOfNodes-2)+i] = (float)SBQuantity::length(SBQuantity::angstrom(0.1)).getValue();

            colorSpline[4*n*(numberOfNodes-2)+4*i+0] = 1.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+1] = 1.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+2] = 0.0f;
            colorSpline[4*n*(numberOfNodes-2)+4*i+3] = 1.0f;

            flagSpline[n*(numberOfNodes-2)+i] = getInheritedFlags();
        }
    }

    int numberOfCarbon = positionCarbon.size()/3;
    float* positionCarbonA = new float[3 * numberOfCarbon]();
    float* radiusCarbonA = new float[numberOfCarbon]();
    float* colorCarbonA = new float[4 * numberOfCarbon]();
    unsigned int* flagCarbonA = new unsigned int[numberOfCarbon]();

    for (int i=0; i<numberOfCarbon; i++) {
        positionCarbonA[3*i+0]=positionCarbon[3*i+0];
        positionCarbonA[3*i+1]=positionCarbon[3*i+1];
        positionCarbonA[3*i+2]=positionCarbon[3*i+2];
        radiusCarbonA[i] = (float)SBQuantity::length(SBQuantity::angstrom(0.25)).getValue();
        colorCarbonA[4 * i + 0] = 0.0f;
        colorCarbonA[4 * i + 1] = 0.0f;
        colorCarbonA[4 * i + 2] = 0.0f;
        colorCarbonA[4 * i + 3] = 0.0f;
        flagCarbonA[i] = getInheritedFlags();
    }


    // display

    SAMSON::displaySpheres(numberOfNodes, positionData, radiusData, colorData, flagData);
    SAMSON::displaySpheres(n*(numberOfNodes-1), positionSpline, radiusSpline, colorSpline, flagSpline);
    SAMSON::displaySpheres(numberOfCarbon, positionCarbonA, radiusCarbonA,colorCarbonA,flagCarbonA);

    // clean

    delete[] positionData;
    delete[] radiusData;
    delete[] colorData;
    delete[] flagData;
    delete[] positionSpline;
    delete[] radiusSpline;
    delete[] colorSpline;
    delete[] flagSpline;

}

void SEProteinDesignVisualModelCurve::displayForShadow() {

    // SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows.
    // Implement this function so that your visual model can cast shadows to other objects in SAMSON, for example thanks to the utility
    // functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEProteinDesignVisualModelCurve::displayForSelection() {

    if (ConstructionNodeList.empty()) return;

    unsigned int numberOfNodes = ConstructionNodeList.size();

    // allocate arrays and initialize them to zeros

    float* positionData = new float[3 * numberOfNodes]();
    float* radiusData = new float[numberOfNodes]();
    unsigned int* indexData = new unsigned int[numberOfNodes]();

    // fill in the arrays

    unsigned int currentIndex = 0;


    SB_FOR(SEProteinDesignNodeConstructionPoint* currentNode, ConstructionNodeList){

        SBPosition3 position = currentNode->getPosition();

        positionData[3*currentIndex+0] = (float)position.v[0].getValue();
        positionData[3*currentIndex+1] = (float)position.v[1].getValue();
        positionData[3*currentIndex+2] = (float)position.v[2].getValue();

        radiusData[currentIndex] = (float)SBQuantity::length(SBQuantity::angstrom(0.2)).getValue();

        indexData[currentIndex] = currentNode->getNodeIndex();

        currentIndex++;

    }

    SAMSON::displaySpheresSelection(numberOfNodes, positionData, radiusData, indexData);

    delete[] positionData;
    delete[] radiusData;
    delete[] indexData;

}

void SEProteinDesignVisualModelCurve::expandBounds(SBIAPosition3& bounds) const {

    // SAMSON Element generator pro tip: this function is called by SAMSON to determine the model's spatial bounds.
    // When this function returns, the bounds interval vector should contain the visual model.

}

void SEProteinDesignVisualModelCurve::collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData) {

    // SAMSON Element generator pro tip: this function is called by SAMSON to determine your model's influence on ambient occlusion.
    // Implement this function if you want your visual model to occlude other objects in ambient occlusion calculations.
    //
    // The ambientOcclusionData represents a nCellsX x nCellsY x nCellsZ grid of occlusion densities over the spatial region (boxOrigin, boxSize).
    // If your model represents geometry at position (x, y, z), then the occlusion density in corresponding grid nodes should be increased.
    //
    // Assuming x, y and z are given in length units (SBQuantity::length, SBQuantity::angstrom, etc.), the grid coordinates are:
    // SBQuantity::dimensionless xGrid = nCellsX * (x - boxOrigin.v[0]) / boxSize.v[0];
    // SBQuantity::dimensionless yGrid = nCellsY * (x - boxOrigin.v[1]) / boxSize.v[1];
    // SBQuantity::dimensionless zGrid = nCellsZ * (x - boxOrigin.v[2]) / boxSize.v[2];
    //
    // The corresponding density can be found at ambientOcclusionData[((int)zGrid.getValue() + 0)*nCellsY*nCellsX + ((int)yGrid.getValue() + 0)*nCellsX + ((int)xGrid.getValue() + 0)] (beware of grid bounds).
    // For higher-quality results, the influence of a point can be spread over neighboring grid nodes.

}

void SEProteinDesignVisualModelCurve::onBaseEvent(SBBaseEvent* baseEvent) {

    // SAMSON Element generator pro tip: implement this function if you need to handle base events (e.g. when a node for which you provide a visual representation emits a base signal, such as when it is erased)

}

void SEProteinDesignVisualModelCurve::onDocumentEvent(SBDocumentEvent* documentEvent) {

    // SAMSON Element generator pro tip: implement this function if you need to handle document events

}

void SEProteinDesignVisualModelCurve::onStructuralEvent(SBStructuralEvent* documentEvent) {

    // SAMSON Element generator pro tip: implement this function if you need to handle structural events (e.g. when a structural node for which you provide a visual representation is updated)

}

void SEProteinDesignVisualModelCurve::addNode(SEProteinDesignNodeConstructionPoint* Node){
    if (!Node) return;
    ConstructionNodeList.addReferenceTarget(Node);
}

void SEProteinDesignVisualModelCurve::removeNode(SEProteinDesignNodeConstructionPoint* Node){
    if (!Node) return;
    ConstructionNodeList.removeReferenceTarget(Node);
}

void SEProteinDesignVisualModelCurve::addCarbon(SEProteinDesignNodeCarbonAlpha* Carbon){
    if (!Carbon) return;
    CarbonAlphaList.addReferenceTarget(Carbon);
}

void SEProteinDesignVisualModelCurve::removeCarbon(SEProteinDesignNodeCarbonAlpha* Carbon){
    if (!Carbon) return;
    CarbonAlphaList.removeReferenceTarget(Carbon);
}

void SEProteinDesignVisualModelCurve::getNodes( SBNodeIndexer& nodeIndexer) {
    SB_FOR(SEProteinDesignNodeCarbonAlpha* currentnode, CarbonAlphaList) {
        nodeIndexer.addNode(currentnode);
    }
}

