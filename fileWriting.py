import csv
def createFile(fileName):
    '''
    This is function creates the file and puts it in 
    write mode. 

    Pre Conditions: CSV File Name

    Post Condtions: A created csv file with labels as the input name
    With real result and prediction as it's header.
    '''
    with open(fileName, mode='w', newline='') as file:   
        fs = csv.writer(file)
        fs.writerow(["Real Result","Prediction"])

def writeResult(realResult,predictionValue,fileName):
    '''
    This function runs in a for loop and takes the calculated value 
    and writes them on the file. This runs through append mode. So instead of overwriting
    the file it just addes to the file.

    Preconditions: Boolean integer that intakes values of 1 and 0. 
    Along with the health score of each indivdual in float data type.


    Post conditions:
    Writen values of the two parameters to represent each person. 
    '''
    predictionValue = str(predictionValue)
    with open(fileName, mode='a', newline='') as file:   
        fs = csv.writer(file)
        fs.writerow([realResult, predictionValue])

