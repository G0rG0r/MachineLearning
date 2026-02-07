#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
float input[] ={1,2,4,6,8,10,12};  /// here is what the input should look like 
float output[] ={2,4,8,12,16,20,24,6}; /// here is what the output should look like 
int numberOfData = 7;

float weight = 0; // this is the variable that would try to reproduce the output using the given input
float learnRate = 0.01; /// the lower the more precise
int epochs = 1000;
for(int epoch=0; epoch < epochs;epoch++){ // here we train the model 1000 times by making a guess and calculating the error rate , if the error rate is high we substract the learning rate from W, and if the error rate is low we add the learning rate value
    float totalgradiant = 0.0;
    float totalLoss;

    for(int i =0 ; i < numberOfData;i++ ){
        float prediction = weight * input[i];
       // printf("predtion is %d\n",prediction);
        float error = prediction-output[i]; //calculate error
        totalLoss += error * error; //calculate error squared

        float gradiant = 2 * error * input[i];
        totalgradiant += gradiant;
    }

    weight -= learnRate * (totalgradiant / numberOfData); // update W
}

//now the model finished learning , we can test that 
// it should satisfy the eqation y = 2x

char Userinpt[1024];
while(1){
printf("enter a test number: ");
fgets(Userinpt, sizeof(Userinpt),stdin);
Userinpt[strcspn(Userinpt, "\n")] = '\0';
float tst = atof(Userinpt);
int result = weight * tst;
printf("Prediction Answere is %d\n",result);
}

}