import java.util.Random;

class IOTCloudCommunicator {
    public int pushMessage(String message) {
        // Simulate interaction with the internet and pushing the message to a message queue
        // If communication successful, return a status code in the range [200 - 400],
        // otherwise return an error code in the range [400 - 500].
        Random random = new Random();
        int randomValue = random.nextInt(301) + 200; // Random value between 200 and 500
        return randomValue;
    }
}

class BNFSpeedSensor {
    public int getCurrentSpeed() {
        Random random = new Random();
        return random.nextInt(100) + 1; // Random value between 1 and 100
    }
}

class SpeedMonitor {
    private int speedThreshold;
    private IOTCloudCommunicator communicator;
    private BNFSpeedSensor sensor;

    public SpeedMonitor(int speedThreshold) {
        this.speedThreshold = speedThreshold;
        this.communicator = new IOTCloudCommunicator();
        this.sensor = new BNFSpeedSensor();
    }

    public void monitor() {
        if (speedThreshold < 1 || speedThreshold > 100) {
            System.out.println("Speed threshold value must be in the range {1-100}: " + speedThreshold);
            return;
        }

        int currentSpeedInKmph = sensor.getCurrentSpeed();
        System.out.println("Current Speed in Kmph: " + currentSpeedInKmph);

        if (currentSpeedInKmph > speedThreshold) {
            double mph = currentSpeedInKmph * 0.621371;
            String message = "Current Speed in Miles: " + String.format("%.2f", mph);

            int statusCode = communicator.pushMessage(message);
            if (statusCode > 400) {
                // Log message to console
                System.out.println("Error in communication: Unable to contact server. Message: " + message);
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SpeedMonitor monitorInstance = new SpeedMonitor(10);

        for (int i = 0; i < 5; i++) {
            monitorInstance.monitor();
        }
    }
}

