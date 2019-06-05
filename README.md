# ProteinDesignGraphic

 In this part a new element for SAMSON was created. This element enables the user to design a new protein containing alpha helices and splines. It contains: 
 ```
- an Editor for creating an alpha helix 
- an Editor for creating splines 
- a Visual Model for curves 
- a Visual Model for the backbone structure of the helices 
- Nodes representing alpha carbons of amino acids of future protein 
- Nodes used to facilitate constructions  
- an App for calculating and displaying the results of prediction 
```
In the application we connect all the alpha carbons from all the models and from between the models into one list. 
```
SEProteinDesignApp::getListNodes()
```
Then a matrice of distances is constructed from that list.
```
SEProteinDesignApp::findAminoAcid()
```
Afterwards we obtain the prediction results. 
```
SEProteinDesignApp::prediction()
```


