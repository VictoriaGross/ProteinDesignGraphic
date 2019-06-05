# ProteinDesignGraphic

 In this part a new element for SAMSON was created. This element permits to design a new protein containing alpha helices and splines. It containes: 
 ```
- Editor for creating an alpha helix 
- Editor for creating splines 
- Visual Model for curves 
- Visual Model for backbone structure of helices 
- Nodes presenting alpha carbons of amino acids of future protein 
- Nodes used to facilitate constructions  
- App for calculating and displaying the results of prediction 
```
In the application we connect all the alpha carbons from all the models and from between the models into one list. 
```
SEProteinDesignApp::getListNodes()
```
Futher a matrice of distances is constructed from that list.
```
SEProteinDesignApp::findAminoAcid()
```
Futher we get the results of prediction. 
```
SEProteinDesignApp::prediction()
```


