import csv
from matplotlib import pyplot as plt
def calcAverages(fileName):
    '''
    This funciton calculates the averages those with heart disease
    and those without heart disease then returns an overall averae score for 
    each. 

    Pre condition: the CSV file name

    Post Condtion: A message that gives overall average score comaparing
    those with heart disase and those without heart disease. 

    This function is in read mode, and contains accumator variables of numberOf yes
    (those with heart disease) nad numberOfNo for (no heart disease) in each line. 
    This then gets to total score to average it out amongst those with heart disease and without 
    heart disease. 


    The result is printed.
    '''
    with open(fileName, 'r') as file:
        overallFile = csv.DictReader(file)
        categoriesList = ['Yes', 'No'] 
        avgScores = [0, 0]

        numberOfNo = 0
        numberOfYes = 0

        scoreOfNo = 0
        scoreOfYes = 0

        for row in overallFile:
            try:
                realResult = int(row['Real Result'])
                score = float(row['Prediction'])
            except ValueError:
                realResult = None
                score = 0

            
            if (realResult == 1):
                numberOfYes = numberOfYes + 1
                scoreOfYes = scoreOfYes + score
            else:
                numberOfNo += 1
                scoreOfNo = scoreOfNo + score
        avgScores[0] = scoreOfYes/numberOfYes
        avgScores[1] = scoreOfNo/numberOfNo
        print(avgScores[0], avgScores[1])
        print(f'The average score with heart disease {scoreOfYes/numberOfYes}.')
        print(f'The average score without heart disease {scoreOfNo/numberOfNo}.')
        makePlot(categoriesList, avgScores)


def makePlot(categories, scores):
        '''
        This function utilizes the matplotlib library.
        To plot the results in a bar chart. 

        Precondtions: A list of categories ("Yes" "No") + 
        A list of the score of each category 
        '''
        plt.bar(categories, scores)
        plt.xlabel('Heart Disease Status')
        plt.ylabel('Heart Disease Sucesptibilty Score')
        plt.title('Scores')
        plt.show()
calcAverages('myPrediction.csv')