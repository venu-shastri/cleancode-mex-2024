#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int (*pushMessage)(const char* message);
} IOTCloudCommunicator;

int pushMessageImplementation(const char* message) {
    // Simulate interaction with the internet and pushing the message to a message queue
    // If communication successful, return a status code in the range [200 - 400],
    // otherwise return an error code in the range [400 - 500].
    int randomValue = (rand() % 301) + 200; // Random value between 200 and 500
    return randomValue;
}

typedef struct {
    int (*getCurrentSpeed)();
} BNFSpeedSensor;

int getCurrentSpeedImplementation() {
    int randomValue = (rand() % 100) + 1; // Random value between 1 and 100
    return randomValue;
}

typedef struct {
    int speedThreshold;
    IOTCloudCommunicator communicator;
    BNFSpeedSensor sensor;
} SpeedMonitor;

void monitor(SpeedMonitor* monitorInstance) {
    if (monitorInstance->speedThreshold < 1 || monitorInstance->speedThreshold > 100) {
        printf("Speed threshold value must be in the range {1-100}: %d\n", monitorInstance->speedThreshold);
        return;
    }

    int currentSpeedInKmph = monitorInstance->sensor.getCurrentSpeed();
    printf("Current Speed in Kmph: %d\n", currentSpeedInKmph);

    if (currentSpeedInKmph > monitorInstance->speedThreshold) {
        double mph = currentSpeedInKmph * 0.621371;
        char message[100];
        snprintf(message, sizeof(message), "Current Speed in Miles %.2f", mph);

        int statusCode = monitorInstance->communicator.pushMessage(message);
        if (statusCode > 400) {
            // Log message to console
            printf("Error in communication: Unable to contact server. Message: %s\n", message);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    IOTCloudCommunicator communicator = { .pushMessage = pushMessageImplementation };
    BNFSpeedSensor sensor = { .getCurrentSpeed = getCurrentSpeedImplementation };

    SpeedMonitor monitorInstance = { .speedThreshold = 10, .communicator = communicator, .sensor = sensor };

    for (int i = 0; i < 5; i++) {
        monitor(&monitorInstance);
    }

    return 0;
}
