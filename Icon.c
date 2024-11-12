#include <stdio.h>
#include <stdbool.h>

// Define an enum for better readability of subtypes
typedef enum {
    SPINNER = 1,
    SLIDER,
    HOPPER
} IconSubtype;

typedef struct {
    float speed, glow, energy;
    int x, y;
    int subtype; // spinner, slider, or hopper

    bool clockwise;  // needed for spinner
    bool expand;     // needed for spinner
    bool vertical;   // needed for slider

    int distance;    // needed for slider
    bool visible;    // needed for hopper

    int xcoord, ycoord; // needed for hopper
} Icon;

// Function prototypes
void spin(Icon *icon);
void slide(Icon *icon);
void hop(Icon *icon);
void move(Icon *icon);
void flair(Icon *icon);

// Function to initialize Icon (acts like a constructor)
void init_icon(Icon *icon, int subtype) {
    icon->subtype = subtype;
    // Set initial values based on subtype
    if (subtype == SPINNER) {
        icon->clockwise = true;
        icon->expand = false;
    } else if (subtype == SLIDER) {
        icon->vertical = true;
        icon->distance = 0;
    } else if (subtype == HOPPER) {
        icon->visible = true;
        icon->xcoord = 0;
        icon->ycoord = 0;
    }
}

// Spin function
void spin(Icon *icon) {
    printf("Spinning...\n");
    // Implement spinning logic here
}

// Slide function
void slide(Icon *icon) {
    printf("Sliding...\n");
    // Implement sliding logic here
}

// Hop function
void hop(Icon *icon) {
    printf("Hopping...\n");
    // Implement hopping logic here
}

// Move function
void move(Icon *icon) {
    if (icon->subtype == SPINNER) {
        spin(icon);
    } else if (icon->subtype == SLIDER) {
        slide(icon);
    } else {
        hop(icon);
    }
}

// Flair function
void flair(Icon *icon) {
    if (icon->subtype == SPINNER) {
        spin(icon);
    } else if (icon->subtype == SLIDER) {
        slide(icon);
    } else {
        hop(icon);
    }
}

// Example of using the Icon struct
int main() {
    Icon myIcon;
    init_icon(&myIcon, SPINNER);
    
    move(&myIcon);
    flair(&myIcon);

    return 0;
}
