import csv 
from fileWriting import createFile
from fileWriting import writeResult





def chestPainValue(CP):
    '''
    This is the chest pain value function
    This funciton puts chest pain into categories. 
    The value is then multiplied by three since 
    '''
    value = 0
    if CP == 0:
        value += -1
    elif CP == 1:
        value += 2
    elif CP == 2:
        value += 6
    elif CP == 3:
        value += 10

    return value * 3

def caValue(CA):
    '''
    This is the CA value function
    This funciton puts CA into categories. 
    The value is then multiplied by 2.75 since it 
    is not as impactful as chest pain.
    '''
    value = 0
    if CA == 0:
        value += 0
    elif CA == 1:
        value += 2
    elif CA == 2:
        value += 4
    elif CA == 3:
        value += 8
    elif CA >= 4:
        value += 10
    return value * 2.75

def thalValue(THAL):
    '''
    This is the THAL value function
    This funciton puts THAL into categories. 
    The value is then multiplied by 2.5 since it 
    is not as impactful as CA.
    '''
    value = 0
    if THAL == 0: 
        value += 0
    elif THAL == 1: 
        value += 1
    elif THAL == 2:
        value += 6
    elif THAL == 3: 
        value += 10
    return value * 2.5



def thalachValue(THALACH):
    '''
    This is the THALACH value function
    This funciton puts THALACH into categories. 
    The value is then multiplied by 2.5 since it 
    is not as impactful as THAL.
    '''

    value = 0
    if THALACH >= 170:
        value += -1
    elif 150 <= THALACH < 170:
        value += 0
    elif 130 <= THALACH < 150:
        value += 2
    elif 100< THALACH < 130:
        value += 6
    else:
        value += 10
    return value * 2.25


def ageMutiplier(AGE):
    '''
    This is the age muliplier. 
    The older you are based on the age the
    mutliplier will increase the severity of the result. 
    '''
    multiplier = 1
    if (AGE <= 35):
        multiplier = 1
    elif (35 < AGE <= 50):
        multiplier = 1.15
    elif (50 < AGE <= 65):
        multiplier = 1.3
    else:
        multiplier * 1.45
    return multiplier

def iterateEachLine(fileReadFrom, fileWriteOn):
    '''
    This is the iterate each line funciton.

    Pre Conditions: CSV File (Must be CSV file )


    Post: Condition: writes a CSV file of the score composition of health


    The function also performs try and except to account for unfilled spaces within the 
    CSV file. The function gets a total value each line then performs the fileWriting function
    to append the score to each line. This is a for loop of writing until the end of the csv file. 


    '''
    createFile(fileWriteOn) # Creates the file

    with open(fileReadFrom, 'r') as file:
        overallFile = csv.DictReader(file)
        for row in overallFile:
            
            try:
                rowAge = int(row['age'])
                rowCp = int(row['cp'])
                rowCa = int(row['ca'])
                rowThal = int(row['thal'])
                rowThalach = int(row['thalach'])
                rowHasHeartDisease = int(row['target'])

            except (ValueError):
                rowAge = 0
                rowCp = 0
                rowCa = 0
                rowThal = 0
                rowThalach = 0
                rowHasHeartDisease = 0
           
            total = 0

            total = total + chestPainValue(rowCp)
            total = total + caValue(rowCa)
            total = total + thalValue(rowThal)
            total = total + thalachValue(rowThalach)

            print(rowHasHeartDisease)
            
            preAvg = total / 4
            avgForPrediction = preAvg * ageMutiplier(rowAge)

            writeResult(rowHasHeartDisease, avgForPrediction,fileWriteOn)


