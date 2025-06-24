import csv
from matplotlib import pyplot as plt
from calcAverages import calcAverages, makePlot
from fileReading import chestPainValue, caValue, thalValue, thalachValue, ageMutiplier, iterateEachLine
from fileWriting import createFile, writeResult
from findAccuracy import getAccuracyValue, plotAccuracyAtEachMinScore


def main():
    '''
    IterateEachLine(): This funciton reads each line 
    from 'CSG-ED.csv' then writes it onto a file called 
    'myPrediction.csv'. This draws up the first plot 
    of average scores. When the file is done Calc Averages is 
    ran in the background to take the average score of those with heart
    disease and those without then plots it. 


    plotAccuracyAtEachMinScore(): This funciton runs a while loop until 
    score 40 and finds the percentage accuracy of each value.


    End Result: Optimal Score 13.29 at 83.5% accuracy. 

    (This means based on the program anyone above a score of 13.29 
    is considered to have heart disease, while any one below is considered not
    to.
    
    Based off my judgement:
    Score

    0 - 6: Not at risk
    6 - 10: Succeptible But does not have
    10- 13: On the verge of heart disease
    13+: Has Heart Disease
    
    )
    '''
    iterateEachLine('CSG-ED.csv', 'myPrediction.csv') 
    plotAccuracyAtEachMinScore('myPrediction.csv')

main()