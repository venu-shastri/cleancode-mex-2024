#include <stdio.h>
#include <stdlib.h>

// BoschTPMS structure
typedef struct BoschTPMS {
    // Add any fields here if needed
} BoschTPMS;

// BoschTPMS constructor
void BoschTPMS_construct(BoschTPMS* self) {
    printf("Bosch TPMS Constructed\n");
}

// BoschTPMS destructor
void BoschTPMS_destruct(BoschTPMS* self) {
    printf("Bosch TPMS Destructed\n");
}

// Engine structure
typedef struct Engine {
    // Add any fields here if needed
} Engine;

// Engine constructor
void Engine_construct(Engine* self) {
    printf("Engine Constructed\n");
}

// Engine destructor
void Engine_destruct(Engine* self) {
    printf("Engine Destructed\n");
}

// Car structure
typedef struct Car {
    Engine engineObj;  // Composition (engine is a part of Car)
    BoschTPMS tpmsObj; // Aggregation (BoschTPMS held by Car)
} Car;

// Car constructor
void Car_construct(Car* self) {
    Engine_construct(&self->engineObj);    // Initialize Engine
    BoschTPMS_construct(&self->tpmsObj);  // Initialize BoschTPMS
    printf("Car Constructed\n");
}

// Car destructor
void Car_destruct(Car* self) {
    BoschTPMS_destruct(&self->tpmsObj);   // Clean up BoschTPMS
    Engine_destruct(&self->engineObj);    // Clean up Engine
    printf("Car Destructed\n");
}

int main() {
    // Create a Car object
    Car car;
    Car_construct(&car);  // Explicitly call constructor
    Car_destruct(&car);   // Explicitly call destructor
    return 0;
}
