#include <stdio.h>

// Function to calculate the mean of an array
float mean(float arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the slope (m) of the linear regression line
float calculateSlope(float x[], float y[], int n) {
    float sumXY = 0, sumXX = 0;
    float xMean = mean(x, n);
    float yMean = mean(y, n);

    for (int i = 0; i < n; i++) {
        sumXY += (x[i] - xMean) * (y[i] - yMean);
        sumXX += (x[i] - xMean) * (x[i] - xMean);
    }

    return sumXY / sumXX;
}

// Function to calculate the intercept (c) of the linear regression line
float calculateIntercept(float x[], float y[], int n, float slope) {
    float xMean = mean(x, n);
    float yMean = mean(y, n);
    
    return yMean - slope * xMean;
}

int main() {
    // Sample input data (x)
    float x[] = {6, 5, 3, 4,34, 5};
    
    // Sample output data (y)
    float y[] = {9, 4, 6, 8,1, 10};

    // Number of data points
    int n = sizeof(x) / sizeof(x[0]);

    // Calculate the slope and intercept of the linear regression line
    float slope = calculateSlope(x, y, n);
    float intercept = calculateIntercept(x, y, n, slope);

    // Print the equation of the linear regression line (y = mx + c)
    printf("Equation: y = %.2fx + %.2f\n", slope, intercept);

    return 0;
}
