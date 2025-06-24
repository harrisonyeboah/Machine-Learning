import csv
from matplotlib import pyplot as plt
def getAccuracyValue(fileName, minScore):
    '''
    This gets the accuracy value of each miniumum threshold score.
    
    Precondtions: A valid CSV file with Real Result and Prediciton as 
    its header. Real Result row containing boolean integer values of 1s and 0s. Representing
    True of False of whether or not they have heart disease. With their float value scores. 

    Post Condition: A decimal float value at a certain minScore threshold for 
    what would be considered heart disease. 
    '''

    # Accumulator variables to get percentage.
    total = 0
    totalCorrect = 0

    # File Stream Reading System on Read Mode that does comparisons 
    # Adds up each value and checks whether correct or not 
    with open(fileName, mode='r', newline='') as file:   
        overallFile = csv.DictReader(file)
        for row in overallFile:
            try:
                rowRealResult = int(row['Real Result'])
                rowPrediction = float(row['Prediction'])
                total += 1
                if (rowPrediction >= minScore and rowRealResult == 1):
                    totalCorrect += 1
                if (rowPrediction < minScore and rowRealResult == 0):
                    totalCorrect += 1
            except (ValueError):
                rowRealResult = 0
                rowPrediction = 0

        percentCorrect = totalCorrect/total
        # Returns Correct Percentage in float decimal
        return percentCorrect
    



def plotAccuracyAtEachMinScore(fileName):
    '''
    This function starts with an accumulator variblae at value zero to be considered 
    as a person with heart disease. Then puts the value into the getAccuracyValue 
    function that returns a percenate for that function. This perentage is then appended into 
    the perentage list and the value for that percentage in another list. The value returned. 
    There is also a varibale that updates to get the most optimal value. 
    '''
    #Accumlator varible along with the lists for plotting
    currentMinScore = 0
    percentAccuracy = []
    currentMinScoreList = []
    maxAccuracy = 0
    optimalScore = 0
    #I utilized while loop and update the current score by .01 for peak accuracy
    # At + 1 it was 82 percent accurate runs fast since only loops forty times

    #At + .01 the loop runs 4000 times so this is less efficient takes a little longer to plot
    while (currentMinScore <= 40):
        percentAtScore = getAccuracyValue(fileName, currentMinScore)
        currentMinScoreList.append(currentMinScore)
        percentAccuracy.append(percentAtScore)
        if (maxAccuracy < percentAtScore):
            maxAccuracy = percentAtScore
            optimalScore = currentMinScore
        currentMinScore += .01
    print(f'The optimal Score is {optimalScore} with {maxAccuracy * 100}% accuracy. ')
    plt.bar(currentMinScoreList, percentAccuracy)
    plt.xlabel('Min Score')
    plt.ylabel('Accuracy')
    plt.title('Calculated Accuracy at Certain Minimum Score')
    plt.show()

plotAccuracyAtEachMinScore('myPrediction.csv')